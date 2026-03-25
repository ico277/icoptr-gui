#include <iostream>
#include "icoptr.h"

#if defined(ICOPTR_OPENGL3) || defined(ICOPTR_OPENGL2)
extern "C" {
    #include <GLFW/glfw3.h>
}
#endif

#include "./imgui/imgui.h"

#include "./imgui/imgui_impl_glfw.h"
#ifdef ICOPTR_OPENGL3
#include "./imgui/imgui_impl_opengl3.h"
#endif
#ifdef ICOPTR_OPENGL2
#include "./imgui/imgui_impl_opengl2.h"
#endif


static void glfw_error_callback(int error, const char* description) {
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

int main() {
    upload_file("");


    // Setup GLFW
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return 1;

#ifdef ICOPTR_OPENGL2
    // GL 2.0
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
#else
    // GL 3.0 + GLSL 130
    auto glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
#endif

    // Create window
    GLFWwindow* window = glfwCreateWindow(500, 500, "icoptr-gui", nullptr, nullptr);
    if (window == nullptr)
        return 1;

    // Setup window
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);    // Enable vsync

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // enable keyboard movement                  

    // Setup OpenGL backend
    ImGui_ImplGlfw_InitForOpenGL(window, true);
#ifdef ICOPTR_OPENGL2
    ImGui_ImplOpenGL2_Init();
#else
    ImGui_ImplOpenGL3_Init(glsl_version);
#endif
    //ImGui_ImplOpenGL3_Init();

    ImGuiWindowFlags fullscreen__flags = /*ImGuiWindowFlags_NoTitleBar*/ 0 | 
        ImGuiWindowFlags_NoCollapse |
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoBringToFrontOnFocus |
        ImGuiWindowFlags_NoNavFocus;

    while (!glfwWindowShouldClose(window)) {
        // Poll and handle events (inputs, window resize, etc.)
        //glfwPollEvents();
        glfwWaitEvents();

        // Start the Dear ImGui frame
#ifdef ICOPTR_OPENGL2
        ImGui_ImplOpenGL2_NewFrame();
#else
        ImGui_ImplOpenGL3_NewFrame();
#endif
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // window
        ImGuiViewport* viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(viewport->WorkPos);
        //std::cout << viewport->WorkSize.x << "x" << viewport->WorkSize.y << "\n";
        ImGui::SetNextWindowSize(viewport->WorkSize);
        // Remove window rounding and padding so it sits flush against the edges
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
        // Pop the style variables we pushed above
        ImGui::PopStyleVar(3);
        ImGui::Begin("Hello, world!", nullptr, fullscreen__flags);
        ImGui::Text("This is some silly text :3");
        ImGui::Text(":3");
        ImGui::End();

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        //glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        //glClear(GL_COLOR_BUFFER_BIT);
        
        // Draw the ImGui data generated above
#ifdef ICOPTR_OPENGL2
        ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
#else
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
#endif

        glfwSwapBuffers(window);
    }

    // Cleanup
#ifdef ICOPTR_OPENGL2
    ImGui_ImplOpenGL2_Shutdown();
#else
    ImGui_ImplOpenGL3_Shutdown();
#endif
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
