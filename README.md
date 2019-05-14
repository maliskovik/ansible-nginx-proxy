# Nginx proxy role

# Variables

-  nginx_proxy_defaults:
    cert: example.crt
    cert_key: example.key
    scheme: https

-  nginx_https_proxy_servers:
    - name: Humna friendly server name(single word)
    - target: Server to proxy to
      - address
      - http_port(optional)
      - https_port(optional)
    - Redirect: Returns a 301 redirect
    - domain: Domain which to listen on
    - reverse: (Boolean) Use silent reverse proxy
    - reverse_name: Name of destination proxy
    - scheme: http|https
    - cert: Server certificate
    - cert_key: Server certificate key
    - server_includes: Include files listed here in server block
    - location_includes: Include files listed here in / location
    - locations: list of location - if any.
      - name: Name of the location (/something ) - can be any valid ngixn location
      - target: Where to proxy to.
        - address
        - http_port(optional)
        - https_port(optional)
      - redirect: Returns a 301 Redirect
      - reverse: (Boolean) Use silent reverse proxy
      - reverse_name: Name of destination proxy
      - scheme: http|https
      - - includes: include fies listed here under this location.
    - aliases: List of other domains to listen to -> redirects them to domain.

- nginx_http_proxy_servers -> Like nginx_https_proxy_servers but without cert and cert_key
The "nginx_proxy_defaults" variable can be used to specify the defaults.
In that case, the appropriate variables in nginx_proxy_servers can be omitted,
specifying them will override the defaults.
In both cases (server or location), either target or redirect must be defined.
If target is specified, server will proxy traffic to the target, if a redirect
is specified, a 301 response will be returned to the client.

## Customizing server configs
To include special configuration for server configuration(v-hosts), you cn use include files. You can add them with the nginx role - custom configs, by creating include files as {{ nginx_config_files }}/<filename>.inc.  
After adding them, they can be included in the configuration by specifying them in the nginx_proxy_servers variable under approptiate includes varaible as described above.
