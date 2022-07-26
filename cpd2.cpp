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

// pass by reference
/*int swap(int* a,int* b){
	int t = *a;
	*a = *b;
	*b = t;
}

void printfun(array<int>& a,int n){
	fr(i,0,n){
		cout<<a.at(i)<<" ";
	}
}*/

/*void printfunction(array<int>& a){
	int size=a.size();
	for(int i=0;i<size;i++)
		cout<<get<i>(a)<<" ";
}*/

/*void printfunction(vector<int>& v,int n){
	fr(i,0,n){
		cout<<v[i]<<" ";
	}
}*/

class node{
public:
	int data;
	node* next;
};

void printlist(node* head){
	while(head!=NULL){
		cout<<head->data<<" -> ";
		head=head->next;
	}
	cout<<"NULL";
}
void solve()
{	
	/*int a=10,b=20;
	cout<<" before swap "<<endl;
	cout<<" a="<<a<<" b="<<b<<" address of a="<<&a<<" address of b="<<&b<<endl;
	swap(&a,&b);
	cout<<" after swap "<<endl;
	cout<<" a="<<a<<" b="<<b<<" address of a="<<&a<<" address of b="<<&b<<endl;*/
	// passing stl data members to function
	// int n;cin>>n;
	// int a[n];
	// array<int,5> a { 1,2,3,4,5 };
	// fr(i,0,n) cout<<a[i]<<" ";
	// fr(i,0,a.size()) cout<<a.at(i)<<" ";
	// printfunction(a);
	// fr(i,0,a.size()) cout<<get<i>(a)<<" ";
	// cout<<get<0>(a)<<endl;
	// cout<<get<1>(a)<<endl;
	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	// printfunction(v,n);
	// vector<vector<int>> a;
	// vector<pair<int,int>> a;
	// vector<tuple<int,int,int>> a;

	// stl robust representation and stl functions to direct use
	
	// array
	// int n;cin>>n;int a[n];fr(i,0,n) cin>>a[i];
	// fr(i,0,n) cout<<a[i]<<" ";
	// array<int,8> a { 1,2,3,5,3,6,4,5 };
	// fr(i,0,a.size()) cout<<a[i]<<" ";

	// linked list

	node* head = new node();
	node* current = new node();
	node* pre = new node();
	int n; cin>>n;
	fr(i,0,n){
		int x;cin>>x;
		if(i==0){
			head-> data = x;
			head-> next = NULL;
			pre = head;
		}
		else{
			current->data = x;
			current -> next = NULL;
			pre -> next = current;
			pre = current; 
		}
	}

	/*node* head = new node();
	node* second = new node();
	node* third =new node();

	head->data =1;
	head->next=second;
	second->data=2;
	second->next=third;
	third->data =3;
	third->next=NULL;*/
	printlist(head);
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