#include <iostream>
#include <vector>

#include <queue>
using namespace std;

int infect(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int, int>> q;
    int fresh = 0;

    // Initialize queue with all infected people
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 2) {
                q.push({i, j});
            } else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    if (fresh == 0) return 0;

    int time = 0;
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    while (!q.empty()) {
        int sz = q.size();
        bool spread = false;

        for (int i = 0; i < sz; i++) {
            auto [x, y] = q.front();
            q.pop();

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                    fresh--;
                    spread = true;
                }
            }
        }

        if (spread) time++;
    }

    return (fresh == 0) ? time : -1;
}
int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> grid(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> grid[i][j];
        }
    }
    int result = infect(grid);
    std::cout << result << std::endl;
    return 0;
}