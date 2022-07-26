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

void solve()
{
	// set

	// intialization of set 
//1->
	
	/*set<int> s;
	s.insert(50);   // all time complexcities are same as map
	s.insert(10);
	s.insert(15);
	s.insert(10);*/

//2->
	/*int n;
	cin>>n;
	set<int> se;
	fr(i,0,n){
		int x;
		cin>>x;
		se.insert(x);
	}*/

	//print the set
	/*	
//1->
	for(auto i:s)
		cout<<i<<" ";
//2->
	for(auto &i:s)
		cout<<i<<" ";
//3->
	for(auto i=s.begin();i!=s.end();i++)
		cout<<*i<<" ";
	*/
	// find and erase operations in set

	/*auto it=s.find(10);
	if(it!=s.end())
		s.erase(it);*/
	//s.find(10);

	// unordered_set

	/*

	// intialization of set 
//1->
	unordered_set<int> s;
	s.insert(50);   // all time complexcities are same as unordered_map
	s.insert(10);
	s.insert(15);
	s.insert(10);

//2->
	/*int n;
	cin>>n;
	unordered_set<int> se;
	fr(i,0,n){
		int x;
		cin>>x;
		se.insert(x);
	}

	*/

	//print the u_set
	/*	
//1->
	for(auto i:s)
		cout<<i<<" ";
//2->
	for(auto &i:s)
		cout<<i<<" ";
//3->
	for(auto i=s.begin();i!=s.end();i++)
		cout<<*i<<" ";
	
	*/

	// other operations like, find and erase are also applicable in u_set

	//defference between them;

	/*          set 				            ||            unordered_set
	    
	    all operation -> O(log n)               ||     all operations -> O(1) 
		print takes -> O(n logn)                ||     print takes -> O(n)
		prints in sorted order                  ||     prints in random order
		data types(key) used in maps are any    ||     data types used in u_maps are only basic
		(basic)including complex data types like
		pair<dt,dt> , tuple<dt,dt,dt> ,
		vector<dt> 

		both stores unique elements only
	*/
	

	// MULTISET --> important for the competative programming

	// multiset comes in a picture when you need to multiple identical keys in the same set in the sorted ways
	// eg.

	multiset<int> ms;
	
	/*ms.insert(10);
	ms.insert(20);
	ms.insert(30);
	ms.insert(10);
	ms.insert(20);
	ms.insert(40);

	/*auto it=ms.find(10);
	if(it!=ms.end())
		ms.erase(it);*/   // if you pass an iterator of a certain vaulue in the erase function then the if multiple values are present then the first value will be deleted , else you directly pass a value in erase function
	//then all values from the multiset will be deleted

	/*ms.erase(10);	

	for(auto i:ms)
		cout<<i<<" ";*/

	/*int n,k;
	cin>>n>>k;
	fr(i,0,n){
		int x;
		cin>>x;
		ms.insert(x);
	}

	int ans=0;
	fr(i,0,k){
		auto it=(--ms.end());
		//int c=*it;
		ans+=*it;
		ms.insert(*it/2);
		ms.erase(it);
		//ms.insert(*it/2);
	}

	cout<<ans;*/

	// unordered multiset also exist => unordered set + multiset
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
