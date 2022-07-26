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
const int M = 10^9 + 7;

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

template<class T>void _print(stack<T> st){ cerr<<"[ "; while(!st.empty()) { _print(st.top()); cerr<<" "; st.pop();} cerr<<"]"; }
template<class T>void _print(vector<T> v1){ cerr<<"[ "; for(T i:v1) { _print(i); cerr<<" "; } cerr<<"]"; }
template<class T>void _print(set<T> s){ cerr<<"[ "; for(T i:s){ _print(i); cerr<<" "; } cerr<<"]"; }
template<class T>void _print(unordered_set<T> s){ cerr<<"[ "; for(T i:s){ _print(i); cerr<<" "; } cerr<<"]"; }
template<class T>void _print(multiset<T> s){ cerr<<"[ "; for(T i:s){ _print(i); cerr<<" "; } cerr<<"]"; }
template<class T,class V>void _print(pair<T,V> p){ cerr<<"{";_print(p.f);cerr<<",";_print(p.s);cerr<<"}"; }
template<class T,class V>void _print(map<T,V> s){ cerr<<"[ "; for(auto i:s){ cerr<<"{";_print(i.f); cerr<<","; _print(i.s); cerr<<"} "; } cerr<<"]"; }
template<class T,class V>void _print(unordered_map<T,V> s){ cerr<<"[ "; for(auto i:s){ cerr<<"{";_print(i.f); cerr<<","; _print(i.s); cerr<<"} "; } cerr<<"]"; }
template<class T,class V>void _print(multimap<T,V> s){ cerr<<"[ "; for(auto i:s){ cerr<<"{";_print(i.f); cerr<<","; _print(i.s); cerr<<"} "; } cerr<<"]"; }

/*int getbit(int n,int x){
	return (n&(1<<x))!=0;
}

int setbit(int n,int x){
	return (n | (1<<x));
}

int unsetbit(int n,int x){
	return (n & (~(1<<x)));
}

int updatebit(int n,int x,int b){
	if(b==1) return setbit(n,x);
	else return unsetbit(n,x);
}

int ispowerof2(int n){
	return n && !(n&(n-1));
}

int countones(int n){
	int ans=0;
	while(n!=0){
		// n = n & ( ~(n&(~(n-1))));
		n = n&(n-1);
		ans++;
	}
	return ans;
}

void subsets(char a[],int n){
	fr(i,0,1<<n){
		fr(j,0,n){
			if(i&(1<<j))
				cout<<a[j]<<" ";
		}
		cout<<endl; 
	}
}

int unique(int a[], int n){
	int ans=0;
	fr(i,0,n) ans=ans^a[i];
	return ans;
}

void twounique(int a[],int n){
	int x=0;
	fr(i,0,n) x=x^a[i];
	int y=x;
	int rms = x&(~(x-1));
	fr(i,0,n){
		if(a[i]&rms)
			y=y^a[i];
	}
	int first=y;
	int second=x^y;
	cout<<second<<" "<<first;
}

void oneinthree(int a[],int n){

}*/

/*int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}

int lcm(int a,int b){
	return a*b/gcd(a,b);
}

const int N = 1e5+10;
int a[26][N];

vector<int> nextgreater(vector<int> v){
	vector<int> ans(v.size());
	stack<int> st;
	for(int i=0;i<v.size();i++){
		while(!st.empty() && v[i]>v[st.top()]){
			ans[st.top()]=i;
			st.pop();
		}
		st.push(i);
	}
	while(!st.empty()){
		ans[st.top()]=-1;
		st.pop();
	}
	return ans;
}
*/



void solve()
{	
	//bit manipulation.
	// int n;cin>>n;
	// int x;cin>>x;
	// int b;cin>>b;
	// cout<<getbit(n,x);
	// cout<<setbit(n,x);
	// cout<<unsetbit(n,x);
	// cout<<updatebit(n,x,b);  
	// cout<<ispowerof2(n);
	// cout<<countones(n);
	// char a[n]; fr(i,0,n) cin>>a[i];
	// subsets(a,n);
	// int a[n]; fr(i,0,n) cin>>a[i];
	// cout<<unique(a,n);
	// twounique(a,n);
	// oneinthree(a,n);
	/*string s;
	int n;cin>>n;
	fr(i,0,n){	
		// s=s+'a';
		s.pb('a');
	}
	cout<<s;*/
	// cout<<char('c'+1);

	// time complexcity

	// -> in online contests 1 sec = 10^7 iterations

	/*int n;cin>>n;
	long long int ans=0;
	fr(i,0,n) fr(j,0,n) ans++;
	cout<<ans;*/

	// ---------------------------------------------------------------------------------------------------------------------- //

	// number theory
	/*cout<<gcd(10,5)<<endl;
	cout<<lcm(10,5)<<endl;
	cout<<__gcd(10,5)<<endl;*/
	// minimum fraction of a/b = (a/gcd(a,b)) / (b/gcd(a,b))

	// pre computation -> not even worth to code

	// prefix sum in 1D and 2D arrays
	
	// int n;cin>>n;
	// int a[n+1],prefix[n+1];
	// a[0]=0;
	// prefix[0]=0;
	// fr(i,1,n+1) cin>>a[i];
	// fr(i,1,n+1) prefix[i]=a[i]+prefix[i-1];
	// int l,r;cin>>l>>r;
	// cout<<prefix[r]-prefix[l-1];

	// int n,m;cin>>n>>m;
	// int a[n+1][m+1];
	// fr(i,0,n+1){
	// 	fr(j,0,m+1){
	// 		if(i==0 || j==0)
	// 			a[i][j]=0;
	// 		else
	// 			cin>>a[i][j];
	// 	}
	// }

	// int prefix[n+1][m+1];
	// fr(i,0,n+1){
	// 	fr(j,0,m+1){
	// 		if(i==0||j==0)
	// 			prefix[i][j]=0;
	// 		else
	// 			prefix[i][j]=a[i][j]+prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
	// 	}
	// }
	// int q;cin>>q;
	// while(q--){
	// 	int x,y,z,w;cin>>x>>y>>z>>w;
	// 	int ans=prefix[z][w]+prefix[x-1][y-1]-prefix[z][y-1]-prefix[x-1][w];
	// 	cout<<ans<<endl;
	// }


	// prefix gcd problem

	/*int n;cin>>n;
	int a[n+1];
	a[0]=0;
	fr(i,1,n+1) cin>>a[i];
	int f_p[n+10],b_p[n+10];

	// f_p[i] = gcd of all elements from i to n
	f_p[n+1]=0;
	// b_p[i] = gcd of all elements from 1 to i
	b_p[0]=0;

	for(int i=n;i>0;i--){
		f_p[i]=gcd(a[i],f_p[i+1]);
	}

	for(int i=1;i<=n;i++){
		b_p[i]=gcd(a[i],b_p[i-1]);
	}

	int q;cin>>q;
	while(q--){
		int l,r;cin>>l>>r;
		int ans=__gcd(b_p[l-1],f_p[r+1]);
		cout<<ans<<endl;
	}*/

	//array manipulation
	// int n;cin>>n;
	// int q;cin>>q;
	// while(q--){
	// 	int l,r,v;cin>>l>>r>>v;
	// 	/*fr(i,l,r+1){
	// 		a[i]+=v;
	// 	}*/
	// 	a[l]+=v;
	// 	a[r+1]-=v;
	// }
	// fr(i,1,n+1)
	// 	a[i]+=a[i-1];
	// long long int mx=int_min;
	// fr(i,0,n+1)
	// 	mx=max(mx,a[i]);
	// cout<<mx<<endl;

	/*int n;cin>>n;
	string s;cin>>s;

	fr(i,0,n){
		a[s[i]-'a'][i+1]++;
	}

	fr(i,0,26){
		fr(j,1,N){
			a[i][j]+=a[i][j-1];
		}
	}

	int q;cin>>q;
	while(q--){
		int l,r;cin>>l>>r;
		int ones = 0;
		fr(i,0,26){
			int cnt = 0;
			cnt = a[i][r]-a[i][l-1];
			if(cnt%2==1) ones++;
		}
		if(ones>1) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}*/

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	// vector<int> ne = nextgreater(v);
	// fr(i,0,n){
	// 	cout<<v[i]<<" -> "<< (ne[i]==-1?-1:v[ne[i]]) << endl;
	// }
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