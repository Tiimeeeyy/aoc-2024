use std::fs::File;
use std::io::{BufRead, BufReader};

fn main() {
    let input = read_data();
    let solution = count_safe_vectors(input);
    print!("Solution: {} ", solution);
}

fn count_safe_vectors(list: Vec<Vec<i32>>) -> usize {
    let counter = list
        .iter()
        .filter(|array| {
            let adjacent = array.windows(2).all(|w| {
                let diff = (w[0] - w[1]).abs();
                diff >= 1 && diff <= 3
            });

            if !adjacent {
                return false;
            }

            let increasing = array.windows(2).all(|w| w[0] < w[1]);
            let decreasing = array.windows(2).all(|w| w[0] > w[1]);

            increasing || decreasing
        })
        .count();
    return counter;
}

fn read_data() -> Vec<Vec<i32>> {
    let filename = "inputday2.txt";
    let file = File::open(filename).expect("Unable To open file");
    let reader = BufReader::new(file);

    let mut data_list: Vec<Vec<i32>> = Vec::new();

    for line in reader.lines() {
        let line = line.expect("Unable to read line");
        let values: Vec<i32> = line
            .trim()
            .split_whitespace()
            .filter_map(|s| s.parse().ok()) // Parse to i32, ignore errors
            .collect();
        if !values.is_empty() {
            data_list.push(values);
        }
    }

    return data_list;
}
