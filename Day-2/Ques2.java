public class Ques2 {
    public static void main(String[] args) {
        int[] nums1 = {2, 2, 1};
        int[] nums2 = {4, 1, 2, 1, 2};
        int[] nums3 = {1};

        System.out.println(singleNumber(nums1)); // Output: 1
        System.out.println(singleNumber(nums2)); // Output: 4
        System.out.println(singleNumber(nums3)); // Output: 1
    }

    public static int singleNumber(int[] nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num;
        }
        return result;
    }
}