
//val变量不能被重新赋值
val greetingStrings = new Array[String](3)

greetingStrings(0) = "hello"
greetingStrings(1) = "world"
greetingStrings(2) = "!\n"

for(i <- 0 to 2)
  print(greetingStrings(i))

val list = List(1, 2)
val list2 = 0 :: list
val list3 = 1 :: 2 :: 3 :: Nil
println(list2)
println(list3)

val pair = (99, "Hello")
print(pair._1)
print(pair._2)
