#include<bits/stdc++.h>
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

const int N = 1001;
int a[N][N];
vector<vector<int>> adjmat(N,vector<int>(N,INT_MAX));
// vector<pair<int,int>> edges(N);
// int grid[N][N],visgrid[N][N];
vector<int> adjlist[N],revadjlist[N],adjlist2[N],cadjlist[N];
vector<int> vis(N),dfsvis(N),height(N),depth(N),level(N),d(N,INT_MIN);
// vector<int> subtreesum(N),evens(N),parent1(N);
vector<int> parent(N),size(N),color(N),indegree(N);
int lca[N][N];

// bool dfs(int v){
// 	vis[v]=1;
// 	dfsvis[v]=1;
// 	for(auto c:adjlist[v]){
// 		if(!vis[c]) {if(dfs(c)) return true;}
// 		else if(dfsvis[c]) return true;
// 	}
// 	dfsvis[v]=0;
// 	return false;
// }

// bool isvalid(int i,int j,int n){return (i>=1 && i<=n && j>=1 && j<=n);}
// // int vis[9][9];

// void bfs(int si,int sj,int ei,int ej,int n){
// 	cout<<si<<" "<<sj<<" "<<ei<<" "<<ej<<endl;
// 	vector<pair<int,int>> move = {{1,2},{2,1},{1,-2},{-2,1},{-1,2},{-1,-2},{-2,-1},{2,-1}};
// 	vector<vector<int>> level(n+1,vector<int>(n+1,INT_MAX)),vis(n+1,vector<int>(n+1,0));
// 	queue<pair<int,int>> q;
// 	q.push(mp(si,sj));
// 	vis[si][sj]=1;
// 	level[si][sj]=0;
// 	// cout<<q.front().f<<" "<<q.front().s<<endl;

// 	// fr(i,0,9) {{fr(j,0,9) cout<<vis[i][j]<<" ";}cout<<endl;}

// 	while(!q.empty()){
// 		auto cv = q.front();
// 		q.pop();
// 		if(cv.f==ei && cv.s==ej) break;
// 		for(int i=0;i<8;i++){
// 			int new_i = move[i].f+cv.f;
// 			int new_j = move[i].s+cv.s;

// 			if(!isvalid(new_i,new_j,n)) continue;
// 			if(vis[new_i][new_j]) continue;
// 			if(level[cv.f][cv.s]+1<level[new_i][new_j]){
// 				level[new_i][new_j] = level[cv.f][cv.s]+1;
// 				q.push(mp(new_i,new_j));
// 				vis[new_i][new_j]=1;
// 			}
// 		}
// 		// if(level[ei][ej]!=int_max) break;
// 	}
// 	fr(i,1,n+1) {{fr(j,1,n+1) if(level[i][j]==INT_MAX)cout<<"I ";else cout<<level[i][j]<<" ";}cout<<endl;}
// 	cout<<level[ei][ej]<<endl;
// }

// bool isvalid(int i,int j,int n,int m) {return (i>=0 && i<n && j>=0 && j<m);}

// void bfs(vector<vector<int>>& image,int si,int sj,int c){
// 	queue<pair<int,int>> q;
// 	q.push(mp(si,sj));
// 	vector<pair<int,int>> mm = { {1,0},{-1,0},{0,1},{0,-1} };
// 	int n = image.sz(),m = image[0].sz();
// 	int vis[n][m];
// 	fr(i,0,n) fr(j,0,m) vis[i][j]=0;
// 	vis[si][sj]=1;

// 	while(!q.empty()){
// 		auto cv = q.front();
// 		q.pop();
// 		debug(cv)
// 		image[cv.f][cv.s]=c;
// 		for(auto p:mm){
// 			int new_i = cv.f + p.f;
// 			int new_j = cv.s + p.s;
// 			if(!isvalid(new_j,new_j,n,m)) continue;
// 			if(!vis[new_i][new_j] && image[new_i][new_j]==1){
// 				q.push(mp(new_i,new_j));
// 				vis[new_i][new_j]=1;
// 			}		
// 		}
// 	}
// }

// vector<pair<int,int>> dfsedges;
// void dfs(int v){
// 	vis[v]=1;
// 	for(auto c:adjlist[v]){
// 		if(vis[c]) continue;
// 		dfsedges.pb(mp(v,c));
// 		dfs(c);
// 	}
// }

// int check(string a,string b){
// 	int d=0;
// 	int n=a.sz();
// 	fr(i,0,n){
// 		if(a[i]!=b[i])d++;
// 		if(d==2) break;
// 	}
// 	return d;
// }

// unordered_map<string,int> l;
// void dfs(string s,unordered_map<string,set<string>> m){
// 	queue<string> q;
// 	q.push(s);
// 	// viss[s]=1;
// 	l[s]=1;

// 	while(!q.empty()){
// 		auto cv = q.front();
// 		q.pop();
// 		for(auto c:m[cv]){
// 			if(l[cv]+1<l[c]){
// 				l[c]=1+l[cv];
// 				q.push(c);
// 			}
// 		}
// 	}
// }

// int ladder(string a,string b,vector<string> v){
// 	unordered_set<string> s(v.begin(),v.end());
// 	int ans=1;
// 	queue<string> q;
// 	q.push(a);
// 	debug(s)
// 	debug(q)

// 	while(!q.empty()){
// 		int n = q.sz();
// 		fr(i,0,n){
// 			auto cv = q.front();
// 			q.pop();
// 			if(cv==b) return ans;
// 			s.erase(cv);
// 			fr(j,0,cv.sz()){
// 				char x = cv[j];
// 				fr(k,0,26){
// 					cv[j]='a'+k;
// 					if(s.find(cv)!=s.end()) q.push(cv);
// 				}
// 				cv[j]=x;
// 			}
// 		}
// 		ans++;
// 		debug(q)
// 	}
// 		// debug(q)

// 	return 0;	
// }

// void dfs(int v,int &k){
// 	vis[v]=1;
// 	k++;
// 	for(auto c:adjlist[v]){
// 		if(!vis[c]) dfs(c,k);
// 	}
// }

// int gcd(int a,int b){
// 	if(b==0) return a;
// 	return gcd(b,a%b);
// }

// bool canfill(int a,int b,int c){
// 	if(a+b<c || max(a,b)<c) return false;
// 	if(a==c || b==c || a+b==c) return true;
// 	return c%gcd(a,b)==0;
// }

// vector<string> bfsfill(int a,int b,int c){
// 	queue<string> q;
// 	unordered_map<string,ll> level;
// 	unordered_map<string,string> parent;
// 	string f = "0_0";
// 	parent[f] = "-1";
// 	level[f] = 0;
// 	q.push(f);

// 	while(!q.empty()){
// 		auto cv = q.front();
// 		q.pop();
// 		stringstream ss(cv);
// 		string s1,s2;
// 		getline(ss,s1,'_');
// 		getline(ss,s2,'_');
// 		int x = stoi(s1),y = stoi(s2);
// 		if((x==c && y==0)||(x==0 && y==c)) break;

// 		/*
// 		x,y -> a,y
// 		x,y -> x,b
// 		x,y -> 0,y
// 		x,y -> x,0
// 		x,y -> a,y-(a-x) if(x+y>=a)
// 		x,y -> x-(b-y),b if(x+y>=b)
// 		x,y -> x+y,0 if(x+y<=a)
// 		x,y -> 0,x+y if(x+y<=b)
// 		*/

// 		if(x<a && level.find(to_string(a)+"_"+to_string(y))==level.end()){
// 			level[to_string(a)+"_"+to_string(y)] = level[cv]+1;
// 			parent[to_string(a)+"_"+to_string(y)] = cv;
// 			q.push(to_string(a)+"_"+to_string(y));
// 		}
// 		if(y<b && level.find(to_string(x)+"_"+to_string(b))==level.end()){
// 			level[to_string(x)+"_"+to_string(b)] = level[cv]+1;
// 			parent[to_string(x)+"_"+to_string(b)] = cv;
// 			q.push(to_string(x)+"_"+to_string(b));
// 		}
// 		if(level.find(to_string(0)+"_"+to_string(y))==level.end()){
// 			level[to_string(0)+"_"+to_string(y)] = level[cv]+1;
// 			parent[to_string(0)+"_"+to_string(y)] = cv;
// 			q.push(to_string(0)+"_"+to_string(y));
// 		}
// 		if(level.find(to_string(x)+"_"+to_string(0))==level.end()){
// 			level[to_string(x)+"_"+to_string(0)] = level[cv]+1;
// 			parent[to_string(x)+"_"+to_string(0)] = cv;
// 			q.push(to_string(x)+"_"+to_string(0));
// 		}
// 		if(x+y>=a && level.find(to_string(a)+"_"+to_string(y-a+x))==level.end()){
// 			level[to_string(a)+"_"+to_string(y-a+x)] = level[cv]+1;
// 			parent[to_string(a)+"_"+to_string(y-a+x)] = cv;
// 			q.push(to_string(a)+"_"+to_string(y-a+x));
// 		}
// 		if(x+y>=b && level.find(to_string(x-b+y)+"_"+to_string(b))==level.end()){
// 			level[to_string(x-b+y)+"_"+to_string(b)] = level[cv]+1;
// 			parent[to_string(x-b+y)+"_"+to_string(b)] = cv;
// 			q.push(to_string(x-b+y)+"_"+to_string(b));
// 		}
// 		if(x+y<=a && level.find(to_string(x+y)+"_"+to_string(0))==level.end()){
// 			level[to_string(x+y)+"_"+to_string(0)] = level[cv]+1;
// 			parent[to_string(x+y)+"_"+to_string(0)] = cv;
// 			q.push(to_string(x+y)+"_"+to_string(0));
// 		}
// 		if(x+y<=b && level.find(to_string(0)+"_"+to_string(x+y))==level.end()){
// 			level[to_string(0)+"_"+to_string(x+y)] = level[cv]+1;
// 			parent[to_string(0)+"_"+to_string(x+y)] = cv;
// 			q.push(to_string(0)+"_"+to_string(x+y));
// 		}
// 	}

// 	vector<string> ans;
// 	int l1 = INT_MAX,l2 = INT_MAX;
// 	if(level.find(to_string(0)+"_"+to_string(c))!=level.end()) l1 = level[to_string(0)+"_"+to_string(c)];
// 	if(level.find(to_string(c)+"_"+to_string(0))!=level.end()) l2 = level[to_string(c)+"_"+to_string(0)];
// 	if(l1<l2){
// 		string aa = to_string(0)+"_"+to_string(c);
// 		while(level[aa]!=0){
// 			ans.pb(aa);
// 			aa=parent[aa];
// 		}
// 	}
// 	else{
// 		string aa = to_string(c)+"_"+to_string(0);
// 		while(level[aa]!=0){
// 			ans.pb(aa);
// 			aa=parent[aa];	
// 		}
// 	}
// 	reverse(all(ans));
// 	return ans;
// }

// void dfs(int i,int j,int n,vector<vector<int>> maze,string s,vector<vector<int>>& vis){
// 	if(i<0 || i>=n || j<0 || j>=n || vis[i][j] || !maze[i][j]) return;
// 	if(i==j && i==n-1){
// 		cout<<s<<endl;
// 		return;
// 	}
// 	vis[i][j]=1;
// 	dfs(i+1,j,n,maze,s+"D",vis);
// 	dfs(i,j+1,n,maze,s+"R",vis);
// 	dfs(i-1,j,n,maze,s+"U",vis);
// 	dfs(i,j-1,n,maze,s+"L",vis);
// 	vis[i][j]=0;
// }

// **************************************************************************************

// class node{
// public:
// 	int data;
// 	vector<node*> adj;
// 	node(){
// 		data=0;
// 		adj = vector<node*>();
// 	}
// 	node(int a){
// 		data=a;
// 		adj = vector<node*>();
// 	}
// 	node(int a,vector<node*> n){
// 		data=a;
// 		adj=n;
// 	}
// };

// void dfs(node* nr,node* r,vector<node*>& vis){
// 	vis[nr->data] = nr;
// 	for(auto c:r->adj){
// 		if(vis[c->data]==null){
// 			node* x = new node(c->data);
// 			nr->adj.pb(x);
// 			dfs(x,c,vis);
// 		}
// 		else{
// 			nr->adj.pb(vis[c->data]);
// 		}
// 	}
// }

// node* clone(node* root){
// 	if(root==null) return root;
// 	vector<node*> vis(10000,null);
// 	node* newroot = new node(root->data);
// 	dfs(newroot,root,vis);
// 	return newroot;
// }

// void dfs1(node* r,vector<int>& vis){
// 	vis[r->data] = r->data;
// 	cout<<r->data<<" ";
// 	for(auto c:r->adj){
// 		if(!vis[c->data]) dfs1(c,vis);
// 	}
// }


// void dfs2(node* r,vector<int>& vis){
// 	vis[r->data] = r->data;
// 	cout<<r->data<<" ";
// 	for(auto c:r->adj){
// 		if(!vis[c->data]) dfs2(c,vis);
// 	}
// }

// **************************************************************************************

// vector<int> mintime(int n){
// 	vector<int> ans(n+1,0);
// 	queue<int> q;
// 	vector<int> indegree(n+1,0);
// 	fr(i,1,n+1){
// 		for(auto c:adjlist[i]){
// 			++indegree[c];
// 		}
// 	}
// 	fr(i,1,n+1){
// 		if(indegree[i]==0) q.push(i);
// 	}

// 	int time = 1;
// 	while(!q.empty()){
// 		debug(q);
// 		int ss = q.sz();
// 		fr(i,0,ss){
// 			auto cv = q.front();
// 			q.pop();
// 			ans[cv]=time;
// 			for(auto c:adjlist[cv]){
// 				--indegree[c];
// 				if(indegree[c]==0) q.push(c);
// 			}
// 		}
// 		time++;
// 	}

// 	return {ans.begin()+1,ans.end()};
// }

// bool mintime(int n){
// 	// vector<int> ans(n+1,0);
// 	int ans = 0;
// 	queue<int> q;
// 	vector<int> indegree(n+1,0);
// 	fr(i,1,n+1){
// 		for(auto c:adjlist[i]){
// 			++indegree[c];
// 		}
// 	}
// 	fr(i,1,n+1){
// 		if(indegree[i]==0) q.push(i);
// 	}

// 	while(!q.empty()){
// 		int ss = q.sz();
// 		fr(i,0,ss){
// 			auto cv = q.front();
// 			q.pop();
// 			ans++;
// 			for(auto c:adjlist[cv]){
// 				--indegree[c];
// 				if(indegree[c]==0) q.push(c);
// 			}
// 		}
// 	}

// 	return ans==n;
// }

// string topologicalsort(vector<int> adjlist3[],unordered_set<char> s){
// 	string ans="";
// 	vector<int> indegree(26,0);
// 	fr(i,0,26){
// 		if(adjlist3[i].sz()){
// 			for(auto e:adjlist3[i])
// 				++indegree[e];
// 		}
// 	}
// 	queue<int> q;
// 	for(int i=0;i<26;i++){
// 		if(indegree[i]==0 && s.find(char('a'+i))!=s.end())
// 			q.push(i);
// 	}
// 	while(!q.empty()){
// 		auto cv = q.front();
// 		q.pop();
// 		ans = ans + (char)('a'+cv);
// 		for(auto c:adjlist3[cv]){
// 			--indegree[c];
// 			if(indegree[c]==0)
// 				q.push(c);
// 		}
// 	}
// 	return ans;
// }

// vector<int> size(N);

// void make(int u){
// 	parent[u]=u;
// 	size[u]=1;
// }

// int find(int u){
// 	if(u==parent[u]) return u;
// 	return parent[u]=find(parent[u]);
// }

// void Union(int u,int v){
// 	u=find(u);
// 	v=find(v);
// 	if(v!=u){
// 		if(size[u]>size[v]) swap(u,v);
// 		parent[u]=v;
// 		size[v]+=size[u];
// 	}
// }

// vector<vector<int>> findsub(vector<vector<int>>& v,int n,int p,int q){
// 	vector<vector<int>> ans;
// 	fr(i,0,n){
// 		if(i==p) continue;
// 		vector<int> t;
// 		fr(j,0,n){
// 			if(j==q) continue;
// 			t.pb(v[i][j]);
// 		}
// 		ans.pb(t);
// 	}
// 	return ans;
// }

// int determine(vector<vector<int>>& v,int n){
// 	if(n==1) return v[0][0];
// 	if(n==2) return (v[0][0]*v[1][1] - v[0][1]*v[1][0]);
// 	int ans = 0;
// 	int s = 1;
// 	fr(i,0,n){
// 		vector<vector<int>> subv = findsub(v,n,i,0);
// 		ans += s*v[i][0]*determine(subv,n-1);
// 		s = -1*s;
// 	}
// 	return ans;
// }

int tcp(int x,int src,unordered_set<int>& s){
	if(s.sz()==0) return adjmat[x][src];
	int ans = int_max;
	for(auto e:s){
		unordered_set<int> copy = s;
		copy.erase(e);
		ans = min(ans,adjmat[x][e]+tcp(e,src,copy));
	}
	return ans;
}

// int n;
// int allvis = ((1<<(n+1))-1);

// int tcp2(int x,int src,int mask,int n){
// 	if(mask==allvis){
// 		debug(mask)
// 		return adjmat[x][src];
// 	}
// 	debug(mask)
// 	int ans = int_max;
// 	unordered_set<int> ss;
// 	fr(i,1,n+1){
// 		int ithbit = mask&(1<<i);
// 		debug(ithbit)
// 		// if(ithbit==0) ss.insert(i);
// 		if( (mask&(1<<i)) == 0 ){
// 			debug(i);
// 			int newmask = mask|(1<<i);
// 			int newans = adjmat[x][i] + tcp2(i,src,newmask,n);
// 			debug(newans)
// 			ans = min(ans,newans);
// 		}
// 	}
// 	// debug(ss)
// 	// for(auto e:ss){
// 	// 	int newmask = mask|(1<<e);
// 	// 	debug(adjmat[x][e])
// 	// 	ans = min(ans,adjmat[x][e]+tcp2(e,src,newmask,n));
// 	// }
// 	return ans;
// }

// vector<int> in(N),low(N),vis(N);
// int timer;
// void bridges(int v,int p){
// 	vis[v]=1;
// 	in[v]=low[v]=timer++;
// 	for(auto c:adjlist[v]){
// 		if(c==p) continue;
// 		if(vis[c]){
// 			low[v] = min(low[v],in[c]);
// 		}else{
// 			bridges(c,v);
// 			if(in[v]<low[c]) cout<<c<<" "<<v<<endl;
// 			low[v] = min(low[v],low[c]);
// 		}
// 	}
// }

// vector<int> inorder,scc;

// void dfsin(int v){
// 	vis[v]=1;
// 	for(auto c:adjlist[v]){
// 		if(!vis[c]) dfsin(c);
// 	}
// 	inorder.pb(v);
// }

// void dfsscc(int v){
// 	vis[v]=1;
// 	for(auto c:revadjlist[v])
// 		if(!vis[c])
// 			dfsscc(c);
// 	scc.pb(v);
// }

// bool mcoloring(int v,int cc,int m){
// 	vis[v]=1;
// 	color[v]=cc;
// 	for(auto c:adjlist[v]){
// 		if(!vis[c]){
// 			bool b = false;
// 			fr(i,1,m+1){
// 				if(i!=cc){	
// 					b|=mcoloring(c,i,m);
// 				}
// 			}
// 			if(!b){
// 				vis[v]=0;
// 				return 0;
// 			}
// 		}
// 		else{
// 			if(color[v]==color[c]){
// 				vis[v]=0;
// 	  			return 0;
// 			}
// 		}
// 	}
// 	return 1;
// }

// bool check(int n,int node,int cc){
	
// 	// fr(k,1,n+1){
// 	// 	if(k!=node && )
// 	// }

// 	for(auto c:adjlist[node]){
// 		if(color[c]==cc) return 0;
// 	}
// 	return 1;
// }

// bool solvee(int n,int m,int node){
// 	if(node==n+1) return 1;
// 	fr(i,1,m+1){
// 		if(check(n,node,i)){
// 			color[node]=i;
// 			if(solvee(n,m,node+1)) return 1;
// 			color[node]=0;
// 		}
// 	}
// 	return 0;
// }

// vector<int> order;

// void dfs(int v){
// 	vis[v]=1;
// 	for(auto c:adjlist[v]){
// 		if(!vis[c.f]) dfs(c.f);
// 	}
// 	order.pb(v);
// }

void dfs(int v,int p){
	parent[v]=p;
	for(auto c:adjlist[v]){
		if(c!=p){
			level[c]=level[v]+1;
			dfs(c,v);
		}
	}
}

int LCA(int a,int b,int ln){
	if(level[a]<level[b]) swap(a,b);
	int d = level[a]-level[b];
	while(d){
		int i = log2(d);
		a = lca[a][i];
		d-=(1<<i);
	}
	if(a==b) return a;
	for(int i=ln;i>=0;i--){
		if(lca[a][i]!=-1 && lca[a][i]!=lca[b][i]){
			a=lca[a][i];
			b=lca[b][i];
		}
	}
	return parent[a];
}



void solve()
{	
	// cycle detection in directed graph
	// int n,m;cin>>n>>m;
	// fr(i,0,m){
	// 	int a,b;cin>>a>>b;
	// 	adjlist[a].pb(b);
	// }
	// bool b = dfs(1);
	// // b?cout<<1:cout<<0;
	// cout<<b?1:0;

	// minimum jumps by knight
	// int a,b,c,d,n;
	// cin>>a>>b>>c>>d>>n;
	// // cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl; 
	// bfs(a,b,c,d,n);

	// flood fill
	
	// int n,m;cin>>n>>m;
	// vector<vector<int>> image(n,vector<int>(m,0));
	// fr(i,0,n){
	// 	fr(j,0,m){
	// 		cin>>image[i][j];
	// 	}
	// }
	// int si,sj;cin>>si>>sj;
	// int c;cin>>c;

	// bfs(image,si,sj,c);
	// fr(i,0,n){
	// 	fr(j,0,m){
	// 		cout<<image[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	// clone a graph ********************************
	
	// node* a = new node(5);
	// node* b = new node(6);
	// node* c = new node(7);
	// node* d = new node(4);
	// d->adj.pb(a);
	// d->adj.pb(b);
	// d->adj.pb(c);
	// node* e = new node(2);
	// e->adj.pb(d);
	// node* f = new node(3);
	// f->adj.pb(d);
	// node* g = new node(1);
	// g->adj.pb(f);
	// g->adj.pb(e);
	// vector<int> vis2(10000,0),vis3(10000,0);
	// dfs1(g,vis2);
	// cout<<endl;
	// node* newg = clone(g);
	// dfs1(newg,vis3);
	// **********************************************

	// making weird connections
	// int n,m;cin>>n>>m;
	// fr(i,0,m){
	// 	int a,b;cin>>a>>b;
	// 	adjlist[a].pb(b);
	// 	adjlist[b].pb(a);
	// }
	// int cc=0;
	// fr(i,0,n){
	// 	if(!vis[i]){
	// 		dfs(i);
	// 		cc++;
	// 	}
	// }
	// // cout<<cc<<endl;
	// // cout<<dfsedges.sz()<<endl;
	// // for(auto p:dfsedges) cout<<p.f<<" "<<p.s<<endl;
	// if(m-dfsedges.sz()>=cc-1) cout<<c-1<<endl;
	// else cout<<-1<<endl;
	// // required edges c-1
	// // m - dfsedges.sz() >= c-1 -> ans = c-1 else -1

	// word ladder

	// approach 1 : space : O(N^2) , time : O(N^2 * K) --> N = total words , K = lenght of the word
	// string s;cin>>s;
	// int n;cin>>n;
	// vector<string> v;
	// v.pb(s);
	// l[s]=1;
	// fr(i,0,n) {string q;cin>>q;v.pb(q);l[q]=int_max;}
	// string d;cin>>d;

	// unordered_map<string,set<string>> m;
	// fr(i,0,n+1){
	// 	fr(j,0,n+1){
	// 		if(i!=j){
	// 			if(check(v[i],v[j])==1){
	// 				m[v[i]].insert(v[j]);
	// 				m[v[j]].insert(v[i]);
	// 			}
	// 		}
	// 	}
	// }
	// dfs(s,m);
	// debug(l)
	// if(l.find(d)!=l.end())
	// 	cout<<(l[d]==int_max?0:l[d])<<endl;
	// else cout<<0<<endl;

	// approach 2 : space : O(N) , time :O(N*K*26)
	// string s;cin>>s;
	// int n;cin>>n;
	// vector<string> v(n);
	// fr(i,0,n) cin>>v[i];
	// string a;cin>>a;

	// int ans = ladder(s,a,v);
	// cout<<ans;

	// journey to moon
	// int n,m;cin>>n>>m;
	// fr(i,0,m){
	// 	int a,b;cin>>a>>b;
	// 	adjlist[a].pb(b);
	// 	adjlist[b].pb(a);
	// }

	// int k=0;
	// vector<int> t;
	// fr(i,0,n){
	// 	if(!vis[i]){
	// 		k=0;
	// 		dfs(i,k);
	// 		t.pb(k);
	// 	}
	// }
	// int ans=0;
	// int a = 0;
	// if(t.sz()>=2){
	// 	// for(int i=t.sz()-2;i>=0;i--)
	// 	// 	t[i]+=t[i+1];
		
	// 	// for(int i=0;i<=t.sz()-2;i++)
	// 	// 	ans+=(t[i]-t[i+1])*t[i+1];
	// 	fr(i,0,t.sz()){
	// 		a+=t[i];
	// 		ans+=t[i]*(n-a);
	// 	}
	// }
	// cout<<ans<<endl;

	// water jug problem - true/false
	// int a,b,c;cin>>a>>b>>c;
	// bool ans = canfill(a,b,c);
	// cout<<ans?1:0;

	// water jug problem 2 : print path from 0_0 to 0_c or c_0 if possible else return -1;
	
	// int a,b,c;cin>>a>>b>>c;
	// bool bb = canfill(a,b,c);
	// cout<<gcd(a,b)<<endl;
	// cout<<bb<<endl;
	// if(bb && c<(max(a,b))){
	// 	vector<string> ans = bfsfill(a,b,c);
	// 	int xx = ans.sz();
	// 	debug(xx-1)
	// 	for(auto e:ans){
	// 		stringstream ss(e);
	// 		string s1,s2;
	// 		getline(ss,s1,'_');
	// 		getline(ss,s2,'_');
	// 		int x = stoi(s1),y = stoi(s2);
	// 		cout<<"{"<<x<<","<<y<<"} ";
	// 	}
	// }
	// else
	// 	cout<<-1;

	// search in maze
	// int n;cin>>n;
	// vector<vector<int>> a(n,vector<int>(n)),vis(n,vector<int>(n,0));
	// fr(i,0,n) fr(j,0,n) cin>>a[i][j];
	// string s="";
	// dfs(0,0,n,a,s,vis);

	// minimum time taken by each job
	// int n,m;cin>>n>>m;
	// while(m--){
	// 	int a,b;cin>>a>>b;
	// 	adjlist[a].pb(b);
	// }

	// vector<int> ans = mintime(n);
	// for(auto e:ans) cout<<e<<" ";

	// find weather it is possible to do all work given the dependancies

	// int n,m;cin>>n>>m;
	// while(m--){
	// 	int a,b;cin>>a>>b;
	// 	adjlist[a].pb(b);
	// }

	// bool ans = mintime(n);
	// ans?cout<<1:cout<<0;

	// **alien dictionary 

	// int n;cin>>n;
	// vector<string> v(n);
	// fr(i,0,n) cin>>v[i];

	// unordered_set<char> s;
	// for(auto e:v) for(auto c:e) s.insert(c);

	// vector<int> adjlist3[26];
	
	// bool b = false;
	// fr(i,0,n-1){
	// 	string s1 = v[i];
	// 	string s2 = v[i+1];

	// 	int ss1 = v[i].sz() , ss2 = v[i+1].sz();
	// 	if(ss1>ss2 && s1.substr(0,ss2)==s2){
	// 		b = true;
	// 		break;
	// 	}

	// 	fr(j,0,min(ss1,ss2)){
	// 		if(s1[j]!=s2[j]){
	// 			adjlist3[s1[j]-'a'].pb(s2[j]-'a');
	// 			break;
	// 		}
	// 	}
	// }

	// fr(i,0,26){
	// 	if(adjlist3[i].sz()){
	// 		cout<<char('a'+i)<<" -> ";
	// 		for(auto c:adjlist3[i]){
	// 			cout<<char('a'+c)<<" ";
	// 		}
	// 		cout<<endl;
	// 	}
	// }

	// if(b) cout<<"the dictionary is not ideal and there is no order of elements";
	// else{
	// 	string ans = topologicalsort(adjlist3,s);
	// 	cout<<ans<<endl;
	// }

	// kruskal's algo
	
	// int n,m;cin>>n>>m;
	// fr(i,1,n+1) make(i);
	// vector<pair<int,pair<int,int>>> edges;
	// while(m--){
	// 	int a,b,c;cin>>a>>b>>c;
	// 	adjlist[a].pb(mp(b,c));
	// 	adjlist[b].pb(mp(a,c));
	// 	edges.pb(mp(c,mp(a,b)));
	// }

	// sort(all(edges));

	// vector<pair<int,int>> tree[1+n];
	// int ans=0;
	// for(auto e:edges){
	// 	auto wt = e.f;
	// 	int u = e.s.f;
	// 	int v = e.s.s;
	// 	if(find(u)==find(v)) continue;
	// 	Union(u,v);
	// 	tree[u].pb(mp(v,wt));
	// 	tree[v].pb(mp(u,wt));
	// 	// cout<<u<<" "<<v<<" "<<wt<<endl;
	// 	ans+=wt;
	// }
	// cout<<ans<<endl;

	// // cout<<endl;
	// fr(i,1,n+1){
	// 	if(tree[i].sz()){
	// 		cout<<i<<" -> {";
	// 		for(auto pp:tree[i]){
	// 			cout<<" {"<<pp.f<<","<<pp.s<<"} ";
	// 		}
	// 		cout<<"}"<<endl;
	// 	}
	// }

	// prim's algo

	/*
	vector<int> p[N],size[N];
	void make(int u){
		p[u]=u;
		size[u]=1;
	}

	int find(int u){
		if(u==p[u]) return u;
		else return p[u]=find(p[u]);
	}

	void Union(int u,int v){
		u=find(u);
		v=find(v);
		if(v!=u){
			if(size[u]>size[v]) swap(u,v);
			p[u]=v;
			size[v]+=size[u]
		}
	}
	*/
	
	// int n,m;cin>>n>>m;
	// fr(i,0,m){
	// 	int a,b,c;cin>>a>>b>>c;
	// 	adjlist[a].pb(mp(b,c));
	// 	adjlist[b].pb(mp(a,c));
	// }
	
	// fr(i,1,n+1) make(i);
	
	// int r;
	// cin>>r;

	// set<pair<int,pair<int,int>>> s;

	// for(auto c:adjlist[r]){
	// 	s.insert(mp(c.s,mp(c.f,r)));
	// }

	// while(s.sz()>0){
	// 	auto cv = *s.begin();
	// 	s.erase(s.begin());
	// 	int wt = cv.f;
	// 	int u = cv.s.f;
	// 	int v = cv.s.s;
	// 	if(find(u)==find(v)) continue;
	// 	Union(u,v);
	// 	cout<<u<<" "<<v<<" "<<wt<<endl;
	// 	for(auto c:adjlist[u]){
	// 		s.insert(mp(c.s,mp(c.f,u)));
	// 	}
	// }

	// determine of a matrix of N x N dimension

	// int n;
	// cin>>n;
	// vector<vector<int>> v(n,vector<int>(n));
	// fr(i,0,n){
	// 	fr(j,0,n){
	// 		cin>>v[i][j];
	// 	}
	// }

	// vector<vector<int>> v2 = findsub(v,n,2,0);
	// for(auto vv:v2){
	// 	for(auto e:vv){
	// 		cout<<e<<" ";
	// 	}
	// 	cout<<endl;
	// }

	// int ans = determine(v,n);
	// cout<<ans<<endl;

	// total no of spannig trees in the graph

	// int n,m;cin>>n>>m;
	// fr(i,0,m){
	// 	int x,y;cin>>x>>y;
	// 	++indegree[x];
	// 	++indegree[y];
	// 	a[x][y]=-1;
	// 	a[y][x]=-1;
	// }

	// fr(i,0,n+1) fr(j,0,n+1){
	// 	if(i==j) a[i][j] = indegree[i];
	// }

	// vector<vector<int>> A;
	// fr(i,1,n+1){
	// 	vector<int> t;
	// 	fr(j,1,n+1){
	// 		t.pb(a[i][j]);
	// 	}
	// 	A.pb(t);
	// }

	// vector<vector<int>> B = findsub(A,n,0,0);

	// int ans = determine(B,n-1);
	// cout<<ans<<endl;

	// the bellman ford's algorithm

	// the concept of the n-1 relaxation of all nodes
	// if in the nth relaxation, distance of any nodes decreases then there is a negative weighted cycle

	// int n,m;cin>>n>>m;
	// vector<pair<int,pair<int,int>>> ee;
	// fr(i,0,m){
	// 	int a,b,c;cin>>a>>b>>c;
	// 	adjlist[a].pb(mp(b,c));
	// 	ee.pb(mp(a,mp(b,c)));
	// }

	// vector<int> dis(n+1,int_max);
	// int s = 1;
	// dis[s] = 0;

	// for(int i=0;i<=n-1;i++){
	// 	for(auto e:ee){
	// 		int u = e.f;
	// 		int v = e.s.f;
	// 		int d = e.s.s;
	// 		if(dis[u]+d<dis[v]){
	// 			dis[v] = dis[u]+d;
	// 		}
	// 	}
	// }

	// debugv(dis,1,n+1)

	// fr(i,0,2){
	// 	for(auto e:ee){
	// 		int u = e.f;
	// 		int v = e.s.f;
	// 		int d = e.s.s;
	// 		if(dis[u]+d<dis[v]){
	// 			dis[v] = dis[u]+d;
	// 			cout<<"negative cycle detected , and this cycle has a edge from "<<u<<" to "<<v<<endl;
	// 		}
	// 	}
	// 	debugv(dis,1,n+1)
	// }

	// // floydd warshell

	// int n,m;cin>>n>>m;
	// fr(i,0,m){
	// 	int a,b,c;cin>>a>>b>>c;
	// 	adjmat[a][b]=c;
	// }

	// fr(i,1,n+1) adjmat[i][i]=0;
	// bool b = false;
	// fr(k,1,n+1){
	// 	fr(i,1,n+1){
	// 		fr(j,1,n+1){
	// 			if(adjmat[i][k]!=INT_MAX && adjmat[k][j]!=INT_MAX){
	// 				adjmat[i][j] = min(adjmat[i][j],adjmat[i][k]+adjmat[k][j]);
	// 				if(i==j && adjmat[i][j]<0){b=true;break;}
	// 			}
	// 		}
	// 	}
	// }

	// if(b) cout<<"negative cycle detected"<<endl;
	// else{
	// 	fr(i,1,n+1){
	// 		fr(j,1,n+1){
	// 			if(adjmat[i][j]!=INT_MAX) cout<<adjmat[i][j]<<" ";
	// 			else cout<<"I ";
	// 		}
	// 		cout<<endl;
	// 	}
	// }

	// ****travelling salesman problem*********************

	// basic approach using the unordered_set
	
	// int n,m;cin>>n>>m;
	// fr(i,0,m){
	// 	int a,b,c;cin>>a>>b>>c;
	// 	adjmat[a][b] = c;
	// 	adjmat[b][a] = c;
	// }
	// unordered_set<int> s;
	// fr(i,1,n+1) {s.insert(i);adjmat[i][i]=0;}

	// int src;cin>>src;
	// s.erase(src);

	// int ans = tcp(src,src,s);
	// cout<<ans<<endl;

	// better approach using bitmasking

	// int n,m;cin>>n>>m;
	// fr(i,0,m){
	// 	int a,b,c;cin>>a>>b>>c;
	// 	adjmat[a][b] = c;
	// 	adjmat[b][a] = c;
	// }

	// fr(i,1,n+1) adjmat[i][i]=0;
	// int mask = 1|(1<<(1));
	// debug(mask)
	// int ans = tcp2(1,1,mask,n);
	// cout<<ans<<endl;

	// ****************************************************

	// int n,m;cin>>n>>m;
	// fr(i,0,m){
	// 	int a,b;cin>>a>>b;
	// 	adjlist[a].pb(b);
	// 	adjlist[b].pb(a);
	// }

	// bridges(1,-1);

	// kosaraju's algo
	// print no of scc and and individual scc with its elements

	// int n,m;cin>>n>>m;
	// fr(i,0,m){
	// 	int a,b;cin>>a>>b;
	// 	adjlist[a].pb(b);
	// 	revadjlist[b].pb(a);
	// }

	// fr(i,1,n+1){
	// 	if(!vis[i])
	// 		dfsin(i);
	// }

	// vis.assign(n+1,0);
	// debug(inorder)
	// debugv(vis,0,n+1)

	// for(int i=n-1;i>=0;i--){
	// 	if(!vis[inorder[i]]){
	// 		dfsscc(inorder[i]);
	// 		for(auto e:scc) cout<<e<<" ";
	// 		cout<<endl;
	// 		scc.clear();
	// 	}
	// }

	// bipartite grpah check

	// m-coloring problem

	// int n,m;cin>>n>>m;
	// fr(i,0,m){
	// 	int a,b;cin>>a>>b;
	// 	adjlist[a].pb(b);
	// 	adjlist[b].pb(a);
	// }

	// approach 1 

	// int mm;cin>>mm;
	// bool b = false;
	// fr(i,1,mm+1)
	// 	b|=mcoloring(1,i,mm);

	// if(b)
	// 	debugv(color,1,n+1);

	// cout<<b<<endl;

	// approach 2

	// int mm;cin>>mm;
	// bool ans = solvee(n,mm,1);
	// cout<<ans<<endl;
 
	// debugv(color,1,n+1)

	// negative cycle detection using bellman ford algo

	// **longest path in acyclic graph
	
	// int n,m;cin>>n>>m;
	// fr(i,0,m){
	// 	int a,b,c;cin>>a>>b>>c;
	// 	adjlist[a].pb(mp(b,c));
	// }

	// fr(i,1,n+1) if(!vis[i]) dfs(i);
	// reverse(all(order));

	// int src;cin>>src;
	// d[src]=0;
	// fr(i,0,n){
	// 	if(d[order[i]!=INT_MIN]){
	// 		for(auto c:adjlist[order[i]]){
	// 			int u = order[i];
	// 			int v = c.f;
	// 			int wt = c.s;
	// 			if(d[u]+wt>d[v])
	// 				d[v]=d[u]+wt;
	// 		}
	// 	}
	// }
	// fr(i,1,n+1) d[i]==INT_MIN?cout<<"I ":cout<<d[i]<<" "; cout<<endl;
	// cout<<*max_element(d.begin()+1,d.begin()+n)<<endl;

	// cheapest flight within k stops

	// scan n,m,adjlist
	// scan src,dest
	// set<pair<int,pair<int,int>>> s;
	// s.insert({0,{src,0}});
	// while(s.sz()){
	// 	auto [cost,t]=*s.begin();
	// 	s.erase(s.begin());
	// 	auto [u,step]=t;
	// 	if(u==dest) return cost;
	// 	if(step>k) continue;
	// 	for(auto c:adjlist[u]){
	// 		auto [v,wt]=c;
	// 		s.insert({cost+wt,{v,step+1}});
	// 	}
	// }
	// return -1;

	// *oliver and the game

	// int n,m;cin>>n;
	// fr(i,0,n-1){
	// 	int a,b;cin>>a>>b;
	// 	adjlist[a].pb(b);
	// 	adjlist[b].pb(a);
	// }

	// for LCA --> LCA[N][logN] tabel then LCA(a,b) function , for LCA[i][0] , bfs to store parents of all
	// LCA[N+1][logN + 1]
	
	// int ln = log2(n)+1;
	// memset(lca,-1,sizeof(lca));
	
	
	// dfs(1,-1);
	// debugv(parent,1,n+1)
	// debugv(level,1,n+1)
	// fr(i,1,n+1) lca[i][0] = parent[i];
	
	// fr(i,1,n+1){
	// 	fr(j,1,ln+1){
	// 		if(lca[i][j-1]!=-1)
	// 			lca[i][j] = lca[lca[i][j-1]][j-1];
	// 	}
	// }

	// int q;cin>>q;
	// while(q--){
	// 	int d,x,y;cin>>d>>x>>y;
	// 	int a = LCA(x,y,ln);
	// 	int ans = 0;
	// 	if( (a==x && d==0) || (a==y && d==1) ) ans=1;
	// 	ans?cout<<"YES"<<endl:cout<<"NO"<<endl;
	// }

	

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