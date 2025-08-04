class Solution {
    public String multiply(String num1, String num2) {

        if(num1.compareTo("0") == 0 || num2.compareTo("0") == 0)
        {
            return "0";
        }
        List<StringBuilder> list = new ArrayList<>();
        int i = 0;

        for (int x = num1.length() - 1; x >= 0; x--) {
            char ch = num1.charAt(x);
            StringBuilder sb = new StringBuilder(func(num2, ch));

            for (int z = 0; z < i; z++) {
                sb.append('0');
            }

            list.add(sb);
            i++;
        }

        String res = list.get(0).toString();
        for (int x = 1; x < list.size(); x++) {
            res = func1(res, list.get(x).toString());
        }

        return res;
    }

    private String func(String str, char ch) {
        int num = ch - '0';
        int carry = 0;
        StringBuilder result = new StringBuilder();

        for (int x = str.length() - 1; x >= 0; x--) {
            int num2 = str.charAt(x) - '0';
            int product = num * num2 + carry;
            result.append(product % 10);
            carry = product / 10;
        }

        if (carry > 0) {
            result.append(carry);
        }

        return result.reverse().toString();
    }

    private String func1(String str1, String str2) {
        int i1 = str1.length() - 1;
        int i2 = str2.length() - 1;
        int carry = 0;
        StringBuilder result = new StringBuilder();

        while (i1 >= 0 || i2 >= 0 || carry != 0) {
            int d1 = i1 >= 0 ? str1.charAt(i1--) - '0' : 0;
            int d2 = i2 >= 0 ? str2.charAt(i2--) - '0' : 0;

            int sum = d1 + d2 + carry;
            result.append(sum % 10);
            carry = sum / 10;
        }

        return result.reverse().toString();
    }
}