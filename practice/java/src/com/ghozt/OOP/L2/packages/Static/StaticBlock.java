package com.ghozt.OOP.L2.packages.Static;

import com.ghozt.OOP.L2.packages.Singleton.Singleton;

// this is a program to demonstrate how static variables are initialized using static block :
// once a class is created all the static members are evaluated in order that they are declared
public class StaticBlock {
    static int x = 10 ;
    static int y ;

    static { // this static block in only executed once during the entire lifetime of the class when the class is loaded for the first time
        System.out.println("static block executed ...");
        y = x * 20 ;
    }

    StaticBlock(){
        System.out.println("Constructor called ...");
    }

    public static void main(String[] args) {
        StaticBlock obj = new StaticBlock() ;
        System.out.println(StaticBlock.x + " " + StaticBlock.y);
        StaticBlock.y += 3 ;
        System.out.println(StaticBlock.x + " " + StaticBlock.y);
        new StaticBlock() ;
        new StaticBlock() ;
        new StaticBlock() ;
        System.out.println(StaticBlock.x + " " + StaticBlock.y);
        Singleton obj1 = Singleton.getInstance() ; // gives the same instance to all the objects
        Singleton obj2 = Singleton.getInstance() ;
        Singleton obj3 = Singleton.getInstance() ;
    }
}
