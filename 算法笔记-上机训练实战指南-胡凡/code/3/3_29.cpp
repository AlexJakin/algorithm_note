/**

1 galleon = 17 sickle
1 sickle = 29 knut

���� �� galleon.sickle(17).knut(29) 

**/
#include <stdio.h>

int main(){
	// a��b�Ǽ������
	// c ��Ž�� 
	int a[3], b[3], c[3];
	scanf("%d.%d.%d %d.%d.%d",  &a[0], &a[1], &a[2], &b[0], &b[1], &b[2]);
	
	//�����λ
 	int carry = 0;
 	//��ĩλ��ʼ����
	c[2] = (a[2] + b[2])%29;
	carry =  (a[2] + b[2])/29;//��λ
	
	//����ڶ�λ 
	c[1] = (a[1] + b[1] + carry)%17;
	carry = (a[1] + b[1] + carry)/17;
	
	//�������λ
	c[0] = a[0] + b[0] +  carry;
	
	printf("%d.%d.%d", c[0], c[1], c[2]); 
	return 0;
}