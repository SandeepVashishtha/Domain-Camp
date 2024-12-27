import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Ques5 {
    public String makeLargestSpecial(String s) {
        int count = 0, i = 0;
        List<String> res = new ArrayList<>();
        for (int j = 0; j < s.length(); ++j) {
            if (s.charAt(j) == '1') count++;
            else count--;
            if (count == 0) {
                res.add('1' + makeLargestSpecial(s.substring(i + 1, j)) + '0');
                i = j + 1;
            }
        }
        Collections.sort(res, Collections.reverseOrder());
        return String.join("", res);
    }

    public static void main(String[] args) {
        Ques5 solution = new Ques5();
        String s1 = "11011000";
        String s2 = "10";
        System.out.println(solution.makeLargestSpecial(s1));
        System.out.println(solution.makeLargestSpecial(s2));
    }
}