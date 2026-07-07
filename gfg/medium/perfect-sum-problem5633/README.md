# Perfect Sum Problem

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an array  **`arr`**  of non-negative integers and an integer  **`target`**, the task is to count all subsets of the array whose sum is equal to the given `target`.

 **Examples:** 

```
Input: arr[] = [5, 2, 3, 10, 6, 8], target = 10
Output: 3
Explanation: The subsets {5, 2, 3}, {2, 8}, and {10} sum up to the target 10.
```

```
Input: arr[] = [2, 5, 1, 4, 3], target = 10
Output: 3
Explanation: The subsets {2, 1, 4, 3}, {5, 1, 4}, and {2, 5, 3} sum up to the target 10.
```

```
Input: arr[] = [5, 7, 8], target = 3
Output: 0
Explanation: There are no subsets of the array that sum up to the target 3.
```

```
Input: arr[] = [35, 2, 8, 22], target = 0
Output: 1
Explanation: The empty subset is the only subset with a sum of 0.
```

 **Constraints:** 
1 ≤ arr.size() ≤ 103
0 ≤ arr[i] ≤ 103
0 ≤ target ≤ 103

## Solution

**Language:** Java  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-07-07T16:18:13.262Z  

```java
class Solution {
    public int perfectSum(int[] nums, int target) {
        int n = nums.length;
        int mod = 1000000007;

        int[] dp = new int[target + 1];
        dp[0] = 1;

        for (int num : nums) {
            for (int sum = target; sum >= 0; sum--) {
                if (num <= sum) {
                    dp[sum] = (dp[sum] + dp[sum - num]) % mod;
                }
            }
        }

        return dp[target];
    }
}
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1)