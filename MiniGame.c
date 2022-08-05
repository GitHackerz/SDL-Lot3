#include "MiniGame.h"

void initGame(Game *game)
{
    SDL_Rect pos[3][3];
    initBackg(&game->Backg, "./assets/images/MiniGame/Background.jpg");

    int x = 700, y = 290;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            initImage(&game->X[i][j], x, y, "./assets/images/MiniGame/X.png");
            initImage(&game->O[i][j], x, y, "./assets/images/MiniGame/O.png");
            game->isChecked[i][j] = 0;
            x += 227;
        }
        x = 700;
        y += 230;
    }
}

bool getPos(Game game, int x, int y, int *i, int *j)
{
    int posX = 630, posY = 241;
    int posX1 = posX + 210, posY1 = posY + 210;
    for (int c = 0; c < 3; c++)
    {

        for (int k = 0; k < 3; k++)
        {
            if (x >= posX && x <= posX1 && y >= posY && y <= posY1)
            {
                *i = c;
                *j = k;
                return true;
            }
            posX += 230;
            posX1 = posX + 210;
        }
        posX = 630;
        posX1 = posX + 210;
        posY += 230;
        posY1 = posY + 210;
    }
    return false;
}

void checkX(Game *game, SDL_Surface *screen, int i, int j)
{
    game->isChecked[i][j] = 1;
    displayGame(*game, screen);
    SDL_Flip(screen);
}
void checkO(Game *game, SDL_Surface *screen, int i, int j)
{
    game->isChecked[i][j] = 2;
    displayGame(*game, screen);
    SDL_Flip(screen);
}
bool onMiddleV(int i)
{
    if (i > 0 && i < 2)
        return true;
    return false;
}

bool onMiddleH(int j)
{
    if (j > 0 && j < 2)
        return true;
    return false;
}

bool onTop(int i)
{
    if (i == 0)
        return true;
    return false;
}

bool onBottom(int i)
{
    if (i == 2)
        return true;
    return false;
}

bool onLeft(int j)
{
    if (j == 0)
        return true;
    return false;
}

bool onRight(int j)
{
    if (j == 2)
        return true;
    return false;
}

bool Attack(Game *game, SDL_Surface *screen)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (game->isChecked[i][j] == 2)

            {
                if (onMiddleV(i) && (game->isChecked[i - 1][j] == 2 || game->isChecked[i + 1][j] == 2) && (game->isChecked[i + 1][j] == 0 || game->isChecked[i + 1][j] == 0))
                {
                    checkO(game, screen, i - 1, j);
                    checkO(game, screen, i + 1, j);
                    return true;
                }
                else if (onMiddleH(j) && (game->isChecked[i][j - 1] == 2 || game->isChecked[i][j + 1] == 2) && (game->isChecked[i][j + 1] == 0 || game->isChecked[i][j - 1] == 0))
                {
                    checkO(game, screen, i, j - 1);
                    checkO(game, screen, i, j + 1);
                    return true;
                }
                else if (onTop(i) && (game->isChecked[i + 1][j] == 2 || game->isChecked[i + 2][j] == 2) && (game->isChecked[i + 1][j] == 0 || game->isChecked[i + 2][j] == 0))
                {
                    checkO(game, screen, i + 1, j);
                    checkO(game, screen, i + 2, j);
                    return true;
                }
                else if (onBottom(i) && (game->isChecked[i - 1][j] == 2 || game->isChecked[i - 2][j] == 2) && (game->isChecked[i - 1][j] == 0 || game->isChecked[i - 2][j] == 0))
                {
                    checkO(game, screen, i - 1, j);
                    checkO(game, screen, i - 2, j);
                    return true;
                }
                else if (onLeft(j) && (game->isChecked[i][j + 1] == 2 || game->isChecked[i][j + 2] == 2) && (game->isChecked[i][j + 1] == 0 || game->isChecked[i][j + 2] == 0))
                {
                    checkO(game, screen, i, j + 1);
                    checkO(game, screen, i, j + 2);
                    return true;
                }
                else if (onRight(j) && (game->isChecked[i][j - 1] == 2 || game->isChecked[i][j - 2] == 2) && (game->isChecked[i][j - 1] == 0 || game->isChecked[i][j - 2] == 0))
                {
                    checkO(game, screen, i, j - 1);
                    checkO(game, screen, i, j - 2);
                    return true;
                }
            }
        }
    }

    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         if (!game->isChecked[i][j])
    //         {
    //             checkO(game, screen, i, j);
    //             return true;
    //         }
    //     }
    // }
    return false;
}

bool Deffense(Game *game, SDL_Surface *screen)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (game->isChecked[i][j] == 1)
            {
                if (onMiddleV(i) && (game->isChecked[i - 1][j] == 1 || game->isChecked[i + 1][j] == 1) && (game->isChecked[i - 1][j] == 0 || game->isChecked[i + 1][j] == 0))
                {
                    if (!game->isChecked[i + 1][j])
                    {
                        checkO(game, screen, i + 1, j);
                        return true;
                    }
                    else if (!game->isChecked[i - 1][j])
                    {
                        checkO(game, screen, i - 1, j);
                        return true;
                    }
                }
                if (onMiddleH(j) && (game->isChecked[i][j - 1] == 1 || game->isChecked[i][j + 1] == 1) && (game->isChecked[i][j + 1] == 0 || game->isChecked[i][j - 1] == 0))
                {
                    if (!game->isChecked[i][j - 1])
                    {
                        checkO(game, screen, i, j - 1);
                        return true;
                    }
                    else if (!game->isChecked[i][j + 1])
                    {
                        checkO(game, screen, i, j + 1);
                        return true;
                    }
                }
                if (onTop(i) && (game->isChecked[i + 1][j] == 1 || game->isChecked[i + 2][j] == 1) && (game->isChecked[i + 1][j] == 0 || game->isChecked[i + 2][j] == 0))
                {
                    if (!game->isChecked[i + 1][j])
                    {
                        checkO(game, screen, i + 1, j);
                        return true;
                    }
                    else
                    {
                        checkO(game, screen, i + 2, j);
                        return true;
                    }
                }
                if (onBottom(i) && (game->isChecked[i - 1][j] == 1 || game->isChecked[i - 2][j] == 1) && (game->isChecked[i - 1][j] == 0 || game->isChecked[i - 2][j] == 0))
                {
                    if (!game->isChecked[i - 1][j])
                    {
                        checkO(game, screen, i - 1, j);
                        return true;
                    }
                    else if (!game->isChecked[i - 2][j])
                    {
                        checkO(game, screen, i - 2, j);
                        return true;
                    }
                }
                if (onLeft(j) && (game->isChecked[i][j + 1] == 1 || game->isChecked[i][j + 2] == 1) && (game->isChecked[i][j + 1] == 0 || game->isChecked[i][j + 2] == 0))
                {
                    if (!game->isChecked[i][j + 1])
                    {
                        checkO(game, screen, i, j + 1);
                        return true;
                    }
                    else if (!game->isChecked[i][j + 2])
                    {
                        checkO(game, screen, i, j + 2);
                        return true;
                    }
                }
                if (onRight(j) && (game->isChecked[i][j - 1] == 1 || game->isChecked[i][j - 2] == 1) && (game->isChecked[i][j - 1] == 0 || game->isChecked[i][j - 2] == 0))
                {
                    if (!game->isChecked[i][j - 1])
                    {
                        checkO(game, screen, i, j - 1);
                        return true;
                    }
                    else if (!game->isChecked[i][j - 2])
                    {
                        checkO(game, screen, i, j - 2);
                        return true;
                    }
                }

                if (onTop(j) && onLeft(j) && (game->isChecked[i + 1][j + 1] == 1 || game->isChecked[i + 2][j + 2] == 1) && (game->isChecked[i + 1][j + 1] == 0 || game->isChecked[i + 2][j + 2] == 0))
                {
                    if (!game->isChecked[i + 1][j + 1])
                    {
                        checkO(game, screen, i + 1, j + 1);
                        return true;
                    }
                    else if (!game->isChecked[i + 2][j + 2])
                    {
                        checkO(game, screen, i + 2, j + 2);
                        return true;
                    }
                }

                if (onMiddleH(j) && onMiddleV(i) && (game->isChecked[i - 1][j - 1] == 1 || game->isChecked[i + 1][j + 1]) && (game->isChecked[i - 1][j - 1] == 0 || game->isChecked[i + 1][j + 1] == 0))
                {
                    if (!game->isChecked[i + 1][j + 1])
                    {
                        checkO(game, screen, i + 1, j + 1);

                        return true;
                    }
                    if (!game->isChecked[i - 1][j - 1])
                    {
                        checkO(game, screen, i - 1, j - 1);
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void randomPlay(Game *game, SDL_Surface *screen)
{
    int i = rand() % 3;
    int j = rand() % 3;
    while (game->isChecked[i][j] != 0)
    {
        i = rand() % 3;
        j = rand() % 3;
    }
    checkO(game, screen, i, j);
}

int playerWin(Game game)
{
    for (int i = 0; i < 3; i++)
    {
        if (game.isChecked[0][i] == 1 && game.isChecked[1][i] == 1 && game.isChecked[2][i] == 1)
            return 1;
        if (game.isChecked[i][0] == 1 && game.isChecked[i][1] == 1 && game.isChecked[i][2] == 1)
            return 1;
        if (game.isChecked[0][0] == 1 && game.isChecked[1][1] == 1 && game.isChecked[2][2] == 1)
            return 1;

        if (game.isChecked[0][i] == 2 && game.isChecked[1][i] == 2 && game.isChecked[2][i] == 2)
            return 2;
        if (game.isChecked[i][0] == 2 && game.isChecked[i][1] == 2 && game.isChecked[i][2] == 2)
            return 2;
        if (game.isChecked[0][0] == 2 && game.isChecked[1][1] == 2 && game.isChecked[2][2] == 2)
            return 2;
    }
    if (game.isChecked[0][2] == 1 && game.isChecked[1][1] == 1 && game.isChecked[2][0] == 1)
        return 1;
    if (game.isChecked[0][2] == 2 && game.isChecked[1][1] == 2 && game.isChecked[2][0] == 2)
        return 2;

    int a = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (game.isChecked[i][j] != 0)
                a++;
        }
    }

    if (a >= 9)
        return 2;

    return 0;
}

bool gameLoop(SDL_Surface *screen, bool *fullScreen)
{
    Game game;
    SDL_Event event;
    bool isRunning = true, quitGame = false;
    bool isMyTurn = true;
    Image winGame[61];
    Image looseGame[58];

    initWinGame(winGame);
    initLooseGame(looseGame);

    initGame(&game);
    displayGame(game, screen);

    while (isRunning)
    {

        SDL_WaitEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            isRunning = false;
            quitGame = true;
            break;
        case SDL_MOUSEBUTTONDOWN:
            int x = event.button.x;
            int y = event.button.y;
            int i, j;
            if (getPos(game, x, y, &i, &j) && isMyTurn)
            {
                if (!game.isChecked[i][j])
                {
                    checkX(&game, screen, i, j);
                    isMyTurn = false;
                }
                break;
            }

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
                displayGame(game, screen);
                break;
            }

            break;
        }

        if (!isMyTurn)
        {
            SDL_Delay(1000);
            if (!playerWin(game) && !Deffense(&game, screen))
                if (!playerWin(game) && !Attack(&game, screen))
                    randomPlay(&game, screen);
            isMyTurn = true;
            SDL_Delay(500);
        }
        int playerWinner = playerWin(game);
        if (playerWinner)
        {
            if (playerWinner == 1)
                displayWinGame(winGame, screen);
            else
                displayLooseGame(looseGame, screen);
            SDL_Delay(5000);
            isRunning = false;
        }
    }
    freeGame(&game);
    return !quitGame;
}

void displayGame(Game game, SDL_Surface *screen)
{
    displayImage(game.Backg, screen);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (game.isChecked[i][j] == 1)
                displayImage(game.X[i][j], screen);
            else if (game.isChecked[i][j] == 2)
                displayImage(game.O[i][j], screen);
        }
    }
    SDL_Flip(screen);
}

void freeGame(Game *game)
{
    freeImage(game->Backg);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            freeImage(game->X[i][j]);
            freeImage(game->O[i][j]);
        }
    }
}