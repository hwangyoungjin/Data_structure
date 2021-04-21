package backjoon.sort;

import java.util.Arrays;

public class MergeSort_BottomUp {
    public static void main(String[] args){
        int[] arr = new int[]{9,87,5,4,1,2,3,47,8};

        System.out.println(Arrays.toString(arr));
        sort(0,arr.length-1,arr);
        System.out.println(Arrays.toString(arr));
    }

    static void sort(int start, int end, int[] arr){


        if(start < end){
            // divide the array into blocks of size `m`
            // m = [1, 2, 4, 8, 16…]
            for (int m = 1; m <= end - start; m = 2*m)
            {
                // for m = 1, i = 0, 2, 4, 6, 8 …
                // for m = 2, i = 0, 4, 8, 12 …
                // for m = 4, i = 0, 8, 16 …
                // …
                for(int i = start; i<end; i+=2*m){
                    int startIdx = i;
                    int mid = i+m-1;
                    int endIdx = Integer.min(i+2*m-1,end);
                    merge(startIdx, mid, endIdx, arr);
                }
            }
        }
    }

    /**
     * Be the Same as recurtion
     */
    static void merge(int start, int mid, int end, int[] arr){

        int[] tem = new int[arr.length];
        int temIdx = start;
        int fs = start;
        int bs = mid+1;

        while(fs <= mid && bs <= end){
            if(arr[fs] < arr[bs]){
                tem[temIdx++] = arr[fs++];
            } else{
                tem[temIdx++] = arr[bs++];
            }
        }

        if(fs > mid){
            for(int i = bs; i<=end; i++){
                tem[temIdx++] = arr[bs++];
            }
        } else {
            for(int i=fs; i<=mid; i++){
                tem[temIdx++] = arr[fs++];
            }
        }

        for(int i=start; i<=end; i++){
            arr[i] = tem[i];
        }
    }

}
