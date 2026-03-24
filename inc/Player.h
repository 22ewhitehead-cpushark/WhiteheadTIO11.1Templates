#pragma once

#include <string>

using namespace std;

class Player{
    private:
        string name;
        int guess;
        double money;
        double bid;
        bool again = true;
    public:
        Player(){};
        Player(string name, int guess, double money, double bid){};

        void setName(string name){
            this->name = name;
        };
        void setMoney(double mone){
            money = mone;
        };
        void setGuess(int gues){
            guess = gues;
        };
        void setBid(double bi){
            bid = bi;
        };
        void setAgain(bool agai){
            again = agai;
        }

        string getName();
        double getMoney() const;
        int getGuess() const;
        double getBid() const;
        bool getAgain();

        friend istream& operator>>(istream& in, Player& player){
            char colon;
            in >> player.bid >> colon >> player.guess;
            return in;
        }
        void calcResults(int guess, double bid, double money, int compNum, string name, Player& player){
            money -= bid;
            if (guess == compNum){
                money += (bid*3);
                cout << name << " has guessed it correctly! Their money is tripled. They now have $"<< money<<endl;
            }
            else if ((compNum - guess <=3 && compNum - guess > 0) || (guess- compNum <=3 && guess - compNum > 0)){
                money += (bid*2);
                cout << name << " was within 3 of the number! Their money has doubled.They now have $"<< money<<endl;
            }
            else{
                cout << name << " wasn't close enough and has lost their money.They now have $"<< money<<endl;
            }
            player.setMoney(money);
        }
        void playAgain(Player& player){
            bool again;
            string result;
            if(player.getMoney() == 0){
                cout << player.getName() << " is out of money and cannot play another round.\n";
                again = false;
            }
            else{
            cout<< player.getName() << ", do you want to play another round? (y/n)\n";
            cin >> result;
            if (result != "y" && result != "Y"){
                again = false;
            }
            else if (result == "y" || result == "Y"){
                again = true;
            }
            }
            player.setAgain(again);
        }
};