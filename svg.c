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
