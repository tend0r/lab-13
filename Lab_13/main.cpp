#include "func.h"

int main()
{
	system("color 3");
	SetConsoleCP(RU);
	SetConsoleOutputCP(RU);
	srand(time(0));

	int taskChoise;

	while (true)
	{
		system("cls");

		cout << "Select one of the following items:" << endl;
		cout << "1. Task 1" << endl;
		cout << "0. Exit" << endl;
		cout << "--> ";
		cin >> taskChoise;

		system("cls");

		switch (taskChoise)
		{
		case 1:
		{
			int rows;
			int cols;

			cout << "Enter count of rows --> ";
			cin >> rows;
			cout << "Enter count of columns --> ";
			cin >> cols;

			while (sizeCheck(rows, cols))
			{
				system("cls");

				cout << "Invalid values. Try again." << endl;

				system("pause");
				system("cls");

				cout << "Enter count of rows --> ";
				cin >> rows;
				cout << "Enter count of columns --> ";
				cin >> cols;

			}

			float** arr = new float* [rows];

			if (MemoryCheck(arr))
			{
				cout << "Error." << endl;
				system("pause");
				return 0;
			}

			for (int i = 0; i < rows; i++)
			{
				arr[i] = new float[cols];
				if (!arr)
				{
					cout << "Error." << endl;
					system("pause");
					return 0;
				}
			}

			cout << "Enter values: " << endl;

			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					cout << "--> ";
					cin >> arr[i][j];
				}
			}

			cout << endl;

			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					cout << arr[i][j] << '\t';
				}
				cout << endl;
			}

			float sum = 0;
			int count = 0;

			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					sum += arr[i][j];
					count++;
				}
			}

			sum /= count;
			cout << endl << "Arithmetic mean: " << sum << endl;

			int sq;
			float sumD = 0;

			(rows > cols) ? (sq = cols) : (sq = rows);

			for (int i = 0; i < sq; i++)
			{
				if (arr[i][i] > sum)
				{
					sumD += arr[i][i];
				}
			}

			cout << endl << "Sum: " << sumD << endl;

			int x;
			float mul = 1;

			cout << endl << "Enter x" << endl;
			cout << "--> ";
			cin >> x;

			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					if (arr[i][j] != arr[i][i] && arr[i][j] != x)
					{
						mul *= arr[i][j];
					}
				}
			}

			cout << endl << "Mul: " << mul << endl;

			float maxElem = arr[0][0];

			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					if (arr[i][j] > maxElem)
					{
						maxElem = arr[i][j];
					}
				}
			}

			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					if (arr[i][j] == maxElem)
					{
						arr[i][j] = sum;
					}
				}
			}

			cout << endl << "Max: " << maxElem << endl;

			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					cout << arr[i][j] << '\t';
				}
				cout << endl;
			}

			int count_2 = 0;

			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					if (arr[i][j] > sum && arr[i][j] != arr[i][i])
					{
						count_2++;
					}
				}
			}

			cout << endl << "Count: " << count_2 << endl;

			for (int i = 0; i < rows; i++)
			{
				delete[] arr[i];
			}
			delete[] arr;

			break;
		}
		case 0:
		{
			return 0;
		}
		default:
			cout << "There is no such item in the menu" << endl;
			break;
		}

		system("pause");
	}

}
