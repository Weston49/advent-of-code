if [ $# -ne 1 ]; then
  echo 'usage: sh newday.sh day_number' >& 2
  exit 1
fi

num=$1
fname="day"
fname+=$num
mkdir $fname
cd $fname
cp ../makefile .
cp ../main.cpp .
touch input.txt
touch example.txt
make
