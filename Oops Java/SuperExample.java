// Parent class
class Animal {
    String color = "White";

    Animal() {
        System.out.println("Animal constructor called");
    }

    void sound() {
        System.out.println("Animal makes a sound");
    }
}

// Child class
class Dog extends Animal {
    String color = "Black";

    Dog() {
        super(); // Calls parent class constructor
        System.out.println("Dog constructor called");
    }

    void printColor() {
        System.out.println("Dog color: " + color);
        System.out.println("Animal color: " + super.color); // Access parent class field
    }

    void sound() {
        super.sound(); // Call parent class method
        System.out.println("Dog barks");
    }
}

// Main class
public class SuperExample {
    public static void main(String[] args) {
        Dog d = new Dog();
        d.printColor();
        d.sound();
    }
}
