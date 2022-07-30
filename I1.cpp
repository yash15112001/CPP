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

// void solve(int i,int j,int n,vector<string>& ans,vector<vector<int>>& vis,vector<vector<int>>& maze,string path,vector<vector<int>>& allpaths){
// 	if(i==j && j==n-1 && maze[i][j]){
// 		ans.pb(path);
// 		allpaths[i][j]=1;
// 		return ;
// 	}
// 	if(i<0 || i>=n || j<0 || j>=n || maze[i][j]!=1 || vis[i][j]) return;
// 	vis[i][j]=1;
// 	allpaths[i][j]=1;
// 	solve(i+1,j,n,ans,vis,maze,path+'D',allpaths);
// 	solve(i,j+1,n,ans,vis,maze,path+'R',allpaths);
// 	solve(i,j-1,n,ans,vis,maze,path+'L',allpaths);
// 	solve(i-1,j,n,ans,vis,maze,path+'U',allpaths);
// 	vis[i][j]=0;
// }

// bool issafe(int r,int c,int n,vector<vector<int>>& board){
// 	int x=r,y=c;
// 	while(y>=0){
// 		if(board[x][y]==1) return false;
// 		y--;
// 	}
// 	x=r,y=c;
// 	while(x>=0 && y>=0){
// 		if(board[x][y]==1) return false;
// 		y--;
// 		x--;
// 	}
// 	x=r,y=c;
// 	while(x<n && y>=0){
// 		if(board[x][y]==1) return false;
// 		y--;
// 		x++;
// 	}
// 	return true;
// }

// void solve(int c,vector<vector<int>>& ans,int n,vector<vector<int>>& board){
// 	if(c==n){
// 		vector<int> temp;
// 		fr(i,0,n){
// 			fr(j,0,n){
// 				if(board[i][j])
// 					temp.pb(j+1);
// 			}
// 		}
// 		ans.pb(temp);
// 		return;
// 	}

// 	// current col -> c
// 	fr(r,0,n){
// 		if(issafe(r,c,n,board)){
// 			board[r][c]=1;
// 			solve(c+1,ans,n,board);
// 			board[r][c]=0;
// 		}
// 	}
// }

bool issafe(int r,int c,int v,vector<vector<int>>& b){
	fr(i,0,9){
		if(b[r][i]==v || b[i][c]==v || b[3*(r/3)+i/3][3*(c/3)+i%3]==v) return false;
	}
	return true;
}

bool sudoku(vector<vector<int>>& b){
	fr(i,0,9) fr(j,0,9)
	if(b[i][j]==0){
		fr(k,1,10){
			if(issafe(i,j,k,b)){
				b[i][j]=k;
				bool x = sudoku(b);
				if(x) return true;
				else{
					b[i][j]=0;
				}
			}
		}
		return false;
	}
	return true;
}

void solve()
{	
	// rat in maze (print paths in form of D,R,L,U and in maze)
	
	// int n;cin>>n;
	// vector<vector<int>> maze(n,vector<int>(n));
	// fr(i,0,n){
	// 	fr(j,0,n){
	// 		cin>>maze[i][j];
	// 	}
	// }
	// vector<vector<int>> vis(n,vector<int>(n,0));
	// vector<vector<int>> allpaths(n,vector<int>(n,0));
	// vector<string> ans;
	// string path = "";
	// solve(0,0,n,ans,vis,maze,path,allpaths);

	// for(auto s:ans) cout<<s<<" ";
	// cout<<endl;

	// fr(i,0,n){
	// 	fr(j,0,n){
	// 		cout<<allpaths[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	// time : O(4^(n*n)) , space : O(n*n)

	// placing N Queens on board of NxN

	// int n;cin>>n;
	// vector<vector<int>> board(n,vector<int>(n,0));
	// vector<vector<int>> ans;
	// solve(0,ans,n,board);
	// for(auto v:ans){
	// 	for(auto e:v){
	// 		cout<<e<<" ";
	// 	}
	// 	cout<<endl;
	// } 

	// sudoku solver

	vector<vector<int>> b(9,vector<int>(9));
	fr(i,0,9) fr(j,0,9) cin>>b[i][j];

	bool x = sudoku(b);

	fr(i,0,9){
		fr(j,0,9){
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}
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