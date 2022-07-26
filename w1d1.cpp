#include<bits/stdc++.h>
using namespace std;
#define fr(i,a,n) for(auto i=a;i<n;i++)
#define rf(i,n,a) for(auto i=n;i>a;i--)
#define pb push_back
#define ppb pop_back
#define f first
#define s second
#define mp make_pair
#define mt make_tuple
#define int_max 1e9
#define int_min -1e9
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

/*class node{
public:
	int data;
	node* next;
	node* prev;
	node(int val){
		data=val;
		next=null;
		prev=null;
	}
};*/

/*class Queue{
public:
	int* a;
	int front;
	int back;

	Queue(){
		a=new int[n];
		front=-1;
		back=-1;
	}

	void push(int x){
		if(back==n-1) cout<<"the queue is full"<<endl;
		else{
			if(front==-1)
				front++;
			back++;
			a[back]=x;
		}
	}

	void pop(){
		if(front==-1 or front>back) cout<<"the stack is empty"<<endl;
		else{
			front++;
		}
	}

	int peek(){
		if(front==-1 or front>back){
			cout<<"the stack is empty"<<endl;
			return -1;
		}
		else{
			return a[front];
		}
	}

	bool empty(){
		return front==-1 or front>back;
	}
};*/

// void reverse(queue<int>& q){
// 	if(q.empty()) return;
// 	int f=q.front();
// 	q.pop();
// 	reverse(q);
// 	q.push(f);
// }

const int N = 1e5+10;
vector<int> adjlist[N];
vector<vector<int>> cc;
vector<int> curr_cc;

bool vis[N];

void DFS(int vertex){
	//
	vis[vertex] = true;
	curr_cc.pb(vertex);
	for(int child : adjlist[vertex]){
		//
		// cout<<"parent ->"<<vertex<<" child->"<<child<<endl;
		if(vis[child]) continue;
		DFS(child);
		//
	}
	//
}

void solve()
{	
	// questions of the queue and deque
	// reverse a queue
	// can be done using the extra space of a stack and a array
	// using the recursion
	// queue<int> q;
	// q.push(1);
	// q.push(2);
	// q.push(3);
	// q.push(4);
	// q.push(5);

	// reverse(q);
	// while(!q.empty()){
	// 	cout<<q.front()<<" ";
	// 	q.pop();
	// }

	// heap data structure
	// heap is a complete binary tree , where every node has atmost two child nodes
	// though it is not implemented using the tree , rather we will use the array which has the size of 0 initially
	// as we are inserting the value in the max heap , the size of the array will be increased by one each and every time

	// though the structure of the max or min heap is of a comlete binary tree
	// we will be storing the each and every nodes of the heap into the array such that 
	// if the current node is i
	// then the parent of the i is at index floor(i/2) if i!=1 , keeping the array as the 1 based indexing
	// leftchild(i) is present at the index 2i of the array if the node i is not the leaf node
	// rightchild(i) is present at the index 2i+1 of the array if the node i is not the leaf node

	// heap -> 1) maxheap = val(node x) > val(child(node x))
	//         2) minheap = val(node x) < val(child(node x))

	// for given n values , create a max heap then print the contents of the array 
	// the array which contain the values of the heap is the values of the level order traversal

	// tree and graph
	// representation of tree and graph using

	// 1) adjacncy matrix

	// int n,m,v1,v2,wt;cin>>n>>m;
	// int adjmat[n+1][n+1];
	// fr(i,0,n+1) fr(j,0,n+1) adjmat[i][j]=0;
	// fr(i,0,m){
	// 	cin>>v1>>v2>>wt;
	// 	adjmat[v1][v2]=wt;
	// 	adjmat[v2][v1]=wt;
	// }

	// 2) adjacency list
	
	// vector<pair<int,int>> adjlist[n+1];
	// fr(i,0,m){
	// 	cin>>v1>>v2>>wt;
	// 	adjlist[v1].pb({v2,wt});
	// 	adjlist[v2].pb({v1,wt});
	// }

	// 			 |         advantages                   |                disadvantages
    //           |										|
	// Adjmat    |  dynamic access for the wt of the    |    space O(V*V)
	//           |  edge joining the i and j            |
	// 			 |  a[i][j] -> O(1)                     |
    //           |										|
	// Adjlist	 |	space O(V+E)                        |    to find the wt b/w vertix i and j -> O(N)

	// traversal for graphs
	// DFS -> depth first search

	// find the number of connected components in the u_graph
	int n,m,v1,v2;cin>>n>>m;
	fr(i,0,m){
		int v1,v2;cin>>v1>>v2;
		adjlist[v1].pb(v2);
		adjlist[v2].pb(v1);
	}
	int ans=0;
	fr(i,1,n+1){
		if(vis[i]) continue;
		curr_cc.clear();
		// clearing the curr_cc for new cc
		DFS(i);
		// after the DFS of the node i is finished every node in that connected components will be stored in the curr_cc
		cc.pb(curr_cc);
		ans++;
	}
	cout<<cc.size()<<endl;

	for(auto c:cc){
		for(auto i:c){
			cout<<i<<" ";
		}
		cout<<endl;
	}
	// O(V+E)
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