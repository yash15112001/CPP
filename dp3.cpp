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
#define all(v) v.begin(),v.end()
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

int static dp[100][100];

// int LCStr(string x,string y,int n,int m){

// 	// base condition
// 	if(n==0 or m==0) return 0;

// 	// choise diagram
// 	if(x[n-1]==y[m-1]) 
// 		return 1 + LCStr(x,y,n-1,m-1);

// 	else 
// 		return max(LCStr(x,y,n-1,m),LCStr(x,y,n,m-1));
// }

// int LCStrmem(string x,string y,int n,int m){

// 	// base condition
// 	if(n==0 or m==0) {dp[n][m]=0;return 0;}

// 	if(dp[n][m]!=-1)
// 		return dp[n][m];

// 	// choise diagram
// 	if(x[n-1]==y[m-1]) 
// 		return dp[n][m] = 1 + LCStr(x,y,n-1,m-1);

// 	else 
// 		return dp[n][m] = max(LCStr(x,y,n-1,m),LCStr(x,y,n,m-1));
// }

void solve()
{	
	// 1 -> Longest Common Subsequence
	// x : a b c d e f
	// y : a b e d g f
	// LCS : a b d f -> ans = 4

	// string x,y;cin>>x>>y;
	// int ans = LCStr(x,y,x.sz(),y.sz());
	// cout<<ans<<endl;

	// memoize ( bottom up )

	// string x,y;cin>>x>>y;
	// memset(dp,-1,sizeof(dp));
	// int ans = LCStrmem(x,y,x.sz(),y.sz());
	// cout<<ans<<endl;

	// top down

	// string x,y;cin>>x>>y;
	// int n = x.sz(),m=y.sz();
	
	// int dp[n+1][m+1];

	// fr(i,0,n+1){
	// 	fr(j,0,m+1){
	// 		if(i==0 || j==0) dp[i][j]=0;
	// 	}
	// }

	// fr(i,1,n+1){
	// 	fr(j,1,m+1){
	// 		if(x[i-1]==y[j-1])
	// 			dp[i][j] = 1 + dp[i-1][j-1];
	// 		else
	// 			dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
	// 		cout<<dp[i][j]<<" ";
	// 	}cout<<endl;
	// }
	// cout<<endl<<dp[n][m]<<endl;

	// 2 -> longest common substring

	// int ans=0;
	// string x,y;cin>>x>>y;
	// int n = x.sz(),m = y.sz();
	// int dp[n+1][m+1];
	// fr(i,0,n+1) fr(j,0,m+1) if(i==0||j==0) dp[i][j]=0;
	// int idash=0,jdash=0;
	// fr(i,1,n+1){
	// 	fr(j,1,m+1){
	// 		if(x[i-1]==y[i-1]) dp[i][j] = 1+dp[i-1][j-1];
	// 		else dp[i][j]=0;
	// 		ans = max(ans,dp[i][j]);
	// 		if(ans==dp[i][j]){
	// 			idash = i;
	// 			jdash = j;
	// 		}			
	// 	}
	// }

	// 2* -> print the longest common substring
	// 2 + --- >

	// cout<<dp[idash][jdash]<<endl;
	// string ans1="";
	// while(idash>=1 && jdash>=1){
	// 	if(dp[idash][jdash]==1+dp[idash-1][jdash-1]){
	// 		ans1 = x[idash-1]+ans1;
	// 		idash--;
	// 		jdash--;
	// 	}else{
	// 		if(dp[idash][jdash-1]>dp[idash-1][jdash]){
	// 			jdash--;
	// 		}else
	// 			idash--;
	// 	}
	// }
	// cout<<ans1<<endl;

	// 3-> printing the longest common subsequence
	
	// string x,y;cin>>x>>y;
	// int n=x.sz(),m=y.sz();
	// int dp[n+1][m+1];

	// fr(i,0,n+1) fr(j,0,m+1) if(i==0||j==0) dp[i][j]=0;

	// fr(i,1,n+1){
	// 	fr(j,1,m+1){
	// 		if(x[i-1]==y[j-1])
	// 			dp[i][j] = 1+dp[i-1][j-1];
	// 		else
	// 			dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
	// 		cout<<dp[i][j]<<" ";
	// 	}cout<<endl;
	// }

	// cout<<dp[n][m]<<endl;

	// string ans="";

	// int i=x.sz(),j=y.sz();
	// while(i>=1 && j>=1){
	// 	debug(mp(i,j));
	// 	if(x[i-1]==y[j-1]){
	// 		ans = y[j-1]+ans;
	// 		i--;
	// 		j--;
	// 		debug(ans);
	// 	}else{
	// 		if(dp[i][j-1]>dp[i-1][j]){
	// 			j--;
	// 		}else
	// 			i--;
	// 	}
	// 	debug(mp(i,j));
	// }
	// // // reverse(all(ans));
	// cout<<ans<<endl;

	// 4 -> shortest supersequence
	// string x,y;
	// cin>>x>>y;
	// int n=x.sz(),m=y.sz();

	// int dp[n+1][m+1];

	// fr(i,0,n+1){
	// 	fr(j,0,m+1){
	// 		if(i==0||j==0) dp[i][j]=0;
	// 	}
	// }

	// fr(i,1,n+1){
	// 	fr(j,1,m+1){
	// 		if(x[i-1]==y[j-1])
	// 			dp[i][j] = 1+dp[i-1][j-1];
	// 		else 
	// 			dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
	// 	}
	// }

	// cout<<(n+m-dp[n][m])<<endl;

	// 5 -> minimum numbers of the insertions and deletions to convert string a to b
	// find the length of the LCS of a and b ---> x
	// ans : Deletions -> a.sz() - x
	// ans2 : insertions -> b.sz() - y

	// sub topic =: Palindromes

	// 6 -> longest palindromic subsequence
	// idea is that the longest common substrind in the s and reverse(s) will be always palindrom of the longest length posible.

	// string x,y;
	// cin>>x;
	// y = x;
	// reverse(all(y));

	// int n=x.sz();
	// int dp[n+1][n+1];

	// fr(i,0,n+1) fr(j,0,n+1) if(i==0||j==0) dp[i][j]=0;

	// fr(i,1,n+1){
	// 	fr(j,1,n+1){
	// 		if(x[i-1]==y[j-1])
	// 			dp[i][j] = 1+dp[i-1][j-1];
	// 		else 
	// 			dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
	// 	}
	// }
	// cout<<dp[n][n]<<endl;

	// 7 -> minumum nunber of deletions to make a string palindrome

	// string s;cin>>s;
	// int n=s.sz();
	// string s2 = s;
	// reverse(all(s2));

	// int dp[n+1][n+1];

	// fr(i,0,n+1) fr(j,0,n+1) if(i==0||j==0) dp[i][j]=0;

	// fr(i,1,n+1){
	// 	fr(j,1,n+1){
	// 		if(s[i-1]==s2[j-1])
	// 			dp[i][j] = 1+dp[i-1][j-1];
	// 		else 
	// 			dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
	// 	}
	// }

	// cout<<n-dp[n][n]<<endl;

	// 8 ** -> print the SCS
	// string x,y;cin>>x>>y;
	// int n = x.sz(),m=y.sz();
	// int dp[n+1][m+1];

	// fr(i,0,n+1){
	// 	fr(j,0,m+1){
	// 		if(i==0||j==0) dp[i][j]=0;
	// 	}
	// }

	// fr(i,1,n+1){
	// 	fr(j,1,m+1){
	// 		if(x[i-1]==y[j-1])
	// 			dp[i][j] = 1+dp[i-1][j-1];
	// 		else
	// 			dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
	// 	}
	// }

	// string s = "";
	// int i=n,j=m;
	// while(i>=1 && j>=1){
	// 	if(x[i-1]==y[j-1]){
	// 		s = x[i-1]+s;
	// 		i--;
	// 		j--;
	// 	}else{
	// 		if(dp[i][j-1]<dp[i-1][j]){
	// 			s = x[i-1]+s;
	// 			i--;
	// 		}else{
	// 			s = y[j-1]+s;
	// 			j--;
	// 		}
	// 	}
	// }

	// cout<<s<<endl;

	// ** determine of a string a is present as a subsequence in string b
	// way 1-> if(LCS(a,b)==a) true else false
	// way 2->
	// string x,y;cin>>x>>y;
	// int n=x.sz(),m=y.sz();
	// int i=0,j=0;
	// int ans=0;
	// while(i<n && j<m){
	// 	if(x[i]==y[j])
	// 		i++;
	// 	j++;
	// 	debug(mp(i,j));
	// 	if(i==n) ans=1;
	// }
	
	// cout<<ans<<endl;

	// 9 * -> longest repeating subsequence && print the longest repeating subsequence

	// string x,y;cin>>x;
	// y=x;
	// int n=x.sz();
	// int dp[n+1][n+1];

	// fr(i,0,n+1) fr(j,0,n+1) dp[i][j]=0;

	// fr(i,1,n+1){
	// 	fr(j,1,n+1){
	// 		if(x[i-1]==y[j-1] && i!=j)
	// 			dp[i][j] = 1 + dp[i-1][j-1];
	// 		else
	// 			dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
	// 		cout<<dp[i][j]<<" ";
	// 	}cout<<endl;
	// }

	// cout<<dp[n][n]<<endl;

	// string ans = "";
	// int i=n,j=n;
	// while (i>0 &&j> 0)
	// {
	//     debug(mp(i,j));
	//     if (dp[i][j] == dp[i-1][j-1] + 1){
	//        ans = x[i-1]+ans;
	//        i--;
	//        j--;
	//     }else{
	//     	if (dp[i][j]== dp[i-1][j])
	//         	i--;
	//     	else
	//         	j--;
	//     }
	//     debug(mp(i,j));
	// }
	// cout<<ans<<endl;

	// 10 -> sequence pattern matching
	// determine if the str a is the subsequence of the b
	// return a.sz()==LCS(a,b)

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