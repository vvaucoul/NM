# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/12 14:52:16 by vvaucoul          #+#    #+#              #
#    Updated: 2022/04/12 15:08:31 by vvaucoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster
MAINTAINER Vincent Vaucouleur <vvaucoul@student.42.fr>

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install apt-utils gcc zsh curl git vim -y

RUN sh -c "$(curl -fsSL https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"
RUN apt-get install zsh -y

COPY ft_nm /home/ft_nm

ENTRYPOINT zsh