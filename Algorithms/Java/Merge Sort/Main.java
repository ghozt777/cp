import java.util.Arrays;
class Main{
    public static void main(String[] args) {
        int[] arr = {-99 , 69 , 104, 1 , 0 , 0, 0, 2};
        mergeSort(arr);
        System.out.println(Arrays.toString(arr));
    }
    static void mergeSort(int[] arr){
        helper(arr , 0 , arr.length - 1);
    }
    static void helper(int[] arr , int start , int end){
        if(start == end) return ;
        int mid = start + (end-start) / 2;
        helper(arr , start , mid);
        helper(arr , mid+1 , end);
        merge(arr , start , mid , end);
    }
    static void merge(int[] arr  , int start , int mid ,  int end){
        int i = start; // represents the start of the left array 
        int j  = mid + 1; // represents the start of the right array
        int k = start; // represents the total number of elements merged 
        int[] temp = new int[arr.length]; // used to store the elements in the correct position and then put them in their correct position in the array
        while(i <= mid && j <= end){ 
            if(arr[i] <= arr[j]) temp[k++] = arr[i++];
            else temp[k++] = arr[j++];
        }
        while(i <= mid) // to insert the remaining elements from the left array
            temp[k++] = arr[i++];  // any one if these while loops execute at once
        while(j <= end) // to insert the remaining elements from the right array
            temp[k++] = arr[j++];
        for(k = start ; k <= end ; k++) // insert into the original array
            arr[k] = temp[k];
    }
}