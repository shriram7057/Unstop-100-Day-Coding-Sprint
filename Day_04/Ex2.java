import java.util.Scanner;

public class Main {
  public static String transformString(String s, char ch) {
    int idx = s.lastIndexOf(ch);
    if (idx == -1)
      return s;

    String prefix = s.substring(0, idx);
    String suffix = s.substring(idx);

    StringBuilder sb = new StringBuilder(suffix);
    sb.reverse();

    return prefix + sb.toString();
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    String input = scanner.nextLine();
    String[] data = input.split(" ");
    String s = data[0];
    char ch = data[1].charAt(0);

    String result = transformString(s, ch);
    System.out.println(result);
  }
}