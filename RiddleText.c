#include "RiddleText.h"
#include <stdlib.h>

int generateRandomNumber(int min, int max)
{
    return rand() % (max - min + 1) + min;
}
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

void displayRiddleText(RiddleText riddle, SDL_Surface *screen)
{
    displayImage(riddle.Backg, screen);

    for (int i = 0; i < 3; i++)
    {
        displayText(riddle.Answer[i], screen);
    }

    SDL_Flip(screen);
}

void freeRiddleText(RiddleText *riddle)
{
    freeImage(riddle->Backg);
    for (int i = 0; i < 3; i++)
    {
        freeText(riddle->Answer[i]);
    }
}

bool RiddleTextLoop(SDL_Surface *screen, bool *fullScreen)
{
    RiddleText riddle;
    Text result;
    SDL_Color white = {255, 255, 255};
    SDL_Event event;
    bool isRunning = true, quitGame = false;
    int answer = 0;

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
            break;
        }
    }
    freeRiddleText(&riddle);
    return !quitGame;
}