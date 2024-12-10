FROM alpine:latest AS builder

RUN apk add --no-cache gcc musl-dev

WORKDIR /app

COPY app/main.c ./

RUN gcc -o terminal main.c -static

FROM alpine:latest

WORKDIR /app

COPY --from=builder /app/terminal /app

CMD ["/bin/sh"]


