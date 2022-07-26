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

int upper(int x,vector<int>& v){
	int l=0,h=v.sz()-1;
	while(h-l>1){
		int m = (h+l)/2;
		if(v[m]<=x) l=m+1; 
		else h=m;
	}
	if(v[l]>x) return l;
	if(v[h]>x) return h;
	else return -1;
}

int lower(int x,vector<int>& v){
	int l=0,h=v.sz()-1;
	while(h-l>1){
		int m = (h+l)/2;
		if(v[m]<x) l=m+1;
		else h=m;
	}
	if(v[l]>=x) return l;
	if(v[h]>=x) return h;
	else return -1;
}

void solve()
{	
	// binary search
	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	// int x;cin>>x;

	// int l=0,h=n-1;
	// while(h-l>1){
	// 	int m=(l+h)/2;
	// 	if(v[m]<x) l=m+1;
	// 	else h=m;
	// }
	// if(v[l]==x) cout<<l<<endl;
	// else if(v[h]==x) cout<<h<<endl;
	// else cout<<-1<<endl;

	// upper_bound , lower_bound
	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	// int x;cin>>x;
	// cout<<*upper_bound(all(v),x)<<endl;	
	// int ans = upper(x,v);
	// if(ans==-1) cout<<-1<<endl; else cout<<v[ans]<<endl;
	// cout<<*lower_bound(all(v),x)<<endl;
	// int ans2 = lower(x,v);
	// if(ans2==-1) cout<<-1<<endl; else cout<<v[ans2]<<endl; 

	// 1) find the index of element in the reverse sorted array
	
	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	// int x;cin>>x;

	// int l=0,h=n-1;
	// while(h-l>1){
	// 	int m = l+(h-l)/2;
	// 	if(v[m]<=x) h=m;
	// 	else l=m+1;
	// }

	// if(v[l]==x) cout<<l<<endl;
	// if(v[h]==x) cout<<h<<endl;
	// else cout<<-1<<endl;

	// 2) order agnostic search
	// order in which array is sorted is not given (ascending/descending) , find index of element x in array if possible

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];

	// bool b = v[0]<v[n-1]?0:1;
	// cout<<b<<endl;
	// int x;cin>>x;
	// int l=0,h=n-1;
	// while(h-l>1){
	// 	int m = l+(h-l)/2;
	// 	if(v[m]<=x){
	// 		if(b) h=m;
	// 		else l=m;
	// 	}else{
	// 		if(b) l=m+1;
	// 		else h=m-1;
	// 	}
	// }
	// if(v[l]==x) cout<<l<<endl;
	// else if(v[h]==x) cout<<h<<endl;
	// else cout<<-1<<endl;

	// 3) first and last occurence of a element in the sorted array
	
	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];

	// int x;cin>>x;
	// int l=0,h=n-1;
	// int ans=-1;
	// for first occurence
	// while(h-l>=0){
	// 	int m = l+(h-l)/2;
	// 	if(v[m]<=x){
	// 		if(v[m]==x){
	// 			cout<<m<<endl;
	// 			ans=m;
	// 			h=m-1;
	// 		}else{
	// 			l=m+1;
	// 		}
	// 	}else{
	// 		h=m-1;
	// 	}
	// }
	// cout<<ans<<endl;
	// for last occurence
	// while(h-l>=0){
	// 	int m = l+(h-l)/2;
	// 	if(v[m]<=x){
	// 		if(v[m]==x){
	// 			cout<<m<<endl;
	// 			ans=m;
	// 			l=m+1;
	// 		}else{
	// 			l=m+1;
	// 		}
	// 	}else{
	// 		h=m-1;
	// 	}
	// }
	// cout<<ans<<endl;

	// 4) count the frequency of an element in the sorted array

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];

	// int x;cin>>x;
	// int fo=-1,lo=-1;

	// int l=0,h=n-1;
	// while(h-l>=0){
	// 	int m = l+(h-l)/2;
	// 	if(v[m]<=x){
	// 		if(v[m]==x){
	// 			fo=m;
	// 			h=m-1;
	// 		}else{
	// 			l=m+1;
	// 		}
	// 	}else{
	// 		h=m-1;
	// 	}
	// }

	// l=0,h=n-1;
	// while(h-l>=0){
	// 	int m = l+(h-l)/2;
	// 	if(v[m]<=x){
	// 		if(v[m]==x){
	// 			lo=m;
	// 			l=m+1;
	// 		}else{
	// 			l=m+1;
	// 		}
	// 	}else{
	// 		h=m-1;
	// 	}
	// }

	// cout<<fo<<" "<<lo<<" "<<lo-fo+1<<endl;

	// 5) no of times a sorted array is rotated

	// find the minimum element in the array
	
	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];

	// int l=0,h=n-1;

	// while(h-l>=0){
	// 	int m = l+(h-l)/2;
	// 	if(v[(m-1+n)%n]>v[m] && v[m]<=v[(m+1)%n]){
	// 		l=m;
	// 		h=l-1;
	// 	}
	// 	if(v[0]<=v[m]){
	// 		l=m+1;
	// 	}else if(v[m]<=v[n-1]){
	// 		h=m-1;
	// 	}
	// }
	// cout<<v[l]<<" "<<n-l<<endl;

	// 6) find element in the rotated sorted array

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];

	// int x;cin>>x;
	// int l=0,h=n-1;
	// while(h-l>1){
	// 	int m = l+(h-l)/2;
	// 	if(v[0]<=v[m]){
	// 		// if v[0]<=x<=v[m] :: h=m;
	// 		// if x<v[0] or x>v[m]:: l=m+1;
	// 		if(v[0]<=x && x<=v[m]) h=m;
	// 		else if(x<v[0] || x>v[m]) l=m+1;
	// 	}else{
	// 		// if v[m]<=x<=v[n-1] :: l=m;
	// 		// if x>v[n-1] or x<v[m] :: h=m-1;
	// 		if(v[m]<=x && x<=v[n-1]) l=m;
	// 		else if(x>v[n-1] || x<v[m]) h=m-1; 
	// 	}

	// }
	// if(v[l]==x) cout<<l<<endl;
	// else if(v[h]==x) cout<<h<<endl;
	// else cout<<-1<<endl;

	// 7) find the element in the nearly sorted array

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	// int x;cin>>x;

	// int l=0,h=n-1;
	// while(h-l>1){
	// 	int m = l+(h-l)/2;
	// 	if(v[m]<=x){
	// 		if(v[m-1]==x){
	// 			l=m-1;
	// 			h=l-1;
	// 		}else{
	// 			l=m;
	// 		}
	// 	}else{
	// 		if(v[m+1]==x){
	// 			l=m+1;
	// 			h=l-1;
	// 		}else{
	// 			h=m-1;
	// 		}
	// 	}
	// }

	// if(v[l]==x) cout<<l<<endl;
	// else if(v[h]==x) cout<<h<<endl;
	// else cout<<-1<<endl;

	// 8) floor and ceil of the number in the sorted array

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];

	// int x;cin>>x;
	// floor
	// int ans = int_min;
	// int l=0,h=n-1;
	// while(h-l>1){
	// 	int m = l+(h-l)/2;
	// 	if(v[m]<=x){
	// 		ans = max(ans,v[m]);
	// 		l=m;
	// 	}else{
	// 		h=m-1;
	// 	}
	// }
	// if(v[l]<=x) ans = max(ans,v[l]);
	// if(v[h]<=x) ans = max(ans,v[h]);
	// cout<<ans<<endl;

	// ceil
	// int ans = int_max;
	// int l=0,h=n-1;
	// while(h-l>1){
	// 	int m = l+(h-l)/2;
	// 	if(v[m]>=x){
	// 		ans = min(ans,v[m]);
	// 		h=m;
	// 	}else{
	// 		l=m+1;
	// 	}
	// }
	// if(v[l]>=x) ans=max(ans,v[l]);
	// if(v[h]>=x) ans=max(ans,v[h]);
	// cout<<ans<<endl;

	// 9) next alphbetic letter

	// int n;cin>>n;
	// vector<char> v(n);
	// fr(i,0,n) cin>>v[i];

	// int t;cin>>t;fr(i,0,t){
	// 	char c;cin>>c;
	// 	char ans = char('z'+1);
	// 	int l=0,h=n-1;
	// 	while(h-l>1){
	// 		int m=l+(h-l)/2;
	// 		if(v[m]<=c) l=m+1;
	// 		else {h=m-1;ans=min(ans,v[m]);}	
	// 	}
	// 	if(v[l]>c) ans=min(ans,v[l]);
	// 	if(v[h]>c) ans=min(ans,v[h]);
	// 	cout<<ans<<endl;
	// }

	// 10) find the element in the infinte sorted array
	
	// int l=0,h=1;
	// int x;cin>>x;
	// while(v[h]<x){
	// 	l=h;
	// 	h*=2;
	// }
	// while(h-l>1){
	// 	int m=l+(h-l)/2;
	// 	if(v[m]<=x){
	// 		l=m;
	// 	}else{
	// 		h=m-1;
	// 	}
	// }
	// if(v[l]==x) cout<<l<<endl;
	// else if(v[h]==x) cout<<h<<endl;
	// else cout<<-1<<endl;

	// 11) index of first 1 in binary sorted array
	// same as above

	// **12) minimum diff element in a sorted array
	
	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	// int x;cin>>x;

	// int l=0,h=n-1;
	// while(h-l>1){
	// 	int m = l+(h-l)/2;
	// 	if(v[m]<=x){
	// 		l=m;
	// 	}else{
	// 		h=m-1;
	// 	}
	// }
	// if(abs(v[l]-x)<=abs(v[h]-x)){
	// 	cout<<l<<" "<<v[l]<<" "<<abs(v[l]-x)<<endl;
	// }else{
	// 	cout<<h<<" "<<v[h]<<" "<<abs(v[h]-x)<<endl;
	// }

	// 13) find the element in the row and coloumn wise sorted array

	// int n,m;cin>>n>>m;
	// int a[n][m];
	// fr(i,0,n) fr(j,0,m) cin>>a[i][j];

	// int x;cin>>x;
	// int i=0,j=m-1;
	// int ans = int_max;
	// while(i>=0 && i<n && j>=0 && j<m){
	// 	ans = min(ans,abs(x-a[i][j]));
	// 	if(a[i][j]==x) break;
	// 	else if(x<a[i][j]) j--;
	// 	else i++;
	// }
	// if(i>=n || j<0) cout<<-1<<" "<<ans<<endl;
	// else cout<<i<<" "<<j<<" "<<a[i][j]<<" "<<ans<<endl;

	// 14) peak element :: wrong ans :: depth of the question is missing :: not specified enough

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];

	// int l=0,h=n-1;
	// while(h-l>1){
	// 	int m = l+(h-l)/2;
	// 	if(m>0 && m<n-1){
	// 		if(v[m-1]<v[m] && v[m]>v[m+1]){
	// 			l=m;
	// 			h=m-1;
	// 		}else if(v[m]<=v[m-1]){
	// 			h=m-1;
	// 		}else if(v[m]<=v[m+1]){
	// 			l=m+1;
	// 		}
	// 	}else{
	// 		if(m==0){
	// 			if(v[m]>v[m+1]){
	// 				l=m;
	// 				h=m-1;
	// 			}else{
	// 				l=m;
	// 				h=m-1;
	// 			}
	// 		}else if(m==n-1){
	// 			if(v[m]>v[m-1]){
	// 				l=m;
	// 				h=l-1;
	// 			}else{
	// 				l=m-1;
	// 				h=l-1;
	// 			}
	// 		}
	// 	}
	// }
	// cout<<l<<" "<<v[l]<<" "<<h<<" "<<v[h]<<endl;

	// 15) bitonic array :: monotonic array :: [ + + + + + ][ - - - - ]
	// in bitonic array the elements are increasing at first place then kept increasing till some point then it will decrease

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];

	// int l=0,h=n-1;
	// while(h-l>=0){
	// 	int m = l+(h-l)/2;
	// 	debug(mp(m,mp(l,h)));
	// 	if(m>0 && m<n-1){
	// 		if(v[m-1]<v[m] && v[m]>v[m+1]){
	// 			l=m;
	// 			h=m-1;
	// 		}else if(v[m]<v[m+1]){
	// 			l=m+1;
	// 		}else if(v[m]<v[m-1]){
	// 			h=m-1;
	// 		}
	// 	}else{
	// 		// if(m==0){
	// 		// 	if(v[m]>v[m+1]){
	// 		// 		l=m;
	// 		// 		h=m-1;
	// 		// 	}
	// 		// }
	// 		// if(m==n-1){
	// 		// 	if(v[m]>v[m-1]){
	// 		// 		l=m;
	// 		// 		h=m-1;
	// 		// 	}
	// 		// }
	// 		l=m;
	// 		h=m-1;
	// 	}
	// 	debug(mp(m,mp(l,h)));
	// }
	// if(l!=-1) cout<<l<<" "<<v[l]<<endl;
	// else if(h!=-1) cout<<h<<" "<<v[h]<<endl;

	// 16) allocate page problem predicate function of type FFFFFFFFFTTTTTTT , find first true
	/*
	bool f(vector<int> v,int k,int p){
		int i=0;
		int tans = 0;
		while(1){
			if(tans+v[i]<=p) tans+=v[i];
			else{
				ans=0;
				k--;
				if(k==0) return false;
			}
			i++;
			if(i==n) break;
		}
		return k==1;
	}
	*/

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