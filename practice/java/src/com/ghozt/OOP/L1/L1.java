// video link : https://www.youtube.com/watch?v=BSVKUk58K6U&list=PL9gnSGHSqcno1G3XjUbwzXHL8_EttOuKk
package com.ghozt.OOP.L1;
import java.util.Arrays;

// create abstract data types:
// a class is a named group of properties and functions
// In real life the class signifies the template and the physical manifestations of that class are the instances i.e the objects
// Class : Logical Construct
// Object : Physical Reality
// default values of non-primitive data types is null
class Student {
    int roll = -1;
    String name = "not assigned(-v Default)";
    float marks = 0.00f;

    Student(Student other) {
        this.name = other.name + " (shared from roll: " + other.roll + ")";
    }

    Student() {
        // this is the way to call a constructor from another constructor
        this(-1, "not assigned(-v Constructor)", 0.00f);
    }

    Student(int roll, String name, float marks) { // parameterized constructor
        // the this keyword replaces the reference of the current object
        this.roll = roll;
        this.name = name;
        this.marks = marks;
    }

    public void details() {
        System.out.println("Student Record:");
        System.out.println("-----------------");
        System.out.println("Name : " + name);
        System.out.println("Roll Number : " + roll);
        System.out.println("Marks : " + marks);
        System.out.println("-----------------");
    }

}

class MyArray {
    static int[] arr;

    MyArray(int[] arr) {
        this.arr = arr;
    }

    public void mergeSort() {
        utilMergeSort(arr, 0, arr.length - 1);
    }

    private void utilMergeSort(int[] arr, int start, int end) {
        if (start >= end)
            return;
        int mid = start + (end - start) / 2;
        utilMergeSort(arr, start, mid);
        utilMergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }

    private void merge(int[] arr, int start, int mid, int end) {
        int i = start;
        int k = start;
        int j = mid + 1;
        int[] temp = new int[arr.length];
        while (i <= mid && j <= end) {
            if (arr[i] <= arr[j])
                temp[k++] = arr[i++];
            else
                temp[k++] = arr[j++];
        }
        while (i <= mid)
            temp[k++] = arr[i++];
        while (j <= end)
            temp[k++] = arr[j++];
        for (k = start; k <= end; k++)
            arr[k] = temp[k];
    }

    public void bubbleSort() {
        for (int i = 0; i < this.arr.length; i++) {
            boolean f = false;
            for (int j = 0; j < this.arr.length - i - 1; j++) {
                if (this.arr[j] > this.arr[j + 1]) {
                    int temp = this.arr[j];
                    this.arr[j] = this.arr[j + 1];
                    this.arr[j + 1] = temp;
                    f = true;
                }
            }
            if (!f)
                break;
        }
    }

    public void insertionSort() {
        for (int i = 1; i < this.arr.length; i++) {
            for (int j = i; j > 0; j--) {
                if (this.arr[j] < this.arr[j - 1]) {
                    int temp = this.arr[j - 1];
                    this.arr[j - 1] = this.arr[j];
                    this.arr[j] = temp;
                } else
                    break;
            }
        }
    }

    public void quickSort() {
        utilQuickSort(this.arr, 0, this.arr.length - 1);
    }

    private void utilQuickSort(int[] arr, int start, int end) {
        if (start >= end || start < 0 || end > arr.length - 1)
            return;
        int pi = partitioner(arr, start, end);
        utilQuickSort(arr, start, pi - 1);
        utilQuickSort(arr, pi + 1, end);
    }

    private int partitioner(int[] arr, int start, int end) {
        int pi = start;
        int pivot = arr[end];
        for (int i = start; i < end; i++) {
            if (arr[i] <= pivot) {
                int temp = arr[pi];
                arr[pi++] = arr[i];
                arr[i] = temp;
            }
        }
        int temp = arr[pi];
        arr[pi] = pivot;
        arr[end] = temp;
        return pi;
    }

    public void printArray() {
        System.out.println(Arrays.toString(this.arr));
    }

    public void printArray(String message) {
        System.out.println(message + " " + Arrays.toString(this.arr));
    }

    // depreciated
    @Override
    protected void finalize() throws Throwable {
        System.out.println("Object Destroyed 💣");
    }
}
public class L1 {
    public static void main(String[] args) {
        Student newKid = new Student(69, "ghozt", 87.4f);
        newKid.details();

        Student _default = new Student();
        _default.details();

        Student shareName = new Student(newKid);
        shareName.details();

        System.out.println();

        MyArray arr = new MyArray(new int[] { 5, 4, 3, 2, 1 }); // the new operator dynamically allocates memory at
        // runtime and then returns a reference of the newly
        // created object
        arr.printArray();
        arr.mergeSort();
        arr.printArray("Sorted(Merge Sort):");

        System.out.println();

        MyArray arr1 = new MyArray(new int[] { -6, 3, -9, 0, 0, 1, 5, 3, -10 });
        arr1.printArray();
        arr1.bubbleSort();
        arr1.printArray("Sorted(Bubble Sort):");

        System.out.println();

        MyArray arr2 = new MyArray(new int[] { 5, 4, 3, 2, 1, 0, -5, -3, -1, -2 });
        arr1.printArray();
        arr2.insertionSort();
        arr2.printArray("Sorted(Insertion Sort):");

        System.out.println();

        MyArray arr3 = new MyArray(new int[] { 10, 4, 3, 2, 3, 0, -79, 3, 0, 69 });
        arr3.printArray();
        arr3.quickSort();
        arr3.printArray("Sorted(Quick Sort):");

        System.out.println();

        MyArray copyOfArr2 = arr2; // NOTE: this does not create a copy of arr2 rather creates a copy of the
        // reference variable
        copyOfArr2.printArray("Copy of arr2:");

        // Wrapper Class :
        int a = 10;
        Integer wa = 10;
        String str = wa.toString();
        System.out.println(wa.byteValue());
        int a1 = 10;
        int a2 = 20;
        System.out.println("OG: " + "a: " + a + " b: " + a1);
        swapInt(a1, a2); // this won't work as int is of primitive type and hence is passed by value and
        // thus wont affect the original values
        System.out.println("Swapped: " + "a: " + a1 + " b: " + a2);
        Integer b1 = 10;
        Integer b2 = 20;
        System.out.println("OG: " + "a: " + b1 + " b: " + b2);
        swapInt(b1, b2); // this will also not work even when Integer being a wrapper class creates
        // objects as instances and hence passing by value for object copies their
        // reference
        // Reason for it to not work : Integer is a 'final' class
        System.out.println("Swapped: " + "a: " + b1 + " b: " + b2);

        final float g = 9.8f;
        // g = 11 ; this is not allowed as it is a final variable and hence its value
        // cant change after initialization
        // ++g ; not allowed
        // final int test ; this is also not allowed as final variables need to be
        // initialized at the same time they are created
        // test = 10 ;

        // final for non primitive data types:
        final Student foo = new Student();
        foo.marks = 90.2f; // allowed
        ++foo.marks;
        // foo = new Student() this is not allowed : hence for non primitive data types
        // having a final object you cant change the reference

        // Garbage collection and finalize()

        // Java doesn't support destructors but lets you specify what to do when the
        // object gets destroyed
        // hence you don't have control of when but what

        // MyArray test ;
        // for(int i = 0 ; i < 10000 ; i++) test = new MyArray(new int[] {0}) ;
        // since test can only store one reference at a time whenever the reference gets
        // updated the old object gets garbage collected
        // NOTE : for smaller number of objects this wont work

        // for(int i = 0 ; i <= 999999999 ; i++) test = new MyArray(new int[] {0}) ; //
        // <- this will work
    }

    static void swapInt(Integer a, Integer b) {
        Integer temp = a;
        a = b;
        b = temp;
    }

    static void swapInt(int a, int b) {
        int temp = a;
        a = b;
        b = temp;
    }
}


