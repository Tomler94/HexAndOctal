#include <iostream>
#include <string>

using namespace std;
//Класс массив
class Array
{
public:
	static const int size = 100;
	unsigned char* number;
	//Конструктор
	Array(int size)
	{
		number = new unsigned char[size];

		for (int i = 0; i < size; i++)
			number[i] = '0';
	};
	Array() {};
	//Метод доступа к отдельному элементу
	//Перегрузка индексации
	int& operator[] (int index)
	{
		while (true)
		{
			if (index < 1 || index > size)
			{
				cout << "Вы ввели недопустимый индекс.\nПопробуйте снова.\n";
					cin >> index;
				continue;
			}
			else break;
		}
		return index;
	}
	//Сравнение
	virtual int Comparison(Array* array, int size);
	//Суммирование 
	virtual void Addition(Array* array, int size);
	//Вычитание
	virtual void Subtraction(unsigned char* array_1,
		unsigned char* array_2, unsigned char* array_3, int size);

	//Умножение
	virtual void Multiplication(unsigned char* array_1,
		unsigned char* array_2, unsigned char* array_3, int size);
	//Деление
	virtual void Division(unsigned char* array_1,
		unsigned char* array_2, unsigned char* array_3, int size);
};

class Octal : public Array
{
public:
	Octal(int size)
	{
		number = new unsigned char[size];

		for (int i = 0; i < size; i++)
			number[i] = '0';
	};
	//Суммирование 
	void Addition(Array* array, int size);
	//Вычитание
	void Subtraction(unsigned char* array_1,
		unsigned char* array_2, unsigned char* array_3, int size);
	//Умножение
	void Multiplication(unsigned char* array_1,
		unsigned char* array_2, unsigned char* array_3, int size);
	//Деление
	void Division(unsigned char* array_1,
		unsigned char* array_2, unsigned char* array_3, int size);
};

class Hex : public Array
{
public:
	Hex(int size)
	{
		number = new unsigned char[size];

		for (int i = 0; i < size; i++)
			number[i] = '0';
	};
	//Суммирование 
	void Addition(Array* array, int size);
	//Вычитание
	void Subtraction(unsigned char* array_1,
		unsigned char* array_2, unsigned char* array_3, int size);
	//Умножение
	void Multiplication(unsigned char* array_1,
		unsigned char* array_2, unsigned char* array_3, int size);
	//Деление
	void Division(unsigned char* array_1,
		unsigned char* array_2, unsigned char* array_3, int size);

};

//Ввод числа в вектор
void InputNumber(unsigned char* array, string number, int size);
//Вывод числа из вектора
void OutputNumber(unsigned char* array, int size);
//Обнуление векторов
void NullArray(unsigned char* array, int size);
//Переопределение функций
void Redefinition(Array* array, int size, string number_1, string number_2);

int main()
{
	setlocale(LC_ALL, "Russian");
	int size;
	cout << "Максимально возможное количество элементов: "
		<< Array::size << endl
		<< "Введите свое количество элементов: "; cin >> size;
	string number_1;
	string number_2;
	Array arr[3] = { size, size, size };
	Array* refArr = &arr[0];

	cout << "Введите первое число в десятичной системе счисления: "; cin >> number_1;
		InputNumber(arr[0].number, number_1, size);
	cout << "Введите второе число в десятичной системе счисления: "; cin >> number_2; cout << endl;
		InputNumber(arr[1].number, number_2, size);
	Redefinition(refArr, size, number_1, number_2);
	cout << endl;

	Octal octal[3] = { size, size, size };
	refArr = &octal[0];
	cout << "Введите первое число в восьмиричной системе счисления : "; cin >> number_1;
		InputNumber(octal[0].number, number_1, size);
	cout << "Введите второе число в восьмиричной системе счисления: "; cin >> number_2; cout << endl;
		InputNumber(octal[1].number, number_2, size);
	Redefinition(refArr, size, number_1, number_2);
	cout << endl;

	Hex hex[3] = { size, size, size };
	refArr = &hex[0];
	cout << "Введите первое число в шестнадцатиричной системе счисления: "; cin >> number_1;
		InputNumber(hex[0].number, number_1, size);
	cout << "Введите второе число в шестнадцатиричной системе счисления: "; cin >> number_2; cout << endl;
		InputNumber(hex[1].number, number_2, size);
	Redefinition(refArr, size, number_1, number_2);
	cout << endl;
	system("pause");
}

//Переопределение функций
void Redefinition(Array* array, int size, string number_1, string number_2)
{
	int biggerNumber;
	//Сравнение
	biggerNumber = array->Comparison(array, size);
	if (biggerNumber == 0)
	{
		//Сравнение
		OutputNumber(array[0].number, size); cout << " > ";
		OutputNumber(array[1].number, size);
		cout << endl;
		//Суммирование
		array->Addition(array, size);
		cout << "Cумма двух чисел: ";
		OutputNumber(array[2].number, size);
		NullArray(array[2].number, size);
		cout << endl;
		//Вычитание
		array->Subtraction(array[0].number, array[1].number,
			array[2].number, size);
		cout << "Вычитание двух чисел: ";
		OutputNumber(array[2].number, size);
		NullArray(array[2].number, size);
		InputNumber(array[0].number, number_1, size);
		cout << endl;
		//Умножение
		array->Multiplication(array[0].number, array[1].number,
			array[2].number, size);
		cout << "Умножение двух чисел: ";
		OutputNumber(array[2].number, size);
		NullArray(array[2].number, size);
		cout << endl;
		//Деление нацело
		if (number_2 != "0")
		{
			if (number_1 != "0")
				array->Division(array[0].number,
					array[1].number, array[2].number, size);
			cout << "Деление двух чисел: ";
			OutputNumber(array[2].number, size);
		}
		else cout << "Ошибка. Деление на 0";
		cout << endl;
	}
	else
	{
		//Сравнение
		if (biggerNumber == 1)
		{
			OutputNumber(array[0].number, size);
			cout << " < "; OutputNumber(array[1].number, size);
		}
		else
		{
			OutputNumber(array[0].number, size);
			cout << " = "; OutputNumber(array[1].number, size);
		}
		cout << endl;
		//Суммирование
		array->Addition(array, size);
		cout << "Cумма двух чисел: ";
		OutputNumber(array[2].number, size);
		NullArray(array[2].number, size);
		cout << endl;
		//Вычитание
		array->Subtraction(array[1].number, array[0].number,
			array[2].number, size);
		cout << "Вычитание двух чисел: ";
		OutputNumber(array[2].number, size);
		NullArray(array[2].number, size);
		InputNumber(array[1].number, number_2, size);
		cout << endl;
		//Умножение
		array->Multiplication(array[1].number, array[0].number,
			array[2].number, size);
		cout << "Умножение двух чисел: ";
		OutputNumber(array[2].number, size);
		NullArray(array[2].number, size);
		cout << endl;
		//Деление нацело
		if (number_2 != "0")
		{
			if (number_1 != "0")
				array->Division(array[1].number,
					array[0].number, array[2].number, size);
			cout << "Деление двух чисел: ";
			OutputNumber(array[2].number, size);
		}
		else cout << "Ошибка. Деление на 0";
	}
	cout << endl;
}

//Сравнение чисел
int Array::Comparison(Array* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (array[0].number[i] > array[1].number[i])
			return 0;
		else if (array[0].number[i] < array[1].number[i])
			return 1;
	}
	return 2;
}

//Суммирование чисел
void Array::Addition(Array* array, int size)
{
	int value = 0;
	for (int i = size - 1; i >= 0; i--)
	{
		value = static_cast<int>(array[0].number[i] - '0') +
			static_cast<int>(array[1].number[i] - '0') + value;
		if (value > 9)
		{
			array[2].number[i] = (value % 10) + '0';
			value /= 10;
		}
		else
		{
			array[2].number[i] = value + '0';
			value = 0;
		}
	}
}

//Вычитание чисел
void Array::Subtraction(unsigned char* array_1, unsigned char* array_2, unsigned char* array_3, int size)
{
	int value_1 = 0, value_2 = 0;
	int index;
	for (int i = size - 1; i >= 0; i--)
	{
		value_1 = static_cast<int>(array_1[i] - '0');
		value_2 = static_cast<int>(array_2[i] - '0');
		if (value_1 >= value_2)
			array_3[i] = (value_1 - value_2) + '0';
		else
		{
			index = i - 1;
			while (array_1[index] == '0')
				index = i - 1;
			value_1 = (static_cast<int>
				(array_1[index] - '0')) - 1;
			array_1[index] = value_1 + '0';
			for (int j = index + 1; j < i; j++)
				if (array_1[j] == '0')
					array_1[j] = 9 + '0';
			value_1 = ((static_cast<int>(array_1[i] - '0')) +
				10) - (static_cast<int>(array_2[i] - '0'));
			array_3[i] = value_1 + '0';
		}
	}
}

//Умножение чисел
void Array::Multiplication(unsigned char* array_1, unsigned char* array_2, unsigned char* array_3, int size)
{
	int shift = 0;
	for (int i = size - 1; i >= 0; i--)
	{
		int value = 0;
		for (int j = size - 1; j >= 0; j--)
		{
			value = static_cast<int>(array_2[i] - '0')
				* static_cast<int>(array_1[j] - '0') + value;
			if (value > 9)
			{
				int num = (static_cast<int>(array_3[j
					- shift] - '0') + (value % 10));
				array_3[j - shift] = num + '0';
				value /= 10;
			}
			else
			{
				array_3[j - shift] = (static_cast<int>(array_3[j - shift] - '0')
					+ value) + '0';
				for (int k = size - 1; k >= 0; k--)
					if (static_cast<int>(array_3[k] - '0') > 9)
					{
						int num = static_cast<int>
							(array_3[k] - '0') / 10;
						array_3[k] =
							(static_cast<int>(array_3[k] - '0') %
								10) + '0';
						array_3[k - 1] = (static_cast<int>(array_3[k - 1] - '0') + num) + '0';
					}
				value = 0;
			}
		}
		shift++;
	}
}

//Деление нацело
void Array::Division(unsigned char* array_1, unsigned char* array_2, unsigned char* array_3, int size)
{
	long long int integer = 0;
	for (int i = 0; i < size; i++)
	{
		integer += static_cast<int>(array_2[i] - '0');
		integer *= 10;
	}
	integer /= 10;
	int i = 0;
	while (array_1[i] == '0')
		i++;
	int carry = 0;
	for (; i < size; i++)
	{
		carry = (carry * 10) + (static_cast<int>
			(array_1[i] - '0'));
		array_3[i] = (carry / integer) + '0';
		carry = carry % integer;
	}
}

//Запись в массив
void InputNumber(unsigned char* array, string number, int size)
{
	int length = number.length();
	int start = size - 1;
	for (int i = length - 1; i >= 0; i--)
	{
		array[start] = number[i];
		start--;
	}
	for (int i = size - 1; i >= 0; i--)
	{
		switch (array[i])
		{
		case 'A': array[i] = 10 + '0'; break;
		case 'B': array[i] = 11 + '0'; break;
		case 'C': array[i] = 12 + '0'; break;
		case 'D': array[i] = 13 + '0'; break;
		case 'E': array[i] = 14 + '0'; break;
		case 'F': array[i] = 15 + '0'; break;
		case 'a': array[i] = 10 + '0'; break;
		case 'b': array[i] = 11 + '0'; break;
		case 'c': array[i] = 12 + '0'; break;
		case 'd': array[i] = 13 + '0'; break;
		case 'e': array[i] = 14 + '0'; break;
		case 'f': array[i] = 15 + '0'; break;
		}
	}
}

//Вывод массива
void OutputNumber(unsigned char* array, int size)
{
	int i = 0;
	while (array[i] == '0')
		i++;
	if (i == size)
		cout << 0;
	else
		for (; i < size; i++)
		{
			switch (array[i])
			{
			case ':': cout << 'A'; break;
			case ';': cout << 'B'; break;
			case '<': cout << 'C'; break;
			case '=': cout << 'D'; break;
			case '>': cout << 'E'; break;
			case '?': cout << 'F'; break;
			default:  cout << array[i];
			}
		}
}

//Обнуление массива
void NullArray(unsigned char* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		array[i] = '0';
	}
}

void Hex::Addition(Array* array, int size)
{
	int value = 0;
	for (int i = size - 1; i >= 0; i--)
	{
		value = static_cast<int>(array[0].number[i] - '0') + static_cast<int>(array[1].number[i] - '0') + value;
		if (value > 15)
		{
			array[2].number[i] = (value - 16) + '0';
			value /= 16;
		}
		else
		{
			array[2].number[i] = value + '0';
			value = 0;
		}
	}
}

void Hex::Subtraction(unsigned char* array_1, unsigned char* array_2, unsigned char* array_3, int size)
{
	int value_1 = 0, value_2 = 0;
	int index;
	for (int i = size - 1; i >= 0; i--)
	{
		value_1 = static_cast<int>(array_1[i] - '0');
		value_2 = static_cast<int>(array_2[i] - '0');
		if (value_1 >= value_2)
			array_3[i] = (value_1 - value_2) + '0';
		else
		{
			index = i - 1;
			while (array_1[index] == '0')
				index--;
			value_1 = (static_cast<int>(array_1[index]
				- '0')) - 1;
			array_1[index] = value_1 + '0';
			for (int j = index + 1; j < i; j++)
				if (array_1[j] == '0')
					array_1[j] = 15 + '0';
			value_1 = ((static_cast<int>(array_1[i] - '0'))
				+ 16) - (static_cast<int>(array_2[i] - '0'));
			array_3[i] = value_1 + '0';
		}
	}
}

void Hex::Multiplication(unsigned char* array_1, unsigned char* array_2, unsigned char* array_3, int size)
{
	int shift = 0;
	for (int i = size - 1; i >= 0; i--)
	{
		int value = 0;
		for (int j = size - 1; j >= 0; j--)
		{
			value = static_cast<int>(array_2[i] - '0')*
				static_cast<int>(array_1[j] - '0') + value;
			if (value > 15)
			{
				int num = (static_cast<int>(array_3[ j - shift] - '0') + (value % 16));
				array_3[j - shift] = num + '0';
				value /= 16;
			}
			else
			{
				array_3[j - shift] =
					(static_cast<int>(array_3[j - shift] - '0')
						+ value) + '0';
				for (int k = size - 1; k >= 0; k--)
					if (static_cast<int>(array_3[k] - '0') > 15)
					{
						int num =
							static_cast<int>(array_3[k]
								- '0') / 16;
						array_3[k] = (static_cast<int>
							(array_3[k] - '0') % 16) + '0';
						array_3[k - 1] = (static_cast<int>
							(array_3[k - 1] - '0') + num) + '0';
					}
				value = 0;
			}
		}
		shift++;
	}
}

void Hex::Division(unsigned char* array_1, unsigned char* array_2, unsigned char* array_3, int size)
{
	unsigned char* time_array_2;
	int check = 0, i = 0;;
	bool trigger = false;
	time_array_2 = new unsigned char[size];
	for (int i = 0; i < size; i++)
		time_array_2[i] = '0';
	while (array_1[i] == '0')
		i++;
	for (; i < size; i++)
	{
		for (int j = 1; j < size; j++)
			time_array_2[j - 1] = time_array_2[j];
		time_array_2[size - 1] = array_1[i];
		for (int j = 0; j < size; j++)
		{
			int p = static_cast<int>(time_array_2[j] - '0');
			int q = static_cast<int>(array_2[j] - '0');
			if ((p >= q) && (time_array_2[j] != '0' ||
				array_2[j] != '0'))
			{
				trigger = true; break;
			}
			else if (time_array_2[j] != '0' ||
				array_2[j] != '0')
			{
				trigger = false; break;
			}
		}
		if (trigger)
		{
			while (trigger)
			{
				Subtraction(time_array_2, array_2,
					time_array_2, size);
				check++;
				for (int j = 0; j < size; j++)
				{
					int p = static_cast<int>
						(time_array_2[j] - '0');
					int q = static_cast<int>
						(array_2[j] - '0');
					if ((p >= q) && (time_array_2[j]
						!= '0' || array_2[j] != '0'))
					{
						trigger = true; break;
					}
					else if (time_array_2[j] != '0' ||
						array_2[j] != '0')
					{
						trigger = false; break;
					}
				}
			}
			array_3[i] = check + '0';
			check = 0;
		}
	}
}

void Octal::Addition(Array* array, int size)
{
	int value = 0;
	for (int i = size - 1; i >= 0; i--)
	{
		value = static_cast<int>(array[0].number[i] - '0') +
			static_cast<int>(array[1].number[i] - '0') + value;
		if (value > 7)
		{
			array[2].number[i] = (value - 8) + '0';
			value /= 8;
		}
		else
		{
			array[2].number[i] = value + '0';
			value = 0;
		}
	}
}

void Octal::Subtraction(unsigned char* array_1, unsigned char* array_2, unsigned char* array_3, int size)
{
	int value_1 = 0, value_2 = 0;
	int index;
	for (int i = size - 1; i >= 0; i--)
	{
		value_1 = static_cast<int>(array_1[i] - '0');
		value_2 = static_cast<int>(array_2[i] - '0');
		if (value_1 >= value_2)
			array_3[i] = (value_1 - value_2) + '0';
		else
		{
			index = i - 1;
			while (array_1[index] == '0')
				index--;
			value_1 = (static_cast<int>(array_1[index]
				- '0')) - 1;
			array_1[index] = value_1 + '0';
			for (int j = index + 1; j < i; j++)
				if (array_1[j] == '0')
					array_1[j] = 7 + '0';
			value_1 = ((static_cast<int>(array_1[i] - '0')) + 8)
				- (static_cast<int>(array_2[i] - '0'));
			array_3[i] = value_1 + '0';
		}
	}
}

void Octal::Multiplication(unsigned char* array_1, unsigned char* array_2, unsigned char* array_3, int size)
{
	int shift = 0;
	for (int i = size - 1; i >= 0; i--)
	{
		int value = 0;
		for (int j = size - 1; j >= 0; j--)
		{
			value = static_cast<int>(array_2[i] - '0')*
				static_cast<int>(array_1[j] - '0') + value;
			if (value > 7)
			{
				int num = (static_cast<int>(array_3[j - shift] - '0') + (value % 8));
				array_3[j - shift] = num + '0';
				value /= 8;
			}
			else
			{
				array_3[j - shift] = (static_cast<int>
					(array_3[j - shift] - '0') + value) + '0';
				for (int k = size - 1; k >= 0; k--)
					if (static_cast<int>(array_3[k] - '0') > 7)
					{
						int num = static_cast<int>
							(array_3[k] - '0') / 8;
						array_3[k] = (static_cast<int
						>(array_3[k] - '0') % 8) + '0';
						array_3[k - 1] = (static_cast<int>
							(array_3[k - 1] - '0') + num) + '0';
					}
				value = 0;
			}
		}
		shift++;
	}
}

void Octal::Division(unsigned char* array_1, unsigned char* array_2, unsigned char* array_3, int size)
{
	unsigned char* time_array_2;
	int check = 0;
	bool trigger = false;
	time_array_2 = new unsigned char[size];
	for (int i = 0; i < size; i++)
		time_array_2[i] = '0';
	int i = 0;
	while (array_1[i] == '0')
		i++;
	for (; i < size; i++)
	{
		for (int j = 1; j < size; j++)
			time_array_2[j - 1] = time_array_2[j];
		time_array_2[size - 1] = array_1[i];
		for (int j = 0; j < size; j++)
		{
			int p = static_cast<int>(time_array_2[j] - '0');
			int q = static_cast<int>(array_2[j] - '0');
			if ((p >= q) && (time_array_2[j] != '0' ||
				array_2[j] != '0'))
			{
				trigger = true; break;
			}
			else if (time_array_2[j] != '0' || array_2[j]
				!= '0')
			{
				trigger = false; break;
			}
		}
		if (trigger)
		{
			while (trigger)
			{
				Subtraction(time_array_2, array_2,
					time_array_2, size);
				check++;
				for (int j = 0; j < size; j++)
				{
					int p = static_cast<int>(time_array_2[j]
						- '0');
					int q = static_cast<int>(array_2[j] - '0');
					if ((p >= q) && (time_array_2[j] != '0'
						|| array_2[j] != '0'))
					{
						trigger = true; break;
					}
					else if (time_array_2[j] != '0' ||
						array_2[j] != '0')
					{
						trigger = false; break;
					}
				}
			}
			array_3[i] = check + '0';
			check = 0;
		}
	}
}