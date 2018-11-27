object ScalaTutorial1{
  def main(args: Array[String]){
    var i = 0

    //List Generator
    var evenList = for{i <- 1 to 20 if i % 2 == 0} yield i

    for(i <- evenList){
      println(i)
    }

    println("=======================")

    // Mutiple iteration
    for( i <- 1 to 5; j <- 6 to 10){
      println(i);
      println(j);
    }

    println("=======================")

    // get prime from 1 to 10
    def printPrimes(){
      val primeList = List(1, 2, 3, 5, 7, 11)
      for(i <- primeList){
        if(i == 11){
          return
        }
        if(i != 1){
          println(i)
        }
      }
    }
    printPrimes()

    println("=======================")

    //input / output
    var GuessNumber = 0
    do{
      println("Guess a number:")
      GuessNumber = readLine.toInt

    }while(GuessNumber != 15)

    printf("You guessed the number %d\n", 15)

    println("=======================")

    val name = "Kermit"
    val age = 20
    val weight = 175.5

    println(s"Hello, $name")
    println(f"I am ${age + 1} and weight $weight%.2f")

    println("=======================")
    printf("'%05d'\n", 5)
    printf("'%-5d'\n", 5)
    printf("%.5f\n", 3.14)
    printf("'%5s'\n", "Hi~")


    println("=======================")

    //String
    val randSent = "Hello, How are you?"
    println("3rd index of: " + randSent(3))
    println("Length of string: " + randSent.length)
    println(randSent.concat(" I'm fine."))
    println("are starts at index " + randSent.indexOf("are"))

    val randSentArray = randSent.toArray
    for(i <- randSentArray){
      println(i)
    }

  }
}
