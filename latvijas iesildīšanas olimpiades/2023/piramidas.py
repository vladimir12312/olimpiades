import math
def cubesum(augstums):
    return (augstums+augstums*augstums)/2
def calculatehighestpyr(cubes):
    varianti=0
    augstumi=[]
    while cubes>=1:
        #print("new cycle")
        #klucišu sk. var apreķināt ar arit. progresijas formulu kluciši=n*((1+n)/2)
        # ->kl=n/2+n^2/2->2*kl=n+n^2->n^2+n-2kl=0 pēc diskriminanta D=b^2-4ac
        #Pēc diskriminanta: D=1-4(-2kl)=1+8kl
        #Reķinam saknes: n1=(-1+sqrt(9kl))/2 n2-neder, jo negativs-> rakstam kodu
        augstums=(-1+math.sqrt(1+(8*cubes)))/2
        #tomēr tās neobligati būs vesels skaitlis
        #vai nu round(augstums-.5)
        augstums=int(augstums)#jo int() atmet visus skaitļus pec komata
        #talak apreķinam izmantotos klucišus
        #print(augstums)
        izmkluciši=augstums*((1+augstums)/2)
        cubes=cubes-izmkluciši
        augstumi.append(int(augstums))
        varianti=varianti+1
        #print("cubesleft "+str(cubes))
        #kamer paliek kl>0 atkartojam
    print(varianti)
    for augstums in augstumi:
        print(augstums,end=" ")
def calculatesmallestamount(cubes):
    #iespejamie izmantoti kluciši:S=n*((1+n)/2) ->visus tos vertībus varam izvest sarakstā:neveiksmīga idejas->memory error
    #2cubes=a+a^2+b+b^2.....+x+x^2 atrast tadu naturalo skaitļu skaitu lai varētu izteikt 2 cubes
    #vajag atrast tadu polinomu kuram būs vismazak saskaitamo, saksim ar vienu, pec tam divas u.t.t
    possiblevalues=[]
    lastvalue=0
    augstumsc=1

    augstumsmax=(-1+math.sqrt(1+(8*cubes)))/2
    Summa= (augstumsmax+augstumsmax*augstumsmax)
    if Summa<cubes:
        Summa= augstumsmax

    if Summa==cubes:
        print(1)
        print(augstumsmax)
        exit()
    i=0
    augstumsr = augstumsmax
    while True:

        summa=cubesum(augstumsr)+cubesum(augstumsr-i)

        if summa==cubes:
            print("success")
            print(2)
            print(i)
            print(str(augstumsr)+" "+str(augstumsr-i))
            exit()
        if summa<cubes:
            print("decrease augstumsr")
            augstumsr=augstumsr-1
            i=0
            if augstumsr<1:
                print(3)
                print("6+ +5+ +1")
                i=0
                y=0
                exit()
                #utt taču baigi ilgi rakstīt, vajag padomāt ka saisīnāt kodu
        i = i + 1
print("sadasdas")
input1=input("input cubes")
input1=int(input1)
calculatehighestpyr(input1)#darbojas ideali pat ja N>10^9
calculatesmallestamount(input1) #darbojas ātri un visticimāk tuvi atrisinajumam, vismaz var noteikt vai var uzbūvet ar 2 piramīdam,ja uzlabot veseliem skaitļiem


