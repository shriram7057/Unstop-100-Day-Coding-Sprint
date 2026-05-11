#include <iostream>
#include <vector>

void petrol_price_days(int n, std::vector<int>& prices) {
    std::vector<int> ans(n, 0);
    std::vector<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && prices[i] > prices[st.back()]) {
            int idx = st.back();
            st.pop_back();
            ans[idx] = i - idx;
        }
        st.push_back(i);
    }

    for (int i = 0; i < n; i++) {
        std::cout << ans[i];
        if (i != n - 1) std::cout << " ";
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> prices(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> prices[i];
    }
    petrol_price_days(n, prices);
    return 0;
}