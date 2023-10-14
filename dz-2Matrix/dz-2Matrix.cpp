#include <numeric>
#include <iostream>
#include <limits>

int main()
{
    setlocale(LC_ALL, "RUS");
    int n , m;
    
    std::cout << "Кол-во строк и столбцов: ";
    std::cin >> n >> m;
    while (std::cin.fail() || (n <= 0 || m <=0 )){
        std::cin.clear();
        std::cout << "Введите числа вверно! Повторите попытку: " << std::endl;
        std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
        std::cin >> n>> m;
    }
    
    //Инициализация динамического двумерного массива && Заполнение случайными числами от 0 до 2
    //В условиях не написано про заполнение матрицы вручную (cin>>)
    int** arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m];
        for (int j = 0; j < m; j++) {
            arr[i][j] = rand() % 2;
            std::cout << arr[i][j] << " ";
        }
        std::cout << '\n';
    }
    std::cout <<"      Матрица NxM" << '\n'<<'\n';
  

      
    int* B = new int[m];
    for (int i=0; i < m; i++) {
        int total = std::accumulate(arr, arr + n, 0, [i](int a, int* b) {
            return a + b[i];
            });
        if (total == 0) B[i] = 0;
        else B[i] = 1;
    }
    
   
    for (int i = 0; i < m; i++) std::cout << B[i] << " ";
    std::cout <<'\n' << "      Массив B"<<'\n';
  
}

