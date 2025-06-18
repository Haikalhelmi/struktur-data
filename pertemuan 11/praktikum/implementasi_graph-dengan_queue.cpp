#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // Tambahkan baris ini!

#define M 1000

using namespace std;

// ... sisa kode Anda ...

const int N = 5;

void dijkstra(int graph[N][N], int source, int destination) {
    // Perbaikan: Tambahkan spasi antara '>' dan '>'
    vector<pair<int, int> > adj[N]; // Perbaikan di sini

    // Membuat adjacency list
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // Asumsi: graph[i][j] == 0 berarti tidak ada edge, atau self-loop.
            // graph[i][j] == M berarti tidak dapat dijangkau (infinity).
            // Kita ingin menambahkan edge hanya jika ada bobot yang valid dan bukan M.
            if (graph[i][j] != 0 && graph[i][j] != M) {
                adj[i].push_back(make_pair(j, graph[i][j]));
            }
        }
    }

    int Q[N], R[N]; // Q untuk jarak terpendek, R untuk rute/predesesor
    for (int i = 0; i < N; i++) {
        Q[i] = M; // Inisialisasi jarak dengan nilai 'infinity' (M)
        R[i] = -1; // Inisialisasi predesesor dengan -1 (belum ada rute)
    }

    // Perbaikan: Tambahkan spasi antara '>' dan '>' pada deklarasi priority_queue
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    // karena input dari user 1-based, kurangi 1 untuk 0-based index
    pq.push(make_pair(0, source - 1));
    Q[source - 1] = 0; // Jarak dari sumber ke diri sendiri adalah 0

    while (!pq.empty()) {
        int u = pq.top().second; // Node dengan jarak terpendek saat ini
        pq.pop();

        // Iterasi melalui tetangga node u
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;  // Tetangga
            int w = adj[u][i].second; // Bobot edge ke tetangga

            // Relaksasi: Jika jarak baru lebih pendek
            if (Q[v] > Q[u] + w) {
                Q[v] = Q[u] + w; // Perbarui jarak
                R[v] = u;        // Set predesesor
                pq.push(make_pair(Q[v], v)); // Masukkan ke priority queue
            }
        }
    }

    // Output hasil jarak terpendek dari source ke semua node
    cout << "Beban = ";
    for (int i = 0; i < N; i++) {
        cout << Q[i] << " ";
    }
    cout << endl;

    // Output rute/predesesor
    cout << "Rute = ";
    for (int i = 0; i < N; i++) {
        cout << R[i] << " ";
    }
    cout << endl;

    // Tambahan: Menampilkan jalur spesifik ke destination
    cout << "Jalur dari " << source << " ke " << destination << ": ";
    if (Q[destination - 1] == M) {
        cout << "Tidak dapat dijangkau." << endl;
    } else {
        vector<int> path;
        int current = destination - 1;
        while (current != -1) {
            path.push_back(current + 1); // Tambahkan 1 untuk kembali ke 1-based index
            current = R[current];
        }
        reverse(path.begin(), path.end()); // Balikkan jalur
        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i < path.size() - 1) {
                cout << " -> ";
            }
        }
        cout << endl;
        cout << "Total Beban: " << Q[destination - 1] << endl;
    }
}

int main() {
    // Matriks adjacency untuk graph
    int graph[N][N] = {
        {0, 1, 3, M, M}, // Node 0
        {M, 0, 1, M, 5}, // Node 1
        {M, M, 0, 2, M}, // Node 2
        {M, M, M, 0, 1}, // Node 3
        {M, M, M, M, 0}  // Node 4
    };

    int source, destination;
    cout << "Masukkan node asal (1-" << N << "): ";
    cin >> source;
    cout << "Masukkan node tujuan (1-" << N << "): ";
    cin >> destination;

    dijkstra(graph, source, destination);

    return 0;
}
