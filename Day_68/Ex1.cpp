#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class DSU {
public:
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) parent[rootY] = rootX;
            else if (rank[rootX] < rank[rootY]) parent[rootX] = rootY;
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

bool canTransform(string& a, string& b) {
    vector<int> diff;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) diff.push_back(i);
        if (diff.size() > 4) return false;
    }
    return diff.size() == 4 || diff.size() == 0;
}

int countGroups(vector<string>& words) {
    int n = words.size();
    DSU dsu(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (canTransform(words[i], words[j])) {
                dsu.unite(i, j);
            }
        }
    }
    unordered_set<int> uniqueGroups;
    for (int i = 0; i < n; i++) {
        uniqueGroups.insert(dsu.find(i));
    }
    return uniqueGroups.size();
}

int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++) cin >> words[i];
    cout << countGroups(words) << endl;
    return 0;
}