def getIntersectionNode(h1, h2):  
    if not h1 or not h2:  
        return None  
    a, b = h1, h2  #a就是长链表
    diff = 0  
    while a.next:  
        a = a.next  
        diff += 1  
    while b.next:  
        b = b.next  
        diff -= 1  
    if a != b:  
        return None  
    # 👆上方确认是否有相交的节点👆 + diff
    

    # 赋值长短链头部
    if diff >= 0:  
        a, b = h1, h2  
    else:  
        a, b = h2, h1  



    #长链表先走差值步，ab相遇点即相交位点+双while
    diff = abs(diff)  
    while diff:  #长链表先走差值步骤
        a = a.next  
        diff -= 1  
    while a != b:  # ab相遇点，跳出while loop，返回相交的位置
        a = a.next  
        b = b.next  
    return a  