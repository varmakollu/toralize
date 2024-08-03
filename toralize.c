/* toralize.c */
#include "toralize.h"

Req *request(const char *dstip, const int dstport) {
    Req *req;

    req = malloc(reqsize);
    
    req->vn = 4;
    req->cd = 1;
    req->dstport = htons(dstport);
    req->dstip = inet_addr(dstip);
    strncpy(req->username, USERNAME, 7);

    return req;
}

int main(int argc, char *argv[]) {
    char *host;
    int port, s;
    struct sockaddr_in sock;
    Req *req;
    Res *res;
    char buf[ressize];
    int success;


    if (argc < 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n",
        argv[0]);

        return -1;
    }

    host = argv[1];
    port = atoi(argv[2]);

    s = socket(AF_INET, SOCK_STREAM, 0);
    if (s < 0) {
        perror("socket");

        return -1;
    }

    sock.sin_family = AF_INET;
    sock.sin_port = htons(PROXYPORT);
    sock.sin_addr.s_addr = inet_addr(PROXY);

    if (connect(s, (struct sockaddr *)&sock, sizeof(sock))) {
        perror("connect");

        return -1;
    }

    printf("Connected to proxy\n");
    req = request(host, port);
    write(s, req, reqsize);

    memset(buf, 0, ressize);
    if (read(s, buf, ressize) < 1) {
        perror("read");
        free(req);
        close(s);

        return -1;
    }

    res = buf;
    success = (res->cd == 90);
    if (!success){
        fprintf(stderr, "Unable to traverse"
            "the proxy, error the code: %d\n",
            res->cd);

            close(s);
            free(req);

            return -1;
    }
    
    printf("Successfully connected through the proxy to "
        "%s:%d\n", host, port);

    close(s);
    free(req);

    return 0;
}