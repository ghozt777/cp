package com.ghozt.OOP.L2.packages.Static;

// outside classes can't be static
// only the inner classes can be static
// static members are resolved during compile time whereas non-static members are resolved during the runtime

public class InnerClasses {
    class InnerClass {
        String str ;

        public InnerClass(String str) {
            this.str = str;
        }
    }

    static class Foo{ // making a class static means that it doesn't depend on any other class irrespective of its location
        String foo ;

        public Foo(String foo) {
            this.foo = foo;
        }

        @Override
        public String toString() {
            return foo ;
        }
    }

    public static void main(String[] args) {
//        InnerClass inner = new InnerClass("foo") ;  // this will create an error as the inner class depends on the outer class and hence we can't use it
//         without an object of the outer class
        Foo foo = new Foo("foo") ; // this is fine as this is a static class and hence doesn't depend on any other class even if its nested inside an outer class
        Foo foofoo = new Foo("foofoo") ;
        System.out.println(foo.foo) ;
        System.out.println(foofoo.foo) ;
        System.out.println(foo);
    }
}
