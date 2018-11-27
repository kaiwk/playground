class Solution:
    # @param {int[]} A an integer array
    # @return nothing
    def sortIntegers(self, A):
        # Write your code here
        # self.bubbleSort(A)
        # self.insertionSort(A)
        self.selectionSort(A)

    def bubbleSort(self, A):
        for i in range(len(A)-1):
            for j in range(i+1, len(A)):
                if A[i] > A[j]:
                    temp = A[i]
                    A[i] = A[j]
                    A[j] = temp

    def insertionSort(self, A):
        for i in range(1, len(A)):
            cur = A[i]
            j = i-1
            while j >= 0 and cur < A[j]:
                A[j+1] = A[j]
                j -= 1
            A[j+1] = cur

    def selectionSort(self, A):
        for i in range(len(A)-1):
            minimum = float('inf')
            index = -1
            for j in range(i, len(A)):
                if A[j] < minimum:
                    minimum = A[j]
                    index = j
            A[index] = A[i]
            A[i] = minimum
