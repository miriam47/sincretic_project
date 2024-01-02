
FROM gcc:latest
WORKDIR /usr/src/proj
COPY proj.c .
RUN gcc -o proj proj.c
CMD ["./proj"]