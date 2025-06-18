#include <iostream> // Digunakan untuk cout, cin
#include <vector>   // Digunakan untuk std::vector
#include <queue>    // Digunakan untuk std::priority_queue
#include <limits>   // Digunakan untuk std::numeric_limits
// #include <bits/stdc++.h> // Hindari penggunaan ini di proyek riil, lebih baik sertakan header yang spesifik
#include <cstring>  // Digunakan untuk memset

#define MAX 100005
#define INF std::numeric_limits<int>::max() // Cara yang lebih aman untuk mendefinisikan infinity

using namespace std;

// Perbaikan Error 1: Tambahkan spasi di antara '>' >'
vector<pair<int, int> > adj[MAX];
bool vis[MAX];
int dist[MAX];

void dijkstra(int start)
{
    memset(vis, false, sizeof(vis)); // Inisialisasi semua node belum dikunjungi
    for (int i = 0; i < MAX; i++)
        dist[i] = INF; // Inisialisasi jarak ke semua node sebagai infinity

    dist[start] = 0; // Jarak dari node awal ke dirinya sendiri adalah 0

    // Perbaikan Error 1: Tambahkan spasi di antara '>' >'
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    // Perbaikan Warning 2: Gunakan make_pair() untuk kompatibilitas yang lebih luas
    // Atau pastikan Anda mengkompilasi dengan -std=c++11 atau lebih tinggi
    pq.push(make_pair(0, start));

    while (!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();

        int d = p.first; // Jarak ke node saat ini
        int u = p.second; // Node saat ini (u)

        // Jika node sudah pernah dikunjungi dengan jarak yang lebih pendek, lewati
        if (d > dist[u]) { // Penting: Periksa jika jarak yang diambil dari PQ lebih besar dari yang sudah ditemukan
            continue;
        }

        // Iterasi melalui semua tetangga (v) dari node saat ini (u)
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].first;  // Tetangga (v)
            int weight = adj[u][i].second; // Bobot edge dari u ke v

            // Relaksasi: Jika jarak dari start ke v melalui u lebih pendek dari jarak yang sudah ada
            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight; // Perbarui jarak terpendek ke v
                // Perbaikan Warning 2: Gunakan make_pair()
                pq.push(make_pair(dist[v], v)); // Masukkan ke priority queue
            }
        }
    }
}

int main()
{
    // Mengisi adjacency list
    // Asumsi node dimulai dari 1 (sesuai penggunaan adj[1], adj[2], dst)
    // Jika MAX adalah 100005, pastikan indeks yang digunakan valid
    // MAX ini sepertinya terlalu besar untuk contoh kecil 5 node
    // Mungkin disarankan untuk menggunakan N atau jumlah node sebenarnya
    // untuk adj (e.g., vector<pair<int, int>> adj[N+1]; jika N adalah jumlah node)
    // Untuk contoh ini, saya akan asumsikan MAX cukup besar.

    adj[1].push_back(make_pair(2, 3)); // Edge dari node 1 ke 2 dengan bobot 3
    adj[2].push_back(make_pair(1, 3)); // Edge dari node 2 ke 1 dengan bobot 3
    adj[2].push_back(make_pair(3, 2)); // Edge dari node 2 ke 3 dengan bobot 2
    adj[3].push_back(make_pair(2, 2)); // Edge dari node 3 ke 2 dengan bobot 2
    adj[3].push_back(make_pair(4, 4)); // Edge dari node 3 ke 4 dengan bobot 4
    adj[3].push_back(make_pair(5, 5)); // Edge dari node 3 ke 5 dengan bobot 5
    adj[4].push_back(make_pair(3, 4)); // Edge dari node 4 ke 3 dengan bobot 4
    adj[5].push_back(make_pair(3, 5)); // Edge dari node 5 ke 3 dengan bobot 5

    // Memanggil algoritma Dijkstra dari node 1
    dijkstra(1);

    // Menampilkan jarak terpendek dari node 1 ke node 5
    cout << "Jarak terpendek dari node 1 ke node 5 adalah " << dist[5] << endl;

    return 0;
}
