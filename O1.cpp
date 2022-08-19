#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
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

void f(int n){
	if(n)f(n>>1);
	cout<<n%2;
}

void solve()
{	
	// jth bit of i : i&(1<<j)>0?1:0;
	// set jth bit of i : i=i|(1<<j);
	// unset jth bit of i : i=i&(~(1<<j));
	// toggle bit : 0->1->0 : i&(1<<j)>0?(i=i&(~(1<<j))):(i=i|(1<<j))
	// is power of 2 : i&&(!(i&(i-1))) , __builtin_popcount(i)==1
	// bitset<5> b(10);
	// cout<<b<<endl;

	// >> -> right shift : n=n/2;
	// << -> left shift : n=2*n;
	// x<<n -> x=x*(2^n)
	// x>>n -> x=x/(2^n)

	// 7*x/2 = (x<<3 - x)>>1
	// cout<< ((4*(1<<3)-4)>>1) <<endl;
	// int x;cin>>x;
	// cout<<(((x<<6)+(x<<5)+x)>>1)<<" "<<x+(x>>1)+(x<<1)<<endl;
	// f(10);

	// right most set bit : n&(~(n-1))

	// n-1 without -,+,/,*

	// int n;cin>>n;
	// int t=0,m=1;
	// while(!(n&m)){
	// 	t|=m;
	// 	m=m<<1;
	// }
	// n = (n&(~m))|t;
	// cout<<n<<endl;

	// n+1 without -,+,*,/

	// int n;cin>>n;
	// int m=1;
	// int x=((1<<30)-1);
	// while(n&m){
	// 	m=m<<1;
	// 	x=x&(~(m-1));
	// }
	// n=(n&x)|m;
	// cout<<n;

	// x*y without *
	// int n,m;cin>>n>>m;
	// int ans=0;
	// while(m){
	// 	if(m&1) ans+=n;
	// 	n=n<<1;
	// 	m=m>>1;
	// }
	// cout<<ans<<endl;

	// x/y without /
	// int n,m;cin>>n>>m;
	// int ans = pow(-1,(n<0)+(m<0))*exp(log(n)-log(m));
	// cout<<ans<<endl;

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	// int x=0;
	// for(auto e:v) x=x^e;

	// int j=x&(~(x-1));
	// int a,b;a=b=0;
	// for(auto e:v){
	// 	if(e&j)
	// 		a=a^e;
	// }
	// cout<<(x^a)<<" "<<endl;
	// cout<<a<<" "<<endl;

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	// vector<int> d(32,0);
	// for(auto e:v){
	// 	for(int i=0;i<=31;i++){
	// 		if(e&(1<<i))d[i]=(d[i]+1)%3;
	// 	}
	// }
	// int ans=0;
	// fr(i,0,32){
	// 	if(d[i]==1)
	// 		ans+=(1<<i);
	// }
	// cout<<ans<<endl;

	// int n;cin>>n;
	// int m=n;
	// int ans=0;
	// while(m){
	// 	if(m&1)
	// 		ans+=n;
	// 	n=n<<1;
	// 	m=m>>1;
	// }
	// cout<<ans<<endl;

	int x,y,l,r;cin>>x>>y>>l>>r;
	for(int i=0;i<32;i++){
		if(i+1>=l && i+1<=r && y&(1<<i))
			x=x|(1<<i);
	}
	cout<<x<<endl;

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