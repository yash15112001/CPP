#include<bits/stdc++.h>
#include<math.h>
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
	int n;
	cin>>n;
	int x=n;
	int ans=0;
	while(n){
		int last=n%10;
		ans+=pow(last,3);
		n=n/10;
	}
	if(ans==x)
		cout<<"armstrongnumber"<<endl;
	else
		cout<<"not a armstrongnumber"<<endl;
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
		cout<<endl;
	}*/
	solve();
	return 0;
}
