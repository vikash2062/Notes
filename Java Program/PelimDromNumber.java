
import java.util.Scanner;

public class PelimDromNumber {
    public static void main(String[] args) {

    int n,c,r,s=0;
  


    System.out.println("Enter your number");
    Scanner ref=new  Scanner(System.in);
    n=ref.nextInt();

    c=n;

    while(n>0)
    {
        r=n%10;
        s=(s*10)+r;
        n=n/10;
    }
    if(c==s)
    System.out.println("Palimdrom Number");

    else
    System.out.println("Not Palimdron Number");

    }
}
