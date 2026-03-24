#include <string>
#include <iostream>
#include "Player.h"

using namespace std;
//Player:: Player(){};
//Player:: Player(string name, int guess, double money, double bid): name(name), guess(guess), money(money), bid(bid){};

/*void Player::setName(string nam){
    name = nam;
};
void Player::setMoney(double money){
    money = money;
};
void Player::setGuess(int guess){
    guess = guess;
};

void Player::setBid(double bid){
    bid = bid;
}
*/

string Player::getName(){
    return name;
};

int Player::getGuess() const{
    return guess;
};

double Player::getMoney() const{
    return money;
};

double Player::getBid() const{
    return bid;
}

bool Player::getAgain() {
    return again;
}