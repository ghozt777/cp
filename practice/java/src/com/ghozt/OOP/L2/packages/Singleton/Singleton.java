package com.ghozt.OOP.L2.packages.Singleton;
// a singleton class is a class that allows only one object of its type to be created .

public class Singleton {
    // to make a singleton class make the constructor private so that no one can create more objects
    String g ;
    private Singleton(String g){
        System.out.println("Singleton class constructor called ...");
        this.g = g ;
    }

    private static Singleton instance ;
    public static Singleton getInstance(){
        if(instance == null) instance = new Singleton("singleton") ;
        return instance ;
    }
}
