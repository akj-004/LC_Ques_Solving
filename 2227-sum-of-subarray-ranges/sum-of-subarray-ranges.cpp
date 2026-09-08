#include<algorithm>
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans=0;
        int n = nums.size();
        long long maxi = INT_MIN;
        long long mini = INT_MAX;


        for (int i=0 ; i<n ; i++){
            maxi = INT_MIN;
            mini = INT_MAX;

            for (int j=i ; j<n ; j++){
                maxi = max(maxi,(long long)nums[j]);
                mini = min(mini,(long long)nums[j]);

                ans += (maxi-mini);
            }
        }
        return ans;
    }
};