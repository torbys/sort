#include <stdio.h>

void Insert_sort(int arr[], int length) //本质上是将前面分出一个小数组，然后将后面的数字在这个小数组里比对；
{

	int i,j;
	int temp;
	//int ret;

	for (i = 1; i < length; i++) 
	{

		temp = arr[i];  //进行比对的元素

		for (j = i - 1; j >= 0 && arr[j] > temp; j--)  //从已排序的最右边的数据进行比较，若大于了对比数字就进入循环

		{
			for (j = i-1; j >= 0;j--) //由于已知这个数据比我们的小所以先进行一次交换，交换后再把这个数据和a[j-1]比较 
			{
				if (arr[j] <= temp) break;	//如果这个数已经比我们的数大了，就不用做交换了

				//ret = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
		//arr[j + 1] = temp;    没有必要，不用插入到后面
	}

}


int main() {

	int arr[] = { 6,0,30,32,6 };

	int length = sizeof(arr) / sizeof(arr[0]);

	Insert_sort(arr, length);

	printf("Insert sort: "); //时间复杂度最坏O(n^2)，最好o(n);
	for (int i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}