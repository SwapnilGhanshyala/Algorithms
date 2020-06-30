#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

enum State {Unvisited, Visited, Visiting} ;

template <typename T>
struct DirectedGraphNode
{
T data;
vector<DirectedGraphNode*> AdList;
State state;
};
template <typename T>
class DirectedGraph
{
    public:
    vector<DirectedGraphNode<T>*> V;
    //NonRecursive : using stack
    DirectedGraph(vector<DirectedGraphNode<T>> *vertices)
    {
        for(unsigned int i=0;i<vertices->size();i++)
        {
            V.push_back(&(vertices->at(i)));
        }
    }
    void printGraphList()
    {
    int numV=V.size();
    vector<DirectedGraphNode<T> *> vertices=V;
    vector<DirectedGraphNode<T> *> AdjList;
    for(unsigned int i=0;i<numV;i++)
        {
        cout<<"ith node is :\n";
        cout<<vertices.at(i)->data<<endl;
        AdjList=vertices.at(i)->AdList;
        cout<<"the nodes it is adjacent to are:\n";
        for(int j=0;j<AdjList.size();j++)
            cout<<AdjList.at(j)->data<<" ";
        cout<<endl;
        }
    }
    // doesRouteExistAlgo_nonrec and recursive are both DFtraversal
    bool doesRouteExistAlgo_nonrec(DirectedGraphNode<T> *source, DirectedGraphNode<T> *sink)
    {
        for(unsigned i=0;i<V.size();i++)
        {
            V.at(i)->state=Unvisited;
        }
        stack<DirectedGraphNode<T>*> d;
        for(unsigned i=0;i<source->AdList.size();i++)
        {
            d.push(source->AdList.at(i));
        }
        source->state=Visiting;
        while(!d.empty())
        {
            DirectedGraphNode<T> *node=d.top();
            d.pop();
            //if sink found
            if(node==sink)
            return true;
            //if the current node has no adjacent nodes
            if (node->AdList.empty())
            {
                node->state=Visited;
                continue;
            }
            if(node->state==Unvisited)
            {
                 int flag=0;
                for(int i=0;i<node->AdList.size();i++)
                {
                    if(node->AdList.at(i)->state!=Visited)
                    {flag=1;
                    break;}
                }
                if(flag==0)
                {
                    node->state=Visited;
                    continue;
                }
                for(unsigned i=0;i<node->AdList.size();i++)
                {
                d.push(node->AdList.at(i));
                }
                node->state=Visiting;
                continue;
            }
            //if node is visiting;
        }
        return false;

    }
    // Assuming all nodes at the begining have state unvisited
    //this is recursive algorithm
    bool doesRouteExistAlgo_rec(DirectedGraphNode<T> *source, DirectedGraphNode<T> *sink)
    {
        for(unsigned i=0;i<V.size();i++)
        {
            V.at(i)->state=Unvisited;
        }
        return doesRouteExist(source,sink);
    }
bool doesRouteExist(DirectedGraphNode<T> *fromNode, DirectedGraphNode<T> *toNode)
{

    if(fromNode->AdList.empty() || fromNode->state==Visited)
    {
        //if the from Node points to no other node
        //if the fromNode has already been visited
        //if this route goes back to the fromNode
        return false;
    }
    fromNode->state=Visiting;
    for(unsigned i=0;i<fromNode->AdList.size();i++)
    {
        if(fromNode->AdList.at(i)==toNode)
        {
            return true;
        }
        if(fromNode->AdList.at(i)->state!=Visiting)
        {
            if(doesRouteExist(fromNode->AdList.at(i),toNode)==true)
            {
                return true;
            }
            else
            {
                fromNode->AdList.at(i)->state=Visited;
            }
        }
        
    }
    return false;   
}
//doesRouteExist with BFTraversal
bool doesRouteExistAlgo_BFSearch(DirectedGraphNode<T> *source, DirectedGraphNode<T> *sink)
{
    //check if any of the source and sink is null
    if(source==NULL || sink==NULL)
    {
        cerr<<"Either source or sink is NULL\n";
        return false;
    }
    //check to see if start and sink both belong to graph G
    int flag_source =0, flag_sink=0;
    for(unsigned i=0;i<V.size();i++)
    {
        if(V.at(i)==source)
            flag_source=1;
        else
        {
            if(sink==V.at(i))
                flag_sink=1;
        }
        
    }
    if(flag_source==0 || flag_sink==0)
    {
        cerr<<"Either start of sink does not belong to the graph\n";
        return false;
    }
    //check if source==sink 
    if(source==sink)//route exists
        return true;
    //check if source's neighbour list is empty
    if(source->AdList.empty())
        return false;
    for(unsigned i=0;i<V.size();i++)
        {
            if(V.at(i)!=source)
                V.at(i)->state=Unvisited;
        }
    source->state=Visited;
    queue<DirectedGraphNode<T> *> q;
    for(unsigned i=0;i<source->AdList.size();i++)
    {
        q.push(source->AdList.at(i));
        source->AdList.at(i)->state=Visiting;
    }
    while(!q.empty())
    {
        DirectedGraphNode<T> * v=q.front();
        q.pop();
        if(v==sink)
            return true;
        for(unsigned i=0;i<v->AdList.size();i++)
        {
            if(v->AdList.at(i)->state==Unvisited)
            {
                q.push(v->AdList.at(i));
                v->AdList.at(i)->state=Visiting;
            }
        }
        v->state=Visited;
    }
    return false;
}
};