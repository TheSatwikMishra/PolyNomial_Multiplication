/* Author - Satwik Mishra */
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int ll;
typedef unsigned long long ull;
typedef long double lld;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define INF               1e18
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
ll msb(ll N) {return (64 - __builtin_clzll(N) - 1);}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fr); cerr << ","; _print(p.sc); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
inline ll modadd (ll a , ll b , ll mod = (ll)(1e9 + 7)) { return (a + b) - (a + b >= mod ? mod : 0); }
vector<vector<ll>> adj(2e5 + 100);
vector<bool> vis(2e5 + 100, 0);
vector<ll> dis(2e5 + 100, 0);
ll MOD = 1e9 + 7;
pair<int, int> singlex(string s, char &vari, bool &pz) {
    char c = '#';
    int index = -1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            c = s[i];
            index = i;
            break;
        }
    }
    debug(s)
    if (c == '#') { //   x hai hi ni x^0
        pair<int, int> p = {stoi(s), 0};
        return p;
    }
    else {
        vari = c;
        int len = s.size();
        if (index == (len - 1)) {
            pz = 1;
            int val = stoi(s.substr(0, len - 1));
            pair<int, int> p = {val, 1};
            return p;
        }
        else {
            int len = s.size();
            int coeff = stoi(s.substr(0, index));
            int power = stoi(s.substr(index + 2, len - index - 2));
            pair<int, int> p = {coeff, power};
            return p;
        }
    }
}
vector<pair<int, int>> brackets(string s, char &vari, bool &pz) {
    vector<int> ind;
    ind.pb(-1);
    for (int i = 0; i < s.size(); i++) {
        if (i && (s[i] == '+' || s[i] == '-') && s[i - 1] != '^') {
            ind.pb(i);
        }
    }
    ind.pb(s.size());
    //debug(ind)
    vector<pair<int, int>> v;
    for (int i = 0; i < ind.size() - 1; i++) {
        int st = ind[i] + 1;
        int en = ind[i + 1];
        string here;
        if (i == 0)
            here = s.substr(st, en - st);
        else
            here = s.substr(st - 1, en - st + 1);
        pair<int, int> p = singlex(here, vari, pz);
        pz = 0;
     //   debug(p)
        v.pb(p);
    }
    return v;
}
vector<pair<int, int>> mul(vector<pair<int, int>> v1, vector<pair<int, int>> v2) {
    vector<pair<int, int>> ans, ansf;
    map<int, int> mp;
    for (int i = 0; i < v1.size(); i++) {
        for (int j = 0; j < v2.size(); j++) {
            pair<int, int> p1 = v1[i];
            pair<int, int> p2 = v2[j];
            pair<int, int> p;
            p.sc = p1.fr * p2.fr;
            p.fr = p1.sc + p2.sc;
            ans.pb(p);
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        mp[ans[i].fr] += ans[i].sc;
    }
    for (auto x : mp) ansf.pb(x);
    return ansf;
}
string printpoly(vector<pair<int, int>> v, char &vari, bool &pz) {
    sort(all(v));
    string ans;
    for (int i = 0; i < v.size(); i++) {
        string s = to_string(v[i].sc);
        if (i && v[i].sc > 0) ans.push_back('+');
        ans += s;
        if (v[i].fr == 0) {
            continue;
        }
        else {
            if (v[i].fr == 1) {
                ans += vari;
            }
            else {
                ans.push_back(vari);
                ans.push_back('^');
                ans += (to_string(v[i].fr));
            }
        }
    }
    //debug(ans)
    return ans;
}
void Jai_shree_ganesh(ll tt) {
    string s = "(-4+3x^-2-1x^-3)(6x^3+3)";
    int i = 0, j = 1;
    string s1, s2;
    while (s[j] != ')') {
        s1.pb(s[j]);
        j++;
    }
    char vari = '$';
    bool pz = 0;
    j += 2;;
    while (s[j] != ')') {
        s2.pb(s[j]);
        j++;
    }
    //debug(s1)
    vector<pair<int, int>> v1 = brackets(s1, vari, pz);
    //debug(s2)
    vector<pair<int, int>> v2 = brackets(s2, vari, pz);
    vector<pair<int, int>> v = mul(v1, v2);
    cout << printpoly(v, vari, pz);
}
int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    //  cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        Jai_shree_ganesh(i);
    }
    return (0);
}
