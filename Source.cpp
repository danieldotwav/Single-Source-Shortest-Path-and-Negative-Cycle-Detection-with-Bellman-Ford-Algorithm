#include <iostream>
#include <exception>
#include <string>
using namespace std;

int main() {
	cout << "+++ Single Source Shortest Path with Bellman-Ford +++\n\n";
	
	try {
		string input;
		int num_vertices, num_edges, source_vertex;

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
		for (int i = 1; i < num_edges; ++i) {
			// Here we will likely use the graph class to define a create-edge function
		}
	}
	catch (invalid_argument &excp) {
		cout << "\nError: invalid input detected\n\n";
	}

	cout << "Terminating Program...\n";
	return 0;
}