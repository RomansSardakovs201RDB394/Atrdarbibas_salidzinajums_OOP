#pragma once
#include <iostream>
#include <windows.h>
#include <psapi.h>

class CountingSort {
private:
    const static int FirstSize = 1000;
    const static int SecondSize = 10000;
    const static int ThirdSize = 100000;

public:
    int FirstCountingSort[FirstSize];

    int SecondCountingSort[SecondSize];

    int ThirdCountingSort[ThirdSize];

    void FillFirstArray(int arr[]) {
        for (int i = 0; i < FirstSize; i++) {
            FirstCountingSort[i] = arr[i];
        }
    }

    void FillSecondArray(int arr[]) {
        for (int i = 0; i < SecondSize; i++) {
            SecondCountingSort[i] = arr[i];
        }
    }

    void FillThirdArray(int arr[]) {
        for (int i = 0; i < ThirdSize; i++) {
            ThirdCountingSort[i] = arr[i];
        }
    }

    void countingSort(int firstarray[], int secondarray[], int thirdarray[]) {
        PROCESS_MEMORY_COUNTERS_EX pmc{};
        GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
        SIZE_T physMemUsedByMe = pmc.WorkingSetSize;

        int firstcount[100 + 1] = { 0 };
        int* firstoutput = new int[FirstSize];

        for (int i = 0; i < FirstSize; i++)
            firstcount[firstarray[i]]++;

        for (int i = 1; i <= 100; i++)
            firstcount[i] += firstcount[i - 1];

        for (int i = FirstSize - 1; i >= 0; i--) {
            firstoutput[firstcount[firstarray[i]] - 1] = firstarray[i];
            firstcount[firstarray[i]]--;
        }

        for (int i = 0; i < FirstSize; i++)
            firstarray[i] = firstoutput[i];

        std::cout << "First CountingSort done" << std::endl;

        int secondcount[100 + 1] = { 0 };
        int* secondoutput = new int[SecondSize];

        for (int i = 0; i < SecondSize; i++)
            secondcount[secondarray[i]]++;

        for (int i = 1; i <= 100; i++)
            secondcount[i] += secondcount[i - 1];

        for (int i = SecondSize - 1; i >= 0; i--) {
            secondoutput[secondcount[secondarray[i]] - 1] = secondarray[i];
            secondcount[secondarray[i]]--;
        }

        for (int i = 0; i < SecondSize; i++)
            secondarray[i] = secondoutput[i];

        std::cout << "Second CountingSort done" << std::endl;

        int thirdcount[100 + 1] = { 0 };
        int* thirdoutput = new int[ThirdSize];

        for (int i = 0; i < ThirdSize; i++)
            thirdcount[thirdarray[i]]++;

        for (int i = 1; i <= 100; i++)
            thirdcount[i] += thirdcount[i - 1];

        for (int i = ThirdSize - 1; i >= 0; i--) {
            thirdoutput[thirdcount[thirdarray[i]] - 1] = thirdarray[i];
            thirdcount[thirdarray[i]]--;
        }

        for (int i = 0; i < ThirdSize; i++)
            thirdarray[i] = thirdoutput[i];

        std::cout << "Third CountingSort done" << std::endl;

        std::cout << "CountingSort RAM USAGE: " << physMemUsedByMe << std::endl;

    }
};
