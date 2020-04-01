//有效括号
// 示例1:输入: "(())"输出: true
//实例2：输入: "())("输出: false


//在遍历字符串的过程中，遇到 "(" 就让它入栈，
//（1）如果有，则把处于栈顶的 "("  弹出，相当于和 ")" 进行匹配，然后继续往后遍历字符串
// （2）、如果没有，则匹配失败。相当于字符串的最前面出现了 ")"，显然这是不合理的。
// 遇到 ")" 就判断下栈里面有没有 "(" ：

import java.util.Stack;

//2、当字符串遍历完成，判断栈是否为空，如果为空则表示字符串串有效，否则⽆
public class ValidBrackets {

    public static boolean isValid(String s){
        if(s==null||s.length() <1)return true;
        int n=s.length();// 字符串长度// 创建一个栈来装字符
        Stack<Character> stack=new Stack<>();// 遍历字符串
        for(int i=0; i<n; i++){// 获取字符串的第 i 个字符
             char c=s.charAt(i);
             if(c=='('){
                 stack.push(c);
             }
             else {
                 if (stack.isEmpty()) return false;
                 else stack.pop();
             }
        }
        // 判断是否为空
        if(stack.isEmpty()) return true;
        return  false;
    }

}
