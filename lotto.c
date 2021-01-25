#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int bubble(int lotto[],int num) {	//�������� �����Լ�
	int temp,i,j;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j <num; j++)
		{
			if (lotto[j] > lotto[j + 1])
			{
				temp = lotto[j];
				lotto[j] = lotto[j + 1];
				lotto[j + 1] = temp;
			}
		}
	}
}

int main() {

	int arr[45];
	int lastnum[6],adnum[12]; //��ȸ�� ��÷��ȣ, ������
	int lotto[6];	//�̹��� �����ȣ
	int i,evencnt=0,oddcnt=0;
	int rannum,token=0;
	srand(time(NULL));

	for (i = 0; i < 45; i++)
	arr[i] = i + 1;

	lotto[0] = 12;	//������ȣ :�ִٺ���
	arr[11] = 0;

	for (i = 0; i < 6; i++) { 
		scanf("%d", &lastnum[i]);	//��ȸ�� ��ȣ�Է�(������������ �Է�)

		if (lastnum[i] == 1) {
			adnum[i * 2] = 0;
			adnum[i * 2 + 1] = 2;
		}

		else if (lastnum[i] == 45) {
			adnum[i * 2] = 44;
			adnum[i * 2 + 1] = 0;
		}

		else {
			if (lastnum[i] - 1 == lotto[0])		//�������� ���� ��� ����
				adnum[i * 2] = 0;
			else
			adnum[i * 2] = lastnum[i] - 1;	//������ ���ϱ�		
			
			if (lastnum[i] + 1 == lotto[0])
				adnum[i * 2+1] = 0;
			else
			adnum[i * 2 + 1] = lastnum[i] + 1;

			if (i!=0 && adnum[i * 2 - 1] > adnum[i * 2]) {	//��ȸ�� ��ȣ�� ���� ��� ����
				adnum[i * 2 - 1] = adnum[i * 2] = 0;
			}
		}
		arr[lastnum[i] - 1] = 0;	//��ȸ�� ��ȣ����
	}

	for(i=0;i<12;i++)
	printf("%d\t", adnum[i]);
	printf(": ������\n\n");
	
	do {
		lotto[1] = adnum[rand() % 12]; //������ �� ���� ����
		lotto[2] = adnum[rand() % 12];	
	} while (lotto[1]==0 || lotto[2]==0 || lotto[1] == lotto[2]); //�ߺ�����

	for (i = 0; i < 12; i++) {	//����������
		if(adnum[i]!=0)
			arr[adnum[i] - 1] = 0;
	}								

	for(i=0;i<45;i++)
	printf(" %d\t", arr[i]);	//���� ��
	printf(" : ������\n\n");
	

	for (i = 0; i < 3; i++) {
		if (lotto[i] % 2 == 0)
			evencnt++;
		else
			oddcnt++;
	}

	while (token!=3) {

		for (i = 3; i < 6;) {	//Ȧ¦���� ���߱� 3:3

			rannum = rand() % 45;							

			if (arr[rannum] != 0 && arr[rannum]!=lotto[i-1]) {	//�ߺ�����

				if (arr[rannum] % 2 == 0 && evencnt < 3) {
					lotto[i] = arr[rannum];
					evencnt++;
					i++;
				}
				else if (arr[rannum] % 2 == 1 && oddcnt < 3) {
					lotto[i] = arr[rannum];
					oddcnt++;
					i++;
				}
			}
		}
	
		bubble(lotto, i-1);	//�������� ����

		for (i = 3; i < 6; i++) {
			if (lotto[i - 1] + 1 != lotto[i] || lotto[i] != lotto[i + 1] - 1)	//3�� �̻� ���ӵ� �� ����
				token ++;
		}

	}

		printf("�̹��� �����ȣ\n");
		for(i=0;i<6;i++)
		printf("%d\t", lotto[i]);

	return 0;
}