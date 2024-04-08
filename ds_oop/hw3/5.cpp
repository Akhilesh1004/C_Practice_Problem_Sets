#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>dp(n);
    for(int i = 0; i<n; i++){
        cin>>dp[i];
    }
    int mxSum = dp[0], curSum = dp[0], total = dp[0];
    for(int i = 1; i<n; i++){
        curSum = max(dp[i], curSum+dp[i]);
        mxSum = max(curSum, mxSum);
        total += dp[i];
    }
    int miSum = dp[0];
    curSum = dp[0];
    for(int i = 1; i<n; i++){
        curSum = min(dp[i], curSum+dp[i]);
        miSum = min(miSum, curSum);
    }
    if(total == miSum) cout<<mxSum<<"\n";
    else cout<<max(mxSum, total-miSum)<<"\n";
    return 0;
}

/*
#include <iostream>
#include <vector>

using namespace std;

int maxSubarraySum(const vector<int>& nums) {
    int maxSum = nums[0];
    int currSum = nums[0];
    
    for (int i = 1; i < nums.size(); ++i) {
        currSum = max(nums[i], currSum + nums[i]);
        maxSum = max(maxSum, currSum);
    }
    
    return maxSum;
}

int main() {
    int N;
    cin >> N;
    
    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }
    
    int maxSum1 = maxSubarraySum(nums);
    
    int totalSum = 0;
    for (int num : nums) {
        totalSum += num;
    }
    
    for (int& num : nums) {
        num = -num;
    }
    
    int maxSum2 = maxSubarraySum(nums);
    
    int maxCircularSum = totalSum + maxSum2;
    if (maxCircularSum == 0) {
        maxCircularSum = maxSum1;
    } else {
        maxCircularSum = max(maxCircularSum, maxSum1);
    }
    
    cout << maxCircularSum << endl;
    
    return 0;
}
*/