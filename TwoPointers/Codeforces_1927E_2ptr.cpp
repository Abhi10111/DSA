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

ll dfs(ll n, ll m, vector<string>& a, ll i, ll j, vector<vector<ll>>& dp, vector<vector<bool>>& seen){
    if(i<0 || i>=n || j<0 || j>=m){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(seen[i][j]){
        return 1;
    }
    seen[i][j]=1;
    if(a[i][j]=='D'){
        dp[i][j]=dfs(n,m,a,i+1,j, dp, seen);
    }
    else if(a[i][j]=='U'){
        dp[i][j]=dfs(n,m,a,i-1,j, dp, seen);
    }
    else if(a[i][j]=='L'){
        dp[i][j]=dfs(n,m,a,i,j-1, dp, seen);
    }
    else if(a[i][j]=='R'){
        dp[i][j]=dfs(n,m,a,i,j+1, dp, seen);
    }
    else{
        dp[i][j]=dfs(n,m,a,i,j+1, dp, seen)|dfs(n,m,a,i,j-1, dp, seen)|dfs(n,m,a,i+1,j, dp, seen)|dfs(n,m,a,i-1,j, dp, seen);
    }
    seen[i][j]=0;
    return dp[i][j];
}
void solve(ll n, ll m, vector<string>& a){
    vector<vector<bool>> seen(n, vector<bool>(m, false));
    vector<vector<ll>> dp(n, vector<ll>(m, -1));
    LOOP(0,n){
        for(ll j{0}; j<m; j++){
            if(dp[i][j]==-1){
                dfs(n,m,a,i,j,dp,seen);
            }
        }
    }
    ll ans{0};
    LOOP(0,n){
        ans+=sum(dp[i]);
    }
    cout << ans << endl;
}

void solve(ll n, vll& a){
}   

void solve(ll n, ll k){
    vll ans(n);
    ll l{1};
    ll r{n};
    LOOP(0,k){
        for(ll j=0;j*k+i<n;j++){
            if(i%2){
                ans[j*k+i]=r--;
            }
            else{
                ans[j*k+i]=l++;
            }
        }
    }
    cout << ans;
}

void solve(ll n){

}
int main() {     
    // Optimize I/O for 2*10^5 operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t{1};
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        // vector<string> a(n);
        // cin >> a;
        // vll b(n);
        // cin >> a >> b;
        // cin >> a;
        // Call the solver
        solve(n, m);
    }
    return 0;
}