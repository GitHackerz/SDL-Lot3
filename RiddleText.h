#ifndef RiddleText_h
#define RiddleText_h

#include "TextImage.h"
#include <stdbool.h>

typedef struct RiddleText
{
    Text Answer[3];
    int correctAnswer;
    Image Backg;
} RiddleText;

int generateRandomNumber(int min, int max);
void generateRiddle(RiddleText *riddle);
void displayRiddle(RiddleText riddle, SDL_Surface *screen);
void freeRiddle(RiddleText *riddle);
bool RiddleTextLoop(SDL_Surface *screen, bool *fullScreen);
#endif /* RiddleText */
