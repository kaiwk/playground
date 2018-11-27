-- haskell tutorial

import Data.List
import System.IO

-- Int -2^63 - 2^63
maxInt = maxBound :: Int
minInt = minBound :: Int

-- Double
bigFloat = 3.999999999 + 0.000000000005

-- Bool: True | False
-- Char '
-- Tuple

-- the value cannot change (final)
always5 :: Int
always5 = 5

sumOfNums = sum [1..1000]

-- calculate
addEx = 5 + 4
subEx = 5 - 4
multEx = 5 * 4
divEx = 5 / 4
modEx = mod 5 4
modEx2 = 5 `mod` 4

-- neg
negNumEx = 5 + (-4)

-- sqrt :: Floating a => a -> a
num9 = 9 :: Int
sqrtOf9 = sqrt(fromIntegral num9)

-- built in math functions
piVal = pi
ePow9 = exp 9
logOf9 = log 9
square9 = 9 ** 2
truncateVal = truncate 9.999
roundVal = round 9.999
ceilingVal = ceiling 9.999
floorVal = floor 9.999

-- sin, cos, tan, asin, acos, atan, sinh, tanh, cosh
-- asinh, acosh, atanh

-- True or False
trueOrFalse = True || False
trueAndFalse = True && False
notTrue = not(True)

