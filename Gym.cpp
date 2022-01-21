#include "Gym.h"
#include <iostream>
#include <string>
using namespace std;


Gym::Gym()
{
    numTrainers = 15;
}

void Gym::setNumTrainers(int _numTrainers)
{
    numTrainers = _numTrainers;
}

int Gym::getNumTrainers()
{
    return numTrainers;
}