#include <iostream>
#include "info.hpp"

using std::cout;

int main(int argc, char** argv) {
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            greet(argv[i]);
        }
    }
    greet("World");
    cout << "Hai\n";
    return 0;
}
