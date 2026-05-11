#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
using namespace std;

void user_logic(int n, int m, int perkm_ola_cost, int perkm_uber_cost, vector<vector<int>>& arr) {
    int start_i = -1, start_j = -1, dest_i = -1, dest_j = -1;
    
    // Locate Arnav's location (value 2) and friend's location (value 3)
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(arr[i][j] == 2) { 
                start_i = i; 
                start_j = j; 
            }
            if(arr[i][j] == 3) { 
                dest_i = i; 
                dest_j = j; 
            }
        }
    }
    
    // If either location is missing, output "null"
    if(start_i == -1 || dest_i == -1) {
        cout << "null";
        return;
    }
    
    // Perform BFS using only 4-direction moves: up, down, left, right.
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    // Queue holds ((row, col), distance)
    queue< pair< pair<int,int>, int > > q;
    q.push(make_pair(make_pair(start_i, start_j), 0));
    visited[start_i][start_j] = true;
    
    int distance = -1;
    int dirs[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
    
    while(!q.empty()){
        pair< pair<int,int>, int > front = q.front();
        q.pop();
        int r = front.first.first;
        int c = front.first.second;
        int dist = front.second;
        
        // If we've reached the friend's location, record the distance.
        if(r == dest_i && c == dest_j) {
            distance = dist;
            break;
        }
        
        for (int i = 0; i < 4; i++){
            int nr = r + dirs[i][0];
            int nc = c + dirs[i][1];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m &&
               !visited[nr][nc] && (arr[nr][nc] == 0 || arr[nr][nc] == 2 || arr[nr][nc] == 3)) {
                visited[nr][nc] = true;
                q.push(make_pair(make_pair(nr, nc), dist + 1));
            }
        }
    }
    
    // If destination is unreachable, output "null"
    if(distance == -1) {
        cout << "null";
        return;
    }
    
    // Calculate travel cost for both rides (each step = 1 km)
    int cost_ola = perkm_ola_cost * distance;
    int cost_uber = perkm_uber_cost * distance;
    
    // Apply discount if the distance is 5 km or more
    if(distance >= 5) {
        cost_ola -= 20;
        cost_uber -= 20;
    }
    
    // If both costs are equal, choose OLA; otherwise, choose the cheaper option.
    if(cost_ola <= cost_uber)
        cout << "OLA cash of " << cost_ola;
    else
        cout << "Uber cash of " << cost_uber;
}

int main(){
    int n, m, perkm_ola_cost, perkm_uber_cost;
    cin >> n >> m >> perkm_ola_cost >> perkm_uber_cost;
    
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    
    user_logic(n, m, perkm_ola_cost, perkm_uber_cost, arr);
    return 0;
}