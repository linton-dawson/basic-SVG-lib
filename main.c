#include<stdio.h>
#include<math.h>
#include<time.h>

#include"svg.h"

void drawrectangle(void);
void drawallshapes(void);
void customalientext(void);

int main()
{

puts("Code in C starts - SVG\n--------------\n");

drawrectangle();
drawallshapes();
customalientext();
return EXIT_SUCCESS;

}

void drawrectangle(void)
{
    svg* psvg;
    psvg = svg_create(512, 512);

    if(psvg == NULL)
    {
        puts("psvg is NULL");
    }
    else
    {
	svg_print(psvg);
        svg_rectangle(psvg, 512, 512, 0, 0, "white", "white", 0, 0, 0);

        svg_rectangle(psvg, 384, 384, 64, 64, "#00FF00", "#000000", 4, 0, 0);
        svg_rectangle(psvg, 320, 320, 96, 96, "#FFFF00", "#000000", 2, 8, 8);
        svg_rectangle(psvg, 256, 256, 128, 128, "#00FFFF", "#000000", 2, 8, 8);
        svg_rectangle(psvg, 192, 192, 160, 160, "#FF80FF", "#000000", 2, 8, 8);

        svg_finalize(psvg);
        svg_save(psvg, "rectangles.svg");
        svg_free(psvg);
    }
} 

void drawallshapes(void)
{
    svg* psvg;
    psvg = svg_create(192, 320);

    if(psvg == NULL)
    {
        puts("psvg is NULL");
    }
    else
    {
        svg_fill(psvg, "#DADAFF");

        svg_text(psvg, 32, 32, "sans-serif", 16, "#000000", "#000000", "drawallshapes");
        svg_circle(psvg, "#000080", 4, "#0000FF", 32, 64, 96);
        svg_ellipse(psvg, 64, 160, 32, 16, "#FF0000", "#800000", 4);

        svg_line(psvg, "#000000", 2, 32, 192, 160, 192);

        svg_rectangle(psvg, 64, 64, 32, 224, "#00FF00", "#008000", 4, 4, 4);

        svg_finalize(psvg);
        svg_print(psvg);
        svg_save(psvg, "allshapes.svg");
        svg_free(psvg);
    }
}

void customalientext(void)
{
    svg* psvg;
    psvg = svg_create(512, 768);

    if(psvg == NULL)
    {
        puts("psvg is NULL");
    }
    else
    {
        svg_fill(psvg, "#000010");

        srand(time(NULL));
        int x, y;
        for(int s = 0; s <= 512; s++)
        {
            x = (rand() % 512);
            y = (rand() % 768);

            svg_rectangle(psvg, 1, 1, x, y, "white", "white", 0, 0, 0);
        }

        svg_text(psvg, 96, 712, "sans-serif", 32, "#FFFFFF", "#FFFFFF", "Custom Alien Text");

        svg_circle(psvg, "silver", 2, "rgba(0,0,0,0)", 28, 256, 384);

        svg_ellipse(psvg, 256, 374, 8, 14, "#808080", "#808080", 0);
        svg_ellipse(psvg, 252, 372, 3, 2, "#000000", "#000000", 0);
        svg_ellipse(psvg, 260, 372, 3, 2, "#000000", "#000000", 0);
        svg_rectangle(psvg, 1, 1, 251, 371, "white", "white", 0, 0, 0);
        svg_rectangle(psvg, 1, 1, 259, 371, "white", "white", 0, 0, 0);
        svg_line(psvg, "black", 1, 254, 378, 258, 378);

        svg_line(psvg, "silver", 2, 234, 416, 226, 432);
        svg_line(psvg, "silver", 2, 278, 416, 286, 432);
        svg_ellipse(psvg, 256, 400, 64, 16, "silver", "silver", 4);

        svg_finalize(psvg);
        svg_save(psvg, "iwanttobelieve.svg");
        svg_free(psvg);
    }
}
