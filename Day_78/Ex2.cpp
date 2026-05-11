#include <iostream>
#include <vector>
using namespace std;

void user_logic(int n, int m, vector<vector<int>>& edges) {
    // Write your logic here.
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(3));
    for (int i = 0; i < m; ++i) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }
    user_logic(n, m, edges);
    return 0;
}
