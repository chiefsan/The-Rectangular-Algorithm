#include <bits/stdc++.h>

void print(std::vector<std::vector<double>> dist, std::vector<std::vector<int>> next) {
  const auto size = next.size();
  for (auto i = 0; i < size; ++i) {
    for (auto j = 0; j < size; ++j) {
      if (i != j) {
        auto u = i + 1;
        auto v = j + 1;
        std::cout << "(" << u << " -> " << v << ", " << dist[i][j]
          << ", ";
        std::stringstream path;
        path << u;
        do {
          u = next[u - 1][v - 1];
          path << " -> " << u;
        } while (u != v);
        std::cout << path.str() << ")" << std::endl;
      }
    }
  }
}

void solve(std::vector<std::vector<double>> dist, const int num_vertices) {

  std::bitset<10000> row_inf(0), col_inf(0);
  std::vector<std::vector<int>> next(num_vertices);
  for (auto i = 0; i < num_vertices; ++i) {
    next[i].resize(num_vertices);
    for (auto j = 0; j < num_vertices; ++j) {
      if (dist[i][j]==INT_MAX) {
        row_inf[i] = col_inf[j] = 1;
      }
      if (i != j) {
        next[i][j] = j + 1;
      }
    }
  }
  auto start = std::chrono::high_resolution_clock::now();
  for (auto j = 0; j < num_vertices; ++j) {
    for (auto i = 0; i < num_vertices; ++i) {
      for (auto k = 0; k < num_vertices; ++k) {
        if (i==j || k==j)
          continue;
        if (dist[i][k]!=INT_MAX && (row_inf[i] || row_inf[k])) {
          continue;
        }
        if (dist[i][j]<INT_MAX && dist[j][k]<INT_MAX && (dist[i][k] > dist[i][j] + dist[j][k])) {
          dist[i][k] = dist[i][j] + dist[j][k];
          next[i][k] = next[i][j];
          row_inf[i] = col_inf[k] = 0;
        }
      }
    }
  }
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
  std::ofstream myfile("ra_output.txt");
  myfile << duration.count();
  myfile.close();
}

int main (int argc, char **argv) {
  auto n = atoi(argv[1]);
  std::vector<std::vector<double>> w(n);
  for (auto i=0; i<n; ++i) {
    w[i].resize(n);
  }

  std::ifstream myfile("input.txt", std::ios::in);
  for (auto i=0; i<n; ++i)
    for (auto j=0; j<n; ++j) {
      myfile>>w[i][j];
      if (w[i][j]==0)
        w[i][j] = INT_MAX;
    }

  auto num_vertices = n;
  solve (w, num_vertices);
  // cin.ignore();
  // cin.get();
  return 0;
}
