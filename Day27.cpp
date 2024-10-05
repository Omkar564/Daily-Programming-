#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int shortestPath(int V, const vector<pair<int, int>>& edges, int start, int end) {
    // Create an adjacency list
    unordered_map<int, vector<int>> graph;
    for (const auto& edge : edges) {
        graph[edge.first].push_back(edge.second);
        graph[edge.second].push_back(edge.first); // because the graph is undirected
    }
    
    // BFS initialization
    queue<int> q;
    vector<bool> visited(V, false);
    vector<int> distance(V, -1); // To store the distance from start
    
    q.push(start);
    visited[start] = true;
    distance[start] = 0;

    // BFS loop
    while (!q.empty()) {
        int current = q.front();
        q.pop();

        // Check neighbors
        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                distance[neighbor] = distance[current] + 1; // Increment distance
                q.push(neighbor);

                // Stop if we reach the end node
                if (neighbor == end) {
                    return distance[neighbor];
                }
            }
        }
    }
    
    // If we finish BFS without finding the end node
    return -1;
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    
    cout << "Enter number of edges: ";
    cin >> E;

    vector<pair<int, int>> edges(E);
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < E; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }

    int start, end;
    cout << "Enter start and end nodes: ";
    cin >> start >> end;

    int result = shortestPath(V, edges, start, end);
    if (result != -1) {
        cout << "Shortest path length: " << result << endl;
    } else {
        cout << "No path exists." << endl;
    }

    return 0;
}
