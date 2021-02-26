FROM debian:buster

RUN apt-get update && \
    apt-get install -y \
    nginx \
    openssl \
    php-mysql \
    php7.3-fpm \
    php-mbstring \
    wget \
    mariadb-server

# ADD source dest
# COPY source dest
COPY srcs/init.sh .
COPY srcs/init2.sh .
COPY srcs/autoindex_on /etc/nginx/sites-available/
COPY srcs/autoindex_off /etc/nginx/sites-available/
COPY srcs/wp-config.php /tmp/
COPY srcs/phpmyadmin.inc.php /tmp/

EXPOSE 80
EXPOSE 443

CMD [ "bash", "init.sh"]