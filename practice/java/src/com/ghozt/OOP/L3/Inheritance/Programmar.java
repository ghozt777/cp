package com.ghozt.OOP.L3.Inheritance;

public class Programmar extends Person {
    String language ;
    String shared = "Foo" ;
    Programmar(String name , int age , String language){
        // since the child class may contain data that relies on the parent class we should call the super method that refers to the parent class constructor first
        // calling it after initializing the child class members will throw an error
        super(name , age) ; // super is used to call the parent class constructor
        // also, if we don't call the super method explicitly there is an implicit call to the default constructor to the base class
        this.language = language ;
        // super(name , age) // this will generate an error as we need to call it before anything
    }
    Programmar(Programmar twin){
        super(twin) ; // the base class constructor takes in a Person type but here we are passing Programmer type hence this  is the same as that mentioned in the Main class
        // since the reference variable is of type Person it will only be able to access the members that are common to the parent class
        // hence it will not be able to access the 'language' member from the child class
        // hence we can pass the child class object to the base class constructor and it will only have access to the common props i.e. the members of the base class
        this.language = twin.language ;
    }
    public void code(){
        System.out.println(this.name + " is coding 👨🏻‍💻 in " + this.language);
    }
    public void tellSecret(String secret){
//        this.secret = secret ; we can't access private members from the parent class in the child class
        System.out.println("secret can't be accessed");
    }
    public void shared(){
        System.out.println("Base class variable : " + super.shared);
        System.out.println("Child class variable : " + this.shared);
    }
}
