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
	node* prev;
	node(int val){
		data=val;
		next=null;
		prev=null;
	}
	node(int val,node* n,node* p){
		data = val;
		next = n;
		prev = p;
	}
};

void printlist(node* head){
	node* i=head;
	cout<<"head - ";
	while(i->next!=null){
		cout<<i->data<<" - ";
		i=i->next;
	}
	cout<<"tail";
}

void insertattail(node* &head,int val){
	node* n=new node(val);
	if(head==null){
		head=n;
		return;
	}
	node* i=head;
	while(i->next!=null)
		i=i->next;
	i->next=n;
	n->prev=i;
}

node* reverse(node* head){
	node* curr=head;
	if(curr==null||curr->next==null)
		return head;
	while(curr->next!=null)
		curr=curr->next;
	head=curr;
	curr->next=curr->prev;
	curr->prev=null;
	curr=curr->next;
	while(curr->prev!=null){
		node* temp=curr->next;
		curr->next=curr->prev;
		curr->prev=temp;
		curr=curr->next;
	}
	curr->prev=curr->next;
	curr->next=null;
	return head;
}

void solve()
{	
	/*node* head=null;
	//doubly linked list
	int n;cin>>n;
	fr(i,0,n){
		int x;cin>>x;
		insertattail(head,x);
	}
	printlist(head);
	cout<<endl;
	head=reverse(head);
	printlist(head);
*/
	// circular linked list
	// same as singly linked list only difference is that the last last node will point to head instead of null
	// all operations are same

	// stl function for list
	list<int> l1 {1,2,2,4,2};
	list<int> l2 {5,9,6,3,4,8,2,0};
	// l2.reverse();
	// l2.sort();
	// l1.merge(l2);
	// for printing the contents of the list we have the range based loops
	// for(auto& i:l2) cout<<i<<" "; 
	// cout<<endl;
	// list<template> is a doubly linked list
	// l1=l2;
	// for(auto i:l1) cout<<i<<" ";
	// cout<<endl;
	// cout<<l1.back()<<endl;
	// for(auto it=l1.begin();it!=l1.end();it++){
	// 	cout<<*it<<" ";
	// }
	/*cout<<l1.empty()<<endl;
	cout<<l1.size()<<endl;
	l1.clear();
	cout<<l1.empty()<<endl;
	cout<<l1.size()<<endl;*/
	// .splice() -> add another list in begging of another list
	// .unique() -> removes the adjesent duplicate
	l1.unique();
	for(auto& i:l1) cout<<i<<" ";
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