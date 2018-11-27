import scala.math._

object ScalaTutorial5{

  def main(args: Array[String]){

    //high order function
    val log10Func = log10 _
    println(log10Func(1000))
    println("==================")

    //map
    List(1000.0, 10000).map(log10Func).foreach(println)

    List(1, 2, 3, 4, 5).map((x: Int) => x * 50).foreach(println)
    println("==================")

    //filter
    List(1, 2, 3, 4, 5).filter(_ % 2 == 0).foreach(println)

    println("==================")

    //pass func as value
    def time3(num: Int) = num * 3
    def time4(num: Int) = num * 4

    def multIt(func: (Int) => Double, num: Int) = {
      func(num)
    }
    printf("3 * 100 = %.1f\n", multIt(time3, 100))
    printf("4 * 100 = %.1f\n", multIt(time4, 100))

    println("==================")

    val divisorVal = 5
    val divisor5 = (num: Double) => num / divisorVal
    printf("5 / 5 = %.1f\n", divisor5(5))
  }

}
