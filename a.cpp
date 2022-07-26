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

// class node{
// public:
// 	int data;
// 	node* next;
// 	node* prev;
// 	node(int val){
// 		data=val;
// 		next=null;
// 		prev=null;
// 	}
// 	node(int val,node* n,node* p){
// 		data = val;
// 		next = n;
// 		prev = p;
// 	}
// };

// void printlist(node* head){
// 	node* i=head;
// 	cout<<"head - ";
// 	while(i!=null){
// 		cout<<i->data<<" - ";
// 		i=i->next;
// 	}
// 	cout<<"tail";
// }

// void insertattail(node* &head,int val){
// 	node* n=new node(val);
// 	if(head==null){
// 		head=n;
// 		return;
// 	}
// 	node* i=head;
// 	while(i->next!=null)
// 		i=i->next;
// 	i->next=n;
// 	n->prev=i;
// }

// node* reverse(node* head){
// 	node* curr=head;
// 	if(curr==null||curr->next==null)
// 		return head;
// 	while(curr->next!=null)
// 		curr=curr->next;
// 	head=curr;
// 	curr->next=curr->prev;
// 	curr->prev=null;
// 	curr=curr->next;
// 	while(curr->prev!=null){
// 		node* temp=curr->next;
// 		curr->next=curr->prev;
// 		curr->prev=temp;
// 		curr=curr->next;
// 	}
// 	curr->prev=curr->next;
// 	curr->next=null;
// 	return head;
// }

// node* reverse(node* head){
// 	node* c = head;
// 	if(c==null || c->next==null) return head;
// 	while(c->next!=null) c=c->next;
// 	node* ans = c;
// 	c->next = c->prev;
// 	c->prev = null;
// 	c = c->next;
// 	while(c->prev!=null){
// 		node* t = c->prev;
// 		c->prev = c->next;
// 		c->next = t;
// 		c = c->next;
// 	}
// 	c->prev = c->next;
// 	c->next = null;
// 	return ans;
// }

class node{

public:
	int data;
	node* next;
	node(int val){
		data = val;
		next = null;
	}
	node(int val,node* n){
		data = val;
		next = n;
	}
};

void printlist(node* head){
	while(head != null){
		cout<<head->data<<" ";
		head = head->next;
	}
}

void _insert(node* &head,int val){
	node* n = new node(val);
	if(head == null){
		head = n;
		return;
	}
	node* t = head;
	while(t->next != null){
		t = t->next;
	}
	t->next = n;
}

void _insertathead(node* &head,int val){
	node* n = new node(val);
	n->next = head;
	head = n;
}

void _insertinsotedlist(node* &head,int val){
 	node* n = new node(val);
	if(head == null || head->data > val){
		n->next = head;
		head = n;
	} else {
		node* t = head;
		while(t->next != null && t->next->data < val)
			t = t->next;
		n->next = t->next;
		t->next = n;
	}
}

node* reverse(node* &head){
	node *prev, *curr,*n;
	curr = head;
	prev = null;
	n = null;
	while(curr != null){
		n = curr->next;
		curr->next = prev;
		prev = curr;
		curr = n;
	}
	head = prev;
	return head;
}

node* findmid(node* head){
	node* slow = head;
	node* fast = head->next;
	while(fast != null && fast->next != null){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

node* mergesorted(node* head1,node* head2){
	// inplace merge
	if(head1 == null) return head2;
	if(head2 == null) return head1;
	if(head1->data > head2->data ){
		node* t = head2;
		head2 = head1;
		head1 = t;
	}

	node* ans = head1;
	while(head1 != null && head2 != null){
		node* x;
		while(head1 != null && head1->data <= head2->data){
			x = head1;
			head1 = head1->next;
		}
		x->next = head2;
		node* y = head2;
		head2 = head1;
		head1 = y;
	}
	return ans;
}

node* sortlist(node* head){
	if(head==null || head->next == null) return head;
	node* mid = findmid(head);
	node* left = head;
	node* right = mid->next;
	mid->next = null;
	left = sortlist(left);
	right = sortlist(right);
	node* ans = mergesorted(left,right);
	return ans;
}


void solve()
{	
	// node* head = new node(1);
	// insertinsortedlist(head,6);
	// insertinsortedlist(head,8);
	// insertinsortedlist(head,4);
	// insertinsortedlist(head,4);
	// insertinsortedlist(head,4);
	// insertinsortedlist(head,0);
	// insertinsortedlist(head,-5);
	// printlist(head);
	// cout<<endl;
	
	node* head2 = new node(10);
	int n;cin>>n;
	fr(i,0,n){
		int x;cin>>x;
		_insert(head2,x);
	}
	head2 = head2->next;
	node* mid = findmid(head2);
	cout<<mid->data<<endl;

	// printlist(head2);
	// cout<<endl;
	// head2 = sortlist(head2);
	// printlist(head2);

	// node* h = mergesorted(head,head2);
	// printlist(h);

	// node* head = new node(1);
	// insertattail(head,2);
	// insertattail(head,3);
	// insertattail(head,4);
	// insertattail(head,5);
	// insertattail(head,6);
	// insertattail(head,7);
	// printlist(head);
	// cout<<endl;
	// head = reverse(head);
	// printlist(head);

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
