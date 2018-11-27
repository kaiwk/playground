object FileMatcher{

  private def filesHere = (new java.io.File(".")).listFiles


  // def filesContaining(query: String) =
  //   for (file <- filesHere if file.getName.contains(query))
  //     yield file

  // def filesRegex(query: String) =
  //   for (file <- filesHere if file.getName.matches(query))
  //     yield file

  // def filesEnding(query: String) =
  //   for(file <- filesHere if file.getName.endsWith(query))
  //     yield file

  def filesMatching(query: String, matcher: (String, String) => Boolean) =
    for (file <- filesHere if matcher(file.getName, query))
      yield file

  def filesEnding(query: String) =
    filesMatching(query, _.endsWith(_))

  def filesContaining(query: String) =
    filesMatching(query, _.contains(_))
}

// FileMatcher.filesEnding(".scala").foreach(x => println(x.getName))
FileMatcher.filesContaining("hello").foreach(x => println(x.getName))

