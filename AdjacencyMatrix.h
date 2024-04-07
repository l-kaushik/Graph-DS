#pragma once

#include <iostream>
#include <unordered_map>

template <class T>
class Graph
{
public:
    Graph() : adjMatrix() {};
    void AddEdge(T FirstVertex, T SecondVertex, bool direction = false);
    void display();
private:
    std::unordered_map<T, std::unordered_map<T, bool>> adjMatrix;    
};

template <class T>
void Graph<T>::AddEdge(T FirstVertex, T SecondVertex, bool direction)
{
    adjMatrix[FirstVertex][SecondVertex] = true;

    // default its undirected
    if(!direction)
        adjMatrix[SecondVertex][FirstVertex] = true;
}

template <class T>
void Graph<T>::display()
{
    for(const auto &i : adjMatrix)
    {
        std::cout << i.first << " ---> ";
        for(const auto &j : i.second) 
        {
            if(j.second)
                std::cout << j.first << " ";
        }
        std::cout << '\n';
    }
}