#pragma once
#include <iostream>
#include <windows.h>
#include <psapi.h>

class SelectionSort {

private:
    const static int FirstSize = 1000;
    const static int SecondSize = 10000;
    const static int ThirdSize = 100000;

public:

    int FirstSelectionSort[FirstSize];

    int SecondSelectionSort[SecondSize];

    int ThirdSelectionSort[ThirdSize];

    void FillFirstArray(int arr[]) {
        for (int i = 0; i < FirstSize; i++) {
            FirstSelectionSort[i] = arr[i];
        }
    }

    void FillSecondArray(int arr[]) {
        for (int i = 0; i < SecondSize; i++) {
            SecondSelectionSort[i] = arr[i];
        }
    }

    void FillThirdArray(int arr[]) {
        for (int i = 0; i < ThirdSize; i++) {
            ThirdSelectionSort[i] = arr[i];
        }
    }

    void selectionSort(int firstarray[], int secondarray[], int thirdarray[]) {
        PROCESS_MEMORY_COUNTERS_EX pmc{};
        GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
        SIZE_T physMemUsedByMe = pmc.WorkingSetSize;

        for (int i = 0; i < FirstSize - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < FirstSize; j++) {
                if (firstarray[j] < firstarray[minIndex]) {
                    minIndex = j;
                }
            }
            int temp = firstarray[i];
            firstarray[i] = firstarray[minIndex];
            firstarray[minIndex] = temp;
        }

        std::cout << "First SelectionSort done" << std::endl;


        for (int i = 0; i < SecondSize - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < SecondSize; j++) {
                if (secondarray[j] < secondarray[minIndex]) {
                    minIndex = j;
                }
            }
            int temp = secondarray[i];
            secondarray[i] = secondarray[minIndex];
            secondarray[minIndex] = temp;
        }

        std::cout << "Second SelectionSort done" << std::endl;

        for (int i = 0; i < ThirdSize - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < ThirdSize; j++) {
                if (thirdarray[j] < thirdarray[minIndex]) {
                    minIndex = j;
                }
            }
            int temp = thirdarray[i];
            thirdarray[i] = thirdarray[minIndex];
            thirdarray[minIndex] = temp;
        }

        std::cout << "Third SelectionSort done" << std::endl;

        std::cout << "SelectionSort RAM USAGE: " << physMemUsedByMe << std::endl;

    }
};

