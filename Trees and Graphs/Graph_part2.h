#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

enum State {Unvisited, Visited, Visiting} ;

template <typename T>
struct AdjWeightedEdge
{
    T weight;
    AdjWeightedEdge<T> *next;
    int V_index;
    State state;
};
struct Graph
{
vector<AdjWeightedEdge<int>*> AdjList;
void printgraph()
{
    for(int i=0;i<AdjList.size();i++)
    {
        AdjWeightedEdge<int> *p=AdjList.at(i);
        while(p!=NULL)
        {
            cout<<i<<" -> "<<p->V_index<<" ";
            cout<<"With weight "<<p->weight<<endl;
            p=p->next;
        }
    }
}

};