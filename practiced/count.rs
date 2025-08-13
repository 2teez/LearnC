#![allow(dead_code, unused)]

use std::env;
use std::fs::{self, File};
use std::io::{self, Read};
use std::path::Path;

fn main() {
    let files = env::args().collect::<Vec<_>>();
    if files.len() != 2 {
        println!("Usage: {:} <filename>", files[0]);
        std::process::exit(-1);
    }

    let filename = &files[1];
    let path = Path::new(filename);
    if !path.exists() {
        println!("filename {:} doesn't exist.", filename);
        std::process::exit(-1);
    }

    let mut counter = 0;
    let mut line = String::new();

    let mut file = File::open(filename).expect("Invalid file.");
    file.read_to_string(&mut line).unwrap();
    println!("{}", line.chars().collect::<Vec<_>>().len());
}
