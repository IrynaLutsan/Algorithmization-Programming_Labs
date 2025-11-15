#include<iostream>

int main(){
    int arr[10];

    std:: cout << "Масив з 10 чисел-кубів: ";
    for (int i = 0; i < 10; i++){
      arr[i] = (i+1)*(i+1)*(i+1);
      std:: cout <<  arr[i] << ", ";
    }

    int *p  = arr;
    int sum = 0;
    for (int i = 0; i<10; i++){
        sum += p[i];
    }
    std:: cout << std::endl << "Сума усіх 10 чисел-кубів: " << sum;
    
    return 0;
}
