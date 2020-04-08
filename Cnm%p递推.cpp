//求Cnm % p
//通过递推公示计算，算法可以支持m<=n<=1000的情况，p的大小没有额外限制

int res[1010][1010] = {0};
int C(int n, int m, int p){
	if(m==0 ||m==n)return 1;
	if(res[n][m]!=0) return res[n][m];
	return res[n][m] = (C(n-1,m)+C(n-1,m-1)%p);
}  

void calC(){
	for(int i=0; i<=n; i++){
		res[i][0] = res[i][i] = 1;//初始化边界 
	}
	for(int i=2; i<=n; i++){
		for(int j=1; j<=n/2; j++){
			res[i][j] = (res[i-1][j-1]+res[i-1][j]%p;
			res[i][i-j] = res[i][j];
		}
	} 
}
