#include "MainFN.h"

int generateRandomNumber(int min, int max)
{
    return rand() % (max - min + 1) + min;
}
