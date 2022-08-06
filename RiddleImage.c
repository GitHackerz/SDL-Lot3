/**
 * @file RiddleImage.c
 * @author
 * @brief Image Riddle Functions
 * @version 0.1
 * @date 2022-08-05
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "RiddleImage.h"

/**
 * @brief Generate a random image Riddle
 *
 * @param riddle
 */
void generateRiddleImage(RiddleImage *riddle)
{
    FILE *imageRiddleFile = fopen("./Data/imageRiddle.txt", "r");
    SDL_Color white = {255, 255, 255};
    bool changed = false;
    char nameImg1[30], nameImg2[30], nameImg3[30], cityName1[30], cityName2[30], cityName3[30];
    int x[3], y[3];

    riddle->correctAnswer = generateRandomNumber(1, 3);
    fscanf(imageRiddleFile, "%s %s %s %s %s %s %s (%d,%d) (%d,%d) (%d,%d)", riddle->Backg.nameImg, riddle->Answer[0].nameImg, riddle->Answer[1].nameImg, riddle->Answer[2].nameImg, cityName1, cityName2, cityName3, &x[0], &y[0], &x[1], &y[1], &x[2], &y[2]);

    initBackg(&riddle->Backg, riddle->Backg.nameImg);

    switch (riddle->correctAnswer)
    {
    case 1:
        strcpy(riddle->cityName.Texte, cityName1);
        break;
    case 2:
        strcpy(riddle->cityName.Texte, cityName2);
        break;
    case 3:
        strcpy(riddle->cityName.Texte, cityName3);
        break;
    }

    initTxt(&riddle->cityName, 770, 237, white, 100, "./assets/fonts/Berlin Sans FB Demi Bold.ttf", riddle->cityName.Texte);

    int randNum;
    for (int i = 0; i < 3; i++)
    {
        do
        {
            randNum = generateRandomNumber(0, 2);
        } while (x[randNum] == 0 || y[randNum] == 0);

        initImage(&riddle->Answer[i], x[randNum], y[randNum], riddle->Answer[i].nameImg);

        if (i == (riddle->correctAnswer - 1) && !changed)
        {
            riddle->correctAnswer = randNum + 1;
            changed = true;
        }
        x[randNum] = 0;
        y[randNum] = 0;
    }
}

/**
 * @brief Display the Riddle
 *
 * @param riddle
 * @param screen
 */
void displayRiddleImage(RiddleImage riddle, SDL_Surface *screen)
{
    displayImage(riddle.Backg, screen);
    displayText(riddle.cityName, screen);

    for (int i = 0; i < 3; i++)
        displayImage(riddle.Answer[i], screen);

    SDL_Flip(screen);
}

/**
 * @brief Free the Riddle Variables
 *
 * @param riddle
 */
void freeRiddleImage(RiddleImage *riddle)
{
    freeImage(riddle->Backg);
    freeText(riddle->cityName);

    for (int i = 0; i < 3; i++)
        freeImage(riddle->Answer[i]);
}

/**
 * @brief Image Riddle Loop
 *
 * @param screen
 * @param fullScreen
 * @return true if he's just quit the ImageRiddle
 * @return false he Want to quit all the game
 */

bool RiddleImageLoop(SDL_Surface *screen, bool *fullScreen)
{
    RiddleImage riddle;
    Text result;
    SDL_Color white = {255, 255, 255};
    SDL_Event event;
    bool isRunning = true, quitGame = false;
    int answer = 0;
    Image winGame[61];
    Image looseGame[58];

    initWinGame(winGame);
    initLooseGame(looseGame);
    generateRiddleImage(&riddle);
    displayRiddleImage(riddle, screen);

    while (isRunning)
    {
        SDL_WaitEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            isRunning = false;
            quitGame = true;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                isRunning = false;
                break;
            case SDLK_f:
                *fullScreen = !*fullScreen;
                if (*fullScreen)
                    screen = SDL_SetVideoMode(Width, Height, 32, SDL_HWSURFACE | SDL_FULLSCREEN);
                else
                    screen = SDL_SetVideoMode(Width, Height, 32, SDL_HWSURFACE);
                displayRiddleImage(riddle, screen);
                break;
            case SDLK_a:
                answer = 1;
                break;
            case SDLK_b:
                answer = 2;
                break;
            case SDLK_c:
                answer = 3;
                break;
            }

            if (answer)
            {
                if (answer == riddle.correctAnswer)
                {
                    displayWinGame(winGame, screen);
                    SDL_Delay(5000);
                    isRunning = false;
                }
                else
                {
                    displayLooseGame(looseGame, screen);
                    SDL_Delay(5000);
                    isRunning = false;
                }
            }
            break;
        }
    }
    freeRiddleImage(&riddle);
    freeWinGame(winGame);
    freeLooseGame(looseGame);
    return !quitGame;
}