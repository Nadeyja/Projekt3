#ifndef TIC_TAC_TOE_ALGORITHM_H
#define TIC_TAC_TOE_ALGORITHM_H


class algorithm {
    int size;
    int how_much_to_win;
    char** gametable;

public:
    algorithm(int size_of_table, int how_much);
    bool Win(char player);
    bool Tie();
    int MiniMax(char player,char computer,char human,int depth);
    int AlphaBeta(char player,char computer,char human,int depth,int alpha,int beta);
    void CleanTable();
    void HumanTurn(char player);
    void ComputerTurn(char player, char computer,char human);
    void ShowActualGametable();
    void Play(char human);
    void Turn(char player, char computer,char human);
};


#endif //TIC_TAC_TOE_ALGORITHM_H
