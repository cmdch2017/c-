#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define length 100//申请的空间大小
int main(){
	int temp = 0;
	char array[length];//申请一个length长度的空间
	int len = 0;//记录gets接收的实际长度
	char value;//记录倒数第二个的字符
	gets(array);
	puts(array);
	//例如"abc" 3
	while (array[len] != '\0'){
		len++;
	}

	//倒数第二个
    value = array[len - 2];
	for (int i = 0; i < len; i++){	
		if (value == array[i]){
			temp++;
		}
	}
	printf("%d", temp);
	return 0;
}