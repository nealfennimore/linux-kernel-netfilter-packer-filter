#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>
#include <linux/ip.h>

MODULE_LICENSE("MIT");

unsigned int hook_func(void *priv, struct sk_buff *skb, const struct nf_hook_state *state)
{
    struct iphdr *ip_headers = (struct iphdr *)skb_network_header(skb);
    printk(KERN_DEBUG "packet accepted\n");
    printk(KERN_DEBUG "Buffer data %c", &skb->data);
    printk(KERN_DEBUG "In Device Name %c", &state->in->name);
    printk(KERN_DEBUG "Src IPV4 Source %d", &ip_headers->saddr);
    printk(KERN_DEBUG "Out Device Name %c", &state->out->name);
    printk(KERN_DEBUG "Dst IPV4 Source %d", &ip_headers->daddr);
    return NF_ACCEPT;
}

static struct nf_hook_ops hook_opts = {
    .hook = hook_func,
    .hooknum = NF_INET_PRE_ROUTING,
    .pf = PF_INET,
    .priority = NF_IP_PRI_FIRST,
};

int init_module()
{
    nf_register_net_hook(&init_net, &hook_opts);
    return 0;
}

void cleanup_module()
{
    nf_unregister_net_hook(&init_net, &hook_opts);
}