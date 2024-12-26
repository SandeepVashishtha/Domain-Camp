public class Ques1 {
    public static int searchNumber(int k, int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == k) {
                return i + 1; // 1-based indexing
            }
        }
        return -1; // k not found in the array
    }

    public static void main(String[] args) {
        int[] arr1 = {9, 7, 16, 16, 4};
        int k1 = 16;
        System.out.println(searchNumber(k1, arr1)); // Output: 3

        int[] arr2 = {1, 22, 57, 47, 34, 18, 66};
        int k2 = 98;
        System.out.println(searchNumber(k2, arr2)); // Output: -1

        int[] arr3 = {1, 22, 57, 47, 34, 9, 66};
        int k3 = 9;
        System.out.println(searchNumber(k3, arr3)); // Output: 6
    }
}