#include <iostream>
#include <stack>//for depth first traversal
#include <queue>//for breadth first traversal
#include <vector>

using namespace std;

enum State {Unvisited, Visited, Visiting} ;

template <typename T>
struct vertex
{
    T data ;
    State state;
    vector <vertex<T>*> AdList;
};

template <typename T>
struct Graph
{vector<vertex<T> *> V;};

template <typename T>
void printGraphList(Graph<T> *G)
{
int numV=G->V.size();
vector<vertex<T> *> vertices=G->V;
vector<vertex<T> *> AdjList;
for(int i=0;i<numV;i++)
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

template <typename T>
void printBFTraversal(Graph<T> *G, vertex<T> *start)
{
    //for all vertexs other than start set state as Unvisited
    if(G==NULL)
    {
        cerr <<"Invalid Graph\n";
        return;
    }
    unsigned numV=G->V.size();
    if(numV==1)
    {
        if(G->V.at(0)!=start)
        {
        cerr<<"Given start node does not belong to the graph\n\n";
        return ;
        }
        else
        {
            cout<<G->V.at(0)->data<<"\n";
            //cout<<start->data<<endl;
            return;
        }
    }
    //check if start node given belongs to the graph
    unsigned flag;
    for( flag=0;flag<numV;flag++)
        if(G->V.at(flag)==start)
            break;
    if(flag==numV)
    {
        cerr<<"The given start node does not belong to the graph\n";
        return;
    }
    start->state=Visiting;
    cout<<"Assigning all nodes, other than start, the sate Unvisited\n ";
    for( unsigned i=0;i<numV;i++)
        if(G->V.at(i)!=start)
            G->V.at(i)->state=Unvisited;
    cout<<"Pushing all adjacent nodes of start to q\n";
    queue<vertex<T>*> q;
    for(int i=0;i<start->AdList.size();i++)
    {
        q.push(start->AdList.at(i));
        //cout<<"after adding q's back is " <<q.back()->data<<endl;
        start->AdList.at(i)->state=Visiting;
    }
    while(!q.empty())//nodes remaining
    {
    vertex<T> *v=q.front();
    //cout<<q.front()->data<<"\n";
    cout<<"accessing " <<q.front()->data<<endl;
    //cout<<"data is "<<v->data<<endl;
    q.pop();
    //add all neighbours of v to queue
    for(unsigned i=0;i<v->AdList.size();i++)
    {
        if(v->AdList.at(i)->state==Visiting || v->AdList.at(i)->state==Visited)
        continue;
        q.push(v->AdList.at(i));
        //cout<<"after adding q's back is " <<q.back()->data<<endl;
        v->AdList.at(i)->state=Visiting;
    }
    v->state=Visited;
}

}

template <typename T>
void printDFTraversal(Graph<T> *G, vertex<T> *start)
{
//checks before traversal same as BFT
//for all vertexs other than start set state as Unvisited
    if(G==NULL)
    {
        cerr <<"Invalid Graph\n";
        return;
    }
    unsigned numV=G->V.size();
    if(numV==1)
    {
        if(G->V.at(0)!=start)
        {
        cerr<<"Given start node does not belong to the graph\n\n";
        return ;
        }
        else
        {
            cout<<G->V.at(0)->data<<"\n";
            //cout<<start->data<<endl;
            return;
        }
    }
    //check if start node given belongs to the graph
    unsigned flag;
    for( flag=0;flag<numV;flag++)
        if(G->V.at(flag)==start)
            break;
    if(flag==numV)
    {
        cerr<<"The given start node does not belong to the graph\n";
        return;
    }
    start->state=Visiting;
    cout<<"Assigning all nodes, other than start, the sate Unvisited\n ";
    for( unsigned i=0;i<numV;i++)
        if(G->V.at(i)!=start)
            G->V.at(i)->state=Unvisited;
    cout<<"Pushing all adjacent nodes of start to stack\n";
    stack<vertex<T>*> s;
    for(int i=0;i<start->AdList.size();i++)
    {
        s.push(start->AdList.at(i));
        //cout<<"after adding q's back is " <<q.back()->data<<endl;
        start->AdList.at(i)->state=Visiting;
    }
    while (!s.empty())
    {
        vertex<T> *v=s.top();
        cout<<v->data<<endl;
        s.pop();
        for(unsigned i=0;i<v->AdList.size();i++)
        {
            if(v->AdList.at(i)->state==Visiting || v->AdList.at(i)->state==Visited)
            continue;
            s.push(v->AdList.at(i));
            //cout<<"after adding q's back is " <<q.back()->data<<endl;
            v->AdList.at(i)->state=Visiting;
        }
        v->state=Visited;
    }

}
/*
//TODO : cpmplete code to generate a BFTree
template <typename T>
void printBFTree(Graph<T> *G,vertex<T> *start)
{//for all vertexs other than start set state as Unvisited
    if(G==NULL)
    {
        cerr <<"Invalid Graph\n";
        return;
    }
    unsigned numV=G->V.size();
    if(numV==1)
    {
        if(G->V.at(0)!=start)
        {
        cerr<<"Given start node does not belong to the graph\n\n";
        return ;
        }
        else
        {
            cout<<G->V.at(0)->data<<"\n";
            //cout<<start->data<<endl;
            return;
        }
    }
    //check if start node given belongs to the graph
    unsigned flag;
    for( flag=0;flag<numV;flag++)
        if(G->V.at(flag)==start)
            break;
    if(flag==numV)
    {
        cerr<<"The given start node does not belong to the graph\n";
        return;
    }
    start->state=Visiting;
    for( unsigned i=0;i<numV;i++)
        if(G->V.at(i)!=start)
            G->V.at(i)->state=Unvisited;
    //START HERE
    queue<vertex<T>*> q;
    queue<T> par_q;
    Graph<T> BFTree;
    for(int i=0;i<start->AdList.size();i++)
    {
        q.push(start->AdList.at(i));
        par_q.push(start->data);
        //cout<<"after adding q's back is " <<q.back()->data<<endl;
        start->AdList.at(i)->state=Visiting;
    }
    while(!q.empty())//nodes remaining
    {
    vertex<T> *v=q.front();
    //cout<<q.front()->data<<"\n";
    cout<<"accessing " <<q.front()->data<<endl;
    //cout<<"data is "<<v->data<<endl;
    q.pop();
    //add all neighbours of v to queue
    for(unsigned i=0;i<v->AdList.size();i++)
    {
        if(v->AdList.at(i)->state==Visiting || v->AdList.at(i)->state==Visited)
        continue;
        q.push(v->AdList.at(i));
        //cout<<"after adding q's back is " <<q.back()->data<<endl;
        v->AdList.at(i)->state=Visiting;
    }
    v->state=Visited;
}
}
*/