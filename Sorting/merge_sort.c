void mergeArrays(int *arr, int start, int mid, int end)
{
    int i = start, j = mid+1, k = 0;

    int temp_arr[(end-start)+1];

    while ((i <= mid) && (j <= end)) {

        if (arr[i] < arr[j]) {
            temp_arr[k] = arr[i];
            i++;
        }
        else {
            temp_arr[k] = arr[j];
            j++;
        }

        k++;
    } 
    
    // Copying Remaining Elements of the Left arrat to Temp array
    while (i <= mid) {
        temp_arr[k] = arr[i];

        k++;
        j++;
    }

    // Copying Remaining Elements of the Right array to Temp array
    while (j <= end) {
        temp_arr[k] = arr[j];

        k++;
        j++;
    }


    // Copy Data to Original Array
    i = start; 
    k = 0;
    
    while(i <= end) {
        arr[i] = temp_arr[k];

        k++;
        i++; 
    }
}

void mergeSort(int *arr, int start, int end)
{
    if(start == end)
        return;
    
    int mid = (start + end) / 2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    mergeArrays(arr, start, mid, end);
}

void sort(int *arr, int size)
{
    mergeSort(arr, 0, size-1);
}
