#include<bits/stdc++.h>
using namespace std;
#define fr(i,a,n) for(auto i=a;i<n;i++)
#define rf(i,n,a) for(auto i=n;i>a;i--)
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ud unordered
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

#ifndef ONLINE_JUDGE
#define debugv(x,a,b) cerr<<#x<<" "; _print(x,a,b); cerr<<endl;
#else
#define debugv(x)
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
template<class T>void _print(vector<T> v1,int a,int b){ cerr<<"[ "; for(int i=a;i<b;i++) { _print(v1[i]); cerr<<" "; } cerr<<"]"; }
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
	node* l;
	node* r;

	node(){
		data = 0;
		l = null;
		r = null;
	}// for the dummy/null node

	node(int val){
		data = val;
		l = null;
		r = null;
	}

	node(int val,node* left,node* right){
		data = val;
		l = left;
		r = right;
	}
};

// recursive
void preorder(node* root){
	if(root==null) return;
	cout<<root->data<<" ";
	preorder(root->l);
	preorder(root->r);
}

void inorder(node* root){
	if(root==null) return;
	inorder(root->l);
	cout<<root->data<<" ";
	inorder(root->r);
}

void postorder(node* root){
	if(root==null) return;
	postorder(root->l);
	postorder(root->r);
	cout<<root->data<<" ";
}

void levelorder(node* root){
	queue<node*> q;
	q.push(root);

	// level(root) = 1

	while(!q.empty()){
		auto cn = q.front();
		q.pop();
		cout<<cn->data<<" ";
		if(cn->l!=null) q.push(cn->l); // level(cn->l) = 1 + level(cn);
		if(cn->r!=null) q.push(cn->r); // level(cn->r) = 1 + level(cn);
	}
}

// // iterative
// void iterativepreorder(node* root){
// 	if(root == null )return;
// 	stack<node*> s;
// 	s.push(root);

// 	while(!s.empty()){
// 		auto cv = s.top();
// 		s.pop();
// 		cout<<cv->data<<" ";
// 		if(cv->r!=null) s.push(cv->r);
// 		if(cv->l!=null) s.push(cv->l);
// 	}
// }

// void iterativeinorder(node* root){
// 	stack<node*> s;
// 	node* t = root;

// 	while(1){
// 		if(t!=null){
// 			s.push(t);
// 			t=t->l;
// 		}else{
// 			if(s.empty()) return;
// 			t = s.top();
// 			s.pop();
// 			cout<<t->data<<" ";
// 			t=t->r;
// 		}
// 	}
// }

// void iterativepostorder(node* root){
// 	if(root==null) return;
// 	node* N = root;
// 	stack<node*> s1,s2;
// 	s1.push(N);

// 	while(!s1.empty()){
// 		N = s1.top();
// 		debug(N->data)
// 		s1.pop();
// 		s2.push(N);
// 		if(N->l!=null) s1.push(N->l);
// 		if(N->r!=null) s1.push(N->r); 
// 	}

// 	while(!s2.empty()){
// 		cout<<s2.top()->data<<" ";
// 		s2.pop();
// 	}
// }

map<int,vector<int>> threetraversals(node* root){
	vector<int> preorder,inorder,postorder;
	stack<pair<node*,int>> s;
	s.push({root,1});
	map<int,vector<int>> m;
	while(!s.empty()){
		auto cv = s.top();
		s.pop();

		if(cv.s==1){
			preorder.pb(cv.f->data);
			cv.s++;
			s.push(cv);
			if(cv.f->l!=null) s.push({cv.f->l,1});
		}else if(cv.s==2){
			inorder.pb(cv.f->data);
			cv.s++;
			s.push(cv);
			if(cv.f->r!=null) s.push({cv.f->r,1});
		}else{
			postorder.pb(cv.f->data);
		}
	}
	m[0] = preorder;
	m[1] = inorder;
	m[2] = postorder;
	// for(auto e:preorder) cout<<e<<" ";
	// cout<<endl;
	// for(auto e:inorder) cout<<e<<" ";
	// cout<<endl;
	// for(auto e:postorder) cout<<e<<" ";
	// cout<<endl;
	return m;
}

// int depth(node* root){

// 	// int ans = 0,dr=0,dl=0;

// 	// if(root->l!=null)
// 	// 	dl = depth(root->l);
// 	// if(root->r!=null)
// 	// 	dr = depth(root->r);
// 	// ans = 1 + max(dl,dr);
// 	// return ans;

// 	if(root == null) return 0;
// 	int dl = depth(root->l);
// 	int dr = depth(root->r);
// 	return 1 + max(dl,dr);
// }

// int checkforbalanced(node* root){
// 	if(root==null) return 0;
// 	int lh = checkforbalanced(root->l);
// 	if(lh==-1) return -1;
// 	int rh = checkforbalanced(root->r);
// 	if(rh==-1) return -1;
// 	if(abs(lh-rh)>1) return -1;
// 	return 1 + max(lh,rh);
// }

// int height(node* root,int& diameter){
// 	if(root==null) return 0;
// 	int lh = height(root->l,diameter);
// 	int rh = height(root->r,diameter);
// 	diameter = max(diameter,lh+rh);
// 	debug(diameter)
// 	return 1 + max(lh,rh);
// }

// int maxpathsum(node* root,int& maxpath){
// 	if(root==null) return 0;
// 	int left = max(0,maxpathsum(root->l,maxpath));
// 	int right = max(0,maxpathsum(root->r,maxpath));
// 	maxpath = max(maxpath , root->data + left + right);
// 	return (max(left,right)+root->data);
// }

// bool identicalcheck(node* root1,node* root2){
// 	if(root1==null || root2==null) return root1==root2;
// 	return ((root1->data == root2->data)&&(identicalcheck(root1->l,root2->l))&&(identicalcheck(root1->r,root2->r)));
// }

// vector<vector<int>> zigzagtraversal(node* root){
// 	vector<vector<int>> result;
// 	if(root==null) return result;

// 	queue<node*> q;
// 	q.push(root);
// 	bool ltor = true;

// 	while(!q.empty()){
// 		int s = q.size();
// 		vector<node*> tempnode(s);
// 		vector<int> tempdata(s);
// 		for(int i=0;i<s;i++){
// 			auto cv = q.front();
// 			q.pop();
// 			tempnode[i] = cv;
// 			tempdata[i] = cv->data;
// 		}
// 		for(auto v:tempnode){
// 			if(v->l!=null) q.push(v->l);
// 			if(v->r!=null) q.push(v->r);
// 		}
// 		// if(ltor==false) reverse(tempnode.begin(),tempnode.end());
// 		// for(int i=0;i<s;i++) tempdata[i] = tempnode[i]->data;
// 		if(ltor==false) reverse(tempdata.begin(),tempdata.end());
// 		ltor = !ltor;
// 		result.pb(tempdata);
// 	}
// 	return result;
// }

// bool isleaf(node* root){
// 	return (root->l==null && root->r==null);
// }

// void getleafs(node* root,vector<int>& ans){
// 	// if(root==null) return;
// 	if(isleaf(root)) {ans.pb(root->data);return;}
// 	if(root->l) getleafs(root->l,ans);
// 	if(root->r) getleafs(root->r,ans);
// }

// void getleft(node* root,vector<int>& ans){
// 	node* t = root->l;
// 	while(t){
// 		if(!isleaf(t)) ans.pb(t->data);
// 		if(t->l) t=t->l;
// 		else t=t->r; 
// 	}
// }

// void getright(node* root,vector<int>& ans){
// 	node* t = root->r;
// 	vector<int> temp;

// 	while(t){
// 		if(!isleaf(t)) temp.pb(t->data);
// 		if(t->r) t=t->r;
// 		else t=t->l; 
// 	}

// 	for(int i=temp.sz()-1 ; i>=0;i--)
// 		ans.pb(temp[i]);
// }

// vector<int> boundrytraversal(node* root){
// 	vector<int> ans;
// 	if(root==null) return ans;
// 	if(root->l==null && root->r==null) return ans;
// 	else ans.pb(root->data);
// 	getleft(root,ans);
// 	getleafs(root,ans);
// 	getright(root,ans);
// 	return ans;
// }

// ********************************************************************************
// ***************************** not working **************************************
// ********************************************************************************

// vector<vector<int>> vertical(node* root){
// 	vector<vector<int>> ans;
// 	map<int,map<int,multiset<node*>>> m;

//   // map< vertical , map< lvl , multiset<nodesonsamelvl> > >

// 	queue<pair<node*,pair<int,int>>> q;
// 	q.push({root,{0,0}});

// 	while(!q.empty()){
// 		auto cv = q.front();
// 		q.pop();
// 		node* v = cv.f;
// 		int vertical = cv.s.f;
// 		int level = cv.s.s;
// 		m.insert({vertical,{level,v->data}});
// 		debug(m)
// 		if(v->l)
// 			q.push({v->l,{vertical-1,level+1}});
// 		if(v->r)
// 			q.push({v->r,{vertical+1,level+1}});
// 	}

// 	// for(auto p:m){
// 	// 	vector<int> col;
// 	// 	for(auto q:p.s){
// 	// 		col.insert(col.end(),q.s.begin(),q.s.end());
// 	// 	}
// 	// 	ans.pb(col);
// 	// }
// 	// return ans;
// }

// ********************************************************************************
// ********************************************************************************
// ********************************************************************************

// vector<int> topview(node* root){
// 	vector<int> ans;
// 	if(root==null) return ans;
// 	map<int,int> m; // p:(vertical,node->data);
// 	queue<pair<node*,int>> q; // p:(node , vertical);

// 	q.push({root,0});
// 	while(!q.empty()){
// 		auto cv = q.front();
// 		q.pop();
// 		auto v = cv.f;
// 		int vertical = cv.s;
// 		if(m.find(vertical)==m.end()) m.insert({vertical,v->data});
// 		if(v->l) q.push({v->l,vertical-1});
// 		if(v->r) q.push({v->r,vertical+1});
// 	}
// 	for(auto p:m){
// 		ans.pb(p.s);
// 	}
// 	return ans;
// }

// vector<int> bottomview(node* root){
// 	vector<int> ans;
// 	if(root==null) return ans;
// 	map<int,int> m; // p:(vertical,node->data);
// 	queue<pair<node*,int>> q; // p:(node , vertical);

// 	q.push({root,0});
// 	while(!q.empty()){
// 		auto cv = q.front();
// 		q.pop();
// 		auto v = cv.f;
// 		int vertical = cv.s;
// 		m[vertical] = v->data;
// 		if(v->l) q.push({v->l,vertical-1});
// 		if(v->r) q.push({v->r,vertical+1});
// 	}
// 	for(auto p:m){
// 		ans.pb(p.s);
// 	}
// 	return ans;
// }

// void rightview(node* root,vector<int>& ans,int level){
// 	if(root==null) return;
// 	if(level==ans.sz()) ans.pb(root->data);
// 	rightview(root->r,ans,level+1);
// 	rightview(root->l,ans,level+1);
// }

// void leftview(node* root,vector<int>& ans,int level){
// 	if(root==null) return;
// 	if(level==ans.sz()) ans.pb(root->data);
// 	leftview(root->l,ans,level+1);
// 	leftview(root->r,ans,level+1);
// }

// bool check(node* left,node* right){
// 	if(left==null || right==null) return left==right;
// 	if(left->data!=right->data) return false;
// 	return check(left->l,right->r)&&check(left->r,right->l);
// }

// bool issymmetric(node* root){
// 	return root==null || check(root->l,root->r);
// }

// bool finder(node* root,vector<int>& ans,int x){
// 	// if(root==null) return false;
	
// 	ans.pb(root->data);
	
// 	if(root->data == x) return true;
// 	if(finder(root->l,ans,x)||finder(root->r,ans,x)) return true;

// 	ans.ppb();
// 	return false;
// }

// vector<int> findpath(node* root,int x){
// 	vector<int> ans;
// 	if(root==null) return ans;
// 	finder(root,ans,x);
// 	return ans;
// }

// vector<int> ans;

// bool findpath(node* root,int x){
// 	if(root==null) return false;
// 	if(root->data == x){
// 		ans.pb(root->data);
// 		return true;
// 	} 
// 	bool leftcall = findpath(root->l,x);
// 	if(leftcall){
// 		ans.pb(root->data);
// 		return true;
// 	}
// 	bool rightcall = findpath(root->r,x);
// 	if(rightcall){
// 		ans.pb(root->data);
// 		return true;
// 	}
// 	return false;
// }

// node* findLCA(node* root,int x,int y){
// 	if(root==null || root->data==x || root->data==y ){
// 		return root;
// 	}
// 	node* l = findLCA(root->l,x,y);
// 	node* r = findLCA(root->r,x,y);

// 	if(l==null) return r;
// 	if(r==null) return l;
// 	else return root;
// }

// int width(node* root){
// 	// int ans=0;
// 	// return ans;
// 	if(root==null) return 0;
// 	queue<pair<node*,int>> q;
// 	q.push({root,0});

// 	int localmax = 0;
// 	while(!q.empty()){
// 		int size = q.sz();
// 		int min = q.front().s;
// 		int first,last;

// 		fr(i,0,size){
// 			auto cv = q.front();
// 			auto v = cv.f;
// 			int c_index = cv.s;
// 			q.pop();
// 			c_index-=min;
// 			if(i==0) first = c_index;
// 			if(i==size-1) last = c_index;
// 			if(v->l) q.push({v->l,c_index*2+1});
// 			if(v->r) q.push({v->r,c_index*2+2});
// 		}
// 		localmax = max(localmax,last-first+1);
// 	}
// 	return localmax;
// }

// void childsum(node* root){
// 	if(!root) return;
// 	int cs = 0;
// 	if(root->l) cs+=root->l->data;
// 	if(root->r) cs+=root->r->data;
// 	if(root->data <= cs) root->data = cs;
// 	else{
// 		if(root->l) root->l->data = root->data;
// 		if(root->r) root->r->data = root->data;
// 	}
// 	childsum(root->l);
// 	childsum(root->r);

// 	int rd=0;
// 	if(root->l) rd+=root->l->data;
// 	if(root->r) rd+=root->r->data;
// 	if(root->l || root->r) root->data = rd;
// }

// void findparentsofall(node* root,unordered_map<node*,node*>& parents){
// 	queue<node*> q;
// 	q.push(root);

// 	while(!q.empty()){
// 		auto cv = q.front();
// 		q.pop();
// 		if(cv->l){
// 			q.push(cv->l);
// 			parents[cv->l] = cv;
// 		}
// 		if(cv->r){
// 			q.push(cv->r);
// 			parents[cv->r] = cv;
// 		}
// 	}
// }

// vector<int> findnodes(node* root,int k,node* target){
// 	unordered_map<node*,node*> parents;
// 	findparentsofall(root,parents);

// 	unordered_map<node*,bool> vis;
// 	queue<node*> q;
// 	q.push(target);
// 	vis[target] = true;

// 	int cd = 0;

// 	while(!q.empty()){
// 		int ss = q.sz();
// 		if(cd==k) break;
// 		fr(i,0,ss){
// 			auto cv = q.front();
// 			q.pop();

// 			if(cv->l && !vis[cv->l]){
// 				q.push(cv->l);
// 				vis[cv->l]=true;
// 			}
// 			if(cv->r && !vis[cv->r]){
// 				q.push(cv->r);
// 				vis[cv->r]=true;
// 			}
// 			if(parents[cv] && !vis[parents[cv]]){
// 				q.push(parents[cv]);
// 				vis[parents[cv]]=true;
// 			}
// 		}
// 		cd++;
// 	}
// 	vector<int> ans;
// 	while(!q.empty()){
// 		auto cv=q.front();
// 		q.pop();
// 		ans.pb(cv->data);
// 	}
// 	return ans;
// }

// node* find(node* root,int x){
// 	node* ans;
// 	if(root->data==x || root==null) return root;
// 	ans = find(root->l,x);
// 	if(ans==null) ans=find(root->r,x);
// 	return ans;
// }

// // node* findthetarget(int x,node* root){
// // 	node* ans;
// // 	if(root==null || root->data==x) return ans;
// // 	ans = findthetarget(x,root->l);
// // 	if(ans==null) ans = findthetarget(x,root->r);
// // 	return ans;
// // }

// void findparentsofall(node* root,unordered_map<node*,node*>& parents){
// 	queue<node*> q;
// 	q.push(root);

// 	while(!q.empty()){
// 		auto cv = q.front();
// 		q.pop();
// 		if(cv->l) {q.push(cv->l);parents[cv->l]=cv;}
// 		if(cv->r) {q.push(cv->r);parents[cv->r]=cv;}
// 	}
// }

// int mintimetoburn(node* root,unordered_map<node*,node*>& parents){
// 	queue<node*> q;
// 	unordered_map<node*,int> m;
// 	q.push(root);
// 	m[root]=1;
// 	int ans = 0;

// 	while(!q.empty()){
// 		int s = q.sz();
// 		bool b = false;
// 		fr(i,0,s){
// 			auto cv = q.front();
// 			q.pop();

// 			if(cv->l && !m[cv->l]){
// 				m[cv->l]=1;
// 				q.push(cv->l);
// 				b = true;
// 			}
// 			if(cv->r && !m[cv->r]){
// 				m[cv->r]=1;
// 				q.push(cv->r);
// 				b = true;
// 			}
// 			if(parents[cv] && !m[parents[cv]]){
// 				m[parents[cv]]=1;
// 				q.push(parents[cv]);
// 				b=true;
// 			}

// 		}
// 		if(b) ans++;
// 	}
// 	return ans;
// }

// int heightl(node* root){
// 	int ans = 0;
// 	while(root){
// 		ans++;
// 		root=root->l;
// 	}
// 	return ans;
// }

// int heightr(node* root){
// 	int ans = 0;
// 	while(root){
// 		ans++;
// 		root=root->r;
// 	}
// 	return ans;
// }
// int countincbt(node* root){
// 	if(root==null) return 0;
// 	int lh = heightl(root);
// 	int rh = heightr(root);
// 	if(lh==rh) return (1<<rh)-1;
// 	return 1 + countincbt(root->l)+countincbt(root->r);
// }

// node* finalbuild(vector<int>& preorder,int prestart,int preend,vector<int>& inorder,int instart,int inend,map<int,int>& m){
// 	if(prestart>preend || instart>inend) return null;
// 	node* root = new node(preorder[prestart]);
// 	int index = m[root->data];

// 	int le = index-instart;

// 	root->l = finalbuild(preorder,prestart+1,prestart+le,inorder,instart,index-1,m);
// 	root->r = finalbuild(preorder,prestart+1+le,preend,inorder,index+1,inend,m);
// 	return root;
// }

// node* build(vector<int>& preorder,vector<int>& inorder){
// 	map<int,int> m;
// 	fr(i,0,inorder.sz()) m[inorder[i]]=i;

// 	node* root = finalbuild(preorder,0,preorder.sz()-1,inorder,0,inorder.sz()-1,m);
// 	return root;
// }

// node* finalbuild(vector<int>& postorder,int poststart,int postend,vector<int>& inorder,int instart,int inend,map<int,int>& m){
// 	if(poststart>postend || instart>inend) return null;
// 	node* root = new node(postorder[postend]);
// 	int index = m[root->data];

// 	int le = index-instart;

// 	root->l = finalbuild(postorder,poststart,poststart+le-1,inorder,instart,index-1,m);
// 	root->r = finalbuild(postorder,poststart+le,postend-1,inorder,index+1,inend,m);

// 	return root;
// }

// node* build(vector<int>& postorder,vector<int>& inorder){
// 	map<int,int> m;
// 	fr(i,0,inorder.sz()) m[inorder[i]]=i;

// 	node* root = finalbuild(postorder,0,postorder.sz()-1,inorder,0,inorder.sz()-1,m);
// 	return root;
// }

string serialize(node* root){
	queue<node*> q;
	q.push(root);

	string s = "";

	while(!q.empty()){
		auto cv = q.front();
		q.pop();
		if(cv==null) s+="#,";
		else s+=(to_string(cv->data)+",");
		if(cv!=null){
			q.push(cv->l);
			q.push(cv->r);
		}
	}
	return s;
}

node* deserialize(string& s){
	if(s.sz()==0) return null;
	stringstream ss(s);
	string str;
	getline(ss,str,',');
	node* root = new node(stoi(str));
	queue<node*> q;
	q.push(root);

	while(!q.empty()){
		node* cv = q.front();
		q.pop();

		getline(ss,str,',');
		if(str=="#")
			cv->l = null;
		else{
			cv->l = new node(stoi(str));
			q.push(cv->l);
		}

		getline(ss,str,',');
		if(str=="#")
			cv->r = null;
		else{
			cv->r = new node(stoi(str));
			q.push(cv->r);
		}
	}

	return root;
}

// vector<int> threddedinorder(node* root){
// 	vector<int> ans;
// 	node* t = root;

// 	while(t){
// 		if(t->l==null){
// 			ans.pb(t->data);
// 			t=t->r;
// 		}else{
// 			node* p = t->l;
// 			while(p->r && p->r!=t){
// 				p = p->r;
// 			}
// 			if(p->r==null){
// 				p->r = t;
// 				t=t->l;
// 			}else{
// 				p->r = null;
// 				ans.pb(t->data);
// 				t=t->r;
// 			}
// 		}
// 	}

// 	return ans;
// }

// vector<int> threddedpreorder(node* root){
// 	vector<int> ans;
// 	node* t = root;

// 	while(t){
// 		if(t->l==null){
// 			ans.pb(t->data);
// 			t=t->r;
// 		}else{
// 			node* p = t->l;
// 			while(p->r && p->r!=t){
// 				p = p->r;
// 			}
// 			if(p->r==null){
// 				p->r = t;
// 				ans.pb(t->data);
// 				t=t->l;
// 			}else{
// 				p->r = null;
// 				t=t->r;
// 			}
// 		}
// 	}

// 	return ans;
// }

// void flatten(node* root){
// 	if(root==null) return;
// 	stack<node*> s;
// 	s.push(root);

// 	while(!s.empty()){
// 		auto cv = s.top();
// 		s.pop();
// 		if(cv->r) s.push(cv->r);
// 		if(cv->l) s.push(cv->l);
// 		if(!s.empty()) cv->r = s.top();
// 		cv->l = null;
// 	}
// }

// void flatten(node* root){
// 	node* curr = root;
// 	// node* prev ;
// 	while(curr!=null){
// 		if(curr->l){
// 			node* prev = curr->l;
// 			while(prev->r!=null) prev = prev->r;
// 			prev->r = curr->r;
// 			curr->r = curr->l;
// 			curr->l =
// 		}
// 		curr=curr->r;
// 	}
// }

void solve()
{	
	// binary tree
	// full binary tree => each node have 0 or 2 childs
	// complete binary tree => all levels are filled completely and in the last level all nodes are as left as posssible
	// balanced binary tree => given the no of nodes  , the binary tree with the smallest possible height : h = 1 + int(log2(n))
	// degenerate tree h = n
	
	// node* root = new node(1);	
	// root->l = new node(2);
	// root->r = new node(3);
	// root->l->l = new node(4);
	// root->l->r = new node(5);

	// root->r->l = new node(8);
	// root->r->r = new node(9);
	// root->l->l->l = new node(6);

	// root->l->l->r = new node(7);

	// root->l->l->l = new node(8);

	node* root = new node(1);
	root->l = new node(2);
	root->r = new node(3);
	root->r->l = new node(4);
	root->r->r = new node(5);
	// root->l->l->l->l = new node(80);
	// root->l->r->r = new node(9);
	// root->r->l->l = new node(10);
	// root->r->r->r = new node(11);
	// root->r->r->r->l = new node(111);

	// node* root2 = new node(1);
	// node* root1 = new node();

	// cout<<"recursive traversals"<<endl; 
	// preorder(root);
	// cout<<endl;
	// inorder(root);
	// cout<<endl;
	// postorder(root);
	// cout<<endl<<endl;

	// levelorder(root);
	// cout<<endl<<endl;

	// cout<<"iterative traversals"<<endl;
	// iterativepreorder(root);
	// cout<<endl;
	// iterativeinorder(root);
	// cout<<endl;
	// iterativepostorder(root);
	// cout<<endl<<endl;

	// cout<<"iterative combined"<<endl;
	// threetraversals(root);

	// depth of the tree ( binary in this case )
	// no of edges from the root to most distinct leaf node
	// int ans = depth(root1);
	// ans--;
	// cout<<ans;

	// check for balanced binary tree
	// if(checkforbalanced(root)!=-1)
	// 	cout<<"the tree is balanced binary tree";
	// else 
	// 	cout<<"the tree is not the balaced binary tree";

	// the diameter of the binary tree
	// int diameter = 0;
	// cout<<"height of the tree is :"<<height(root,diameter)<<endl;
	// cout<<"the diameter of the tree is:"<<diameter<<endl;

	// max path sum problem
	// int maxpath = 0;
	// int ans = maxpathsum(root,maxpath);
	// cout<<maxpath<<endl;

	// identical tree check
	// cout<<identicalcheck(root,root);

	// zigzag traversal
	// vector<vector<int>> ans = zigzagtraversal(root);
	// for(auto v:ans){
	// 	for(auto e:v){
	// 		cout<<e<<" ";
	// 	}
	// }

	// boundry traversal ( anti clockwise and clockwise )
	// -> left boundry excluding the leaf node
	// -> leaf nodes
	// -> reverse order of the right boundry excluding the leaf node
	
	// vector<int> ans = boundrytraversal(root);
	// for(auto v:ans) cout<<v<<" ";
	
	// vertical traversal 
	// vector<vector<int>> ans = vertical(root);
	// for(auto v:ans){
	// 	for(auto e:v){
	// 		cout<<e<<" ";
	// 	}
	// }

	// vector<int> ans = topview(root);
	// for(auto v:ans) cout<<v<<" ";

	// vector<int> ans = bottomview(root);
	// for(auto v:ans) cout<<v<<" ";

	// vector<int> ans;
	// rightview(root,ans,0);
	// for(auto e:ans) cout<<e<<" ";
	// cout<<endl;
	// vector<int> ans1;
	// leftview(root,ans1,0);
	// for(auto e:ans1) cout<<e<<" ";

	// symmetrical binary tree
	// bool ans = issymmetric(root);
	// debug(ans)
	// if(ans) cout<<"symmetric"<<endl;
	// else cout<<"not symmetric"<<endl;

	// root to node path 
	// int x = 20;
	// if(findpath(root,x))
	// 	for(auto e:ans) cout<<e<<" ";
	// else
	// 	cout<<"no path"<<endl;

	// the LCA of two nodes in the binary tree:
	// brute force
	// this path is using the extra space 

	// int x,y;cin>>x>>y;
	// bool b = findpath(root,x);
	// vector<int> path1 = ans;
	// ans.clear();
	// bool c = findpath(root,y);
	// vector<int> path2 = ans;
	// reverse(path1.begin(),path1.end());
	// reverse(path2.begin(),path2.end());
	// int s = min(path1.sz(),path2.sz());
	// int p;
	// fr(i,1,s-1){
	// 	if(path1[i]==path2[i]) continue;
	// 	else{
	// 		p = i;
	// 	}
	// }
	// cout<<path1[p-1];

	// optimized way 
	// int x,y;
	// cin>>x>>y;
	// node* ans = findLCA(root,x,y);
	// cout<<ans->data<<" ";

	// max width of the binary tree
	
	// int ans = width(root);
	// cout<<ans<<endl;

	// the concept of the heapfy , where we used to mark the left and right child of any node by indexes of the parent 
	// for the 1 based indexes : parent -> i , left child = 2i , right child = 2i+1
	// for the 0 based indexes : parent -> i , left child = 2i+1 , right child = 2i+2;

	// in the level order traversal , as we keep moving ti the down , make the left child's index as 2*parents index +1 and for the right child
	// the index is : 2*the index of hte parent + 2
	// the level order traversal
	// segment tree => independent indexing
	// width = last - first + 1 

	// the child sum property:
	// every node has the value = left child + right child
	// while going down , if left + right < node => left = node , right = node
	// else if left + right > node => node = left + right
	// while going up the value of every node = node->left + node->right
	// return root

	// childsum(root);
	// printtree(root);
	// preorder(root);

	// print all nodes at level k
	// int k;cin>>k;
	// int t;cin>>t;
	// node* target = find(root,t);
	// // cout<<target->data<<" "<<target->r->data<<" "<<target->l->data;
	// vector<int> ans = findnodes(root,k,target);
	// for(auto e:ans) cout<<e<<" ";

	// min time taken to burn the entire binary tree from given node
	// find the parents of the all nodes in the tree for the radial outward traversal
	// ans = height of the target node

	// int x;cin>>x;
	// node* target = find(root,x);
	// // cout<<target->data;
	// unordered_map<node*,node*> parents;
	// findparentsofall(root,parents);
	// int ans = mintimetoburn(target,parents);
	// cout<<ans<<endl;

	// total number of the nodes in the complete binary tree
	// inorder(root);
	// cout<<countincbt(root);

	// construct the unique binary tree from the inorder and (preorder/postorder) traversals
	// map<int,vector<int>> ans = threetraversals(root);
	// node* root1 = build(ans[2],ans[1]);

	// map<int,vector<int>> ans1 = threetraversals(root1);
	// cout<<(ans[0]==ans1[0]?1:0)<<endl;

	// serialize and de serialize the binary tree
	// specializedlevelorder(root);
	// inorder(root);
	// string s = serialize(root);
	// cout<<s<<endl;
	// node* root1 = deserialize(s);
	// inorder(root1);

	// vector<int> ans = threddedinorder(root);
	// for(auto e:ans) cout<<e<<" ";
	// cout<<endl;
	// vector<int> ans1 = threddedpreorder(root);
	// for(auto e:ans1) cout<<e<<" ";

	// flatten the binary tree in the linked list
	// 1) recursive approach
	// 2) iterative approach using stack => extra O(n) space
	// 3) iterative approach in O(1)
	flatten(root);
	cout<<endl;
	inorder(root);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    #ifndef ONLINE_JUDGE
	freopen("error.txt","w",stderr); 
    #endif
	// int t;
	// cin>>t;
	// int p=t;
	// while(t--){
	// 	cout<<"Case #"<<p-t<<" : ";
	// 	solve();
	// }
	solve();
	return 0;
}