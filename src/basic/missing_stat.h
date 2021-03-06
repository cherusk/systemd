/* SPDX-License-Identifier: LGPL-2.1+ */
#pragma once

#include <linux/types.h>
#include <sys/stat.h>

#if WANT_LINUX_STAT_H
#include <linux/stat.h>
#endif

/* Thew newest definition we are aware of (fa2fcf4f1df1559a0a4ee0f46915b496cc2ebf60; 5.8) */
#define STATX_DEFINITION {                      \
        __u32 stx_mask;                         \
        __u32 stx_blksize;                      \
        __u64 stx_attributes;                   \
        __u32 stx_nlink;                        \
        __u32 stx_uid;                          \
        __u32 stx_gid;                          \
        __u16 stx_mode;                         \
        __u16 __spare0[1];                      \
        __u64 stx_ino;                          \
        __u64 stx_size;                         \
        __u64 stx_blocks;                       \
        __u64 stx_attributes_mask;              \
        struct statx_timestamp stx_atime;       \
        struct statx_timestamp stx_btime;       \
        struct statx_timestamp stx_ctime;       \
        struct statx_timestamp stx_mtime;       \
        __u32 stx_rdev_major;                   \
        __u32 stx_rdev_minor;                   \
        __u32 stx_dev_major;                    \
        __u32 stx_dev_minor;                    \
        __u64 stx_mnt_id;                       \
        __u64 __spare2;                         \
        __u64 __spare3[12];                     \
}

#if !HAVE_STRUCT_STATX
struct statx_timestamp {
        __s64 tv_sec;
        __u32 tv_nsec;
        __s32 __reserved;
};

struct statx STATX_DEFINITION;
#endif

/* Always define the newest version we are aware of as a distinct type, so that we can use it even if glibc
 * defines an older definition */
struct new_statx STATX_DEFINITION;

/* a528d35e8bfcc521d7cb70aaf03e1bd296c8493f (4.11) */
#ifndef STATX_BTIME
#define STATX_BTIME 0x00000800U
#endif

/* a528d35e8bfcc521d7cb70aaf03e1bd296c8493f (4.11) */
#ifndef AT_STATX_DONT_SYNC
#define AT_STATX_DONT_SYNC 0x4000
#endif

/* fa2fcf4f1df1559a0a4ee0f46915b496cc2ebf60 (5.8) */
#ifndef STATX_MNT_ID
#define STATX_MNT_ID 0x00001000U
#endif

/* 80340fe3605c0e78cfe496c3b3878be828cfdbfe (5.8) */
#ifndef STATX_ATTR_MOUNT_ROOT
#define STATX_ATTR_MOUNT_ROOT 0x00002000 /* Root of a mount */
#endif
