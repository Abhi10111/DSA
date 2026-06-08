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

void solve(ll n, vll& a){
    ll ans{0};
    ll inc{0};
    ll minIdx{n-1};
    for(ll i{n-2}; i>=0; i--){
        if(a[i]<a[minIdx]){
            inc=max(minIdx-i-1,inc);
            minIdx=i;
        }
        ans+=a[i]-a[minIdx];
    }
    inc=max(inc, minIdx);
    cout << ans+inc << endl;
}   

void solve(ll n, string s){
}

void solve(ll n, ll k){

}

void solve(ll n, vll& a, vll& b){
}

void solve(ll n){
}
//Invariant pattern because xor of any subarray remains invariant
void solve(ll n, ll q, string s, vll& a, vector<vll>& Q){
    vll pre(n+1);
    LOOP(1, n+1){
        pre[i]=pre[i-1]^a[i-1];
    }
    vll ans(2);
    LOOP(0,n){
        ans[s[i]-'0']^=a[i];
    }
    LOOP(0,q){
        if(Q[i][0]==1){
            ll xo = pre[Q[i][2]]^pre[Q[i][1]-1];
            ans[0]^=xo;
            ans[1]^=xo;
        }
        else{
            cout << ans[Q[i][1]] << " ";        
        }
    }
    cout << endl;
}

int main() {     
    // Optimize I/O for 2*10^5 operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t{1};
    cin >> t;
    while (t--) {
        ll n, q;
        string s;
        cin >> n;
        vll a(n);
        cin >> a >> s >> q;
        vector<vll> Q(q);
        LOOP(0,q){
            ll type;
            cin >> type;
            vll vec(3-type+1);
            vec[0] = type;
            if(type == 1){
                cin >> vec[1] >> vec[2];
            }
            else{
                cin >> vec[1];
            }
            Q[i]=vec;
        }
        // // Call the solver
        solve(n, q, s, a, Q);
    }
    return 0;
}