// Base class (Parent class)
class Animal {
    public void speak() {
        System.out.println("Animal makes a sound.");
    }
}

// Subclass Dog (Child class)
class Dog extends Animal {
    @Override // Optional annotation, but good practice
    public void speak() {
        System.out.println("Dog barks: Woof!");
    }
}

// Subclass Cat (Child class)
class Cat extends Animal {
    @Override // Optional annotation, but good practice
    public void speak() {
        System.out.println("Cat meows: Meow!");
    }
}

// Main class to test the code
public class Main {
    public static void main(String[] args) {
        Animal myAnimal = new Animal();
        Dog myDog = new Dog();
        Cat myCat = new Cat();

        myAnimal.speak(); // Output: Animal makes a sound.
        myDog.speak();    // Output: Dog barks: Woof!
        myCat.speak();    // Output: Cat meows: Meow!
    }
}