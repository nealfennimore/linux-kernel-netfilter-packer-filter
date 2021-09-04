#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>

MODULE_LICENSE("MIT");

unsigned int hook_func(void *priv, struct sk_buff *skb, const struct nf_hook_state *state)
{
    printk(KERN_INFO "packet accepted\n");
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