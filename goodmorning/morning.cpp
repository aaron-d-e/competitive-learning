#include <bits/stdc++.h>
using namespace std;

// edges available for travel
vector<pair<int, int>> edges = {{1, 2}, {1, 4}, {2, 5}, {2, 3}, {3, 6},
                                {4, 5}, {4, 7}, {5, 6}, {5, 8}, {6, 9},
                                {7, 8}, {8, 9}, {8, 0}};

int current_node = 1;  // edge index n - 1

void addEdge(vector<vector<int>>& adj, int s, int t) {
    adj[s].push_back(t);
}

// function to iterate through nodes, circular array DOWN,RIGHT,DOWN,RIGHT,etc
// is there a way to make the graph at runtime to let DFS do all the work

void DFSRec(vector<vector<int>>& adj, vector<bool>& visited, int source) {
    visited.at(source) = true;
    cout << source << " ";
}

void DFS(vector<vector<int>>& adj, int source) {
    vector<bool> visited(10, false);  // 10 nodes in the graph

    DFSRec(adj, visited, source);
}

int main() {
    vector<vector<int>> adj(10);
    for (auto& e : edges) {
        addEdge(adj, e.first, e.second);
    }

    int j = 0;
    for (const auto& v : adj) {
        cout << j << ": ";
        for (const auto& node : v) {
            cout << node << " ";
        }
        cout << endl;
        j++;
    }
    DFS(adj, current_node);

    return 0;
}
