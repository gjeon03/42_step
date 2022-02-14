FROM	debian:buster

RUN		apt-get update && apt-get install -y \
		nginx \
		openssl \
		php7.3-fpm \
		mariadb-server \
		php-mysql \
		wget \
		vim

COPY	./srcs/run.sh /
COPY	./srcs/default /tmp/
COPY	./srcs/auto_off_default /tmp/
COPY	./srcs/wp-config.php /tmp/
COPY	./srcs/config.inc.php /tmp/

EXPOSE	80 443

CMD		bash run.sh
