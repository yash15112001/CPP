#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
#define int_max INT_MAX
#define int_min INT_MIN
#define null NULL
const int M = 1e9 + 7;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
  
#define pbds_i tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define pbds_c tree<char, null_type,less<char>, rb_tree_tag,tree_order_statistics_node_update>
#define pbds_ll tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define pbds_d tree<double, null_type,less<double>, rb_tree_tag,tree_order_statistics_node_update>
#define pbds_s tree<string, null_type,less<string>, rb_tree_tag,tree_order_statistics_node_update>

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

// class hero{
// private:
// public:	
// 	char level;
// 	int health;
// 	const static int time;
// 	hero(){
// 		cout<<"defualt constructor called"<<endl;
// 	}
// 	hero(int health,char level){
// 		// cout<<"parameterized constructor called"<<endl;
// 		this->health = health;
// 		this->level = level;
// 	}
// 	hero(hero& x){
// 		this->level = x.level;
// 		this->health = x.health;
// 	}
// 	void print(){
// 		cout<<this->level<<" "<<this->health<<endl;
// 	}
// 	~hero(){
// 		cout<<"destructor called"<<endl;
// 	}
// 	static int r(){
// 		return time;
// 	}
// };

// const int hero::time = 5;

// class abc{
// public:	
// 	int a;
// 	abc(int b/*=0*/)/*:a(b)*/{
// 		this->a=b;
// 		// this is read only varable of the class abc
// 		// once we assign value of the const variable of the class as
// 		// abc(int a):a(a){}
// 		// then value of a for particular instance of the class will be assigned and can never be chaged
// 		// this is also called as intialization of const data members using the intialization list
// 		// however the non const data memebers of the class can still be intialized using parameterized constructor
// 	}
// 	void f() const{
// 		cout<<"call from const function"<<endl;
// 	}
// };

// class A{
// 	const int a,b;
// public:	
// 	A(int a=0,int b=0):a(a),b(b){
// 		// const data members of the class must be intialized with intialization list 
// 		// intialization list is the parameterized constructor for the const data memebrs
// 		cout<<"call from intialization list"<<endl;
// 		// once the const data memebers of the class is intialized it can be changed
// 	}
// 	int geta(){return a;}
// 	int getb(){return b;}
// };

void solve()
{	
	// hero a(10,'a');
	// hero *b = new hero(a);
	// a.print();
	// (*b).print();

	// A a;
	// cout<<sizeof(b)<<endl;

	// -> access modifiers for the access of the data members -> by default -> preivate is enabled
	// public , private , protected

	// hero r;
	// r.health = 70;
	// r.setlevel('D');
	// cout<<r.getlevel()<<endl<<r.health<<endl;

	// cout<<sizeof(r)<<endl;

	// declaration for instance of the class hero
	// hero a;
	// a.level='A';
	// a.health = 80;

	// hero *b = new hero;
	// // b->level='B';
	// (*b).level = 'C';
	// b->health=90;

	// for dynamically allocated instance of the class

	// hero *x = new hero(5,'A');
	// cout<<x->level<<" "<<x->health<<endl;
	// cout<<(*x).level<<" "<<(*x).health<<endl;

	// cout<<a.level<<" "<<a.health<<" "<<(*b).level<<" "<<(*b).health<<" "<<b->level<<" "<<b->health<<endl; 

	// constructor : default and user defined
	// hero a; // default constructor called
	// hero *b = new hero(); // default constructor called
	// hero *c = new hero(50); // parameterized constructor

	// copy constructor
	// hero h(5,'a');
	// hero b(h);
	// cout<<b.level<<" "<<b.health<<endl;
	// in user defined copy constructor pass the instance of the class by reference

	// diff between user defined copy constructor and default constructor

	// hero a(10,'A');
	// cout<<a.level<<" "<<a.health<<endl;
	// a.print();

	// hero b(a);
	// cout<<b.level<<" "<<b.health<<endl;
	// b.print();

	// a.level = 'B';
	
	// cout<<a.level<<" "<<a.health<<endl;
	// cout<<b.level<<" "<<b.health<<endl;

	// a.print();
	// b.print();

	// in case of shallow copy which is done if called the default constructor 
	// if we have attribute in the class which works with pointer rather than the value then after default copy constructor call
	// new instaces' attribute will also change
	// to prevernt this type of situations , use user defined constructor in which every time make the copy of instances which deals with the pointers

	// copy assignmnet operator

	// hero a(10,'z');
	// hero b(15,'t');

	// a.print();
	// b.print();

	// a=b;

	// a.print();
	// b.print();

	// **destructor
	// for statically allocated object of the class the destructor is automatically called at the end of the program
	// but we have to call the destructor manually for the dynamically allocated objects

	// hero a(5,'s');
	// hero *b = new hero(10,'c');
	// delete b;

	// ** const data member & const functions of the class
	// abc ba(15);
	// cout<<ba.a<<endl;
	// ba.f();
	// ba.a = 20;

	// ** intializing list
	// intialization list is a parameterized constructor for the const data members
	// A a(5,6);
	// cout<<a.geta()<<endl;
	// cout<<a.getb()<<endl;

	// **static datamember
	// this type of datamembers are property of class and are independent of the instance of the class
	// to access the static datamembers of the class , there is no need of making the object of the class

	// cout<<hero::time<<endl;
	// hero a;
	// cout<<a.time<<endl;
	// hero b;
	// b.time = 10;

	// cout<<a.time<<" "<<b.time<<endl;

	// static variables of the class are also accessed through the objects of the class , which should not happen 
	// so we could use the const static int , instead of static int .. line 74 - 95

	// **static functions of the class
	// static function are independent of the objects of the class and is property of the class 
	// static function does not have the this-> pointer
	// static function can only access the static variables

	//cout<<hero::r()<<endl; 

	// *************************************************************************************************************************************

	// pillers of the OOPs
	// 1) encapsulation
	// 2) inheritance
	// 3) polymorphism
	// 4) abstraction

	// ----------------------------------------------------------------------------------------------------------------

	// 1) encapsulation
	// preocess of wrapping data members with memeber function
	// data hiding
	// normal class we have implemented till now
	// fully encapsulated -> all data members are private


	// ----------------------------------------------------------------------------------------------------------------

	// **2) inheritance
	// parent class -> super class
	// child class -> sub class

	// syntax :: class child_class_name : (access_modifier:{public,private,protected}) parent_class_name
	
	// class A{
	// private:
	// 	int x;
	// public:
	// 	A(int x=0):x(x){}
	// 	void setx(int x){this->x=x;}
	// 	int getx(){return this->x;}
	// };

	// class B:public A{
	// public: // not area of focus ...
	// 	int y;
	// public:
	// 	B(int y=0):y(y){}
	// 	void sety(int y){this->y=y;}
	// 	int gety(){return this->y;}
	// 	void setxinB(int x){this->x=x;}
	// 	int getxinB(){return this->x;}
	// };

	// class C:public B{
	// 	int getxinC(){return this->x;}
	// };

	// B b;
	// // b.x = 10;
	// b.setxinB(5);
	// cout<<b.getxinB()<<endl;

	// types of inheritance --------------------------------------
	// 1) single inheritance
	// 2) multilevel inheritance
	// 3) multiple inheritance
	// 4) hybrid inheritance
	// 5) heirarchicle inheritance

	// 1) single inheritance
	// class A{
	// public:
	// 	void fA(){
	// 		cout<<"in A"<<endl;
	// 	}
	// };

	// class B:public A{

	// };

	// B b;
	// b.fA();

	// 2) multilevel inheritance
	// class A{
	// public:	
	// 	void fA(){
	// 		cout<<"in A"<<endl;
	// 	}
	// };
	// class B:public A{
	// public:
	// 	void fB(){
	// 		cout<<"in B"<<endl;
	// 	}
	// };
	// class C:public B{

	// };

	// C c;
	// c.fA();
	// c.fB();

	// 3) multiple inheritance
	// class A{
	// public:	
	// 	void fA(){
	// 		cout<<"in A"<<endl;
	// 	}
	// };
	// class B{
	// public:
	// 	void fB(){
	// 		cout<<"in B"<<endl;
	// 	}
	// };
	// class C:public A,public B{

	// };

	// C c;
	// c.fA();
	// c.fB();

	// 4) hierarchical inheritance
	// class A{
	// public:	
	// 	void fA(){
	// 		cout<<"in A"<<endl;
	// 	}
	// };
	// class B:public A{
	// public:
	// 	void fB(){
	// 		cout<<"in B"<<endl;
	// 	}
	// };
	// class C:public A{

	// };

	// B b;
	// C c;
	// b.fA();
	// b.fB();
	// c.fA();
	// // c.fB();

	// 5) hybrid inheritance : 
    
	//     A
	//     |
	// C   B
	//  \ /
	//   D
	//   |
	//   E   H
	//  / \ /
	// F   G

	// class A{
	// public:
	// 	void fA(){
	// 		cout<<"in A"<<endl;
	// 	}
	// };

	// class C{
	// public:
	// 	void fC(){
	// 		cout<<"in C"<<endl;
	// 	}
	// };

	// class H{
	// public:
	// 	void fH(){
	// 		cout<<"in H"<<endl;
	// 	}
	// };

	// class B:public A{
	// public:
	// 	void fB(){
	// 		cout<<"in B"<<endl;
	// 	}
	// };

	// class D:private B,public C{
	// public:	
	// 	void fD(){
	// 		cout<<"in D"<<endl;
	// 	}
	// };

	// class E:public D{
	// public:
	// 	void fE(){
	// 		cout<<"in E"<<endl;
	// 	}
	// };

	// class F:public E{
	// public:
	// 	void fF(){
	// 		cout<<"in F"<<endl;
	// 	}
	// };

	// class G:public E,public H{
	// public:
	// 	void fG(){
	// 		cout<<"in G"<<endl;
	// 	}
	// };

	// G g;
	// g.fA();
	// g.fB();
	// g.fC();
	// g.fD();
	// g.fE();
	// g.fG();
	// g.fH();

	// ** inheritance ambiguity

	// class A{
	// public:
	// 	void ff(){
	// 		cout<<"in A"<<endl;
	// 	}
	// };

	// class B{
	// public:
	// 	void ff(){
	// 		cout<<"in B"<<endl;
	// 	}
	// };

	// class C:public A,public B{

	// };

	// C c;
	// // :: -> scope resolution operator
	// c.A::ff();
	// c.B::ff();


	// ----------------------------------------------------------------------------------------------------------------

	// ***3) polymorphism
	// many characteristic , implementstion , behaviour of same thing

	// 					      polymorphism
	//						  /           \
	//						 /             \
	//						/               \
	//					   /                 \
	// 					  /                   \
	//					 /             		   \
	//  				/               		\
	// 		compile time(static)        run time(dynamic)
	// 			polymorphism         	  polymorphism
	// 			/           \					|
	// 		function     operator 			  method
	// 		overloading  overolading 		overriding

	// compile time polymorphism - static polymorphism
	// function overloading

	// class A{
	// public: 	
	// 	void f(){
	// 		cout<<"hello yash"<<endl;
	// 	}
	// 	void f(string s){
	// 		cout<<"hello "<<s<<endl;
	// 	}
	// 	int f(int x){
	// 		return x+5;
	// 	}
	// };

	// A a;
	// a.f("hkhhkb");
	// cout<<a.f(5)<<endl;

	// operator overloading

	// class A{
	// public:
	// 	int a;
	// 	A(int a){
	// 		this->a=a;
	// 	}
	// 	int add(A& b){
	// 		return this->a+b.a;
	// 	}
	// 	int operator+(A& b){
	// 		return this->a-b.a;
	// 	}
	// 	int minus(A& b){
	// 		return this->a-b.a;
	// 	}
	// 	int operator-(A& b){
	// 		return this->a+b.a;
	// 	}
	// };

	// A a(10),b(5);
	// cout<<a.add(b)<<endl<<a.minus(b)<<endl<<a+b<<endl<<a-b<<endl;

	// run time polymorphism - dynamic polymorphism
	// method overidding

	// class A{
	// public: 
	// 	void f(){
	// 		cout<<"in A"<<endl;
	// 	}
	// };

	// class B:public A{
	// public:	
	// 	void f(){
	// 		cout<<"now in B"<<endl;
	// 	}
	// };

	// class C:public B{
	// public:	
	// 	void f(){
	// 		cout<<"now in C"<<endl;
	// 	}
	// };

	
	// C c;
	// c.f();
	// B b;
	// b.f();

	// ----------------------------------------------------------------------------------------------------------------

	// Abstraction

	

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