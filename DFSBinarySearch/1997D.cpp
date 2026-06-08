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
#define ACTIVATE(x, l, r) x|=((1LL<<(l+1))-1)&(1LL<<(r+1))

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

#include <vector>

using namespace std;

vector<ll> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    
    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                is_prime[i] = false;
            }
        }
    }
    
    vector<ll> primes;
    primes.reserve(78498); 
    
    for (ll p = 2; p <= n; p++) {
        if (is_prime[p]) {
            primes.push_back(p);
        }
    }
    
    return primes;
}

void solve(ll n, ll x, ll y, vll& vec){

}


void solve(ll n, ll k , string s, vll& a){
   
}   

void solve(ll n, string a, string b){

}

void solve(ll n, ll m, vll& a){

}

vector<pair<ll, ll>> MergeAndCalculate(vector<pair<ll, ll>>& a, ll left, ll right, vll& lrg){
    vector<pair<ll, ll>> merged;
    if(left==right){
        merged.push_back(a[left]);
        return merged;
    }
    ll mid = left+(right-left)/2;
    auto leftAr = MergeAndCalculate(a, left, mid, lrg);
    auto rightAr = MergeAndCalculate(a, mid+1, right, lrg);
    ll l{0};
    ll r{0};
    while(l<leftAr.size() && r<rightAr.size()){
        if(leftAr[l].first<rightAr[r].first){
            merged.push_back(leftAr[l++]);
        }
        else{
            lrg[rightAr[r].second]+=leftAr.size()-l;
            merged.push_back(rightAr[r++]);
        }
    }
    while(l<leftAr.size()){
        merged.push_back(leftAr[l++]);
    }
    while(r<rightAr.size()){
        merged.push_back(rightAr[r++]);
    }
    return merged;
}

ll Inversions(vll& a, ll left, ll right){
    if(left==right)return 0;
    ll mid = left + (right-left)/2;
    ll lI=Inversions(a, left, mid);
    ll rI=Inversions(a, mid+1, right);
    ll l{left};
    ll r{mid+1};
    vll merged;
    while(l<=mid && r<=right){
        if(a[l]<a[r])merged.push_back(a[l++]);
        else{
            lI+=mid-l+1;
            merged.push_back(a[r++]);
        }
    }
    while(l<=mid)merged.push_back(a[l++]);
    while(r<=right)merged.push_back(a[r++]);
    
    for(ll i{0}; i< right-left+1; i++){
        a[left+i]=merged[i];
    }
    return lI+rI;
}

void solve(ll n, vll& a){
    vll preL(n);
    vll sufL(n);
    vector<pair<ll, ll>> el(n);
    LOOP(0, n){
        el[i] = {a[i], i};
    }
    MergeAndCalculate(el, 0, n-1, preL);
    LOOP(0, n){
        sufL[i]=n-a[i]-preL[i];
    }
    LOOP(0, n){
        if(preL[i]>sufL[i])a[i]=2*n-a[i];
    }
    cout << Inversions(a, 0, n-1) << endl;
}

void solve(ll n, ll m){

}

void solve(ll n){
}

/*
Check if its possible to make all child of node>=x
*/
bool checkDFS(vector<vll>& g, vll& a, ll node, ll x){
    if(x>1000000000)return false;
    for(auto& ch: g[node]){
        if(g[ch].empty() && a[ch-1]<x) return false;
        if(!checkDFS(g, a, ch,  x + max(0LL, x-a[ch-1])))return false;
    }
    return true;
}

void solve(ll n, vll& a, vector<vll>& g){
    ll l{0};
    ll h{max(a)};
    ll ans{a[0]};
    while(l<=h){
        ll mid = l+(h-l)/2;
        if(checkDFS(g, a, 1, mid)){
            l = mid+1;
            ans = a[0]+mid;
        }
        else{
            h = mid-1;
        }
    }
    cout << ans << endl;
}


void solve(ll n, ll x, ll s, string a){

}
int main() {     
    // Optimize I/O for 2*10^5 operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t{1};
    cin >> t;
    while (t--) {
        ll n, m, k;
        string s, s2;
        cin >> n;
        vll a(n);
        cin >> a;
        vector<vll> g(n+1);
        LOOP(0,n-1){
            ll x{0};
            cin >> x;
            g[x].push_back(i+2);
        }
        solve(n, a, g);
        // solve(n, m);
    }
    return 0;
}