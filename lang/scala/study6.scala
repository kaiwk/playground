class Rational(n: Int, d: Int){
  require(d != 0)
  private val g = gcd(n.abs, d.abs)
  var number: Int = n / g
  var denom: Int = d / g
  override def toString = number + "/" + denom
  def add(that: Rational): Rational =
    new Rational(
      number * that.denom + that.number * denom,
      denom * that.denom
    )
  def this(n: Int) = this(1, n)

  private def gcd(a: Int, b: Int): Int =
    if(b == 0) a else gcd(b, a%b)
}

val a = new Rational(10)
println("a is " + a)
val b = new Rational(-4, 6)
println("b is " + b)
println("a + b is " + (a add b))
