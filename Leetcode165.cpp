class Solution {
public:
// the link of the problem: https://leetcode.cn/problems/compare-version-numbers/
    int compareVersion(string version1, string version2) {
      version1 += '.';
      version2 += '.';
      int i = 0;
      int j = 0;
      queue<int> v1;
      queue<int> v2;
      vector<int> v1_num;
      vector<int> v2_num;
      for(char i:version1){
        if(i=='.'){
          int temp = 0;
          while(!v1.empty()){
            int t = int (v1.front()-'0');
            temp = temp*10 + t;
            v1.pop();
          }
          v1_num.push_back(temp);
        }
        if(i=='0'&&!v1.empty()){
          v1.push(i);
        }
        if(i>'0'&&i<='9'){
          v1.push(i);
        }
      }
      for(char i:version2){
        if(i=='.'){
          int temp = 0;
          while(!v2.empty()){
            int t = int (v2.front()-'0');
            temp = temp*10 + t;
            v2.pop();
          }
          v2_num.push_back(temp);
        }
        if(i=='0'&&!v2.empty()){
          v2.push(i);
        }
        if(i>'0'&&i<='9'){
          v2.push(i);
        }
      }
      int max_size = v1_num.size()>v2_num.size()? v1_num.size():v2_num.size();
      for(int i = v1.size();i<max_size;i++){
        v1_num.push_back(0);
      }
      for(int i = v2.size();i<max_size; i++){
        v2_num.push_back(0);
      }
      for(int i = 0; i<v1_num.size()&&i<v2_num.size(); i++){
        if(v1_num[i]>v2_num[i]){
          return 1;
        }else if(v1_num[i]<v2_num[i]){
          return -1;
        }else{
          continue;
        }
      }
      return 0;
    }
};
