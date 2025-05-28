/*
* Boardinfo Linux driver written by RuhanSA079
* Version: 0.1
*/

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/of.h>
#include <linux/of_platform.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>

#define PROC_FILENAME "boardinfo"

static struct device_node *boardinfo_node;
static char boardname[64] = "unknown";

static int boardinfo_proc_show(struct seq_file *m, void *v)
{
    seq_printf(m, "%s\n", boardname);
    return 0;
}

static int boardinfo_proc_open(struct inode *inode, struct file *file)
{
    return single_open(file, boardinfo_proc_show, NULL);
}

static const struct proc_ops boardinfo_proc_fops = {
    .proc_open    = boardinfo_proc_open,
    .proc_read    = seq_read,
    .proc_lseek   = seq_lseek,
    .proc_release = single_release,
};

static int __init boardinfo_init(void)
{
    struct proc_dir_entry *entry;
    const char *name;

    boardinfo_node = of_find_node_by_name(NULL, "boardinfo");
    if (!boardinfo_node) {
        pr_err("boardinfo: DT node 'boardinfo' not found\n");
        return -ENODEV;
    }

    if (of_property_read_string(boardinfo_node, "boardname", &name)) {
        pr_err("boardinfo: 'boardname' property not found\n");
        return -EINVAL;
    }

    strlcpy(boardname, name, sizeof(boardname));

    entry = proc_create(PROC_FILENAME, 0444, NULL, &boardinfo_proc_fops);
    if (!entry) {
        pr_err("boardinfo: Failed to create /proc/%s\n", PROC_FILENAME);
        return -ENOMEM;
    }

    pr_info("boardinfo: loaded, boardname=%s\n", boardname);
    return 0;
}

static void __exit boardinfo_exit(void)
{
    remove_proc_entry(PROC_FILENAME, NULL);
    pr_info("boardinfo: unloaded\n");
}

module_init(boardinfo_init);
module_exit(boardinfo_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("RuhanSA079");
MODULE_DESCRIPTION("Boardinfo reader from DTB");
