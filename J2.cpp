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

const int n = 1000;

// class Queue{
// public:	 
// 	int* a;
// 	int f,b;
// 	Queue(){
// 		a = new int[n];
// 		f=b=-1;
// 	}
// 	void push(int x){
// 		if(b==n-1) return;
// 		if(f==-1) ++f;
// 		a[++b] = x;
// 	}
// 	void pop(){
// 		if(f==-1 || f>b) return;
// 		++f;
// 	}
// 	int front(){
// 		if(f==-1 || f>b) return -1;
// 		return a[f];
// 	}
// 	int size(){
// 		if(f==-1 || f>b) return 0;
// 		return b-f+1;
// 	}
// 	bool isempty(){
// 		if(f==-1 || f>b) return 1;
// 		return 0;
//  	}
// };

// class Queue{
// public:
// 	stack<int> s1,s2;
// 	void push(int x){
// 		while(!s1.empty()){
// 			s2.push(s1.top());
// 			s1.pop();
// 		}
// 		s1.push(x);
// 		while(!s2.empty()){
// 			s1.push(s2.top());
// 			s2.pop();
// 		}
// 	}
// 	void pop(){
// 		if(s1.empty()) return;
// 		s1.pop();
// 	}
// 	int front(){
// 		if(s1.empty()) return -1;
// 		return s1.top();
// 	}
// 	int size(){
// 		return s1.sz();
// 	}
// 	bool isempty(){
// 		return s1.empty();
// 	}
// };

// void print(circularQueue q){
// 	int ff = q.f;
// 	int bb = q.b;
// 	if(ff<=bb){
// 		fr(i,ff,bb+1)
// 			cout<<q.a[i]<<" ";
// 		cout<<endl;
// 	}else{
// 		fr(i,ff,n)
// 			cout<<q.a[i]<<" ";
// 		fr(i,0,bb+1)
// 			cout<<q.a[i]<<" ";
// 		cout<<endl;
// 	}
// }

// class circularQueue{
// public:	 	
// 	int *a;
// 	int f,b;
// 	circularQueue(){
// 		a=new int[n];
// 		f=b=-1;
// 	}
// 	void push(int x){
// 		if((f==0&&b==n-1)||(b+1==f)) return;
// 		if(f==-1 && b==-1){
// 			++f;
// 			a[++b]=x;
// 		}
// 		else if(b<n-1){
// 			a[++b]=x;
// 		}else if(b==n-1 && f>=1){
// 			a[b=0]=x;
// 		}
// 	}
// 	void pop(){
// 		if(f==-1) return;
// 		if(f==b)
// 			f=b=-1;
// 		else{
// 			f=(f+1)%n;
// 		}
// 	}
// 	int front(){
// 		if(f==-1) return -1;
// 		return a[f];
// 	}
// 	int size(){
// 		if(f==-1) return 0;
// 		if(f<=b) return b-f+1;
// 		else return b-f+1+n;
// 	}
// 	bool isempty(){
// 		return (f==-1&&b==-1);
// 	}
// 	void print(){
// 		if(f<=b){
// 			fr(i,f,b+1)
// 				cout<<a[i]<<" ";
// 			cout<<endl;
// 		}else{
// 			fr(i,f,n)
// 				cout<<a[i]<<" ";
// 			fr(i,0,b+1)
// 				cout<<a[i]<<" ";
// 			cout<<endl;
// 		}
// 	}
// };

// class node{
// public:	
// 	int key,value;
// 	node* prev;
// 	node* next;

// 	node(int x,int y){
// 		key=x;
// 		value=y;
// 		prev=next=null;
// 	}
// };

// class cache{
// public: 
// 	node* head = new node(-1,-1);
// 	node* tail = new node(-1,-1);
// 	int cap;
// 	unordered_map<int,node*> m;
// 	cache(int x){
// 		cap=x;
// 		head->next = tail;
// 		head->next->prev = head;
// 	}
// 	void _add(node* x){
// 		node* nhead = head->next;
// 		x->next = nhead;
// 		nhead->prev = x;
// 		head->next = x;
// 		x->prev = head;
// 	}
// 	void _remove(node* x){
// 		node* nx = x->next;
// 		node* px = x->prev;
// 		px->next = nx;
// 		nx->prev = px;
// 		x->prev = x->next = null;
// 	}
// 	int get(int x){
// 		if(m.find(x)!=m.end()){
// 			node* seeknode = m[x];
// 			m.erase(x);
// 			_remove(seeknode);
// 			_add(seeknode);
// 			m[x]=head->next;
// 			return seeknode->value;
// 		}
// 		else return -1;
// 	}
// 	void put(int x,int y){
// 		if(m.find(x)!=m.end()){
// 			node* seeknode = m[x];
// 			m.erase(x);
// 			_remove(seeknode);
// 		}else if(m.sz()==cap){
// 			m.erase(tail->prev->key);
// 			_remove(tail->prev);
// 		}
// 		_add(new node(x,y));
// 		m[x]=head->next;
// 	}
// };

// void reverse(queue<int>& q){
// 	if(q.sz()==1) return;
// 	int x = q.front();
// 	q.pop();
// 	reverse(q);
// 	q.push(x);
// }

void solve()
{	
	// Queue q;
	// q.push(1);
	// q.push(2);
	// q.push(3);
	// q.push(4);
	// q.push(5);
	// print(q);

	// cout<<q.front()<<endl<<q.isempty()<<endl<<q.size()<<endl;
	// q.pop();
	// q.pop();
	// q.pop();
	// q.pop();
	// q.pop();
	// q.pop();
	// q.pop();
	// cout<<q.front()<<endl<<q.isempty()<<endl<<q.size()<<endl;

	// implement a circular queue
	// circularQueue q;
	
	// q.push(1);
	// q.push(2);
	// q.push(3);
	// q.push(4);
	// q.push(5);
	// q.print();

	// LRU cache
	// int n,q;cin>>n>>q;
	// cache* c = new cache(n);
	// while(q--){
	// 	int x;cin>>x;
	// 	if(x==0){
	// 		int a,b;cin>>a>>b;
	// 		c->put(a,b);
	// 	}else{
	// 		int a;cin>>a;
	// 		cout<<c->get(a);
	// 		cout<<endl;
	// 	}
	// }

	// reverse a queue using recurssion
	// queue<int> q;
	// q.push(1);
	// q.push(2);
	// q.push(3);
	// q.push(4);
	// q.push(5);

	// reverse(q);
	// while(q.sz()){
	// 	cout<<q.front()<<" ";
	// 	q.pop();
	// }

	// reverse first k elements of the queue .. O(K) .. easy
	// O(1) space ?? => if used then queue implemented using array and swaps in array

	// interleave first half of the elements with second half
	// int n;cin>>n;
	// queue<int> q;
	// fr(i,0,n){
	// 	int x;cin>>x;
	// 	q.push(x);
	// }
	// queue<int> q1;
	// fr(i,0,n/2){
	// 	q1.push(q.front());
	// 	q.pop();
	// }
	// while(q1.sz()){
	// 	q.push(q1.front());
	// 	q.push(q.front());
	// 	q.pop();
	// 	q1.pop();
	// }
	// while(q.sz()){
	// 	cout<<q.front()<<" ";
	// 	q.pop();
	// }

	// first negative in window of size k

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	// int k;cin>>k;

	// queue<int> q;
	// int i=0;
	// for(;i<=k-2;i++){
	// 	if(v[i]<0) q.push(i);
	// }

	// for(;i<n;i++){
	// 	if(v[i]<0) q.push(i);
	// 	if(!q.empty() && q.front()==i-k) q.pop();
	// 	if(q.sz()>=1)
	// 		cout<<v[q.front()]<<" ";
	// 	else
	// 		cout<<0<<" ";
	// 	debug(q)
	// }

	// first non repeating character in stram of charachters
	
	// string s;cin>>s;
	// unordered_map<char,int> m;
	// queue<char> q;
	// string ans;
	// int n=s.sz();
	// fr(i,0,n){
	// 	q.push(s[i]);
	// 	m[s[i]]++;
	// 	while(q.size() && m[q.front()]>1)
	// 		q.pop();
	// 	if(q.empty()) ans.push_back('#');
	// 	else ans.push_back(q.front());
	// }
	// cout<<ans<<endl;

	// ************************************************************************
	// ** circular tour

	// int n;cin>>n;
	// vector<int> p(n),d(n);
	// fr(i,0,n) cin>>p[i];
	// fr(i,0,n) cin>>d[i];

	// int start = 0;
	// int extrafuel = 0;
	// int requiredfuel = 0;

	// fr(i,0,n){
	// 	extrafuel+=(p[i]-d[i]);
	// 	if(extrafuel<0){
	// 		requiredfuel+=extrafuel;
	// 		extrafuel=0;
	// 		start=i+1;
	// 	}
	// }
	// if(requiredfuel+extrafuel >= 0) cout<<start<<endl;
	// else cout<<-1<<endl;

	// ************************************************************************

	// **sum of maximum and minimum element of all subarrays of size k

	// this quesion is same as sliding window maximum and sliding window minimum

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	// int k;cin>>k;
	// int ans=0;
	// deque<int> dq;

	// fr(i,0,n){
	// 	if(!dq.empty() && dq.front()==i-k) dq.ppf();
	// 	while(dq.sz() && v[dq.back()] < v[i]) dq.ppb();
	// 	dq.pb(i);
	// 	if(i>=k-1) ans+=v[dq.front()];
	// }

	// dq.clear();

	// fr(i,0,n){
	// 	if(!dq.empty() && dq.front()==i-k) dq.ppf();
	// 	while(dq.sz() && v[dq.back()] > v[i]) dq.ppb();
	// 	dq.pb(i);
	// 	if(i>=k-1) ans+=v[dq.front()];
	// }

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