# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run.sh                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/01 00:01:58 by gjeon             #+#    #+#              #
#    Updated: 2021/03/02 23:41:35 by gjeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# chmod 775 /tmp/run.sh
# chown -R www-data:www-data /var/www/
# chmod -R 755 /var/www/

# ssl
openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Lee/CN=localhost" -keyout etc/ssl/private/private.key -out etc/ssl/certs/public.crt
chmod 600 etc/ssl/private/private.key etc/ssl/certs/public.crt

# nginx
cp -rp /tmp/default /etc/nginx/sites-available/

# wordpress 설치
wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
mv wordpress/ /var/www/html/
rm latest.tar.gz
chown -R www-data:www-data /var/www/html/wordpress
cp -rp ./tmp/wp-config.php /var/www/html/wordpress

# wordpress DB 테이블 생성
service mysql start
echo "CREATE DATABASE wordpress;" | mysql -u root
echo "CREATE USER '42user'@'localhost';" | mysql -u root
echo "SET password FOR '42user'@'localhost' = password('42seoul');    " | mysql -u root
echo "GRANT ALL PRIVILEGES ON wordpress.* TO '42user'@'localhost' IDENTIFIED BY '42seoul';" | mysql -u root
echo "FLUSH PRIVILEGES;" | mysql -u root

# phpMyAddmin
wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
mv phpMyAdmin-5.0.2-all-languages phpmyadmin
mv phpmyadmin /var/www/html/
rm phpMyAdmin-5.0.2-all-languages.tar.gz
cp -rp /tmp/config.inc.php /var/www/html/phpmyadmin/

service nginx start
service php7.3-fpm start
service mysql restart
