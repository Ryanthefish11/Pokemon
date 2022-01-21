
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "Gym.h"
#include "Player.h"
#include "Game.h"
#include "Pokemon.h"
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;


    
// void encounterTrainer()
// {
//     Gym myGym;
//     Game game;
//     int i = myGym.getNumTrainers();

        
//         cout << game.trainerPokes[0].getName() << endl;    
    
   
    
    
// }
        


void travelOptions()
{
    cout <<"=== Which direction would you like to go? ===" << endl;
     cout << "Press 8 to go North" << endl;
     cout << "Press 4 to go West" << endl;
     cout << "Press 5 to go South" << endl;
     cout << "Press 6 to go East" << endl;
     cout << "Press 0 to go back" << endl;
}



void chooseFirstPoke()
{
    cout << "Please choose from the following Pokemon:" << endl;
    cout << "1. Pikachu" << endl;
    cout << "2. Charmander" << endl;
    cout << "3. Squirtle" << endl;
    cout << "4. Bulbasaur" << endl;
}

void waterWarning()
{
    cout << "Your Pokemon can't swim, neither can you! Try another move." << endl;
}

int chanceFlee()
{
        srand(time(nullptr));
    
    int value = rand() % 100 + 1;
    
    return value;   //if value greater than 60, flee failed
    
}

void giveOptions()
{
    cout << "=== Please choose from the following options ===" << endl << endl;
    
    cout << "1. Travel" << endl;
    cout << "2. Rest" << endl;
    cout << "3. Try your luck" << endl;
    cout << "4. Quit the game" << endl;

}


int main()
{   

    
    Game game;
    
    string addName = "";
    string name;
    Player myPlayer;
    Pokemon myPoke;
    Gym myGym;
    int randomCount = 0;
    bool firstPokeMenu = true;
    int choice = 0;
    bool optionMenu = true;
    int optionChoice = 0;
    int travelChoice= 0;
    bool travelMenu = true;
    bool quit = false;
    
     while(quit == false)
 {    
    cout << "Hello! Welcome to Pokemon!" << endl;
    
    cout << "Please enter your name ";
    getline(cin, name);
    myPlayer.setPlayerName(name);

    
    cout << "Welcome " << myPlayer.getPlayerName() << "!" << endl << endl;
    sleep(1);
    cout << "Before you can begin your Pokemon adventure," << endl << "you must choose a starting Pokemon, courtesy of the Professor." << endl;
      
    while(firstPokeMenu == true)
    {
        chooseFirstPoke();
        cin>>choice;
        switch(choice)
        {
            case 1: //sets active poke to Pikachu
            {
                myPlayer.setXPos(19);
                myPlayer.setYPos(16);
                game.addPokemon("Pikachu");
                cout << "You've picked " << game.activePoke[0].getName() << "!" << endl;
                myPlayer.setNumPokeballs(10);
                firstPokeMenu = false;
                break; 
            }
            
            case 2: //sets active poke to Charmander
            {
                myPlayer.setXPos(18);
                myPlayer.setYPos(7);
                game.addPokemon("Charmander");
                cout << "You've picked " << game.activePoke[0].getName() << "!" << endl;
                myPlayer.setNumPokeballs(10);
                
                firstPokeMenu = false;
                break;
            }
            case 3: //sets active poke to Squirtle
            {
               myPlayer.setXPos(23);
               myPlayer.setYPos(16);
               game.addPokemon("Squirtle");
               cout << "You've picked " << game.activePoke[0].getName() << "!" << endl;
               myPlayer.setNumPokeballs(10);
                firstPokeMenu = false;
                break;
            }
            
            case 4: //Bulbasaur
            {
                myPlayer.setXPos(23);
                myPlayer.setYPos(20);
                game.addPokemon("Bulbasaur");
                cout << "You've picked " << game.activePoke[0].getName() << "!" << endl;
                myPlayer.setNumPokeballs(10);
                firstPokeMenu = false;
                break;
            }
            default:
            {
                cout << "Please choose again" << endl;
                break;
            }
        
        }
         
               
           
    }


    
    game.loadPokemon("pokemon.txt");
    game.loadMap("pokemap.txt", myPlayer.getXPos(), myPlayer.getYPos());
    game.setTrainerPokes();
    game.setRandomPokes();
    bool retryMenu = true;
    
    while(optionMenu == true)
    {  
      
        if(myPlayer.getNumBadges() >= 6)    //Wins game with 6 badges
        {
            cout << "\u001b[46;1m You have earned a total of 6 Badges!! YOU WIN!!!\u001b[0m" << endl << endl;
            cout << "\u001b[46;1m You scored " << myPlayer.getPoints() << " along the way, Nice!!" << endl << endl;
            ofstream resultsFile("results.txt", fstream::app);
            resultsFile << myPlayer.getPlayerName() << ":     " << myPlayer.getPoints() << endl << endl;
            resultsFile.close();
            optionMenu = false;
            quit = true;
            break;
        }
        
        cout << endl << endl;
        cout << "The sun is shining, " << myPlayer.getPlayerName() << "! It's a beautiful day!" << endl << "You have " << myPlayer.getNumPokeballs() << 
        " Pokeballs left and your Pokemon are strong." << endl;
        cout << "Your active Pokemon: " << game.activePoke[0].getName() << ", HP: " << game.activePoke[0].getHP() << " Atk: " << game.activePoke[0].getAttack() << " Def: " << game.activePoke[0].getDefense() << " Spd: " << game.activePoke[0].getSpeed() << " Max: " << game.activePoke[0].getMax() << endl << endl;
        cout << "Number of Badges Earned: " << myPlayer.getNumBadges() << endl << endl;
        giveOptions();
        cin >> optionChoice;
        
        switch(optionChoice)
        {
            case 1:     //travel option
            {   travelMenu = true;
                while(travelMenu == true)
                {
                    travelOptions();
                    cin >> travelChoice;
                    if(cin.fail())
                    {
                        cin.ignore();
                        cin.clear();
                        quit = true;
                    }

                    switch(travelChoice)
                    {
                        case 8: //travel north
                        {
                       
                                                   
                            if(game.checkCollision(myPlayer.getXPos(), myPlayer.getYPos() - 1) == 1)    //if player is going out of bounds
                            {
                                game.loadMap("pokemap.txt", myPlayer.getXPos(), myPlayer.getYPos());        
                                cout << "You cannot swim!! Try another move." << endl;
                            }
                            else
                            {
                        
                                myPlayer.playerMove(0, -1); //moves player north
     
                                if(game.enterPokeCenter(myPlayer.getXPos(), myPlayer.getYPos()) == 1)   //if player is on a pokecenter tile
                                {
                                    game.pokeCenter();
                                    travelMenu = false;
                                    break;
                                }
                                if(game.enterGym(myPlayer.getXPos(), myPlayer.getYPos()) == 1)      //if player is on a gym tile
                                {
                                    cout << "Time to fight" << endl;
                                    sleep(1);
                                    int maxHP = game.trainerPokes[0].getHP();
                                    int myMax = game.activePoke[0].getHP();
                                    game.encounterTrainer();
                            
                            
                                    if(game.trainerIsDead(game.trainerPokes[0].getName()) == 1) //if trainer poke has fainted
                                    {
                                        myPlayer.setNumPokeballs(myPlayer.getNumPokeballs() + 5);
                                        myPlayer.setNumBadges(myPlayer.getNumBadges() + 1);
                                        myPlayer.setPoints(myPlayer.getPoints() + 60);
                                        game.activePoke[0].setHP(myMax);
                                
                                        if(game.activePoke.size() <= 6)
                                        {
                                            game.trainerPokes[0].setHP(maxHP);
                                            game.activePoke.push_back(game.trainerPokes[0]);    //adds trainer pokemon to players collection
                                            game.trainerPokes.erase(game.trainerPokes.begin());
                                            myGym.setNumTrainers((myGym.getNumTrainers() - 1));
                      
                                            for(int j = 0; j < 120; j++)
                                            {
                                                if(game.activePoke[0].getName() == game.pokeList[j].getName())
                                                {
                                                    if(game.activePoke[0].getMax() < game.pokeList[j + 1].getMax())
                                                    {
                                                        swap(game.activePoke[0], game.pokeList[j + 1]); 
                                                        cout << "Your Pokemon has evolved to " << game.activePoke[0].getName() << "!!" << endl << endl; 
                                                        sleep(2);
                                                    }
                                                    else
                                                    {
                                                        cout << "Your Pokemon has already evolved to its max!!" << endl << endl;
                                                        sleep(2);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    travelMenu = false;
                                    break;
                                }
                                if(game.encounterRandom() == 1)     //if player encounters random pokemon
                                {
                                    cout << "You have encountered a Wild Pokemon!" << endl << endl;
                                    sleep(1);
                                    randomCount++;
                            
                                    if(myPlayer.getNumFree() < 2)   //first 2 times encountering random pokemon, gain pokemon for free
                                    {
                                
                                        cout << "You have collected " << game.randomPokes[0].getName() << "!" << endl << endl;
                                        game.activePoke.push_back(game.randomPokes[0]);
                                        game.randomPokes.erase(game.randomPokes.begin());
                                        myPlayer.setNumFree(myPlayer.getNumFree() + 1);
                                        sleep(1);
                                
                                    }
                                    else
                                    {
                                        int maxHP = game.randomPokes[0].getHP();
                                        int myMax = game.activePoke[0].getHP();
                                        game.randomFight();
                                        if(game.randomIsDead(game.randomPokes[0].getName()) == 1)   //if random poke has fainted
                                        {
                                            myPlayer.setPoints(myPlayer.getPoints() + 25);
                                            game.activePoke[0].setHP(myMax);
                                            if(game.activePoke.size() <= 6)
                                            {
                                                game.randomPokes[0].setHP(maxHP);
                                                game.activePoke.push_back(game.randomPokes[0]); //adds random poke to player collection
                                                game.randomPokes.erase(game.randomPokes.begin());

                                                for(int j = 0; j < 120; j++)
                                                {
                                                    if(game.activePoke[0].getName() == game.pokeList[j].getName())
                                                    {
                                                        if(game.activePoke[0].getMax() < game.pokeList[j + 1].getMax())
                                                        {
                                                            swap(game.activePoke[0], game.pokeList[j + 1]);
                                                            cout << "Your Pokemon has evolved to: " << game.activePoke[0].getName() << endl << endl;
                                                            sleep(2);
                                                        }
                                                        else
                                                        {
                                                            cout << "Your Pokemon has already evolved to its max!!" << endl << endl;
                                                            sleep(2);
                                                        }
                                                    }
                                    
                                                }
                                    
                                                myPlayer.setNumPokeballs(myPlayer.getNumPokeballs() + 5);
                                                myPlayer.setNumBadges(myPlayer.getNumBadges() + 1);
                                            }
                                        }
                                    }    
                                }   
                        
                                game.loadMap("pokemap.txt", myPlayer.getXPos(), myPlayer.getYPos());    //loads map
                            }
                            break;
                        }
                        case 4:     //travel west
                        {
                            if(game.checkCollision(myPlayer.getXPos() - 1, myPlayer.getYPos()) == 1)
                            {
                                game.loadMap("pokemap.txt", myPlayer.getXPos(), myPlayer.getYPos());
                                cout << "You cannot swim!! Try another move." << endl;
                            }
                            else
                            {
                                myPlayer.playerMove(-1, 0);
                                if(game.enterPokeCenter(myPlayer.getXPos(), myPlayer.getYPos()) == 1)
                                {
                                    game.pokeCenter();
                                    travelMenu = false;
                                    break;
                                }
                            
                                if(game.enterGym(myPlayer.getXPos(), myPlayer.getYPos()) == 1)
                                {
                                    cout << "Time to fight" << endl;
                                    sleep(1);
                                    int maxHP = game.trainerPokes[0].getHP();
                                    int myMax = game.activePoke[0].getHP();
                                    game.encounterTrainer();
                                
                                    if(game.trainerIsDead(game.trainerPokes[0].getName()) == 1)
                                    {
                                        myPlayer.setNumPokeballs(myPlayer.getNumPokeballs() + 5);
                                        myPlayer.setNumBadges(myPlayer.getNumBadges() + 1);
                                        myPlayer.setPoints(myPlayer.getPoints() + 60);
                                        game.activePoke[0].setHP(myMax);
                                
                                        if(game.activePoke.size() <= 6)
                                        {
                                            game.trainerPokes[0].setHP(maxHP);
                                            game.activePoke.push_back(game.trainerPokes[0]);
                                            game.trainerPokes.erase(game.trainerPokes.begin());
                                            myGym.setNumTrainers((myGym.getNumTrainers() - 1));
                      
                                            for(int j = 0; j < 120; j++)
                                            {
                                                if(game.activePoke[0].getName() == game.pokeList[j].getName())
                                                {
                                                    if(game.activePoke[0].getMax() < game.pokeList[j + 1].getMax())
                                                    {
                                                        swap(game.activePoke[0], game.pokeList[j + 1]); 
                                                        cout << "Your Pokemon has evolved to " << game.activePoke[0].getName() << "!!" << endl << endl; 
                                                        sleep(2);
                                                    }
                                                    else
                                                    {
                                                        cout << "Your Pokemon has already evolved to its max!!" << endl << endl;
                                                        sleep(2);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    travelMenu = false;
                                    break;
                                }
                                if(game.encounterRandom() == 1)
                                {   
                                    cout << "You have encountered a wild Pokemon!" << endl << endl;
                                    sleep(1);
                                    if(myPlayer.getNumFree() < 2)
                                    {
                                    
                                        cout << "You have collected " << game.randomPokes[0].getName() << "!" << endl << endl;
                                        game.activePoke.push_back(game.randomPokes[0]);
                                        game.randomPokes.erase(game.randomPokes.begin());
                                        myPlayer.setNumFree(myPlayer.getNumFree() + 1);
                                        sleep(1);
                                
                                    }
                                    else
                                    {
                                
                                        int maxHP = game.randomPokes[0].getHP();
                                        int myMax = game.activePoke[0].getHP();
                                        game.randomFight();
                                        if(game.randomIsDead(game.randomPokes[0].getName()) == 1)
                                        {
                                            
                                            myPlayer.setPoints(myPlayer.getPoints() + 25);
                                            game.activePoke[0].setHP(myMax);
                                            if(game.activePoke.size() <= 6)
                                            {
                                                game.randomPokes[0].setHP(maxHP);
                                                game.activePoke.push_back(game.randomPokes[0]);
                                                game.randomPokes.erase(game.randomPokes.begin());
    
                                                for(int j = 0; j < 120; j++)
                                                {
                                                    if(game.activePoke[0].getName() == game.pokeList[j].getName())
                                                    {
                                                        if(game.activePoke[0].getMax() < game.pokeList[j + 1].getMax())
                                                        {
                                                            swap(game.activePoke[0], game.pokeList[j + 1]);
                                                            cout << "Your Pokemon has evolved to: " << game.activePoke[0].getName() << endl << endl;
                                                            sleep(2);
                                                        }
                                                        else
                                                        {
                                                            cout << "Your Pokemon has already evolved to its max!!" << endl << endl;
                                                            sleep(2);
                                                        }
                                                    }
                                        
                                                }
                                        
                                                myPlayer.setNumPokeballs(myPlayer.getNumPokeballs() + 5);
                                                myPlayer.setNumBadges(myPlayer.getNumBadges() + 1);
                                        
                                        
                                            }
                                        }
                                    }
                                }
                                game.loadMap("pokemap.txt", myPlayer.getXPos(), myPlayer.getYPos());
                            }
                             break;
                        }
                    
                        case 5:     //travel south
                        {
                            if(game.checkCollision(myPlayer.getXPos(), myPlayer.getYPos() + 1) == 1)
                            {
                                game.loadMap("pokemap.txt", myPlayer.getXPos(), myPlayer.getYPos());
                                cout << "You cannot swim!! Try another move." << endl;
                            }
                            else
                            {
                                myPlayer.playerMove(0, 1);
                                if(game.enterPokeCenter(myPlayer.getXPos(), myPlayer.getYPos()) == 1)
                                {
                                    game.pokeCenter();
                                    travelMenu = false;
                                    break;
                                }
                                if(game.enterGym(myPlayer.getXPos(), myPlayer.getYPos()) == 1)
                                {
                                    cout << "Time to fight" << endl;
                                    sleep(1);
                                
                                    int maxHP = game.trainerPokes[0].getHP();
                                    int myMax = game.activePoke[0].getHP();
                                    game.encounterTrainer();
                                
                                    if(game.trainerIsDead(game.trainerPokes[0].getName()) == 1)
                                    {
                                        myPlayer.setNumPokeballs(myPlayer.getNumPokeballs() + 5);
                                        myPlayer.setNumBadges(myPlayer.getNumBadges() + 1);
                                        myPlayer.setPoints(myPlayer.getPoints() + 60);
                                        game.activePoke[0].setHP(myMax);
                                
                                        if(game.activePoke.size() <= 6)
                                        {
                                            game.trainerPokes[0].setHP(maxHP);
                                            game.activePoke.push_back(game.trainerPokes[0]);
                                            game.trainerPokes.erase(game.trainerPokes.begin());
                                            myGym.setNumTrainers((myGym.getNumTrainers() - 1));
                      
                                            for(int j = 0; j < 120; j++)
                                            {
                                                if(game.activePoke[0].getName() == game.pokeList[j].getName())
                                                {
                                                    if(game.activePoke[0].getMax() < game.pokeList[j + 1].getMax())
                                                    {
                                                        swap(game.activePoke[0], game.pokeList[j + 1]); 
                                                        cout << "Your Pokemon has evolved to " << game.activePoke[0].getName() << "!!" << endl << endl; 
                                                        sleep(2);
                                                  
                                                    }

                                                    else
                                                    {
                                                        cout << "Your Pokemon has already evolved to its max!!" << endl << endl;
                                                        sleep(2);
                                                    }
                                                }
                                            }
                                        }
                                
                                        cout << "You have earned a badge from this gym!" << endl << endl;
                                        sleep(2);
                                    }
                                    travelMenu = false;
                                    break;
                                }
                                if(game.encounterRandom() == 1)
                                {
                                    cout << "You have encountered a wild Pokemon!" << endl << endl;
                                    sleep(1);
                                    if(myPlayer.getNumFree() < 2)
                                    {
                                    
                                        cout << "You have collected " << game.randomPokes[0].getName() << "!" << endl << endl;
                                        game.activePoke.push_back(game.randomPokes[0]);
                                        game.randomPokes.erase(game.randomPokes.begin());
                                        myPlayer.setNumFree(myPlayer.getNumFree() + 1);
                                        sleep(1);
                                
                                    }
                                    else
                                    {
                                
                                        int maxHP = game.randomPokes[0].getHP();
                                        int myMax = game.activePoke[0].getHP();
                                        game.randomFight();
                                        if(game.randomIsDead(game.randomPokes[0].getName()) == 1)
                                        {
                                            myPlayer.setPoints(myPlayer.getPoints() + 25);
                                            if(game.activePoke.size() <= 6)
                                            {
                                                game.activePoke[0].setHP(myMax);
                                                game.randomPokes[0].setHP(maxHP);
                                                game.activePoke.push_back(game.randomPokes[0]);
                                                game.randomPokes.erase(game.randomPokes.begin());
    
                                                for(int j = 0; j < 120; j++)
                                                {
                                                    if(game.activePoke[0].getName() == game.pokeList[j].getName())
                                                    {
                                                        if(game.activePoke[0].getMax() < game.pokeList[j + 1].getMax())
                                                        {
                                                            swap(game.activePoke[0], game.pokeList[j + 1]);
                                                            cout << "Your Pokemon has evolved to: " << game.activePoke[0].getName() << endl;
                                                            sleep(2);
                                                        }
                                                        else
                                                        {
                                                            cout << "Your Pokemon has already evolved to its max!!" << endl << endl;
                                                            sleep(2);
                                                        }
                                                    }
                                        
                                                }
                                        
                                                myPlayer.setNumPokeballs(myPlayer.getNumPokeballs() + 5);
                                                myPlayer.setNumBadges(myPlayer.getNumBadges() + 1);
                                        
                                        
                                            }
                                        }
                                    }
                                }
                            
                                game.loadMap("pokemap.txt", myPlayer.getXPos(), myPlayer.getYPos());
                            }
                            break;
                        
                        }
                        case 6:     //travel east
                        {
                            if(game.checkCollision(myPlayer.getXPos() + 1, myPlayer.getYPos()) == 1)
                            {
                                game.loadMap("pokemap.txt", myPlayer.getXPos(), myPlayer.getYPos());
                                cout << "You cannot swim!! Try another move." << endl;
                            }
                            else
                            {
                                myPlayer.playerMove(1, 0);
                            
                                if(game.enterPokeCenter(myPlayer.getXPos(), myPlayer.getYPos()) == 1)
                                {
                                    game.pokeCenter();
                                    travelMenu = false;
                                    break;
                                }
                                if(game.enterGym(myPlayer.getXPos(), myPlayer.getYPos()) == 1)
                                {
                                    cout << "Time to fight" << endl;
                                    sleep(1);
                                    int maxHP = game.trainerPokes[0].getHP();
                                    int myMax = game.activePoke[0].getHP();
                                    game.encounterTrainer();
                               
                                    if(game.trainerIsDead(game.trainerPokes[0].getName()) == 1)
                                    {
                                
                                    myPlayer.setNumPokeballs(myPlayer.getNumPokeballs() + 5);
                                    myPlayer.setNumBadges(myPlayer.getNumBadges() + 1);
                                    myPlayer.setPoints(myPlayer.getPoints() + 60);
                                    game.activePoke[0].setHP(myMax);
                                
                                    if(game.activePoke.size() <= 6)
                                    {
                                        game.trainerPokes[0].setHP(maxHP);
                                        game.activePoke.push_back(game.trainerPokes[0]);
                                        game.trainerPokes.erase(game.trainerPokes.begin());
                                        myGym.setNumTrainers((myGym.getNumTrainers() - 1));
                      
                                        for(int j = 0; j < 120; j++)
                                        {
                                            if(game.activePoke[0].getName() == game.pokeList[j].getName())
                                            {
                                                if(game.activePoke[0].getMax() < game.pokeList[j + 1].getMax())
                                                {
                                                    swap(game.activePoke[0], game.pokeList[j + 1]); 
                                                    cout << "Your Pokemon has evolved to " << game.activePoke[0].getName() << "!!" << endl << endl; 
                                                    sleep(2);
                                                }
                                                
                                                
                                            
                                                else
                                                {
                                                    cout << "Your Pokemon has already evolved to its max!!" << endl << endl;
                                                    sleep(2);
                                                }
                                            }
                                        }
                                    }
                                }
                                travelMenu = false;
                                break;
                            }
                            if(game.encounterRandom() == 1)
                            {
                                cout << "You have encountered a wild Pokemon!" << endl << endl;
                                sleep(1);
                                if(myPlayer.getNumFree() < 2)
                                {
                                    cout << "You have collected " << game.randomPokes[0].getName() << "!" << endl << endl;
                                    game.activePoke.push_back(game.randomPokes[0]);
                                    game.randomPokes.erase(game.randomPokes.begin());
                                    myPlayer.setNumFree(myPlayer.getNumFree() + 1);
                                    sleep(1);
                                
                                }
                                
                                int maxHP = game.randomPokes[0].getHP();
                                int myMax = game.activePoke[0].getHP();
                                game.randomFight();
                                if(game.randomIsDead(game.randomPokes[0].getName()) == 1)
                                {
                                    myPlayer.setPoints(myPlayer.getPoints() + 25);
                                    game.activePoke[0].setHP(myMax);
                                    if(game.activePoke.size() <= 6)
                                    {
                                        game.randomPokes[0].setHP(maxHP);
                                        game.activePoke.push_back(game.randomPokes[0]);
                                        game.randomPokes.erase(game.randomPokes.begin());
    
                                            for(int j = 0; j < 120; j++)
                                            {
                                                if(game.activePoke[0].getName() == game.pokeList[j].getName())
                                                {
                                                    if(game.activePoke[0].getMax() < game.pokeList[j + 1].getMax())
                                                    {
                                                        swap(game.activePoke[0], game.pokeList[j + 1]);
                                                        cout << "Your Pokemon has evolved to: " << game.activePoke[0].getName() << endl;
                                                    }
                                                    else
                                                    {
                                                        cout << "Your Pokemon has already evolved to its max!!" << endl << endl;
                                                    }
                                                }
                                        
                                            }
                                        
                                        myPlayer.setNumPokeballs(myPlayer.getNumPokeballs() + 5);
                                        myPlayer.setNumBadges(myPlayer.getNumBadges() + 1);
                                        
                                        
                                    }
                                }
                            }
                            game.loadMap("pokemap.txt", myPlayer.getXPos(), myPlayer.getYPos());
                        }
                        break;
                    }
                    
                    case 0:
                    {
                        travelMenu = false;
                        break;
                    }
                    default:
                    {
                        cout << "That was not a valid move. Please try again." << endl << endl;
                        travelChoice = -1;
                        break;
                    }
                }
            
            }
            continue;
        }
        
        case 2: //adds 2 HP to pokemon at cost of 1 pokeball
        {           
            if(myPlayer.getNumPokeballs() > 0)
            {
            game.restOption();
            myPlayer.setNumPokeballs(myPlayer.getNumPokeballs() - 1);
            }
            else
            {
                cout << "You have no more Pokeballs to consume" << endl << endl;
            }
            continue;
        }
        
        case 3: //attemps luck
        {
            game.tryLuck();
            sleep(1);
            continue;
        }
        
        case 4:     //game Quit
        {
           cout << "Thanks for playing!! Come back soon!" << endl;
            optionMenu = false;
            quit = true;
            break;
        }
        
        
        default:
        {
            cout << "Please choose another option" << endl;
            continue;
        }
        
        
        
    }
    
    
    optionMenu = false;
    
    
    
    }
    
 }

}