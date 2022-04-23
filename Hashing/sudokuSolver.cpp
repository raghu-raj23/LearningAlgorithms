#include <bits/stdc++.h> 
using namespace std;
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back
#define POB pop_back
#define MP make_pair

void helper(int r,int c,vector<vi> &board,map<pi, map<int, int>> &mp,vector<map<int,int>> &row,vector<map<int,int>> &col){
    if(r == 9){
        for(auto it: board){
            for(auto i : it){
                cout<<i<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
        return;
    }
    if(c == 9){
        helper(r+1,0,board,mp,row,col);
        return;
    }
    if(board[r][c] != 0){
        helper(r,c+1,board,mp,row,col);
        return;
    }
    FORL(i, 0, 9){
        int rw = r/3, cw = c/3;
        if(!mp[{rw,cw}][i] and !row[r][i] and !col[c][i]){
            mp[{rw,cw}][i] = 1;
            row[r][i] = 1;
            col[c][i] = 1;
            board[r][c] = i;
            helper(r,c+1,board,mp,row,col);
            mp[{rw,cw}][i] = 0;
            row[r][i] = 0;
            col[c][i] = 0;
            board[r][c] = 0;
        }
    }
}

void solveSudoku(vector<vector<int>> &board){
    map<pi, map<int, int>> mp;
    vector<map<int, int>> row(9);
    vector<map<int, int>> col(9);
    FOR(i,9){
        FOR(j,9){
            if(board[i][j] != 0){
                mp[{i/3,j/3}][board[i][j]] = 1;
                row[i][board[i][j]] = 1;
                col[j][board[i][j]] = 1;
            }
        }
    }
    helper(0,0,board, mp, row, col);
}

int main()
{
    vector<vector<int>> board;
    board = {
        {8, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 3, 6, 0, 0, 0, 0, 0},
        {0, 7, 0, 0, 9, 0, 2, 0, 0},
        {0, 5, 0, 0, 0, 7, 0, 0, 0},
        {0, 0, 0, 0, 4, 5, 7, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 3, 0},
        {0, 0, 1, 0, 0, 0, 0, 6, 8},
        {0, 0, 8, 5, 0, 0, 0, 1, 0},
        {0, 9, 0, 0, 0, 0, 4, 0, 0}
    };
    solveSudoku(board);
    return 0;
}
