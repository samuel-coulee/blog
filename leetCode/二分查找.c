第一个，最基本的二分查找算法：
因为我们初始化 right = nums.length - 1
所以决定了我们的「搜索区间」是 [left, right]
所以决定了 while (left <= right)
同时也决定了 left = mid+1 和 right = mid-1
因为我们只需找到一个 target 的索引即可
所以当 nums[mid] == target 时可以立即返回

int binarySearch(int[] nums, int target) {
	int left = 0;
	int right = nums.length - 1; // 注意
	while(left <= right) {
		int mid = (right + left) / 2;
		if(nums[mid] == target)
			return mid;
		else if (nums[mid] < target)
			left = mid + 1; // 注意
		else if (nums[mid] > target)
			right = mid - 1; // 注意
	}
	return -1;
}


第二个，寻找左侧边界的二分查找：
因为我们初始化 right = nums.length
所以决定了我们的「搜索区间」是 [left, right)
所以决定了 while (left < right)
同时也决定了 left = mid + 1 和 right = mid
因为我们需找到 target 的最左侧索引
所以当 nums[mid] == target 时不要立即返回
而是要收紧右侧边界以锁定左侧边界

int left_bound(int[] nums, int target) {
	if (nums.length == 0) return -1;
	int left = 0;
	int right = nums.length; // 注意
	while (left < right) { // 注意
		int mid = (left + right) / 2;
		if (nums[mid] == target) {
			right = mid;
		} else if (nums[mid] < target) {
			left = mid + 1;
		} else if (nums[mid] > target) {
			right = mid; // 注意
		}
	}
	return left;
}


第三个，寻找右侧边界的二分查找：
因为我们初始化 right = nums.length
所以决定了我们的「搜索区间」是 [left, right)
所以决定了 while (left < right)
同时也决定了 left = mid + 1 和 right = mid
因为我们需找到 target 的最右侧索引
所以当 nums[mid] == target 时不要立即返回
而是要收紧左侧边界以锁定右侧边界
又因为收紧左侧边界时必须 left = mid + 1
所以最后无论返回 left 还是 right，必须减一.

int right_bound(int[] nums, int target) {
	if (nums.length == 0) return -1;
	int left = 0, right = nums.length;
	while (left < right) {
		int mid = (left + right) / 2;
		if (nums[mid] == target) {
			left = mid + 1; // 注意
		} else if (nums[mid] < target) {
			left = mid + 1;
		} else if (nums[mid] > target) {
			right = mid;
		}
	}
	return left - 1; // 注意
}
