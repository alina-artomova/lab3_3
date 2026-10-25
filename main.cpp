#include <iostream>
#include <limits>

using namespace std; 

// Декларації функцій
void task_if14();
void task_if18();
void task_geom8();

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    int menu;
     cout << "Виберіть завдання:\n"
         << "1 - Завдання 1 If14\n"
         << "2 - Завдання 1 If18\n"
         << "3 - Завдання 2 Geom8\n"
         << "Введіть завдання: ";

        if (!(cin >> menu))
    {
        cout << "Помилка введення!\n";
        return 0;
    }
    
    // Вибираємо завдання за допомогою switch.
     switch (menu) {
         case 1: 
            task_if14(); 
            break; 
        case 2:
            task_if18();
            break;
        case 3:
            task_geom8();
            break;
        default: 
            cout << "Неправильний вибір завдання!\n"; 
    }

          cout << "\n";
          cout << "Натисніть Enter для виходу...";
          cin.get(); 
          return 0;
}

// завдання 1 (if14) реалізація
    void task_if14()
    {
        double a, b, c;
        cout << "************* Завдання 1 If14 *****************\n";
        cout << "Введіть три числа: ";
    
    // Перевірка, чи коректно введені числові дані
        if (!(cin >> a >> b >> c))
        {
            cout << "Помилка: треба ввести числа!\n";
            clearInput();
            return;
        }
    
    double minNum = a;
    double maxNum = a;
    
    // Шукаємо найменше число
    if (b < minNum) minNum = b;
    if (c < minNum) minNum = c;
    
    // Шукаємо найбільше число
    if (b > maxNum) maxNum = b;
    if (c > maxNum) maxNum = c;
    
    // Виведення результату: спочатку найменше, потім найбільше 
    cout << "Найменше число: " << minNum << '\n';
    cout << "Найбільше число: " << maxNum << '\n';
    }
    
// завдання 1 (if18) реалізація
    void task_if18() 
    {
        int a, b, c;
        cout << "\n************* Завдання 1 If18 *****************\n";
        cout << "Введіть три цілих числа (два з яких рівні): ";
    
        if (!(cin >> a >> b >> c)) 
        {
            cout << "Помилка: потрібно ввести цілі числа!\n";
            clearInput();
            return ;
        }
        if (a == b) {
            cout << "Порядковий номер відмінного числа: 3\n";
        } else if (a == c) {
            cout << "Порядковий номер відмінного числа: 2\n";
        } else if (b == c) {
            cout << "Порядковий номер відмінного числа: 1\n";
        } else {
            cout << "Помилка: серед чисел немає двох рівних!\n";
        }
    }
    
    // завдання 2 (geom8) реалізація
    void task_geom8() 
    {
       double a, x, y; 
    
       cout << "\n************* Завдання 2 Geom8 *****************\n";
       cout << "Введіть сторону квадрата a: ";
         
    // Перевірка коректності введення сторони квадрата        
        if (!(cin >> a) || a <= 0) 
        {
            cout << "Помилка: некоректне значення сторони a!\n";
            clearInput();
            return;
        }

        cout << "Введіть координати точки (x та y): ";
        
        if (!(cin >> x >> y))
        {
            cout << "Помилка: некоректні координати точки!\n";
            clearInput();
            return;
        }
     

        bool in_area = false;
        // Коло має центр (0, -a/2) і радіус a/2.
    double radius = a / 2.0;
    double center_y = -a / 2.0;
    
    // 1. Верхній жовтий трикутник 
    // x >= 0, y >= 0, x + y <= a/2
    if (x >= 0.0 && y >= 0.0 && (x + y <= a / 2.0)) 
    {
        in_area = true;
    }

    // 2. Нижня права частина кола
    else if (x >= 0 && y <= 0) {
        if ((x * x + (y - center_y) * (y - center_y)) <= (radius * radius)){
            in_area = true;
        }
    }

    if (in_area) {
        cout << "Результат: Точка належить жовтій області)\n";
    } else {
        cout << "Результат: Точка не належить жовтій області\n";
    }
    }
