
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

// Function for simple definition of matrix and vector elements
void DummyDataInitialization(double* pMatrix, double* pVector, int Size) {
    int i, j; // Loop variables
    for (i = 0; i < Size; i++) {
        pVector[i] = 1;
        for (j = 0; j < Size; j++)
            pMatrix[i * Size + j] = i;
    }
}
// Function for random definition of matrix and vector elements
void RandomDataInitialization(double* pMatrix, double* pVector, int Size) {
    int i, j; // Loop variables
    srand(unsigned(clock()));
    for (i = 0; i < Size; i++) {
        pVector[i] = rand() / double(1000);
        for (j = 0; j < Size; j++)
            pMatrix[i * Size + j] = rand() / double(1000);
    }
}
// Function for memory allocation and definition of object's elements
void ProcessInitialization(double*& pMatrix, double*& pVector, double*& pResult, int& Size) {
    // Size of initial matrix and vector definition
    /*do {
        printf("\nEnter size of the initial objects: ");
        scanf_s("%d", &Size);
        printf("\nChosen objects size = %d\n", Size);
        if (Size <= 0)
            printf("\nSize of objects must be greater than O!\n");
    } while (Size <= 0);*/
    // Memory allocation
    pMatrix = new double[Size * Size];
    pVector = new double[Size];
    pResult = new double[Size];
    // Definition of matrix and vector elements
    DummyDataInitialization(pMatrix, pVector, Size);
}
// Function for formatted matrix output
void PrintMatrix(double* pMatrix, int RowCount, int ColCount) {
    int i, j; // Loop variables
    for (i = 0; i < RowCount; i++) {
        for (j = 0; j < ColCount; j++)
            printf("%7.4f", pMatrix[i * RowCount + j]);
        printf("\n");
    }
}
// Function for formatted vector output
void PrintVector(double* pVector, int Size) {
    int i;
    for (i = 0; i < Size; i++)
        printf("%7.4f\n", pVector[i]);
}
// Function for matrix-vector multiplication
void ResultCalculation(double* pMatrix, double* pVector, double* pResult, int Size, int iMatrix) {
    int i, j, m = 0; // Loop variables
    for (i = 0; i < iMatrix; i++) {
        pResult[i] = 0;
        for (j = 0; j < Size; j++)
            pResult[i] += pMatrix[m++] * pVector[j];
    }
}
// Function for computational process termination
void ProcessTermination(double* pMatrix, double* pVector, double* pResult) {
    delete[] pMatrix;
    delete[] pVector;
    delete[] pResult;
}

void StreamSeparator(double* pMatrix, double* pVector, double* pResult, int Size, int Stream) {
    int streamCounts = (Size - 1) / Stream + 1;
    int q = streamCounts;
    for (int i = 0; i < Stream; i++)
    {
        if (i == Stream - 1)
        {
            q = Size - i * streamCounts;
        }
        ResultCalculation(pMatrix + i * streamCounts * Size, pVector, pResult + i * streamCounts, Size, q);
        //PrintMatrix(pMatrix + i * streamCounts * Size, q, Size);
        //printf("%d\t%d\t%d\n", i * streamCounts * Size, i * streamCounts, q);
    }
}

int main() {
    double* pMatrix; // The first argument - initial matrix
    double* pVector; // The second argument - initial vector
    double* pResult; // Result vector for matrix-vector multiplication
    int Size = 10;
    time_t start, finish;
    double duration;
    // Sizes of initial matrix and vector
    printf("Serial matrix-vector multiplication program\n");
    // Memory allocation and definition objects' elements
    ProcessInitialization(pMatrix, pVector, pResult, Size);
    // Matrix and vector output
    printf("Initial Matrix \n");
    PrintMatrix(pMatrix, Size, Size);
    printf("Initial Vector \n");
    PrintVector(pVector, Size);
    // Matrix-vector multiplication*/
    start = clock();

    int Streams = 3;
    StreamSeparator(pMatrix, pVector, pResult, Size, Streams);

    finish = clock();
    duration = (finish - start) / double(CLOCKS_PER_SEC);
    // Printing the result vector
    printf("\n Result Vector: \n");
    PrintVector(pResult, Size);
    // Printing the time spent by matrix-vector multiplication
    printf("\n Time of execution: %f\n", duration);
    // Computational process termination
    ProcessTermination(pMatrix, pVector, pResult);
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

