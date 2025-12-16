fn main() {
    // Ініціалізація масиву (36 елементів)
    let nums: [f64; 36] = [
        -10.0, -20.5, 3.0, 5.5, -3.2, 0.0, 8.1, -1.0, 12.0, 4.5,
        -50.0, -2.0, 1.1, 7.7, -9.9, 2.2, -4.4, 6.6, 10.0, -100.0,
        3.3, 15.0, -0.5, 9.0, 1.5, -6.0, 20.0, -7.5, 5.0, -12.0,
        18.0, -30.0, 4.0, 0.5, -8.0, 2.5
    ];

    println!("Масив: {:?}", nums);

    // Знаходимо "друге найбільше від’ємне" значення
    // Збираємо всі від'ємні, сортуємо їх. Найбільше від'ємне - це те, що найближче до 0 (наприклад -1 більшее за -100).
    let mut negatives: Vec<f64> = nums.iter().cloned().filter(|&x| x < 0.0).collect();
    negatives.sort_by(|a, b| a.partial_cmp(b).unwrap()); 
    
    let second_largest_negative = if negatives.len() >= 2 {
        Some(negatives[negatives.len() - 2])
    } else {
        None
    };

    // Знаходимо "перше найменше додатне" значення
    let mut positives: Vec<f64> = nums.iter().cloned().filter(|&x| x > 0.0).collect();
    positives.sort_by(|a, b| a.partial_cmp(b).unwrap());
    let smallest_positive = positives.first().cloned();

    // Основна логіка пошуку індексів та суми
    match (second_largest_negative, smallest_positive) {
        (Some(neg_val), Some(pos_val)) => {
            println!("Друге найбільше від'ємне: {}", neg_val);
            println!("Найменше додатне: {}", pos_val);

            // Знаходимо індекси цих елементів у початковому масиві
            let idx1 = nums.iter().position(|&x| x == neg_val).unwrap();
            let idx2 = nums.iter().position(|&x| x == pos_val).unwrap();

            println!("Індекс від'ємного: {}, Індекс додатного: {}", idx1, idx2);

            // Визначаємо межі (початок і кінець), бо idx1 може бути більше за idx2
            let start = std::cmp::min(idx1, idx2);
            let end = std::cmp::max(idx1, idx2);

            // Рахуємо суму квадратів МІЖ ними 
            let mut sum_sq = 0.0;
            if end > start + 1 {
                for i in (start + 1)..end {
                    sum_sq += nums[i].powi(2); 
                }
            }

            println!("--------------------------------------------------");
            println!("Сума квадратів елементів між ними: {:.4}", sum_sq);
        },
        _ => {
            println!("Недостатньо даних для розрахунку (мало від'ємних або немає додатних чисел).");
        }
    }
}