package com.company;
interface Animal{
    void eat();
    void sound();
}
class Lion implements Animal{
    public void eat()
    {
        System.out.println("Carnivore");
    }
    public void sound()
    {
        System.out.println("Roar");
    }
}
class Snake implements Animal{
    public void eat() {
        System.out.println("Swallow");
    }
    public void sound()
    {
        System.out.println("Hiss");
    }

public void display()
{
    System.out.println("Animal is tired after eating");
}}
interface TiredAnimal extends Animal{
    void display();
}

public class main5 {
    public static void main(String[] args) {
        Lion l = new Lion();
        Snake s = new Snake();
        l.eat();
        l.sound();
        s.eat();
        s.sound();
        s.display();
    }
}