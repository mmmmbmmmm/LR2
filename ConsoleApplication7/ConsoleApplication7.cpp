#include <iostream>
#define m 10

struct Books
{
    int ID;
    char Auth[40];
    char Name[50];
    int Year;
    char Publ[40];
    int Pages;
};
Books* base = new Books[m];

void input_struct(struct Books, size_t k);
void print_struct(struct Books, size_t k);
void year_query(struct Books, size_t k);

int main(void)
{
    setlocale(0, "");
    input_struct(*base, m);
    print_struct(*base, m);
    year_query(*base, m);
    delete[] base;
    system("pause");
    return 0;
}

void input_struct(struct Books, size_t k)
{
    std::cout << "Поля заполняются в кодировке ANSI ASCII!\n";
    std::cout << std::endl;
    for (size_t i = 0; i < k; ++i)
    {
        std::cout << "Введите данные о книге [" << i + 1 << "] -> ";
        std::cin >> base[i].ID;
        std::cin >> base[i].Auth;
        std::cin >> base[i].Name;
        std::cin >> base[i].Year;
        std::cin >> base[i].Publ;
        std::cin >> base[i].Pages;
    }
    std::cout << std::endl;
}

void print_struct(struct Books, size_t k)
{
    std::cout << "Состояние полей структуры Books: \n";
    for (size_t i = 0; i < k; ++i)
    {
        std::cout << base[i].ID << '\t';
        std::cout << base[i].Auth << '\t';
        std::cout << base[i].Name << '\t';
        std::cout << base[i].Year << '\t';
        std::cout << base[i].Publ << '\t';
        std::cout << base[i].Pages << '\t';
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void year_query(struct Books, size_t k)
{
    int y;
    std::cout << "Введите год для выборки -> ";
    std::cin >> y;
    std::cout << std::endl;
    bool f = false;
    for (size_t i = 0; i < k; ++i)
        if (y < base[i].Year)
        {
            std::cout << base[i].Name << '\t' << base[i].Auth << std::endl;
            f = true;
        }
    if (!f)
        std::cout << "Книг после " << y << " года" << " нет" << std::endl;
}