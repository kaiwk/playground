/**
 * Created by kermit on 2017/3/9.
 */
class MinimumScore implements Calculation {

    @Override
    def execute(examScore) {
        examScore.min()
    }
}
