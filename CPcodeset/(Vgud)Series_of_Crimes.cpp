#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<int> row_count(n, 0), col_count(m, 0);

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '1') {
                row_count[i]++;
                col_count[j]++;
                
            }
        }
    }

    int req_row = -1, req_col = -1;

    for (int i = 0; i < n; i++) {
        if (row_count[i] == 1) {
            req_row = i + 1; // 1-indexed
            break;
        }
    }

    for (int j = 0; j < m; j++) {
        if (col_count[j] == 1) {
            req_col = j + 1; // 1-indexed
            break;
        }
    }

    cout << req_row << " " << req_col << "\n";
    return 0;
}
