#include <stdio.h>

void select_sort(int arr[], int n)
{
	int count;
	int temp; 

	int i, j;

	for (i=0; i < n ; i++)  //遍历整个数组，目的是让起始的a[i]不断向后移动一位
	{

		count = i;	//用count记录i值进行计算，即假设a[count]是最小值
		
		for ( j=i+1; j < n ; j++) //内层循环控制的比较量，即找a[i]后面的所有数和a[count]比较 
		{
			
			if (arr[count] > arr[j]) { //如果a[j]比a[count]小，则令a[j]为最小值再向后比较
				count = j;
			}
		}
		if (count != i) { //判断count移动没有，如果没有即是正序，如果有则需要交换

			//因为我们是将最小值都移动到最前面，所以我们需要存储的是a[i]的值
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