#include <iostream>
#include <stdalign.h>

using namespace std;

    char board[3][3] ={{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
    int choice;
    int column, row;
    char turn = 'X';
    bool draw = false;
    string p1name;
    string p2name;

    void display_board(){
    cout<<"\n  "<<board[0][0]<<"  | "<<board[0][1]<<"  |  "<<board[0][2]<<"\n";
    cout<<"_____|____|____\n";
    cout<<"  "<<board[1][0]<<"  | "<<board[1][1]<<"  |  "<<board[1][2]<<"\n";
    cout<<"_____|____|____\n";
    cout<<"  "<<board[2][0]<<"  | "<<board[2][1]<<"  |  "<<board[2][2]<<"\n";
    }
void player_turn(){
    if(turn == 'X'){
        cout<<"\n"<<p1name<<"'s turn :  ";
    }
    else if(turn == 'O'){
        cout<<"\n"<<p2name<<"'s turn : ";
}
cin>>choice;
switch(choice){
case 1:row=0;column=0;break;
case 2:row=0;column=1;break;
case 3:row=0;column=2;break;
case 4:row=1;column=0;break;
case 5:row=1;column=1;break;
case 6:row=1;column=2;break;
case 7:row=2;column=0;break;
case 8:row=2;column=1;break;
case 9:row=2;column=2;break;
    default:
        cout<<"Invalid move\n";
}
if(turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O'){
        board[row][column] = 'X';
        turn = 'O';
    }else if(turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O'){
        board[row][column] = 'O';
        turn = 'X';
    }else {
        cout<<"Box already filled!n Please choose another!\n";
        player_turn();
    }
    display_board;
}
bool gameover(){
     for(int i=0; i<3; i++)
    if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
    return false;
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
    return false;

    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    if(board[i][j] != 'X' && board[i][j] != 'O')
    return true;

    draw = true;
    return false;
}
int main(){
    cout<<"Welcome to the Tic Tac Toe Game\n";
    cout<<endl;
    cout<<"For 2 players\n";
    cout<<"The game is programmed for 2 players;\n each player has got to choose a number representing the box of the step he/she wants to play their turn in."<<endl;
    cout<<endl;
    cout<<"Instructions :\n\n";
    cout<<"1. Player 1 (X) will enter his/her name, same goes for player 2 (O).\n\n";
    cout<<"2. P1 (X) will have his/her turn first, then P2 (O).\n\n";
    cout<<"3. Each player will choose the number of the box they want to play their turn in.\n\n";
    cout<<"4. If P1 reaches 3 consecutive diagonal/horizontal/vertical 'X' first, P1 wins. However;\n if P2 reaches 3 consecutive diagonal/horizontal/vertical 'O', P2 wins.\n\n";
    cout<<"\n P1 - X\n\n P2 - O\n\n";
    cout<<"P1 please enter your name: ";
    cin>>p1name;
    cout<<endl;
    cout<<"P2 please enter your name: ";
    cin>>p2name;
    while(gameover()){
        display_board();
        player_turn();
        gameover();
    }
    if(turn == 'X' && draw == false){
        cout<<"Congratulations, "<<p2name<<" has won!\n";
    }
    else if(turn == 'O' && draw == false){
        cout<<"Congratulations, "<<p1name<<" has won!\n";
    }
    else{
        cout<<"Draw!\n";
    }
    cout<<"Thanks for playing!";
}
