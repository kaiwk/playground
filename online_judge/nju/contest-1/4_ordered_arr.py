n=int(input())
array_num=input()
array1=input()
array_tmp1=array1.strip(" ").split(" ")
list1=[]
for item in array_tmp1:
    list1.append(int(item))
array2=input()
array_tmp2=array2.strip(" ").split(" ")
list2=[]
for item in array_tmp2:
    list2.append(int(item))
# print(n)
# print(list1)
# print(list2)
new_list1=[]
new_list2=[]
for item in list2:
    for i in range(0,len(list1)):
        if item==list1[i]:
            new_list1.append(item)
for i in range(0,len(list1)):
    if list1[i] not in list2:
        new_list2.append(list1[i])
#print(new_list1)
#print(new_list2)
new_list2.sort()
for item in new_list2:
    new_list1.append(item)
for item in new_list1:
    print(item,end=" ")
