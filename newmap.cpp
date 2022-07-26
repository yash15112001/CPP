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
//map - unordered_map - multimap
void solve()
{	
	//intialization of map from int to int;
	
//1->
	
	// map<int,int> m;
	// m[3]=5;
	// m[7]=10;
	// m[2]=63;
	// m.insert({10,50});
	// map only stores the unique keys ex. if you inserts multiple values with the same key then the last entery with same key will be valid
	// suppose map<int ,int> m;
	// m[1]=5;
	// m[2]=10;
	// m[1]=15;
	// now if you print the map then output will be like this:
	// 1 -> 15
	// 2 -> 10
	// no matter in which order of keys it takes the input but always it will store it in the sorted (increasing order) order of the key 

//2->
	// int n;
	// cin>>n;
	// fr(i,0,n){
	// 	int x,y,z;
	// 	cin>>x>>y>>z;
	// 	m[x]=mp(y,z);                  // insertion in map cost O( log n ) time
 //   		//m.insert(mp(x,y));
	// 	//m.insert({x,y});
	// }

	//print the map
//1->
	// for(auto i:m)
		// cout<<i.f<<endl;                // here i.f access any certain value from map and costs O(log n) time -- all over operations costs = n * O(log n) time complexcity which is to print the map;
//2->
	// for(auto &i:m)
		// cout<<i.f<<endl;
//3->
	// for(auto it=0;it<m.size();it++)
	// 	if(m[it])cout<<it<<" "<<m[it]<<endl;
//4->
	// for(auto it=m.begin();it!=m.end();it++)
		// cout<<it->f<<endl;

	//other operations in map

	// find and erase
	// m.erase(2);        // costs O(log n) time

	// another way to delete a key with its value in map is by passing iterator
	// auto it=m.find(7);         // find operation also costs you a O(log n) time;
	// m.erase(it); 

	// unordered_map<dt,dt> um;

	// every operations in the u_map is same as the map
	//defference between them;

	/*          map ( red-black tree )         ||            unordered_map(hash map)
	    
	    all operation -> O(log n)              ||     all operations -> O(1) 
		print takes -> O(n logn)               ||     print takes -> O(n)
		prints in sorted order                 ||     prints in random order
		data types used in maps are any(basic) ||     data types used in u_maps are only basic
		including complex data types like
		pair<dt,dt> , tuple<dt,dt,dt> ,
		vector<dt> 

		both stores unique elements only
	*/

	// multi maps
	// multimap<int,int> mm;
	//multimap<dt,dt> m --> dt -> any
	// in map when we assigns another value using already stored key then, older value gets erased in the map, but in multimap you can store multiple values with the same key
	// like
	// mm.insert(mp(1,2));
	// mm.insert(mp(2,10));
	// mm.insert(mp(1,2));
	// mm.insert(mp(1,3));
	// // cout<<" iodjoidfjg ";
	// for(auto &i:mm)
	// 	cout<<i.f<<" -> "<<i.s<<endl;
	multimap<int,vector<int>> m;
	m.insert({1,{1,2,3}});
	

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
