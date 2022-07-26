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
template<class T>void _print(priority_queue<T> pq){ cerr<<"[ "; while(!pq.empty()) { _print(pq.top()); cerr<<" "; pq.pop();} cerr<<"]"; }
template<class T>void _print(priority_queue<T,vector<T>,greater<T>> pq){ cerr<<"[ "; while(!pq.empty()) { _print(pq.top()); cerr<<" "; pq.pop();} cerr<<"]"; }
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

// const int n = 1000;

// class heap{
// public:
	
// 	int* a;
// 	int s;
// 	heap(){
// 		a=new int[n];
// 		s=0;
// 		a[0]=-1;
// 	}
	
// 	void insert_max(int data){
// 		a[++s]=data;
// 		int i=s;

// 		while(i>1){
// 			int parent = i/2;
// 			if(a[parent]<a[i]){
// 				swap(a[i],a[parent]);
// 				i=parent;
// 			}else{
// 				return;
// 			}
// 		}
// 	}
	
// 	void insert_min(int data){
// 		a[++s]=data;
// 		int i=s;
// 		while(i>1){
// 			int parent = i/2;
// 			if(a[parent]>a[i]){
// 				swap(a[parent],a[i]);
// 				i=parent;
// 			}else{
// 				return;
// 			}
// 		}
// 	}
	
// 	void _print(){
// 		fr(i,1,s+1)
// 			cout<<a[i]<<" ";
// 		cout<<endl;
// 	}
	
// 	void _delete_max(){
// 		if(!s) return;
// 		a[1]=a[s--];
// 		int i=1;
// 		while(i<s){
// 			int lc=2*i;
// 			int rc=2*i+1;

// 			if( lc<=s && rc<=s && a[i]<a[lc] && a[i]<a[rc]){
// 				int mc = (a[lc]>a[rc]?lc:rc);
// 				swap(a[i],a[mc]);
// 				i=mc;
// 			}
// 			else if( lc<=s && a[i]<a[lc] ){
// 				swap(a[lc],a[i]);
// 				i=lc;
// 			}else if( rc<=s && a[i]<a[rc] ){
// 				swap(a[rc],a[i]);
// 				i=rc;
// 			}else{
// 				return;
// 			}
// 		}	
// 	}
	
// 	void _delete_min(){
// 		if(!s) return;
// 		a[1]=a[s--];
// 		int i=1;
// 		while(i<s){
// 			int lc=2*i;
// 			int rc=2*i+1;

// 			if( lc<=s && rc<=s && a[i]>a[lc] && a[i]>a[rc]){
// 				int mc = (a[lc]>a[rc]?rc:lc);
// 				swap(a[i],a[mc]);
// 				i=mc;
// 			}
// 			else if( lc<=s && a[i]>a[lc] ){
// 				swap(a[lc],a[i]);
// 				i=lc;
// 			}else if( rc<=s && a[i]>a[rc] ){
// 				swap(a[rc],a[i]);
// 				i=rc;
// 			}else{
// 				return;
// 			}
// 		}	
// 	}
// };

// void max_heapify(vector<int>& v,int n,int i){
// 	int l=i;
// 	int lc=2*i;
// 	int rc=2*i+1;

// 	if(lc<n && v[l]<v[lc]) l=lc;
// 	if(rc<n && v[l]<v[rc]) l=rc;

// 	if(l!=i){
// 		swap(v[i],v[l]);
// 		max_heapify(v,n,l);
// 	}
// }

// void min_heapify(vector<int>& v,int n,int i){
// 	int l=i;
// 	int lc=2*i;
// 	int rc=2*i+1;

// 	if(lc<n && v[l]>v[lc]) l=lc;
// 	if(rc<n && v[l]>v[rc]) l=rc;

// 	if(l!=i){
// 		swap(v[i],v[l]);
// 		min_heapify(v,n,l);
// 	}
// }

// void heapsort(vector<int>& v,int n){
// 	for(int i=n/2;i>0;i--){
// 		max_heapify(v,n+1,i);
// 	}
// 	int t=n;
// 	while(t>1){
// 		swap(v[1],v[t]);
// 		t--;
// 		max_heapify(v,t,1);
// 	}
// }

// // for 0 based indexes
// void heapify(int a[],int n,int i){
// 	int l=i;
// 	int lc=2*i+1;
// 	int rc=2*i+2;

// 	if(lc<n && a[l]<a[lc]) l=lc;
// 	if(rc<n && a[l]<a[rc]) l=rc;

// 	if(l!=i){
// 		swap(a[l],a[i]);
// 		heapify(a,n,l);
// 	}
// }

// void heapsort(int a[],int n){
// 	rf(i,n/2 -1,-1) heapify(a,n,i);

// 	int t=n-1;
// 	while(t>0){
// 		swap(a[0],a[t]);
// 		heapify(a,t,0);
// 		t--;
// 	}
// }
// till here

// vector<int> kLargest(vector<int>& v,int n,int k){
// 	vector<int> ans;
// 	priority_queue<int,vector<int>,greater<int>> pq;
// 	fr(i,0,n){
// 		if(i<=k-1) pq.push(v[i]);
// 		else{
// 			if(v[i]>pq.top()){
// 				pq.pop();
// 				pq.push(v[i]);
// 			}
// 		}
// 	}
// 	while(!pq.empty()){
// 		ans.pb(pq.top());
// 		pq.pop();
// 	}
// 	reverse(all(ans));
// 	return ans;
// }

//*******************************************************************

// int getpivotindex(vector<int>& v,int l,int h){
// 	int pivotelement=v[h];
// 	int pivotpoint=l;
// 	fr(i,l,h){
// 		if(v[i]<pivotelement){
// 			swap(v[i],v[pivotpoint]);
// 			pivotpoint++;
// 		}
// 	}
// 	swap(v[pivotpoint],v[h]);
// 	return pivotpoint;
// }

// int kthsmallest(vector<int>& v,int l,int h,int k){
// 	int pivotindex=getpivotindex(v,l,h);
// 	if(pivotindex==k-1)return v[pivotindex];
// 	else if(pivotindex<k-1)return kthsmallest(v,pivotindex+1,h,k);
// 	else return kthsmallest(v,l,pivotindex-1,k);
// }

//*******************************************************************

/****/
// string reorganize(string s){
//     string ans="";
// 	int mf=0;
// 	map<char,int> m;
// 	for(auto e:s) m[e]++,mf=max(mf,m[e]);
// 	map<int,char> m2;
// 	debug(m)
// 	for(auto p:m) m2.insert(mp(p.s,p.f));
// 	if(mf > (s.size()+1)/2)return ans;
// }
/****/


// class node{
// public:
// 	int data;
// 	node* next;
// 	node(){
// 		data=0;
// 		next=null;
// 	}
// 	node(int val){
// 		data=val;
// 		next=null;
// 	}
// 	node(int val,node* n){
// 		data=val;
// 		next=n;
// 	}
// };

// void printlist(node* head){
// 	while(head!=null){
// 		cout<<head->data<<" ";
// 		head=head->next;
// 	}
// }

// void _insert(node* &head,int val){
// 	node* n=new node(val);
// 	if(head==null){
// 		head=n;
// 		return;
// 	}
// 	node* t=head;
// 	while(t->next!=null){
// 		t=t->next;
// 	}
// 	t->next=n;
// }

// node* merge(vector<node*>& v,int k){
// 	node* ans = new node();
// 	node* rans = ans;

// 	priority_queue<pair<int,node*>,vector<pair<int,node*>>,greater<pair<int,node*>>> pq;

// 	fr(i,0,k){
// 		pq.push(mp(v[i]->data,v[i]));
// 	}

// 	// debug(pq)
// 	while(!pq.empty()){

// 		pair<int,node*> cl = pq.top();
// 		pq.pop();

// 		if(cl.s->next){
// 			pair<int,node*> cln = mp(cl.s->next->data,cl.s->next);
// 			cl.s->next=null;
// 			pq.push(cln); 
// 		}

// 		ans->next = cl.s;
// 		ans=ans->next;
// 	}

// 	rans=rans->next;
// 	return rans;
// }


// string stringaddition(string s1,string s2){
// 	string ans="";     
// 	int carry=0;        
// 	int n = s1.size(), m = s2.size();                
// 	reverse(s1.begin(),s1.end());
// 	reverse(s2.begin(),s2.end());
// 	debug(s1)
// 	debug(s2)
// 	string d = (max(n,m)==n?s1:s2);

// 	int i=0;
// 	while(i<min(n,m)){
// 		int x = (s1[i]-'0'+s2[i]-'0'+carry);
// 		int y = x%10;
// 		char seek = char((int)'0'+y);
// 		carry = x/10;
// 		i++;
// 		ans+=seek;
// 	}

// 	while(i<max(m,n)){
// 		if(d==s1){
// 			int x = (s1[i]-'0'+carry);
// 			int y = x%10;
// 			char seek = char((int)'0'+y);
// 			carry = x/10;
// 			i++;
// 			ans+=seek;
// 		}else{
// 			int x = (s2[i]-'0'+carry);
// 			int y = x%10;
// 			char seek = char((int)'0'+y);
// 			carry = x/10;
// 			i++;
// 			ans+=seek;
// 		}
// 	}

// 	if(carry!=0) ans+=(char((int)'0'+carry));
     
// 	reverse(ans.begin(),ans.end());
//     i=0;
//     while(i<ans.size() && ans[i]=='0')
//         i++;
//     return ans.substr(i); 
// }

// class node{
// public:
// 	int data;
// 	node* l;
// 	node* r;

// 	node(){
// 		data = 0;
// 		l = null;
// 		r = null;
// 	}// for the dummy/null node

// 	node(int val){
// 		data = val;
// 		l = null;
// 		r = null;
// 	}

// 	node(int val,node* left,node* right){
// 		data = val;
// 		l = left;
// 		r = right;
// 	}
// };

// vector<int> inorder_traversal;

// void inorder(node* root){
// 	if(root==null) return;
// 	inorder(root->l);
// 	inorder_traversal.pb(root->data);
// 	inorder(root->r);
// }

// void preorder(node* root,int& i){
// 	if(root==null) return;
// 	root->data = inorder_traversal[i++];
// 	preorder(root->l,i);
// 	preorder(root->r,i);
// }

// const int N = 1e4+7;
// vector<int> childc(N);

// void inorder(node* root){
// 	if(root==null){
// 		// childc[root->data]=1;
// 		return;
// 	}
// 	int ans=1;
// 	if(root->l){
// 		inorder(root->l);
// 		ans+=childc[root->l->data];
// 	}
// 	if(root->r){
// 		inorder(root->r);
// 		ans+=childc[root->r->data];
// 	}
// 	childc[root->data]=ans;
// }

// bool checkformaxheap(node* root){
// 	if(root==null) return true;
// 	bool left,right,b = true;
// 	if(root->l) left = checkformaxheap(root->l);
// 	if(root->r) right = checkformaxheap(root->r);
// 	if(root->l && root->r){
// 		b = b && (root->data > root->l->data) && (root->data > root->r->data) && left && right && childc[root->l->data]>=childc[root->r->data];
// 	}
// 	else if(root->l && !root->r){
// 		b = b && (root->data > root->l->data) && left;
// 	}
// 	else if(!root->l && root->r){
// 		return false;
// 	}
// 	else if(!root->l && !root->r){
// 		return true;
// 	}
// 	return b;
// }

// **

// float addandprint(priority_queue<int>& maxheap,priority_queue<int,vector<int>,greater<int>>& minheap,int x){
// 	if(maxheap.sz()==0 || x<=maxheap.top()) maxheap.push(x);
// 	else minheap.push(x);

// 	if(maxheap.sz() > minheap.sz()+1){
// 		minheap.push(maxheap.top());
// 		maxheap.pop();
// 	}
// 	else if(maxheap.sz() < minheap.sz()){
// 		maxheap.push(minheap.top());
// 		minheap.pop();
// 	}

// 	if(maxheap.sz() > minheap.sz()){
// 		return maxheap.top()/1.0;
// 	}
// 	else{
// 		return (maxheap.top()+minheap.top())/2.0;
// 	}
// }

// class x{
// public:
// 	int val;
// 	int i;
// 	int an;
// 	int as;

// 	x(int a,int b,int c,int d){
// 		val=a;
// 		i=b;
// 		an=c;
// 		as=d;
// 	}
// };

// struct com{
// 	bool operator()(x a,x b){
// 			return a.val>b.val;}
// };

// pair<int,int> minrange(vector<vector<int>>& v,int n){
// 	int mn = int_max, mx=int_min, range = int_max;
// 	priority_queue<x,vector<x>,com> pq;
// 	int l,h;
// 	fr(i,0,n){
// 		pq.push((v[i][0],0,i,v[i].sz()));
// 		mn = min(mn,v[i][0]);
// 		mx = max(mx,v[i][0]);
// 	}
// 	while(!pq.empty()){
// 		x a=pq.top();
// 		pq.pop();
// 		int mm = a.val;
// 		if(range>mx-mm){
// 			mn = mm;
// 			range = mx-mn;
// 			l=mn;
// 			h=mx;
// 		}

// 		if(a.i==a.as-1) break;
// 		a.i++;
// 		pq.push(v[a.an][a.i],a.i,a.an,v[a.an].sz());
// 		mx = max(mx,v[a.an][a.i]);
// 	}

// 	return mp(l,h);
// }

// double median(vector<int>& v){
// 	int n=v.sz();
// 	if(n%2==0) return (double)((v[n/2]+v[n/2 -1])/2.0);
// 	else return (double)v[n/2];
// }

// double findmedian(vector<int>& nums1,vector<int>& nums2){
// 	int n=nums1.sz(),m=nums2.sz();
// 	if(n==0){
// 		return (double)median(nums2);
// 	}
// 	else if(m==0){
// 		return (double)median(nums1);
// 	}
// 	else if(n<=m){
// 		int begin=0,end=n;
//    		double ans;
// 		while(begin<=end){
// 			int i=(begin+end)/2;
// 			int j=(n+m+1)/2 - i;

// 			int min1,max1,min2,max2;

// 			min1=(i==n)?INT_MAX:nums1[i];
// 		    max1=(i==0)?INT_MIN:nums1[i-1];
	            
// 			min2=(j==m)?INT_MAX:nums2[j];
// 			max2=(j==0)?INT_MIN:nums2[j-1];
	            
// 			if(max1<=min2 && max2<=min1){
// 				if((n+m)%2 ==0){
// 					ans = (double)((min(min1,min2)+max(max1,max2))/2.0);
// 				}else{
// 					ans = (double)(max(max1,max2));
// 				}
// 				break;
// 			}
// 			else if(max1>min2){
// 				end=i-1;
// 			}
// 			else{
// 				begin=i+1;
// 			}
// 		}
// 		return ans;
// 	}
// 	else{
// 		return (double)(findmedian(nums2,nums1));
// 	}
// }

// const int Max = 5000;
// vector<int> ans(Max+1,0);

// int multiply(int x,int anss){
// 	int carry=0;
// 	fr(i,0,anss){
// 		int p = ans[i]*x + carry;
// 		carry = p/10;
// 		ans[i]=p%10;
// 	}
// 	while(carry){
// 		ans[anss]=carry%10;
// 		carry/=10;
// 		anss++;
// 	}
// 	return anss;
// }

// void fact(int n){
// 	ans[0]=1;
// 	int anss=1;

// 	fr(i,2,n+1) anss=multiply(i,anss);
// 	rf(i,anss-1,-1) cout<<ans[i];
// 	debug(anss)
// }

int global_x = int_min;

bool cmp(int a,int b){
	if(a<0) a=(-1)*a/global_x;
	else a=a/global_x;
	if(b<0) b=(-1)*b/global_x;
	else b=b/global_x;
	return a<b;
}











void solve()
{	
	// int n;cin>>n;
	// int a[n];
	// fr(i,0,n) cin>>a[i];
	// heapsort(a,n);
	// fr(i,0,n) cout<<a[i]<<" ";

	// ** sliding window maximum
	
	// int n,k;cin>>n>>k;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];

	// approach 1 -> brute force approach -> time O(NK) , space O(K)
	// approach 2 -> using the priority queue

	// this approach is correct but the .remove() function is not implemented in the c++14 , 
	// though the java code with same logic works fine
	// time O(N*logK) , space O(K)

	// priority_queue<int> pq;
	// fr(i,0,n){
	// 	pq.insert(v[i]);
	// 	if(i>=k-1){
	// 		cout<<pq.peek()<<" ";
	// 		pq.remove(v[i-k+1]);
	// 	}
	// }

	// approach 3 -> using the deque and concept of usefull element

	// deque<int> d;
	// for(int i=0;i<k;i++){
	// 	while(!d.empty() && v[i]>=v[d.back()]) d.ppb();
	// 	d.pb(i);
	// }
	// for(int i=k;i<n+1;i++){
	// 	cout<<v[d.front()]<<" ";
	// 	if(i<n){
	// 		while(!d.empty() && d.front()<=i-k) d.ppf();
	// 		while(!d.empty() && v[i]>=v[d.back()]) d.ppb();
	// 		d.pb(i);
	// 	}
	// }

	// k largest elements in the array
	// approach 1 -> sort array , k elements from the back : time O(K+NlogN) , space O(1)

	// approach 2 -> make the max_heap of array -> pop pop out the k elements 
	
	// int n,k;cin>>n>>k;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];

	// priority_queue<int> pq;
	// fr(i,0,n) pq.push(v[i]);

	// fr(i,0,k){
	// 	cout<<pq.top()<<" ";
	// 	pq.pop();
	// }

	// time O(K+NlogN) , space O(K)

	// approach 3 -> instead of making heap of N elements make heap of only k elements

	// int n,k;cin>>n>>k;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];

	// vector<int> ans = kLargest(v,n,k);
	// for(auto e:ans) cout<<e<<" ";

	// time : O(N+KlogK) , space : O(K)

	// kth largest element:

	// approach 1: sort
	// approach 2: max_heap and min_heap
	
	// int n,k;cin>>n>>k;
	// vector<int> v(n);
	// // int k;cin>>n;
	// fr(i,0,n) cin>>v[i];
	
	// priority_queue<int> pq;
	// fr(i,0,n) pq.push(v[i]);
	// fr(i,0,k-1) pq.pop();
	// cout<<pq.top()<<endl;

	// time : O(N+KlogN) , space : O(N)
	// for kth smallest -> min heap

	// **approach 3: Quick select

	// int n,k;cin>>n>>k;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];

	// cout<<kthsmallest(v,0,n-1,n-k+1);

	// kth smallest -> k-1 index
	// kth largest -> (N-k+1)th smallest -> (N-K)th smallest
	// time : O(N) , space : O(1)

	// **merge k sorted arrays

	// int n;cin>>n;
	// vector<vector<int>> v;
	// fr(i,0,n){
	// 	int m;cin>>m;
	// 	vector<int> t(m);
	// 	fr(j,0,m) cin>>t[j];
	// 	v.pb(t);
	// }

	// vector<int> ans;
	// vector<int> index(n,0);
	// priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;

	// fr(i,0,n){
	// 	pq.push(mp(v[i][0],i));
	// }

	// while(!pq.empty()){
	// 	pair<int,int> p=pq.top();
	// 	pq.pop();
	// 	int ce = p.f;
	// 	ans.pb(ce);
	// 	int num = p.s;
	// 	if(index[num]+1<v[num].sz())
	// 		pq.push(mp(v[num][index[num]+1],num));
	// 	index[num]++;
	// }

	// for(auto e:ans) cout<<e<<" ";

	// string s;cin>>s;
	// string ans = reorganize(s);
	// cout<<ans<<endl;

	// kth largest continues sum sub array

	// xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

	// priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	// int n,k;cin>>n>>k;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];

	// int mx = int_min;
	// int sum = v[0];
	// // pq.push(mp(v[0],0));

	// set<int> us;
	// // us.insert(v[0]);

	// fr(i,1,n){
	// 	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> ans;
	// 	ans.push(mp(v[i],i));
	// 	us.insert(v[i]);
	// 	if(us.sz()==k-1) us.erase(us.begin());
	// 	while(!pq.empty()){
	// 		pair<int,int> p=pq.top();
	// 		pq.pop();
	// 		if(us.find(p.f)==us.end() || ans.sz()<k){
	// 						debug(p.f)
	// 						ans.push(p),us.insert(p.f);}
	// 		// if pair with already p.f present in pq then dont push
	// 		if(ans.sz()>k)ans.pop(),us.erase(us.begin());
	// 		if(p.s==i-1){
	// 			// insert(p.s+v[i],i)
	// 			if(us.find(p.f+v[i])==us.end() || ans.sz()<k){
	// 								debug(p.f+v[i])
	// 								ans.push({p.f+v[i],i}),us.insert(p.f+v[i]);}
	// 			if(ans.sz()>k)ans.pop(),us.erase(us.begin());
	// 		}
	// 	}
	// 	pq=ans;
	// 	debug(us)
	// }
	// cout<<pq.top().f<<endl;
	// time : O(NKlogK)

	// xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

	// priority_queue<int,vector<int>,greater<int>> pq;
	// int n,k;cin>>n>>k;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];

	// fr(i,0,n){
	// 	int cs=0;
	// 	fr(j,i,n){
	// 		cs+=v[j];
	// 		pq.push(cs);
	// 		if(pq.sz()>k) pq.pop();
	// 	}
	// }
	// cout<<pq.top()<<endl;

	// time : O(N^2 * logK)

	// reorganize the string
	// string s;cin>>s;
	// int mf=int_min;
	// unordered_map<char,int> m;
	// for(auto e:s) m[e]++,mf=max(mf,m[e]);

	// string ans = "";

	// if(mf<=(s.sz()+1)/2){
	// 	priority_queue<pair<int,char>> pq;
	// 	for(auto e:m){
	// 		pq.push(mp(e.s,e.f));
	// 	}
	// 	fr(i,0,s.sz()/2){
	// 		// __print(pq);
	// 		pair<int,char> p1=pq.top();
	// 		pq.pop();
	// 		pair<int,char> p2=pq.top();
	// 		pq.pop();
	// 		ans.pb(p1.s);
	// 		ans.pb(p2.s);
	// 		if(p1.f-1!=0) pq.push(mp(p1.f-1,p1.s));
	// 		if(p2.f-1!=0) pq.push(mp(p2.f-1,p2.s));
	// 		// __print(pq);
	// 	}
	// 	if(!pq.empty())
	// 		ans.pb(pq.top().s);
	// }
	// cout<<ans<<endl;
	// time : worst : O(SlogS) , space O(S)

	// *merge k sorted linked list
	// int k;cin>>k;
	// vector<node*> v(k);

	// fr(i,0,k){
	// 	node* hi = new node();
	// 	int n;cin>>n;
	// 	v[i] = hi;
	// 	fr(j,0,n){
	// 		int x;cin>>x;
	// 		hi->next = new node(x);
	// 		hi = hi->next;
	// 	}
	// 	v[i]=v[i]->next;
	// }

	// node* ans=merge(v,k);
	// printlist(ans);

	// minimum cost to connect all ropes , connecting two ropes cost is sum of their lengths
	// int n;cin>>n;
	// vector<int> v(n);
	// priority_queue<int,vector<int>,greater<int>> pq;
	// fr(i,0,n) cin>>v[i],pq.push(v[i]);
	// int ans=0;
	// fr(i,0,n-1){
	// 	int a=pq.top();
	// 	pq.pop();
	// 	int b=pq.top();
	// 	pq.pop();
	// 	ans+=(a+b);
	// 	pq.push(a+b);
	// }

	// cout<<ans<<endl;

	// large string addition
	// string s1,s2;cin>>s1>>s2;
	// string ans = stringaddition(s1,s2);
	// cout<<ans<<endl;

	// convert the complete BST in to min heap
	// node* root = new node(4);
	// root->l = new node(2);
	// root->r = new node(6);
	// root->l->l = new node(1);
	// root->l->r = new node(3);
	// root->r->l = new node(5);
	// root->r->r = new node(7);

	// int i=0;
	// inorder(root);
	// debug(inorder_traversal);
	// preorder(root,i);
	// inorder_traversal.clear();
	// inorder(root);
	// debug(inorder_traversal);

	// check if the binary tree is a max heap
	// node* root = new node(10);
	// root->l = new node(9);
	// root->r = new node(8);
	// root->l->l = new node(7);
	// root->l->r = new node(6);
	// root->r->l = new node(5);
	// root->r->r = new node(9);

	// inorder(root);
	// debugv(childc,1,11);
	// bool b = checkformaxheap(root);
	// cout<<b<<endl;

	// ************************************* median in a stream of integers *******************************************

	// approach 1 :
	// int n;cin>>n;
	// vector<int> s;
	// fr(i,0,n){
	// 	int x;cin>>x;
	// 	s.pb(x);
	// 	sort(all(s));
	// 	if(s.sz()%2){
	// 		cout<<s[s.sz()/2]<<" ";
	// 	}else{
	// 		float x = float(s[(s.sz()-1)/2]);
	// 		float y = float(s[(s.sz()+1)/2]);
	// 		float ans = (x+y)/2.0;
	// 		cout<<ans<<" ";
	// 	}
	// }
	// time : O(N*N*logN) , space : O(N)

	// approach 2 : insertion sort : maintaining the sorted array and each time after adding elements find the median
	// time : O(N*N) , space : O(N)

	// approach 3 : using one max heap and one min heap

	// priority_queue<int> maxheap;
	// priority_queue<int,vector<int>,greater<int>> minheap;
	// int n;cin>>n;
	// fr(i,0,n){
	// 	int x;cin>>x;
	// 	cout<<addandprint(maxheap,minheap,x)<<" ";
	// }

	// time : O(NlogN) , space : O(N).

	// ************************************* minimum range in K lists *************************************************

	// int n;cin>>n;
	// vector<vector<int>> lists;
	// fr(i,0,n){
	// 	int x;cin>>x;
	// 	vector<int> t(x);
	// 	fr(j,0,x) cin>>t[i];
	// }

	// pair<int,int> ans = minrange(lists,n);
	// cout<<ans.f<<" "<<ans.s<<endl;

	// ****************************************************************************************************************

	// rearrange the array with alternating positive and negative elements
	
	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];

	// approach 1 : time : O(N) , space : O(N) -> order will be maintained
	
	// deque<int> pos,neg;
	// for(auto e:v){
	// 	if(e<0) neg.pb(e);
	// 	else pos.pb(e);
	// }
	// v.clear();
	// while(pos.sz() && neg.sz()){
	// 	v.pb(neg.front());
	// 	neg.ppf();
	// 	v.pb(pos.front());
	// 	pos.ppf();
	// }
	// while(pos.sz()){
	// 	v.pb(pos.front());
	// 	pos.ppf();
	// }
	// while(neg.sz()){
	// 	v.pb(neg.front());
	// 	neg.ppf();
	// }
	// debug(v)

	// approach 2 : time : O(N) , space : O(1) -> order wont be maintained

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];

	// int i=0,j=n-1;

	// while(i<j && i<n && j>=0){
	// 	if(v[i]>=0 && v[j]<0) i++,j--;
	// 	else if(v[i]>=0 && v[j]>=0) i++;
	// 	else if(v[i]<0 && v[j]<0) j--;
	// 	else if(v[i]<0 && v[j]>=0) swap(v[i++],v[j--]);
	// }

	// debug(v)

	// int fn=-1;
	// fr(i,0,n){
	// 	if(v[i]<0) {fn=i;break;}
	// }

	// if(fn!=-1){
	// 	i=0;
	// 	while(i<fn && i<n && fn<n){
	// 		swap(v[i],v[fn]);
	// 		i+=2;
	// 		fn++;
	// 	}
	// }

	// debug(v)

	// approach 3 : time : O(N*logN) , space : O(1)

	// int n;cin>>n;
	// int x=int_min;
	// vector<int> v(n);
	// fr(i,0,n){ cin>>v[i];x=max(x,v[i]); }

	// x+=5;
	// global_x=x;

	// int ne=0,p=1;
	// fr(i,0,n){
	// 	if(v[i]>=0){
	// 		v[i]+=(p*x);
	// 		p+=2;
	// 	}else{
	// 		v[i]-=(ne*x);
	// 		ne+=2;
	// 	}
	// }

	// sort(v.begin(),v.end(),cmp);
	// fr(i,0,n) v[i]=v[i]%x;
	// debug(v)

	// ****************************************************************************************************************

	// find if there is a sub array with sum equall to zero
	// int n;cin>>n;
	// vector<int> v(n);fr(i,0,n) cin>>v[i];

	// approach 1 : time : O(N*N*N) , space : O(1)

	// bool b = false;
	// fr(i,0,n){
	// 	fr(j,i,n){
	// 		int sum = 0;
	// 		fr(k,i,j+1){
	// 			sum+=v[k];
	// 		}
	// 		if(sum==0){
	// 			b=true;
	// 			break;
	// 		}
	// 	}
	// }
	// cout<<b<<endl;

	// approach 2 : time : O(N*N) , space : O(1)
	
	// bool b = false;
	// fr(i,0,n){
	// 	int sum=0;
	// 	fr(j,i,n){
	// 		sum+=v[j];
	// 		if(v[j]==0||sum==0){
	// 			b=true;break;
	// 		}
	// 	}
	// }
	// cout<<b<<endl;

	// approach 3 : time : O(N) , space : O(1)
	
	// bool b=false;
	// set<int> s;
	// int sum=0;
	// fr(i,0,n){
	// 	sum+=v[i];
	// 	if(sum==0 || v[i]==0 || s.find(sum)!=s.end()){b=true;break;}
	// 	else s.insert(sum);
	// }
	// cout<<b<<endl;
	// debug(s)

	// ** sub array with sum = k;
	
	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	// int k;cin>>k;

	// bool b=false;
	// unordered_set<int> s;
	// int sum=0;
	// fr(i,0,n){
	// 	sum+=v[i];
	// 	if(sum==k || v[i]==k || s.find(sum-k)!=s.end()){b=true;break;}
	// 	else s.insert(sum);
	// }
	// cout<<b<<endl;
	// space : O(N) , time : O(N)

	// maximum product sub array
	// approach 1 : check for all subarrays : time : O(N*N) , space : O(1)
	// approach 2 : kadane's algo variation : time : O(N) , space : O(1)

	// int n;cin>>n;
	// vector<int> v(n);fr(i,0,n) cin>>v[i];

	// int ans=int_min;
	// int prod=1;
	// fr(i,0,n){
	// 	if(!prod) prod=1;
	// 	prod*=v[i];
	// 	ans=max(ans,prod);
	// }

	// prod=1;
	// rf(i,n-1,-1){
	// 	if(!prod) prod=1;
	// 	prod*=v[i];
	// 	ans=max(ans,prod);
	// }
	// cout<<ans<<endl;

	// find longest consequetive subsequence

	// int n;cin>>n;
	// vector<int> v(n);fr(i,0,n) cin>>v[i];	

	// approach 1 : sort then check linearly : time : O(NlogN) , space : O(1)
	// sort(all(v));
	// int ans=1,c=1;
	// fr(i,0,n-1){
	// 	if(v[i]+1==v[i+1])c++;
	// 	else if(v[i]==v[i+1]) continue;
	// 	else{
	// 		ans=max(ans,c);
	// 		c=1;
	// 	}
	// }
	// cout<<ans<<endl;

	// approach 2 : extra space : O(max(v)) , time : O(max(v))

	// int m = *max_element(all(v));
	// vector<int> p(m+1,0);
	// fr(i,0,n) p[v[i]]=1;
	// fr(i,1,m+1){
	// 	if(p[i]!=0 && p[i-1]!=0) p[i]+=p[i-1];
	// }
	// // debug(p)
	// cout<<*max_element(all(p));

	// max profit by selling the product atmost 2 times
	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	// int fb=int_max,sb=int_max,fs=0,ss=0;
	// fr(i,0,n){
	// 	fb=min(fb,v[i]);
	// 	fs=max(fs,v[i]-fb);
	// 	sb=min(sb,v[i]-fs);
	// 	ss=max(ss,v[i]-sb);
	// }
	// cout<<ss<<endl;

	// check if a1 is subset of a2 , sorted/unsorted with duplicates
	
	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	// int m;cin>>m;
	// vector<int> b(m);
	// fr(i,0,m) cin>>b[i];

	// unordered_map<int,int> m1,m2;
	// for(auto e:v) m1[e]++;
	// for(auto e:b) m2[e]++;

	// debug(m1)
	// debug(m2)

	// bool bb=true;
	// for(auto p:m2){
	// 	int e = p.f;
	// 	if(m1.find(e)!=m1.end() && m1[e]>=m2[e]) continue;
	// 	else{
	// 		bb=false;
	// 		break;
	// 	}
	// }
	// cout<<bb<<endl;
	
	// time : O(N) , space : O(N)

	// **trapping rain water problem
	// approach 1 : time : O(N*N) , space : O(1)
	// -> at every block find the max on both side then calculate for that block and add it into ans

	// approach 2 : left and right max array , time : O(N) , space : O(N)
	
	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];

	// vector<int> left(n,0),right(n,0);
	// left[0]=v[0];
	// right[n-1]=v[n-1];

	// fr(i,1,n) left[i]=max(v[i],left[i-1]);
	// rf(i,n-2,-1) right[i]=max(v[i],right[i+1]);
	// int ans=0;
	// fr(i,0,n){
	// 	ans+=(min(left[i],right[i])-v[i]);
	// }

	// cout<<ans<<endl;

	// minimum swaps to bring the elements with value <=k in array together

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	// int k;cin>>k;
	// int c=0;
	// fr(i,0,n) if(v[i]<=k) c++;
	// debug(c)
	// int ans = INT_MAX;
	// int inwindow=0;
	// fr(i,0,n){
	// 	if(i<c) {if(v[i]<=k)inwindow++;}
	// 	else{
	// 		if(v[i]<=k) inwindow++;
	// 		if(v[i-c]<=k && inwindow>0) inwindow--;
	// 	}
	// 	ans=min(ans,c-inwindow);
	// 	if(i>=c-1) {debug(inwindow);}
	// }
	// cout<<ans<<endl;
	// time : O(N) , space : O(1)

	// smallest sub array with value greater than x

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	// int ans=int_max;
	// int k;cin>>k;
	// int i=0;
	// int sum=0;
	// fr(j,0,n+1){
	// 	if(sum<=k && j<n) sum+=v[j];
	// 	else if(sum>k || (j==n && sum>k)){
	// 		ans=min(ans,j-i);
	// 		sum-=v[i++];
	// 		j--;
	// 	}
	// }
	// cout<<ans<<endl;

	// ** find median of 2 sorted arrays
	
	// approach 1 : merge then sort then find median : O((n+m)log(n+m)) , O(n+m)
	// approach 2 : merge two sorted : O(n+m) , O(n+m)

	// approach 3 : log(min(n,m)) , O(1)
	// int n,m;cin>>n;
	// vector<int> v1(n);
	// fr(i,0,n) cin>>v1[i];
	// cin>>m;
	// vector<int> v2(m);
	// fr(i,0,m) cin>>v2[i];

	// double ans=findmedian(v1,v2);
	// cout<<ans<<endl;

	// three way paritioning
	
	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];

	// int a,b;cin>>a>>b;

	// int start=0,end=n-1;
	// for(int i=0;i<=end;){
	// 	if(v[i]<a){
	// 		if(i==start){
	// 			i++,start++;
	// 		}else{
	// 			swap(v[i++],v[start++]);
	// 		}
	// 	}
	// 	else if(v[i]>b){
	// 		swap(v[i],v[end--]);
	// 	}
	// 	else
	// 		i++;
	// }
	// debug(v)

	// **find the addition and multiplication of two large numbers 

	// addition : O(max(n,m)) , O(max(n,m))
	
	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	// int m;cin>>m;
	// vector<int> b(m);
	// fr(i,0,m) cin>>b[i];

	// vector<int> ans(max(n,m)+1,0);
	// int i=n-1,j=m-1;
	// for(int k=max(n,m);k>=1;k--){
	// 	if(i>=0) ans[k]+=v[i--];
	// 	if(j>=0) ans[k]+=b[j--];
	// 	int t=ans[k]%10;
	// 	int carry=ans[k]/10;
	// 	ans[k]=t;
	// 	ans[k-1]+=carry; 
	// }
	// debug(ans)

	// multiplication of a large number with the integer of 1 digit : O(n) , O(1)

	// int n;cin>>n;
	// vector<int> v(n+1);
	// fr(i,1,n+1) cin>>v[i];
	// v[0]=0;
	// int k;cin>>k;

	// int carry=0;
	// for(int i=n;i>=1;i--){
	// 	int p=v[i]*k;
	// 	p+=carry;
	// 	v[i]=p%10;
	// 	carry=p/10;
	// }
	// v[0]=carry;
	// debug(v)

	// multiplication of two large numbers

	// int n;cin>>n;vector<int> v(n);fr(i,0,n) cin>>v[i];
	// int m;cin>>m;vector<int> b(m);fr(i,0,m) cin>>b[i];
	// vector<int> ans(n+m,0);

	// int carry=0;
	// for(int i=m-1;i>=0;i--){
	// 	carry=0;
	// 	for(int j=n-1;j>=0;j--){
	// 		int r = b[i]*v[j] + carry + ans[i+j+1];
	// 		ans[i+j+1] = r%10;
	// 		carry = r/10;
	// 	}
	// 	ans[i]=carry;
	// 	debug(ans)
	// }
	// int i=0;
	// while(i<ans.sz() && ans[i]==0) i++;

	// for(;i<ans.sz();i++) cout<<ans[i]<<" ";

	// factorial of a large number
	// approach 1 : linear multiplication of two large numbers : O(N*N*N) , O(N)

	// approach 2 : O(N*log(N!)) ~ O(N*N*log(N)) & O(MAX) using the array of size MAX

	// int n;cin>>n;
	// fact(n);
	// debug(ans) // fact(n) has ceil(log 10(n!)) digits

	// approach 3 : O(N*log(N!)) ~ O(N*N*log(N)) & O(1) --- using the linked list

	// min no of jumps to reach end of the array

	// approach 1 : O(N*N) , O(N)
	
	// scanvector(v,n);
	// vector<int> dp(n,INT_MAX);
	// dp[0]=0;

	// fr(i,1,n){
	// 	fr(j,0,i){
	// 		if(dp[j]!=INT_MAX && v[j]+j>=i){
	// 			if(dp[j]+1<dp[i]) dp[i]=dp[j]+1;
	// 		}
	// 	}
	// }
	// debug(dp)
	// if(dp.back()!=INT_MAX) cout<<dp.back()<<endl;
	// else cout<<-1<<endl;

	// approach 2 : O(N) , O(1)

	// int ans=int_max;
	// scanvector(v,n);
	// if(n==1) ans=0;
	// else if(v[0]==0) ans=-1;
	// else{
	// 	int j=1,step=v[0],mr=v[0];
	// 	fr(i,1,n){
	// 		if(i==n-1)
	// 			{ans=j;break;}
	// 		mr = max(mr,i+v[i]);
	// 		step--;
	// 		if(step==0){
	// 			j++;
	// 			if(i>=mr) {ans=-1;break;}
	// 			step = mr-i;
	// 		}
	// 	}
	// }
	// cout<<ans<<endl;

	// minimize the maximum difference between heights
	
	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];

	
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