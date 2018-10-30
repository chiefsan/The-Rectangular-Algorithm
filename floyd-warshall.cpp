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
  std::vector<std::vector<int>> next(num_vertices);
  for (auto i = 0; i < num_vertices; i++) {
    for (auto j = 0; j < num_vertices; j++) {
      next[i].push_back(0);
    }
    for (auto j = 0; j < num_vertices; j++) {
      if (i != j) {
        next[i][j] = j + 1;
      }
    }
  }
  auto start = std::chrono::high_resolution_clock::now();
  for (auto k = 0; k < num_vertices; k++) {
    for (auto i = 0; i < num_vertices; i++) {
      for (auto j = 0; j < num_vertices; j++) {
        if (dist[i][j] > dist[i][k] + dist[k][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
          next[i][j] = next[i][k];
        }
      }
    }
  }
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
  std::ofstream myfile("fw_output.txt");
  myfile << duration.count();
  myfile.close();
}

int main (int argc, char **argv) {
  int n = atoi(argv[1]);
  std::vector<std::vector<double>> w(n);
  for (int i=0; i<n; i++) {
    w[i].resize(n);
  }

  std::ifstream myfile("input.txt", std::ios::in);
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++) {
      myfile>>w[i][j];
      if (w[i][j]==0)
        w[i][j] = INT_MAX;
    }

  int num_vertices = n;

  solve (w, num_vertices);
  return 0;
}
