FROM debian:bullseye

USER root

ENV DEBIAN_FRONTEND=noninteractive
ENV APT_KEY_DONT_WARN_ON_DANGEROUS_USAGE=DontWarn

RUN apt-get update --no-install-recommends -y
RUN apt-get install --no-install-recommends -y \
        dialog \
        mariadb-server \
        mariadb-client \
        && apt-get clean autoclean \
    && apt-get autoremove --yes \
    && rm -rf /var/lib/{apt,dpkg,cache,log}

COPY --chown=root:root ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

RUN chown -R root:root /var/lib/mysql

ARG MYSQL_USER
ARG MYSQL_PASSWORD
ARG MYSQL_ROOT_PASSWORD
ARG MYSQL_DB

RUN service mariadb start &&\
    mariadb -e "CREATE DATABASE IF NOT EXISTS ${MYSQL_DB}; \
    CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}'; \
    GRANT ALL PRIVILEGES ON ${MYSQL_DB}.* TO '${MYSQL_USER}'@'%'; \
    ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}'; \
    CREATE USER IF NOT EXISTS 'root'@'%' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}'; \
    GRANT ALL PRIVILEGES on *.* TO 'root'@'localhost' WITH GRANT OPTION; \
    FLUSH PRIVILEGES;"

ENV DEBIAN_FRONTEND=dialog

ENTRYPOINT ["mysqld_safe", "--defaults-extra-file=/etc/mysql/mariadb.conf.d/50-server.cnf"]