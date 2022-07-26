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

// bool check1(vector<vector<char>>& v,int i,int j){
// 	char c = v[i][j];
// 	fr(ii,0,9){
// 		if(ii==i) continue;
// 		if(v[ii][j]==c)return false;	
// 	}
// 	return true;
// }

// bool check2(vector<vector<char>>& v,int i,int j){
// 	char c=v[i][j];
// 	fr(jj,0,9){
// 		if(jj==j) continue;
// 		if(v[i][jj]==c)return false;
// 	}
// 	return true;
// }

// bool check3(vector<vector<char>>& v,int i,int j){
// 	char c=v[i][j];
// 	fr(ii,i-(i%3),i-(i%3)+3){
// 		fr(jj,j-(j%3),j-(j%3)+3){
// 			if(i==ii && j==jj) continue;
// 			if(v[ii][jj]==c)return false;
// 		}
// 	}
// 	return true;
// }

bool cmp(string a,string b){
    return a.size()>b.size();
}

// bool check(string s,string b){
// 	int n=s.sz();
// 	int m=b.sz();
// 	fr(i,0,n-m+1){
// 		string news = s.substr(i,m);
// 		if(news==b && s[i+m]=='#') return true;
// 	}
// 	return false;
// }

int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        multiset<int> lmaxh;
        int n=heights.size();
        for(int i=1;i<n;i++){
            int hd = heights[i]-heights[i-1];
            if(hd>0){
                if(lmaxh.size()<ladders) lmaxh.insert(hd);
                else{
                    if(hd>*lmaxh.begin()){
                        lmaxh.erase(lmaxh.begin());
                        lmaxh.insert(hd);
                    }
                }
            }
        }
        int ans=0;
        while(ans<n-1){
            int hd1 = heights[ans+1]-heights[ans];
            if(hd1<0){
                ans++;
            }
            else{
                if(hd1>=*lmaxh.begin()){
                    // use ladder
                    if(ladders){
                        ladders--;
                        ans++;
                        lmaxh.erase(hd1);
                    }
                    else if(bricks>=hd1){
                        //use bricks
                        bricks-=hd1;
                        ans++;
                    }
                    else{
                        break;
                    }
                }else{
                    // if sufficient bricks use bricks 
                    // else use ladders
                    if(hd1<=bricks){
                        bricks-=hd1;
                        ans++;
                    }
                    else if(ladders){
                        ladders--;
                        ans++;
                    }
                    else{
                        break;
                    }
                }
            }
        }
        return ans;
    }

void solve()
{	
	// check if a sudoku is valid , not neccesarily solvable.

	// approach 1 : O(9*9*9) , space : O(1)

	// vector<vector<char>> s(9,vector<char>(9));
	// fr(i,0,9){
	// 	fr(j,0,9){
	// 		cin>>s[i][j];
	// 	}
	// }
	// bool b=true;
	// fr(i,0,9){
	// 	fr(j,0,9){
	// 		if(s[i][j]!='.'){
	// 			// check in s[][j],s[i][], and s[i-i%3][j-j%3] to s[i-i%3+2][j-j%3+2]
	// 			b = b && check1(s,i,j) && check2(s,i,j) && check3(s,i,j);
	// 			if(!b) break;
	// 		}
	// 	}
	// }
	// cout<<b<<endl;

	// approach 2 : O(9*9) , space : O(9*9)

	// vector<vector<char>> s(9,vector<char>(9));
	// fr(i,0,9){
	// 	fr(j,0,9){
	// 		cin>>s[i][j];
	// 	}
	// }

	// unordered_set<string> us;
	// bool b=true;
	// fr(i,0,9){
	// 	fr(j,0,9){
	// 		if(s[i][j]!='.'){
	// 			int x = s[i][j]-'0';
	// 			string s1=to_string(x)+"_"+to_string(i);
	// 			string s2=to_string(x)+"-"+to_string(j);
	// 			string s3=to_string(x)+"_"+to_string(i/3)+"-"+to_string(j/3);
	// 			if(us.find(s1)!=us.end() || us.find(s2)!=us.end() || us.find(s3)!=us.end()){
	// 				b=false;break;
	// 			}
	// 			us.insert(s1);
	// 			us.insert(s2);
	// 			us.insert(s3);
	// 		}
	// 	}
	// }
	// cout<<b<<endl;

	// **group anagrams
	// time : O(N*max(S)*log(max(S))) , space : O(max(S))

	// int n;cin>>n;
	// vector<string> v(n);
	// fr(i,0,n){
	// 	cin>>v[i];
	// }
	// map<map<char,int>,vector<string>> m;

	// fr(i,0,n){
	// 	map<char,int> t;
	// 	for(auto c:v[i]) t[c]++;
	// 	m[t].pb(v[i]);
	// }

	// vector<vector<string>> ans;
	// for(auto e:m)
	// 	ans.pb(e.s);

	// for(auto vv:ans){
	// 	for(auto ss:vv) cout<<ss<<" ";
	// 	cout<<endl;
	// }

	// set matrix zeros
	
	// int n,m;cin>>n>>m;
	// vector<vector<int>> v(n,vector<int>(m));

	// fr(i,0,n) fr(j,0,m) cin>>v[i][j];

	// unordered_set<string> us;
	// vector<pair<int,int>> vv;

	// fr(i,0,n){
	// 	fr(j,0,m){
	// 		if(v[i][j]==0) vv.pb(mp(i,j));
	// 	}
	// }

	// for(auto p:vv){
	// 	int ii=p.f;
	// 	int jj=p.s;
	// 	string s1 = "r_"+to_string(ii);
	// 	string s2 = "c_"+to_string(jj);
	// 	if(us.find(s1)==us.end()){
	// 		fr(j,0,m) v[ii][j]=0;
	// 		us.insert(s1);
	// 	}
	// 	if(us.find(s2)==us.end()){
	// 		fr(i,0,n) v[i][jj]=0;
	// 		us.insert(s2);
	// 	}
	// }

	// fr(i,0,n){
	// 	fr(j,0,m){
	// 		cout<<v[i][j]<<" ";
	// 	}cout<<endl;
	// }
	// time : O(N*N) , space : O(N*N)

	// ********************************************************************************************
	// 820. Short Encoding of Words
	
	// approach 1 : time : O(N*logN) , space : O(N*max(S))

	// int n;cin>>n;
	// vector<string> v(n);
	// fr(i,0,n) cin>>v[i];

	// sort(v.begin(),v.end(),cmp); 
	// string s = v[0]+"#";

	// fr(i,1,n){
	// 	string news = v[i]+"#";
	// 	int x = s.find(news);
	// 	if(x==-1){
	// 		s=s+v[i]+"#";
	// 	}
	// }

	// debug(s)

	// approach 2 : 
	// ********************************************************************************************

	int n;cin>>n;
	vector<int> v(n);
	fr(i,0,n) cin>>v[i];
	int b,l;cin>>b>>l;
	int ans = furthestBuilding(v,b,l);
	cout<<ans<<endl;
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