#include <stdio.h>

void bubble_sort(int arr[], int n)
{
    int guss = 0;   //�Ż������ж��ǲ����Ѿ�����
    for (int i = 0; i < n - 1; i++) //�趨ÿ��ѭ���������
    {
        printf("%d\n", n-i);//�ж�ѭ������
        for (int j = 0; j < n - i - 1; j++)  //��ʼ��һ�����������
        {

            if (arr[j] > arr[j + 1]) //��ʼ��a[0]�Ƚ�,�����ں�һ����������������
            {
                int temp = arr[j];  //��ʱ�������浱ǰֵ
                arr[j] = arr[j + 1];   //�������С�����ָ�ֵ����ǰλ��
                arr[j + 1] = temp;  //������Ľϴ����ƶ�����һ��λ��
                guss = 1;
            }
        }//�ظ�ִ��ֱ�����һ�����ıȽ�
        if (guss == 0) { return; }  //���û�н���֤������ֱ�ӽ���
    }//��һ��ִ����ѭ�����������һ
}

int main() { 
    int arr[] = { 1,1,2,2,3,3,5,2 };
    int length = sizeof(arr) / sizeof(arr[0]);  //�����鳤��

    bubble_sort(arr, length);

    printf("Sorted array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

