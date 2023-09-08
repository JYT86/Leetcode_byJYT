class Solution {
public:
    // use two pointers
    // the link of the problem: https://leetcode.cn/problems/3sum-closest/description/
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = nums[0]+nums[1]+nums[2];
        int a,b,c;
        for(int i = 0; i<nums.size()-2;i++){
            a = nums[i];
            int left = i+1;
            int right = nums.size()-1;
            while(left<right){
                b = nums[left]; c = nums[right];
                if(a+b+c<target){
                    if(abs(ans-target)>abs(a+b+c-target)){
                        ans = a+b+c;
                    }
                    left++;
                    continue;
                }
                if(a+b+c>target){
                    if(abs(ans-target)>abs(a+b+c-target)){
                        ans = a+b+c;
                    }
                    right--;
                    continue;
                }
                return a+b+c;
            }
        }
        return ans;
    }
};
