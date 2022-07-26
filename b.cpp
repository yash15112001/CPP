#include<bits/stdc++.h>
using namespace std;
#define fr(i,a,n) for(auto i=a;i<n;i++)
#define rf(i,n,a) for(auto i=n;i>a;i--)
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
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

const int n = 1000;

class Stack{
public:
	int* a;
	int i;

	// default constructor , push , pop , top , empty

	Stack(){
		a = new int[n];
		i = -1;
	}

	void push(int data){
		if(i==n-1){
			cout<<"stack is full"<<endl;
			return ;
		}
		i++;
		a[i] = data;
	}

	void pop(){
		if(i==-1){
			cout<<" stack is empty"<<endl;
			return ;
		}
		i--;
	}

	int top(){
		if(i==-1){
			cout<<" stack is empty"<<endl;
			return -1;
		}
		return a[i];
	}

	int _size(){
		int ans = i;
		return ans+1;
	}

	bool empty(){
		return i==-1;
	}
};

// class Queue{
// 	int* arr;
// 	int front;
// 	int back;
// public:
// 	Queue(){
// 		arr=new int[n];
// 		front=-1;
// 		back=-1;
// 	}
// 	void push(int x){
// 		if(back==n-1){
// 			cout<<" queue is full "<<endl;
// 			return;
// 		}
// 		if(front==-1)
// 			front++;
// 		back++;
// 		arr[back]=x;
// 	}
// 	void pop(){
// 		if(front==-1 or front>back){
// 			cout<<"queue is empty"<<endl;
// 			return;
// 		}
// 		else
// 			front++;
// 	}
// 	int peek(){
// 		if(front==-1 or front>back){
// 			cout<<"queue is empty"<<endl;
// 			return -1;
// 		}
// 		else
// 			return arr[front];
// 	}
// 	bool empty(){
// 		if(front==-1 or front>back)
// 			return true;
// 		return false;
// 	}
// };

// class Queue{

// 	int* a;
// 	int front;
// 	int back;
// public:
// 	Queue(){
// 		a = new int[n];
// 		front = -1;
// 		back = -1;
// 	}

// 	void push(int data){
// 		if(back == n-1){
// 			cout<<"queue is full"<<endl;
// 			return ;
// 		}
// 		if(front == -1) front++;
// 		back++;
// 		a[back] = data;
// 	}

// 	void pop(){
// 		if(front == -1 or front>back){
// 			cout<<"queue is empty"<<endl;
// 			return ;
// 		}
// 		front++;
// 	}

// 	int peek(){
// 		if(front == -1 or front>back){
// 			cout<<"queue is empty"<<endl;
// 			return -1;
// 		}
// 		return a[front];
// 	}

// 	bool empty(){
// 		return front==-1 or front>back;
// 	}

// 	int _size(){
// 		return back-front+1;
// 	}
// };

void solve()
{	
	/*map<int,pair<int,int>> m;
	m.insert({-1,{0,0}});
	int n;cin>>n;
	fr(i,0,n){
		int x,y,z;
		cin>>x>>y>>z;
		m[x]=mp(y,z);
	}

	for(auto i:m){
		cout<<i.f<<" -> ("<<i.s.f<<","<<i.s.s<<")"<<endl;
	}

	auto it = m.find(10);
	if(it!=m.end()){
		m.erase(it);
	}else{
		cout<<" the pair does not exists "<<endl;
	}

	for(auto it = m.begin() ; it!=m.end();it++){
		cout<<it->f<<" "<<it->s.f<<" "<<it->s.s<<endl;
	}*/

	/*map<pair<int,int>,pair<int,int>> m;
	int n;cin>>n;
	fr(i,0,n){
		int x,y,z,w;
		cin>>x>>y>>z>>w;
		m[{x,y}]={z,w};
	}
	for(auto &i:m){
		cout<<i.f.f<<" "<<i.f.s<<" "<<i.s.f<<" "<<i.s.s<<endl;
	}
	for(auto it = m.begin();it!=m.end();it++){
		cout<<it->f.f<<" "<<it->f.s<<" "<<it->s.f<<" "<<it->s.s<<endl;
	}*/
	/*unordered_map<int,pair<int,int>> um;
	um.insert({-1,{0,0}});
	int n;cin>>n;
	fr(i,0,n){
		int x,y,z;
		cin>>x>>y>>z;
		um[x]=mp(y,z);
	}

	for(auto i:um){
		cout<<i.f<<" -> ("<<i.s.f<<","<<i.s.s<<")"<<endl;
	}*/

	/*multimap<int,pair<int,int>> mm;
	mm.insert({1,{4,9}});
	int n;cin>>n;
	fr(i,0,n){
		int x,y,z;
		cin>>x>>y>>z;
		mm.insert({x,{y,z}});
	}

	for(auto i:mm){
		cout<<i.f<<" -> ("<<i.s.f<<","<<i.s.s<<")"<<endl;
	}

	auto it = mm.find(1);
	if(it!=mm.end())
		mm.erase(it);
	else cout<<"no element to remove"<<endl;
	cout<<endl;

	for(auto i:mm){
		cout<<i.f<<" -> ("<<i.s.f<<","<<i.s.s<<")"<<endl;
	}*/

	// set<int> s;
	// int n;cin>>n;
	// fr(i,0,n){
	// 	int x;cin>>x;
	// 	s.insert(x);
	// }
	// for(auto i:s)
	// 	cout<<i<<" ";
	// cout<<endl;
	// cout<<s.sz()<<endl;
	// // s.erase(1);
	// auto it = s.find(2);
	// if(it!=s.end()) {
	// 	s.erase(it);
	// 	cout<<"element "<<*it<<" removed"<<endl;
	// }
	// else cout<<"element does not exist"<<endl;
	// cout<<s.sz()<<endl;

	/*unordered_set<int> s;
	int n;cin>>n;
	fr(i,0,n){
		int x;cin>>x;
		s.insert(x);
	}
	for(auto i:s)
		cout<<i<<" ";

	auto it = s.find(6);
	if(it!=s.end())
		s.erase(it);

	cout<<endl;
	for(auto i:s)
		cout<<i<<" ";*/

	/*multiset<int> s;
	s.insert(1);
	s.insert(7);
	s.insert(6);
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(2);
	for(auto i:s) cout<<i<<" ";
	auto it = s.find(2);
	if(it!=s.end()) s.erase(it);
	cout<<endl;
	for(auto i:s) cout<<i<<" ";*/

	// stack -> FILO / LIFO
	Stack s;
	int n;cin>>n;
	fr(i,0,n){
		int x;cin>>x;
		s.push(x);
	}

	cout<<s._size()<<endl<<endl;
	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}

	// stack<int> s;
	// int n;cin>>n;
	// fr(i,0,n){
	// 	int x;cin>>x;
	// 	s.push(x);
	// }
	// cout<<s.sz()<<endl;

	// while(!s.empty()){
	// 	cout<<s.top()<<endl;
	// 	s.pop();
	// }

	// queue -> FIFO ( stl + implmentation using the class )
	// Queue Q;
	// int n;cin>>n;
	// fr(i,0,n){
	// 	int x;cin>>x;
	// 	Q.push(x);
	// }
	// cout<<Q.empty()<<endl;
	// cout<<Q.peek()<<endl;
	// cout<<Q._size()<<endl;
	// while(!Q.empty()){
	// 	cout<<Q.peek()<<" ";
	// 	Q.pop();
	// }

	// queue<int> q;
	// q.push(10);
	// q.push(20);
	// q.push(30);
	// q.push(40);
	// q.push(50);
	
	// while(!q.empty()){
	// 	cout<<q.front();
	// 	q.pop();
	// }
	// cout<<q.sz()<<endl;

	// deque<int> dq;
	// pf -> pb -> ppf -> ppb


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
