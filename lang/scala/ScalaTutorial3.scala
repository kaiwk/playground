object ScalaTutorial3{

  def main(args: Array[String]){

    val rover = new Animal
    rover.setName("Rover")
    rover.setSound("Woof")
    printf("%s says %s\n", rover.name, rover.sound)

    println("=================")
    val whisker = new Animal("Whisker", "Meow")
    println(s"${whisker.name} with id ${whisker.id} says ${whisker.sound}")
    println(whisker.toString)

    println("=================")
    val spike = new Dog("Spike", "Woof", "Grrrr")
    spike.setName("Spike")
    println(spike.toString)

    println("=================")
    val fang = new Wolf("Fang")
    fang.moveSpeed = 36.0
    println(fang.move)

  }

  //default constructor
  class Animal(var name: String, var sound: String){
    this.setName(name)

    val id = Animal.newIdNum

    //can be accessed by subclass
    // protected var name = "No Name"

    def getName(): String = name
    def getSound(): String = sound

    def setName(name: String) = {
      if(!(name.matches(".*\\d+.*"))){
        this.name = name
      }else{
        this.name = "No name"
      }
    }

    def setSound(sound: String){
      this.sound = sound
    }


    //other constructors
    def this(name: String){
      this("No name", "No sound")
      this.name = name
    }

    def this(){
      this("No name", "No sound")
    }

    override def toString(): String = {
      return "%s with the id %d says %s.\n".format(this.name, this.id, this.sound)
    }
  }

  // static attributes defined in 'object'
  object Animal{
    private var idNumber = 0
    private def newIdNum = { idNumber += 1; idNumber }
  }

  //inherit
  class Dog(name: String, sound: String, growl: String) extends Animal(name, sound){

    def this(name: String, sound: String){
      this("No name", sound, "No growl")
      this.setName(name)
    }

    def this(name: String){
      this("No name", "No Sound", "No growl")
      this.setName(name)
    }

    def this(){
      this("No name", "No sound", "No growl")
    }

    override def toString(): String = {
      return "%s with the id %d says %s.\n".format(this.name, this.id, this.growl)
    }
  }


  //abstrac class
  abstract class Mammal(val name: String) {

    var moveSpeed: Double

    def move: String
  }

  class Wolf(name: String) extends Mammal(name){
    var moveSpeed = 35.0

    def move = "The wolf %s run %.2f mph".format(this.name, this.moveSpeed)
  }

}

