#include<bits/stdc++.h>
using namespace std;

// ---

#define fr(i,a,n) for(auto i=a;i<n;i++)
#define rf(i,n,a) for(auto i=n;i>a;i--)
#define pb push_back
#define ppb pop_back
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

// ---

class node{
public:
	int data;
	node* l;
	node* r;
	node(int val){
		data = val;
		l = null;
		r = null;
	}
	node(){
		data = 0;
		l = null;
		r = null;
	}
	node(int val,node* left,node* right){
		data = val;
		l = left;
		r = right;
	}
};

void preorder(node* N){
	if(N==null) return;
	cout<<N->data<<" ";
	preorder(N->l);
	preorder(N->r);
}

void inorder(node* N){
	if(N==null) return;
	inorder(N->l);
	cout<<N->data<<" "; 
	inorder(N->r);
}

void postorder(node* N){
	if(N==null) return;
	postorder(N->l);
	postorder(N->r);
	cout<<N->data<<" ";
}

void levelorder(node* N){

	// this code is using the same concept as the BFS on graph

	if(N==null) return;
	queue<node*> q;
	q.push(N);

	while(!q.empty()){
		node* cn=q.front();
		q.pop();
		cout<<cn->data<<" ";
		if(cn->l!=null) q.push(cn->l);
		if(cn->r!=null) q.push(cn->r);
	}
}

void iterativepreorder(node* N){
	if(N==null) return;
	stack<node*> st;
	st.push(N);

	while(!st.empty()){
		node* cn=st.top();
		st.pop();
		cout<<cn->data<<" ";
		if(cn->r!=null) st.push(cn->r);
		if(cn->l!=null) st.push(cn->l);
	}
}

void iterativeinorder(node* N){
	stack<node*> st;
	node* temp=N;

	while(1){
		if(temp!=null){
			st.push(temp);
			temp=temp->l;
		}else{
			if(st.empty()) break;
			temp=st.top();
			cout<<temp->data<<" ";
			st.pop();
			temp=temp->r;
		}
	}
}

void iterativepostordertwo(node* N){
	if(N==null) return;
	stack<node*> s1,s2;
	s1.push(N);

	while(!s1.empty()){
		N = s1.top();
		s1.pop();
		s2.push(N);
		if(N->l!=null){
			s1.push(N->l);
		}
		if(N->r!=null){
			s1.push(N->r);
		}
	}

	while(!s2.empty()){
		cout<<s2.top()->data<<" ";
		s2.pop();
	}
}

// void iterativepostorderone(node* N){

// }

void threetraversal(node* N){
	vector<int> preorder,inorder,postorder;
	stack<pair<node*,int>> st;

	st.push({N,1});

	while(!st.empty()){
		auto cv = st.top();
		st.pop();

		if(cv.s ==1){
			
			preorder.pb(cv.f->data);
			cv.s++;
			st.push(cv);

			if(cv.f->l!=null) st.push({cv.f->l,1});

		} else if ( cv.s ==2 ){
			
			inorder.pb(cv.f->data);
			cv.s++;
			st.push(cv);

			if(cv.f->r!=null) st.push({cv.f->r,1});

		} else {
		
			postorder.pb(cv.f->data);
		
		}
	}

	cout<<"preorder traversal : ";
	for(auto e:preorder) cout<<e<<" ";

	cout<<endl<<"inorder traversal : ";
	for(auto e:inorder) cout<<e<<" ";

	cout<<endl<<"postorder traversal : ";
	for(auto e:postorder) cout<<e<<" ";
}

void solve()
{	
	// till this moment -> tree we have considered , has N children at any instance of the node , thats why the we have used the 
	// adjlist to represent the tree , because for every possible node we have a list which contains all the children
	// but in the case of the binary tree , we have atmost two child nodes at ant instance of the node
	// we will take advantage of this fact and save the extra space of the list , we will use the class to implement the node of the 
	// binary tree

	node* root = new node(1);

	// as we have seen before that for any given data structure the problems of that data structures are solved using the traversal
	// techniques
	// for tree with more than two childs , or a directed or undirected graph -> we have used the BFS and DFS traversal to solve the problem 
	// but in the case of the binary tree we have these specific traversal techniques ( we can still use the BFS and DFS on BT )
	
	// three depth order traversal
	// 1) inorder traversal ( left , root , right )
	// 2) preorder traversal ( root , left , right )
	// 3) postorder traversal ( left , right , root )
	// these three traversals are recursive

	// one breadth order traversal
	// 1) level order traversal
	// the concept is same as before we need the queue data structure
	// the level order traversal is iterative

	// all these techniques can be implemented using the recursive approach and iterative approach (extra space in iterative ?)
	// note that preorder traversal = DFS for the BT and, BFS on BT = level order traversal

	root->l = new node(2);
	root->r = new node(3);
	root->l->l = new node(4);
	root->l->r = new node(5);
	root->r->l = new node(6);
	root->r->r = new node(7);

	//  BT 
	//	      1
	//	     / \
	//	    /   \
	//	   2     3
	//	  / \   / \
	//	 4   5 6   7

	// all 3 types of depth order traversal

	// preorder recursive => ( root , left , right )
	// cout<<"preorder traversal of this BT is : ";
	// preorder(root);

	// // inorder recursive => ( left , root , right )
	// cout<<endl<<"inorder traversal of this BT is : ";
	// inorder(root);

	// // postorder recursive => ( left , right , root )
	// cout<<endl<<"postorder traversal of this BT is : ";
	// postorder(root);

	// // level order traversal -> using queue -> breadth order -> iterative
	// cout<<endl<<"levelorder traversal for BT is : ";
	// levelorder(root);

	// // as the time complexcity of the recursive (DFSs) inorder , preorder , postorder = O(N)
	// // the iterative approach for the same can be used to modify the time complexcity to O(h) , where h = log(N)

	// // iterative preorder traversal using the stack
	// cout<<endl<<"iterative preorder traversal using stack for BT is : ";
	// iterativepreorder(root);

	// cout<<endl;

	// // iterative inorder traversal using the stack
	// cout<<endl<<"iterative inorder traversal using stack for BT is : ";
	// iterativeinorder(root);

	// // iterative postorder traversal using the 2 stacks
	// cout<<endl<<"iterative postorder traversal using 2 stacks for BT is : ";
	// iterativepostordertwo(root);

	// iterative postorder traversal using the 1 stack
	// cout<<endl<<"iterative postorder traversal using 1 stack for BT is : ";
	// iterativepreorderone(root); 

	// all three traversal of a BT in one go linear time complexcity

	threetraversal(root);
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