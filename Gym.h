#ifndef GYM_H
#define GYM_H
#include <string>
#include <iostream>
using namespace std;


class Gym
{
    private:
    int numTrainers;
    bool badgeWon;
    
    public:
    Gym();
    void setNumTrainers(int);
    
    int getNumTrainers();
    
    
    
};



#endif