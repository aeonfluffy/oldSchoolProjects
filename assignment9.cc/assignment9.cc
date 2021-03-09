#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <stack>
#include "assignment9.h"
using namespace std;


//container for visited first traversal
vector<bool> seen;
//container to hold order
vector<char> order;

graph::graph( const char* filename)
{
	ifstream infile(filename);

	//get size
	infile >> size;
	//add edges
	for(int i = 0; i < size; i++)
	{
		//set label

	}
	
}

graph::~graph()
{
	
}

void graph::depth_first(int v)
{
	//mark as visited
	seen[v] = true;
	//visit
	order.push_back(labels[v]);
	//for each vertex w adjacent to v
	//get # of adjacent nodes to v
	for(int w = 0; w < adj_list[v].size(); w++)
	{
		if(!seen[w])
			{
				depth_first(w);
			}
	}
}

int graph::get_size() const
{
	return size;
}

void graph::traverse()
{
		//initialise the vector stuff
	for (int i = 0; i < size; i++)
	{
		seen.push_back(false);
	}

	for(int i = 0; i < size; i++)
	{
		if(!seen[i])
		{
			depth_first(i);
		}
	}
}

void graph::print() const
{
	
}





#define ASSIGNMENT9_TEST
#ifdef  ASSIGNMENT9_TEST

int main(int argc, char** argv) {
    if ( argc < 2 ) {
        cerr << "args: input-file-name\n";
        return 1;
    }

    graph g(argv[1]);

    g.print();

    g.traverse();


    return 0;
}

#endif

