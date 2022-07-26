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

// ************ TRIE **************

class node{
public:
	char data;
	node* c[26];
	int cc;
	bool end;

	node(char ch){
		data = ch;
		fr(i,0,26) c[i]=null;
		cc=0;
		end = false;
	}
};

class Trie{
	public:
	node* root;

	Trie(){
		root = new node('\0');
	}

	Trie(char ch){
		root = new node(ch);
	}

	// void insertword(node* root,string word){
	// 	if(word.sz()==0){
	// 		root->end = true;
	// 		return;
	// 	}
	// 	int ind = word[0] - 'A';
	// 	node* child;
	// 	if(root->c[ind] != null){
	// 		child = root->c[ind];
	// 	}else{
	// 		root->c[ind] = new node(word[0]);
	// 		child = root->c[ind];
	// 	}
	// 	insertword(child,word.substr(1));
	// }

	// void insert(string word){
	// 	insertword(root,word);
	// }

	void insert(string word){
		node* curr = root;
		fr(i,0,word.sz()){
			int j = word[i]-'a';
			if(curr->c[j]==null){
				curr->c[j] = new node(word[j]);
				curr->cc++;
			}
			curr = curr->c[j];
		}
		curr->end = true;
	}	

	// bool searchword(node* root,string word){
	// 	if(word.sz()==0){
	// 		return root->end==true; 
	// 	}
	// 	int ind = word[0] - 'A';
	// 	node* child;
	// 	if(root->c[ind] != null){
	// 		child = root->c[ind];
	// 	}else{
	// 		return false;
	// 	}
	// 	return searchword(child,word.substr(1));
	// }

	// bool search(string word){
	// 	return searchword(root,word);
	// }

	bool search(string word){
		node* curr = root;
		fr(i,0,word.sz()){
			int j = word[i]-'a';
			if(curr->c[j]==null) return false;
			curr = curr->c[j];
		}
		return curr->end && curr;
	}

	bool searchprefix(string p){
		node* curr = root;
		fr(i,0,p.sz()){
			int j = p[i]-'a';
			if(!curr->c[j]) return false;
			curr = curr->c[j];
		}
		return curr;
	}

	void longestcommonprefix(string s,string& ans){
		int n = s.sz();
		node* curr = root;
		fr(i,0,n){
			char x = s[i];
			if(curr->cc==1){
				ans.pb(x);
				curr = curr->c[x-'a'];
			}else{
				break; 
			}
			if(curr->end) break;
		}
	}

	bool isempty(node* root){
		for(int i=0;i<26;i++)
			if(root->c[i]) return false;
		return true;
	}
	node* Delete(node* root,string s,int d=0){
		if(!root)
			return NULL;
		if(d==s.sz()){
			if(root->end) root->end = false;
			if(isempty(root)){
				delete(root);
				root = null;
			}
			return root;
		}

		int ci = s[d]-'a';
		root->c[ci] = Delete(root->c[ci],s,d+1);

		if(isempty(root) && !root->end){
			delete(root);
			root=null;
		}
		return root;
	}
};

void solve()
{	
	// Trie* t = new Trie();

	// t->insert("yash");
	// t->insert("yashjm");

	// cout<<t->search("yash")<<endl;
	// t->Delete(t->root,"yash");
	// cout<<t->search("yash")<<endl;
	// cout<<t->search("yashjm")<<endl;

	// // longest common prefix using the trie
	// string ans = "";
	// t->longestcommonprefix("yash",ans);
	// cout<<ans<<endl;

	// implement the phone directory

	Trie* t = new Trie();
	int n;cin>>n;
	fr(i,0,n){
		string s;
		cin>>s;
		t->insert(s);
	}
	string x;
	cin>>x;
	fr(i,0,x.sz()){

	}

	
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