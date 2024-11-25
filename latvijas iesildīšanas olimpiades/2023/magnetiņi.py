def calculatelowest():
    #vajag nokartot datus sarakstā, tomēr tad ir jautajums vai pietiks atmiņas:
    numbers=[]
    number1=[]
    number2=[]
    for char in input1:
        int(char)
        numbers.append(int(char))
    appendamount=len(numbers)+1
    i=1
    while i<appendamount:
        numbers.append(0)#vajadzes labot ja numbers jau satur 0
        i=i+1
    numbers.sort()
    #tagad iedomasimies 2 ciparus kā sarakstus, kuriem indeksu sk ir vienāds ar max cip. sk.
    x=0
    for number in numbers:
        if x%2==1:
            number1.append(number)
        if x%2==0:
            number2.append(number)
        x=x+1
    i=1
    number1int=0
    while i<=len(number1):
        number1int=number1[-i]*pow(10,i-1)+number1int
        i=i+1
    i=1
    number2int=0
    while i<=len(number2):
        number2int=number2[-i]*pow(10,i-1)+number2int
        i=i+1
    #varētu izdarīt papildus parbaudi,ja ievaddatos ir 0, un mainīt vietas nepieciešamo 0 skaitu lai iegūt pareizo rezultātu
    print(numbers)
    print(number1)
    print(number2)
    print(number2int+number1int)
input1=input("input")
calculatelowest()#ideali darbojas, ja ievaddatos nav 0(50)
