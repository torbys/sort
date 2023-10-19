#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fast_sort(int a[], int n)	//本质是选取一个中间数，使左边都是小于它的数，右边都是大于它的数
{

	if (n < 2) { return; }	//为了递归做跳出处理

	int left = 0;	//设定左下标，可以像指针一样移动

	int right = n - 1;	//设定右下标

	int temp = a[0];	//选取第一个数当作标志数，优化可以在这里

	int judge=2;	//判断每次从哪边开始找

	while (left < right)	//两个指标重合时停止
	{

		if(judge==2)	//从右边开始寻找
		{
			if (a[right] >= temp) { right--; continue; }	//要一直找到一个比标志数小的数

			a[left] = a[right];		//使找到的这个最小的数

			left++;		//左下标从下一位开始，因为从上面可见，该位已经比标志数小了，而left是找比标志数大的

			judge = 1;		//下一次从左边开始找

			continue;	//继续while循环，来判断left和right，如果经移动后已经相等了就结束
		}

		if (judge == 1)		//从左边开始寻找 
		{

			if (a[left] <= temp) { left++; continue; }		

			a[right] = a[left];

			right--;

			judge = 2;

			continue;
		}
	}

	a[left] = temp;		//在最后把两个指标重合的那位，即空出来的那位放入标志数；

	fast_sort(a,left);		//递归1：从已分出的数组左开始再分组

	fast_sort(a+left+1,n-left-1);	//递归2：从已分处的数组右开始再分组，第一个传的是数的开始头

}

/*
		ai写的，本质是将left和right写成参数，而且swap函数好像没有
void quicksort(int a[], int p, int r) {
	if (p < r) {
		int q = partition(a, p, r);
		quicksort(a, p, q - 1);		还是用的递归；
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

	printf("fast sort: "); //时间复杂度最坏O(n^2)，最好o(nlogn);
	for (int i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}