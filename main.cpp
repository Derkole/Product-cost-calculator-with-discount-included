#include <iostream>
#include <limits>
#include <iomanip>

// Доп скидка если условие выполнено
const double dop_discount{5};

// Условие для дополнительной скидки
const double condition{1000};

int main()
{
    std::cout << "Введите стоимость товара: ";
    double cost{};
    while (!(std::cin >> cost) || cost <= 0)
	{std::cout << "Неверный ввод! Введите корректную стоимость товара: ";
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}


    std::cout << "Введите процент скидки: ";
    float discount{};
	while (!(std::cin >> discount) || discount < 0 || discount > 100)
	{std::cout << "Неверный ввод! Введите процент скидки от 0 до 100: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	
    // Вычисление итоговой стоимости после основной скидки
    double total_cost{cost * (1 - discount / 100)};

    // Вывод total_cost после основной скидки с точностью до 2 знаков после ","
    std::cout << "Итоговая стоимость после скидки: " 
              << std::fixed << std::setprecision(2) << total_cost << '\n';

    // Применяем дополнительную скидку, если итоговая стоимость больше условия
    if (total_cost > condition)
    {
    // Вычисляем дополнительную скидку
    total_cost = total_cost * (1 - dop_discount / 100);

    // Вывод dop_discount(доп. скидки)
    std::cout << "Итоговая стоимость после скидки больше " 
    << condition << " рублей, дополнительная скидка " << dop_discount << "%" << '\n';

    // Вывод total_cost после дополнительной скидки с точностью до 2 знаков после ","
    std::cout << "Итоговая стоимость после дополнительной скидки: " 
    << std::fixed << std::setprecision(2) << total_cost << '\n';
    }

    return 0;
}
