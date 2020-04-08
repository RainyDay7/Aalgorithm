#include<bits/stdc++.h>
using namespace std;

//根据定义式计算
//O(klogn) k为不超过n的质数个数
//可以支持m<=n<=10^6的数据范围，对于p的大小的素性没有限制
const int maxn = 100010;
////求素数表
int prime[maxn] , pnum =0 ;

//筛选法求素数表 O(nloglogn) 
bool p[maxn] = {0};//素数为false 
void findPrime(){
	for(int i=2; i<maxn; i++){
		if(p[i] == false){//如果i是素数
			prime[pnum++] = i;
			for(int j=i+i; j<maxn; j+=i){//对每一个素数，筛去它的所有倍数 
				p[j] = true;
			} 
		 } 
	}
}

//计算n!中质因子k的个数  O(logn) 
int cal(int n,  int k){
	int ans = 0;
	while(n){
		ans+=n/k;
		n/=k;
	} 
} 

//快速幂 a^b%p
//(a^b) mod c = (a mod c)^b mod c
int binaryPow(int a, int b, int p){
	int ans = 1;
	int base = a%p;
	while(b){
		if(b&1) ans = (ans*base)%p;
		base = (base*base)%p;
		b>>=1;
	}
} 

//计算C(n,m)%p
int C(int n, int m, int p){
	int ans=1;
	//遍历不超过n的所有数
	for(int i=0; prime[i]<=n; i++){
		//计算C(n,m)中的prime的指数c，cal(n,k)为n!中含质因子k的个数
		int c = cal(n,prime[i]) - cal(m,prime[i]) - cal(n-m,prime[i]);
		//快速幂计算prime[i]^c%p
		ans = ans*binaryPow(prime[i],c,p)%p;  
	} 
	return ans;
} 

int main(){
	findPrime();
	int n, m, p;
	scanf("%d%d%d", &n,&m,&p);
	int ans = C(n,m,p);
	printf("%d", ans);
}
