#include <bits/stdc++.h>
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

#ifndef ONLINE_JUDGE
#define debugd(x,a,b) cerr<<#x<<" "; __print(x,a,b); cerr<<endl;
#else
#define debugd(x)
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

const int N = 1e4+1;
int dp[N][N];

// int fib(int n){
// 	if(n==0||n==1) return n;
// 	return fib(n-1)+fib(n-2);
// }

// int fib(int n){
// 	if(n==1||n==0) return n;
// 	if(dp[n]!=-1) return dp[n];
// 	return dp[n]=fib(n-1)+fib(n-2);
// }

// int find(int n,vector<int>& v){
// 	if(n==0||n==1) return v[n];
// 	return v[n]+min(find(n-1,v),find(n-2,v));
// }

// int find(int n,vector<int> v){
// 	if(n==0||n==1) return v[n];
// 	if(dp[n]!=-1) return dp[n];
// 	return dp[n] = v[n]+min(find(n-1,v),find(n-2,v));
// }

// int mincoins(vector<int>& v,int w){
// 	// debug(w)
// 	if(w==0) return 0;
// 	if(w<0) return int_max;
// 	int ans = int_max;
// 	fr(i,0,v.sz()){
// 		int t = mincoins(v,w-v[i]);
// 		if(t!=int_max) ans = min(ans,1+t);
// 	}
// 	return ans;
// }

// int maxnonadjsum(vector<int>& v,int i){
// 	if(i<0) return 0;
// 	if(i==0) return v[0];
// 	return max(v[i]+maxnonadjsum(v,i-2),maxnonadjsum(v,i-1));
// }

// int maxnonadjsummem(vector<int>& v,int i){
// 	if(i<0) return 0;
// 	if(i==0) return v[0];
// 	if(dp[i]!=-1) return dp[i];
// 	return dp[i]=max(v[i]+maxnonadjsummem(v,i-2),maxnonadjsummem(v,i-1));
// }

// int f(vector<int> v,int i){
// 	if(i<0) return 0;
// 	if(i==0) return v[0];
// 	if(dp[i]!=-1) return dp[i];
// 	return dp[i] = max(v[i]+f(v,i-2),f(v,i-1));
// }

// int cutrod3(int n,int x,int y,int z){
// 	if(n<0) return int_min;
// 	if(n==0) return 0;

// 	int X = 1+cutrod3(n-x,x,y,z);
// 	int Y = 1+cutrod3(n-y,x,y,z);
// 	int Z = 1+cutrod3(n-z,x,y,z);

// 	return max(X,max(Y,Z)); 
// }

// int cutrod3mem(int n,int x,int y,int z){
// 	if(n<0) return int_min;
// 	if(n==0) return 0;
// 	if(dp[n]!=-1) return dp[n];
// 	int X = 1+cutrod3mem(n-x,x,y,z);
// 	int Y = 1+cutrod3mem(n-y,x,y,z);
// 	int Z = 1+cutrod3mem(n-z,x,y,z);

// 	return dp[n]=max(X,max(Y,Z)); 
// }

// int derangements(int n){
// 	if(n==1 || n==2) return n-1;
// 	return (n-1)*(derangements(n-2)+derangements(n-1)); 
// }

// int derangemem(int n){
// 	if(n==1||n==2) return n-1;
// 	if(dp[n]!=-1) return dp[n];
// 	return dp[n] = (n-1)*(derangemem(n-1)+derangemem(n-2));
// }

// int paintfence(int n,int k){
// 	if(n==1 || n==2) return pow(k,n);
// 	return (k-1)*(paintfence(n-1,k)+paintfence(n-2,k));  
// }

// int paintfencemem(int n,int k){
// 	if(n==1 || n==2) return pow(k,n);
// 	if(dp[n]!=-1) return dp[n];
// 	return dp[n]=(k-1)*(paintfencemem(n-1,k)+paintfencemem(n-2,k));  
// }

// int f(vector<vector<int>> a,int day,int x,int n){
// 	if(day==n) return 0;
// 	int ans = int_min;
// 	for(int flag=1;flag<=3;flag++){
// 		if(flag==x) continue;
// 		ans = max(ans,a[day][flag]+f(a,day+1,flag,n));
// 	}
// 	return ans;
// }

// int f(vector<vector<int>> a,int day,int x,int n){
// 	if(day==n) return 0;
// 	if(dp[day][x]!=-1) return dp[day][x];
// 	int ans = int_min;
// 	for(int flag=1;flag<=3;flag++){
// 		if(flag==x) continue;
// 		ans = max(ans,a[day][flag]+f(a,day+1,flag,n));
// 	}
// 	return dp[day][x]=ans;
// }

// int f(vector<vector<int>> a,int n,int day,int arrno){
// 	if(day==n+1) return 0;
// 	int ans=int_min;

// 	for(int ano=1;ano<=3;ano++){
// 		if(ano==arrno) continue;
// 		ans = max(ans,a[day][ano]+f(a,n,day+1,ano));
// 	} 

// 	return ans;
// }

// int f(vector<vector<int>> a,int n,int day,int arrno){
// 	if(day==n+1) return 0;
// 	if(dp[day][arrno]!=-1) return dp[day][arrno];
// 	int ans=int_min;

// 	for(int ano=1;ano<=3;ano++){
// 		if(ano==arrno) continue;
// 		ans = max(ans,a[day][ano]+f(a,n,day+1,ano));
// 	} 

// 	return dp[day][arrno]=ans;
// }

// int frog1(vector<int> v,int i){
// 	if(i==0) return 0;
// 	if(i==1) return abs(v[0]-v[1]);

// 	else return min(abs(v[i]-v[i-1])+frog1(v,i-1),abs(v[i]-v[i-2])+frog1(v,i-2));
// }

// int frog1mem(vector<int> v,int i){
// 	if(i==0) return 0;
// 	if(i==1) return abs(v[0]-v[1]);
// 	if(dp[i]!=-1) return dp[i];

// 	else return dp[i]=min(abs(v[i]-v[i-1])+frog1mem(v,i-1),abs(v[i]-v[i-2])+frog1mem(v,i-2));
// }

// int frog2(vector<int> v,int i,int k){
// 	if(i==0) return 0;
// 	if(i==1) return abs(v[1]-v[0]);

// 	int ans = int_max;

// 	fr(j,1,k+1){
// 		if(i-j>=0)
// 			ans = min(ans,abs(v[i]-v[i-j])+frog2(v,i-j,k));
// 	}

// 	return ans;
// }

// int frog2mem(vector<int> v,int i,int k){
// 	if(i==0) return 0;
// 	if(i==1) return abs(v[1]-v[0]);
// 	if(dp[i]!=-1) return dp[i];
// 	int ans = int_max;

// 	fr(j,1,k+1){
// 		if(i-j>=0)
// 			ans = min(ans,abs(v[i]-v[i-j])+frog2mem(v,i-j,k));
// 	}

// 	return dp[i]=ans;
// }

// // ***********************************************************************************************************************************************
// // ***********************************************************************************************************************************************

// int knapsack(vector<int> wt,vector<int> val,int w,int n){
// 	if(w==0||n==0) return 0;
// 	if(wt[n-1]<=w)
// 		return max(knapsack(wt,val,w,n-1),val[n-1]+knapsack(wt,val,w-wt[n-1],n-1));
// 	return knapsack(wt,val,w,n-1);
// }

// int knapsackmem(vector<int> wt,vector<int> val,int w,int n){
// 	if(w==0||n==0) return 0;
// 	if(dp[n][w]!=-1) return dp[n][w];
// 	// total (n+1)*(w+1) dp size will be used; 
// 	if(wt[n-1]<=w)
// 		return dp[n][w]=max(knapsackmem(wt,val,w,n-1),val[n-1]+knapsackmem(wt,val,w-wt[n-1],n-1));
// 	return dp[n][w]=knapsackmem(wt,val,w,n-1);
// }

// bool subsetsum(vector<int> v,int n,int w){
// 	if(w==0) return true;
// 	if(n==0 && w!=0) return false;
// 	bool b = false;
// 	if(v[n-1]<=w){
// 		b = subsetsum(v,n-1,w)||subsetsum(v,n-1,w-v[n-1]);
// 	}else{
// 		b = subsetsum(v,n-1,w);
// 	}
// 	return b;
// }

// bool subsetsummem(vector<int> v,int n,int w){
// 	if(w==0) return true;
// 	if(n==0 && w!=0) return false;
// 	if(dp[n][w]!=-1) return dp[n][w];
// 	bool b = false;
// 	if(v[n-1]<=w){
// 		b = subsetsummem(v,n-1,w)||subsetsummem(v,n-1,w-v[n-1]);
// 	}else{
// 		b = subsetsummem(v,n-1,w);
// 	}
// 	return dp[n][w]=b;
// }

// int totalsubset(vector<int> v,int n,int w){
// 	if(w==0) return 1;
// 	if(n==0 && w!=0) return 0;
// 	int ans = 0;
// 	if(v[n-1]<=w)
// 		ans = totalsubset(v,n-1,w)+totalsubset(v,n-1,w-v[n-1]);
// 	else
// 		ans = totalsubset(v,n-1,w);
// 	return ans;
// }

// int totalsubsetmem(vector<int> v,int n,int w){
// 	if(w==0) return 1;
// 	if(n==0 && w!=0) return 0;
// 	if(dp[n][w]!=-1) return dp[n][w];
// 	int ans = 0;
// 	if(v[n-1]<=w)
// 		ans = totalsubsetmem(v,n-1,w)+totalsubsetmem(v,n-1,w-v[n-1]);
// 	else
// 		ans = totalsubsetmem(v,n-1,w);
// 	return dp[n][w] = ans;
// }

// int subsetss(vector<int> v,int n,int w){
// 	if(w==0) return 1;
// 	if(w!=0 &&n==0) return 0;
// 	if(dp[n][w]!=-1) return dp[n][w];
// 	int ans = 0;
// 	if(v[n-1]<=w)
// 		ans = subsetss(v,n-1,w) + subsetss(v,n-1,w-v[n-1]);
// 	else 
// 		ans = subsetss(v,n-1,w);
// 	return dp[n][w] = ans;
// }

// int ubknapsack(vector<int> wt,vector<int> val,int n,int w){
// 	if(w==0||n==0) return 0;
// 	if(wt[n-1]<=w){
// 		return max(ubknapsack(wt,val,n-1,w),val[n-1]+ubknapsack(wt,val,n,w-wt[n-1]));
// 	}
// 	else 
// 		return ubknapsack(wt,val,n-1,w);
// }

// int ubknapsackmem(vector<int> wt,vector<int> val,int n,int w){
// 	if(w==0||n==0) return 0;
// 	if(dp[n][w]!=-1) return dp[n][w];
// 	if(wt[n-1]<=w){
// 		return dp[n][w]=max(ubknapsackmem(wt,val,n-1,w),val[n-1]+ubknapsackmem(wt,val,n,w-wt[n-1]));
// 	}
// 	else 
// 		return dp[n][w]=ubknapsackmem(wt,val,n-1,w);
// }

// int countwayscoin(vector<int> v,int n,int w){
// 	if(w==0) return 1;
// 	if(n==0 && w!=0) return 0;
// 	if(v[n-1]<=w)
// 		return (countwayscoin(v,n-1,w)+countwayscoin(v,n,w-v[n-1]));
// 	else 
// 		return countwayscoin(v,n-1,w);
// }

// int countwayscoinmem(vector<int> v,int n,int w){
// 	if(w==0) return 1;
// 	if(n==0 && w!=0) return 0;
// 	if(dp[n][w]!=-1) return dp[n][w];
// 	if(v[n-1]<=w)
// 		return dp[n][w]=(countwayscoinmem(v,n-1,w)+countwayscoinmem(v,n,w-v[n-1]));
// 	else 
// 		return dp[n][w]=countwayscoinmem(v,n-1,w);
// }

// int mincoins(vector<int> v,int n,int w){
// 	debug(mp(n,w))
// 	if(w==0) return 0;
// 	if(n==0 && w!=0) return int_max-10;
// 	if(n==1){
// 		if( w%v[0] ==0) return w/v[0];
// 		else return int_max-10;
// 	}
// 	if(v[n-1]<=w)
// 		return min(mincoins(v,n-1,w),1+mincoins(v,n,w-v[n-1]));
// 	else
// 		return mincoins(v,n-1,w);
// }

// int mincoinsmem(vector<int> v,int n,int w){
// 	debug(mp(n,w))
// 	if(w==0) return 0;
// 	if(n==0 && w!=0) return int_max-10;
// 	if(n==1){
// 		if( w%v[0] ==0) return w/v[0];
// 		else return int_max-10;
// 	}
// 	if(dp[n][w]!=-1) return dp[n][w];
// 	if(v[n-1]<=w)
// 		return dp[n][w]=min(mincoins(v,n-1,w),1+mincoins(v,n,w-v[n-1]));
// 	else
// 		return dp[n][w]=mincoins(v,n-1,w);
// }


// int lcsubseq(string a,string b,int n,int m){
// 	if(n==0||m==0) return 0;
// 	if(a[n-1]==b[m-1])
// 		return 1+lcsubseq(a,b,n-1,m-1);
// 	else 
// 		return max(lcsubseq(a,b,n-1,m),lcsubseq(a,b,n,m-1));
// }

// int lcsubseqmem(string a,string b,int n,int m){
// 	if(n==0||m==0) return 0;
// 	if(dp[n][m]!=-1) return dp[n][m];
// 	if(a[n-1]==b[m-1])
// 		return dp[n][m]=1+lcsubseqmem(a,b,n-1,m-1);
// 	else 
// 		return dp[n][m]=max(lcsubseqmem(a,b,n-1,m),lcsubseqmem(a,b,n,m-1));
// }

// int lrsubseq(string a,int n,int m){
// 	if(n==0||m==0) return 0;
// 	if(n!=m && a[n-1]==a[m-1])
// 		return 1+lrsubseq(a,n-1,m-1);
// 	else
// 		return max(lrsubseq(a,n-1,m),lrsubseq(a,n,m-1));
// }

// int lrsubseqmem(string a,int n,int m){
// 	if(n==0||m==0) return 0;
// 	if(dp[n][m]!=-1) return dp[n][m];
// 	if(n!=m && a[n-1]==a[m-1])
// 		return dp[n][m]=1+lrsubseqmem(a,n-1,m-1);
// 	else
// 		return dp[n][m]=max(lrsubseqmem(a,n-1,m),lrsubseqmem(a,n,m-1));
// }

// int mcm(vector<int>& v,int i,int j){
// 	if(i>=j) return 0;
// 	int ans = int_max;
// 	for(int k=i;k<=j-1;k++){
// 		ans = min(ans,mcm(v,i,k)+mcm(v,k+1,j)+v[i-1]*v[k]*v[j]);
// 	}
// 	return ans;
// }

// int mcmmem(vector<int>& v,int i,int j){
// 	if(i>=j) return 0;
// 	if(dp[i][j]!=-1) return dp[i][j];
// 	int ans = int_max;
// 	for(int k=i;k<=j-1;k++){
// 		ans = min(ans,mcmmem(v,i,k)+mcmmem(v,k+1,j)+v[i-1]*v[k]*v[j]);
// 	}
// 	return dp[i][j]=ans;
// }

// bool isp(string s,int i,int j){
// 	while(i<j){
// 		if(s[i]!=s[j]) return 0;
// 		else i++,j--;
// 	}
// 	return 1;
// }

// int pp(string s,int i,int j){
// 	if(i>=j || isp(s,i,j)) return 0;
// 	int ans = int_max;
// 	for(int k=i;k<j;k++)
// 		ans = min(ans,1+pp(s,i,k)+pp(s,k+1,j));
// 	return ans;
// }

// int ppmem(string s,int i,int j){
// 	if(i>=j || isp(s,i,j)) return 0;
// 	if(dp[i][j]!=-1) return dp[i][j];
// 	int ans = int_max;
// 	for(int k=i;k<j;k++)
// 		ans = min(ans,1+ppmem(s,i,k)+ppmem(s,k+1,j));
// 	return dp[i][j] = ans;
// }

// int ppmemopt(string s,int i,int j){
// 	if(i>=j || isp(s,i,j)) return 0;
// 	if(dp[i][j]!=-1) return dp[i][j];
// 	int ans = int_max;
// 	for(int k=i;k<j;k++){
// 		int l,r;
// 		if(dp[i][k]!=-1) l = dp[i][k];
// 		else{
// 			l = ppmemopt(s,i,k);
// 			dp[i][k] = l;
// 		}
// 		if(dp[k+1][j]!=-1) r = dp[k+1][j];
// 		else{
// 			r = ppmemopt(s,k+1,j);
// 			dp[k+1][j] = r;
// 		}
// 		ans = min(ans,1+l+r);
// 	}
// 	return dp[i][j] = ans;
// }

int evaltrue(string s,int i,int j,bool b){
	if(i>j) return 0;
	if(i==j){
		if(b) return s[i]=='T';
		else return s[i]=='F';
	}
	int ans=0;
	for(int k=i+1;k<j;k+=2){
		int lt = evaltrue(s,i,k-1,1);
		int lf = evaltrue(s,i,k-1,0);
		int rt = evaltrue(s,k+1,j,1);
		int rf = evaltrue(s,k+1,j,0);

		if(s[k]=='&'){
			if(b){
				ans += lt*rt;
			}else{
				ans += lf*rt + lt*rf + lf*rf;
			}
		}else if(s[k]=='|'){
			if(b){
				ans += lt*rt + lt*rf + lf*rt;
			}else{
				ans += lf*rf;
			}
		}else if(s[k]=='^'){
			if(b){
				ans += lt*rf + lf*rt;
			}else{
				ans += lt*rt + lf*rf;
			}
		}
	}
	return ans;
}

// int evaltruemem(string s,int i,int j,bool b){
// 	if(i>j) return 0;
// 	if(i==j){
// 		if(b) return s[i]=='T';
// 		else return s[i]=='F';
// 	}
// 	if(dp[i][j][b]!=-1) return dp[i][j][b];
// 	int ans=0;
// 	for(int k=i+1;k<j;k+=2){
// 		int lt = evaltruemem(s,i,k-1,1);
// 		int lf = evaltruemem(s,i,k-1,0);
// 		int rt = evaltruemem(s,k+1,j,1);
// 		int rf = evaltruemem(s,k+1,j,0);

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
// 	return dp[i][j][b] = ans;
// }

bool scrambled(string a,string b){
	if(a.sz()!=b.sz()) return 0;
	if(a==b) return 1;
	if(a.sz()<=1) return 0;
	int n=a.sz();
	fr(i,1,n){
		bool c1,c2;
		c1 = scrambled(a.substr(0,i),b.substr(n-i,i)) && scrambled(a.substr(i,n-i),b.substr(0,n-i));
		if(c1) return true;
		c2 = scrambled(a.substr(0,i),b.substr(0,i)) && scrambled(a.substr(i,n-i),b.substr(i,n-i));
		if(c2) return true;
	}
	return false;
}

unordered_map<string,bool> m;

bool scrambledmem(string a,string b){
	if(a.sz()!=b.sz()) return 0;
	if(a==b) return 1;
	if(a.sz()<=1) return 0;
	if(m.find(a+"_"+b)!=m.end()) return m[a+"_"+b];
	int n=a.sz();
	bool bb = false;
	fr(i,1,n){
		bool c1,c2;
		c1 = scrambledmem(a.substr(0,i),b.substr(n-i,i)) && scrambledmem(a.substr(i,n-i),b.substr(0,n-i));
		if(c1) {bb=true;break;}
		c2 = scrambledmem(a.substr(0,i),b.substr(0,i)) && scrambledmem(a.substr(i,n-i),b.substr(i,n-i));
		if(c2) {bb=true;break;}
	}
	return m[a+"_"+b]=bb;
}

int eggdrop(int e,int f){
	if(e==1||f==0||f==1) return f;
	int ans = int_max;
	fr(i,1,f+1){
		ans = min(ans,1+max(eggdrop(e-1,i-1),eggdrop(e,f-i)));
	}
	return ans;
}

int eggdropmem(int e,int f){
	if(e==1||f==0||f==1) return f;
	if(dp[e][f]!=-1) return dp[e][f];
	int ans = int_max;
	fr(i,1,f+1){
		ans = min(ans,1+max(eggdropmem(e-1,i-1),eggdropmem(e,f-i)));
	}
	return dp[e][f]=ans;
}

void solve()
{	
	// "THOSE WE FORGOT THE PAST ARE CONDEMEND TO REPEAT IT!!"

	// problems with exponential time : solved using recusrssion : time : O(2^n)
	// apply dp to make the time polynomial

	// recurssion :: -> top down (memoization) :: 				-> bottom up (tabulation) :: 				-> tabulation space optimization
	//					(table + recurssion)		 			   (table)					  				   (possible : n^p -> n^(p-1))
	//					( n -> 0 )(higher input to lower input)    ( 0 -> n )(lower input to higher input) 

	// ** 1D DP ***************************************************************************************************************************
	// ************************************************************************************************************************************

	// 1) nth fibonacci number 

	// recurssive
	
	// int n;cin>>n;
	// cout<<fib(n)<<endl;
	// time : O(2^n)

	// memoized
	
	// int n;cin>>n;
	// memset(dp,-1,sizeof(dp));
	// fr(i,0,n+1)
	// 	cout<<fib(i)<<endl;
	// time space : O(n)

	// tabulation
	
	// int n;cin>>n;
	// memset(dp,-1,sizeof(dp));
	// dp[0]=0;
	// dp[1]=1;
	// fr(i,2,n+1)
	// 	dp[i]=dp[i-1]+dp[i-2];
	// cout<<dp[n]<<endl;
	// time space : O(n)

	// space optimization

	// int n;cin>>n;
	// int a=0,b=1;

	// int ans;
	// fr(i,2,n+1){
	// 	ans=a+b;
	// 	a=b;
	// 	b=ans;
	// }
	// cout<<b<<" "<<ans<<endl;
	// time O(n) space O(1)

	// 2) climbing stairs problem

	// *1) number of ways to reach nth stair : f(n) = f(n-1) + f(n-2) st f(1)=1, f(2)=1
	// *2) minimum cost to reach the Nth stair , given the cost array for stairs from o to N-1 th stair

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];

	// recurssive
	// int ans = min(find(n-1,v),find(n-2,v));
	// cout<<ans<<endl;

	// memoized
	// memset(dp,-1,sizeof(dp));
	// int ans = min(find(n-1,v),find(n-2,v));
	// cout<<ans<<endl;

	// tabulation
	// dp[0]=v[0];
	// dp[1]=v[1];
	// fr(i,2,n){
	// 	dp[i]=v[i]+min(dp[i-1],dp[i-2]);
	// }
	// cout<<min(dp[n-1],dp[n-2])<<endl;

	// space optimized
	// int prev0 = v[0];
	// int prev1 = v[1];
	// fr(i,2,n){
	// 	int curr = v[i]+min(prev0,prev1);
	// 	prev0=prev1;
	// 	prev1=curr;
	// }
	// cout<<min(prev1,prev0)<<endl;

	// 3) minimum number of coins needed to make the target amount ******** in 2D DP explored well ***********
	// given different types of coins -- unbounded knapsack variation

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	// int w;cin>>w;
	// debug(w)

	// int ans = mincoins(v,w);
	// if(ans!=int_max) cout<<ans<<endl;
	// else cout<<-1<<endl;

	// *******************************************************************************************************

	// 4) max sum of non adjecent elements
	
	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];

	// recurssive
	// int ans = maxnonadjsum(v,n-1);
	// cout<<ans<<endl;

	// memoized
	// memset(dp,-1,sizeof dp);
	// int ans = maxnonadjsummem(v,n-1);
	// cout<<ans<<endl;

	// tabulation
	// memset(dp,-1,sizeof dp);
	// dp[0]=v[0];
	// dp[1]=max(v[0],v[1]);
	// fr(i,1,n){
	// 	debug(mp(dp[i-2],dp[i-1]))
	// 	dp[i] = max(v[i]+dp[i-2],dp[i-1]);
	// }
	// fr(i,0,n) cout<<dp[i]<<" ";
	// cout<<endl;
	// cout<<dp[n-1]<<endl;

	// space optimized
	
	// int prev2 = v[0];
	// int prev1 = max(v[0],v[1]);

	// fr(i,2,n){
	// 	int newans = max(v[i]+prev2,prev1);
	// 	prev2 = prev1;
	// 	prev1 = newans;
	// }

	// cout<<prev1<<endl;

	// 5) house robbery in circular house system :: same as above with slite alteration
	
	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];

	// ans = max(f(v[0...n-2]),f(v[1...n-1]));

	// vector<int> v1(v.begin(),v.end()-1),v2(v.begin()+1,v.end());

	// int ans1 = maxnonadjsummem(v1,n-2) ;
	// memset(dp,-1,sizeof(dp));
	// int ans2 = maxnonadjsummem(v2,n-2);
	// int ans = max(ans1,ans2);
	// cout<<ans<<endl;

	// 6) maximum number of segemnts that a rod can be cut into given three specific lengths to cut rod into

	// int n,x,y,z;
	// cin>>n>>x>>y>>z;

	// recurssive
	// int ans = cutrod3(n,x,y,z);
	// cout<<ans<<endl;

	// memoized
	// memset(dp,-1,sizeof dp);
	// int ans = cutrod3mem(n,x,y,z);
	// cout<<ans<<endl;

	// tabulation

	// memset(dp,-1,sizeof dp);
	// dp[0]=0;
	// fr(i,1,n+1){
	// 	if(i-x>=0 && dp[i-x]!=-1) dp[i] = max(dp[i],1+dp[i-x]);
	// 	if(i-y>=0 && dp[i-y]!=-1) dp[i] = max(dp[i],1+dp[i-y]);
	// 	if(i-z>=0 && dp[i-z]!=-1) dp[i] = max(dp[i],1+dp[i-z]);
	// }
	// fr(i,0,n+1) cout<<dp[i]<<" ";
	// cout<<endl;
	// if(dp[n]!=-1) cout<<dp[n]<<endl;
	// else cout<<0<<endl;

	// 7) count derangements
	// f(n) = (n-1)*(f(n-1)+f(n-2));

	// recurssive
	// int n;cin>>n;
	// int ans = derangements(n);
	// cout<<ans<<endl;

	// memoized
	// memset(dp,-1,sizeof(dp));
	// int n;cin>>n;
	// int ans = derangemem(n);
	// cout<<ans<<endl;

	// tabulation
	// int n;cin>>n;
	// memset(dp,-1,sizeof(dp));
	// dp[1]=0;
	// dp[2]=1;
	// fr(i,3,n+1)
	// 	dp[i]=(i-1)*(dp[i-1]+dp[i-2]);
	// cout<<dp[n]<<endl;

	// space optimized
	// int n;cin>>n;
	// int prev2 = 0;
	// int prev1 = 1;
	// fr(i,3,n+1){
	// 	int newans = (i-1)*(prev1+prev2);
	// 	prev2 = prev1;
	// 	prev1 = newans;
	// }
	// cout<<prev1<<endl;

	// 8) painting fence ninja
	// int n,k;cin>>n>>k;

	// recurssive
	// int ans = paintfence(n,k);
	// cout<<ans<<endl;

	// memoization
	// memset(dp,-1,sizeof dp);
	// int ans = paintfencemem(n,k);
	// cout<<ans<<endl;
	// fr(i,1,n+1) cout<<dp[i]<<" ";

	// tabulation
	// dp[1]=k;
	// dp[2]=k*k;

	// fr(i,3,n+1){
	// 	dp[i]=(k-1)*(dp[i-1]+dp[i-2]);
	// }
	// cout<<dp[n]<<endl;

	// spcae optimization
	// int prev2 = k;
	// int prev1 = k*k;

	// fr(i,3,n+1){
	// 	int newans = (k-1)*(prev1+prev2);
	// 	prev2 = prev1;
	// 	prev1 = newans;
	// }
	// cout<<prev1<<endl;

	// **9) vacation problem

	// recurssive + memoized
	// memset(dp,-1,sizeof dp);
	// int n;cin>>n;
	// vector<vector<int>> a(n+1,vector<int>(4,0));

	// fr(i,1,n+1){
	// 	cin>>a[i][1]>>a[i][2]>>a[i][3];
	// }

	// int day = 1;
	// int aa,bb,cc;
	// // a[day][arrno]
	// // day :: 1:n , arrno :: 1:3
	// aa = a[1][1]+f(a,n,day+1,1);
	// bb = a[1][2]+f(a,n,day+1,2);
	// cc = a[1][3]+f(a,n,day+1,3);
	// int ans = max(aa,max(bb,cc));
	// cout<<ans<<endl;

	// tabulation

	// for(int i=n-1;i>=1;i--){
	// 	a[i][1]+=max(a[i+1][2],a[i+1][3]);
	// 	a[i][2]+=max(a[i+1][1],a[i+1][3]);
	// 	a[i][3]+=max(a[i+1][1],a[i+1][2]);
	// }

	// int ans = max(a[1][1],max(a[1][2],a[1][3]));
	// cout<<ans<<endl;

	// **10) longest increasing subsequence *******************************

	// approach 1 : time : O(N^2) , space : O(N)
	// int n;cin>>n;
	// int lis = int_min;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	// vector<int> dp(n,1);
	// fr(i,1,n){
	// 	fr(j,0,i){
	// 		if(v[j]<v[i]){
	// 			dp[i]=max(dp[i],1+dp[j]);
	// 		}
	// 	}
	// 	lis = max(lis,dp[i]);
	// }
	// cout<<lis<<endl;
	
	// vector<int> a;
	// int i=n-1;
	// while(i>=0&&k>=0){
	// 	if(lis[i]==k){
	// 		a.pb(v[i]);
	// 		k--;
	// 	}
	// 	i--;
	// }
	// reverse(all(a));
	// debug(a)

	// approach 2 : LIS using binary search
	
	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];

	// vector<int> t;
	// t.pb(v[0]);
	// fr(i,1,n){
	// 	if(v[i]>t.back()) t.pb(v[i]);
	// 	else t[lower_bound(t.begin(),t.end(),v[i])-t.begin()]=v[i];
    // 	}
    // 	cout<<t.sz()<<endl;

    // ********************************************************************

	// 11) frog 1
	
	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];

	// recurssive
	// int ans = frog1(v,n-1);
	// cout<<ans<<endl;

	// memoized
	// memset(dp,-1,sizeof dp);
	// int ans = frog1mem(v,n-1);
	// cout<<ans<<endl;

	// tabulation
	// memset(dp,-1,sizeof(dp));
	// dp[0]=0;
	// dp[1]=abs(v[1]-v[0]);

	// fr(i,2,n)
	// 	dp[i] = min(dp[i-1]+abs(v[i]-v[i-1]),dp[i-2]+abs(v[i]-v[i-2]));
	// cout<<dp[n-1]<<endl;

	// space optimized
	// int prev2 = 0;
	// int prev1 = abs(v[1]-v[0]);

	// fr(i,2,n){
	// 	int newans = min(prev1+abs(v[i]-v[i-1]),prev2+abs(v[i]-v[i-2]));
	// 	prev2 = prev1;
	// 	prev1 = newans;
	// }
	// cout<<prev1<<endl;

	// 12) frog 2

	// int n;cin>>n;
	// int k;cin>>k;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];

	// recurssive
	// int ans = frog2(v,n-1,k);
	// cout<<ans<<endl;

	// memoized
	// memset(dp,-1,sizeof dp);
	// int ans = frog2mem(v,n-1,k);
	// cout<<ans<<endl;

	// tabulation
	// memset(dp,-1,sizeof dp);
	// vector<int> dp(n,INT_MAX);
	// dp[0]=0;
	// dp[1]=abs(v[1]-v[0]);

	// fr(i,2,n){
	// 	fr(j,1,k+1){
	// 		if(i-j>=0){
	// 			dp[i] = min(dp[i],abs(v[i]-v[i-j])+dp[i-j]);
	// 		}
	// 	}
	// }
	// debugv(dp,0,n);
	// cout<<dp[n-1]<<endl;
	// time : O(nk) , space : O(n)

	// space optimization : time : O(nk) , space : O(k)


	// ** 2D DP ***************************************************************************************************************************
	// ************************************************************************************************************************************

	// 1) (0-1) knapsack

	// int n;cin>>n;
	// vector<int> wt(n),val(n);
	// fr(i,0,n) cin>>wt[i];
	// fr(i,0,n) cin>>val[i];
	// int w;cin>>w;

	// recurssive
	// int ans = knapsack(wt,val,w,n);
	// cout<<ans<<endl;

	// memoization
	// memset(dp,-1,sizeof dp);
	// int ans = knapsackmem(wt,val,w,n);
	// cout<<ans<<endl;

	// tabulation
	// memset(dp,-1,sizeof dp);
	// fr(i,0,n+1) dp[i][0]=0;
	// fr(j,0,w+1) dp[0][j]=0;
	// fr(i,1,n+1){
	// 	fr(j,1,w+1){
	// 		if(wt[i-1]<=j)
	// 			dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
	// 		else
	// 			dp[i][j]=dp[i-1][j];
	// 	}
	// }
	// cout<<dp[n][w]<<endl;
	// space & time : O(N^2)

	// space optimization
	// vector<int> prev(w+1,0),curr(w+1,0);
	// fr(i,1,n+1){
	// 	fr(j,1,w+1){
	// 		if(wt[i-1]<=j)
	// 			curr[j]=max(prev[j],val[i-1]+prev[j-wt[i-1]]);
	// 		else
	// 			curr[j]=prev[j];
	// 	}
	// 	prev=curr;
	// }
	// cout<<prev[w]<<endl;	
	// space : O(n) , time : O(n^2)

	// 2) subset sum problem
	// check if given number can be formed as the sum of any subset from given set

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	// int w;cin>>w;

	// recurssive
	// bool ans = subsetsum(v,n,w);
	// cout<<ans<<endl;

	// memoized
	// memset(dp,-1,sizeof(dp));
	// bool ans = subsetsummem(v,n,w);
	// cout<<ans<<endl;

	// tabulation
	// memset(dp,-1,sizeof(dp));
	// fr(i,0,n+1){
	// 	fr(j,0,w+1){
	// 		if(i==0) dp[i][j]=0;
	// 		if(j==0) dp[i][j]=1;
	// 	}
	// }

	// fr(i,1,n+1){
	// 	fr(j,1,w+1){
	// 		if(v[i-1]<=j){
	// 			dp[i][j] = dp[i-1][j] || dp[i-1][j-v[i-1]];
	// 		}
	// 		else{
	// 			dp[i][j] = dp[i-1][j];
	// 		}
	// 	}
	// }

	// space optimization
	// vector<bool> prev(w+1,0),curr(w+1,0);
	// prev[0]=curr[0]=1;

	// fr(i,1,n+1){
	// 	fr(j,1,w+1){
	// 		if(v[i-1]<=j){
	// 			curr[j] = prev[j] || prev[j-v[i-1]];
	// 		}
	// 		else{
	// 			curr[j] = prev[j];
	// 		}
	// 	}
	// 	prev = curr;
	// }
	// fr(j,1,w+1)
	// 	cout<<prev[j]<<endl;

	// 3) check for equal partition of the array such that sum of elements in each set is equal

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	// int s=0;
	// fr(i,0,n) s+=v[i];

	// recurssive
	// if(s%2) cout<<0<<endl;
	// else{
	// 	int k=s/2;
	// 	bool ans = subsetsum(v,n,k);
	// 	cout<<ans<<endl;
	// }

	// memoized
	// if(s%2) cout<<0<<endl;
	// else{
	// 	memset(dp,-1,sizeof(dp));
	// 	int k=s/2;
	// 	bool ans = subsetsummem(v,n,k);
	// 	cout<<ans<<endl;
	// }

	// tabulation
	// if(s%2) cout<<0<<endl;
	// else{
	// 	int k=s/2;
	// 	memset(dp,-1,sizeof(dp));
	// 	fr(i,0,n+1){
	// 		fr(j,0,k+1){
	// 			if(i==0) dp[i][j]=0;
	// 			if(j==0) dp[i][j]=1;
	// 		}
	// 	}

	// 	fr(i,1,n+1){
	// 		fr(j,1,k+1){
	// 			if(v[i-1]<=j)
	// 				dp[i][j] = dp[i-1][j] || dp[i-1][j-v[i-1]];
	// 			else
	// 				dp[i][j] = dp[i-1][j];
	// 		}
	// 	}
	// 	cout<<dp[n][k]<<endl;
	// }

	// space optimization
	// if(s%2) cout<<0<<endl;
	// else{
	// 	int k=s/2;
	// 	memset(dp,-1,sizeof(dp));
	// 	vector<int> prev(k+1,0),curr(k+1,0);
	// 	prev[0]=curr[0]=1;
		
	// 	fr(i,1,n+1){
	// 		fr(j,1,k+1){
	// 			if(v[i-1]<=j)
	// 				curr[j] = prev[j] || prev[j-v[i-1]];
	// 			else
	// 				curr[j] = prev[j];
	// 		}
	// 		prev = curr;
	// 	}
	// 	cout<<prev[k]<<endl;
	// } 

	// 4) count of subsetsum
	// given w ,find total number of subsets from set which's sum is w

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	// int w;cin>>w;

	// recurssive
	// int ans = totalsubset(v,n,w);
	// cout<<ans<<endl;

	// memoization
	// memset(dp,-1,sizeof(dp));
	// int ans = totalsubsetmem(v,n,w);
	// cout<<ans<<endl;

	// tabulation
	// memset(dp,-1,sizeof(dp));
	// fr(i,0,n+1){
	// 	fr(j,0,w+1){
	// 		if(i==0) dp[i][j]=0;
	// 		if(j==0) dp[i][j]=1;
	// 	}
	// }

	// fr(i,1,n+1){
	// 	fr(j,1,w+1){
	// 		if(v[i-1]<=j)
	// 			dp[i][j] = dp[i-1][j]+dp[i-1][j-v[i-1]];
	// 		else
	// 			dp[i][j] = dp[i-1][j];
	// 	}
	// }

	// cout<<dp[n][w]<<endl;

	// space optimization
	// vector<int> prev(w+1,0),curr(w+1,0);
	// prev[0]=curr[0]=1;

	// fr(i,1,n+1){
	// 	fr(j,1,w+1){
	// 		if(v[i-1]<=j)
	// 			curr[j] = prev[j]+prev[j-v[i-1]];
	// 		else
	// 			curr[j] = prev[j];
	// 	}
	// 	prev=curr;
	// }

	// cout<<prev[w]<<endl;

	// 5) minimum subset sum difference

	// int n;cin>>n;
	// int s=0;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i],s+=v[i];

	// memoized
	// memset(dp,-1,sizeof dp);
	// int ans = subsetss(v,n,s);
	// int ans1 = int_max;
	// fr(i,1,s+1){
	// 	if(dp[n][i]) ans1 = min(ans1,abs(s-2*i));
	// }
	// debugd(dp,n+1,s+1);
	// cout<<ans1<<endl;

	// tabulation
	// memset(dp,-1,sizeof dp);
	// fr(i,0,n+1){
	// 	fr(j,0,s+1){
	// 		if(i==0) dp[i][j]=0;
	// 		if(j==0) dp[i][j]=1;
	// 	}
	// }
	// int ans = int_max;
	// fr(i,1,n+1){
	// 	fr(j,1,s+1){
	// 		if(v[i-1]<=j)
	// 			dp[i][j] = dp[i-1][j]+dp[i-1][j-v[i-1]];
	// 		else 
	// 			dp[i][j] = dp[i-1][j];
	// 		if(i==n && dp[i][j]) ans = min(ans,abs(s-2*j));
	// 	}
	// }
	// cout<<ans<<endl;

	// space optimization
	
	// vector<int> prev(s+1,0),curr(s+1,0);
	// prev[0]=curr[0]=1;
	// int ans = int_max;
	// fr(i,1,n+1){
	// 	fr(j,1,s+1){
	// 		if(v[i-1]<=j)
	// 			curr[j] = prev[j]+prev[j-v[i-1]];
	// 		else
	// 			curr[j] = prev[j];
	// 		if(i==n && curr[j]) ans = min(ans,abs(s-2*j));
	// 	}
	// 	prev = curr;
	// }
	// cout<<ans<<endl;

	// 6) count pair of subsets with given difference d
	
	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];

	// int d;cin>>d;
	// int s=0;s=accumulate(all(v),s);
	// if(d%2==s%2){
	// 	int k = (s+d)/2;
	// 	int ans = totalsubset(v,n,k);
	// 	cout<<ans<<endl;
	// }else cout<<0<<endl;

	// 7) target sum = count pair of subsets with given diff d

	// *8) unbounded knapsack

	// int n;cin>>n;
	// vector<int> wt(n),val(n);
	// fr(i,0,n) cin>>wt[i];
	// fr(i,0,n) cin>>val[i];
	// int w;cin>>w;

	// int ans0 = ubknapsack(wt,val,n,w);
	// cout<<ans0<<endl;

	// memset(dp,-1,sizeof(dp));
	// int anss = ubknapsackmem(wt,val,n,w);
	// cout<<anss<<endl;

	// memset(dp,-1,sizeof(dp));
	// fr(i,0,n+1) fr(j,0,w+1) dp[i][j]=0;

	// fr(i,1,n+1){
	// 	fr(j,1,w+1){
	// 		if(wt[i-1]<=j)
	// 			dp[i][j] = max(dp[i-1][j],val[i-1]+dp[i][j-wt[i-1]]);
	// 		else
	// 			dp[i][j] = dp[i-1][j];
	// 	}
	// }

	// cout<<dp[n][w]<<endl;

	// vector<int> prev(w+1,0),curr(w+1,0);

	// fr(i,1,n+1){
	// 	fr(j,1,w+1){
	// 		if(wt[i-1]<=j)
	// 			curr[j] = max(prev[j],val[i-1]+curr[j-wt[i-1]]);
	// 		else
	// 			curr[j] = prev[j];
	// 	}
	// 	prev = curr;
	// }

	// cout<<prev[w]<<endl;

	// 9) rod cutting problem = same ubns
	// if the array of possible lengths of the rod is given then dp[lenghtarr.sz()+1][rodlenght+1]

	// 10) coin change 1 (max no ways to make the required total from given coins)

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	// int s;cin>>s;

	// memset(dp,-1,sizeof dp);
	// int ans = countwayscoinmem(v,n,s);
	// cout<<ans<<endl;

	// memset(dp,-1,sizeof dp);
	// fr(i,0,n+1) fr(j,0,s+1){
	// 	if(i==0) dp[i][j]=0;
	// 	if(j==0) dp[i][j]=1;
	// }

	// fr(i,1,n+1){
	// 	fr(j,1,s+1){
	// 		if(v[i-1]<=j)
	// 			dp[i][j] = dp[i-1][j]+dp[i][j-v[i-1]];
	// 		else
	// 			dp[i][j] = dp[i-1][j];
	// 	}
	// }

	// cout<<dp[n][s]<<endl;

	// vector<int> prev(s+1,0),curr(s+1,0);
	// prev[0]=curr[0]=1;

	// fr(i,1,n+1){
	// 	fr(j,1,s+1){
	// 		if(v[i-1]<=j)
	// 			curr[j] = prev[j]+curr[j-v[i-1]];
	// 		else
	// 			curr[j] = prev[j];
	// 	}
	// 	prev = curr;
	// }

	// cout<<prev[s]<<endl;

	// 11) coin change 2 (min no of coins needed to make the total)

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	// int w;cin>>w;

	// int ans = mincoins(v,n,w);
	// cout<<ans<<endl;

	// memset(dp,-1,sizeof dp);
	// int ans = mincoinsmem(v,n,w);
	// cout<<ans<<endl;

	// memset(dp,-1,sizeof dp);
	// fr(i,0,n+1){
	// 	fr(j,0,w+1){
	// 		if(i==0) dp[i][j]=int_max-10;
	// 		if(j==0) dp[i][j]=0;
	// 	}
	// }

	// for(int i=1,j=1;j<=w;j++){
	// 	dp[i][j] = (j%v[0]==0)?(j/v[0]):int_max-10;
	// }

	// fr(i,1,n+1){
	// 	fr(j,1,w+1){
	// 		if(v[i-1]<=j)
	// 			dp[i][j] = min(dp[i-1][j],1+dp[i][j-v[i-1]]);
	// 		else
	// 			dp[i][j] = dp[i-1][j];
	// 	}
	// }

	// cout<<dp[n][w]<<endl;

	// vector<int> prev(w+1,int_max-10),curr(w+1,int_max-10);
	// prev[0]=curr[0]=0;
	// fr(i,1,w+1){
	// 	curr[i] = (i%v[0]==0)?(i/v[0]):curr[i];
	// }

	// fr(i,1,n+1){
	// 	fr(j,1,w+1){
	// 		if(v[i-1]<=j)
	// 			curr[j] = min(prev[j],1+curr[j-v[i-1]]);
	// 		else 
	// 			curr[j] = prev[j];
	// 	}
	// 	prev = curr;
	// }

	// cout<<prev[w]<<endl;

	// dp with strings **************************************************************************************

	// 12) LCSubseq && print LCSubseq

	// string a,b;cin>>a>>b;
	// int n = a.sz(),m = b.sz();
	// int ans = lcsubseq(a,b,a.sz(),b.sz());
	// cout<<ans<<endl;

	// memset(dp,-1,sizeof dp);
	// int ans = lcsubseqmem(a,b,a.sz(),b.sz());
	// cout<<ans<<endl;

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

	// cout<<dp[n][m]<<endl;

	// string ans = "";

	// int i=n,j=m;
	// while(i>=1 && j>=1){
	// 	if(a[i-1]==b[j-1]){
	// 		ans.pb(a[i-1]);
	// 		i--;
	// 		j--;
	// 	}else{
	// 		if(dp[i][j-1]>dp[i-1][j])
	// 			j--;
	// 		else
	// 			i--;
	// 	}
	// }

	// reverse(all(ans));
	// cout<<ans<<endl;

	// vector<int> prev(m+1,0),curr(m+1,0);

	// fr(i,1,n+1){
	// 	fr(j,1,m+1){
	// 		if(a[i-1]==b[j-1])
	// 			curr[j] = 1+prev[j-1];
	// 		else
	// 			curr[j] = max(curr[j-1],prev[j]);
	// 	}
	// 	prev = curr;
	// }
	// cout<<prev[m]<<endl;

	// 13) longest common substring & print it

	// string a,b;cin>>a>>b;
	// int n=a.sz(),m=b.sz();
	// int ans=0;
	// memset(dp,-1,sizeof dp);
	
	// fr(i,0,n+1) fr(j,0,m+1)
	// 	if(i==0||j==0) dp[i][j]=0;
	
	// fr(i,1,n+1){
	// 	fr(j,1,m+1){
	// 		if(a[i-1]==b[j-1])
	// 			dp[i][j] = 1+dp[i-1][j-1];
	// 		else
	// 			dp[i][j] = 0;
	// 		ans = max(ans,dp[i][j]);
	// 	}
	// }
	// cout<<ans<<endl;

	// print
	// string ss="";
	// int ii=0,jj=0;
	// fr(i,0,n+1){
	// 	fr(j,0,m+1){
	// 		if(dp[i][j]==ans){
	// 			ii=i;
	// 			jj=j;
	// 			break;
	// 		}
	// 	}
	// }

	// while(dp[ii][jj]){
	// 	ss.pb(a[ii-1]);
	// 	ii--,jj--;
	// }

	// reverse(all(ss));
	// cout<<ss<<endl;
	
	// int ans1=0;
	// vector<int> prev(m+1,0),curr(m+1,0);

	// fr(i,1,n+1){
	// 	fr(j,1,m+1){
	// 		if(a[i-1]==b[j-1])
	// 			curr[j] = 1+prev[j-1];
	// 		else
	// 			curr[j] = 0;
	// 		ans1 = max(ans1,curr[j]);
	// 	}
	// 	prev = curr;
	// }
	// cout<<ans1<<endl;

	// 14) shortest common super sequence lenght and print it

	// string a,b;cin>>a>>b;
	// int n=a.sz(),m=b.sz();

	// int ans = n+m-lcsubseq(a,b,n,m);
	// cout<<ans<<endl;

	// 15) longest repeating subsequence

	// string a;cin>>a;
	// int n=a.sz();

	// int ans = lrsubseq(a,n,n);
	// cout<<ans<<endl;

	// // memoized
	// memset(dp,-1,sizeof dp);
	// int ans2 = lrsubseqmem(a,n,n);
	// cout<<ans2<<endl;

	// memset(dp,-1,sizeof dp);
	// fr(i,0,n+1) fr(j,0,n+1) if(i==0||j==0) dp[i][j]=0;

	// fr(i,1,n+1){
	// 	fr(j,1,n+1){
	// 		if(i!=j && a[i-1]==a[j-1])
	// 			dp[i][j] = 1+dp[i-1][j-1];
	// 		else
	// 			dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
	// 	}
	// }

	// cout<<dp[n][n]<<endl;

	// 16) min no of operation to a->b
	// ans = a.sz()+b.sz() - 2*lcs(a,b)

	// 17) longest palindromic subseq
	// lcs(a,a.reverse());

	// 18) min no deletions to mak the string palindromic
	// a.sz() - lcs(a,a.reverse());

	// 19) pattern mathicg, check if a is a subseq of b
	// a.sz()==lcs(a,b) , bruteforce O(b)

	// ********* MCM ****************************************************************************************

	// 20) the minimum operation matrix chain multiplication

	// int n;cin>>n;
	// // total (n-1) matrics
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	// matrix Ai has the dimension of v[i-1] x v[i];

	// int ans = mcm(v,1,n-1);
	// cout<<ans<<endl;

	// memoized
	// memset(dp,-1,sizeof dp);
	// int ans = mcmmem(v,1,n-1);
	// cout<<ans<<endl;

	// fr(i,0,n-1){
	// 	fr(j,0,n){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	// tabulation
	// memset(dp,-1,sizeof dp);
	// fr(i,1,n) dp[i][i]=0;

	// for(int i=n-2;i>=1;i--){
	// 	for(int j=i+1;j<n;j++){
	// 		dp[i][j]=int_max;
	// 		for(int k=i;k<j;k++){
	// 			dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+v[i-1]*v[k]*v[j]);
	// 		}
	// 	}
	// }

	// cout<<dp[1][n-1]<<endl;

	// 21) palindrome partitioning

	// string s;cin>>s;

	// int ans = pp(s,0,s.sz()-1);
	// cout<<ans<<endl;

	// memset(dp,-1,sizeof dp);
	// int ans = ppmem(s,0,s.sz()-1);
	// cout<<ans<<endl;

	// memset(dp,-1,sizeof dp);
	// int ans = ppmemopt(s,0,s.sz()-1);
	// cout<<ans<<endl;

	// tabulation 
	// memset(dp,-1,sizeof dp);
	// fr(i,0,s.sz()){
	// 	fr(j,0,s.sz()){
	// 		if(i>=j || isp(s,i,j)) dp[i][j]=0;
	// 		else dp[i][j] = int_max;
	// 	}
	// }

	// fr(i,0,s.sz()){
	// 	fr(j,0,s.sz()){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	// for(int i=s.sz()-1;i>=0;i--){
	// 	for(int j=i+1;j<s.sz();j++){
	// 		for(int k=i;k<=j;k++){
	// 			dp[i][j] = min(dp[i][j],1+dp[i][k]+dp[k+1][j]);
	// 		}
	// 	}
	// }
	// cout<<endl;

	// fr(i,0,s.sz()){
	// 	fr(j,0,s.sz()){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	// cout<<dp[0][s.sz()-1]<<endl;

	// 22) no of ways to evalute boolean expression to true

	// string s;cin>>s;
	// int ans = evaltrue(s,0,s.sz()-1,1);
	// cout<<ans<<endl;

	// memset(dp,-1,sizeof dp);
	// int ans1 = evaltruemem(s,0,s.sz()-1,1);
	// cout<<ans1<<endl;

	// 23) scrambled string check

	// string s1,s2;cin>>s1>>s2;
	// bool ans = scrambled(s1,s2);
	// cout<<ans<<endl;

	// bool ans = scrambledmem(s1,s2);
	// cout<<ans<<endl;


	// 24) egg drop problem

	int e,f;cin>>e>>f;
	// int ans = eggdrop(e,f);
	// cout<<ans<<endl;

	// memset(dp,-1,sizeof dp);
	// int ans = eggdropmem(e,f);
	// cout<<ans<<endl;

	// tabulation
	memset(dp,-1,sizeof dp);

	// dp(e+1)(f+1);

	// if(e==1) ans=f;
	// dp[1][j] = j;
	for(int j=0;j<=f;j++) dp[1][j]=j;

	// if(f==0||f==1) ans=f;
	// dp[i][0]=0,dp[i][1]=1;
	for(int i=0;i<=e;i++) {dp[i][1]=1;dp[i][0]=0;}

	for(int i=2;i<=e;i++){
		for(int j=2;j<=f;j++){
			dp[i][j]=int_max;
			for(int k=1;k<=j;k++){
				int t = 1+max(dp[i-1][k-1],dp[i][j-k]);
				dp[i][j] = min(dp[i][j],t);
			}
		}
	}

	cout<<dp[e][f]<<endl;
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