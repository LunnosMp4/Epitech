FROM debian:latest AS build-env

RUN apt-get update
RUN apt-get install -y curl git unzip

ARG FLUTTER_SDK=/usr/local/flutter
ARG APP=/app/

RUN git clone https://github.com/flutter/flutter.git $FLUTTER_SDK

ENV PATH="$FLUTTER_SDK/bin:$FLUTTER_SDK/bin/cache/dart-sdk/bin:${PATH}"

RUN flutter channel master

RUN flutter upgrade

RUN mkdir $APP

COPY . $APP

WORKDIR $APP

RUN flutter clean
RUN flutter pub get
RUN flutter build web

FROM nginx:1.25.2-alpine

COPY --from=build-env /app/build/web /usr/share/nginx/html

EXPOSE 80
CMD ["nginx", "-g", "daemon off;"]
