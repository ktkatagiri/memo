import java.util.Scanner;

public class Main {
    /**
     * @param args
     */
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int c1 = 0;
	int c2 = 0;

	while(sc.hasNext() != false) {
	    String[] s = sc.next().split(",");
	    if (Integer.parseInt(s[0]) == 0) break;
	    int a = Integer.parseInt(s[0]);
	    int b = Integer.parseInt(s[1]);
	    int c = Integer.parseInt(s[2]);

	    if ((a * a + b * b) == c * c) { ++c1; }
	    if (a == b) { ++c2; }
	}
	System.out.println(c1);
	System.out.println(c2);
    }
}
