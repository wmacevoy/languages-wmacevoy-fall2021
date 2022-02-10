FROM ocaml/opam
RUN mkdir -p /home/opam/app
WORKDIR /home/opam/app
COPY --chown=opam . /home/opam/app
RUN chmod +x /home/opam/app/run
RUN opam switch 4.13
RUN eval `opam config env`
CMD ["ocaml","app.ml"]
#CMD ["/bin/sh", "-c", "while true; do echo .; sleep 1; done"]
