
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// BFS traversal Function

void BFS(vector<int> adj[], int v, int s, bool visited[]){
    queue<int> q;
    visited[s] = true;
    q.push(s);

    while(q.empty() == false){
        int u = q.front();
        q.pop();
        cout<<u<<" ";

        // Traverse all adjacent vertices of u
        for(int i=0; i<adj[u].size(); i++){
            int vertex = adj[u][i];
            if(!visited[vertex]){
                visited[vertex] = true;
                q.push(vertex);
            }
        }
    }
}

// Function to perform BFS for disconnected graph

void BFSDis(vector<int> adj[], int v){
    bool visited[v];

    // initialise all vertices as unvisited
    for(int i=0; i<v; i++){
        visited[i] = false;
    }

    // Call BFS for every unvisited node
       for(int i=0; i<v; i++){
        if(visited[i] == false){
            BFS(adj, v, i, visited);
        }
    }
}


// Main Function for testing the BFS Code
int main(){
    int v = 5; // Number of vertices
    vector<int> adj[v];  // Adjacency List representation of graph

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);

    cout<<"BFS traversal of the graph is: ";
    BFSDis(adj, v); // calling BFS on graph

    return 0;
}
