import scala.collection.mutable.Map

val hashMap = Map[Int, String]()
hashMap += (1 -> "go to school")
hashMap += (2 -> "find big X on the ground")
hashMap += (3 -> "Big")

print(hashMap(2))

def formatArgs(args: Array[String]) = args.mkString("\n")

println(formatArgs(Array("hello", "how", "are")))
