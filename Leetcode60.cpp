class Solution {
public:
    int factorial(int n){
        if(n==1){
            return 1;
        }
        return n*factorial(n-1);
    }
    void getAns(string& str, vector<int>& all_num, int k){
        if(all_num.size()==1){
            str += char('0'+all_num[0]);
            return;
        }
        int n = all_num.size();
        int temp = factorial(n-1);
        int t = k/temp;
        str += char('0'+all_num[t]);
        all_num.erase(all_num.begin()+t);
        k = k%temp;
        getAns(str, all_num, k);
        
    }
    string getPermutation(int n, int k) {
        // 我的想法很简单 我觉得这个字典序有点像一个进制问题
        string ans;
        vector<int> all_num;
        for(int i = 0; i<n; i++){
            all_num.push_back(i+1);
        }
        k--;
        getAns(ans, all_num, k);
        return ans;
    }   
};
