#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <limits>
#include <vector>
#include <stack>
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

	void printCycle(int start, vector<int>& predecessor) {
		int current = start;
		vector<bool> visited(num_vertices, false); // Initialize all vertices to unvisited
		stack<int> cycle; // Store the cycle

		// 
		while (!visited[current]) {
			visited[current] = true;
			cycle.push(current);
			current = predecessor[current];
		}

		// Print the cycle starting from the first detected repeating vertex
		vector<int> path;
		while (!cycle.empty() && cycle.top() != current) {
			cycle.pop();
		}

		while (!cycle.empty()) {
			path.push_back(cycle.top());
			cycle.pop();
		}

		cout << "Negative weight cycle: ";
		for (auto it = path.rbegin(); it != path.rend(); ++it) {
			cout << *it << " -> ";
		}
		cout << path.front() << endl; // to complete the cycle
	}

	void bellmanFord(int src) {
		// First, we initialize a distance array
		vector<int> distance(num_vertices, INT_MAX); // The distance from the source to all other vertices is assumed to be infinite
		vector<int> predecessor(num_vertices, -1);
		distance[src] = 0; // The shortest distance from the source to itself is zero

		// Relax all edges V-1 times
		for (int i = 1; i < num_vertices - 1; ++i) {
			for (const Edge& edge : edges) {
				int u = edge.source;
				int v = edge.destination;
				int weight = edge.weight;

				// If the current known distance to vertex v through u is less 
				if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
					distance[v] = distance[u] + weight;
					predecessor[v] = u;
				}
			}
		}

		// If any edge can still be relaxed after the previous loop, then we know there is a negative-weight cycle
		bool has_negative_weight_cycle = false;
		for (const Edge& edge : edges) {
			int u = edge.source;
			int v = edge.destination;
			int weight = edge.weight;

			if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
				cout << "Graph contains negative weight cycle.\n";
				printCycle(v, predecessor);
				has_negative_weight_cycle = true;
				return;
			}
		}

		if (!has_negative_weight_cycle) {
			cout << "This graph does not have a negative cycle.\n";
		}

		cout << "Vertext Distance from Source Vertex" << endl;
		for (int i = 0; i < num_vertices; ++i) {
			cout << i << "\t\t" << distance[i] << endl;
		}
	}
};

#endif