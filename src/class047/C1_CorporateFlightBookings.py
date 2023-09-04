def corpFlightBookings(bookings, n):
    cnt = [0] * (n + 2)
    for book in bookings:
        cnt[book[0] - 1] += book[2]
        cnt[book[1]] -= book[2]
        
    for i in range(1, len(cnt)):
        cnt[i] += cnt[i - 1]
        
    return cnt[1:n + 1]
