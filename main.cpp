#include "AdjacencyMatrix.h"
#include "AdjacencyList.h"

int main()
{
    AdjacencyList::Graph<int> g1({{0, {1,2,3}}, {1, {0,2}}, {2, {0,1,3, 4}}, {3, {0,2,4}}, {4, {2, 3, 5, 6}}, {5, {4}}, {6, {4}}});
    AdjacencyMatrix::Graph<int> g2({{0, {1,2,3}}, {1, {0,2}}, {2, {0,1,3, 4}}, {3, {0,2,4}}, {4, {2, 3, 5, 6}}, {5, {4}}, {6, {4}}});

    // g1.AddEdge(1,2);
    // g1.AddEdge(2,3);
    // g1.AddEdge(1,3);
    // g1.AddEdge(2,4);

    // g2.AddEdge(1,2);
    // g2.AddEdge(2,3);
    // g2.AddEdge(1,3);
    // g2.AddEdge(2,4);
    
    std::vector<int> ans = g1.DepthFirstSearch(1);
    
    for(const auto &i : ans)
    {
        std::cout<< i << ' ';
    }

    std::cout<<'\n';

    std::vector<int> ans2 = g2.BreadthFirstSearch(1);
    
    for(const auto &i : ans2)
    {
        std::cout<< i << ' ';
    }

    return 0;
}