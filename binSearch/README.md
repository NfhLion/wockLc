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

- 上述代码`int mid = (left + right) / 2 `中的 `left + right`有可能会导致`int`整型溢出，所以我们一般可以使用`int mid = left + (right - left) / 2`来避免溢出。
- 另外，二分法可以使用递归实现，但是大部分程序设计中采用的都是非递归的方法。 
- `right = n而不是n - 1`的原因是：考虑到欲查询元素有可能比序列中的所有元素都大，此时应当返回n（假设它存在应该在的位置），因此二分上届是n。
