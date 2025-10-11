#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<string> &board, int row, int col){
    int i = row, j = col;

    while(i>=0){
        if(board[i][j] == 'Q')
            return false;
        i--;
    }
    i = row;

    while( i >= 0  && j >=0){
        if(board[i][j] == 'Q')
            return false;
        i--; j--;
    }

    i = row; j = col;

    while(i >=0 && j < 8){
        if(board[i][j] == 'Q')
            return false;
        i--; j++;
    }

    return true;
}

int funct(int row, vector<string> &board){
    if(row == board.size())
        return 1;

    int ans = 0;

    for(int i=0; i<8; i++){
        if(board[row][i] == '*' || !isSafe(board, row, i))
            continue;

        board[row][i] = 'Q';
        ans += funct(row+1, board);
        board[row][i] = '.';
    }

    return ans;
}

int main(){
    vector<string> board(8);
    for(int i=0; i<8; i++)
        cin >> board[i];

    cout << funct(0, board) << endl;

    return 0;
}