#include<bits/stdc++.h>
using namespace std;
 
 //ѡ������ �Ӻ����ѡ����С��ֵ��ǰ��Ľ��� 
void selectSort(){
 	for(int i=0; i<n; i++){//��n�� 
 		int k=i;
 		for(int j=i; j<n; j++){//ÿ�αȽϴ�i��n 
 			if(a[j]<a[k])
			  k=j; 
		}
		swap(a[i],a[k]);//����A[i]��A[k] 
	}
 } 
 
 //�������� 
void insertSort(){
	for(int i=1; i<n; i++){//����n-1�� 
		int temp = a[i];
		int j=i;
		while(j>0 && temp<a[j-1]){//�Ӻ�����ǰ�Ƚ� 
			a[j] = a[j-1];//������һ�� 
			j--; 
		} 
		a[j] = temp; 
	}
} 


