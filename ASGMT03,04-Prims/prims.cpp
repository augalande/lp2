#include<bits/stdc++.h>
// #include<iostream>
// #include<map>
using namespace std;

class Graph{
    public:

    int vertexCount;
    int edgeCount;
    int **adjMatrix;
    map<string,int> cities;
    map<int,string> inv_cities;

    Graph()
    {
        cout<<"Enter Number of Cities :"<<endl;
        cin>>vertexCount;
        cout<<"Enter Number of Lines :"<<endl;
        cin>>edgeCount;

        adjMatrix=new int* [vertexCount];
        for(int i=0;i<vertexCount;i++)
        {
            adjMatrix[i]=new int [vertexCount];
            for (int j=0;j<vertexCount;j++)
            {
                adjMatrix[i][j]=0;
            }
        }

        cout<<"Enter Names of Cities :"<<endl;
        for(int i=0;i<vertexCount;i++)
        {
            string s;
            cin>>s;
            // cities.insert(pair<string ,int>(s,i));
            // inv_cities.insert(pair<int,string>(i,s));
            cities[s]=i;
            inv_cities[i]=s;
        }

        cout<<"Enter Length of Lines :"<<endl;
        for(int i=0;i<edgeCount;i++)
        {
            string u,v;
            int dist;
            cout<<"City A :"<<endl;
            cin>>u;
            cout<<"City B :"<<endl;
            cin>>v;
            cout<<"Distance between A and B :"<<endl;
            cin>>dist;
            add(u,v,dist);
        }
    }

    void add(string u,string v,int dist)
    {
        adjMatrix[cities[u]][cities[v]]=dist;
        adjMatrix[cities[v]][cities[u]]=dist;
    }

    int min_key(int key[],bool mst[])
    {
        int minimum=INT_MAX;
        int min;

        for(int i=0;i<vertexCount;i++)
        {
            if(mst[i]==0 && key[i]<minimum)
            {
                minimum=key[i];
                min=i;
            }
        }

        return min;
    }

    void prims()
    {
        int n=vertexCount;
        int key[n],parent[n];
        bool mst[n];

        for(int i=0;i<n;i++)
        {
            key[i]=INT_MAX;
            mst[i]=0;
            parent[i]=-2;
        }

        key[0]=0;
        parent[0]=-1;

        for(int count=1;count<=n;count++)
        {
            int min_vertex=min_key(key,mst);
            mst[min_vertex]=1;

            for(int vertex=0;vertex<n;vertex++)
            {
                if(adjMatrix[min_vertex][vertex] && mst[vertex]==0 && adjMatrix[min_vertex][vertex]<key[vertex])
                {
                    parent[vertex]=min_vertex;
                    key[vertex]=adjMatrix[min_vertex][vertex];
                }
            }
        }

        cout<<"MST :"<<endl;
        cout<<"Lines"<<"\t"<<"Distance"<<endl;
        int total=0;
        for(int i=1;i<n;i++)
        {
            cout<<inv_cities[i]<<"<-->"<<inv_cities[parent[i]]<<"\t"<<adjMatrix[i][parent[i]]<<endl;
            total+=adjMatrix[i][parent[i]];;
        }

        cout<<"Total Cost : "<<total<<endl;
    }
};

int main()
{
    Graph g;
    g.prims();
    return 0;
}

/*
Time Complexity :- O(n^2)
*/
/*
Test Case-1 :-
Input :-
5
6
0 1 2 3 4 
0 1 1
1 2 2
0 3 3
1 4 4
3 1 5
4 2 6

Output :-
10

Test Case-2 :-
Input :-
7 
8
0 1 2 3 4 5 6
0 1 2
0 3 3
0 6 4
1 2 3
1 4 2
3 4 5
4 5 7
4 6 6

Output :-
21
*/