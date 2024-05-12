def merge(l1, r1, l2, r2):
    if not l1:
        return l2, r2
    if not l2:
        return l1, r1

    start = end = None
    if l1.val <= l2.val:
        start = end = l1
        l1 = l1.next
    else:
        start = end = l2
        l2 = l2.next

    while l1 and l2:
        if l1.val <= l2.val:
            end.next = l1
            end = l1
            l1 = l1.next
        else:
            end.next = l2
            end = l2
            l2 = l2.next

    if l1:
        end.next = l1
        end = r1
    else:
        end.next = l2
        end = r2

    return start, end
