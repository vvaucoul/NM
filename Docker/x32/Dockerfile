# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/04 14:37:30 by vvaucoul          #+#    #+#              #
#    Updated: 2022/04/12 16:05:20 by vvaucoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM i386/debian:buster
MAINTAINER Vincent Vaucouleur <vvaucoul@student.42.fr>

ARG ARCHITECTURE=i386
ENV ARCHITECTURE $ARCHITECTURE

RUN apk -U upgrade \
    && apk add -t build-dependencies \
    build-base \
    python-dev \
    libffi-dev \
    libxslt-dev \
    libxml2-dev \
    openssl-dev \
    tar \
    libssl1.0 \
    musl \
    wget \
    ca-certificates \
    && apk add \
    su-exec \
    python \
    libxml2 \
    libxslt \
    openssl \
    tini \
    py2-pip \
    gcc \
    curl \
    git \
    zsh \
    vim \
    emacs \
    && mkdir /usr/local/searx && cd /usr/local/searx \
    && wget -O- https://github.com/asciimoo/searx/archive/${SEARX_VERSION}.tar.gz | tar xz --strip 1 \
    && pip install --no-cache -r requirements.txt \
    && sed -i "s/127.0.0.1/0.0.0.0/g" searx/settings.yml \
    && apk del build-dependencies \
    && rm -f /var/cache/apk/*

RUN sh -c "$(curl -fsSL https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"

COPY ft_nm /home/ft_nm

ENTRYPOINT zsh