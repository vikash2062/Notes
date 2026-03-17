class Student {  //super class
    int roll, marks;
    String name;

    void input() {
        System.out.println("Enter roll name & marks");
    }
}

class vikash extends Student { //sub-class
    void disp() {
       
        name = "vikash";
        roll = 1;
        marks = 91;
        System.out.println(roll + "" + name + "" + marks);
    }

    public static void main(String[] args) {  //main class call
        vikash r = new vikash();
        r.input();
        r.disp();
    }
}
