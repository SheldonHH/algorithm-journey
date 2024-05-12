public static void morris(Node head){
    if (head == null){
        return;
    }
    Node cur = head;
    Node MR = null;
    while (cur != null){
        // 判断是否有左树
        MR = cur.left;
        //有左树，流程一
        if (MR != null){ // 有左树的情况下
            // 找到cur左树上，真实的最右侧节点
            // 最右侧节点的右指针 ≠ 空 也 ≠ cur 就出来
            while (MR.right != null && MR.right != cur){
                MR = MR.right;
            }
            // 从while出来，MR一定是cur左树上的最右侧节点
            if (MR.right == null){
                MR.right = cur;
                cur = cur.left;
                continue;
            } else { //🔥一定会等于cur
                MR.right = null;
            }
        }
        cur = cur.right;

    }
}