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