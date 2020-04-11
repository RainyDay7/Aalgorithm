//随机选择算法
//从a[left,right]中返回第k大的数
//最坏O(n^2) 任意输入的期望时间复杂度是O(n) 
int randSelect(int a[], int left, int right, int k){
	if(left == right) return a[left];//边界情况
	int p = randPartition(a,left, tight);//划分后主元的位置为P
	int m = p-left+1;//A[p]是A[left,right]中的第M大
	if(k==m) return a[p];
	if(k<m) return randSelect(a,left,p-1,k);//往主元左侧找第k大
	else return randSelect(a,p+1,right, k-m); 
} 

