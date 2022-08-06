/**
 * @file MiniGame.h
 * @author
 * @brief Header File for MiniGame
 * @version 0.1
 * @date 2022-08-05
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef MiniGame
#define MiniGame

#include "MainFN.h"

/**
 * @struct Game
 * @brief Game structure for miniGame
 */
typedef struct Game
{
    Image Backg;
    Image X[3][3], O[3][3];
    int isChecked[3][3];
} Game;

void initGame(Game *game);
void displayGame(Game game, SDL_Surface *screen);
void freeGame(Game *game);
bool gameLoop(SDL_Surface *screen, bool *fullScreen);
bool getPos(Game game, int x, int y, int *i, int *j);
void checkX(Game *game, SDL_Surface *screen, int i, int j);
void checkO(Game *game, SDL_Surface *screen, int i, int j);
bool onMiddleV(int i);
bool onMiddleH(int j);
bool onTop(int i);
bool onBottom(int i);
bool onLeft(int j);
bool onRight(int j);
bool Attack(Game *game, SDL_Surface *screen);
bool Defense(Game *game, SDL_Surface *screen);
void randomPlay(Game *game, SDL_Surface *screen);
int PlayerWin(Game game);

#endif /* MiniGame */
