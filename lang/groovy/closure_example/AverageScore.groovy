/**
 * Created by kermit on 2017/3/9.
 */
class AverageScore implements Calculation {

    @Override
    def execute(examScore) {
        def total = 0
        for (int i = 0; i < examScore.size(); ++i) {
            total += examScore[i]
        }
        total / examScore.size()
    }
}
