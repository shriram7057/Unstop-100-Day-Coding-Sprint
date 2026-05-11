#include <iostream>
using namespace std;

long long calculate_moves(long long N) {
    // The array arr is [1, 3, 5, ..., 2N-1], we want to make them all equal to N.
    
    // If there are no piles, no moves are required
    if (N == 0) return 0;

    // The sum of the first N odd numbers is N^2, and the target height for each pile is N.
    
    long long total_moves = 0;
    
    // Loop through the first N piles and calculate the difference from the target height N
    for (long long i = 0; i < N; ++i) {
        long long current_height = (2 * i) + 1;
        total_moves += abs(current_height - N);
    }

    // The minimum number of moves required is total_moves / 2 because each move involves
    // moving one unit from one pile to another.
    return total_moves / 2;
}

int main() {
    long long N;
    cin >> N;
    
    // Print the result
    cout << calculate_moves(N) << endl;
    
    return 0;
}