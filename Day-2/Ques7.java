public class Ques7 {
    public static int removeDuplicates(int[] nums) {
        if (nums.length == 0) return 0;

        int k = 1; // Start with the first element as unique
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] != nums[i - 1]) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }

    public static void main(String[] args) {
        int[] nums1 = {1, 1, 2};
        int k1 = removeDuplicates(nums1);
        System.out.println("Output: " + k1 + ", nums = " + java.util.Arrays.toString(nums1));

        int[] nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
        int k2 = removeDuplicates(nums2);
        System.out.println("Output: " + k2 + ", nums = " + java.util.Arrays.toString(nums2));
    }
}