#include <iostream>
#include "algorithm.h"


int main() {
    int size,how_much_to_win,choice;
    char human;
    bool flag= true;
    while(flag){
        std::cout<<"Wpisz wielkosc pola gry (Musi byc wieksze niz 2)"<<std::endl;
        std::cin>>size;
        std::cout<<"Wpisz ilosc znakow do wygrania (Musi byc wieksza niz 2 i mniejsza lub rowna wielkosci pola)"<<std::endl;
        std::cin>>how_much_to_win;
        if(size<3||how_much_to_win<3||how_much_to_win>size){
            std::cout<<"Niepoprawna wielkosc pola lub ilosc znakow do wygrania"<<std::endl;
        } else{
            flag=false;
        }
    }
    algorithm ttt (size,how_much_to_win);
    flag = true;
    while(flag){
        std::cout<<"Wybierz znak gracza (Wpisz 1 dla X lub 2 dla O)"<<std::endl;
        std::cin>>choice;
        if (choice==1){
            std::cout<<"Zostal wybrany X"<<std::endl;
            human='X';
            flag= false;
        }
        else if(choice==2){
            std::cout<<"Zostal wybrany O"<<std::endl;
            human='O';
            flag= false;
        }else{
            std::cout<<"Zostal wybrany zly znak. Sprobuj ponownie"<<std::endl;
        }
    }
    ttt.Play(human);

}
