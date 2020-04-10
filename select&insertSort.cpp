#include<bits/stdc++.h>
using namespace std;
 
 //选择排序 从后面的选出最小的值与前面的交换 
void selectSort(){
 	for(int i=0; i<n; i++){//走n次 
 		int k=i;
 		for(int j=i; j<n; j++){//每次比较从i到n 
 			if(a[j]<a[k])
			  k=j; 
		}
		swap(a[i],a[k]);//交换A[i]和A[k] 
	}
 } 
 
 //插入排序 
void insertSort(){
	for(int i=1; i<n; i++){//进行n-1次 
		int temp = a[i];
		int j=i;
		while(j>0 && temp<a[j-1]){//从后面往前比较 
			a[j] = a[j-1];//往后移一个 
			j--; 
		} 
		a[j] = temp; 
	}
} 


