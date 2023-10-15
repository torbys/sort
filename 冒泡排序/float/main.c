#include <stdio.h>

void bubble_sort(int arr[], int n)
{
    int guss = 0;   //优化处理，判断是不是已经有序
    for (int i = 0; i < n - 1; i++) //设定每次循环的最大数
    {
        printf("%d\n", n-i);//判断循环次数
        for (int j = 0; j < n - i - 1; j++)  //开始从一到最大数遍历
        {

            if (arr[j] > arr[j + 1]) //开始从a[0]比较,若大于后一个数则做调换操作
            {
                int temp = arr[j];  //临时变量保存当前值
                arr[j] = arr[j + 1];   //将后面较小的数字赋值给当前位置
                arr[j + 1] = temp;  //将保存的较大数移动到后一个位置
                guss = 1;
            }
        }//重复执行直到最后一个数的比较
        if (guss == 0) { return; }  //如果没有交换证明有序，直接结束
    }//下一次执行则循环到最大数减一
}

int main() { 
    int arr[] = { 1,1,2,2,3,3,5,2 };
    int length = sizeof(arr) / sizeof(arr[0]);  //算数组长度

    bubble_sort(arr, length);

    printf("Sorted array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

