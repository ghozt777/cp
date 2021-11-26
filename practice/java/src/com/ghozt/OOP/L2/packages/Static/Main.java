package com.ghozt.OOP.L2.packages.Static;
// file in the same package don't need to be imported
public class Main {
    public static void main(String[] args) { // we need to use the main method without creating an object of that class
        // and in any Java program the first method to be executed and hence creation of objects of other classes is not possible if we don't execute the
        // main method and this can only be achieved if we make main as static (given we are not creating an object of the class that the main function belong to)
        System.out.println("initial count : " + Shape.count) ; // we can access the static members without reference to any object
        Shape rectangle = new Shape(10 , 12 , "red") ;
        Shape square = new Shape(10 , 10 , "blue") ;
        System.out.println("count: " + Shape.count);
        // and any function that is executed in main also needs to be static
        Main m = new Main() ; // in order to access the nonstatic members we need to create an object first and here the nonstatic member function greeting() belong to the
        // Main class hence first we need to create an object of the class first inorder to access it
        m.greeting();
        fun() ;
        m.fun2() ;
    }
    // something that is not static belong to an object
    void greeting(){
        System.out.println("non static called ...");
    }

    static void fun() {
//        greeting() ; this is not allowed as we can't use a nonstatic method in a static method
//         hence without specifying which instance the greeting() method belongs to we can't use it
//         ...
        new Main().greeting();
    }
    // we can use a non-static method inside a non-static method as we are sure that an object is used to access it
    void fun2(){
        greeting() ; // uses the object used to run fun2
    }
    // also we can't use this inside a static method
    static void testThis(){
//        System.out.println(this.name); not allowed
    }

}
