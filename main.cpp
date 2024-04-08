#include "AdjacencyMatrix.h"
#include "AdjacencyList.h"

int main()
{
    AdjacencyList::Graph<int> g1({{1, {2,3,4}}, {2, {1, 3, 4}}, {3, {1, 2}}});
    AdjacencyMatrix::Graph<int> g2({{1, {2,3,4}}, {2, {1, 3, 4}}, {3, {1, 2}}});

    // g1.AddEdge(1,2);
    // g1.AddEdge(2,3);
    // g1.AddEdge(1,3);
    // g1.AddEdge(2,4);

    // g2.AddEdge(1,2);
    // g2.AddEdge(2,3);
    // g2.AddEdge(1,3);
    // g2.AddEdge(2,4);
    
    std::vector<int> ans = g1.BreadthFirstSearch(1);
    
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