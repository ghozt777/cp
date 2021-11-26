package com.ghozt.OOP.L2.packages.Static;
// shortcut to create a constructor in intelliJ is to use <command> + n
// props that are common and hence are object independent are known as static props
public class Shape {
    static int count = 0 ;// common to all the shapes
    int height ; // instance variable (different for different instances i.e. object)
    int width ; // instance variable
    String color ;
    public Shape(int height, int width, String color) {
        this.height = height;
        this.width = width;
        this.color = color;
        Shape.count++ ; // to use the static member use the class name
    }
}
