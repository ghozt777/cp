// in this approach we use two subarrays left and right to merge
import java.util.Arrays;
public class ExtraSpace {
    public static void main(String[] args) {
        int[] arr = {9,-89,-34,12,69,0,0,0,1,3,4};
        System.out.println("OG Array: " + Arrays.toString(arr));
        arr = mergeSort(arr);
        System.out.println("Sorted Array: " + Arrays.toString(arr));
    }
    static int[] mergeSort(int[] arr){
        if(arr.length == 1) return arr;
        int mid = arr.length / 2;
        int[] left = mergeSort(Arrays.copyOfRange(arr, 0, mid));
        int[] right = mergeSort(Arrays.copyOfRange(arr, mid, arr.length));
        return merge(left,right); 
    } 
    static int[] merge(int[] left , int[] right){
        int i = 0 , j = 0 ,k = 0;
        int[] res = new int[left.length + right.length];
        while(i < left.length && j < right.length){
            if(left[i] <= right[j]) res[k++] = left[i++];
            else res[k++] = right[j++];
        }
        while(i < left.length) res[k++] = left[i++];
        while(j < right.length) res[k++] = right[j++];
        return res;
    } 
}
