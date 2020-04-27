#include <bits/stdc++.h>

/*
Print the solution

Parameters
dist - distance matrix, vector<std::vector<double>>
next - next matrix, vector<std::vector<int>>
*/
void print(std::vector<std::vector<double>> dist, std::vector<std::vector<int>> next)
{
  const auto size = next.size();
  for (auto i = 0; i < size; ++i)
  {
    for (auto j = 0; j < size; ++j)
    {
      if (i != j)
      {
        auto u = i + 1;
        auto v = j + 1;
        std::cout << "(" << u << " -> " << v << ", " << dist[i][j]
                  << ", ";
        std::stringstream path;
        path << u;
        do
        {
          u = next[u - 1][v - 1];
          path << " -> " << u;
        } while (u != v);
        std::cout << path.str() << ")" << std::endl;
      }
    }
  }
}

/*
Compute the solution

Parameters
dist - distance matrix, vector<std::vector<double>>
num_vertices - number of vertices, int
*/
void solve(std::vector<std::vector<double>> dist, const int num_vertices)
{
  register unsigned int t, r, s, i, k, j, m;
  std::vector<std::vector<int>> next(num_vertices);
  for (i = 0; i < num_vertices; ++i)
    next[i].resize(num_vertices);
  for (i = 0; i < num_vertices; ++i)
  {
    for (j = 0; j < num_vertices; ++j)
    {
      if (i != j)
      {
        next[i][j] = j + 1;
      }
    }
  }
  // Uncomment lines 51, 71-76 to dump running time in a file (fw_output.txt)
  // auto start = std::chrono::high_resolution_clock::now();
  for (j = 0; j < num_vertices; ++j)
  {
    for (i = 0; i < num_vertices; ++i)
    {
      r = dist[i][j];
      if (r == INT_MAX)
      {
        continue;
      }
      for (k = 0; k < num_vertices; ++k)
      {
        t = dist[j][k];
        if (t == INT_MAX || i == j || k == j)
        {
          continue;
        }
        s = dist[i][k];
        if (s > r + t)
        {
          s = r + t;
          next[i][k] = next[i][j];
        }
      }
    }
  }
  // auto stop = std::chrono::high_resolution_clock::now();
  // auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

  // std::ofstream myfile("ra_output.txt");
  // myfile << duration.count();
  // myfile.close();
}

int main(int argc, char **argv)
{

  auto num_vertices = atoi(argv[1]);

  std::vector<std::vector<double>> w(num_vertices);
  for (auto i = 0; i < num_vertices; ++i)
  {
    w[i].resize(num_vertices);
  }

  std::ifstream myfile("input.txt", std::ios::in);
  for (auto i = 0; i < num_vertices; ++i)
    for (auto j = 0; j < num_vertices; ++j)
    {
      myfile >> w[i][j];
      if (w[i][j] == 0)
        w[i][j] = INT_MAX;
    }

  solve(w, num_vertices);

  w.clear();

  return 0;
}
