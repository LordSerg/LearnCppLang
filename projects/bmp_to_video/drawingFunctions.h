#pragma once
#include "BITMAP.h"
#include "Color.h"

void drawRect(BITMAP& bit,int x, int y, int w, int h, Color col);
void fillRect(BITMAP& bit,int x, int y, int w, int h, Color col);

void drawEllipse(BITMAP& bit,int xc, int yc, int a, int b, Color col);
void fillEllipse(BITMAP& bit,int xc, int yc, int a, int b, Color col);

void drawLine(BITMAP& bit,int x1, int y1, int x2, int y2, Color col);
void drawLine(BITMAP& bit,int x1, int y1, int x2, int y2, Color col1, Color col2);
void drawLine(BITMAP& bit,int x1, int y1, int x2, int y2, int colorNum, Color *colors);
