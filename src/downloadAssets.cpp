#include "inc/downloadAssets.h"

static size_t write_data(void* ptr, size_t size, size_t nmemb, void* stream) {
    size_t written = fwrite(ptr, size, nmemb, (FILE*)stream);
    return written;
}
USI downloadAssets() {
    cout << "=============DOWNLOADING ASSETS============\r\n";
    CURL* curl_handle;
    static const char* pagefilename = "list.txt";
    FILE* pagefile;
    try {
        curl_global_init(CURL_GLOBAL_ALL);

        /* init the curl session */
        curl_handle = curl_easy_init();

        /* set URL to get here */
        curl_easy_setopt(curl_handle, CURLOPT_URL, "https://raw.githubusercontent.com/sanikdah/DOS-Simulator/main/assets/list.txt");

        /* disable progress meter, set to 0L to enable it */
        curl_easy_setopt(curl_handle, CURLOPT_NOPROGRESS, 1L);

        /* send all data to this function  */
        curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);

        /* open the file */
        pagefile = fopen(pagefilename, "wb");
    }
    catch (...) {
        cerr << "Failed to set up the downloader!   Exiting...\r\n";
        return ERROR_CURL_SETUP_FAIL;
    }
    try {
        if (pagefile) {

            /* write the page body to this file handle */
            curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, pagefile);

            /* get it! */
            curl_easy_perform(curl_handle);

            /* close the header file */
            fclose(pagefile);
        }

        /* cleanup curl stuff */
        curl_easy_cleanup(curl_handle);

        curl_global_cleanup();
    }
    catch (...) {
        cerr << "Error occurred trying to download assets for the program!  Exiting...\r\n";
        return ERROR_ASSET_DOWNLOAD;
    }
    return SUCCESS;
}