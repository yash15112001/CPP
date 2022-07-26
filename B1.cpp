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
#define scanv(v,n) int n;cin>>n;vector<int> v(n);fr(i,0,n) cin>>v[i];
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

// void __print(int *a,int n,int m){
// 	fr(i,0,n){
// 		fr(j,0,m){
// 			cout<<(*(a+i*m+j))<<" ";
// 		}cout<<endl;
// 	}
// }

// void move(vector<int>& v,int i,int j){
// 	if(j==v.sz()-1 || i>j) return;
// 	if(v[j]<0){
// 		swap(v[i],v[j]);
// 		move(v,++i,++j);
// 	}else{
// 		move(v,i,++j);
// 	}
// }

// int getp(vector<int>& v,int l,int r){
// 	int pe = v[r];
// 	int pp = l;
// 	fr(i,l,r+1){
// 		if(v[i]<pe)swap(v[i],v[pp++]);
// 	}
// 	swap(v[r],v[pp]);
// 	return pp;
// }

// int kthlargest(vector<int>& v,int l,int r,int k){
// 	int p = getp(v,l,r);
// 	if(p==k-1) return v[p];
// 	else if(p<k-1) return kthlargest(v,p+1,r,k);
// 	else return kthlargest(v,l,p-1,k);
// }


    // vector<vector<int>> merge(vector<vector<int>>& intervals) {
    //     int m = INT_MIN;
    //     for(auto v:intervals){
    //         m=max(m,max(v[0],v[1]));
    //     }
    //     vector<int> a(m+2,0);
    //     for(auto v:intervals){
    //         int aa=v[0],b=v[1];
    //         a[aa]=1;a[b+1]=-1;
    //     }
    //     for(int i=1;i<a.size();i++) a[i]=a[i]+a[i-1];
    //     vector<vector<int>> ans;
    //     int l=0,r=0;
    //     while(l<=r && r<a.size()){
    //         if(a[l]==0 && a[r]==0){
    //             l++,r++;
    //         }else if(a[r]==1){
    //             r++;
    //         }else if(a[l]==1 && a[r]==1){
    //             ans.push_back({l,r-1});
    //             l=r;
    //         }
    //     }
    //     return ans;
    // }

void solve()
{	
	// vector<int> v(5000,10);
	// auto it=v.begin();
	// fr(i,0,v.sz()){
	// 	cout<<(*(it+i))<<endl;
	// }

	// array (stl+normal)
	// vector
	// pair
	// tuple
	// map
	// u_map
	// multimap
	// set
	// u_set
	// multiset
	// u_multiset
	// ordered_set : pbds

	// int n;cin>>n;
	// int a[n];
	// fr(i,0,n) cin>>a[i];
	// fr(i,0,n) cout<<a[i]+i<<" ";

	// .... -> f(int a[][x],int y)

	// if we want to send both no of cols and rows in the function then
	// int n,m;cin>>n>>m;
	// int a[n][m];

	// fr(i,0,n){
	// 	fr(j,0,m){
	// 		cin>>a[i][j];
	// 	}
	// }

	// __print((int*)a,n,m);

	// vector functions
	// begin end , size , capacity max_size , clear empty , front back .at() , push_back pop_back , .swap()

	// vector<int> v {1,2,3,4,5,6};
	// cout<<v.front()<<" "<<v.back()<<endl;
	// cout<<(*(v.begin()))<<" "<<(*(--v.end()))<<endl;
	// cout<<(*(v.cbegin()))<<" "<<(*(--v.cend()))<<endl;
	// cout<<(*(v.rbegin()))<<" "<<(*(--v.rend()))<<endl;
	// cout<<(*(v.crbegin()))<<" "<<(*(--v.crend()))<<endl;
	// v.ppb();
	// cout<<v.sz()<<" "<<v.capacity()<<endl;
	// // v.resize(3);
	// cout<<v.sz()<<" "<<v.capacity()<<endl;
	// cout<<v.max_size()<<endl;
	// // vector<ll> x;
	// // cout<<x.max_size()<<endl;

	// cout<<v.at(3)<<endl;
	// vector<int> v2 {7,8,9,4,5,6,1,2,3};
	// v.swap(v2);
	// debug(v)
	// debug(v2)
	// swap(v,v2);
	// debug(v)
	// debug(v2)

	// pair<int,int> p;
	// cin>>p.f>>p.s;
	// cout<<p.f<<" "<<p.s;

	// pair<char,string> p;
	// cin>>p.f;
	// getline(cin,p.s);
	// cout<<p.f<<" "<<p.s<<endl; 

	// pair<pair<int,int>,int> p;
	// cin>>p.f.f>>p.f.s>>p.s;
	// cout<<p.f.f<<" "<<p.f.s<<" "<<p.s<<endl;

	// pair<int,int> p;
	// p = mp(1,2);
	// cout<<p.f+p.s<<endl;

	// tuple<int,int,int> t{1,2,3};
	// // cout<<get<0>(t)<<" "<<get<1>(t)<<" "<<get<2>(t)<<endl;
	// tuple<int,int,int> t2(t);
	// // t2 = make_tuple(4,5,6);
	// cout<<get<0>(t2)<<" "<<get<1>(t2)<<" "<<get<2>(t2)<<endl;

	// map<int,int> m;
	// int n;cin>>n;
	// fr(i,0,n){
	// 	int x,y;cin>>x>>y;
	// 	m[x]=y;
	// }
	// debug(m)
	// auto it=--m.end();
	// --it;
	// m.erase(it);
	// debug(m)
	// // value from pointer : *it
	// // value from iteratior : it->x


	// for(auto &p:m)
	// 	cout<<p.f<<" "<<p.s<<endl;
	// cout<<endl;

	// auto it = m.find(7);
	// if(it!=m.end()) m.erase(it);

	// for(auto e:m) cout<<e.f<<" "<<e.s<<endl;

	// unordered_multimap<char,int> x;
	// unordered_multiset<int> s;
	// s.insert(1);
	// s.insert(45);
	// s.insert(32);
	// s.insert(987);
	// s.insert(10);
	// s.insert(186);
	// s.insert(987);
	// s.insert(654);
	// s.insert(32);
	// s.insert(-54);
	// for(auto e:s)cout<<e<<" ";

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	// int zero=0,one=0,two=0;
	// fr(i,0,n){
	// 	if(v[i]==0)zero++;
	// 	else if(v[i]==1)one++;
	// 	else two++;
	// }
	// debug(mp(zero,mp(one,two)))
	// fr(i,0,n){
	// 	if(i<=zero-1)v[i]=0;
	// 	else if(i>=zero&&i<=zero+one-1)v[i]=1;
	// 	else v[i]=2;
	// }debug(v)
	// for(auto e:v)cout<<e<<" ";

	// int two=n-1;
	// int i=0;
	// while(i<=two){
	// 	if(v[two]==2)two--;
	// 	else{
	// 		if(v[i]==2){
	// 			swap(v[i],v[two]);
	// 			i++,two--;
	// 		}else{
	// 			i++;
	// 		}
	// 	}
	// }
	// i=0;
	// int one=two;
	// while(i<=one){
	// 	if(v[one]==1)one--;
	// 	else{
	// 		if(v[i]==1){
	// 			swap(v[i],v[one]);
	// 			i++,one--;
	// 		}else{
	// 			i++;
	// 		}
	// 	}
	// }debug(v)

	// int low=0,mid=0,high=n-1;
	// while(mid<=high){
	// 	if(v[mid]==0){
	// 		swap(v[mid],v[low]);
	// 		low++,mid++;
	// 	}else if(v[mid]==2){
	// 		swap(v[mid],v[high]);
	// 		high--;
	// 	}else
	// 		mid++;
	// }debug(v)

	// move all negatives to one side
	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	// // int j=0;
	// // fr(i,0,n){
	// // 	if(v[i]<0){
	// // 		swap(v[i],v[j]);
	// // 		j++;
	// // 	}
	// // }
	// // debug(v)
	// move(v,0,0);
	// debug(v)

	// **print the union & intersection of two sorted arrays in sorted order
	// using multiset -> O((n+m)log(n+m)) -> O(n+m)

	// ***************************************************************************************
	
	// int n,m;cin>>n>>m;
	// vector<int> v1(n),v2(m);
	// fr(i,0,n) cin>>v1[i];
	// fr(i,0,m) cin>>v2[i];
	// int i=0,j=0;
	// while(i<n && j<m){
	// 	if(v1[i]<v2[j]) cout<<v1[i++]<<" ";
	// 	else if(v1[i]>v2[j]) cout<<v2[j++]<<" ";
	// 	else {cout<<v1[i++]<<" ";j++;}
	// }
	// while(i<n) cout<<v1[i++]<<" ";
	// while(j<m) cout<<v2[j++]<<" ";

	// time : O(n+m) , space : O(1)

	// ***************************************************************************************

	// maximum sum subarray -> kadane's algo

	// scanvector(v,n);
	// int ans=0;
	// int csum=0;
	// fr(i,0,n){
	// 	csum+=v[i];
	// 	if(csum>ans)ans=csum;
	// 	if(csum<0)csum=0;
	// }cout<<ans<<endl;

	// kth max and kth min
	// int n,k;cin>>n>>k;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];

	// approach 1 : sort the array : time : O(NlogN) , space : O(1);
	// approach 2 : using the max heap or min heap : time : O(NlogN) , space : O(N)
	// approach 3 : maintain the pq of size k : time : O(NlogK) , space : O(K)
	// approach 4 : hepaify : time : O(N+klogN) , space :O(1)
	// approach 5 : using the quick select : time : O(N) , space : O(1)

	// priority_queue<int,vector<int>,greater<int>> pq;
	// fr(i,0,n) pq.push(v[i]);

	// fr(i,0,k){
	// 	if(i==k-1)cout<<pq.top()<<" ";
	// 	pq.pop();
	// }

	// priority_queue<int,vector<int>,greater<int>> pq;
	// fr(i,0,n){
	// 	if(pq.sz()<n-k+1)pq.push(v[i]);
	// 	else if(v[i]>pq.top()){
	// 		pq.pop();
	// 		pq.push(v[i]);
	// 	}
	// }
	// cout<<pq.top()<<" ";

	// int ans = kthlargest(v,0,n-1,k);
	// cout<<ans<<endl;

	// find the duplicate in the array of size n containning the n-1 elements

	// *1 : O(NN) , O(1)
	
	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	// fr(i,0,n-1) fr(j,i+1,n){
	// 	if(v[i]==v[j]){
	// 		cout<<i<<" "<<j<<" "<<v[j]<<" "<<endl;
	// 	}
	// }

	// *2 : O(NlogN) , O(1)
	// sort(all(v));
	// fr(i,0,n-1){
	// 	if(v[i]==v[i+1]) cout<<v[i]<<endl;
	// }

	// *3 : O(N) , O(N)
	// unordered_map<int,int> m;
	// for(auto e:v) {m[e]++;if(m[e]==2){cout<<e<<" ";break;};}

	// *4 : O(N) , O(1)

	// int i=v[0],j=v[0];
	// while(1){
	// 	i=v[i];
	// 	j=v[v[j]];
	// 	if(i==j)break;
	// }
	// j=v[0];
	// while(i!=j){
	// 	i=v[i];
	// 	j=v[j];
	// }
	// cout<<j<<endl;

	// merge two sorted arrays in O((n+m)log(n+m))
	
	// approach 1 : create the array of n+m size then sort it : time : O((n+m)log(n+m)) , space : O(n+m)
	// approach 2 : time : O((n+m)log(n+m))
	// int n;cin>>n;
	// vector<int> v1(n);fr(i,0,n) cin>>v1[i];
	// int m;cin>>m;
	// vector<int> v2(m);fr(i,0,m) cin>>v2[i];

	// int i=n-1,j=0;
	// while(i>=0 && j<m){
	// 	if(v1[i]<v2[j]) break;
	// 	swap(v1[i--],v2[j++]);
	// }
	// sort(all(v1));
	// sort(all(v2));

	// debug(v1)
	// debug(v2)

	// merge the interval

	// approach 1 : time : O(max(in all pair)) , space : O(max(in all pair))

	// int n;cin>>n;
	// vector<vector<int>> vp(n);

	// fr(i,0,n){
	// 	int mm;cin>>mm;
	// 	vector<int> t(mm);
	// 	fr(i,0,mm) cin>>t[i];
	// 	vp.pb(t);
	// }

	// int m = INT_MIN;
	// for(auto v:vp){
 //       	for(auto e:v){
 //       		m=max(m,e);
 //       	}
 //    }

 //    vector<int> a(m+2,0);
 //    for(auto v:vp){
 //              // debug(v)
 //      	if(!v.empty()){
 //  	 		int aa=v[0],bb=v[1];
 //       			a[aa]=1,a[bb+1]=-1;
 //      	}
 //    }

	// for(int i=1;i<a.size();i++) a[i]=a[i]+a[i-1];
	// for(int i=1;i<a.size();i++) if(a[i]>1)a[i]=1;

	// vector<vector<int>> ans;
	// int l=0,r=0;
	// while(l<=r && r<a.size()){
	// 	if(a[l]==0 && a[r]==0){
	// 	l++,r++;
	// 	}else if(a[r]==1)r++;
	// 	else if(a[l]==1 && a[r]==0){
	// 		vector<int> t;
	// 		t.pb(l);
	// 		t.pb(r-1);
	// 		ans.pb(t);
	// 		l=r;
	// 	}
	// }

	// for(auto e:ans){
	// 	for(auto ee:e)cout<<ee<<" ";
	// 	cout<<endl;
	// }
        
	// approach 2 : space : O(n) , time : O(n)

	// int n;cin>>n;
	// vector<vector<int>> v(n);
	// fr(i,0,n){
	// 	vector<int> t;
	// 	fr(i,0,2){
	// 		int x;cin>>x;
	// 		t.pb(x);
	// 	}
	// 	v[i]=t;
	// }
	
	// vector<vector<int>> ans;
	// sort(v.begin(),v.end());
    // stack<vector<int>> st;
	// st.push(v[0]);
	// for(int i=1;i<n;i++){
    //     vector<int> p = st.top();
    //     if(p[1]>=v[i][0]){
    //         st.pop();
    //         st.push({p[0],max(p[1],v[i][1])});
    //     }else{
    //         st.push(v[i]);
    //     }
    // }
    // while(!st.empty()){
    //     ans.push_back(st.top());
    //     st.pop();
    // }
    // sort(ans.begin(),ans.end());
    // for(auto e:ans){
    // 	cout<<e[0]<<" "<<e[1]<<endl;
    // }

    // next permutation

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];

	// int fp = n-1;
	// while(fp>0 && v[fp-1]>=v[fp])fp--;

	// if(fp==0) reverse(all(v));
	// else{
	// 	int i = fp;
	// 	while(v[fp]>=v[i] && v[i]>v[fp-1])i++;
	// 	swap(v[fp-1],v[i-1]);
	// 	reverse(v.begin()+fp,v.end());
	// }

	// debug(v)

	// stock buy and sell
	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	// int mprice=int_max;
	// int maxp=0;
	// fr(i,0,n){
	// 	mprice = min(mprice,v[i]);
	// 	maxp = max(maxp,v[i]-mprice);
	// }
	// cout<<maxp<<endl;

	// find all pair of integers whose sum is given number

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	// int k;cin>>k;

	// appoach 1 : time : O(NN) , space : O(1)
	// approach 2 : time : O(NlogN) , space : O(1)

	// sort(all(v));
	// int i=0,j=n-1;
	// while(i<j){
	// 	if(v[i]+v[j]==k){ 
	// 		cout<<i<<" "<<j<<endl;
	// 		if(v[i]+v[j-1]==k) j--;
	// 		else i++;
	// 	}
	// 	else if(v[i]+v[j]<k) i++;
	// 	else j--;
	// 	debug(mp(i,j))
	// }

	// approach 3 : time : O(N) , space : O(N)
	// int ans=0;
	// unordered_map<int,int> m;
	// fr(i,0,n){
	// 	if(m.find(k-v[i])!=m.end())ans+=m[k-v[i]];
	// 	m[v[i]]++;
	// }
	// cout<<ans<<endl;

	// find common elemenets in the 3 sorted arrays

	// int n,m,p;cin>>n>>m>>p;
	// vector<int> a(n),b(m),c(p);
	// fr(i,0,n) cin>>a[i];
	// fr(i,0,m) cin>>b[i];
	// fr(i,0,p) cin>>c[i];

	// set<int> ans;
	// int i=0,j=0,k=0;
	// while(i<n && j<m && k<p){
	// 	int mine = min(a[i],min(b[j],c[k]));
	// 	if(a[i]==b[j] && b[j]==c[k]) ans.insert(a[i]);
	// 	if(a[i]==mine) i++;
	// 	if(b[j]==mine) j++;
	// 	if(c[k]==mine) k++;
	// 	debug(mp(i,mp(j,k)))
	// }
	// debug(ans)

	// rearrange the array such that all positive and negative elements are in alternate position
	
	// approach 1 : time O(N) , space O(N)
	
	// scanv(v,n);
	// map<int,int> m;
	// for(auto e:v) m[e]++;

	// debug(m)
	// fr(i,0,n){
	// 	if(i%2==0){
	// 		auto it=m.begin();
	// 		v[i]=it->f;
	// 		m.erase(it);
	// 		if(it->s-1!=0) m[it->f]=it->s-1;
	// 	}else{
	// 		auto it=--m.end();
	// 		v[i]=it->f;
	// 		m.erase(it);
	// 		if(it->s-1!=0) m[it->f]=it->s-1;
	// 	}
	// }

	// approach 2 : time O(N) , space O(1)
	
	// scanv(v,n);
	// *****************************************

	// find the triplet with given sum
	// approach 1 : time : O(NNN) , O(1)

	// approach 2 : time : O(NN + NlogN) , O(1)
	// scanv(v,n);
	// int key;cin>>key;
	// bool b=false;
	// sort(all(v));
	// fr(i,0,n-3){
	// 	int j=i+1,k=n-1;
	// 	while(j<k){
	// 		if(v[i]+v[j]+v[k]==key){
	// 			b=true;
	// 			break;
	// 		}
	// 		else if(v[i]+v[j]+v[k]<key)j++;
	// 		else k--;
	// 	}
	// }
	// cout<<b<<endl;

	// chocalate problem
	
	// scanv(v,n);
	// sort(all(v));
	// int k;cin>>k;
	// int ans = int_max;
	// fr(i,0,n-k+1) ans=min(ans,v[k-1+i]-v[i]);
	// cout<<ans<<endl;

	// smallest subarray with sum > k
	// approach 1 : O(NN) , O(1)
	// apprach 2 
	
	
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