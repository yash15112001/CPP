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

class heap{
public:
	int* a;
	int s;
	heap(){
		a=new int[n];
		s=0;
		a[0]=-1;
	}
	
	void insert_max(int data){
		a[++s]=data;
		int i=s;

		while(i>1){
			int parent = i/2;
			if(a[parent]<a[i]){
				swap(a[i],a[parent]);
				i=parent;
			}else{
				return;
			}
		}
	}
	
	void insert_min(int data){
		a[++s]=data;
		int i=s;
		while(i>1){
			int parent = i/2;
			if(a[parent]>a[i]){
				swap(a[parent],a[i]);
				i=parent;
			}else{
				return;
			}
		}
	}
	
	void _print(){
		fr(i,1,s+1)
			cout<<a[i]<<" ";
		cout<<endl;
	}
	
	void _delete_max(){
		if(!s) return;
		a[1]=a[s--];
		int i=1;
		while(i<s){
			int lc=2*i;
			int rc=2*i+1;

			if( lc<=s && rc<=s && a[i]<a[lc] && a[i]<a[rc]){
				int mc = (a[lc]>a[rc]?lc:rc);
				swap(a[i],a[mc]);
				i=mc;
			}
			else if( lc<=s && a[i]<a[lc] ){
				swap(a[lc],a[i]);
				i=lc;
			}else if( rc<=s && a[i]<a[rc] ){
				swap(a[rc],a[i]);
				i=rc;
			}else{
				return;
			}
		}	
	}
	
	void _delete_min(){
		if(!s) return;
		a[1]=a[s--];
		int i=1;
		while(i<s){
			int lc=2*i;
			int rc=2*i+1;

			if( lc<=s && rc<=s && a[i]>a[lc] && a[i]>a[rc]){
				int mc = (a[lc]>a[rc]?rc:lc);
				swap(a[i],a[mc]);
				i=mc;
			}
			else if( lc<=s && a[i]>a[lc] ){
				swap(a[lc],a[i]);
				i=lc;
			}else if( rc<=s && a[i]>a[rc] ){
				swap(a[rc],a[i]);
				i=rc;
			}else{
				return;
			}
		}	
	}
};

void max_heapify(vector<int>& v,int n,int i){
	int l=i;
	int lc=2*i;
	int rc=2*i+1;

	if(lc<n && v[l]<v[lc]) l=lc;
	if(rc<n && v[l]<v[rc]) l=rc;

	if(l!=i){
		swap(v[i],v[l]);
		max_heapify(v,n,l);
	}
}

void min_heapify(vector<int>& v,int n,int i){
	int l=i;
	int lc=2*i;
	int rc=2*i+1;

	if(lc<n && v[l]>v[lc]) l=lc;
	if(rc<n && v[l]>v[rc]) l=rc;

	if(l!=i){
		swap(v[i],v[l]);
		min_heapify(v,n,l);
	}
}

void heapsort(vector<int>& v,int n){
	for(int i=n/2;i>0;i--){
		max_heapify(v,n+1,i);
	}
	int t=n;
	while(t>1){
		swap(v[1],v[t]);
		t--;
		max_heapify(v,t,1);
	}
}

void solve()
{	
	heap h;
	// h.insert_max(105);
	// h.insert_max(106);
	// h.insert_max(110);
	// h.insert_max(103);
	// h.insert_max(102);
	
	// h.insert_max(70);
	// h.insert_max(50);
	// h.insert_max(60);
	// h.insert_max(20);
	// h.insert_max(30);
	// h.insert_max(40);
	// h.insert_max(35);
	
	// h.insert_max(55);
	// h.insert_max(54);
	// h.insert_max(53);
	// h.insert_max(50);
	// h.insert_max(52);

	// h.insert_max(10);
	// h.insert_max(20);
	// h.insert_max(5);
	// h.insert_max(8);
	// h.insert_max(11);
	// h.insert_max(13);
	// h.insert_max(15);
	// h.insert_max(12);
	// h.insert_max(6);
	// h.insert_max(9);

	// h._print();
	// h._delete();
	// h._print();
	
	// heap h2;
	// h2.insert_min(60);
	// h2.insert_min(30);
	// h2.insert_min(40);
	// h2.insert_min(20);
	// h2.insert_min(50);
	// h2.insert_min(70);
	// h2.insert_min(55);
	// h2._print();
	// h2._delete_min();
	// h2._print();

	// heapify

	// int n;cin>>n;
	// vector<int> v(n+1);
	// v[0]=-1;
	// fr(i,1,n+1) cin>>v[i];
	// for(int i=n/2;i>0;i--){
	// 	max_heapify(v,n+1,i);
	// }

	// fr(i,1,n+1) cout<<v[i]<<" ";

	// heap h;
	// h.insert_min(10);
	// h.insert_min(20);
	// h.insert_min(5);
	// h.insert_min(8);
	// h.insert_min(11);
	// h.insert_min(13);
	// h.insert_min(15);
	// h.insert_min(12);
	// h.insert_min(6);
	// h.insert_min(9);
	// h._print();

	// int n;cin>>n;
	// vector<int> v(n+1);
	// v[0]=-1;
	// fr(i,1,n+1) cin>>v[i];
	// for(int i=n/2;i>0;i--){
	// 	min_heapify(v,n+1,i);
	// }

	// fr(i,1,n+1) cout<<v[i]<<" ";

	// heapsort
	
	// int n;cin>>n;
	// vector<int> v(n+1);
	// v[0]=-1;
	// fr(i,1,n+1) cin>>v[i];
	// heapsort(v,n);
	// fr(i,1,n+1) cout<<v[i]<<" ";

	// proirity queue
	// priority_queue<int> pq; // -> max heap
	// pq.push(5);
	// pq.push(7);
	// pq.push(6);
	// pq.push(9);
	// pq.push(10);

	// pq.remove(6);

	// while(!pq.empty()){
	// 	cout<<pq.top()<<" ";
	// 	pq.pop(); 
	// }cout<<endl;

	// // max heap prints the elements in the reverse sorted order
	// // if want to print the element in the sorted order then use the min heap

	// priority_queue<int,vector<int>,greater<int>> pq2;

	// pq2.push(5);
	// pq2.push(7);
	// pq2.push(6);
	// pq2.push(9);
	// pq2.push(10);

	// while(!pq2.empty()){
	// 	cout<<pq2.top()<<" ";
	// 	pq2.pop(); 
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