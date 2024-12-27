import java.util.*;

public class Solution {
    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        Map<String, String> emailToName = new HashMap<>();
        Map<String, String> parent = new HashMap<>();
        Map<String, TreeSet<String>> unions = new HashMap<>();

        // Initialize the union-find structure
        for (List<String> account : accounts) {
            String name = account.get(0);
            for (int i = 1; i < account.size(); i++) {
                emailToName.put(account.get(i), name);
                parent.put(account.get(i), account.get(i));
            }
        }

        // Union emails
        for (List<String> account : accounts) {
            String p = find(account.get(1), parent);
            for (int i = 2; i < account.size(); i++) {
                parent.put(find(account.get(i), parent), p);
            }
        }

        // Group emails by their root parent
        for (List<String> account : accounts) {
            String p = find(account.get(1), parent);
            unions.putIfAbsent(p, new TreeSet<>());
            for (int i = 1; i < account.size(); i++) {
                unions.get(p).add(account.get(i));
            }
        }

        // Prepare the result
        List<List<String>> result = new ArrayList<>();
        for (String p : unions.keySet()) {
            List<String> emails = new ArrayList<>(unions.get(p));
            emails.add(0, emailToName.get(p));
            result.add(emails);
        }

        return result;
    }

    private String find(String s, Map<String, String> parent) {
        return parent.get(s).equals(s) ? s : find(parent.get(s), parent);
    }
}