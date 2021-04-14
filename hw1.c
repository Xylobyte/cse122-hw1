#include <stdio.h>

int search(int nums[], int s, int n, int target);
int rotatedsearch(int nums[], int n, int target);
void printarray(int nums[], int n);
int findpivot(int nums[], int s, int n);

int main(){
    int arr1[] = {1, 2, 2, 4, 5, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {4, 5, 6, 7, 0, 1, 2};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    printf("Array 1: ");
    printarray(arr1, n1);
    printf("\nTarget = 2\nIndex = %d\n\n", search(arr1, 0, n1, 2));

    printf("Array 2: ");
    printarray(arr2, n2);
    printf("\nTarget = 6\nIndex = %d\n", rotatedsearch(arr2, n2, 6));
}

void printarray(int nums[], int n){
    printf("[");
    for(int i = 0; i < n; i++){
        printf("%d", nums[i]);
        if(i != n - 1)
            printf(", ");
    }
    printf("]");
}

int search(int nums[], int s, int n, int target){
    int start = s;
    int end = n - 1;

    while(start + 1 < end){
        int mid = start + (end - start) / 2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] < target)
            start = mid;
        else
            end = mid;
    }
    if(nums[start] == target)
        return start;
    else if(nums[end] == target)
        return end;
    return -1;
}

int rotatedsearch(int nums[], int n, int target){
    int p = findpivot(nums, 0, n - 1); 

    if(p == -1) 
        return search(nums, 0, n, target);  //not rotated for some reason
    if(nums[p] == target) 
        return p; 
    if(nums[0] <= target) 
        return search(nums, 0, p, target); 
    return search(nums, p + 1, n, target); 
}

int findpivot(int nums[], int s, int n){
    if(n < s)
        return -1;  //not rotated for some reason
    if(n == s)
        return s;
    int mid = (s + n) / 2;
    if(mid < n && nums[mid] > nums[mid + 1])
        return mid;
    if(mid > s && nums[mid] < nums[mid - 1])
        return (mid - 1);
    if(nums[s] >= nums[mid])
        return findpivot(nums, s, mid - 1);
    return findpivot(nums, mid + 1, n);
} 