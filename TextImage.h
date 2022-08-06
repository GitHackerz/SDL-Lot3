/**
 * @file TextImage.h
 * @author
 * @brief Header File for TextImage
 * @version 0.1
 * @date 2022-08-05
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef TextImage
#define TextImage

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

/**
 * @struct Text
 * @brief Text Structure
 */
typedef struct Text
{
    SDL_Rect pos;
    SDL_Color color;
    SDL_Surface *surfaceText;
    TTF_Font *font;
    char Texte[100];
} Text;

/**
 * @struct Image
 * @brief Image Structure
 */
typedef struct Image
{
    SDL_Rect pos;
    SDL_Surface *imgSurface;
    char nameImg[100];
} Image;

// Text Functions
void initTxt(Text *t, int x, int y, SDL_Color color, int size, char Font[], char Texte[]);
void displayText(Text text, SDL_Surface *screen);
void freeText(Text text);

// Image Functions
void initBackg(Image *Backg, char nameImg[]);
void initImage(Image *Img, int x, int y, char nameImg[]);
void displayImage(Image Img, SDL_Surface *screen);
void freeImage(Image Img);

#endif /* TextImage */
