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

// int knapsack(vector<int>& val,vector<int>& wt,int W,int n){
// 	// base condition
// 	if(W==0 || n==0) return 0;
// 	// decision tree
// 	if(wt[n-1] <= W){
// 		return max(val[n-1]+knapsack(val,wt,W-wt[n-1],n-1),knapsack(val,wt,W,n-1));
// 	}else{
// 		return knapsack(val,wt,W,n-1);
// 	}
// }

// int dp[W+1][n+1];
// int dp[100000][100000];

// 1<= W <= 10^5
// 1<= n <= 10^3

// int knapsackmemoize(vector<int>& val,vector<int>& wt,int W,int n){

// 	if(W==0||n==0) return 0;

// 	if(dp[W][n]!=-1) return dp[W][n];

// 	if(wt[n-1]<=W){
// 		return dp[W][n] = max(val[n-1]+knapsackmemoize(val,wt,W-wt[n-1],n-1),knapsackmemoize(val,wt,W,n-1));
// 	}else{
// 		return dp[W][n] = knapsackmemoize(val,wt,W,n-1);
// 	}
// }

void solve()
{	
	// "Those who does not remember the past are condemped to repeat itself."  - dp

	// dynamic programming
	// -> base is recurssion
	// parent  questions
	// pattern recognization

	// 1) (0-1) knapsack (6)
	// 2) unbounded knpsack (5)
	// 3) fibonacci (7)
	// 4) LCS (15)
	// 5) LIS (10)
	// 6) kadane's algo(6)
	// 7) matrix chain multiplication (7)
	// 8) Dp on trees (4)
	// 9) Dp on Grid(14)
	// 10) others (5)

	// ##############################################################################################
	// ##############################################################################################

	//*) (0-1) Knapsack

	// ##############################################################################################
	// ##############################################################################################

	// related questions
	// -> subset sum
	// -> equal sum partitioning
	// -> count of subset sum
	// -> minimum subset sum diff
	// -> tareget sum
	// -> no of subsets with given diff

	// // knapsack variations -> (0-1)
	// 					   -> unbounded
	// 					   -> fractional ( not dp but greedy )

	// basic recurssive solution
	// int n;cin>>n;
	// vector<int> val(n),wt(n);
	// fr(i,0,n) cin>>val[i];
	// fr(i,0,n) cin>>wt[i];
	// int W;cin>>W;

	// int ans = knapsack(val,wt,W,n);
	// cout<<ans<<endl;

	// memoization for the knapsack
	// state of the problem -> paremeters in the recurssive calls which are changing like => W and n
	// take the table of type *[W+1][n+1]
	// feel it with the -1 
	// for any call if the cell [W][n] is not -1 then return the cell [W][n]
	// ans -> dp[W][n] => in the recursive function which calls the smaller variations of it self. 
	
	// memset(dp,-1,sizeof(dp));
	// int ans = knapsackmemoize(val,wt,W,n);
	// cout<<ans<<endl;

	// top down approach for the knapsack / any dp problems
	// i=> n
	// j=> W
	
	// initiallization part -> replacing the base conditions

	// fr(i,0,n+1){
	// 	fr(j,0,W+1){
	// 		if(i==0||j==0) dp[i][j]=0;
	// 	}
	// }

	// fr(i,1,n+1){
	// 	fr(j,1,W+1){
	// 		if(wt[i-1]<=j){
	// 			dp[i][j] = max( dp[i-1][j] , val[i-1]+dp[i-1][j-wt[i-1]] );
	// 		}else{
	// 			dp[i][j] = dp[i-1][j];
	// 		}
	// 	}
	// }

	// cout<<dp[n][W]<<endl;

	// knapsack based ( same technique ) problems:

	// 1 -> subset sum
	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
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
	// 		if(v[i-1]<=j){
	// 			dp[i][j] = dp[i-1][j] or dp[i-1][j-v[i-1]];
	// 		}else{
	// 			dp[i][j] = dp[i-1][j];
	// 		}
	// 	}
	// }

	// fr(i,0,n+1){
	// 	fr(j,0,s+1){
	// 		cout<<dp[i][j]<<" ";
	// 	}cout<<endl;
	// }
	// cout<<dp[n][s]<<endl;

	// 2 -> equal sum partition
	// if s = odd -> ans is false
	// if s = even -> check if there exist an partition with sum = s/2 present in the array

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];

	// int s=0;
	// fr(i,0,n) s+=v[i];
	// bool b;
	// if(s%2) b=false;
	// else{
	// 	int k = s/2;
	// 	int dp[n+1][k+1];

	// 	fr(i,0,n+1) fr(j,0,k+1){
	// 		if(i==0) dp[i][j] = 0;
	// 		if(j==0) dp[i][j] = 1;
	// 	}

	// 	fr(i,1,n+1){
	// 		fr(j,1,k+1){
	// 			if(v[i-1]<=j){
	// 				dp[i][j] = dp[i-1][j] || dp[i-1][j-v[i-1]];
	// 			}else{
	// 				dp[i][j] = dp[i-1][j];
	// 			}
	// 		}
	// 	}
	// 	b = b | dp[n][k];		
	// }

	// cout<<b<<endl;

	// 3 -> count of subset sum
	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	// int s;cin>>s;
	// // debug(mp(n,s))
	// int dp[n+1][s+1];
	// fr(i,0,n+1)fr(j,0,s+1){
	// 	if(i==0) dp[i][j]=0;
	// 	if(j==0) dp[i][j]=1;
	// }

	// fr(i,1,n+1){
	// 	fr(j,1,s+1){
	// 		if(v[i-1]<=j){
	// 			dp[i][j] = dp[i-1][j] + dp[i-1][j-v[i-1]];
	// 		}else{
	// 			dp[i][j] = dp[i-1][j];
	// 		}
	// 	}
	// }

	// cout<<dp[n][s]<<endl;

	// 4 -> minimum subset sum diff

	// int n,s=0;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i],s+=v[i];
	// int k;cin>>k;

	// // int s=0;
	// // fr(i,0,n) s+=v[i];

	// int dp[n+1][s+1];

	// fr(i,0,n+1){
	// 	fr(j,0,s+1){
	// 		if(i==0) dp[i][j] = 0;
	// 		if(j==0) dp[i][j] = 1;
	// 	}
	// }

	// int ans = 0;

	// fr(i,1,n+1){
	// 	fr(j,1,s+1){

	// 		// dp[i][j] = dp[i-1][j];
	// 		// if(v[i-1]<=j)
	// 		// 	dp[i][j] = dp[i][j] or dp[i-1][j-v[i-1]];
		
	// 		if(v[i-1]<=j){
	// 			dp[i][j] = dp[i-1][j] or dp[i-1][j-v[i-1]];
	// 		}else{
	// 			dp[i][j] = dp[i-1][j];
	// 		}
	// 		if(i==n && dp[i][j] && j<=s/2){
	// 			ans = min(ans,s-2*j);
	// 		}
	// 	}
	// }

	// // fr(i,0,n+1){			
	// // 	fr(j,0,s+1){
	// // 		cout<<dp[i][j]<<" ";
	// // 	}cout<<endl;
	// // }

	// // int ans = int_max;

	// // fr(j,1,s/2){
	// // 	if(dp[n][j])
	// // 		ans = min(ans,s-2*j);
	// // }

	// cout<<ans;

	// 5 -> count the number of subsets with given sum
	// s1 - s2 = d;
	// s1 + s2 = sum;
	// s1 = (d+sum)/2;
	// count the number of subsets with ss = d+sum /2

	// int n,s=0;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i],s+=v[i];
	// int d;cin>>d;

	// int ns = (s+d)/2;
	// int dp[n+1][ns+1];

	// fr(i,0,n+1) fr(j,0,ns+1){
	// 	if(i==0) dp[i][j]= 0;
	// 	if(j==0) dp[i][j]= 1;
	// }

	// fr(i,1,n+1){
	// 	fr(j,1,ns+1){
	// 		dp[i][j] = dp[i-1][j];
	// 		if(v[i-1]<=j) dp[i][j]+=dp[i-1][j-v[i-1]];
	// 		cout<<dp[i][j]<<" ";
	// 	}cout<<endl;
	// }

	// cout<<dp[n][ns]<<endl;

	// 6 -> target sum 
	// assign each element +/- such that overall sum is equall to the given value.
	// count such way that we can do the job

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