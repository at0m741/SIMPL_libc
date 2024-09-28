#ifndef __SYSCALL_TABLE_AARCH64_H__
#define __SYSCALL_TABLE_AARCH64_H__

#define SYS_AARCH64_io_setup            0
#define SYS_AARCH64_io_destroy          1
#define SYS_AARCH64_io_submit           2
#define SYS_AARCH64_io_cancel           3
#define SYS_AARCH64_io_getevents        4
#define SYS_AARCH64_setxattr            5
#define SYS_AARCH64_lsetxattr           6
#define SYS_AARCH64_fsetxattr           7
#define SYS_AARCH64_getxattr            8
#define SYS_AARCH64_lgetxattr           9
#define SYS_AARCH64_fgetxattr           10
#define SYS_AARCH64_listxattr           11
#define SYS_AARCH64_llistxattr          12
#define SYS_AARCH64_flistxattr          13
#define SYS_AARCH64_removexattr         14
#define SYS_AARCH64_lremovexattr        15
#define SYS_AARCH64_fremovexattr        16
#define SYS_AARCH64_getcwd              17
#define SYS_AARCH64_lookup_dcookie      18
#define SYS_AARCH64_eventfd2            19
#define SYS_AARCH64_epoll_create1       20
#define SYS_AARCH64_epoll_ctl           21
#define SYS_AARCH64_epoll_pwait         22
#define SYS_AARCH64_dup                 23
#define SYS_AARCH64_dup3                24
#define SYS_AARCH64_fcntl               25
#define SYS_AARCH64_inotify_init1       26
#define SYS_AARCH64_inotify_add_watch   27
#define SYS_AARCH64_inotify_rm_watch    28
#define SYS_AARCH64_ioctl               29
#define SYS_AARCH64_ioprio_set          30
#define SYS_AARCH64_ioprio_get          31
#define SYS_AARCH64_flock               32
#define SYS_AARCH64_mknodat             33
#define SYS_AARCH64_mkdirat             34
#define SYS_AARCH64_unlinkat            35
#define SYS_AARCH64_symlinkat           36
#define SYS_AARCH64_linkat              37
#define SYS_AARCH64_renameat            38
#define SYS_AARCH64_umount2             39
#define SYS_AARCH64_mount               40
#define SYS_AARCH64_pivot_root          41
#define SYS_AARCH64_nfsservctl          42
#define SYS_AARCH64_statfs              43
#define SYS_AARCH64_fstatfs             44
#define SYS_AARCH64_truncate            45
#define SYS_AARCH64_ftruncate           46
#define SYS_AARCH64_fallocate           47
#define SYS_AARCH64_faccessat           48
#define SYS_AARCH64_chdir               49
#define SYS_AARCH64_fchdir              50
#define SYS_AARCH64_chroot              51
#define SYS_AARCH64_fchmod              52
#define SYS_AARCH64_fchmodat            53
#define SYS_AARCH64_fchownat            54
#define SYS_AARCH64_fchown              55
#define SYS_AARCH64_openat              56
#define SYS_AARCH64_close               57
#define SYS_AARCH64_vhangup             58
#define SYS_AARCH64_pipe2               59
#define SYS_AARCH64_quotactl            60
#define SYS_AARCH64_getdents64          61
#define SYS_AARCH64_lseek               62
#define SYS_AARCH64_read                63
#define SYS_AARCH64_write               64
#define SYS_AARCH64_readv               65
#define SYS_AARCH64_writev              66
#define SYS_AARCH64_pread64             67
#define SYS_AARCH64_pwrite64            68
#define SYS_AARCH64_preadv              69
#define SYS_AARCH64_pwritev             70
#define SYS_AARCH64_sendfile            71
#define SYS_AARCH64_pselect6            72
#define SYS_AARCH64_ppoll               73
#define SYS_AARCH64_signalfd4           74
#define SYS_AARCH64_vmsplice            75
#define SYS_AARCH64_splice              76
#define SYS_AARCH64_tee                 77
#define SYS_AARCH64_readlinkat          78
#define SYS_AARCH64_newfstatat          79
#define SYS_AARCH64_fstat               80
#define SYS_AARCH64_sync                81
#define SYS_AARCH64_fsync               82
#define SYS_AARCH64_fdatasync           83
#define SYS_AARCH64_sync_file_range     84
#define SYS_AARCH64_timerfd_create      85
#define SYS_AARCH64_timerfd_settime     86
#define SYS_AARCH64_timerfd_gettime     87
#define SYS_AARCH64_utimensat           88
#define SYS_AARCH64_acct                89
#define SYS_AARCH64_capget              90
#define SYS_AARCH64_capset              91
#define SYS_AARCH64_personality         92
#define SYS_AARCH64_exit                93
#define SYS_AARCH64_exit_group          94
#define SYS_AARCH64_waitid              95
#define SYS_AARCH64_set_tid_address     96
#define SYS_AARCH64_unshare             97
#define SYS_AARCH64_futex               98
#define SYS_AARCH64_set_robust_list     99
#define SYS_AARCH64_get_robust_list     100
#define SYS_AARCH64_nanosleep           101
#define SYS_AARCH64_getitimer           102
#define SYS_AARCH64_setitimer           103
#define SYS_AARCH64_kexec_load          104
#define SYS_AARCH64_init_module         105
#define SYS_AARCH64_delete_module       106
#define SYS_AARCH64_timer_create        107
#define SYS_AARCH64_timer_gettime       108
#define SYS_AARCH64_timer_getoverrun    109
#define SYS_AARCH64_timer_settime       110
#define SYS_AARCH64_timer_delete        111
#define SYS_AARCH64_clock_settime       112
#define SYS_AARCH64_clock_gettime       113
#define SYS_AARCH64_clock_getres        114
#define SYS_AARCH64_clock_nanosleep     115
#define SYS_AARCH64_syslog              116
#define SYS_AARCH64_ptrace              117
#define SYS_AARCH64_sched_setparam      118
#define SYS_AARCH64_sched_setscheduler  119
#define SYS_AARCH64_sched_getscheduler  120
#define SYS_AARCH64_sched_getparam      121
#define SYS_AARCH64_sched_setaffinity   122
#define SYS_AARCH64_sched_getaffinity   123
#define SYS_AARCH64_sched_yield         124
#define SYS_AARCH64_sched_get_priority_max 125
#define SYS_AARCH64_sched_get_priority_min 126
#define SYS_AARCH64_sched_rr_get_interval 127
#define SYS_AARCH64_restart_syscall     128
#define SYS_AARCH64_kill                129
#define SYS_AARCH64_tkill               130
#define SYS_AARCH64_tgkill              131
#define SYS_AARCH64_sigaltstack         132
#define SYS_AARCH64_rt_sigsuspend       133
#define SYS_AARCH64_rt_sigaction        134
#define SYS_AARCH64_rt_sigprocmask      135
#define SYS_AARCH64_rt_sigpending       136
#define SYS_AARCH64_rt_sigtimedwait     137
#define SYS_AARCH64_rt_sigqueueinfo     138
#define SYS_AARCH64_rt_sigreturn        139
#define SYS_AARCH64_setpriority         140
#define SYS_AARCH64_getpriority         141
#define SYS_AARCH64_reboot              142
#define SYS_AARCH64_setregid            143
#define SYS_AARCH64_setgid              144
#define SYS_AARCH64_setreuid            145
#define SYS_AARCH64_setuid              146
#define SYS_AARCH64_setresuid           147
#define SYS_AARCH64_getresuid           148
#define SYS_AARCH64_setresgid           149
#define SYS_AARCH64_getresgid           150
#define SYS_AARCH64_setfsuid            151
#define SYS_AARCH64_setfsgid            152
#define SYS_AARCH64_times               153
#define SYS_AARCH64_setpgid             154
#define SYS_AARCH64_getpgid             155
#define SYS_AARCH64_getsid              156
#define SYS_AARCH64_setsid              157
#define SYS_AARCH64_getgroups           158
#define SYS_AARCH64_setgroups           159
#define SYS_AARCH64_uname               160
#define SYS_AARCH64_sethostname         161
#define SYS_AARCH64_setdomainname       162
#define SYS_AARCH64_getrlimit           163
#define SYS_AARCH64_setrlimit           164
#define SYS_AARCH64_getrusage           165
#define SYS_AARCH64_umask               166
#define SYS_AARCH64_prctl               167
#define SYS_AARCH64_getcpu              168
#define SYS_AARCH64_gettimeofday        169
#define SYS_AARCH64_settimeofday        170
#define SYS_AARCH64_adjtimex            171
#define SYS_AARCH64_getpid              172
#define SYS_AARCH64_getppid             173
#define SYS_AARCH64_getuid              174
#define SYS_AARCH64_geteuid             175
#define SYS_AARCH64_getgid              176
#define SYS_AARCH64_getegid             177
#define SYS_AARCH64_gettid              178
#define SYS_AARCH64_sysinfo             179
#define SYS_AARCH64_mq_open             180
#define SYS_AARCH64_mq_unlink           181
#define SYS_AARCH64_mq_timedsend        182
#define SYS_AARCH64_mq_timedreceive     183
#define SYS_AARCH64_mq_notify           184
#define SYS_AARCH64_mq_getsetattr       185
#define SYS_AARCH64_msgget              186
#define SYS_AARCH64_msgctl              187
#define SYS_AARCH64_msgrcv              188
#define SYS_AARCH64_msgsnd              189
#define SYS_AARCH64_semget              190
#define SYS_AARCH64_semctl              191
#define SYS_AARCH64_semtimedop          192
#define SYS_AARCH64_semop               193
#define SYS_AARCH64_shmget              194
#define SYS_AARCH64_shmctl              195
#define SYS_AARCH64_shmat               196
#define SYS_AARCH64_shmdt               197
#define SYS_AARCH64_socket              198
#define SYS_AARCH64_socketpair          199
#define SYS_AARCH64_bind                200
#define SYS_AARCH64_listen              201
#define SYS_AARCH64_accept              202
#define SYS_AARCH64_connect             203
#define SYS_AARCH64_getsockname         204
#define SYS_AARCH64_getpeername         205
#define SYS_AARCH64_sendto              206
#define SYS_AARCH64_recvfrom            207
#define SYS_AARCH64_setsockopt          208
#define SYS_AARCH64_getsockopt          209
#define SYS_AARCH64_shutdown            210
#define SYS_AARCH64_sendmsg             211
#define SYS_AARCH64_recvmsg             212
#define SYS_AARCH64_readahead           213
#define SYS_AARCH64_brk                 214
#define SYS_AARCH64_munmap              215
#define SYS_AARCH64_mremap              216
#define SYS_AARCH64_add_key             217
#define SYS_AARCH64_request_key         218
#define SYS_AARCH64_keyctl              219
#define SYS_AARCH64_clone               220
#define SYS_AARCH64_execve              221
#define SYS_AARCH64_mmap                222
#define SYS_AARCH64_fadvise64           223
#define SYS_AARCH64_swapon              224
#define SYS_AARCH64_swapoff             225
#define SYS_AARCH64_mprotect            226
#define SYS_AARCH64_msync               227
#define SYS_AARCH64_mlock               228
#define SYS_AARCH64_munlock             229
#define SYS_AARCH64_mlockall            230
#define SYS_AARCH64_munlockall           231
#define SYS_AARCH64_mincore              232
#define SYS_AARCH64_madvise              233
#define SYS_AARCH64_remap_file_pages      234
#define SYS_AARCH64_mbind                235
#define SYS_AARCH64_get_mempolicy        236
#define SYS_AARCH64_set_mempolicy        237
#define SYS_AARCH64_migrate_pages        238
#define SYS_AARCH64_move_pages           239
#define SYS_AARCH64_rt_tgsigqueueinfo    240
#define SYS_AARCH64_perf_event_open      241
#define SYS_AARCH64_accept4              242
#define SYS_AARCH64_recvmmsg             243
#define SYS_AARCH64_wait4                260
#define SYS_AARCH64_prlimit64            261
#define SYS_AARCH64_fanotify_init        262
#define SYS_AARCH64_fanotify_mark        263
#define SYS_AARCH64_name_to_handle_at    264
#define SYS_AARCH64_open_by_handle_at    265
#define SYS_AARCH64_clock_adjtime        266
#define SYS_AARCH64_syncfs               267
#define SYS_AARCH64_setns                268
#define SYS_AARCH64_sendmmsg             269
#define SYS_AARCH64_process_vm_readv     270
#define SYS_AARCH64_process_vm_writev    271
#define SYS_AARCH64_kcmp                 272
#define SYS_AARCH64_finit_module         273
#define SYS_AARCH64_sched_setattr        274
#define SYS_AARCH64_sched_getattr        275
#define SYS_AARCH64_renameat2            276
#define SYS_AARCH64_seccomp              277
#define SYS_AARCH64_getrandom            278
#define SYS_AARCH64_memfd_create         279
#define SYS_AARCH64_bpf                  280
#define SYS_AARCH64_execveat             281
#define SYS_AARCH64_userfaultfd          282
#define SYS_AARCH64_membarrier           283
#define SYS_AARCH64_mlock2               284
#define SYS_AARCH64_copy_file_range      285
#define SYS_AARCH64_preadv2              286
#define SYS_AARCH64_pwritev2             287
#define SYS_AARCH64_pkey_mprotect        288
#define SYS_AARCH64_pkey_alloc           289
#define SYS_AARCH64_pkey_free            290
#define SYS_AARCH64_statx                291
#define SYS_AARCH64_io_uring_setup       425
#define SYS_AARCH64_io_uring_enter       426
#define SYS_AARCH64_faccessat2           439


#define SYS_AARCH64_arch_prctl           -1
#define SYS_AARCH64_modify_ldt           -1
#define SYS_AARCH64_iopl                 -1
#define SYS_AARCH64_ioperm               -1
#define SYS_AARCH64_create_module        -1
#define SYS_AARCH64_get_kernel_syms      -1
#define SYS_AARCH64_query_module         -1
#define SYS_AARCH64_getpmsg              -1
#define SYS_AARCH64_putpmsg              -1
#define SYS_AARCH64_afs_syscall          -1
#define SYS_AARCH64_tuxcall              -1
#define SYS_AARCH64_security             -1
#define SYS_AARCH64_vm86                 -1
#define SYS_AARCH64_vm86old              -1
#define SYS_AARCH64_sigreturn            -1
#define SYS_AARCH64_syscall              -1
#define SYS_AARCH64__sysctl              -1
#define SYS_AARCH64_vserver              -1
#define SYS_AARCH64_uselib               -1
#define SYS_AARCH64_mmap2                -1
#define SYS_AARCH64_sigprocmask          -1
#define SYS_AARCH64_sigpending           -1
#define SYS_AARCH64_sigaction            -1
#define SYS_AARCH64_time                 -1
#define SYS_AARCH64_alarm                -1
#define SYS_AARCH64_pause                -1
#define SYS_AARCH64_ustat                -1
#define SYS_AARCH64_nice                 -1
#define SYS_AARCH64_vfork                -1
#define SYS_AARCH64_fork                 -1
#define SYS_AARCH64_waitpid              -1
#define SYS_AARCH64_sendfile64           -1
#define SYS_AARCH64_io_pgetevents        -1
#define SYS_AARCH64_rseq                 -1
#define SYS_AARCH64_pidfd_send_signal    -1
#define SYS_AARCH64_io_uring_register    -1
#define SYS_AARCH64_open_tree            -1
#define SYS_AARCH64_move_mount           -1
#define SYS_AARCH64_fsopen               -1
#define SYS_AARCH64_fsconfig             -1
#define SYS_AARCH64_fsmount              -1
#define SYS_AARCH64_fspick               -1
#define SYS_AARCH64_pidfd_open           -1
#define SYS_AARCH64_clone3               -1
#define SYS_AARCH64_close_range          -1
#define SYS_AARCH64_openat2              -1
#define SYS_AARCH64_pidfd_getfd          -1
#define SYS_AARCH64_process_madvise      -1
#define SYS_AARCH64_dup2				 -1


#endif /* __SYSCALL_TABLE_AARCH64_H__ */
