### 一. 介绍

二分查找的相关例题

### 二. 例题模板

```c++
// 查找有序数组中的某一元素x
// 递归二分查找
int binSearch1(int n, int *arr, int low, int high) {
	int ret;
	if (low > high)
		ret = -1;
	int mid = (low + high) / 2;
	if (n == arr[mid]) {
		printf("查找成功：");
		ret = arr[mid];
	} else if (n < arr[mid]) {
		ret = binSearch1(n, arr, low, mid - 1);
	} else {
		ret = binSearch1(n, arr, mid + 1, high);
	} 
    return ret;
}

// 迭代二分查找
int binSearch2(int n, int *arr, int low, int high) {
	while (low <= high) {
		int mid = (low + high) / 2;
		if (n == arr[mid]) {
			printf("查找成功：");
			return arr[mid];
		} else if (n < arr[mid]) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
    printf("查找失败：");
    return -1;
} 

// 查找第一个大于等于x的元素
// 传入的left = 0, right = n而不是n - 1; 具体原因看《算法笔记》
int lowerBound(int *arr, int left, int right, int x) {
	while (left < right) {
		int mid = (left + right) / 2; // int mid = left + (right - left) / 2;
		if (arr[mid] >= x) {
			right = mid;
		} else {
			left = mid + 1;
		}
	}
    return left;
} 

// 查找第一个大于x的元素
int upperBound(int *arr, int left, int right, int x) {
	while (left < right) {
		int mid = (left + right) / 2;
	if (arr[mid] > x) {
		right = mid;
	} else {
		left = mid + 1;
	}
	} 
    return left;
}

// 通用的一个模版
int solve(int *arr, int left, int right, int x) {
	while (left < right) {
		int mid = (left + right) / 2;
		if (/*条件成立*/) {
			right = mid;
		} else {
			left = mid + 1;
		}
	} 
    return left;
}
```

