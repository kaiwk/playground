class Example {

    String instanceVar = "my var"

    static classVar = "Class Var"

    static def datatype() {
        //Example of a int datatype
        int x = 5;

        //Example of a long datatype
        long y = 100L;

        //Example of a floating point datatype
        float a = 10.56f;

        //Example of a double datatype
        double b = 10.5e40;

        //Example of a BigInteger datatype
        BigInteger bi = 30g;

        //Example of a BigDecimal datatype
        BigDecimal bd = 3.5g;

        println(x);
        println(y);
        println(a);
        println(b);
        println(bi);
        println(bd);
    }

    static def type_inference() {
        def a = 100
        println(a)
    }

    static def looping() {
        for (i in 1..5) {
            println(i)
        }
    }

    public def setInstanceVar(String var) {
        this.instanceVar = var
    }

    public def getInstanceVar() {
        return this.instanceVar
    }

    // template literal
    static testFileAndDirectory() {
        def file = new File("~/Documents")
        println "File? ${file.isFile()}"
        println "Directory? ${file.isDirectory()}"
    }

    static repeatString(){
        String rpstring = "Hello " * 3
        return rpstring
    }

    static def formatPrint() {
        String str = "Hello, World!"
        println("A $str string\n")
        printf("A %s string\n", str)
    }

    // IO
    static def getInputFromConsole() {
        println("Enter a Number: ")
        def num1 = System.console().readLine().toDouble()
        println("Enter a Number: ")
        def num2 = System.console().readLine().toDouble()

        printf("%.2f + %.2f = %.2f\n", [num1, num2, (num1 + num2)])
    }

    // high level data structure
    static def listDemo() {
        def primes = [2, 3, 5, 7, 11, 13]

        println("2nd Prime " + primes[1])
        println("3nd Prime " + primes.get(2))

        def misc = [1, 2, 3, "hello", [1, 2, 3]]

        println("2nd Number " + misc[3][1])

        println("length of primes: " + primes.size())

        // << is the same as `add`
        primes << 17
        primes.add(19)

        // concatenate
        primes += [23, 29]

        // get rid of [2, 3], more intuitive
        primes -= [2, 3]

        println(primes)
        println("primes is empty? ${primes.isEmpty()}")
        println(primes[2..4])

        // intersect
        println(primes.intersect([1, 2, 3, 4, 5]))

        // reverse, sort
        println(primes.reverse())
        println(primes.sort())

        // pop
        println(primes.pop())
    }

    static def mapDemo() {
        def demoMap = [
            'name': 'kermit',
                       'age': 20,
                       'address': '123 Main st',
                       'list': [1, 2, 3]
        ]

        println("Name: " + demoMap['name'])
        println("Age: " + demoMap.get('age'))
        println("List Item: " + demoMap['list'][2])

        demoMap.put('city', 'shanghai')
        println("Has city " + demoMap.containsKey('city'))
        println("Map size: " + demoMap.size())
    }

    // flow contral: if-else statement, loop

    static def getSum(num1=0, num2=0) {
        return num1 + num2
    }

    static def rangeDemo() {
        def oneToTen = 1..10
        println(oneToTen)

        def aToZ = 'a'..'z'
        def zToA = 'z'..'a'
        println(zToA)
        println(aToZ)

        println(zToA.getFrom())
        println(zToA.getTo())
    }

    static def doubleList(list) {
        def newList = list.collect { it * 2 }
        return newList
    }

    static def sumAll (int...num) {
        int sum = 0
        num.each { sum += it }
        return sum
    }

    static void main(String[] args) {
        // datatype()
        // type_inference()
        // looping()

        // data abstract: class
        // Example ex1 = new Example()
        // ex1.setInstanceVar("still my var")
        // println(ex1.getInstanceVar())
        // testFileAndDirectory()

        // println(repeatString())

        // formatPrint()

        // getInputFromConsole()

        // listDemo()

        // mapDemo()

        // rangeDemo()

        // default parameter
        // println(getSum())

        // println doubleList([1, 2, 3, 4])

        // println sumAll(1, 2, 3, 4)

        // println(getFactorial(4))

        // listOperation()

        // file
        new File("test.txt").eachLine {
            line -> println "$line"
        }

        new File("test.txt").withWriter("utf-8") {
            writer -> writer.writeLine("Line 4")
        }

        def file = new File("test.txt")
        file.append("Line 5")
        println file.text

        def newfile = new File("test-new.txt")
        newfile << "how are you"
        println newfile.text

    }

    // closure
    static def getFactorial = { num ->
        (num <= 1 ? 1 :
         num * call(num - 1))
    }

    static def listOperation (){
        def numList = [1, 2, 3, 4]
        numList.each { it -> println(it) }
        println numList.find { it -> it == 4 }
        println numList.findAll { it -> it > 2}
    }


}
