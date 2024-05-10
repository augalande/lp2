#include<bits/stdc++.h>
// #include<map>
// #include<iostream>
// #include<queue>
using namespace std;

class Graph
{
    public:

    unordered_map<string,vector<string>> adj;
    queue<pair<string,int>> q;
    int v;
    int e;

    Graph(int v1,int e1)
    {
        v=v1;
        e=e1;
        take_input();
    }

    void take_input()
    {
        cout<<"Enter the Two Cites between Routes !!"<<endl;
        for(int i=0;i<e;i++)
        {
            cout<<"Route "<<i+1<<" : "<<endl;
            string a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }

    void dfs(pair<string,int> p,unordered_map<string,int> &v)
    {
        string node=p.first;
        int level=p.second;

        cout<<node<<" "<<level<<endl;
        v[node]=true;

        for(auto it:adj[node])
        {
            if(!v[it])
            {
                dfs({it,level+1},v);
            }
        }
    }

    void DFS()
    {
        unordered_map<string,int> v;
        cout<<endl;
        cout<<"DFS"<<endl;
        cout<<"Enter Starting City : "<<endl;
        string s;
        cin>>s;
        dfs({s,0},v);
    }

    void bfs(unordered_map<string,int> &v)
    {
        if(q.empty())
        {
            return;
        }

        string node=q.front().first;
        int level=q.front().second;
        q.pop();

        cout<<node<<" "<<level<<endl;

        for(auto it:adj[node])
        {
            if(!v[it])
            {
                v[it]=true;
                q.push({it,level+1});
            }
        }

        bfs(v);
    }

    void BFS()
    {
        unordered_map<string,int> v;
        cout<<endl;
        cout<<"BFS"<<endl;
        cout<<"Enter Starting City : "<<endl;
        string s;
        cin>>s;

        v[s]=true;
        q.push({s,0});
        bfs(v);
    }


};

int main()
{
    cout<<"Enter Number of Cities : "<<endl;
    int n;
    cin>>n;

    cout<<"Enter Number of Routes : "<<endl;
    int e;
    cin>>e;

    Graph g(n,e);

    g.DFS();
    g.BFS();

    return 0;
}

/*
Time Complexity :- O(v+e)
*/

/*
Input & Output:-
Enter Number of Cities : 
5
Enter Number of Routes : 
6
Enter the Two Cites between Routes !!
Route 1 : 
a b
Route 2 : 
a c
Route 3 : 
b c
Route 4 : 
b d
Route 5 : 
c e
Route 6 : 
d e

DFS
Enter Starting City : 
a
a 0
b 1
c 2
e 3
d 4

BFS
Enter Starting City : 
a
a 0
b 1
c 1
d 2
e 2
*/