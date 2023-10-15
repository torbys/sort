#include <stdio.h>

void select_sort(int arr[], int n)
{
	int count;
	int temp; 

	int i, j;

	for (i=0; i < n ; i++)  //�����������飬Ŀ��������ʼ��a[i]��������ƶ�һλ
	{

		count = i;	//��count��¼iֵ���м��㣬������a[count]����Сֵ
		
		for ( j=i+1; j < n ; j++) //�ڲ�ѭ�����ƵıȽ���������a[i]�������������a[count]�Ƚ� 
		{
			
			if (arr[count] > arr[j]) { //���a[j]��a[count]С������a[j]Ϊ��Сֵ�����Ƚ�
				count = j;
			}
		}
		if (count != i) { //�ж�count�ƶ�û�У����û�м����������������Ҫ����

			//��Ϊ�����ǽ���Сֵ���ƶ�����ǰ�棬����������Ҫ�洢����a[i]��ֵ
			temp = arr[i];		
			arr[i] = arr[count];		
			arr[count] = temp;

		}

	}
	
}


int main() {

	int arr[] = { 5,6,12,3,2 };
	
	int length = sizeof(arr) / sizeof(arr[0]);

	choose_sort(arr, length);

	printf("Select array: ");
	for (int i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");


	return 0;
}