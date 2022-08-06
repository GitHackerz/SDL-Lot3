/**
 * @file RiddleText.h
 * @author
 * @brief Header file for RiddleText
 * @version 0.1
 * @date 2022-08-05
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef RiddleText_h
#define RiddleText_h

#include "MainFN.h"

/**
 * @struct RiddleText
 * @brief Text Riddle structure
 *
 */
typedef struct RiddleText
{
    Text Answer[3];
    int correctAnswer;
    Image Backg;
} RiddleText;

void generateRiddle(RiddleText *riddle);
void displayRiddle(RiddleText riddle, SDL_Surface *screen);
void freeRiddle(RiddleText *riddle);
bool RiddleTextLoop(SDL_Surface *screen, bool *fullScreen);
#endif /* RiddleText */
