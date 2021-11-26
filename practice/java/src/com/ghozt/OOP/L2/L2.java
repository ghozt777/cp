// video link : https://www.youtube.com/watch?v=_Ya6CN13t8k
package com.ghozt.OOP.L2; // name of the package represents the path from the source src -> com -> ghozt -> OOP
// by convention the name of the package is the url of the company in reverse eg: com.ghozt
// packages are containers for classes (can be thought of as a folder)
// packages can be used to separate same named files separated by packages hence prevents name collisions using visibility control
// file in the same package don't need to be imported

import static com.ghozt.OOP.L2.packages.HelloWorld.hello; // importing method using packages
// when importing only the public methods are available

// hence when we say import java.util.ArrayList we actually import the ArrayList file like -> java -> util -> ArrayList

public class L2 {
    public static void main(String[] args) {
        hello() ;
    }
}
