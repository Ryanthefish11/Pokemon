#include "Player.h"
#include "Game.h"
#include "Pokemon.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;




// Pokemon::Pokemon()
// {
//       name = "";
//     type1 = "";
//     type2 = "";
//     hitPoints = 0;
//     attack = 0;
//     defense = 0;
//     speed = 0;
//     max = 0; 
// }

// Pokemon::Pokemon(string _name, int _HP, int _attack, int _defense, int _speed, int _max, string _type1, string _type2)
// {
// _name = name;
// _HP = hitPoints;
// _attack = attack;
// _defense = defense;
// _speed = speed;
// _max = max;
// _type1 = type1;
// _type2 = type2;


// }

// string Pokemon::getName()
// {
//     return name;
// }

// int Pokemon::getHP()
// {
//     return hitPoints;
// }

// int Pokemon::getAttack()
// {
//     return attack;
// }

// int Pokemon::getDefense()
// {
//     return defense;
// }

// int Pokemon::getMax()
// {
//     return max;
// }

// string Pokemon::getType1()
// {
//     return type1;
// }

// string Pokemon::getType2()
// {
//     return type2;
// }

// void Pokemon::setName(string _name)
// {
//     name = _name;
// }

// void Pokemon::setHP(int _HP)
// {
//     hitPoints = _HP;
// }

// void Pokemon::setAttack(int _attack)
// {
//     attack = _attack;
// }

// void Pokemon::setDefense(int _defense)
// {
//     defense = _defense;
// }

// void Pokemon::setSpeed(int _speed)
// {
//     speed = _speed;
// }

// void Pokemon::setMax(int _max)
// {
//     max = _max;
// }

// void Pokemon::setType1(string _type1)
// {
//     type1 = _type1;
// }

// void Pokemon::setType2(string _type2)
// {
//     type2 = _type2;
// }





int splitTwo (string str, char c, string array[], int size)
{
    if (str.length() == 0) {
         return 0;
     }
    string word = "";
    int count = 0;
    str = str + c;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == c)
        {
            if (word.length() == 0)
                continue;
            array[count++] = word;
            word = "";
        } else {
            word = word + str[i];
        }
    }
    return count ;
}


Player::Player()
{
playerName = "";
numPokeballs = 0;
numPokemon = 0;
xPos = 0;
yPos = 0;
numBadges = 0;

}

Player::Player(string myPlayerName, int myNumPokeballs, int myNumPokemon, int startXPos, int startYPos, int myNumBadges)
{
    playerName = myPlayerName;
    numPokeballs = myNumPokeballs;
    numPokemon = myNumPokemon;
    xPos = startXPos;
    yPos = startYPos;
    numBadges = myNumBadges;
    
}

void Player::setPlayerName(string myPlayerName)
{
    playerName = myPlayerName;
    
}

string Player::getPlayerName()
{
    
    return playerName;
}

void Player::setNumBadges(int myNumBadges)
{
    
    numBadges = myNumBadges;
}
 int Player::getNumBadges()
 {
     return numBadges;
 }
 
 void Player::setNumPokeballs(int myNumPokeballs)
 {
     numPokeballs = myNumPokeballs;
 }
 
 int Player::getNumPokeballs()
 {
     return numPokeballs;
 }
 
 void Player::setNumPokemon(int myNumPokemon)
 {
     numPokemon = myNumPokemon;
 }
 
 int Player::getNumPokemon()
 {
  return numPokemon;   
 }
 
 void Player::setXPos(int _xPos)
 {
     xPos = _xPos;
 }
 
 int Player::getXPos()
 {
     return xPos;
 }
 
 void Player::setYPos(int _yPos)
 {
     
     yPos = _yPos;
 }
 
 int Player::getYPos()
 {
     return yPos;
 }
 
 void Player::setPoints(int _points)
 {
     points = _points;
 }
 
int Player::getPoints()
{
    return points;
}

void Player::setNumFree(int _numFree)
{
    numFree = _numFree;
}

int Player::getNumFree()
{
    return numFree;
}


void Player::playerMove(int xChange, int yChange)
{
    Player myPlayer;
    Game game;
    if(xChange == 1 && yChange == 0)
    {
    
            setXPos(getXPos() + 1); 
 
    }
    if(xChange == -1 && yChange == 0)
    {
        setXPos(getXPos() - 1);
    }
    if(yChange == 1 && xChange == 0)
    {
        setYPos(getYPos() + 1);
    }
    if(yChange == -1 && xChange == 0)
    {
       
        
        setYPos(getYPos() - 1);
    }
    
    
}

