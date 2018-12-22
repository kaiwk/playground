T = int(input())

# f = open('input.txt')
# T = int(f.readline())

for _ in range(T):
    N = int(input())
    ARR = [int(i) for i in input().split()]

    # N = int(f.readline())
    # ARR = [int(i) for i in f.readline().split()]

    sorted_arr = sorted(ARR)
    sorted_ix = {}

    for i in range(N):
        sorted_ix[sorted_arr[i]] = i

    cnt = 0

    for i in range(N):
        if ARR[i] == sorted_arr[i]:
            continue

        ix = sorted_ix[ARR[i]]
        ARR[i], ARR[ix] = ARR[ix], ARR[i]
        cnt += 1

    print(cnt)



num=int(input())
for i in range(0,num):
    n=int(input())
    array=input()
    list=[]
    tmp_array=array.strip(" ").split(" ")
    for item in tmp_array:
        list.append(int(item))
    #print(list)
    sum=0
    for q in range(0,len(list)):
        for w in range(q+1,len(list)):
            if list[q]>list[w]:
                sum+=1
    print(sum)

n=int(input())
result=[]
for i in range(0,n):
    num=int(input())
    array=input()
    array_tmp=array.strip(" ").split(" ")
    list1=[]
    list2=[]
    for item in array_tmp:
        list1.append(int(item))
        list2.append(int(item))
    sum=0
    list2.sort()
    for i in range(0,len(list1)):
        if list1[i]!=list2[i]:
            sum+=1
            index=list2.index(list1[i])
            t=list1[i]
            list1[i]=list1[index]
            list1[index]=t
    result.append(sum)
for item in result:
    print(item)
