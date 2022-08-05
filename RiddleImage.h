#ifndef RiddleImage_h
#define RiddleImage_h

#include "MainFN.h"

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
