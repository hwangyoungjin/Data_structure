package Sort;

public class MergeSort_TopDown {
    public static int[] src;
    public static int[] tmp;
    public static int mergeCount;

    public static void main(String[] args) {
        src = new int[]{100,4,8,4,2,3,7,6,4,8};
        tmp = new int[src.length];

        printArray(src);
        mergeSort(0,src.length-1);
        printArray(src);

        System.out.println("mergeCount : "+ mergeCount);
    }

    public static void mergeSort(int start, int end) {
        if(start<end) {
            int mid = (start + end) / 2;
            mergeSort(start, mid);
            mergeSort(mid + 1, end);

            merge(start, mid, end);
        }
    }

    public static void merge(int start,int mid, int end){
        mergeCount++;

        int front = start;
        int back = mid+1;
        int tmpIdx = front;

        while(front <= mid && back <= end) {
            if(src[front] <= src[back]){
                tmp[tmpIdx++] = src[front++];
            } else {
                tmp[tmpIdx++] = src[back++];
            }
        }

        if(front > mid){
            for(int i = back; i<=end; i++){
                tmp[tmpIdx++] = src[back++];
            }
        } else {
            for(int i= front; i<=mid; i++){
                tmp[tmpIdx++] = src[front++];
            }
        }

        for(int i=start; i<=end; i++){
            src[i] = tmp[i];
        }
    }
    public static void printArray(int[] a) {
        for(int i=0; i<a.length; i++){
            System.out.print(a[i]+ " ");
        }
        System.out.println();
    }

}
