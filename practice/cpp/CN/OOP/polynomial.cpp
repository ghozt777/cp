/* C++ implementation to convert infix expression to postfix*/
// Note that here we use std::stack  for Stack operations
#include <vector>
#include <climits>
#include <iostream>
using namespace std;

// class Polynomial
// {

// public:
//     int *degCoeff; // Name of your array (Don't change this)
//     int size;

//     Polynomial()
//     {
//         this->size = 9;
//         this->degCoeff = new int[10];
//         for (int i = 0; i < this->size; i++)
//             this->degCoeff[i] = 0;
//         return;
//     }

//     Polynomial(Polynomial const &p)
//     {
//         this->degCoeff = new int[p.size + 1];
//         this->size = p.size;
//         for (int i = 0; i <= p.size; i++)
//             this->degCoeff[i] = p.degCoeff[i];
//     }

//     void setCoefficient(int deg, int coeff)
//     {
//         if (deg > this->size)
//         {
//             int *newArr = new int[2 * this->size + 1];
//             for (int i = 0; i <= this->size; i++)
//                 newArr[i] = this->degCoeff[i];
//             for (int i = this->size + 1; i <= 2 * this->size; i++)
//                 newArr[i] = 0;
//             this->degCoeff = newArr;
//             this->size = 2 * this->size;
//             setCoefficient(deg, coeff);
//         }
//         this->degCoeff[deg] = coeff;
//         return;
//     }

//     void print()
//     {
//         for (int i = 0; i < this->size; i++)
//             if (this->degCoeff[i] != 0)
//                 cout << this->degCoeff[i] << "x" << i << " ";
//         cout << endl;
//         return;
//     }

//     Polynomial operator=(Polynomial const &p)
//     {
//         Polynomial newP(p);
//         return newP;
//     }

//     Polynomial operator+(Polynomial const &p)
//     {
//         Polynomial newP;
//         int n = max(p.size, this->size);
//         int *arr = new int[n];
//         for (int i = 0; i < n; i++)
//         {
//             if (i < this->size && i < p.size)
//                 newP.setCoefficient(i, this->degCoeff[i] + p.degCoeff[i]);
//             else if (i <= this->size)
//                 newP.setCoefficient(i, p.degCoeff[i]);
//             else
//                 newP.setCoefficient(i, this->degCoeff[i]);
//         }
//         return newP;
//     }

//     Polynomial operator*(Polynomial p)
//     {
//         Polynomial newP;
//         for (int i = 0; i <= this->size; i++)
//         {
//             if (this->degCoeff[i] != 0)
//             {
//                 for (int j = 0; j <= p.size; j++)
//                 {
//                     if (p.degCoeff[j] != 0)
//                         newP.degCoeff[i + j] = this->degCoeff[i] * p.degCoeff[j];
//                 }
//             }
//         }
//         return newP;
//     }

//     Polynomial operator-(Polynomial const &p)
//     {
//         Polynomial newP;
//         int n = max(p.size, this->size);
//         int *arr = new int[n];
//         for (int i = 0; i < n; i++)
//         {
//             if (i < this->size && i < p.size)
//                 newP.setCoefficient(i, this->degCoeff[i] - p.degCoeff[i]);
//             else if (i <= this->size)
//                 newP.setCoefficient(i, -p.degCoeff[i]);
//             else
//                 newP.setCoefficient(i, this->degCoeff[i]);
//         }
//         return newP;
//     }
// };

class Polynomial {
    
    public:
    int *degCoeff;      // Name of your array (Don't change this)
    int capacity;
    
    Polynomial(){
        this->degCoeff=new int[6];
        this->capacity=5;
    }
    //Making paramaterized constructor for defining with capacity
    Polynomial (int capacity){
        this->degCoeff=new int[capacity+1];
        this->capacity=capacity;
    }
    
    Polynomial (Polynomial const &p){
        int *newdeg=new int[p.capacity+1];
            
        for(int i=0;i<=p.capacity;i++)
            newdeg[i]=p.degCoeff[i];
            
        this->degCoeff=newdeg;
        
        this->capacity=p.capacity;
    }
    
    void setCoefficient(int deg,int coef){
        if(deg>capacity){
            int newcapacity=deg;
            int *newdeg=new int[newcapacity+1];
            //Copy the contents from original to new
            for(int i=0;i<=capacity;i++)
                newdeg[i]=degCoeff[i];
            
            this->degCoeff=newdeg;
            this->capacity=newcapacity;
            //Set the new coeff;
            degCoeff[deg]=coef;
        }
        else{
            degCoeff[deg]=coef;
        }
    }
    
    Polynomial operator+(Polynomial const &P2){
        
        int newcap=max(this->capacity,P2.capacity);
        
        Polynomial P3(newcap);
        
        for(int i=0;i<=newcap;i++){
            if(i<=capacity && i<=P2.capacity)
                P3.degCoeff[i]=this->degCoeff[i]+P2.degCoeff[i];
            else if(i<=capacity)
                P3.degCoeff[i]=this->degCoeff[i];
            else 
                P3.degCoeff[i]=P2.degCoeff[i];
        }
        
        return P3;
    }
    
    Polynomial operator-(Polynomial const &P2){
        
        int newcap=max(this->capacity,P2.capacity);
        Polynomial P3(newcap);
        
        for(int i=0;i<=newcap;i++){
            if(i<=capacity && i<=P2.capacity)
                P3.degCoeff[i]=this->degCoeff[i]-P2.degCoeff[i];
            else if(i<=capacity)
                P3.degCoeff[i]=this->degCoeff[i];
            else 
                P3.degCoeff[i]=-P2.degCoeff[i];
        }
        
        return P3;
    }
    
    Polynomial operator*(Polynomial const &P2){
        
        int newcap=this->capacity+P2.capacity;
        Polynomial P3(newcap);
        
        for(int i=0;i<=this->capacity;i++){
            
            for(int j=0;j<=P2.capacity;j++){
                P3.degCoeff[i+j]+=this->degCoeff[i]*P2.degCoeff[j];
            }
        }
        return P3;
    }
    
    void operator=(Polynomial const &p){
        int *newdeg=new int[p.capacity+1];
        //Copy the contents
        for(int i=0;i<p.capacity;i++)
            newdeg[i]=p.degCoeff[i];
            
        
        this->degCoeff=newdeg;
        
        this->capacity=p.capacity;
    }
    
    void print(){
        
        for(int i=0;i<=this->capacity;i++){
            if(degCoeff[i]!=0)
                cout<<degCoeff[i]<<"x"<<i<<" ";
        }
        cout<<endl;
    }
           
};



// Driver program to test above functions

int main()
{
    int count1, count2, choice;
    cin >> count1;

    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];

    for (int i = 0; i < count1; i++)
    {
        cin >> degree1[i];
    }

    for (int i = 0; i < count1; i++)
    {
        cin >> coeff1[i];
    }

    Polynomial first;
    for (int i = 0; i < count1; i++)
    {
        first.setCoefficient(degree1[i], coeff1[i]);
    }

    cin >> count2;

    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];

    for (int i = 0; i < count2; i++)
    {
        cin >> degree2[i];
    }

    for (int i = 0; i < count2; i++)
    {
        cin >> coeff2[i];
    }

    Polynomial second;
    for (int i = 0; i < count2; i++)
    {
        second.setCoefficient(degree2[i], coeff2[i]);
    }

    cin >> choice;

    switch (choice)
    {
        // Add
    case 1:
    {
        Polynomial result1 = first + second;
        result1.print();
        break;
    }
        // Subtract
    case 2:
    {
        Polynomial result2 = first - second;
        result2.print();
        break;
    }
        // Multiply
    case 3:
    {
        Polynomial result3 = first * second;
        result3.print();
        break;
    }
    case 4: // Copy constructor
    {
        Polynomial third(first);
        if (third.degCoeff == first.degCoeff)
        {
            cout << "false" << endl;
        }
        else
        {
            cout << "true" << endl;
        }
        break;
    }

    case 5: // Copy assignment operator
    {
        Polynomial fourth(first);
        if (fourth.degCoeff == first.degCoeff)
        {
            cout << "false" << endl;
        }
        else
        {
            cout << "true" << endl;
        }
        break;
    }
    }

    return 0;
}

// int main()
// {
//     Polynomial p1;
//     p1.setCoefficient(1, 1);
//     p1.setCoefficient(3, 2);
//     p1.setCoefficient(5, -4);
//     Polynomial p2;
//     p2.setCoefficient(0, 4);
//     p2.setCoefficient(1, 2);
//     p2.setCoefficient(2, -3);
//     p2.setCoefficient(2, -3);
//     p2.setCoefficient(3, 1);

//     Polynomial p3 = p1 - p2;
//     p1.print();
//     p2.print();
//     p3.print();
//     return 0;
// }