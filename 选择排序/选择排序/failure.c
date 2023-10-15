/*
* 这只是一个关于失败代码的点评
* 
#include <stdio.h>

void choose_sort(int arr[], int n)

{
	int temp;
	int head;	
	int count;
	int i, j, k;

	for (i = 0; i < n - 1; i++)		//不知为何，循环数少了一
	{
		head = arr[i];		在一开始就记录下了arr[i]的值，是为了交换

		int guss = 0;		试图用这个变量来判断做过变值没有

		for (j = i; j < n - 1; j++)  //循环数少了一个 
		{	

			if (arr[i] > arr[j + 1])   //这个判断倒是没什么问题 
			{
				temp = arr[j + 1];		//主要原因：只是记录了变量的值，没有记录变量的位置
										  同时这代表之后进行比较的不是这个记录的较小的变量；
										  更会导致值的记录也被覆盖。
				k = j;			
				count = k + 1;		//多余操作
				guss = 1;
			}

		}
		if (guss == 1) {
			arr[i] = temp;		//交换正常
			arr[count] = head;
		}
		printf("temp=%d,head=%d\n", temp, head);



	}

}
*/