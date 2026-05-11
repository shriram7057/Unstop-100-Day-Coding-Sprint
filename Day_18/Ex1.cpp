#include <iostream>
#include <iostream>
#include <cmath>
using namespace std;
using namespace std;
int find(int m) {
    return (int)sqrt(m);
}

int main() {
    int m;
    cin >> m;
    int count = find(m);
    cout << count << endl;
    return 0;
}