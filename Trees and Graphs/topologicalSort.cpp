/*To test the topological Sort Method in DirectedGraph_part2.h*/
#include <iostream>
#include "DirectedGraph_part2.h"
using namespace std;

int main()
{
    DirectedGraph G;
    int V;
    cout<<"Enter the number of Nodes you want in the Graph \n";
    cin>>V;
    for(int i=0;i<V;i++)
    {
        int index=0;
        cout<<"For Node "<<i<<" enter the directed Edges from it, or press -1 if no node \n";
        cin>>index;
        if(index==-1)
            {
            G.AdjList.push_back(NULL);
            continue;
            }
        AdjWeightedEdge<int> *edgeList=new AdjWeightedEdge<int>;
        edgeList->V_index=index;
        edgeList->weight=1;
        //edgeList.next=NULL;
        edgeList->state=Unvisited;
        AdjWeightedEdge<int> *p=edgeList;
        while(true)
        {
            cout<<"For Node "<<i<<" enter the directed Edges from it, or press -1 if no node \n";
            cin>>index;
            if(index==-1)
                break;
            AdjWeightedEdge<int> *nextedge=new AdjWeightedEdge<int>;
            nextedge->V_index=index;
            nextedge->weight=1;
            nextedge->next=NULL;
            nextedge->state=Unvisited;
            p->next=nextedge;
            p=p->next;
        }
        p->next=NULL;
        G.AdjList.push_back(edgeList);
    }
    //G.printgraph();
    G.topologicalSort(0);
    return 0;

}
