//��Cnm % p
//ͨ�����ƹ�ʾ���㣬�㷨����֧��m<=n<=1000�������p�Ĵ�Сû�ж�������

int res[1010][1010] = {0};
int C(int n, int m, int p){
	if(m==0 ||m==n)return 1;
	if(res[n][m]!=0) return res[n][m];
	return res[n][m] = (C(n-1,m)+C(n-1,m-1)%p);
}  

void calC(){
	for(int i=0; i<=n; i++){
		res[i][0] = res[i][i] = 1;//��ʼ���߽� 
	}
	for(int i=2; i<=n; i++){
		for(int j=1; j<=n/2; j++){
			res[i][j] = (res[i-1][j-1]+res[i-1][j]%p;
			res[i][i-j] = res[i][j];
		}
	} 
}
