#include <stdio.h>

/*  ʧ��֮����1

void hill_sort(int arr[], int n) {

	int line = n/2�� ���Ӧ����ѭ������

	int temp;
	int i;
	while (line != 0)  
    {
		for (i = 0; i < n / 2; i++) {

			if (arr[i] > arr[i + line]) {

				temp = arr[i];
				arr[i] = arr[i + line];
				arr[i + line] = temp;

			}
		}
		line/=2��
	}

}*/

void shell_sort(int arr[], int n) {
    int gap, i, j, temp;

    for (gap = n / 2; gap > 0; gap /= 2) //���ѭ�����Ʒ�������������������Ϊ1��������н���һ�β�������
    {

        for (i = gap; i < n; i++) //����������������бȽ� 
        {

            temp = arr[i];  //��¼����һ����
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap )  //�������У�j-=gap�����Ͼ���ֻ������һ�β�������Ϊj��=gap��
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() {
    int arr[] = { 12,2,3,5,16,17,56,32,0 };
    int n = sizeof(arr) / sizeof(arr[0]);

    shell_sort(arr, n);

    printf("Sorted array: \n");

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}