mkdir /usr/include/ls
mkdir /usr/include/ls/smtp

cp build/liblssmtp.so /usr/lib
cp src/ls/smtp/*.h /usr/include/ls/smtp
