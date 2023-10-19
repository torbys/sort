#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fast_sort(int a[], int n)	//������ѡȡһ���м�����ʹ��߶���С�����������ұ߶��Ǵ���������
{

	if (n < 2) { return; }	//Ϊ�˵ݹ�����������

	int left = 0;	//�趨���±꣬������ָ��һ���ƶ�

	int right = n - 1;	//�趨���±�

	int temp = a[0];	//ѡȡ��һ����������־�����Ż�����������

	int judge=2;	//�ж�ÿ�δ��ı߿�ʼ��

	while (left < right)	//����ָ���غ�ʱֹͣ
	{

		if(judge==2)	//���ұ߿�ʼѰ��
		{
			if (a[right] >= temp) { right--; continue; }	//Ҫһֱ�ҵ�һ���ȱ�־��С����

			a[left] = a[right];		//ʹ�ҵ��������С����

			left++;		//���±����һλ��ʼ����Ϊ������ɼ�����λ�Ѿ��ȱ�־��С�ˣ���left���ұȱ�־�����

			judge = 1;		//��һ�δ���߿�ʼ��

			continue;	//����whileѭ�������ж�left��right��������ƶ����Ѿ�����˾ͽ���
		}

		if (judge == 1)		//����߿�ʼѰ�� 
		{

			if (a[left] <= temp) { left++; continue; }		

			a[right] = a[left];

			right--;

			judge = 2;

			continue;
		}
	}

	a[left] = temp;		//����������ָ���غϵ���λ�����ճ�������λ�����־����

	fast_sort(a,left);		//�ݹ�1�����ѷֳ���������ʼ�ٷ���

	fast_sort(a+left+1,n-left-1);	//�ݹ�2�����ѷִ��������ҿ�ʼ�ٷ��飬��һ�����������Ŀ�ʼͷ

}

/*
		aiд�ģ������ǽ�left��rightд�ɲ���������swap��������û��
void quicksort(int a[], int p, int r) {
	if (p < r) {
		int q = partition(a, p, r);
		quicksort(a, p, q - 1);		�����õĵݹ飻
		quicksort(a, q + 1, r);
	}
}

int partition(int a[], int p, int r) {
	int x = a[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (a[j] <= x) {
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[r]);
	return i + 1;
}*/

int main() {

	int arr[] = { 10,456,132,548,1320,52,2,13,56,46,222,153,648};

	//swap(arr[0], arr[1]);

	int length = sizeof(arr) / sizeof(arr[0]);

	//quicksort(arr, arr[0],arr[length-1]);

	fast_sort(arr, length);

	printf("fast sort: "); //ʱ�临�Ӷ��O(n^2)�����o(nlogn);
	for (int i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}