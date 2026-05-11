#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> queens_attack_the_king(vector<vector<int>>& queens, vector<int>& king) {
    // Initialize an 8x8 board. (Board indices: 0 to 7)
    vector<vector<bool>> board(8, vector<bool>(8, false));
    for (auto& q : queens) {
        board[q[0]][q[1]] = true;
    }
    
    vector<vector<int>> result;
    // Directions in the required order: up-left, up, up-right, left, right, down-left, down, down-right.
    vector<vector<int>> directions = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1}, {0, 1},
        {1, -1}, {1, 0}, {1, 1}
    };
    
    int r0 = king[0], c0 = king[1];
    for (auto& d : directions) {
        int dr = d[0], dc = d[1];
        int r = r0, c = c0;
        while (true) {
            r += dr;
            c += dc;
            if (r < 0 || r >= 8 || c < 0 || c >= 8)
                break;
            if (board[r][c]) {
                result.push_back({r, c});
                break;
            }
        }
    }
    
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> queens(n, vector<int>(2));
    for (int i = 0; i < n; ++i) {
        cin >> queens[i][0] >> queens[i][1];
    }
    vector<int> king(2);
    cin >> king[0] >> king[1];

    vector<vector<int>> result = queens_attack_the_king(queens, king);

    // Print the coordinates in one line separated by spaces.
    for (const auto& pos : result) {
        cout << pos[0] << " " << pos[1] << " ";
    }
    cout << endl;
    
    return 0;
}