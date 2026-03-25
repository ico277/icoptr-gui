#include <string>

#include <curl/curl.h>

CURL *curl = nullptr;

std::string upload_file(std::string file_path) {
    if (!curl) {
        curl = curl_easy_init();
    }



    return "";
}

class UploadUtil {
    public:
        bool isUploading = false;
        
};