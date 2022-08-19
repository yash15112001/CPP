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

// const int N = 1e3+7;
// int dp[N][N];

// int f(int n,vector<int>& v){
// 	if(n==0||n==1) return v[n];
// 	return v[n]+min(f(n-1,v),f(n-2,v));
// }

// int f(int n,vector<int>& v){
// 	if(n<0) return 0;
// 	if(n==0) return v[n];
// 	return max(f(n-1,v),v[n]+f(n-2,v));
// }

// int f(int n,int x,int y,int z){
// 	if(n<0) return int_min;
// 	if(n==0) return 0;
// 	int a = 1+f(n-x,x,y,z);
// 	int b = 1+f(n-y,x,y,z);
// 	int c = 1+f(n-z,x,y,z);
// 	return max({a,b,c});
// }

// int f(vector<vector<int>>& a,int n,int day,int i){
// 	if(day==n) return 0;
// 	int ans = int_min;
// 	fr(j,0,3){
// 		if(j!=i){
// 			ans = max(ans,a[day][j]+f(a,n,day+1,j));
// 		}
// 	}
// 	return ans;
// }

// int f(int n,vector<int>& v,int k){
// 	if(n==0) return 0;
// 	if(n==1) return abs(v[0]-v[1]);
// 	int ans = int_max;
// 	fr(j,1,k+1){
// 		if(n-j>=0){
// 			ans = min(ans,abs(v[n]-v[n-j])+f(n-j));
// 		}
// 	}
// 	return ans;
// 	// return min(f(n-1)+abs(v[n]-v[n-1]),f(n-2)+abs(v[n]-v[n-2]));
// }

// int f(vector<int>& wt,vector<int>& val,int n,int W){
// 	if(W==0||n==0) return 0;
// 	if(wt[n-1]<=W){
// 		return max(f(wt,val,n-1,W),val[n-1]+f(wt,val,n-1,W-wt[n-1]));
// 	}
// 	else{
// 		return f(wt,val,n-1,W);
// 	}
// }

// int f(vector<int>& v,int n,int w){
// 	if(w==0) return 1;
// 	if(n==0 && w!=0) return 0;
// 	// if(dp[n][w]!=-1) return dp[n][w];
// 	if(v[n-1]<=w)
// 		return f(v,n-1,w)+f(v,n-1,w-v[n-1]);
// 	else
// 		return f(v,n-1,w); 
// }

// int f(vector<int>& wt,vector<int>& val,int n,int w){
// 	if(w==0||n==0) return 0;
// 	if(wt[n-1]<=w)
// 		return max(f(wt,val,n-1,w),val[n-1]+f(wt,val,n,w-wt[n-1]));
// 	else
// 		return f(wt,val,n-1,w);
// }

// int f(vector<int>& len,vector<int>& val,int n,int l){
// 	if(n==0||l==0) return 0;
// 	if(len[n-1]<=l)
// 		return max(f(len,val,n-1,l),val[n-1]+f(len,val,n,l-len[n-1]));
// 	else
// 		return f(len,val,n-1,l);
// }

// int f(vector<int>& v,int x,int n,vector<int>& s){
// 	if(x==0) {
// 		int t = s.sz();
// 		fr(i,0,t){
// 			cout<<v[s[i]];
// 			if(i!=t-1) cout<<" + ";
// 		}
// 		cout<<endl;
// 		return 1;
// 	}
// 	if(n==0) return 0;
// 	vector<int> s2 = s;
// 	s2.pb(n-1);
// 	if(v[n-1]<=x)
// 		return f(v,x-v[n-1],n,s2)+f(v,x,n-1,s);
// 	else
// 		return f(v,x,n-1,s);
// }

// int f(vector<int>& v,int n,int x){
// 	if(x==0) return 0;
// 	if(n==0) return int_max-10;
// 	if(n==1){
// 		if(x%v[n-1]==0) return x/v[n-1];
// 		else return int_max-10;
// 	}
// 	if(v[n-1]<=x){
// 		return min(f(v,n-1,x),1+f(v,n,x-v[n-1]));
// 	}else{
// 		return f(v,n-1,x);
// 	}
// }

// int f(string a,string b,int n,int m){
// 	if(n==0 || m==0) return 0;
// 	if(dp[n][m]!=-1) return dp[n][m];
// 	if(a[n-1]==b[m-1])
// 		return 1+f(a,b,n-1,m-1);
// 	else
// 		return 0;
// }

// int f(string a,string b,int n,int m,int ans){
// 	if(n==0||m==0) return ans;
// 	if(a[n-1]==b[m-1]){
// 		ans = f(a,b,n-1,m-1,ans+1);
// 	}
// 	ans = max({ans,f(a,b,n-1,m,0),f(a,b,n,m-1,0)});
// 	return ans;
// }

// int f(string s,int n,int m){
// 	if(n==0||m==0) return 0;
// 	if(n!=m && s[n-1]==s[m-1])
// 		return 1+f(s,n-1,m-1);
// 	else
// 		return max(f(s,n-1,m),f(s,n,m-1));
// }

// int f(string a,string b,int n,int m){
// 	if(m==0) return 1;
// 	if(n==0) return 0;
// 	if(a[n-1]==b[m-1])
// 		return f(a,b,n-1,m-1)+f(a,b,n-1,m);
// 	else
// 		return f(a,b,n-1,m);
// }

// int f(int n,int m){
// 	if(n==0||m==0) return 1;
// 	return f(n-1,m)+f(n,m-1);
// }

// int f(int i,int j){
// 	if(i==0 && j==0) return 1;
// 	if(i<0 || j<0) return 0;
// 	return f(i-1,j)+f(i,j-1);
// }

// int f(int n,int m,vector<vector<int>>& a){
// 	if(n>=0 && m>=0 && a[n][m]==-1) return 0;
// 	if(n==0 && m==0 && a[0][0]!=-1) return 1;
// 	if(n<0 || m<0) return 0;
// 	return f(n-1,m,a)+f(n,m-1,a);  
// }

// int f(int n,int m,vector<vector<int>>& a){
// 	if(n==0 && m==0) return a[0][0];
// 	if(n<0 || m<0) return int_max;
// 	return a[n][m]+min(f(n-1,m,a),f(n,m-1,a));
// }

// int f(int i,int j,int n,vector<vector<int>>& a){
// 	if(i==n-1) return a[n-1][j];
// 	return a[i][j]+min(f(i+1,j,n,a),f(i+1,j+1,n,a));
// }

// int f(int n,int j,vector<vector<int>>& a){
// 	if(j<0 || j>a[0].sz()) return int_min;
// 	if(n==0) return a[0][j];
// 	return a[n][j]+max({f(n-1,j-1,a),f(n-1,j,a),f(n-1,j+1,a)});
// }

// int f(int i,int j,vector<vector<int>>& a){
// 	if(j<0 || j>a[0].sz()) return -1e9;
// 	// if(dp[i][j]!=-1) return dp[i][j];
// 	if(i==0) return a[0][j];
// 	else{
// 		return a[i][j]+max(f(i-1,j-1,a),max(f(i-1,j,a),f(i-1,j+1,a)));
// 	}
// }

// int f(int i,int j,vector<vector<int>>& a,int m,int n){
// 	if(j<0 || j>=m) return int_min;
// 	if(i==n-1) return a[i][j];
// 	return a[i][j]+max({f(i+1,j,a,m,n),f(i+1,j-1,a,m,n),f(i+1,j+1,a,m,n)});
// }

// int f(int i,int j1,int j2,int n,int m,vector<vector<int>>& a){
// 	if(j1<0 || j2<0 || j1>=m || j2>=m) return int_min;
// 	if(i==n-1){
// 		if(j1==j2) return a[i][j1];
// 		return a[i][j1]+a[i][j2];
// 	}
// 	int ans = int_min;
// 	for(int x=-1;x<=1;x++){
// 		for(int y=-1;y<=1;y++){
// 			int tans = 0;
// 			if(j1==j2) tans+=a[i][j1];
// 			else tans+=(a[i][j1]+a[i][j2]);
// 			tans+=f(i+1,j1+x,j2+y,n,m,a);
// 			ans = max(ans,tans);
// 		}
// 	}
// 	return ans;
// }

// int f(string a,string b,int n,int m){
// 	if(n==0) return m;
// 	if(m==0) return n;
// 	if(a[n-1]==b[m-1]) return f(a,b,n-1,m-1);
// 	else{
// 		return 1+min({f(a,b,n,m-1),f(a,b,n-1,m),f(a,b,n-1,m-1)});
// 	}
// }

// bool f(string a,string b,int n,int m){
// 	if(n==0 && m==0) return 1;
// 	if(n==0 && m) return 0;
// 	if(n && m==0) return (a[n-1]=='*')&&f(a,b,n-1,m);
// 	if(a[n-1]==b[m-1] || a[n-1]=='?')
// 		return f(a,b,n-1,m-1);
// 	else if(a[n-1]=='*')
// 		return f(a,b,n-1,m) || f(a,b,n,m-1);
// 	else
// 		return 0;
// }

// int f(int i,int b,vector<int>& v){
// 	if(i==v.sz()) return 0;
// 	if(b)
// 		return max(f(i+1,b,v),-v[i]+f(i+1,!b,v));
// 	else
// 		return max(v[i]+f(i+1,!b,v),f(i+1,b,v));
// }

// int f(int i,int b,int k,vector<int>& v){
// 	if(i==v.sz()||k==0) return 0;
// 	if(b)
// 		return max(f(i+1,b,k,v),-v[i]+f(i+1,!b,k,v));
// 	else
// 		return max(f(i+1,b,k,v),v[i]+f(i+1,!b,k-1,v));
// }

// int f(int i,int b,vector<int>& v){
// 	if(i>=v.sz()) return 0;
// 	if(b)
// 		return max(f(i+1,b,v),-v[i]+f(i+1,!b,v));
// 	else
// 		return max(f(i+1,b,v),v[i]+f(i+2,!b,v));
// }

// int f(int i,int j,vector<int>& v){
// 	if(i>=j) return 0;
// 	int ans = int_max;
// 	fr(k,i,j)
// 		ans = min(ans,v[i-1]*v[k]*v[j]+f(i,k,v)+f(k+1,j,v));
// 	return ans;
// }

// bool isp(string s,int i,int j){
// 	while(i<j){
// 		if(s[i]==s[j]){
// 			i++,j--;
// 		}else{
// 			return false;
// 		}
// 	}
// 	return true;
// }

// int f(int i,int j,string s){
// 	if(i>=j||isp(s,i,j)) return 0;
// 	int ans = int_max;
// 	for(int k=i;k<j;k++)
// 		ans = min(ans,1+f(i,k,s)+f(k+1,j,s));
// 	return ans;
// }

// int f(int i,int j,string s,bool b){
// 	if(i>j) return 0;
// 	if(i==j){
// 		if(b) return s[i]=='T';
// 		return s[i]=='F';
// 	}
// 	int ans=0;
// 	for(int k=i+1;k<=j-1;k+=2){
// 		int lt,lf,rt,rf;
// 		lt = f(i,k-1,s,1);
// 		lf = f(i,k-1,s,0);
// 		rt = f(k+1,j,s,1);
// 		rf = f(k+1,j,s,0);
// 		if(s[k]=='&'){
// 			if(b) ans += lt*rt;
// 			else ans += lt*rf + lf*rt + lf*rf;
// 		}else if(s[k]=='^'){
// 			if(b) ans += lt*rf + rt*lf;
// 			else ans += lt*rt + lf*rf;
// 		}else{
// 			if(b) ans += lt*rt + lf*rt + lt*rf;
// 			else ans += lf*rf;
// 		}
// 	}
// 	return ans;
// }

// int f(string s,int i,int j,bool b){
// 	if(i>j) return 0;
// 	if(i==j){
// 		if(b) return s[i]=='T';
// 		else return s[i]=='F';
// 	}
// 	int ans=0;
// 	for(int k=i+1;k<j;k+=2){
// 		int lt = f(s,i,k-1,1);
// 		int lf = f(s,i,k-1,0);
// 		int rt = f(s,k+1,j,1);
// 		int rf = f(s,k+1,j,0);

// 		if(s[k]=='&'){
// 			if(b){
// 				ans += lt*rt;
// 			}else{
// 				ans += lf*rt + lt*rf + lf*rf;
// 			}
// 		}else if(s[k]=='|'){
// 			if(b){
// 				ans += lt*rt + lt*rf + lf*rt;
// 			}else{
// 				ans += lf*rf;
// 			}
// 		}else if(s[k]=='^'){
// 			if(b){
// 				ans += lt*rf + lf*rt;
// 			}else{
// 				ans += lt*rt + lf*rf;
// 			}
// 		}
// 	}
// 	return ans;
// }

// map<pair<string,string>,int> m;

// bool f(string a,string b){
// 	if(a.sz()!=b.sz()) return 0;
// 	if(a==b) return 1;
// 	if(a.sz()<1) return 0;
// 	if(m.find(mp(a,b))!=m.end()) return m[{a,b}];
// 	int n = a.sz();
// 	fr(i,1,a.sz()){
// 		bool b1 = f(a.substr(0,i),b.substr(n-i)) && f(a.substr(i),b.substr(0,n-i)); 
// 		if(b1) return m[{a,b}]=true;
// 		bool b2 = f(a.substr(0,i),b.substr(0,i)) && f(a.substr(i),b.substr(i));
// 		if(b2) return m[{a,b}]=true;
// 	}
// 	return m[{a,b}]=false;
// }

// int ff(int e,int f){
// 	if(e==1||f==0||f==1) return f;
// 	int ans = int_max;
// 	fr(i,1,f+1)
// 		ans = min(ans,1+max(ff(e-1,i-1),ff(e,f-i)));
// 	return ans;
// }

void solve()
{	
	// no of ways to reach the the nth stair : f(n) = f(n-1)+f(n-2) .. f(1) = 1 = f(2) , f(3) = 2;
	// min steps to reach the nth stair : n/2 + n%2

	// min cost to reach the nth stair with 
	// pay when arrive the ith step except nth step
	// steps are from 0 1 2 to n-1
	// can start from 0 or 1
	// ans = min(f(n-1),f(n-2));
	// f(0)=v(0) , f(1)=v(1) , f(n) = v(n)+min(f(n-1),f(n-2))

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];

	// int ans = min(f(n-1,v),f(n-2,v));
	// cout<<ans<<endl;

	// maxsumofnonadjele
	
	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];

	// int ans = f(n-1,v);
	// cout<<ans<<endl;

	// int n,x,y,z;cin>>n>>x>>y>>z;
	// int ans = f(n,x,y,z);
	// cout<<ans<<endl;

	// int n;cin>>n;
	// vector<vector<int>> a(n+1,vector<int>(4,0));
	// fr(i,1,n+1){
	// 	cin>>a[i][1]>>a[i][2]>>a[i][3];
	// }

	// // int ans = max(f(a,n,0,0),f(a,n,0,1),f(a,n,0,2));
	// // cout<<ans<<endl;

	// for(int i=n-1;i>=1;i--){
	// 	a[i][1]+=max(a[i+1][2],a[i+1][3]);
	// 	a[i][2]+=max(a[i+1][1],a[i+1][3]);
	// 	a[i][3]+=max(a[i+1][1],a[i+1][2]);
	// }

	// int ans=max({a[1][1],a[1][2],a[1][3]});
	// cout<<ans<<endl;

	// lis ::
	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];

	// vector<int> dp(n,1);
	// fr(i,1,n){
	// 	fr(j,0,i){
	// 		if(v[j]<v[i]){
	// 			dp[i]=max(dp[i],1+dp[j]);
	// 		}
	// 	}
	// }

	// debug(dp)
	// cout<<*max_element(all(dp))<<endl;

	// cout<<dp[n-1]<<endl;

	// vector<int> ans;
	// ans.pb(v[0]);
	// fr(i,1,n){
	// 	if(v[i]>ans.back()) ans.pb(v[i]);
	// 	else{
	// 		int t = lower_bound(all(ans),v[i])-ans.begin();
	// 		ans[t]=v[i];
	// 	}
	// }

	// cout<<ans.sz()<<endl;
	// debug(ans)

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];

	// vector<int> t;
	// t.pb(v[0]);
	// fr(i,1,n){
	// 	if(v[i]>t.back()) t.pb(v[i]);
	// 	else t[lower_bound(t.begin(),t.end(),v[i])-t.begin()]=v[i];
	// 	debug(t)
	// }
	// cout<<t.sz()<<endl;

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	// int k,cin>>k;
	// int ans = f(n-1,v,k);
	// cout<<ans<<endl;

	// -> 2D
	// knapsack
	// int n;cin>>n;
	// int W;cin>>W;
	// vector<int> wt(n),val(n);
	// fr(i,0,n) cin>>wt[i]>>val[i];
	// // fr(i,0,n) cin>>val[i];

	// int ans = f(wt,val,n,W);
	// cout<<ans<<endl;

	// subset sum

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	// int w;cin>>w;

	// // int dp[n+1][w+1];
	// // memset(dp,-1,sizeof dp);

	// int ans = totalsubset(v,n,w);
	// cout<<ans<<endl;

	// // fr(i,0,n+1){
	// // 	fr(j,0,w+1){
	// // 		cout<<dp[i][j]<<" ";
	// // 	}
	// // 	cout<<endl;
	// // }


	// memset(dp,-1,sizeof dp);
	// fr(i,0,n+1){
	// 	fr(j,0,w+1){
	// 		if(i==0) dp[i][j]=0;
	// 		if(j==0) dp[i][j]=1;
	// 	}
	// }

	// fr(i,1,n+1){
	// 	fr(j,1,w+1){
	// 		if(v[i-1]<=j){
	// 			dp[i][j] = dp[i-1][j]+dp[i-1][j-v[i-1]];
	// 		}else{
	// 			dp[i][j] = dp[i-1][j];
	// 		}
	// 	}
	// }

	// fr(i,0,n+1){
	// 	fr(j,0,w+1){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	// cout<<dp[n][w]<<endl;

	// equall partition

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];

	// int s=0;
	// for(auto &e:v) s+=e;

	// debug(s)

	// if(s%2) cout<<"partiton not possible";
	// else{
	// 	int k = s/2;
	// 	int ans = f(v,n,k);
	// 	cout<<ans<<endl;
	// }

	// min subset sum diff
	
	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];

	// int s=0;
	// s=accumulate(all(v),s);

	// memset(dp,-1,sizeof dp);
	// fr(i,0,n+1) fr(j,0,s+1){
	// 	if(i==0) dp[i][j]=0;
	// 	if(j==0) dp[i][j]=1;
	// }
	// int ans = int_max;
	// fr(i,1,n+1){
	// 	fr(j,1,s+1){
	// 		dp[i][j]=dp[i-1][j];
	// 		if(v[i-1]<=j)
	// 			dp[i][j] = dp[i][j] || dp[i-1][j-v[n-1]];
	// 		if(i==n && dp[i][j])
	// 			ans = min(ans,abs(s-2*j));
	// 	}
	// }

	// fr(i,0,n+1){
	// 	fr(j,0,s+1){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	// cout<<ans<<endl;

	// unbounded subset

	// int n;cin>>n;
	// vector<int> wt(n),val(n);
	// fr(i,0,n) cin>>wt[i];
	// fr(i,0,n) cin>>val[i];
	// int w;cin>>w;

	// int ans = f(wt,val,n,w);
	// cout<<ans<<endl;

	// max profit in rod cutting

	// int n;cin>>n;
	// vector<int> val(n);
	// fr(i,0,n) cin>>val[i];

	// int m;cin>>m;
	// vector<int> len(m);
	// fr(i,0,m) cin>>len[i];
	// int l=n;
	// // int ans = f(len,val,n,l);
	// // cout<<ans<<endl;

	// memset(dp,-1,sizeof dp);
	// fr(i,0,n+1) fr(j,0,l+1){
	// 	if(i==0||j==0) dp[i][j]=0;
	// }

	// fr(i,1,n+1){
	// 	fr(j,1,l+1){
	// 		if(len[i-1]<=j)
	// 			dp[i][j] = max(dp[i-1][j],val[i-1]+dp[i][j-len[i-1]]);
	// 		else
	// 			dp[i][j] = dp[i-1][j];
	// 	}
	// }

	// cout<<dp[n][l]<<endl;

	// coin change 1 : max no of ways to form amount x using coins of amount lesser than x (repetive)

	// int n;cin>>n;
	// vector<int> v(n);
	// // set of coins of amount lesser than x
	// fr(i,0,n) cin>>v[i];
	// int x;cin>>x;
	// // vector<int> s;
	// // int ans = f(v,x,n,s);
	// // cout<<ans<<endl;

	// memset(dp,-1,sizeof dp);

	// fr(i,0,n+1) fr(j,0,x+1) {
	// 	if(i==0) dp[i][j]=0;
	// 	if(j==0) dp[i][j]=1;
	// } 

	// fr(i,1,n+1){
	// 	fr(j,1,x+1){
	// 		if(v[i-1]<=j)
	// 			dp[i][j] = dp[i-1][j] + dp[i][j-v[i-1]];
	// 		else
	// 			dp[i][j] = dp[i-1][j];
	// 	}
	// }

	// cout<<dp[n][x]<<endl;

	// coin change 2 : min no of coins to make total change of x

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	// int x;cin>>x;

	// // int ans = f(v,n,x);
	// // cout<<ans<<endl;

	// memset(dp,-1,sizeof dp);
	// fr(i,0,n+1){
	// 	fr(j,0,x+1){
	// 		if(i==0) dp[i][j] = int_max-10;
	// 		if(j==0) dp[i][j] = 0;
	// 	}
	// }

	// for(int i=1,j=1;j<=x;j++){
	// 	if(j%v[i-1]) dp[i][j] = int_max-10;
	// 	else dp[i][j] = j/v[i-1];
	// }

	// fr(i,1,n+1){
	// 	fr(j,1,x+1){
	// 		if(v[i-1]<=j){
	// 			dp[i][j] = min(dp[i-1][j],1+dp[i][j-v[i-1]]);
	// 		}else{
	// 			dp[i][j] = dp[i-1][j];
	// 		}
	// 	}
	// }

	// cout<<dp[n][x]<<endl;

	// string a,b;cin>>a>>b;
	// int ans = f(a,b,a.sz(),b.sz());
	
	// fr(i,0,a.sz()+1){
	// 	fr(j,0,b.sz()+1){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	// int ans = int_min;
	// fr(i,1,a.sz()+1){
	// 	fr(j,1,b.sz()+1){
	// 		int x = f(a,b,i,j);
	// 		ans = max(ans,x);
	// 		debug(mp(mp(ans,x),mp(i,j)))
	// 	}
	// }
	// cout<<ans<<endl;

	// *******************************
	// int ans = f(a,b,a.sz(),b.sz(),0);
	// cout<<ans<<endl;
	// *******************************

	// memset(dp,-1,sizeof dp);
	// fr(i,0,a.sz()+1){
	// 	fr(j,0,b.sz()+1){
	// 		if(i==0||j==0) dp[i][j]=0;
	// 	}
	// }

	// int ans = 1;

	// fr(i,1,a.sz()+1){
	// 	fr(j,1,b.sz()+1){
	// 		if(a[i-1]==b[j-1])
	// 			dp[i][j] = 1+dp[i-1][j-1];
	// 		else
	// 			dp[i][j] = 0;
	// 		ans = max(ans,dp[i][j]);
	// 	}
	// }

	// cout<<ans<<endl;

	// // print 1
	// string a,b;
	// cin>>a>>b;
	// int n = a.sz(),m = b.sz();

	// memset(dp,-1,sizeof dp);
	// fr(i,0,n+1){
	// 	fr(j,0,m+1){
	// 		if(i==0||j==0) dp[i][j]=0;
	// 	}
	// }

	// fr(i,1,n+1){
	// 	fr(j,1,m+1){
	// 		if(a[i-1]==b[j-1])
	// 			dp[i][j] = 1+dp[i-1][j-1];
	// 		else
	// 			dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
	// 	}
	// }

	// // cout<<dp[n][m]<<endl;
	// int i=n,j=m;
	// string ans = "";
	// while(i && j){
	// 	if(a[i-1]==b[j-1]){
	// 		ans.pb(a[i-1]);
	// 		i--,j--;
	// 	}
	// 	else{
	// 		if(dp[i-1][j]>dp[i][j-1])
	// 			i--;
	// 		else
	// 			j--;
	// 	}
	// }

	// reverse(all(ans));
	// cout<<ans<<endl;

	// print 2
	// string a,b;
	// cin>>a>>b;
	// int n = a.sz(),m = b.sz();

	// memset(dp,-1,sizeof dp);
	// fr(i,0,n+1){
	// 	fr(j,0,m+1){
	// 		if(i==0||j==0) dp[i][j]=0;
	// 	}
	// }
	
	// int ans = int_min;
	// int ii=-1,jj=-1;
	// fr(i,1,n+1){
	// 	fr(j,1,m+1){
	// 		if(a[i-1]==b[j-1])
	// 			dp[i][j] = 1+dp[i-1][j-1];
	// 		else
	// 			dp[i][j] = 0;
	// 		if(dp[i][j]>ans){
	// 			ans = dp[i][j];
	// 			ii=i;
	// 			jj=j;
	// 		}
	// 	}
	// }

	// debug(mp(ii,jj));
	// cout<<ans<<endl;
	// string s="";
	// while(ii && jj){
	// 	if(a[ii-1]==b[jj-1]){
	// 		s.pb(a[ii-1]);
	// 		ii--,jj--;
	// 	}else{
	// 		break;
	// 	}
	// }

	// reverse(all(s));
	// cout<<s<<endl;

	// scs
	
	// string a,b;cin>>a>>b;
	// int n = a.sz(),m = b.sz();

	// memset(dp,-1,sizeof dp);
	// fr(i,0,n+1) fr(j,0,m+1){
	// 	if(i==0||j==0) dp[i][j]=0;
	// }

	// fr(i,1,n+1){
	// 	fr(j,1,m+1){
	// 		if(a[i-1]==b[j-1])
	// 			dp[i][j]=1+dp[i-1][j-1];
	// 		else
	// 			dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
	// 	}
	// }

	// cout<<n+m-dp[n][m]<<endl;

	// int i=n,j=m;
	// string ans="";
	// while(i>0 && j>0){
	// 	if(a[i-1]==b[j-1]){
	// 		ans.pb(a[i-1]);
	// 		i--,j--;
	// 	}else{
	// 		if(dp[i][j-1]>dp[i-1][j]){
	// 			ans.pb(b[j-1]);
	// 			j--;
	// 		}else{
	// 			ans.pb(a[i-1]);
	// 			i--;
	// 		}
	// 	}
	// }

	// while(i>0){
	// 	ans.pb(a[i-1]);
	// 	i--;
	// }

	// while(j>0){
	// 	ans.pb(b[j-1]);
	// 	j--;
	// }

	// reverse(all(ans));
	// cout<<ans<<endl;

	// lrs
	// string s;cin>>s;
	// int n = s.sz();
	// // int ans = f(s,n,n);
	// // cout<<ans<<endl;
	// memset(dp,-1,sizeof dp);

	// for(int i=0;i<n+1;i++){
	// 	for(int j=0;j<n+1;j++){
	// 		if(i==0||j==0) dp[i][j]=0;
	// 	}
	// }

	// for(int i=1;i<n+1;i++){
	// 	for(int j=1;j<n+1;j++){
	// 		if(i!=j && s[i-1]==s[j-1])
	// 			dp[i][j]=1+dp[i-1][j-1];
	// 		else
	// 			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	// 	}
	// }

	// cout<<dp[n][n]<<endl;

	// string ans="";
	// int i,j;i=j=n;
	// while(i && j){
	// 	if(dp[i][j]==1+dp[i-1][j-1]){
	// 		ans.pb(s[i-1]);
	// 		i--,j--;
	// 	}
	// 	else if(dp[i][j]==dp[i-1][j])
	// 		i--;
	// 	else
	// 		j--;
	// }

	// reverse(all(ans));
	// cout<<ans<<endl;




	

	// **distinct occurence of string b as subsequence in a

	// string a,b;cin>>a>>b;
	// int n = a.sz() , m = b.sz();

	// // int ans = f(a,b,n,m);
	// // cout<<ans<<endl;
	// memset(dp,-1,sizeof dp);

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

	// total paths in grid of n x m
	// int n,m;cin>>n>>m;
	// int ans = f(n-1,m-1);
	// cout<<ans<<endl;

	// int ans=1;
	// for(int i=n;i<=(m+n-2);i++){
	// 	ans *= i;
	// 	ans /= (i-n+1);
	// }
	// cout<<ans<<endl;

	// total no of paths on n x m grid with obstacles as -1 on grid

	// int n,m;cin>>n>>m;
	// vector<vector<int>> a(n,vector<int>(m));
	// fr(i,0,n) fr(j,0,m) cin>>a[i][j];

	// int ans = f(n-1,m-1,a);
	// cout<<ans<<endl;

	// memset(dp,-1,sizeof dp);
	// dp[0][0]=1;

	// fr(j,1,m){
	// 	if(a[0][j]!=-1)
	// 		dp[0][j]=1;
	// 	else
	// 		break;
	// }

	// fr(i,1,n){
	// 	if(a[i][0]!=-1)
	// 		dp[i][0]=1;
	// 	else
	// 		break;
	// }

	// fr(i,1,n){
	// 	fr(j,1,m){
	// 		if(a[i][j]!=-1)
	// 			dp[i][j]=dp[i-1][j]+dp[i][j-1];
	// 	}
	// }

	// cout<<dp[n-1][m-1]<<endl;

	// fr(i,0,n){
	// 	fr(j,0,m){
	// 		if(a[i][j]==-1) dp[i][j]=0;
	// 		else if(i==0 && j==0 && a[i][j]!=-1) dp[i][j]=1;
	// 		else{
	// 			dp[i][j]=0;
	// 			if(i-1>=0) dp[i][j]+=dp[i-1][j];
	// 			if(j-1>=0) dp[i][j]+=dp[i][j-1];
	// 		}
	// 	}
	// }

	// fr(i,0,n){
	// 	fr(j,0,m){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	// cout<<dp[n-1][m-1]<<endl;

	// min cost to reach n-1,m-1 from 0,0

	// int n,m;cin>>n>>m;
	// vector<vector<int>> a(n,vector<int>(m));
	// fr(i,0,n) fr(j,0,m) cin>>a[i][j];

	// int ans = f(n-1,m-1,a);
	// cout<<ans<<endl;

	// fr(i,1,n)
	// 	a[i][0]+=a[i-1][0];
	// fr(j,1,m)
	// 	a[0][j]+=a[0][j-1];

	// fr(i,1,n){
	// 	fr(j,1,m){
	// 		a[i][j] += min(a[i-1][j],a[i][j-1]);
	// 	}
	// }
	// fr(i,0,n){
	// 	fr(j,0,m){
	// 		cout<<a[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	// cout<<a[n-1][m-1]<<endl;

	// min falling path sum in triangle

	// int n;cin>>n;
	// vector<vector<int>> a;
	// fr(i,0,n){
	// 	vector<int> t;
	// 	// t.pb(int_max);
	// 	fr(j,0,i+1){
	// 		int x;cin>>x;
	// 		t.pb(x);
	// 	}
	// 	// t.pb(int_max);
	// 	a.pb(t);
	// }

	// int ans = f(0,0,n,a);
	// cout<<ans<<endl;

	// int ans = int_max;
	// fr(i,1,n){
	// 	fr(j,1,i+2){
	// 		a[i][j]+=min(a[i-1][j],a[i-1][j-1]);
	// 		if(i==n-1)
	// 			ans = min(ans,a[i][j]);
	// 	}
	// }

	// fr(i,0,n){
	// 	fr(j,0,i+3){
	// 		cout<<a[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	// cout<<ans<<endl;

	// for(int i=n-2;i>=0;i--){
	// 	fr(j,0,i+1){
	// 		a[i][j]+=min(a[i+1][j],a[i+1][j+1]);
	// 	}
	// }
	// fr(i,0,n){
	// 	fr(j,0,i+1){
	// 		cout<<a[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	// cout<<a[0][0]<<endl;

	// max falling sum in grid
	
	// int n,m;cin>>n>>m;
	// debug(mp(n,m))
	// vector<vector<int>> a(n,vector<int>(m,0));
	// fr(i,0,n){
	// 	fr(j,0,m){
	// 		cin>>a[i][j];
	// 	}
	// }

	// fr(i,0,n){
	// 	fr(j,0,m){
	// 		cout<<a[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	// cout<<endl;
	
	// memset(dp,-1,sizeof dp);
	
	// int ans1 = int_min;
	// fr(j,0,m){
	// 	ans1 = max(ans1,f(n-1,j,a));
	// }
	// cout<<f(0,0,a,m,n)<<" "<<f(0,1,a,m,n)<<" "<<f(0,2,a,m,n)<<" "<<f(0,3,a,m,n)<<" "<<f(0,4,a,m,n)<<" "<<f(0,5,a,m,n)<<endl;   

	// fr(i,0,n){
	// 	fr(j,0,m){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	// cout<<ans1<<endl;

	// int ans = int_min;
	// fr(i,1,n){
	// 	fr(j,0,m){
	// 		int x,y,z;
	// 		x=y=z=0;
	// 		if(j-1>=0) x=a[i-1][j-1];
	// 		if(j>=0) y=a[i-1][j];
	// 		if(j+1<=m-1) z=a[i-1][j+1];
	// 		debug(mp(x,mp(y,z)));
	// 		a[i][j] += max({x,y,z});
	// 		ans = max(ans,a[i][j]);
	// 	}
	// }
	// cout<<ans<<endl;

	// fr(i,0,n){
	// 	fr(j,0,m){
	// 		cout<<a[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

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
	// 		ans = max(ans,dp[i][j]);
	// 	}
	// }
	// cout<<ans<<endl;

	// **max fall path sum for 2 fixed starting point and atmost 2 variable ending point

	// int n,m;cin>>n>>m;
	// vector<vector<int>> a(n,vector<int>(m,0));
	// fr(i,0,n) fr(j,0,m) cin>>a[i][j];
		
	// int ans = f(0,0,m-1,n,m,a);
	// cout<<ans<<endl;

	// memset(dp,-1,sizeof dp);

	// fr(j1,0,m) fr(j2,0,m){
	// 	if(j1==j2) dp[n-1][j1][j2] = a[n-1][j1];
	// 	else dp[n-1][j1][j2] = a[n-1][j1]+a[n-1][j2];
	// }

	// for(int i=n-2;i>=0;i--){
	// 	for(int j1=0;j1<m;j1++){
	// 		for(int j2=0;j2<m;j2++){
	// 			dp[i][j1][j2]=int_min;
	// 			for(int x=-1;x<=1;x++){
	// 				for(int y=-1;y<=1;y++){
	// 					int v=0;
	// 					if(j1==j2) v=a[i][j1];
	// 					else v=a[i][j1]+a[i][j2];
	// 					if(j1+x>=0 && j2+y>=0 && j1+x<m && j2+y<m)
	// 						v+=dp[i+1][j1+x][j2+y];
	// 					else
	// 						v=int_min;
	// 					dp[i][j1][j2]=max(v,dp[i][j1][j2]);
	// 				}
	// 			}
	// 		}
	// 	}
	// }

	// cout<<dp[0][0][m-1]<<endl;

	// string a,b;cin>>a>>b;
	// int n=a.sz(),m=b.sz();

	// // int ans = f(a,b,n,m);
	// // cout<<ans<<endl;

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

	// string a,b;cin>>a>>b;
	// int n=a.sz(),m=b.sz();

	// // bool ans = f(a,b,n,m);
	// // cout<<ans<<endl;

	// memset(dp,-1,sizeof dp);

	// fr(i,0,n+1){
	// 	fr(j,0,m+1){
	// 		if(i==0 && j==0) dp[i][j]=1;
	// 		if(i==0 && j>0) dp[i][j]=0;
	// 		if(j==0 && i>0) dp[i][j] = dp[i-1][j]*a[i-1]=='*';
	// 	}
	// }

	// fr(i,1,n+1){
	// 	fr(j,1,m+1){
	// 		dp[i][j]=0;
	// 		if(a[i-1]==b[j-1] || a[i-1]=='?')
	// 			dp[i][j] = dp[i][j] | dp[i-1][j-1];
	// 		else if(a[i-1]=='*')
	// 			dp[i][j] = dp[i][j] | dp[i-1][j] | dp[i][j-1];
	// 	}
	// }

	// cout<<dp[n][m]<<endl;

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];

	// int minbuy = int_max;
	// int ans = int_min;
	// fr(i,0,n){
	// 	ans = max(ans,v[i]-minbuy);
	// 	minbuy = min(minbuy,v[i]);
	// 	debug(mp(ans,minbuy));
	// }

	// int ans = f(0,1,v);
	// cout<<ans<<endl;

	// vector<vector<int>> dp(n+1,vector<int>(2,0));

	// dp[n][1]=dp[n][0]=0;
	// for(int i=n-1;i>=0;i--){
	// 	for(int b=0;b<=1;b++){
	// 		if(b){
	// 			dp[i][b] = max(dp[i+1][b],-v[i]+dp[i+1][!b]);
	// 		}else{
	// 			dp[i][b] = max(dp[i+1][b],v[i]+dp[i+1][!b]);
	// 		}
	// 	}
	// }

	// cout<<dp[0][1]<<endl;

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	// int k;cin>>k;

	// // int ans = f(0,1,k,v);
	// // cout<<ans<<endl;

	// vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
	// fr(i,0,n+1) fr(b,0,2) fr(j,0,k+1) if(i==n||j==0) dp[i][b][j]=0;

	// rf(i,n-1,-1){
	// 	fr(b,0,2){
	// 		fr(j,1,k+1){
	// 			if(b){
	// 				dp[i][1][j] = max(dp[i+1][1][j],-v[i]+dp[i+1][0][j]);
	// 			}else{
	// 				dp[i][0][j] = max(dp[i+1][0][j],v[i]+dp[i+1][1][j-1]);
	// 			}
	// 		}
	// 	}
	// }

	// cout<<dp[0][1][k]<<endl;

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];

	// // int ans = f(0,1,v);
	// // cout<<ans<<endl;

	// vector<vector<int>> dp(n+2,vector<int>(2,0));

	// fr(i,0,n+2) fr(b,0,2) if(i>=n) dp[i][b]=0;

	// rf(i,n-1,-1){
	// 	fr(b,0,2){
	// 		if(b)
	// 			dp[i][b] = max(dp[i+1][b],-v[i]+dp[i+1][!b]);
	// 		else
	// 			dp[i][b] = max(dp[i+1][b],v[i]+dp[i+2][!b]);
	// 	}
	// }

	// cout<<dp[0][1]<<endl;

	// mcm

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	// // int ans = f(1,n-1,v);
	// // cout<<ans<<endl;

	// vector<vector<int>> dp(n,vector<int>(n,int_max));
	// fr(i,0,n) dp[i][i]=0;
	// for(int i=n-2;i>=0;i--){
	// 	for(int j=i+1;j<n;j++){
	// 		dp[i][j]=int_max;
	// 		for(int k=i;k<j;k++){
	// 			dp[i][j]=min(dp[i][j],v[i-1]*v[k]*v[j]+dp[i][k]+dp[k+1][j]);
	// 		}
	// 	}
	// }
	// cout<<dp[1][n-1]<<endl;

	// string s;cin>>s;
	// // int ans = f(0,s.sz()-1,s);
	// // cout<<ans<<endl;

	// vector<vector<int>> dp(s.sz(),vector<int>(s.sz(),int_max));
	// fr(i,0,s.sz()) fr(j,0,s.sz()) if(i>=j||isp(s,i,j)) dp[i][j]=0;

	// for(int i=s.sz()-1;i>=0;i--){
	// 	for(int j=i+1;j<s.sz();j++){
	// 		for(int k=i;k<j;k++){
	// 			dp[i][j]=min(dp[i][j],1+dp[i][k]+dp[k+1][j]);
	// 		}
	// 	}
	// }

	// cout<<dp[0][s.sz()-1]<<endl;

	// string s;cin>>s;
	// // int ans = f(s,0,s.sz()-1,1);
	// // cout<<ans<<endl;

	// int n = s.sz();
	// vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,0)));

	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<n;j++){
	// 		for(int b=0;b<2;b++){
	// 			if(i>j) dp[i][j][0]=dp[i][j][1]=0;
	// 			if(i==j){
	// 				if(b) dp[i][j][b] = (s[i]=='T');
	// 				else dp[i][j][b] = (s[i]=='F');
	// 			}
	// 		}
	// 	}
	// }

	// for(int i=n-1;i>=0;i--){
	// 	for(int j=i+1;j<n;j++){
	// 		for(int b=0;b<2;b++){
	// 			dp[i][j][b]=0;
	// 			for(int k=i+1;k<=j-1;k+=2){
	// 				int lt,lf,rt,rf;
	// 				lt = dp[i][k-1][1];
	// 				lf = dp[i][k-1][0];
	// 				rt = dp[k+1][j][1];
	// 				rf = dp[k+1][j][0];
	// 				if(s[k]=='&'){
	// 					if(b) dp[i][j][b] += lt*rt;
	// 					else dp[i][j][b] += lt*rf + lf*rt + lf*rf;
	// 				}else if(s[k]=='^'){
	// 					if(b) dp[i][j][b] += lt*rf + rt*lf;
	// 					else dp[i][j][b] += lt*rt + lf*rf;
	// 				}else if(s[k]=='|'){
	// 					if(b) dp[i][j][b] += lt*rt + lf*rt + rf*lt;
	// 					else dp[i][j][b] += lf*rf;
	// 				}
	// 			}
	// 		}
	// 	}
	// }

	// cout<<dp[0][n-1][1];

	// string a,b;cin>>a>>b;
	// bool ans = f(a,b);
	// cout<<ans<<endl;

	// int E,F;cin>>E>>F;
	// // int ans = ff(e,f);
	// // cout<<ans<<endl;

	// vector<vector<int>> dp(E+1,vector<int>(F+1,0));

	// fr(i,0,E+1) fr(j,0,F+1) if(i==1||j==0||j==1) dp[i][j]=j;

	// fr(e,2,E+1){
	// 	fr(f,2,F+1){
	// 		dp[e][f]=int_max;
	// 		fr(i,1,f+1)
	// 			dp[e][f]=min(dp[e][f],1+max(dp[e-1][i-1],dp[e][f-i]));
	// 	}
	// }

	// cout<<dp[E][F]<<endl;

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