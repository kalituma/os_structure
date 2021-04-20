readelf -h /bin/sleep
readelf -S /bin/sleep

/bin/sleep 10000&
cat /proc/41834/maps
kill 41834
