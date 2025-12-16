type Matrix4x4 = [[f64; 4]; 4];
type Vector4 = [f64; 4];

fn main() {
    
    let a: Matrix4x4 = [
        [-1.0, 0.0, 1.0, 1.0],
        [2.0, 1.0, -1.0, 3.0],
        [-1.0, 0.0, 3.0, 2.0],
        [1.0, 2.0, 2.0, 1.0],
    ];

    let d: Matrix4x4 = [
        [1.0, 1.0, 0.0, -1.0],
        [-2.0, 1.0, -2.0, 0.0],
        [-1.0, 0.0, 1.0, 2.0],
        [-1.0, 2.0, 3.0, 1.0],
    ];

    let f: Matrix4x4 = [
        [-1.0, 1.0, 0.0, -1.0],
        [2.0, 1.0, -2.0, 0.0],
        [-1.0, 0.0, 0.0, 2.0],
        [1.0, -2.0, 4.0, 1.0],
    ];

    let y: Vector4 = [2.0, 5.0, -1.0, -2.0];
    let t: Vector4 = [1.0, 2.0, 0.0, 5.0];

    println!("--- Початок обчислення (2F + 3AD)(2y + 5t) ---");

    // AD (множення матриць)
    let ad = multiply_matrices(&a, &d);
    // println!("Матриця AD:"); print_matrix(&ad);

    //  3 * AD
    let three_ad = scale_matrix(&ad, 3.0);

    // Крок 3: 2 * F
    let two_f = scale_matrix(&f, 2.0);

    // (2F + 3AD) -> Ліва матриця
    let left_matrix = add_matrices(&two_f, &three_ad);
    println!("\nЛіва дужка (матриця 2F + 3AD):");
    print_matrix(&left_matrix);

    // 2 * y
    let two_y = scale_vector(&y, 2.0);
    // 5 * t
    let five_t = scale_vector(&t, 5.0);

    // (2y + 5t) -> Правий вектор
    let right_vector = add_vectors(&two_y, &five_t);
    println!("\nПрава дужка (вектор 2y + 5t):");
    print_vector(&right_vector);

    // Фінальне множення Матриці на Вектор
    let result = multiply_matrix_vector(&left_matrix, &right_vector);

    // Вивід результату
    println!("\n=== Результат (вектор x) ===");
    print_vector(&result);
}

// Множення матриці на матрицю (Rows x Cols)
fn multiply_matrices(m1: &Matrix4x4, m2: &Matrix4x4) -> Matrix4x4 {
    let mut result = [[0.0; 4]; 4];
    for i in 0..4 {
        for j in 0..4 {
            for k in 0..4 {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    result
}

// Множення матриці на число
fn scale_matrix(m: &Matrix4x4, scalar: f64) -> Matrix4x4 {
    let mut result = [[0.0; 4]; 4];
    for i in 0..4 {
        for j in 0..4 {
            result[i][j] = m[i][j] * scalar;
        }
    }
    result
}

// Додавання двох матриць
fn add_matrices(m1: &Matrix4x4, m2: &Matrix4x4) -> Matrix4x4 {
    let mut result = [[0.0; 4]; 4];
    for i in 0..4 {
        for j in 0..4 {
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
    result
}

// Множення вектора на число
fn scale_vector(v: &Vector4, scalar: f64) -> Vector4 {
    let mut result = [0.0; 4];
    for i in 0..4 {
        result[i] = v[i] * scalar;
    }
    result
}

// Додавання двох векторів
fn add_vectors(v1: &Vector4, v2: &Vector4) -> Vector4 {
    let mut result = [0.0; 4];
    for i in 0..4 {
        result[i] = v1[i] + v2[i];
    }
    result
}

// Множення матриці на вектор (Результат - вектор)
fn multiply_matrix_vector(m: &Matrix4x4, v: &Vector4) -> Vector4 {
    let mut result = [0.0; 4];
    for i in 0..4 { // Проходимо по рядках матриці
        let mut sum = 0.0;
        for j in 0..4 { // Проходимо по стовпцях/елементах вектора
            sum += m[i][j] * v[j];
        }
        result[i] = sum;
    }
    result
}

// Функція для красивого виводу матриці
fn print_matrix(m: &Matrix4x4) {
    for row in m {
        println!("{:8.2} {:8.2} {:8.2} {:8.2}", row[0], row[1], row[2], row[3]);
    }
}

fn print_vector(v: &Vector4) {
    for val in v {
        println!("{:8.2}", val);
    }
}