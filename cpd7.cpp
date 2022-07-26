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

template<class T>void _print(vector<T> v1){ cerr<<"[ "; for(T i:v1) { _print(i); cerr<<" "; } cerr<<"]"; }
template<class T>void _print(set<T> s){ cerr<<"[ "; for(T i:s){ _print(i); cerr<<" "; } cerr<<"]"; }
template<class T>void _print(unordered_set<T> s){ cerr<<"[ "; for(T i:s){ _print(i); cerr<<" "; } cerr<<"]"; }
template<class T>void _print(multiset<T> s){ cerr<<"[ "; for(T i:s){ _print(i); cerr<<" "; } cerr<<"]"; }
template<class T,class V>void _print(pair<T,V> p){ cerr<<"{";_print(p.f);cerr<<",";_print(p.s);cerr<<"}"; }
template<class T,class V>void _print(map<T,V> s){ cerr<<"[ "; for(auto i:s){ cerr<<"{";_print(i.f); cerr<<","; _print(i.s); cerr<<"} "; } cerr<<"]"; }
template<class T,class V>void _print(unordered_map<T,V> s){ cerr<<"[ "; for(auto i:s){ cerr<<"{";_print(i.f); cerr<<","; _print(i.s); cerr<<"} "; } cerr<<"]"; }
template<class T,class V>void _print(multimap<T,V> s){ cerr<<"[ "; for(auto i:s){ cerr<<"{";_print(i.f); cerr<<","; _print(i.s); cerr<<"} "; } cerr<<"]"; }

/*bool issorted(int a[],int n){
	return n==1?1:(a[0]>a[1] && issorted(a+1,n-1));
}*/

/*void inc(int n){
	if(n==1){
		cout<<1<<endl;
		return;
	}
	inc(n-1);
	cout<<n<<endl;
}

void dec(int n){
	if(n==1){
		cout<<1<<endl;
		return;
	}
	
	cout<<n<<endl;
	dec(n-1);
}*/

/*int firstoccurence(int a[],int n,int i,int m){
	if(a[i]==m)
		return i;
	if(i==n)
		return -1;
	return firstoccurence(a,n,i+1,m);
}*/

/*void reverse(string s){
	if(!s.size()) return;
	reverse(s.substr(1));
	cout<<s[0];
}*/

/*void replacepi(string s)
{
	if(s.length()==0)
		return;
	if(s[0]=='p'&&s[1]=='i'){
			cout<<"3.14";
			replacepi(s.substr(2));
		}
	else{
			cout<<s[0];
			replacepi(s.substr(1));
	}
}*/

/*void honoi(int n,char source,char helper,char destination)
{
	if(!n) return;
	honoi(n-1,source,destination,helper);
	cout<<source<<" -> "<<destination<<endl;
	honoi(n-1,helper,source,destination);
}*/

/*string remove(string s){
	if(!s.size())
		return "";
	if(s[0]==remove(s.substr(1))[0])
		return remove(s.substr(1));
	else
		return s[0]+remove(s.substr(1));
}*/

/*string move(string s){
	if(!s.size()) return "";
	if(s[0]=='x') return move(s.substr(1))+s[0];
	else return s[0]+move(s.substr(1));
}*/

/*void substringswithascii(string s,string ans){
	if(!s.size()){
		cout<<ans<<endl;
		return;
	}
	char c=s[0];
	substringswithascii(s.substr(1),ans);
	substringswithascii(s.substr(1),ans+c);
	substringswithascii(s.substr(1),ans+to_string(int(c)));
}*/

/*void permutations(string s,string ans){
	if(!s.size()){
		cout<<ans<<endl;
		return;
	}
	fr(i,0,s.size()){
		char c=s[i];
		permutations(s.substr(0,i)+s.substr(i+1),ans+c);
	}
}*/

/*string kk[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void keypad(string s,string ans){
	if(!s.size()){
		cout<<ans<<endl;
		return;
	}
	string x=kk[s[0]-'0'];
	fr(i,0,x.size()){
		keypad(s.substr(1),ans+x[i]);
	}
}*/

/*int maze(int n,int i,int j)
{
	if(i==n-1 && j==n-1)
		return 1;
	if(i>n-1 || j>n-1)
		return 0;
	return maze(n,i+1,j)+maze(n,i,j+1);
}*/

/*int allpaths(int s,int e){
	if(s==e) return 1;
	if(s>e) return 0;
	int ans=0;
	fr(i,1,7)
		ans+=allpaths(s+i,e);
	return ans;
}*/

/*int tilling(int n){
	if(n==0||n==1||n==2) return n;
	return tilling(n-1)+tilling(n-2);
}*/

/*int pairing(int n){
	if(n==0) return 0;
	if(n==1) return 1;
	if(n==2) return 2;
	return pairing(n-1)+(n-1)*pairing(n-2);
}*/
void solve()
{	
	/*int n;cin>>n;
	int a[n];
	fr(i,0,n) cin>>a[i];
	cout<<issorted(a,n);*/
	// int n;cin>>n;dec(n);

	/*int n;cin>>n;
	int a[n];
	fr(i,0,n) cin>>a[i];
	int m;cin>>m;
	int i=0;
	cout<<firstoccurence(a,n,i,m);*/

	/*string s;cin>>s;
	reverse(s);*/

	/*string s;cin>>s;
	replacepi(s);*/

	/*int n;cin>>n;
	honoi(n,'A','B','C');*/

	/*string s;cin>>s;
	cout<<remove(s);*/

	/*string s;cin>>s;
	cout<<move(s);*/

	/*string s;cin>>s;
	substringswithascii(s,"");*/

	/*string s;cin>>s;
	permutations(s,"");*/

	/*string s;cin>>s;
	keypad(s,"");*/

	/*int n;cin>>n;
	cout<<maze(n,0,0);*/

	/*int s,e;cin>>s>>e;
	cout<<allpaths(s,e);*/

	/*int n;cin>>n;
	cout<<tilling(n);*/

	/*int n;cin>>n;
	cout<<pairing(n);*/

	
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