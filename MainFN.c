/**
 * @file MainFN.c
 * @author
 * @brief File containing main functions
 * @version 0.1
 * @date 2022-08-05
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "MainFN.h"

/**
 * @brief Generate random numbers between min and max
 *
 * @param min
 * @param max
 * @return random Number
 */
int generateRandomNumber(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

/**
 * @brief Init win game images
 * @param winGame
 */
void initWinGame(Image winGame[])
{
    for (int i = 0; i < 61; i++)
    {
        sprintf(winGame[i].nameImg, "./assets/images/WinGame/%d.png", i);
        initBackg(&winGame[i], winGame[i].nameImg);
    }
}

/**
 * @brief Display win game images
 * @param winGame
 * @param screen
 */
void displayWinGame(Image winGame[], SDL_Surface *screen)
{
    for (int i = 0; i < 61; i++)
    {
        displayImage(winGame[i], screen);
        SDL_Flip(screen);
    }
}

/**
 * @brief Init Loose Game Images
 * @param looseGame
 */
void initLooseGame(Image looseGame[])
{
    for (int i = 0; i < 58; i++)
    {
        sprintf(looseGame[i].nameImg, "./assets/images/LooseGame/%d.png", i);
        initBackg(&looseGame[i], looseGame[i].nameImg);
    }
}

/**
 * @brief display Loose Game Images
 *
 * @param looseGame
 * @param screen
 */
void displayLooseGame(Image looseGame[], SDL_Surface *screen)
{
    for (int i = 0; i < 58; i++)
    {
        displayImage(looseGame[i], screen);
        SDL_Flip(screen);
    }
}