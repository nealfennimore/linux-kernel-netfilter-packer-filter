#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>

unsigned int hook_func(void *priv, struct sk_buff *skb, const struct nf_hook_state *state)
{
    printk(KERN_INFO "packet dropped\n");
    return NF_DROP;
}

static struct nf_hook_ops nfho = {
    .hook = hook_func,
    .hooknum = NF_INET_PRE_ROUTING,
    .pf = PF_INET,
    .priority = NF_IP_PRI_FIRST,
};

int init_module()
{
    nf_register_net_hook(&init_net, &nfho);
    return 0;
}

void cleanup_module()
{
    nf_unregister_net_hook(&init_net, &nfho);
}

MODULE_LICENSE("GPL");
