import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef {
    public static void main(String[] args) throws java.lang.Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        while (T-- > 0) {
            String s = br.readLine();
            int n = s.length();

            // Odd length can never become self-destructing
            if (n % 2 == 1) {
                System.out.println(-1);
                continue;
            }

            int zero = 0, one = 0;
            boolean hasDifferentAdjacent = false;

            for (int i = 0; i < n; i++) {
                if (s.charAt(i) == '0')
                    zero++;
                else
                    one++;

                if (i > 0 && s.charAt(i) != s.charAt(i - 1))
                    hasDifferentAdjacent = true;
            }

            // Already balanced
            if (zero == one) {
                System.out.println(0);
            }
            // No operation possible
            else if (!hasDifferentAdjacent) {
                System.out.println(-1);
            }
            // Minimum operations
            else {
                System.out.println(Math.abs(zero - one) / 2);
            }
        }
    }
}