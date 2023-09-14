#!/bin/bash

if ! [ -x "$(type -P iperf3)" ]; then
  echo "ERROR: script requires iperf3"
  echo "For Debian and friends get it with 'apt-get install iperf3'"
  echo "If you have it, perhaps you don't have permissions to run it, try 'sudo $(basename $0)'"
  exit 1
fi

if [ "$#" -ne "2" ]; then
  echo "ERROR: script needs four arguments, where:"
  echo
  echo "1. Number of times to repeat test (e.g. 10)"
  echo "2. Host running 'iperf3 -s' (e.g. somehost)"
  echo
  echo "Example:"
  echo "  $(basename $0) 10 somehost"
  echo 
  echo "The above will run 'iperf3 -c' 10 times on the client and report totals and average."
  exit 1
else
  runs=$1
  host=$2
fi

log=sender_onepath.log

if [ -f $log ]; then
  echo removing $log
  rm $log
fi

echo "=================================================================="
echo " Results"
echo "=================================================================="
echo " target host .... $host"
echo "------------------------------------------------------------------"

for run in $(seq 1 $runs); do
  iperf3 -c $host -u -t 10 -P 5 | grep 'SUM' >> $log
  echo -e " run $run: \t $(awk '/Bitrate/ {getline}; END{print $6, $7}' $log)"
done

avg=$(awk -v runs=$runs '/Bitrate/ {getline; sum+=$7; avg=sum/runs} END {print avg}' $log)


echo "------------------------------------------------------------------"
echo " average ....... $avg Mbits/sec"
echo
echo "see $log for details"
