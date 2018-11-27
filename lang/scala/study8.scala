def withPrintWriter(file: File, op: PrintWriter => Unit){
  val writer = new PrintWriter(file)
  try{
    op(writer)
  }finally{
    writer.close()
  }
}

withPrintWriter(writer => writer.println(new java.util.Date))
