#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

// Globalization functions.
// --------------------------------------------------------------------------------------
// Enter
void enterLobby();
void enterCalculator();

// Mode
void ModeSum(int numbers[], int size);
void ModeAvg(int numbers[], int size);
void ModeSort(int numbers[], int size);

// Utility
void swapValue(int &a, int &b);
void sortArr(int numbers[], int size);
void sortArrInvert(int numbers[], int size);

// Mathematical
int sumNumbers(int numbers[], int size);
int avgNumbers(int numbers[], int size);

// Display
void inputArr(int numbers[], int size);
void outputArr(int numbers[], int size);
// --------------------------------------------------------------------------------------


// main Function.
void main()
{
    while (true)
    {
        // Welcome kit
         cout << "---------------------------" << endl;
         cout << "-------배열 계산기------" << endl;
         cout << "---------------------------" << endl;

        // Lobby
        enterLobby();

        return;
    }
}

// Enter
// --------------------------------------------------------------------------------------
void enterLobby()
{
    while (true)
    {
        // Guide Enter.
        cout << "(1)계산기 (2)종료" << endl;
        cout << ">" << endl;
        int choice;
        cin >> choice;

        // Process enter or end
        if (choice == 1)
            enterCalculator();
        else if (choice == 2)
        {
            cout << "----------------------" << endl;
            cout << "산술기를 종료합니다." << endl;
            return;
        }
        
        // Exception : process other number that player input
        else
        {
            cout << "----------------------" << endl;
            cout << "다른 메뉴를 입력하셨습니다." << endl;
            cout << "----------------------" << endl;
        }
    }
}

void enterCalculator()
{
    while (true)
    {
        // Numbers arrary
        const int size = 5;
        int numbers[size];

        //Receieve numbers through console.
        inputArr(numbers, size);

        // Select caculatate mode

        while (true)
        {
            outputArr(numbers, size);
            
            int choice;
            cout << "------------------------------------------" << endl;
            cout << "(1)합계 (2)평균 || (9)배열 정렬 (0)배열 재설정" << endl;
            cout << ">" << endl;
            cin >> choice;

            // Switch mode into 1 = sum, 2 = min, 3 = sort, other = [choice again]
            if (choice == 1)
                ModeSum(numbers, size);
            else if (choice == 2)
                ModeAvg(numbers, size);
            else if (choice == 9)
                ModeSort(numbers, size);
            else if (choice == 0)
            {
                cout << "---------------------------------" << endl;
                cout << "숫자 배열을 다시 설정합니다." << endl;
                break;
            }
            else
            {
                cout << "--------------------------" << endl;
                cout << "다른 모드를 입력하셨습니다." << endl;
                cout << "--------------------------" << endl;
            }
            cout << "----------------------------------------" << endl;
            cout << "설정된 배열을 바탕으로 계산을 다시 시작합니다." << endl;
        }
    }
}

void ModeSum(int numbers[], int size)
{
    int sum = sumNumbers(numbers,size);
    cout << size << "개 숫자 배열의 합계는 [" << sum << "] 입니다." <<endl;
}

void ModeAvg(int numbers[], int size)
{
    int min = avgNumbers(numbers,size);
    cout << size << "개 숫자 배열의 평균은 [" << min << "] 입니다." <<endl;
}

void ModeSort(int numbers[], int size)
{
    while (true)
    {
        cout << "----------------------" << endl;
        cout << "--------정렬 모드-------" << endl;
        cout << "----------------------" << endl;
        int choice;
        cout << "(1)오름차순 (2)내림차순" << endl;
        cout << ">" << endl;
        cin >> choice;

        // Select detail mode
        if (choice == 1)
        {
            sortArr(numbers, size);
        }
        else if (choice == 2)
        {
            sortArrInvert(numbers, size);
        }

        // Display numbers.
        outputArr(numbers, size);
        return;
    }
}

// --------------------------------------------------------------------------------------


// Utility
// --------------------------------------------------------------------------------------
void swapValue(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void sortArr(int numbers[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            // i(선발 숫자)가 j(후발 숫자)보다 클 경우,
            if (numbers[j] < numbers[i])
            {
                swapValue(numbers[i], numbers[j]);
            }
        }
    }
}

void sortArrInvert(int numbers[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            // i(선발 숫자)가 j(후발 숫자)보다 클 경우,
            if (numbers[j] > numbers[i])
            {
                swapValue(numbers[i], numbers[j]);
            }
        }
    }
}
// --------------------------------------------------------------------------------------


// Mathematical
// --------------------------------------------------------------------------------------
int sumNumbers(int numbers[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += numbers[i];
    }
    return sum;
}

int avgNumbers(int numbers[], int size)
{
    int min = (sumNumbers(numbers, size)/size);
    return min;
}
// --------------------------------------------------------------------------------------


// Display
// --------------------------------------------------------------------------------------
void inputArr(int numbers[], int size)
{
    // let's receive input values thorough console typing.
    cout << "----------------------------------------" << endl;
    cout << "숫자 " << size << "개를 각각 입력해주십시오." << endl;
    for (int i = 0; i < size; i++)
    {
        cout << ">" << endl;
        cin >> numbers[i];
    }
}

void outputArr(int numbers[], int size)
{
    cout << "현재 배열은 [";
    for (int i = 0; i < size; i++)
    {
        if (i < size - 1)
            cout << numbers[i] << ", ";
        else
            cout << numbers[i];
    }
    cout << "] 입니다." << endl;
}
// --------------------------------------------------------------------------------------

