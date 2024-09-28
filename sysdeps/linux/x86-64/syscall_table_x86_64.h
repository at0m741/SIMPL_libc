#ifndef __SYSCALL_TABLE_X86_64_H__
#define __SYSCALL_TABLE_X86_64_H__

#define SYS_X86_64_read                    0
#define SYS_X86_64_write                   1
#define SYS_X86_64_open                    2
#define SYS_X86_64_close                   3
#define SYS_X86_64_stat                    4
#define SYS_X86_64_fstat                   5
#define SYS_X86_64_lstat                   6
#define SYS_X86_64_poll                    7
#define SYS_X86_64_lseek                   8
#define SYS_X86_64_mmap                    9
#define SYS_X86_64_mprotect               10
#define SYS_X86_64_munmap                 11
#define SYS_X86_64_brk                    12
#define SYS_X86_64_rt_sigaction           13
#define SYS_X86_64_rt_sigprocmask         14
#define SYS_X86_64_rt_sigreturn           15
#define SYS_X86_64_ioctl                  16
#define SYS_X86_64_pread64                17
#define SYS_X86_64_pwrite64               18
#define SYS_X86_64_readv                  19
#define SYS_X86_64_writev                 20
#define SYS_X86_64_access                 21
#define SYS_X86_64_pipe                   22
#define SYS_X86_64_select                 23
#define SYS_X86_64_sched_yield            24
#define SYS_X86_64_mremap                 25
#define SYS_X86_64_msync                  26
#define SYS_X86_64_mincore                27
#define SYS_X86_64_madvise                28
#define SYS_X86_64_shmget                 29
#define SYS_X86_64_shmat                  30
#define SYS_X86_64_shmctl                 31
#define SYS_X86_64_dup                    32
#define SYS_X86_64_dup2                   33
#define SYS_X86_64_pause                  34
#define SYS_X86_64_nanosleep              35
#define SYS_X86_64_getitimer              36
#define SYS_X86_64_alarm                  37
#define SYS_X86_64_setitimer              38
#define SYS_X86_64_getpid                 39
#define SYS_X86_64_sendfile               40
#define SYS_X86_64_socket                 41
#define SYS_X86_64_connect                42
#define SYS_X86_64_accept                 43
#define SYS_X86_64_sendto                 44
#define SYS_X86_64_recvfrom               45
#define SYS_X86_64_sendmsg                46
#define SYS_X86_64_recvmsg                47
#define SYS_X86_64_shutdown               48
#define SYS_X86_64_bind                   49
#define SYS_X86_64_listen                 50
#define SYS_X86_64_getsockname            51
#define SYS_X86_64_getpeername            52
#define SYS_X86_64_socketpair             53
#define SYS_X86_64_setsockopt             54
#define SYS_X86_64_getsockopt             55
#define SYS_X86_64_clone                  56
#define SYS_X86_64_fork                   57
#define SYS_X86_64_vfork                  58
#define SYS_X86_64_execve                 59
#define SYS_X86_64_exit                   60
#define SYS_X86_64_wait4                  61
#define SYS_X86_64_kill                   62
#define SYS_X86_64_uname                  63
#define SYS_X86_64_semget                 64
#define SYS_X86_64_semop                  65
#define SYS_X86_64_semctl                 66
#define SYS_X86_64_shmdt                  67
#define SYS_X86_64_msgget                 68
#define SYS_X86_64_msgsnd                 69
#define SYS_X86_64_msgrcv                 70
#define SYS_X86_64_msgctl                 71
#define SYS_X86_64_fcntl                  72
#define SYS_X86_64_flock                  73
#define SYS_X86_64_fsync                  74
#define SYS_X86_64_fdatasync              75
#define SYS_X86_64_truncate               76
#define SYS_X86_64_ftruncate              77
#define SYS_X86_64_getdents               78
#define SYS_X86_64_getcwd                 79
#define SYS_X86_64_chdir                  80
#define SYS_X86_64_fchdir                 81
#define SYS_X86_64_rename                 82
#define SYS_X86_64_mkdir                  83
#define SYS_X86_64_rmdir                  84
#define SYS_X86_64_creat                  85
#define SYS_X86_64_link                   86
#define SYS_X86_64_unlink                 87
#define SYS_X86_64_symlink                88
#define SYS_X86_64_readlink               89
#define SYS_X86_64_chmod                  90
#define SYS_X86_64_fchmod                 91
#define SYS_X86_64_chown                  92
#define SYS_X86_64_fchown                 93
#define SYS_X86_64_lchown                 94
#define SYS_X86_64_umask                  95
#define SYS_X86_64_gettimeofday           96
#define SYS_X86_64_getrlimit              97
#define SYS_X86_64_getrusage              98
#define SYS_X86_64_sysinfo                99
#define SYS_X86_64_times                 100
#define SYS_X86_64_ptrace                101
#define SYS_X86_64_getuid                102
#define SYS_X86_64_syslog                103
#define SYS_X86_64_getgid                104
#define SYS_X86_64_setuid                105
#define SYS_X86_64_setgid                106
#define SYS_X86_64_geteuid               107
#define SYS_X86_64_getegid               108
#define SYS_X86_64_setpgid               109
#define SYS_X86_64_getppid               110
#define SYS_X86_64_getpgrp               111
#define SYS_X86_64_setsid                112
#define SYS_X86_64_setreuid              113
#define SYS_X86_64_setregid              114
#define SYS_X86_64_getgroups             115
#define SYS_X86_64_setgroups             116
#define SYS_X86_64_setresuid             117
#define SYS_X86_64_getresuid             118
#define SYS_X86_64_setresgid             119
#define SYS_X86_64_getresgid             120
#define SYS_X86_64_getpgid               121
#define SYS_X86_64_setfsuid              122
#define SYS_X86_64_setfsgid              123
#define SYS_X86_64_getsid                124
#define SYS_X86_64_capget                125
#define SYS_X86_64_capset                126
#define SYS_X86_64_rt_sigpending         127
#define SYS_X86_64_rt_sigtimedwait       128
#define SYS_X86_64_rt_sigqueueinfo       129
#define SYS_X86_64_rt_sigsuspend         130
#define SYS_X86_64_sigaltstack           131
#define SYS_X86_64_utime                 132
#define SYS_X86_64_mknod                 133
#define SYS_X86_64_uselib                134
#define SYS_X86_64_personality           135
#define SYS_X86_64_ustat                 136
#define SYS_X86_64_statfs                137
#define SYS_X86_64_fstatfs               138
#define SYS_X86_64_sysfs                 139
#define SYS_X86_64_getpriority           140
#define SYS_X86_64_setpriority           141
#define SYS_X86_64_sched_setparam        142
#define SYS_X86_64_sched_getparam        143
#define SYS_X86_64_sched_setscheduler    144
#define SYS_X86_64_sched_getscheduler    145
#define SYS_X86_64_sched_get_priority_max 146
#define SYS_X86_64_sched_get_priority_min 147
#define SYS_X86_64_sched_rr_get_interval 148
#define SYS_X86_64_mlock                 149
#define SYS_X86_64_munlock               150
#define SYS_X86_64_mlockall              151
#define SYS_X86_64_munlockall            152
#define SYS_X86_64_vhangup               153
#define SYS_X86_64_modify_ldt            154
#define SYS_X86_64_pivot_root            155
#define SYS_X86_64__sysctl               156
#define SYS_X86_64_prctl                 157
#define SYS_X86_64_arch_prctl            158
#define SYS_X86_64_adjtimex              159
#define SYS_X86_64_setrlimit             160
#define SYS_X86_64_chroot                161
#define SYS_X86_64_sync                  162
#define SYS_X86_64_acct                  163
#define SYS_X86_64_settimeofday          164
#define SYS_X86_64_mount                 165
#define SYS_X86_64_umount2               166
#define SYS_X86_64_swapon                167
#define SYS_X86_64_swapoff               168
#define SYS_X86_64_reboot                169
#define SYS_X86_64_sethostname           170
#define SYS_X86_64_setdomainname         171
#define SYS_X86_64_iopl                  172
#define SYS_X86_64_ioperm                173
#define SYS_X86_64_create_module         174
#define SYS_X86_64_init_module           175
#define SYS_X86_64_delete_module         176
#define SYS_X86_64_get_kernel_syms       177
#define SYS_X86_64_query_module          178
#define SYS_X86_64_quotactl              179
#define SYS_X86_64_nfsservctl            180
#define SYS_X86_64_getpmsg               181
#define SYS_X86_64_putpmsg               182
#define SYS_X86_64_afs_syscall           183
#define SYS_X86_64_tuxcall               184
#define SYS_X86_64_security              185
#define SYS_X86_64_gettid                186
#define SYS_X86_64_readahead             187
#define SYS_X86_64_setxattr              188
#define SYS_X86_64_lsetxattr             189
#define SYS_X86_64_fsetxattr             190
#define SYS_X86_64_getxattr              191
#define SYS_X86_64_lgetxattr             192
#define SYS_X86_64_fgetxattr             193
#define SYS_X86_64_listxattr             194
#define SYS_X86_64_llistxattr            195
#define SYS_X86_64_flistxattr            196
#define SYS_X86_64_removexattr           197
#define SYS_X86_64_lremovexattr          198
#define SYS_X86_64_fremovexattr          199
#define SYS_X86_64_tkill                 200
#define SYS_X86_64_time                  201
#define SYS_X86_64_futex                 202
#define SYS_X86_64_sched_setaffinity     203
#define SYS_X86_64_sched_getaffinity     204
#define SYS_X86_64_set_thread_area       205
#define SYS_X86_64_io_setup              206
#define SYS_X86_64_io_destroy            207
#define SYS_X86_64_io_getevents          208
#define SYS_X86_64_io_submit             209
#define SYS_X86_64_io_cancel             210
#define SYS_X86_64_get_thread_area       211
#define SYS_X86_64_lookup_dcookie        212
#define SYS_X86_64_epoll_create          213
#define SYS_X86_64_epoll_ctl_old         214
#define SYS_X86_64_epoll_wait_old        215
#define SYS_X86_64_remap_file_pages      216
#define SYS_X86_64_getdents64            217
#define SYS_X86_64_set_tid_address       218
#define SYS_X86_64_restart_syscall       219
#define SYS_X86_64_semtimedop            220
#define SYS_X86_64_fadvise64             221
#define SYS_X86_64_timer_create          222
#define SYS_X86_64_timer_settime         223
#define SYS_X86_64_timer_gettime         224
#define SYS_X86_64_timer_getoverrun      225
#define SYS_X86_64_timer_delete          226
#define SYS_X86_64_clock_settime         227
#define SYS_X86_64_clock_gettime         228
#define SYS_X86_64_clock_getres          229
#define SYS_X86_64_clock_nanosleep       230
#define SYS_X86_64_exit_group            231
#define SYS_X86_64_epoll_wait            232
#define SYS_X86_64_epoll_ctl             233
#define SYS_X86_64_tgkill                234
#define SYS_X86_64_utimes                235
#define SYS_X86_64_vserver               236
#define SYS_X86_64_mbind                 237
#define SYS_X86_64_set_mempolicy         238
#define SYS_X86_64_get_mempolicy         239
#define SYS_X86_64_mq_open               240
#define SYS_X86_64_mq_unlink             241
#define SYS_X86_64_mq_timedsend          242
#define SYS_X86_64_mq_timedreceive       243
#define SYS_X86_64_mq_notify             244
#define SYS_X86_64_mq_getsetattr         245
#define SYS_X86_64_kexec_load            246
#define SYS_X86_64_waitid                247
#define SYS_X86_64_add_key               248
#define SYS_X86_64_request_key           249
#define SYS_X86_64_keyctl                250
#define SYS_X86_64_ioprio_set            251
#define SYS_X86_64_ioprio_get            252
#define SYS_X86_64_inotify_init          253
#define SYS_X86_64_inotify_add_watch     254
#define SYS_X86_64_inotify_rm_watch      255
#define SYS_X86_64_migrate_pages         256
#define SYS_X86_64_openat                257
#define SYS_X86_64_mkdirat               258
#define SYS_X86_64_mknodat               259
#define SYS_X86_64_fchownat              260
#define SYS_X86_64_futimesat             261
#define SYS_X86_64_newfstatat            262
#define SYS_X86_64_unlinkat              263
#define SYS_X86_64_renameat              264
#define SYS_X86_64_linkat                265
#define SYS_X86_64_symlinkat             266
#define SYS_X86_64_readlinkat            267
#define SYS_X86_64_fchmodat              268
#define SYS_X86_64_faccessat             269
#define SYS_X86_64_pselect6              270
#define SYS_X86_64_ppoll                 271
#define SYS_X86_64_unshare               272
#define SYS_X86_64_set_robust_list       273
#define SYS_X86_64_get_robust_list       274
#define SYS_X86_64_splice                275
#define SYS_X86_64_tee                   276
#define SYS_X86_64_sync_file_range       277
#define SYS_X86_64_vmsplice              278
#define SYS_X86_64_move_pages            279
#define SYS_X86_64_utimensat             280
#define SYS_X86_64_epoll_pwait           281
#define SYS_X86_64_signalfd              282
#define SYS_X86_64_timerfd_create        283
#define SYS_X86_64_eventfd               284
#define SYS_X86_64_fallocate             285
#define SYS_X86_64_timerfd_settime       286
#define SYS_X86_64_timerfd_gettime       287
#define SYS_X86_64_accept4               288
#define SYS_X86_64_signalfd4             289
#define SYS_X86_64_eventfd2              290
#define SYS_X86_64_epoll_create1         291
#define SYS_X86_64_dup3                  292
#define SYS_X86_64_pipe2                 293
#define SYS_X86_64_inotify_init1         294
#define SYS_X86_64_preadv                295
#define SYS_X86_64_pwritev               296
#define SYS_X86_64_rt_tgsigqueueinfo     297
#define SYS_X86_64_perf_event_open       298
#define SYS_X86_64_recvmmsg              299
#define SYS_X86_64_fanotify_init         300
#define SYS_X86_64_fanotify_mark         301
#define SYS_X86_64_prlimit64             302
#define SYS_X86_64_name_to_handle_at     303
#define SYS_X86_64_open_by_handle_at     304
#define SYS_X86_64_clock_adjtime         305
#define SYS_X86_64_syncfs                306
#define SYS_X86_64_sendmmsg              307
#define SYS_X86_64_setns                 308
#define SYS_X86_64_getcpu                309
#define SYS_X86_64_process_vm_readv      310
#define SYS_X86_64_process_vm_writev     311
#define SYS_X86_64_kcmp                  312
#define SYS_X86_64_finit_module          313
#define SYS_X86_64_sched_setattr         314
#define SYS_X86_64_sched_getattr         315
#define SYS_X86_64_renameat2             316
#define SYS_X86_64_seccomp               317
#define SYS_X86_64_getrandom             318
#define SYS_X86_64_memfd_create          319
#define SYS_X86_64_kexec_file_load       320
#define SYS_X86_64_bpf                   321
#define SYS_X86_64_execveat              322
#define SYS_X86_64_userfaultfd           323
#define SYS_X86_64_membarrier            324
#define SYS_X86_64_mlock2                325
#define SYS_X86_64_copy_file_range       326
#define SYS_X86_64_preadv2               327
#define SYS_X86_64_pwritev2              328
#define SYS_X86_64_pkey_mprotect         329
#define SYS_X86_64_pkey_alloc            330
#define SYS_X86_64_pkey_free             331
#define SYS_X86_64_statx                 332
#define SYS_X86_64_io_pgetevents         333
#define SYS_X86_64_rseq                  334
#define SYS_X86_64_pidfd_send_signal     424
#define SYS_X86_64_io_uring_setup        425
#define SYS_X86_64_io_uring_enter        426
#define SYS_X86_64_io_uring_register     427
#define SYS_X86_64_open_tree             428
#define SYS_X86_64_move_mount            429
#define SYS_X86_64_fsopen                430
#define SYS_X86_64_fsconfig              431
#define SYS_X86_64_fsmount               432
#define SYS_X86_64_fspick                433
#define SYS_X86_64_pidfd_open            434
#define SYS_X86_64_clone3                435
#define SYS_X86_64_close_range           436
#define SYS_X86_64_openat2               437
#define SYS_X86_64_pidfd_getfd           438
#define SYS_X86_64_faccessat2            439
#define SYS_X86_64_process_madvise       440

#endif /* __SYSCALL_TABLE_X86_64_H__ */
