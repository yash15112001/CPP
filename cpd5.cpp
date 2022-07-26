#include<bits/stdc++.h>
using namespace std;
#define fr(i,a,n) for(auto i=a;i<n;i++)
#define rf(i,n,a) for(auto i=n;i>a;i--)
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define f first
#define s second
#define mp make_pair
#define mt make_tuple
#define int_max 1e9
#define int_min -1e9

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" "; _print(x); cerr<<endl;
#else
#define debug(x)
#endif

void _print(int x){ cerr<<x; }
void _print(string x){ cerr<<x; }
void _print(char x){ cerr<<x; }
void _print(ll x){ cerr<<x; }
void _print(bool x){ cerr<<x; }

template<class T>void _print(vector<T> v1){ cerr<<"[ "; for(T i:v1) { _print(i); cerr<<" "; } cerr<<"]"; }
template<class T>void _print(set<T> s){ cerr<<"[ "; for(T i:s){ _print(i); cerr<<" "; } cerr<<"]"; }
template<class T>void _print(unordered_set<T> s){ cerr<<"[ "; for(T i:s){ _print(i); cerr<<" "; } cerr<<"]"; }
template<class T>void _print(multiset<T> s){ cerr<<"[ "; for(T i:s){ _print(i); cerr<<" "; } cerr<<"]"; }
template<class T,class V>void _print(pair<T,V> p){ cerr<<"{";_print(p.f);cerr<<",";_print(p.s);cerr<<"}"; }
template<class T,class V>void _print(map<T,V> s){ cerr<<"[ "; for(auto i:s){ cerr<<"{";_print(i.f); cerr<<","; _print(i.s); cerr<<"} "; } cerr<<"]"; }
template<class T,class V>void _print(unordered_map<T,V> s){ cerr<<"[ "; for(auto i:s){ cerr<<"{";_print(i.f); cerr<<","; _print(i.s); cerr<<"} "; } cerr<<"]"; }
template<class T,class V>void _print(multimap<T,V> s){ cerr<<"[ "; for(auto i:s){ cerr<<"{";_print(i.f); cerr<<","; _print(i.s); cerr<<"} "; } cerr<<"]"; }

/*class Stack{
	int* a;
	int i;
public:
	Stack(){
		a=new int[n];
		i=-1;
	}

	void push(int x){
		if(i==n-1){
			cout<<" Stack is full "<<endl;
			return;
		}
		i++;
		a[i]=x;
	}

	void pop(){
		if(i==-1){
			cout<<" stack is empty no element to pop"<<endl;
			return;
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

	bool empty(){
		return i==-1;
	}
};

class Queue{
	int* arr;
	int front;
	int back;
public:
	Queue(){
		arr=new int[n];
		front=-1;
		back=-1;
	}
	void push(int x){
		if(back==n-1){
			cout<<" queue is full "<<endl;
			return;
		}
		if(front==-1)
			front++;
		back++;
		arr[back]=x;
	}
	void pop(){
		if(front==-1 or front>back){
			cout<<"queue is empty"<<endl;
			return;
		}
		else
			front++;
	}
	int peek(){
		if(front==-1 or front>back){
			cout<<"queue is empty"<<endl;
			return -1;
		}
		else
			return arr[front];
	}
	bool empty(){
		if(front==-1 or front>back)
			return true;
		return false;
	}
};*/

template<typename T> void print(T& pq){
	while(!pq.empty()){
		cout<<pq.top()<<" ";
		pq.pop();
	}
}

void solve()
{	
	// stack, queue, deque, priority queue(heap)

	// stack stl
	/*stack<int> s;
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}*/

	// stack implementation using ( array / class )

	/*Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}*/
	

	// queue stl
	/*queue<char> q;
	q.push('a');
	q.push('b');
	q.push('c');
	q.push('d');
	q.push('e');
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}	*/

	// queue implementation using ( array / class )

	/*Queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	cout<<q.peek()<<endl;
	q.pop();
	cout<<q.empty()<<endl;
	cout<<q.peek()<<endl;
	q.pop();
	q.pop();
	q.pop();
	q.pop();
	cout<<q.empty()<<endl;*/


	// deque stl -> doubly ended queue 
	// push and pop from both side
	// not contiguous memory
	// the storage of deque is automatically expanded or contracted

	/*deque<int> dq {1,2,3};
	dq.pf(0);
	dq.pf(-1);
	dq.pb(4);
	dq.pb(5);

	for(auto& e:dq){
		cout<<e<<" ";
	}
	cout<<endl;

	dq.ppb();
	dq.ppf();
	
	for(auto& e:dq){
		cout<<e<<" ";
	}
	cout<<endl;

	cout<<dq.front()<<endl;
	cout<<dq.back()<<endl;
	cout<<dq.size()<<endl;*/


	// sliding window maximum
	
	/*int n;cin>>n;
	vector<int> v(n);
	fr(i,0,n) cin>>v[i];
	int k;cin>>k;

	fr(i,0,n-k+1){
		int maxi;
		maxi=v[i];
		fr(j,i,i+k){
			maxi=max(maxi,v[j]);
		}
		cout<<maxi<<" ";
	}  */   //-> time complexcity = O(n*n)

	// // priority queue stl 
	// priority_queue<int> pq;
	// pq.push(20);
	// pq.push(10);
	// pq.push(30);
	// pq.push(5);
	// pq.push(40);
	// pq.push(0);
	
	// when adding elements in the priority queue it will make max heap and arrange the ele accordingly

	// print(pq);
	// cout<<pq.size();
	// pq.pop();
	// cout<<endl;
	// print(pq);
	// cout<<pq.size();

	// if we want to store elements in desending order then we can use the comparator function or the inbuild comparator greater<int>
	/*priority_queue<int, vector<int> ,greater<int>> pq;
	pq.push(20);
	pq.push(10);
	pq.push(30);
	pq.push(5);
	pq.push(40);
	pq.push(0);
	print(pq);*/

	// user defined comparator
	auto cmp = [](int l,int r){ return l>r; };

	priority_queue< int , vector<int> , decltype(cmp) > pq(cmp);
	for(auto e:{20,10,30,5,40,0}) { pq.push(e);}
	print(pq);
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