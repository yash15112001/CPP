#include<bits/stdc++.h>
using namespace std;
#define fr(i,a,n) for(auto i=a;i<n;++i)
#define rf(i,n,a) for(auto i=n;i>a;--i)
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ud unordered
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
const long long M2 = 1e18 + 7;

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

ll binexpo2(int a,int b,ll m){ll ans=1;while(b){if(b&1) ans=(ans*1ll*a)%m; a=(a*1ll*a)%m; b>>=1;} return ans;}
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

// string CAS(int n){
// 	if(n==1) return "1";
// 	string os = CAS(n-1);
// 	char c = os[0];
// 	string ns;

// }

// string answer(string os){
// 	int n=os.sz();
// 	string ans;
// 	char c = os[0];
// 	int ccc=0;
// 	fr(i,0,n+1){
// 		if(i<n){
// 			if(os[i]==c) ccc++;
// 			else{
// 				ans+=to_string(ccc);
// 				ans.pb(c);
// 				c=s[i];
// 				ccc=1;
// 			}
// 		}else{
// 			ans+=to_string(ccc);
// 			ans.pb(c);
// 		}
// 	}
// 	return ans;
// }

// string CAS(int n){
// 	if(n==1) return "1";
// 	string os = CAS(n-1);
// 	int nn=os.sz();
// 	string ans;
// 	char c = os[0];
// 	int ccc=0;
// 	fr(i,0,nn+1){
// 		if(i<nn){
// 			if(os[i]==c) ccc++;
// 			else{
// 				ans+=to_string(ccc);
// 				ans.pb(c);
// 				c=os[i];
// 				ccc=1;
// 			}
// 		}else{
// 			ans+=to_string(ccc);
// 			ans.pb(c);
// 		}
// 	}
// 	return ans;
// }

// string LPS(string s){
// 	int n=s.sz();
// 	int l,r;
// 	int st=0,end=1;

// 	fr(i,0,n){
// 		l=i;
// 		r=i+1;
// 		while(l>=0&&r<n&&s[l]==s[r]){
// 			if(r-l+1>end){
// 				st=l;
// 				end=r-l+1;
// 			}l--;r++;
// 		}
// 		l=i;
// 		r=i+2;
// 		while(l>=0&&r<n&&s[l]==s[r]){
// 			if(r-l+1>end){
// 				st=l;
// 				end=r-l+1;
// 			}l--;r++;
// 		}
// 	}
// 	debug(mp(st,end))

// 	string ans;
// 	fr(i,st,end+st)
// 		ans+=s[i];

// 	return ans;
// }

// const int N = 1e3+5;
// int dp[N][N];

// void printsubsequences(string s,string ans){
// 	if(!s.sz()){
// 		cout<<ans<<endl;
// 		return ;
// 	}
// 	printsubsequences(s.substr(1),ans);
// 	printsubsequences(s.substr(1),ans+s[0]);
// }

// void permutations(set<string>&ss,string s,string ans){
// 	if(!s.sz()){
// 		ss.insert(ans);
// 		return;
// 	}
// 	fr(i,0,s.sz()){
// 		permutations(ss, s.substr(0,i) + s.substr(i+1) , ans+s[i] );
// 	} 
// }

// void reverse(vector<int>& v,int i,int j){
// 	for(int k=0;k<=(i+j)/2;k++)
// 		swap(v[i+k],v[j-k]);
// }
// vector<vector<pair<int,int>>> paths;

// vector<pair<int,int>> v;
// int finder(vector<vector<char>>& a,int n,int m,int i,int j,string s,int pos){
// 	int ans=0;
// 	if(i>=0 && i<n && j>=0 && j<m && s[pos]==a[i][j]){
// 		char c = a[i][j];
// 		a[i][j] = 0;
// 		pos++;
// 		if(pos==s.sz()){
// 			ans = 1;
// 		}else{
// 			ans+=finder(a,n,m,i+1,j,s,pos);
// 			ans+=finder(a,n,m,i,j+1,s,pos);
// 			ans+=finder(a,n,m,i-1,j,s,pos);
// 			ans+=finder(a,n,m,i,j-1,s,pos);
// 		}
// 		a[i][j]=c;
// 	}
// 	if(ans>0 && a[i][j]==s[0]){
// 		v.pb(mp(i,j));
// 	}
// 	return ans;
// }

// int find(vector<vector<char>>& a,int n,int m,string s){
// 	int ans=0;
// 	fr(i,0,n){
// 		fr(j,0,m){
// 			if(a[i][j]==s[0]){
// 				ans+=finder(a,n,m,i,j,s,0);
// 				debug(mp(i,j))
// 			}
// 		}
// 	}
// 	return ans;
// }

// string findcomm(string s1,string s2){
// 	int n=s1.sz();
// 	int m=s2.sz();
// 	string ans="";
// 	int cs = min(m,n);
// 	fr(i,0,cs){
// 		if(s1[i]==s2[i]){
// 			ans.pb(s1[i]);
// 		}else{
// 			break;
// 		}
// 	}
// 	return ans;
// }

// int minChar(string s){
//     //Write your code here
//     int n=s.sz();
//     int ans=0;
//     for(int j=n-1;j>=0;j--){
//         string st=s.substr(0,j+1);
//         string st2=st;
//         reverse(st.begin(),st.end());
//         if(st2==st){
//             ans = n-j-1;
//             break;
//         }
//     }
//     return ans;
// }

// vector<vector<string>> v;
// int n;
// string ans;

// void prints(int i,string ans){
// 	if(i==n-1){
// 		cout<<ans<<endl;
// 		return;
// 	}
// 	for(auto e:v[i+1]){
// 		prints(i+1,ans+" "+e);
// 	}
// }

// string remove(string s)
// {
// 	if(s.length()==0)
// 		return "";
// 	if(s[0]==s[1]){
// 		int i=0;
// 		while(s[0]==s[i] && i<s.sz())i++;
// 		return s[0]+remove(s.substr(i));
// 	}else
// 		return s[0]+remove(s.substr(1));
// }

// vector<vector<int>> v;
    
// int finder(vector<vector<char>>a,int n,int m,int lasti,int lastj,int i,int j,string s,int pos){
//      int ans=0;
//   	if(i>=0 && i<n && j>=0 && j<m && s[pos]==a[i][j]){
//    		char c = a[i][j];
//     	a[i][j] = 0;
//     	pos++;
//     	if(pos==s.size()){
//    			ans = 1;
//    		}else{
//    			if(i==lasti && j==lastj){
//    			    ans+=finder(a,n,m,i,j,i+1,j,s,pos);
//    			    ans+=finder(a,n,m,i,j,i,j+1,s,pos);
//    			    ans+=finder(a,n,m,i,j,i-1,j,s,pos);
//    			    ans+=finder(a,n,m,i,j,i,j-1,s,pos);
//   			    ans+=finder(a,n,m,i,j,i+1,j+1,s,pos);
//    			    ans+=finder(a,n,m,i,j,i+1,j-1,s,pos);
//    			    ans+=finder(a,n,m,i,j,i-1,j+1,s,pos);
//    			    ans+=finder(a,n,m,i,j,i-1,j-1,s,pos);
//    			}else
//    				ans+=finder(a,n,m,i,j,i+(i-lasti),j+(j-lastj),s,pos);
//    		}
//    		a[i][j]=c;
//    	}
//   	if(ans>0 && a[i][j]==s[0]){
//    		vector<int> x = {i,j};
//   		v.push_back(x);
//   	}
// 	return ans;
// }

// vector<vector<int>> searchWord(vector<vector<char>>a, string s){
//     int anss=0;
//     int n = a.size();
//     int m = a[0].size();
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(a[i][j]==s[0]){
//                 anss+=finder(a,n,m,i,j,i,j,s,0);
//             }
//         }
//     }
//     return v;
// }

// bool check(map<char,int>&a, map<char,int>&b){
// 	int n=a.sz();
// 	// for(auto it=0;it<n;it++){
// 	// 	if(a[it].second<b[it].second)return 0;
// 	// }return 1;
// 	// for(auto e:Sets.union(a.keySet(),b.keySet())){
// 	// 	auto it1 = a.get(e);
// 	// 	auto it2 = b.get(e);
// 	// 	if(it1->s<it2->s)return 0;
// 	// }return 1;

// 	for(auto e:a){
// 		char c = e.f;
// 		if(a[c]<b[c])return 0;
// 	}return 1;
// }

// string process(string& s){
// 	int n=s.sz();
// 	int j=0;
// 	fr(i,0,n){
// 		if(s[i]!='#')s[j++]=s[i];
// 		else if(s[i]=='#' && j>=0)j--;
// 		if(j<0) j=0; 
// 	}
// 	return s.substr(0,j);
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

void solve()
{	
	// string s;cin>>s;

	// int i=0;
	// while(s[i]!='\0'){
	// 	cout<<s[i];
	// 	i++;
	// }

	// int n;cin>>n;
	// string s(n,'a');
	// cout<<s<<endl;

	// erase(int(index)) (int(index),int(no of characters))
	// find(string)
	// s.clear
	// s.empty
	// sort
	// stoi(string)
	// to_string(int)
	// substr(int(index)) (int(index),int(no of characters))
	// pushback(char) , s.append(string) , concatenation(char*,char*) strcat
	// insert(int,string)

	// string s;cin>>s;
	// s.erase(5,2); s.erase(5);
	// cout<<s<<endl;

	// string s1,s2;
	// getline(cin,s1);
	// cin>>s2;
	// // // s1 = s1+s2;
	// // // s1.append(s2);
	// // strcat(s1,s2);
	// // s1.pb('d');
	// cout<<s1<<endl;

	// char a[]="sflkdsjfkl sldfjskl sf";
	// char b[]="sfks sfdiufhi iuwegh";
	// strcat(a,b);
	// cout<<a<<endl;

	// string s1,s2;cin>>s1>>s2;
	// if(s1.find(s2)<s1.sz())
	// 	cout<<s1.find(s2);
	// else
	// 	cout<<"-1"<<endl;
	// // cout<<s1.empty()<<endl;
	// // s1.clear();cout<<s1.empty()<<endl;
	// sort(all(s1));
	// cout<<s1<<endl;

	// string s;cin>>s;
	// int x = stoi(s);
	// x++;
	// s = to_string(x);
	// cout<<s<<endl;

	// string s;cin>>s;
	// cout<<s.substr(5,8);

	// string s;cin>>s;
	// s.insert(4,"mandaviya");
	// cout<<s<<endl;

	// **check is strings are rotations of each other?
	// string s1,s2;cin>>s1>>s2;
	// s1=s1.append(s1);
	// if(s1.find(s2)<s1.sz()){
	// 	cout<<1<<endl;
	// }else cout<<0<<endl; ---> O(1),O(1)

	// string s1,s2;cin>>s1>>s2;
	// int ans=0;
	// if(s1.sz()==s2.sz()){
	// 	int n=s1.sz();
	// 	fr(i,0,n){
	// 		// char c = s1[0];
	// 		// s1=s1+c;
	// 		s1=s1.substr(1)+s1[0];
	// 		if(s1==s2){
	// 			ans=1;
	// 			break;
	// 		}
	// 	}
	// }
	// cout<<ans<<endl; ---> O(n),O(1)

	// check if a string is a valid shuffle of the two distinct strings
	// string s1,s2,s3;cin>>s1>>s2>>s3;
	// int l=s1.sz(),m=s2.sz(),n=s3.sz();
	// int ans=1;
	// if(l+m==n){
	// 	int i=0,j=0,k=0;
	// 	while(k<n){
	// 		if(i<l && s1[i]==s3[k]) i++;
	// 		else if(j<m && s2[j]==s3[k]) j++;
	// 		else{
	// 			ans=0;
	// 			break;
	// 		}
	// 		k++;
	// 	}
	// }
	// if(ans) cout<<"yes"<<endl;
	// else cout<<"no"<<endl;

	// count and say
	// int n;cin>>n;
	// string ans = CAS(n);
	// cout<<ans;

	// string s;cin>>s;
	// cout<<answer(s)<<endl;

	// longest palidromic substring
	// string s;cin>>s;
	// string ans = LPS(s);
	// cout<<ans<<endl;

	// longest repeating subsequence
	// string s;cin>>s;
	// int n = s.sz();
	// memset(dp,-1,sizeof(dp));

	// fr(i,0,n+1){
	// 	fr(j,0,n+1){
	// 		if(i==0||j==0) dp[i][j]=0;
	// 	}
	// }

	// fr(i,1,n+1){
	// 	fr(j,1,n+1){
	// 		if(s[i-1]==s[j-1] && i!=j)
	// 			dp[i][j]=1+dp[i-1][j-1];
	// 		else 
	// 			dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
	// 	}
	// }
	// cout<<dp[n][n]<<endl;

	// print all subsequences of the string
	// string s;cin>>s;
	// int n = s.sz();
	// int t = (1<<n) -1;
	// debug(t)
	// rf(i,t,-1){
	// 	fr(j,0,n){
	// 		if( (i&(1<<j)) ) cout<<s[j];
	// 	}cout<<endl;
	// } ---------> O( n * 2^n )

	// string s;cin>>s;
	// printsubsequences(s,""); ---> O(2^n)

	// string s;cin>>s;
	// set<string> ans;
	// permutations(ans,s,"");
	// debug(ans)
	// for(auto e:ans)
	// 	cout<<e<<endl;

	// count no of ways to split the binary string into substrings such that no of 0 and 1 are same 
	// string s;cin>>s;
	// int n=s.sz();
	// int ans=0;
	// int flag=0;
	// for(auto c:s){
	// 	if(c=='0')flag--;
	// 	else flag++;
	// 	if(flag==0) ans++;
	// }
	// if(flag!=0) ans=-1;
	// cout<<ans<<endl;

	// next permutation
	
	// 	int n;cin>>n;
	// 	vector<int> v(n);
	// 	fr(i,0,n) cin>>v[i];
	// 	int kflag=0;
	// 	int flag=n-1;
	// 	while(v[flag]<=v[flag-1]){ 
	// 		flag--;
	// 		if(flag==0) {kflag=1; break;}
	// 	}
	// 	if(kflag==0){
	// 		int t=flag;
	// 		cout<<t<<endl;
	//         for(int p=flag;p<n;p++){
	//             if(v[p]>v[flag-1]) {
	            	
	//             	t=min(t,p);
	//             }
	//         }
	//         cout<<t<<endl;
	//    		swap(v[flag-1],v[t]);
	// // 		for(int k=0;k<=(n-1-flag)/2;k++)
	// // 			swap(v[flag+k],v[n-1-k]);
	//         sort(v.begin()+flag,v.end());
	// 	}else{
	// 		for(int k=0;k<=n/2;k++)
	// 			swap(v[k],v[n-1-k]);
	// 	}
	// 	for(auto c:v) cout<<c<<" ";

	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];

	// int flag=n-1;
	// for(int k=n-1;k>0;k--){
	// 	if(v[k]<=v[k-1]) flag--;
	// }
	// int s=flag-1;
	// if(flag==0){ //reverse 0 to n-1}
	// 	reverse(v.begin(),v.end());
	// }
	// else{
	// 	int flag2;
	// 	for(int i=flag;i<n;i++){
	// 		if(v[i]>v[s]) flag2=i;
	// 		else break; 
	// 	}
	// 	swap(v[s],v[flag2]);
	// 	reverse(v.begin()+flag,v.end());
	// }

	// for(auto c:v) cout<<c<<" ";

	// balanced parenthesis
	// map<char,int> m { {'(',-1} ,{')',1}, {'{',-2}, {'}',2}, {'[',-3}, {']',3}};
	// string s;cin>>s;
	// bool flag=0;
	// stack<int> ss;
	// for(auto c:s){
	// 	if(m[c]<0) ss.push(m[c]);
	// 	else{
	// 		if(ss.empty()){
	// 			flag=1;
	// 			break;
	// 		}else{
	// 			auto t=ss.top();
	// 			if(t+m[c]!=0){
	// 				flag=1;
	// 				break;
	// 			}else{
	// 				ss.pop();
	// 			}
	// 		}
	// 	}
	// }
	// if(flag || !ss.empty()) cout<<"no";
	// else cout<<"yes";

	// **rabin karp algo

	// string s,p;cin>>s>>p;
	// int B = 26;
	// int m = p.sz();
	// int n = s.sz();
	// map<char,int> mm;
	// // fr(i,97,97+26){
	// // 	m[char(i)]=i;
	// // }
	// // cout<<char(97)<<endl;
	// fr(i,0,26) mm[char(97+i)]=i;
	// // debug(mm)
	// // calculating the hash for the pattern
	// int hashp = 0;
	// fr(i,0,m){
	// 	debug(mp(p[i]-'a'+1,binexpo(B,m-1-i,M)))
	// 	hashp+=(mm[p[i]]*binexpo(B,m-1-i,M));
	// 	hashp%=M;
	// }
	// // cout<<hashp<<endl;

	// int hashroll = 0;

	// // fr(i,0,n){
	// // 	if(i<m){
	// // 		hashroll+=(((int)s[i])*binexpo(B,m-1-i,M));
	// // 		hashroll%=M;		
	// // 	}else{
	// // 		cout<<hashroll<<endl;
	// // 		hashroll = ((B*(hashroll-((int)s[i-m])*binexpo(B,m-1,M)))%M + (int)s[i+1]%M)%M;
	// // 		// cout<<hashroll<<endl;
	// // 	}
	// // }
	// debug(hashp)
	// fr(i,0,m){
	// 	hashroll+=(mm[s[i]]*binexpo(B,m-1-i,M));
	// 	hashroll%=M;
	// }
	// // cout<<hashroll<<endl;
	// if(hashroll==hashp) cout<<1<<endl;
	// debug(hashroll)
	// fr(j,m,n){
	// 	// debug(mm[s[j-m]]*binexpo(B,m-1,M))
	// 	hashroll = (((B* (( M+ hashroll - ((mm[s[j-m]]*binexpo(B,m-1,M))%M) )%M) )%M +M)+mm[s[j]])%M;
	// 	// hashroll = ((B*(hashroll - (mm[s[j-m]]*binexpo(B,m-1,M))%M + M) + mm[s[j]]))%M;
	// 	if(hashroll==hashp) cout<<(j-m+2)<<endl;
	// 	debug(hashroll)
	// }

	// string s,p;cin>>s>>p;
	// int n=s.sz();
	// int m=p.sz();
	// int B = 10;
	// map<char,int> mm;
	// fr(i,0,10){
	// 	mm[char(i+97)]=i+1;
	// }
	// debug(mm)

	// int hashp=0;
	// fr(i,0,m){
	// 	hashp+=(mm[p[i]])*pow(B,m-1-i);
	// }

	// debug(hashp)

	// int hashroll=0;

	// fr(i,0,m){
	// 	hashroll+=(mm[s[i]])*pow(B,m-1-i);
	// }

	// debug(hashroll)
	// if(hashroll==hashp) cout<<1<<endl;
	// fr(i,m,n){
	// 	debug(hashroll)
	// 	hashroll = B*(hashroll-(mm[s[i-m]]*pow(B,m-1))) + mm[s[i+1]];
	// 	if(hashroll==hashp) cout<<i-m+1<<endl;
	// }

	// string s;getline(cin,s);
	// unordered_map<char,int> m = {{' ',1},{'A',21},{'B',22},{'C',23},{'D',31},{'E',32},{'F',33},{'G',41},{'H',42},{'I',43},{'J',51},{'K',52},
	// {'L',53},{'M',61},{'N',62},{'O',63},{'P',71},{'Q',72},{'R',73},{'S',74},{'T',81},{'U',82},{'V',83},{'W',91},{'X',92},{'Y',93},{'Z',94}};

	// for(auto c:s){
	// 	int x=m[c];
	// 	fr(i,0,x%10) cout<<x/10;
	// }
	// int ans=0;
	// string str;cin>>str;
	// stack<char> st;
	// for(auto c:str){
	// 	// if(c=='{' || ( s.empty() && c=='}') )s.push(c);
	// 	// else{
	// 	// 	if(s.top()=='{')s.pop();
	// 	// }
	// 	if(c=='{')st.push(c);
	// 	else{
	// 		if(st.empty())st.push(c);
	// 		else{
	// 			if(st.top()=='{')st.pop();
	// 			else st.push(c);
	// 		}
	// 	}
	// }debug(st);
	// if(st.sz()%2) ans=-1;
	// else{
	// 	int l=0,r=0;
	// 	while(!st.empty()){
	// 		auto e=st.top();
	// 		st.pop();
	// 		if(e=='{')l++;
	// 		else r++;
	// 	}
	// 	ans = ceil(l/2.0)+ceil(r/2.0);
	// }cout<<ans<<endl;

	// count of number of times string appears in the 2D array of characters && starting pos is string is found
	// string s;cin>>s;
	// int n,m;cin>>n>>m;
	// vector<vector<char>> a(n,vector<char>(m));
	// fr(i,0,n){
	// 	fr(j,0,m){
	// 		cin>>a[i][j];
	// 	}
	// }
	// int ans = find(a,n,m,s);
	
	// for(auto p:v){
	// 	cout<<p.f<<" "<<p.s<<endl;
	// }cout<<endl;
	
 	// I            1
 	// IV           4
	// V            5
	// IX           9
	// X            10
	// XL           40
	// L            50
	// XC           90
	// C            100
	// CD           400
	// D            500
	// CM           900 
	// M            1000

	// unordered_map<string,int> m2 ={{"IV",4},{"IX",9},{"XL",40},{"XC",90},{"CD",400},{"CM",900}};
	// unordered_map<char,int> m1 ={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};

	// string s;cin>>s;
	// int ans=0;
	// int i=0;
	// while(i<s.sz()){
	// 	if(i<s.sz()-1 && m2[s.substr(i,2)]!=0){
	// 		// string s2;
	// 		// s2.pb(s[i]);
	// 		// s2.pb(s[i+1]);
	// 		// // debug(mp(s2,m2[s2]))
	// 		// if(m2[s2]!=0){
	// 		// 	ans+=m2[s2];
	// 		// 	i=i+2;
	// 		// }
	// 		debug(s.substr(i,2))
	// 		ans+=m2[s.substr(i,2)];
	// 		i=i+2;
	// 	}
	// 	else{
	// 		ans+=m1[s[i]];
	// 		i++;
	// 	}
	
	// }
	// cout<<ans<<endl;

	// int n;cin>>n;
	// vector<string> v(n);fr(i,0,n) cin>>v[i];
	// string scomm=v[0];
	// fr(i,0,n){
	// 	scomm=findcomm(scomm,v[i]);
	// 	if(scomm.sz()==0) break;
	// }
	// cout<<scomm;

	// string s;cin>>s;
	// int ans1=0,ans2=0;
	// fr(i,0,s.sz()){
	// 	if((s[i]-'0')!=(i%2))ans1++;
	// }
	// fr(i,0,s.sz()){
	// 	if((s[i]-'0')==(i%2))ans2++;
	// }cout<<min(ans1,ans2);

	// int n;cin>>n;
	// string ans;
	// vector<string> v(n);fr(i,0,n) cin>>v[i];
	// map<string,int> m;
	// map<int,string> m2;
	// fr(i,0,n){
	// 	m[v[i]]++;
	// }debug(m)
	// for(auto p:m)
	// 	m2[p.second]=p.first;
	// debug(m2)
	// auto it=m2.end();
	// if(m2.size()>1){
	// it--;
	// it--;
	// cout<<(it->s)<<endl;}	

	// map<int,int> m = {{4,5},{12,1}};
	// auto it = m.end();
	// if(m.size()>1){
	// 	it--;
	// 	it--;
	// 	cout<<it->s<<endl;
	// }

	// string s;cin>>s;
	// int a=0,ans=0;
	// for(auto c:s){
	// 	if(c=='[')a--;
	// 	else{
	// 		a++;
	// 		if(a>0)ans+=a;
	// 	}
	// }cout<<ans<<endl;

	// ************************************
	// amazon - IP , IPv4
	// string s;cin>>s;
	// vector<string> ans;
	// if(s.sz()>=4){
	// 	fr(i,1,5){
	// 		fr(j,1,5){
	// 			fr(k,1,5){
	// 				fr(l,1,5){
	// 					if(i+j+k+l==s.sz()){
	// 						string s1,s2,s3,s4;
	// 						s1=s.substr(0,i);
	// 						s2=s.substr(i,j);
	// 						s3=s.substr(i+j,k);
	// 						s4=s.substr(i+j+k,l);
	// 						int a=stoi(s1),b=stoi(s2),c=stoi(s3),d=stoi(s4);
	// 						if(a<256 && b<256 && c<256 && d<256){
	// 							string nip = to_string(a)+"."+to_string(b)+"."+to_string(c)+"."+to_string(d);
	// 							if(nip.sz()<=s.sz()+3)ans.pb(nip);
	// 						}
	// 					}
	// 				}
	// 			}
	// 		}
	// 	}
	// }
	// if(ans.size()==0)cout<<"-1"<<endl;
	// else{
	// 	for(auto e:ans)
	// 		cout<<e<<" "<<endl;
	// } //*********************************

	// find the smallest window which contains all the distinct charachters of the string
	
	// string s;cin>>s;
	// int ans=0;
	// unordered_map<char,int> m;
	// for(auto e:s) m[e]++;
	// int unique = m.sz();
	// debug(m)

	// bool b=false;
	// for(int ss=unique;ss<=s.sz();++ss){
	// 	for(int i=0;i<=s.sz()-ss;++i){
	// 		// substr to work on = substr(i,unique)
	// 		string temp = s.substr(i,ss);
	// 		unordered_map<char,int> tm;
	// 		for(auto c:temp){
	// 			tm[c]++;
	// 		}debug(tm)
	// 		if(tm.sz()==m.sz()){
	// 			debug(tm)
	// 			cout<<ss<<" ";
	// 			debug(i)
	// 			b=true;
	// 			break;
	// 		}
	// 	}if(b) break;
	// } // ----> O(N*N)

	// ***********************************
	// string s;cin>>s;
	// int n=s.sz();
	// map<char,int> m,tm;
	// for(auto e:s) m[e]++;
	// int d=m.sz();
	
	// debug(m)

	// int ans=int_max;
	// int i=-1,j=-1;
		
	// // while(j<n){
	// // 	if(tm.sz()!=m.sz()){
	// // 		tm[s[j]]++;
	// // 	}j++;
	// // }

	// while(i<=j && j<n){
	// 	if(tm.sz()!=m.sz()){
	// 		j++;tm[s[j]]++;
	// 	}else{
	// 		// while(tm.sz()==m.sz()){
	// 			ans=min(ans,j-i);
	// 			debug(mp(ans,mp(i,j)))
	// 			i++;tm[s[i]]--;
	// 			auto it = tm.find(s[i]);
	// 			if(it==tm.end()) tm.erase(it);
	// 	}
	// 	debug(tm)
	// }
	// // cout<<ans<<endl;
	// ***********************************

	// string s;cin>>s;
	// cout<<minChar(s); // O(N*N) ---> hard problem

	// int n;cin>>n;
	// vector<string> v(n);
	// fr(i,0,n) cin>>v[i];
	// vector<vector<string>> ans;
	// map<map<char,int>,vector<string>> m;

	// for(auto e:v){
	// 	map<char,int> t;
	// 	for(auto c:e)
	// 		t[c]++;
	// 	m[t].pb(e);
	// }

	// for(auto p:m){
	// 	ans.pb(p.s);
	// }

	// for(auto e:ans){
	// 	for(auto ee:e){
	// 		cout<<ee<<" ";
	// 	}cout<<endl;
	// }

	// string s1,s2;cin>>s1>>s2;
	// int n = s1.sz();
	// bool b=true;
	// map<char,int> m;
	// for(int i=0;i<n;i++){
	// 	if(m.find(s1[i])==m.end())
	// 		m[s1[i]]=(int)s2[i];
	// 	else{
	// 		if(m[s1[i]]==(int)s2[i]){
	// 			continue;
	// 		}else{
	// 			b=false;
	// 			break;
	// 		}
	// 	}
	// }debug(m)
	// if(b) cout<<1<<endl;
	// else cout<<0<<endl;

	// // transfiguration
	// string s1,s2;cin>>s1>>s2;
	// bool b=true;
	// int ans=0;
	// unordered_map<char,int> m;
	// for(auto e:s1)m[e]++;
	// for(auto e:s2)m[e]--;
	// for(auto e:m) if(e.s!=0) b=false;
	// if(!b) ans=-1;
	// else{
	// 	int i=s1.sz()-1,j=s2.sz()-1;
	// 	while(i>=0){
	// 		if(s1[i]==s2[j])i--,j--;
	// 		else ans++,i--;
	// 	}
	// }
	// cout<<ans<<endl;

	// cafe computer use customer prblem

	// 1**diffrent problem -> customer will wait till its departure time
	// unordered_map<char,int> occ,waiting;
	// queue<char> q;

	// for(auto c:s){
	// 	debug(occ)
	// 	int x = occ.sz();
	// 	// debug(mp(x,c))
	// 	debug(waiting)
	// 	debug(q)
	// 	if(occ.sz()<n){
	// 		if(!q.empty()){
	// 			char hc=q.front();
	// 			q.pop();
	// 			occ[hc]++;
	// 			waiting.erase(hc);
	// 		}else{
	// 			if(occ.find(c)==occ.end()){
	// 				occ[c]++;
	// 			}else{
	// 				occ.erase(c);
	// 			}

	// 		}
	// 	}else{
	// 		if(occ.find(c)!=occ.end()){
	// 			occ.erase(c);
	// 			if(!q.empty()){
	// 				char hc=q.front();
	// 				q.pop();
	// 				occ[hc]++;
	// 				waiting.erase(hc);
	// 			}
	// 		}else{
	// 			// if in queue -> remove from queue and map and ans++;
	// 			// else insert in queue and map
	// 			if(waiting.find(c)!=waiting.end()){
	// 				waiting.erase(c);
	// 				// remove from queue
	// 				queue<char> q2;
	// 				// for(auto e:q){
	// 				// 	if(e!=c)q2.push(e);
	// 				// }
	// 				while(!q.empty()){
	// 					char cc=q.front();
	// 					q.pop();
	// 					if(cc!=c)q2.push(cc);
	// 				}
	// 				q=q2;
	// 				ans++;
	// 			}else{
	// 				waiting[c]++;
	// 				q.push(c);
	// 			}
	// 		}
	// 	}
	// } // O(N*N) , O(N)
	// cout<<ans<<endl;

	// 2**customer won't wait
	// int n;cin>>n;
	// string s;cin>>s;
	
	// unordered_map<char,int> al,ondesk;
	// for(auto e:s){
	// 	if(ondesk.sz()<n){
	// 		if(al.find(e)!=al.end()) continue;
	// 		if(ondesk.find(e)==ondesk.end())
	// 			ondesk[e]++;
	// 		else
	// 			ondesk.erase(e);
	// 	}else{
	// 		if(ondesk.find(e)!=ondesk.end())
	// 			ondesk.erase(e);
	// 		else{
	// 			// al[e]++;
	// 			if(al.find(e)==al.end())
	// 				al[e]++;
	// 			else 
	// 				continue;

	// 		}
	// 	} // O(N) , O(N)
	// }cout<<al.sz()<<endl;

	// print all statements possible using the words in diven dictionary of type list(list(word))

	// naive -> iterative approach -> O(N*N*N)
	// vector<vector<string>> v;
	// int n;cin>>n;
	// fr(i,0,n){
	// 	int x;cin>>x;
	// 	vector<string> temp;
	// 	fr(j,0,x){
	// 		string s;cin>>s;
	// 		temp.pb(s);
	// 	}v.pb(temp);
	// }

	// for(int i=n-2;i>=0;--i){
	// 	vector<string> curr=v[i],next=v[i+1];
	// 	vector<string> up;
	// 	for(auto e:curr){
	// 		for(auto f:next){
	// 			string new_s = e+" "+f;
	// 			up.pb(new_s);
	// 		}
	// 	}
	// 	v[i]=up;
	// }

	// for(auto e:v[0])
	// 	cout<<e<<endl;

	// better approach -> recurssive
	// cin>>n;
	// fr(i,0,n){
	// 	int x;cin>>x;
	// 	vector<string> temp;
	// 	fr(j,0,x){
	// 		string s;cin>>s;
	// 		temp.pb(s);
	// 	}v.pb(temp);
	// }

	// for(auto e:v[0]){
	// 	ans=e;
	// 	prints(0,ans);
	// } -> time O(n*longest vector in vector<vector<>>)  space -> O(1)

	// string s;cin>>s;
	// string ans = remove(s);
	// cout<<ans<<endl;

	// shortest window to have the all the characters --- ok --- length of the window
	// string s;cin>>s;
	// map<char,int> m1;
	// for(auto e:s) m1[e]++;
	// int m = m1.sz();

	// map<char,int> m2;

	// int i=0,j=0;
	// int ans = int_max;
	// while(i<=j && j<=s.sz()){
	// 	if(m2.sz()!=m){
	// 		m2[s[j]]++;
	// 		j++;
	// 	}
	// 	if(m2.sz()==m){
	// 		ans=min(ans,j-i);
	// 		debug(mp(i,j))}
	// 	if(m2.sz()==m){
	// 		m2[s[i]]--;
	// 		if(m2[s[i]]==0) m2.erase(s[i]);
	// 		i++;
	// 	}
	// }
	// cout<<ans<<endl;

	// **shortest window to have the all the characters from another string -- print the window

	// string s1,s,p;cin>>s>>p;
	// int n=s.sz();
	// s1=s;
	// map<char,int> m1;
	// for(auto e:p) m1[e]++;
	// int m=m1.sz();
	// debug(m1)
	// fr(i,0,n){
	// 	if(m1[s[i]]==0) s[i]='.';
	// }
	// debug(s)

	// set<pair<int,int>> index;
	// // unordered_map<int,vector<pair<int,int>>> indexes;
	// int newj=-1;
	// int newi=-1;
	// int i=0,j=0;
	// map<char,int> m2;
	// int ans=int_max;
	// vector<string> ofa;
	// while(i<=j && j<=s.sz()){
	// 	debug(m2)
	// 	if(m2.sz()!=m){
	// 		if(s[j]!='#'){
	// 			m2[s[j]]++;
	// 			m2.erase('#');
	// 		}j++;
	// 	}
	// 	if(m2.sz()==m){
	// 		// ans=min(ans,j-i);
	// 		// if(j-i==ans){
	// 		// 	index.insert(mp(i,j));
	// 		// }
	// 		if(check(m1,m2)){
	// 			ans=min(ans,j-i);
	// 			if(j-i==ans){
	// 				string ans=s.substr(i,j);
	// 				ofa.pb(ans);
	// 			}
	// 		}
	// 		// indexes.pb(mp(j-i,mp(i,j)));
	// 		// indexes[j-i].pb(mp(i,j));
	// 	}
	// 	if(m2.sz()==m){
	// 		if(s[i]!='#'){
	// 			m2[s[i]]--;
	// 			if(m2[s[i]]==0) m2.erase(s[i]);
	// 		}i++;
	// 	}
	// }
	// int ml=int_max;
	// int o = ofa.sz();
	// fr(i,0,o){
	// 	string seek = ofa[i];
	// 	int seekl = seek.sz();
	// 	ml = min(ml,seekl);
	// }
	// fr(i,0,o){
	// 	string seek = ofa[i];
	// 	int seekl = seek.sz();
	// 	if(seekl==ml){
	// 		cout<<seek<<endl;
	// 		break;
	// 	}
	// }
	// for(auto)
	// debug(indexes)
	// for(auto e:indexes){
	// 	cout<<e.f<<" [";
	// 	for(auto p:e.s){
	// 		cout<<" ("<<p.f<<","<<p.s<<") ";
	// 	}cout<<endl;
	// }
	// fr(k,newi,newj){
	// 	cout<<s1[k];
	// } // O(N) , O(N)  <---- optimize the extra space to O(1) --- i wanna kill my self

	// find the all starting pos of the word present in the 2D char array - no zigzag motion

	// int n,m;cin>>n>>m;
	// vector<vector<char>> v;
	// fr(i,0,n){
	// 	vector<char> temp(m);
	// 	fr(j,0,m){
	// 		cin>>temp[j];
	// 	}v.pb(temp);
	// }string ss;cin>>ss;
	// vector<vector<int>> ans=searchWord(v,ss);

	// if(ans.sz()==0)cout<<"-1"<<endl;
	// for(auto p:ans){
	// 	for(auto e:p){
	// 		cout<<e<<" ";
	// 	}cout<<endl;
	// } // O(N*N*S) , O(N*N*S)<-system stack space 

	// **** rabin karp algorithm ,,, works for the lesser B ans comparitively smaller lengths
	// **************************************************************************************

	// string s,p;cin>>s>>p;
	// int n=s.sz(),m=p.sz();
	// ll hashcode = 0;
	// int B = 26;

	// pow(a,b) => binexpo(a,b,M)
	// a+b => (a+b)%M
	// a-b => (a-b+M)%M
	// a*b => ( (a%M)*(b%M) )%M


	// fr(i,0,m){
	// 	ll x=((int)(p[i]));
	// 	ll t=(x*binexpo2(B,m-1-i,M2))%M2;
	// 	debug(binexpo2(B,m-1-i,M2))
	// 	hashcode = (hashcode%M2 + t%M2);
	// 	// debug(hashcode)
	// }
	// cout<<hashcode<<endl;

	// ll hashroll = 0;

	// fr(i,0,m){
	// 	ll x=((int)(s[i]));
	// 	ll t=(x*binexpo2(B,m-1-i,M2))%M2;
	// 	hashroll = (hashroll%M2 + t%M2);
	// }
	// debug(hashroll)
	// if(hashroll==hashcode)cout<<0<<endl;
	// // debug(hashroll)
	// fr(i,m,n){
	// 	// remove the i-m th character and add i th character
	// 	ll x=((int)(s[i-m]));
	// 	ll y=((int)(s[i]));

	// 	ll t=(x*binexpo2(B,m-1,M2))%M2;

	// 	hashroll = (hashroll-t+M2)%M2;
	// 	// hashroll = ((hashroll%M2)*(B%M2))%M2;
	// 	// hashroll = binmul(hashroll,B);
	// 	fr(j,0,256){
	// 		hashroll = (hashroll+hashroll)%M2;
	// 	}
	// 	hashroll = (hashroll%M2 + y%M2);

	// 	// hashroll -= (x*pow(B,m-1));
	// 	// hashroll *= B;
	// 	// hashroll += y;
	// 	debug(hashroll)
	// 	if(hashroll==hashcode)cout<<i-m+1<<endl;
	// }

	// **************************************************************************************

	// KMP algorithm
	// string s,p;cin>>s>>p;
	// int n=s.sz();
	// int m=p.sz();

	// vector<int> lps(m,0);
	// int l=0,i=1;

	// while(i<m){
	// 	if(p[i]==p[l])
	// 		lps[i++]=++l;
	// 	else{
	// 		if(l)
	// 			l=lps[l-1];
	// 		else
	// 			lps[i++]=0;
	// 	}
	// }
	// i=0;
	// int j=0;
	// while(i<n){
	// 	if(s[i]==p[j])
	// 		i++,j++;
	// 	else{
	// 		if(j) j=lps[j-1];
	// 		else i++;
	// 	}
	// 	if(j==m){
	// 		cout<<i-j<<endl;j=lps[j-1];
	// 	}
	// }
	// debug(lps)

	// ** min number of characters to add in front to make the srting palindrome
	// string s;cin>>s;
	// int n=s.sz();
	// string s1=s,s2=s;
	// reverse(all(s));
	// s2+=s;
	// vector<int> lps(s2.sz(),0);
	// int l=0,i=1;
	// while(i<s2.sz()){
	// 	if(s2[i]==s2[l])lps[i++]=++l;
	// 	else{
	// 		if(l)l=lps[l-1];
	// 		else lps[i++]=0;
	// 	}
	// }
	// int ans = n-lps[s2.sz()-1];
	// if(ans<0){cout<<0<<endl;cout<<s<<endl;}
	// else{
	// 	cout<<ans<<endl;
	// 	string toa = s1.substr(n-ans);
	// 	reverse(all(toa));
	// 	s1 = toa+s1;
	// 	cout<<s1<<endl; 
	// }

	// process and compare strings with backspace character '#'
	// string s,p;cin>>s>>p;
	// string s1 = process(s),p1=process(p);
	// if(s1==p1)cout<<1<<endl;
	// else cout<<0<<endl;

	// zig zag print of k
	// string s;cin>>s;
	// int n;cin>>n;
	
	// if(s.sz()==1||n==1||n>=s.sz()) cout<<s<<endl;
	// else{
	// 	vector<int> c(2*n-2);
	// 	vector<int> level;
	// 	vector<string> levelwisec(n); 
	// 	fr(i,0,2*n-2){
	// 		if(i<=n-1)c[i]=i;
	// 		else c[i]=(n-1-(i%(n-1)));
	// 	}
	// 	fr(i,0,s.sz()){
	// 		int index = i%(c.sz());
	// 		level.pb(c[index]);
	// 	}
	// 	fr(i,0,s.sz()){
	// 		levelwisec[level[i]].pb(s[i]);
	// 	}
	
	// 	string ans="";
	// 	for(auto e:levelwisec)ans.append(e);
	// 	cout<<ans<<endl;
	// }

	// given n and k , print 0 1 2 3 .... k-1 k-2 .... 2 1 0 1 2 ... k-1 k-2 ... 2 1 0 1 2 .........
	// int n,k;cin>>n>>k;
	// bool b=true;

	// vector<int> level(n);
	// level[0]=0;
	// int c=0;
	// int p=1;
	// int i=0;
	// cout<<0<<" ";
	// while(i<n-1){
	// 	cout<<p<<" ";
	// 	if(i%(k-1)==0){
	// 		c++;
	// 		if(c%2)b=!b;
	// 	}else if(i%(2*k-2)==0){
	// 		b=!b;
	// 	}
	// 	if(b)p++;
	// 	else p--;
	// 	i++;
	// }
	// debug(level)

	// large integers given in form of strngs addition

	// string s1,s2;cin>>s1>>s2;
	// string ans = stringaddition(s1,s2);
	// cout<<ans<<endl;
	
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