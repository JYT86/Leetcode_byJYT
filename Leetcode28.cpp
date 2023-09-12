#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

// this code realises the KMP algorithm which can be used to solve matching problems of string.
// the problem link on leetcode:https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/

vector<int> get_next_array(string target){
    int n = target.size();
    vector<int> next_array(n);
    next_array[0] = -1;
    for(int i = 1; i<n; i++){
        int temp = 0;
        int size = i;
        if(size == 1){
            next_array[i] = 0;
            continue;
        }
        for(int j = size-1; j>=1; j--){
            string str1 = target.substr(0, j);
            string str2 = target.substr(size-j,j);
            if(str1 == str2){
                temp = j>temp? j:temp;
            }
        }
        next_array[i] = temp;
    }
    return next_array;
}

int main(){
    string str = "aaa";
    vector<int> v = get_next_array(str);
    for(auto iter = v.begin(); iter!=v.end(); iter++){
        cout<<*iter<<" ";

    }
    cout<<endl;

    string str1 = "aabaabbcaaaaabba";
    int j = 0;
    int ans = 0;
    for(int i = 0; i<str1.length(); i++){
        bool if_youxi = true;
        while(str1[i]!=str[j]){
            if(v[j]!=-1){
                j = v[j];
            }else{
                if_youxi = false;
                break;
            }
        }
        if(!if_youxi){
            j = 0;
            continue;
        }else{
            j++;
            if(j==str.length()){
                ans = i-j+1;
                break;
            }
        }
    }
    cout<<ans<<endl;
}
