#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define fr(i,a,n) for(auto i=a;i<n;i++)
#define rf(i,n,a) for(auto i=n;i>a;i--)
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define um unordered_map
#define sz size
#define f first
#define s second
#define mp make_pair
#define mt make_tuple
#define all(x) x.begin(),x.end()
#define scanvector(v,n) int n;cin>>n;vector<int> v(n);fr(i,0,n) cin>>v[i];
#define int_max INT_MAX
#define int_min INT_MIN
#define null NULL
const int M = 1e9 + 7;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
  
#define pbds_i tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define pbds_c tree<char, null_type,less<char>, rb_tree_tag,tree_order_statistics_node_update>
#define pbds_ll tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define pbds_d tree<double, null_type,less<double>, rb_tree_tag,tree_order_statistics_node_update>
#define pbds_s tree<string, null_type,less<string>, rb_tree_tag,tree_order_statistics_node_update>

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

void _print(char x){ cerr<<x; }
void _print(int x){ cerr<<x; }
void _print(string x){ cerr<<x; }
void _print(string x,int a,int b){ cerr<<"["; for(int i=a;i<b;i++){char t=x[i];_print(t);cerr<<" ";} cerr<<"]";}
void _print(ll x){ cerr<<x; }
void _print(bool x){ cerr<<x; }

template<class T>void _print(stack<T> st){ cerr<<"[ "; while(!st.empty()) { _print(st.top()); cerr<<" "; st.pop();} cerr<<"]"; }
template<class T>void _print(queue<T> q){ cerr<<"[ "; while(!q.empty()) { _print(q.front()); cerr<<" "; q.pop();} cerr<<"]"; }
template<class T>void _print(vector<T> v1){ cerr<<"[ "; for(T i:v1) { _print(i); cerr<<" "; } cerr<<"]"; }
template<class T>void _print(vector<T> v1,int a,int b){ cerr<<"[ "; for(int i=a;i<b;i++) { _print(v1[i]); cerr<<" "; } cerr<<"]"; }
template<class T>void _print(set<T> s){ cerr<<"[ "; for(T i:s){ _print(i); cerr<<" "; } cerr<<"]"; }
template<class T>void _print(unordered_set<T> s){ cerr<<"[ "; for(T i:s){ _print(i); cerr<<" "; } cerr<<"]"; }
template<class T>void _print(multiset<T> s){ cerr<<"[ "; for(T i:s){ _print(i); cerr<<" "; } cerr<<"]"; }
template<class T,class V>void _print(pair<T,V> p){ cerr<<"{";_print(p.f);cerr<<",";_print(p.s);cerr<<"}"; }
template<class T,class V>void _print(map<T,V> s){ cerr<<"[ "; for(auto i:s){ cerr<<"{";_print(i.f); cerr<<","; _print(i.s); cerr<<"} "; } cerr<<"]"; }
template<class T,class V>void _print(unordered_map<T,V> s){ cerr<<"[ "; for(auto i:s){ cerr<<"{";_print(i.f); cerr<<","; _print(i.s); cerr<<"} "; } cerr<<"]"; }
template<class T,class V>void _print(multimap<T,V> s){ cerr<<"[ "; for(auto i:s){ cerr<<"{";_print(i.f); cerr<<","; _print(i.s); cerr<<"} "; } cerr<<"]"; }

const int N = 1e2+1;
int dp[N][2][N];

// int paths(int i,int j){
// 	if(i==0 && j==0) return 1;
// 	if(i<0 || j<0) return 0;
// 	return paths(i-1,j)+paths(i,j-1);
// }

// int pathsmem(int i,int j){
// 	if(i==0 && j==0) return dp[i][j]=1;
// 	if(i<0 || j<0) return 0;
// 	if(dp[i][j]!=-1) return dp[i][j];
// 	return dp[i][j] = pathsmem(i-1,j)+pathsmem(i,j-1);
// }

// int pathsinobstacle(int i,int j,vector<vector<int>> a){
// 	if(i>=0 && j>=0 && a[i][j]==-1) return 0;
// 	if(i==0 && j==0) return 1;
// 	if(i<0 || j<0) return 0;
// 	return pathsinobstacle(i-1,j,a)+pathsinobstacle(i,j-1,a);
// }

// int pathsinobstaclemem(int i,int j,vector<vector<int>> a){
// 	if(i>=0 && j>=0 && a[i][j]==-1) return 0;
// 	if(i==0 && j==0) return 1;
// 	if(i<0 || j<0) return 0;
// 	if(dp[i][j]!=-1) return dp[i][j];
// 	return dp[i][j]=pathsinobstaclemem(i-1,j,a)+pathsinobstaclemem(i,j-1,a);
// }

// int minpath(int i,int j,vector<vector<int>> a){
// 	if(i==0&&j==0) return a[0][0];
// 	if(i<0 || j<0) return int_max;
// 	return a[i][j]+min(minpath(i-1,j,a),minpath(i,j-1,a));
// }

// int minpathmem(int i,int j,vector<vector<int>> a){
// 	if(i==0&&j==0) return a[0][0];
// 	if(i<0 || j<0) return int_max;
// 	if(dp[i][j]!=-1) return dp[i][j];
// 	return dp[i][j]=a[i][j]+min(minpathmem(i-1,j,a),minpathmem(i,j-1,a));
// }

// int minpathsumtriangle(int i,int j,int n,vector<vector<int>>& a){
// 	if(i==n-1) return a[n-1][j];
// 	else{
// 		return a[i][j]+min(minpathsumtriangle(i+1,j,n,a),minpathsumtriangle(i+1,j+1,n,a));
// 	}
// }

// int minpathsumtrianglemem(int i,int j,int n,vector<vector<int>>& a){
// 	if(i==n-1) return a[n-1][j];
// 	if(dp[i][j]!=-1) return dp[i][j];
// 	else{
// 		return dp[i][j]=a[i][j]+min(minpathsumtrianglemem(i+1,j,n,a),minpathsumtrianglemem(i+1,j+1,n,a));
// 	}
// }

// int maxpathfallingsum(int i,int j,vector<vector<int>>& a){
// 	if(j<0 || j>a[0].sz()) return -1e9;
// 	if(i==0) return a[0][j];
// 	else{
// 		return a[i][j]+max(maxpathfallingsum(i-1,j-1,a),max(maxpathfallingsum(i-1,j,a),maxpathfallingsum(i-1,j+1,a)));
// 	}
// }

// int maxpathfallingmem(int i,int j,vector<vector<int>>& a){
// 	if(j<0 || j>a[0].sz()) return -1e9;
// 	if(i==0) return a[0][j];
// 	if(dp[i][j]!=-1) return dp[i][j];
// 	else{
// 		int xx,yy,zz;
// 		xx = maxpathfallingmem(i-1,j-1,a);
// 		yy = maxpathfallingmem(i-1,j,a);
// 		zz = maxpathfallingmem(i-1,j+1,a);
// 		return dp[i][j]=a[i][j]+max({xx,yy,zz});
// 	}
// }

// int maxchocalatepickup(int i,int j1,int j2,vector<vector<int>>& a,int n,int m){
// 	if(j1<0 || j1>=m || j2<0 || j2>=m) return -1e8;
// 	if(i==n-1){
// 		if(j1==j2) return a[i][j1];
// 		else return a[i][j1]+a[i][j2];
// 	}
// 	int ans = int_min;
// 	fr(dj1,-1,2){
// 		fr(dj2,-1,2){
// 			int v=0;
// 			if(j1==j2) v=a[i][j1];
// 			else v=a[i][j1]+a[i][j2];
// 			v+=maxchocalatepickup(i+1,j1+dj1,j2+dj2,a,n,m);
// 			ans = max(ans,v);
// 		}
// 	}
// 	return ans;
// }

// int maxchocalatepickupmem(int i,int j1,int j2,vector<vector<int>>& a,int n,int m){
// 	if(j1<0 || j1>=m || j2<0 || j2>=m) return -1e8;
// 	if(i==n-1){
// 		if(j1==j2) return a[i][j1];
// 		else return a[i][j1]+a[i][j2];
// 	}
// 	if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
// 	int ans = int_min;
// 	fr(dj1,-1,2){
// 		fr(dj2,-1,2){
// 			int v=0;
// 			if(j1==j2) v=a[i][j1];
// 			else v=a[i][j1]+a[i][j2];
// 			v+=maxchocalatepickupmem(i+1,j1+dj1,j2+dj2,a,n,m);
// 			ans = max(ans,v);
// 		}
// 	}
// 	return dp[i][j1][j2]=ans;
// }

// int distinctss(string a,string b,int i,int j){
// 	if(j<0) return 1;
// 	if(i<0) return 0;
// 	if(a[i]==b[j])
// 		return distinctss(a,b,i-1,j-1)+distinctss(a,b,i-1,j);
// 	else
// 		return distinctss(a,b,i-1,j);
// }

// int distinctssmem(string& a,string& b,int i,int j){
// 	if(j<1) return 1;
// 	if(i<1) return 0;
// 	if(dp[i][j]!=-1) return dp[i][j];
// 	if(a[i-1]==b[j-1])
// 		return dp[i][j]=distinctssmem(a,b,i-1,j-1)+distinctssmem(a,b,i-1,j);
// 	else
// 		return dp[i][j]=distinctssmem(a,b,i-1,j);
// }

// int editdist(string a,string b,int i,int j){
// 	if(i<1) return j;
// 	if(j<1) return i;
// 	if(a[i-1]==b[j-1]) return editdist(a,b,i-1,j-1);
// 	else{
// 		return min({1+editdist(a,b,i,j-1),1+editdist(a,b,i-1,j),1+editdist(a,b,i-1,j-1)});
// 	}
// }

// int editdistmem(string a,string b,int i,int j){
// 	if(i<1) return j;
// 	if(j<1) return i;
// 	if(dp[i][j]!=-1) return dp[i][j];
// 	if(a[i-1]==b[j-1]) return dp[i][j]=editdist(a,b,i-1,j-1);
// 	else{
// 		return dp[i][j]=min({1+editdistmem(a,b,i,j-1),1+editdistmem(a,b,i-1,j),1+editdistmem(a,b,i-1,j-1)});
// 	}
// }

// bool matching(string a,string b,int i,int j){
// 	if(i<1 && j<1) return true;
// 	if(i<1 && j>=1) return false;
// 	if(i>=1 && j<1){
// 		fr(k,1,i+1){
// 			if(a[k-1]!='*') 
// 				return false;
// 		}
// 		return true;
// 	}
// 	if(a[i-1]==b[j-1] || a[i-1]=='?'){
// 		return matching(a,b,i-1,j-1);
// 	}else if(a[i-1]=='*'){
// 		return matching(a,b,i-1,j) | matching(a,b,i,j-1);
// 	}else{
// 		return false;
// 	}
// }

// bool matchingmem(string a,string b,int i,int j){
// 	if(i<1 && j<1) return true;
// 	if(i<1 && j>=1) return false;
// 	if(i>=1 && j<1){
// 		fr(k,1,i+1){
// 			if(a[k-1]!='*') 
// 				return false;
// 		}
// 		return true;
// 	}
// 	if(dp[i][j]!=-1) return dp[i][j];
// 	if(a[i-1]==b[j-1] || a[i-1]=='?'){
// 		return dp[i][j]=matchingmem(a,b,i-1,j-1);
// 	}else if(a[i-1]=='*'){
// 		return dp[i][j]=matchingmem(a,b,i-1,j) | matchingmem(a,b,i,j-1);
// 	}else{
// 		return dp[i][j]=false;
// 	}
// }

// int pbns(int i,int n,int buy,vector<int> v){
// 	if(i>=n) return 0;
// 	int profit = int_min;
// 	if(buy){
// 		profit = max(profit,max(pbns(i+1,n,0,v)-v[i],pbns(i+1,n,1,v)));
// 	}else{
// 		profit = max(profit,max(pbns(i+1,n,1,v)+v[i],pbns(i+1,n,0,v)));
// 	}
// 	return profit;
// }

// int IImem(int i,int buy,int n,vector<int> v){
// 	if(i>=n) return 0;
// 	int profit = int_min;
// 	if(dp[i][buy]!=-1) return dp[i][buy];
// 	if(buy){
// 		profit = max(profit,max(IImem(i+1,0,n,v)-v[i],IImem(i+1,1,n,v)));
// 	}else{
// 		profit = max(profit,max(IImem(i+1,1,n,v)+v[i],IImem(i+1,0,n,v)));
// 	}
// 	return dp[i][buy] = profit;
// }

// int atmax2(int i,int buy,int cap,vector<int> v){
// 	if(i==v.sz() || cap==0) return 0;
// 	if(buy){
// 		return max(atmax2(i+1,1,cap,v),-v[i]+atmax2(i+1,0,cap,v));
// 	}else{
// 		return max(atmax2(i+1,0,cap,v),v[i]+atmax2(i+1,1,cap-1,v));
// 	}
// }

int IIImem(int i,int buy,int cap,vector<int> v){
	if(i==v.sz() || cap==0) return 0;
	if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
	if(buy){
		return dp[i][buy][cap]=max(IIImem(i+1,1,cap,v),-v[i]+IIImem(i+1,0,cap,v));
	}else{
		return dp[i][buy][cap]=max(IIImem(i+1,0,cap,v),v[i]+IIImem(i+1,1,cap-1,v));
	}
}

int cooldown(int i,int buy,vector<int> v){
	if(i>=v.sz()) return 0;
	if(buy)
		return max(-v[i]+cooldown(i+1,0,v),cooldown(i+1,1,v));
	else
		return max(v[i]+cooldown(i+2,1,v),cooldown(i+1,0,v));
}

int transectionfee(int i,int buy,vector<int> v,int f){
	if(i==v.sz()) return 0;
	if(buy){
		return max(-v[i]+transectionfee(i+1,0,v,f),transectionfee(i+1,1,v,f));
	}else{
		return max(v[i]-f+transectionfee(i+1,1,v,f),transectionfee(i+1,0,v,f));
	}
}



void solve()
{	
	// ******************************************************************************
	// dp on grid
	// ******************************************************************************

	// 1) no of ways to reach the opposite corner of the grid starting from (0,0);
	// int n,m;cin>>n>>m;

	// int ans = paths(n-1,m-1);
	// cout<<ans<<endl;

	// memoized
	// memset(dp,-1,sizeof dp);
	// int ans = pathsmem(n-1,m-1);
	// cout<<ans<<endl;

	// tabulation
	// memset(dp,-1,sizeof dp);
	// dp[0][0]=1;

	// fr(i,0,n){
	// 	fr(j,0,m){
	// 		if(i==0 && j==0) continue;
	// 		int x=0,y=0;
	// 		if(i-1>=0) x=dp[i-1][j];
	// 		if(j-1>=0) y=dp[i][j-1];
	// 		dp[i][j] = (x+y)%M;
	// 	}
	// }

	// cout<<dp[n-1][m-1]<<endl;

	// most optimized
	// the ans of these quesion in combinatrics is the (m+n-1)!/((m-1)!(n-1)!)

	// ll ans = 1;
	// for(int i=n;i<(m+n-1);i++){
	// 	ans *= i;
	// 	ans /= (i-n+1);
	// }
	// cout<<ans<<endl;

	// 2) no of ways to reach the bottom right cell in the grid of the obstacles

	// int n,m;cin>>n>>m;
	// vector<vector<int>> a(n,vector<int>(m));
	// fr(i,0,n) fr(j,0,m) cin>>a[i][j];

	// int ans = pathsinobstacle(n-1,m-1,a);
	// cout<<ans<<endl;

	// memset(dp,-1,sizeof dp);
	// int ans = pathsinobstaclemem(n-1,m-1,a);
	// cout<<ans<<endl;

	// tabulation
	// memset(dp,0,sizeof dp);
	// fr(i,0,n){
	// 	fr(j,0,m){
	// 		if(a[i][j]==-1) dp[i][j]=0;
	// 		else if(i==0 && j==0) dp[i][j]=1;
	// 		else{
	// 			int x=0,y=0;
	// 			if(i-1>=0) x=dp[i-1][j];
	// 			if(j-1>=0) y=dp[i][j-1];
	// 			dp[i][j]=x+y;
	// 		}
	// 	}
	// }
	// cout<<dp[n-1][m-1]<<endl;

	// 3) minimum path sum in 2d grid

	// int n,m;cin>>n>>m;
	// vector<vector<int>> a(n,vector<int>(m));
	// fr(i,0,n){
	// 	fr(j,0,m){
	// 		cin>>a[i][j];
	// 	}
	// }

	// int ans = minpath(n-1,m-1,a);
	// cout<<ans<<endl;

	// memset(dp,-1,sizeof dp);
	// int ans = minpathmem(n-1,m-1,a);
	// cout<<ans<<endl;

	// fr(i,0,n){
	// 	fr(j,0,m){
	// 		if(i==0 && j==0) dp[0][0]=a[0][0];
	// 		else{
	// 			int x=int_max,y=int_max;
	// 			if(i-1>=0) x=dp[i-1][j];
	// 			if(j-1>=0) y=dp[i][j-1];
	// 			dp[i][j] = a[i][j]+min(x,y);		
	// 		}
	// 	}
	// }

	// fr(i,0,n){
	// 	fr(j,0,m){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	// cout<<endl<<dp[n-1][m-1]<<endl;

	// 4) min path sum in trinagular grid : a[i][j>i]=int_max; , a[i<j][j]<int_max;
	// fixed staring point and variable ending point

	// 1
	// 2 3
	// 4 5 6
	// 7 8 9 3
	// 4 5 6 1 2

	// int n;cin>>n;
	// vector<vector<int>> a;

	// fr(i,0,n){
	// 	vector<int> t(i+1);
	// 	fr(j,0,i+1) cin>>t[j];
	// 	a.pb(t);
	// }

	// int ans = minpathsumtriangle(0,0,n,a);
	// cout<<ans<<endl;

	// memset(dp,-1,sizeof dp);
	// int ans = minpathsumtrianglemem(0,0,n,a);
	// cout<<ans<<endl;

	// fr(i,0,n){
	// 	fr(j,0,i+1){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	// memset(dp,-1,sizeof dp);
	// vector<int> prev(n,-1),curr(n,-1);
	// fr(i,0,n) dp[n-1][i]=a[n-1][i];

	// for(int i=n-2;i>=0;i--){
	// 	for(int j=0;j<=i;j++){
	// 		dp[i][j]=int_max;
	// 		dp[i][j]=a[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
	// 	}
	// }

	// cout<<dp[0][0]<<endl;
	
	// fr(i,0,n) curr[i]=a[n-1][i];

	// for(int i=n-2;i>=0;i--){
	// 	for(int j=0;j<=i;j++){
	// 		prev[j]=int_max;
	// 		prev[j]=a[i][j]+min(curr[j],curr[j+1]);
	// 	}
	// 	curr = prev;
	// }
	// cout<<curr[0]<<endl;

	// 5) min/max falling path sum in the N x M matrix
	// check answer on every cell in last row falling from first row

	// int n,m;cin>>n>>m;
	// vector<vector<int>> a(n,vector<int>(m));
	// fr(i,0,n) fr(j,0,m) cin>>a[i][j];

	// int ans = int_min;
	// fr(j,0,m) ans=max(ans,maxpathfallingsum(n-1,j,a));
	// cout<<ans<<endl;

	// memset(dp,-1,sizeof dp);
	// int ans = int_min;
	// fr(j,0,m) ans=max(ans,maxpathfallingmem(n-1,j,a));
	// cout<<ans<<endl;

	// memset(dp,-1,sizeof dp);
	// fr(j,0,m) dp[0][j] = a[0][j];

	// fr(i,1,n){
	// 	fr(j,0,m){
	// 		dp[i][j] = int_min;
	// 		int x = int_min,y = int_min,z = int_min;
	// 		if(j-1>=0) x=dp[i-1][j-1];
	// 		if(j>=0) y=dp[i-1][j];
	// 		if(j+1<=m-1) z=dp[i-1][j+1];
	// 		dp[i][j] = a[i][j] + max({x,y,z});
	// 	}
	// }

	// fr(i,0,n){
	// 	fr(j,0,m){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	// int ans = int_min;
	// fr(j,0,m-1) ans = max(ans,dp[n-1][j]);
	// cout<<ans<<endl;

	// 6) cherry pickup II (3D DP)

	// alice at pos (0,0) and bob at pos (0,m-1)
	// find max no of candy they can collect if they go downwords in three directions
	// (i,j) -> {(i+1,j),(i+1,j-1),(i+1,j+1)}

	// int n,m;cin>>n>>m;
	// vector<vector<int>> a(n,vector<int>(m));
	// fr(i,0,n) fr(j,0,m) cin>>a[i][j];

	// int ans = maxchocalatepickup(0,0,m-1,a,n,m);
	// cout<<ans<<endl;

	// memset(dp,-1,sizeof dp);
	// int ans = maxchocalatepickupmem(0,0,m-1,a,n,m);
	// cout<<ans<<endl;

	// memset(dp,-1,sizeof dp);
	// fr(j1,0,m){
	// 	fr(j2,0,m){
	// 		if(j1==j2) dp[n-1][j1][j2] = a[n-1][j1];
	// 		else dp[n-1][j1][j2] = a[n-1][j1]+a[n-1][j2];
	// 	}
	// }

	// for(int i=n-2;i>=0;i--){
	// 	fr(j1,0,m){
	// 		fr(j2,0,m){
	// 			dp[i][j1][j2] = int_min;
	// 			fr(x,-1,2){
	// 				fr(y,-1,2){
	// 					int v=0;
	// 					if(j1==j2) v=a[i][j1];
	// 					else v=a[i][j1]+a[i][j2];
	// 					if(j1+x<m && j1+x>=0 && j2+y>=0 && j2+y<m)
	// 						v += dp[i+1][j1+x][j2+y];
	// 					else
	// 						v += -1e8;
	// 					dp[i][j1][j2] = max(dp[i][j1][j2],v);
	// 				}
	// 			}
	// 		}
	// 	}
	// }

	// cout<<dp[0][0][m-1]<<endl;

	// vector<vector<int>> curr(m,vector<int>(m,0)),prev(m,vector<int>(m,0));

	// fr(i,0,m){
	// 	fr(j,0,m){
	// 		if(i==j) curr[i][j] = a[n-1][i];
	// 		else curr[i][j] = a[n-1][i] + a[n-1][j];
	// 	}
	// }

	// for(int i=n-2;i>=0;i--){
	// 	fr(j1,0,m){
	// 		fr(j2,0,m){
	// 			prev[j1][j2] = int_min;
	// 			fr(x,-1,2){
	// 				fr(y,-1,2){
	// 					int v=0;
	// 					if(j1==j2) v=a[i][j1];
	// 					else v=a[i][j1]+a[i][j2];
	// 					if(0<=j1+x && j1+x<m && 0<=j2+y && j2+y<m)
	// 						v+=curr[j1+x][j2+y];
	// 					else
	// 						v+= -1e9;
	// 					prev[j1][j2] = max(prev[j1][j2],v);
	// 				}
	// 			}
	// 		}
	// 	}
	// 	curr = prev;
	// }
	// cout<<prev[0][m-1]<<endl;

	// **7) no of total distinct strings s1 as a subsequence in s1

	// string a,b;cin>>a>>b;
	// int ans = distinctss(a,b,a.sz()-1,b.sz()-1);
	// cout<<ans<<endl;

	// memset(dp,-1,sizeof dp);
	// int ans = distinctssmem(a,b,a.sz(),b.sz());
	// cout<<ans<<endl;

	// memset(dp,-1,sizeof dp);
	// int n = a.sz(),m=b.sz();
	// fr(i,0,n+1){
	// 	fr(j,0,m+1){
	// 		if(i==0) dp[i][j]=0;
	// 		if(j==0) dp[i][j]=1;
	// 	}
	// }

	// fr(i,1,n+1){
	// 	fr(j,1,m+1){
	// 		if(a[i-1]==b[j-1])
	// 			dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
	// 		else
	// 			dp[i][j] = dp[i-1][j];
	// 	}
	// }

	// cout<<dp[n][m]<<endl;

	// int n = a.sz(),m=b.sz();
	// vector<int> curr(m+1,0),prev(m+1,0);
	// prev[0]=curr[0]=1;

	// fr(i,1,n+1){
	// 	fr(j,1,m+1){
	// 		if(a[i-1]==b[j-1])
	// 			prev[j] = prev[j-1] + prev[j];
	// 		// else
	// 		// 	curr[j] = prev[j];
	// 	}
	// 	// prev = curr;
	// }

	// cout<<prev[m]<<endl;

	// 8) edit distance :: min no of operations to transform s1 into s2
	// using three operations : insert,delete and replace

	// string a,b;cin>>a>>b;
	// int n=a.sz(),m=b.sz();

	// int ans = editdist(a,b,n,m);
	// cout<<ans<<endl;

	// memset(dp,-1,sizeof dp);
	// int ans = editdistmem(a,b,n,m);
	// cout<<ans<<endl;

	// memset(dp,-1,sizeof dp);
	// fr(i,0,n+1){
	// 	fr(j,0,m+1){
	// 		if(i==0) dp[i][j]=j;
	// 		if(j==0) dp[i][j]=i;
	// 	}
	// }

	// fr(i,1,n+1){
	// 	fr(j,1,m+1){
	// 		if(a[i-1]==b[j-1])
	// 			dp[i][j] = dp[i-1][j-1];
	// 		else
	// 			dp[i][j] = 1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
	// 	}
	// }

	// cout<<dp[n][m]<<endl;

	// 9) wild card matching

	// string s1,s2;cin>>s1>>s2;
	// bool b = matching(s1,s2,s1.sz(),s2.sz());
	// cout<<b<<endl;

	// memset(dp,-1,sizeof dp);
	// bool b = matchingmem(s1,s2,s1.sz(),s2.sz());
	// cout<<b<<endl;

	// int n=s1.sz(),m=s2.sz();
	// memset(dp,-1,sizeof dp);
	// fr(i,0,n+1){
	// 	fr(j,0,m+1){
	// 		if(i==0 && j==0) dp[i][j]= 1;
	// 		if(i==0 && j>0) dp[i][j]= 0;
	// 		if(j==0 && i>0) dp[i][j] = dp[i-1][j]*(s1[i-1]=='*');	
	// 	}
	// }

	// dp[0][0]=0;
	// // dp[0][1->m+1]=false;
	// // dp[i::1->n+1i][0] = dp[i-1][0]*s1[i-1]=='*'

	// fr(j,1,m+1) dp[0][j] = false;
	// fr(i,1,n+1) dp[i][0] = dp[i-1][0]*s[i-1]=='*';

	// fr(i,1,n+1){
	// 	fr(j,1,m+1){
	// 		dp[i][j] = 0;
	// 		if(s1[i-1]==s2[j-1] || s1[i-1]=='?')
	// 			dp[i][j] = dp[i][j] | dp[i-1][j-1];
	// 		else if(s1[i-1]=='*')
	// 			dp[i][j] = dp[i][j] | dp[i-1][j] | dp[i][j-1];
	// 	}
	// }
	// cout<<dp[n][m]<<endl;

	// ********************************************************************************
	// dp on stocks
	// ********************************************************************************

	// 1) maximum profit by buying and selling the stock only one time :: I

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	// int minbuy = v[0];
	// int ans = 0;
	// fr(i,0,n){
	// 	ans = max(ans,v[i]-minbuy);
	// 	minbuy = min(minbuy,v[i]);
	// }
	// cout<<ans<<endl;

	// 2) maximum profit by buying and selling stocks as many time u wish : II
	// buy-sell-buy-sell-buy-sell

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];

	// int ans = pbns(0,n,1,v);
	// cout<<ans<<endl;

	// memset(dp,-1,sizeof dp);
	// int ans = IImem(0,1,n,v);
	// cout<<ans<<endl;

	// memset(dp,-1,sizeof dp);
	// dp[n][1] = dp[n][0] = 0;
	// for(int i=n-1;i>=0;i--){
	// 	for(int buy = 0;buy<=1;buy++){
	// 		if(buy){
	// 			dp[i][1] = max(dp[i+1][1],-v[i]+dp[i+1][0]);
	// 		}else{
	// 			dp[i][0] = max(dp[i+1][0],v[i]+dp[i+1][1]);
	// 		}
	// 	}
	// }
	// cout<<dp[0][1]<<endl;

	// 3) maximum profit by buying and selling the stocks at max 2 times : III

	// same as above but there will be limit on complete transections

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];

	// int ans = atmax2(0,1,2,v);
	// cout<<ans<<endl;

	// memset(dp,-1,sizeof dp);
	// int ans = IIImem(0,1,2,v);
	// cout<<ans<<endl;

	// memset(dp,-1,sizeof dp);
	// // dp[n+1][2][2];

	// fr(i,0,n+1){
	// 	fr(buy,0,2){
	// 		fr(cap,0,3){
	// 			if(cap==0||i==n) dp[i][buy][cap]=0;
	// 		}
	// 	}
	// }

	// for(int i=n-1;i>=0;i--){
	// 	for(int b=0;b<=1;b++){
	// 		for(int c=1;c<=2;c++){
	// 			dp[i][b][c] = int_min;
	// 			if(b){
	// 				dp[i][b][c] = max(-v[i]+dp[i+1][0][c],dp[i+1][1][c]);
	// 			}else{
	// 				dp[i][b][c] = max(v[i]+dp[i+1][1][c-1],dp[i+1][0][c]);
	// 			}

	// 		}
	// 	}
	// }

	// cout<<dp[0][1][2]<<endl;

	// 4) atmost k transections : IV

	// same as above but there will be k instead of 2 :: dp[][][k]
	// and ans is :: dp[0][1][k]

	// 5) buy and sell with cooldown : V

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];

	// int ans = cooldown(0,1,v);
	// cout<<ans<<endl;

	// 6) buy and sell with transection free : VI

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	// int f;cin>>f;

	// int ans = transectionfee(0,1,v,f);
	// cout<<ans<<endl;
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