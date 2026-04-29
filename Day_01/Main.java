import java.util.Scanner;

public class Main {
  public static String determineColor(String s) {
    char file = s.charAt(0); // column (a-h)
    int rank = s.charAt(1) - '0'; // row (1-8)

    int col = file - 'a' + 1;

    // If sum is even -> Black, else White
    if ((col + rank) % 2 == 0) {
      return "Black";
    } else {
      return "White";
    }
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    String s = scanner.nextLine().trim();
    String result = determineColor(s);
    System.out.println(result);
  }
}