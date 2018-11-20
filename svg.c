#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include"svg.h"

//Appending stuff to SVG doc


//Appending string
static void appendstr2svg(svg* psvg, char* text)
{
int len = strlen(psvg->svg) + strlen(text) + 1;

char* p = realloc(psvg->svg, len);

if(p)
{

psvg->svg = p;

}

strcat(psvg->svg, text);

}

//Appending number
static void appendnum2svg(svg* psvg, int n)
{

char sn[16];

sprintf(sn, "%d", n);

appendstr2svg(psvg, sn);

}

//Creates new svg instance and writes opening tags to that instance
svg* svg_create(int width, int height)
{

svg* psvg = malloc(sizeof(svg));

//psvg!=null
if(psvg != NULL)
{
//initialising psvg struct
*psvg = (svg){.svg = NULL, .width = width, .height = height, .finalized = false};

psvg->svg = malloc(1);

sprintf(psvg->svg, "%s", "\0");

appendstr2svg(psvg, "<svg width='");
appendnum2svg(psvg, width);
appendstr2svg(psvg, "px' height='");
appendnum2svg(psvg, height);
appendstr2svg(psvg, "px' xmlns='http://www.w3.org/2000/svg' version='1.1' xmlns:xlink='http://www.w3.org/1999/xlink'>\n");

return psvg;

}

else
{
return NULL;
}

}

//Finalizing i.e inserting closing tag to doc
void svg_finalize(svg* psvg)
{
appendstr2svg(psvg, "</svg>");

psvg->finalized = true;
}

//Rectangle function

void svg_rectangle(svg* psvg, int width, int height, int x, int y, char* fill, char* stroke, int strokewidth, int radiusx, int radiusy)
{

appendstr2svg(psvg, "    <rect fill='");
appendstr2svg(psvg, fill);
appendstr2svg(psvg, "' stroke='");
appendstr2svg(psvg, stroke);
appendstr2svg(psvg, "' stroke-width='");
appendnum2svg(psvg, strokewidth);
appendstr2svg(psvg, "px' width='");
appendnum2svg(psvg, width);
appendstr2svg(psvg, "' height='");
appendnum2svg(psvg, height);
appendstr2svg(psvg, "' y='");
appendnum2svg(psvg, y);
appendstr2svg(psvg, "' x='");
appendnum2svg(psvg, x);
appendstr2svg(psvg, "' ry='");
appendnum2svg(psvg, radiusy);
appendstr2svg(psvg, "' rx='");
appendnum2svg(psvg, radiusx);
appendstr2svg(psvg, "' />\n");

}

//SAVE FUNCTION (IMP !)

void svg_save(svg* psvg, char* filepath)
{

if(!psvg->finalized)
{
svg_finalize(psvg);
}

FILE* fp;
fp = fopen(filepath, "w");

if(fp != NULL)
{

fwrite(psvg->svg, 1, strlen(psvg->svg), fp);

fclose(fp);

}

}

//FREE FUNCTION to free memory after usage(EXTIMP !)

void svg_free(svg* psvg)
{

free(psvg->svg);

free(psvg);

}

void svg_fill(svg* psvg, char* Fill)
{

svg_rectangle(psvg, psvg->width, psvg->height, 0, 0, Fill, Fill, 0, 0, 0);

}

void svg_print(svg* psvg)
{

printf("%s\n",psvg->svg);
printf("\t\t-------------------------EOF-------------------------\n");

}

void svg_line(svg* psvg, char* stroke, int strokewidth, int x1, int y1, int x2, int y2)
{
    appendstr2svg(psvg, "    <line stroke='");
    appendstr2svg(psvg, stroke);
    appendstr2svg(psvg, "' stroke-width='");
    appendnum2svg(psvg, strokewidth);
    appendstr2svg(psvg, "px' y2='");
    appendnum2svg(psvg, y2);
    appendstr2svg(psvg, "' x2='");
    appendnum2svg(psvg, x2);
    appendstr2svg(psvg, "' y1='");
    appendnum2svg(psvg, y1);
    appendstr2svg(psvg, "' x1='");
    appendnum2svg(psvg, x1);
    appendstr2svg(psvg, "' />\n");
}

void svg_text(svg* psvg, int x, int y, char* fontfamily, int fontsize, char* fill, char* stroke, char* text)
{
    appendstr2svg(psvg, "    <text x='");
    appendnum2svg(psvg, x);
    appendstr2svg(psvg, "' y = '");
    appendnum2svg(psvg, y);
    appendstr2svg(psvg, "' font-family='");
    appendstr2svg(psvg, fontfamily);
    appendstr2svg(psvg, "' stroke='");
    appendstr2svg(psvg, stroke);
    appendstr2svg(psvg, "' fill='");
    appendstr2svg(psvg, fill);
    appendstr2svg(psvg, "' font-size='");
    appendnum2svg(psvg, fontsize);
    appendstr2svg(psvg, "px'>");
    appendstr2svg(psvg, text);
    appendstr2svg(psvg, "</text>\n");
}

void svg_circle(svg* psvg, char* stroke, int strokewidth, char* fill, int r, int cx, int cy)
{
    appendstr2svg(psvg, "    <circle stroke='");
    appendstr2svg(psvg, stroke);
    appendstr2svg(psvg, "' stroke-width='");
    appendnum2svg(psvg, strokewidth);
    appendstr2svg(psvg, "px' fill='");
    appendstr2svg(psvg, fill);
    appendstr2svg(psvg, "' r='");
    appendnum2svg(psvg, r);
    appendstr2svg(psvg, "' cy='");
    appendnum2svg(psvg, cy);
    appendstr2svg(psvg, "' cx='");
    appendnum2svg(psvg, cx);
    appendstr2svg(psvg, "' />\n");
}

void svg_ellipse(svg* psvg, int cx, int cy, int rx, int ry, char* fill, char* stroke, int strokewidth)
{
    appendstr2svg(psvg, "    <ellipse cx='");
    appendnum2svg(psvg, cx);
    appendstr2svg(psvg, "' cy='");
    appendnum2svg(psvg, cy);
    appendstr2svg(psvg, "' rx='");
    appendnum2svg(psvg, rx);
    appendstr2svg(psvg, "' ry='");
    appendnum2svg(psvg, ry);
    appendstr2svg(psvg, "' fill='");
    appendstr2svg(psvg, fill);
    appendstr2svg(psvg, "' stroke='");
    appendstr2svg(psvg, stroke);
    appendstr2svg(psvg, "' stroke-width='");
    appendnum2svg(psvg, strokewidth);
    appendstr2svg(psvg, "' />\n");
}

