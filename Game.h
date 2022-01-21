#ifndef GAME_H
#define GAME_H
#include "Pokemon.h"
// #include "Player.h"
#include <string>

#include <vector> 
using namespace std;


class Game
{
 private:  
    int maxRow=31;
    int maxColumn=38;
    char fields[31][38];
    char offLimits;
    
    string stuff[8];


    
    
 public:
    vector <Pokemon> pokeList;
    vector <Pokemon> trainerPokes;
    vector <Pokemon> activePoke;
    vector <Pokemon> randomPokes;
    Game();
   friend class Player;
   friend class Pokemon;
    void setOffLimits(char);
    char getOffLimits();
    void loadMap(string filename, int xStart, int yStart);
    char getElem(int row, int col);
    void setElem(int row, int col, char element);
    void displayMiniMap();
    void loadPokemon(string filename);
    bool checkCollision(int, int);
    void restOption();
    void setTrainerPokes();
    bool enterGym(int, int);
    void encounterTrainer();
    void addPokemon(string);
    bool enterPokeCenter(int, int);
    void pokeCenter();
    bool badgeEarned(int, int);
    void setRandomPokes();
    void randomPokeMove();
    bool encounterRandom();
    void randomFight();
    void tryLuck();
    bool trainerIsDead(string);
    bool randomIsDead(string);
    bool winFromType();
};


#endif