/**
 * @file MainFN.h
 * @author
 * @brief Header file for MainFN
 * @version 0.1
 * @date 2022-08-05
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef mainFN_h
#define mainFN_h

#include "TextImage.h"
#include <stdbool.h>

#define Width 1920
#define Height 1080

int generateRandomNumber(int min, int max);
void initWinGame(Image winGame[]);
void displayWinGame(Image winGame[], SDL_Surface *screen);
void initLooseGame(Image looseGame[]);
void displayLooseGame(Image looseGame[], SDL_Surface *screen);
#endif /* mainFN_h */
