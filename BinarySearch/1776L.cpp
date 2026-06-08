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
    bool l{true};
    bool r{s[0]=='0'};
    LOOP(1,n){
        if(s[i]=='0'){
            bool tmp=r;
            r = l||(s[i-1]=='0');
            l = tmp||(s[i-1]=='0');
        }
        else if(s[i-1] == '1'){
            if(!l){
                cout << "NO" << endl;
                return;
            }
            r = false;
        }
    }
    cout << ((l || s[n-1] == '0') ? "YES" : "NO") << endl;
}   

void solve(ll n, ll k, string s, string t){
}


void solve(ll n, vll& a, vll& b){
}

void solve(ll n, vll& a){
}

void solve(ll n, ll k, string s, vll& a){

}

bool Check(vector<ll>& sn, vll& but){
    ll lc{lcm(but[0], but[1])};
    ll l{0};
    ll h{sn[0]};
    
    while(l<=h){
        ll mid = l + (h-l)/2;
        ll x = mid*(lc/but[0]);
        ll y = sn[1]-sn[0]+x;
        if(x>sn[0] || y < mid*(lc/but[1])){
            h = mid-1;
        }
        else if(y == mid*(lc/but[1])){
            return true;
        }
        else{ l=mid+1;}
    }
    return false;
}

void solve(ll n, string s, ll q, vector<vll>& a){
    ll ps{0};
    ll neg{0};
    LOOP(0, n){
        if(s[i] == '+')ps++;
        if(s[i] == '-')neg++;
    }
    vll sn{ps, neg};
    sort(sn);
    LOOP(0, q){
        cout << (Check(sn, a[i]) ? "YES" : "NO") << endl;
    }
}
int main() {     
    // Optimize I/O for 2*10^5 operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t{1};
    // cin >> t;
    while (t--) {
        ll n, q;
        string s;
        cin >> n >> s >> q;
        vector<vll> a(q, vll(2));
        LOOP(0,q){
            cin >> a[i][0] >> a[i][1];
            sort(a[i], true);
        }
        // cin >> a;
        // // Call the solver
        solve(n, s, q, a);
    }
    return 0;
}