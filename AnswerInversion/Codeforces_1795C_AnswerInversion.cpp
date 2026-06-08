#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <queue>

#define GETMSB(x)  ((x)&(1LL << (63 - __builtin_clzll(x))))
#define ceil(x,MOD) (x<=0 ? 0 : (x-1)/MOD+1)
#define LOOP(start,end) for(ll i=start;i<end;i+=1LL)
#define ISBITSET(x,idx) (long long)(((1LL<<idx)&x)>0LL)

using namespace std;
using ll=long long;
using vll = vector<ll>;
using um=unordered_map<int,int>;

ll sum(const vector<ll>& a, ll MOD=LONG_LONG_MAX){
    ll sum=0;
    for(auto& x:a){
        sum=(sum+x)%MOD;
    }
    return sum%MOD;
}
    ll mul(const vector<ll>& a,ll MOD=1){
        ll prod=1LL;
        for(auto& x:a){
            prod*=x%MOD;
        }
        return prod;
    }
    ll max(const vector<ll>& a){
        ll maxEl=INT_MIN;
        for (auto x:a){
            maxEl=max(maxEl,x);
        }
        return maxEl;
    }
    ll min(const vector<ll>& a){
        ll minEl=INT_MAX;
        for (auto x:a){
            minEl=min(minEl,x);
        }
        return minEl;
    }

    ll lcm(long long a, long long b) {
        if (a == 0 || b == 0) return 0;
        // Divide first to prevent potential overflow
        return (std::abs(a) / gcd(a, b)) * std::abs(b);
    }

    template<typename T1, typename T2>
    ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
        os << "{" << p.first << ", " << p.second << "}";
        return os;
    }

    template<typename T1, typename T2>
    ostream& operator<<(ostream& os, const unordered_map<T1, T2>& map) {
        for(auto& p:map){
            os << "{" << p.first << ", " << p.second << "}, ";
        }
        os<<endl;
        return os;
    }

    template <typename T>
    std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
        for (const auto& elem : vec) {
            os << elem << " ";
        }
        os<<endl;
        return os;
    }

    template <typename T1, typename T2>
    std::ostream& operator<<(std::ostream& os, const std::map<T1, T2>& mp) {
        for (const auto& [key,value] : mp) {
            os << "{" << key << ", " << value << "}, ";
        }
        os<<endl;
        return os;
    }

    template <typename T>
    std::istream& operator>>(std::istream& in, std::vector<T>& vec) {
        for (auto& element : vec) {
            in >> element;
        }
        return in;
    }

template<typename T>
void sort(vector<T>& a,bool reversed=false){
    sort(a.begin(),a.end());
    if(reversed){
        reverse(a.begin(),a.end());
    }
}

template<typename T>
void CalculatePresum(vector<T>& input,vector<T>& output){
    if(input.size()==0 || input.size()!=output.size()){
        return;
    }
    output[0]=input[0];
    for(ll i=1;i<input.size();i++){
        output[i]=output[i-1]+input[i];
    }
}

#define DEBUG(x) cout << #x << ":" << x << endl    
#define LOGOPS(x) (x == 1LL) ? 1 : (long long)log2(x)+1

void solve(ll n, ll x, ll y, vll& vec){

}

void solve(ll n, string s){
    ll adj{0};
    ll r{0};
    LOOP(0, n){
        if(s.substr(i, 3) == "101"){

        }
    }
    cout << "YES" << endl;
}   

void solve(ll n, ll k, string s, string t){
}

pair<ll,ll> FindR(ll n, vll& a, vll& pre, ll st){
    ll l{st};
    ll h{n-1};
    ll t=a[st];
    if(st){
        t+=pre[st-1];
    }
    while(l<=h){
        ll mid = l + (h-l)/2;
        if(pre[mid]>t){
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    if(h<st){
        return {st-1, a[st]};
    }
    else{
        return {h, (t-pre[h])};
    }
}

void solve(ll n, vll& a, vll& b){
    vll pre(n+1);
    pre[0]=b[0];
    LOOP(1,n){
        pre[i] = pre[i-1] + b[i];
    }
    vll rng(n);
    vll ans(n);
    LOOP(0,n){
        rng[i]++;
        auto r=FindR(n, a, pre, i);
        if(r.first<n-1){
            rng[r.first+1]--;
            ans[r.first+1]+=r.second;
        }
    }
    ll s{0};
    LOOP(0,n){
        s+=rng[i];
        ans[i]+=b[i]*s;
    }
    cout << ans;
}

void solve(ll n, vll& a){

}

void solve(ll n, ll k, string s, vll& a){

}

ll FindMex(ll n, vll& a){
    ll m{0};
    sort(a);  
    LOOP(0,n){
        if(a[i]==m){
            m++;
        }
    }
    return m;
}
void solve(ll n, ll k, vll& a){

}
int main() {     
    // Optimize I/O for 2*10^5 operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t{1};
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vll a(n), b(n);
        cin >> a >> b;
        // // Call the solver
        solve(n, a, b);
    }
    return 0;
}