#ifndef POKEMON_H
#define POKEMON_H
#include <iostream>
#include <string>
// #include "Game.h"
using namespace std;

class Pokemon
{
   private:
        string name;
        string type1;
        string type2;
        int hitPoints;
        int attack;
        int defense;
        int speed;
        int max;
        // bool hasFainted;



    public:
        Pokemon();
        Pokemon(string name, int hitPoints, int attack, int defense, int speed, int max, string type1, string type2);
        friend class Game;
        string getName();
        int getHP();
        int getAttack();
        int getDefense();
        int getSpeed();
        int getMax();
        string getType1();
        string getType2();
        

        void setName(string name);        
        void setHP(int hitPoints);        
        void setAttack(int attack);        
        void setDefense(int defense);
        void setSpeed(int speed);        
        void setMax(int max);        
        void setType1(string type1);
        void setType2(string type2);

};

#endif