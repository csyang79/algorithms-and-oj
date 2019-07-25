//该返回时一定要返回......
class Solution {
	public double findMedianSortedArrays(int[] nums1, int[] nums2) {
		int total = nums1.length + nums2.length;
		if (total % 2 == 0) {
			return (findKthMax(nums1, 0, nums2, 0, total / 2) + 
					findKthMax(nums1, 0, nums2, 0, total / 2 + 1)) / 2.0;

		} else {
			return findKthMax(nums1, 0, nums2, 0, total / 2 + 1);
		}     
	}
	int findKthMax(final int[] nums1, int start1, final int[] nums2, int start2, int k) {
		//这里少个return报ArrayIndexOutOfBoundsException,样例[2] []
		if (nums1.length - start1 > nums2.length - start2)
			return findKthMax(nums2, start2, nums1, start1, k);
		if (nums1.length - start1 == 0)
			return nums2[start2 + k - 1];
		if (k == 1)
			return Math.min(nums1[start1], nums2[start2]);

		int jump1 = Math.min(nums1.length - start1, k / 2);
		int jump2 = k - jump1;
		if (nums1[start1 + jump1 - 1] < nums2[start2 + jump2 - 1])
			return findKthMax(nums1, start1 + jump1, nums2, start2, k - jump1);
		else if (nums1[start1 + jump1 - 1] > nums2[start2 + jump2 - 1])
			return findKthMax(nums1, start1, nums2, start2 + jump2, k - jump2);
		else
			return nums1[start1 + jump1 - 1];
	}
	/*int findKth(int[] A, int ai,int[] B, int bi, int k )
	  {
	  if ( A.length - ai > B.length - bi )
	  {
	  return(findKth( B, bi, A, ai, k ) );
	  }
	  if ( A.length - ai == 0 )
	  return(B[bi + k - 1]);
	  if ( k == 1 )
	  return(Math.min( A[ai], B[bi] ) );
	  int k1 = Math.min( k / 2, A.length - ai ), k2 = k - k1;
	  if ( A[ai + k1 - 1] < B[bi + k2 - 1] )
	  return(findKth( A, ai + k1, B, bi, k - k1 ) );
	  else if ( A[ai + k1 - 1] > B[bi + k2 - 1] )
	  return(findKth( A, ai, B, bi + k2, k - k2 ) );
	  else
	  return(A[ai + k1 - 1]);
	  }*/
}
