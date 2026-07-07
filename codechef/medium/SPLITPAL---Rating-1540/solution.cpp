#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<long long> A(N);
        for (auto &x : A) cin >> x;

        int l = 0, r = N - 1;
        long long left = A[l], right = A[r];
        long long ans = 0;

        while (l < r) {
            if (left == right) {
                l++;
                r--;
                if (l < r) {
                    left = A[l];
                    right = A[r];
                }
            } 
            else if (left < right) {
                ans++;
                right -= left;
                l++;
                if (l < r)
                    left = A[l];
            } 
            else {
                ans++;
                left -= right;
                r--;
                if (l < r)
                    right = A[r];
            }
        }

        cout << ans << '\n';
    }

    return 0;
}