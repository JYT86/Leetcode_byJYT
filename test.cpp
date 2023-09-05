#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int min_len = INT_MAX;
        int max_len = 0;

        for(string str: wordDict){
            if(str.length()<min_len){
                min_len = str.length();
            }
            if(str.length()>max_len&&str.length()<=s.length()){
                max_len = str.length();
            }
        }

        
        vector<int> v(s.length());
        if(s.length()<min_len){
            cout<<1<<endl;
            return false;
        }
        // find the tail
        bool if_find_tail = false;
        int f_tail = s.length() - min_len;
        for(int i = f_tail; i>=s.length() - max_len&& i>=0 ;i--){
            string tail = s.substr(i);
            for(string str:wordDict){
                if(str == tail){
                    if_find_tail = true;
                    v[i] = 1;
                    f_tail = i;
                    break;
                }
            }
            if(if_find_tail){
                break;
            }
        }
        if(!if_find_tail){
            cout<<2<<endl;
            return false;
        }
        for(int i = f_tail-1; i>=0; i--){
            
            for(int l = min_len; l<=max_len&& i+l-1<s.length(); l++){
                string sub = s.substr(i, l);
                for(string str: wordDict){
                    if(str == sub){
                        if(i+l == s.length()){
                            v[i] = 1;
                            break;
                        }else if(i+l<s.length() && v[i+l] == 1){
                            v[i] = 1;
                            break;
                        }
                    }
                }
            }
        }
        if(v[0] == 1){
            return true;
        }else{
            cout<<3<<endl;
            return false;
        }
    }
};
int main(){
    string s = "bb";
    vector<string> v= {"a", "b", "bbb","bbbb"};
    Solution s1;
    cout<<s1.wordBreak(s, v)<<endl;
}