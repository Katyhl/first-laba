#include <iostream>
#include <random>
#include <chrono>
using namespace std;
using namespace chrono;




// Функция для заполнения массива 
void Array(int array[], int size) {
     srand(time(0));
    for (int i = 0; i < 100; i++){
        array[i] = rand() % 199 - 99;
    }
}



// Функция для сортировки массива bubble sort
void BubbleSort(int array[], int size) {
	auto start = high_resolution_clock::now();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 99; j ++) {
            if (array[j] > array[j + 1])
                swap(array[j], array[j + 1]);

        }
    }
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(stop - start);
	cout << "затраченное время при помощи bubble sort  " <<  duration.count()<< "  наносекунд" << endl;

}



//Функция для сортировки массива shaker sort
void ShakerSort(int array[], int size) {
    bool swapped = true;
    int start = 0;
    int end = size - 1;
	auto startyem = high_resolution_clock::now();
    while (swapped) {
        swapped = false;
        for (int i = 0; i < size - 1; ++i) {
            if (array[i] > array[i + 1]) {
                swap(array[i], array[i + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
        for (int i = end - 1; i >= start; --i) {
			if (array[i] > array[i + 1]) {
				swap(array[i], array[i + 1]);
				swapped = true;
            }
        }
    }
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(stop - startyem);
	cout << "затраченное время при помощи shaker sort  " <<  duration.count()<< "  наносекунд" << endl;
}



//Функция для сортировки массива  comb sort
void CombSort(int array[], int size) {
    int swap;
	float k = 1.247, S = size - 1;
	int  count = 0;
	auto startyem = high_resolution_clock::now();
	while (S >= 1)
	{
		for (int i = 0; i + S  < size ; i++)
		{
			if (array[i] > array[int(i + S)])
			{
				swap = array[int(i + S)];
				array[int(i + S)] = array[i];
				array[i] = swap;
			}
		}
		S = S /k;
	}

	while (true)
	{
		for (int i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap = array[i + 1];
				array[i + 1] = array[i];
				array[i] = swap;
			}
			else count++;
		}
		if (count == size- 1)
			break;
		else
			count = 0;
	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(stop - startyem);
	cout << "затраченное время при помощи comb sort  " <<  duration.count()<< "  наносекунд" << endl;


}




//Функция для сортировки массива Insert sort 
void Insertsort(int array[], int size) {
    int i, key, j;
	auto startyem = high_resolution_clock::now();
	for (i = 1; i < size; i++) {
		key = array[i];
		j = i - 1;

		// Сдвигаем элементы массива, которые больше key, на одну позицию вперед
		while (j >= 0 && array[j] > key) {
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(stop - startyem);
	cout << "затраченное время при помощи insert sort  " <<  duration.count()<< "  наносекунд" << endl;

}


//Функция для сортировки массива Quick sort
void QuickSort(int array[], int end, int begin)
{
	int mid;
	int f = begin;
	int l = end;
	mid = array[(f + l) / 2];
	
	while (f < l)
	{
		while (array[f] < mid) f++;
		while (array[l] > mid) l--;
		if (f <= l)
		{
			swap(array[f], array[l]);
			f++;
			l--;
		}
	}
	if (begin < l) 
		QuickSort(array, l, begin);
	if (f < end) 
		QuickSort(array, end, f);
}



//Функция для вывода сортировками
//void sortirovka(int array[], int n){
void outBubbleSort(int array[], int n){
	BubbleSort(array, n);
	cout << "Отсортированный массив при помощи bubble sort:" << endl;
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
	}
}
	
void outShakerSort(int array[], int n){
	ShakerSort(array, n);
	cout << "Отсортированный массив при помощи shaker sort:" << endl;
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
	}
}
	
void outCombSort(int array[], int n){
	CombSort(array, n);
	cout << "Отсортированный массив при помощи comb sort:" << endl;
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
	}
}

void outInsertsort(int array[], int n){
	Insertsort(array, n);
	cout << "Отсортированный массив при помощи insert sort:" << endl;
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
	}
}

void outQuickSort(int array[], int n, int a){
	QuickSort(array, n - 1 , 0);
	cout << "Отсортированный массив при помощи quick sort:" << endl;
    for (int i = 0; i < n ; i++) {
        cout << array[i] << " ";
	}


}

//Функция для  нахождения мин и макс элемента в неотсортированном массиве 
void MaxMin(int array[], int nsorted[], int n) {
    int ma, mi;
  

// Поиск min и max
	auto startyem = high_resolution_clock::now();
	for (int j = 0; j < n - 1; j++) {
		for (int i = 0; i < n - 1 - j; i++) {
			if (nsorted[i] > nsorted[i + 1]) 
				swap(nsorted[i], nsorted[i + 1]);
			
		}
	}
    ma = nsorted[0];
    mi = nsorted[n - 1];
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(stop - startyem);
	cout << "затраченное время на поиск максимального и минимального элементов в массиве в неотсортированном массиве:   " <<  duration.count()<< "  наносекунд" << endl;
	cout << "Максимальный и минимальный элементы для неотсортированного массива: " <<  ma << " " << mi << endl;
// для отсортированного массива
	int max;
	int min;
	auto startyemi = high_resolution_clock::now();
	for (int j = 0; j < n - 1; j++) {
		for (int i = 0; i < n - 1 - j; i++) {
			if (array[i] > array[i + 1]) 
				swap(array[i], array[i + 1]);
			
		}
	}
	min = array[0];
	max = array[n- 1];
	auto stopi = high_resolution_clock::now();
	auto durationi = duration_cast<nanoseconds>(stopi - startyemi);
	cout << "затраченное время на поиск максимального и минимального элементов в массиве в отсортированном массиве:   " <<  duration.count()<< "  наносекунд" << endl;
	cout << "Максимальный и минимальный элементы для отсортированного массива: " << min << ' ' << max << endl;
}

//Функция для нахождения  Среднего значения максимального и минимального 
void FindMedium(int array[], int number){
	int average_value = ((array[0] + array[number - 1]) / 2);
	cout << endl;
	cout << "Среднее значение максимального и минимального значения:" << average_value << endl;
	int count = 0;
	cout << "Индексы элементов, которые равны  сpеднему значению максимального и минимального значения: " << " ";
	auto startyem = high_resolution_clock::now();
	for (int i = 0; i < number; ++i) {
		if (array[i] == average_value){
			cout << i << " ";
			count += 1;
		}
	}

	if (count == 0)
		cout << "Таких значений нет" << endl;
	else
		cout << "Таких значений: " << " " << count << endl;
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(stop - startyem);
	cout << "затраченное время вывод заданных элементов :   " <<  duration.count()<< "  наносекунд" << endl;
}


//Функция, которая выводит количество чисел, которые меньше определенного числа 
void SmallNumber(int array[],int  n) {
	int number;
	int counter = 0;
	cout << "Введите число:" << " ";
	cin >> number;
	for (int i = 0; i < n; i++){
		if (number > array[i]) 
			counter += 1;
	}
	if (counter == 0)
		cout << "Таких чисел нет";
	cout << endl;
	cout << "Количество чисел, которые меньше, чем " << number << " равно " << counter << endl;

}



//Функция, которая выводит количество чисел, которые больше определенного числа числа
void BigNumber(int array[],int  n) {
	int numberB;
	int counterB = 0;
	cout << "Введите число:" << " ";
	cin >> numberB;
	for (int i = 0; i < n; i++){
		if (numberB < array[i]) 
			counterB += 1;
	}
	if (counterB == 0)
		cout << "Таких чисел нет";
	cout << endl;
	cout << "Количество чисел, которые больше, чем " << numberB << " равно " << counterB << endl;

}


//Бинарный поиск

int binarySearch(int arr[], int value, int start, int end) {
    if (end >= start) {
        int mid = start + (end - start) / 2;
        
        if (arr[mid] == value) {
            return mid;
        }
        
        if (arr[mid] > value) {
            return binarySearch(arr, value, start, mid - 1);
        }
        
        return binarySearch(arr, value, mid + 1, end);
    }
    
    return -1;
}
void FindNumber(int array[], int n) {
	int number;
	int ans;
	int number_arr = 0;
	cout << "Введите число для того, чтобы узнать есть ли оно в массиве или нет:" << " ";
	cin >> number;
		for (int i = 0; i < n; i++) {
			if (number == array[i]) {
				number_arr = 1;
				break;
		}
		}

	ans = binarySearch(array, number, 0, n - 1);

	if (ans == -1) {
		cout << "Введенного числа нет в массиве!" << endl;
	}
	else {
		cout << "Введенное число есть в массиве!" << endl;
	}
}


//Функция для перемены мест элементов
void change(int array[], int n) {
	int index1;
	int index2;
	cout << "Введите индексы, которые надо поменять местами:" << " ";
	cin >> index1;
	cout << endl;
	cin >> index2;
	cout << endl;
	auto startyem = high_resolution_clock::now();
	swap(array[index1], array[index2]);
	cout << "Результат перемены:" << endl;
	for (int i = 0; i < n; i++) {
		cout << array[i] << ' ';
	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(stop - startyem);
	cout << endl;
	cout << "затраченное время :   " <<  duration.count()<< "  наносекунд" << endl;
	cout << endl;


}


void idz3(int original[], int arr1[], int arr2[], int size) {
    for (int i = 0; i < size; ++i) {
        if (i % 2 == 0) 
            arr1[i / 2] = original[i]; 
        
		else 
            arr2[i / 2] = original[i]; 
        
    }

	// Обмен значениями нечетных чисел 1-го массива с четными числами 2-го массива

    for (int i = 0; i < size / 2; ++i) {
        if (i % 2 == 1 && i + 1 < size / 2) { 
            swap(arr1[i], arr2[i + 1]); 
        }
    }

    // Делаем все значения второго массива четными
    for (int i = 0; i < size / 2; ++i) {
        if (arr2[i] % 2 != 0) {
            arr2[i] += (arr2[i] > 0) ? -1 : 1; // Если нечетное, делаем четным
        }
    }
}

void counter(int arr1[], int arr2[], int size) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr1[i] > arr2[i]) {
            count++;
        }
    }
    cout <<  count << endl;
}



int main() {
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
	unsigned sortirovka;
    const int SizeAr = 100;
    int notsorted[SizeAr]; 
    int arr[SizeAr]; 
	int arr1[SizeAr / 2];
	int arr2[SizeAr / 2];
    unsigned choose;
    unsigned int start = -99;
	int end = 99;
	srand(time(0));
    Array(arr, SizeAr);

        cout << "Случайно заполненный массив: " << endl;
    for (int i = 0; i < SizeAr; ++i) {
        notsorted[i] = arr[i];

    }
    cout << endl;
	cout << "Доступные задания: " << endl;
	cout << "0. ИДЗ номер 3" << endl;
	cout << "1.Сгенерировать новый массив" << endl;
	cout << "2. Сортировка от меньшего к большему" << endl;
	cout << "3. Поиск минимального и максимального значений" << endl;
	cout << "4. Среднее значение минимального и максимального значения в массиве. Вывод индексов и количества равных этому значению. " << endl;
	cout << "5. Количество чисел, которые меньше, чем заданное число" << endl;
	cout << "6. Количество чисел, которые больше, чем заданное число" << endl;
	cout << "7. Поиск число в массиве" << endl;
	cout << "8. Перемены чисел по индексу" << endl;
    cout << "9. Завершение работы программы" << endl;
    while (true) {
		cout << "Введите номер задания: ";
		cin >> choose;

		switch (choose) {
		case 0:
		idz3(arr, arr1, arr2, SizeAr);
		counter(arr1, arr2, SizeAr/2);
		cout << endl;
		break;
		case 1:
        cout << "Вывод нового массива:" << endl;
			for (int i = 0; i < SizeAr; i++) {
				arr[i] = rand() % (end - start + 1) + start;
				notsorted[i] = arr[i];
				cout << arr[i] << ' ';
			}
			cout << endl;
			break;
        case 2:
		    cout << "Сортировки от меньшего к большему:" << endl;
			while (true) {
				cout << "Выберите, каким способом хотите отсортировать массив: "<< endl;
				cout << "1. Bubble sort" << endl;
				cout << "2. Shaker sort" << endl;
				cout << "3. Comb sort" << endl;
				cout << "4. Inter sort" << endl;
				cout << "5. Quick sort" << endl;
				cin >> sortirovka;

			switch (sortirovka) {
				case 1:
				outBubbleSort(arr, SizeAr);
				cout << endl;
				break;
				case 2:
				outShakerSort(arr, SizeAr);
				cout << endl;
				break;
				case 3:
				outCombSort(arr, SizeAr);
				cout << endl;
				break;
				case 4:
				outInsertsort(arr, SizeAr);
				cout << endl;
				break;
				case 5:
				outQuickSort(arr, SizeAr, 0);
				cout << endl;
				break;
			} 
			break;
		}
		break;
        case 3:
        MaxMin(arr, notsorted, SizeAr);
        break;


		case 4:
		FindMedium(arr,SizeAr);
		break;


		case 5:
		SmallNumber(arr, SizeAr);
		break;


		case 6:
		BigNumber(arr, SizeAr);
		break;

		case 7:
		FindNumber(arr, SizeAr);
		break;

		case 8:
		change(arr, SizeAr);
		break;

        case 9:
		cout << "Вы вышли из программы!!!" << endl;
		return 0;
        }
    }
}



