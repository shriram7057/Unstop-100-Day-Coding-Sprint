import java.util.Scanner;

public class Main {
    static final int MOD = 1000000007;
    static int[][] dp;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(); // Length of the permutation
        int K = sc.nextInt(); // Maximum number of elements greater than neighbors

        dp = new int[N + 1][K + 1];

        // Fill the dp table
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= K; j++) {
                if (i == 1 && j == 1) {
                    dp[i][j] = 1;
                    continue;
                }
                // Apply the recurrence relation
                dp[i][j] = (int)((dp[i - 1][j - 1] * 1L * (i - 2 * (j - 1))) % MOD);
                dp[i][j] = (int)((dp[i][j] + 0L + dp[i - 1][j] * 2L * j) % MOD);
            }
        }

        // Calculate the final answer
        int ans = 0;
        for (int i = 1; i <= K; i++) {
            ans = (int)((ans + 0L + dp[N][i]) % MOD);
        }

        System.out.println(ans);
        sc.close();
    }
}