#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>
#include <linux/net.h>
#include <linux/in.h>
#include <linux/skbuff.h>
#include <linux/ip.h>
#include <linux/tcp.h>
#include <linux/module.h>

static unsigned int my_nf_hookfn(void *priv,
                                 struct sk_buff *skb,
                                 const struct nf_hook_state *state)
{
    /* process packet */
    //...

    return NF_ACCEPT;
}

static struct nf_hook_ops my_nfho = {
    .hook = my_nf_hookfn,
    .hooknum = NF_INET_LOCAL_OUT,
    .pf = PF_INET,
    .priority = NF_IP_PRI_FIRST};

int __init my_hook_init(void)
{
    return nf_register_net_hook(&init_net, &my_nfho);
}

void __exit my_hook_exit(void)
{
    nf_unregister_net_hook(&init_net, &my_nfho);
}

module_init(my_hook_init);
module_exit(my_hook_exit);