# SPLITPAL - Rating 1540

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Palindrome by Splitting

JJ has an array $A$ initially of length $N$. He can perform the following operation on $A$:

 **1)**  Pick any index $i$ $(1 \le i \le |A|)$ such that $A_i \gt 1$ $\\$  **2)**  Select any two integers $X$ and $Y$ such that $X + Y = A_i$ and $X, Y \ge 1$ $\\$  **3)**  Replace $A_i$ with $X$ and $Y$

Note that the length of the array increases by $1$ after each operation.

For example, if $A = [4, 6, 7, 2]$, he can select $i = 1$ and select $X = 1, Y = 3$ (since $X + Y = A_1$). After the operation array becomes: $[\underline{4}, 6, 7, 2] \rightarrow [\underline{1}, \underline{3}, 6, 7, 2]$.

JJ wants to make $A$ palindromic. Find the minimum number of operations to do so.

It is guaranteed that $A$ can be converted to a palindromic array by using the above operation.

Note: An array is called a palindrome if it reads the same backwards and forwards, for e.g. $[1, 3, 3, 1]$ and $[6, 2, 6]$ are palindromic.

### Input Format
- The first line contains a single integer $T$ — the number of test cases. Then the test cases follow.
- The first line of each test case contains an integer $N$ — the size of the array $A$.
- The second line of each test case contains $N$ space-separated integers $A_1, A_2, \dots, A_N$ denoting the array $A$.
### Output Format

For each test case, output the minimum number of operations to make $A$ palindromic.

### Constraints
- $1 \leq T \leq 10^5$
- $1 \leq N \leq 10^5$
- $1 \le A_i \le 10^5$
- Sum of $N$ over all test cases does not exceed $2 \cdot 10^5$.
### Sample 1:
Input
Output

```
3
4
3 7 6 4
5
1 4 5 4 1
5
1 2 3 4 5

```

```
2
0
4

```

### Explanation:

 **Test Case 1:**  We can perform the following operations:

- $[3, \underline{7}, 6, 4] \xrightarrow{i = 2, X = 1, Y = 6} [3, \underline{1}, \underline{6}, 6, 4]$
- $[3, 1, 6, 6, \underline{4}] \xrightarrow{i = 5, X = 1, Y = 3} [3, 1, 6, 6, \underline{1}, \underline{3}]$

 **Test Case 2:**  $A$ is already palindromic.

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-07-07T16:21:18.066Z  

```cpp
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
```

---

[View on CodeChef](https://www.codechef.com/problems/SPLITPAL)