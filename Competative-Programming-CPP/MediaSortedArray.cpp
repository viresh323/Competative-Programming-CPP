#include "pch.h"
#include "MediaSortedArray.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include "limits.h"
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

	if (nums2.size() < nums1.size()) // Making sure first array is always smaller than other
	{
		return findMedianSortedArrays(nums2, nums1);
	}

	int start = 0;
	int end = nums1.size();
	int total = (nums1.size() + nums2.size() + 1) / 2; // (size1+size2+1)/2 - Constant value used in the Formula to find partitionY = (size1+size2+1)/2 - partitionX; 

	// Binary Search
	while (start <= end) {
		int partitionX = (start + end) / 2;
		int partitionY = total - partitionX;

		int maxLeftX = partitionX == 0 ? INT_MIN : nums1[partitionX - 1]; // Nothing is there on left side
		int minRightX = partitionX == nums1.size() ? INT_MAX : nums1[partitionX]; // Nothing is there on right side

		int maxLeftY = partitionY == 0? INT_MIN : nums2[partitionY - 1]; // Nothing is there on left side
		int minRightY = partitionY == nums2.size() ? INT_MAX : nums2[partitionY]; // Nothing is there on right side

		if (maxLeftX <= minRightY && maxLeftY <= minRightX)
		{
			if ((nums1.size() + nums2.size()) % 2 == 0) { // In case of even length, get the average of maxLeft & minRight
				return (double)(max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2;
			}
			else
			{
				return (double)(max(maxLeftX, maxLeftY));
			}
		}
		else if (maxLeftX > minRightY)
		{
			end = partitionX - 1; // Move left
		}
		else {
			start = partitionX + 1; // Move right
		}

	}
}
void MediaSortedArray::Execute()
{
	vector<int> nums1({1,2});
	vector<int> nums2({3,4});
	cout << findMedianSortedArrays(nums1, nums2);
}
