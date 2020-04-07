#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//计算Cnm组合数的计算 
//cnm = c(n-1)(m-1)+c(n-1)m 边界条件：cn0 = cnn = 1; 

//递归单次计算 
long long res[67][67] = {0};
ll C(ll n, ll m){
	if(m==0 || n==m) return 1;
	if(res[n][m]!=0) return res[n][m];
	return res[n][m] = C(n-1, m)+C(n-1, m-1);
}
//递推所有的C(n,m) O(n^2)
const int n=60;
void cal(){
	for(int i=0; i<=n; i++){
		res[i][0] = res[i][i]= 1;//初始化边界 
	}
	for(int i=2; i<=n; i++){
		for(int j=1; j<=i/2; j++){
			res[i][j] = res[i-1][j]+res[i-1][j-1];
			res[i][i-j] = res[i][j];//C[i,i-j]  = C[i][j]
		}
	} 
} 

int main(){
	cout<<C(10,2);
	return 0;
} 
