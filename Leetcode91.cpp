class Solution {
public:
    int numDecodings(string s) {
        vector<int> v(s.length());
        if(s.length() == 1){
            int t = (int)(s[0]-'1'+ 1);
            if(t==0){
                v[0] = 0;
            }else{
                v[0] = 1;
            }

        }
        if(s.length() >= 2){
            int l = s.length();
            //last one
            int t = (int)(int)(s[l-1]-'1'+ 1);
            v[l-1] = (t==0)?0:1;
            //last two
            if(s[l-2]=='0'){
                v[l-2] = 0;
            }else{
                int t1 = (int)(s[l-2]-'1'+ 1);
                int t2 = (int)(s[l-1]-'1'+ 1);
                t = t1*10+t2;
                if(t>26){
                    if(v[l-1]==0){
                        return 0;
                    }else{
                        v[l-2] = v[l-1];
                    }
                }else{
                    v[l-2] = 1+v[l-1];
                }
            }
            for(int i = l-3; i>=0; i--){
                int t1 = (int)(s[i]-'1'+ 1);
                int t2 = (int)(s[i+1]-'1'+ 1);
                t =t1*10+t2;
                if(t1==0){
                    v[i]=0;
                }else{
                    if(t>26){
                        if(v[i+1] == 0){
                            return 0;
                        }else{
                            v[i] = v[i+1];
                        }
                    }else{
                        v[i] = v[i+1]+v[i+2];
                    }
                }
            }
            
        }
        return v[0];
    }
};
