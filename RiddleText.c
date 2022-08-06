/**
 * @file RiddleText.c
 * @author
 * @brief Text Riddle functions
 * @version 0.1
 * @date 2022-08-05
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "RiddleText.h"

/**
 * @brief erate a random text Riddle
 *
 * @param riddle
 */
void generateRiddleText(RiddleText *riddle)
{
    FILE *textRiddleFile = fopen("./Data/textRiddle.txt", "r");
    SDL_Color white = {255, 255, 255};

    int x[3], y[3];
    char Answ1[30], Answ2[30], Answ3[30];
    int numRiddle = generateRandomNumber(1, 3);
    strcpy(riddle->Answer[0].Texte, "A- ");
    strcpy(riddle->Answer[1].Texte, "B- ");
    strcpy(riddle->Answer[2].Texte, "C- ");

    int i = 0;
    while (i < numRiddle)
    {
        fscanf(textRiddleFile, "%s %s %s %s %d (%d,%d) (%d,%d) (%d,%d)", riddle->Backg.nameImg, Answ1, Answ2, Answ3, &riddle->correctAnswer, &x[0], &y[0], &x[1], &y[1], &x[2], &y[2]);
        i++;
    }

    initBackg(&riddle->Backg, riddle->Backg.nameImg);

    i = 0;
    do
    {
        int randNum = generateRandomNumber(0, 3);
        if (strlen(riddle->Answer[randNum].Texte) <= 3)
        {
            switch (i)
            {
            case 0:
                strcat(riddle->Answer[randNum].Texte, Answ1);

                initTxt(&riddle->Answer[randNum], x[randNum], y[randNum], white, 70, "./assets/fonts/Berlin Sans FB Demi Bold.ttf", riddle->Answer[randNum].Texte);
                riddle->correctAnswer = randNum + 1;
                break;
            case 1:

                strcat(riddle->Answer[randNum].Texte, Answ2);

                initTxt(&riddle->Answer[randNum], x[randNum], y[randNum], white, 70, "./assets/fonts/Berlin Sans FB Demi Bold.ttf", riddle->Answer[randNum].Texte);

                break;
            case 2:

                strcat(riddle->Answer[randNum].Texte, Answ3);

                initTxt(&riddle->Answer[randNum], x[randNum], y[randNum], white, 70, "./assets/fonts/Berlin Sans FB Demi Bold.ttf", riddle->Answer[randNum].Texte);

                break;
            }
            i++;
        }
    } while (i < 3);
}

/**
 * @brief Display the Riddle
 *
 * @param riddle
 * @param screen
 */
void displayRiddleText(RiddleText riddle, SDL_Surface *screen)
{
    displayImage(riddle.Backg, screen);

    for (int i = 0; i < 3; i++)
    {
        displayText(riddle.Answer[i], screen);
    }

    SDL_Flip(screen);
}

/**
 * @brief Free the Riddle Variables
 *
 * @param riddle
 */
void freeRiddleText(RiddleText *riddle)
{
    freeImage(riddle->Backg);
    for (int i = 0; i < 3; i++)
    {
        freeText(riddle->Answer[i]);
    }
}

/**
 * @brief Text Riddle Loop
 *
 * @param screen
 * @param fullScreen
 * @return true if he's just quit the TextRiddle
 * @return false he Want to quit all the game
 */

bool RiddleTextLoop(SDL_Surface *screen, bool *fullScreen)
{
    RiddleText riddle;
    Image winGame[61];
    Image looseGame[58];
    Text result;
    SDL_Color white = {255, 255, 255};
    SDL_Event event;
    bool isRunning = true, quitGame = false;
    int answer = 0;

    initWinGame(winGame);
    initLooseGame(looseGame);
    generateRiddleText(&riddle);
    displayRiddleText(riddle, screen);

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
                displayRiddleText(riddle, screen);
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
    freeRiddleText(&riddle);
    return !quitGame;
}