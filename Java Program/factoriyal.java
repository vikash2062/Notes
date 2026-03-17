import java.math.BigInteger;

public class factoriyal {
     public static void main(String[] args) {
        for (int i = 1; i <= 50; i++) {
            BigInteger result = BigInteger.ONE;
            for (int j = 2; j <= i; j++) {
                result = result.multiply(BigInteger.valueOf(j));
            }
            System.out.println("Fact " + i + " is " + result);
        }
    }
}
