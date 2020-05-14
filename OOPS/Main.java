package com.company;
import java.util.Scanner;
class complex{
    float real[]=new float[2];
    float imaginary[]=new float[2];
    print p=new print();

    complex(float a,float b,float c,float d)
    {
        real[0]=a;
        real[1]=c;
        imaginary[0]=b;
        imaginary[1]=d;

        add(a,b,c,d);
        sub(a,b,c,d);


    }

    void add(float r1,float i1,float r2,float i2)
    {
        float rer=r1+r2;
        float rei=i1+i2;
        p.display(rer,rei);
    }
    void sub(float r1,float i1,float r2,float i2)
    {
        float rer=r1-r2;
        float rei=i1-i2;
        p.display(rer,rei);
    }


}
class print{
    void display(float a,float b)
    {
        System.out.println("Result "+a+"+"+b+"i");
    }
}
class input{
    void get(){
        Scanner s1=new Scanner(System.in);
        System.out.println("Enter the first real and imaginary part");
        float a=s1.nextFloat();
        float b=s1.nextFloat();

        System.out.println("Enter the second real and imaginary part");
        float c=s1.nextFloat();
        float d=s1.nextFloat();
        complex ct=new complex(a,b,c,d);
    }
}
public class Main {

    public static void main(String[] args) {

        input g=new input();
        g.get();

         /*
        ct.add(a,b,c,d);
        ct.sub(a,b,c,d);*/


    }
}