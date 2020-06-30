#include <iostream>
#include <vector>
#include <math.h>
#include<fstream>
#include<sstream>
#include "Graph_part2.h"
using namespace std;
//create a heap of indexes wrt value , and the parent changes modifies as the algo proceeds
struct minHeap
{
    //vector of vertices or vertex indexes stored according to value 
    // the value of each element , maps into the heapdjList of Graph and the p_v vector
vector<int> heap;
int last,heapSize;
//vector of parent and value 
vector<pair<int,int>> p_v;
int defaultvalue;
void buildHeap(int V, int startIndex, int maxValue)
{
for(int i=0;i<V;i++)
{
    heap.push_back(i);
    p_v.push_back(make_pair(-999,maxValue));
}
last=V-1;
heapSize=V;
defaultvalue=maxValue;
changeValue(startIndex,0,-999);
}
int getMin()
{
    if(heap.empty())
    {
        cout<<"heap is empty\n";
        return -999;
    }
    return heap[0]; 
}
void heapify(unsigned int position)
{
    if(position<=last/2)//not leaf
    {
        unsigned int lpos=position*2+1;
        unsigned int rpos=position*2+2;
        int valueAtPos=p_v.at(heap.at(position)).second;
        int lchild;
        int rchild;
        if(lpos<=last)
            lchild=p_v.at(heap.at(lpos)).second;
        else
            lchild=defaultvalue;
        if(rpos<=last)
            rchild=p_v.at(heap.at(rpos)).second;
        else
            rchild=defaultvalue;
        //if(neither leaft nor rightchild exists)
        if(lchild==rchild && lchild==defaultvalue)
            return;
        if(valueAtPos< lchild && valueAtPos<rchild)
            {
                return ;
            }
        if(lchild<rchild)
            {
                int index=heap.at(position);
                heap.at(position)=heap.at(lpos);
                heap.at(lpos)=index;
                heapify(lpos);
            }
            else
            {
                int index=heap.at(position);
                heap.at(position)=heap.at(rpos);
                heap.at(rpos)=index;
                heapify(rpos);
            }            
        }
    }
    void changeValue(unsigned int vertex,int value,int parent)
    {
        int position=-999;
        for(int i=0;i<=last;i++)
        {
            if(heap.at(i)==vertex)
            {position=i;
            break;}
        }
        if(position==-999)
            return;
        int oldvalue=p_v.at(vertex).second;
        p_v.at(vertex).second=value;
        p_v.at(vertex).first=parent;
        int changedVertex=vertex;
        if(value<oldvalue)
        {
            //if new value < old value : check with parent 
            unsigned int parent=floor(position/2);
            while(p_v.at(heap.at(parent)).second>=value)
            //parent of the current position is less than the value
            {
                int t=heap.at(parent);
                heap.at(parent)=changedVertex;
                heap.at(position)=t;
                position=parent;
                parent=floor(position/2);
                if(parent==position)//root: done
                    break;
            }
        }
        //else heapify at position
        else
        {
            heapify(position);
        }        
    }
    void printHeap()
    {
        for(int i=0;i<=last;i++)
            {cout<<heap.at(i)<<" ";
            cout<<p_v.at(heap.at(i)).first<<" ";
            cout<<p_v.at(heap.at(i)).second<<endl;
            }
        cout<<"\n\n";
    }
    void deleteNode(int position)
    {
        //swap with last element and last --;
        int t=heap.at(last);
        heap.at(last)=heap.at(position);
        heap.at(position)=t;
        last--;
        heapify(position);
    }
    bool empty()
    {
        if (last<0)
            return true;
        else
            return false; 
    }
};
void primsAlgorithm(Graph G, int V,minHeap H)
{
    int mstWeight=0;
    while(!H.empty())
    {
        int index=H.getMin();
        cout<<H.p_v.at(index).first<<"->"<<index<<" , ";
        mstWeight+=H.p_v.at(index).second;
        H.deleteNode(0);
        //scan the neighbours for smallest edge
        AdjWeightedEdge<int> *edgeList=G.AdjList.at(index);
        while(edgeList!=NULL)
        {
            int w=edgeList->weight;
            int v=edgeList->V_index;
            //if the new weight is less than the previous
            // weight then change the value and parent
            if(H.p_v.at(v).second>w)
                H.changeValue(v,w,index);
            edgeList=edgeList->next;
        }
    }
    cout<<endl<<mstWeight<<endl;
}
int main()
{
    int a,b,i=1;
	Graph G;
	ifstream file;
        file.open("prim_Test2.txt");
        string line;
    int V=0,maxWeight=-999;
	while (getline(file, line))						        	// Take Input From The File.
		{
            V++;
			istringstream iss(line);
			char seperator;
            AdjWeightedEdge<int> *edges;
            AdjWeightedEdge<int> *p=NULL;
			while ((iss >>a>>seperator>>b)&& seperator==',')
			{
				//G[i].push_back(make_pair(a,b));
                AdjWeightedEdge<int> *edge=new AdjWeightedEdge<int>;
                edge->state=Unvisited;
                edge->V_index=a;
                edge->weight=b;
                if(b>maxWeight)
                    maxWeight=b;
                edge->next=NULL;
                cout<<a<<endl<<b<<endl;
                if(p==NULL)
                {   p=edge;
                    cout<<"yes p is null\n";
                    edges=p;
                }
                else
                {    p->next=edge;
                    p=p->next;
                }
			}
			G.AdjList.push_back(edges);
			i++;
		}
	file.close();
	//printMST_prims(Graph G,int V, int E, int start)
    G.printgraph();
    minHeap h;
    h.buildHeap(V,0,maxWeight+1);
    h.printHeap();
    primsAlgorithm(G,V,h);
    //printMST_prims(G,G.heapdjList.size(),E/2,0,maxWeight+1);
    return 0;
}