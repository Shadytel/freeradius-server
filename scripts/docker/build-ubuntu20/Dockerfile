ARG from=freeradius/ubuntu20-deps
FROM ${from}

SHELL ["/usr/bin/nice", "-n", "5", "/usr/bin/ionice", "-c", "3", "/bin/sh", "-x", "-c"]

ARG cc=gcc
ARG branch=master
ARG dh_key_size=2048

WORKDIR /usr/local/src/repositories/freeradius-server
RUN git checkout ${branch}
RUN CC=${cc} ./configure --prefix=/opt/freeradius
RUN make -j$(($(getconf _NPROCESSORS_ONLN) + 1))
RUN make install
WORKDIR /opt/freeradius/etc/raddb
RUN sed -i -e 's/allow_vulnerable_openssl.*/allow_vulnerable_openssl = yes/' radiusd.conf
RUN make -C certs DH_KEY_SIZE=$dh_key_size
WORKDIR /

FROM ${from}
COPY --from=0 /opt/freeradius /opt/freeradius

EXPOSE 1812/udp 1813/udp
ENV LD_LIBRARY_PATH=/opt/freeradius/lib
CMD ["/opt/freeradius/sbin/radiusd", "-X"]
