// #include "Player.h"
#include "Game.h"
#include "Pokemon.h"
#include "Player.h"
#include "Gym.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <time.h>
#include <unistd.h>
#include <math.h>



using namespace std;


int split (string str, char c, string array[], int size)
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


Game::Game()
{
     maxRow = 29;
     maxColumn = 37;
     pokeList;
}






void Game::loadMap(string filename,int xStart,int yStart)   //loads the map file
{
    
    bool isWater = false;
     ifstream mapFile;
     mapFile.open(filename);
    
     if(mapFile.is_open())
     {
             
             for(int i = 0; i < maxRow; i++)
            {
                for(int j = 0; j < maxColumn; j++)
                {
                   mapFile >> fields[i][j];
                    
                    
                    
                    if(fields[i][j] == 'w')
                    {
                      fields[i][j] = '~';
                      
                    }
                    if(fields[i][j] == 'p')
                    {
                         fields[i][j] = ' ';
                    }
                    if(fields[i][j] == ',')
                    {
                         fields[i][j] = ' ';
                    }
                    if(fields[i][j] == ' ' && fields[i][j+1] == '~' && fields[i][j+2] == ' ')
                    {
                        fields[i][j] = '~';
                    }

                    if(i == yStart && j == xStart && fields[i][j] != '~')
                    {
                        fields[i][j] = '@';
                    }
                    
                    if(i == yStart && j == xStart && fields[i][j] == '~')
                    {
                        
                        cout << "Cannot swim!" << endl;
                        
                    }
                    

                    
                
                    
                }
                
            }
            for(int i = yStart - 6; i < yStart + 6; i++)
            {
                for(int j = xStart - 6; j < xStart + 6; j++)
                {
  
                    if(fields[i][j] == '~')
                    {
                        cout << "\u001b[46m~\u001b[0m";  
                    }
                    else if(fields[i][j] == '@')
                    {
                        cout << "\u001b[1m\u001b[33m@\u001b[0m";
                    }
                    else if(fields[i][j] == ' ')
                    {
                        cout << "\u001b[42m \u001b[0m";
                    }
                    else if(fields[i][j] == 'G')
                    {
                        cout << "\u001b[45mG\u001b[0m";
                    }
                    else if(fields[i][j] == 'C')
                    {
                        cout << "\u001b[45;1mC\u001b[0m";
                    }
                    else if(fields[i][j] == 'X')
                    {
                    cout << "\u001B[41mX\u001b[0m";
                    }
                    else
                    {
                        cout << "\u001b[42m \u001b[0m";
                    }
                }
                cout << endl;
            }
            
            
     }
}
     
bool Game::checkCollision(int xStart, int yStart)   //checks if player is not out of bounds
{
ifstream mapFile;
     mapFile.open("pokemap.txt");
    
     if(mapFile.is_open())
     {
             
             for(int i = 0; i < maxRow; i++)
            {
                for(int j = 0; j < maxColumn; j++)
                {
                   mapFile >> fields[i][j];
                    
                    
                    
                    if(fields[i][j] == 'w')
                    {
                      fields[i][j] = '~';
                    }
                    if(fields[i][j] == 'p')
                    {
                         fields[i][j] = ' ';
                    }
                    if(fields[i][j] == ',')
                    {
                         fields[i][j] = ' ';
                    }
                    if(fields[yStart][xStart] == '~' || fields[yStart][xStart] == '~')
                    {
                        return true;
                    }
                    
                    if(fields[yStart][xStart] == 'X' || fields[yStart][xStart] == 'X')
                    {
                        return true;
                    }
                    
                    else
                    {
                        return false;
                    }

}
}
}
}


void Game::loadPokemon(string filename) //loads all pokemon from file
{
    int count = 8;
    string name;
    int hitPoints;
    int attack;
    int defense;
    int speed;
    int max; 
    char comma;
    string type1;
    string type2;
    string line = "";
    Pokemon pokes;   
    
    
    ifstream pokeFile;
    pokeFile.open(filename);
    
    
    if(pokeFile.is_open())
    {
        for(int i = 0; i < 120; i++)
        {
        
        getline(pokeFile, line);
        
           
            split(line, ',', stuff, 8);
            
       
            pokes.setName(stuff[0]);
            pokes.setHP(stoi(stuff[1]));
            pokes.setAttack(stoi(stuff[2]));
            pokes.setDefense(stoi(stuff[3]));
            pokes.setSpeed(stoi(stuff[4]));
            pokes.setMax(stoi(stuff[5]));
            pokes.setType1(stuff[6]);
            pokes.setType2(stuff[7]);
        
            
                pokeList.push_back(pokes);
           
         count++;
        }
        
        
    }
        

    }   
   

 void Game::addPokemon(string pokeAdd)  //adds pokemon to the active Poke vector
 {
  string name;
 
  int hitPoints;
  int attack;
  int defense;
  int speed;
  string type1;
  string type2;
  string line;
    
    ifstream pokeFile;
    pokeFile.open("pokemon.txt");
    
    Pokemon pokes;
    string stuff[8];
    Player myPlayer;
    
    if(pokeFile.is_open())
    {
        
    
    for(int i = 0; i < 120; i++)
    {
        getline(pokeFile, line);
        split(line, ',', stuff, 8);

        
        pokes.setName(stuff[0]);
        
        if(pokes.getName() == pokeAdd)
        {
            pokes.setName(stuff[0]);
            pokes.setHP(stoi(stuff[1]));
            pokes.setAttack(stoi(stuff[2]));
            pokes.setDefense(stoi(stuff[3]));
            pokes.setSpeed(stoi(stuff[4]));
            pokes.setMax(stoi(stuff[5]));
            pokes.setType1(stuff[6]);
            pokes.setType2(stuff[7]);
            
            if(myPlayer.getNumPokemon() <= 6)
            {
                activePoke.push_back(pokes);
            }
            
            myPlayer.setNumPokemon(myPlayer.getNumPokemon() + 1);
        }
        
    }
    cout << activePoke[0].getName() << endl;
    }
   
}



void Game::setTrainerPokes()    //sets pokemon to Trainers pokemon vector
{
int count = 0;



while(count < 15)
{
    srand(time(0));
for(int j = 0; j < activePoke.size(); j++)
{
    for(int k = 0; k < 120; k++)
    {
        if(activePoke[j].getName() != pokeList[k].getName())
        {
           
           int i = rand() % 120; 
         
              trainerPokes.push_back(pokeList[i]);
              count++; 
              
           
        }
    }
}
}
}
 
 
void Game::setRandomPokes() //sets random Pokemon to randomPoke vector
{
int count = 0;
srand(time(0));


while(count < 20)
{
for(int j = 0; j < trainerPokes.size(); j++)
{
    
        int i = rand() % 120; 
        if(trainerPokes[j].getName() != pokeList[i].getName())
        {
           

              randomPokes.push_back(pokeList[i]);
              count++; 
           
        }
    
}
}
    
}

bool Game::encounterRandom()    //chances of encountering a random Pokemon
{
    srand(time(0));
    if(randomPokes.size() > 0)
    {
    int chances = rand() % 100;
    if(chances < 5)
    {
        return true;
    }
    else
    {
        return false;
    }
    }
    else
    {
        return false;
    }
}



void Game::tryLuck()    //gives a 15% chance of free pokemon, 45% chance of active pokemon gaining 15 HP and 
{                       //10% chance of Pokemon getting food poisoning
    Player myPlayer;
    int count;
    srand(time(0));
    if(randomPokes.size() > 0)
    {
        int chances = rand() % 100;
        if(chances < 15)
        {
            cout << "A Pokemon has been found!! Attempting to catch. . ." << endl;
            sleep(2);
            int catchChance = rand() % 100;
            if(catchChance < 50)
            {
                cout << "You have captured " << randomPokes[0].getName() << " for free!!" << endl << endl;

                
                activePoke.push_back(randomPokes[0]);
                sleep(1);
                
            }
            else
            {
                cout << "Unsuccessful capture attempt" << endl;
                sleep(1);
            }
        }
        if(chances > 15 && chances < 60)
        {
            cout << "One of your Pokemon have sniffed out a PokeMeal!!" << endl << "That Pokemon has gained 15 HP" << endl << endl;
        while(count <= 15)
                    {
                for(int i = 0; i < 120; i++)
                {
                    
                    if(activePoke[0].getName() == pokeList[i].getName())
                    {
                        
                        if(activePoke[0].getHP() <= pokeList[i].getHP())
                        {
                            activePoke[0].setHP(activePoke[0].getHP() + 1);
                            count++;
                        }
                        else
                        {
                            cout << "Your Pokemon is already at full health!" << endl << endl;
                            return;
                        }
                    }
                }
            }
        }
        if(chances > 60 && chances < 70)
        {
            if(activePoke.size() > 1)
            {
            int size = activePoke.size();
            int deathChance = rand() % size;
            cout << "Oh No!! " << activePoke[deathChance].getName() << " ate a rotten PokeMeal and has died!!" << endl << endl; 
            activePoke.erase(activePoke.begin() + deathChance);
            }
            else
            {
                cout << "No luck for you today!" << endl << endl;
            }
        }
        // if(chances >= 70 && chances <= 80)
        // {
        //     cout << "Thinking it smelled a delicious Pokemeal, " << endl << activePoke[0].getName() << " bumped into you, causing some Pokeballs to fall out of your pack!!" << endl << endl;
        //     int lostPokeballs = rand() % 6;
        //     sleep(1);
        //     cout << "You have lost " << lostPokeballs << " Pokeballs!" << endl;
        //     myPlayer.setNumPokeballs(myPlayer.getNumPokeballs() - lostPokeballs);
        //     sleep(1);
        // }
        if(chances >= 70 && chances <= 100)
        {
            cout << "No luck for you today!" << endl << endl;
        }
    }
    
}


void Game::randomFight()    //function where the fight between player and random pokemon takes place
{
  
    int numRandom = randomPokes.size();
    bool startMenu = true;
    bool quit = false;
    bool playersTurn;
    bool randomsTurn;
    bool fight = true;
    int startOptions;
    int attackRand;
    int defenseRand;
    int count = 1;
    int counter;
   
    Player myPlayer;
     int maxHP = randomPokes[0].getHP();
    
    if(activePoke[0].getSpeed() > randomPokes[0].getSpeed())
    {
        playersTurn = true;
        randomsTurn = false;
    }   
    if(activePoke[0].getSpeed() < randomPokes[0].getSpeed())
    {
        playersTurn = false;
        randomsTurn = true;
    }   
    
    while(!quit)
    {

        
    while(startMenu = true)
    {
    cout << "You have encountered a wild Pokemon!" << endl;
    cout << "Wild Pokemon: " << randomPokes[0].getName()
    << " HP: " << randomPokes[0].getHP() 
    << " Atk: " << randomPokes[0].getAttack() 
    << " Def: " << randomPokes[0].getDefense()
    << " Spd: " << randomPokes[0].getSpeed()
    << " Max: " << randomPokes[0].getMax() << endl << endl;
    
           
    cout << "Your active Pokemon:" << endl;
    cout << "Name: " << activePoke[0].getName() 
    << ", HP: " << activePoke[0].getHP() 
    << " Atk: " << activePoke[0].getAttack() 
    << " Def: " << activePoke[0].getDefense() 
    << " Spd: " << activePoke[0].getSpeed() 
    << " Max: " << activePoke[0].getMax() << endl << endl;
        int countTurn = 0;
        sleep(1);
    cout << "Which would you like to do?" << endl << endl;
    cout << "1. Fight" << endl;
    cout << "2. Switch active Pokemon" << endl;
    cout << "3. Attempt to flee" << endl;
    cin >> startOptions;
    
    startMenu = false;
    
    switch(startOptions)
    {
        case 1:
                {
                    
                    if(activePoke[0].getHP() <= 0)
                    {
                        cout << "That Pokemon has fainted!! Please choose again." << endl << endl;
                        sleep(1);
                        startMenu = true;
                        break;
                    }
                    

                    
                    fight = true;
                    int myAttack = activePoke[0].getAttack();
                    int myDefense = activePoke[0].getDefense();
                    int randomAttack = randomPokes[0].getAttack();
                    int randomDefense = randomPokes[0].getDefense();
                   
                   
                       srand(time(0));
                        
                        while(fight == true)
                         {
                             
                            if(countTurn % 2 == 0) ////////////////////
                            {
                                startMenu = true;
                                fight = false;
                            
                            
                          
                           while(playersTurn == true)
                           {
                           if(activePoke[0].getHP() > 0 || randomPokes[0].getHP() > 0)
                            sleep(1);
                            cout << "\u001b[34;1mIt is " << activePoke[0].getName() << "'s turn to attack!\u001b[0m" << endl << endl;
                            sleep(1);
                           attackRand = rand() % myAttack;
                           defenseRand = rand() % randomDefense;
                          
                            if(attackRand > defenseRand)
                            {
                                cout << "\u001b[41m*****BAM!*****\u001b[0m" << endl << endl << endl;
                                cout << activePoke[0].getName() << " has struck " << randomPokes[0].getName() << "!!" << endl << endl;
                                randomPokes[0].setHP(randomPokes[0].getHP() - (attackRand - defenseRand));
                                sleep(1); //change to 2
                                cout << randomPokes[0].getName() << "'s health is: " << randomPokes[0].getHP() << endl;

                                countTurn++;
                               
                                playersTurn = false;
                                randomsTurn = true;
                            }
                            if(attackRand < defenseRand)
                            {
                                cout << "\u001b[36;1m========" << activePoke[0].getName() << " Missed!========\u001b[0m" << endl << endl << endl;
                                sleep(1);
                                countTurn++;
                                playersTurn = false;
                             
                                randomsTurn = true;
                                
                            }
                            
                            
                            if(activePoke[0].getHP() <= 0 || randomPokes[0].getHP() <= 0)
                            {
                                cout << randomPokes[0].getName() << " Has fainted!!" << endl;
                                int numPokeballs = myPlayer.getNumPokeballs();

                                fight = false;
                                startMenu = true;
                                playersTurn=false;
                                quit = true;
                                return;
                            }
                          }
                          while(randomsTurn == true)
                          {
                            if(activePoke[0].getHP() > 0 || randomPokes[0].getHP() > 0)
                            {   
                                sleep(1);
                                cout << "\u001b[31;1mIt is " << randomPokes[0].getName() << "'s turn to attack!\u001b[0m" << endl << endl;
                                sleep(1);   //change to 2
                                attackRand = rand() % randomAttack;
                                defenseRand = rand() % myDefense; 
                                
                                if(attackRand > defenseRand)
                                {
                                    cout << "\u001b[41m*****BAM!*****\u001b[0m" << endl << endl << endl;
                                     cout << randomPokes[0].getName() << " has struck " << activePoke[0].getName() << "!!" << endl << endl;
                                    activePoke[0].setHP(activePoke[0].getHP() - (attackRand - defenseRand));
                                    sleep(1);
                                    cout << activePoke[0].getName() << "'s Health is: " << activePoke[0].getHP() << endl << endl;
                                    countTurn++;

                                    
                                    playersTurn = true;
                                    randomsTurn = false;
                                   
                                    
                                    
                                    
                                    
                                }
                                if(attackRand < defenseRand)
                                {
                                    cout << "\u001b[36;1m========" << randomPokes[0].getName() << " Missed!========\u001b[0m" << endl << endl << endl;
                                    sleep(1);
                                    countTurn++;

                                    playersTurn = true;
                                    randomsTurn = false;
                                    
                                    
                                }
                                if(activePoke[0].getHP() <= 0 || randomPokes[0].getHP() <= 0)
                                {
                                    cout << activePoke[0].getName() << " Has fainted!" << endl;
                                    activePoke[0].setHP(0);
                                    
                                    fight = false;
                                    
                                    randomsTurn = false;
                                    startMenu = true;
                                    for(int i = 0; i < activePoke.size(); i++)
                                    {
                                        if(activePoke[i].getHP() <= 0)
                                        {
                                            quit = true;
                                        }
                                    }
                                    
                                    
                                    break;
                                }
                            }
                          }
                          
                       }
                         }  
                         break;
                   }
                   case 2:
                   {
                       cout << "Which Pokemon would you like to assign as your active Pokemon?" << endl << endl;
                        for(int i = 0; i < activePoke.size(); i++)
                        {
                            cout << i << ". " << activePoke[i].getName() << " HP: " << activePoke[i].getHP() << endl;
                        }
                        
                        int index;              
                        cin >> index;   //index number of pokemon in suite
                        if(index >= activePoke.size())
                        {
                            cout << "Try again" << endl;
                            sleep(1);
                            cin.clear();
                        }
                        else
                        {
                        swap(activePoke[0], activePoke[index]);
                        cout << "You have chosen: " << activePoke[0].getName() << endl;
                        }
                        startMenu = true;
                        break;
                       
                   }
                   
                   case 3:
                   {
                      
                      int chancesOfFlee;
                      srand(time(0));
                      int A = activePoke[0].getSpeed();
                      int B = (randomPokes[0].getSpeed() / 4) % 256;
                      int C = count;
                      chancesOfFlee = ((((A * 32) / B) + 30) * C);
                      
                      count++;
                      if(chancesOfFlee > 255)
                      {
                          quit = true;
                          return;
                      }
                      else
                      {
                          int lastHope = rand() % 255;
                          if(lastHope > chancesOfFlee)
                          {
                              quit = true;
                              return;
                          }
                          else
                          {
                              break;
                          }
                      }
                       
                   }
            
            
            
            
            
            
            
            
        }
        
        
    }
    }
    
    
}




void Game::restOption() //heals all pokes by 2 HP at a cost of 1 pokeball
{
    bool healed = false;
    Player myPlayer;
    for(int i = 0; i < activePoke.size(); i++)
    {
        for(int j = 0; j < 120; j++)
        {
            if(activePoke[i].getName() == pokeList[j].getName())
            {
                
                    activePoke[i].setHP(activePoke[i].getHP() + 2);
                    cout << activePoke[i].getName() << " has been healed by 2 HP!" << endl << endl;
            }
                
                  
                
            }
        }
        
        if(healed == false)
        {
            cout << "Your Pokemon are already at full health." << endl << endl;
        }
       
    }
    
    

        
bool Game::enterGym(int xStart, int yStart) // determines if player is on Gym tile
{
    
    ifstream mapFile;
     mapFile.open("pokemap.txt");
    
     if(mapFile.is_open())
     {
             
             for(int i = 0; i < maxRow; i++)
            {
                for(int j = 0; j < maxColumn; j++)
                {
                   mapFile >> fields[i][j];

                    if(fields[yStart][xStart] == 'G')
                    {
                        return true;
                    }
                    if(fields[yStart][xStart] != 'G')
                    {
                        return false;
                    }

}
}
}
}
    

bool Game::enterPokeCenter(int xStart, int yStart) // determines if Player is on Pokecenter tile
{
    {
    
    ifstream mapFile;
     mapFile.open("pokemap.txt");
    
     if(mapFile.is_open())
     {
             
             for(int i = 0; i < maxRow; i++)
            {
                for(int j = 0; j < maxColumn; j++)
                {
                   mapFile >> fields[i][j];

                    if(fields[yStart][xStart] == 'C')
                    {
                        return true;
                    }
                    if(fields[yStart][xStart] != 'C')
                    {
                        return false;
                    }

}
}
}
}
    
}

void Game::pokeCenter()     //heals all Pokemon and gives option to swap pokemon
{
    for(int i = 0; i < activePoke.size(); i++)
    {
        for(int j = 0; j < 120; j++)
        {
            if(activePoke[i].getName() == pokeList[j].getName())
            {
                activePoke[i].setHP(pokeList[j].getHP());
            }
        }
        
    }
    int change;
    cout << "Welcome to the PokeCenter!" << endl;
    cout << "All of your Pokemon have been healed." << endl;
    cout << "Do you want to change your PokeSuite?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No (quit)" << endl;
    cin >> change;
    switch(change)
    {
        case 1:
        {
                                    
            cout << "Which Pokemon would you like to assign as your active Pokemon?" << endl << endl;
            for(int i = 0; i < activePoke.size(); i++)
            {
                cout << i + 1 << ". " << activePoke[i].getName() << endl;
            }
            
            int index;              // make menu to ask which pokemon to pick from suite
            cin >> index;   //index number of pokemon in suite
            
            swap(activePoke[0], activePoke[index - 1]);
            cout << "You have chosen: " << activePoke[0].getName() << endl;
           
            break;
        }
        
        case 2:
        {
            return;
        }
    }
    
    
}




void Game::encounterTrainer()       //The fight process for encountering Trainers Pokemon
{
    Gym myGym;
    Game game;
    Player myPlayer;
    int encounterChoice;
   bool endCombat = false;
   bool fight = true;
   int attackRand;
   int defenseRand;
  bool playersTurn;
  bool trainersTurn;
  bool fightMenu = true;
  
   int maxHP = trainerPokes[0].getHP();
   
           if(activePoke[0].getSpeed() > trainerPokes[0].getSpeed())
        {
            playersTurn = true;
            trainersTurn = false;
        }   
        if(activePoke[0].getSpeed() < trainerPokes[0].getSpeed())
        {
            playersTurn = false;
            trainersTurn = true;
        }  
   
   while(!endCombat)
      {
      
      
      
   if(myGym.getNumTrainers() > 0)
   {
     


           cout << "=== You've arrived at the Gym and the Trainer is ready to fight!! ===" << endl << endl;

          while(fightMenu = true)
      { 
           cout << "The Trainer's active Pokemon:" << endl;
           cout << "Name: " << trainerPokes[0].getName() 
           << " HP: " << trainerPokes[0].getHP() 
           << " Atk: " << trainerPokes[0].getAttack() 
           << " Def: " << trainerPokes[0].getDefense()
           << " Spd: " << trainerPokes[0].getSpeed()
           << " Max: " << trainerPokes[0].getMax() << endl << endl;
           
           cout << "Your active Pokemon:" << endl;
           cout << "Name: " << activePoke[0].getName() 
           << ", HP: " << activePoke[0].getHP() 
           << " Atk: " << activePoke[0].getAttack() 
           << " Def: " << activePoke[0].getDefense() 
           << " Spd: " << activePoke[0].getSpeed() 
           << " Max: " << activePoke[0].getMax() << endl << endl;
                 
                int countTurn = 0;
               cout << "Which would you like to do?" << endl << endl;
               cout << "1. Fight" << endl;
               cout << "2. Switch active Pokemon" << endl;
               cout << "3. Leave the gym" << endl;
               
               cin >> encounterChoice;
                fightMenu = false;
                switch(encounterChoice)
                {
                case 1:
                {
                    if(activePoke[0].getHP() <= 0)
                    {
                        cout << "That Pokemon has fainted! Choose another option. " << endl << endl;
                        sleep(1);
                        fightMenu = true;
                        break;
                    }
                    

                    
                    fight = true;
                    int myAttack = activePoke[0].getAttack();
                    int myDefense = activePoke[0].getDefense();
                    int trainerAttack = trainerPokes[0].getAttack();
                    int trainerDefense = trainerPokes[0].getDefense();
                   
                   
                       srand(time(0));
                        
                        while(fight == true)
                         {
                             int other = countTurn;
                            if(countTurn % 2 == 0) ////////////////////
                            {
                                fight = false;
                                fightMenu = true;
                                cin.ignore();
                            
                            
                            
                            
                          
                           while(playersTurn == true)
                           {
                           if(activePoke[0].getHP() > 0 || trainerPokes[0].getHP() > 0)
                            
                            cout << "\u001b[34;1mIt is " << activePoke[0].getName() << "'s turn to attack!\u001b[0m" << endl << endl;
                            sleep(1);
                           attackRand = rand() % myAttack;
                           defenseRand = rand() % trainerDefense;
                          
                            if(attackRand > defenseRand)
                            {
                                cout << "\u001b[41m*****BAM!*****\u001b[0m" << endl << endl << endl;
                                cout << activePoke[0].getName() << " has struck " << trainerPokes[0].getName() << "!!" << endl << endl;
                                trainerPokes[0].setHP(trainerPokes[0].getHP() - (attackRand - defenseRand));
                                sleep(1); //change to 2
                                cout << trainerPokes[0].getName() << "'s health is: " << trainerPokes[0].getHP() << endl;

                                countTurn++;
                               
                                playersTurn = false;
                                trainersTurn = true;
                            }
                            if(attackRand < defenseRand)
                            {
                                cout << "\u001b[36;1m========" << activePoke[0].getName() << " Missed!========\u001b[0m" << endl << endl << endl;
                                sleep(1);
                                countTurn++;
                                playersTurn = false;
                             
                                trainersTurn = true;
                                
                            }
                            
                            
                            if(activePoke[0].getHP() <= 0 || trainerPokes[0].getHP() <= 0)
                            {
                                cout << trainerPokes[0].getName() << " Has fainted!!" << endl;
                                int numPokeballs = myPlayer.getNumPokeballs();

                                fight = false;
                                fightMenu = true;
                                playersTurn=false;
                                endCombat = true;
                                return;
                            }
                          }
                          while(trainersTurn == true)
                          {
                            if(activePoke[0].getHP() > 0 || trainerPokes[0].getHP() > 0)
                            {   
                                sleep(1);
                                cout << "\u001b[31;1mIt is " << trainerPokes[0].getName() << "'s turn to attack!\u001b[0m" << endl << endl;
                                sleep(1);   //change to 2
                                attackRand = rand() % trainerAttack;
                                defenseRand = rand() % myDefense; 
                                
                                if(attackRand > defenseRand)
                                {
                                    cout << "\u001b[41m*****BAM!*****\u001b[0m" << endl << endl << endl;
                                     cout << trainerPokes[0].getName() << " has struck " << activePoke[0].getName() << "!!" << endl << endl;
                                    activePoke[0].setHP(activePoke[0].getHP() - (attackRand - defenseRand));
                                    sleep(1);
                                    cout << activePoke[0].getName() << "'s Health is: " << activePoke[0].getHP() << endl << endl;
                                    countTurn++;

                                    trainersTurn = false;
                                    playersTurn = true;
                                    
                                   
                                    
                                    
                                    
                                    
                                }
                                if(attackRand < defenseRand)
                                {
                                    cout << "\u001b[36;1m========" << trainerPokes[0].getName() << " Missed!========\u001b[0m" << endl << endl << endl;
                                    sleep(1);
                                    countTurn++;
                                    trainersTurn = false;
                                    playersTurn = true;
                                    
                                    
                                    
                                }
                                if(activePoke[0].getHP() <= 0 || trainerPokes[0].getHP() <= 0)
                                {
                                    cout << activePoke[0].getName() << " Has fainted!" << endl;
                                    activePoke[0].setHP(0);
                                    
                                    trainersTurn = false;
                                    fightMenu = true;
                                    fight = false;
                                    
                                    
                                    
                                    break;
                                }
                            }
                          }
                            } 
                           
                       }
                         
                   }
                   break;
                
                   case 2:
                   {
                       
                       
                        cout << "Which Pokemon would you like to assign as your active Pokemon?" << endl << endl;
                        for(int i = 0; i < activePoke.size(); i++)
                        {
                            cout << i << ". " << activePoke[i].getName() << endl;
                        }
                        
                        int index;              // make menu to ask which pokemon to pick from suite
                        cin >> index;   //index number of pokemon in suite
                        if(index >= activePoke.size())
                        {
                            cout << "Not an active Pokemon! Try again" << endl;
                            break;
                        }
                        else
                        {
                        swap(activePoke[0], activePoke[index]);
                        cout << "You have chosen: " << activePoke[0].getName() << endl;
                        }
                        fightMenu = true;
                        
                        break;
                       
                   }
                   
                   case 3:
                   {
                      endCombat = true;
                      return;
                   }
                   
                   
               }
                
           }
           
           }
           
           endCombat = true;
           
           
       }
}
  
  
bool Game::trainerIsDead(string trainerName)    //checks if the trainers pokemon has fainted
{
    if(trainerPokes[0].getName() == trainerName)
    {
        if(trainerPokes[0].getHP() <= 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool Game::randomIsDead(string randomName)  //checks if the random pokemon has fainted
{
    if(randomPokes[0].getName() == randomName)
    {
        if(randomPokes[0].getHP() <= 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}