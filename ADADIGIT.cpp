#include<bits/stdc++.h>
using namespace std;
typedef long long lld;
const lld MAX = 555555;
lld n;
lld fact[MAX];
lld mod = 1e9+7;
lld ans = 0;
void factorial(){
    fact[0] = 1;
    fact[1] = 1;
    for(lld i=2;i<MAX;i++){
        fact[i] = (i*fact[i-1])%mod;
    }
}

lld powP(lld a,lld b){
    if(b == 0){
        return 1%mod;
    }
    lld temp = powP(a,b/2);
    temp = (temp*temp%mod);
    if(b&1) temp = (temp*a)%mod;
    return temp%mod;
}

lld inverse(lld val,lld mod){
    return powP(val,mod-2)%mod;
}

void solve(lld sum,lld prod,lld dig,lld deo,lld num){
    if(sum>n){
        return ;
    }
    if(prod == 1){
        lld one = n-sum;
        lld total = one+num;
        deo = deo*fact[one]%mod;
        num = fact[total];
        ans += (num*inverse(deo,mod)%mod)%mod;
        return;
    }
    if(dig>9){
        return;
    }
    solve(sum,prod,dig+1,deo,num);
    lld cnt = 0;
    while(prod%dig == 0){
        cnt++;
        prod/=dig;
        solve(sum + dig*cnt, prod, dig+1, deo*fact[cnt], num+cnt);
    }   
}
    
int main(){
    std::ios::sync_with_stdio(0);
    factorial();
    lld t;
    cin>>t;
    while(t--){
        ans = 0;
        cin>>n;
        solve(0,n,2,1,0);
        cout<<ans%mod<<"\n";
    }

}