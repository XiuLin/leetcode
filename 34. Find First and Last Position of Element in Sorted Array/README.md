# leetcode
33. Search in Rotated Sorted Array
## 结题思路：

题目要求在一个升序数组中以O(log n)的时间复杂度找到目标数字的索引范围。思路就是先二分查找到目标数字，然后以此为分界线往左右 往右二分查找边界线即可。
