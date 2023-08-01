proxy_hide_header   X-Frame-Options;
proxy_http_version  1.1;
proxy_pass_header   Server;
proxy_set_header    Host $host;
proxy_set_header    HTTP_PROXY "";
proxy_set_header    Proxy "";
proxy_set_header    X-Real-IP $remote_addr;
proxy_set_header    X-Forwarded-For $proxy_add_x_forwarded_for;
proxy_set_header    X-Forwarded-Host $http_host;
proxy_set_header    X-NginX-Proxy true;
proxy_set_header    X-Forwarded-Proto $scheme;

proxy_set_header    "Connection" "";
