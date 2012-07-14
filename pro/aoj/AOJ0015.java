import java.math.BigInteger;
import java.util.Scanner;

public class AOJ0015 {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int count = sc.nextInt();

	for(int i = 0; i < count; ++i) {
	    BigInteger money = new BigInteger("0");	    
	    BigInteger left = sc.nextBigInteger();
	    BigInteger right = sc.nextBigInteger();

	    money = money.add(left).add(right);
	    System.out.println(money.toString().length() > 80 ?
			       "overflow" : money.toString());
	}
    }
}