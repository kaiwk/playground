val firstArgs = if (args.length > 0) args(0) else ""

val hello = firstArgs  match {
  case "hello" => "hello"
  case "world" => "world"
  case _ => "nothing"
}

println(hello)
