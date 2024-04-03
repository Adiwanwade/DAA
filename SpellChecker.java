import java.util.Scanner;

public class SpellChecker {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the word to check for spelling errors:");
        String str = sc.nextLine();
        System.out.println("Enter the correct string to check with :");
        String str2 = sc.nextLine();
        System.out.println("Minimum number of edits required are :" +
                spellcheck(str, str2));
        sc.close();
    }

    public static int spellcheck(String s, String t) {
        int lenS = s.length();
        int lenT = t.length();
        if (lenS == 0) {
            return lenT;
        }
        if (lenT == 0) {
            return lenS;
        }
        int[][] dp = new int[lenS + 1][lenT + 1];
        for (int i = 0; i <= lenS; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= lenT; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= lenS; i++) {
            for (int j = 1; j <= lenT; j++) {

                if (s.charAt(i - 1) == t.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + Math.min(Math.min(dp[i - 1][j], dp[i][j -

                            1]), dp[i - 1][j - 1]);
                }
            }
        }
        return dp[lenS][lenT];
    }
}
