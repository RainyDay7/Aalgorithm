#include<bits/stdc++.h> 
using namespace std;

//���кϲ�����
int merge(int a[], int b[], int c[], int n. int m){
	int i=0, j=0, index=0;//iָ��a[0], jָ��b[0];
	while(i<n && j<m){
		if(a[i]<=b[j]){
			c[index++] = a[i++];
		}
		else {
			c[index++] = b[j++];
		}
	} 
	while(i<n) c[index++]=a[i++];
	while(j<m) c[index++]=b[j++];
	return index;//��������c�ĳ��� 
} 
