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

// class node{
// public:	
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

// void insert(node* head,int x){
// 	if(!head){
// 		head=new node(x);
// 	}
// 	while(head->next)
// 		head=head->next;
// 	head->next=new node(x);
// }

// void inserthead(node* &head,int x){
// 	node* n = new node(x);
// 	n->next=head;
// 	head=n;
// }

// void print(node* head){
// 	while(head){
// 		cout<<head->data<<" ";
// 		head=head->next;
// 	}
// 	cout<<endl;	
// }

// node* reverse(node* root){
// 	node* prev = null;
// 	node* n = null;
// 	node* curr = root;
// 	while(curr){
// 		n = curr->next;
// 		curr->next = prev;
// 		prev = curr;
// 		curr = n;
// 	}
// 	root = prev;
// 	return root;
// }

// void insertmid(node* root,int x){
// 	if(!root){
// 		root = new node(x);
// 	}
// 	node* slow = root;
// 	node* fast = root;
// 	while(fast && fast->next){
// 		fast=fast->next->next;
// 		slow=slow->next;
// 	}
// 	node* t = slow->next;
// 	slow->next = new node(x);
// 	slow->next->next = t;
// }

// void deletemid(node* root){
// 	if(!root){
// 		return;
// 	}
// 	node* t = null;
// 	node* slow = root;
// 	node* fast = root;
// 	while(fast && fast->next){
// 		t = slow;
// 		fast=fast->next->next;
// 		slow=slow->next;
// 	}
// 	t->next = slow->next;
// 	slow->next = null;
// 	free(slow);
// }

// void insertsorted(node* &root,int x){
// 	if(!root){
// 		root = new node(x);
// 	}
// 	if(root->data > x){
// 		node* n = new node(x,root);
// 		root = n;
// 	}else{
// 		node* curr = root;
// 		while(curr->next && curr->next->data < x)
// 			curr=curr->next;
// 		node* n = curr->next;
// 		curr->next = new node(x);
// 		curr->next->next = n;
// 	}
// }

// node* fhead=null;

// void revrec(node* head){
// 	if(head->next==null){
// 		fhead = head;
// 		return;
// 	}
// 	revrec(head->next);
// 	head->next->next = head;
// 	head->next = null;
// }

// node* merge(node* &left,node* &right){
// 	if(!left) return right;
// 	if(!right) return left;
// 	if(left->data > right->data){
// 		node* t = right;
// 		right = left;
// 		left = t;
// 	}

// 	node* ans = left;
// 	while(left && right){
// 		node* x;
// 		while(left && left->data <= right->data){
// 			x=left;
// 			left=left->next;
// 		}
// 		x->next = right;
// 		node* t = right;
// 		right = left;
// 		left = t;
// 	}
// 	return ans;
// }

// node* mergesorted(node* head1,node* head2){
// 	// inplace merge
// 	if(head1 == null) return head2;
// 	if(head2 == null) return head1;
// 	if(head1->data > head2->data ){
// 		node* t = head2;
// 		head2 = head1;
// 		head1 = t;
// 	}

// 	node* ans = head1;
// 	while(head1 != null && head2 != null){
// 		node* x;
// 		while(head1 != null && head1->data <= head2->data){
// 			x = head1;
// 			head1 = head1->next;
// 		}
// 		x->next = head2;
// 		node* y = head2;
// 		head2 = head1;
// 		head1 = y;
// 	}
// 	return ans;
// }

// node* findmid(node* root){
// 	if(!root){
// 		return null;
// 	}
// 	node* slow = root;
// 	node* fast = root;
// 	while(fast && fast->next){
// 		fast=fast->next->next;
// 		slow=slow->next;
// 	}
// 	return slow;
// }

// node* sort(node* &head){
// 	if(!head || !head->next) return head;
// 	node* mid = findmid(head);
// 	debug(mid->data)
// 	node* left = head;
// 	node* right = mid->next;
// 	mid->next = null;
// 	left = sort(left);
// 	right = sort(right);
// 	head = merge(left,right);
// 	return head;
// }

// node* intersection(node* &head1,node* &head2){
// 	node* i1 = head1;
// 	if(!i1) return null;
// 	node* i2 = head2;
// 	if(!i2) return null;
// 	int totalends = 0;
// 	while(i1!=i2){
// 		if(i1==null){
// 			i1=head2;
// 			totalends++;
// 			if(totalends>=3) break;
// 		}
// 		else i1=i1->next;
// 		if(i2==null){
// 			i2=head1;
// 			totalends++;
// 			if(totalends>=3) break;
// 		}
// 		else i2=i2->next;
// 	}
// 	if(totalends>=3) return null;
// 	else return i1;
// }

// node* intersection2(node* &head1,node* &head2){
// 	int l1=0,l2=0;
// 	node* i1=head1;
// 	node* i2=head2;
// 	while(i1){
// 		l1++;
// 		i1=i1->next;
// 	}
// 	while(i2){
// 		l2++;
// 		i2=i2->next;
// 	}
// 	i1=head1;
// 	i2=head2;
// 	if(l1>l2){
// 		fr(i,0,l1-l2) i1=i1->next;
// 	}else{
// 		fr(i,0,l2-l1) i2=i2->next;
// 	}
// 	while(i1!=i2 && i1){
// 		i1=i1->next;
// 		i2=i2->next;
// 	}
// 	if(i1) return i1;
// 	else return null;
// }

// int length(node* root){
// 	int ans=0;
// 	while(root){
// 		ans++;
// 		root=root->next;
// 	}
// 	return ans;
// }

// class node{
// public: 
// 	int data;
// 	node* next;
// 	node* prev;

// 	node(){
// 		data=0;
// 		next=prev=null;
// 	}

// 	node(int x){
// 		data=x;
// 		next=prev=null;
// 	}
// };

// void print(node* head){
// 	while(head){
// 		cout<<head->data<<" ";
// 		head = head->next;
// 	}
// }

// void insert(node* head,int x){
// 	if(!head){
// 		head = new node(x);
// 		return;
// 	}
// 	while(head->next)
// 		head = head->next;
// 	node* n = new node(x);
// 	head->next = n;
// 	n->prev = head;
// }

// void insertmid(node* head,int x){
// 	if(!head){
// 		head = new node(x);
// 		return;
// 	}
// 	node* slow = head;
// 	node* fast = head->next;
// 	while(fast && fast->next){
// 		fast = fast->next->next;
// 		slow = slow->next;
// 	}
// 	node* nslow = slow->next;
// 	slow->next = new node(x);
// 	slow->next->prev = slow;
// 	slow->next->next = nslow;
// 	slow->next->next->prev = slow->next;
// }

// void insert_sorted(node* &head,int x){
// 	if(!head){
// 		head = new node(x);
// 		return;
// 	}
// 	if(head->data > x){
// 		node* n = new node(x);
// 		n->next = head;
// 		head->prev = n;
// 		head = n;
// 		return;
// 	}
// 	else{
// 		node* curr=head;
// 		while(curr->next && curr->next->data < x){
// 			curr = curr->next;
// 		}
// 		if(curr->next){
// 			node* nhead = curr->next;
// 			curr->next = new node(x);
// 			curr->next->prev = curr;
// 			curr->next->next = nhead;
// 			curr->next->next->prev = curr->next;
// 		}
// 		else{
// 			curr->next = new node(x);
// 			curr->next->prev = curr;
// 		}
// 	}
// }

// node* reverse(node* head){
// 	node* curr = head;
// 	if(curr==null || curr->next==null)
// 		return head;
// 	while(curr->next)
// 		curr=curr->next;
// 	head=curr;
// 	curr->next=curr->prev;
// 	curr->prev=null;
// 	curr=curr->next;
// 	while(curr->prev){
// 		node* t = curr->next;
// 		curr->next = curr->prev;
// 		curr->prev = t;
// 		curr = curr->next;
// 	}
// 	curr->prev=curr->next;
// 	curr->next=null;
// 	return head;
// }





void solve()
{		
	// node* head = new node(5);
	// insert(head,9);
	// insert(head,20);
	// insert(head,30);
	// insert(head,31);
	// insert(head,41);
	// insert(head,48);
	// insert(head,55);
	// // insert(head,-500);
	// // inserthead(head,11);
	// // print(head);
	// // head = reverse(head);
	// // print(head);
	// // insertmid(head,15);
	// print(head);
	// insertsorted(head,35);
	// // deletemid(head);
	// // node* newhead = null;
	// // revrec(head);

	// print(head);
	// head=sort(head);
	// print(head);

	// node* ans = findmid(head);
	// cout<<ans->data<<endl;

	// intersection point of two linked lists
	// node* head1 = new node(1);
	// node* head2 = new node(-1);
	// node* t = new node(5);
	// t->next = new node(6);
	// t->next->next = new node(7);
	// t->next->next->next = new node(8);
	// head1->next = new node(2);
	// head1->next->next = new node(3);
	// head1->next->next->next = new node(4);
	// head1->next->next->next->next = t;
	// head2->next = new node(-2);
	// head2->next->next = new node(-3);
	// head2->next->next->next = new node(-4);
	// head2->next->next->next->next = t;

	// node* ans = intersection(head1,head2);
	// if(ans) cout<<ans->data<<endl;
	// else cout<<"no intersection point";

	// detect and remove loop/cycle in the linked list

	// node* head = new node(1);
	// head->next = new node(2);
	// head->next->next = new node(3);
	// head->next->next->next = new node(4);
	// node* t = head->next->next->next;
	// head->next->next->next->next = new node(5);
	// head->next->next->next->next->next = new node(6);
	// head->next->next->next->next->next->next = new node(7);
	// head->next->next->next->next->next->next->next = new node(8);
	// head->next->next->next->next->next->next->next->next = new node(9);
	// head->next->next->next->next->next->next->next->next->next = new node(10);
	// head->next->next->next->next->next->next->next->next->next->next = t;
	
	// node* slow = head;
	// node* fast = head;
	// bool b = false;
	// while(1){
	// 	slow = slow->next;
	// 	fast = fast->next->next;
	// 	if(fast->next==null || fast->next->next==null){
	// 		b=true;
	// 		break;
	// 	}
	// 	if(fast==slow){
	// 		break;
	// 	}
	// }
	// if(b) cout<<"no loop"<<endl;
	// else{
	// 	node* prevslow = null;
	// 	fast = head;
	// 	while(1){
	// 		prevslow = slow;
	// 		slow=slow->next;
	// 		fast=fast->next;
	// 		if(fast==slow)
	// 			break;
	// 	}
	// 	cout<<fast->data<<endl;
	// 	prevslow->next = null;
	// }

	// print(head);

	// add large numbers
	
	// node* head1 = new node(-1);
	// int n;cin>>n;
	// fr(i,0,n){
	// 	int x;cin>>x;
	// 	insert(head1,x);
	// }
	
	// head1 = head1->next;
	
	// node* head2 = new node(-1);
	// int m;cin>>m;
	// fr(i,0,m){
	// 	int x;cin>>x;
	// 	insert(head2,x);
	// }

	// head2 = head2->next;
	
	// head1 = reverse(head1);
	// head2 = reverse(head2);

	// int l1 = length(head1);
	// int l2 = length(head2);

	// node* mhead = l1>l2?head1:head2;
	// node* head = l1>l2?head2:head1;

	// int ml = mhead==head1?l1:l2;
	// int l = head==head1?l1:l2;

	// int c=0;
	// node* it = mhead;
	// while(it && it->data!=-1){
	// 	int a=0,b=0;
	// 	a = it->data;
	// 	if(head) b=head->data;
	// 	int x = (a+b+c);
	// 	it->data = x%10;
	// 	c = x/10;
	// 	if(it->next==null){
	// 		it->next = new node(-1);
	// 	}
	// 	it = it->next;
	// 	if(head) head=head->next;
	// }
	
	// while(c){
	// 	it->data = c%10;
	// 	c/=10;
	// 	it->next = new node(-1);
	// }
	
	// mhead = reverse(mhead);
	// mhead=mhead->next;
	// print(mhead);

	// merge k sorted linked lists .....

	// DLL

	// node* head = new node(5);
	// insert(head,10);
	// insert(head,30);
	// insert(head,50);
	// insert(head,70);
	// insert(head,110);
	// insertmid(head,45);
	// insert_sorted(head,111);
	// head = reverse(head);
	// print(head);

	
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