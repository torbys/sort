#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mergesort(int* a, int* atemp, int start, int end);

void merge_sort(int a[], int n) {

	if (n < 2)return;	

	int* atemp = (int*)malloc(n * sizeof(int));		//由于vs不支持c99，所以只能用malloc。

	mergesort(a, atemp, 0, n - 1);		//调用循环函数，主要是需要传入函数头和尾。当然不嫌麻烦也可以在函数体里自己弄
}

void mergesort(int* a, int* atemp, int start, int end) {

	if (start >= end)return;	//判断递归结束条件，一直分到每个组只有一个数就结束

	//进行分组操作，都是每段分成两组有二叉树的感觉
	int mid = start + (end - start) / 2;	//这个是确定怎么划分组内元素个数

	int start1 = start, end1 = mid;		//分出第一组，也是头组，都是以a[0]开头，mid为结尾

	int start2 = mid + 1, end2 = end;	//第二组，也是尾组以a[mid+1]开头，a[n-1]为结尾

	mergesort(a, atemp, start1, end1);	//相当于左节点继续向下分支两个
	mergesort(a, atemp, start2, end2);	//相当于右节点继续向下分支两个

	int i = start;	//做计算器

	while (start1 <= end1 && start2 <= end2)	//即判断两个相邻的数组一方遍历完没有
	{
		atemp[i++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
		//从两个数组的头开始判断，看哪个小就让那个数排到我们的存储数组前面里去，
	}

	while (start1 <= end1)		//继续遍历那个没有遍历完的数组，把它的数组存放到我们的存储数组里
	{
		atemp[i++] = a[start1++];
	}

	while (start2 <= end2)		//同上
	{
		atemp[i++] = a[start2++];
	}

	memcpy(a + start, atemp + start, (end - start + 1) * sizeof(int));	
	//将数组中已排好的数值先放到a中，参数3是说明已排好的数组有多少个，最开始n=0；

}

int main() {

	int arr[] = { 10,456,132,548,1320,52,2,13,56,46,222,153,648 };

	//swap(arr[0], arr[1]);

	int length = sizeof(arr) / sizeof(arr[0]);

	merge_sort(arr, length);

	printf("merge sort: "); //时间复杂度最坏O(n^2)，最好o(nlogn);

	for (int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}