// B1014 福尔摩斯的约会 
#include <stdio.h>
#include <cstring>

char week[7][5] = {
		"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"
};
 
int main(){
	char str1[70], str2[70], str3[70], str4[70];
	//输入部分 
	gets(str1); gets(str2);gets(str3);gets(str4);
	
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int len3 = strlen(str3);
	int len4 = strlen(str4);
	
	int i =0; //保存i值 
	
	// 星期几 寻找str1和str2中的第一对相同位置的字符 
	for (i = 0; i < len1 && i < len2; i++)
	{
		if(str1[i] == str2[i] && str1[i] >= 'A' && str2[i] <= 'G')
		{
			printf("%s ", week[str1[i] - 'A']); //减去A的ascii得到i字母的相对位置 
			break;
		}
	}
	
	// 寻找第二对相同
	for(i++; i < len1 && i < len2; i++)
	{
		if(str1[i] == str2[i])
		{
			if(str1[i] >= '0' && str1[i] <= '9')
			{
				printf("%02d:", str1[i] - '0');
				break;
			}
			else if (str1[i] >= 'A' && str1[i] <='N')// 0~12 对应 0~N
			{
				printf("%02d:", str1[i] - 'A' + 10);
				break;
			} 
		}
		
	}
	
	//分钟
	for(int i = 0; i < len3 && i < len4; i++)
	{
		if(str3[i] == str4[i])
		{
			if( (str3[i] >= 'A' && str4[i] < 'Z')
				|| (str3[i] >= 'a' && str4[i]<='z'))
			{
				printf("%02d", i);
				break;
			}
		}
	} 
	return 0;
} 