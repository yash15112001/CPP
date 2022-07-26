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

void solve()
{	
	/*
		c++
			basics -> dt , if-else , loops
			array , string ,functions , pointers , "OOPs"
			time & space complexcity --
			stl -> robust representation using the class + direct use using the inbuild implementation
				array
				list - linked list,doubly linked list, circulat linked list
				vectors
				pairs
				tuples
				map ( , unordered , multi )
				set ( , unordered , multi , ordered )
				nesting of stl containers
				queue
				deque
				priority queue ( heap )
				stack
				list
			recursion --
			number theory --
			bit manipulation ( bit masking ?? ) --
			miscllenous --

		Data structures ( implementation using class for majority of datastructures ) 
			array
			linked list & variations ( ll , dll , csll ,cdll )
			stack
			queue , deque 
			priority queue => heap ( max heap , min heap )
			hashing
			tree
				bt & bst and variations
			graph
			matrix
			miscllenous

			* advanced data structure
				advanced tree
				advanced list
				trie
				segment tree
				binary indexed tree

		algorithms
			searching and sorting
				-> linear search				->bubble sort
				-> binary search 				->insertion sort
				-> jump searching				->selection sort
				-> interpolation search			->count sort
				-> exponential search			->dnf sort
												->merge sort
												->quick sort
												->wave sort
												->heap sort
												->bucket sort
												->radix sort
			greedy algorithm
			dynamic programming
			backtracking
			divide and conquer
			graph and tree algos
			bit algos
			string algos 
			misc

		CP
			codeforces and codechef
			leetcode
	*/

	//revision

	//s.erase(a,b); -> erase total b characters from position a in string
	//s.erase(a); -> erasing all characters from index a till character '\0'
	//getline(cin,str);
	//s1 = s1+s2 -> s1.append(s2);
	//random access possible
	//s.clear() and s.empty() -> 1
	//s.find(string s1) -> finds s1 in s as substr of s , if substr found then return position of that substr starting
	//s.substr(i) -> returns the substr of s from index i 
	//s.substr(i,j) -> returns the substr of length j from index i in string s
	//string to integer and vice versa  -> stoi(string s) & to_string(int a)
	//sort the string in lexographical manner -> sort(s.begin(),s.end())
	/*string s="65116";
	s=to_string(stoi(s)+2)+"dfdgdf";
	sort(s.begin(),s.end());
	cout<<s;
	// cout<<s.insert(5,"erfedfvdvdf");
	string s2="dfvd";
	s2.erase(1);*/
	// cout<<s2.append(s);

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