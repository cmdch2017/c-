#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <windows.h>
void game_screw(int a[100][10],int n,int j){
	int i, k, m;
	//每层首个元素
	m = 4 *j*n - 4*j*j + 1;
	//j层上
	for (k = j; k < n - j; k++)
	{
		a[j][k] = m + k - j; 
	}
	for (i = j; i < n - j; i++){
		a[i][n - 1 - j] = n + m - 1 - 2 * j + i - j; 
	}
	for (k = n - 1 - j; k >= j; k--){
		a[n - 1 - j][k] = m + 2 * n - 2 - 4 * j + n - 1 - j - k; 
	}
		for (i = n - 1 - j; i>j; i--){
			a[i][j] = m + 3 * n - 3 - 6 * j + n - 1 - j - i; 
		}
	
}
int main(){
	//n阶数，i内层数
	int n, i, j;
	static int a[10][10];
	printf("请输入螺旋阵的阶数：");
	scanf("%d", &n);
	i = (n + 1) / 2;//从外向里一共有i层
	for (j = 0; j< i; j++){
		game_screw(a, n, j);
	}
	//打印矩阵
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			printf("%-5d", a[i][j]); Sleep(100);
		}printf("\n");
	}
	system("pause");
	return 0;
}