#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <queue>
// #include <algorithm>
using namespace std;

int evalFn(vector<vector<int>> &state,vector<vector<int>> &grid,int level)
{
    int count=0;
    for (int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(state[i][j]!=grid[i][j])
            {
                count++;
            }
        }
    }
    return count+level;
}

int main()
{
    vector<vector<int>> startState(3,vector<int>(3));
    vector<vector<int>> goalState(3,vector<int>(3));

    cout<<"Enter Start State :"<<endl;
    for (int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>startState[i][j];
        }
    }

    cout<<endl;
    cout<<endl;

    cout<<"Enter Goal State :"<<endl;
    for (int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>goalState[i][j];
        }
    }

    cout<<endl;
    cout<<endl;

    // priority_queue< int , vector<int> , greater<int> > pq;
    // int = pair<int,pair<int,vector<vector<int>>>>
    // pq.push({evalFn(startState,goalState,0),{0,startState}});
    

    priority_queue< pair<int,pair<int,vector<vector<int>>>>, vector<pair<int,pair<int,vector<vector<int>>>>>, greater<pair<int,pair<int,vector<vector<int>>>>>> pq;
    pq.push({evalFn(startState,goalState,0),{0,startState}});

    while(!pq.empty())
    {
        cout<<"Current State :-"<<endl;
        int val=pq.top().first;
        int lvl=pq.top().second.first;
        vector<vector<int>> state=pq.top().second.second;
        pq.pop();
        for (int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                cout<<state[i][j]<<" "; 
            }
            cout<<endl;
        }
        cout<<"Value of Evaluation Function :- "<<val<<endl;
        cout<<"Level :- "<<lvl<<endl;
        cout<<"Heuristic Value :- "<<(val-lvl)<<endl;

        cout<<endl;
        cout<<endl;

        if(state==goalState)
        {
            cout<<"The Goal State has reached !!"<<endl;
            break;
        }

        cout<<"Next Possible States :- "<<endl;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(state[i][j]==-1)
                {
                    int perrow[4]={-1,0,1,0};
                    int percol[4]={0,-1,0,1};

                    for(int k=0;k<4;k++)
                    {
                        int rowi=i+perrow[k];
                        int colj=j+percol[k];

                        if(rowi>=0 && rowi<=2 && colj>=0 && colj<=2)
                        {
                            vector<vector<int>> temp=state;
                            swap(temp[i][j],temp[rowi][colj]);
                            pq.push({evalFn(temp,goalState,lvl+1),{lvl+1,temp}});
                            for (int i=0;i<3;i++)
                                {
                                    for(int j=0;j<3;j++)
                                    {
                                        cout<<temp[i][j]<<" "; 
                                    }
                                    cout<<endl;
                                }
                            cout<<"Value of Evaluation Function :- "<<evalFn(temp,goalState,lvl+1)<<endl;
                            cout<<"Level :- "<<lvl+1<<endl;
                            cout<<"Heuristic Value :- "<<evalFn(temp,goalState,lvl+1)-lvl-1<<endl;
                            cout<<endl;
                            cout<<endl;
                        }
                    }
                }
            }
        }

    }
    return 0;
}
/*
Time Complexity :- O(b^d)
b->branching factor(2 to 4)
d->depth 
*/


/*
Enter Start State :
1 2 3 5 6 -1 7 8 4


Enter Goal State :
1 2 3 5 8 6 -1 7 4


Current State :-
1 2 3 
5 6 -1 
7 8 4 
Value of Evaluation Function :- 4
Level :- 0
Heuristic Value :- 4


Next Possible States :- 
1 2 -1 
5 6 3 
7 8 4 
Value of Evaluation Function :- 6
Level :- 1
Heuristic Value :- 5


1 2 3 
5 -1 6 
7 8 4 
Value of Evaluation Function :- 4
Level :- 1
Heuristic Value :- 3


1 2 3 
5 6 4 
7 8 -1 
Value of Evaluation Function :- 6
Level :- 1
Heuristic Value :- 5


Current State :-
1 2 3 
5 -1 6 
7 8 4 
Value of Evaluation Function :- 4
Level :- 1
Heuristic Value :- 3


Next Possible States :- 
1 -1 3 
5 2 6 
7 8 4 
Value of Evaluation Function :- 6
Level :- 2
Heuristic Value :- 4


1 2 3 
-1 5 6 
7 8 4 
Value of Evaluation Function :- 6
Level :- 2
Heuristic Value :- 4


1 2 3 
5 8 6 
7 -1 4 
Value of Evaluation Function :- 4
Level :- 2
Heuristic Value :- 2


1 2 3 
5 6 -1 
7 8 4 
Value of Evaluation Function :- 6
Level :- 2
Heuristic Value :- 4


Current State :-
1 2 3 
5 8 6 
7 -1 4 
Value of Evaluation Function :- 4
Level :- 2
Heuristic Value :- 2


Next Possible States :- 
1 2 3 
5 -1 6 
7 8 4 
Value of Evaluation Function :- 6
Level :- 3
Heuristic Value :- 3


1 2 3 
5 8 6 
-1 7 4 
Value of Evaluation Function :- 3
Level :- 3
Heuristic Value :- 0


1 2 3 
5 8 6 
7 4 -1 
Value of Evaluation Function :- 6
Level :- 3
Heuristic Value :- 3


Current State :-
1 2 3 
5 8 6 
-1 7 4 
Value of Evaluation Function :- 3
Level :- 3
Heuristic Value :- 0


The Goal State has reached !!
*/