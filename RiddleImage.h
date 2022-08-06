/**
 * @file RiddleImage.h
 * @author
 * @brief Header file for RiddleImage.c
 * @version 0.1
 * @date 2022-08-05
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef RiddleImage_h
#define RiddleImage_h

#include "MainFN.h"

/**
 * @struct RiddleImage
 * @brief Image Riddle structure
 *
 */

typedef struct RiddleImage
{
    Image Backg;
    Image Answer[3];
    int correctAnswer;
    Text cityName;
} RiddleImage;

void generateRiddleImage(RiddleImage *riddle);
void displayRiddleImage(RiddleImage riddle, SDL_Surface *screen);
void freeRiddleImage(RiddleImage *riddle);
bool RiddleImageLoop(SDL_Surface *screen, bool *fullScreen);
#endif /* RiddleImage */
