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

int getbit(int n,int p)
{	
	bool x=	(n & (1<<p))>0?1:0;
	return x;
	/*if((n&(1<<p))>0)
		return 1;
	else
		return 0;*/
}
int setbit(int n,int p)
{
	return ( n | (1<<p) );	
}
int unsetbit(int n,int p)
{
	return ( n & (~(1<<p)) );
}
int updatebit(int n,int p,int v)
{
	// return setbit(unsetbit(n,p),p);
	/*n = n & (~(1<<p));
	n = n | (v<<p);
	return n;*/
	return ( (n & (~(1<<p))) | (v<<p) );
}
int ispowerof2(int n)
{
	return (n && (!(n&(n-1))));
}
void printsubset(char a[],int n)
{
	fr(i,0,1<<n){
		fr(j,0,n){
			if((1<<j)&i)
				cout<<a[j];
		}
		cout<<endl;
	}
}
int isxor(int a,int b)
{
	return a^b;
}
void solve()
{		
// 1 ->	// to get a bit   -- > to get desired bit from the binary representation of the number
	// suppose that we want to get the from 0101 ,which is at index 2 then;
	// int n=512;
	// int p=3;
	// // cout<<((n&(1<<p))!=0?1:0);
	// cout<<getbit(n,p);


// 2 -> to set or unset(clear) a bit
	// set means  -  if there is a bit 0 in no, then set it 1
	// unset means  - if there is a bit 1 in no , then set it to 0

	// int n=5;
	// int p=1;
	// int v=1;
	// cout<<setbit(n,p);
	// cout<<unsetbit(n,p);
	//unsetbit operation is same as clearbit operation

// 3 -> updatebit 
	// it is combination of clear(unset) and set bit
	// cout<<updatebit(n,p,v); 
	/*int n;
	cin>>n;*/
	// cout<<ispowerof2(n)<<endl;
	// n and ( n&(n-1) ) has the same no.of bits except rightmost set bit
	// ex,  5 -> 101
	// 5&4    -> 100
	// both has same bits except the right most set bit which is at index 0
	/*int x = (n & (n-1));
	cout<<x;*/

// QUE -> check how many 1s are in a binary represenatation of the n 
	// ans  -> 
	/*int n;
	cin>>n;
	int ans=0;
	while(n){
		n=n&(n-1);
		// as we know n and n&n-1 has same no. of same bits except the right most set bit in the n,we are removing the right most set bit one by one and keep a count of it
		ans++;
	}
	cout<<ans<<endl;*/

// QUE -> print all posible subset of a given set of length n
	// int n;
	// cin>>n;
	// char a[n];
	// fr(i,0,n)
	// 	cin>>a[i];
	// -
	// (a,n);

//QUE -> find a uniqye element in a array where all no. occurs twice except one no.
	// ex, if array is like -> {1,2,3,4,3,2,1} -> output is 4
	// 1 ->
	/*int n;
	cin>>n;
	int a[n];
	fr(i,0,n)
		cin>>a[i];
	int x=0;
	fr(i,0,n){
		x=x^a[i];
	}
	cout<<x;*/        // time complexcity -> O(n) , space complexcity -> O(1)
	// 2 ->
/*	int n;
	cin>>n;
	int a[n],vis[n];
	fr(i,0,n){
		cin>>a[i];
		vis[i]=0;
	}
	fr(i,0,n-1){
		fr(j,i+1,n){
			if(!(a[i]^a[j])){
				vis[i]++;
				vis[j]++;
			}
		}
	}
	fr(i,0,n){
		if(vis[i]==0)
			cout<<a[i]<<" ";
	}   */              // time complexcity -> O(n*n) , space complexcity -> O(n)

//QUE -> find two uniqye element in a array where all no. occurs twice except two no.
	// ex. if a={1,2,3,4,5,6,7,5,4,3,2,1} -> output is 6 7
	
	// 1->

/*	int n;
	cin>>n;
	int a[n],vis[n];
	fr(i,0,n){
		cin>>a[i];
		vis[i]=0;
	}
	fr(i,0,n-1){
		fr(j,i+1,n){
			if(!(a[i]^a[j])){
				vis[i]++;
				vis[j]++;
			}
		}
	}
	fr(i,0,n){
		if(vis[i]==0)
			cout<<a[i]<<" ";
	} */				// time complexcity -> O(n*n) , space complexcity -> O(n)
	
	// 2 ->
	
	/*int n;
	cin>>n;
	int a[n];
	fr(i,0,n)	cin>>a[i];
	int xorsum=0;
	fr(i,0,n)	xorsum=xorsum^a[i];
	
	int j=xorsum&(~(xorsum-1));
	int x=0,y=0;
	fr(i,0,n){
		if(a[i]&j)
			x=x^a[i];
		/*else
			y=y^a[i];
	}
	cout<<x<<" ";
	x=x^xorsum;
	cout<<x;*/		// time complexcity -> O(n) , space complexcity -> O(1)

	// 3 ->

	// int n;
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
	// time complexcity -> O(n) , space complexcity -> O(1)


// QUE -> find a unique element in a array st all no. occurs thrice except that no.

	// 1 ->

	/*int n;
	cin>>n;
	int a[n],vis[n];
	fr(i,0,n){
		cin>>a[i];
		vis[i]=0;
	}

	fr(i,0,n-1){
		fr(j,i+1,n){
			if(!(a[i]^a[j])){
				vis[i]++;
				vis[j]++;
			}
		}
	}

	fr(i,0,n){
		if(vis[i]==0)
			cout<<a[i]<<" ";
	}  */             // time complexcity -> O(n*n) , space complexcity -> O(n)

	// 2 ->
/*
	int n;
	cin>>n;
	int a[n];
	fr(i,0,n) cin>>a[i];*/

	// solution of this problem using the bitmanipulation technique is pending.

	// total no of setbits using inbuild function
	// int n;cin>>n;
	// cout<<__builtin_popcount(n);
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
