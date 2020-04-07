#include<bits/stdc++.h>
using namespace std;

//计算n！中有多少个质因子p  
//O(logn) 等价于n/p +n/p^2+n/p^3…… 
int cal(int n, int p){
	 int ans = 0;
	 while(n){
	 	ans+=n/p;//累加n/p^k 
	 	n/=p;//相当于分母多乘一个p 
	 }
} 

int cal2(int n, int p){
	if(n<p) return 0;
	return n/p+cal(n/p,p);
} 

int main(){
	
	return 0;
} 
