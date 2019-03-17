FILES="*"

for file in $FILES;
do
    if [ $file = "script.sh" ]
 	then
    	echo $file
	else
		if [ -z $(cat $file) ]
        then rm $file
        fi
    	#echo "file = $file"
		#echo $TMP > $NORM_FILE
    	#echo "ok"
    	#zsh $file
fi
done 2>/dev/null
