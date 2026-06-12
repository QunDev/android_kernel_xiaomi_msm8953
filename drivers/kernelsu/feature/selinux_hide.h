#ifndef __KSU_H_SELINUX_HIDE
#define __KSU_H_SELINUX_HIDE

#include <linux/version.h>

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0)
void ksu_selinux_hide_init();
void ksu_selinux_hide_exit();
void ksu_selinux_hide_drop_backup_if_unused();
void ksu_selinux_hide_handle_second_stage();
void ksu_selinux_hide_handle_post_fs_data();
#else
/*
 * tissot: selinux_hide is a GKI (>=5.10) feature; feature/selinux_hide.c is only
 * compiled for >=5.10 in ksu.c. runtime/ksud.c calls these helpers
 * unconditionally, so provide no-op stubs to keep the non-GKI 4.9 build linking.
 */
static inline void ksu_selinux_hide_init(void) {}
static inline void ksu_selinux_hide_exit(void) {}
static inline void ksu_selinux_hide_drop_backup_if_unused(void) {}
static inline void ksu_selinux_hide_handle_second_stage(void) {}
static inline void ksu_selinux_hide_handle_post_fs_data(void) {}
#endif

#endif
