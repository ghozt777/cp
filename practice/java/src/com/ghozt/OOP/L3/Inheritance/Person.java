package com.ghozt.OOP.L3.Inheritance;

//  Inheritance :
// the class that derives the props from the base class is know as the child class and the class that the child class derives the props from is known as the base class
// the child class inherits props from the base class

// the super keyword has two use cases : 1. to call the base class constructor 2. to access the base class members
public class Person{

    String name ;
    int age ;
    private String secret ;
    String shared = "foo" ; // this member is overriden by the child class

    Person(){
        this("no name" , -1) ; // used to call the second constructor
    }

    Person(String name, int age) {
        super() ; // this calls the Object class as every class is derived from this Object class [HINT: try clicking on it and see its contents]
        this.name = name;
        this.age = age;
    }

    Person(Person twin){
        this.name = twin.name ;
        this.age = twin.age ;
    }

    public void introduce(){
        System.out.println("Hi ! I am " + this.name + " and I am " + this.age + " years old.");
    }
}

