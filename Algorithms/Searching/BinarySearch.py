""" 
search at the mis of the array recursively

mid = floor(low + high) / 2

if searching element is lesser then chnage the high as mid

and if its greater then set low as mid

"""

def binarySearch(self, array, element, low, high):
    mid = (low+high) //2
    if array[mid] == element:
        return mid
    else:
        if mid < element:
            return binarySearch(self, array, element, mid + 1, high)
        else:
            return binarySearch(self, array, element, low, mid)


array = [map(int, input().split())]
ele = int(input())
binarySearch(array,ele, 0, len(array))