#include "AdjacencyMatrix.h"
#include "AdjacencyList.h"

int main()
{
    AdjacencyList::Graph<int> g1({{0, {1,2,3}}, {1, {0,2}}, {2, {0,1,3, 4}}, {3, {0,2,4}}, {4, {2, 3, 5, 6}}, {5, {4}}, {6, {4}}, {10,{11, 12}}});
    AdjacencyMatrix::Graph<int> g2({{0, {1,2,3}}, {1, {0,2}}, {2, {0,1,3, 4}}, {3, {0,2,4}}, {4, {2, 3, 5, 6}}, {5, {4}}, {6, {4}}});

    // g1.AddEdge(1,2);
    // g1.AddEdge(2,3);
    // g1.AddEdge(1,3);
    // g1.AddEdge(2,4);

    // g2.AddEdge(1,2);
    // g2.AddEdge(2,3);
    // g2.AddEdge(1,3);
    // g2.AddEdge(2,4);
    
    if(g1.isCyclicBFS())
        std::cout << "Yes";
    else
        std::cout << "No";

    return 0;
}