import java.io.PrintWriter
import scala.io.Source

object ScalaTutorial6{

  //file input&output
  def main(args: Array[String]){
    val writer = new PrintWriter("text.txt")
    writer.write("Just some random text...\nSome more random text...")
    writer.close()

    val textFromFile = Source.fromFile("text.txt", "utf-8")
    val lineIterator = textFromFile.getLines
    for(line <- lineIterator){
      println(line)
    }
    textFromFile.close
  }
}
