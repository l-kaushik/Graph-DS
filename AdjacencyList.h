#pragma once

#include <iostream>
#include <unordered_map>
#include <list>

template <class T>
class Graph
{
public:
    Graph() = default;
    void AddEdge(T u, T v, bool direction = false);
    void display();
private:
    std::unordered_map<T, std::list<T>> adj{};
};

template <class T>
void Graph<T>::AddEdge(T u, T v, bool direction)
{
    //create an edge from u to v
    adj[u].push_back(v);

    // if undirected graph
    if(!direction)
    {
        adj[v].push_back(u);
    }
}

template <class T>
void Graph<T>::display()
{
    for(auto i : adj)
    {
        std::cout << i.first << " ---> ";
        for(auto j: i.second)
        {
            std::cout << j << ", ";
        }
        std::cout << '\n';
    }
}
