#include <stdlib.h>
#include <stdio.h>


// common
#include "la_map.h"
#include "la_map_template.h"
#include "la_map_state.h"
#include "la_map_collider.h"
#include "la_sequence.h"
#include "la_solver.h"

// common/objects
#include "base.h"
#include "wall.h"

// client
// #include "interaction.h"

int main(int argc, char const *argv[])
{

    la_sequence_t* sqnc = la_sqnc_init();
    // la_sqnc_from_file(sqnc, "solver1.sqnc");
    int arr[] = {0, 0, 3, 1, 0, 4};
    la_sqnc_from_array(sqnc, 6, arr);
    sqnc_print(sqnc);

    la_map_template_t* tmpl = map_tmpl_init_from_file("map.json");
    la_map_t* map = map_init_from_template(tmpl);
    map_print(map);
    map_cldr_print(map);

    la_solve(map, sqnc);
    map_print(map);
    // la_map_t* map = map_init_from_file("map.json");
    // map_print(map);
    // map_cldr_init(map);
    // map_cldr_fill_default(map);
    // map_cldr_print(map);

    // printf("Hi\n");

    // la_obj_base_t* base = obj_base_new();
    // obj_base_init_xy(base, 0, 0);
    //
    // la_map_state_t* map_state = map_state_init_with(map, base);
    // la_obj_wall_t* wall = obj_wall_new();
    // obj_wall_init(wall, 2, 2, 120);
    // map_state_add_wall(map_state, wall);
    // map_state_print(map_state);
    //
    // la_solve(map, sqnc2);


    return 0;
    // while(1)
    // {
    //
    // };


    // la_map_t* map;
    // map_print(map);
    // map_close(map);
    // CURL* curl;
    // CURLcode response;
    // curl_global_init(CURL_GLOBAL_ALL);
    //
    // curl = curl_easy_init();
    //
    // if(curl)
    // {
    //     curl_easy_setopt(
    //         curl,
    //         CURLOPT_URL,
    //         LA_URL
    //     );
    //     struct curl_slist *hs = NULL;
    //     hs = curl_slist_append(hs, "Content-Type: application/json");
    //     curl_easy_setopt(curl, CURLOPT_HTTPHEADER, hs);
    //
    //     // curl_easy_setopt(curl, CURLOPT_POST, 1L);
    //     // static const char *postthis = "this is post message, please send this stuff";
    //     static const char *postthis = "{\"type\":\"map\"}";
    //     curl_easy_setopt(curl, CURLOPT_POSTFIELDS, buffer);
    //     curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)strlen(buffer));
    //
    //     response = curl_easy_perform(curl);
    //     if(response != CURLE_OK)
    //           fprintf(stderr, "curl_easy_perform() failed: %s\n",
    //                   curl_easy_strerror(response));
    //     else
    //     {
    //         printf("%s", response);
    //     }
    //
    //
    //     curl_easy_cleanup(curl);
    //
    // }
    //
    // curl_global_cleanup();
    // return 0;
}


// int main(int argc, char const *argv[])
// {
//     // la_map_t* my_map = map_init_default();
//     // map_print(my_map);
//     // map_print_element(my_map, 0, 0);
//     // map_print_element(my_map, 3, 3);
//
//     int sock = 0, valread, client_fd;
//     struct sockaddr_in serv_addr;
//     char* hello = "Hello from client";
//     char buffer[1024] = { 0 };
//     if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
//     {
//         printf("\n Socket creation error \n");
//         return -1;
//     }
//
//     serv_addr.sin_family = AF_INET;
//     serv_addr.sin_port = htons(PORT);
//
//     // Convert IPv4 and IPv6 addresses from text to binary
//     // form
//     if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)
//         <= 0) {
//         printf(
//             "\nInvalid address/ Address not supported \n");
//         return -1;
//     }
//
//     if ((client_fd
//          = connect(sock, (struct sockaddr*)&serv_addr,
//                    sizeof(serv_addr)))
//         < 0) {
//         printf("\nConnection Failed \n");
//         return -1;
//     }
//     send(sock, hello, strlen(hello), 0);
//     printf("Hello message sent\n");
//     valread = read(sock, buffer, 1024);
//     printf("%s\n", buffer);
//
//     // closing the connected socket
//     close(client_fd);
//
//     return 0;
// }
