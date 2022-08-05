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
