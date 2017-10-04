# Nginx proxy role

# Variables

-  nginx_proxy_defaults:
    cert: example.crt
    cert_key: example.key
    scheme: https

-  nginx_proxy_servers:
    - name: Humna friendly server name(single word)
    - target: Server to proxy to
    - Redirect: Returns a 301 redirect
    - domain: Domain which to listen on
    - scheme: http|https
    - cert: Server certificate
    - cert_key: Server certificate key
    - locations: list of location - if any.
      - name: Name of the location (/something ) - can be any valid ngixn location
      - target: Where to proxy to.
      - redirect: Returns a 301 Redirect
      - scheme: http|https
    - aliases: List of other domains to listen to -> redirects them to domain.


The "nginx_proxy_defaults" variable can be used to specify the defaults.
In that case, the appropriate variables in nginx_proxy_servers can be omitted,
specifying them will override the defaults.
In both cases (server or location), either target or redirect must be defined.
If target is specified, server will proxy traffic to the target, if a redirect
is specified, a 301 response will be returned to the client.
