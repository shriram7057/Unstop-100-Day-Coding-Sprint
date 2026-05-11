import java.util.*;

class Main {
  public static boolean userLogic(String bob, String alice) {
    return process(bob).equals(process(alice));
  }

  private static String process(String s) {
    StringBuilder sb = new StringBuilder();

    for (char c : s.toCharArray()) {
      if (c == '#') {
        if (sb.length() > 0) {
          sb.deleteCharAt(sb.length() - 1);
        }
      } else {
        sb.append(c);
      }
    }

    return sb.toString();
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String bob = sc.nextLine();
    String alice = sc.nextLine();
    boolean result = userLogic(bob, alice);
    System.out.println(result ? "YES" : "NO");
  }
}