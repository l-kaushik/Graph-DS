#pragma once

#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>

namespace AdjacencyList
{
    template <class T>
    class Graph
    {
    public:
        Graph() : adjList(){};
        Graph(std::initializer_list<std::pair<T, std::list<T>>> initList)
        {
            for (const auto &pair : initList)
            {
                adjList[pair.first] = pair.second;
            }
        }

        void AddEdge(T u, T v, bool direction = false);
        void display();
        std::vector<T> BreadthFirstSearch();
        std::vector<T> BreadthFirstSearch(T SourceNode);
        std::vector<T> DepthFirstSearch();
        std::vector<T> DepthFirstSearch(T SourceNode);

    private:
        void BFSRecur(T SourceNode,std::queue<T> &q, std::vector<T> &ans, std::unordered_map<T, bool> &visited);
        void DFSRecur(T SourceNode, std::vector<T> &ans, std::unordered_map<T, bool> &visited);

    private:
        std::unordered_map<T, std::list<T>> adjList{};
        static T DefaultValue;

        /*
            std::vector<std::vector<T>>

            This can be used in place of map, but needs extra implementations for index
        */
    };

    template <class T>
    void Graph<T>::AddEdge(T u, T v, bool direction)
    {
        // create an edge from u to v
        adjList[u].push_back(v);

        // if undirected graph
        if (!direction)
        {
            adjList[v].push_back(u);
        }
    }

    template <class T>
    void Graph<T>::display()
    {
        for (const auto &i : adjList)
        {
            std::cout << i.first << " ---> ";
            for (const auto &j : i.second)
            {
                std::cout << j << ", ";
            }
            std::cout << '\n';
        }
    }

    template <class T>
    std::vector<T> Graph<T>::BreadthFirstSearch()
    {
        std::queue<T> q;
        std::unordered_map<T, bool> visited;
        std::vector<T> ans;

        // traverse each node
        for (const auto &node : adjList)
        {
            if (!visited[node.first])
            {
                BFSRecur(node.first, q, ans, visited);
            }
        }
        return ans;
    }

    // if user provide a default starting node

    template <class T>
    std::vector<T> Graph<T>::BreadthFirstSearch(T SourceNode)
    {
        std::queue<T> q;
        std::unordered_map<T, bool> visited;
        std::vector<T> ans;

        BFSRecur(SourceNode, q, ans, visited);

        // traverse each node
        for (const auto &node : adjList)
        {
            if (!visited[node.first])
            {
                BFSRecur(node.first, q, ans, visited);
            }
        }
        return ans;
    }

    template <class T>
    void Graph<T>::BFSRecur(T SourceNode,std::queue<T> &q, std::vector<T> &ans, std::unordered_map<T, bool> &visited)
    {
        q.push(SourceNode);
        visited[SourceNode] = true;

        while (!q.empty())
        {
            T FrontNode = q.front();
            q.pop();

            // store into answer
            ans.push_back(FrontNode);

            // traverse all neighbours of FrontNode;
            for (const auto &i : adjList[FrontNode])
            {
                if (!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    template <class T>
    std::vector<T> Graph<T>::DepthFirstSearch()
    {
        std::unordered_map<T, bool> visited;
        std::vector<T> ans;

        for(const auto &node : adjList)
        {
            if(!visited[node.first])
                DFSRecur(node.first, ans, visited);
        }
        return ans;
    }

    template <class T>
    std::vector<T> Graph<T>::DepthFirstSearch(T SourceNode)
    {
        std::unordered_map<T, bool> visited;
        std::vector<T> ans;

        DFSRecur(SourceNode, ans, visited);

        for(const auto &node : adjList)
        {
            if(!visited[node.first])
                DFSRecur(node.first, ans, visited);
        }

        return ans;
    }

    template <class T>
    void Graph<T>::DFSRecur(T SourceNode, std::vector<T> &ans, std::unordered_map<T, bool> &visited)
    {
        // marks as visited
        visited[SourceNode] = true;

        // put in the answer vector
        ans.push_back(SourceNode);

        // recur for all other nodes
        for (const auto &i : adjList[SourceNode])
        {
            if (!visited[i])
            {
                DFSRecur(i, ans, visited);
            }
        }
    }
}