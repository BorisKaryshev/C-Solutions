int binsearch (int searchInt, int *intArray, int lowIndx, int highIndx) {
    if (lowIndx >= highIndx) {
        if (intArray[highIndx] == searchInt)
            return highIndx;
        else if (intArray[lowIndx] == searchInt)
            return lowIndx;
        else
            return -1;
    }
    
    int mid = (lowIndx+highIndx)/2;
    
    if (intArray[mid] == searchInt)
        return mid;
    else if (intArray[mid] > searchInt)
        return binsearch(searchInt, intArray, lowIndx, mid-1);
    else if (intArray[mid] < searchInt)
        return binsearch(searchInt, intArray, mid+1, highIndx);
}