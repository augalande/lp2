#include<bits/stdc++.h>
// #include<iostream>
// #include<algorithm>
// #include<vector>
// #include<map>

using namespace std;

struct Edge{
    int src,dest,weight;
};

bool compareEdges(const Edge &e1,const Edge &e2)
{
    return e1.weight<e2.weight;
}

int findParent(vector<int> &parent, int u) //o(4)=o(1)
{
    if(parent[u]==u)
    {
        return u;
    }
    return parent[u]=findParent(parent, parent[u]);
}

void unionSets(vector<int> &parent,vector<int> &rank, int u, int v) //o(4)=o(1)
{
    int uroot=findParent(parent, u);
    int vroot=findParent(parent, v);

    if(rank[uroot]<rank[vroot])
    {
        parent[uroot]=vroot;
    }
    else if(rank[uroot]>rank[vroot])
    {
        parent[vroot]=uroot;
    }
    else
    {
        parent[uroot]=vroot;
        rank[vroot]++;
    }
}

vector<Edge> kruskals(vector<Edge> &edges,int V)
{
    vector<int> parent(V);
    vector<int> rank(V);
    vector<Edge> result;

    for(int i=0;i<V;i++)
    {
        parent[i]=i;
        rank[i]=0;
    }

    sort(edges.begin(),edges.end(),compareEdges);// o(nlogn)

    int i=0;
    while(result.size()<V-1)
    {
        Edge edge=edges[i];
        i++;

        int u=findParent(parent,edge.src);
        int v=findParent(parent,edge.dest);

        if(u!=v)
        {
            result.emplace_back(edge);
            unionSets(parent, rank, u, v);
        }
    }
    return result;
}

int main()
{
    // vector<Edge> edges={{0,3,6},{1,4,5},{2,4,7},{3,1,8},{0,1,2},{1,2,3}};
    // int V=5;

    int vertexCount,edgeCount;
    cout<<"Enter Number of Cities :"<<endl;
    cin>>vertexCount;
    cout<<"Enter Number of Lines :"<<endl;
    cin>>edgeCount;


    map<string,int> cities;
    map<int,string> inv_cities;
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

    vector<Edge> edges(edgeCount);

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

        edges[i].src=cities[u];
        edges[i].dest=cities[v];
        edges[i].weight=dist;
    }

    vector<Edge> result=kruskals(edges,vertexCount);

    cout<<"Lines"<<"\t"<<"Distance"<<endl;
    int total=0;
    for(Edge e:result)
    {
        cout<<inv_cities[e.src]<<"<->"<<inv_cities[e.dest]<<"\t"<<e.weight<<endl;
        total+=e.weight;
    }
    cout<<"Total Cost: "<<total;
    return 0;
}


/*
Time Complexity :- O(nlogn)
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