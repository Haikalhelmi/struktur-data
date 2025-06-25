#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

const int N = 10;
int cost[N][N];
int m;

int main() {
    cout << "Masukkan Jumlah Kota : ";
    cin >> m;

    // Input cost matrix per baris
    cout << "Nilai Cost Matrix\n";
    for (int i = 0; i < m; i++) {
        cout << "Cost Element Baris ke-: " << i + 1 << endl;
        for (int j = 0; j < m; j++) {
            cin >> cost[i][j];
            if (i != j && cost[i][j] == 0)
                cost[i][j] = INT_MAX; // Anggap tidak terhubung
        }
    }

    // Tampilkan Cost List
    cout << "\nCost List :\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (cost[i][j] == INT_MAX) cout << "*\t";
            else cout << cost[i][j] << "\t";
        }
        cout << endl;
    }

    // Permutasi kota untuk mencari rute minimum (TSP TERTUTUP)
    vector<int> nodes;
    for (int i = 0; i < m; i++) nodes.push_back(i);

    int minCost = INT_MAX;
    vector<int> bestPath;

    do {
        int total = 0;
        bool valid = true;
        for (int i = 0; i < m - 1; i++) {
            if (cost[nodes[i]][nodes[i + 1]] == INT_MAX) {
                valid = false;
                break;
            }
            total += cost[nodes[i]][nodes[i + 1]];
        }

        // Tambahkan kembali ke awal (karena TSP tertutup)
        if (valid && cost[nodes[m - 1]][nodes[0]] != INT_MAX) {
            total += cost[nodes[m - 1]][nodes[0]];
            if (total < minCost) {
                minCost = total;
                bestPath = nodes;
            }
        }

    } while (next_permutation(nodes.begin(), nodes.end()));

    // Tampilkan hasil jalur dan biaya minimum
    if (!bestPath.empty()) {
        cout << "\nJalur Terpendek :\n";
        for (int i = 0; i < bestPath.size(); i++) {
            cout << bestPath[i] + 1 << "--->";
        }
        cout << bestPath[0] + 1 << endl;
        cout << "\nMinimum Cost : " << minCost << endl;
    } else {
        cout << "Tidak ada jalur yang valid untuk semua kota.\n";
    }

    return 0;
}

