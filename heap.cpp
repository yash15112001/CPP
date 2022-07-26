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

const int n=100;

// max heap
class heap{
public:
	int* a;
	int s;

	heap(){
		a = new int[n];
		a[0] = -1;
		s = 0;
	}

	void insert(int data){
		s++;
		int i = s;
		a[i]=data;

		while(i>1){
			int p = i/2;
			if(a[p]<a[i]){
				swap(a[p],a[i]);
				i = p;
			}
			else{
				return;
			}
		}
	}

	void print(){
		fr(i,1,s+1){
			cout<<a[i]<<" ";
		}cout<<endl;
	}

	void Delete(){
		if(!s) return;
		a[1]=a[s];
		s--;
		int i = 1;
		while(i<s){
			int l = 2*i;
			int r = 2*i+1;

			// int c = (a[l]>a[r]?l:r);
			// if(c<s && a[c]>a[i]){
			// 	swap(a[c],a[i]);
			// 	i = c;
			// }

			if( l<s && r<s ){
				int localmaxindex = (a[l]<a[r]?r:l);
				if(a[i]<a[localmaxindex]){
					swap(a[i],a[localmaxindex]);
					i =  localmaxindex;
				} 
			}else if( l<s ){
				if(a[i]<a[l]){
					swap(a[i],a[i]);
					i=l;
				}
			}else if( r<s ){
				if(a[i]<a[r]){
					swap(a[i],a[r]);
					i=r;
				}
			}else{
				return;
			}

			// if( l<s && a[i]<a[l]){
			// 	swap(a[i],a[l]);
			// 	i=l;
			// }
			// else if( r<s && a[i]<a[r]){
			// 	swap(a[i],a[r]);
			// 	i=r;
			// }
			// else
			// 	return;
		}
	}
};

void maxheapify(int a[],int n,int i){

	int large = i;
	int l = 2*i+1;
	int r = 2*i+2;

	// for 0 based indexing , l = 2i + 1 , r = 2i + 2
	// for 1 based indexing , l = 2i , r = 2i + 1

	if(l<n && a[large]<a[l]) large = l;
	if(r<n && a[large]<a[r]) large = r;
	if(large!=i){
		swap(a[i],a[large]);
		maxheapify(a,n,large);
	}

}

void minheapify(int a[],int n,int i){

	int small = i;
	int l = 2*i;
	int r = 2*i+1;

	if(l<n && a[small]>a[l]) small = l;
	if(r<n && a[small]>a[r]) small = r;
	if(small!=i){
		swap(a[i],a[small]);
		minheapify(a,n,small);
	}
	
}

void heapsort(int a[],int n){
	int s = n;
	while(s>1){
		swap(a[s-1],a[0]);
		s--;
		maxheapify(a,s,0);
	}
}

void solve()
{	
	// heap -> complete binary tree -> which follows the heap order property
	// use of the array and manipulate array to satisfy the heap property
	// add node every time at most left empty space = no free space in between the nodes allowed
	// heap => max heap , min heap
	// max heap ==> value(node) > value(node->child) , root node has the max value in the max heap
	// min heap ==> value(node) < value(node->child) . root node has the min value in the min heap

	// insertion in heap (max heap)
	// for a node of cbt in the array is at the ( 0 based indexing )
	// (node)index = i
	// (node->left child)=2i
	// (node->right child)=2i+1
	// for a node(index = i) , parrent of that node is at index = i/2

	// insert at end of the array
	// take that node to its right position

	heap h;
	h.insert(55);
	h.insert(52);
	h.insert(54);
	h.insert(51);
	h.insert(50);
	h.insert(53);
	h.print();
	cout<<endl;
	h.Delete();
	h.print();

	// // deletion at the root node
	// // root node = last leaf node
	// // size --
	// // propagate the root
	// h.Delete();
	// h.print();

	// heapify => manipulating the array so that it follows the heap order property
	// observation => leaf node from index n/2 + 1 to n are already following the heap property
	// only processing the node from index 1 to n/2

	// int a[6] = {-1,54,53,55,52,50};
	// int n = 5;
	// for(int i = n/2;i>=1;i--) maxheapify(a,n,i);
	// fr(i,0,n+1) cout<<a[i]<<" "; 

	// int n;cin>>n;
	// int a[n+1];
	// a[0] = -1;
	// fr(i,1,n+1) cin>>a[i];
	// for(int i = n/2; i>=1 ;i--) minheapify(a,n+1,i);
	// fr(i,0,n+1) cout<<a[i]<<" ";

	// heap sort
	// int n,k;cin>>k>>n;
	// while(k--){
	// int a[n];
	// fr(i,0,n) cin>>a[i];
	// for(int i = n/2 - 1 ;i>=0 ; i--) maxheapify(a,n,i);
	// heapsort(a,n);
	// fr(i,0,n) cout<<a[i]<<" ";
	// cout<<endl;
	// }

	// priority queue => heap => default max heap
/*	priority_queue<int> pq;
	pq.push(54);
	pq.push(53);
	pq.push(55);
	pq.push(52);
	pq.push(50);
	while(!pq.empty()){
		cout<<pq.top()<<" ";
		pq.pop();
	}*/

	// for the min heap => use the greater comparator inside the declaration of the heap

	// priority_queue<int , vector<int> , greater<int>> pq;
	// pq.push(54);
	// pq.push(53);
	// pq.push(55);
	// pq.push(52);
	// pq.push(50);
	// while(!pq.empty()){
	// 	cout<<pq.top()<<" ";
	// 	pq.pop();
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