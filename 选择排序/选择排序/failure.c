/*
* ��ֻ��һ������ʧ�ܴ���ĵ���
* 
#include <stdio.h>

void choose_sort(int arr[], int n)

{
	int temp;
	int head;	
	int count;
	int i, j, k;

	for (i = 0; i < n - 1; i++)		//��֪Ϊ�Σ�ѭ��������һ
	{
		head = arr[i];		��һ��ʼ�ͼ�¼����arr[i]��ֵ����Ϊ�˽���

		int guss = 0;		��ͼ������������ж�������ֵû��

		for (j = i; j < n - 1; j++)  //ѭ��������һ�� 
		{	

			if (arr[i] > arr[j + 1])   //����жϵ���ûʲô���� 
			{
				temp = arr[j + 1];		//��Ҫԭ��ֻ�Ǽ�¼�˱�����ֵ��û�м�¼������λ��
										  ͬʱ�����֮����бȽϵĲ��������¼�Ľ�С�ı�����
										  ���ᵼ��ֵ�ļ�¼Ҳ�����ǡ�
				k = j;			
				count = k + 1;		//�������
				guss = 1;
			}

		}
		if (guss == 1) {
			arr[i] = temp;		//��������
			arr[count] = head;
		}
		printf("temp=%d,head=%d\n", temp, head);



	}

}
*/