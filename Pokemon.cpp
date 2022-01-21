#include "Pokemon.h"
#include "Player.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

Pokemon::Pokemon()
{
       name = "";
    type1 = "";
    type2 = "";
    hitPoints = 0;
    attack = 0;
    defense = 0;
    speed = 0;
    max = 0; 
}

Pokemon::Pokemon(string _name, int _HP, int _attack, int _defense, int _speed, int _max, string _type1, string _type2)
{
_name = name;
_HP = hitPoints;
_attack = attack;
_defense = defense;
_speed = speed;
_max = max;
_type1 = type1;
_type2 = type2;


}

string Pokemon::getName()
{
    return name;
}

int Pokemon::getHP()
{
    return hitPoints;
}

int Pokemon::getAttack()
{
    return attack;
}

int Pokemon::getDefense()
{
    return defense;
}

int Pokemon::getMax()
{

    return max;
}

string Pokemon::getType1()
{
    return type1;
}

string Pokemon::getType2()
{
    return type2;
}

void Pokemon::setName(string _name)
{
    name = _name;
}

void Pokemon::setHP(int _HP)
{
    hitPoints = _HP;
}

void Pokemon::setAttack(int _attack)
{
    attack = _attack;
}

void Pokemon::setDefense(int _defense)
{
    defense = _defense;
}

void Pokemon::setSpeed(int _speed)
{
    speed = _speed;
}

int Pokemon::getSpeed()
{
    return speed;
}

void Pokemon::setMax(int _max)
{
    max = _max;
}

void Pokemon::setType1(string _type1)
{
    type1 = _type1;
}

void Pokemon::setType2(string _type2)
{
    type2 = _type2;
}

