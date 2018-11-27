object ScalaTutorial2{
  def main(args: Array[String]){

    //normal function with return type
    def getSum(num1 : Int = 1, num2 : Int = 1) : Int = {
      return num1 + num2
    }
    println("5 + 4 = " + getSum(4, 5))
    println("5 + 4 = " + getSum(num2 = 4, num1 = 5))

    println("=================")

    //without return type
    def sayHi : Unit = {
      println("How are you?")
    }
    sayHi

    println("=================")

    //mutiple parameter
    def getSums(args : Int*) : Int = {
      var sum = 0
      for(i <- args){
        sum += i
      }
      sum
    }
    println("Get Sum: " + getSums(1, 2, 3, 4, 5, 6))

    println("=================")

    // factorial
    def factorial(n : BigInt) : BigInt = {
      if(n <= 1)
        1
      else
        n * factorial(n - 1)
    }
    println("Factorial of 5 is : " + factorial(5))

    println("=================")

    //Array, ArrayBuffer
    // val favNum = new Array[Int](20)
    // val friends = Array("Bob", "Tom", "Marry")
    // friends(0) = "Kermit"
    // println("Best Friends " + friends(0))

    // val friends2 = ArrayBuffer[String]()
    // friends2.insert(0, "Jerry")
    // friends2 += "Mike"
    // friends2 ++= Array("Mark", "Zurk")
    // friends2.insert(1, "animal", "Lion", "Tiger")
    // friends2.remove(1, 2)

    // var friend : String = ""
    // for(friend <- friends2){
    //   println(friend)
    // }

    println("=================")

    //foreach
    val favNum = new Array[Int](20)
    for(i <- 0 to (favNum.length-1)){
      favNum(i) = i
      println(favNum(i))
    }
    val favNumsTimes2 = for(num <- favNum) yield 2 * num
    favNumsTimes2.foreach(println)
    var favNumsDiv4 = for(num <- favNum if num % 4 == 0) yield num / 4
    favNumsDiv4.foreach(println)

    //table
    println("=================")
    val multTable = Array.ofDim[Int](10, 10)
    for(i <- 0 to 9){
      for(j <- 0 to 9){
        multTable(i)(j) = i * j
      }
    }

    for(i <- 0 to 9){
      for(j <- 0 to 9){
        printf("%d : %d = %d\n", i, j, multTable(i)(j))
      }
    }

    println("Sum: " + favNum.sum)
    println("Min: " + favNum.min)
    println("Max: " + favNum.max)

    val sortedNums = favNum.sortWith(_>_)
    println(sortedNums.deep.mkString(", "))


    //collection
    println("=================")
    //Map is immutable!
    val employees = Map("Manager" -> "Kermit Wang", "Secretary" -> "Sue Brown")

    if(employees.contains("Manager")){
      printf("Mananger : %s\n", employees("Manager"))
    }

    //mutable
    val customers = collection.mutable.Map(100 -> "Paul Smith", 101 -> "Sally Smith")
    printf("Cust1 : %s\n", customers(100))
    customers(100) = "Henrry Smith"
    customers(102) = "Jerry Smith"
    for((key, value) <- customers){
      printf("%d : %s\n", key, value)
    }

    // tuple, immutable
    var tupleMarge = (103, "Marge Simpson", 10.25)
    printf("%s owes us $%.2f\n", tupleMarge._2, tupleMarge._3)
    // iterator
    tupleMarge.productIterator.foreach{i => println(i)}
    println(tupleMarge.toString())

  }
}
