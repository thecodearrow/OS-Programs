fact(){

n=5
count=1
fact=1

while [ $count -le $n ]
do
fact=`expr $fact \* $count`
count=`expr $count + 1`
done

echo "$fact"

}
