FROM ubuntu:latest
ENTRYPOINT [ "/usr/bin/testu01" ]
WORKDIR /app

RUN apt-get update && \
    apt-get upgrade && \
    apt-get dist-upgrade && \
    apt-get -y install gcc libtestu01-dev

COPY tester.c ./
RUN gcc -o /usr/bin/testu01 tester.c -I/usr/include/testu01 -ltestu01
