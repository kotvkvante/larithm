#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <math.h>
#include <limits.h>
#include <time.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT
#include "nuklear.h"
#include "nuklear_glfw_gl4.h"

#include "gui.h"

void render_gui(struct nk_context *ctx, GLFWwindow *win)
{

    int width = 0, height = 0;
    /* GUI */
    if( nk_begin(ctx, "Larithm",
        nk_rect(WINDOW_WIDTH- 50 - 200, 50, 200, 200),
        NK_WINDOW_BORDER|NK_WINDOW_MINIMIZABLE|NK_WINDOW_TITLE))
    {
        nk_layout_row_dynamic(ctx, 30, 1);
        if (nk_button_label(ctx, "Play"))
            fprintf(stdout, "Play\n");
        nk_layout_row_dynamic(ctx, 30, 1);
        if (nk_button_label(ctx, "Pause"))
            fprintf(stdout, "Pause\n");
        nk_layout_row_dynamic(ctx, 30, 1);
        if (nk_button_label(ctx, "Restart"))
            fprintf(stdout, "Restart\n");
        nk_layout_row_dynamic(ctx, 30, 1);
        if (nk_button_label(ctx, "Exit"))
            fprintf(stdout, "Exit\n");

    } nk_end(ctx);
    if(nk_begin(ctx, "Settings",
        nk_rect(WINDOW_WIDTH- 50 - 200, WINDOW_HEIGHT - 50 - 200, 200, 200),
        NK_WINDOW_BORDER|NK_WINDOW_MINIMIZABLE|NK_WINDOW_TITLE))
    {
        static float value = 0.6f;
        // nk_layout_row_dynamic(ctx, 30, 2);
        nk_layout_row_begin(ctx, NK_STATIC, 30, 2);
            nk_layout_row_push(ctx, 50);
            nk_label(ctx, "Volume:", NK_TEXT_LEFT);
            nk_layout_row_push(ctx, 110);
            if(nk_slider_float(ctx, 0, &value, 1.0f, 0.05f))
                printf("%f\n", value);


        nk_layout_row_begin(ctx, NK_STATIC, 30, 2);
            nk_layout_row_push(ctx, 25);
            nk_label(ctx, "Ip:", NK_TEXT_LEFT);
            nk_layout_row_push(ctx, 135);
            static char text[64];
            static int text_len;
            nk_edit_string(ctx, NK_EDIT_SIMPLE, text, &text_len, 64, nk_filter_default);


    } nk_end(ctx);
    if( nk_begin(ctx, "Control",
        nk_rect(WINDOW_WIDTH- 50 - 200, WINDOW_HEIGHT - 50 - 450, 200, 200),
        NK_WINDOW_BORDER|NK_WINDOW_MINIMIZABLE|NK_WINDOW_TITLE))
    {
        nk_layout_row_dynamic(ctx, 30, 4);
        if (nk_button_label(ctx, "Up"))
            fprintf(stdout, "Up\n");
        if (nk_button_label(ctx, "Left"))
            fprintf(stdout, "Left\n");
        if (nk_button_label(ctx, "Rigth"))
            fprintf(stdout, "Rigth\n");
        if (nk_button_label(ctx, "Down"))
            fprintf(stdout, "Down\n");

        nk_layout_row_dynamic(ctx, 0, 2);
        if (nk_button_label(ctx, "Exec"))
            fprintf(stdout, "Exec\n");

        nk_layout_row_static(ctx, 30, 80, 1);
        if (nk_button_label(ctx, "Solve"))
            fprintf(stdout, "Solve\n");

        nk_layout_row_static(ctx, 30, 80, 1);
        if (nk_button_label(ctx, "Clear"))
            fprintf(stdout, "Clear\n");
    } nk_end(ctx);

    // if (nk_begin(ctx, "Demo", nk_rect(50, 50, 230, 250),
    //     NK_WINDOW_BORDER|NK_WINDOW_MOVABLE|NK_WINDOW_SCALABLE|
    //     NK_WINDOW_MINIMIZABLE|NK_WINDOW_TITLE))
    // {
    //     enum {EASY, HARD};
    //     static int op = EASY;
    //     static int property = 20;
    //
    //
    //     nk_layout_row_dynamic(ctx, 30, 2);
    //     if (nk_option_label(ctx, "easy", op == EASY)) op = EASY;
    //     if (nk_option_label(ctx, "hard", op == HARD)) op = HARD;
    //
    //     nk_layout_row_dynamic(ctx, 25, 1);
    //     nk_property_int(ctx, "Compression:", 0, &property, 100, 10, 1);
    //
    //     nk_layout_row_dynamic(ctx, 20, 1);
    //     nk_label(ctx, "background:", NK_TEXT_LEFT);
    //     nk_layout_row_dynamic(ctx, 25, 1);
    //     if (nk_combo_begin_color(ctx, nk_rgb_cf(bg), nk_vec2(nk_widget_width(ctx),400))) {
    //         nk_layout_row_dynamic(ctx, 120, 1);
    //         bg = nk_color_picker(ctx, bg, NK_RGBA);
    //         nk_layout_row_dynamic(ctx, 25, 1);
    //         bg.r = nk_propertyf(ctx, "#R:", 0, bg.r, 1.0f, 0.01f,0.005f);
    //         bg.g = nk_propertyf(ctx, "#G:", 0, bg.g, 1.0f, 0.01f,0.005f);
    //         bg.b = nk_propertyf(ctx, "#B:", 0, bg.b, 1.0f, 0.01f,0.005f);
    //         bg.a = nk_propertyf(ctx, "#A:", 0, bg.a, 1.0f, 0.01f,0.005f);
    //         nk_combo_end(ctx);
    //     }
    // }
    // nk_end(ctx);

    struct nk_colorf bg;
    bg.r = 0.10f, bg.g = 0.18f, bg.b = 0.24f, bg.a = 1.0f;
    glfwGetWindowSize(win, &width, &height);
    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(bg.r, bg.g, bg.b, bg.a);
    /* IMPORTANT: `nk_glfw_render` modifies some global OpenGL state
     * with blending, scissor, face culling, depth test and viewport and
     * defaults everything back into a default state.
     * Make sure to either a.) save and restore or b.) reset your own state after
     * rendering the UI. */
    nk_glfw3_render(NK_ANTI_ALIASING_ON);

}
