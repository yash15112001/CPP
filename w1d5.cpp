#include<bits/stdc++.h>
using namespace std;
#define fr(i,a,n) for(auto i=a;i<n;i++)
#define rf(i,n,a) for(auto i=n;i>a;i--)
#define pb push_back
#define ppb pop_back
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

int binexpo(int a,int b,int m){int ans=1;while(b){if(b&1) ans=(ans*1ll*a)%m; a=(a*1ll*a)%m; b>>=1;} return ans;}
int MMI(int a){return binexpo(a,M-2,M);}

void _print(int x){ cerr<<x; }
void _print(float x){ cerr<<x; }
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

const int N = 1e4+353;

// vector<int> adjlist[N];
// vector<int> vis(N);
// vector<int> level(N);

int vis[N][N];
int level[N][N];

int getx(string s){
	return s[0]-'a';
}
int gety(string s){
	return s[1]-'1';
}
vector<pair<int,int>> movements = {
	{1,2} , {2,1} , {1,-2} , {2,-1} , {-2,1} , {-1,2} , {-1,-2} , {-2,-1}
};

bool isvalid(int x,int y){
	return (x>=0 && x<8 && y>=0 && y<8);
}

int BFS(string sp,string dp){
	int s_x=getx(sp);
	int s_y=gety(sp);
	int d_x=getx(dp);
	int d_y=gety(dp);

	queue<pair<int,int>> q;
	q.push({s_x,s_y});
	vis[s_x][s_y]=1;

	while(!q.empty()){
		auto cv=q.front();
		q.pop();
		int x=cv.f,y=cv.s;
		for(auto m:movements){
			int c_cv_x=m.f+x;
			int c_cv_y=m.s+y;

			if(!isvalid(c_cv_x,c_cv_y)) continue;
			if(!vis[c_cv_x][c_cv_y]){
				q.push(mp(c_cv_x,c_cv_y));
				vis[c_cv_x][c_cv_y] =1;
				level[c_cv_x][c_cv_y]=level[x][y]+1;
			}
		}
	}
	return level[d_x][d_y];
}

// void BFS(int source){
// 	queue<int> q;
// 	q.push(source);
// 	vis[source]=1;

// 	while(!q.empty()){ 
// 		int cv=q.front();
// 		q.pop();
// 		cout<<cv<<" ";
// 		for(auto c:adjlist[cv]){
// 			if(!vis[c]){
// 				q.push(c);
// 				vis[c]=1;
// 				level[c]=level[cv]+1;
// 			}
// 		}
// 	}
// }

// void BFS(int vertex){
// 	queue<int> q;
// 	q.push(vertex);
// 	vis[vertex]=1;

// 	while(!q.empty()){
// 		int cv=q.front();
// 		q.pop();
// 		cout<<cv<<" ";
// 		for(auto c:adjlist[cv]){
// 			if(!vis[c]){
// 				q.push(c);
// 				vis[c]=1;
// 				level[c]=level[cv]+1;
// 			}
// 		}
// 	}
// }

void solve()
{	
	// int n,m,v1,v2;cin>>n>>m;
	// fr(i,0,m){
	// 	cin>>v1>>v2;
	// 	adjlist[v1].pb(v2);
	// 	adjlist[v2].pb(v1);
	// }

	// BFS(1);
	// cout<<endl;	// cout<<10<<endl;

	// fr(i,1,n+1){
	// 	cout<<"level of node "<<i<<" -> "<<level[i]<<endl;
	// }

	// shortest path using the BFS -> ( level orders ) => level = shortest path ?
	// shortest path from node1 to node2 = abs(diff of level of the nodes)

	// SPOJ NAKANJ
	// given two positions on the chess board -> find the minimum no of jumps require to go from squre 1 to squre 2 using the knight  

	// string sp,dp;
	// cin>>sp>>dp;
	// cout<<BFS(sp,dp);
	
	srand(time(0));
	// char c1=char(97+(rand()%8));
	// string c2=to_string((rand()%8)+1);
	// string s1=c1+c2;
	// char c3=char(97+(rand()%8));
	// string c4=to_string((rand()%8)+1);
	// string s2=c3+c4;
	// cout<<s1<<" "<<s2<<" "<<BFS(s1,s2)<<endl;
	float x,y;
	int c=0,s=0;
	fr(i,0,100000){
		x=(rand()%1000000)/1000000.0;
		y=(rand()%1000000)/1000000.0;
		// debug(mp(x,y));
		// debug(x*x+y*y)
		if((x*x+y*y)<=1) c++;
		s++;
	}
	debug(mp(c,s))
	cout<<c<<" "<<s<<endl;
	cout<<4.00*(c/(1.00*s))<<endl;
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