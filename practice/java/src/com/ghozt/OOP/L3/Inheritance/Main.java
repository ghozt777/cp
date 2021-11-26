package com.ghozt.OOP.L3.Inheritance;


public class Main {
    public static void main(String[] args) {
        Person andy = new Person("Andy" , 22) ;
        andy.introduce();
        Programmar jim = new Programmar("Jim" , 31 , "Java") ;
        jim.introduce();
        jim.code() ;
        // this is a funny piece of code :
        Person funny = new Programmar("Funny", 51 , "JavaScript") ; // the object that is created is of the child type and the reference is of the PArten
//        funny.code() ; not accessible
        // it is actually the type of the reference variable that determines which members can be accessed and not the type of the variable
        System.out.println("funny is of " + funny.getClass() + " class"); // even thought it's of the Programmer class we can't access the code method due to the reference variable
        jim.shared() ;
        Programmar copyOfJim = new Programmar(jim) ;
        System.out.println(copyOfJim);
    }
}
