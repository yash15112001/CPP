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
vector<int> adjlist[N];

vector<int> sts(N);
vector<int> val(N);

void DFS(int vertex,int p){
	sts[vertex]+=val[vertex];
	for(auto c:adjlist[vertex]){
		if(c==p) continue;
		DFS(c,vertex);
		sts[vertex]+=sts[c];
	}
}

void BFS(int source,int p){
	queue<int> q;
	q.push(source);
	while(!q.empty()){
		int v=q.front();
		q.pop();
		cout<<v<<" ";
		for(auto c:adjlist[v]){
			if(c!=p){
				q.push(c);
			}
		}
	}
}

void solve()
{	
	// edge deletion using the DFS
	int n,v1,v2,p;cin>>n;
	vector<pair<int,int>> x;
	fr(i,0,n-1){
		cin>>v1>>v2;
		x.pb(mp(v1,v2));
		adjlist[v1].pb(v2);
		adjlist[v2].pb(v1);
	}
	// fr(i,1,n+1)
	// 	cin>>val[i];

	// DFS(1,0);

	// int ans=int_min;
	// fr(i,0,n-1){
	// 	v1=x[i].f;
	// 	v2=x[i].s;
	// 	p=(sts[v2])*(sts[1]-sts[v2]);
	// 	ans=max(ans,p);
	// }
	// cout<<ans;

	// BFS -> breadth first search -> level order traversal
	
	// tree      	    1
	//                 / \
	//                /   \
	//               /     \
	//              2       3
	//             / \     / \
	//            4   5   6   7     BFS = 1 2 3 4 5 6 7  , DFS = 1 2 4 5 3 6 7

	BFS(1,0);
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