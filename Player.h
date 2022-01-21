#ifndef PLAYER_H
#define PLAYER_H
#include "Pokemon.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Player
{
    private: 
    
    // Pokemon pokeDex[100];
        string playerName;
        int numPokeballs;
        int numPokemon;
        int xPos;
        int yPos;
        int numBadges;
        int points;
        int numFree;
        
        
    public:
    friend class Game;
    friend class Pokemon;
        Player();
        Player(string myPlayerName, int myNumPokeballs, int myNumPokemon, int startXPos, int startYPos, int myNumBadges);
       void addPokemon(string);
        void setNumBadges(int);
        void setPlayerName(string);
        void setNumPokeballs(int);
        void setNumPokemon(int);
        void managePokedex(string);
        void setXPos(int);
        void setYPos(int);
        void setPokeSuite(string);
        void playerMove(int, int);
        void setPoints(int);
        void setNumFree(int);
   
        
        string getPokemon();
        int getNumBadges();
        string getPokeSuite();
        int getXPos();
        int getYPos();
        string getPlayerName();
        int getNumPokeballs();
        int getNumPokemon();
        string getPokedex();
        int getPoints();
        int getNumFree();
   
    
    
};


#endif