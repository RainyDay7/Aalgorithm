//���ѡ���㷨
//��a[left,right]�з��ص�k�����
//�O(n^2) �������������ʱ�临�Ӷ���O(n) 
int randSelect(int a[], int left, int right, int k){
	if(left == right) return a[left];//�߽����
	int p = randPartition(a,left, tight);//���ֺ���Ԫ��λ��ΪP
	int m = p-left+1;//A[p]��A[left,right]�еĵ�M��
	if(k==m) return a[p];
	if(k<m) return randSelect(a,left,p-1,k);//����Ԫ����ҵ�k��
	else return randSelect(a,p+1,right, k-m); 
} 

