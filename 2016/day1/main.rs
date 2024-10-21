use std::fs;
fn main() {
    let contents = fs::read_to_string("day1.txt").expect("i suck");
    let directions = contents.split(", ");
    let mut current_direction = 0;
    let mut x = 0;
    let mut y = 0;
    let mut locs : Vec< [i32;2] > = Vec::new();
    locs.push([0,0]);
    for direction in directions{
        // if turn right, and current direction != 3 currentDirection++
        if direction.chars().next().unwrap() == 'R' {
            if current_direction == 3{
                current_direction = 0;
            }else{
                current_direction += 1;
            }
        }else{
            if current_direction == 0{
                current_direction = 3;
            }else{
                current_direction -= 1;
            }
        }
        
        let temp = &direction[1..];
        let n: i32 = temp.parse().unwrap();
        for i in 0..n{
            match current_direction{
                0=>y+=1,
                1=>x+=1,
                2=>y-=1,
                3=>x-=1,
                _=>println!("{}",n),
            }
            if locs.contains(&[x,y]){
                x = x.abs();
                y = y.abs();
                println!("{}", x+y);
                return;
                break;
            }
            
            locs.push([x,y]);
            //println!("X: {}", x);
            //println!("Y: {}", y);
        }   
    }
}