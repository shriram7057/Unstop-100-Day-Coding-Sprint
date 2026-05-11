import java.util.Scanner;

public class Main {
    public static float water_jug(float X, int i, int j) {
        if (X == 0) return 0.0f; // No water means all bottles are empty.

        // 2D array to store water in each bottle
        double[][] dp = new double[i + 1][i + 1]; 
        dp[1][1] = X; // Pour all water into the topmost bottle

        // Iterate over each row
        for (int row = 1; row < i; row++) {
            for (int col = 1; col <= row; col++) {
                if (dp[row][col] > 1.0) { // If bottle overflows
                    double excess = dp[row][col] - 1.0;
                    dp[row][col] = 1.0; // Max capacity is 1 liter
                    
                    // Distribute excess water equally to the two bottles below
                    dp[row + 1][col] += excess / 2.0;
                    dp[row + 1][col + 1] += excess / 2.0;
                }
            }
        }
        
        // Return the water in the requested bottle with six decimal places
        return (float) Math.min(1.0, dp[i][j]); 
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int i = scanner.nextInt();
        int j = scanner.nextInt();
        float X = scanner.nextFloat();
        scanner.close();

        float result = water_jug(X, i, j);
        System.out.printf("%.6f", result);
    }
}