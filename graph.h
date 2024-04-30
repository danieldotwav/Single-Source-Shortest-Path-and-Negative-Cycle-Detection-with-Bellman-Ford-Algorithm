#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
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

};

#endif