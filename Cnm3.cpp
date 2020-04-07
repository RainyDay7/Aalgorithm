#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//计算Cnm组合数的计算 
//O(m)
long long res[67][67] = {0};
ll C(ll n, ll m){
	ll ans = 1;
	for(ll i=1; i<=m; i++){
		ans=ans*(n-m+i)/i;//注意一定要先乘再除 
	}
	return ans; 
}


int main(){
	cout<<C(10,2);
	return 0;
} 
