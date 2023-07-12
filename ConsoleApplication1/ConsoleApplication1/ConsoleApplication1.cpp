#include "stdafx.h"
#include <iostream>
#include <set>
 
using namespace std;

const int SIZE = 8; 
 
int board[SIZE][SIZE];
int results_count = 0; 
set<int> sols;
 
void showBoard()
{
    for(int a = 0; a < SIZE; ++a)
    {
        for(int b = 0; b < SIZE; ++b)
        {
            cout << ((board[a][b]) ? "Q " : ". ");
        }
        cout << endl;
    }
}
bool tryQueen(int a, int b){
    for(int i = 0; i < a; ++i)
    {
        if(board[i][b])
        {
            return false;
        }
    }
    for(int i = 1; i <= a && b-i >= 0; ++i)
    {
        if(board[a-i][b-i])
        {
            return false;
        }
    }
    
    for(int i = 1; i <= a && b+i < SIZE; i++)
    {
        if(board[a-i][b+i])
        {
            return false;
        }
    }
    return true;
}

 bool solution()
{
    int s[SIZE];
    for(int i = 0; i < SIZE; ++i)
    {
        for(int j = 0; j < SIZE; ++j)
        {
            if (board[i][j])
            {
                s[i] = j;
                break;
            }
        }
    }

    int S[3];
    for(int i = 0; i < SIZE; ++i)
    {
        S[0] = S[0] * SIZE + s[i];
        S[1] = S[1] * SIZE + s[SIZE - i - 1];   // Симметрия по горизонтали
        S[2] = S[2] * SIZE + SIZE - s[i] - 1;   // Симметрия по вертикали
    }
    for(int i = 0; i < 3; ++i)
    {
        // Симметричные т.о. решения не могут совпадать, проверка не нужна
        auto res = sols.insert(S[i]);
        if (res.second == false) return false;
    }
    return true;
}
void setQueen(int a) {
    if(a == SIZE)
    {
		 if (!solution()) return;
        showBoard();
        cout << "Result #" << ++results_count << endl << endl;
        return; 
    }
    for(int i = 0; i < SIZE; ++i)
    {

        if(tryQueen(a, i))
        {
            board[a][i] = 1;
            setQueen(a+1);
            board[a][i] = 0;
        }
    }
    return; 
}

 
int main()
{

    setQueen(0);
    
    system("pause");
}