import time
def binary_search(arr, x):
    low = 0
    high = len(arr) - 1
    mid = 0
 
    while low <= high:
        mid = (high + low) // 2
 
        # Check if x is present at mid
        if arr[mid] < x:
            low = mid + 1
 
        # If x is greater, ignore left half
        elif arr[mid] > x:
            high = mid - 1
 
        # If x is smaller, ignore right half
        else:
            return mid
        #print("itter")
    # If we reach here, the element was not present
    return -1
file=open("input12.txt","r+")
text=file.read()
print(time.time())
lines=text.split("\n")
#print(lines)
length, summ=lines[0].split(" ")
print(int(length) )
print(int(summ))
if int(length)<1:
    exit("incorrect input")
lines.pop(0)
lines.pop(-1)
lines = [int(numeric_string) for numeric_string in lines]
#print(lines)
#Katram massiva elementam es izmantosu"binary search"algoritmu, lai atrast vai eksiste tads paris kuru veido sis elements, vajag dalit ar 2 jo mums pilnigi vienalga elementu seciba 
i=0
count=0
summ=int(summ)
length=int(length)
while i<(length):
    newsumm=summ-lines[i]
    res=binary_search(lines, newsumm)
    if res!=-1 and res!=lines[i]:
        count=count+1   
    #print(i)
    i=i+1
totalsum=count/2

print(int(totalsum+.999))
print(time.time())
#.12 sekundes input11( 6425 paris)
#