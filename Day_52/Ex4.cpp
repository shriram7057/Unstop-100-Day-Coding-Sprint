#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int user_logic(int n, vector<pair<int, int>> &edges) {
    // If n <= 2 the tree is trivially a path.
    if(n <= 2) return 1;
    
    vector<int> deg(n+1, 0);
    for(auto &e: edges) {
        deg[e.first]++;
        deg[e.second]++;
    }
    
    // Check if the tree is a path (max degree <= 2)
    int max_deg = 0;
    for (int i = 1; i <= n; i++) {
        max_deg = max(max_deg, deg[i]);
    }
    if(max_deg <= 2) return 1;
    
    // Count how many vertices have degree at least 3.
    int countBranch = 0;
    int branchDegree = 0;
    for (int i = 1; i <= n; i++) {
        if(deg[i] >= 3) {
            countBranch++;
            branchDegree = deg[i]; // If there is only one such vertex, this is it.
        }
    }
    
    // If there is exactly one branching vertex and its degree is exactly 3, k can be 2.
    if(countBranch == 1 && branchDegree == 3)
        return 2;
    
    // Otherwise, the answer is 3.
    return 3;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> edges;
    int x, y;
    while(cin >> x >> y) {
        edges.push_back({x, y});
    }
    
    int result = user_logic(n, edges);
    cout << result << endl;
    return 0;
}