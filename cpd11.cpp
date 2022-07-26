#include<bits/stdc++.h>
using namespace std;
#define fr(i,a,n) for(auto i=a;i<n;i++)
#define rf(i,n,a) for(auto i=n;i>a;i--)
#define pb push_back
#define ppb pop_back
#define f first
#define s second
#define mp make_pair
#define mt make_tuple
#define int_max 1e9
#define int_min -1e9
const int M = 1e9 + 7;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" "; _print(x); cerr<<endl;
#else
#define debug(x)
#endif

void _print(int x){ cerr<<x; }
void _print(string x){ cerr<<x; }
void _print(char x){ cerr<<x; }
void _print(ll x){ cerr<<x; }
void _print(bool x){ cerr<<x; }

template<class T>void _print(stack<T> st){ cerr<<"[ "; while(!st.empty()) { _print(st.top()); cerr<<" "; st.pop();} cerr<<"]"; }
template<class T>void _print(vector<T> v1){ cerr<<"[ "; for(T i:v1) { _print(i); cerr<<" "; } cerr<<"]"; }
template<class T>void _print(set<T> s){ cerr<<"[ "; for(T i:s){ _print(i); cerr<<" "; } cerr<<"]"; }
template<class T>void _print(unordered_set<T> s){ cerr<<"[ "; for(T i:s){ _print(i); cerr<<" "; } cerr<<"]"; }
template<class T>void _print(multiset<T> s){ cerr<<"[ "; for(T i:s){ _print(i); cerr<<" "; } cerr<<"]"; }
template<class T,class V>void _print(pair<T,V> p){ cerr<<"{";_print(p.f);cerr<<",";_print(p.s);cerr<<"}"; }
template<class T,class V>void _print(map<T,V> s){ cerr<<"[ "; for(auto i:s){ cerr<<"{";_print(i.f); cerr<<","; _print(i.s); cerr<<"} "; } cerr<<"]"; }
template<class T,class V>void _print(unordered_map<T,V> s){ cerr<<"[ "; for(auto i:s){ cerr<<"{";_print(i.f); cerr<<","; _print(i.s); cerr<<"} "; } cerr<<"]"; }
template<class T,class V>void _print(multimap<T,V> s){ cerr<<"[ "; for(auto i:s){ cerr<<"{";_print(i.f); cerr<<","; _print(i.s); cerr<<"} "; } cerr<<"]"; }

long long binmul(long long a,long long b,int m){
	long long ans = 0;
	while(b){
		if(b&1){
			ans = ( ans + a)%m;
		}
		b>>=1;
		a=(a+a)%m;
	}
	return ans;
}

long long binexpoiter(long long a,long long b,int m){
	a%=M;
	long long ans=1;
	while(b){
		if(b&1){
			ans = binmul(ans,a,m)%m;
		}
		b>>=1;
		a = binmul(a,a,m)%m;
	}
	return ans;
}

long long calc(int b[],int n){
	long long ans = 0;
	fr(i,0,n){
		ans += (b[i]*(pow(10,i)));
	}
	return ans;
}

void solve()
{	
	// long long a = 3, b = 5;
	// cout<<binexpoiter(a,b);
	// what if a is too high = a=a%M;
	// what if M is too high -> binmul.
	// what if b is too high -> ?

	// calculate 2147483647 ^ 200 % 1337

	int m = 1337;
	long long a ; cin>>a;
	int n;cin>>n;
	int b[n];
	fr(i,0,n) cin>>b[i];
	long long B = calc(b,n);
	B%=1140;
	cout<<binexpoiter(a,B,m);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    #ifndef ONLINE_JUDGE
	freopen("error.txt","w",stderr); 
    #endif
	/*int t;
	cin>>t;
	int p=t;
	while(t--){
		cout<<"Case #"<<p-t<<" : ";
		solve();
	}*/
	solve();
	return 0;
}
