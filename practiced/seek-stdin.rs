#![allow(dead_code, unused)]

use std::io::{self, Read, Write};

fn main() {
    let input = get_input("Enter your input: ");
    for letter in input.chars().rev() {
        print!("{}", letter);
    }
    println!("");
}

fn get_input(msg: &str) -> String {
    println!("{}", msg);
    let mut line = String::new();
    io::stdin().read_line(&mut line).expect("Wrong input");
    line.trim().to_string()
}
