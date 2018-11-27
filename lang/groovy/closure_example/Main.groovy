class Main {

    static void main(String[] args) {
        def examScore = new ExamScores()

        // closure, a code block
        def firstScore = { scores ->
            scores[0]
        }

        def first = examScore.analyse(firstScore)
        println "First score is: $first"

        def averageScore = { scores ->
            def total = 0
            scores.each { total += it }
            total / scores.size()
        }

        def minimumScore = { scores ->
            scores.min()
        }

        def greaterThanFifty = { scores ->
            def num = 0
            scores.each {
                if(it > 50) num += 1
            }
            num
        }

        def average = examScore.analyse(averageScore)
        def minimum = examScore.analyse(minimumScore)
        def greater50 = examScore.analyse(greaterThanFifty)

        // strategy pattern
//        def average = examScore.analyse(new AverageScore())
//        def minimum = examScore.analyse(new MinimumScore())


        println "Average is: $average"
        println "Minimum is: $minimum"
        println "Greater than fifty: $greater50"
    }
}

