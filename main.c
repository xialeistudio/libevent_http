#include <stdio.h>
#include <event.h>
#include <evhttp.h>
#include <unistd.h>

/**
 * 处理HTTP请求
 * @param request
 * @param arg
 */
void handle_request(struct evhttp_request *, void *);

int main() {
    u_int16_t port = 10000;
    char *host = "0.0.0.0";
    struct evhttp *server = NULL;

    event_init();
    server = evhttp_start(host, port);
    evhttp_set_gencb(server, handle_request, NULL);
    printf("Server running on %s:%d. pid=%d\n", host, port, getpid());
    event_dispatch();
    return 0;
}

void handle_request(struct evhttp_request *request, void *arg) {
    time_t now;
    time(&now);

    struct evbuffer *buffer = evbuffer_new();
    evbuffer_add_printf(buffer, "server time: %s", ctime(&now));
    evhttp_send_reply(request, HTTP_OK, "OK", buffer);
    evbuffer_free(buffer);
}