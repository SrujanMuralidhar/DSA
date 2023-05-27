#define MAXSIZE 1000000


void bubble_sort(int* a,int n){
    int i,j,temp;
    for(i = 0;i< n - 1;i++){
        for(j = 0;j < n - i -1;j++){
            if(a[j]>a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void selection_sort(int* a,int n){
    int i,j,min;
    for(i = 0; i < n -1 ; i++){
        min = i;
        for(j = i+1;j<n;j++){
            if(a[min] > a[j]) min = j;
        }
        if(min != i){
            a[min] = a[min] + a[i];
            a[i] = a[min] - a[i];
            a[min] = a[min] - a[i];
        }
    }
}

void insertion_sort(int arr[],int n){
    int temp,i,j ;
    for(i = 1;i < n;i++){
        temp = arr[i];
        j = i - 1;
        while(j >=0 && arr[j] > temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void BinaryInsertionSort(int arr[],int n){
    int temp,i,j ;
    for(i = 1;i < n;i++){
        temp = arr[i];
        int pos = BinarySearch(arr,0,j,temp);
        j = i - 1;
        while(j>= pos){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
       
    }
}

void Merge(int arr[],int low ,int mid,int high){
    int brr[MAXSIZE];
    int i = low;
    int j = mid+1;
    int k = low;
    while(i <= mid && j <= high){
        if(arr[i] < arr[j]){
            brr[k++] = arr[i];
            i++;
        }
        else{
            brr[k++] = arr[j];
            j++;
        }
    }
    while(i <= mid){
        brr[k++] = arr[i++];
    }
    while(j <= high){
        brr[k++] = arr[j++];
    }
    
    for(int i = low;i <= high;i++){
        arr[i] = brr[i];
    }


}

void MergeSort(int arr[],int low,int high){
    if(low < high){
        int mid = (low + high)/2;
        MergeSort(arr,low,mid);
        MergeSort(arr,mid + 1 , high);
        Merge(arr,low,mid,high);

    }
    
}


int partition(int arr[],int low,int high){
    int i = low;
    int j = high;
    int pivot = arr[low];         // considering the first element to be the pivot
    while(i < j){
        while(i<=high && arr[i] <= pivot){
            i++;
        }
        while(j>=low && arr[j] > pivot){
            j--;
        }
        if(i<j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp =  arr[j];
    arr[j] = pivot;
    arr[low] = temp;
    return j;
    

}

void QuickSort(int arr[],int low,int high){
    int pivot_pos;
    if(low < high){
        pivot_pos = partition(arr,low,high);
        QuickSort(arr,low,pivot_pos-1);
        QuickSort(arr,pivot_pos+1,high);
    }
}


int BinarySearch(int arr[],int low,int high,int ele){
    if(low > high) return -1;
    int mid = (low + high)/2;
    if(arr[mid] == ele) return mid;
    else if(arr[mid] < ele) return BinarySearch(arr,0,mid-1,ele);
    else return BinarySearch(arr,mid+1,high,ele);
}

void Heapify(int arr[],int n){
    int parent,child,vertex;
    for(int i = n/2-1;i>=0;i--){
        bool heap = false;
        parent  = i;
        vertex = arr[parent];
        while(!heap && 2*parent+1 < n){
            child = 2*parent+1;
            if(child+1 < n && arr[child + 1] > arr[child]){     //comparing the left and the right child 
                child = child+1;
            }
            if(vertex < arr[child]){                // comparing the parent and the child value
                arr[parent] = arr[child];
                parent = child;
            }
            else{
                heap = true;
            }
        }
        arr[parent] = vertex;
    }

}

void HeapSort(int arr[],int n){
    if(n == 1) return ;
    int temp = arr[n-1];
    arr[n-1] = arr[0];
    arr[0] = temp;
    Heapify(arr,n-1);
    HeapSort(arr,n-1);
}