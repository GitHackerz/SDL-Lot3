/**
 * @file main.c
 * @author Hamza 
 * @brief Main File
 * @version 0.1
 * @date 2022-08-05
 *
 * @copyright Copyright (c) 2022
 *
 */


#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <stdbool.h>
#include <time.h>

#include "TextImage.h"
#include "RiddleText.h"
#include "RiddleImage.h"
#include "MiniGame.h"
#include "MainFN.h"

// Global Variables
SDL_Surface *screen;
bool fullScreen = false;

/**
 * @brief Configuring the SDL
 *
 * @return int (1: Configured /0: Not Configured)
 */
int setup()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("ERROR : %s\n", SDL_GetError());
        return 0;
    }
    if (TTF_Init() != 0)
    {
        printf("ERROR : %s\n", SDL_GetError());
        return 0;
    }
    return 1;
}

/**
 * @brief Init Function
 *
 * @return int Status (1 OK / 0 ERROR)
 */
int initScreen()
{
    if (fullScreen)
        screen = SDL_SetVideoMode(Width, Height, 32, SDL_HWSURFACE | SDL_FULLSCREEN);
    else
        screen = SDL_SetVideoMode(Width, Height, 32, SDL_HWSURFACE);
    return 1;
}

int main()
{
    srand(time(NULL));

    RiddleText riddle;
    Image menuBackg, butClick[3], butClickActive[3];
    SDL_Event event;
    SDL_Color white = {255, 255, 255};
    bool insideButton[3] = {false, false, false};
    int choice = 0; // 1- TextRiddle / 2- MiniGame / 3- ImageRiddle
    bool isRunning = true;

    // Setting UP SDL window
    printf("Setting up ...\n");
    if (setup())
        printf("Setting Up Successfully\n");
    else
        return printf("Setting Up Failed\n");

    printf("Initializing...\n");
    if (initScreen())
        printf("Initializing Successfully\n");
    else
        return printf("Initializing Failed\n");

    // Loading The Menu ...
    initBackg(&menuBackg, "./assets/images/Menu/Background.jpg");
    initImage(&butClick[0], 230, 700, "./assets/images/Menu/ButtonClick.png");
    initImage(&butClick[1], 796, 700, "./assets/images/Menu/ButtonClick.png");
    initImage(&butClick[2], 1363, 700, "./assets/images/Menu/ButtonClick.png");

    initImage(&butClickActive[0], 230, 700, "./assets/images/Menu/ButtonClickActive.png");
    initImage(&butClickActive[1], 796, 700, "./assets/images/Menu/ButtonClickActive.png");
    initImage(&butClickActive[2], 1363, 700, "./assets/images/Menu/ButtonClickActive.png");

    displayImage(menuBackg, screen);
    for (int i = 0; i < 3; i++)
        displayImage(butClick[i], screen);
    SDL_Flip(screen);

    // Game Loop ...
    while (isRunning)
    {
        SDL_WaitEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_MOUSEMOTION:

            for (int i = 0; i < 3; i++)
            {
                int x = event.motion.x;
                int y = event.motion.y;
                int posX = butClick[i].pos.x;
                int posY = butClick[i].pos.y;
                int posX1 = posX + butClick[i].imgSurface->w;
                int posY1 = posY + butClick[i].imgSurface->h;
                displayImage(butClick[i], screen);
                if (x >= posX && x <= posX1 && y >= posY && y <= posY1)
                {
                    if (!insideButton[i])
                    {
                        displayImage(menuBackg, screen);
                        displayImage(butClickActive[i], screen);
                        for (int j = 0; j < 3; j++)
                        {
                            if (j != i)
                                displayImage(butClick[j], screen);
                        }
                        insideButton[i] = true;
                        SDL_Flip(screen);
                    }
                }

                else
                {
                    if (insideButton[i])
                    {
                        displayImage(butClick[i], screen);
                        insideButton[i] = false;
                        SDL_Flip(screen);
                    }
                }
            }

            break;
        case SDL_MOUSEBUTTONDOWN:
            for (int i = 0; i < 3; i++)
                if (insideButton[i])
                    choice = i + 1;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_f:
                fullScreen = !fullScreen;
                initScreen();
                displayImage(menuBackg, screen);
                for (int i = 0; i < 3; i++)
                    displayImage(butClick[i], screen);
                SDL_Flip(screen);
                break;
            case SDLK_a:
                choice = 1;
                break;
            case SDLK_b:
                choice = 2;
                break;
            case SDLK_c:
                choice = 3;
                break;
            case SDLK_ESCAPE:
                isRunning = false;
                break;
            }

            break;
        }

        if (choice != 0)
        {
            switch (choice)
            {
            case 1:
                isRunning = RiddleImageLoop(screen, &fullScreen);
                break;
            case 2:
                isRunning = gameLoop(screen, &fullScreen);
                break;
            case 3:
                isRunning = RiddleTextLoop(screen, &fullScreen);
                ;
                break;
            }

            choice = 0;
            displayImage(menuBackg, screen);
            for (int i = 0; i < 3; i++)
                displayImage(butClick[i], screen);
            SDL_Flip(screen);
        }
    }

    return 0;
}