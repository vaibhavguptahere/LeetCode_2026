class Solution {
public:
    void merge(vector<int>& arr, int start, int mid, int end) {
        // temporary array
        vector<int> temp;
        // left half
        int i = start;
        // right half
        int j = mid + 1;

        // main loop -- Smaller element goes into temp
        while (i <= mid && j <= end) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i]);
                i++;
            } else {
                temp.push_back(arr[j]);
                j++;
            }
        }

        //left
        while (i <= mid) {
            temp.push_back(arr[i]);
            i++;
        }

        //right
        while (j <= end) {
            temp.push_back(arr[j]);
            j++;
        }

        // copy back to the original array
        for (int idx = 0; idx < temp.size(); idx++) {
            arr[idx + start] = temp[idx];
        }
    }

    void mergeSort(vector<int>& arr, int start, int end) {
        // main function
        if (start < end) {
            int mid = start + (end - start) / 2;

            // divide
            mergeSort(arr, start, mid); // left part
            mergeSort(arr, mid + 1, end); // right part
            
            //merge both left and right parts 
            merge(arr, start, mid, end); 
        }
    }

    vector<int> sortArray(vector<int>& arr) {
        int start = 0; 
        int end = arr.size() - 1;

        mergeSort(arr, 0, arr.size() - 1);
        return arr;
    }
};