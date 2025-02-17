#include <iostream>
#include <vector>
using namespace std;


void DFSRec(vector<int> adj[], int s, bool visited[]){
    visited[s] = true;   // Mark the current node as visited 
    cout<<s<<" ";       // Print the current node
    for (int i = 0; i < adj[s].size(); i++) {
    int u = adj[s][i];  // Access each adjacent vertex
    if (!visited[u]) {  // If the vertex is not visited, then recur for that vertex
        DFSRec(adj, u, visited);  // Recur for the vertex
    }
}
}

void DFS(vector<int> adj[], int v, int s){
    bool visited[v];    // Create a boolean array to keep track of visited vertices 
    for(int i=0; i<v; i++){
        visited[i] = false; // Initialize all vertices as not visited
    }
    DFSRec(adj, s, visited);    // Call the recursive helper function to print DFS traversal
}

int main(){
    int v = 5;
    vector<int> adj[v]; // Create an adjacency list

    // Add edges
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[1].push_back(4);

    int start = 0;      // Starting vertex
    DFS(adj, v, start); // Call the DFS function
    return 0;

}
