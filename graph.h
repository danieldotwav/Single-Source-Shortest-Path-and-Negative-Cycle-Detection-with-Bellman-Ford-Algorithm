#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <stack>
#include <map>
using namespace std;

struct Edge {
	int source, destination, weight;
};

class Graph {
private:
	int num_vertices, num_edges;
	vector<Edge> edges;

public:
	Graph(int v, int e) : num_vertices(v), num_edges(e) {}

	void addEdge(int s, int d, int w) {
		Edge edge = { s, d, w };
		edges.push_back(edge);
	}

    void bellmanFord(int src) {
        // Initialize distance and predecessor arrays
        vector<int> distance(num_vertices, INT_MAX);
        vector<int> predecessor(num_vertices, -1);
        distance[src] = 0;

        // Relax all edges V-1 times
        for (int i = 1; i < num_vertices; ++i) {
            for (const Edge& edge : edges) {
                int u = edge.source;
                int v = edge.destination;
                int weight = edge.weight;

                if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                    predecessor[v] = u;
                }
            }
        }

        // Check for negative-weight cycles
        bool has_negative_weight_cycle = false;
        for (const Edge& edge : edges) {
            int u = edge.source;
            int v = edge.destination;
            int weight = edge.weight;

            if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                cout << "Graph contains negative weight cycle.\n";
                has_negative_weight_cycle = true;
                // Find the vertices in the cycle
                vector<int> cycle;
                int cycle_start = v;
                for (int i = 0; i < num_vertices; ++i)
                    cycle_start = predecessor[cycle_start];  // Find the start of the cycle

                int cycle_vertex = cycle_start;
                do {
                    cycle.push_back(cycle_vertex);
                    cycle_vertex = predecessor[cycle_vertex];
                } while (cycle_vertex != cycle_start);
                cycle.push_back(cycle_start);  // Close the cycle

                cout << "Cycle consists of vertices: ";
                for (int i = cycle.size() - 1; i >= 0; --i) {
                    if (i == 0) {
                        cout << cycle[i] << endl;
                    }
                    else {
                        cout << cycle[i] << " -> ";
                    }
                }
                break;  // Exit after finding one cycle
            }
        }

        if (!has_negative_weight_cycle) {
            cout << "This graph does not have a negative cycle.\n";
        }

        // Output the shortest path to all vertices
        cout << "Vertex Distance from Source Vertex" << endl;
        for (int i = 0; i < num_vertices; ++i) {
            cout << i << "\t\t" << (distance[i] == INT_MAX ? "Infinity" : to_string(distance[i])) << endl;
        }
    }
};

#endif


/*
// Test 1 - Negative Cycle

4
5
0
0 1 1
0 2 1
1 3 -6
2 3 2
3 0 3

// Test 2 - Negative Cycle (graph data from Sample Outputs)

4
5
1
0 1 1
0 2 1
1 3 -4
3 2 3
3 0 2

// Test 3 - Negative Cycle (actual input from Sample Outputs)

4
5
1
0 1 1
0 3 1
1 2 -4
2 1 2
2 3 3

// Test 4

5
6
0
0 1 2
0 2 2
1 3 3
2 3 6
2 4 4
4 3 -5

*/