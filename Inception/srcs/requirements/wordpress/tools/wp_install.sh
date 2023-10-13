#!/bin/bash

# * download workpress
wp core download \
	--version=6.2.2 \
	--path=/var/www/html/ \
	--allow-root

mv ./wp-config.php /var/www/html/

wp config set --allow-root --path=/var/www/html/ DB_NAME ${MYSQL_DB}
wp config set --allow-root --path=/var/www/html/ DB_USER ${MYSQL_USER}
wp config set --allow-root --path=/var/www/html/ DB_PASSWORD ${MYSQL_PASSWORD}
wp config set --allow-root --path=/var/www/html/ DB_HOST ${MYSQL_HOST}

wp core install \
    --url=https://$DOMAIN_NAME \
    --title="$WORDPRESS_TITLE" \
    --admin_user=$WORDPRESS_ADMIN_NAME \
    --admin_password=$WORDPRESS_ADMIN_PASSWORD \
    --admin_email=$WORDPRESS_ADMIN_EMAIL \
    --path=/var/www/html/ \
    --allow-root

wp user create --allow-root --path=/var/www/html/ $WORDPRESS_USER $WORDPRESS_EMAIL --role=author
wp user update --allow-root --path=/var/www/html/ $WORDPRESS_USER --user_pass=${WORDPRESS_PASSWORD}

wp plugin update --allow-root --path=/var/www/html/ --all
wp theme update --allow-root --path=/var/www/html/ --all
wp plugin activate --allow-root --path=/var/www/html/ --all
chown -R www-data:www-data /var/www
chmod -R 775 $(find /var/www/html -type d)
chmod -R 664 $(find /var/www/html -type f)


php-fpm7.4 -F -R --fpm-config /etc/php/7.4/fpm/pool.d/www.conf #--fpm-config /etc/php-fpm.conf