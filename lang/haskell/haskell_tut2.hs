import Data.List
import System.IO

-- List
primeNumbers = [3, 5, 7, 11]
morePrimes = primeNumbers ++ [13, 17, 19, 23, 29]
favNums = 2 : 7 : 21 : 66 : []

multlist = [[3, 5, 7], [11, 13, 17]]
morePrimes2 = 2 : morePrimes
lenPrime = length morePrimes2

revPrime = reverse morePrimes2
isListEmpty = null morePrimes2
secondPrime = morePrimes2 !! 1
fifthPrime = morePrimes2 !! 4
firstPrime = head morePrimes2
lastPrime = last morePrimes2
-- return the list except the last one
primeInit = init morePrimes2
-- first three element
first3Primes = take 3 morePrimes2
-- except first three element
removePrimes = drop 3 morePrimes2

is7InList = 7 `elem` morePrimes2

maxPrime = maximum morePrimes2
minPrime = minimum morePrimes2

newList = [2, 3, 5]
prodPrimes =  product newList

zeroToTen = [0..10]

evenList = [2,4..20]

letterList = ['A', 'C'..'Z']

infinPow10 = [10, 20..]

many2s = take 10 (repeat 2)

many3s = replicate 10 3

cycleList = take 10 (cycle [1, 2, 3, 4, 5])

listTimes2 = [x * 2 | x <- [1, 2, 3, 4], x * 2 < 4]
divideBy9N13 = [x | x <- [1..500], x `mod` 13 == 0, x `mod` 9 == 0]

-- operater
sortedList = sort [1, 3, 5, 7, 9, 2, 4, 6, 8, 10]
sumOfList = zipWith (+) [1, 2, 3, 4, 5] [6, 7, 8, 9, 10]
listBiggerThan5 = filter (>5) morePrimes
evensUpTo20 = takeWhile (<= 20) [2, 4..]

-- fold right to left
multOfListr = foldr (*) 2 [2, 3, 4, 5]
-- fold left to right
multOfListl = foldl (*) 1 [2, 3, 4, 5]

powOf3 = [3^n | n <- [1..10]]
multTable = [[x * y | y <- [1..10]] | x <- [1..10]]

-- Tuple
randTuple = (1, "Random Tuple")
bobSmith = ("Bob Smith", 52)
bobsName = fst bobSmith
bobsAge = snd bobSmith

names = ["Bob", "Mary", "Tom"]
addresses = ["123 Main", "234 North", "567 South"]

-- zip :: [a] -> [b] -> [(a, b)]
namesNAddress = zip names addresses
