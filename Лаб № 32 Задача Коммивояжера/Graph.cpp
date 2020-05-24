#include "Graph.h"
#include <string>

Graph<char> graph;
int main(int argc, char** argv)
{
	system("color F0");
	setlocale(LC_ALL, "ru");
	int size = 5;
	graph.addVertex('1');
	graph.addVertex('2');
	graph.addVertex('3');
	graph.addVertex('4');
	graph.addVertex('5');
	graph.addEdgeIn();

	graph.Print();
	cout << endl;
	graph.Salesman();
	graph.drawGraph(argc, argv);
	return 0;
}