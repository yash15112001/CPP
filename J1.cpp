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

// const int n = 1000;
// class Stack{
// 	int *a;
// 	int i;
// 	public: 
// 	Stack(){
// 		a = new int[n];
// 		i=-1;
// 	}
// 	void push(int x){
// 		if(i==n-1)
// 			return;
// 		a[++i]=x;
// 	}
// 	void pop(){
// 		if(i==-1)
// 			return;
// 		i--;
// 	}
// 	int top(){
// 		if(i==-1)
// 			return -1;
// 		return a[i];
// 	}
// 	int _size(){
// 		return i+1;
// 	}
// 	bool isEmpty(){
// 		return i==-1;
// 	}
// };

// class Queue{
// 	int *a;
// 	int f,b;
// 	public:
// 	Queue(){
// 		a = new int[n];
// 		f=b=-1;
// 	}
// 	void push(int x){
// 		if(b==n-1) return;
// 		if(f==-1) ++f;
// 		++b;
// 		a[b]=x;
// 	}
// 	void pop(){
// 		if(f==-1 || f>b) return;
// 		f++;
// 	}
// 	int front(){
// 		if(f==-1 || f>b) return -1;
// 		return a[f];
// 	}
// 	int back(){
// 		if(b==-1 || f>b) return -1;
// 		return a[b];
// 	}
// 	bool isEmpty(){
// 		return (f==-1 || f>b);
// 	}
// 	int _size(){
// 		return b-f+1;
// 	}
// };

// class KStacks{
// 	int *a;
// 	int *top;
// 	int *next;
// 	int n,k,freespot;
// 	public:
// 	KStacks(int N,int K){
// 		n=N;
// 		k=K;
// 		a = new int[n];
// 		top = new int[k];
// 		next = new int[n];
// 		freespot = 0;
// 		fr(i,0,k) top[i]=-1;
// 		fr(i,0,n) next[i]=i+1;
// 		next[n-1]=-1;
// 	}
// 	bool push(int x,int m){
// 		if(freespot==-1) 
// 			return false;
// 		int index = freespot;
// 		freespot = next[freespot];
// 		a[index] = x;
// 		next[index] = top[m-1];
// 		top[m-1] = index;	
// 		return true;
// 	}
// 	int pop(int m){
// 		if(top[m-1]==-1) 
// 			return -1;
// 		int index = top[m-1];
// 		top[m-1] = next[index];
// 		next[index] = freespot;
// 		freespot = index;
// 		return a[index];
// 	}
// };

// class Stack{
// 	queue<int> q1,q2;
// 	public:
// 	void push(int x){
// 		q2.push(x);
// 		while(!q1.empty()){
// 			q2.push(q1.front());
// 			q1.pop();
// 		}
// 		queue<int> q=q1;
// 		q1=q2;
// 		q2=q;
// 	}
// 	void pop(){
// 		if(q1.empty()) return;
// 		q1.pop();
// 	}
// 	int top(){
// 		if(q1.empty()) return -1;
// 		return q1.front();
// 	}
// 	int _size(){
// 		return q1.sz();
// 	}
// 	bool isEmpty(){
// 		if(q1.sz()) return false;
// 		return true;
// 	}
// };

// class Queue{
// 	stack<int> s1,s2;
// 	public:
// 	void push(int x){
// 		while(s1.sz()){
// 			s2.push(s1.top());
// 			s1.pop();
// 		}
// 		s1.push(x);
// 		while(s2.sz()){
// 			s1.push(s2.top());
// 			s2.pop();
// 		}
// 	}
// 	void pop(){
// 		if(s1.sz())
// 			s1.pop();
// 	}
// 	int front(){
// 		if(s1.sz())
// 			return s1.top();
// 		else return -1; 
// 	}
// 	int _size(){
// 		return s1.sz();
// 	}
// 	bool isEmpty(){
// 		if(s1.sz()) return false;
// 		return true;
// 	}
// };

// class node{
// 	public:
// 	int data;
// 	node* next;
// 	node(){
// 		data=0;
// 		next=null;
// 	}
// 	node(int x){
// 		data=x;
// 		next=null;
// 	}
// 	node(int x,node* n){
// 		data=x;
// 		next=n;
// 	}
// };

// node* top;
// class Stack{
// 	int size;
// 	public:
// 	Stack(){
// 		size = 0;
// 	}
// 	void push(int x){
// 		node* head = new node();
// 		if(head==null){
// 			return;
// 		}
// 		size++;
// 		head->data = x;
// 		head->next = top;
// 		top = head;
// 	}
// 	void pop(){
// 		if(top!=null){
// 			top=top->next;
// 			size--;
// 		}
// 	}
// 	int _top(){
// 		if(top) return top->data;
// 		else return -1;
// 	}
// 	bool isEmpty(){
// 		return top==null;
// 	}
// 	int _size(){
// 		return size;
// 	}
// 	void pushatend(int x){
// 		node* t = top;
// 		while(t->next) t=t->next;
// 		t->next = new node(x);
// 		size++;
// 	}
// 	void reverse(){
// 		node* curr = top;
// 		node* prev = null;
// 		node* n = null;
// 		while(curr){
// 			n=curr->next;
// 			curr->next=prev;
// 			prev = curr;
// 			curr = n;
// 		}
// 		top = prev;
// 	}
// 	void print(){
// 		node* curr = top;
// 		while(curr){
// 			cout<<curr->data<<" ";
// 			curr=curr->next;
// 		}
// 	}
// };

// class Stack2{
// 	int *a;
// 	int top1,top2,s;
// public:
// 	Stack2(int x){
// 		a = new int[x];
// 		top1=-1;
// 		top2=x;
// 	}
// 	void push1(int x){
// 		if(top1+1==top2) return;
// 		a[++top1]=x;
// 	}
// 	void push2(int x){
// 		if(top1+1==top2) return;
// 		a[--top2]=x;
// 	}
// 	int pop1(){
// 		if(top1==-1) return -1;
// 		return a[top1--];
// 	}
// 	int pop2(){
// 		if(top2==s) return -1;
// 		return a[top2++];
// 	}
// };

// int ans = int_max;
// int ans1 = int_min;

// void getmin(stack<int>& s){
// 	if(!s.sz()) return;
// 	int x = s.top();
// 	s.pop();
// 	ans = min(ans,x);
// 	getmin(s);
// 	s.push(x);
// }

// void getmax(stack<int>& s){
// 	if(!s.sz()) return;
// 	int x = s.top();
// 	s.pop();
// 	ans1 = max(ans1,x);
// 	getmax(s);
// 	s.push(x);
// }

// void insertatend(stack<int>& s,int a){
// 	if(!s.sz()) {s.push(a);return;}
// 	int x=s.top();
// 	s.pop();
// 	insertatend(s,a);
// 	s.push(x);
// }

// void reverse(stack<int>& s){
// 	if(!s.sz()) return;
// 	int a = s.top();
// 	s.pop();
// 	reverse(s);
// 	insertatend(s,a);
// }

// vector<int> next(vector<int>& v){
// 	int n=v.sz();
// 	vector<int> nse(n,-1);
// 	stack<int> st;
// 	fr(i,0,n){
// 		while(!st.empty() && v[i]<v[st.top()]){
// 			nse[st.top()]=i;
// 			st.pop();
// 		}
// 		st.push(i);
// 	}
// 	fr(i,0,n) if(nse[i]==-1) nse[i]=n;
// 	return nse;
// }

// vector<int> prev(vector<int>& v){
// 	int n=v.sz();
// 	vector<int> pse(n,-1);
// 	stack<int> st;
// 	for(int i=n-1;i>=0;i--){
// 		while(!st.empty() && v[i]<v[st.top()]){
// 			pse[st.top()] = i;
// 			st.pop();
// 		}
// 		st.push(i);
// 	}
// 	return pse;
// }

// class Stack{
// public:
// 	stack<int> s;
// 	int mini;

// 	void push(int x){
// 		if(s.empty()){
// 			s.push(x);
// 			mini=x;
// 		}else{
// 			if(x<mini){
// 				s.push(2*x-mini);
// 				mini=x;
// 			}else{
// 				s.push(x);
// 			}
// 		}
// 	}
// 	void pop(){
// 		if(s.empty()){
// 			return;
// 		}else{
// 			int curr=s.top();
// 			s.pop();
// 			if(curr>mini) return;
// 			else{
// 				int pmini = mini;
// 				mini = 2*mini-curr;
// 				return;
// 			}
// 		}
// 	}
// 	int top(){
// 		if(s.empty()){
// 			return -1;
// 		}
// 		if(s.top()<mini)
// 			return mini;
// 		else return s.top();
// 	}
// 	bool isempty(){
// 		return s.empty();
// 	}
// 	int size(){
// 		return s.sz();
// 	}
// 	int getmin(){
// 		if(!s.sz()) return -1;
// 		return mini;
// 	}
// };

// ************************************************************************************************

// class Stack{
// 	stack<int> s;
// 	int m;
// public: 
// 	void push(int x){
// 		if(s.empty()){
// 			s.push(x);
// 			m=x;
// 		}else{
// 			if(x<m){
// 				s.push(2*x-m);
// 				m=x;
// 			}else{
// 				s.push(x);
// 			}
// 		}
// 	}
// 	void pop(){
// 		if(s.empty()) return;
// 		else{
// 			if(s.top()<m)
// 				m=2*m-s.top();
// 			s.pop();
// 		}
// 	}
// 	int top(){
// 		if(s.empty()) return -1;
// 		return max(m,s.top());
// 	}
// 	bool isempty(){
// 		return s.sz()==0;
// 	}
// 	int size(){
// 		return s.sz();
// 	}
// 	int getmin(){
// 		return m;
// 	}
// };

// ************************************************************************************************

// void insertinsorted(stack<int>& s,int x){
// 	if(s.empty() || (s.top()<=x && !s.empty())){
// 		s.push(x);
// 		return;
// 	}
// 	int t=s.top();
// 	s.pop();
// 	insertinsorted(s,x);
// 	s.push(t);
// }

// void sortstack(stack<int>& s){
// 	if(!s.sz()) return;
// 	int x=s.top();
// 	s.pop();
// 	sortstack(s);
// 	insertinsorted(s,x);
// }

void solve()
{	
	// implementation probelms ::

	// implement stack & queue from scratch using the array
	// implement stack using linked list
	// implement 2 stacks in array
	// **implement k stacks in array --
	// implement stack using queue --
	// implement stack using deque
	// implement queue using stack --
	// **implement k queues in array --
	// implement circular queue --

	// push(x,m)
	// if(freespot==-1) return false;
	// int index = freespot;
	// freespot = next[freespot];
	// arr[index] = x;
	// next[index] = top[m-1];
	// top[m-1] = index
	// return true

	// pop(m)
	// if(top[m-1]) return -1;
	// int index = top[m-1];
	// top[m-1] = next[index];
	// next[freespot] = freespot
	// freespot = index
	// return arr[index]

	// **implement K stacks in space of n
	// int n,k;cin>>n>>k;
	// KStacks s(n,k);
	// int q;cin>>q;
	// fr(i,0,q){
	// 	int o;cin>>o;
	// 	if(o==1){
	// 		int a,b;cin>>a>>b;
	// 		cout<<s.push(a,b)<<endl;
	// 	}else{
	// 		int a;cin>>a;
	// 		cout<<s.pop(a)<<endl;
	// 	}
	// }

	// implement stack using array

	// Stack s;
	// s.push(1);
	// s.push(2);
	// s.push(3);
	// s.push(4);
	// cout<<s._size()<<endl<<endl;
	// while(s._size()){
	// 	int x = s.top();
	// 	cout<<x<<endl;
	// 	s.pop();
	// }

	// stack<int> s;
	// s.push(1);
	// s.push(2);
	// s.push(3);
	// s.push(4);
	// s.push(5);

	// cout<<s.sz()<<endl;
	// cout<<s.top()<<endl;
	// s.pop();
	// cout<<s.sz()<<endl<<s.top()<<endl;
	// cout<<s.empty()<<endl;

	// implement the stack using the array

	// Queue q;
	// q.push(1);
	// q.push(3);
	// q.push(4);
	// q.push(6);
	// q.push(8);
	// q.pop();
	// q.getf();
	// cout<<q._size()<<endl;
	// cout<<q.front()<<endl;
	// cout<<q.back()<<endl;
	// cout<<q.isEmpty()<<endl;
	// q.pop();
	// cout<<q.front()<<endl<<q._size()<<endl;

	// while(q._size()){
	// 	cout<<q.front()<<endl;
	// 	q.pop();
	// }

	// queue<int> q;
	// q.push(1);
	// q.push(4);
	// q.push(3);
	// q.push(8);
	// q.push(3);

	// while(!q.empty()) {cout<<q.front()<<endl;q.pop();}

	// implement stack using 2 queues

	// Stack s;
	// s.push(1);
	// s.push(2);
	// s.push(3);
	// s.push(4);
	// s.push(5);

	// while(s._size()){
	// 	cout<<s.top()<<" ";
	// 	s.pop();
	// }

	// Queue q;
	// q.push(1);
	// q.push(2);
	// q.push(3);
	// q.push(4);
	// q.push(5);
	
	// while(!q.isEmpty()){
	// 	cout<<q.front()<<" ";
	// 	q.pop();
	// }

	// implement the stack using the linkedlist && reverse a stack in O(n) & O(1)

	// Stack s;
	// s.push(1);
	// s.push(2);
	// s.push(3);
	// s.push(4);
	// s.push(5);

	// cout<<s._size()<<endl;
	// s.pop();
	// cout<<s._size()<<endl;
	// cout<<s.isEmpty()<<endl;
	// cout<<s._top()<<endl;

	// s.pushatend(10);
	// cout<<s._size()<<endl;
	// while(!s.isEmpty()){
	// 	cout<<s._top()<<" ";
	// 	s.pop();
	// }

	// s.print();
	// cout<<endl;
	// s.reverse();
	// s.print();

	// 1) implement 2 stacks in one array
	// Stack2 s(5);

	// ************************************************************************************************

	// **2) implement the stack which supports the findmiddle() and deletemiddle() in O(1)

	// Stack s;
	// s.push(5);
	// s.push(3);
	// s.push(8);
	// s.push(2);
	// s.push(4);

	// cout<<s.getmin()<<endl;
	// s.pop();
	// cout<<s.getmin()<<endl;
	// s.pop();
	// s.pop();
	// cout<<s.getmin()<<endl;

	// ************************************************************************************************

	// 3) check if an expression has valid or balanced parenthesis
	
	// string s;cin>>s;
	// unordered_map<char,int> m {{'{',-3},{'[',-2},{'(',-1},{')',1},{']',2},{'}',3}};

	// bool flag = 0;
	// stack<char> st;
	// for(auto c:s){
	// 	if(m[c]<0)st.push(c);
	// 	else{
	// 		if(!st.sz()){
	// 			flag=1;
	// 			break;
	// 		}else{
	// 			if(m[st.top()]+m[c]!=0){
	// 				flag=1;
	// 				break;
	// 			}else{
	// 				st.pop();
	// 			}
	// 		}
	// 	} 
	// }
	// if(flag || st.sz()!=0) cout<<0<<endl;
	// else cout<<1<<endl;

	// 4) reverse a string using stack
	// 5) find min and max in stack using recurrsion

	// stack<int> s;
	// s.push(5);
	// s.push(2);
	// s.push(3);
	// s.push(7);
	// s.push(9);
	
	// getmin(s);
	// getmax(s);
	// cout<<ans<<" "<<ans1<<endl;

	// 6) next greater element
	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];

	// vector<int> ans(n,-1);
	// stack<int> st;

	// int i=1;
	// st.push(0);
	// while(i<n){
	// 	if(st.sz() && v[i]>v[st.top()]){
	// 		ans[st.top()] = v[i];
	// 		st.pop();
	// 	}
	// 	else{
	// 		st.push(i);
	// 		i++;
	// 	}
	// 	debug(st)
	// }
	// fr(i,0,n) cout<<ans[i]<<" ";

	// 7) the celebrity problem
	
	// int n;cin>>n;
	// int a[n][n];
	// fr(i,0,n) fr(j,0,n) cin>>a[i][j];

	// stack<int> s;
	// fr(i,0,n) s.push(i);

	// while(s.sz()>1){
	// 	int t1 = s.top();
	// 	s.pop();
	// 	int t2 = s.top();
	// 	s.pop();
	// 	if(a[t1][t2]){
	// 		s.push(t2);
	// 	}else{
	// 		s.push(t1);
	// 	}
	// }

	// int pc = s.top();
	// bool b1=true,b2=true;

	// fr(i,0,n) b1 = b1 && a[pc][i]==0;
	// for(int j=0;j<n && j!=pc;j++) b2 = b2 && a[j][pc]==1;

	// if(b1&&b2) cout<<pc+1<<endl;

	// 8) reverse a stack using recurssion

	// stack<int> s;
	// int n;cin>>n;
	// fr(i,0,n){
	// 	int x;cin>>x;
	// 	s.push(x);
	// }

	// _print(s);
	// // insertatend(s,10);
	// reverse(s);
	// _print(s);

	// 9) next smaller element in the array

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	// vector<int> ans(n,-1);

	// stack<int> s;
	// s.push(-1);
	// int i=n-1;
	// while(i>=0){
	// 	if(v[i]>s.top()){
	// 		ans[i] = s.top();
	// 		s.push(v[i--]);
	// 	}else if(v[i]<=s.top()){
	// 		s.pop();
	// 	}
	// }

	// fr(i,0,n) cout<<ans[i]<<" ";

	// ***1 next greater(index,value)
	// ***2 next smaller(index,value)
	// ***3 prev greater(index,value)
	// ***4 prev smaller(index,value)

	// next_greater(i) : nearest element in range [i+1...n-1] which is greater than element at i;
	// next_smaller(i) : nearest element in range [i+1...n-1] which is smaller than element at i;
	// prev_greater(i) : nearest element in range [0...i-1] which is greater than element at i;
	// prev_smaller(i) : nearest element in range [0...i-1] which is smaller than element at i;

	// ***1 next greater(index,value)
	
	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	// vector<int> nge(n,-1);
	// stack<int> s;
	// fr(i,0,n){
	// 	while(!s.empty() && v[i]>v[s.top()]){
	// 		nge[s.top()]=i;
	// 		cout<<"the nge of "<<v[s.top()]<<" is "<<v[i]<<endl;
	// 		s.pop();
	// 	}
	// 	s.push(i);
	// }
	// while(s.sz()){
	// 	cout<<"the nge of "<<v[s.top()]<<" is "<<-1<<endl;
	// 	s.pop();
	// }

	// fr(i,0,n)
	// 	cout<<nge[i]<<" ";

	// ***2 next smaller(index,value)

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	// vector<int> nse(n,-1);
	// stack<int> s;
	// fr(i,0,n){
	// 	while(!s.empty() && v[i]<v[s.top()]){
	// 		nse[s.top()]=i;
	// 		cout<<"the nse of "<<v[s.top()]<<" is "<<v[i]<<endl;
	// 		s.pop();
	// 	}
	// 	s.push(i);
	// }
	// while(s.sz()){
	// 	cout<<"the nse of "<<v[s.top()]<<" is "<<-1<<endl;
	// 	s.pop();
	// }

	// fr(i,0,n)
	// 	cout<<nse[i]<<" ";

	// ***3 previous greater(index,value)

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	// stack<int> st;
	// vector<int> pge(n,-1);
	// for(int i=n-1;i>=0;i--){
	// 	while(!st.empty() && v[i]>v[st.top()]){
	// 		pge[st.top()]=i;
	// 		st.pop();
	// 	}
	// 	st.push(i);
	// }

	// debug(pge)

	// ***4 previous smaller(index,value)

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	// vector<int> pse(n,-1);
	// stack<int> st;
	// for(int i=n-1;i>=0;i--){
	// 	while(!st.empty() && v[i]<v[st.top()]){
	// 		pse[st.top()]=i;
	// 		st.pop();
	// 	}
	// 	st.push(i);
	// }

	// debug(pse)

	// 10) largest area in a histogram

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];

	// vector<int> ps = prev(v);
	// vector<int> ns = next(v);
	// // fr(i,0,n){
	// // 	if(ns[i]==-1)
	// // 		ns[i]=n;
	// // }

	// int ans = int_min;
	// fr(i,0,n){
	// 	ans = max(ans,v[i]*(ns[i]-ps[i]-1));
	// }

	// cout<<ans<<endl;

	// 11) largest area in a binary matrix.
	// follow up question on question 10

	// int n;cin>>n;
	// vector<vector<int>> v(n,vector<int>(n));
	// fr(i,0,n) fr(j,0,n) cin>>v[i][j];

	// fr(i,1,n){
	// 	fr(j,0,n){
	// 		if(v[i][j]!=0)v[i][j]+=v[i-1][j];
	// 	}
	// }
	// fr(i,0,n){
	// 	fr(j,0,n){
	// 		cout<<v[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	
	// int ans = int_min;
	// fr(i,0,n){
	// 	vector<int> nse = next(v[i]);
	// 	vector<int> pse = prev(v[i]);
	// 	debug(nse)
	// 	debug(pse)
	// 	fr(j,0,n){
	// 		ans = max(ans,v[i][j]*(nse[j]-pse[j]-1));
	// 	}
	// }
	// cout<<ans<<endl;

	// 12) evalute the postfix expression
	
	// string s;cin>>s;
	// // 0<=s[i]<=9 U {+,-,/,*,^}
	// stack<int> st;
	// for(auto c:s){
	// 	if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^'){
	// 		int x=st.top();
	// 		st.pop();
	// 		int y=st.top();
	// 		st.pop();

	// 		switch(c){
	// 			case '+':
	// 				st.push(x+y);
	// 				break;
	// 			case '-':
	// 				st.push(y-x);
	// 				break;
	// 			case '/':
	// 				{
	// 					if(x!=0)
	// 						st.push(y/x);
	// 					break;
	// 				}
	// 			case '*':
	// 				st.push(x*y);
	// 				break;
	// 			case '^':
	// 				st.push(x^y);
	// 				break;
	// 		}
	// 	}else{
	// 		st.push(c-'0');
	// 	}
	// 	debug(st)
	// }
	// cout<<st.top();

	// 13) insert at end::recurssion
	// 14) reverse a stack using recurssion

	// 15) sort a stack using recussion
	// same logic as reverse a stack

	// stack<int> s;
	// s.push(-1);
	// s.push(2);
	// s.push(5);
	// s.push(-9);
	// s.push(7);
	// s.push(4);

	// sortstack(s);
	// while(!s.empty()){
	// 	cout<<s.top()<<" ";
	// 	s.pop(); 
	// }

	// 16) check if there is redundant bracets in the expression

	// string s;cin>>s;
	// // for a closing bracket to be non redundant there must be a operator and a opening bracket associated with it in the expression
	// bool b = true;
	// stack<char> st;
	// for(auto c:s){
	// 	debug(st);
	// 	if(c=='('||c=='+'||c=='*'||c=='-'||c=='/')
	// 		st.push(c);
	// 	else if(c==')'){
	// 		if(st.top()=='('){
	// 			b=false;
	// 			break;
	// 		}
	// 		else{
	// 			// find the opening bracket in the stack
	// 			// and keep poping till found '('
	// 			while(st.top()!='('){
	// 				st.pop();
	// 			}
	// 			st.pop();
	// 		}
	// 	}
	// 	else
	// 		continue;
	// }
	// cout<<!b<<endl;

	// 17) make string of brackets valid (minimum reversal to make the string valid)

	// string s;cin>>s;
	// stack<char> st;
	// int openct=0,closect=0;
	// for(auto c:s){
	// 	if(c=='('){
	// 		st.push(c);
	// 		openct++;
	// 	}
	// 	else if(c==')'){
	// 		if(!st.empty() && st.top()=='('){
	// 			st.pop();
	// 			openct--;
	// 		}
	// 		else{
	// 			st.push(c);
	// 			closect++;
	// 		}
	// 	}
	// }
	// cout<<ceil(openct/2.0)+ceil(closect/2.0)<<endl;

	// 18) merge overlapping intervals

	// int n;cin>>n;
	// vector<pair<int,int>> in(n,{0,0});
	// fr(i,0,n){
	// 	cin>>in[i].f>>in[i].s;
	// }
	// sort(all(in));
	// stack<pair<int,int>> s;
	// s.push(in[0]);
	// fr(i,1,n){
	// 	auto p1 = s.top();
	// 	auto p2 = in[i];
	// 	if(p2.f<=p1.s){
	// 		s.pop();
	// 		s.push({p1.f,max(p1.s,p2.s)});
	// 	}else{
	// 		s.push(p2);
	// 	}
	// }

	// while(!s.empty()){
	// 	debug(s.top());
	// 	cout<<s.top().f<<" "<<s.top().s<<endl;
	// 	s.pop();
	// }

	// 19) longest valid string of opening and closing brackets in the string

	string s;cin>>s;

	// stack solution

	// stack<int> st;
	// st.push(-1);
	// int ans=0;
	// fr(i,0,s.sz()){
	// 	if(s[i]=='(')st.push(i);
	// 	else{
	// 		st.pop();
	// 		if(st.empty())st.push(i);
	// 		else ans=max(ans,i-st.top());
	// 	}
	// }	
	// cout<<ans<<endl;

	// dp solution
	
	// vector<int> dp(s.sz()+1);
	// dp[0]=0;
	// int ans=0;
	// fr(i,1,s.sz()){
	// 	int j=i-1-dp[i];
	// 	if(s[i]==')'&&(j+1)&&s[j]=='(')
	// 		dp[i+1]=dp[i]+dp[j]+2;
	// 	ans=max(ans,dp[i+1]);
	// }
	// cout<<ans<<endl;

	// O(1) solution
	// int ans=0;
	// int l=0,r=0,n=s.sz();
	// fr(i,0,n){
	// 	if(s[i]=='(')++l;
	// 	else ++r;
	// 	if(l==r) ans=max(ans,l+r);
	// 	else if(r>l) l=r=0;
	// }
	// debug(ans)
	// l=r=0;
	// rf(i,n-1,-1){
	// 	if(s[i]==')')++r;
	// 	else ++l;
	// 	if(l==r) ans=max(ans,l+r);
	// 	else if(l>r) l=r=0;
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