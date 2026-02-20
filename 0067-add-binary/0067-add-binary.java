class Solution {
    public String addBinary(String a, String b) {

        StringBuilder s = new StringBuilder();
        int i = a.length() - 1;
        int j = b.length() - 1;
        int c = 0;

        while(i >= 0 || j >= 0 || c == 1) {

            int sum = c;

            if(i >= 0) 
            sum = sum + a.charAt(i--) - '0';
            if(j >= 0) 
            sum = sum + b.charAt(j--) - '0';

            s.append(sum % 2);
            c = sum / 2;
        }

        return s.reverse().toString();
    }
}