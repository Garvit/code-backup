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
#include<utility>
using namespace std;

/* Complete the function below to print 2 integers separated by a single space which will be your next move
   */
pair<pair<int,int>,int> finish(vector<string> board)
{
    char w;
    for(int i=0;i<3;i++)
    {
        if(board[i][0]!='_' && board[i][0]==board[i][1] && board[i][0]==board[i][2])
        {
            w=board[i][0];
            pair<pair<int,int>,int> p;
            if(w=='X')
                p=make_pair(pair<int,int>(1,0),0);
            else
                p=make_pair(pair<int,int>(0,0),1);
            return p;

        }
    }

    for(int i=0;i<3;i++)
    {
        if(board[0][i]!='_' && board[0][i]==board[1][i] && board[0][i]==board[2][i])
        {
            w=board[0][i];
            pair<pair<int,int>,int> p;
            if(w=='X')
                p=make_pair(pair<int,int>(1,0),0);
            else
                p=make_pair(pair<int,int>(0,0),1);
            return p;

        }
    }
    if(board[0][0]!='_' && board[0][0]==board[1][1] && board[0][0]==board[2][2])
    {
            w=board[0][0];
            pair<pair<int,int>,int> p;
            if(w=='X')
                p=make_pair(pair<int,int>(1,0),0);
            else
                p=make_pair(pair<int,int>(0,0),1);
            return p;

    }
    if(board[0][2]!='_' && board[0][2]==board[1][1] && board[0][2]==board[2][0])
    {
            w=board[0][2];
            pair<pair<int,int>,int> p;
            if(w=='X')
                p=make_pair(pair<int,int>(1,0),0);
            else
                p=make_pair(pair<int,int>(0,0),1);
            //cout<<"ok here "<<w<<endl;
            //cout<<p.first.first<<" "<<p.first.second<<" "<<p.second<<endl;
            return p;

    }
    int empty=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j]=='_')
                empty++;
        }
    }
    pair<pair<int,int>,int> p;
    if(empty==0)
        p=make_pair(pair<int,int>(0,1),0);
    else
        p=make_pair(pair<int,int>(0,0),0);

    //cout<<p.first.first<<" "<<p.first.second<<" "<<p.second<<endl;
    return p;
}
bool comparepair(pair<pair<int,int>,int> p1,pair<pair<int,int>,int> p2,char player)
{
    if(player=='X')
    {
        if(p1.first.first<p2.first.first)
            return false;
        else if(p1.first.first>p2.first.first)
            return true;
        else
        {
            if(p1.first.second<p2.first.second)
                return false;
            else if(p1.first.second>p2.first.second)
                return true;
            else
            {
                if(p1.second>p2.second)
                    return false;
                else if(p1.second<p2.second)
                    return true;
                else
                    return false;

            }
        }

    }
    else
    {
        if(p1.second<p2.second)
            return false;
        else if(p1.second>p2.second)
            return true;
        else
        {
            if(p1.first.second<p2.first.second)
                return false;
            else if(p1.first.second>p2.first.second)
                return true;
            else
            {
                if(p1.first.first>p2.first.first)
                    return false;
                else if(p1.first.first<p2.first.first)
                    return true;
                else
                    return false;

            }
        }
    }
}
pair<pair<int,int>,int> move(char player, vector<string> board)
{
    char opp=player=='X'?'O':'X';
    pair<pair<int,int>,int> ans=make_pair(pair<int,int>(0,0),0);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j]=='_')
            {
                board[i][j]=player;
                pair<pair<int,int>,int> p=finish(board);
                if(p.first.first==0 && p.first.second==0 && p.second==0)
                {
                    pair<pair<int,int>,int> r=move(opp,board);
                    ans.first.first+=r.first.first;
                    ans.first.second+=r.first.second;
                    ans.second+=ans.second;
                    //cout<<ans.first.first<<" "<<ans.first.second<<" "<<ans.second<<endl;
                }
                else
                {
                    return p;
                }
                board[i][j]='_';
            }
        }
    }
    //cout<<"move returning\n";
    //cout<<ans.first.first<<" "<<ans.first.second<<" "<<ans.second<<endl;
    return ans;
}
void nextMove(char player, vector <string> board)
{
    char opp=(player=='X')?'O':'X';
    pair<pair<int,int>,int> max=make_pair(pair<int,int>(0,0),0);
    int maxi,maxj,flag=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j]=='_')
            {
                if(flag==0) {maxi=i;maxj=j;flag=1;}
                board[i][j]=player;
                pair<pair<int,int>,int> p=finish(board);
                pair<pair<int,int>,int> ans=make_pair(pair<int,int>(0,0),0);
                if(p.first.first==0 && p.first.second==0 && p.second==0)
                {
                    pair<pair<int,int>,int> r=move(opp,board);
                    ans.first.first=r.first.first;
                    ans.first.second=r.first.second;
                    ans.second=ans.second;
                    //cout<<ans.first.first<<" "<<ans.first.second<<" "<<ans.second<<endl;
                    if(comparepair(ans,max,player))
                    {
                        max.first.first=ans.first.first;
                        max.first.second=ans.first.second;
                        max.second=ans.second;
                        maxi=i;maxj=j;

                    }
                }
                else
                {
                    cout<<i<<" "<<j<<endl;
                    return;
                }
                board[i][j]='_';
            }
        }
    }
    //cout<<max.first.first<<" "<<max.first.second<<" "<<max.second<<endl;
    cout<<maxi<<" "<<maxj<<endl;


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

   nextMove(player,board);

    return 0;
}
