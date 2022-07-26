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

/*bool mcmp(pair<int,int>& p1,pair<int,int>& p2){
	return p1.f>p2.f;
}
void print(map<int,int>& m){
	for(auto i=m.begin();i!=m.end();i++){
		cout<<i->f<<" "<<i->s<<endl;
	}
}*/

void solve()
{	
	//map
	/*map<int,int> m;
	m[5]=10;
	m[10]=20;
	m.insert(mp(4,13));
	m.insert({9,10});
	m[1]=2;*/

	// if i is an iterator then and only then i->f and i->s , else i.f and i.s

/*	for(auto i:m)
		cout<<i.f<<" -> "<<i.s<<endl;*/

	/*print(m);
	cout<<endl;
	m.erase(5);
	print(m);
       
	//unordered_map

	unordered_map<int,int> um;
	um[1]=10;
	um[5]=46;
	um[6]=64;

	//multi_map

	//-> same as map but can store multiple same key unlike the map

	multimap<int,int> mm;
	mm.insert({1,10});
	mm.insert({2,16});
	mm.insert({1,102});
	mm.insert({3,654});B
	mm.insert({5,65});
	mm.insert({3,100});*/

	//set   ,  set and multiset both stored the keys in increasing order

	/*multiset<int> s;
	s.insert(1);
	s.insert(5);
	s.insert(20);
	s.insert(5);

	for(auto i=s.begin();i!=s.end();i++)
		cout<<*i<<" ";
	s.erase(s.find(5));
	for(auto i=s.begin();i!=s.end();i++)
		cout<<*i<<" ";*/

	// recursion basic + advanced
	fr(i,0,int_max)
		cout<<"hello!! ";
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
