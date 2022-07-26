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
#define all(x) x.begin(),x.end()
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

void _print(char x){ cerr<<x; }
void _print(int x){ cerr<<x; }
void _print(string x){ cerr<<x; }
void _print(string x,int a,int b){ cerr<<"["; for(int i=a;i<b;i++){char t=x[i];_print(t);cerr<<" ";} cerr<<"]";}
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

// int mcm(vector<int>& v,int i,int j){
// 	if(i>=j) return 0;
// 	int ans = int_max;
// 	for(int k=i;k<j;k++){
		
// 		int t=mcm(v,i,k)+mcm(v,k+1,j)+v[i-1]*v[k]*v[j];
// 		ans = min(ans,t);


// 		// ans = min(ans ,mcm(v,i,k)+mcm(v,k+1,j)+v[i-1]*v[k]*v[j]);
// 	}
// 	return ans;
// }

// int dp[10001][10001];
// vector<vector<int>> dp2(10001,vector<int>(10001,45));

// int memmcm(vector<int>& v,int i,int j){
// 	if(i>=j) return 0;
// 	if(dp[i][j]!=-1) return dp[i][j];
// 	int ans = int_max;
// 	fr(k,i,j){
// 		int t = v[i-1]*v[k]*v[j] + memmcm(v,i,k) + memmcm(v,k+1,j);
// 		// ans = min(ans , v[i-1]*v[k]*v[j]+mcm(v,i,k)+mcm(v,k+1,j));
// 		ans = min(ans,t);
// 	}
// 	// dp[i][j]=ans;
// 	return dp[i][j]=ans;
// }

// bool ispalindrome(string s,int i,int j){
// 	for(int k=0;k<=(j-i)/2;k++){
// 		if(s[i+k]!=s[j-k]) return false;
// 	}
// 	return true;
// }

// int palidromepartition(string s,int i,int j){
	
// 	if( i>=j  ) return 0;
// 	if(ispalindrome(s,i,j)){
// 		fr(k,i,j) cout<<s[k];
// 		cout<<endl;
// 		return 0;
// 	}
// 	int ans = int_max,c;

// 	for(int k=i;k<j;k++){
// 		c = 1+palidromepartition(s,i,k)+palidromepartition(s,k+1,j);
// 		ans = min(ans,c);
// 		debug(ans)
// 	}

// 	return ans;
// }

// int ppmem(string s,int i,int j){
// 	if(i>=j || ispalindrome(s,i,j)) return 0;
// 	if(dp[i][j]!=-1) return dp[i][j];

// 	int ans = int_max;

// 	fr(k,i,j){
// 		int t = ppmem(s,i,k) + ppmem(s,k+1,j) + 1;
// 		ans = min(ans,t);
// 	}

// 	return dp[i][j]=ans;
// }

// int ppmemopt(string s,int i,int j){
// 	if(i>=j || ispalindrome(s,i,j)) return 0;
// 	if(dp[i][j]!=-1) return dp[i][j];

// 	int ans = int_max;
// 	fr(k,i,j){
// 		int left,right;
// 		if(dp[i][k]!=-1){
// 			left = dp[i][k];
// 		}else{
// 			left = ppmemopt(s,i,k);
// 			dp[i][k] = left;
// 		}
// 		if(dp[k+1][j]!=-1){
// 			right = dp[k+1][j];
// 		}else{
// 			right = ppmemopt(s,k+1,j);
// 			dp[k+1][j] = right;
// 		}
// 		int t = 1 + left + right;
// 		ans = min(ans,t);
// 	}
// 	return dp[i][j]=ans;
// }

int evaluate(string s,int i,int j,bool b){
	if(i>j) return 0;
	if(i==j){
		if(b){
			return s[i]=='T';
		}else{
			return s[i]=='F';
		}
	}
	int ans=0;

	for(int k=i+1;k<j;k=k+2){
		int lt = evaluate(s,i,k-1,1);
		int lf = evaluate(s,i,k-1,0);
		int rt = evaluate(s,k+1,j,1);
		int rf = evaluate(s,k+1,j,0);

		if(s[k]=='&'){
			if(b){
				ans = ans + lt*rt;
			}else{
				ans = ans + lt*rf + lf*rt + lf*rf;
			}
		}else if(s[k]=='|'){
			if(b){
				ans = ans + lt*rt + lt*rf + lf*rt;
			}else{
				ans = ans + lf*rf;
			}
		}else{
			if(b){
				ans = ans + lt*rf + lf*rt;
			}else{
				ans = ans + lt*rt + lf*rf;
			}
		}
	}
	return ans;
}

// int dp[1001][1001][2];

// int evaluatemem(string s,int i,int j,bool b){
// 	if(i>j) return 0;
// 	if(i==j){
// 		if(b) return s[i]=='T';
// 		else return s[i]=='F';
// 	}
// 	if(dp[i][j][b]!=-1) return dp[i][j][b];

// 	int ans = 0;

// 	for(int k=i+1;k<j;k=k+2){
// 		int lt = evaluatemem(s,i,k-1,1);
// 		int lf = evaluatemem(s,i,k-1,0);
// 		int rt = evaluatemem(s,k+1,j,1);
// 		int rf = evaluatemem(s,k+1,j,0);

// 		if(s[k]=='&'){
// 			if(b){
// 				ans = ans + lt*rt;
// 			}else{
// 				ans = ans + lt*rf + lf*rt + lf*rf;
// 			}
// 		}else if(s[k]=='|'){
// 			if(b){
// 				ans = ans + lt*rt + lt*rf + lf*rt;
// 			}else{
// 				ans = ans + lf*rf;
// 			}
// 		}else{
// 			if(b){
// 				ans = ans + lt*rf + lf*rt;
// 			}else{
// 				ans = ans + lt*rt + lf*rf;
// 			}
// 		}
// 	}
// 	return dp[i][j][b]=ans;
// }

// :) :()
// unordered_map<string,int> m;

// int evaluatemem(string s,int i,int j,int b){
// 	if(i>j) return 0;
// 	if(i==j){
// 		if(b) return s[i]=='T';
// 		else return s[i]=='F';
// 	}
// 	string t = to_string(i)+"_"+to_string(j)+"_"+to_string(b);
// 	if(m.find(t)!=m.end())return m[t];
// 	// if(dp[i][j][b]!=-1) return dp[i][j][b];

// 	int ans = 0;

// 	for(int k=i+1;k<j;k=k+2){
// 		int lt = evaluatemem(s,i,k-1,1);
// 		int lf = evaluatemem(s,i,k-1,0);
// 		int rt = evaluatemem(s,k+1,j,1);
// 		int rf = evaluatemem(s,k+1,j,0);

// 		if(s[k]=='&'){
// 			if(b){
// 				ans = ans + lt*rt;
// 			}else{
// 				ans = ans + lt*rf + lf*rt + lf*rf;
// 			}
// 		}else if(s[k]=='|'){
// 			if(b){
// 				ans = ans + lt*rt + lt*rf + lf*rt;
// 			}else{
// 				ans = ans + lf*rf;
// 			}
// 		}else{
// 			if(b){
// 				ans = ans + lt*rf + lf*rt;
// 			}else{
// 				ans = ans + lt*rt + lf*rf;
// 			}
// 		}
// 	}
// 	// return dp[i][j][b]=ans;
// 	return m[t]=ans;
// }

// bool scrambled(string a,string b){
// 	if(a.sz()!=b.sz()) return 0;
// 	if(a==b) return 1;
// 	if(a.sz()<2) return 0;

// 	bool ans=false;
// 	int n = a.sz();
// 	for(int i=1;i<n;i++){
// 		bool c1 = scrambled(a.substr(0,i),b.substr(n-i,i)) && scrambled(a.substr(i,n-i),b.substr(0,n-i));
// 		bool c2 = scrambled(a.substr(0,i),b.substr(0,i)) && scrambled(a.substr(i,n-i),b.substr(i,n-i));
// 		if( c1 || c2 ){
// 			ans = true;
// 			break;
// 		}
// 	}
// 	return ans;
// }

// bool checker(string a,string b){
// 	map<char,int> m1,m2;

// 	for(auto c:a) m1[c]++;
// 	for(auto c:b) m2[c]++;
// 	auto it1=m1.begin(),it2=m2.begin();
// 	bool bb=true;

// 	debug(m1)
// 	debug(m2)

// 	return m1==m2;
// 	while(it1!=m1.end() && it2!=m2.end()){
// 		if(it1->f==it2->f && it1->s==it2->s){
// 			it1++;
// 			it2++;
// 		}else{
// 			bb=false;
// 			break;
// 		}
// 	}
// 	return bb;
// }

// unordered_map<string,bool> m;

// bool scrambledmem(string a,string b){
// 	if(a.sz()!=b.sz()) return 0;
// 	if(a==b) return 1;
// 	if(a.sz()<2) return 0;

// 	string t = a+"_"+b;
// 	if(m.find(t)!=m.end()) return m[t];

// 	int n = a.sz();
// 	int ans = false;
// 	for(int i=1;i<n;i++){
// 		bool c1 = scrambledmem(a.substr(0,i),b.substr(n-i,i)) && scrambledmem(a.substr(i,n-i),b.substr(0,n-i)); 
// 		bool c2 = scrambledmem(a.substr(0,i),b.substr(0,i)) && scrambledmem(a.substr(i,n-i),b.substr(i,n-i));
// 		if(c1||c2){
// 			ans = true;
// 			break;
// 		}
// 	}
// 	return m[t]=ans;
// }

// int eggdrop(int e,int f){
// 	if(e==0||f==0||f==1) return f;
// 	int ans = int_max;
// 	fr(k,1,f+1){
// 		int t = 1+max(eggdrop(e-1,k-1),eggdrop(e,f-k));
// 		ans = min(ans,t);
// 	}
// 	return ans;
// }

int dp[10001][10001];

// int eggdropmem(int e,int f){
// 	if(e==0||f==0||f==1) return f;
// 	if(dp[e][f]!=-1) return dp[e][f];
// 	int ans = int_max;
// 	fr(k,1,f+1){
// 		int t = 1+max(eggdropmem(e-1,k-1),eggdropmem(e,f-k));
// 		ans = min(ans,t);
// 	}
// 	return dp[e][f]=ans;
// }

int eggdropmemopt(int e,int f){
	if(e==0||f==0||f==1) return f;
	if(dp[e][f]!=-1) return dp[e][f];
	int ans = int_max;
	fr(k,1,f+1){
		int l,h;
		if(dp[e-1][k-1]!=-1)
			l = dp[e-1][k-1];
		else{
			l = eggdropmemopt(e-1,k-1);
			dp[e-1][k-1] = l;
		}
		if(dp[e][f-k]!=-1)
			h = dp[e][f-k];
		else{
			h = eggdropmemopt(e,f-k);
			dp[e][f-k] = h;
		}
		int t = 1+max(l,h);
		ans = min(ans,t);
	}
	return dp[e][f]=ans;
}

void solve()
{	
	// Matrix chain multiplication - MCM

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	
	// recursive
	
	// int i=1,j=n-1;
	// int ans = mcm(v,i,j);
	// cout<<ans<<endl;

	// bottom-up (memoize)
	// int dp[n+1][n+1];
	// memset(dp,-1,sizeof(dp));
	// int ans = memmcm(v,1,n-1);
	// cout<<ans<<endl;
	// fr(i,0,n+1){
	// 	fr(j,0,n+1){
	// 		cout<<dp[i][j]<<" ";
	// 	}cout<<endl;
	// }

	// 1 -> palindrome partitioning recursive

	// string s;cin>>s;
	// // memset(dp,-1,sizeof(dp));
	// cout<<ispalindrome(s,0,s.sz()-1);
	// int ans = palidromepartition(s,0,s.sz()-1);
	// cout<<ans;

	// 2 -> palindrome partitioning memoize

	// string s;cin>>s;
	// memset(dp,-1,sizeof(dp));
	// cout<<ppmem(s,0,s.sz()-1);

	// 3 -> palindrome partitioning memioze optimized

	// string s;cin>>s;
	// memset(dp,-1,sizeof(dp));
	// cout<<ppmemopt(s,0,s.sz()-1);

	// cout<<endl;

	// fr(i,1,s.sz()+1){
	// 	fr(j,1,s.sz()+1){
	// 		cout<<dp[i][j]<<" ";
	// 	}cout<<endl;
	// }

	// 4 -> no of ways to evaluate the boolean expression to true -- recursive

	string s;cin>>s;
	int ans = evaluate(s,0,s.sz()-1,1);
	cout<<ans<<endl;

	// 5 -> no of ways to evalute the boolean expression to true -- memoized ( 3d array/unordered_map )

	// string s;cin>>s;
	// // memset(dp,-1,sizeof(dp));
	// int ans = evaluatemem(s,0,s.sz()-1,1);
	// cout<<ans<<endl;

	// **6 -> Scrambled string
	// string a,b;cin>>a>>b;
	// bool ans = scrambled(a,b);
	// cout<<ans<<endl;

	// bool ans1 = checker(a,b);
	// cout<<ans1<<endl;

	// **7 -> scrambled string memoized -- ( use of the unordered_map )
	// string a,b;cin>>a>>b;
	// bool ans = scrambledmem(a,b);
	// cout<<ans<<endl;

	// 8 -> egg dropping 
	// int e,f;cin>>e>>f;
	// int ans = eggdrop(e,f);
	// cout<<ans;

	// 9 -> egg dropping memoized
	// int e,f;cin>>e>>f;
	// memset(dp,-1,sizeof(dp));
	// int ans = eggdropmem(e,f);
	// cout<<ans; 

	// 10 -> egg dropping memoized optimized 
	// int e,f;cin>>e>>f;
	// memset(dp,-1,sizeof(dp));
	// int ans = eggdropmemopt(e,f);
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