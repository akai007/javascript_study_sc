import java.util.Stack;

class Solution {
    public boolean isValid(String s) {
        String L = "({[";
        String R = ")}]";

        Stack<Character> stack = new Stack<Character>();
        char[] sList = s.toCharArray();

        char c;
        for (int i = 0 ; i < sList.length; i++ ) {
            c = sList[i];
            if (L.indexOf(c) >= 0) {
                stack.push(c);
            } else {
                if (!stack.isEmpty() && L.indexOf(stack.get(stack.size()-1)) == R.indexOf(c)) stack.pop();
                else return false;
            }
        }
        return stack.isEmpty();
    }
}