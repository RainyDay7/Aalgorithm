#include<bits/stdc++.h>
using namespace std;

//����N�����������ٸ���M��������������M�����е�ÿ�����ֱ��Ƿ�����N�����г��ֹ� 
//�����������Ϊ������±���������������ʽ���ͳ�� 
const int maxn = 100010;
bool hashTable[maxn] = {false};
int main(){
	int n,m,x;
	scnaf("%d%d",&n,&m);
	for(int i=0;i<n; i++){
		scanf("%d",&x);
		hashTable[x] = true;//����x���ֹ� 
	}
	for(int i=0;i<m; i++){
		scnaf("%d",&x);
		if(hashTable[x]==true)
			printf("YES\n");
		else printf("NO\n");
	} 
	return 0;
} 
