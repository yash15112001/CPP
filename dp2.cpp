#include<bits/stdc++.h>
using namespace std;
#define fr(i,a,n) for(auto i=a;i<n;i++)
#define rf(i,n,a) for(auto i=n;i>a;i--)
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ud unordered
#define sz size
#define f first
#define s second
#define mp make_pair
#define mt make_tuple
#define int_max 1e9
#define int_min -1e9
#define null NULL
const int M = 1e9 + 7;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" "; _print(x); cerr<<endl;
#else
#define debug(x)
#endif

#ifndef ONLINE_JUDGE
#define debugv(x,a,b) cerr<<#x<<" "; _print(x,a,b); cerr<<endl;
#else
#define debugv(x)
#endif

int binexpo(int a,int b,int m){int ans=1;while(b){if(b&1) ans=(ans*1ll*a)%m; a=(a*1ll*a)%m; b>>=1;} return ans;}
int MMI(int a){return binexpo(a,M-2,M);}

void _print(int x){ cerr<<x; }
void _print(string x){ cerr<<x; }
void _print(char x){ cerr<<x; }
void _print(ll x){ cerr<<x; }
void _print(bool x){ cerr<<x; }

template<class T>void _print(stack<T> st){ cerr<<"[ "; while(!st.empty()) { _print(st.top()); cerr<<" "; st.pop();} cerr<<"]"; }
template<class T>void _print(vector<T> v1){ cerr<<"[ "; for(T i:v1) { _print(i); cerr<<" "; } cerr<<"]"; }
template<class T>void _print(vector<T> v1,int a,int b){ cerr<<"[ "; for(int i=a;i<b;i++) { _print(v1[i]); cerr<<" "; } cerr<<"]"; }
template<class T>void _print(set<T> s){ cerr<<"[ "; for(T i:s){ _print(i); cerr<<" "; } cerr<<"]"; }
template<class T>void _print(unordered_set<T> s){ cerr<<"[ "; for(T i:s){ _print(i); cerr<<" "; } cerr<<"]"; }
template<class T>void _print(multiset<T> s){ cerr<<"[ "; for(T i:s){ _print(i); cerr<<" "; } cerr<<"]"; }
template<class T,class V>void _print(pair<T,V> p){ cerr<<"{";_print(p.f);cerr<<",";_print(p.s);cerr<<"}"; }
template<class T,class V>void _print(map<T,V> s){ cerr<<"[ "; for(auto i:s){ cerr<<"{";_print(i.f); cerr<<","; _print(i.s); cerr<<"} "; } cerr<<"]"; }
template<class T,class V>void _print(unordered_map<T,V> s){ cerr<<"[ "; for(auto i:s){ cerr<<"{";_print(i.f); cerr<<","; _print(i.s); cerr<<"} "; } cerr<<"]"; }
template<class T,class V>void _print(multimap<T,V> s){ cerr<<"[ "; for(auto i:s){ cerr<<"{";_print(i.f); cerr<<","; _print(i.s); cerr<<"} "; } cerr<<"]"; }

void solve()
{	
	// ##############################################################################################
	// ##############################################################################################

	//*) Unbounded Knapsack

	// ##############################################################################################
	// ##############################################################################################

	// related questions
	// -> rod cutting
	// -> coin change 1 (max no of ways)
	// -> coin change 2 (min no of coins)
	// -> max ribbon cut
	
	// idea is that unlike the 0 1 knapsack if you decides to put an element in the knapsack then you might reconsider putting it in bag again 
	// as long as the boundry conditions are met.

	// int n;cin>>n;
	// vector<int> v(n),val(n);
	// fr(i,0,n) cin>>v[i];
	// fr(i,0,n) cin>>val[i];
	// int W;cin>>W;

	// int dp[n+1][W+1];

	// fr(i,0,n+1){
	// 	fr(j,0,W+1){
	// 		if(i==0 || j==0) dp[i][j]=0; 
	// 	}
	// }

	// fr(i,1,n+1){
	// 	fr(j,1,W+1){
	// 		dp[i][j] = dp[i-1][j];
	// 		if(v[i-1]<=j) dp[i][j] = max(dp[i][j],val[i-1]+dp[i][j-v[i-1]]);
	// 	}
	// }

	// cout<<dp[n][W]<<endl;

	// 1 -> rod cutting problem
	// int n,m;cin>>n>>m;
	// vector<int> l(m),val(m);
	// fr(i,0,m){
	// 	cin>>l[i];
	// }
	// fr(i,0,m){
	// 	cin>>val[i];
	// }
	// // if wt/lenght array is not given that assume that the pices of any size <= n can be cut
	// int dp[m+1][n+1];
	// // first [] in dp -> size of the array
	// // second [] in dp -> problem size -> lenght of the rode
	// fr(i,0,m+1){
	// 	fr(j,0,n+1){
	// 		if(i==0 || j==0) dp[i][j]=0;
	// 	}
	// }

	// fr(i,1,m+1){
	// 	fr(j,1,n+1){
	// 		dp[i][j]=dp[i-1][j];
	// 		if(l[i-1]<=j)
	// 			dp[i][j] = max(dp[i][j],val[i-1]+dp[i][j-l[i-1]]);
	// 	}
	// }
	// cout<<dp[m][n]<<endl;

	// 2 -> coin change 1 (count no of ways of choosing 0 or many coins from arr such that sum = s)
	
	// int n;cin>>n;
	// vector<int> c(n);
	// fr(i,0,n) cin>>c[i];
	// int s;cin>>s;

	// int dp[n+1][s+1];

	// fr(i,0,n+1){
	// 	fr(j,0,s+1){
	// 		if(i==0) dp[i][j]=0;
	// 		if(j==0) dp[i][j]=1;
	// 	}
	// }

	// fr(i,1,n+1){
	// 	fr(j,1,s+1){
	// 		dp[i][j]=dp[i-1][j];
	// 		if(c[i-1]<=j)
	// 			dp[i][j]+=dp[i][j-c[i-1]];
	// 	}
	// }

	// cout<<dp[n][s]<<endl;

	// **3 -> coin change 2 (count min no of coins needed to such that thier sum is s)

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	// int s;cin>>s;

	// int dp[n+1][s+1];
	// fr(i,0,n+1){
	// 	fr(j,0,s+1){
	// 		if(i==0) dp[i][j]=int_max-1;
	// 		if(j==0) dp[i][j]=0;
	// 	}
	// }

	// for(int i=1,j=1;j<s+1;j++){
	// 	if(j%v[i-1]==0) dp[i][j] = j/v[i-1];
	// 	else dp[i][j] = int_max-1;
	// }

	// fr(i,1,n+1){
	// 	fr(j,1,s+1){
	// 		dp[i][j]=dp[i-1][j];
	// 		if(v[i-1]<=j)
	// 			dp[i][j] = min(1+dp[i][j-v[i-1]],dp[i][j]);
	// 	}
	// }

	// cout<<dp[n][s]<<endl;

	// 
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