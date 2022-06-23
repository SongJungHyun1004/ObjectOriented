#include<stdio.h>

int main()
{
	printf("문자를 입력하세요(100자 이내).\n");
	char input[100];
	gets(input);	//scanf("%s", input);
	printf("입력된 문자는 %s입니다.", input);
	return 0;
}