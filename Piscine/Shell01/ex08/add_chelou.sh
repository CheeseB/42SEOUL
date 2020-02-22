#! /bin/sh

num1=`echo $FT_NBR1 | sed "s/\'/0/g" | sed "s/\\\\\/1/g" | sed "s/\"/2/g" | sed "s/?/3/g" | sed "s/!/4/g"`

num2=`echo $FT_NBR2 | tr 'mrdoc' '01234'`

num1_10=`echo "ibase=5; $num1" | bc`
num2_10=`echo "ibase=5; $num2" | bc`

sum=`echo "$num1_10 + $num2_10" | bc`

sum_13=`echo "obase=13; $sum" | bc`

echo $sum_13 | tr '0123456789ABC' 'gtaio luSnemf'
