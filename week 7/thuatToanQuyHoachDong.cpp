#include <iostream>
#include <vector>

using namespace std;

int maxSumNonAdjacent(const vector<int>& nums) {
    int n = nums.size();

    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return nums[0];

    }
    vector<int> dp(n, 0);

    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    return max(dp[n - 1], dp[n - 2]);
}

int main()
{
    vector<int> nums = {2, 7, 9, 3, 1};

    int result = maxSumNonAdjacent(nums);

    cout << result << endl;

    return 0;
}

