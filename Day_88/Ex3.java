package Day_88;

public

import java.util.*;

public class Main {
    public static boolean user_logic(List<String> arr1, List<String> arr2) {
        return String.join("", arr1).equals(String.join("", arr2));
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = Integer.parseInt(scanner.nextLine().trim());
        String[] firstLine = scanner.nextLine().trim().split("\\s+");
        if (firstLine.length != n) {
            System.out.println("Invalid input for arr1");
            return;
        }
        List<String> arr1 = Arrays.asList(firstLine);

        int m = Integer.parseInt(scanner.nextLine().trim());
        String[] secondLine = scanner.nextLine().trim().split("\\s+");
        if (secondLine.length != m) {
            System.out.println("Invalid input for arr2");
            return;
        }
        List<String> arr2 = Arrays.asList(secondLine);

        boolean result = user_logic(arr1, arr2);
        System.out.println(result);
    }
}{

}
