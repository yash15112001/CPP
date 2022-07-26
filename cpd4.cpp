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
#define null NULL

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

class node{
public:
	int data;
	node* next;
	node(int val){
		data=val;
		next=null;
	}
};

void printlist(node* head){
	node* i=head;
	cout<<"Head->";
	while(i!=null){
		cout<<i->data<<"->";
		i=i->next;
	}
	cout<<"NULL"<<endl;
}

void insertinlist(node* &head,int val){
	node* t= new node(val);
	if(head==null){
		head=t;
		return;
	}
	node* temp=head;
	while(temp->next!=null){
		temp=temp->next;
	}
	temp->next=t;
}

void insertathead(node* &head,int val){
	node* t=new node(val);
	t->next=head;
	// node* temp;
	// temp=head;
	head=t;
	// t=temp;
}

bool search(node* head,int k){
	node* t=head;
	while(t!=null){
		if(t->data==k)
			return true;
		t=t->next;
	}
	return false;
}

/*void insertinsortedlist(node* &head,int k){
	node* i=head;
	node* n=new node(k);

	while(i->next!=null)
		i=i->next;

	if(head==null||head->data>k) insertathead(head,k);
	else if(i->data<k) insertinlist(head,k);
	else{
		i=head;
		while(i->next->data<=k){
			i=i->next;
		}
		n->next=i->next;
		i->next=n;
	}
}*/
node* reverse(node* head){
	node *pre,*curr,*n;
	pre=null;
	curr=head;
	while(curr!=null){
 		n=curr->next;
		curr->next=pre;
		pre=curr;
		curr=n;
	}
	head=pre;
	return head;
}
void solve()
{	
	// singly linked list
	node* head=null;
	int n;cin>>n;
	fr(i,0,n){
		int x;cin>>x;
		insertinlist(head,x);
	}
	// printlist(head);
	// int y;cin>>y;
	// insertinsortedlist(head,y);
	printlist(head);
	head=reverse(head);
	printlist(head);

	// doubly linked list
	
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