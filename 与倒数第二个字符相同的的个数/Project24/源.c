#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define length 100//����Ŀռ��С
int main(){
	int temp = 0;
	char array[length];//����һ��length���ȵĿռ�
	int len = 0;//��¼gets���յ�ʵ�ʳ���
	char value;//��¼�����ڶ������ַ�
	gets(array);
	puts(array);
	//����"abc" 3
	while (array[len] != '\0'){
		len++;
	}

	//�����ڶ���
    value = array[len - 2];
	for (int i = 0; i < len; i++){	
		if (value == array[i]){
			temp++;
		}
	}
	printf("%d", temp);
	return 0;
}