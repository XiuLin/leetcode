# leetcode
33. Search in Rotated Sorted Array
## 结题思路：

题目要求在一个升序数组中以O(log n)的时间复杂度找到目标数字的索引，如果不存在则返回-1。但是这个数组是被折叠的，就是从正常升序的数组的第一个位置起到某一位置，这段升序子数组被移动到后面。

eg:
org: {1,2,3,4,5,6,7,8,9}
new:{5,6,7,8,9,1,2,3,4}


既然题目要求事件复杂度是O(log n) 而目标数组又算是有序升序数组，那么用二分查找方法就是结题的思路。

二分查找的核心就是每次找到待查的子数组的中轴线，以此为基准查看mid索引对应的值是否是与之相等，不相等怎么处理。ok开始我们的递归查询，我们需要一个起始索引（begin），一个终点索引（end）。

既然是递归，那么就要考虑好返回的情况。
当这么几种情况需要返回最后的结果。
case 1
begin >= end && nums[begin] != target  --->  return -1

case 2
nums[begin] == target    --->  return begin

case 3
int mid = (end-begin)/2+begin;   target == nums[mid]    --->  return mid

case 4
begin == mid && target == nums[end]  --->  return end

case 5
begin == mid && target != nums[end]  --->  -1


OK 这几种返回结果考虑清楚后 我们就开始各种case的递归，不同的case区别就是传入的begin和end不同
当

nums[begin] > target && nums[mid] > target 和 nums[begin] < target && nums[mid] < target
这两种情况下不光需要考虑一边的情况，即--mid to end--  or --begin to mid--如果一边返回-1那么另一半可能存在目标值。


nums[begin] > target && nums[mid] < target 和 nums[begin] < target && nums[mid] > target 就只需要考虑一半就好了。

