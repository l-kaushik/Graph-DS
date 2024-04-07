#include "Graph.h"

int main()
{
    Graph<int> g;

    g.AddEdge(1,2);
    g.AddEdge(2,3);
    g.AddEdge(1,3);
    g.AddEdge(2,4);
    g.display();
    return 0;
}