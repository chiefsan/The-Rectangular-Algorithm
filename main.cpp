#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

/*
  Generate a random graph (adjacency matrix representation)
  
  Parameters
  n : int, number of vertices in the random graph

  Output
  Adjacency matrix,  int**
*/
int **randGraph(int n)
{
  int **a = new int *[n];
  for (int i = 0; i < n; i++)
  {
    a[i] = new int[n];
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i == j)
      {
        a[i][j] = 0;
      }
      else
      {
        a[i][j] = rand() % 1000 + 1;
        if (a[i][j] % 2)
          a[i][j] = 0;
      }
    }
  }
  return (a);
}

int main(int argc, char **argv)
{

  int num_vertices = atoi(argv[1]);

  int **adj = randGraph(num_vertices);
  ofstream myfile("input.txt");
  for (int i = 0; i < num_vertices; i++)
    for (int j = 0; j < num_vertices; j++)
    {
      myfile << adj[i][j] << ' ';
    }

  myfile.close();
  system("g++ -o fw floyd-warshall.cpp");
  system("g++ -o ra rectangular.cpp");

  auto start = high_resolution_clock::now();
  system("fw 300");
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << "Time taken by function fw: " << duration.count() << " microseconds" << endl;

  start = high_resolution_clock::now();
  system("ra 300");
  stop = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start);
  cout << "Time taken by function ra: " << duration.count() << " microseconds" << endl;
}
