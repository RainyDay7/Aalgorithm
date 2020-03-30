import java.util.List;

public class ReverseListNodeFromHead {

    //k为一个组逆序
    public ListNode reverseKGroup(ListNode head, int k){
        ListNode temp = head;
        for(int i=1; i<k&&temp!=null; i++){
            temp = temp.next;
        }
        //判断节点的数量能否凑成一组
        if(temp == null) return head;
        ListNode t2 = temp.next;
        temp.next = null;
        //把当前的组进行逆序
        ListNode newHead = reverseList(head);
        //把之后的节点分组逆序
        ListNode newTemp = reverseKGroup(t2,k);
        //把两部分连接起来
        head.next = newTemp;
        return newHead;
    }

    public ListNode reverseList(ListNode head) {
        if(head == null || head.next ==null){
            return head;
        }
        ListNode res = reverseList(head.next);
        head.next.next = head;
        head.next = null;
        return res;
    }
}
class ListNode
{
    int val;
    ListNode next;

    public ListNode(int x){
        val=x;
    }

}
