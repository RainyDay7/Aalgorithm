#include<bits/stdc++.h>
using namespace std;

//���ݶ���ʽ����
//O(klogn) kΪ������n����������
//����֧��m<=n<=10^6�����ݷ�Χ������p�Ĵ�С������û������
const int maxn = 100010;
////��������
int prime[maxn] , pnum =0 ;

//ɸѡ���������� O(nloglogn) 
bool p[maxn] = {0};//����Ϊfalse 
void findPrime(){
	for(int i=2; i<maxn; i++){
		if(p[i] == false){//���i������
			prime[pnum++] = i;
			for(int j=i+i; j<maxn; j+=i){//��ÿһ��������ɸȥ�������б��� 
				p[j] = true;
			} 
		 } 
	}
}

//����n!��������k�ĸ���  O(logn) 
int cal(int n,  int k){
	int ans = 0;
	while(n){
		ans+=n/k;
		n/=k;
	} 
} 

//������ a^b%p
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

//����C(n,m)%p
int C(int n, int m, int p){
	int ans=1;
	//����������n��������
	for(int i=0; prime[i]<=n; i++){
		//����C(n,m)�е�prime��ָ��c��cal(n,k)Ϊn!�к�������k�ĸ���
		int c = cal(n,prime[i]) - cal(m,prime[i]) - cal(n-m,prime[i]);
		//�����ݼ���prime[i]^c%p
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
