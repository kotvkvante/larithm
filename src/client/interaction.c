#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

// common
#include "la_map.h"

// client
#include "interaction.h"

#define LA_URL_CHECK "http://kotbkbahte.pythonanywhere.com/check"
#define LA_URL "http://kotbkbahte.pythonanywhere.com/get_map"

char str[2048];

size_t curl_write(void *ptr, size_t size, size_t nmemb, void *stream)
{
    // fwrite("char\n", 1, 5, stdout);
    strcpy(str, (char*)ptr);
    return fwrite(ptr, size, nmemb, stdout);
}

la_map_t* cl_get_map()
{
    CURL* curl = NULL;
    CURLcode response;
    la_map_t* map;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if(!curl)
    {
        printf("Error!\n");
        goto CLEANUP;
    }

    curl_easy_setopt(
        curl,
        CURLOPT_URL,
        LA_URL
    );
    curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curl_write);

    response = curl_easy_perform(curl);

    if(response != CURLE_OK)
    {
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
            curl_easy_strerror(response));
        goto CLEANUP;
    }
    else
    {
        printf(">> %s\n", str);
        map = map_init_from_json_str((const char*)str);
        return map;
    }

CLEANUP:

    curl_easy_cleanup(curl);
    curl_global_cleanup();
    return NULL;
}


// void __cl_ask_for_map(void)
// {
//     CURL* curl;
//     CURLcode response;
//     curl_global_init(CURL_GLOBAL_ALL);
//
//     curl = curl_easy_init();
//
//     if(curl)
//     {
//         curl_easy_setopt(
//             curl,
//             CURLOPT_URL,
//             LA_URL
//         );
//         struct curl_slist *hs = NULL;
//         hs = curl_slist_append(hs, "Content-Type: application/json");
//         curl_easy_setopt(curl, CURLOPT_HTTPHEADER, hs);
//
//         // curl_easy_setopt(curl, CURLOPT_POST, 1L);
//         // static const char *postthis = "this is post message, please send this stuff";
//         static const char *postthis = "{\"type\":\"map\"}";
//         curl_easy_setopt(curl, CURLOPT_POSTFIELDS, buffer);
//         curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)strlen(buffer));
//
//         response = curl_easy_perform(curl);
//         if(response != CURLE_OK)
//               fprintf(stderr, "curl_easy_perform() failed: %s\n",
//                       curl_easy_strerror(response));
//         else
//         {
//             printf("%s", response);
//         }
//
//
//         curl_easy_cleanup(curl);
//
//     }
//
//     curl_global_cleanup();
//
// }
