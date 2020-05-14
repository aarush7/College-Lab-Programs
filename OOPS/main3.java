package com.company;
import java.util.Scanner;

class Circle
{
    double radius,color;
    Circle(){
        radius=0.0;
        color=0.0;
    }
    public Circle(double radius)
    {
        this.radius=radius;
    }
    public Circle(double radius,double color)
    {
        this.radius=radius;
        this.color=color;
    }

    public double getRadius(){

        return radius;
    }
    public double getArea()
    {
        return Math.PI*Math.pow(radius,2.0);
    }
}
    class Cylinder extends Circle
    {
        double height;
        Cylinder(){
            height=0.0;
    }

        Cylinder(double height, double radius){
            this.height=height;
            this.radius=radius;
    }
        Cylinder(double height, double radius,double color)
        {
            this.height=height;
            this.radius=radius;
            this.color=color;

        }
        public double getHeight(){

            return height;
        }
        public double getVolume(){

            return Math.PI*Math.pow(radius,2.0)*height;
        }
        public double getArea(){

            return super.getArea();
        }

    }


public class main3 {
    public static void main(String[] args) {

        Cylinder c1 = new Cylinder(10, 50,3.0);
        Cylinder c2 = new Cylinder(10, 20, 3.0);
        if (c1.getArea() == c2.getArea() && c1.getVolume() == c2.getVolume() && c1.color == c2.color)
            System.out.println("Similar Cylinder");
        else
            System.out.println("Disimilar Cylinder");
    }
}
