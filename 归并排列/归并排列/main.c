#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mergesort(int* a, int* atemp, int start, int end);

void merge_sort(int a[], int n) {

	if (n < 2)return;	

	int* atemp = (int*)malloc(n * sizeof(int));		//����vs��֧��c99������ֻ����malloc��

	mergesort(a, atemp, 0, n - 1);		//����ѭ����������Ҫ����Ҫ���뺯��ͷ��β����Ȼ�����鷳Ҳ�����ں��������Լ�Ū
}

void mergesort(int* a, int* atemp, int start, int end) {

	if (start >= end)return;	//�жϵݹ����������һֱ�ֵ�ÿ����ֻ��һ�����ͽ���

	//���з������������ÿ�ηֳ������ж������ĸо�
	int mid = start + (end - start) / 2;	//�����ȷ����ô��������Ԫ�ظ���

	int start1 = start, end1 = mid;		//�ֳ���һ�飬Ҳ��ͷ�飬������a[0]��ͷ��midΪ��β

	int start2 = mid + 1, end2 = end;	//�ڶ��飬Ҳ��β����a[mid+1]��ͷ��a[n-1]Ϊ��β

	mergesort(a, atemp, start1, end1);	//�൱����ڵ�������·�֧����
	mergesort(a, atemp, start2, end2);	//�൱���ҽڵ�������·�֧����

	int i = start;	//��������

	while (start1 <= end1 && start2 <= end2)	//���ж��������ڵ�����һ��������û��
	{
		atemp[i++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
		//�����������ͷ��ʼ�жϣ����ĸ�С�����Ǹ����ŵ����ǵĴ洢����ǰ����ȥ��
	}

	while (start1 <= end1)		//���������Ǹ�û�б���������飬�����������ŵ����ǵĴ洢������
	{
		atemp[i++] = a[start1++];
	}

	while (start2 <= end2)		//ͬ��
	{
		atemp[i++] = a[start2++];
	}

	memcpy(a + start, atemp + start, (end - start + 1) * sizeof(int));	
	//�����������źõ���ֵ�ȷŵ�a�У�����3��˵�����źõ������ж��ٸ����ʼn=0��

}

int main() {

	int arr[] = { 10,456,132,548,1320,52,2,13,56,46,222,153,648 };

	//swap(arr[0], arr[1]);

	int length = sizeof(arr) / sizeof(arr[0]);

	merge_sort(arr, length);

	printf("merge sort: "); //ʱ�临�Ӷ��O(n^2)�����o(nlogn);

	for (int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}