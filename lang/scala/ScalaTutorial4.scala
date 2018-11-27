object ScalaTutorial4{
  def main(args: Array[String]){

    val superman = new Superhero("SuperMan")
    println(superman.fly)
    println(superman.hitByBullet)
    println(superman.ricochet(2500))

  }

  //trait
  trait Flyable{
    def fly: String
  }

  trait BulletProof{
    def hitByBullet: String
    def ricochet(startSpeed: Double): String = {
      return "The bullet is at a speed of %.1f ft/s".format(startSpeed * .75)
    }
  }

  class Superhero(val name: String) extends Flyable with BulletProof{
    def fly = "%s flys through the air".format(this.name)
    def hitByBullet = "The Bullet bounces off of %s.".format(this.name)
  }

}
