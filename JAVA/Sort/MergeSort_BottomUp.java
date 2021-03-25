package Sort;

import java.util.Arrays;

public class MergeSortBottomUp {

    static int count;

    //Merge sort Bottom Up implementation (Iterative - Non recursive)
    public static void main(String[] args)
    {
        int[] src = new int[]{27,10,12,20,25,13,15,22};

        System.out.println("before : "+ Arrays.toString(src));
        mergesort(src);
        System.out.println("after : "+ Arrays.toString(src));
    }

    // Merge two sorted subArrays `src[start...mid]` and `src[mid+1 ... end]`
    public static void merge(int[] src, int[] tmp, int start, int mid, int end)
    {
        int front = start, tmpIdx = start, back = mid + 1;

        // loop till no elements are lef in the left and right runts
        while (front <= mid && back <= end)
        {
            if (src[front] < src[back]) {
                tmp[tmpIdx++] = src[front++];
            }
            else {
                tmp[tmpIdx++] = src[back++];
            }
        }

        // copy remaining elements
        if(front > mid){
            for(int i=back; i<=end; i++){
                tmp[tmpIdx++] = src[back++];
            }
        } else{
            for(int i=front; i<=mid; i++){
                tmp[tmpIdx++] = src[front++];
            }
        }

        // copy back to the original array to reflect sorted order
        for (front = start; front <= end; front++) {
            src[front] = tmp[front];
        }
    }

    // Iteratively sort subarray `src[start…end]` using a temporary array
    public static void mergesort(int[] src)
    {
        int start = 0;
        int end = src.length - 1;

        // sort array `src[]` using a temporary array `temp`
        int[] temp = Arrays.copyOf(src, src.length);

        // divide the array into blocks of size `m`
        // m = [1, 2, 4, 8, 16…]
        for (int m = 1; m <= end - start; m = 2*m)
        {
            // for m = 1, i = 0, 2, 4, 6, 8 …
            // for m = 2, i = 0, 4, 8, 12 …
            // for m = 4, i = 0, 8, 16 …
            // …
            for (int i = start; i < end; i += 2*m)
            {
                int startIdx  = i;
                int mid = i + m - 1;
                int endIdx = Integer.min((i + 2*m - 1), end);

                merge(src, temp, startIdx, mid, endIdx);
            }
        }
    }


}
