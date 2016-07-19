/*
The darkest places in the hell are reserved for those who maintain thier neutrality in the time of moral crisis.
*/

#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<deque>
using namespace std;
int chess_board[8][8]   ;
int color[8][8] ;
char start[3], end[3]   ;
deque < pair<int, int> > Q;
int main(){
    int t   ;
    string start, end;
    cin >> t    ;
    while(t--){
        memset(color, 1, sizeof color)  ;
        memset(chess_board, 0, sizeof chess_board)  ;
        cin >> start >> end;
        int start_row = 56 - start[1]   ;
        int start_column = start[0] - 97;
        int end_row = 56 - end[1]       ;
        int end_column = end[0] - 97    ;
        Q.push_back(make_pair(start_row, start_column)) ;
        while(!Q.empty()){
            int row = Q.back().first ;
            int column = Q.back().second   ;
            Q.pop_back()    ;

            for (int i = -2; i < 3; i += 4)
                if (row + i < 8 && row + i >= 0)
                    for (int j = -1; j < 2; j += 2)
                        if (column + j < 8 && column + j >= 0)
                            if (color[row+i][column+j]){
                                chess_board[row+i][column+j] = chess_board[row][column] + 1 ;
                                color[row+i][column+j] = 0  ;
                                Q.push_front(make_pair(row+i, column+j))    ;
                        }
            for (int j = -2; j < 3; j += 4)
                if (column + j < 8 && column + j >= 0)
                    for (int i = -1; i < 2; i += 2)
                        if (row + i < 8 && row + i >= 0)
                            if (color[row+i][column+j]){
                                chess_board[row+i][column+j] = chess_board[row][column] + 1 ;
                                color[row+i][column+j] = 0  ;
                                Q.push_front(make_pair(row+i, column+j))    ;
                        }
            color[row][column] = 0  ;
        }
        cout << chess_board[end_row][end_column] << "\n";
    }
    return 0    ;
}
