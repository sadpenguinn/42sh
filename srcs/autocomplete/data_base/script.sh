FILES="*"

for file in $FILES;
do
    if [ $file = "script.sh" ]
 	then
    	echo $file
	else
		if [ $file != ${file#_} ]
		then
			rm $file
			echo $file
		fi
    	#cat $file | grep -Eo '(\-([a-zA-Z]|(-[a-zA-Z]+))\[.*?\])' >  ${file#_}
		#echo $TMP > $NORM_FILE
    	#echo "ok"
    	#zsh $file
fi
done 2>/dev/null
