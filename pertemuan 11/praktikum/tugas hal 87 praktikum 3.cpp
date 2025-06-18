#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000
using namespace std;

const int N = 6;

void dijkstra(int graph[N][N], int source, int destination) {
    vector< pair<int, int> > adj[N];
    
    // Buat adjacency list dari matriks
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (graph[i][j] != INF && i != j) {
                adj[i].push_back(make_pair(j, graph[i][j]));
            }
        }
    }

    int dist[N], prev[N];
    for (int i = 0; i < N; i++) {
        dist[i] = INF;
        prev[i] = -1;
    }

    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;

    dist[source] = 0;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                prev[v] = u;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    // Output hasil
    cout << "Jarak minimum dari " << source + 1 << " ke " << destination + 1 << " adalah: " << dist[destination] << endl;

    // Cetak rute terpendek
    vector<int> path;
    for (int at = destination; at != -1; at = prev[at]) {
        path.push_back(at);
    }

    cout << "Rute terpendek: ";
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] + 1;
        if (i > 0) cout << " -> ";
    }
    cout << endl;
}

int main() {
    int graph[N][N] = {
        // 1   2   3   4   5   6
        {  0,  7,  9, INF, INF, 14}, // 1
        {INF, 0, INF, 15, INF, INF}, // 2
        {INF, 10, 0, 11, INF, 2 },   // 3
        {INF, INF, INF, 0, 6, INF},  // 4
        {INF, INF, INF, INF, 0, 9},  // 5
        {INF, INF, INF, INF, 9, 0}   // 6
    };

    int source, destination;
    cout << "Masukkan node asal (1-6): ";
    cin >> source;
    cout << "Masukkan node tujuan (1-6): ";
    cin >> destination;

    dijkstra(graph, source - 1, destination - 1);

    return 0;
}

