
FROM gcc:latest
WORKDIR C:/Users/Miri/Desktop/Proiect_sincretic/sincretic_project/proj.c
COPY proj.c .
RUN gcc -o proj proj.c -lstdc
CMD ["./proj"]