#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <limits>
#include <vector>
using namespace std;

struct Edge {
	int source, destination, weight;
};

struct Graph {
	int V, E;
	vector<Edge> edges;

	void addEdge(int s, int d, int w) {
		Edge edge = { s, d, w };
		edges.push_back(edge);
	}

	void bellmanFord(int src) {
		vector<int> distance(V, INT_MAX);
		distance[src] = 0;

		// Relax all edges V-1 times
		for (int i = 1; i < V - 1; ++i) {
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
		for (const Edge& edge : edges) {
			int u = edge.source;
			int v = edge.destination;
			int weight = edge.weight;

			if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
				cout << "Graph contains a negative weight cycle" << endl;
				return;
			}
		}

		cout << "Vertext Distance from Source" << endl;
		for (int i = 0; i < V; ++i) {
			cout << i << "\t\t" << distance[i] << endl;
		}
	}
};

#endif