/**
 * Created by kermit on 2017/3/9.
 */
class ExamScores{

    def scores = [71, 11, 34, 99, 95, 67, 59, 88] as Integer[]

    def analyse(closure) {
        closure(scores)
    }
}
