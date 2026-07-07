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

        string s;
        cin >> s;

        stack<int> st;

        for (char ch : s) {
            if (isdigit(ch)) {
                st.push(ch - '0');
            } else {
                int b = st.top();
                st.pop();

                int a = st.top();
                st.pop();

                if (ch == '+')
                    st.push(a + b);
                else if (ch == '-')
                    st.push(a - b);
                else
                    st.push(a * b);
            }
        }

        cout << st.top() << "\n";
    }

    return 0;
}