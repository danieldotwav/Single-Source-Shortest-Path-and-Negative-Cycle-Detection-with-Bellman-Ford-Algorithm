#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <limits>
#include <vector>
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
		vector<int> distance(num_vertices, INT_MAX);
		distance[src] = 0;

		// Relax all edges V-1 times
		for (int i = 1; i < num_vertices - 1; ++i) {
			for (const Edge& edge : edges) {
				int u = edge.source;
				int v = edge.destination;
				int weight = edge.weight;

				if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
					distance[v] = distance[u] + weight;
				}
			}
		}

		// Now we check for negative weight cycles
		bool has_negative_weight_cycle = false;
		for (const Edge& edge : edges) {
			int u = edge.source;
			int v = edge.destination;
			int weight = edge.weight;

			if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
				has_negative_weight_cycle = true;
			}
		}

		if (has_negative_weight_cycle) {
			// TODO: Add a utility function to backtrack through the vertices that form the negative-weight cycle
		}
		else {
			cout << "This graph does not have a negative cycle.\n";
		}

		cout << "Vertext Distance from Source Vertex" << endl;
		for (int i = 0; i < num_vertices; ++i) {
			cout << i << "\t\t" << distance[i] << endl;
		}
	}
};

#endif