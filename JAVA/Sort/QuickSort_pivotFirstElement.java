import java.util.Arrays;


public class QuickSortFirst {
    /**
     * QuickSort 시작
     */
    public static void quickSort(int[] arr){
        sort(arr, 0, arr.length-1);
    }


    /**
     * Divide and conquer
     */
    private static void sort(int[] arr, int low, int high){
        if(low >= high){
            return;
        }

        int q = partition(arr, low, high);
        sort(arr, low, q-1);
        sort(arr, q+1, high);

    }


    /**
     * Pivot은 무조건 arr의 first element 선택으로
     */
    private static int partition(int[] arr, int start, int end) {
        int pivot = arr[start];

        int low = start;
        int high = end+1;

        do {
            do {
                low++;
            }while (arr[low] < pivot && low<end);

            do {
                high--;
            }while (arr[high] > pivot && high > start);

            if(low < high){
                swap(arr, low, high);
            }
        }while(low < high);

        swap(arr,start,high);
        return high;
    }


    private static void swap(int[] arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }


    public static void main(String[] args) {
        /**
         * array size 8,8,9
         */
//        int[] arr = new int[]{1,2,3,4,5,6,7,8};
//        int[] arr = new int[]{8,7,6,5,4,3,2,1};
//        int[] arr = new int[]{5,3,8,4,9,1,6,2,7};
        int[] arr = new int[]{5,3,8,4,7,2,6,1,9};

        System.out.println("Before arr : "+ Arrays.toString(arr));
        quickSort(arr);
        System.out.println("After arr : "+ Arrays.toString(arr));
    }
}
