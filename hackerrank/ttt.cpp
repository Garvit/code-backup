#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

bool IsGameOver(vector<string> board)
{
    int i,j;
        int row[3] = {0};
        int col[3] = {0};
        char winner = '_';
        int empty = 0 ;
        for( i=0; i<3; ++i)
        {
                for( j=0; j<3; ++j)
                {
                        if(board[i][j] == '_')
                                empty++;
                        if (board[i][j]!='_' && board[i][j]==board[i][0])
                                row[i]++;
                        if (board[i][j]!='_' && board[i][j] == board[0][j])
                                col[j]++;
                        if(col[j] == 3)
                        {
                                winner = board[0][j];
                        //      break;
                        }
                }
                if(row[i]==3)
                {
                        winner = board[i][0];
                //      break;
                }

        }
        if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
        {
                winner = board[1][1];
        }
        else if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
        {
                winner = board[1][1];
        }

        if(winner != '_')
        {
                return true;
        }

        return false;


}

int evaluateLine(int row1, int col1, int row2, int col2, int row3, int col3,vector<string> cells)
{
    int score = 0;

      if (cells[row1][col1] == 'X') {
         score = 1;
      } else if (cells[row1][col1] == 'O') {
         score = -1;
      }

      if (cells[row2][col2] == 'X') {
         if (score == 1) {   // cell1 is 'X'
            score = 10;
         } else if (score == -1) {  // cell1 is 'O'
            return 0;
         } else {  // cell1 is empty
            score = 1;
         }
      } else if (cells[row2][col2] == 'O') {
         if (score == -1) { // cell1 is 'O'
            score = -10;
         } else if (score == 1) { // cell1 is 'X'
            return 0;
         } else {  // cell1 is empty
            score = -1;
         }
      }

      // Third cell
      if (cells[row3][col3] == 'X') {
         if (score > 0) {  // cell1 and/or cell2 is 'X'
            score *= 10;
         } else if (score < 0) {  // cell1 and/or cell2 is 'O'
            return 0;
         } else {  // cell1 and cell2 are empty
            score = 1;
         }
      } else if (cells[row3][col3] == 'O') {
         if (score < 0) {  // cell1 and/or cell2 is 'O'
            score *= 10;
         } else if (score > 0) {  // cell1 and/or cell2 is 'X'
            return 0;
         } else {  // cell1 and cell2 are empty
            score = -1;
         }
      }
      //cout<<score<<endl;
      return score;

}
int evaluate(vector<string> board)
{
    int score=0;
    for(int i=0;i<3;i++)
    {
        score+=evaluateLine(i,0,i,1,i,2,board);
        score+=evaluateLine(0,i,1,i,2,i,board);
    }
    score+=evaluateLine(0,0,1,1,2,2,board);
    score+=evaluateLine(0,2,1,1,2,0,board);
    /*for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<board[i][j];
        }
        cout<<endl;
    }
    cout<<score<<endl;
    */return score;
}
int makeMove(char player, vector<string> board,int depth)
{

    int flag=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j]=='_'){
                flag=1;break;}
        }
    }
    if(IsGameOver(board) || flag==0 || depth==0)
    {
        return evaluate(board);
    }

    int curr,best=(player=='X')?-100000:100000;
    char opponent = player=='O' ? 'X' : 'O' ;
    int ans=0;
    for(int i=0; i<3; ++i)
            for(int j=0; j<3; ++j)
            {
                    if(board[i][j]=='_')
                    {
                            board[i][j] = player ;
                            curr=makeMove(opponent,board,depth-1);
                            //cout<<curr<<" "<<i<<" "<<j<<endl;

                            if(player=='X')
                            {
                                if(curr>best)
                                    best=curr;
                            }
                            else
                            {
                                if(curr<best)
                                    best=curr;
                            }
                            board[i][j] = '_' ;
                    }
            }
   //cout<<"makemove returns: "<<best<<endl;
    return best;
}

/* Complete the function below to print 2 integers separated by a single space which will be your next move
 */
int nextMove(char player, vector <string> board)
{
    int curr,best=(player=='X')?-100000:100000;
    char opponent = player=='O' ? 'X' : 'O' ;
    int besti,bestj;
    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j)
        {
            if(board[i][j]=='_')
            {
                board[i][j] = player ;
                curr=makeMove(opponent,board,1);
                //cout<<curr<<" "<<i<<" "<<j<<endl;
                if(player=='X')
                {
                    if(curr>best){
                        best=curr;
                        besti=i;
                        bestj=j;
                    }
                }
                else
                {
                    if(curr<best){
                        best=curr;
                        besti=i;
                        bestj=j;
                    }
                }
                board[i][j] = '_' ;
            }
        }
    }
    cout<<besti<<" "<<bestj<<endl;
}
int main(void) {

        char player;
        vector <string> board;

        //If player is X, I'm the first player.
        //If player is O, I'm the second player.
        cin >> player;

        //Read the board now. The board is a 3x3 array filled with X, O or _.
        for(int i=0; i<3; i++) {
                string s; cin >> s;
                board.push_back(s);
        }

    int a = nextMove(player,board);
	//evaluate(board);

        return 0;
}
