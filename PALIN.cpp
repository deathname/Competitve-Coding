#include<bits/stdc++.h>
using namespace std;
typedef long long lld;

lld is_9(string s){
    for(lld i=0;i<s.size();i++){
        if(s[i]!='9'){
            return 0;
        }
    }
    return 1;
}

int main(){
    std::ios::sync_with_stdio(0);
    lld t;
    cin>>t;
    while(t--){
     string s,ans;
        cin>>s;
        if(is_9(s)){
            for(lld i=0;i<=s.size();i++){
                if(i==0 || i==s.size()){
                    ans.push_back('1');
                }
                else{
                    ans.push_back('0');
                }
            }
            cout<<ans<<"\n";
        }    
        else{
            lld i = s.size()/2;
            lld j = i;
            i=(s.size()%2==0)?i-1:i;
            while(i>=0 && s[i]==s[j]){
                i--;
                j++;
            }
            if(i<0 || s[i]<s[j]){
                i = s.size()/2;
                j = i;
                i=(s.size()%2==0)?i-1:i;
                lld carry = 1;
                while(i>=0){
                    lld val = (s[i]-'0')+carry;
                    carry = val/10;
                    s[i] = (val%10+'0');
                    s[j] = s[i];
                    i--,j++;
                }
            }
            else{
                i = s.size()/2;
                j = i;
                i=(s.size()%2==0)?i-1:i;
                while(i>=0){
                    s[j] = s[i];
                    i--,j++;
                }
            }
            cout<<s<<"\n";
        }
    }
}