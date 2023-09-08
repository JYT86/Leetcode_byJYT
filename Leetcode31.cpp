class Solution {
public:
// the link of this problem: https://leetcode.cn/problems/next-permutation/?envType=featured-list&envId=2cktkvj?envType=featured-list&envId=2cktkvj
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int s = 1;
        int left = 0;
        for(int i = n-2;i>=0;i--){
            //检查字典序是否最大

            //判断从i到末尾的字典序是否最大
            if(nums[i]<nums[i+1]){
                left = i;
                break;
            }
            s++;
        }
        cout<<nums[left]<<endl;
        if(s == n){
            sort(nums.begin(), nums.end());
        }
        else{
            auto temp = nums[left];
            int right = -1;
            for(int i = n-1; i>=0; i--){
                if(nums[i]>temp){
                    right = i;
                    break;
                }
            }
            nums[left] = nums[right];
            nums[right] = temp;
            sort(nums.begin()+left+1, nums.end());
        }
    }
};
