#include <iostream>
#include "algorithm.h"

algorithm::algorithm(int size_of_table, int how_much) {
    size=size_of_table;
    how_much_to_win=how_much;

    gametable=new char*[size];
    for (int c=0;c<size;c++){
        gametable[c]=new char[size];
    }
    for (int i=0;i<size;i++) {
        for (int j=0;j<size;j++){
            gametable[i][j]=' ';
        }
    }

}
bool algorithm::Win(char player){
    int l;
    ///wiersze
    for (int i=0;i<size;i++){
        l=0;
        for (int j=0;j<size-1;j++){
            if(gametable[i][j]==gametable[i][j+1]&&gametable[i][j]==player){
                l++;
                if(l==how_much_to_win-1){
                    return true;
                }
            }else{
                l=0;
            }
        }
    }
    l=0;
    ///kolumny
    for (int j=0;j<size;j++){
        l=0;
        for (int i=0;i<size-1;i++){
            if(gametable[i][j]==gametable[i+1][j]&&gametable[i][j]==player){
                l++;
                if(l==how_much_to_win-1){
                    return true;
                }
            }else{
                l=0;
            }
        }
    }
    l=0;
    ///główna przekątną lewej w dół
    for (int i=0;i<size-1;i++){
        if(gametable[i][i]==gametable[i+1][i+1]&&gametable[i][i]==player){
            l++;
            if(l==how_much_to_win-1){
                return true;
            }
        }else{
            l=0;
        }
    }
    l=0;
    ///główna przekątną z prawej w dół
    for (int i=0;i<size-1;i++){
        if(gametable[i][size-i-1]==gametable[i+1][size-2-i]&&gametable[i][size-i-1]==player){
            l++;
            if(l==how_much_to_win-1){
                return true;
            }
        }else{
            l=0;
        }
    }
    l=0;
    if(size!=how_much_to_win){
    ///przekątne z lewej w dół z dołu głównej
    for(int k=1;k<size-how_much_to_win+1;k++){
        for (int i=0;i<size-1-k;i++){
            if(gametable[i+k][i]==gametable[i+1+k][i+1]&&gametable[i+k][i]==player){
                l++;
                if(l==how_much_to_win-1){
                    return true;
                }
            }else{
                l=0;
            }
        }
    }
    l=0;
    ///przekątne z lewej w dół z góry głównej
    for(int k=1;k<size-how_much_to_win+1;k++){
        for (int i=0;i<size-1-k;i++){
            if(gametable[i][i+k]==gametable[i+1][i+1+k]&&gametable[i][i+k]==player){
                l++;
                if(l==how_much_to_win-1){
                    return true;
                }
            }else{
                l=0;
            }
        }
    }
    l=0;
    ///przekątne z prawej w dół z góry głównej
    for(int k=1;k<size-how_much_to_win+1;k++){
        for (int i=0;i<size-1-k;i++){
            if(gametable[i][size-1-k-i]==gametable[i+1][size-2-k-i]&&gametable[i][size-1-k-i]==player){
                l++;
                if(l==how_much_to_win-1){
                    return true;
                }
            }else{
                l=0;
            }
        }
    }
    l=0;
    ///przekątne z prawej w dół z dołu głównej
    for(int k=1;k<size-how_much_to_win+1;k++){
        for (int i=0;i<size-1-k;i++){
            if(gametable[i+k][size-1-i]==gametable[i+k+1][size-2-i]&&gametable[i+k][size-1-i]==player){
                l++;
                if(l==how_much_to_win-1){
                    return true;
                }
            }else{
                l=0;
            }
        }
    }
    l=0;
    }
    return false;
}
bool algorithm::Tie() {
    for (int i=0;i<size;i++){
        for (int j=0;j<size;j++){
            if(gametable[i][j]==' '){
                return false;
            }
        }
    }
    return true;
}
int algorithm::MiniMax(char player,char computer,char human,int depth){
    if(depth==10-size&&size!=3&&size<7){
        return 0;
    } else if(size>=7&&depth==4){
        return 0;
    }
    if(Win(computer)){
        return 1;
    }
    if(Win(human)){
        return -1;
    }
    if(Tie()){
        return 0;
    }
    if(player==computer){
        int max=-1000;
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(gametable[i][j]==' '){
                    gametable[i][j]=computer;
                    max=std::max(max,MiniMax(human,computer,human,depth+1));
                    gametable[i][j]=' ';
                }
            }
        }
        return max;
    }else{
        int min=1000;
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(gametable[i][j]==' '){
                    gametable[i][j]=human;
                    min=std::min(min,MiniMax(computer,computer,human,depth+1));
                    gametable[i][j]=' ';
                }
            }
        }
        return min;
    }
}
int algorithm::AlphaBeta(char player,char computer,char human,int depth,int alpha,int beta){
    if(depth==5&&size!=3){
        return 0;
    }
    if(Win(computer)){
            return 1;
    }
    if(Win(human)){
            return -1;
    }
    if(Tie()){
        return 0;
    }
    if(player==computer){
        int max=-2147483648;
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(gametable[i][j]==' '){
                    gametable[i][j]=computer;
                    int x=AlphaBeta(human,computer,human,depth+1,alpha,beta);
                    max=std::max(x,max);
                    alpha=std::max(max,alpha);
                    gametable[i][j]=' ';
                    if(alpha>=beta){
                        break;
                    }
                }
            }
        }
        return max;
    }else{
        int min=2147483647;
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(gametable[i][j]==' '){
                    gametable[i][j]=human;
                    int x=AlphaBeta(computer,computer,human,depth+1,alpha,beta);
                    min=std::min(x,min);
                    beta=std::min(min,beta);
                    gametable[i][j]=' ';
                    if(alpha>=beta){
                        break;
                    }
                }
            }
        }
        return min;
    }
}
void algorithm::CleanTable(){
    for (int i=0;i<size;i++){
        for (int j=0;j<size;j++){
            gametable[i][j]=' ';
        }
    }
}
void algorithm::ComputerTurn(char player,char computer,char human){
    int row,collumn,x;
    int max = -2147483648;
    for(int i=0;i<size;i++) {
        for (int j=0;j<size; j++) {
            if (gametable[i][j] == ' ') {
                gametable[i][j] = player;
                x = MiniMax(human,computer,human,0);
                //x = AlphaBeta(human,computer,human,0,-2147483648,2147483647);
                gametable[i][j] = ' ';
                if (x > max) {
                    row = i;
                    collumn = j;
                    max = x;
                }

            }
        }
    }
    gametable[row][collumn]=computer;
}
void algorithm::HumanTurn(char player){
    int row;
    int collumn;
    bool flag = true;
    while(flag){
        std::cout<<"Podaj numer wiersza (od zera)"<<std::endl;
        std::cin>>row;
        std::cout<<"Podaj numer kolumny (od zera)"<<std::endl;
        std::cin>>collumn;

        if(row<0||row>size-1||collumn<0||collumn>size-1){
            std::cout<<"Wspolrzedne wychodza poza tablice"<<std::endl;
        }
        else if(gametable[row][collumn]!=' '){
            std::cout<<"Dane wspolrzedne sa juz zajete"<<std::endl;
        }
        else{
            gametable[row][collumn]=player;
            flag=false;
        }
    }
}
void algorithm::ShowActualGametable(){
    std::string rows(size*4+1,'-');
    for(int i=0;i<size;i++){
        std::cout<<rows<<std::endl;
        for(int j=0;j<size;j++){
            std::cout<<'|'<<' '<<gametable[i][j]<<' ';
        }
        std::cout<<'|'<<std::endl;
    }
    std::cout<<rows<<std::endl;
}
void algorithm::Turn(char player, char computer,char human){
    if(player==computer){
        ComputerTurn(player,computer,human);
    }else{
        HumanTurn(human);
    }
}
void algorithm::Play(char human){
    char computer,player;
    if (human=='X'){
        computer='O';
    }else{
        computer='X';
    }
    player=human;
    CleanTable();
    while(!Win(computer)&&!Win(human)&&!Tie()){
        Turn(player,computer,human);
        ShowActualGametable();
        if(Win(player)){
            std::cout<<player<<" wygrywa!"<<std::endl;
        }else if(Tie()){
            std::cout<<"Remis!"<<std::endl;
        }
        if(player==human){
            player=computer;
        }else{
            player=human;
        }

    }
}
