fn swap(a: &mut i32, b: &mut i32) {
    let temp = *a;
    *a = *b;
    *b = temp;
}

fn partition(arr: &mut [i32], low: usize, high: usize) -> usize {
    let pivot = arr[high];
    let mut i = low as isize - 1;

    for j in low..high {
        if arr[j] <= pivot {
            i += 1;
            swap(&mut arr[i as usize], &mut arr[j]);
        }
    }
    swap(&mut arr[(i + 1) as usize], &mut arr[high]);
    (i + 1) as usize
}

fn quick_sort(arr: &mut [i32], low: usize, high: usize) {
    if low < high {
        let pi = partition(arr, low, high);

        if pi > 0 {
            quick_sort(arr, low, pi - 1);
        }
        quick_sort(arr, pi + 1, high);
    }
}

fn main() {
    let mut arr = [10, 7, 8, 9, 1, 5];
    let n = arr.len();
    quick_sort(&mut arr, 0, n - 1);

    print!("Sorted array: ");
    for &x in arr.iter() {
        print!("{} ", x);
    }
    println!();
}

