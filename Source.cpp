#include "Graph.h"
#include <exception>
#include <string>
using namespace std;

int main() {
	cout << "+++ Single Source Shortest Path with Bellman-Ford +++\n\n";
	
	try {
		string input;
		int num_vertices, num_edges, source_vertex;
		bool is_valid_input = true;

		cout << "Enter number of vertices: ";
		getline(cin, input);
		num_vertices = stoi(input); // Will throw an exception upon non-numeric input

		cout << "Enter number of edges: ";
		getline(cin, input);
		num_edges = stoi(input);

		cout << "Enter the source vertex number: ";
		getline(cin, input);
		source_vertex = stoi(input);

		// Upon valid input, we have the user define the edge properties
		int source, destination, weight;
		for (int i = 1; i < num_edges; ++i) {
			// Here we will likely use the graph class to define a create-edge function
			cout << "Enter edge " << i << " properties: Source, Destination, Weight respectively\n";
			cin >> source >> destination >> weight; // An exception will be thrown upon non-numeric input

		}
	}
	catch (invalid_argument &excp) {
		cout << "\nError: invalid input detected\n\n";
	}

	cout << "Terminating Program...\n";
	return 0;
}