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
const int M = 1e9 + 7;

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

int lower_bound(vector<int>& a,int x){
	int left = 0, right = a.size()-1;
	while(right-left>1){
		int mid = (left + right )/2;
		if(x>a[mid]) left = mid+1;
		else right = mid;
	}
	if(a[left]>=x) return left;
	if(a[right]>=x) return right;
	else return -1;
}

int upper_bound(vector<int>& a,int x){
	int left = 0, right = a.size()-1;
	while(right-left>1){
		int mid = (left + right )/2;
		if(x>=a[mid]) left = mid+1;
		else right = mid;
	}
	if(a[left]>x) return left;
	if(a[right]>x) return right;
	else return -1;
}

double epsilon = 1e-6;

const int N = 1e5 + 13;
int cows,n;
int pos[N];

bool placingcows(int m){
	int lastpos = -1;
	int cows_ct = cows;
	fr(i,0,n){
		if(pos[i]-lastpos >=m || lastpos == -1){
			cows_ct--;
			lastpos = pos[i];
		}
		if(!cows_ct) break;
	}
	return cows_ct==0;
}

int AAA(int a,int b){
	return b==0?a:AAA(b,a%b);
}

int binexpo(int a,int b){
	if(b==0) return 1;
	int r = binexpo(a,b/2);
	if(b&1) return (a*((r*1LL*r)%M))%M;
	else return (r*1LL*r)%M;
}

int binmul(long long a,long long b){
	int ans = 0;
	while(b){
		if(b&1){
			ans = (ans+a)%M;
		}
		a =(a+a)%M;
		b>>=1;
	}
	return ans;
}

int binexpoiter(long long a,long long b){
	a%=M;
	int ans = 1;
	while(b){
		if(b&1){
			ans = binmul(ans,a);
		}
		a =binmul(a,a);
		b>>=1;
	}
	return ans;
}

void solve()
{	
	// c++ inbuilt function
	// inbuilt sort , upper_bound , lower_bound
	// max , min , count , accumulate(sum) , find, reverse
	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	// int it = *max_element(v.begin(),v.end());
	// cout<<it<<endl;
	// int it2 = *min_element(v.begin(),v.end());
	// cout<<it2<<endl;
	// int sum = accumulate(v.begin(),v.end(),0);
	// cout<<sum<<endl;
	// int ct = count(v.begin(),v.end(),3);
	// cout<< ct<<endl;
	// auto itt = find(v.begin(),v.end(),6);
	// if(itt!=v.end()) cout<<*itt<<endl;
	// else cout<<"element not found"<<endl;
	// reverse(v.begin(),v.end());
	// for(auto e:v)
	// 	cout<<e<<" ";
	// in case of arrays , a.begin() = a , a.end() = a+n;
	// in case of sets and maps dont use max_element(s.begin(),s.end()) - > O(n) , instead use s.max_element(); -> O(log n)

	// set<int> s;
	// s.insert(5);
	// s.insert(10);
	// s.insert(1);
	// s.insert(3);
	// s.insert(12);
	// int it3 = *max_element(s.begin(),s.end());
	// cout<<it3<<endl;

	// lambda function - temporory function to save time and space
	// auto sum = [](int x,int y){return x+y;};
	// cout<<sum(1,2);
	// vector<int> v {-1,-2,-3};
	// cout<<all_of(v.begin(),v.end(),[](int x) { return x>0; });

	// // cout<<all_of(v.begin(),v.end(),is_pos);
	// cout<<any_of(v.begin(),v.end(),[](int x){return x>0;})<<endl;
	// cout<<none_of(v.begin(),v.end(),[](int x) { return x>0; });


	// ******************************************************************************************************
	// searching in data structures
	// ******************************************************************************************************

	// all types of searching works on a monotonic data structures
	// monotonic data structures -> which maintains an order
	// orders like increasing order of elements, decreasing order of the elements

	// int n;cin>>n;
	// vector<int> a(n);
	// fr(i,0,n) cin>>a[i];
	// int x;cin>>x;

	// int left = 0, right = n-1;
	// while(right - left > 1){
	// 	int mid = (left+right)/2;
	// 	if(x>a[mid]) left = mid+1;
	// 	else right = mid;
	// }
	// if(a[left]==x) cout<<left;
	// else if(a[right]==x) cout<<right;
	// else cout<<-1;
	// int i = lower_bound(a,x);
	// cout<<i<<" "<<(i==-1?-1:a[i])<<endl;
	// int i2 = upper_bound(a,x);n
	// cout<<i2<<" "<<(i2==-1?-1:a[i2])<<endl;
	// cout<<upper_bound(a,x)<<endl;

	// nth root of x using binary search for a decimal places
	// double a;cin>>a; 
	// int n,pri;cin>>n>>pri;
	// double e = 1e-6;
	// double low = 1;
	// double high = a;
	// double mid;
	// while(high - low>e){
	// 	mid = (low+high)/2;
	// 	if(pow(mid,n)<a) low = mid;
	// 	else high = mid;
	// }
	// cout<<setprecision(10)<<high<<" "<<low<<endl;

	// sufficient wood problem
	// cin>>n>>w;
	// fr(i,0,n) cin>>trees[i];
	// long long low=0,high=*max_element(trees,trees+n),mid;
	// while(high-low>1){
	// 	mid = (low+high)/2;
	// 	if(predi_suff(mid)){
	// 		low=mid;
	// 	}
	// 	else{
	// 		high = mid-1;
	// 	}
	// }
	// if(predi_suff(high)) cout<<high<<endl;
	// else cout<<low<<endl;

	// aggressive cows using predicate binary search
	// cin>>n>>c;
	// fr(i,0,n) cin>>pos[i];
	// sort(pos,pos+n);

	// int low = 0 , high = 1e9 , mid;
	// while(high-low>1){ 
	// 	mid = ( low+high )/2;
	// 	debug(mid)
	// 	if(placingcows(mid)){
	// 		low = mid;
	// 	}
	// 	else{
	// 		high = mid-1;
	// 	}
	// }
	// if(placingcows(mid)) cout<<mid<<endl;
	// else cout<<low<<endl;

	// int t;cin>>t;
	// while(t--){
	// 	cin>>n>>cows;
	// 	fr(i,0,n) cin>>pos[i];
	// 	sort(pos,pos+n);
	// 	int low = 0 , high = 1e9 , mid;
	// 	while(high-low>1){
	// 		mid = (high+low)/2;
	// 		if(placingcows(mid)){
	// 			low = mid;
	// 		}
	// 		else
	// 			high = mid-1;
	// 	}
	// 	if(placingcows(high)) cout<<high<<endl;
	// 	else cout<<low;
	// }

	// // time complexcity of the recursion
	// cout<<(12,18)<<endl;	
	// cout<<" LCM is "<<(12*18/AAA(12,18))<<endl;
	
	// binary exponentiation : recursive and iterative method
	// cout<<fixed<<setprecision(25)<<pow(10,24);
	// binary exponentiation is power function , why new one as we already have
	// pow( , ) , reason is pow(,) returns the double and problem with double is 
	// it stores the numbers till 10^24 but the accuracy is whole different story.
	// thats why we need the binary exponentiation
	// binary exponentiation is based on divide and conquer technique
	// cout<<binexpo(3213,346454)<<endl;
	// cout<<binexpoiter(1e14+47,2e6+533)<<endl;

	// what if we increase the values of A B or M exponentially ?
	// suppose that A is of range 1e18 then simply add a%=M in code of binexpo and every thing is fine
	// if M is too high then replace all multiplecation in binexpoiter with binarymultiply.
	int a = 31;
	int b = 452;
	cout<<binexpoiter(a,b);
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