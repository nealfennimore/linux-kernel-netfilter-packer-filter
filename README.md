# Netfilter Hook

Packet filtering at the kernel level with a netfilter module is
## Netfilter
Linux kernel packet filter
![](http://linux-ip.net/nf/nfk-traversal.png)


### Use links
- https://linux-kernel-labs.github.io/refs/heads/master/labs/networking.html
- https://www.cs.unh.edu/cnrg/people/gherrin/linux-net.html
- https://www.digitalocean.com/community/tutorials/a-deep-dive-into-iptables-and-netfilter-architecture

## Scripts
### Build

```sh
make
```

### Install
```sh
make install
sudo journalctl -f
```

### Uninstall
```sh
make uninstall
```