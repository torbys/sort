#include <stdio.h>

void Insert_sort(int arr[], int length) //�������ǽ�ǰ��ֳ�һ��С���飬Ȼ�󽫺�������������С������ȶԣ�
{

	int i,j;
	int temp;
	//int ret;

	for (i = 1; i < length; i++) 
	{

		temp = arr[i];  //���бȶԵ�Ԫ��

		for (j = i - 1; j >= 0 && arr[j] > temp; j--)  //������������ұߵ����ݽ��бȽϣ��������˶Ա����־ͽ���ѭ��

		{
			for (j = i-1; j >= 0;j--) //������֪������ݱ����ǵ�С�����Ƚ���һ�ν������������ٰ�������ݺ�a[j-1]�Ƚ� 
			{
				if (arr[j] <= temp) break;	//���������Ѿ������ǵ������ˣ��Ͳ�����������

				//ret = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
		//arr[j + 1] = temp;    û�б�Ҫ�����ò��뵽����
	}

}


int main() {

	int arr[] = { 6,0,30,32,6 };

	int length = sizeof(arr) / sizeof(arr[0]);

	Insert_sort(arr, length);

	printf("Insert sort: "); //ʱ�临�Ӷ��O(n^2)�����o(n);
	for (int i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}