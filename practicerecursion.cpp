#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,a,n) for(auto i=a;i<n;i++)
#define rf(i,n,a) for(auto i=n;i>a;i--)
#define pb push_back
#define pob pop_back
#define f first
#define s second
#define mp make_pair
#define mt make_tuple
#define int_max 1e9
#define int_min -1e9
int issorted(int a[],int n)
{
	// if(n==1)
	// 	return 1;
	// if(a[0]<=a[1]&&issorted(a+1,n-1))
	// 	return 1;
	// else
	// 	return 0;

	return ((n==1)||(a[0]<=a[1]&&issorted(a+1,n-1)));
}
void increasing(int n)
{
	if(n==1)
	{
		cout<<1<<endl;
		return;
	}
	increasing(n-1);
	cout<<n<<endl;
}
void decreasing(int n)
{
	if(n==1)
	{
		cout<<1<<endl;
		return ;
	}
	cout<<n<<endl;
	decreasing(n-1);
}
int fo(int a[],int n,int pos,int key)
{
	if(pos==n)
		return -1;
	if(a[pos]==key)
		return pos;
	else
		return fo(a,n,pos+1,key);
}
int lo(int a[],int n,int pos,int key)
{
	if(pos==-1)
		return -1;
	if(a[pos]==key)
		return pos;
	else
		return lo(a,n,pos-1,key);
}
void reverse(string s)
{
	if(s.size()==0)
		return ;
	reverse(s.substr(1));
	cout<<s[0];
}
void replacepi(string s)
{
	if(s.size()==0)
		return;
	if(s[0]=='p'&&s[1]=='i'){
		cout<<"3.14";
		replacepi(s.substr(2));
	}
	else
	{
		cout<<s[0];
		replacepi(s.substr(1));
	}
}
void towerofhonoi(int n, char source, char helper, char dest)
{	
	if(n==0)
		return;
	towerofhonoi(n-1,source,dest,helper);
	cout<<source<<" -> "<<dest<<endl;
	towerofhonoi(n-1,helper,source,dest);
}
string removeduplicates(string s)
{
	if(!s.size())
		return "";
	if(s[0]==removeduplicates(s.substr(1))[0])
		return removeduplicates(s.substr(1));
	else
		return s[0]+removeduplicates(s.substr(1));
}
string moveallc(string s)
{
	if(!s.size())
		return "";
	if(s[0]=='x')
		return moveallc(s.substr(1))+s[0];
	else
		return s[0]+moveallc(s.substr(1));
}
void printsubsequence(string s,string ans)
{
	if(!s.size()){
		cout<<ans<<endl;
		return ;
	}
	printsubsequence(s.substr(1),ans);
	printsubsequence(s.substr(1),ans+s[0]);
}
void xyz(string s,string ans)
{
	if(!s.size()){
		cout<<ans<<endl;
		return ;
	}
	xyz(s.substr(1),ans);
	xyz(s.substr(1),ans+s[0]);
	xyz(s.substr(1),ans+to_string(int(s[0])));
}
string keypadarr[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void keypad(string s,string ans)
{
	if(!s.size()){
		cout<<ans<<endl;
		return ;
	}
	char c=s[0];
	string code=keypadarr[c-'0'];
	fr(i,0,code.length())
		keypad(s.substr(1),ans+code[i]);
}
void permutations(string s,string ans)
{
	if(!s.size()){
		cout<<ans<<endl;
		return;
	}
	fr(i,0,s.size()){
		char c=s[i];
		permutations(s.substr(0,i)+s.substr(i+1),ans+c);
	}
}
int path(int s,int e)
{
	if(s==e)
		return 1;
	if(s>e)
		return 0;
	int ans=0;
	fr(i,1,7)
		ans+=path(s+i,e);
	return ans;
}
int maze(int n,int i,int j)
{
	if(i==n-1&&j==n-1) return 1;
	if(i>n || j>n) return 0;
	return maze(n,i+1,j)+maze(n,i,j+1);
}
int admaze(pair<int,int> st,pair<int,int> en,int i,int j)
{
	if( i==( en.f - st.f ) && j==( en.s - st.s ) ) return 1;
	if(i>( en.f - st.f ) || j>( en.s - st.s )) return 0;
	return admaze(st,en,i+1,j)+admaze(st,en,i,j+1);
}
int admaze1(pair<int,int> st,pair<int,int> en,int i,int j)
{
	if( i==( en.f - st.f ) && j==( st.s - en.s ) ) return 1;
	if(i>( en.f - st.f ) || j>( st.s - en.s )) return 0;
	return admaze(st,en,i+1,j)+admaze(st,en,i,j+1);
}
int tilling(int n)
{
	return (n==0||n==1||n==2)?n:tilling(n-1)+tilling(n-2);	
}
int knapsack(int val[],int wt[],int n,int W)
{
	if(!n||!W) return 0;
	if(wt[n-1]>W) knapsack(val,wt,n-1,W);
	else
		return max( val[n-1]+knapsack(val,wt,n-1,W-wt[n-1]) , knapsack(val,wt,n-1,W) );
}
void solve()
{	
	// right the recursive algo to check if an array is sorted or not
	/*int n;
	cin>>n;
	int a[n];
	fr(i,0,n) cin>>a[i];
	cout<<issorted(a,n);*/

	// given n, print 1 to n and n to 1
	/*int n;
	cin>>n;
	// increasing(n);	
	decreasing(n);*/

	//find out the first and last occurence of a certain int from
	//given array;
	/*int n;
	cin>>n;
	int a[n];
	fr(i,0,n) cin>>a[i];
	int key;
	cin>>key;
	int pos=0;
	cout<<fo(a,n,pos,key);	*/
	/*int pos=n-1;
	cout<<lo(a,n,pos,key);*/
	
	//reverse a string -> this not exactly reverse a string 
	//but it will print it in the reverse order
	/*string s;
	getline(cin,s);
	reverse(s);*/

	// replace 3.14 with pi in given string
	/*string s;
	getline(cin,s);
	replacepi(s);*/

	//tower of honoi
	/*int n;
	cin>>n;
	towerofhonoi(n,'A','B','C');*/

	//remove all duplicates from the string (sorted)
	/*string s;
	cin>>s;
	cout<<removeduplicates(s);*/

	// move all 'x' to the right side of a string
	/*string s;
	cin>>s;
	cout<<moveallc(s);*/

	//print all subsequence of a given string
	/*string s;
	cin>>s;
	printsubsequence(s,"");*/

	//print all subsequence of a string along with every character of string's ascii value
	/*string s;
	cin>>s;
	xyz(s,"");*/

	//keypad 
	// string s;cin>>s;keypad(s,"");

	//permutation of the string
	// string s;cin>>s;permutations(s,"");

	//pathproblem
	/*int start,end;
	cin>>start>>end;
	cout<<path(start,end);*/

	//maze
	/*int n;
	cin>>n;
	cout<<maze(n,0,0);*/

	//advancedmaze
	/*pair<int,int> A,B;
	cin>>A.f>>A.s>>B.f>>B.s;
	pair<int,int> st,en;
	st.f=(A.f<=B.f)?A.f:B.f;
	st.s=(st.f==A.f)?A.s:B.s;
	en.f=(st.f==A.f)?B.f:A.f;
	en.s=(en.f==A.f)?A.s:B.s;
	st=A<B?A:B;
	en=(st==A)?B:A;

	if(st.f<en.f && st.s<en.s){
		cout<<admaze(st,en,st.f,st.s);
	}
	else if(st.f<en.f && st.s>en.s){
		cout<<admaze1(st,en,st.f,st.s);
	} */  // wa -> pending

	//tilling
	/*int n;cin>>n;
	cout<<tilling(n);*/

	//knapsack
	int n;cin>>n;
	int value[n],wt[n];
	fr(i,0,n) cin>>value[i];
	fr(i,0,n) cin>>wt[i];
	int W;cin>>W;
	cout<<knapsack(value,wt,n,W);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
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
