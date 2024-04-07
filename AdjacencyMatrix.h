#pragma once

#include <iostream>
#include <unordered_map>

/*
    User can overwrite U to create a weighted graphs
*/

template <class T>
class Graph
{
public:
    void AddEdge(T FirstVertex, T SecondVertex, bool direction = false);
private:
    std::unordered_map<T, std::unordered_map<T, bool>> adjMatrix;    
};

template <class T>
void Graph<T>::AddEdge(T FirstVertex, T SecondVertex, bool direction = false)
{
    /*
        WeightLR acts an default weight from First to Second
    */
    adjMatrix[FirstVertex][SecondVertex] = true;

    // default its undirected
    if(!direction)
        adjMatrix[SecondVertex][FirstVertex] = true;
}