use std::cmp::max;

fn maxProfit(prices: Vec<i32>) -> i32 {
    let mut maxProfit: i32 = 0;
    for i in 0..prices.len() - 1 {
        for j in 1..prices.len() - i {
            maxProfit = max(maxProfit, prices[i + j] - prices[i]);
        }
    }
    return maxProfit;
}

fn main() {
    println!("max profit: {}", maxProfit(vec![1, 3, 1, 4, 5, 9, 2, 8, 1]));
}
