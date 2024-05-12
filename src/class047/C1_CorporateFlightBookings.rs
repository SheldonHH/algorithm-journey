fn corp_flight_bookings(bookings: Vec<Vec<i32>>, n: usize) -> Vec<i32> {
    let mut cnt = vec![0; n + 2];
    for book in &bookings {
        cnt[book[0] as usize] += book[2];
        cnt[book[1] as usize + 1] -= book[2];
    }
    
    for i in 1..cnt.len() {
        cnt[i] += cnt[i - 1];
    }
    
    cnt[1..=n].to_vec()
}
