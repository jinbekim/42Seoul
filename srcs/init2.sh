#!bin/bash

# mysql
service mysql start


chown -R www-data /var/www/*
chmod -R 755 /var/www/*

# nginx
ln -s /etc/nginx/sites-available/autoindex_off /etc/nginx/sites-enabled/nginx-conf
rm -rf /etc/nginx/sites-enabled/default

# ssl
openssl req -newkey rsa:4096 -days 365 -nodes -x509 \
            -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=kim/CN=localhost" \
            -keyout localhost.key \
            -out localhost.crt
mv localhost.crt etc/ssl/certs/
mv localhost.key etc/ssl/private/
chmod 600 etc/ssl/certs/localhost.crt etc/ssl/private/localhost.key

# wordpress
wget -c https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
mv wordpress/ /var/www/html
mv /tmp/wp-config.php /var/www/html/wordpress/

# mysql -u [user name] -p [your password]
echo "CREATE DATABASE wordpress;" \
		| mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* to 'root'@'localhost';" \
		| mysql -u root --skip-password
echo "UPDATE mysql.user SET plugin = 'mysql_native_password' WHERE user='root';" \
		| mysql -u root --skip-password
echo "FLUSH PRIVILEGES" \
		| mysql -u root --skip-password

# phpmyadmin
wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
mv phpMyAdmin-5.0.2-all-languages /var/www/html/phpmyadmin
mv /tmp/phpmyadmin.inc.php /var/www/html/phpmyadmin/config.inc.php

# fastCGI
service php7.3-fpm start
# nginx
service nginx start

bash