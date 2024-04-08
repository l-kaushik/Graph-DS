#pragma once

#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <vector>

namespace AdjacencyMatrix
{
    template <class T>
    class Graph
    {
    public:
        Graph() : adjMatrix(){};

        Graph(std::initializer_list<std::pair<T, std::list<T>>> initList) : adjMatrix()
        {
            for (const auto &pair : initList)
            {
                T vertex = pair.first;
                const std::list<T> &neighbors = pair.second;

                for (const T &neighbor : neighbors)
                {
                    adjMatrix[vertex][neighbor] = true;
                }
            }
        }

        void AddEdge(T FirstVertex, T SecondVertex, bool direction = false);
        void display();
        std::vector<T> BreadthFirstSearch(T SourceNode);

    private:
        std::unordered_map<T, std::unordered_map<T, bool>> adjMatrix;
    };

    template <class T>
    void Graph<T>::AddEdge(T FirstVertex, T SecondVertex, bool direction)
    {
        adjMatrix[FirstVertex][SecondVertex] = true;

        // default its undirected
        if (!direction)
            adjMatrix[SecondVertex][FirstVertex] = true;
    }

    template <class T>
    void Graph<T>::display()
    {
        for (const auto &i : adjMatrix)
        {
            std::cout << i.first << " ---> ";
            for (const auto &j : i.second)
            {
                if (j.second)
                    std::cout << j.first << " ";
            }
            std::cout << '\n';
        }
    }

    template <class T>
    std::vector<T> Graph<T>::BreadthFirstSearch(T SourceNode)
    {
        std::queue<T> q;
        std::unordered_map<T, bool> visited;
        std::vector<T> ans;

        q.push(SourceNode);
        visited[SourceNode] = true;

        while (!q.empty())
        {
            T FrontNode = q.front();
            q.pop();

            // push into answer
            ans.push_back(FrontNode);

            for (const auto &i : adjMatrix[FrontNode])
            {
                T j = i.first;
                if (!visited[j])
                {
                    q.push(j);
                    visited[j] = true;
                }
            }
        }

        return ans;
    }

}