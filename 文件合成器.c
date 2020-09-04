#include <stdio.h>
#include <stdlib.h>


/*
玩法：可以将图片和压缩包合成一个文件，通过改后缀名来回切换
*/
void main()
{
	FILE *f_pic,*f_file,*f_finish;//建立文件指针
	char ch,pic_name[100],file_name[100],finish_name[100];


	printf("请输入需要合成的图片和文件的名称:\n");
	printf("图片:");
	scanf("%s", pic_name);
	printf("文件:");
	scanf("%s", file_name);
	printf("生成后的命名:");
	scanf("%s", finish_name);

	//打开文件函数 文件指针名 = fopen(文件名,打开方式)
	if(!(f_pic = fopen(pic_name,"rb")))
	{
		printf("无法打开%s",pic_name);
		return;
	}

	if(!(f_file = fopen(file_name,"rb")))
	{
		printf("无法打开%s",file_name);
		return;
	}

	if(!(f_finish = fopen(finish_name,"wb")))
	{
		printf("无法打开%s",finish_name);
		return;
	}

	/* 如果文件以二进制方式读取与存放的时候就只能使用feof函数EOF=-1,在二进制存放的时候会出现-1 */

	//feof(文件指针名)  文件未结束时返回值为0
	while(!(feof(f_pic)))
	{
		ch = fgetc(f_pic);   //fgetc(文件指针)从文件指针读取一个字符，读取一个字节后，光标位置后移一个字节
		fputc(ch,f_finish);  //fputc()将字符x写到文件指针fp所指向的文件的当前写指针的位置
	}
	fclose(f_pic);

	while(!(feof(f_file)))
	{
		ch = fgetc(f_file);
		fputc(ch,f_finish);
	}

	fclose(f_file);
	fclose(f_finish);

	system("pause");
}
