#include <iostream>
#include <vector>
#include <queue>
using namespace std;

enum State {Unvisited, Visited, Visiting} ;

 void printVector(vector<int> A)
 {
     for(int i=0;i<A.size();i++)
     {
         cout<<A[i]<<" ";
     }
     cout<<endl;
 }
template <typename T>
struct AdjWeightedEdge
{
    T weight;
    AdjWeightedEdge<T> *next;
    int V_index;
    State state;
};
struct DirectedGraph
{
vector<AdjWeightedEdge<int>*> AdjList;
vector<int> getIndegrees()
{
    vector<int> indegree;
    for(int i=0;i<AdjList.size();i++)
        indegree.push_back(0);
    for(int i=0;i<AdjList.size();i++)
    {
        AdjWeightedEdge<int> *p=AdjList.at(i);
        while(p!=NULL)
        {
            indegree[p->V_index]++;
            p=p->next;
        }
    }
    return indegree;
}
void topologicalSort(int start)
{
    vector<int> indegree=getIndegrees();
    //printVector(indegree);
    queue<int> q;
    q.push(start);
    while(!q.empty())
    {
        int v=q.front();
        q.pop();
        AdjWeightedEdge<int>* AdjNode=AdjList.at(v);
        while(AdjNode!=NULL)
        {
            indegree[AdjNode->V_index]--;
            if(indegree[AdjNode->V_index]==0)
                q.push(AdjNode->V_index);
            AdjNode=AdjNode->next;
        }
        cout<<v<<" ";
    }
    for(int i=0;i<indegree.size();i++)
    {
        if(indegree[i]>0)
        cout<<"\nCycle present \n";
    }

}
void printgraph()
{
    for(int i=0;i<AdjList.size();i++)
    {
        AdjWeightedEdge<int> *p=AdjList.at(i);
        while(p!=NULL)
        {
            cout<<i<<" -> "<<p->V_index<<endl;
            p=p->next;
        }
    }
}

};