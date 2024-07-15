#include <stdio.h>
#include <errno.h>
#include <string.h>

void ListErrorMsg()
{
	char *errmsg;

	printf("== Error Message List ==\n");
	for (int i = 0; i < 45; i++)
	{
		errmsg = strerror(i);
		printf("<%d>.%s\n", i, errmsg);
	}
}

int main()
{
	FILE *fp;

	ListErrorMsg();
	
	printf("\n없는 파일 읽기 모드로 열었을 때의 에러 메시지 확인\n");
	fp = fopen("noexist.txt", "rt");
	if (fp == NULL)
	{
		perror("file not existed");
		printf("%d: %s\n", errno, strerror(errno));
		return 0;
	}
	fclose(fp);
	return 0;
}
