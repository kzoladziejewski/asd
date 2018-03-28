
def sito(m):

    lista=[0]
    for i in range(1,m+1,1):
        lista=lista+[1]


    i=1
    p=3
    q=4
    while q <=m:
        if lista[i] != 0:
            j = q
            while j <= m:
                lista[j]=0
                j=j+p

        i=i+1
        p=p+2
        q=q+2*(p-1)

    for a in range(0, len(lista)):
            print(a, lista[a])

sito(100)