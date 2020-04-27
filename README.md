# The Rectangular Algorithm

- The Floyd-Warshall algorithm is an algorithm for finding shortest paths between every two vertices in a weighted graph with positive or negative edge weights (but with no negative cycle).
- The [Rectangular algorithm](https://www.sciencedirect.com/science/article/pii/S0893965911002928 "Rectangular algorithm") is an algorithm that solves the same problem as Floyd-Warshall algorithm, requiring lesser computational effort. 

This repository contains C++ implementations of the above mentioned algorithms. 

## Running the algorithms
- Two important methods in `<algorithm-name>.cpp` are 
	- `solve` - solve the problem on the given graph using &lt;algorithm-name&gt; algorithm (`main.cpp` contains a simple function to generate a random graph)
	- `print` - print the solution to stdout.  The function can be modified to print the output elsewhere 