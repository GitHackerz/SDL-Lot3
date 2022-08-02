#include "TextImage.h"

// Text Functions
void initTxt(Text *t, int x, int y, SDL_Color color, int size, char Font[], char Texte[])
{
    t->pos.x = x;
    t->pos.y = y;
    t->font = TTF_OpenFont(Font, size);
    t->color = color;
    strcpy(t->Texte, Texte);
    t->surfaceText = TTF_RenderText_Solid(t->font, t->Texte, t->color);
}
void displayText(Text text, SDL_Surface *screen)
{
    SDL_BlitSurface(text.surfaceText, NULL, screen, &text.pos);
}
void freeText(Text text)
{
    SDL_FreeSurface(text.surfaceText);
    TTF_CloseFont(text.font);
}

// Image functions
void initBackg(Image *Backg, char nameImg[])
{
    Backg->img = IMG_Load(nameImg);
    Backg->pos.x = 0;
    Backg->pos.y = 0;
}
void initImage(Image *Img, int x, int y, char nameImg[])
{
    Img->img = NULL;
    strcpy(Img->nameImg, nameImg);
    Img->img = IMG_Load(nameImg);
    Img->pos.x = x;
    Img->pos.y = y;
}
void displayImage(Image Img, SDL_Surface *screen)
{
    SDL_BlitSurface(Img.img, NULL, screen, &Img.pos);
}
void freeImage(Image Img)
{
    SDL_FreeSurface(Img.img);
}
