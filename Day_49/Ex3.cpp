  #include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void findCombinations(vector<int>& candidates, vector<int>& combination, int target, int start, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(combination);
        return;
    }
    
    for (int i = start; i < candidates.size() && target >= candidates[i]; i++) {
        combination.push_back(candidates[i]);
        findCombinations(candidates, combination, target - candidates[i], i, result);
        combination.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> combination(0);
    sort(candidates.begin(), candidates.end(),greater <>());
    findCombinations(candidates, combination, target, 0, result);
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());
    return result;
}

int main() {
    int n, sum;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> sum;
    vector<vector<int>> combinations = combinationSum(arr, sum);

    for (const auto& combination : combinations) {
        for (int i = 0; i < combination.size(); i++) {
            cout << combination[i] << " ";
        }
        cout << endl;
    }

    return 0;
}