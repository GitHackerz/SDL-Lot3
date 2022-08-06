/**
 * @file TextImage.c
 * @author
 * @brief Text and Images Functions
 * @version 0.1
 * @date 2022-08-05
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "TextImage.h"

/**
 * @brief Initialize the text
 *
 * @param t the Text
 * @param x position X
 * @param y position Y
 * @param color Color of the text
 * @param size Size of the text
 * @param Font Font of the text
 * @param Texte Text of the text
 */

void initTxt(Text *t, int x, int y, SDL_Color color, int size, char Font[], char Texte[])
{
    t->pos.x = x;
    t->pos.y = y;
    t->font = TTF_OpenFont(Font, size);
    t->color = color;
    strcpy(t->Texte, Texte);
    t->surfaceText = TTF_RenderText_Solid(t->font, t->Texte, t->color);
}

/**
 * @brief Display the text
 *
 * @param text
 * @param screen
 */
void displayText(Text text, SDL_Surface *screen)
{
    SDL_BlitSurface(text.surfaceText, NULL, screen, &text.pos);
}

/**
 * @brief Free the text
 *
 * @param text
 */
void freeText(Text text)
{
    SDL_FreeSurface(text.surfaceText);
    TTF_CloseFont(text.font);
}

/**
 * @brief Init the Background
 *
 * @param Backg Background Variable
 * @param nameImg Image Name
 */
void initBackg(Image *Backg, char nameImg[])
{
    strcpy(Backg->nameImg, nameImg);
    Backg->imgSurface = IMG_Load(Backg->nameImg);
    Backg->pos.x = 0;
    Backg->pos.y = 0;
}

/**
 * @brief Init the Image
 *
 * @param Img Image Variable
 * @param x X Position
 * @param y Y Position
 * @param nameImg Image Name
 */
void initImage(Image *Img, int x, int y, char nameImg[])
{
    strcpy(Img->nameImg, nameImg);
    Img->imgSurface = IMG_Load(Img->nameImg);
    Img->pos.x = x;
    Img->pos.y = y;
}
/**
 * @brief Display The Image
 *
 * @param Img Image Variable
 * @param screen
 */
void displayImage(Image Img, SDL_Surface *screen)
{
    SDL_BlitSurface(Img.imgSurface, NULL, screen, &Img.pos);
}
/**
 * @brief Free the Image
 *
 * @param Img Image Variable
 */
void freeImage(Image Img)
{
    SDL_FreeSurface(Img.imgSurface);
}
