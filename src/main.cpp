#include <iostream>
#include <string>
#include "Player.h"
#include <ctime>

using namespace std; 

bool checkBid(double playerMoney, double bid){
    bool valid = true;
    if (bid > playerMoney){
        cout << "Invalid bid. Not enough money.\n";
        cout << "You have: $" << playerMoney << endl;
        valid = false;
    }
    return valid;
}

bool checkGuess(int guess){
    bool valid = true;
    if (!(guess >0 && guess <21)){
        cout<<"invalid guess. Please pick a number between 1-20.\n";
        valid = false;
    }
    return valid;
};

struct Computer{
    int compNum;
    string name;
};

Computer getComputerNumber(Computer& comp){
    int compNumber = 1;
    comp.compNum = rand()% 20 + 1;
    comp.name = "number";
    return comp;
}

template <typename T1>
T1 add(T1 begin, T1 end){
    return begin + end;
}

int main(){
    string playerCountS;
    string playerCountJr;
    double playerBid = 0;
    int playerGuess, playerNum;
    bool valid = true;
    int i=1;
    bool haveMoney = true;
    Player player1;
    Player player2;
    Player player3;
    int compNum;
    Computer comp;
    cout << "Welcome to my Casino! We only have one game. It is a number guessing game.\n"
     "Here is $100 to start. First you place a bid. Then you guess a number between 1-20.\n" 
     "If you guess the number correctly, you get 3 times the amount of money. If your guess is within 3 of the number, your money is doubled.\n"
     "If your guess is 4 or more away from the number, you lose your bid. Simple right? Even better is you can play with other people!\n";
    
    do {
        cout<< "How many people are playing? (Only a maximum of 3 players can play)\n";
        cin>> playerCountS;
        if (playerCountS == "1" || playerCountS == "2" || playerCountS == "3"){
            valid = false;
            break;
        }
        else{
            cout << "Invalid player number.\n";
            valid = true;
            //continue;
        }
        //cin.clear(playerCount);
    } while (valid);
    int playerCount = stoi(playerCountS);

    cout<< "Excellent! you have chosen: " << playerCount << " person/people to play, we will now enter their names.\n";
    while(playerCount>=i){
        string playerName;
        cout<< "What is player "<< i <<"s name?\n";
        cin >> playerName;
        if (i==1){
            player1.setName(playerName);
            player1.setMoney(100);
        }
        else if(i==2){
            player2.setName(playerName);
            player2.setMoney(100);
        }
        else if (i==3){
            player3.setName(playerName);
            player3.setMoney(100);
            break;
        }
        else{
            cout<< "playerNumbers are messed up";
        }
        i+=1;
    }
    if (playerCount == 1){
        player2.setAgain(false);
        player3.setAgain(false);
    }
    else if (playerCount == 2){
        player3.setAgain(false);
    }
    do{
        cout << "Now lets get those bids and guesses!\n";
        if(player1.getAgain()){
            do{cout << player1.getName() << ", what is your bid and guess? (bid:guess)\n";
            cin >> player1;
            }while(!(checkBid(player1.getMoney(), player1.getBid()) && checkGuess(player1.getGuess())));
            cout << player1.getName() << " bid $" << player1.getBid() << " and guessed " << player1.getGuess()<< endl;
        }
        if (playerCount>=2 && player2.getAgain()){
            do{cout << player2.getName() << ", what is your bid and guess? (bid:guess)\n";
            cin >>player2;
            }while(!(checkBid(player2.getMoney(), player2.getBid()) && checkGuess(player2.getGuess())));
    }
        if (playerCount == 3 && player3.getAgain()){
            do{cout << player3.getName() << ", what is your bid and guess? (bid:guess)\n";
            cin >> player3;
            }while(!(checkBid(player3.getMoney(), player3.getBid()) && checkGuess(player3.getGuess())));
        }
        comp = getComputerNumber(comp);
        cout << "Let's check those results. \n";
        cout << "The " << comp.name << " was " << comp.compNum << endl;
        if(player1.getAgain()){
            player1.calcResults(player1.getGuess(), player1.getBid(), player1.getMoney(), comp.compNum, player1.getName(), player1);
        }
        if (playerCount >=2 && player2.getAgain()){
            player2.calcResults(player2.getGuess(), player2.getBid(), player2.getMoney(), comp.compNum, player2.getName(), player2);
        }
        if (playerCount == 3 && player3.getAgain()){
            player3.calcResults(player3.getGuess(), player3.getBid(), player3.getMoney(), comp.compNum, player3.getName(), player3);
        }
        if (player1.getAgain()){
            player1.playAgain(player1);
        }
        if (playerCount >= 2 && player2.getAgain()){
            player2.playAgain(player2);
        }
        if (playerCount ==3 && player3.getAgain()){
            player3.playAgain(player3);
        }
    }while(player1.getAgain() || player2.getAgain() || player3.getAgain());
    string begin = "Thank you ";
    string end = "for playing my game\n";
    cout << add(begin, end);
    //cout << "Thank you for playing my game!\n";
    return 0;
}