
class A {

    int a, b, c;

    void add() {
        a = 10;
        b = 20;
        c = a + b;
        System.out.println("Sum of two number" + c);
    }

    void sub() {
        a = 200;
        b = 100;
        c = a - b;
        System.out.println("Sub of two number:" + c);
    }
}

class B extends A {

    void multi() {
        a = 10;
        b = 20;
        c = a + b;
        System.out.println("Multi :" + c);
    }

}
