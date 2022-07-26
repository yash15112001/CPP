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
	// benefits - dynamic size
	/*operation like concatenation it requires more space&time rather than stringd
	string has '\0'	*/
	// declare string
// 1 ->
	/*string s;
	cin>>s;*/
// 2 -> 
	// string s1="vdvdfv";
// 3 ->
	// string s2(5,'n');     // s2 = nnnnn
	// string string_name(size of string, char)

// 4 -> how to input whole sentence in a string
	/*string str;
	getline(cin,str);
	cout<<str;*/

	// useful functions of the strings

// 1 -> concatenation of strings   , ex,
	// string s1="fam";
	// string s2="ily";
	// cout<<s1+s2<<endl;
	// s2.append(s1);
	// s1 = s1 + s2
	// cout<<s2;

	// any element of the any string can be accessed as any array
	// cout<<s2[1];

// 2 -> erase function
	// string s="nincompoop";
	// s.erase(5,2);
	// // the argument erase(int a,int b) -> will erase total b character from the a index
	// cout<<so;

	/*string s1,s2,r1="",r2="";
	cin>>s1>>s2;
	fr(i,0,s1.size()){
		if(s1[i]=='#'&&r1.size()==0)
			continue;
		else if(s1[i]=='#'&&r1.size()!=0){
			r1.erase(r1.size()-1,1);
		}
		else
			r1=r1+s1[i];
	}
	fr(i,0,s2.size()){
		if(s2[i]=='#'&&r2.size()==0)
			continue;
		else if(s2[i]=='#'&&r2.size()!=0){
			r2.erase(r2.size()-1,1);
		}
		else
			r2=r2+s2[i];
	}
	if(r1==r2)
		cout<<"good";
	else
		cout<<"ughh";*/

// 3 -> clear function & empty
	// string s="DVFVefvdvvebe";
	// if(s.empty()) cout<<"string is empty";
	// else cout<<"string is not empty";
	// cout<<endl;
	// s.clear();
	// if(s.empty()) cout<<"string is empty";
	// else cout<<"string is not empty";
	
// 4 -> compare the strings 
	// string s1="abc",s2="xyz";
	// string str;
	// str=s1>s2?s1:s2;
	// cout<<str;
	// failed attempt->
	/*string s;
	cin>>s;
	int i=0;
	while(s[i]!='\0'){
		if(s[i]=='#')
		{
			if(i==0) s.erase(i,1);
			else if(i!=0) s.erase(i-1,2);
		}
		if(s[i+1]=='#'&&s[i]!='#')
			s.erase(i,2);
		i++;
		cout<<s<<endl;
	}
	cout<<s;*/

// 5 -> find function
	string s = "ejbnvnqnvnla";
	int x = s.find("nvn");  // -> return the index where it locates the sub string else garbadge value or -1
	cout<<x<<endl;
// 6 -> insert a substring in a given string 
	// string str,str2;
	// cin>>str>>str2;
	// int n;
	// cin>>n;
	// if(n<=str.size()){
	// 	str.insert(n,str2);
	// 	cout<<str;
	// }
	// else
	// 	cout<<"insertion is not possibele";

// 7 -> to get a substring from given string if possible;

	// string s,s1;
	// cin>>s;
	// int x;
	// cin>>x;
	// if(x<s.size()){
	// 	s1=s.substr(x);
	// 	cout<<s1;
	// }
	// else
	// 	cout<<"substring you are asking is not possible to get";

	// IMPORTANT note about the substr() function, 
	    /*1. -> if there is only in parameter in the substr function then it will return full substr from that index to end of the string
	    ex. -> if s=yash and if we use like, s1=s.substr(2); then s1 -> sh
	    2. -> if there is two parameter in the substr function then it will return substring from index x to y
	    ex -> if s=abcdefg and if we use like , s1 = s.substr(2,6); then s1 -> cdefg*/

// 8 -> converting str to int and int to str

	// string s="065462";
	// int x= stoi(s);
	// x+=2;
	// cout<<to_string(x) + "fbdvdv" <<endl;

// 9 -> sort the string in lexographical order

	// string s= "dbvnvwbfsldfvsdbnldnboiwnvsdjbskbn";

	// sort(s.begin(),s.end());
	// cout<<s<<endl;

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
