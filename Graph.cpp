#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

class Graph {
  std::unordered_map<std::string, std::unordered_set<std::string>> adjList;

 public:
  void printGraph() const {
    for (const auto& kv : adjList) {
      std::cout << kv.first << ": [";
      bool first = true;
      for (const auto& n : kv.second) {
        if (!first) std::cout << ' ';
        first = false;
        std::cout << n;
      }
      std::cout << "]\n";
    }
  }

  bool addVertex(const std::string& vertex) {
    if (adjList.find(vertex) == adjList.end()) {
      adjList[vertex] = {};
      return true;
    }
    return false;
  }

  bool addEdge(const std::string& vertex1, const std::string& vertex2) {
    if (adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0) {
      adjList.at(vertex1).insert(vertex2);
      adjList.at(vertex2).insert(vertex1);
      return true;
    }
    return false;
  }

  bool removeEdge(const std::string& vertex1, const std::string& vertex2) {
    if (adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0) {
      adjList.at(vertex1).erase(vertex2);
      adjList.at(vertex2).erase(vertex1);
      return true;
    }
    return false;
  }

  bool removeVertex(const std::string& vertex) {
    if (adjList.count(vertex) != 0) {
      for (const auto& i : adjList[vertex]) adjList[i].erase(vertex);
      adjList.erase(vertex);
      return true;
    }
    return false;
  }
};

void sample_test_graph() {
  Graph g;
  g.addVertex("A");
  g.addVertex("B");
  g.addEdge("A", "B");
  std::cout << "Graph:\n";
  g.printGraph();
}

#if defined(SAMPLE_TEST_MAIN)
int main() {
  sample_test_graph();
  return 0;
}
#endif
