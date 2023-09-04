class Solution {
public:
    // using dynamic programming to solve the problem
    // problem link: https://leetcode.cn/problems/house-robber/
    int rob(vector<int>& nums) {
        int ans = 0;
        if(nums.size()==1){
            return nums[0];
        }else if(nums.size() == 2){
            return max(nums[0], nums[1]);
        }else{
            int l = nums.size();
            vector<int> money(l);
            // last one
            money[l-1] = nums[l-1];
            // next to last
            money[l-2] = nums[l-2];
            // 3rd from last
            money[l-3] = nums[l-3]+money[l-1];

            for(int i = l-4; i>=0; i--){
                money[i] = max(money[i+2], money[i+3])+nums[i];
            }
            ans = max(money[0], money[1]);
        }
        return ans;
    }
};
