import java.util.Arrays;

public class QuickSort3WayPartition {

    private static int low;
    private static int high;

    public static void swap(int[] arr, int a, int b){ //here indexes are passed
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }

    public static void partition(int[] arr, int start, int end){

        int pivotValue = arr[start];
        low = start;
        high = end;

        int i = start;
        while(i <= high) {

            if(arr[i] < pivotValue) {
                swap(arr,low, i);
                low++;
                i++;
            }

            if(arr[i] > pivotValue) {
                swap(arr, high, i);
                high--;
            }

            if(arr[i] == pivotValue)
                i++;
        }
    }

    public static void Sort(int[] arr, int start, int end){
        if(start < end) {

            partition(arr, start, end); // about index the array is partitioned

            Sort(arr, start, low-1);
            Sort(arr, high+1, end);

        }
    }


    public static void main(String[] args) {

        int[] arr = new int[]{7,0,7,8,1,8,9,3,8,8,8,0,7,8,1,8,9,3};

        System.out.println(Arrays.toString(arr));
        Sort(arr,0,arr.length-1);
        System.out.println(Arrays.toString(arr));

    }

}