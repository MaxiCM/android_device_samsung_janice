LOCAL_PATH=../../../..


PATCHES="bionic build frameworks/av frameworks/base/ frameworks/native/ frameworks/opt/net/wifi/ \
	frameworks/opt/telephony/ hardware/libhardware/ hardware/libhardware_legacy packages/services/Telecomm system/core"

export CL_RED="\033[31m"
export CL_GRN="\033[32m"
export CL_YLW="\033[33m"
export CL_BLU="\033[34m"
export CL_MAG="\033[35m"
export CL_CYN="\033[36m"
export CL_RST="\033[0m"

pre_clean() {
    tmp=$PWD
    cd $1

    git reset --hard > /dev/null 2>&1
    git clean -fd > /dev/null 2>&1
    git am  --abort > /dev/null 2>&1

    cd $tmp

    out=$( repo sync -fl $1 )
}

apply() {
    out=$( patch -p1 -i $1 )
    fail=$( echo $out | grep -ic "FAILED" )
    ign=$( echo $out | grep -ic "ignore" )

    if [ "$fail" == "0" ]  ; then
         git commit -am "$1"
         if [ "$ign" != "0" ]  ; then
             echo -e $CL_RED"some hunks of patch $1 has been ignored"$CL_RST
             #echo -e $CL_RED$out$CL_RST | tr '.' '\n'
         fi
    else 
         echo -e $CL_RED"patch $1 has been applied with errors"$CL_RST
         #echo -e $CL_RED$l$CL_RST | tr '.' '\n'
    fi;
}

apply_all() {
    tmp=$PWD
    cd $1

    echo -e $CL_BLU"Applying patches to $1"$CL_RST ; echo "" ; echo "" ;

    for i in $( ls *.patch )
    do
        echo "applying "$i
        apply $i
        echo ""
    done
 
    cd $tmp
}

# pre clean 

echo -e $CL_GRN"get rid of any uncommitted or unstaged changes"$CL_RST

patches=$PWD
cd $LOCAL_PATH

for i in $PATCHES
do
pre_clean $i
done

if [ "$1" != "clean" ]; then

	cd $patches

	# copy patches
	cp -r * $LOCAL_PATH 
	cd $LOCAL_PATH

	# now apply it 

	for i in  $PATCHES
	do
	apply_all $i
	done
fi
