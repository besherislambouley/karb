/*
 * https://github.com/thecodingwizard/competitive-programming/blob/master/Infoarena/karb.cpp
*/
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 270
//#define mp make_pair
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
#define all(x) x.begin(), x.end()
#define gc getchar_unlocked
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll inf=1e18;
const ll mod=1e9+7;
const ld pai=acos(-1);
int n , m , k ;
int p [100009] ;
int get ( int node ) {
	if ( node == p [node] ) return node ;
	return p [node] = get ( p [node] ) ; 
}
int merge ( int a , int b ) {
	a = get ( a ) , b = get ( b ) ; 
	if ( a == b ) return 0 ;
	p [b] = a ;
	return 1 ;
}
int main () {
	freopen ( "karb.in"  , "r" , stdin  ) ;
	freopen ( "karb.out" , "w" , stdout ) ;
	scanf("%d%d%d",&n,&m,&k) ;
	for ( int i = 0 ; i < n ; i ++ ) p [i] = i ;
	vpi one , zero ;
	for ( int i = 0 ; i < m ; i ++ ) {
		int a , b , c ;
		scanf("%d%d%d",&a,&b,&c) ;
		a -- , b -- ;
		if ( c ) one .pb ( { a , b } ) ;
		else zero .pb ( { a , b } ) ;
	}
	vpi ans , must , other ; 
	for ( auto u : zero ) merge ( u.fi , u.se ) ;
	for ( auto u : one  ) {
		if ( merge ( u.fi , u.se ) ) {
			must .pb ( u ) ;
			ans  .pb ( u ) ;
			k -- ;
			C ; 
		}
		other .pb ( u ) ;
	}
	for ( int i = 0 ; i < n ; i ++ ) p [i] = i ;
	for ( auto u : must ) merge ( u.fi , u.se ) ;
	for ( auto u : other ) {
		if ( !k ) break ; 
		if ( merge ( u.fi , u.se ) ) {
			k -- ;
			ans .pb ( u ) ;
		}
	}
	for ( auto u : zero ) {
		if ( merge ( u .fi , u.se ) ) {
			ans .pb ( u ) ;
		}
	}
	for ( auto u : ans ) printf("%d %d\n",u.fi+1,u.se+1) ;
}
