#include <iostream>
#include "directedGraph.h"

int main()
{
    //making a graph
    cout<<"The number of nodes in the graph is 8\n";
    int value=0;
    vector<DirectedGraphNode<int>> Ver(8);
    for(unsigned int i=0;i<8;i++)
    {   
        Ver.at(i).data=value++;
    }
    DirectedGraph<int> G(&Ver);
    for(unsigned i=0;i<8;i++)
    {
        if(i==0)
        {
            G.V.at(i)->AdList.push_back(G.V.at(1));
            G.V.at(i)->AdList.push_back(G.V.at(2));
        }
        else
        {
            if(i==1)
            {
            G.V.at(i)->AdList.push_back(G.V.at(4));
            G.V.at(i)->AdList.push_back(G.V.at(5));
            }
            else
            {
                if(i==2)
                {
                G.V.at(i)->AdList.push_back(G.V.at(1));
                G.V.at(i)->AdList.push_back(G.V.at(6));
                }
                else
                {
                    if(i==3)
                    {
                    G.V.at(i)->AdList.push_back(G.V.at(0));
                    G.V.at(i)->AdList.push_back(G.V.at(7));
                    }
                    else
                    {
                        if(i==4)
                        {
                        G.V.at(i)->AdList.push_back(G.V.at(7));
                        }
                        else
                        {
                            if(i==5)
                            {
                            G.V.at(i)->AdList.push_back(G.V.at(7));
                            }
                            else
                            {
                                if(i==6)
                                {
                                G.V.at(i)->AdList.push_back(G.V.at(3));
                                }                                
                            }                            
                        }                        
                    }                    
                }                
            }            
        } 
        cout<<"Node "<<i<<"'s neighbours assigned"<<endl;       
    }
        G.printGraphList();

    if(G.doesRouteExistAlgo_BFSearch(G.V.at(3),G.V.at(5)))
    {
        cout<<"Route exists from 3 to 5\n";
    }
    else
    {
        cout<<"No route exists from 3 to 5\n";
    }
    
    //printDFTraversal(&G,v);
    return 0;
}