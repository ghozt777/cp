package LinkedLists;
import java.util.Arrays ;
import java.util.ArrayList ;


public class LinkedLists {
    public static void main(String[] args) {
        // Arrays :
        int[] arr  = {1,2,3,4} ;
        // similar to vectors in c++
        ArrayList<Integer> arrL = new ArrayList<>(5) ;
    }
}

/*
	Notes :

	Problems associated with array data structure :
	Arrays store all of its elements as a contagious memory block whereas a Linked Lists stores its elements in random order
	Arrays and Lined Lists are the biggest competitors of each other

	Now the potential problems with arrays :
	1. We need to preallocate the space
	2. The problem with vectors is that during insertion if its reaches its size then it needs to create a new array with double its size and then copy all its elements to the newly created one which takes O(n)
	Therefore in some cases it may take O(n) time for insertion(for vectors).
	3. Insertion / Deletion in the middle is costly
	4. Implementation of Data Structures like Queue and Deque is complex using arrays

*/
