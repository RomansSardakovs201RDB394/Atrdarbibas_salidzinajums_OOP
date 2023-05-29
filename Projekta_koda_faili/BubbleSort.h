#pragma once
#include <iostream>
#include <windows.h>
#include <psapi.h>

class BubbleSort {
private:
    const static int FirstSize = 1000;
    const static int SecondSize = 10000;
    const static int ThirdSize = 100000;

public:

    int FirstBubbleSort[FirstSize];

    int SecondBubbleSort[SecondSize];

    int ThirdBubbleSort[ThirdSize];

    void FillFirstArray(int arr[]) {
        for (int i = 0; i < FirstSize; i++) {
            FirstBubbleSort[i] = arr[i];
        }
    }

    void FillSecondArray(int arr[]) {
        for (int i = 0; i < SecondSize; i++) {
            SecondBubbleSort[i] = arr[i];
        }
    }

    void FillThirdArray(int arr[]) {
        for (int i = 0; i < ThirdSize; i++) {
            ThirdBubbleSort[i] = arr[i];
        }
    }

    void bubbleSort(int firstarray[], int secondarray[], int thirdarray[]) {
        PROCESS_MEMORY_COUNTERS_EX pmc{};
        GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
        SIZE_T physMemUsedByMe = pmc.WorkingSetSize;

        for (int i = 0; i < FirstSize - 1; i++) {
            for (int j = 0; j < FirstSize - i - 1; j++) {
                if (firstarray[j] > firstarray[j + 1]) {
                    int temp = firstarray[j];
                    firstarray[j] = firstarray[j + 1];
                    firstarray[j + 1] = temp;
                }
            }
        }

        std::cout << "First BubbleSort done" << std::endl;

        for (int i = 0; i < SecondSize - 1; i++) {
            for (int j = 0; j < SecondSize - i - 1; j++) {
                if (secondarray[j] > secondarray[j + 1]) {
                    int temp = secondarray[j];
                    secondarray[j] = secondarray[j + 1];
                    secondarray[j + 1] = temp;
                }
            }
        }

        std::cout << "Second BubbleSort done" << std::endl;

        for (int i = 0; i < ThirdSize - 1; i++) {
            for (int j = 0; j < ThirdSize - i - 1; j++) {
                if (thirdarray[j] > thirdarray[j + 1]) {
                    int temp = thirdarray[j];
                    thirdarray[j] = thirdarray[j + 1];
                    thirdarray[j + 1] = temp;
                }
            }
        }

        std::cout << "Third BubbleSort done" << std::endl;

        std::cout << "BubbleSort RAM USAGE: " << physMemUsedByMe << std::endl;

    }
};
