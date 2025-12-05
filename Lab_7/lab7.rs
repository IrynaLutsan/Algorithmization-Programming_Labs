use std::f64;

fn factorial(n: u64) -> f64 {
    (1..=n).map(|i| i as f64).product()
}

// k-й член ряду: a_k = (2k + 1) * x^k / k!
fn term(x: f64, k: u64) -> f64 {
    if k == 0 {
        1.0
    } else {
        let k_f64 = k as f64;
        (2.0 * k_f64 + 1.0) * x.powf(k_f64) / factorial(k)
    }
}

fn y(x: f64) -> f64 {
    (1.0 + 2.0 * x.powi(2)) * x.exp()
}

// сума S1: Обчислення з фіксованою кількістю N членів (від k=0 до N)
fn sum1(x: f64, n: u64) -> f64 {
    let mut z = 0.0;
    for k in 0..=n {
        z += term(x, k);
    }
    z
}

// сума S2: обчислення з заданою точністю eps 
fn sum2(x: f64, eps: f64) -> f64 {
    if eps <= 0.0 { return f64::NAN; }

    let mut z = 0.0;
    let mut k = 0;
    let mut ak: f64 = 1.0;
    
    if ak.abs() <= eps {
         return z;
    }
    z += ak;
    k += 1;

    loop {
        let k_f64 = k as f64;
        
        // Рекурсивне співвідношення a_k = a_{k-1} * (2k+1)/(2k-1) * x/k
        let ratio = (2.0 * k_f64 + 1.0) / (2.0 * (k_f64 - 1.0) + 1.0) * x / k_f64;
        ak *= ratio;

        if ak.abs() <= eps {
            z += ak; 
            break;
        }

        z += ak;
        k += 1;

        if k > 100 { // Запобіжник на випадок повільної збіжності
            break;
        }
    }

    z
}

fn main() {
    let a = 0.0;             // Початок діапазону
    let b = 1.0;             // Кінець діапазону
    let k_points = 5;        // Кількість точок
    let h = (b - a) / (k_points - 1) as f64; // Крок
    let n_max = 10;          // Максимальна кількість членів для S1
    let eps = 0.0001;        // Точність для S2

    // Вивід заголовка таблиці
    println!("-----------------------------------------------------------------------------------------");
    println!(" x        \ty(x)      \tS(sum1,n={})\tS(sum2,eps={})  Delta1  \tDelta2", n_max, eps);
    println!("-----------------------------------------------------------------------------------------");

    for j in 0..k_points {
        let x = a + j as f64 * h;
        let y_exact = y(x);
        let s1 = sum1(x, n_max);
        let s2 = sum2(x, eps);

        let delta1 = (y_exact - s1).abs();
        let delta2 = (y_exact - s2).abs();

        // Вивід рядка таблиці з 6 знаками після коми
        println!("{:8.6}\t{:8.6}\t{:8.6}\t{:8.6}\t{:8.6}\t{:8.6}",
                 x, y_exact, s1, s2, delta1, delta2);
    }

    println!("-----------------------------------------------------------------------------------------");
}