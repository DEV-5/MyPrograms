#!/bin/bash

#declare -r num1=3 #declaring a variable is readonly and intializing it
#num2=2
#num3=$((num1+num2))
#echo "num3 = $num3"
#echo "5 pow 2 =" $((5**2))
#rand=5
#let rand+=4
#echo "rand = $rand"
#rand+=10
#echo "after inc rand = $rand"
#echo "rand++ = $((rand++))"
#echo "++rand = $((++rand))"
#echo "rand-- = $((rand--))"
#echo "--rand = $((--rand))"
#num7=1.2
#num8=3.4
#num9=$(python2 -c "print $num7+$num8")
#echo "num9 = $num9"
#
##hair script
#cat<<END
#This test
#prints on 
#many lines
#END
#
#getDate(){
#    date
#    return
#}
#
#getDate
#
#name="vasu"
#demlocal()
#{
#    name="dev"
#    local name="DEV"
#    name="VASU"
#    return
#}
#demlocal
#
#echo "name = $name"# will print name as dev
#getSum(){
#    #local num1=$1 won't work as it is already declared a read only variable
#    local num2=$1
#    local num3=$2
#    local sum=$((num2+num3))
#    echo "$sum"
#}
#nu1=90
#nu2=7
#sum=$(getSum nu1 nu2)
#echo "$nu1+$nu2=$sum"
#
#read -p "How feet tall are you? " height
#
#if [ $height -ge 9 ]
#then
#    echo "you do not exist"
#elif [ $height -ge 6 ]
#then
#    echo "you are tall"
#elif [ $height -ge 5 ] 
#then 
#    echo "You are short"
#elif((height >= 4))
#then
#    echo "You are very short"
#else 
#    echo "You are Vivek"
#fi
## eq ne le lt ge gt are other comparision operators available in bash
#
##read -p "Enter you favorite number :" height #not needed
#
#if (( ((height % 2)) == 0 )); then  #here we can use $height or height
#    echo "you height is even"
#fi
#if ((height == 8)); then  #here we can use $height or height
#    echo "There are very few of you"
#fi
#if (( ((height > 0)) && ((height < 3)) ));
#then
#    echo "you are either a child or vivek"
#fi
#
##FILES tutorial
##touch sample_file && vim sample_file # create file and open in vim
#[ -d sample_dir ] || mkdir sample_dir #look for dir if not present create dir
#
##Strings Tutorial
#str1=""
#str2="sad"
#str3="happy"
#if ["$str1" ]; then
#    echo "$str1 is not null"
#fi
#if [ -z "$str1" ]; then
#    echo "str1 has no value"
#fi
#
#if [ "$str2" == "$str3" ]; then
#    echo "$str2 equals $str3"
#elif [ "$str2" != "$str3" ]; then
#    echo "$str2 not equal to $str3"
#fi
#if [ "$str2" > "$str3" ]; then
#    echo "$str2 is greater than $str3"
#elif [ "$str2" != "$str3" ]; then
#    echo "$str2 is lesser than $str3"
#fi
#
##Files Tutorial
#
#file1="./test_file1"
#file2="./test_file2"
#
# if [ -e "$file1" ];then
#    echo "$file1 exists"
#    if [ -f "$file1" ];then
#        echo "$file1 is an normal file"
#    fi
#
#    if [ -r "$file1" ];then
#        echo "$file1 is readable"
#    fi
#    if [ -w "$file1" ];then
#        echo "$file1 is writable"
#    fi
#    if [ -x "$file1" ];then
#        echo "$file1 is executable"
#    fi
#    if [ -d "$file1" ];then
#        echo "$file1 is a directory"
#    fi
#    if [ -L "$file1" ];then
#        echo "$file1 is a symbolic link"
#    fi
#    if [ -p "$file1" ];then
#        echo "$file1 is a named pipe"
#    fi
#    if [ -S "$file1" ];then
#        echo "$file1 is a network socket"
#    fi
#    if [ -G "$file1" ];then
#        echo "$file1 is owned by the group"
#    fi
#    if [ -O "$file1" ];then
#        echo "$file1 is owned by the userid"
#    fi
#fi

#regular expressions

#read -p "Validate Date :" date
#
#pat="^[0-9]{8}$"
#
#if [[ $date =~ $pat ]]; then
#    echo "$date is valid"
#else
#    echo "$date not valid"
#fi
#
#read -p "Enter two numbers :" nu3 nu4
#
#sum=$((nu3+nu4))
#echo "$nu3 + $nu4 = $sum"
#
##sp dont show the user input
#read -sp "Enter the secret code:" secret 
#if [ "$secret" == "password" ]; then
#    echo "correct password entered"
#else
#    echo "Wrong Password"
#fi
#echo "<$IFS>"
#OTFS="$IFS"
#IFS=","
#
#read -p "Enter 2 numbers to add seperate by a comma :" num1 num2
#
#num1=${num1//[[:blank:]]/}
#num2=${num2//[[:blank:]]/}
#
#sum=$((num1+num2))
#echo "$num1 +$num2 = $sum"
#IFS="$OIFS"

#name="DEV"
#echo "${name}'s toy"
# 
#sample_string="The dog climbed up the hill"
#echo "${sample_string//dog/cat}" #search for dog and replace it with cat
#
#echo "I am ${name:-vasudev}" #as name is already declared no substituion 
#echo "I am ${name:=vasudev}"
#echo "I am ${name2:=vasudev}"
#echo "I am ${name2:-vasudev}"

##Case Tutorial
#read -p "Hoa old are you :" age
#case $age in
#[0-4])
#    echo "To pre-school"
#    ;;
#5)
#    echo "To kindergarden"
#    ;;
#[6-9]|1[0-8])    #checks for ages 6-9 and ages 10 to 18
#    grade=$((age-5))
#    echo "Go to grade $grade"
#    ;;
#*)
#    echo "You are too old to formal school"
#    ;;
#esac
##terinary operator
#age=18
#((age >= 18?(can_vote=1):(can_vote=0)))
#echo "can vote = $can_vote"

#some string operations

#rand_str="A random string"
#
#echo "$String Length : ${#rand_str}"
#echo "${rand_str:2}"
#echo "${rand_str:2:7}" #print 2 to 7 characters of string
#echo "${rand_str#*A }" #print every thing after A   
#echo "${rand_str#*m }" #print everyting after m  

#while loop
#nu5=1
#
#while [ $nu5 -le 10 ]; do
#    echo $nu5
#    nu5=$((nu5 + 1))
#done
#
#nu5=1
#
#while [ $nu5 -le 20 ]; do
#    if (( ((nu5 % 2)) == 0 )); then
#        nu5=$((nu5 + 1))
#        continue
#    fi
#    
#    if((nu5 >= 15)); then
#        break
#    fi
#
#    echo $nu5
#    nu5=$((nu5 +1))
#done

#nu6=1
#until [ $nu6 -gt 10 ]; do
#    echo $nu6
#    nu6=$((nu6 + 1))
#done

#file read tutorial
#while read inn runs avg; do
#    printf "Inn: ${inn}\nRuns: ${runs}\n Avg: ${avg}\n"
#done < sachin_odi_batting_record.txt

#For loop tutorial
#for (( i=0 ; i<=10 ;i=i+1 )); do
#    echo $i
#done
#for  i in {A..Z}; do
#    echo $i
#done

#array tutorial
fav_nums=(3.14 2.718 .57721 4.6692)
echo "Pi : ${fav_nums[0]}"
fav_nums[4]=1.618
echo "GR : ${fav_nums[4]}"
fav_nums+=(1 7)
for i in ${fav_nums[*]}; do
    echo $i
done

for i in ${!fav_nums[@]}; do
    echo $i
done

echo "Array Length : ${#fav_nums[@]}"
echo "Index 3 Length : ${#fav_nums[3]}"

#To Do .57721 is not being sorted correctly but it works for derek verify why?
sorted_nums=($(for i in "${fav_nums[@]}"; do
    echo $i;
done | sort))

for i in ${sorted_nums[*]}; do
    echo $i
done

unset 'sorted_nums[1]' #delete 2nd element in the array
unset sorted_nums

##postional parameters  variables that can store data on the commandline they 
#are $0-$9
#
#echo "1st Argument: $1"
#
#sum=0
#
#while [[ $# -gt 0 ]];do
#    num=$1
#    sum=$((sum+num))
#    shift
#done
#
#echo "Sum : $sum"
