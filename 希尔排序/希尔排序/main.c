#include <stdio.h>

/*  失败之作加1

void hill_sort(int arr[], int n) {

	int line = n/2； 这个应该用循环来做

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
		line/=2；
	}

}*/

void shell_sort(int arr[], int n) {
    int gap, i, j, temp;

    for (gap = n / 2; gap > 0; gap /= 2) //外层循环控制分组量，由于连除最后必为1，会对所有进行一次插入排序
    {

        for (i = gap; i < n; i++) //控制哪两个数组进行比较 
        {

            temp = arr[i];  //记录其中一个数
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap )  //插入排列，j-=gap本质上就是只让你做一次操作，因为j将=gap；
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