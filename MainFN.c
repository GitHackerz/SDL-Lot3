#include "MainFN.h"

int generateRandomNumber(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

void initWinGame(Image winGame[])
{
    for (int i = 0; i < 61; i++)
    {
        sprintf(winGame[i].nameImg, "./assets/images/WinGame/%d.png", i);
        initBackg(&winGame[i], winGame[i].nameImg);
    }
}

void displayWinGame(Image winGame[], SDL_Surface *screen)
{
    for (int i = 0; i < 61; i++)
    {
        displayImage(winGame[i], screen);
        SDL_Flip(screen);
    }
}

void initLooseGame(Image looseGame[])
{
    for (int i = 0; i < 58; i++)
    {
        sprintf(looseGame[i].nameImg, "./assets/images/LooseGame/%d.png", i);
        initBackg(&looseGame[i], looseGame[i].nameImg);
    }
}

void displayLooseGame(Image looseGame[], SDL_Surface *screen)
{
    for (int i = 0; i < 58; i++)
    {
        displayImage(looseGame[i], screen);
        SDL_Flip(screen);
    }
}