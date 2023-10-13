FROM debian:bullseye

ARG WORDPRESS_USER
ARG WORDPRESS_PASSWORD
ARG DOMAIN_NAME

USER root

ENV APT_KEY_DONT_WARN_ON_DANGEROUS_USAGE=DontWarn
ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update --no-install-recommends -y
RUN apt-get install --no-install-recommends -y \
	dialog \
	wget \
	ca-certificates \
	php-fpm \
	curl \
	php-mysqli \
	mariadb-client \
	&& apt-get clean autoclean \
    && apt-get autoremove --yes \
    && rm -rf /var/lib/{apt,dpkg,cache,log}

RUN mkdir -p /var/run/php \
	&& mkdir -p /var/run/mysqld \
	&& mkdir -p /var/www/html \
	&& chmod 755 /var/www/html/

COPY tools/wp_install.sh ./
COPY --chown=root:root conf/wp-config.php ./
COPY tools/wp-cli.phar /usr/local/bin/wp
COPY ./conf/www.conf /etc/php/7.4/fpm/pool.d/www.conf
RUN chmod +x wp_install.sh

ENV DEBIAN_FRONTEND=dialog
ENTRYPOINT ["./wp_install.sh"]