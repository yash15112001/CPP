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

// basic + advanced recursion and some of the best problems on recursion.

/*int sum(int n)
	return n==0?0:n+sum(n-1);*/

/*int power(int n,int p)
{
	if(p==0)
		return 1;
	return n*power(n,p-1);
}*/
/*int power(int n,int p){
	return p!=0?n*power(n,p-1):1;
}*/
/*int fact(int n){
	return n==1?1:n*fact(n-1);}*/
/*int fib(int n)
{
	return n<2?n:fib(n-1)+fib(n-2);
}*/
int issorted(int a[],int n)
{
	return n==1?1:( (a[0]<a[1]) && (issorted(a+1,n-1)) );
}
/*void dec(int n)
{
	if(!n)
		return;
	// to use break like property in recursive function use simply return; at the point of breaking recursive calls
	else
	{
		cout<<n<<endl;
		dec(n-1);
	}
}
void inc(int n)
{	
	if(!n)
		return;
	else
	{
		inc(n-1);
		cout<<n<<endl;
	}
}
int firtsoccurence(int a[],int n,int pos,int x)
{
	if(pos==n)
		return -1;
	if(a[pos]==x)
		return pos;
	return firtsoccurence(a,n,pos+1,x);
}
int lastoccurence(int a[],int n,int pos1,int x)
{
	if(pos1==-1)
		return -1;
	if(a[pos1]==x)
		return pos1;
	return lastoccurence(a,n,pos1-1,x);
}*/
/*void reverse(string s)
{	
	if(!s.length()) return;
	reverse(s.substr(1));
	cout<<s[0];
	// in this code we are not reversing the string, not to mention it just prints the string in the reverse order
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
/*void honoi(int n, char source , char helper ,char destination)
{	
	if(!n)
		return;
	honoi(n-1,source,destination,helper);
	cout<<source<<" -> "<<destination<<endl;
	honoi(n-1,helper,source,destination);

}*/
string remove(string s)
{
	if(s.length()==0)
		return "";
	if(s[0]==(remove(s.substr(1)))[0])
		return remove(s.substr(1));
	else
		return s[0]+(remove(s.substr(1)));
}
/*string move(string s)
{
	if(!s.length())
		return "";
	if(s[0]=='x')
		return move(s.substr(1))+s[0];
	if(s[0]!='x')
		return s[0]+move(s.substr(1));
}*/
/*string advanceremove(string s)
{
	// advanceremove is combination of the remove and move
	// pending
}*/
/*void printsubstrings(string s,string ans)
{
	if(!s.length()){
		cout<<ans<<endl;
		return ;
	}
	char c=s[0];
	printsubstrings(s.substr(1),ans);
	printsubstrings(s.substr(1),ans+c);		
}*/
/*void printsubstringswithascii(string s,string ans)
{
	if(!s.size()){
		cout<<ans<<endl;
		return ;
	}
	printsubstringswithascii(s.substr(1),ans);
	printsubstringswithascii(s.substr(1),ans+s[0]);	
	printsubstringswithascii(s.substr(1),ans+to_string(int(s[0])));
}*/


/*string keypadval[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void keypad(string s, string ans)
{ 
	if(!s.size()){
		cout<<ans<<endl;
		return;
	}
	string code=keypadval[s[0]-'0'];
	fr(i,0,code.length())
		keypad(s.substr(1),ans+code[i]);
}*/
/*void permutation(string s,string ans)
{
	if(!s.size()){
		cout<<ans<<endl;
		return;	// int n;
	// cin>>n;
	// int a[n];
	// fr(i,0,n) cin>>a[i];
	// int xorsum=0;
	// fr(i,0,n) xorsum=xorsum^a[i];

	// int rmsx = xorsum & (~(xorsum-1));
	// int u1=0,u2=0;
	// fr(i,0,n){
	// 	if(a[i]&rmsx) u1=u1^a[i];
	// 	else u2 = u2^a[i];
	// }

	// cout<<u1<<" "<<u2;
	}
	fr(i,0,s.size()){
		char c=s[i];
		// string ros= ( (s.substr(0,i)) + s.substr(i+1) );
		// string ros = s - s.substr(i) + s.substr(i+1) ;
		permutation(s.substr(0,i)+s.substr(i+1),ans+c);
	}
}*/
/*int allpossiblepath(int start,int end)
{
	if(start==end)
		return 1;     // -> ?
	if(start>end)
		return 0;
	int ans=0;
	fr(i,1,7)
		ans+=allpossiblepath(start+i,end);
	return ans;
}*/
/*int maze(int n,int i,int j)
{
	if(i==n-1 && j==n-1)
		return 1;
	if(i>n-1 || j>n-1)
		return 0;
	return maze(n,i+1,j)+maze(n,i,j+1);
}
int advancedmaze(pair<int,int> p1,pair<int,int> p2,int i,int j)
{
	if(i==(p2.f)-(p1.f)-1 && j==(p2.s)-(p1.s)-1)
		return 1;
	if(i>(p2.f)-(p1.f)-1 || j>(p2.s)-(p1.s)-1)
		return 0;
	return advancedmaze(p1,p2,i+1,j)+advancedmaze(p1,p2,i,j+1);
}
int tilling(int n)
{
	if(n==2||n==1||n==0) return n;
	return tilling(n-1)+tilling(n-2);
}
int waystopair(int n)
{
	if(n==0) return 0;
	if(n==1) return 1;
	if(n==2) return 2;
	return (n-1)*waystopair(n-2)+waystopair(n-1);
}*/
/*int max(int a,int b) {return a>b?a:b;}
int knapsack(int val[],int wt[],int n,int W)
{
	if(n==0||W==0) return 0;
	if(wt[n-1]>W) knapsack(val,wt,n-1,W);
	else
		return max( ( val[n-1] + knapsack(val,wt,n-1,W-wt[n-1]) ) , knapsack(val,wt,n-1,W));
}*/
void solve()
{	
	// 1 -> check if a given array is sorted or not
	
	// int n;
	// cin>>n;
	// int a[n];
	// fr(i,0,n) cin>>a[i];
	// cout<<issorted(a,n);

	// 2 -> given n , print no from n to 1 and 1 to n using recursion
	
	/*int n;
	cin>>n;
	dec(n);
	inc(n);*/

	// 3-> find the first and last occurence of a certain no, in array
	
	/*int n;
	cin>>n;
	int a[n];
	fr(i,0,n) cin>>a[i];
	int m;
	cin>>m;
	int i=0;
	cout<<firtsoccurence(a,n,i,m);*/

	/*int j=n-1;
	cout<<lastoccurence(a,n,j,m);*/

	// 4 -> reverse a string using recursion
	
	// answer without using recursion
	/*string s;
	getline(cin,s);
	string rev="";
	fr(i,0,s.size()){
		rev+=s[s.size()-1-i];
	}
	cout<<rev<<endl;*/
	/*string s;
	getline(cin,s);
	reverse(s);*/

	// 5 -> replace 3.14 with every substr pi in the given string

	/*string s;
	cin>>s;
	replacepi(s);*/

	// 6 -> tower of honoi

	/*int n;
	cin>>n;
	char a='A',b='B',c='C';
	honoi(n,a,b,c);*/
	// space complexcity -> O(1) , time complexcity -> O(2^n)

	// 7 -> remove all duplicate character from the given strind

	string s;
	cin>>s;
	cout<<remove(s);

	// imp note -> remove algo we have now used only work if the same characters are happend to be in a neighbourhood of each other
	// but what if we have string like "acbdabcadcdabcabdcbadc" in which , there are many duplicates but , they are not in each others'
	// neighbourhood, then obviously this algo wont work so we have to right some other also ,say advanceremove(s);
	/*string s;
	cin>>s;
	cout<<advanceremove(s);*/


	// 8 -> move all x to the right of the string

	/*string s;
	cin>>s;
	cout<<move(s);*/

	// 9 -> generate all substrings of a string

	/*string s;
	cin>>s;
	printsubstrings(s,"");	*/

	// 10 -> generate all substrinf of a string including the ascii value of all characters string has

	/*string s;
	cin>>s;
	printsubstringswithascii(s,"");*/

	// 11 -> print all possible words from the phone digits

	/*string s;
	cin>>s;
	keypad(s,"");*/

	//   <------ ADVANCED RECURSION PROBLEMS ------>

	// 12 -> print all permutation of the given string

	/*string s; getline(cin,s);
	permutation(s,"");*/

	// 13 -> count the possible no of paths from the beginning to end on the gameboard
	/*int st,en;cin>>st>>en;
	cout<<allpossiblepath(st,en);*/

	// 14 -> count the possible no of paths from the beginning to end in a maze ( a square )
	/*int n;
	cin>>n;
	cout<<maze(n,0,0);*/  // -> in this program strictly assume that start point is (0,0) and end point is (n-1,n-1)

	// follow up question on maze -> count the no. of paths to go from (a,b) to (c,d)
	/*pair<int,int> start,end;
	cin>>start.f>>start.s>>end.f>>end.s;
	cout<<advancedmaze(start,end,0,0);*/  // wa -> pending

	// 15 -> tilling problem -> given grid of 2 x n , and the n tiles of size 2 x 1 , find the no. of ways to arrange these tiles on grid 
	/*int n; cin>>n;
	cout<<tilling(n);*/

	// 16 -> friends pairing
	/*int n;cin>>n;
	cout<<waystopair(n);*/

	// 17 -> (0-1) knapsack // 0-1 means , we are not allowed to put the partial item with partial value and weight in the knapsack
	/*int n;cin>>n;
	int val[n],wt[n];
	fr(i,0,n) cin>>val[i];
	fr(i,0,n) cin>>wt[i];
	int W;cin>>W;
	cout<<knapsack(val,wt,n,W)<<endl;
	cout<<W;*/
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