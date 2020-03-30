//把单链表进行一次逆序，逆序之后就能转化为从头部开始组起了，
// 然后按照ReversrListNodeFromHead的解法，处理完之后，
// 把结果再次逆序即搞定。两次逆序相当于没逆

public class ReverseListNodeFromTail {

    public  ListNode reverseLN(ListNode head, int k){
        //先逆序一次
        ReverseListNodeFromHead re = new ReverseListNodeFromHead();
        head = re.reverseList(head);
        head = re.reverseKGroup(head, k);
        head = re.reverseList(head);
        return head;
    }
}
