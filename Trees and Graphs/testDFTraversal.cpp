#include <iostream>
#include "graph.h"

int main()
{
    //making a graph
    Graph<int> G;
    cout<<"The number of nodes in the graph is 8\n";
    int value=0;
    vector<vertex<int>> Ver(8);
    for(unsigned int i=0;i<8;i++)
    {   
        Ver.at(i).data=value++;
        cout<<"Node "<<i<<" assigned"<<"\n";
    }
    for(unsigned int i=0;i<8;i++)
    {
        G.V.push_back(&Ver.at(i));
        cout<<&Ver.at(i)<<endl;
        cout<<G.V.at(i)<<endl;
    }
    for(unsigned i=0;i<8;i++)
    {
        if(i==0)
        {
            G.V.at(i)->AdList.push_back(G.V.at(1));
            G.V.at(i)->AdList.push_back(G.V.at(2));
            G.V.at(i)->AdList.push_back(G.V.at(3));
        }
        else
        {
            if(i==1)
            {
            G.V.at(i)->AdList.push_back(G.V.at(0));
            G.V.at(i)->AdList.push_back(G.V.at(2));
            G.V.at(i)->AdList.push_back(G.V.at(4));
            G.V.at(i)->AdList.push_back(G.V.at(5));
            }
            else
            {
                if(i==2)
                {
                G.V.at(i)->AdList.push_back(G.V.at(0));
                G.V.at(i)->AdList.push_back(G.V.at(1));
                G.V.at(i)->AdList.push_back(G.V.at(6));
                }
                else
                {
                    if(i==3)
                    {
                    G.V.at(i)->AdList.push_back(G.V.at(0));
                    G.V.at(i)->AdList.push_back(G.V.at(6));
                    G.V.at(i)->AdList.push_back(G.V.at(7));
                    }
                    else
                    {
                        if(i==4)
                        {
                        G.V.at(i)->AdList.push_back(G.V.at(1));
                        G.V.at(i)->AdList.push_back(G.V.at(7));
                        }
                        else
                        {
                            if(i==5)
                            {
                            G.V.at(i)->AdList.push_back(G.V.at(1));
                            G.V.at(i)->AdList.push_back(G.V.at(7));
                            }
                            else
                            {
                                if(i==6)
                                {
                                G.V.at(i)->AdList.push_back(G.V.at(2));
                                G.V.at(i)->AdList.push_back(G.V.at(3));
                                }
                                else
                                {
                                    if(i==7)
                                    {
                                    G.V.at(i)->AdList.push_back(G.V.at(3));
                                    G.V.at(i)->AdList.push_back(G.V.at(4));
                                    G.V.at(i)->AdList.push_back(G.V.at(5));
                                    }
                                }                                
                            }                            
                        }                        
                    }                    
                }                
            }            
        } 
        cout<<"Node "<<i<<"'s neighbours assigned"<<endl;       
    }
        printGraphList(&G);

    cout<<"Printing the Breadth first traversal starting at 0 \n";
    vertex<int> *v=G.V.at(0);
    cout << "Start node is with data"<<v->data<<endl;
    printDFTraversal(&G,v);
    return 0;
}