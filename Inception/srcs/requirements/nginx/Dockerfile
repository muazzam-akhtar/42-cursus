FROM debian:bullseye

ARG WORDPRESS_ADMIN_NAME

RUN	apt-get update -y --no-install-recommends && \
	apt-get install \
	nginx \
	dialog \
	openssl \
	gettext-base \
	-y --no-install-recommends

RUN mkdir -p /etc/nginx/certificates && openssl req -x509 -nodes -days 365 -newkey rsa:4096     \
        -keyout /etc/nginx/certificates/nginx.key       \
        -out /etc/nginx/certificates/nginx-certificate.crt            \
        -subj "/C=AE/ST=Abu Dhabi/L=Abu Dhabi/O=42/OU=Abu Dhabi/CN=$WORDPRESS_ADMIN_NAME"

COPY --chown=www-data:www-data ./conf/nginx.conf /etc/nginx/sites-available/default

ENTRYPOINT [ "nginx", "-g", "daemon off;" ]