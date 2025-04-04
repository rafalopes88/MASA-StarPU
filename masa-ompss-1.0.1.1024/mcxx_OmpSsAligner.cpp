typedef long int ptrdiff_t;
typedef unsigned long int size_t;
typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;
typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef short int __int16_t;
typedef unsigned short int __uint16_t;
typedef int __int32_t;
typedef unsigned int __uint32_t;
typedef long int __int64_t;
typedef unsigned long int __uint64_t;
typedef long int __quad_t;
typedef unsigned long int __u_quad_t;
typedef long int __intmax_t;
typedef unsigned long int __uintmax_t;
typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
struct  __fsid_t
{
    int __val[2L];
};
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;
typedef int __daddr_t;
typedef int __key_t;
typedef int __clockid_t;
typedef void *__timer_t;
typedef long int __blksize_t;
typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;
typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;
typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;
typedef long int __fsword_t;
typedef long int __ssize_t;
typedef long int __syscall_slong_t;
typedef unsigned long int __syscall_ulong_t;
typedef ::__off64_t __loff_t;
typedef char *__caddr_t;
typedef long int __intptr_t;
typedef unsigned int __socklen_t;
typedef int __sig_atomic_t;
typedef ::__int8_t int8_t;
typedef ::__int16_t int16_t;
typedef ::__int32_t int32_t;
typedef ::__int64_t int64_t;
typedef ::__uint8_t uint8_t;
typedef ::__uint16_t uint16_t;
typedef ::__uint32_t uint32_t;
typedef ::__uint64_t uint64_t;
typedef signed char int_least8_t;
typedef short int int_least16_t;
typedef int int_least32_t;
typedef long int int_least64_t;
typedef unsigned char uint_least8_t;
typedef unsigned short int uint_least16_t;
typedef unsigned int uint_least32_t;
typedef unsigned long int uint_least64_t;
typedef signed char int_fast8_t;
typedef long int int_fast16_t;
typedef long int int_fast32_t;
typedef long int int_fast64_t;
typedef unsigned char uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long int uint_fast64_t;
typedef long int intptr_t;
typedef unsigned long int uintptr_t;
typedef ::__intmax_t intmax_t;
typedef ::__uintmax_t uintmax_t;
struct  nanos_region_dimension_internal_t
{
    ::size_t size;
    ::size_t lower_bound;
    ::size_t accessed_length;
};
struct  nanos_access_type_internal_t
{
    bool input:1;
    bool output:1;
    bool can_rename:1;
    bool concurrent:1;
    bool commutative:1;
};
struct  nanos_data_access_internal_t
{
    void *address;
    ::nanos_access_type_internal_t flags;
    short int dimension_count;
    const ::nanos_region_dimension_internal_t *dimensions;
    ::ptrdiff_t offset;
};
enum nanos_sharing_t
{
  NANOS_PRIVATE = 0,
  NANOS_SHARED = 1
};
struct  nanos_reduction_t
{
    void *original;
    void *privates;
    ::size_t element_size;
    ::size_t num_scalars;
    void *descriptor;
    void (*bop)(void *, void *, int);
    void (*vop)(int, void *, void *);
    void (*cleanup)(void *);
};
typedef unsigned int reg_t;
typedef unsigned int memory_space_id_t;
struct  nanos_copy_data_internal_t
{
    void *address;
    ::nanos_sharing_t sharing;
    struct  mcc_struct_anon_6
    {
        bool input:1;
        bool output:1;
    };
    ::nanos_copy_data_internal_t::mcc_struct_anon_6 flags;
    short int dimension_count;
    const ::nanos_region_dimension_internal_t *dimensions;
    ::ptrdiff_t offset;
    ::uint64_t host_base_address;
    ::reg_t host_region_id;
    bool remote_host;
    void *deducted_cd;
};
typedef ::nanos_access_type_internal_t nanos_access_type_t;
typedef ::nanos_region_dimension_internal_t nanos_region_dimension_t;
typedef ::nanos_data_access_internal_t nanos_data_access_t;
typedef ::nanos_copy_data_internal_t nanos_copy_data_t;
typedef void *nanos_thread_t;
typedef void *nanos_wd_t;
struct  nanos_compound_wd_data_t
{
    int nsect;
    ::nanos_wd_t lwd[];
};
struct  nanos_repeat_n_info_t
{
    int n;
};
struct  nanos_loop_info_t
{
    ::int64_t lower;
    ::int64_t upper;
    ::int64_t step;
    bool last;
    bool wait;
    ::int64_t chunk;
    ::int64_t stride;
    int thid;
    int threads;
    void *args;
};
typedef void *nanos_ws_t;
typedef void *nanos_ws_info_t;
typedef void *nanos_ws_data_t;
typedef void *nanos_ws_item_t;
struct  nanos_ws_info_loop_t
{
    ::int64_t lower_bound;
    ::int64_t upper_bound;
    ::int64_t loop_step;
    ::int64_t chunk_size;
};
struct  nanos_ws_item_loop_t
{
    ::int64_t lower;
    ::int64_t upper;
    bool execute:1;
    bool last:1;
};
struct nanos_ws_desc;
struct  nanos_ws_desc
{
    volatile ::nanos_ws_t ws;
    ::nanos_ws_data_t data;
    ::nanos_ws_desc *next;
    ::nanos_thread_t *threads;
    int nths;
};
typedef ::nanos_ws_desc nanos_ws_desc_t;
struct  nanos_wd_props_t
{
    bool mandatory_creation:1;
    bool tied:1;
    bool clear_chunk:1;
    bool reserved0:1;
    bool reserved1:1;
    bool reserved2:1;
    bool reserved3:1;
    bool reserved4:1;
};
struct  nanos_wd_dyn_flags_t
{
    bool is_final:1;
    bool is_recover:1;
    bool is_implicit:1;
    bool reserved3:1;
    bool reserved4:1;
    bool reserved5:1;
    bool reserved6:1;
    bool reserved7:1;
};
struct  nanos_wd_dyn_props_t
{
    ::nanos_wd_dyn_flags_t flags;
    ::nanos_thread_t tie_to;
    int priority;
    void *callback;
    void *arguments;
};
struct  nanos_device_t
{
    void *(*factory)(void *);
    void *arg;
};
struct  nanos_smp_args_t
{
    void (*outline)(void *);
};
extern "C"
{
  extern void *nanos_smp_factory_(void *args);
}
extern "C"
{
  extern void *nanos_smp_factory(void *args);
}
enum nanos_event_type_t
{
  NANOS_STATE_START = 0,
  NANOS_STATE_END = 1,
  NANOS_SUBSTATE_START = 2,
  NANOS_SUBSTATE_END = 3,
  NANOS_BURST_START = 4,
  NANOS_BURST_END = 5,
  NANOS_PTP_START = 6,
  NANOS_PTP_END = 7,
  NANOS_POINT = 8,
  EVENT_TYPES = 9
};
typedef unsigned int nanos_event_key_t;
typedef unsigned long long int nanos_event_value_t;
enum nanos_event_state_value_t
{
  NANOS_NOT_CREATED = 0,
  NANOS_NOT_RUNNING = 1,
  NANOS_STARTUP = 2,
  NANOS_SHUTDOWN = 3,
  NANOS_ERROR = 4,
  NANOS_IDLE = 5,
  NANOS_RUNTIME = 6,
  NANOS_RUNNING = 7,
  NANOS_SYNCHRONIZATION = 8,
  NANOS_SCHEDULING = 9,
  NANOS_CREATION = 10,
  NANOS_MEM_TRANSFER_ISSUE = 11,
  NANOS_CACHE = 12,
  NANOS_YIELD = 13,
  NANOS_ACQUIRING_LOCK = 14,
  NANOS_CONTEXT_SWITCH = 15,
  NANOS_FILL1 = 16,
  NANOS_WAKINGUP = 17,
  NANOS_STOPPED = 18,
  NANOS_SYNCED_RUNNING = 19,
  NANOS_DEBUG = 20,
  NANOS_EVENT_STATE_TYPES = 21
};
enum nanos_event_domain_t
{
  NANOS_WD_DOMAIN = 0,
  NANOS_WD_DEPENDENCY = 1,
  NANOS_WAIT = 2,
  NANOS_XFER_DATA = 3,
  NANOS_XFER_REQ = 4,
  NANOS_WD_REMOTE = 5,
  NANOS_AM_WORK = 6,
  NANOS_AM_WORK_DONE = 7,
  NANOS_XFER_WAIT_REQ_PUT = 8,
  NANOS_XFER_FREE_TMP_BUFF = 9
};
typedef long long int nanos_event_id_t;
struct  nanos_event_t
{
    ::nanos_event_type_t type;
    ::nanos_event_key_t key;
    ::nanos_event_value_t value;
    ::nanos_event_domain_t domain;
    ::nanos_event_id_t id;
};
enum nanos_lock_state_t
{
  NANOS_LOCK_FREE = 0,
  NANOS_LOCK_BUSY = 1
};
struct  nanos_lock_t
{
    volatile ::nanos_lock_state_t state_;
    inline nanos_lock_t(::nanos_lock_state_t init  = (::NANOS_LOCK_FREE))
      : state_(init)
    {
    }
};
typedef void (*nanos_translate_args_t)(void *, ::nanos_wd_t);
typedef void nanos_init_func_t(void *);
struct  nanos_init_desc_t
{
    ::nanos_init_func_t (*func);
    void *data;
};
enum nanos_err_t
{
  NANOS_OK = 0,
  NANOS_UNKNOWN_ERR = 1,
  NANOS_UNIMPLEMENTED = 2,
  NANOS_ENOMEM = 3,
  NANOS_INVALID_PARAM = 4,
  NANOS_INVALID_REQUEST = 5
};
typedef void *nanos_wg_t;
typedef void *nanos_team_t;
typedef void *nanos_sched_t;
typedef void *nanos_slicer_t;
typedef void *nanos_dd_t;
typedef void *nanos_sync_cond_t;
typedef unsigned int nanos_copy_id_t;
struct  nanos_const_wd_definition_tag
{
    ::nanos_wd_props_t props;
    ::size_t data_alignment;
    ::size_t num_copies;
    ::size_t num_devices;
    ::size_t num_dimensions;
    const char *description;
};
typedef ::nanos_const_wd_definition_tag nanos_const_wd_definition_t;
struct  nanos_const_wd_definition_1
{
    ::nanos_const_wd_definition_t base;
    ::nanos_device_t devices[1L];
};
struct  nanos_constraint_t
{
    int nthreads;
    void *arch;
};
typedef void *nanos_cpu_set_t;
typedef const void *const_nanos_cpu_set_t;
struct  nanos_const_wd_definition_internal_t : ::nanos_const_wd_definition_tag
{
    ::nanos_device_t devices[1L];
};
extern "C"
{
  extern char *nanos_get_mode_();
}
extern "C"
{
  extern char *nanos_get_mode();
}
extern "C"
{
  extern ::nanos_wd_t nanos_current_wd_();
}
extern "C"
{
  extern ::nanos_wd_t nanos_current_wd();
}
extern "C"
{
  extern int nanos_get_wd_id_(::nanos_wd_t wd);
}
extern "C"
{
  extern int nanos_get_wd_id(::nanos_wd_t wd);
}
extern "C"
{
  extern int nanos_get_wd_priority_(::nanos_wd_t wd);
}
extern "C"
{
  extern int nanos_get_wd_priority(::nanos_wd_t wd);
}
extern "C"
{
  extern void nanos_set_wd_priority_(::nanos_wd_t wd, int p);
}
extern "C"
{
  extern void nanos_set_wd_priority(::nanos_wd_t wd, int p);
}
extern "C"
{
  extern ::nanos_err_t nanos_get_wd_description_(const char **description, ::nanos_wd_t wd);
}
extern "C"
{
  extern ::nanos_err_t nanos_get_wd_description(const char **description, ::nanos_wd_t wd);
}
extern "C"
{
  extern ::nanos_slicer_t nanos_find_slicer_(const char *slicer);
}
extern "C"
{
  extern ::nanos_slicer_t nanos_find_slicer(const char *slicer);
}
extern "C"
{
  extern ::nanos_ws_t nanos_find_worksharing_(const char *label);
}
extern "C"
{
  extern ::nanos_ws_t nanos_find_worksharing(const char *label);
}
extern "C"
{
  extern ::nanos_err_t nanos_create_wd_compact_(::nanos_wd_t *wd, ::nanos_const_wd_definition_t *const_data, ::nanos_wd_dyn_props_t *dyn_props, ::size_t data_size, void **data, ::nanos_wg_t wg, ::nanos_copy_data_t **copies, ::nanos_region_dimension_internal_t **dimensions);
}
extern "C"
{
  extern ::nanos_err_t nanos_create_wd_compact(::nanos_wd_t *wd, ::nanos_const_wd_definition_t *const_data, ::nanos_wd_dyn_props_t *dyn_props, ::size_t data_size, void **data, ::nanos_wg_t wg, ::nanos_copy_data_t **copies, ::nanos_region_dimension_internal_t **dimensions);
}
extern "C"
{
  extern ::nanos_err_t nanos_set_translate_function_(::nanos_wd_t wd, ::nanos_translate_args_t translate_args);
}
extern "C"
{
  extern ::nanos_err_t nanos_set_translate_function(::nanos_wd_t wd, ::nanos_translate_args_t translate_args);
}
extern "C"
{
  extern ::nanos_err_t nanos_create_sliced_wd_(::nanos_wd_t *uwd, ::size_t num_devices, ::nanos_device_t *devices, ::size_t outline_data_size, int outline_data_align, void **outline_data, ::nanos_wg_t uwg, ::nanos_slicer_t slicer, ::nanos_wd_props_t *props, ::nanos_wd_dyn_props_t *dyn_props, ::size_t num_copies, ::nanos_copy_data_t **copies, ::size_t num_dimensions, ::nanos_region_dimension_internal_t **dimensions);
}
extern "C"
{
  extern ::nanos_err_t nanos_create_sliced_wd(::nanos_wd_t *uwd, ::size_t num_devices, ::nanos_device_t *devices, ::size_t outline_data_size, int outline_data_align, void **outline_data, ::nanos_wg_t uwg, ::nanos_slicer_t slicer, ::nanos_wd_props_t *props, ::nanos_wd_dyn_props_t *dyn_props, ::size_t num_copies, ::nanos_copy_data_t **copies, ::size_t num_dimensions, ::nanos_region_dimension_internal_t **dimensions);
}
extern "C"
{
  extern ::nanos_err_t nanos_submit_(::nanos_wd_t wd, ::size_t num_data_accesses, ::nanos_data_access_t *data_accesses, ::nanos_team_t team);
}
extern "C"
{
  extern ::nanos_err_t nanos_submit(::nanos_wd_t wd, ::size_t num_data_accesses, ::nanos_data_access_t *data_accesses, ::nanos_team_t team);
}
extern "C"
{
  extern ::nanos_err_t nanos_create_wd_and_run_compact_(::nanos_const_wd_definition_t *const_data, ::nanos_wd_dyn_props_t *dyn_props, ::size_t data_size, void *data, ::size_t num_data_accesses, ::nanos_data_access_t *data_accesses, ::nanos_copy_data_t *copies, ::nanos_region_dimension_internal_t *dimensions, ::nanos_translate_args_t translate_args);
}
extern "C"
{
  extern ::nanos_err_t nanos_create_wd_and_run_compact(::nanos_const_wd_definition_t *const_data, ::nanos_wd_dyn_props_t *dyn_props, ::size_t data_size, void *data, ::size_t num_data_accesses, ::nanos_data_access_t *data_accesses, ::nanos_copy_data_t *copies, ::nanos_region_dimension_internal_t *dimensions, ::nanos_translate_args_t translate_args);
}
extern "C"
{
  extern ::nanos_err_t nanos_create_for_();
}
extern "C"
{
  extern ::nanos_err_t nanos_create_for();
}
extern "C"
{
  extern ::nanos_err_t nanos_set_internal_wd_data_(::nanos_wd_t wd, void *data);
}
extern "C"
{
  extern ::nanos_err_t nanos_set_internal_wd_data(::nanos_wd_t wd, void *data);
}
extern "C"
{
  extern ::nanos_err_t nanos_get_internal_wd_data_(::nanos_wd_t wd, void **data);
}
extern "C"
{
  extern ::nanos_err_t nanos_get_internal_wd_data(::nanos_wd_t wd, void **data);
}
extern "C"
{
  extern ::nanos_err_t nanos_yield_();
}
extern "C"
{
  extern ::nanos_err_t nanos_yield();
}
extern "C"
{
  extern ::nanos_err_t nanos_slicer_get_specific_data_(::nanos_slicer_t slicer, void **data);
}
extern "C"
{
  extern ::nanos_err_t nanos_slicer_get_specific_data(::nanos_slicer_t slicer, void **data);
}
extern "C"
{
  extern ::nanos_err_t nanos_get_num_ready_tasks_(unsigned int *ready_tasks);
}
extern "C"
{
  extern ::nanos_err_t nanos_get_num_ready_tasks(unsigned int *ready_tasks);
}
extern "C"
{
  extern ::nanos_err_t nanos_get_num_total_tasks_(unsigned int *total_tasks);
}
extern "C"
{
  extern ::nanos_err_t nanos_get_num_total_tasks(unsigned int *total_tasks);
}
extern "C"
{
  extern ::nanos_err_t nanos_get_num_nonready_tasks_(unsigned int *nonready_tasks);
}
extern "C"
{
  extern ::nanos_err_t nanos_get_num_nonready_tasks(unsigned int *nonready_tasks);
}
extern "C"
{
  extern ::nanos_err_t nanos_get_num_running_tasks_(unsigned int *running_tasks);
}
extern "C"
{
  extern ::nanos_err_t nanos_get_num_running_tasks(unsigned int *running_tasks);
}
extern "C"
{
  extern ::nanos_err_t nanos_get_num_blocked_tasks_(unsigned int *blocked_tasks);
}
extern "C"
{
  extern ::nanos_err_t nanos_get_num_blocked_tasks(unsigned int *blocked_tasks);
}
extern "C"
{
  extern ::nanos_err_t nanos_in_final_(bool *result);
}
extern "C"
{
  extern ::nanos_err_t nanos_in_final(bool *result);
}
extern "C"
{
  extern ::nanos_err_t nanos_set_final_(bool value);
}
extern "C"
{
  extern ::nanos_err_t nanos_set_final(bool value);
}
extern "C"
{
  extern ::nanos_err_t nanos_switch_to_thread_(unsigned int *thid);
}
extern "C"
{
  extern ::nanos_err_t nanos_switch_to_thread(unsigned int *thid);
}
extern "C"
{
  extern ::nanos_err_t nanos_is_tied_(bool *result);
}
extern "C"
{
  extern ::nanos_err_t nanos_is_tied(bool *result);
}
extern "C"
{
  extern ::nanos_err_t nanos_create_team_(::nanos_team_t *team, ::nanos_sched_t sg, unsigned int *nthreads, ::nanos_constraint_t *constraints, bool reuse, ::nanos_thread_t *info, ::nanos_const_wd_definition_t *const_data);
}
extern "C"
{
  extern ::nanos_err_t nanos_create_team(::nanos_team_t *team, ::nanos_sched_t sg, unsigned int *nthreads, ::nanos_constraint_t *constraints, bool reuse, ::nanos_thread_t *info, ::nanos_const_wd_definition_t *const_data);
}
extern "C"
{
  extern ::nanos_err_t nanos_create_team_mapped_(::nanos_team_t *team, ::nanos_sched_t sg, unsigned int *nthreads, unsigned int *mapping);
}
extern "C"
{
  extern ::nanos_err_t nanos_create_team_mapped(::nanos_team_t *team, ::nanos_sched_t sg, unsigned int *nthreads, unsigned int *mapping);
}
extern "C"
{
  extern ::nanos_err_t nanos_enter_team_();
}
extern "C"
{
  extern ::nanos_err_t nanos_enter_team();
}
extern "C"
{
  extern ::nanos_err_t nanos_leave_team_();
}
extern "C"
{
  extern ::nanos_err_t nanos_leave_team();
}
extern "C"
{
  extern ::nanos_err_t nanos_end_team_(::nanos_team_t team);
}
extern "C"
{
  extern ::nanos_err_t nanos_end_team(::nanos_team_t team);
}
extern "C"
{
  extern ::nanos_err_t nanos_team_barrier_();
}
extern "C"
{
  extern ::nanos_err_t nanos_team_barrier();
}
extern "C"
{
  extern ::nanos_err_t nanos_single_guard_(bool *);
}
extern "C"
{
  extern ::nanos_err_t nanos_single_guard(bool *);
}
extern "C"
{
  extern ::nanos_err_t nanos_enter_sync_init_(bool *b);
}
extern "C"
{
  extern ::nanos_err_t nanos_enter_sync_init(bool *b);
}
extern "C"
{
  extern ::nanos_err_t nanos_wait_sync_init_();
}
extern "C"
{
  extern ::nanos_err_t nanos_wait_sync_init();
}
extern "C"
{
  extern ::nanos_err_t nanos_release_sync_init_();
}
extern "C"
{
  extern ::nanos_err_t nanos_release_sync_init();
}
extern "C"
{
  extern ::nanos_err_t nanos_memory_fence_();
}
extern "C"
{
  extern ::nanos_err_t nanos_memory_fence();
}
extern "C"
{
  extern ::nanos_err_t nanos_team_get_num_supporting_threads_(int *n);
}
extern "C"
{
  extern ::nanos_err_t nanos_team_get_num_supporting_threads(int *n);
}
extern "C"
{
  extern ::nanos_err_t nanos_team_get_supporting_threads_(int *n, ::nanos_thread_t *list_of_threads);
}
extern "C"
{
  extern ::nanos_err_t nanos_team_get_supporting_threads(int *n, ::nanos_thread_t *list_of_threads);
}
extern "C"
{
  extern ::nanos_err_t nanos_register_reduction_(::nanos_reduction_t *red);
}
extern "C"
{
  extern ::nanos_err_t nanos_register_reduction(::nanos_reduction_t *red);
}
extern "C"
{
  extern ::nanos_err_t nanos_reduction_get_private_data_(void **copy, void *original);
}
extern "C"
{
  extern ::nanos_err_t nanos_reduction_get_private_data(void **copy, void *original);
}
extern "C"
{
  extern ::nanos_err_t nanos_reduction_get_(::nanos_reduction_t **dest, void *original);
}
extern "C"
{
  extern ::nanos_err_t nanos_reduction_get(::nanos_reduction_t **dest, void *original);
}
extern "C"
{
  extern ::nanos_err_t nanos_task_reduction_register_(void *orig, ::size_t size_target, ::size_t size_elem, void (*init)(void *, void *), void (*reducer)(void *, void *));
}
extern "C"
{
  extern ::nanos_err_t nanos_task_reduction_register(void *orig, ::size_t size_target, ::size_t size_elem, void (*init)(void *, void *), void (*reducer)(void *, void *));
}
extern "C"
{
  extern ::nanos_err_t nanos_task_fortran_array_reduction_register_(void *orig, void *dep, ::size_t array_descriptor_size, void (*init)(void *, void *), void (*reducer)(void *, void *), void (*reducer_orig_var)(void *, void *));
}
extern "C"
{
  extern ::nanos_err_t nanos_task_fortran_array_reduction_register(void *orig, void *dep, ::size_t array_descriptor_size, void (*init)(void *, void *), void (*reducer)(void *, void *), void (*reducer_orig_var)(void *, void *));
}
extern "C"
{
  extern ::nanos_err_t nanos_task_reduction_get_thread_storage_(void *orig, void **tpd);
}
extern "C"
{
  extern ::nanos_err_t nanos_task_reduction_get_thread_storage(void *orig, void **tpd);
}
extern "C"
{
  extern ::nanos_err_t nanos_admit_current_thread_();
}
extern "C"
{
  extern ::nanos_err_t nanos_admit_current_thread();
}
extern "C"
{
  extern ::nanos_err_t nanos_expel_current_thread_();
}
extern "C"
{
  extern ::nanos_err_t nanos_expel_current_thread();
}
extern "C"
{
  extern ::nanos_err_t nanos_dependence_release_all_();
}
extern "C"
{
  extern ::nanos_err_t nanos_dependence_release_all();
}
extern "C"
{
  extern ::nanos_err_t nanos_dependence_pendant_writes_(bool *res, void *addr);
}
extern "C"
{
  extern ::nanos_err_t nanos_dependence_pendant_writes(bool *res, void *addr);
}
extern "C"
{
  extern ::nanos_err_t nanos_dependence_create_(::nanos_wd_t pred, ::nanos_wd_t succ);
}
extern "C"
{
  extern ::nanos_err_t nanos_dependence_create(::nanos_wd_t pred, ::nanos_wd_t succ);
}
extern "C"
{
  extern ::nanos_err_t nanos_worksharing_create_(::nanos_ws_desc_t **wsd, ::nanos_ws_t ws, ::nanos_ws_info_t *info, bool *b);
}
extern "C"
{
  extern ::nanos_err_t nanos_worksharing_create(::nanos_ws_desc_t **wsd, ::nanos_ws_t ws, ::nanos_ws_info_t *info, bool *b);
}
extern "C"
{
  extern ::nanos_err_t nanos_worksharing_next_item_(::nanos_ws_desc_t *wsd, ::nanos_ws_item_t *wsi);
}
extern "C"
{
  extern ::nanos_err_t nanos_worksharing_next_item(::nanos_ws_desc_t *wsd, ::nanos_ws_item_t *wsi);
}
extern "C"
{
  extern ::nanos_err_t nanos_wg_wait_completion_mandatory_(::nanos_wg_t wg, bool avoid_flush);
}
extern "C"
{
  extern ::nanos_err_t nanos_wg_wait_completion_mandatory(::nanos_wg_t wg, bool avoid_flush);
}
extern "C"
{
  extern ::nanos_err_t nanos_wg_wait_completion_(::nanos_wg_t wg, bool avoid_flush);
}
extern "C"
{
  extern ::nanos_err_t nanos_wg_wait_completion(::nanos_wg_t wg, bool avoid_flush);
}
extern "C"
{
  extern ::nanos_err_t nanos_create_int_sync_cond_(::nanos_sync_cond_t *sync_cond, volatile int *p, int condition);
}
extern "C"
{
  extern ::nanos_err_t nanos_create_int_sync_cond(::nanos_sync_cond_t *sync_cond, volatile int *p, int condition);
}
extern "C"
{
  extern ::nanos_err_t nanos_create_bool_sync_cond_(::nanos_sync_cond_t *sync_cond, volatile bool *p, bool condition);
}
extern "C"
{
  extern ::nanos_err_t nanos_create_bool_sync_cond(::nanos_sync_cond_t *sync_cond, volatile bool *p, bool condition);
}
extern "C"
{
  extern ::nanos_err_t nanos_sync_cond_wait_(::nanos_sync_cond_t sync_cond);
}
extern "C"
{
  extern ::nanos_err_t nanos_sync_cond_wait(::nanos_sync_cond_t sync_cond);
}
extern "C"
{
  extern ::nanos_err_t nanos_sync_cond_signal_(::nanos_sync_cond_t sync_cond);
}
extern "C"
{
  extern ::nanos_err_t nanos_sync_cond_signal(::nanos_sync_cond_t sync_cond);
}
extern "C"
{
  extern ::nanos_err_t nanos_destroy_sync_cond_(::nanos_sync_cond_t sync_cond);
}
extern "C"
{
  extern ::nanos_err_t nanos_destroy_sync_cond(::nanos_sync_cond_t sync_cond);
}
extern "C"
{
  extern ::nanos_err_t nanos_wait_on_(::size_t num_data_accesses, ::nanos_data_access_t *data_accesses);
}
extern "C"
{
  extern ::nanos_err_t nanos_wait_on(::size_t num_data_accesses, ::nanos_data_access_t *data_accesses);
}
extern "C"
{
  extern ::nanos_err_t nanos_init_lock_(::nanos_lock_t **lock);
}
extern "C"
{
  extern ::nanos_err_t nanos_init_lock(::nanos_lock_t **lock);
}
extern "C"
{
  extern ::nanos_err_t nanos_init_lock_at_(::nanos_lock_t *lock);
}
extern "C"
{
  extern ::nanos_err_t nanos_init_lock_at(::nanos_lock_t *lock);
}
extern "C"
{
  extern ::nanos_err_t nanos_set_lock_(::nanos_lock_t *lock);
}
extern "C"
{
  extern ::nanos_err_t nanos_set_lock(::nanos_lock_t *lock);
}
extern "C"
{
  extern ::nanos_err_t nanos_unset_lock_(::nanos_lock_t *lock);
}
extern "C"
{
  extern ::nanos_err_t nanos_unset_lock(::nanos_lock_t *lock);
}
extern "C"
{
  extern ::nanos_err_t nanos_try_lock_(::nanos_lock_t *lock, bool *result);
}
extern "C"
{
  extern ::nanos_err_t nanos_try_lock(::nanos_lock_t *lock, bool *result);
}
extern "C"
{
  extern ::nanos_err_t nanos_destroy_lock_(::nanos_lock_t *lock);
}
extern "C"
{
  extern ::nanos_err_t nanos_destroy_lock(::nanos_lock_t *lock);
}
extern "C"
{
  extern ::nanos_err_t nanos_get_lock_address_(void *addr, ::nanos_lock_t **lock);
}
extern "C"
{
  extern ::nanos_err_t nanos_get_lock_address(void *addr, ::nanos_lock_t **lock);
}
extern "C"
{
  extern ::nanos_err_t nanos_set_copies_(::nanos_wd_t wd, int num_copies, ::nanos_copy_data_t *copies);
}
extern "C"
{
  extern ::nanos_err_t nanos_set_copies(::nanos_wd_t wd, int num_copies, ::nanos_copy_data_t *copies);
}
extern "C"
{
  extern ::nanos_err_t nanos_get_addr_(::nanos_copy_id_t copy_id, void **addr, ::nanos_wd_t cwd);
}
extern "C"
{
  extern ::nanos_err_t nanos_get_addr(::nanos_copy_id_t copy_id, void **addr, ::nanos_wd_t cwd);
}
extern "C"
{
  extern ::nanos_err_t nanos_copy_value_(void *dst, ::nanos_copy_id_t copy_id, ::nanos_wd_t cwd);
}
extern "C"
{
  extern ::nanos_err_t nanos_copy_value(void *dst, ::nanos_copy_id_t copy_id, ::nanos_wd_t cwd);
}
extern "C"
{
  extern const char *nanos_get_runtime_version_();
}
extern "C"
{
  extern const char *nanos_get_runtime_version();
}
extern "C"
{
  extern const char *nanos_get_default_architecture_();
}
extern "C"
{
  extern const char *nanos_get_default_architecture();
}
extern "C"
{
  extern const char *nanos_get_pm_();
}
extern "C"
{
  extern const char *nanos_get_pm();
}
extern "C"
{
  extern ::nanos_err_t nanos_get_default_binding_(bool *res);
}
extern "C"
{
  extern ::nanos_err_t nanos_get_default_binding(bool *res);
}
extern "C"
{
  extern ::nanos_err_t nanos_get_binding_(::nanos_cpu_set_t *);
}
extern "C"
{
  extern ::nanos_err_t nanos_get_binding(::nanos_cpu_set_t *);
}
extern "C"
{
  extern ::nanos_err_t nanos_delay_start_();
}
extern "C"
{
  extern ::nanos_err_t nanos_delay_start();
}
extern "C"
{
  extern ::nanos_err_t nanos_start_();
}
extern "C"
{
  extern ::nanos_err_t nanos_start();
}
extern "C"
{
  extern ::nanos_err_t nanos_finish_();
}
extern "C"
{
  extern ::nanos_err_t nanos_finish();
}
extern "C"
{
  extern ::nanos_err_t nanos_current_socket_(int socket);
}
extern "C"
{
  extern ::nanos_err_t nanos_current_socket(int socket);
}
extern "C"
{
  extern ::nanos_err_t nanos_get_num_sockets_(int *num_sockets);
}
extern "C"
{
  extern ::nanos_err_t nanos_get_num_sockets(int *num_sockets);
}
extern "C"
{
  extern ::nanos_err_t nanos_malloc_(void **p, ::size_t size, const char *file, int line);
}
extern "C"
{
  extern ::nanos_err_t nanos_malloc(void **p, ::size_t size, const char *file, int line);
}
extern "C"
{
  extern ::nanos_err_t nanos_memalign_(void **p, ::size_t size, const char *file, int line);
}
extern "C"
{
  extern ::nanos_err_t nanos_memalign(void **p, ::size_t size, const char *file, int line);
}
extern "C"
{
  extern ::nanos_err_t nanos_cmalloc_(void **p, ::size_t size, unsigned int node, const char *file, int line);
}
extern "C"
{
  extern ::nanos_err_t nanos_cmalloc(void **p, ::size_t size, unsigned int node, const char *file, int line);
}
extern "C"
{
  extern ::nanos_err_t nanos_cmalloc_2dim_distributed_(void **p, ::size_t rows, ::size_t cols, ::size_t elem_size, unsigned int start_node, ::size_t num_nodes, const char *file, int line);
}
extern "C"
{
  extern ::nanos_err_t nanos_cmalloc_2dim_distributed(void **p, ::size_t rows, ::size_t cols, ::size_t elem_size, unsigned int start_node, ::size_t num_nodes, const char *file, int line);
}
extern "C"
{
  extern ::nanos_err_t nanos_stick_to_producer_(void *p, ::size_t size);
}
extern "C"
{
  extern ::nanos_err_t nanos_stick_to_producer(void *p, ::size_t size);
}
extern "C"
{
  extern ::nanos_err_t nanos_free_(void *p);
}
extern "C"
{
  extern ::nanos_err_t nanos_free(void *p);
}
extern "C"
{
  extern void nanos_free0_(void *p);
}
extern "C"
{
  extern void nanos_free0(void *p);
}
extern "C"
{
  extern void nanos_handle_error_(::nanos_err_t err);
}
extern "C"
{
  extern void nanos_handle_error(::nanos_err_t err);
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_register_key_(::nanos_event_key_t *event_key, const char *key, const char *description, bool abort_when_registered);
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_register_key(::nanos_event_key_t *event_key, const char *key, const char *description, bool abort_when_registered);
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_register_value_(::nanos_event_value_t *event_value, const char *key, const char *value, const char *description, bool abort_when_registered);
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_register_value(::nanos_event_value_t *event_value, const char *key, const char *value, const char *description, bool abort_when_registered);
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_register_value_with_val_(::nanos_event_value_t val, const char *key, const char *value, const char *description, bool abort_when_registered);
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_register_value_with_val(::nanos_event_value_t val, const char *key, const char *value, const char *description, bool abort_when_registered);
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_get_key_(const char *key, ::nanos_event_key_t *event_key);
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_get_key(const char *key, ::nanos_event_key_t *event_key);
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_get_value_(const char *key, const char *value, ::nanos_event_value_t *event_value);
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_get_value(const char *key, const char *value, ::nanos_event_value_t *event_value);
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_events_(unsigned int num_events, ::nanos_event_t events[]);
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_events(unsigned int num_events, ::nanos_event_t events[]);
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_close_user_fun_event_();
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_close_user_fun_event();
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_raise_gpu_kernel_launch_event_();
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_raise_gpu_kernel_launch_event();
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_close_gpu_kernel_launch_event_();
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_close_gpu_kernel_launch_event();
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_enable_();
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_enable();
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_disable_();
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_disable();
}
extern "C"
{
  extern ::nanos_err_t nanos_get_node_num_(unsigned int *num);
}
extern "C"
{
  extern ::nanos_err_t nanos_get_node_num(unsigned int *num);
}
extern "C"
{
  extern int nanos_get_num_nodes_();
}
extern "C"
{
  extern int nanos_get_num_nodes();
}
extern "C"
{
  extern ::nanos_err_t nanos_set_create_local_tasks_(bool value);
}
extern "C"
{
  extern ::nanos_err_t nanos_set_create_local_tasks(bool value);
}
typedef const char *nanos_string_t;
extern "C"
{
  extern ::nanos_err_t nanos_instrument_begin_burst_(::nanos_string_t key, ::nanos_string_t key_descr, ::nanos_string_t value, ::nanos_string_t value_descr);
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_begin_burst(::nanos_string_t key, ::nanos_string_t key_descr, ::nanos_string_t value, ::nanos_string_t value_descr);
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_end_burst_(::nanos_string_t key, ::nanos_string_t value);
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_end_burst(::nanos_string_t key, ::nanos_string_t value);
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_begin_burst_with_val_(::nanos_string_t key, ::nanos_string_t key_descr, ::nanos_event_value_t *val);
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_begin_burst_with_val(::nanos_string_t key, ::nanos_string_t key_descr, ::nanos_event_value_t *val);
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_end_burst_with_val_(::nanos_string_t key, ::nanos_event_value_t *val);
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_end_burst_with_val(::nanos_string_t key, ::nanos_event_value_t *val);
}
extern "C"
{
  extern ::nanos_err_t nanos_memcpy_(void *dest, const void *src, ::size_t n);
}
extern "C"
{
  extern ::nanos_err_t nanos_memcpy(void *dest, const void *src, ::size_t n);
}
extern "C"
{
  extern ::nanos_err_t nanos_register_object_(int num_objects, ::nanos_copy_data_t *obj);
}
extern "C"
{
  extern ::nanos_err_t nanos_register_object(int num_objects, ::nanos_copy_data_t *obj);
}
extern "C"
{
  extern ::nanos_err_t nanos_unregister_object_(int num_objects, void *base_addresses);
}
extern "C"
{
  extern ::nanos_err_t nanos_unregister_object(int num_objects, void *base_addresses);
}
extern "C"
{
  extern const char *nanos_get_default_scheduler_();
}
extern "C"
{
  extern const char *nanos_get_default_scheduler();
}
extern "C"
{
  extern ::nanos_err_t nanos_start_scheduler_();
}
extern "C"
{
  extern ::nanos_err_t nanos_start_scheduler();
}
extern "C"
{
  extern ::nanos_err_t nanos_stop_scheduler_();
}
extern "C"
{
  extern ::nanos_err_t nanos_stop_scheduler();
}
extern "C"
{
  extern ::nanos_err_t nanos_scheduler_enabled_(bool *res);
}
extern "C"
{
  extern ::nanos_err_t nanos_scheduler_enabled(bool *res);
}
extern "C"
{
  extern ::nanos_err_t nanos_wait_until_threads_paused_();
}
extern "C"
{
  extern ::nanos_err_t nanos_wait_until_threads_paused();
}
extern "C"
{
  extern ::nanos_err_t nanos_wait_until_threads_unpaused_();
}
extern "C"
{
  extern ::nanos_err_t nanos_wait_until_threads_unpaused();
}
extern "C"
{
  extern ::nanos_err_t nanos_scheduler_get_stealing_(bool *res);
}
extern "C"
{
  extern ::nanos_err_t nanos_scheduler_get_stealing(bool *res);
}
extern "C"
{
  extern ::nanos_err_t nanos_scheduler_set_stealing_(bool value);
}
extern "C"
{
  extern ::nanos_err_t nanos_scheduler_set_stealing(bool value);
}
extern "C"
{
  extern void ompss_nanox_main_begin_(void *addr, const char *filename, int line);
}
extern "C"
{
  extern void ompss_nanox_main_begin(void *addr, const char *filename, int line);
}
extern "C"
{
  extern void ompss_nanox_main_end_();
}
extern "C"
{
  extern void ompss_nanox_main_end();
}
extern "C"
{
  extern void ompss_nanox_main_();
}
extern "C"
{
  extern void ompss_nanox_main();
}
extern "C"
{
  extern void nanos_atexit_(void *);
}
extern "C"
{
  extern void nanos_atexit(void *);
}
extern "C"
{
  void nanos_reduction_int_vop(int, void *, void *);
}
extern "C"
{
  extern int nanos_cmpi_init_(int *argc, char **argv[]);
}
extern "C"
{
  extern int nanos_cmpi_init(int *argc, char **argv[]);
}
extern "C"
{
  extern void nanos_cmpi_finalize_();
}
extern "C"
{
  extern void nanos_cmpi_finalize();
}
extern "C"
{
  extern void nanos_into_blocking_mpi_call_();
}
extern "C"
{
  extern void nanos_into_blocking_mpi_call();
}
extern "C"
{
  extern void nanos_out_of_blocking_mpi_call_();
}
extern "C"
{
  extern void nanos_out_of_blocking_mpi_call();
}
extern "C"
{
  extern void nanos_thread_print_(char *str);
}
extern "C"
{
  extern void nanos_thread_print(char *str);
}
extern "C"
{
  extern void nanos_set_watch_addr_(void *addr);
}
extern "C"
{
  extern void nanos_set_watch_addr(void *addr);
}
extern "C"
{
  extern void nanos_print_bt_();
}
extern "C"
{
  extern void nanos_print_bt();
}
extern "C"
{
  extern void nanos_enable_verbose_copies_();
}
extern "C"
{
  extern void nanos_enable_verbose_copies();
}
extern "C"
{
  extern void nanos_disable_verbose_copies_();
}
extern "C"
{
  extern void nanos_disable_verbose_copies();
}
extern "C"
{
  extern void nanos_atomic_assig_schar_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_assig_schar(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_assig_short_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_assig_short(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_assig_int_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_assig_int(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_assig_long_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_assig_long(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_assig_longlong_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_assig_longlong(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_assig_uchar_(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_assig_uchar(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_assig_ushort_(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_assig_ushort(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_assig_uint_(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_assig_uint(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_assig_ulong_(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_assig_ulong(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_assig_ulonglong_(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_assig_ulonglong(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_assig_bytebool_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_assig_bytebool(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_assig_shortbool_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_assig_shortbool(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_assig_intbool_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_assig_intbool(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_assig_longbool_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_assig_longbool(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_assig_longlongbool_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_assig_longlongbool(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_assig_float_(volatile float *, float);
}
extern "C"
{
  extern void nanos_atomic_assig_float(volatile float *, float);
}
extern "C"
{
  extern void nanos_atomic_assig_double_(volatile double *, double);
}
extern "C"
{
  extern void nanos_atomic_assig_double(volatile double *, double);
}
extern "C"
{
  extern void nanos_atomic_assig_ldouble_(volatile long double *, long double);
}
extern "C"
{
  extern void nanos_atomic_assig_ldouble(volatile long double *, long double);
}
extern "C"
{
  extern void nanos_atomic_assig_cfloat_(volatile _Complex float *, _Complex float);
}
extern "C"
{
  extern void nanos_atomic_assig_cfloat(volatile _Complex float *, _Complex float);
}
extern "C"
{
  extern void nanos_atomic_assig_cdouble_(volatile _Complex double *, _Complex double);
}
extern "C"
{
  extern void nanos_atomic_assig_cdouble(volatile _Complex double *, _Complex double);
}
extern "C"
{
  extern void nanos_atomic_assig_cldouble_(volatile _Complex long double *, _Complex long double);
}
extern "C"
{
  extern void nanos_atomic_assig_cldouble(volatile _Complex long double *, _Complex long double);
}
extern "C"
{
  extern void nanos_atomic_add_schar_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_add_schar(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_add_short_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_add_short(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_add_int_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_add_int(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_add_long_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_add_long(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_add_longlong_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_add_longlong(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_add_uchar_(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_add_uchar(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_add_ushort_(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_add_ushort(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_add_uint_(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_add_uint(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_add_ulong_(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_add_ulong(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_add_ulonglong_(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_add_ulonglong(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_add_bytebool_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_add_bytebool(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_add_shortbool_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_add_shortbool(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_add_intbool_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_add_intbool(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_add_longbool_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_add_longbool(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_add_longlongbool_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_add_longlongbool(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_add_float_(volatile float *, float);
}
extern "C"
{
  extern void nanos_atomic_add_float(volatile float *, float);
}
extern "C"
{
  extern void nanos_atomic_add_double_(volatile double *, double);
}
extern "C"
{
  extern void nanos_atomic_add_double(volatile double *, double);
}
extern "C"
{
  extern void nanos_atomic_add_ldouble_(volatile long double *, long double);
}
extern "C"
{
  extern void nanos_atomic_add_ldouble(volatile long double *, long double);
}
extern "C"
{
  extern void nanos_atomic_add_cfloat_(volatile _Complex float *, _Complex float);
}
extern "C"
{
  extern void nanos_atomic_add_cfloat(volatile _Complex float *, _Complex float);
}
extern "C"
{
  extern void nanos_atomic_add_cdouble_(volatile _Complex double *, _Complex double);
}
extern "C"
{
  extern void nanos_atomic_add_cdouble(volatile _Complex double *, _Complex double);
}
extern "C"
{
  extern void nanos_atomic_add_cldouble_(volatile _Complex long double *, _Complex long double);
}
extern "C"
{
  extern void nanos_atomic_add_cldouble(volatile _Complex long double *, _Complex long double);
}
extern "C"
{
  extern void nanos_atomic_sub_schar_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_sub_schar(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_sub_short_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_sub_short(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_sub_int_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_sub_int(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_sub_long_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_sub_long(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_sub_longlong_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_sub_longlong(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_sub_uchar_(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_sub_uchar(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_sub_ushort_(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_sub_ushort(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_sub_uint_(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_sub_uint(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_sub_ulong_(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_sub_ulong(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_sub_ulonglong_(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_sub_ulonglong(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_sub_bytebool_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_sub_bytebool(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_sub_shortbool_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_sub_shortbool(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_sub_intbool_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_sub_intbool(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_sub_longbool_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_sub_longbool(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_sub_longlongbool_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_sub_longlongbool(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_sub_float_(volatile float *, float);
}
extern "C"
{
  extern void nanos_atomic_sub_float(volatile float *, float);
}
extern "C"
{
  extern void nanos_atomic_sub_double_(volatile double *, double);
}
extern "C"
{
  extern void nanos_atomic_sub_double(volatile double *, double);
}
extern "C"
{
  extern void nanos_atomic_sub_ldouble_(volatile long double *, long double);
}
extern "C"
{
  extern void nanos_atomic_sub_ldouble(volatile long double *, long double);
}
extern "C"
{
  extern void nanos_atomic_sub_cfloat_(volatile _Complex float *, _Complex float);
}
extern "C"
{
  extern void nanos_atomic_sub_cfloat(volatile _Complex float *, _Complex float);
}
extern "C"
{
  extern void nanos_atomic_sub_cdouble_(volatile _Complex double *, _Complex double);
}
extern "C"
{
  extern void nanos_atomic_sub_cdouble(volatile _Complex double *, _Complex double);
}
extern "C"
{
  extern void nanos_atomic_sub_cldouble_(volatile _Complex long double *, _Complex long double);
}
extern "C"
{
  extern void nanos_atomic_sub_cldouble(volatile _Complex long double *, _Complex long double);
}
extern "C"
{
  extern void nanos_atomic_mul_schar_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_mul_schar(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_mul_short_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_mul_short(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_mul_int_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_mul_int(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_mul_long_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_mul_long(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_mul_longlong_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_mul_longlong(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_mul_uchar_(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_mul_uchar(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_mul_ushort_(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_mul_ushort(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_mul_uint_(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_mul_uint(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_mul_ulong_(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_mul_ulong(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_mul_ulonglong_(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_mul_ulonglong(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_mul_bytebool_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_mul_bytebool(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_mul_shortbool_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_mul_shortbool(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_mul_intbool_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_mul_intbool(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_mul_longbool_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_mul_longbool(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_mul_longlongbool_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_mul_longlongbool(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_mul_float_(volatile float *, float);
}
extern "C"
{
  extern void nanos_atomic_mul_float(volatile float *, float);
}
extern "C"
{
  extern void nanos_atomic_mul_double_(volatile double *, double);
}
extern "C"
{
  extern void nanos_atomic_mul_double(volatile double *, double);
}
extern "C"
{
  extern void nanos_atomic_mul_ldouble_(volatile long double *, long double);
}
extern "C"
{
  extern void nanos_atomic_mul_ldouble(volatile long double *, long double);
}
extern "C"
{
  extern void nanos_atomic_mul_cfloat_(volatile _Complex float *, _Complex float);
}
extern "C"
{
  extern void nanos_atomic_mul_cfloat(volatile _Complex float *, _Complex float);
}
extern "C"
{
  extern void nanos_atomic_mul_cdouble_(volatile _Complex double *, _Complex double);
}
extern "C"
{
  extern void nanos_atomic_mul_cdouble(volatile _Complex double *, _Complex double);
}
extern "C"
{
  extern void nanos_atomic_mul_cldouble_(volatile _Complex long double *, _Complex long double);
}
extern "C"
{
  extern void nanos_atomic_mul_cldouble(volatile _Complex long double *, _Complex long double);
}
extern "C"
{
  extern void nanos_atomic_div_schar_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_div_schar(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_div_short_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_div_short(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_div_int_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_div_int(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_div_long_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_div_long(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_div_longlong_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_div_longlong(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_div_uchar_(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_div_uchar(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_div_ushort_(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_div_ushort(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_div_uint_(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_div_uint(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_div_ulong_(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_div_ulong(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_div_ulonglong_(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_div_ulonglong(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_div_bytebool_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_div_bytebool(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_div_shortbool_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_div_shortbool(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_div_intbool_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_div_intbool(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_div_longbool_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_div_longbool(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_div_longlongbool_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_div_longlongbool(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_div_float_(volatile float *, float);
}
extern "C"
{
  extern void nanos_atomic_div_float(volatile float *, float);
}
extern "C"
{
  extern void nanos_atomic_div_double_(volatile double *, double);
}
extern "C"
{
  extern void nanos_atomic_div_double(volatile double *, double);
}
extern "C"
{
  extern void nanos_atomic_div_ldouble_(volatile long double *, long double);
}
extern "C"
{
  extern void nanos_atomic_div_ldouble(volatile long double *, long double);
}
extern "C"
{
  extern void nanos_atomic_div_cfloat_(volatile _Complex float *, _Complex float);
}
extern "C"
{
  extern void nanos_atomic_div_cfloat(volatile _Complex float *, _Complex float);
}
extern "C"
{
  extern void nanos_atomic_div_cdouble_(volatile _Complex double *, _Complex double);
}
extern "C"
{
  extern void nanos_atomic_div_cdouble(volatile _Complex double *, _Complex double);
}
extern "C"
{
  extern void nanos_atomic_div_cldouble_(volatile _Complex long double *, _Complex long double);
}
extern "C"
{
  extern void nanos_atomic_div_cldouble(volatile _Complex long double *, _Complex long double);
}
extern "C"
{
  extern void nanos_atomic_pow_schar_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_pow_schar(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_pow_short_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_pow_short(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_pow_int_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_pow_int(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_pow_long_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_pow_long(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_pow_longlong_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_pow_longlong(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_pow_uchar_(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_pow_uchar(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_pow_ushort_(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_pow_ushort(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_pow_uint_(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_pow_uint(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_pow_ulong_(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_pow_ulong(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_pow_ulonglong_(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_pow_ulonglong(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_pow_bytebool_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_pow_bytebool(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_pow_shortbool_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_pow_shortbool(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_pow_intbool_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_pow_intbool(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_pow_longbool_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_pow_longbool(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_pow_longlongbool_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_pow_longlongbool(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_pow_float_(volatile float *, float);
}
extern "C"
{
  extern void nanos_atomic_pow_float(volatile float *, float);
}
extern "C"
{
  extern void nanos_atomic_pow_double_(volatile double *, double);
}
extern "C"
{
  extern void nanos_atomic_pow_double(volatile double *, double);
}
extern "C"
{
  extern void nanos_atomic_pow_ldouble_(volatile long double *, long double);
}
extern "C"
{
  extern void nanos_atomic_pow_ldouble(volatile long double *, long double);
}
extern "C"
{
  extern void nanos_atomic_pow_cfloat_(volatile _Complex float *, _Complex float);
}
extern "C"
{
  extern void nanos_atomic_pow_cfloat(volatile _Complex float *, _Complex float);
}
extern "C"
{
  extern void nanos_atomic_pow_cdouble_(volatile _Complex double *, _Complex double);
}
extern "C"
{
  extern void nanos_atomic_pow_cdouble(volatile _Complex double *, _Complex double);
}
extern "C"
{
  extern void nanos_atomic_pow_cldouble_(volatile _Complex long double *, _Complex long double);
}
extern "C"
{
  extern void nanos_atomic_pow_cldouble(volatile _Complex long double *, _Complex long double);
}
extern "C"
{
  extern void nanos_atomic_max_schar_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_max_schar(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_max_short_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_max_short(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_max_int_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_max_int(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_max_long_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_max_long(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_max_longlong_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_max_longlong(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_max_uchar_(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_max_uchar(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_max_ushort_(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_max_ushort(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_max_uint_(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_max_uint(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_max_ulong_(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_max_ulong(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_max_ulonglong_(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_max_ulonglong(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_max_bytebool_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_max_bytebool(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_max_shortbool_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_max_shortbool(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_max_intbool_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_max_intbool(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_max_longbool_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_max_longbool(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_max_longlongbool_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_max_longlongbool(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_min_schar_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_min_schar(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_min_short_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_min_short(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_min_int_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_min_int(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_min_long_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_min_long(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_min_longlong_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_min_longlong(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_min_uchar_(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_min_uchar(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_min_ushort_(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_min_ushort(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_min_uint_(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_min_uint(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_min_ulong_(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_min_ulong(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_min_ulonglong_(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_min_ulonglong(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_min_bytebool_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_min_bytebool(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_min_shortbool_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_min_shortbool(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_min_intbool_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_min_intbool(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_min_longbool_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_min_longbool(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_min_longlongbool_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_min_longlongbool(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_max_float_(volatile float *, float);
}
extern "C"
{
  extern void nanos_atomic_max_float(volatile float *, float);
}
extern "C"
{
  extern void nanos_atomic_max_double_(volatile double *, double);
}
extern "C"
{
  extern void nanos_atomic_max_double(volatile double *, double);
}
extern "C"
{
  extern void nanos_atomic_max_ldouble_(volatile long double *, long double);
}
extern "C"
{
  extern void nanos_atomic_max_ldouble(volatile long double *, long double);
}
extern "C"
{
  extern void nanos_atomic_min_float_(volatile float *, float);
}
extern "C"
{
  extern void nanos_atomic_min_float(volatile float *, float);
}
extern "C"
{
  extern void nanos_atomic_min_double_(volatile double *, double);
}
extern "C"
{
  extern void nanos_atomic_min_double(volatile double *, double);
}
extern "C"
{
  extern void nanos_atomic_min_ldouble_(volatile long double *, long double);
}
extern "C"
{
  extern void nanos_atomic_min_ldouble(volatile long double *, long double);
}
extern "C"
{
  extern void nanos_atomic_eq_schar_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_eq_schar(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_eq_short_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_eq_short(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_eq_int_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_eq_int(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_eq_long_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_eq_long(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_eq_longlong_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_eq_longlong(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_eq_uchar_(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_eq_uchar(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_eq_ushort_(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_eq_ushort(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_eq_uint_(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_eq_uint(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_eq_ulong_(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_eq_ulong(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_eq_ulonglong_(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_eq_ulonglong(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_eq_bytebool_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_eq_bytebool(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_eq_shortbool_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_eq_shortbool(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_eq_intbool_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_eq_intbool(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_eq_longbool_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_eq_longbool(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_eq_longlongbool_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_eq_longlongbool(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_eq_float_(volatile float *, float);
}
extern "C"
{
  extern void nanos_atomic_eq_float(volatile float *, float);
}
extern "C"
{
  extern void nanos_atomic_eq_double_(volatile double *, double);
}
extern "C"
{
  extern void nanos_atomic_eq_double(volatile double *, double);
}
extern "C"
{
  extern void nanos_atomic_eq_ldouble_(volatile long double *, long double);
}
extern "C"
{
  extern void nanos_atomic_eq_ldouble(volatile long double *, long double);
}
extern "C"
{
  extern void nanos_atomic_eq_cfloat_(volatile _Complex float *, _Complex float);
}
extern "C"
{
  extern void nanos_atomic_eq_cfloat(volatile _Complex float *, _Complex float);
}
extern "C"
{
  extern void nanos_atomic_eq_cdouble_(volatile _Complex double *, _Complex double);
}
extern "C"
{
  extern void nanos_atomic_eq_cdouble(volatile _Complex double *, _Complex double);
}
extern "C"
{
  extern void nanos_atomic_eq_cldouble_(volatile _Complex long double *, _Complex long double);
}
extern "C"
{
  extern void nanos_atomic_eq_cldouble(volatile _Complex long double *, _Complex long double);
}
extern "C"
{
  extern void nanos_atomic_neq_schar_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_neq_schar(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_neq_short_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_neq_short(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_neq_int_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_neq_int(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_neq_long_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_neq_long(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_neq_longlong_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_neq_longlong(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_neq_uchar_(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_neq_uchar(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_neq_ushort_(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_neq_ushort(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_neq_uint_(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_neq_uint(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_neq_ulong_(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_neq_ulong(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_neq_ulonglong_(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_neq_ulonglong(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_neq_bytebool_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_neq_bytebool(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_neq_shortbool_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_neq_shortbool(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_neq_intbool_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_neq_intbool(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_neq_longbool_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_neq_longbool(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_neq_longlongbool_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_neq_longlongbool(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_neq_float_(volatile float *, float);
}
extern "C"
{
  extern void nanos_atomic_neq_float(volatile float *, float);
}
extern "C"
{
  extern void nanos_atomic_neq_double_(volatile double *, double);
}
extern "C"
{
  extern void nanos_atomic_neq_double(volatile double *, double);
}
extern "C"
{
  extern void nanos_atomic_neq_ldouble_(volatile long double *, long double);
}
extern "C"
{
  extern void nanos_atomic_neq_ldouble(volatile long double *, long double);
}
extern "C"
{
  extern void nanos_atomic_neq_cfloat_(volatile _Complex float *, _Complex float);
}
extern "C"
{
  extern void nanos_atomic_neq_cfloat(volatile _Complex float *, _Complex float);
}
extern "C"
{
  extern void nanos_atomic_neq_cdouble_(volatile _Complex double *, _Complex double);
}
extern "C"
{
  extern void nanos_atomic_neq_cdouble(volatile _Complex double *, _Complex double);
}
extern "C"
{
  extern void nanos_atomic_neq_cldouble_(volatile _Complex long double *, _Complex long double);
}
extern "C"
{
  extern void nanos_atomic_neq_cldouble(volatile _Complex long double *, _Complex long double);
}
extern "C"
{
  extern void nanos_atomic_mod_schar_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_mod_schar(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_mod_short_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_mod_short(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_mod_int_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_mod_int(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_mod_long_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_mod_long(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_mod_longlong_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_mod_longlong(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_mod_uchar_(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_mod_uchar(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_mod_ushort_(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_mod_ushort(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_mod_uint_(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_mod_uint(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_mod_ulong_(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_mod_ulong(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_mod_ulonglong_(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_mod_ulonglong(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_mod_bytebool_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_mod_bytebool(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_mod_shortbool_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_mod_shortbool(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_mod_intbool_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_mod_intbool(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_mod_longbool_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_mod_longbool(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_mod_longlongbool_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_mod_longlongbool(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_shl_schar_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_shl_schar(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_shl_short_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_shl_short(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_shl_int_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_shl_int(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_shl_long_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_shl_long(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_shl_longlong_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_shl_longlong(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_shl_uchar_(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_shl_uchar(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_shl_ushort_(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_shl_ushort(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_shl_uint_(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_shl_uint(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_shl_ulong_(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_shl_ulong(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_shl_ulonglong_(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_shl_ulonglong(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_shl_bytebool_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_shl_bytebool(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_shl_shortbool_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_shl_shortbool(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_shl_intbool_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_shl_intbool(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_shl_longbool_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_shl_longbool(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_shl_longlongbool_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_shl_longlongbool(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_shr_schar_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_shr_schar(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_shr_short_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_shr_short(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_shr_int_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_shr_int(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_shr_long_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_shr_long(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_shr_longlong_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_shr_longlong(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_shr_uchar_(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_shr_uchar(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_shr_ushort_(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_shr_ushort(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_shr_uint_(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_shr_uint(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_shr_ulong_(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_shr_ulong(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_shr_ulonglong_(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_shr_ulonglong(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_shr_bytebool_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_shr_bytebool(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_shr_shortbool_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_shr_shortbool(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_shr_intbool_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_shr_intbool(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_shr_longbool_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_shr_longbool(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_shr_longlongbool_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_shr_longlongbool(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_land_schar_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_land_schar(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_land_short_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_land_short(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_land_int_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_land_int(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_land_long_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_land_long(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_land_longlong_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_land_longlong(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_land_uchar_(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_land_uchar(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_land_ushort_(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_land_ushort(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_land_uint_(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_land_uint(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_land_ulong_(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_land_ulong(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_land_ulonglong_(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_land_ulonglong(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_land_bytebool_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_land_bytebool(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_land_shortbool_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_land_shortbool(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_land_intbool_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_land_intbool(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_land_longbool_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_land_longbool(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_land_longlongbool_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_land_longlongbool(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_lor_schar_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_lor_schar(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_lor_short_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_lor_short(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_lor_int_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_lor_int(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_lor_long_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_lor_long(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_lor_longlong_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_lor_longlong(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_lor_uchar_(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_lor_uchar(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_lor_ushort_(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_lor_ushort(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_lor_uint_(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_lor_uint(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_lor_ulong_(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_lor_ulong(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_lor_ulonglong_(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_lor_ulonglong(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_lor_bytebool_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_lor_bytebool(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_lor_shortbool_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_lor_shortbool(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_lor_intbool_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_lor_intbool(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_lor_longbool_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_lor_longbool(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_lor_longlongbool_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_lor_longlongbool(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_band_schar_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_band_schar(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_band_short_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_band_short(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_band_int_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_band_int(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_band_long_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_band_long(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_band_longlong_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_band_longlong(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_band_uchar_(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_band_uchar(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_band_ushort_(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_band_ushort(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_band_uint_(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_band_uint(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_band_ulong_(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_band_ulong(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_band_ulonglong_(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_band_ulonglong(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_band_bytebool_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_band_bytebool(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_band_shortbool_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_band_shortbool(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_band_intbool_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_band_intbool(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_band_longbool_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_band_longbool(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_band_longlongbool_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_band_longlongbool(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_bor_schar_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_bor_schar(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_bor_short_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_bor_short(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_bor_int_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_bor_int(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_bor_long_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_bor_long(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_bor_longlong_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_bor_longlong(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_bor_uchar_(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_bor_uchar(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_bor_ushort_(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_bor_ushort(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_bor_uint_(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_bor_uint(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_bor_ulong_(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_bor_ulong(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_bor_ulonglong_(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_bor_ulonglong(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_bor_bytebool_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_bor_bytebool(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_bor_shortbool_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_bor_shortbool(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_bor_intbool_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_bor_intbool(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_bor_longbool_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_bor_longbool(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_bor_longlongbool_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_bor_longlongbool(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_bxor_schar_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_bxor_schar(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_bxor_short_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_bxor_short(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_bxor_int_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_bxor_int(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_bxor_long_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_bxor_long(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_bxor_longlong_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_bxor_longlong(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_bxor_uchar_(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_bxor_uchar(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_bxor_ushort_(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_bxor_ushort(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_bxor_uint_(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_bxor_uint(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_bxor_ulong_(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_bxor_ulong(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_bxor_ulonglong_(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_bxor_ulonglong(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_bxor_bytebool_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_bxor_bytebool(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_bxor_shortbool_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_bxor_shortbool(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_bxor_intbool_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_bxor_intbool(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_bxor_longbool_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_bxor_longbool(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_bxor_longlongbool_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_bxor_longlongbool(volatile long long int *, long long int);
}
enum nanos_omp_sched_t
{
  nanos_omp_sched_static = 1,
  nanos_omp_sched_dynamic = 2,
  nanos_omp_sched_guided = 3,
  nanos_omp_sched_auto = 4
};
extern "C"
{
  extern ::nanos_err_t nanos_omp_single_(bool *);
}
extern "C"
{
  extern ::nanos_err_t nanos_omp_single(bool *);
}
extern "C"
{
  extern ::nanos_err_t nanos_omp_barrier_();
}
extern "C"
{
  extern ::nanos_err_t nanos_omp_barrier();
}
extern "C"
{
  extern ::nanos_err_t nanos_omp_set_implicit_(::nanos_wd_t uwd);
}
extern "C"
{
  extern ::nanos_err_t nanos_omp_set_implicit(::nanos_wd_t uwd);
}
extern "C"
{
  extern int nanos_omp_get_max_threads_();
}
extern "C"
{
  extern int nanos_omp_get_max_threads();
}
extern "C"
{
  extern int nanos_omp_get_num_threads_();
}
extern "C"
{
  extern int nanos_omp_get_num_threads();
}
extern "C"
{
  extern int nanos_omp_get_thread_num_();
}
extern "C"
{
  extern int nanos_omp_get_thread_num();
}
extern "C"
{
  extern void nanos_omp_set_num_threads_(int nthreads);
}
extern "C"
{
  extern void nanos_omp_set_num_threads(int nthreads);
}
extern "C"
{
  extern ::nanos_ws_t nanos_omp_find_worksharing_(::nanos_omp_sched_t kind);
}
extern "C"
{
  extern ::nanos_ws_t nanos_omp_find_worksharing(::nanos_omp_sched_t kind);
}
extern "C"
{
  extern ::nanos_err_t nanos_omp_get_schedule_(::nanos_omp_sched_t *kind, int *modifier);
}
extern "C"
{
  extern ::nanos_err_t nanos_omp_get_schedule(::nanos_omp_sched_t *kind, int *modifier);
}
extern "C"
{
  extern int nanos_omp_get_num_threads_next_parallel_(int threads_requested);
}
extern "C"
{
  extern int nanos_omp_get_num_threads_next_parallel(int threads_requested);
}
extern "C"
{
  extern void nanos_omp_get_process_mask_(::nanos_cpu_set_t cpu_set);
}
extern "C"
{
  extern void nanos_omp_get_process_mask(::nanos_cpu_set_t cpu_set);
}
extern "C"
{
  extern int nanos_omp_set_process_mask_(::const_nanos_cpu_set_t cpu_set);
}
extern "C"
{
  extern int nanos_omp_set_process_mask(::const_nanos_cpu_set_t cpu_set);
}
extern "C"
{
  extern void nanos_omp_add_process_mask_(::const_nanos_cpu_set_t cpu_set);
}
extern "C"
{
  extern void nanos_omp_add_process_mask(::const_nanos_cpu_set_t cpu_set);
}
extern "C"
{
  extern void nanos_omp_get_active_mask_(::nanos_cpu_set_t cpu_set);
}
extern "C"
{
  extern void nanos_omp_get_active_mask(::nanos_cpu_set_t cpu_set);
}
extern "C"
{
  extern int nanos_omp_set_active_mask_(::const_nanos_cpu_set_t cpu_set);
}
extern "C"
{
  extern int nanos_omp_set_active_mask(::const_nanos_cpu_set_t cpu_set);
}
extern "C"
{
  extern void nanos_omp_add_active_mask_(::const_nanos_cpu_set_t cpu_set);
}
extern "C"
{
  extern void nanos_omp_add_active_mask(::const_nanos_cpu_set_t cpu_set);
}
extern "C"
{
  extern int nanos_omp_enable_cpu_(int cpuid);
}
extern "C"
{
  extern int nanos_omp_enable_cpu(int cpuid);
}
extern "C"
{
  extern int nanos_omp_disable_cpu_(int cpuid);
}
extern "C"
{
  extern int nanos_omp_disable_cpu(int cpuid);
}
extern "C"
{
  extern int nanos_omp_get_max_processors_();
}
extern "C"
{
  extern int nanos_omp_get_max_processors();
}
namespace std __attribute__((__visibility__("default"))) {
  typedef unsigned long int size_t;
  typedef long int ptrdiff_t;
}
#pragma GCC visibility push(default)
#pragma GCC visibility push(default)
namespace std __attribute__((__visibility__("default"))) {
  class  exception
  {
    public:
      inline exception() throw()
      {
      }
      virtual ~exception() throw();
      virtual const char *what() const  throw();
  };
}
#pragma GCC visibility pop
namespace std __attribute__((__visibility__("default"))) {
  class  bad_exception : public ::std::exception
  {
    public:
      inline bad_exception() throw()
      {
      }
      virtual ~bad_exception() throw();
      virtual const char *what() const  throw();
  };
  typedef void (*terminate_handler)();
  typedef void (*unexpected_handler)();
  ::std::terminate_handler set_terminate(::std::terminate_handler) throw();
  void terminate() throw() __attribute__((__noreturn__));
  ::std::unexpected_handler set_unexpected(::std::unexpected_handler) throw();
  void unexpected() __attribute__((__noreturn__));
  bool uncaught_exception() throw() __attribute__((__pure__));
  int uncaught_exceptions() throw() __attribute__((__pure__));
}
namespace __gnu_cxx __attribute__((__visibility__("default"))) {
  void __verbose_terminate_handler();
}
#pragma GCC visibility pop
#pragma GCC visibility push(default)
namespace std __attribute__((__visibility__("default"))) {
  class  bad_alloc : public ::std::exception
  {
    public:
      inline bad_alloc() throw()
      {
      }
      virtual ~bad_alloc() throw();
      virtual const char *what() const  throw();
  };
  struct  nothrow_t
  {
  };
  extern const ::std::nothrow_t nothrow;
  typedef void (*new_handler)();
  ::std::new_handler set_new_handler(::std::new_handler) throw();
}
void *operator new(::std::size_t, const ::std::nothrow_t &) throw() __attribute__((__externally_visible__));
void *operator new[](::std::size_t, const ::std::nothrow_t &) throw() __attribute__((__externally_visible__));
void operator delete(void *, const ::std::nothrow_t &) throw() __attribute__((__externally_visible__));
void operator delete[](void *, const ::std::nothrow_t &) throw() __attribute__((__externally_visible__));
inline void *operator new(::std::size_t, void *__p) throw()
{
  return __p;
}
inline void *operator new[](::std::size_t, void *__p) throw()
{
  return __p;
}
inline void operator delete(void *, void *) throw()
{
}
inline void operator delete[](void *, void *) throw()
{
}
#pragma GCC visibility pop
struct __attribute__((aligned(8)))  cell_t
{
    int h;
    union 
    {
        int f;
        int e;
    };
};
struct  match_result_t
{
    bool found;
    int k;
    int score;
    int type;
};
struct  score_t
{
    int i;
    int j;
    int score;
};
struct  score_params_t
{
    int match;
    int mismatch;
    int gap_open;
    int gap_ext;
};
class  Partition
{
    int i0;
    int j0;
    int i1;
    int j1;
  public:
    Partition();
    Partition(int i0, int j0, int i1, int j1);
    Partition(const ::Partition &partition, int i_offset, int j_offset);
    virtual ~Partition();
    int getI0() const ;
    void setI0(int i0);
    int getI1() const ;
    void setI1(int i1);
    int getJ0() const ;
    void setJ0(int j0);
    int getJ1() const ;
    void setJ1(int j1);
    int getHeight() const ;
    int getWidth() const ;
    bool hasZeroArea() const ;
};
class  IManager
{
  public:
    virtual int getRecurrenceType() const  = 0 ;
    virtual int getSpecialRowInterval() const  = 0 ;
    virtual int getSpecialColumnInterval() const  = 0 ;
    virtual int getFirstColumnInitType() = 0 ;
    virtual int getFirstRowInitType() = 0 ;
    virtual ::Partition getSuperPartition() = 0 ;
    virtual void receiveFirstRow(::cell_t *buffer, int len) = 0 ;
    virtual void receiveFirstColumn(::cell_t *buffer, int len) = 0 ;
    virtual void dispatchColumn(int j, const ::cell_t *buffer, int len) = 0 ;
    virtual void dispatchRow(int i, const ::cell_t *buffer, int len) = 0 ;
    virtual void dispatchScore(::score_t score, int bx  = ( -1), int by  = ( -1)) = 0 ;
    virtual bool mustContinue() = 0 ;
    virtual bool mustDispatchLastCell() = 0 ;
    virtual bool mustDispatchLastRow() = 0 ;
    virtual bool mustDispatchLastColumn() = 0 ;
    virtual bool mustDispatchSpecialRows() = 0 ;
    virtual bool mustDispatchSpecialColumns() = 0 ;
    virtual bool mustDispatchScores() = 0 ;
    virtual bool mustPruneBlocks() = 0 ;
  protected:
    inline ~IManager()
    {
    }
    inline IManager()
    {
    }
  public:
};
extern "C"
{
  extern inline void *memcpy(void *__restrict __dest, const void *__restrict __src, ::size_t __len) throw() __attribute__((__nonnull__(1, 2))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern inline void *memmove(void *__dest, const void *__src, ::size_t __len) throw() __attribute__((__nonnull__(1, 2))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern void *memccpy(void *__restrict __dest, const void *__restrict __src, int __c, ::size_t __n) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern inline void *memset(void *__dest, int __ch, ::size_t __len) throw() __attribute__((__nonnull__(1))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern int memcmp(const void *__s1, const void *__s2, ::size_t __n) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
}
extern inline void *memchr(void *__s, int __c, ::size_t __n) throw() __asm("memchr") __attribute__((__pure__)) __attribute__((__nonnull__(1))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__));
extern inline const void *memchr(const void *__s, int __c, ::size_t __n) throw() __asm("memchr") __attribute__((__pure__)) __attribute__((__nonnull__(1))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__));
extern inline __attribute__((__pure__)) __attribute__((__nonnull__(1))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) void *memchr(void *__s, int __c, ::size_t __n) throw()
{
  return __builtin_memchr(__s, __c, __n);
}
extern inline __attribute__((__pure__)) __attribute__((__nonnull__(1))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) const void *memchr(const void *__s, int __c, ::size_t __n) throw()
{
  return __builtin_memchr(__s, __c, __n);
}
void *rawmemchr(void *__s, int __c) throw() __asm("rawmemchr") __attribute__((__pure__)) __attribute__((__nonnull__(1)));
const void *rawmemchr(const void *__s, int __c) throw() __asm("rawmemchr") __attribute__((__pure__)) __attribute__((__nonnull__(1)));
void *memrchr(void *__s, int __c, ::size_t __n) throw() __asm("memrchr") __attribute__((__pure__)) __attribute__((__nonnull__(1)));
const void *memrchr(const void *__s, int __c, ::size_t __n) throw() __asm("memrchr") __attribute__((__pure__)) __attribute__((__nonnull__(1)));
extern "C"
{
  extern inline char *strcpy(char *__restrict __dest, const char *__restrict __src) throw() __attribute__((__nonnull__(1, 2))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern inline char *strncpy(char *__restrict __dest, const char *__restrict __src, ::size_t __len) throw() __attribute__((__nonnull__(1, 2))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern inline char *strcat(char *__restrict __dest, const char *__restrict __src) throw() __attribute__((__nonnull__(1, 2))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern inline char *strncat(char *__restrict __dest, const char *__restrict __src, ::size_t __len) throw() __attribute__((__nonnull__(1, 2))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern int strcmp(const char *__s1, const char *__s2) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int strncmp(const char *__s1, const char *__s2, ::size_t __n) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int strcoll(const char *__s1, const char *__s2) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern ::size_t strxfrm(char *__restrict __dest, const char *__restrict __src, ::size_t __n) throw() __attribute__((__nonnull__(2)));
}
struct __locale_data;
struct  __locale_struct
{
    ::__locale_data *__locales[13L];
    const unsigned short int *__ctype_b;
    const int *__ctype_tolower;
    const int *__ctype_toupper;
    const char *__names[13L];
};
typedef ::__locale_struct *__locale_t;
typedef ::__locale_t locale_t;
extern "C"
{
  extern int strcoll_l(const char *__s1, const char *__s2, ::locale_t __l) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1, 2, 3)));
}
extern "C"
{
  extern ::size_t strxfrm_l(char *__dest, const char *__src, ::size_t __n, ::locale_t __l) throw() __attribute__((__nonnull__(2, 4)));
}
extern "C"
{
  extern char *strdup(const char *__s) throw() __attribute__((__malloc__)) __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern char *strndup(const char *__string, ::size_t __n) throw() __attribute__((__malloc__)) __attribute__((__nonnull__(1)));
}
extern inline char *strchr(char *__s, int __c) throw() __asm("strchr") __attribute__((__pure__)) __attribute__((__nonnull__(1))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__));
extern inline const char *strchr(const char *__s, int __c) throw() __asm("strchr") __attribute__((__pure__)) __attribute__((__nonnull__(1))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__));
extern inline __attribute__((__pure__)) __attribute__((__nonnull__(1))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) char *strchr(char *__s, int __c) throw()
{
  return __builtin_strchr(__s, __c);
}
extern inline __attribute__((__pure__)) __attribute__((__nonnull__(1))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) const char *strchr(const char *__s, int __c) throw()
{
  return __builtin_strchr(__s, __c);
}
extern inline char *strrchr(char *__s, int __c) throw() __asm("strrchr") __attribute__((__pure__)) __attribute__((__nonnull__(1))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__));
extern inline const char *strrchr(const char *__s, int __c) throw() __asm("strrchr") __attribute__((__pure__)) __attribute__((__nonnull__(1))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__));
extern inline __attribute__((__pure__)) __attribute__((__nonnull__(1))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) char *strrchr(char *__s, int __c) throw()
{
  return __builtin_strrchr(__s, __c);
}
extern inline __attribute__((__pure__)) __attribute__((__nonnull__(1))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) const char *strrchr(const char *__s, int __c) throw()
{
  return __builtin_strrchr(__s, __c);
}
char *strchrnul(char *__s, int __c) throw() __asm("strchrnul") __attribute__((__pure__)) __attribute__((__nonnull__(1)));
const char *strchrnul(const char *__s, int __c) throw() __asm("strchrnul") __attribute__((__pure__)) __attribute__((__nonnull__(1)));
extern "C"
{
  extern ::size_t strcspn(const char *__s, const char *__reject) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern ::size_t strspn(const char *__s, const char *__accept) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
}
extern inline char *strpbrk(char *__s, const char *__accept) throw() __asm("strpbrk") __attribute__((__pure__)) __attribute__((__nonnull__(1, 2))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__));
extern inline const char *strpbrk(const char *__s, const char *__accept) throw() __asm("strpbrk") __attribute__((__pure__)) __attribute__((__nonnull__(1, 2))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__));
extern inline __attribute__((__pure__)) __attribute__((__nonnull__(1, 2))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) char *strpbrk(char *__s, const char *__accept) throw()
{
  return __builtin_strpbrk(__s, __accept);
}
extern inline __attribute__((__pure__)) __attribute__((__nonnull__(1, 2))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) const char *strpbrk(const char *__s, const char *__accept) throw()
{
  return __builtin_strpbrk(__s, __accept);
}
extern inline char *strstr(char *__haystack, const char *__needle) throw() __asm("strstr") __attribute__((__pure__)) __attribute__((__nonnull__(1, 2))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__));
extern inline const char *strstr(const char *__haystack, const char *__needle) throw() __asm("strstr") __attribute__((__pure__)) __attribute__((__nonnull__(1, 2))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__));
extern inline __attribute__((__pure__)) __attribute__((__nonnull__(1, 2))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) char *strstr(char *__haystack, const char *__needle) throw()
{
  return __builtin_strstr(__haystack, __needle);
}
extern inline __attribute__((__pure__)) __attribute__((__nonnull__(1, 2))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) const char *strstr(const char *__haystack, const char *__needle) throw()
{
  return __builtin_strstr(__haystack, __needle);
}
extern "C"
{
  extern char *strtok(char *__restrict __s, const char *__restrict __delim) throw() __attribute__((__nonnull__(2)));
}
extern "C"
{
  extern char *__strtok_r(char *__restrict __s, const char *__restrict __delim, char **__restrict __save_ptr) throw() __attribute__((__nonnull__(2, 3)));
}
extern "C"
{
  extern char *strtok_r(char *__restrict __s, const char *__restrict __delim, char **__restrict __save_ptr) throw() __attribute__((__nonnull__(2, 3)));
}
char *strcasestr(char *__haystack, const char *__needle) throw() __asm("strcasestr") __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
const char *strcasestr(const char *__haystack, const char *__needle) throw() __asm("strcasestr") __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
extern "C"
{
  extern void *memmem(const void *__haystack, ::size_t __haystacklen, const void *__needle, ::size_t __needlelen) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1, 3)));
}
extern "C"
{
  extern void *__mempcpy(void *__restrict __dest, const void *__restrict __src, ::size_t __n) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern inline void *mempcpy(void *__restrict __dest, const void *__restrict __src, ::size_t __len) throw() __attribute__((__nonnull__(1, 2))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern ::size_t strlen(const char *__s) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern ::size_t strnlen(const char *__string, ::size_t __maxlen) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern char *strerror(int __errnum) throw();
}
extern "C"
{
  extern char *strerror_r(int __errnum, char *__buf, ::size_t __buflen) throw() __attribute__((__nonnull__(2))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern char *strerror_l(int __errnum, ::locale_t __l) throw();
}
extern "C"
{
  extern int bcmp(const void *__s1, const void *__s2, ::size_t __n) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern inline void bcopy(const void *__src, void *__dest, ::size_t __len) throw() __attribute__((__nonnull__(1, 2))) __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern inline void bzero(void *__dest, ::size_t __len) throw() __attribute__((__nonnull__(1))) __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern inline char *index(char *__s, int __c) throw() __asm("index") __attribute__((__pure__)) __attribute__((__nonnull__(1))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__));
extern inline const char *index(const char *__s, int __c) throw() __asm("index") __attribute__((__pure__)) __attribute__((__nonnull__(1))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__));
extern inline __attribute__((__pure__)) __attribute__((__nonnull__(1))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) char *index(char *__s, int __c) throw()
{
  return __builtin_index(__s, __c);
}
extern inline __attribute__((__pure__)) __attribute__((__nonnull__(1))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) const char *index(const char *__s, int __c) throw()
{
  return __builtin_index(__s, __c);
}
extern inline char *rindex(char *__s, int __c) throw() __asm("rindex") __attribute__((__pure__)) __attribute__((__nonnull__(1))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__));
extern inline const char *rindex(const char *__s, int __c) throw() __asm("rindex") __attribute__((__pure__)) __attribute__((__nonnull__(1))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__));
extern inline __attribute__((__pure__)) __attribute__((__nonnull__(1))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) char *rindex(char *__s, int __c) throw()
{
  return __builtin_rindex(__s, __c);
}
extern inline __attribute__((__pure__)) __attribute__((__nonnull__(1))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) const char *rindex(const char *__s, int __c) throw()
{
  return __builtin_rindex(__s, __c);
}
extern "C"
{
  extern int ffs(int __i) throw() __attribute__((__const__));
}
extern "C"
{
  extern int ffsl(long int __l) throw() __attribute__((__const__));
}
extern "C"
{
  extern int ffsll(long long int __ll) throw() __attribute__((__const__));
}
extern "C"
{
  extern int strcasecmp(const char *__s1, const char *__s2) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int strncasecmp(const char *__s1, const char *__s2, ::size_t __n) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int strcasecmp_l(const char *__s1, const char *__s2, ::locale_t __loc) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1, 2, 3)));
}
extern "C"
{
  extern int strncasecmp_l(const char *__s1, const char *__s2, ::size_t __n, ::locale_t __loc) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1, 2, 4)));
}
extern "C"
{
  extern inline __attribute__((__nonnull__(1, 2))) __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) void bcopy(const void *__src, void *__dest, ::size_t __len) throw()
  {
    (void)__builtin___memmove_chk(__dest, __src, __len, __builtin_object_size(__dest, 0));
  }
}
extern "C"
{
  extern inline __attribute__((__nonnull__(1))) __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) void bzero(void *__dest, ::size_t __len) throw()
  {
    (void)__builtin___memset_chk(__dest, '\000', __len, __builtin_object_size(__dest, 0));
  }
}
extern "C"
{
  extern inline void explicit_bzero(void *__dest, ::size_t __len) throw() __attribute__((__nonnull__(1))) __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern char *strsep(char **__restrict __stringp, const char *__restrict __delim) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern char *strsignal(int __sig) throw();
}
extern "C"
{
  extern char *__stpcpy(char *__restrict __dest, const char *__restrict __src) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern inline char *stpcpy(char *__restrict __dest, const char *__restrict __src) throw() __attribute__((__nonnull__(1, 2))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern char *__stpncpy(char *__restrict __dest, const char *__restrict __src, ::size_t __n) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern inline char *stpncpy(char *__restrict __dest, const char *__restrict __src, ::size_t __n) throw() __attribute__((__nonnull__(1, 2))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern int strverscmp(const char *__s1, const char *__s2) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern char *strfry(char *__string) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern void *memfrob(void *__s, ::size_t __n) throw() __attribute__((__nonnull__(1)));
}
char *basename(char *__filename) throw() __asm("basename") __attribute__((__nonnull__(1)));
const char *basename(const char *__filename) throw() __asm("basename") __attribute__((__nonnull__(1)));
extern "C"
{
  extern inline __attribute__((__nonnull__(1, 2))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) void *memcpy(void *__restrict __dest, const void *__restrict __src, ::size_t __len) throw()
  {
    return __builtin___memcpy_chk(__dest, __src, __len, __builtin_object_size(__dest, 0));
  }
}
extern "C"
{
  extern inline __attribute__((__nonnull__(1, 2))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) void *memmove(void *__dest, const void *__src, ::size_t __len) throw()
  {
    return __builtin___memmove_chk(__dest, __src, __len, __builtin_object_size(__dest, 0));
  }
}
extern "C"
{
  extern inline __attribute__((__nonnull__(1, 2))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) void *mempcpy(void *__restrict __dest, const void *__restrict __src, ::size_t __len) throw()
  {
    return __builtin___mempcpy_chk(__dest, __src, __len, __builtin_object_size(__dest, 0));
  }
}
extern "C"
{
  extern inline __attribute__((__nonnull__(1))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) void *memset(void *__dest, int __ch, ::size_t __len) throw()
  {
    return __builtin___memset_chk(__dest, __ch, __len, __builtin_object_size(__dest, 0));
  }
}
extern "C"
{
  void __explicit_bzero_chk(void *__dest, ::size_t __len, ::size_t __destlen) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern inline __attribute__((__nonnull__(1))) __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) void explicit_bzero(void *__dest, ::size_t __len) throw()
  {
    ::__explicit_bzero_chk(__dest, __len, __builtin_object_size(__dest, 0));
  }
}
extern "C"
{
  extern inline __attribute__((__nonnull__(1, 2))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) char *strcpy(char *__restrict __dest, const char *__restrict __src) throw()
  {
    return __builtin___strcpy_chk(__dest, __src, __builtin_object_size(__dest, 2 > 1));
  }
}
extern "C"
{
  extern inline __attribute__((__nonnull__(1, 2))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) char *stpcpy(char *__restrict __dest, const char *__restrict __src) throw()
  {
    return __builtin___stpcpy_chk(__dest, __src, __builtin_object_size(__dest, 2 > 1));
  }
}
extern "C"
{
  extern inline __attribute__((__nonnull__(1, 2))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) char *strncpy(char *__restrict __dest, const char *__restrict __src, ::size_t __len) throw()
  {
    return __builtin___strncpy_chk(__dest, __src, __len, __builtin_object_size(__dest, 2 > 1));
  }
}
extern "C"
{
  extern char *__stpncpy_chk(char *__dest, const char *__src, ::size_t __n, ::size_t __destlen) throw();
}
extern "C"
{
  extern char *__stpncpy_alias(char *__dest, const char *__src, ::size_t __n) throw() __asm("""stpncpy");
}
extern "C"
{
  extern inline __attribute__((__nonnull__(1, 2))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) char *stpncpy(char *__dest, const char *__src, ::size_t __n) throw()
  {
    if (__builtin_object_size(__dest, 2 > 1) != (::size_t) -1 && (!__builtin_constant_p(__n) || __n > __builtin_object_size(__dest, 2 > 1)))
      {
        return ::__stpncpy_chk(__dest, __src, __n, __builtin_object_size(__dest, 2 > 1));
      }
    return ::__stpncpy_alias(__dest, __src, __n);
  }
}
extern "C"
{
  extern inline __attribute__((__nonnull__(1, 2))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) char *strcat(char *__restrict __dest, const char *__restrict __src) throw()
  {
    return __builtin___strcat_chk(__dest, __src, __builtin_object_size(__dest, 2 > 1));
  }
}
extern "C"
{
  extern inline __attribute__((__nonnull__(1, 2))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) char *strncat(char *__restrict __dest, const char *__restrict __src, ::size_t __len) throw()
  {
    return __builtin___strncat_chk(__dest, __src, __len, __builtin_object_size(__dest, 2 > 1));
  }
}
struct _IO_FILE;
typedef ::_IO_FILE __FILE;
typedef ::_IO_FILE FILE;
struct  __mbstate_t
{
    int __count;
    union  mcc_union_anon_26
    {
        unsigned int __wch;
        char __wchb[4L];
    };
    ::__mbstate_t::mcc_union_anon_26 __value;
};
struct  _G_fpos_t
{
    ::__off_t __pos;
    ::__mbstate_t __state;
};
struct  _G_fpos64_t
{
    ::__off64_t __pos;
    ::__mbstate_t __state;
};
typedef ::__builtin_va_list __gnuc_va_list;
struct _IO_jump_t;
typedef void _IO_lock_t;
struct _IO_marker;
struct  _IO_marker
{
    ::_IO_marker *_next;
    ::_IO_FILE *_sbuf;
    int _pos;
};
enum __codecvt_result
{
  __codecvt_ok = 0,
  __codecvt_partial = 1,
  __codecvt_error = 2,
  __codecvt_noconv = 3
};
struct  _IO_FILE
{
    int _flags;
    char *_IO_read_ptr;
    char *_IO_read_end;
    char *_IO_read_base;
    char *_IO_write_base;
    char *_IO_write_ptr;
    char *_IO_write_end;
    char *_IO_buf_base;
    char *_IO_buf_end;
    char *_IO_save_base;
    char *_IO_backup_base;
    char *_IO_save_end;
    ::_IO_marker *_markers;
    ::_IO_FILE *_chain;
    int _fileno;
    int _flags2;
    ::__off_t _old_offset;
    unsigned short int _cur_column;
    signed char _vtable_offset;
    char _shortbuf[1L];
    ::_IO_lock_t *_lock;
    ::__off64_t _offset;
    void *__pad1;
    void *__pad2;
    void *__pad3;
    void *__pad4;
    ::size_t __pad5;
    int _mode;
    char _unused2[20L];
};
struct _IO_FILE_plus;
extern "C"
{
  extern ::_IO_FILE_plus _IO_2_1_stdin_;
}
extern "C"
{
  extern ::_IO_FILE_plus _IO_2_1_stdout_;
}
extern "C"
{
  extern ::_IO_FILE_plus _IO_2_1_stderr_;
}
typedef ::__ssize_t __io_read_fn(void *, char *, ::size_t);
typedef ::__ssize_t __io_write_fn(void *, const char *, ::size_t);
typedef int __io_seek_fn(void *, ::__off64_t *, int);
typedef int __io_close_fn(void *);
typedef ::__io_read_fn cookie_read_function_t;
typedef ::__io_write_fn cookie_write_function_t;
typedef ::__io_seek_fn cookie_seek_function_t;
typedef ::__io_close_fn cookie_close_function_t;
struct  _IO_cookie_io_functions_t
{
    ::__io_read_fn (*read);
    ::__io_write_fn (*write);
    ::__io_seek_fn (*seek);
    ::__io_close_fn (*close);
};
typedef ::_IO_cookie_io_functions_t cookie_io_functions_t;
struct _IO_cookie_file;
extern "C"
{
  extern void _IO_cookie_init(::_IO_cookie_file *__cfile, int __read_write, void *__cookie, ::_IO_cookie_io_functions_t __fns);
}
extern "C"
{
  extern int __underflow(::_IO_FILE *);
}
extern "C"
{
  extern int __uflow(::_IO_FILE *);
}
extern "C"
{
  extern int __overflow(::_IO_FILE *, int);
}
extern "C"
{
  extern int _IO_getc(::_IO_FILE *__fp);
}
extern "C"
{
  extern int _IO_putc(int __c, ::_IO_FILE *__fp);
}
extern "C"
{
  extern int _IO_feof(::_IO_FILE *__fp) throw();
}
extern "C"
{
  extern int _IO_ferror(::_IO_FILE *__fp) throw();
}
extern "C"
{
  extern int _IO_peekc_locked(::_IO_FILE *__fp);
}
extern "C"
{
  extern void _IO_flockfile(::_IO_FILE *) throw();
}
extern "C"
{
  extern void _IO_funlockfile(::_IO_FILE *) throw();
}
extern "C"
{
  extern int _IO_ftrylockfile(::_IO_FILE *) throw();
}
extern "C"
{
  extern int _IO_vfscanf(::_IO_FILE *__restrict , const char *__restrict , ::__gnuc_va_list, int *__restrict );
}
extern "C"
{
  extern int _IO_vfprintf(::_IO_FILE *__restrict , const char *__restrict , ::__gnuc_va_list);
}
extern "C"
{
  extern ::__ssize_t _IO_padn(::_IO_FILE *, int, ::__ssize_t);
}
extern "C"
{
  extern ::size_t _IO_sgetn(::_IO_FILE *, void *, ::size_t);
}
extern "C"
{
  extern ::__off64_t _IO_seekoff(::_IO_FILE *, ::__off64_t, int, int);
}
extern "C"
{
  extern ::__off64_t _IO_seekpos(::_IO_FILE *, ::__off64_t, int);
}
extern "C"
{
  extern void _IO_free_backup_area(::_IO_FILE *) throw();
}
typedef ::__gnuc_va_list va_list;
typedef ::__off_t off_t;
typedef ::__off64_t off64_t;
typedef ::__ssize_t ssize_t;
typedef ::_G_fpos_t fpos_t;
typedef ::_G_fpos64_t fpos64_t;
extern "C"
{
  extern ::_IO_FILE *stdin;
}
extern "C"
{
  extern ::_IO_FILE *stdout;
}
extern "C"
{
  extern ::_IO_FILE *stderr;
}
extern "C"
{
  extern int remove(const char *__filename) throw();
}
extern "C"
{
  extern int rename(const char *__old, const char *__new) throw();
}
extern "C"
{
  extern int renameat(int __oldfd, const char *__old, int __newfd, const char *__new) throw();
}
extern "C"
{
  extern ::FILE *tmpfile() __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern ::FILE *tmpfile64() __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern char *tmpnam(char *__s) throw() __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern char *tmpnam_r(char *__s) throw() __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern char *tempnam(const char *__dir, const char *__pfx) throw() __attribute__((__malloc__)) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int fclose(::FILE *__stream);
}
extern "C"
{
  extern int fflush(::FILE *__stream);
}
extern "C"
{
  extern int fflush_unlocked(::FILE *__stream);
}
extern "C"
{
  extern int fcloseall();
}
extern "C"
{
  extern ::FILE *fopen(const char *__restrict __filename, const char *__restrict __modes) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern ::FILE *freopen(const char *__restrict __filename, const char *__restrict __modes, ::FILE *__restrict __stream) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern ::FILE *fopen64(const char *__restrict __filename, const char *__restrict __modes) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern ::FILE *freopen64(const char *__restrict __filename, const char *__restrict __modes, ::FILE *__restrict __stream) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern ::FILE *fdopen(int __fd, const char *__modes) throw() __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern ::FILE *fopencookie(void *__restrict __magic_cookie, const char *__restrict __modes, ::_IO_cookie_io_functions_t __io_funcs) throw() __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern ::FILE *fmemopen(void *__s, ::size_t __len, const char *__modes) throw() __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern ::FILE *open_memstream(char **__bufloc, ::size_t *__sizeloc) throw() __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern void setbuf(::FILE *__restrict __stream, char *__restrict __buf) throw();
}
extern "C"
{
  extern int setvbuf(::FILE *__restrict __stream, char *__restrict __buf, int __modes, ::size_t __n) throw();
}
extern "C"
{
  extern void setbuffer(::FILE *__restrict __stream, char *__restrict __buf, ::size_t __size) throw();
}
extern "C"
{
  extern void setlinebuf(::FILE *__stream) throw();
}
extern "C"
{
  extern inline int fprintf(::FILE *__restrict __stream, const char *__restrict __fmt, ...) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern inline int printf(const char *__restrict __fmt, ...) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern inline int sprintf(char *__restrict __s, const char *__restrict __fmt, ...) throw() __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern inline int vfprintf(::FILE *__restrict __stream, const char *__restrict __fmt, ::__gnuc_va_list __ap) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern inline int vprintf(const char *__restrict __fmt, ::__gnuc_va_list __ap) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern inline int vsprintf(char *__restrict __s, const char *__restrict __fmt, ::__gnuc_va_list __ap) throw() __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern inline int snprintf(char *__restrict __s, ::size_t __n, const char *__restrict __fmt, ...) throw() __attribute__((__format__(__printf__, 3, 4))) __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern inline int vsnprintf(char *__restrict __s, ::size_t __n, const char *__restrict __fmt, ::__gnuc_va_list __ap) throw() __attribute__((__format__(__printf__, 3, 0))) __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern inline int vasprintf(char **__restrict __ptr, const char *__restrict __fmt, ::__gnuc_va_list __ap) throw() __attribute__((__format__(__printf__, 2, 0))) __attribute__((__warn_unused_result__)) __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern inline int __asprintf(char **__restrict __ptr, const char *__restrict __fmt, ...) throw() __attribute__((__format__(__printf__, 2, 3))) __attribute__((__warn_unused_result__)) __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern inline int asprintf(char **__restrict __ptr, const char *__restrict __fmt, ...) throw() __attribute__((__format__(__printf__, 2, 3))) __attribute__((__warn_unused_result__)) __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern inline int vdprintf(int __fd, const char *__restrict __fmt, ::__gnuc_va_list __ap) __attribute__((__format__(__printf__, 2, 0))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern inline int dprintf(int __fd, const char *__restrict __fmt, ...) __attribute__((__format__(__printf__, 2, 3))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern int fscanf(::FILE *__restrict __stream, const char *__restrict __format, ...) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int scanf(const char *__restrict __format, ...) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int sscanf(const char *__restrict __s, const char *__restrict __format, ...) throw();
}
extern "C"
{
  extern int vfscanf(::FILE *__restrict __s, const char *__restrict __format, ::__gnuc_va_list __arg) __attribute__((__format__(__scanf__, 2, 0))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int vscanf(const char *__restrict __format, ::__gnuc_va_list __arg) __attribute__((__format__(__scanf__, 1, 0))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int vsscanf(const char *__restrict __s, const char *__restrict __format, ::__gnuc_va_list __arg) throw() __attribute__((__format__(__scanf__, 2, 0)));
}
extern "C"
{
  extern int fgetc(::FILE *__stream);
}
extern "C"
{
  extern int getc(::FILE *__stream);
}
extern "C"
{
  extern inline int getchar() __attribute__((__gnu_inline__));
}
extern "C"
{
  extern inline int getc_unlocked(::FILE *__fp) __attribute__((__gnu_inline__));
}
extern "C"
{
  extern inline int getchar_unlocked() __attribute__((__gnu_inline__));
}
extern "C"
{
  extern inline int fgetc_unlocked(::FILE *__fp) __attribute__((__gnu_inline__));
}
extern "C"
{
  extern int fputc(int __c, ::FILE *__stream);
}
extern "C"
{
  extern int putc(int __c, ::FILE *__stream);
}
extern "C"
{
  extern inline int putchar(int __c) __attribute__((__gnu_inline__));
}
extern "C"
{
  extern inline int fputc_unlocked(int __c, ::FILE *__stream) __attribute__((__gnu_inline__));
}
extern "C"
{
  extern inline int putc_unlocked(int __c, ::FILE *__stream) __attribute__((__gnu_inline__));
}
extern "C"
{
  extern inline int putchar_unlocked(int __c) __attribute__((__gnu_inline__));
}
extern "C"
{
  extern int getw(::FILE *__stream);
}
extern "C"
{
  extern int putw(int __w, ::FILE *__stream);
}
extern "C"
{
  extern inline char *fgets(char *__restrict __s, int __n, ::FILE *__restrict __stream) __attribute__((__warn_unused_result__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern inline char *gets(char *__str) __attribute__((__warn_unused_result__)) __attribute__((__deprecated__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern inline char *fgets_unlocked(char *__restrict __s, int __n, ::FILE *__restrict __stream) __attribute__((__warn_unused_result__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern ::__ssize_t __getdelim(char **__restrict __lineptr, ::size_t *__restrict __n, int __delimiter, ::FILE *__restrict __stream) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern ::__ssize_t getdelim(char **__restrict __lineptr, ::size_t *__restrict __n, int __delimiter, ::FILE *__restrict __stream) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern inline ::__ssize_t getline(char **__restrict __lineptr, ::size_t *__restrict __n, ::FILE *__restrict __stream) __attribute__((__warn_unused_result__)) __attribute__((__gnu_inline__));
}
extern "C"
{
  extern int fputs(const char *__restrict __s, ::FILE *__restrict __stream);
}
extern "C"
{
  extern int puts(const char *__s);
}
extern "C"
{
  extern int ungetc(int __c, ::FILE *__stream);
}
extern "C"
{
  extern inline ::size_t fread(void *__restrict __ptr, ::size_t __size, ::size_t __n, ::FILE *__restrict __stream) __attribute__((__warn_unused_result__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern ::size_t fwrite(const void *__restrict __ptr, ::size_t __size, ::size_t __n, ::FILE *__restrict __s);
}
extern "C"
{
  extern int fputs_unlocked(const char *__restrict __s, ::FILE *__restrict __stream);
}
extern "C"
{
  extern inline ::size_t fread_unlocked(void *__restrict __ptr, ::size_t __size, ::size_t __n, ::FILE *__restrict __stream) __attribute__((__warn_unused_result__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern ::size_t fwrite_unlocked(const void *__restrict __ptr, ::size_t __size, ::size_t __n, ::FILE *__restrict __stream);
}
extern "C"
{
  extern int fseek(::FILE *__stream, long int __off, int __whence);
}
extern "C"
{
  extern long int ftell(::FILE *__stream) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern void rewind(::FILE *__stream);
}
extern "C"
{
  extern int fseeko(::FILE *__stream, ::__off_t __off, int __whence);
}
extern "C"
{
  extern ::__off_t ftello(::FILE *__stream) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int fgetpos(::FILE *__restrict __stream, ::fpos_t *__restrict __pos);
}
extern "C"
{
  extern int fsetpos(::FILE *__stream, const ::fpos_t *__pos);
}
extern "C"
{
  extern int fseeko64(::FILE *__stream, ::__off64_t __off, int __whence);
}
extern "C"
{
  extern ::__off64_t ftello64(::FILE *__stream) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int fgetpos64(::FILE *__restrict __stream, ::fpos64_t *__restrict __pos);
}
extern "C"
{
  extern int fsetpos64(::FILE *__stream, const ::fpos64_t *__pos);
}
extern "C"
{
  extern void clearerr(::FILE *__stream) throw();
}
extern "C"
{
  extern int feof(::FILE *__stream) throw() __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int ferror(::FILE *__stream) throw() __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern void clearerr_unlocked(::FILE *__stream) throw();
}
extern "C"
{
  extern inline int feof_unlocked(::FILE *__stream) throw() __attribute__((__warn_unused_result__)) __attribute__((__leaf__)) __attribute__((__gnu_inline__));
}
extern "C"
{
  extern inline int ferror_unlocked(::FILE *__stream) throw() __attribute__((__warn_unused_result__)) __attribute__((__leaf__)) __attribute__((__gnu_inline__));
}
extern "C"
{
  extern void perror(const char *__s);
}
extern "C"
{
  extern int sys_nerr;
}
extern "C"
{
  extern const char *const sys_errlist[];
}
extern "C"
{
  extern int _sys_nerr;
}
extern "C"
{
  extern const char *const _sys_errlist[];
}
extern "C"
{
  extern int fileno(::FILE *__stream) throw() __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int fileno_unlocked(::FILE *__stream) throw() __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern ::FILE *popen(const char *__command, const char *__modes) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int pclose(::FILE *__stream);
}
extern "C"
{
  extern char *ctermid(char *__s) throw();
}
extern "C"
{
  extern char *cuserid(char *__s);
}
struct obstack;
extern "C"
{
  extern inline int obstack_printf(::obstack *__restrict __obstack, const char *__restrict __fmt, ...) throw() __attribute__((__format__(__printf__, 2, 3))) __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern inline int obstack_vprintf(::obstack *__restrict __obstack, const char *__restrict __fmt, ::__gnuc_va_list __ap) throw() __attribute__((__format__(__printf__, 2, 0))) __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern void flockfile(::FILE *__stream) throw();
}
extern "C"
{
  extern int ftrylockfile(::FILE *__stream) throw() __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern void funlockfile(::FILE *__stream) throw();
}
extern "C"
{
  extern inline __attribute__((__gnu_inline__)) int getchar()
  {
    return ::_IO_getc(::stdin);
  }
}
extern "C"
{
  extern inline __attribute__((__gnu_inline__)) int fgetc_unlocked(::FILE *__fp)
  {
    return __builtin_expect((*__fp)._IO_read_ptr >= (*__fp)._IO_read_end, 0) ? ::__uflow(__fp) : *((unsigned char *)(*__fp)._IO_read_ptr++);
  }
}
extern "C"
{
  extern inline __attribute__((__gnu_inline__)) int getc_unlocked(::FILE *__fp)
  {
    return __builtin_expect((*__fp)._IO_read_ptr >= (*__fp)._IO_read_end, 0) ? ::__uflow(__fp) : *((unsigned char *)(*__fp)._IO_read_ptr++);
  }
}
extern "C"
{
  extern inline __attribute__((__gnu_inline__)) int getchar_unlocked()
  {
    return __builtin_expect((*::stdin)._IO_read_ptr >= (*::stdin)._IO_read_end, 0) ? ::__uflow(::stdin) : *((unsigned char *)(*::stdin)._IO_read_ptr++);
  }
}
extern "C"
{
  extern inline __attribute__((__gnu_inline__)) int putchar(int __c)
  {
    return ::_IO_putc(__c, ::stdout);
  }
}
extern "C"
{
  extern inline __attribute__((__gnu_inline__)) int fputc_unlocked(int __c, ::FILE *__stream)
  {
    return __builtin_expect((*__stream)._IO_write_ptr >= (*__stream)._IO_write_end, 0) ? ::__overflow(__stream, (unsigned char)__c) : (unsigned char)(*(*__stream)._IO_write_ptr++ = __c);
  }
}
extern "C"
{
  extern inline __attribute__((__gnu_inline__)) int putc_unlocked(int __c, ::FILE *__stream)
  {
    return __builtin_expect((*__stream)._IO_write_ptr >= (*__stream)._IO_write_end, 0) ? ::__overflow(__stream, (unsigned char)__c) : (unsigned char)(*(*__stream)._IO_write_ptr++ = __c);
  }
}
extern "C"
{
  extern inline __attribute__((__gnu_inline__)) int putchar_unlocked(int __c)
  {
    return __builtin_expect((*::stdout)._IO_write_ptr >= (*::stdout)._IO_write_end, 0) ? ::__overflow(::stdout, (unsigned char)__c) : (unsigned char)(*(*::stdout)._IO_write_ptr++ = __c);
  }
}
extern "C"
{
  extern inline __attribute__((__warn_unused_result__)) __attribute__((__gnu_inline__)) ::__ssize_t getline(char **__lineptr, ::size_t *__n, ::FILE *__stream)
  {
    return ::__getdelim(__lineptr, __n, '\n', __stream);
  }
}
extern "C"
{
  extern inline __attribute__((__warn_unused_result__)) __attribute__((__leaf__)) __attribute__((__gnu_inline__)) int feof_unlocked(::FILE *__stream) throw()
  {
    return ((*__stream)._flags & 16) != 0;
  }
}
extern "C"
{
  extern inline __attribute__((__warn_unused_result__)) __attribute__((__leaf__)) __attribute__((__gnu_inline__)) int ferror_unlocked(::FILE *__stream) throw()
  {
    return ((*__stream)._flags & 32) != 0;
  }
}
extern "C"
{
  extern int __sprintf_chk(char *__restrict __s, int __flag, ::size_t __slen, const char *__restrict __format, ...) throw();
}
extern "C"
{
  extern int __vsprintf_chk(char *__restrict __s, int __flag, ::size_t __slen, const char *__restrict __format, ::__gnuc_va_list __ap) throw();
}
extern "C"
{
  extern inline __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) int sprintf(char *__restrict __s, const char *__restrict __fmt, ...) throw()
  {
    return __builtin___sprintf_chk(__s, 2 - 1, __builtin_object_size(__s, 2 > 1), __fmt, __builtin_va_arg_pack());
  }
}
extern "C"
{
  extern inline __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) int vsprintf(char *__restrict __s, const char *__restrict __fmt, ::__gnuc_va_list __ap) throw()
  {
    return __builtin___vsprintf_chk(__s, 2 - 1, __builtin_object_size(__s, 2 > 1), __fmt, __ap);
  }
}
extern "C"
{
  extern int __snprintf_chk(char *__restrict __s, ::size_t __n, int __flag, ::size_t __slen, const char *__restrict __format, ...) throw();
}
extern "C"
{
  extern int __vsnprintf_chk(char *__restrict __s, ::size_t __n, int __flag, ::size_t __slen, const char *__restrict __format, ::__gnuc_va_list __ap) throw();
}
extern "C"
{
  extern inline __attribute__((__format__(__printf__, 3, 4))) __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) int snprintf(char *__restrict __s, ::size_t __n, const char *__restrict __fmt, ...) throw()
  {
    return __builtin___snprintf_chk(__s, __n, 2 - 1, __builtin_object_size(__s, 2 > 1), __fmt, __builtin_va_arg_pack());
  }
}
extern "C"
{
  extern inline __attribute__((__format__(__printf__, 3, 0))) __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) int vsnprintf(char *__restrict __s, ::size_t __n, const char *__restrict __fmt, ::__gnuc_va_list __ap) throw()
  {
    return __builtin___vsnprintf_chk(__s, __n, 2 - 1, __builtin_object_size(__s, 2 > 1), __fmt, __ap);
  }
}
extern "C"
{
  extern int __fprintf_chk(::FILE *__restrict __stream, int __flag, const char *__restrict __format, ...);
}
extern "C"
{
  extern int __printf_chk(int __flag, const char *__restrict __format, ...);
}
extern "C"
{
  extern int __vfprintf_chk(::FILE *__restrict __stream, int __flag, const char *__restrict __format, ::__gnuc_va_list __ap);
}
extern "C"
{
  extern int __vprintf_chk(int __flag, const char *__restrict __format, ::__gnuc_va_list __ap);
}
extern "C"
{
  extern inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) int fprintf(::FILE *__restrict __stream, const char *__restrict __fmt, ...)
  {
    return ::__fprintf_chk(__stream, 2 - 1, __fmt, __builtin_va_arg_pack());
  }
}
extern "C"
{
  extern inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) int printf(const char *__restrict __fmt, ...)
  {
    return ::__printf_chk(2 - 1, __fmt, __builtin_va_arg_pack());
  }
}
extern "C"
{
  extern inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) int vprintf(const char *__restrict __fmt, ::__gnuc_va_list __ap)
  {
    return ::__vfprintf_chk(::stdout, 2 - 1, __fmt, __ap);
  }
}
extern "C"
{
  extern inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) int vfprintf(::FILE *__restrict __stream, const char *__restrict __fmt, ::__gnuc_va_list __ap)
  {
    return ::__vfprintf_chk(__stream, 2 - 1, __fmt, __ap);
  }
}
extern "C"
{
  extern int __dprintf_chk(int __fd, int __flag, const char *__restrict __fmt, ...) __attribute__((__format__(__printf__, 3, 4)));
}
extern "C"
{
  extern int __vdprintf_chk(int __fd, int __flag, const char *__restrict __fmt, ::__gnuc_va_list __arg) __attribute__((__format__(__printf__, 3, 0)));
}
extern "C"
{
  extern inline __attribute__((__format__(__printf__, 2, 3))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) int dprintf(int __fd, const char *__restrict __fmt, ...)
  {
    return ::__dprintf_chk(__fd, 2 - 1, __fmt, __builtin_va_arg_pack());
  }
}
extern "C"
{
  extern inline __attribute__((__format__(__printf__, 2, 0))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) int vdprintf(int __fd, const char *__restrict __fmt, ::__gnuc_va_list __ap)
  {
    return ::__vdprintf_chk(__fd, 2 - 1, __fmt, __ap);
  }
}
extern "C"
{
  extern int __asprintf_chk(char **__restrict __ptr, int __flag, const char *__restrict __fmt, ...) throw() __attribute__((__format__(__printf__, 3, 4))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int __vasprintf_chk(char **__restrict __ptr, int __flag, const char *__restrict __fmt, ::__gnuc_va_list __arg) throw() __attribute__((__format__(__printf__, 3, 0))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int __obstack_printf_chk(::obstack *__restrict __obstack, int __flag, const char *__restrict __format, ...) throw() __attribute__((__format__(__printf__, 3, 4)));
}
extern "C"
{
  extern int __obstack_vprintf_chk(::obstack *__restrict __obstack, int __flag, const char *__restrict __format, ::__gnuc_va_list __args) throw() __attribute__((__format__(__printf__, 3, 0)));
}
extern "C"
{
  extern inline __attribute__((__format__(__printf__, 2, 3))) __attribute__((__warn_unused_result__)) __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) int asprintf(char **__restrict __ptr, const char *__restrict __fmt, ...) throw()
  {
    return ::__asprintf_chk(__ptr, 2 - 1, __fmt, __builtin_va_arg_pack());
  }
}
extern "C"
{
  extern inline __attribute__((__format__(__printf__, 2, 3))) __attribute__((__warn_unused_result__)) __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) int __asprintf(char **__restrict __ptr, const char *__restrict __fmt, ...) throw()
  {
    return ::__asprintf_chk(__ptr, 2 - 1, __fmt, __builtin_va_arg_pack());
  }
}
extern "C"
{
  extern inline __attribute__((__format__(__printf__, 2, 3))) __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) int obstack_printf(::obstack *__restrict __obstack, const char *__restrict __fmt, ...) throw()
  {
    return ::__obstack_printf_chk(__obstack, 2 - 1, __fmt, __builtin_va_arg_pack());
  }
}
extern "C"
{
  extern inline __attribute__((__format__(__printf__, 2, 0))) __attribute__((__warn_unused_result__)) __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) int vasprintf(char **__restrict __ptr, const char *__restrict __fmt, ::__gnuc_va_list __ap) throw()
  {
    return ::__vasprintf_chk(__ptr, 2 - 1, __fmt, __ap);
  }
}
extern "C"
{
  extern inline __attribute__((__format__(__printf__, 2, 0))) __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) int obstack_vprintf(::obstack *__restrict __obstack, const char *__restrict __fmt, ::__gnuc_va_list __ap) throw()
  {
    return ::__obstack_vprintf_chk(__obstack, 2 - 1, __fmt, __ap);
  }
}
extern "C"
{
  extern char *__gets_chk(char *__str, ::size_t) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern char *__gets_warn(char *__str) __asm("""gets") __attribute__((__warn_unused_result__)) __attribute__((__warning__("please use fgets or getline instead, gets can't ""specify buffer size")));
}
extern "C"
{
  extern inline __attribute__((__warn_unused_result__)) __attribute__((__deprecated__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) char *gets(char *__str)
  {
    if (__builtin_object_size(__str, 2 > 1) != (::size_t) -1)
      {
        return ::__gets_chk(__str, __builtin_object_size(__str, 2 > 1));
      }
    return ::__gets_warn(__str);
  }
}
extern "C"
{
  extern char *__fgets_chk(char *__restrict __s, ::size_t __size, int __n, ::FILE *__restrict __stream) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern char *__fgets_alias(char *__restrict __s, int __n, ::FILE *__restrict __stream) __asm("""fgets") __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern char *__fgets_chk_warn(char *__restrict __s, ::size_t __size, int __n, ::FILE *__restrict __stream) __asm("""__fgets_chk") __attribute__((__warn_unused_result__)) __attribute__((__warning__("fgets called with bigger size than length ""of destination buffer")));
}
extern "C"
{
  extern inline __attribute__((__warn_unused_result__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) char *fgets(char *__restrict __s, int __n, ::FILE *__restrict __stream)
  {
    if (__builtin_object_size(__s, 2 > 1) != (::size_t) -1)
      {
        if (!__builtin_constant_p(__n) || __n <= 0)
          {
            return ::__fgets_chk(__s, __builtin_object_size(__s, 2 > 1), __n, __stream);
          }
        if ((::size_t)__n > __builtin_object_size(__s, 2 > 1))
          {
            return ::__fgets_chk_warn(__s, __builtin_object_size(__s, 2 > 1), __n, __stream);
          }
      }
    return ::__fgets_alias(__s, __n, __stream);
  }
}
extern "C"
{
  extern ::size_t __fread_chk(void *__restrict __ptr, ::size_t __ptrlen, ::size_t __size, ::size_t __n, ::FILE *__restrict __stream) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern ::size_t __fread_alias(void *__restrict __ptr, ::size_t __size, ::size_t __n, ::FILE *__restrict __stream) __asm("""fread") __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern ::size_t __fread_chk_warn(void *__restrict __ptr, ::size_t __ptrlen, ::size_t __size, ::size_t __n, ::FILE *__restrict __stream) __asm("""__fread_chk") __attribute__((__warn_unused_result__)) __attribute__((__warning__("fread called with bigger size * nmemb than length ""of destination buffer")));
}
extern "C"
{
  extern inline __attribute__((__warn_unused_result__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) ::size_t fread(void *__restrict __ptr, ::size_t __size, ::size_t __n, ::FILE *__restrict __stream)
  {
    if (__builtin_object_size(__ptr, 0) != (::size_t) -1)
      {
        if ((!__builtin_constant_p(__size) || !__builtin_constant_p(__n)) || (__size | __n) >= (::size_t)1 << 8 * sizeof(::size_t) / 2)
          {
            return ::__fread_chk(__ptr, __builtin_object_size(__ptr, 0), __size, __n, __stream);
          }
        if (__size * __n > __builtin_object_size(__ptr, 0))
          {
            return ::__fread_chk_warn(__ptr, __builtin_object_size(__ptr, 0), __size, __n, __stream);
          }
      }
    return ::__fread_alias(__ptr, __size, __n, __stream);
  }
}
extern "C"
{
  extern char *__fgets_unlocked_chk(char *__restrict __s, ::size_t __size, int __n, ::FILE *__restrict __stream) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern char *__fgets_unlocked_alias(char *__restrict __s, int __n, ::FILE *__restrict __stream) __asm("""fgets_unlocked") __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern char *__fgets_unlocked_chk_warn(char *__restrict __s, ::size_t __size, int __n, ::FILE *__restrict __stream) __asm("""__fgets_unlocked_chk") __attribute__((__warn_unused_result__)) __attribute__((__warning__("fgets_unlocked called with bigger size than length ""of destination buffer")));
}
extern "C"
{
  extern inline __attribute__((__warn_unused_result__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) char *fgets_unlocked(char *__restrict __s, int __n, ::FILE *__restrict __stream)
  {
    if (__builtin_object_size(__s, 2 > 1) != (::size_t) -1)
      {
        if (!__builtin_constant_p(__n) || __n <= 0)
          {
            return ::__fgets_unlocked_chk(__s, __builtin_object_size(__s, 2 > 1), __n, __stream);
          }
        if ((::size_t)__n > __builtin_object_size(__s, 2 > 1))
          {
            return ::__fgets_unlocked_chk_warn(__s, __builtin_object_size(__s, 2 > 1), __n, __stream);
          }
      }
    return ::__fgets_unlocked_alias(__s, __n, __stream);
  }
}
extern "C"
{
  extern ::size_t __fread_unlocked_chk(void *__restrict __ptr, ::size_t __ptrlen, ::size_t __size, ::size_t __n, ::FILE *__restrict __stream) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern ::size_t __fread_unlocked_alias(void *__restrict __ptr, ::size_t __size, ::size_t __n, ::FILE *__restrict __stream) __asm("""fread_unlocked") __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern ::size_t __fread_unlocked_chk_warn(void *__restrict __ptr, ::size_t __ptrlen, ::size_t __size, ::size_t __n, ::FILE *__restrict __stream) __asm("""__fread_unlocked_chk") __attribute__((__warn_unused_result__)) __attribute__((__warning__("fread_unlocked called with bigger size * nmemb than ""length of destination buffer")));
}
extern "C"
{
  extern inline __attribute__((__warn_unused_result__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) ::size_t fread_unlocked(void *__restrict __ptr, ::size_t __size, ::size_t __n, ::FILE *__restrict __stream)
  {
    if (__builtin_object_size(__ptr, 0) != (::size_t) -1)
      {
        if ((!__builtin_constant_p(__size) || !__builtin_constant_p(__n)) || (__size | __n) >= (::size_t)1 << 8 * sizeof(::size_t) / 2)
          {
            return ::__fread_unlocked_chk(__ptr, __builtin_object_size(__ptr, 0), __size, __n, __stream);
          }
        if (__size * __n > __builtin_object_size(__ptr, 0))
          {
            return ::__fread_unlocked_chk_warn(__ptr, __builtin_object_size(__ptr, 0), __size, __n, __stream);
          }
      }
    if (((__builtin_constant_p(__size) && __builtin_constant_p(__n)) && (__size | __n) < (::size_t)1 << 8 * sizeof(::size_t) / 2) && __size * __n <= 8)
      {
        ::size_t __cnt(__size * __n);
        char *__cptr((char *)__ptr);
        if (__cnt == 0)
          {
            return 0;
          }
        for (; __cnt > 0;  --__cnt)
          {
            int __c(__builtin_expect((*__stream)._IO_read_ptr >= (*__stream)._IO_read_end, 0) ? ::__uflow(__stream) : *((unsigned char *)(*__stream)._IO_read_ptr++));
            if (__c ==  -1)
              {
                break;
              }
            *__cptr++ = __c;
          }
        return (__cptr - (char *)__ptr) / __size;
      }
    return ::__fread_unlocked_alias(__ptr, __size, __n, __stream);
  }
}
extern "C"
{
  extern char *optarg;
}
extern "C"
{
  extern int optind;
}
extern "C"
{
  extern int opterr;
}
extern "C"
{
  extern int optopt;
}
extern "C"
{
  extern int getopt(int ___argc, char *const *___argv, const char *__shortopts) throw() __attribute__((__nonnull__(2, 3)));
}
struct  option
{
    const char *name;
    int has_arg;
    int *flag;
    int val;
};
extern "C"
{
  extern int getopt_long(int ___argc, char *const *___argv, const char *__shortopts, const ::option *__longopts, int *__longind) throw() __attribute__((__nonnull__(2, 3)));
}
extern "C"
{
  extern int getopt_long_only(int ___argc, char *const *___argv, const char *__shortopts, const ::option *__longopts, int *__longind) throw() __attribute__((__nonnull__(2, 3)));
}
class  IAlignerParameters
{
  public:
    virtual void printUsage() const  = 0 ;
    virtual int processArgument(int argc, char **argv) = 0 ;
    virtual const char *getLastError() const  = 0 ;
    virtual int getForkId() const  = 0 ;
    virtual void setForkId(int forkId) = 0 ;
  protected:
    inline ~IAlignerParameters()
    {
    }
    inline IAlignerParameters()
    {
    }
  public:
};
class  AbstractAlignerParameters : public ::IAlignerParameters
{
  public:
    AbstractAlignerParameters();
    virtual ~AbstractAlignerParameters();
    virtual const char *getLastError() const ;
    virtual int getForkId() const ;
    virtual void setForkId(int forkId);
  protected:
    void setForkCount(const int forkCount, const int *forkWeights  = (0L));
    void setLastError(const char *error);
    static void printFormattedUsage(const char *header, const char *text);
    static int callGetOpt(int argc, char **argv, ::option *arguments);
  private:
    char lastError[500L];
    int forkId;
    const ::option *arguments;
  public:
};
struct  aligner_capabilities_t
{
    bool customize_first_column;
    bool customize_first_row;
    bool dispatch_last_column;
    bool dispatch_last_row;
    bool dispatch_last_cell;
    bool dispatch_special_column;
    bool dispatch_special_row;
    bool dispatch_best_score;
    bool dispatch_scores;
    bool dispatch_block_scores;
    bool process_partition;
    bool variable_penalties;
    bool block_pruning;
    bool needleman_wunsch;
    bool smith_waterman;
    bool fork_processes;
    int maximum_seq0_len;
    int maximum_seq1_len;
    inline aligner_capabilities_t()
    {
      ::memset(this, 0, sizeof(::aligner_capabilities_t));
    }
};
class Grid;
class  Grid
{
  public:
    Grid(::Partition partition);
    virtual ~Grid();
    void setBlockHeight(int blockHeight);
    void setBlockWidth(int blockWidth);
    void splitGridVertically(int count);
    void splitGridHorizontally(int count);
    void splitGridVertically(int count, int *splits);
    void splitGridHorizontally(int count, int *splits);
    void getBlockPosition(int bx, int by, int *i0, int *j0, int *i1  = (0L), int *j1  = (0L)) const ;
    void setMinBlockSize(int minBlockWidth, int minBlockHeight);
    void setAdjustment(int adjustment);
    int getBlockAdjustment(int bx, int by) const ;
    int getGridWidth() const ;
    int getGridHeight() const ;
    int getBlockWidth(int bx, int by) const ;
    int getBlockHeight(int bx, int by) const ;
    int getHeight() const ;
    int getWidth() const ;
    const int *getBlockSplitHorizontal() const ;
    const int *getBlockSplitVertical() const ;
  private:
    int blockWidth;
    int blockHeight;
    int adjustment;
    int minBlockWidth;
    int minBlockHeight;
    int blockCountHorizontal;
    int *blockSplitHorizontal;
    int blockCountVertical;
    int *blockSplitVertical;
    int width;
    int height;
    ::Partition partition;
    void getBlockPositionH(int bx, int by, int *j0, int *j1) const ;
    void getBlockPositionV(int bx, int by, int *i0, int *i1) const ;
  public:
};
class  IAligner
{
  public:
    virtual ::aligner_capabilities_t getCapabilities() = 0 ;
    virtual void setManager(::IManager *manager) = 0 ;
    virtual const int *getForkWeights() = 0 ;
    virtual ::IAlignerParameters *getParameters() = 0 ;
    virtual const ::score_params_t *getScoreParameters() = 0 ;
    virtual void initialize() = 0 ;
    virtual void setSequences(const char *seq0, const char *seq1, int seq0_len, int seq1_len) = 0 ;
    virtual void unsetSequences() = 0 ;
    virtual void alignPartition(::Partition partition) = 0 ;
    virtual void finalize() = 0 ;
    virtual ::match_result_t matchLastColumn(const ::cell_t *buffer, const ::cell_t *base, int len, int goalScore) = 0 ;
    virtual const ::Grid *getGrid() const  = 0 ;
    virtual void clearStatistics() = 0 ;
    virtual void printInitialStatistics(::FILE *file) = 0 ;
    virtual void printStageStatistics(::FILE *file) = 0 ;
    virtual void printFinalStatistics(::FILE *file) = 0 ;
    virtual void printStatistics(::FILE *file) = 0 ;
    virtual const char *getProgressString() const  = 0 ;
    virtual long long int getProcessedCells() = 0 ;
  protected:
    inline ~IAligner()
    {
    }
    inline IAligner()
    {
    }
  public:
};
class AbstractAligner;
namespace std __attribute__((__visibility__("default"))) {
  template < typename __type_tpl__param_1_0__ >
  class allocator;
  template <>
  class allocator<void>;
  template < typename __type_tpl__param_1_0__, typename __type_tpl__param_1_1__ >
  struct uses_allocator;
  template < typename _CharT >
  struct char_traits;
  template <>
  struct char_traits<char>;
  template <>
  struct char_traits<wchar_t>;
  inline namespace __cxx11 __attribute__((__abi_tag__("cxx11"))) {
    template < typename _CharT, typename _Traits = ::std::char_traits<_CharT>, typename _Alloc = ::std::allocator<_CharT> >
    class basic_string;
    typedef ::std::__cxx11::basic_string<char> string;
    typedef ::std::__cxx11::basic_string<wchar_t> wstring;
  }
  void __throw_bad_exception() __attribute__((__noreturn__));
  void __throw_bad_alloc() __attribute__((__noreturn__));
  void __throw_bad_cast() __attribute__((__noreturn__));
  void __throw_bad_typeid() __attribute__((__noreturn__));
  void __throw_logic_error(const char *) __attribute__((__noreturn__));
  void __throw_domain_error(const char *) __attribute__((__noreturn__));
  void __throw_invalid_argument(const char *) __attribute__((__noreturn__));
  void __throw_length_error(const char *) __attribute__((__noreturn__));
  void __throw_out_of_range(const char *) __attribute__((__noreturn__));
  void __throw_out_of_range_fmt(const char *, ...) __attribute__((__noreturn__)) __attribute__((__format__(__gnu_printf__, 1, 2)));
  void __throw_runtime_error(const char *) __attribute__((__noreturn__));
  void __throw_range_error(const char *) __attribute__((__noreturn__));
  void __throw_overflow_error(const char *) __attribute__((__noreturn__));
  void __throw_underflow_error(const char *) __attribute__((__noreturn__));
  void __throw_ios_failure(const char *) __attribute__((__noreturn__));
  void __throw_system_error(int) __attribute__((__noreturn__));
  void __throw_future_error(int) __attribute__((__noreturn__));
  void __throw_bad_function_call() __attribute__((__noreturn__));
  struct  __true_type
  {
  };
  struct  __false_type
  {
  };
  template < bool __nontype_tpl_param_1_0__ >
  struct  __truth_type
  {
      typedef ::std::__false_type __type;
  };
  template <>
  struct  __truth_type<true>
  {
      typedef ::std::__true_type __type;
  };
  template < typename _Sp, typename _Tp >
  struct  __traitor
  {
      enum mcc_enum_anon_6
      {
        __value = bool(_Sp::__value) || bool(_Tp::__value)
      };
      typedef typename ::std::__truth_type< ::std::__traitor<_Sp, _Tp>::__value>::__type __type;
  };
  template < typename __type_tpl__param_1_0__, typename __type_tpl__param_1_1__ >
  struct  __are_same
  {
      enum mcc_enum_anon_7
      {
        __value = 0
      };
      typedef ::std::__false_type __type;
  };
  template < typename _Tp >
  struct  __are_same<_Tp, _Tp>
  {
      enum mcc_enum_anon_8
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template < typename _Tp >
  struct  __is_void
  {
      enum mcc_enum_anon_9
      {
        __value = 0
      };
      typedef ::std::__false_type __type;
  };
  template <>
  struct  __is_void<void>
  {
      enum mcc_enum_anon_10
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template < typename _Tp >
  struct  __is_integer
  {
      enum mcc_enum_anon_11
      {
        __value = 0
      };
      typedef ::std::__false_type __type;
  };
  template <>
  struct  __is_integer<bool>
  {
      enum mcc_enum_anon_12
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template <>
  struct  __is_integer<char>
  {
      enum mcc_enum_anon_13
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template <>
  struct  __is_integer<signed char>
  {
      enum mcc_enum_anon_14
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template <>
  struct  __is_integer<unsigned char>
  {
      enum mcc_enum_anon_15
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template <>
  struct  __is_integer<wchar_t>
  {
      enum mcc_enum_anon_16
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template <>
  struct  __is_integer<short int>
  {
      enum mcc_enum_anon_17
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template <>
  struct  __is_integer<unsigned short int>
  {
      enum mcc_enum_anon_18
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template <>
  struct  __is_integer<int>
  {
      enum mcc_enum_anon_19
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template <>
  struct  __is_integer<unsigned int>
  {
      enum mcc_enum_anon_20
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template <>
  struct  __is_integer<long int>
  {
      enum mcc_enum_anon_21
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template <>
  struct  __is_integer<unsigned long int>
  {
      enum mcc_enum_anon_22
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template <>
  struct  __is_integer<long long int>
  {
      enum mcc_enum_anon_23
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template <>
  struct  __is_integer<unsigned long long int>
  {
      enum mcc_enum_anon_24
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template <>
  struct  __is_integer<__int128>
  {
      enum mcc_enum_anon_25
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template <>
  struct  __is_integer<unsigned __int128>
  {
      enum mcc_enum_anon_26
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template < typename _Tp >
  struct  __is_floating
  {
      enum mcc_enum_anon_27
      {
        __value = 0
      };
      typedef ::std::__false_type __type;
  };
  template <>
  struct  __is_floating<float>
  {
      enum mcc_enum_anon_28
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template <>
  struct  __is_floating<double>
  {
      enum mcc_enum_anon_29
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template <>
  struct  __is_floating<long double>
  {
      enum mcc_enum_anon_30
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template < typename _Tp >
  struct  __is_pointer
  {
      enum mcc_enum_anon_31
      {
        __value = 0
      };
      typedef ::std::__false_type __type;
  };
  template < typename _Tp >
  struct  __is_pointer<_Tp *>
  {
      enum mcc_enum_anon_32
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template < typename _Tp >
  struct  __is_arithmetic : ::std::__traitor< ::std::__is_integer<_Tp>, ::std::__is_floating<_Tp> >
  {
  };
  template < typename _Tp >
  struct  __is_scalar : ::std::__traitor< ::std::__is_arithmetic<_Tp>, ::std::__is_pointer<_Tp> >
  {
  };
  template < typename _Tp >
  struct  __is_char
  {
      enum mcc_enum_anon_33
      {
        __value = 0
      };
      typedef ::std::__false_type __type;
  };
  template <>
  struct  __is_char<char>
  {
      enum mcc_enum_anon_34
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template <>
  struct  __is_char<wchar_t>
  {
      enum mcc_enum_anon_35
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template < typename _Tp >
  struct  __is_byte
  {
      enum mcc_enum_anon_36
      {
        __value = 0
      };
      typedef ::std::__false_type __type;
  };
  template <>
  struct  __is_byte<char>
  {
      enum mcc_enum_anon_37
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template <>
  struct  __is_byte<signed char>
  {
      enum mcc_enum_anon_38
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template <>
  struct  __is_byte<unsigned char>
  {
      enum mcc_enum_anon_39
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template < typename _Tp >
  struct  __is_move_iterator
  {
      enum mcc_enum_anon_40
      {
        __value = 0
      };
      typedef ::std::__false_type __type;
  };
  template < typename _Iterator >
  inline _Iterator __miter_base(_Iterator __it);
  template < typename _Iterator >
  inline _Iterator __miter_base(_Iterator __it)
  {
    return __it;
  }
}
namespace __gnu_cxx __attribute__((__visibility__("default"))) {
  template < bool __nontype_tpl_param_1_0__, typename __type_tpl__param_1_1__ >
  struct  __enable_if
  {
  };
  template < typename _Tp >
  struct  __enable_if<true, _Tp>
  {
      typedef _Tp __type;
  };
  template < bool _Cond, typename _Iftrue, typename _Iffalse >
  struct  __conditional_type
  {
      typedef _Iftrue __type;
  };
  template < typename _Iftrue, typename _Iffalse >
  struct  __conditional_type<false, _Iftrue, _Iffalse>
  {
      typedef _Iffalse __type;
  };
  template < typename _Tp >
  struct  __add_unsigned
  {
    private:
      typedef ::__gnu_cxx::__enable_if<std::__is_integer<_Tp>::__value, _Tp> __if_type;
    public:
      typedef typename ::__gnu_cxx::__enable_if<std::__is_integer<_Tp>::__value, _Tp>::__type __type;
  };
  template <>
  struct  __add_unsigned<char>
  {
      typedef unsigned char __type;
  };
  template <>
  struct  __add_unsigned<signed char>
  {
      typedef unsigned char __type;
  };
  template <>
  struct  __add_unsigned<short int>
  {
      typedef unsigned short int __type;
  };
  template <>
  struct  __add_unsigned<int>
  {
      typedef unsigned int __type;
  };
  template <>
  struct  __add_unsigned<long int>
  {
      typedef unsigned long int __type;
  };
  template <>
  struct  __add_unsigned<long long int>
  {
      typedef unsigned long long int __type;
  };
  template <>
  struct __add_unsigned<bool>;
  template <>
  struct __add_unsigned<wchar_t>;
  template < typename _Tp >
  struct  __remove_unsigned
  {
    private:
      typedef ::__gnu_cxx::__enable_if<std::__is_integer<_Tp>::__value, _Tp> __if_type;
    public:
      typedef typename ::__gnu_cxx::__enable_if<std::__is_integer<_Tp>::__value, _Tp>::__type __type;
  };
  template <>
  struct  __remove_unsigned<char>
  {
      typedef signed char __type;
  };
  template <>
  struct  __remove_unsigned<unsigned char>
  {
      typedef signed char __type;
  };
  template <>
  struct  __remove_unsigned<unsigned short int>
  {
      typedef short int __type;
  };
  template <>
  struct  __remove_unsigned<unsigned int>
  {
      typedef int __type;
  };
  template <>
  struct  __remove_unsigned<unsigned long int>
  {
      typedef long int __type;
  };
  template <>
  struct  __remove_unsigned<unsigned long long int>
  {
      typedef long long int __type;
  };
  template <>
  struct __remove_unsigned<bool>;
  template <>
  struct __remove_unsigned<wchar_t>;
  template < typename _Type >
  inline bool __is_null_pointer(_Type *__ptr);
  template < typename _Type >
  inline bool __is_null_pointer(_Type *__ptr)
  {
    return __ptr == 0;
  }
  template < typename _Type >
  inline bool __is_null_pointer(_Type);
  template < typename _Type >
  inline bool __is_null_pointer(_Type)
  {
    return false;
  }
  template < typename _Tp, bool __nontype_tpl_param_1_1__ = std::__is_integer<_Tp>::__value >
  struct  __promote
  {
      typedef double __type;
  };
  template < typename _Tp >
  struct  __promote<_Tp, false>
  {
  };
 /* Instantiation of class template '::std::__is_integer<long double>' */ 
  template <>
  struct  __promote<long double>
  {
      typedef long double __type;
  };
 /* Instantiation of class template '::std::__is_integer<double>' */ 
  template <>
  struct  __promote<double>
  {
      typedef double __type;
  };
 /* Instantiation of class template '::std::__is_integer<float>' */ 
  template <>
  struct  __promote<float>
  {
      typedef float __type;
  };
  template < typename _Tp, typename _Up, typename _Tp2 = typename ::__gnu_cxx::__promote<_Tp>::__type, typename _Up2 = typename ::__gnu_cxx::__promote<_Up>::__type >
  struct  __promote_2
  {
      typedef __typeof__(_Tp2() + _Up2()) __type;
  };
  template < typename _Tp, typename _Up, typename _Vp, typename _Tp2 = typename ::__gnu_cxx::__promote<_Tp>::__type, typename _Up2 = typename ::__gnu_cxx::__promote<_Up>::__type, typename _Vp2 = typename ::__gnu_cxx::__promote<_Vp>::__type >
  struct  __promote_3
  {
      typedef __typeof__(_Tp2() + _Up2() + _Vp2()) __type;
  };
  template < typename _Tp, typename _Up, typename _Vp, typename _Wp, typename _Tp2 = typename ::__gnu_cxx::__promote<_Tp>::__type, typename _Up2 = typename ::__gnu_cxx::__promote<_Up>::__type, typename _Vp2 = typename ::__gnu_cxx::__promote<_Vp>::__type, typename _Wp2 = typename ::__gnu_cxx::__promote<_Wp>::__type >
  struct  __promote_4
  {
      typedef __typeof__(_Tp2() + _Up2() + _Vp2() + _Wp2()) __type;
  };
  template < typename _Value >
  struct  __numeric_traits_integer
  {
      static const _Value __min = ((_Value) -1 < 0 ? (_Value)1 << (sizeof(_Value) * 8 - ((_Value) -1 < 0)) : (_Value)0);
      static const _Value __max = ((_Value) -1 < 0 ? ((((_Value)1 << (sizeof(_Value) * 8 - ((_Value) -1 < 0) - 1)) - 1) << 1) + 1 : ~((_Value)0));
      static const bool __is_signed = (_Value) -1 < 0;
      static const int __digits = sizeof(_Value) * 8 - ((_Value) -1 < 0);
  };
  template < typename _Value >
  const _Value __numeric_traits_integer<_Value>::__min;
  template < typename _Value >
  const _Value __numeric_traits_integer<_Value>::__max;
  template < typename _Value >
  const bool __numeric_traits_integer<_Value>::__is_signed;
  template < typename _Value >
  const int __numeric_traits_integer<_Value>::__digits;
  template < typename _Value >
  struct  __numeric_traits_floating
  {
      static const int __max_digits10 = 2 + (std::__are_same<_Value, float>::__value ? 24 : std::__are_same<_Value, double>::__value ? 53 : 64) * 643L / 2136;
      static const bool __is_signed = true;
      static const int __digits10 = std::__are_same<_Value, float>::__value ? 6 : std::__are_same<_Value, double>::__value ? 15 : 18;
      static const int __max_exponent10 = std::__are_same<_Value, float>::__value ? 38 : std::__are_same<_Value, double>::__value ? 308 : 4932;
  };
  template < typename _Value >
  const int __numeric_traits_floating<_Value>::__max_digits10;
  template < typename _Value >
  const bool __numeric_traits_floating<_Value>::__is_signed;
  template < typename _Value >
  const int __numeric_traits_floating<_Value>::__digits10;
  template < typename _Value >
  const int __numeric_traits_floating<_Value>::__max_exponent10;
  template < typename _Value >
  struct  __numeric_traits : ::__gnu_cxx::__conditional_type<std::__is_integer<_Value>::__value, ::__gnu_cxx::__numeric_traits_integer<_Value>, ::__gnu_cxx::__numeric_traits_floating<_Value> >::__type
  {
  };
}
namespace std __attribute__((__visibility__("default"))) {
  template < typename _Tp >
  inline _Tp *__addressof(_Tp &__r);
  template < typename _Tp >
  inline _Tp *__addressof(_Tp &__r)
  {
    return __builtin_addressof(__r);
  }
  template < typename _Tp >
  inline void swap(_Tp &__a, _Tp &__b);
  template < typename _Tp >
  inline void swap(_Tp &__a, _Tp &__b)
  {
    _Tp __tmp = (__a);
    __a = __b;
    __b = __tmp;
  }
  template < typename _Tp, ::std::size_t _Nm >
  inline void swap(_Tp (&__a)[_Nm], _Tp (&__b)[_Nm]);
  template < typename _Tp, ::std::size_t _Nm >
  inline void swap(_Tp (&__a)[_Nm], _Tp (&__b)[_Nm])
  {
    for (::std::size_t __n(0); __n < _Nm;  ++__n)
      {
        swap(__a[__n], __b[__n]);
      }
  }
  template < typename _U1, typename _U2 >
  class  __pair_base
  {
  };
  template < typename _T1, typename _T2 >
  struct  pair : private ::std::__pair_base<_T1, _T2>
  {
      typedef _T1 first_type;
      typedef _T2 second_type;
      _T1 first;
      _T2 second;
      inline pair()
        : first(), second()
      {
      }
      inline pair(const _T1 &__a, const _T2 &__b)
        : first(__a), second(__b)
      {
      }
      template < typename _U1, typename _U2 >
      inline pair(const ::std::pair<_U1, _U2> &__p)
        : first(__p.first), second(__p.second)
      {
      }
  };
  template < typename _T1, typename _T2 >
  inline bool operator ==(const ::std::pair<_T1, _T2> &__x, const ::std::pair<_T1, _T2> &__y);
  template < typename _T1, typename _T2 >
  inline bool operator ==(const ::std::pair<_T1, _T2> &__x, const ::std::pair<_T1, _T2> &__y)
  {
    return __x.first == __y.first && __x.second == __y.second;
  }
  template < typename _T1, typename _T2 >
  inline bool operator <(const ::std::pair<_T1, _T2> &__x, const ::std::pair<_T1, _T2> &__y);
  template < typename _T1, typename _T2 >
  inline bool operator <(const ::std::pair<_T1, _T2> &__x, const ::std::pair<_T1, _T2> &__y)
  {
    return __x.first < __y.first || (!(__y.first < __x.first) && __x.second < __y.second);
  }
  template < typename _T1, typename _T2 >
  inline bool operator !=(const ::std::pair<_T1, _T2> &__x, const ::std::pair<_T1, _T2> &__y);
  template < typename _T1, typename _T2 >
  inline bool operator !=(const ::std::pair<_T1, _T2> &__x, const ::std::pair<_T1, _T2> &__y)
  {
    return !(__x == __y);
  }
  template < typename _T1, typename _T2 >
  inline bool operator >(const ::std::pair<_T1, _T2> &__x, const ::std::pair<_T1, _T2> &__y);
  template < typename _T1, typename _T2 >
  inline bool operator >(const ::std::pair<_T1, _T2> &__x, const ::std::pair<_T1, _T2> &__y)
  {
    return __y < __x;
  }
  template < typename _T1, typename _T2 >
  inline bool operator <=(const ::std::pair<_T1, _T2> &__x, const ::std::pair<_T1, _T2> &__y);
  template < typename _T1, typename _T2 >
  inline bool operator <=(const ::std::pair<_T1, _T2> &__x, const ::std::pair<_T1, _T2> &__y)
  {
    return !(__y < __x);
  }
  template < typename _T1, typename _T2 >
  inline bool operator >=(const ::std::pair<_T1, _T2> &__x, const ::std::pair<_T1, _T2> &__y);
  template < typename _T1, typename _T2 >
  inline bool operator >=(const ::std::pair<_T1, _T2> &__x, const ::std::pair<_T1, _T2> &__y)
  {
    return !(__x < __y);
  }
  template < typename _T1, typename _T2 >
  inline ::std::pair<_T1, _T2> make_pair(_T1 __x, _T2 __y);
  template < typename _T1, typename _T2 >
  inline ::std::pair<_T1, _T2> make_pair(_T1 __x, _T2 __y)
  {
    return ::std::pair<_T1, _T2>(__x, __y);
  }
  struct  input_iterator_tag
  {
  };
  struct  output_iterator_tag
  {
  };
  struct  forward_iterator_tag : ::std::input_iterator_tag
  {
  };
  struct  bidirectional_iterator_tag : ::std::forward_iterator_tag
  {
  };
  struct  random_access_iterator_tag : ::std::bidirectional_iterator_tag
  {
  };
  template < typename _Category, typename _Tp, typename _Distance = ::std::ptrdiff_t, typename _Pointer = _Tp *, typename _Reference = _Tp & >
  struct  iterator
  {
      typedef _Category iterator_category;
      typedef _Tp value_type;
      typedef _Distance difference_type;
      typedef _Pointer pointer;
      typedef _Reference reference;
  };
  template < typename _Iterator >
  struct  iterator_traits
  {
      typedef typename _Iterator::iterator_category iterator_category;
      typedef typename _Iterator::value_type value_type;
      typedef typename _Iterator::difference_type difference_type;
      typedef typename _Iterator::pointer pointer;
      typedef typename _Iterator::reference reference;
  };
  template < typename _Tp >
  struct  iterator_traits<_Tp *>
  {
      typedef ::std::random_access_iterator_tag iterator_category;
      typedef _Tp value_type;
      typedef ::std::ptrdiff_t difference_type;
      typedef _Tp *pointer;
      typedef _Tp &reference;
  };
  template < typename _Tp >
  struct  iterator_traits<const _Tp *>
  {
      typedef ::std::random_access_iterator_tag iterator_category;
      typedef _Tp value_type;
      typedef ::std::ptrdiff_t difference_type;
      typedef const _Tp *pointer;
      typedef const _Tp &reference;
  };
  template < typename _Iter >
  inline typename ::std::iterator_traits<_Iter>::iterator_category __iterator_category(const _Iter &);
  template < typename _Iter >
  inline typename ::std::iterator_traits<_Iter>::iterator_category __iterator_category(const _Iter &)
  {
    return typename ::std::iterator_traits<_Iter>::iterator_category();
  }
  template < typename _Iterator, bool _HasBase >
  struct  _Iter_base
  {
      typedef _Iterator iterator_type;
      static inline typename ::std::_Iter_base<_Iterator, _HasBase>::iterator_type _S_base(_Iterator __it)
      {
        return __it;
      }
  };
  template < typename _Iterator >
  struct  _Iter_base<_Iterator, true>
  {
      typedef typename _Iterator::iterator_type iterator_type;
      static inline typename ::std::_Iter_base<_Iterator, true>::iterator_type _S_base(_Iterator __it)
      {
        return __it.base();
      }
  };
  template < typename __type_tpl__param_1_0__ >
  struct _List_iterator;
  template < typename __type_tpl__param_1_0__ >
  struct _List_const_iterator;
  template < typename _InputIterator >
  inline typename ::std::iterator_traits<_InputIterator>::difference_type __distance(_InputIterator __first, _InputIterator __last, ::std::input_iterator_tag);
  template < typename _InputIterator >
  inline typename ::std::iterator_traits<_InputIterator>::difference_type __distance(_InputIterator __first, _InputIterator __last, ::std::input_iterator_tag)
  {
    typename ::std::iterator_traits<_InputIterator>::difference_type __n = 0;
    while (__first != __last)
      {
         ++__first;
         ++__n;
      }
    return __n;
  }
  template < typename _RandomAccessIterator >
  inline typename ::std::iterator_traits<_RandomAccessIterator>::difference_type __distance(_RandomAccessIterator __first, _RandomAccessIterator __last, ::std::random_access_iterator_tag);
  template < typename _RandomAccessIterator >
  inline typename ::std::iterator_traits<_RandomAccessIterator>::difference_type __distance(_RandomAccessIterator __first, _RandomAccessIterator __last, ::std::random_access_iterator_tag)
  {
    return __last - __first;
  }
  template < typename _Tp >
  ::std::ptrdiff_t __distance(::std::_List_iterator<_Tp>, ::std::_List_iterator<_Tp>, ::std::input_iterator_tag);
  template < typename _Tp >
  ::std::ptrdiff_t __distance(::std::_List_const_iterator<_Tp>, ::std::_List_const_iterator<_Tp>, ::std::input_iterator_tag);
  template < typename _InputIterator >
  inline typename ::std::iterator_traits<_InputIterator>::difference_type distance(_InputIterator __first, _InputIterator __last);
  template < typename _InputIterator >
  inline typename ::std::iterator_traits<_InputIterator>::difference_type distance(_InputIterator __first, _InputIterator __last)
  {
    return std::__distance(__first, __last, std::__iterator_category(__first));
  }
  template < typename _InputIterator, typename _Distance >
  inline void __advance(_InputIterator &__i, _Distance __n, ::std::input_iterator_tag);
  template < typename _InputIterator, typename _Distance >
  inline void __advance(_InputIterator &__i, _Distance __n, ::std::input_iterator_tag)
  {
    ;
    while (__n--)
      {
         ++__i;
      }
  }
  template < typename _BidirectionalIterator, typename _Distance >
  inline void __advance(_BidirectionalIterator &__i, _Distance __n, ::std::bidirectional_iterator_tag);
  template < typename _BidirectionalIterator, typename _Distance >
  inline void __advance(_BidirectionalIterator &__i, _Distance __n, ::std::bidirectional_iterator_tag)
  {
    if (__n > 0)
      {
        while (__n--)
          {
             ++__i;
          }
      }
    else
      {
        while (__n++)
          {
             --__i;
          }
      }
  }
  template < typename _RandomAccessIterator, typename _Distance >
  inline void __advance(_RandomAccessIterator &__i, _Distance __n, ::std::random_access_iterator_tag);
  template < typename _RandomAccessIterator, typename _Distance >
  inline void __advance(_RandomAccessIterator &__i, _Distance __n, ::std::random_access_iterator_tag)
  {
    __i += __n;
  }
  template < typename _InputIterator, typename _Distance >
  inline void advance(_InputIterator &__i, _Distance __n);
  template < typename _InputIterator, typename _Distance >
  inline void advance(_InputIterator &__i, _Distance __n)
  {
    typename ::std::iterator_traits<_InputIterator>::difference_type __d = __n;
    std::__advance(__i, __d, std::__iterator_category(__i));
  }
  template < typename _Iterator >
  class  reverse_iterator : public ::std::iterator<typename ::std::iterator_traits<_Iterator>::iterator_category, typename ::std::iterator_traits<_Iterator>::value_type, typename ::std::iterator_traits<_Iterator>::difference_type, typename ::std::iterator_traits<_Iterator>::pointer, typename ::std::iterator_traits<_Iterator>::reference>
  {
    protected:
      _Iterator current;
      typedef ::std::iterator_traits<_Iterator> __traits_type;
    public:
      typedef _Iterator iterator_type;
      typedef typename ::std::iterator_traits<_Iterator>::difference_type difference_type;
      typedef typename ::std::iterator_traits<_Iterator>::pointer pointer;
      typedef typename ::std::iterator_traits<_Iterator>::reference reference;
      inline reverse_iterator()
        : current()
      {
      }
      inline explicit reverse_iterator(typename ::std::reverse_iterator<_Iterator>::iterator_type __x)
        : current(__x)
      {
      }
      inline reverse_iterator(const ::std::reverse_iterator<_Iterator> &__x)
        : current(__x.current)
      {
      }
      template < typename _Iter >
      inline reverse_iterator(const ::std::reverse_iterator<_Iter> &__x)
        : current(__x.base())
      {
      }
      inline typename ::std::reverse_iterator<_Iterator>::iterator_type base() const 
      {
        return ::std::reverse_iterator<_Iterator>::current;
      }
      inline typename ::std::reverse_iterator<_Iterator>::reference operator *() const 
      {
        _Iterator __tmp = ::std::reverse_iterator<_Iterator>::current;
        return * --__tmp;
      }
      inline typename ::std::reverse_iterator<_Iterator>::pointer operator ->() const 
      {
        return std::__addressof((*this).operator *());
      }
      inline ::std::reverse_iterator<_Iterator> &operator ++()
      {
         --::std::reverse_iterator<_Iterator>::current;
        return *this;
      }
      inline ::std::reverse_iterator<_Iterator> operator ++(int)
      {
        ::std::reverse_iterator<_Iterator> __tmp = *this;
         --::std::reverse_iterator<_Iterator>::current;
        return __tmp;
      }
      inline ::std::reverse_iterator<_Iterator> &operator --()
      {
         ++::std::reverse_iterator<_Iterator>::current;
        return *this;
      }
      inline ::std::reverse_iterator<_Iterator> operator --(int)
      {
        ::std::reverse_iterator<_Iterator> __tmp = *this;
         ++::std::reverse_iterator<_Iterator>::current;
        return __tmp;
      }
      inline ::std::reverse_iterator<_Iterator> operator +(typename ::std::reverse_iterator<_Iterator>::difference_type __n) const 
      {
        return ::std::reverse_iterator<_Iterator>(::std::reverse_iterator<_Iterator>::current - __n);
      }
      inline ::std::reverse_iterator<_Iterator> &operator +=(typename ::std::reverse_iterator<_Iterator>::difference_type __n)
      {
        ::std::reverse_iterator<_Iterator>::current -= __n;
        return *this;
      }
      inline ::std::reverse_iterator<_Iterator> operator -(typename ::std::reverse_iterator<_Iterator>::difference_type __n) const 
      {
        return ::std::reverse_iterator<_Iterator>(::std::reverse_iterator<_Iterator>::current + __n);
      }
      inline ::std::reverse_iterator<_Iterator> &operator -=(typename ::std::reverse_iterator<_Iterator>::difference_type __n)
      {
        ::std::reverse_iterator<_Iterator>::current += __n;
        return *this;
      }
      inline typename ::std::reverse_iterator<_Iterator>::reference operator [](typename ::std::reverse_iterator<_Iterator>::difference_type __n) const 
      {
        return *(*this + __n);
      }
  };
  template < typename _Iterator >
  inline bool operator ==(const ::std::reverse_iterator<_Iterator> &__x, const ::std::reverse_iterator<_Iterator> &__y);
  template < typename _Iterator >
  inline bool operator ==(const ::std::reverse_iterator<_Iterator> &__x, const ::std::reverse_iterator<_Iterator> &__y)
  {
    return __x.base() == __y.base();
  }
  template < typename _Iterator >
  inline bool operator <(const ::std::reverse_iterator<_Iterator> &__x, const ::std::reverse_iterator<_Iterator> &__y);
  template < typename _Iterator >
  inline bool operator <(const ::std::reverse_iterator<_Iterator> &__x, const ::std::reverse_iterator<_Iterator> &__y)
  {
    return __y.base() < __x.base();
  }
  template < typename _Iterator >
  inline bool operator !=(const ::std::reverse_iterator<_Iterator> &__x, const ::std::reverse_iterator<_Iterator> &__y);
  template < typename _Iterator >
  inline bool operator !=(const ::std::reverse_iterator<_Iterator> &__x, const ::std::reverse_iterator<_Iterator> &__y)
  {
    return !(__x == __y);
  }
  template < typename _Iterator >
  inline bool operator >(const ::std::reverse_iterator<_Iterator> &__x, const ::std::reverse_iterator<_Iterator> &__y);
  template < typename _Iterator >
  inline bool operator >(const ::std::reverse_iterator<_Iterator> &__x, const ::std::reverse_iterator<_Iterator> &__y)
  {
    return __y < __x;
  }
  template < typename _Iterator >
  inline bool operator <=(const ::std::reverse_iterator<_Iterator> &__x, const ::std::reverse_iterator<_Iterator> &__y);
  template < typename _Iterator >
  inline bool operator <=(const ::std::reverse_iterator<_Iterator> &__x, const ::std::reverse_iterator<_Iterator> &__y)
  {
    return !(__y < __x);
  }
  template < typename _Iterator >
  inline bool operator >=(const ::std::reverse_iterator<_Iterator> &__x, const ::std::reverse_iterator<_Iterator> &__y);
  template < typename _Iterator >
  inline bool operator >=(const ::std::reverse_iterator<_Iterator> &__x, const ::std::reverse_iterator<_Iterator> &__y)
  {
    return !(__x < __y);
  }
  template < typename _IteratorL, typename _IteratorR >
  inline bool operator ==(const ::std::reverse_iterator<_IteratorL> &__x, const ::std::reverse_iterator<_IteratorR> &__y);
  template < typename _IteratorL, typename _IteratorR >
  inline bool operator ==(const ::std::reverse_iterator<_IteratorL> &__x, const ::std::reverse_iterator<_IteratorR> &__y)
  {
    return __x.base() == __y.base();
  }
  template < typename _IteratorL, typename _IteratorR >
  inline bool operator <(const ::std::reverse_iterator<_IteratorL> &__x, const ::std::reverse_iterator<_IteratorR> &__y);
  template < typename _IteratorL, typename _IteratorR >
  inline bool operator <(const ::std::reverse_iterator<_IteratorL> &__x, const ::std::reverse_iterator<_IteratorR> &__y)
  {
    return __y.base() < __x.base();
  }
  template < typename _IteratorL, typename _IteratorR >
  inline bool operator !=(const ::std::reverse_iterator<_IteratorL> &__x, const ::std::reverse_iterator<_IteratorR> &__y);
  template < typename _IteratorL, typename _IteratorR >
  inline bool operator !=(const ::std::reverse_iterator<_IteratorL> &__x, const ::std::reverse_iterator<_IteratorR> &__y)
  {
    return !(__x == __y);
  }
  template < typename _IteratorL, typename _IteratorR >
  inline bool operator >(const ::std::reverse_iterator<_IteratorL> &__x, const ::std::reverse_iterator<_IteratorR> &__y);
  template < typename _IteratorL, typename _IteratorR >
  inline bool operator >(const ::std::reverse_iterator<_IteratorL> &__x, const ::std::reverse_iterator<_IteratorR> &__y)
  {
    return __y < __x;
  }
  template < typename _IteratorL, typename _IteratorR >
  inline bool operator <=(const ::std::reverse_iterator<_IteratorL> &__x, const ::std::reverse_iterator<_IteratorR> &__y);
  template < typename _IteratorL, typename _IteratorR >
  inline bool operator <=(const ::std::reverse_iterator<_IteratorL> &__x, const ::std::reverse_iterator<_IteratorR> &__y)
  {
    return !(__y < __x);
  }
  template < typename _IteratorL, typename _IteratorR >
  inline bool operator >=(const ::std::reverse_iterator<_IteratorL> &__x, const ::std::reverse_iterator<_IteratorR> &__y);
  template < typename _IteratorL, typename _IteratorR >
  inline bool operator >=(const ::std::reverse_iterator<_IteratorL> &__x, const ::std::reverse_iterator<_IteratorR> &__y)
  {
    return !(__x < __y);
  }
  template < typename _Iterator >
  inline typename ::std::reverse_iterator<_Iterator>::difference_type operator -(const ::std::reverse_iterator<_Iterator> &__x, const ::std::reverse_iterator<_Iterator> &__y);
  template < typename _Iterator >
  inline typename ::std::reverse_iterator<_Iterator>::difference_type operator -(const ::std::reverse_iterator<_Iterator> &__x, const ::std::reverse_iterator<_Iterator> &__y)
  {
    return __y.base() - __x.base();
  }
  template < typename _IteratorL, typename _IteratorR >
  inline typename ::std::reverse_iterator<_IteratorL>::difference_type operator -(const ::std::reverse_iterator<_IteratorL> &__x, const ::std::reverse_iterator<_IteratorR> &__y);
  template < typename _IteratorL, typename _IteratorR >
  inline typename ::std::reverse_iterator<_IteratorL>::difference_type operator -(const ::std::reverse_iterator<_IteratorL> &__x, const ::std::reverse_iterator<_IteratorR> &__y)
  {
    return __y.base() - __x.base();
  }
  template < typename _Iterator >
  inline ::std::reverse_iterator<_Iterator> operator +(typename ::std::reverse_iterator<_Iterator>::difference_type __n, const ::std::reverse_iterator<_Iterator> &__x);
  template < typename _Iterator >
  inline ::std::reverse_iterator<_Iterator> operator +(typename ::std::reverse_iterator<_Iterator>::difference_type __n, const ::std::reverse_iterator<_Iterator> &__x)
  {
    return ::std::reverse_iterator<_Iterator>(__x.base() - __n);
  }
 /* Instantiation of class template '::std::iterator< ::std::output_iterator_tag, void, void, void, void>' */ 
  template < typename _Container >
  class  back_insert_iterator : public ::std::iterator< ::std::output_iterator_tag, void, void, void, void>
  {
    protected:
      _Container *container;
    public:
      typedef _Container container_type;
      inline explicit back_insert_iterator(_Container &__x)
        : container(std::__addressof(__x))
      {
      }
      inline ::std::back_insert_iterator<_Container> &operator =(typename _Container::const_reference __value)
      {
        ::std::back_insert_iterator<_Container>::container->push_back(__value);
        return *this;
      }
      inline ::std::back_insert_iterator<_Container> &operator *()
      {
        return *this;
      }
      inline ::std::back_insert_iterator<_Container> &operator ++()
      {
        return *this;
      }
      inline ::std::back_insert_iterator<_Container> operator ++(int)
      {
        return *this;
      }
  };
  template < typename _Container >
  inline ::std::back_insert_iterator<_Container> back_inserter(_Container &__x);
  template < typename _Container >
  inline ::std::back_insert_iterator<_Container> back_inserter(_Container &__x)
  {
    return ::std::back_insert_iterator<_Container>(__x);
  }
  template < typename _Container >
  class  front_insert_iterator : public ::std::iterator< ::std::output_iterator_tag, void, void, void, void>
  {
    protected:
      _Container *container;
    public:
      typedef _Container container_type;
      inline explicit front_insert_iterator(_Container &__x)
        : container(std::__addressof(__x))
      {
      }
      inline ::std::front_insert_iterator<_Container> &operator =(typename _Container::const_reference __value)
      {
        ::std::front_insert_iterator<_Container>::container->push_front(__value);
        return *this;
      }
      inline ::std::front_insert_iterator<_Container> &operator *()
      {
        return *this;
      }
      inline ::std::front_insert_iterator<_Container> &operator ++()
      {
        return *this;
      }
      inline ::std::front_insert_iterator<_Container> operator ++(int)
      {
        return *this;
      }
  };
  template < typename _Container >
  inline ::std::front_insert_iterator<_Container> front_inserter(_Container &__x);
  template < typename _Container >
  inline ::std::front_insert_iterator<_Container> front_inserter(_Container &__x)
  {
    return ::std::front_insert_iterator<_Container>(__x);
  }
  template < typename _Container >
  class  insert_iterator : public ::std::iterator< ::std::output_iterator_tag, void, void, void, void>
  {
    protected:
      _Container *container;
      typename _Container::iterator iter;
    public:
      typedef _Container container_type;
      inline insert_iterator(_Container &__x, typename _Container::iterator __i)
        : container(std::__addressof(__x)), iter(__i)
      {
      }
      inline ::std::insert_iterator<_Container> &operator =(typename _Container::const_reference __value)
      {
        ::std::insert_iterator<_Container>::iter = ::std::insert_iterator<_Container>::container->insert(::std::insert_iterator<_Container>::iter, __value);
         ++::std::insert_iterator<_Container>::iter;
        return *this;
      }
      inline ::std::insert_iterator<_Container> &operator *()
      {
        return *this;
      }
      inline ::std::insert_iterator<_Container> &operator ++()
      {
        return *this;
      }
      inline ::std::insert_iterator<_Container> &operator ++(int)
      {
        return *this;
      }
  };
  template < typename _Container, typename _Iterator >
  inline ::std::insert_iterator<_Container> inserter(_Container &__x, _Iterator __i);
  template < typename _Container, typename _Iterator >
  inline ::std::insert_iterator<_Container> inserter(_Container &__x, _Iterator __i)
  {
    return ::std::insert_iterator<_Container>(__x, typename _Container::iterator(__i));
  }
}
namespace __gnu_cxx __attribute__((__visibility__("default"))) {
  using ::std::iterator_traits;
  using ::std::iterator;
  template < typename _Iterator, typename _Container >
  class  __normal_iterator
  {
    protected:
      _Iterator _M_current;
      typedef ::std::iterator_traits<_Iterator> __traits_type;
    public:
      typedef _Iterator iterator_type;
      typedef typename ::std::iterator_traits<_Iterator>::iterator_category iterator_category;
      typedef typename ::std::iterator_traits<_Iterator>::value_type value_type;
      typedef typename ::std::iterator_traits<_Iterator>::difference_type difference_type;
      typedef typename ::std::iterator_traits<_Iterator>::reference reference;
      typedef typename ::std::iterator_traits<_Iterator>::pointer pointer;
      inline __normal_iterator()
        : _M_current(_Iterator())
      {
      }
      inline explicit __normal_iterator(const _Iterator &__i)
        : _M_current(__i)
      {
      }
      template < typename _Iter >
      inline __normal_iterator(const ::__gnu_cxx::__normal_iterator<_Iter, typename ::__gnu_cxx::__enable_if<std::__are_same<_Iter, typename _Container::pointer>::__value, _Container>::__type> &__i)
        : _M_current(__i.base())
      {
      }
      inline typename ::__gnu_cxx::__normal_iterator<_Iterator, _Container>::reference operator *() const 
      {
        return *::__gnu_cxx::__normal_iterator<_Iterator, _Container>::_M_current;
      }
      inline typename ::__gnu_cxx::__normal_iterator<_Iterator, _Container>::pointer operator ->() const 
      {
        return ::__gnu_cxx::__normal_iterator<_Iterator, _Container>::_M_current;
      }
      inline ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &operator ++()
      {
         ++::__gnu_cxx::__normal_iterator<_Iterator, _Container>::_M_current;
        return *this;
      }
      inline ::__gnu_cxx::__normal_iterator<_Iterator, _Container> operator ++(int)
      {
        return ::__gnu_cxx::__normal_iterator<_Iterator, _Container>(::__gnu_cxx::__normal_iterator<_Iterator, _Container>::_M_current++);
      }
      inline ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &operator --()
      {
         --::__gnu_cxx::__normal_iterator<_Iterator, _Container>::_M_current;
        return *this;
      }
      inline ::__gnu_cxx::__normal_iterator<_Iterator, _Container> operator --(int)
      {
        return ::__gnu_cxx::__normal_iterator<_Iterator, _Container>(::__gnu_cxx::__normal_iterator<_Iterator, _Container>::_M_current--);
      }
      inline typename ::__gnu_cxx::__normal_iterator<_Iterator, _Container>::reference operator [](typename ::__gnu_cxx::__normal_iterator<_Iterator, _Container>::difference_type __n) const 
      {
        return ::__gnu_cxx::__normal_iterator<_Iterator, _Container>::_M_current[__n];
      }
      inline ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &operator +=(typename ::__gnu_cxx::__normal_iterator<_Iterator, _Container>::difference_type __n)
      {
        ::__gnu_cxx::__normal_iterator<_Iterator, _Container>::_M_current += __n;
        return *this;
      }
      inline ::__gnu_cxx::__normal_iterator<_Iterator, _Container> operator +(typename ::__gnu_cxx::__normal_iterator<_Iterator, _Container>::difference_type __n) const 
      {
        return ::__gnu_cxx::__normal_iterator<_Iterator, _Container>(::__gnu_cxx::__normal_iterator<_Iterator, _Container>::_M_current + __n);
      }
      inline ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &operator -=(typename ::__gnu_cxx::__normal_iterator<_Iterator, _Container>::difference_type __n)
      {
        ::__gnu_cxx::__normal_iterator<_Iterator, _Container>::_M_current -= __n;
        return *this;
      }
      inline ::__gnu_cxx::__normal_iterator<_Iterator, _Container> operator -(typename ::__gnu_cxx::__normal_iterator<_Iterator, _Container>::difference_type __n) const 
      {
        return ::__gnu_cxx::__normal_iterator<_Iterator, _Container>(::__gnu_cxx::__normal_iterator<_Iterator, _Container>::_M_current - __n);
      }
      inline const _Iterator &base() const 
      {
        return ::__gnu_cxx::__normal_iterator<_Iterator, _Container>::_M_current;
      }
  };
  template < typename _IteratorL, typename _IteratorR, typename _Container >
  inline bool operator ==(const ::__gnu_cxx::__normal_iterator<_IteratorL, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_IteratorR, _Container> &__rhs);
  template < typename _IteratorL, typename _IteratorR, typename _Container >
  inline bool operator ==(const ::__gnu_cxx::__normal_iterator<_IteratorL, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_IteratorR, _Container> &__rhs)
  {
    return __lhs.base() == __rhs.base();
  }
  template < typename _Iterator, typename _Container >
  inline bool operator ==(const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__rhs);
  template < typename _Iterator, typename _Container >
  inline bool operator ==(const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__rhs)
  {
    return __lhs.base() == __rhs.base();
  }
  template < typename _IteratorL, typename _IteratorR, typename _Container >
  inline bool operator !=(const ::__gnu_cxx::__normal_iterator<_IteratorL, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_IteratorR, _Container> &__rhs);
  template < typename _IteratorL, typename _IteratorR, typename _Container >
  inline bool operator !=(const ::__gnu_cxx::__normal_iterator<_IteratorL, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_IteratorR, _Container> &__rhs)
  {
    return __lhs.base() != __rhs.base();
  }
  template < typename _Iterator, typename _Container >
  inline bool operator !=(const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__rhs);
  template < typename _Iterator, typename _Container >
  inline bool operator !=(const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__rhs)
  {
    return __lhs.base() != __rhs.base();
  }
  template < typename _IteratorL, typename _IteratorR, typename _Container >
  inline bool operator <(const ::__gnu_cxx::__normal_iterator<_IteratorL, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_IteratorR, _Container> &__rhs);
  template < typename _IteratorL, typename _IteratorR, typename _Container >
  inline bool operator <(const ::__gnu_cxx::__normal_iterator<_IteratorL, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_IteratorR, _Container> &__rhs)
  {
    return __lhs.base() < __rhs.base();
  }
  template < typename _Iterator, typename _Container >
  inline bool operator <(const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__rhs);
  template < typename _Iterator, typename _Container >
  inline bool operator <(const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__rhs)
  {
    return __lhs.base() < __rhs.base();
  }
  template < typename _IteratorL, typename _IteratorR, typename _Container >
  inline bool operator >(const ::__gnu_cxx::__normal_iterator<_IteratorL, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_IteratorR, _Container> &__rhs);
  template < typename _IteratorL, typename _IteratorR, typename _Container >
  inline bool operator >(const ::__gnu_cxx::__normal_iterator<_IteratorL, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_IteratorR, _Container> &__rhs)
  {
    return __lhs.base() > __rhs.base();
  }
  template < typename _Iterator, typename _Container >
  inline bool operator >(const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__rhs);
  template < typename _Iterator, typename _Container >
  inline bool operator >(const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__rhs)
  {
    return __lhs.base() > __rhs.base();
  }
  template < typename _IteratorL, typename _IteratorR, typename _Container >
  inline bool operator <=(const ::__gnu_cxx::__normal_iterator<_IteratorL, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_IteratorR, _Container> &__rhs);
  template < typename _IteratorL, typename _IteratorR, typename _Container >
  inline bool operator <=(const ::__gnu_cxx::__normal_iterator<_IteratorL, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_IteratorR, _Container> &__rhs)
  {
    return __lhs.base() <= __rhs.base();
  }
  template < typename _Iterator, typename _Container >
  inline bool operator <=(const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__rhs);
  template < typename _Iterator, typename _Container >
  inline bool operator <=(const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__rhs)
  {
    return __lhs.base() <= __rhs.base();
  }
  template < typename _IteratorL, typename _IteratorR, typename _Container >
  inline bool operator >=(const ::__gnu_cxx::__normal_iterator<_IteratorL, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_IteratorR, _Container> &__rhs);
  template < typename _IteratorL, typename _IteratorR, typename _Container >
  inline bool operator >=(const ::__gnu_cxx::__normal_iterator<_IteratorL, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_IteratorR, _Container> &__rhs)
  {
    return __lhs.base() >= __rhs.base();
  }
  template < typename _Iterator, typename _Container >
  inline bool operator >=(const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__rhs);
  template < typename _Iterator, typename _Container >
  inline bool operator >=(const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__rhs)
  {
    return __lhs.base() >= __rhs.base();
  }
  template < typename _IteratorL, typename _IteratorR, typename _Container >
  inline typename ::__gnu_cxx::__normal_iterator<_IteratorL, _Container>::difference_type operator -(const ::__gnu_cxx::__normal_iterator<_IteratorL, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_IteratorR, _Container> &__rhs);
  template < typename _IteratorL, typename _IteratorR, typename _Container >
  inline typename ::__gnu_cxx::__normal_iterator<_IteratorL, _Container>::difference_type operator -(const ::__gnu_cxx::__normal_iterator<_IteratorL, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_IteratorR, _Container> &__rhs)
  {
    return __lhs.base() - __rhs.base();
  }
  template < typename _Iterator, typename _Container >
  inline typename ::__gnu_cxx::__normal_iterator<_Iterator, _Container>::difference_type operator -(const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__rhs);
  template < typename _Iterator, typename _Container >
  inline typename ::__gnu_cxx::__normal_iterator<_Iterator, _Container>::difference_type operator -(const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__rhs)
  {
    return __lhs.base() - __rhs.base();
  }
  template < typename _Iterator, typename _Container >
  inline ::__gnu_cxx::__normal_iterator<_Iterator, _Container> operator +(typename ::__gnu_cxx::__normal_iterator<_Iterator, _Container>::difference_type __n, const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__i);
  template < typename _Iterator, typename _Container >
  inline ::__gnu_cxx::__normal_iterator<_Iterator, _Container> operator +(typename ::__gnu_cxx::__normal_iterator<_Iterator, _Container>::difference_type __n, const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__i)
  {
    return ::__gnu_cxx::__normal_iterator<_Iterator, _Container>(__i.base() + __n);
  }
}
namespace std __attribute__((__visibility__("default"))) {
  template < typename _Iterator, typename _Container >
  _Iterator __niter_base(::__gnu_cxx::__normal_iterator<_Iterator, _Container> __it);
  template < typename _Iterator, typename _Container >
  _Iterator __niter_base(::__gnu_cxx::__normal_iterator<_Iterator, _Container> __it)
  {
    return __it.base();
  }
  namespace __debug { }
}
namespace __gnu_debug {
  using namespace ::std::__debug;
}
namespace __gnu_cxx __attribute__((__visibility__("default"))) {
  namespace __ops {
    struct  _Iter_less_iter
    {
        template < typename _Iterator1, typename _Iterator2 >
        inline bool operator ()(_Iterator1 __it1, _Iterator2 __it2) const 
        {
          return *__it1 < *__it2;
        }
    };
    inline ::__gnu_cxx::__ops::_Iter_less_iter __iter_less_iter()
    {
      return ::__gnu_cxx::__ops::_Iter_less_iter();
    }
    struct  _Iter_less_val
    {
        inline _Iter_less_val()
        {
        }
        inline explicit _Iter_less_val(::__gnu_cxx::__ops::_Iter_less_iter)
        {
        }
        template < typename _Iterator, typename _Value >
        inline bool operator ()(_Iterator __it, _Value &__val) const 
        {
          return *__it < __val;
        }
    };
    inline ::__gnu_cxx::__ops::_Iter_less_val __iter_less_val()
    {
      return ::__gnu_cxx::__ops::_Iter_less_val();
    }
    inline ::__gnu_cxx::__ops::_Iter_less_val __iter_comp_val(::__gnu_cxx::__ops::_Iter_less_iter)
    {
      return ::__gnu_cxx::__ops::_Iter_less_val();
    }
    struct  _Val_less_iter
    {
        inline _Val_less_iter()
        {
        }
        inline explicit _Val_less_iter(::__gnu_cxx::__ops::_Iter_less_iter)
        {
        }
        template < typename _Value, typename _Iterator >
        inline bool operator ()(_Value &__val, _Iterator __it) const 
        {
          return __val < *__it;
        }
    };
    inline ::__gnu_cxx::__ops::_Val_less_iter __val_less_iter()
    {
      return ::__gnu_cxx::__ops::_Val_less_iter();
    }
    inline ::__gnu_cxx::__ops::_Val_less_iter __val_comp_iter(::__gnu_cxx::__ops::_Iter_less_iter)
    {
      return ::__gnu_cxx::__ops::_Val_less_iter();
    }
    struct  _Iter_equal_to_iter
    {
        template < typename _Iterator1, typename _Iterator2 >
        inline bool operator ()(_Iterator1 __it1, _Iterator2 __it2) const 
        {
          return *__it1 == *__it2;
        }
    };
    inline ::__gnu_cxx::__ops::_Iter_equal_to_iter __iter_equal_to_iter()
    {
      return ::__gnu_cxx::__ops::_Iter_equal_to_iter();
    }
    struct  _Iter_equal_to_val
    {
        template < typename _Iterator, typename _Value >
        inline bool operator ()(_Iterator __it, _Value &__val) const 
        {
          return *__it == __val;
        }
    };
    inline ::__gnu_cxx::__ops::_Iter_equal_to_val __iter_equal_to_val()
    {
      return ::__gnu_cxx::__ops::_Iter_equal_to_val();
    }
    inline ::__gnu_cxx::__ops::_Iter_equal_to_val __iter_comp_val(::__gnu_cxx::__ops::_Iter_equal_to_iter)
    {
      return ::__gnu_cxx::__ops::_Iter_equal_to_val();
    }
    template < typename _Compare >
    struct  _Iter_comp_iter
    {
        _Compare _M_comp;
        inline explicit _Iter_comp_iter(_Compare __comp)
          : _M_comp(__comp)
        {
        }
        template < typename _Iterator1, typename _Iterator2 >
        inline bool operator ()(_Iterator1 __it1, _Iterator2 __it2)
        {
          return bool(::__gnu_cxx::__ops::_Iter_comp_iter<_Compare>::_M_comp(*__it1, *__it2));
        }
    };
    template < typename _Compare >
    inline ::__gnu_cxx::__ops::_Iter_comp_iter<_Compare> __iter_comp_iter(_Compare __comp);
    template < typename _Compare >
    inline ::__gnu_cxx::__ops::_Iter_comp_iter<_Compare> __iter_comp_iter(_Compare __comp)
    {
      return ::__gnu_cxx::__ops::_Iter_comp_iter<_Compare>(__comp);
    }
    template < typename _Compare >
    struct  _Iter_comp_val
    {
        _Compare _M_comp;
        inline explicit _Iter_comp_val(_Compare __comp)
          : _M_comp(__comp)
        {
        }
        inline explicit _Iter_comp_val(const ::__gnu_cxx::__ops::_Iter_comp_iter<_Compare> &__comp)
          : _M_comp(__comp._M_comp)
        {
        }
        template < typename _Iterator, typename _Value >
        inline bool operator ()(_Iterator __it, _Value &__val)
        {
          return bool(::__gnu_cxx::__ops::_Iter_comp_val<_Compare>::_M_comp(*__it, __val));
        }
    };
    template < typename _Compare >
    inline ::__gnu_cxx::__ops::_Iter_comp_val<_Compare> __iter_comp_val(_Compare __comp);
    template < typename _Compare >
    inline ::__gnu_cxx::__ops::_Iter_comp_val<_Compare> __iter_comp_val(_Compare __comp)
    {
      return ::__gnu_cxx::__ops::_Iter_comp_val<_Compare>(__comp);
    }
    template < typename _Compare >
    inline ::__gnu_cxx::__ops::_Iter_comp_val<_Compare> __iter_comp_val(::__gnu_cxx::__ops::_Iter_comp_iter<_Compare> __comp);
    template < typename _Compare >
    inline ::__gnu_cxx::__ops::_Iter_comp_val<_Compare> __iter_comp_val(::__gnu_cxx::__ops::_Iter_comp_iter<_Compare> __comp)
    {
      return ::__gnu_cxx::__ops::_Iter_comp_val<_Compare>(__comp);
    }
    template < typename _Compare >
    struct  _Val_comp_iter
    {
        _Compare _M_comp;
        inline explicit _Val_comp_iter(_Compare __comp)
          : _M_comp(__comp)
        {
        }
        inline explicit _Val_comp_iter(const ::__gnu_cxx::__ops::_Iter_comp_iter<_Compare> &__comp)
          : _M_comp(__comp._M_comp)
        {
        }
        template < typename _Value, typename _Iterator >
        inline bool operator ()(_Value &__val, _Iterator __it)
        {
          return bool(::__gnu_cxx::__ops::_Val_comp_iter<_Compare>::_M_comp(__val, *__it));
        }
    };
    template < typename _Compare >
    inline ::__gnu_cxx::__ops::_Val_comp_iter<_Compare> __val_comp_iter(_Compare __comp);
    template < typename _Compare >
    inline ::__gnu_cxx::__ops::_Val_comp_iter<_Compare> __val_comp_iter(_Compare __comp)
    {
      return ::__gnu_cxx::__ops::_Val_comp_iter<_Compare>(__comp);
    }
    template < typename _Compare >
    inline ::__gnu_cxx::__ops::_Val_comp_iter<_Compare> __val_comp_iter(::__gnu_cxx::__ops::_Iter_comp_iter<_Compare> __comp);
    template < typename _Compare >
    inline ::__gnu_cxx::__ops::_Val_comp_iter<_Compare> __val_comp_iter(::__gnu_cxx::__ops::_Iter_comp_iter<_Compare> __comp)
    {
      return ::__gnu_cxx::__ops::_Val_comp_iter<_Compare>(__comp);
    }
    template < typename _Value >
    struct  _Iter_equals_val
    {
        _Value &_M_value;
        inline explicit _Iter_equals_val(_Value &__value)
          : _M_value(__value)
        {
        }
        template < typename _Iterator >
        inline bool operator ()(_Iterator __it)
        {
          return *__it == ::__gnu_cxx::__ops::_Iter_equals_val<_Value>::_M_value;
        }
    };
    template < typename _Value >
    inline ::__gnu_cxx::__ops::_Iter_equals_val<_Value> __iter_equals_val(_Value &__val);
    template < typename _Value >
    inline ::__gnu_cxx::__ops::_Iter_equals_val<_Value> __iter_equals_val(_Value &__val)
    {
      return ::__gnu_cxx::__ops::_Iter_equals_val<_Value>(__val);
    }
    template < typename _Iterator1 >
    struct  _Iter_equals_iter
    {
        _Iterator1 _M_it1;
        inline explicit _Iter_equals_iter(_Iterator1 __it1)
          : _M_it1(__it1)
        {
        }
        template < typename _Iterator2 >
        inline bool operator ()(_Iterator2 __it2)
        {
          return *__it2 == *::__gnu_cxx::__ops::_Iter_equals_iter<_Iterator1>::_M_it1;
        }
    };
    template < typename _Iterator >
    inline ::__gnu_cxx::__ops::_Iter_equals_iter<_Iterator> __iter_comp_iter(::__gnu_cxx::__ops::_Iter_equal_to_iter, _Iterator __it);
    template < typename _Iterator >
    inline ::__gnu_cxx::__ops::_Iter_equals_iter<_Iterator> __iter_comp_iter(::__gnu_cxx::__ops::_Iter_equal_to_iter, _Iterator __it)
    {
      return ::__gnu_cxx::__ops::_Iter_equals_iter<_Iterator>(__it);
    }
    template < typename _Predicate >
    struct  _Iter_pred
    {
        _Predicate _M_pred;
        inline explicit _Iter_pred(_Predicate __pred)
          : _M_pred(__pred)
        {
        }
        template < typename _Iterator >
        inline bool operator ()(_Iterator __it)
        {
          return bool(::__gnu_cxx::__ops::_Iter_pred<_Predicate>::_M_pred(*__it));
        }
    };
    template < typename _Predicate >
    inline ::__gnu_cxx::__ops::_Iter_pred<_Predicate> __pred_iter(_Predicate __pred);
    template < typename _Predicate >
    inline ::__gnu_cxx::__ops::_Iter_pred<_Predicate> __pred_iter(_Predicate __pred)
    {
      return ::__gnu_cxx::__ops::_Iter_pred<_Predicate>(__pred);
    }
    template < typename _Compare, typename _Value >
    struct  _Iter_comp_to_val
    {
        _Compare _M_comp;
        _Value &_M_value;
        inline _Iter_comp_to_val(_Compare __comp, _Value &__value)
          : _M_comp(__comp), _M_value(__value)
        {
        }
        template < typename _Iterator >
        inline bool operator ()(_Iterator __it)
        {
          return bool(::__gnu_cxx::__ops::_Iter_comp_to_val<_Compare, _Value>::_M_comp(*__it, ::__gnu_cxx::__ops::_Iter_comp_to_val<_Compare, _Value>::_M_value));
        }
    };
    template < typename _Compare, typename _Value >
    ::__gnu_cxx::__ops::_Iter_comp_to_val<_Compare, _Value> __iter_comp_val(_Compare __comp, _Value &__val);
    template < typename _Compare, typename _Value >
    ::__gnu_cxx::__ops::_Iter_comp_to_val<_Compare, _Value> __iter_comp_val(_Compare __comp, _Value &__val)
    {
      return ::__gnu_cxx::__ops::_Iter_comp_to_val<_Compare, _Value>(__comp, __val);
    }
    template < typename _Compare, typename _Iterator1 >
    struct  _Iter_comp_to_iter
    {
        _Compare _M_comp;
        _Iterator1 _M_it1;
        inline _Iter_comp_to_iter(_Compare __comp, _Iterator1 __it1)
          : _M_comp(__comp), _M_it1(__it1)
        {
        }
        template < typename _Iterator2 >
        inline bool operator ()(_Iterator2 __it2)
        {
          return bool(::__gnu_cxx::__ops::_Iter_comp_to_iter<_Compare, _Iterator1>::_M_comp(*__it2, *::__gnu_cxx::__ops::_Iter_comp_to_iter<_Compare, _Iterator1>::_M_it1));
        }
    };
    template < typename _Compare, typename _Iterator >
    inline ::__gnu_cxx::__ops::_Iter_comp_to_iter<_Compare, _Iterator> __iter_comp_iter(::__gnu_cxx::__ops::_Iter_comp_iter<_Compare> __comp, _Iterator __it);
    template < typename _Compare, typename _Iterator >
    inline ::__gnu_cxx::__ops::_Iter_comp_to_iter<_Compare, _Iterator> __iter_comp_iter(::__gnu_cxx::__ops::_Iter_comp_iter<_Compare> __comp, _Iterator __it)
    {
      return ::__gnu_cxx::__ops::_Iter_comp_to_iter<_Compare, _Iterator>(__comp._M_comp, __it);
    }
    template < typename _Predicate >
    struct  _Iter_negate
    {
        _Predicate _M_pred;
        inline explicit _Iter_negate(_Predicate __pred)
          : _M_pred(__pred)
        {
        }
        template < typename _Iterator >
        inline bool operator ()(_Iterator __it)
        {
          return !bool(::__gnu_cxx::__ops::_Iter_negate<_Predicate>::_M_pred(*__it));
        }
    };
    template < typename _Predicate >
    inline ::__gnu_cxx::__ops::_Iter_negate<_Predicate> __negate(::__gnu_cxx::__ops::_Iter_pred<_Predicate> __pred);
    template < typename _Predicate >
    inline ::__gnu_cxx::__ops::_Iter_negate<_Predicate> __negate(::__gnu_cxx::__ops::_Iter_pred<_Predicate> __pred)
    {
      return ::__gnu_cxx::__ops::_Iter_negate<_Predicate>(__pred._M_pred);
    }
  }
}
namespace std __attribute__((__visibility__("default"))) {
   template < bool _BoolType >
  struct  __iter_swap
  {
      template < typename _ForwardIterator1, typename _ForwardIterator2 >
      static inline void iter_swap(_ForwardIterator1 __a, _ForwardIterator2 __b)
      {
        typedef typename ::std::iterator_traits<_ForwardIterator1>::value_type _ValueType1;
        _ValueType1 __tmp = (*__a);
        *__a = *__b;
        *__b = __tmp;
      }
  };
  template <>
  struct  __iter_swap<true>
  {
      template < typename _ForwardIterator1, typename _ForwardIterator2 >
      static inline void iter_swap(_ForwardIterator1 __a, _ForwardIterator2 __b)
      {
        swap(*__a, *__b);
      }
  };
  template < typename _ForwardIterator1, typename _ForwardIterator2 >
  inline void iter_swap(_ForwardIterator1 __a, _ForwardIterator2 __b);
  template < typename _ForwardIterator1, typename _ForwardIterator2 >
  inline void iter_swap(_ForwardIterator1 __a, _ForwardIterator2 __b)
  {
    typedef typename ::std::iterator_traits<_ForwardIterator1>::value_type _ValueType1;
    typedef typename ::std::iterator_traits<_ForwardIterator2>::value_type _ValueType2;
    typedef typename ::std::iterator_traits<_ForwardIterator1>::reference _ReferenceType1;
    typedef typename ::std::iterator_traits<_ForwardIterator2>::reference _ReferenceType2;
    std::__iter_swap<(__are_same<_ValueType1, _ValueType2>::__value && __are_same<_ValueType1 &, _ReferenceType1>::__value) && __are_same<_ValueType2 &, _ReferenceType2>::__value>::iter_swap(__a, __b);
  }
  template < typename _ForwardIterator1, typename _ForwardIterator2 >
  _ForwardIterator2 swap_ranges(_ForwardIterator1 __first1, _ForwardIterator1 __last1, _ForwardIterator2 __first2);
  template < typename _ForwardIterator1, typename _ForwardIterator2 >
  _ForwardIterator2 swap_ranges(_ForwardIterator1 __first1, _ForwardIterator1 __last1, _ForwardIterator2 __first2)
  {
    ;
    for (; __first1 != __last1; ( ++__first1, (void) ++__first2))
      {
        std::iter_swap(__first1, __first2);
      }
    return __first2;
  }
  template < typename _Tp >
  inline const _Tp &min(const _Tp &__a, const _Tp &__b);
  template < typename _Tp >
  inline const _Tp &min(const _Tp &__a, const _Tp &__b)
  {
    if (__b < __a)
      {
        return __b;
      }
    return __a;
  }
  template < typename _Tp >
  inline const _Tp &max(const _Tp &__a, const _Tp &__b);
  template < typename _Tp >
  inline const _Tp &max(const _Tp &__a, const _Tp &__b)
  {
    if (__a < __b)
      {
        return __b;
      }
    return __a;
  }
  template < typename _Tp, typename _Compare >
  inline const _Tp &min(const _Tp &__a, const _Tp &__b, _Compare __comp);
  template < typename _Tp, typename _Compare >
  inline const _Tp &min(const _Tp &__a, const _Tp &__b, _Compare __comp)
  {
    if (__comp(__b, __a))
      {
        return __b;
      }
    return __a;
  }
  template < typename _Tp, typename _Compare >
  inline const _Tp &max(const _Tp &__a, const _Tp &__b, _Compare __comp);
  template < typename _Tp, typename _Compare >
  inline const _Tp &max(const _Tp &__a, const _Tp &__b, _Compare __comp)
  {
    if (__comp(__a, __b))
      {
        return __b;
      }
    return __a;
  }
  template < typename _Iterator >
  inline _Iterator __niter_base(_Iterator __it);
  template < typename _Iterator >
  inline _Iterator __niter_base(_Iterator __it)
  {
    return __it;
  }
  template < bool __nontype_tpl_param_1_0__, bool __nontype_tpl_param_1_1__, typename __type_tpl__param_1_2__ >
  struct  __copy_move
  {
      template < typename _II, typename _OI >
      static inline _OI __copy_m(_II __first, _II __last, _OI __result)
      {
        for (; __first != __last; ( ++__result, (void) ++__first))
          {
            *__result = *__first;
          }
        return __result;
      }
  };
  template <>
  struct  __copy_move<false, false, ::std::random_access_iterator_tag>
  {
      template < typename _II, typename _OI >
      static inline _OI __copy_m(_II __first, _II __last, _OI __result)
      {
        typedef typename ::std::iterator_traits<_II>::difference_type _Distance;
        for (_Distance __n = __last - __first; __n > 0;  --__n)
          {
            *__result = *__first;
             ++__first;
             ++__result;
          }
        return __result;
      }
  };
  template < bool _IsMove >
  struct  __copy_move<_IsMove, true, ::std::random_access_iterator_tag>
  {
      template < typename _Tp >
      static inline _Tp *__copy_m(const _Tp *__first, const _Tp *__last, _Tp *__result)
      {
        const ::std::ptrdiff_t _Num = __last - __first;
        if (_Num)
          {
            __builtin_memmove(__result, __first, sizeof(_Tp) * _Num);
          }
        return __result + _Num;
      }
  };
  template < bool _IsMove, typename _II, typename _OI >
  inline _OI __copy_move_a(_II __first, _II __last, _OI __result);
  template < bool _IsMove, typename _II, typename _OI >
  inline _OI __copy_move_a(_II __first, _II __last, _OI __result)
  {
    typedef typename ::std::iterator_traits<_II>::value_type _ValueTypeI;
    typedef typename ::std::iterator_traits<_OI>::value_type _ValueTypeO;
    typedef typename ::std::iterator_traits<_II>::iterator_category _Category;
    const bool __simple = (((__is_trivial(_ValueTypeI)) && __is_pointer<_II>::__value) && __is_pointer<_OI>::__value) && __are_same<_ValueTypeI, _ValueTypeO>::__value;
    return std::__copy_move<_IsMove, __simple, _Category>::__copy_m(__first, __last, __result);
  }
  template < typename _CharT >
  struct char_traits;
  template < typename _CharT, typename _Traits >
  class istreambuf_iterator;
  template < typename _CharT, typename _Traits >
  class ostreambuf_iterator;
  template < bool _IsMove, typename _CharT >
  typename ::__gnu_cxx::__enable_if<__is_char<_CharT>::__value, ::std::ostreambuf_iterator<_CharT, ::std::char_traits<_CharT> > >::__type __copy_move_a2(_CharT *, _CharT *, ::std::ostreambuf_iterator<_CharT, ::std::char_traits<_CharT> >);
  template < bool _IsMove, typename _CharT >
  typename ::__gnu_cxx::__enable_if<__is_char<_CharT>::__value, ::std::ostreambuf_iterator<_CharT, ::std::char_traits<_CharT> > >::__type __copy_move_a2(const _CharT *, const _CharT *, ::std::ostreambuf_iterator<_CharT, ::std::char_traits<_CharT> >);
  template < bool _IsMove, typename _CharT >
  typename ::__gnu_cxx::__enable_if<__is_char<_CharT>::__value, _CharT *>::__type __copy_move_a2(::std::istreambuf_iterator<_CharT, ::std::char_traits<_CharT> >, ::std::istreambuf_iterator<_CharT, ::std::char_traits<_CharT> >, _CharT *);
  template < bool _IsMove, typename _II, typename _OI >
  inline _OI __copy_move_a2(_II __first, _II __last, _OI __result);
  template < bool _IsMove, typename _II, typename _OI >
  inline _OI __copy_move_a2(_II __first, _II __last, _OI __result)
  {
    return _OI(std::__copy_move_a<_IsMove>(std::__niter_base(__first), std::__niter_base(__last), std::__niter_base(__result)));
  }
  template < typename _II, typename _OI >
  inline _OI copy(_II __first, _II __last, _OI __result);
  template < typename _II, typename _OI >
  inline _OI copy(_II __first, _II __last, _OI __result)
  {
    ;
    return std::__copy_move_a2<__is_move_iterator<_II>::__value>(std::__miter_base(__first), std::__miter_base(__last), __result);
  }
  template < bool __nontype_tpl_param_1_0__, bool __nontype_tpl_param_1_1__, typename __type_tpl__param_1_2__ >
  struct  __copy_move_backward
  {
      template < typename _BI1, typename _BI2 >
      static inline _BI2 __copy_move_b(_BI1 __first, _BI1 __last, _BI2 __result)
      {
        while (__first != __last)
          {
            * --__result = * --__last;
          }
        return __result;
      }
  };
  template <>
  struct  __copy_move_backward<false, false, ::std::random_access_iterator_tag>
  {
      template < typename _BI1, typename _BI2 >
      static inline _BI2 __copy_move_b(_BI1 __first, _BI1 __last, _BI2 __result)
      {
        typename ::std::iterator_traits<_BI1>::difference_type __n;
        for (__n = __last - __first; __n > 0;  --__n)
          {
            * --__result = * --__last;
          }
        return __result;
      }
  };
  template < bool _IsMove >
  struct  __copy_move_backward<_IsMove, true, ::std::random_access_iterator_tag>
  {
      template < typename _Tp >
      static inline _Tp *__copy_move_b(const _Tp *__first, const _Tp *__last, _Tp *__result)
      {
        const ::std::ptrdiff_t _Num = __last - __first;
        if (_Num)
          {
            __builtin_memmove(__result - _Num, __first, sizeof(_Tp) * _Num);
          }
        return __result - _Num;
      }
  };
  template < bool _IsMove, typename _BI1, typename _BI2 >
  inline _BI2 __copy_move_backward_a(_BI1 __first, _BI1 __last, _BI2 __result);
  template < bool _IsMove, typename _BI1, typename _BI2 >
  inline _BI2 __copy_move_backward_a(_BI1 __first, _BI1 __last, _BI2 __result)
  {
    typedef typename ::std::iterator_traits<_BI1>::value_type _ValueType1;
    typedef typename ::std::iterator_traits<_BI2>::value_type _ValueType2;
    typedef typename ::std::iterator_traits<_BI1>::iterator_category _Category;
    const bool __simple = (((__is_trivial(_ValueType1)) && __is_pointer<_BI1>::__value) && __is_pointer<_BI2>::__value) && __are_same<_ValueType1, _ValueType2>::__value;
    return std::__copy_move_backward<_IsMove, __simple, _Category>::__copy_move_b(__first, __last, __result);
  }
  template < bool _IsMove, typename _BI1, typename _BI2 >
  inline _BI2 __copy_move_backward_a2(_BI1 __first, _BI1 __last, _BI2 __result);
  template < bool _IsMove, typename _BI1, typename _BI2 >
  inline _BI2 __copy_move_backward_a2(_BI1 __first, _BI1 __last, _BI2 __result)
  {
    return _BI2(std::__copy_move_backward_a<_IsMove>(std::__niter_base(__first), std::__niter_base(__last), std::__niter_base(__result)));
  }
  template < typename _BI1, typename _BI2 >
  inline _BI2 copy_backward(_BI1 __first, _BI1 __last, _BI2 __result);
  template < typename _BI1, typename _BI2 >
  inline _BI2 copy_backward(_BI1 __first, _BI1 __last, _BI2 __result)
  {
    ;
    return std::__copy_move_backward_a2<__is_move_iterator<_BI1>::__value>(std::__miter_base(__first), std::__miter_base(__last), __result);
  }
  template < typename _ForwardIterator, typename _Tp >
  inline typename ::__gnu_cxx::__enable_if<!__is_scalar<_Tp>::__value, void>::__type __fill_a(_ForwardIterator __first, _ForwardIterator __last, const _Tp &__value);
  template < typename _ForwardIterator, typename _Tp >
  inline typename ::__gnu_cxx::__enable_if<!__is_scalar<_Tp>::__value, void>::__type __fill_a(_ForwardIterator __first, _ForwardIterator __last, const _Tp &__value)
  {
    for (; __first != __last;  ++__first)
      {
        *__first = __value;
      }
  }
  template < typename _ForwardIterator, typename _Tp >
  inline typename ::__gnu_cxx::__enable_if<__is_scalar<_Tp>::__value, void>::__type __fill_a(_ForwardIterator __first, _ForwardIterator __last, const _Tp &__value);
  template < typename _ForwardIterator, typename _Tp >
  inline typename ::__gnu_cxx::__enable_if<__is_scalar<_Tp>::__value, void>::__type __fill_a(_ForwardIterator __first, _ForwardIterator __last, const _Tp &__value)
  {
    const _Tp __tmp = __value;
    for (; __first != __last;  ++__first)
      {
        *__first = __tmp;
      }
  }
  template < typename _Tp >
  inline typename ::__gnu_cxx::__enable_if<__is_byte<_Tp>::__value, void>::__type __fill_a(_Tp *__first, _Tp *__last, const _Tp &__c);
  template < typename _Tp >
  inline typename ::__gnu_cxx::__enable_if<__is_byte<_Tp>::__value, void>::__type __fill_a(_Tp *__first, _Tp *__last, const _Tp &__c)
  {
    const _Tp __tmp = __c;
    if (const ::std::size_t __len = __last - __first)
      {
        __builtin_memset(__first, static_cast<unsigned char>(__tmp), __len);
      }
  }
  template < typename _ForwardIterator, typename _Tp >
  inline void fill(_ForwardIterator __first, _ForwardIterator __last, const _Tp &__value);
  template < typename _ForwardIterator, typename _Tp >
  inline void fill(_ForwardIterator __first, _ForwardIterator __last, const _Tp &__value)
  {
    ;
    std::__fill_a(std::__niter_base(__first), std::__niter_base(__last), __value);
  }
  template < typename _OutputIterator, typename _Size, typename _Tp >
  inline typename ::__gnu_cxx::__enable_if<!__is_scalar<_Tp>::__value, _OutputIterator>::__type __fill_n_a(_OutputIterator __first, _Size __n, const _Tp &__value);
  template < typename _OutputIterator, typename _Size, typename _Tp >
  inline typename ::__gnu_cxx::__enable_if<!__is_scalar<_Tp>::__value, _OutputIterator>::__type __fill_n_a(_OutputIterator __first, _Size __n, const _Tp &__value)
  {
    for (__decltype(__n + 0) __niter = __n; __niter > 0; ( --__niter,  ++__first))
      {
        *__first = __value;
      }
    return __first;
  }
  template < typename _OutputIterator, typename _Size, typename _Tp >
  inline typename ::__gnu_cxx::__enable_if<__is_scalar<_Tp>::__value, _OutputIterator>::__type __fill_n_a(_OutputIterator __first, _Size __n, const _Tp &__value);
  template < typename _OutputIterator, typename _Size, typename _Tp >
  inline typename ::__gnu_cxx::__enable_if<__is_scalar<_Tp>::__value, _OutputIterator>::__type __fill_n_a(_OutputIterator __first, _Size __n, const _Tp &__value)
  {
    const _Tp __tmp = __value;
    for (__decltype(__n + 0) __niter = __n; __niter > 0; ( --__niter,  ++__first))
      {
        *__first = __tmp;
      }
    return __first;
  }
  template < typename _Size, typename _Tp >
  inline typename ::__gnu_cxx::__enable_if<__is_byte<_Tp>::__value, _Tp *>::__type __fill_n_a(_Tp *__first, _Size __n, const _Tp &__c);
  template < typename _Size, typename _Tp >
  inline typename ::__gnu_cxx::__enable_if<__is_byte<_Tp>::__value, _Tp *>::__type __fill_n_a(_Tp *__first, _Size __n, const _Tp &__c)
  {
    std::__fill_a(__first, __first + __n, __c);
    return __first + __n;
  }
  template < typename _OI, typename _Size, typename _Tp >
  inline _OI fill_n(_OI __first, _Size __n, const _Tp &__value);
  template < typename _OI, typename _Size, typename _Tp >
  inline _OI fill_n(_OI __first, _Size __n, const _Tp &__value)
  {
    return _OI(std::__fill_n_a(std::__niter_base(__first), __n, __value));
  }
  template < bool _BoolType >
  struct  __equal
  {
      template < typename _II1, typename _II2 >
      static inline bool equal(_II1 __first1, _II1 __last1, _II2 __first2)
      {
        for (; __first1 != __last1; ( ++__first1, (void) ++__first2))
          {
            if (!(*__first1 == *__first2))
              {
                return false;
              }
          }
        return true;
      }
  };
  template <>
  struct  __equal<true>
  {
      template < typename _Tp >
      static inline bool equal(const _Tp *__first1, const _Tp *__last1, const _Tp *__first2)
      {
        if (const ::std::size_t __len = __last1 - __first1)
          {
            return !__builtin_memcmp(__first1, __first2, sizeof(_Tp) * __len);
          }
        return true;
      }
  };
  template < typename _II1, typename _II2 >
  inline bool __equal_aux(_II1 __first1, _II1 __last1, _II2 __first2);
  template < typename _II1, typename _II2 >
  inline bool __equal_aux(_II1 __first1, _II1 __last1, _II2 __first2)
  {
    typedef typename ::std::iterator_traits<_II1>::value_type _ValueType1;
    typedef typename ::std::iterator_traits<_II2>::value_type _ValueType2;
    const bool __simple = (((__is_integer<_ValueType1>::__value || __is_pointer<_ValueType1>::__value) && __is_pointer<_II1>::__value) && __is_pointer<_II2>::__value) && __are_same<_ValueType1, _ValueType2>::__value;
    return std::__equal<__simple>::equal(__first1, __last1, __first2);
  }
  template < typename __type_tpl__param_1_0__, typename __type_tpl__param_1_1__ >
  struct  __lc_rai
  {
      template < typename _II1, typename _II2 >
      static inline _II1 __newlast1(_II1, _II1 __last1, _II2, _II2)
      {
        return __last1;
      }
      template < typename _II >
      static inline bool __cnd2(_II __first, _II __last)
      {
        return __first != __last;
      }
  };
  template <>
  struct  __lc_rai< ::std::random_access_iterator_tag, ::std::random_access_iterator_tag>
  {
      template < typename _RAI1, typename _RAI2 >
      static inline _RAI1 __newlast1(_RAI1 __first1, _RAI1 __last1, _RAI2 __first2, _RAI2 __last2)
      {
        const typename ::std::iterator_traits<_RAI1>::difference_type __diff1 = __last1 - __first1;
        const typename ::std::iterator_traits<_RAI2>::difference_type __diff2 = __last2 - __first2;
        return __diff2 < __diff1 ? __first1 + __diff2 : __last1;
      }
      template < typename _RAI >
      static inline bool __cnd2(_RAI, _RAI)
      {
        return true;
      }
  };
  template < typename _II1, typename _II2, typename _Compare >
  bool __lexicographical_compare_impl(_II1 __first1, _II1 __last1, _II2 __first2, _II2 __last2, _Compare __comp);
  template < typename _II1, typename _II2, typename _Compare >
  bool __lexicographical_compare_impl(_II1 __first1, _II1 __last1, _II2 __first2, _II2 __last2, _Compare __comp)
  {
    typedef typename ::std::iterator_traits<_II1>::iterator_category _Category1;
    typedef typename ::std::iterator_traits<_II2>::iterator_category _Category2;
    typedef ::std::__lc_rai<_Category1, _Category2> __rai_type;
    __last1 = __rai_type::__newlast1(__first1, __last1, __first2, __last2);
    for (; __first1 != __last1 && __rai_type::__cnd2(__first2, __last2); ( ++__first1, (void) ++__first2))
      {
        if (__comp(__first1, __first2))
          {
            return true;
          }
        if (__comp(__first2, __first1))
          {
            return false;
          }
      }
    return __first1 == __last1 && __first2 != __last2;
  }
  template < bool _BoolType >
  struct  __lexicographical_compare
  {
      template < typename _II1, typename _II2 >
      static bool __lc(_II1 __first1, _II1 __last1, _II2 __first2, _II2 __last2);
  };
  template < bool _BoolType >
  template < typename _II1, typename _II2 >
  bool __lexicographical_compare<_BoolType>::__lc(_II1 __first1, _II1 __last1, _II2 __first2, _II2 __last2)
  {
    return std::__lexicographical_compare_impl(__first1, __last1, __first2, __last2, __gnu_cxx::__ops::__iter_less_iter());
  }
  template <>
  struct  __lexicographical_compare<true>
  {
      template < typename _Tp, typename _Up >
      static inline bool __lc(const _Tp *__first1, const _Tp *__last1, const _Up *__first2, const _Up *__last2)
      {
        const ::std::size_t __len1 = __last1 - __first1;
        const ::std::size_t __len2 = __last2 - __first2;
        if (const ::std::size_t __len = std::min(__len1, __len2))
          {
            if (int __result = __builtin_memcmp(__first1, __first2, __len))
              {
                return __result < 0;
              }
          }
        return __len1 < __len2;
      }
  };
  template < typename _II1, typename _II2 >
  inline bool __lexicographical_compare_aux(_II1 __first1, _II1 __last1, _II2 __first2, _II2 __last2);
  template < typename _II1, typename _II2 >
  inline bool __lexicographical_compare_aux(_II1 __first1, _II1 __last1, _II2 __first2, _II2 __last2)
  {
    typedef typename ::std::iterator_traits<_II1>::value_type _ValueType1;
    typedef typename ::std::iterator_traits<_II2>::value_type _ValueType2;
    const bool __simple = ((((__is_byte<_ValueType1>::__value && __is_byte<_ValueType2>::__value) && !__gnu_cxx::__numeric_traits<_ValueType1>::__is_signed) && !__gnu_cxx::__numeric_traits<_ValueType2>::__is_signed) && __is_pointer<_II1>::__value) && __is_pointer<_II2>::__value;
    return std::__lexicographical_compare<__simple>::__lc(__first1, __last1, __first2, __last2);
  }
  template < typename _ForwardIterator, typename _Tp, typename _Compare >
  _ForwardIterator __lower_bound(_ForwardIterator __first, _ForwardIterator __last, const _Tp &__val, _Compare __comp);
  template < typename _ForwardIterator, typename _Tp, typename _Compare >
  _ForwardIterator __lower_bound(_ForwardIterator __first, _ForwardIterator __last, const _Tp &__val, _Compare __comp)
  {
    typedef typename ::std::iterator_traits<_ForwardIterator>::difference_type _DistanceType;
    _DistanceType __len = std::distance(__first, __last);
    while (__len > 0)
      {
        _DistanceType __half = __len >> 1;
        _ForwardIterator __middle = __first;
        std::advance(__middle, __half);
        if (__comp(__middle, __val))
          {
            __first = __middle;
             ++__first;
            __len = __len - __half - 1;
          }
        else
          {
            __len = __half;
          }
      }
    return __first;
  }
  template < typename _ForwardIterator, typename _Tp >
  inline _ForwardIterator lower_bound(_ForwardIterator __first, _ForwardIterator __last, const _Tp &__val);
  template < typename _ForwardIterator, typename _Tp >
  inline _ForwardIterator lower_bound(_ForwardIterator __first, _ForwardIterator __last, const _Tp &__val)
  {
    ;
    return std::__lower_bound(__first, __last, __val, __gnu_cxx::__ops::__iter_less_val());
  }
  inline int __lg(int __n)
  {
    return sizeof(int) * 8 - 1 - __builtin_clz(__n);
  }
  inline unsigned int __lg(unsigned int __n)
  {
    return sizeof(int) * 8 - 1 - __builtin_clz(__n);
  }
  inline long int __lg(long int __n)
  {
    return sizeof(long int) * 8 - 1 - __builtin_clzl(__n);
  }
  inline unsigned long int __lg(unsigned long int __n)
  {
    return sizeof(long int) * 8 - 1 - __builtin_clzl(__n);
  }
  inline long long int __lg(long long int __n)
  {
    return sizeof(long long int) * 8 - 1 - __builtin_clzll(__n);
  }
  inline unsigned long long int __lg(unsigned long long int __n)
  {
    return sizeof(long long int) * 8 - 1 - __builtin_clzll(__n);
  }
  template < typename _II1, typename _II2 >
  inline bool equal(_II1 __first1, _II1 __last1, _II2 __first2);
  template < typename _II1, typename _II2 >
  inline bool equal(_II1 __first1, _II1 __last1, _II2 __first2)
  {
    ;
    return std::__equal_aux(std::__niter_base(__first1), std::__niter_base(__last1), std::__niter_base(__first2));
  }
  template < typename _IIter1, typename _IIter2, typename _BinaryPredicate >
  inline bool equal(_IIter1 __first1, _IIter1 __last1, _IIter2 __first2, _BinaryPredicate __binary_pred);
  template < typename _IIter1, typename _IIter2, typename _BinaryPredicate >
  inline bool equal(_IIter1 __first1, _IIter1 __last1, _IIter2 __first2, _BinaryPredicate __binary_pred)
  {
    ;
    for (; __first1 != __last1; ( ++__first1, (void) ++__first2))
      {
        if (!bool(__binary_pred(*__first1, *__first2)))
          {
            return false;
          }
      }
    return true;
  }
  template < typename _II1, typename _II2 >
  inline bool lexicographical_compare(_II1 __first1, _II1 __last1, _II2 __first2, _II2 __last2);
  template < typename _II1, typename _II2 >
  inline bool lexicographical_compare(_II1 __first1, _II1 __last1, _II2 __first2, _II2 __last2)
  {
    ;
    ;
    return std::__lexicographical_compare_aux(std::__niter_base(__first1), std::__niter_base(__last1), std::__niter_base(__first2), std::__niter_base(__last2));
  }
  template < typename _II1, typename _II2, typename _Compare >
  inline bool lexicographical_compare(_II1 __first1, _II1 __last1, _II2 __first2, _II2 __last2, _Compare __comp);
  template < typename _II1, typename _II2, typename _Compare >
  inline bool lexicographical_compare(_II1 __first1, _II1 __last1, _II2 __first2, _II2 __last2, _Compare __comp)
  {
    ;
    ;
    return std::__lexicographical_compare_impl(__first1, __last1, __first2, __last2, __gnu_cxx::__ops::__iter_comp_iter(__comp));
  }
  template < typename _InputIterator1, typename _InputIterator2, typename _BinaryPredicate >
  ::std::pair<_InputIterator1, _InputIterator2> __mismatch(_InputIterator1 __first1, _InputIterator1 __last1, _InputIterator2 __first2, _BinaryPredicate __binary_pred);
  template < typename _InputIterator1, typename _InputIterator2, typename _BinaryPredicate >
  ::std::pair<_InputIterator1, _InputIterator2> __mismatch(_InputIterator1 __first1, _InputIterator1 __last1, _InputIterator2 __first2, _BinaryPredicate __binary_pred)
  {
    while (__first1 != __last1 && __binary_pred(__first1, __first2))
      {
         ++__first1;
         ++__first2;
      }
    return ::std::pair<_InputIterator1, _InputIterator2>(__first1, __first2);
  }
  template < typename _InputIterator1, typename _InputIterator2 >
  inline ::std::pair<_InputIterator1, _InputIterator2> mismatch(_InputIterator1 __first1, _InputIterator1 __last1, _InputIterator2 __first2);
  template < typename _InputIterator1, typename _InputIterator2 >
  inline ::std::pair<_InputIterator1, _InputIterator2> mismatch(_InputIterator1 __first1, _InputIterator1 __last1, _InputIterator2 __first2)
  {
    ;
    return std::__mismatch(__first1, __last1, __first2, __gnu_cxx::__ops::__iter_equal_to_iter());
  }
  template < typename _InputIterator1, typename _InputIterator2, typename _BinaryPredicate >
  inline ::std::pair<_InputIterator1, _InputIterator2> mismatch(_InputIterator1 __first1, _InputIterator1 __last1, _InputIterator2 __first2, _BinaryPredicate __binary_pred);
  template < typename _InputIterator1, typename _InputIterator2, typename _BinaryPredicate >
  inline ::std::pair<_InputIterator1, _InputIterator2> mismatch(_InputIterator1 __first1, _InputIterator1 __last1, _InputIterator2 __first2, _BinaryPredicate __binary_pred)
  {
    ;
    return std::__mismatch(__first1, __last1, __first2, __gnu_cxx::__ops::__iter_comp_iter(__binary_pred));
  }
}
typedef __attribute__((mode(TC))) _Complex float __cfloat128;
typedef __float128 _Float128;
typedef float _Float32;
typedef double _Float64;
typedef double _Float32x;
typedef long double _Float64x;
typedef unsigned int wint_t;
typedef ::__mbstate_t mbstate_t;
struct tm;
extern "C"
{
  extern inline wchar_t *wcscpy(wchar_t *__restrict __dest, const wchar_t *__restrict __src) throw() __attribute__((__nonnull__(1, 2))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern inline wchar_t *wcsncpy(wchar_t *__restrict __dest, const wchar_t *__restrict __src, ::size_t __n) throw() __attribute__((__nonnull__(1, 2))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern inline wchar_t *wcscat(wchar_t *__restrict __dest, const wchar_t *__restrict __src) throw() __attribute__((__nonnull__(1, 2))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern inline wchar_t *wcsncat(wchar_t *__restrict __dest, const wchar_t *__restrict __src, ::size_t __n) throw() __attribute__((__nonnull__(1, 2))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern int wcscmp(const wchar_t *__s1, const wchar_t *__s2) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int wcsncmp(const wchar_t *__s1, const wchar_t *__s2, ::size_t __n) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int wcscasecmp(const wchar_t *__s1, const wchar_t *__s2) throw();
}
extern "C"
{
  extern int wcsncasecmp(const wchar_t *__s1, const wchar_t *__s2, ::size_t __n) throw();
}
extern "C"
{
  extern int wcscasecmp_l(const wchar_t *__s1, const wchar_t *__s2, ::locale_t __loc) throw();
}
extern "C"
{
  extern int wcsncasecmp_l(const wchar_t *__s1, const wchar_t *__s2, ::size_t __n, ::locale_t __loc) throw();
}
extern "C"
{
  extern int wcscoll(const wchar_t *__s1, const wchar_t *__s2) throw();
}
extern "C"
{
  extern ::size_t wcsxfrm(wchar_t *__restrict __s1, const wchar_t *__restrict __s2, ::size_t __n) throw();
}
extern "C"
{
  extern int wcscoll_l(const wchar_t *__s1, const wchar_t *__s2, ::locale_t __loc) throw();
}
extern "C"
{
  extern ::size_t wcsxfrm_l(wchar_t *__s1, const wchar_t *__s2, ::size_t __n, ::locale_t __loc) throw();
}
extern "C"
{
  extern wchar_t *wcsdup(const wchar_t *__s) throw() __attribute__((__malloc__));
}
wchar_t *wcschr(wchar_t *__wcs, wchar_t __wc) throw() __asm("wcschr") __attribute__((__pure__));
const wchar_t *wcschr(const wchar_t *__wcs, wchar_t __wc) throw() __asm("wcschr") __attribute__((__pure__));
wchar_t *wcsrchr(wchar_t *__wcs, wchar_t __wc) throw() __asm("wcsrchr") __attribute__((__pure__));
const wchar_t *wcsrchr(const wchar_t *__wcs, wchar_t __wc) throw() __asm("wcsrchr") __attribute__((__pure__));
extern "C"
{
  extern wchar_t *wcschrnul(const wchar_t *__s, wchar_t __wc) throw() __attribute__((__pure__));
}
extern "C"
{
  extern ::size_t wcscspn(const wchar_t *__wcs, const wchar_t *__reject) throw() __attribute__((__pure__));
}
extern "C"
{
  extern ::size_t wcsspn(const wchar_t *__wcs, const wchar_t *__accept) throw() __attribute__((__pure__));
}
wchar_t *wcspbrk(wchar_t *__wcs, const wchar_t *__accept) throw() __asm("wcspbrk") __attribute__((__pure__));
const wchar_t *wcspbrk(const wchar_t *__wcs, const wchar_t *__accept) throw() __asm("wcspbrk") __attribute__((__pure__));
wchar_t *wcsstr(wchar_t *__haystack, const wchar_t *__needle) throw() __asm("wcsstr") __attribute__((__pure__));
const wchar_t *wcsstr(const wchar_t *__haystack, const wchar_t *__needle) throw() __asm("wcsstr") __attribute__((__pure__));
extern "C"
{
  extern wchar_t *wcstok(wchar_t *__restrict __s, const wchar_t *__restrict __delim, wchar_t **__restrict __ptr) throw();
}
extern "C"
{
  extern ::size_t wcslen(const wchar_t *__s) throw() __attribute__((__pure__));
}
wchar_t *wcswcs(wchar_t *__haystack, const wchar_t *__needle) throw() __asm("wcswcs") __attribute__((__pure__));
const wchar_t *wcswcs(const wchar_t *__haystack, const wchar_t *__needle) throw() __asm("wcswcs") __attribute__((__pure__));
extern "C"
{
  extern ::size_t wcsnlen(const wchar_t *__s, ::size_t __maxlen) throw() __attribute__((__pure__));
}
wchar_t *wmemchr(wchar_t *__s, wchar_t __c, ::size_t __n) throw() __asm("wmemchr") __attribute__((__pure__));
const wchar_t *wmemchr(const wchar_t *__s, wchar_t __c, ::size_t __n) throw() __asm("wmemchr") __attribute__((__pure__));
extern "C"
{
  extern int wmemcmp(const wchar_t *__s1, const wchar_t *__s2, ::size_t __n) throw() __attribute__((__pure__));
}
extern "C"
{
  extern inline wchar_t *wmemcpy(wchar_t *__restrict __s1, const wchar_t *__restrict __s2, ::size_t __n) throw() __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern inline wchar_t *wmemmove(wchar_t *__s1, const wchar_t *__s2, ::size_t __n) throw() __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern inline wchar_t *wmemset(wchar_t *__s, wchar_t __c, ::size_t __n) throw() __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern inline wchar_t *wmempcpy(wchar_t *__restrict __s1, const wchar_t *__restrict __s2, ::size_t __n) throw() __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern inline ::wint_t btowc(int __c) throw() __attribute__((__leaf__)) __attribute__((__gnu_inline__));
}
extern "C"
{
  extern inline int wctob(::wint_t __wc) throw() __attribute__((__leaf__)) __attribute__((__gnu_inline__));
}
extern "C"
{
  extern int mbsinit(const ::mbstate_t *__ps) throw() __attribute__((__pure__));
}
extern "C"
{
  extern ::size_t mbrtowc(wchar_t *__restrict __pwc, const char *__restrict __s, ::size_t __n, ::mbstate_t *__restrict __p) throw();
}
extern "C"
{
  extern inline ::size_t wcrtomb(char *__restrict __s, wchar_t __wchar, ::mbstate_t *__restrict __ps) throw() __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern ::size_t __mbrlen(const char *__restrict __s, ::size_t __n, ::mbstate_t *__restrict __ps) throw();
}
extern "C"
{
  extern inline ::size_t mbrlen(const char *__restrict __s, ::size_t __n, ::mbstate_t *__restrict __ps) throw() __attribute__((__leaf__)) __attribute__((__gnu_inline__));
}
extern "C"
{
  extern ::wint_t __btowc_alias(int __c) __asm("btowc");
}
extern "C"
{
  extern inline __attribute__((__leaf__)) __attribute__((__gnu_inline__)) ::wint_t btowc(int __c) throw()
  {
    return (__builtin_constant_p(__c) && __c >= '\000') && __c <= '\177' ? (::wint_t)__c : ::__btowc_alias(__c);
  }
}
extern "C"
{
  extern int __wctob_alias(::wint_t __c) __asm("wctob");
}
extern "C"
{
  extern inline __attribute__((__leaf__)) __attribute__((__gnu_inline__)) int wctob(::wint_t __wc) throw()
  {
    return (__builtin_constant_p(__wc) && __wc >= L'\x0000') && __wc <= L'\x007f' ? (int)__wc : ::__wctob_alias(__wc);
  }
}
extern "C"
{
  extern inline __attribute__((__leaf__)) __attribute__((__gnu_inline__)) ::size_t mbrlen(const char *__restrict __s, ::size_t __n, ::mbstate_t *__restrict __ps) throw()
  {
    return __ps != 0L ? ::mbrtowc(0L, __s, __n, __ps) : ::__mbrlen(__s, __n, 0L);
  }
}
extern "C"
{
  extern inline ::size_t mbsrtowcs(wchar_t *__restrict __dst, const char **__restrict __src, ::size_t __len, ::mbstate_t *__restrict __ps) throw() __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern inline ::size_t wcsrtombs(char *__restrict __dst, const wchar_t **__restrict __src, ::size_t __len, ::mbstate_t *__restrict __ps) throw() __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern inline ::size_t mbsnrtowcs(wchar_t *__restrict __dst, const char **__restrict __src, ::size_t __nmc, ::size_t __len, ::mbstate_t *__restrict __ps) throw() __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern inline ::size_t wcsnrtombs(char *__restrict __dst, const wchar_t **__restrict __src, ::size_t __nwc, ::size_t __len, ::mbstate_t *__restrict __ps) throw() __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern int wcwidth(wchar_t __c) throw();
}
extern "C"
{
  extern int wcswidth(const wchar_t *__s, ::size_t __n) throw();
}
extern "C"
{
  extern double wcstod(const wchar_t *__restrict __nptr, wchar_t **__restrict __endptr) throw();
}
extern "C"
{
  extern float wcstof(const wchar_t *__restrict __nptr, wchar_t **__restrict __endptr) throw();
}
extern "C"
{
  extern long double wcstold(const wchar_t *__restrict __nptr, wchar_t **__restrict __endptr) throw();
}
extern "C"
{
  extern ::_Float32 wcstof32(const wchar_t *__restrict __nptr, wchar_t **__restrict __endptr) throw();
}
extern "C"
{
  extern ::_Float64 wcstof64(const wchar_t *__restrict __nptr, wchar_t **__restrict __endptr) throw();
}
extern "C"
{
  extern ::_Float128 wcstof128(const wchar_t *__restrict __nptr, wchar_t **__restrict __endptr) throw();
}
extern "C"
{
  extern ::_Float32x wcstof32x(const wchar_t *__restrict __nptr, wchar_t **__restrict __endptr) throw();
}
extern "C"
{
  extern ::_Float64x wcstof64x(const wchar_t *__restrict __nptr, wchar_t **__restrict __endptr) throw();
}
extern "C"
{
  extern long int wcstol(const wchar_t *__restrict __nptr, wchar_t **__restrict __endptr, int __base) throw();
}
extern "C"
{
  extern unsigned long int wcstoul(const wchar_t *__restrict __nptr, wchar_t **__restrict __endptr, int __base) throw();
}
extern "C"
{
  extern long long int wcstoll(const wchar_t *__restrict __nptr, wchar_t **__restrict __endptr, int __base) throw();
}
extern "C"
{
  extern unsigned long long int wcstoull(const wchar_t *__restrict __nptr, wchar_t **__restrict __endptr, int __base) throw();
}
extern "C"
{
  extern long long int wcstoq(const wchar_t *__restrict __nptr, wchar_t **__restrict __endptr, int __base) throw();
}
extern "C"
{
  extern unsigned long long int wcstouq(const wchar_t *__restrict __nptr, wchar_t **__restrict __endptr, int __base) throw();
}
extern "C"
{
  extern long int wcstol_l(const wchar_t *__restrict __nptr, wchar_t **__restrict __endptr, int __base, ::locale_t __loc) throw();
}
extern "C"
{
  extern unsigned long int wcstoul_l(const wchar_t *__restrict __nptr, wchar_t **__restrict __endptr, int __base, ::locale_t __loc) throw();
}
extern "C"
{
  extern long long int wcstoll_l(const wchar_t *__restrict __nptr, wchar_t **__restrict __endptr, int __base, ::locale_t __loc) throw();
}
extern "C"
{
  extern unsigned long long int wcstoull_l(const wchar_t *__restrict __nptr, wchar_t **__restrict __endptr, int __base, ::locale_t __loc) throw();
}
extern "C"
{
  extern double wcstod_l(const wchar_t *__restrict __nptr, wchar_t **__restrict __endptr, ::locale_t __loc) throw();
}
extern "C"
{
  extern float wcstof_l(const wchar_t *__restrict __nptr, wchar_t **__restrict __endptr, ::locale_t __loc) throw();
}
extern "C"
{
  extern long double wcstold_l(const wchar_t *__restrict __nptr, wchar_t **__restrict __endptr, ::locale_t __loc) throw();
}
extern "C"
{
  extern ::_Float32 wcstof32_l(const wchar_t *__restrict __nptr, wchar_t **__restrict __endptr, ::locale_t __loc) throw();
}
extern "C"
{
  extern ::_Float64 wcstof64_l(const wchar_t *__restrict __nptr, wchar_t **__restrict __endptr, ::locale_t __loc) throw();
}
extern "C"
{
  extern ::_Float128 wcstof128_l(const wchar_t *__restrict __nptr, wchar_t **__restrict __endptr, ::locale_t __loc) throw();
}
extern "C"
{
  extern ::_Float32x wcstof32x_l(const wchar_t *__restrict __nptr, wchar_t **__restrict __endptr, ::locale_t __loc) throw();
}
extern "C"
{
  extern ::_Float64x wcstof64x_l(const wchar_t *__restrict __nptr, wchar_t **__restrict __endptr, ::locale_t __loc) throw();
}
extern "C"
{
  extern inline wchar_t *wcpcpy(wchar_t *__restrict __dest, const wchar_t *__restrict __src) throw() __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern inline wchar_t *wcpncpy(wchar_t *__restrict __dest, const wchar_t *__restrict __src, ::size_t __n) throw() __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern ::__FILE *open_wmemstream(wchar_t **__bufloc, ::size_t *__sizeloc) throw();
}
extern "C"
{
  extern int fwide(::__FILE *__fp, int __mode) throw();
}
extern "C"
{
  extern inline int fwprintf(::__FILE *__restrict __stream, const wchar_t *__restrict __fmt, ...) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern inline int wprintf(const wchar_t *__restrict __fmt, ...) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern inline int swprintf(wchar_t *__restrict __s, ::size_t __n, const wchar_t *__restrict __fmt, ...) throw() __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern inline int vfwprintf(::__FILE *__restrict __stream, const wchar_t *__restrict __fmt, ::__gnuc_va_list __ap) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern inline int vwprintf(const wchar_t *__restrict __fmt, ::__gnuc_va_list __ap) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern inline int vswprintf(wchar_t *__restrict __s, ::size_t __n, const wchar_t *__restrict __fmt, ::__gnuc_va_list __ap) throw() __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern int fwscanf(::__FILE *__restrict __stream, const wchar_t *__restrict __format, ...);
}
extern "C"
{
  extern int wscanf(const wchar_t *__restrict __format, ...);
}
extern "C"
{
  extern int swscanf(const wchar_t *__restrict __s, const wchar_t *__restrict __format, ...) throw();
}
extern "C"
{
  extern int vfwscanf(::__FILE *__restrict __s, const wchar_t *__restrict __format, ::__gnuc_va_list __arg);
}
extern "C"
{
  extern int vwscanf(const wchar_t *__restrict __format, ::__gnuc_va_list __arg);
}
extern "C"
{
  extern int vswscanf(const wchar_t *__restrict __s, const wchar_t *__restrict __format, ::__gnuc_va_list __arg) throw();
}
extern "C"
{
  extern ::wint_t fgetwc(::__FILE *__stream);
}
extern "C"
{
  extern ::wint_t getwc(::__FILE *__stream);
}
extern "C"
{
  extern ::wint_t getwchar();
}
extern "C"
{
  extern ::wint_t fputwc(wchar_t __wc, ::__FILE *__stream);
}
extern "C"
{
  extern ::wint_t putwc(wchar_t __wc, ::__FILE *__stream);
}
extern "C"
{
  extern ::wint_t putwchar(wchar_t __wc);
}
extern "C"
{
  extern inline wchar_t *fgetws(wchar_t *__restrict __s, int __n, ::__FILE *__restrict __stream) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int fputws(const wchar_t *__restrict __ws, ::__FILE *__restrict __stream);
}
extern "C"
{
  extern ::wint_t ungetwc(::wint_t __wc, ::__FILE *__stream);
}
extern "C"
{
  extern ::wint_t getwc_unlocked(::__FILE *__stream);
}
extern "C"
{
  extern ::wint_t getwchar_unlocked();
}
extern "C"
{
  extern ::wint_t fgetwc_unlocked(::__FILE *__stream);
}
extern "C"
{
  extern ::wint_t fputwc_unlocked(wchar_t __wc, ::__FILE *__stream);
}
extern "C"
{
  extern ::wint_t putwc_unlocked(wchar_t __wc, ::__FILE *__stream);
}
extern "C"
{
  extern ::wint_t putwchar_unlocked(wchar_t __wc);
}
extern "C"
{
  extern inline wchar_t *fgetws_unlocked(wchar_t *__restrict __s, int __n, ::__FILE *__restrict __stream) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int fputws_unlocked(const wchar_t *__restrict __ws, ::__FILE *__restrict __stream);
}
extern "C"
{
  extern ::size_t wcsftime(wchar_t *__restrict __s, ::size_t __maxsize, const wchar_t *__restrict __format, const ::tm *__restrict __tp) throw();
}
extern "C"
{
  extern ::size_t wcsftime_l(wchar_t *__restrict __s, ::size_t __maxsize, const wchar_t *__restrict __format, const ::tm *__restrict __tp, ::locale_t __loc) throw();
}
extern "C"
{
  extern wchar_t *__wmemcpy_chk(wchar_t *__restrict __s1, const wchar_t *__restrict __s2, ::size_t __n, ::size_t __ns1) throw();
}
extern "C"
{
  extern wchar_t *__wmemcpy_alias(wchar_t *__restrict __s1, const wchar_t *__restrict __s2, ::size_t __n) throw() __asm("""wmemcpy");
}
extern "C"
{
  extern wchar_t *__wmemcpy_chk_warn(wchar_t *__restrict __s1, const wchar_t *__restrict __s2, ::size_t __n, ::size_t __ns1) throw() __asm("""__wmemcpy_chk") __attribute__((__warning__("wmemcpy called with length bigger than size of destination ""buffer")));
}
extern "C"
{
  extern inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) wchar_t *wmemcpy(wchar_t *__restrict __s1, const wchar_t *__restrict __s2, ::size_t __n) throw()
  {
    if (__builtin_object_size(__s1, 0) != (::size_t) -1)
      {
        if (!__builtin_constant_p(__n))
          {
            return ::__wmemcpy_chk(__s1, __s2, __n, __builtin_object_size(__s1, 0) / sizeof(wchar_t));
          }
        if (__n > __builtin_object_size(__s1, 0) / sizeof(wchar_t))
          {
            return ::__wmemcpy_chk_warn(__s1, __s2, __n, __builtin_object_size(__s1, 0) / sizeof(wchar_t));
          }
      }
    return ::__wmemcpy_alias(__s1, __s2, __n);
  }
}
extern "C"
{
  extern wchar_t *__wmemmove_chk(wchar_t *__s1, const wchar_t *__s2, ::size_t __n, ::size_t __ns1) throw();
}
extern "C"
{
  extern wchar_t *__wmemmove_alias(wchar_t *__s1, const wchar_t *__s2, ::size_t __n) throw() __asm("""wmemmove");
}
extern "C"
{
  extern wchar_t *__wmemmove_chk_warn(wchar_t *__s1, const wchar_t *__s2, ::size_t __n, ::size_t __ns1) throw() __asm("""__wmemmove_chk") __attribute__((__warning__("wmemmove called with length bigger than size of destination ""buffer")));
}
extern "C"
{
  extern inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) wchar_t *wmemmove(wchar_t *__s1, const wchar_t *__s2, ::size_t __n) throw()
  {
    if (__builtin_object_size(__s1, 0) != (::size_t) -1)
      {
        if (!__builtin_constant_p(__n))
          {
            return ::__wmemmove_chk(__s1, __s2, __n, __builtin_object_size(__s1, 0) / sizeof(wchar_t));
          }
        if (__n > __builtin_object_size(__s1, 0) / sizeof(wchar_t))
          {
            return ::__wmemmove_chk_warn(__s1, __s2, __n, __builtin_object_size(__s1, 0) / sizeof(wchar_t));
          }
      }
    return ::__wmemmove_alias(__s1, __s2, __n);
  }
}
extern "C"
{
  extern wchar_t *__wmempcpy_chk(wchar_t *__restrict __s1, const wchar_t *__restrict __s2, ::size_t __n, ::size_t __ns1) throw();
}
extern "C"
{
  extern wchar_t *__wmempcpy_alias(wchar_t *__restrict __s1, const wchar_t *__restrict __s2, ::size_t __n) throw() __asm("""wmempcpy");
}
extern "C"
{
  extern wchar_t *__wmempcpy_chk_warn(wchar_t *__restrict __s1, const wchar_t *__restrict __s2, ::size_t __n, ::size_t __ns1) throw() __asm("""__wmempcpy_chk") __attribute__((__warning__("wmempcpy called with length bigger than size of destination ""buffer")));
}
extern "C"
{
  extern inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) wchar_t *wmempcpy(wchar_t *__restrict __s1, const wchar_t *__restrict __s2, ::size_t __n) throw()
  {
    if (__builtin_object_size(__s1, 0) != (::size_t) -1)
      {
        if (!__builtin_constant_p(__n))
          {
            return ::__wmempcpy_chk(__s1, __s2, __n, __builtin_object_size(__s1, 0) / sizeof(wchar_t));
          }
        if (__n > __builtin_object_size(__s1, 0) / sizeof(wchar_t))
          {
            return ::__wmempcpy_chk_warn(__s1, __s2, __n, __builtin_object_size(__s1, 0) / sizeof(wchar_t));
          }
      }
    return ::__wmempcpy_alias(__s1, __s2, __n);
  }
}
extern "C"
{
  extern wchar_t *__wmemset_chk(wchar_t *__s, wchar_t __c, ::size_t __n, ::size_t __ns) throw();
}
extern "C"
{
  extern wchar_t *__wmemset_alias(wchar_t *__s, wchar_t __c, ::size_t __n) throw() __asm("""wmemset");
}
extern "C"
{
  extern wchar_t *__wmemset_chk_warn(wchar_t *__s, wchar_t __c, ::size_t __n, ::size_t __ns) throw() __asm("""__wmemset_chk") __attribute__((__warning__("wmemset called with length bigger than size of destination ""buffer")));
}
extern "C"
{
  extern inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) wchar_t *wmemset(wchar_t *__s, wchar_t __c, ::size_t __n) throw()
  {
    if (__builtin_object_size(__s, 0) != (::size_t) -1)
      {
        if (!__builtin_constant_p(__n))
          {
            return ::__wmemset_chk(__s, __c, __n, __builtin_object_size(__s, 0) / sizeof(wchar_t));
          }
        if (__n > __builtin_object_size(__s, 0) / sizeof(wchar_t))
          {
            return ::__wmemset_chk_warn(__s, __c, __n, __builtin_object_size(__s, 0) / sizeof(wchar_t));
          }
      }
    return ::__wmemset_alias(__s, __c, __n);
  }
}
extern "C"
{
  extern wchar_t *__wcscpy_chk(wchar_t *__restrict __dest, const wchar_t *__restrict __src, ::size_t __n) throw();
}
extern "C"
{
  extern wchar_t *__wcscpy_alias(wchar_t *__restrict __dest, const wchar_t *__restrict __src) throw() __asm("""wcscpy");
}
extern "C"
{
  extern inline __attribute__((__nonnull__(1, 2))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) wchar_t *wcscpy(wchar_t *__restrict __dest, const wchar_t *__restrict __src) throw()
  {
    if (__builtin_object_size(__dest, 2 > 1) != (::size_t) -1)
      {
        return ::__wcscpy_chk(__dest, __src, __builtin_object_size(__dest, 2 > 1) / sizeof(wchar_t));
      }
    return ::__wcscpy_alias(__dest, __src);
  }
}
extern "C"
{
  extern wchar_t *__wcpcpy_chk(wchar_t *__restrict __dest, const wchar_t *__restrict __src, ::size_t __destlen) throw();
}
extern "C"
{
  extern wchar_t *__wcpcpy_alias(wchar_t *__restrict __dest, const wchar_t *__restrict __src) throw() __asm("""wcpcpy");
}
extern "C"
{
  extern inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) wchar_t *wcpcpy(wchar_t *__restrict __dest, const wchar_t *__restrict __src) throw()
  {
    if (__builtin_object_size(__dest, 2 > 1) != (::size_t) -1)
      {
        return ::__wcpcpy_chk(__dest, __src, __builtin_object_size(__dest, 2 > 1) / sizeof(wchar_t));
      }
    return ::__wcpcpy_alias(__dest, __src);
  }
}
extern "C"
{
  extern wchar_t *__wcsncpy_chk(wchar_t *__restrict __dest, const wchar_t *__restrict __src, ::size_t __n, ::size_t __destlen) throw();
}
extern "C"
{
  extern wchar_t *__wcsncpy_alias(wchar_t *__restrict __dest, const wchar_t *__restrict __src, ::size_t __n) throw() __asm("""wcsncpy");
}
extern "C"
{
  extern wchar_t *__wcsncpy_chk_warn(wchar_t *__restrict __dest, const wchar_t *__restrict __src, ::size_t __n, ::size_t __destlen) throw() __asm("""__wcsncpy_chk") __attribute__((__warning__("wcsncpy called with length bigger than size of destination ""buffer")));
}
extern "C"
{
  extern inline __attribute__((__nonnull__(1, 2))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) wchar_t *wcsncpy(wchar_t *__restrict __dest, const wchar_t *__restrict __src, ::size_t __n) throw()
  {
    if (__builtin_object_size(__dest, 2 > 1) != (::size_t) -1)
      {
        if (!__builtin_constant_p(__n))
          {
            return ::__wcsncpy_chk(__dest, __src, __n, __builtin_object_size(__dest, 2 > 1) / sizeof(wchar_t));
          }
        if (__n > __builtin_object_size(__dest, 2 > 1) / sizeof(wchar_t))
          {
            return ::__wcsncpy_chk_warn(__dest, __src, __n, __builtin_object_size(__dest, 2 > 1) / sizeof(wchar_t));
          }
      }
    return ::__wcsncpy_alias(__dest, __src, __n);
  }
}
extern "C"
{
  extern wchar_t *__wcpncpy_chk(wchar_t *__restrict __dest, const wchar_t *__restrict __src, ::size_t __n, ::size_t __destlen) throw();
}
extern "C"
{
  extern wchar_t *__wcpncpy_alias(wchar_t *__restrict __dest, const wchar_t *__restrict __src, ::size_t __n) throw() __asm("""wcpncpy");
}
extern "C"
{
  extern wchar_t *__wcpncpy_chk_warn(wchar_t *__restrict __dest, const wchar_t *__restrict __src, ::size_t __n, ::size_t __destlen) throw() __asm("""__wcpncpy_chk") __attribute__((__warning__("wcpncpy called with length bigger than size of destination ""buffer")));
}
extern "C"
{
  extern inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) wchar_t *wcpncpy(wchar_t *__restrict __dest, const wchar_t *__restrict __src, ::size_t __n) throw()
  {
    if (__builtin_object_size(__dest, 2 > 1) != (::size_t) -1)
      {
        if (!__builtin_constant_p(__n))
          {
            return ::__wcpncpy_chk(__dest, __src, __n, __builtin_object_size(__dest, 2 > 1) / sizeof(wchar_t));
          }
        if (__n > __builtin_object_size(__dest, 2 > 1) / sizeof(wchar_t))
          {
            return ::__wcpncpy_chk_warn(__dest, __src, __n, __builtin_object_size(__dest, 2 > 1) / sizeof(wchar_t));
          }
      }
    return ::__wcpncpy_alias(__dest, __src, __n);
  }
}
extern "C"
{
  extern wchar_t *__wcscat_chk(wchar_t *__restrict __dest, const wchar_t *__restrict __src, ::size_t __destlen) throw();
}
extern "C"
{
  extern wchar_t *__wcscat_alias(wchar_t *__restrict __dest, const wchar_t *__restrict __src) throw() __asm("""wcscat");
}
extern "C"
{
  extern inline __attribute__((__nonnull__(1, 2))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) wchar_t *wcscat(wchar_t *__restrict __dest, const wchar_t *__restrict __src) throw()
  {
    if (__builtin_object_size(__dest, 2 > 1) != (::size_t) -1)
      {
        return ::__wcscat_chk(__dest, __src, __builtin_object_size(__dest, 2 > 1) / sizeof(wchar_t));
      }
    return ::__wcscat_alias(__dest, __src);
  }
}
extern "C"
{
  extern wchar_t *__wcsncat_chk(wchar_t *__restrict __dest, const wchar_t *__restrict __src, ::size_t __n, ::size_t __destlen) throw();
}
extern "C"
{
  extern wchar_t *__wcsncat_alias(wchar_t *__restrict __dest, const wchar_t *__restrict __src, ::size_t __n) throw() __asm("""wcsncat");
}
extern "C"
{
  extern inline __attribute__((__nonnull__(1, 2))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) wchar_t *wcsncat(wchar_t *__restrict __dest, const wchar_t *__restrict __src, ::size_t __n) throw()
  {
    if (__builtin_object_size(__dest, 2 > 1) != (::size_t) -1)
      {
        return ::__wcsncat_chk(__dest, __src, __n, __builtin_object_size(__dest, 2 > 1) / sizeof(wchar_t));
      }
    return ::__wcsncat_alias(__dest, __src, __n);
  }
}
extern "C"
{
  extern int __swprintf_chk(wchar_t *__restrict __s, ::size_t __n, int __flag, ::size_t __s_len, const wchar_t *__restrict __format, ...) throw();
}
extern "C"
{
  extern int __swprintf_alias(wchar_t *__restrict __s, ::size_t __n, const wchar_t *__restrict __fmt, ...) throw() __asm("""swprintf");
}
extern "C"
{
  extern inline __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) int swprintf(wchar_t *__restrict __s, ::size_t __n, const wchar_t *__restrict __fmt, ...) throw()
  {
    if (__builtin_object_size(__s, 2 > 1) != (::size_t) -1 || 2 > 1)
      {
        return ::__swprintf_chk(__s, __n, 2 - 1, __builtin_object_size(__s, 2 > 1) / sizeof(wchar_t), __fmt, __builtin_va_arg_pack());
      }
    return ::__swprintf_alias(__s, __n, __fmt, __builtin_va_arg_pack());
  }
}
extern "C"
{
  extern int __vswprintf_chk(wchar_t *__restrict __s, ::size_t __n, int __flag, ::size_t __s_len, const wchar_t *__restrict __format, ::__gnuc_va_list __arg) throw();
}
extern "C"
{
  extern int __vswprintf_alias(wchar_t *__restrict __s, ::size_t __n, const wchar_t *__restrict __fmt, ::__gnuc_va_list __ap) throw() __asm("""vswprintf");
}
extern "C"
{
  extern inline __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) int vswprintf(wchar_t *__restrict __s, ::size_t __n, const wchar_t *__restrict __fmt, ::__gnuc_va_list __ap) throw()
  {
    if (__builtin_object_size(__s, 2 > 1) != (::size_t) -1 || 2 > 1)
      {
        return ::__vswprintf_chk(__s, __n, 2 - 1, __builtin_object_size(__s, 2 > 1) / sizeof(wchar_t), __fmt, __ap);
      }
    return ::__vswprintf_alias(__s, __n, __fmt, __ap);
  }
}
extern "C"
{
  extern int __fwprintf_chk(::__FILE *__restrict __stream, int __flag, const wchar_t *__restrict __format, ...);
}
extern "C"
{
  extern int __wprintf_chk(int __flag, const wchar_t *__restrict __format, ...);
}
extern "C"
{
  extern int __vfwprintf_chk(::__FILE *__restrict __stream, int __flag, const wchar_t *__restrict __format, ::__gnuc_va_list __ap);
}
extern "C"
{
  extern int __vwprintf_chk(int __flag, const wchar_t *__restrict __format, ::__gnuc_va_list __ap);
}
extern "C"
{
  extern inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) int wprintf(const wchar_t *__restrict __fmt, ...)
  {
    return ::__wprintf_chk(2 - 1, __fmt, __builtin_va_arg_pack());
  }
}
extern "C"
{
  extern inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) int fwprintf(::__FILE *__restrict __stream, const wchar_t *__restrict __fmt, ...)
  {
    return ::__fwprintf_chk(__stream, 2 - 1, __fmt, __builtin_va_arg_pack());
  }
}
extern "C"
{
  extern inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) int vwprintf(const wchar_t *__restrict __fmt, ::__gnuc_va_list __ap)
  {
    return ::__vwprintf_chk(2 - 1, __fmt, __ap);
  }
}
extern "C"
{
  extern inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) int vfwprintf(::__FILE *__restrict __stream, const wchar_t *__restrict __fmt, ::__gnuc_va_list __ap)
  {
    return ::__vfwprintf_chk(__stream, 2 - 1, __fmt, __ap);
  }
}
extern "C"
{
  extern wchar_t *__fgetws_chk(wchar_t *__restrict __s, ::size_t __size, int __n, ::__FILE *__restrict __stream) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern wchar_t *__fgetws_alias(wchar_t *__restrict __s, int __n, ::__FILE *__restrict __stream) __asm("""fgetws") __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern wchar_t *__fgetws_chk_warn(wchar_t *__restrict __s, ::size_t __size, int __n, ::__FILE *__restrict __stream) __asm("""__fgetws_chk") __attribute__((__warn_unused_result__)) __attribute__((__warning__("fgetws called with bigger size than length ""of destination buffer")));
}
extern "C"
{
  extern inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) __attribute__((__warn_unused_result__)) wchar_t *fgetws(wchar_t *__restrict __s, int __n, ::__FILE *__restrict __stream)
  {
    if (__builtin_object_size(__s, 2 > 1) != (::size_t) -1)
      {
        if (!__builtin_constant_p(__n) || __n <= 0)
          {
            return ::__fgetws_chk(__s, __builtin_object_size(__s, 2 > 1) / sizeof(wchar_t), __n, __stream);
          }
        if ((::size_t)__n > __builtin_object_size(__s, 2 > 1) / sizeof(wchar_t))
          {
            return ::__fgetws_chk_warn(__s, __builtin_object_size(__s, 2 > 1) / sizeof(wchar_t), __n, __stream);
          }
      }
    return ::__fgetws_alias(__s, __n, __stream);
  }
}
extern "C"
{
  extern wchar_t *__fgetws_unlocked_chk(wchar_t *__restrict __s, ::size_t __size, int __n, ::__FILE *__restrict __stream) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern wchar_t *__fgetws_unlocked_alias(wchar_t *__restrict __s, int __n, ::__FILE *__restrict __stream) __asm("""fgetws_unlocked") __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern wchar_t *__fgetws_unlocked_chk_warn(wchar_t *__restrict __s, ::size_t __size, int __n, ::__FILE *__restrict __stream) __asm("""__fgetws_unlocked_chk") __attribute__((__warn_unused_result__)) __attribute__((__warning__("fgetws_unlocked called with bigger size than length ""of destination buffer")));
}
extern "C"
{
  extern inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) __attribute__((__warn_unused_result__)) wchar_t *fgetws_unlocked(wchar_t *__restrict __s, int __n, ::__FILE *__restrict __stream)
  {
    if (__builtin_object_size(__s, 2 > 1) != (::size_t) -1)
      {
        if (!__builtin_constant_p(__n) || __n <= 0)
          {
            return ::__fgetws_unlocked_chk(__s, __builtin_object_size(__s, 2 > 1) / sizeof(wchar_t), __n, __stream);
          }
        if ((::size_t)__n > __builtin_object_size(__s, 2 > 1) / sizeof(wchar_t))
          {
            return ::__fgetws_unlocked_chk_warn(__s, __builtin_object_size(__s, 2 > 1) / sizeof(wchar_t), __n, __stream);
          }
      }
    return ::__fgetws_unlocked_alias(__s, __n, __stream);
  }
}
extern "C"
{
  extern ::size_t __wcrtomb_chk(char *__restrict __s, wchar_t __wchar, ::mbstate_t *__restrict __p, ::size_t __buflen) throw() __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern ::size_t __wcrtomb_alias(char *__restrict __s, wchar_t __wchar, ::mbstate_t *__restrict __ps) throw() __asm("""wcrtomb") __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern inline __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) __attribute__((__warn_unused_result__)) ::size_t wcrtomb(char *__restrict __s, wchar_t __wchar, ::mbstate_t *__restrict __ps) throw()
  {
    if (__builtin_object_size(__s, 2 > 1) != (::size_t) -1 && 16 > __builtin_object_size(__s, 2 > 1))
      {
        return ::__wcrtomb_chk(__s, __wchar, __ps, __builtin_object_size(__s, 2 > 1));
      }
    return ::__wcrtomb_alias(__s, __wchar, __ps);
  }
}
extern "C"
{
  extern ::size_t __mbsrtowcs_chk(wchar_t *__restrict __dst, const char **__restrict __src, ::size_t __len, ::mbstate_t *__restrict __ps, ::size_t __dstlen) throw();
}
extern "C"
{
  extern ::size_t __mbsrtowcs_alias(wchar_t *__restrict __dst, const char **__restrict __src, ::size_t __len, ::mbstate_t *__restrict __ps) throw() __asm("""mbsrtowcs");
}
extern "C"
{
  extern ::size_t __mbsrtowcs_chk_warn(wchar_t *__restrict __dst, const char **__restrict __src, ::size_t __len, ::mbstate_t *__restrict __ps, ::size_t __dstlen) throw() __asm("""__mbsrtowcs_chk") __attribute__((__warning__("mbsrtowcs called with dst buffer smaller than len ""* sizeof (wchar_t)")));
}
extern "C"
{
  extern inline __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) ::size_t mbsrtowcs(wchar_t *__restrict __dst, const char **__restrict __src, ::size_t __len, ::mbstate_t *__restrict __ps) throw()
  {
    if (__builtin_object_size(__dst, 2 > 1) != (::size_t) -1)
      {
        if (!__builtin_constant_p(__len))
          {
            return ::__mbsrtowcs_chk(__dst, __src, __len, __ps, __builtin_object_size(__dst, 2 > 1) / sizeof(wchar_t));
          }
        if (__len > __builtin_object_size(__dst, 2 > 1) / sizeof(wchar_t))
          {
            return ::__mbsrtowcs_chk_warn(__dst, __src, __len, __ps, __builtin_object_size(__dst, 2 > 1) / sizeof(wchar_t));
          }
      }
    return ::__mbsrtowcs_alias(__dst, __src, __len, __ps);
  }
}
extern "C"
{
  extern ::size_t __wcsrtombs_chk(char *__restrict __dst, const wchar_t **__restrict __src, ::size_t __len, ::mbstate_t *__restrict __ps, ::size_t __dstlen) throw();
}
extern "C"
{
  extern ::size_t __wcsrtombs_alias(char *__restrict __dst, const wchar_t **__restrict __src, ::size_t __len, ::mbstate_t *__restrict __ps) throw() __asm("""wcsrtombs");
}
extern "C"
{
  extern ::size_t __wcsrtombs_chk_warn(char *__restrict __dst, const wchar_t **__restrict __src, ::size_t __len, ::mbstate_t *__restrict __ps, ::size_t __dstlen) throw() __asm("""__wcsrtombs_chk") __attribute__((__warning__("wcsrtombs called with dst buffer smaller than len")));
}
extern "C"
{
  extern inline __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) ::size_t wcsrtombs(char *__restrict __dst, const wchar_t **__restrict __src, ::size_t __len, ::mbstate_t *__restrict __ps) throw()
  {
    if (__builtin_object_size(__dst, 2 > 1) != (::size_t) -1)
      {
        if (!__builtin_constant_p(__len))
          {
            return ::__wcsrtombs_chk(__dst, __src, __len, __ps, __builtin_object_size(__dst, 2 > 1));
          }
        if (__len > __builtin_object_size(__dst, 2 > 1))
          {
            return ::__wcsrtombs_chk_warn(__dst, __src, __len, __ps, __builtin_object_size(__dst, 2 > 1));
          }
      }
    return ::__wcsrtombs_alias(__dst, __src, __len, __ps);
  }
}
extern "C"
{
  extern ::size_t __mbsnrtowcs_chk(wchar_t *__restrict __dst, const char **__restrict __src, ::size_t __nmc, ::size_t __len, ::mbstate_t *__restrict __ps, ::size_t __dstlen) throw();
}
extern "C"
{
  extern ::size_t __mbsnrtowcs_alias(wchar_t *__restrict __dst, const char **__restrict __src, ::size_t __nmc, ::size_t __len, ::mbstate_t *__restrict __ps) throw() __asm("""mbsnrtowcs");
}
extern "C"
{
  extern ::size_t __mbsnrtowcs_chk_warn(wchar_t *__restrict __dst, const char **__restrict __src, ::size_t __nmc, ::size_t __len, ::mbstate_t *__restrict __ps, ::size_t __dstlen) throw() __asm("""__mbsnrtowcs_chk") __attribute__((__warning__("mbsnrtowcs called with dst buffer smaller than len ""* sizeof (wchar_t)")));
}
extern "C"
{
  extern inline __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) ::size_t mbsnrtowcs(wchar_t *__restrict __dst, const char **__restrict __src, ::size_t __nmc, ::size_t __len, ::mbstate_t *__restrict __ps) throw()
  {
    if (__builtin_object_size(__dst, 2 > 1) != (::size_t) -1)
      {
        if (!__builtin_constant_p(__len))
          {
            return ::__mbsnrtowcs_chk(__dst, __src, __nmc, __len, __ps, __builtin_object_size(__dst, 2 > 1) / sizeof(wchar_t));
          }
        if (__len > __builtin_object_size(__dst, 2 > 1) / sizeof(wchar_t))
          {
            return ::__mbsnrtowcs_chk_warn(__dst, __src, __nmc, __len, __ps, __builtin_object_size(__dst, 2 > 1) / sizeof(wchar_t));
          }
      }
    return ::__mbsnrtowcs_alias(__dst, __src, __nmc, __len, __ps);
  }
}
extern "C"
{
  extern ::size_t __wcsnrtombs_chk(char *__restrict __dst, const wchar_t **__restrict __src, ::size_t __nwc, ::size_t __len, ::mbstate_t *__restrict __ps, ::size_t __dstlen) throw();
}
extern "C"
{
  extern ::size_t __wcsnrtombs_alias(char *__restrict __dst, const wchar_t **__restrict __src, ::size_t __nwc, ::size_t __len, ::mbstate_t *__restrict __ps) throw() __asm("""wcsnrtombs");
}
extern "C"
{
  extern ::size_t __wcsnrtombs_chk_warn(char *__restrict __dst, const wchar_t **__restrict __src, ::size_t __nwc, ::size_t __len, ::mbstate_t *__restrict __ps, ::size_t __dstlen) throw() __asm("""__wcsnrtombs_chk") __attribute__((__warning__("wcsnrtombs called with dst buffer smaller than len")));
}
extern "C"
{
  extern inline __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) ::size_t wcsnrtombs(char *__restrict __dst, const wchar_t **__restrict __src, ::size_t __nwc, ::size_t __len, ::mbstate_t *__restrict __ps) throw()
  {
    if (__builtin_object_size(__dst, 2 > 1) != (::size_t) -1)
      {
        if (!__builtin_constant_p(__len))
          {
            return ::__wcsnrtombs_chk(__dst, __src, __nwc, __len, __ps, __builtin_object_size(__dst, 2 > 1));
          }
        if (__len > __builtin_object_size(__dst, 2 > 1))
          {
            return ::__wcsnrtombs_chk_warn(__dst, __src, __nwc, __len, __ps, __builtin_object_size(__dst, 2 > 1));
          }
      }
    return ::__wcsnrtombs_alias(__dst, __src, __nwc, __len, __ps);
  }
}
namespace std __attribute__((__visibility__("default"))) {
  using ::mbstate_t;
  using ::wint_t;
  using ::btowc;
  using ::fgetwc;
  using ::fgetws;
  using ::fputwc;
  using ::fputws;
  using ::fwide;
  using ::fwprintf;
  using ::fwscanf;
  using ::getwc;
  using ::getwchar;
  using ::mbrlen;
  using ::mbrtowc;
  using ::mbsinit;
  using ::mbsrtowcs;
  using ::putwc;
  using ::putwchar;
  using ::swprintf;
  using ::swscanf;
  using ::ungetwc;
  using ::vfwprintf;
  using ::vfwscanf;
  using ::vswprintf;
  using ::vswscanf;
  using ::vwprintf;
  using ::vwscanf;
  using ::wcrtomb;
  using ::wcscat;
  using ::wcscmp;
  using ::wcscoll;
  using ::wcscpy;
  using ::wcscspn;
  using ::wcsftime;
  using ::wcslen;
  using ::wcsncat;
  using ::wcsncmp;
  using ::wcsncpy;
  using ::wcsrtombs;
  using ::wcsspn;
  using ::wcstod;
  using ::wcstof;
  using ::wcstok;
  using ::wcstol;
  using ::wcstoul;
  using ::wcsxfrm;
  using ::wctob;
  using ::wmemcmp;
  using ::wmemcpy;
  using ::wmemmove;
  using ::wmemset;
  using ::wprintf;
  using ::wscanf;
  using ::wcschr;
  using ::wcspbrk;
  using ::wcsrchr;
  using ::wcsstr;
  using ::wmemchr;
}
namespace __gnu_cxx __attribute__((__visibility__("default"))) {
  using ::wcstold;
  using ::wcstoll;
  using ::wcstoull;
}
namespace std __attribute__((__visibility__("default"))) {
  using ::__gnu_cxx::wcstold;
  using ::__gnu_cxx::wcstoll;
  using ::__gnu_cxx::wcstoull;
  typedef long int streamoff;
  typedef ::std::ptrdiff_t streamsize;
  template < typename _StateT >
  class  fpos
  {
      ::std::streamoff _M_off;
      _StateT _M_state;
    public:
      inline fpos()
        : _M_off(0), _M_state()
      {
      }
      inline fpos(::std::streamoff __off)
        : _M_off(__off), _M_state()
      {
      }
      inline operator ::std::streamoff() const 
      {
        return ::std::fpos<_StateT>::_M_off;
      }
      inline void state(_StateT __st)
      {
        ::std::fpos<_StateT>::_M_state = __st;
      }
      inline _StateT state() const 
      {
        return ::std::fpos<_StateT>::_M_state;
      }
      inline ::std::fpos<_StateT> &operator +=(::std::streamoff __off)
      {
        ::std::fpos<_StateT>::_M_off += __off;
        return *this;
      }
      inline ::std::fpos<_StateT> &operator -=(::std::streamoff __off)
      {
        ::std::fpos<_StateT>::_M_off -= __off;
        return *this;
      }
      inline ::std::fpos<_StateT> operator +(::std::streamoff __off) const 
      {
        ::std::fpos<_StateT> __pos(*this);
        __pos += __off;
        return __pos;
      }
      inline ::std::fpos<_StateT> operator -(::std::streamoff __off) const 
      {
        ::std::fpos<_StateT> __pos(*this);
        __pos -= __off;
        return __pos;
      }
      inline ::std::streamoff operator -(const ::std::fpos<_StateT> &__other) const 
      {
        return ::std::fpos<_StateT>::_M_off - __other._M_off;
      }
  };
  template < typename _StateT >
  inline bool operator ==(const ::std::fpos<_StateT> &__lhs, const ::std::fpos<_StateT> &__rhs);
  template < typename _StateT >
  inline bool operator ==(const ::std::fpos<_StateT> &__lhs, const ::std::fpos<_StateT> &__rhs)
  {
    return long(__lhs) == long(__rhs);
  }
  template < typename _StateT >
  inline bool operator !=(const ::std::fpos<_StateT> &__lhs, const ::std::fpos<_StateT> &__rhs);
  template < typename _StateT >
  inline bool operator !=(const ::std::fpos<_StateT> &__lhs, const ::std::fpos<_StateT> &__rhs)
  {
    return long(__lhs) != long(__rhs);
  }
  typedef ::std::fpos< ::__mbstate_t> streampos;
  typedef ::std::fpos< ::__mbstate_t> wstreampos;
}
namespace __gnu_cxx __attribute__((__visibility__("default"))) {
  template < typename _CharT >
  struct  _Char_types
  {
      typedef unsigned long int int_type;
      typedef ::std::streampos pos_type;
      typedef ::std::streamoff off_type;
      typedef ::mbstate_t state_type;
  };
  template < typename _CharT >
  struct  char_traits
  {
      typedef _CharT char_type;
      typedef typename ::__gnu_cxx::_Char_types<_CharT>::int_type int_type;
      typedef typename ::__gnu_cxx::_Char_types<_CharT>::pos_type pos_type;
      typedef typename ::__gnu_cxx::_Char_types<_CharT>::off_type off_type;
      typedef typename ::__gnu_cxx::_Char_types<_CharT>::state_type state_type;
      static inline void assign(typename ::__gnu_cxx::char_traits<_CharT>::char_type &__c1, const typename ::__gnu_cxx::char_traits<_CharT>::char_type &__c2)
      {
        __c1 = __c2;
      }
      static inline bool eq(const typename ::__gnu_cxx::char_traits<_CharT>::char_type &__c1, const typename ::__gnu_cxx::char_traits<_CharT>::char_type &__c2)
      {
        return __c1 == __c2;
      }
      static inline bool lt(const typename ::__gnu_cxx::char_traits<_CharT>::char_type &__c1, const typename ::__gnu_cxx::char_traits<_CharT>::char_type &__c2)
      {
        return __c1 < __c2;
      }
      static int compare(const typename ::__gnu_cxx::char_traits<_CharT>::char_type *__s1, const typename ::__gnu_cxx::char_traits<_CharT>::char_type *__s2, ::std::size_t __n);
      static ::std::size_t length(const typename ::__gnu_cxx::char_traits<_CharT>::char_type *__p);
      static const typename ::__gnu_cxx::char_traits<_CharT>::char_type *find(const typename ::__gnu_cxx::char_traits<_CharT>::char_type *__s, ::std::size_t __n, const typename ::__gnu_cxx::char_traits<_CharT>::char_type &__a);
      static typename ::__gnu_cxx::char_traits<_CharT>::char_type *move(typename ::__gnu_cxx::char_traits<_CharT>::char_type *__s1, const typename ::__gnu_cxx::char_traits<_CharT>::char_type *__s2, ::std::size_t __n);
      static typename ::__gnu_cxx::char_traits<_CharT>::char_type *copy(typename ::__gnu_cxx::char_traits<_CharT>::char_type *__s1, const typename ::__gnu_cxx::char_traits<_CharT>::char_type *__s2, ::std::size_t __n);
      static typename ::__gnu_cxx::char_traits<_CharT>::char_type *assign(typename ::__gnu_cxx::char_traits<_CharT>::char_type *__s, ::std::size_t __n, typename ::__gnu_cxx::char_traits<_CharT>::char_type __a);
      static inline typename ::__gnu_cxx::char_traits<_CharT>::char_type to_char_type(const typename ::__gnu_cxx::char_traits<_CharT>::int_type &__c)
      {
        return static_cast<typename ::__gnu_cxx::char_traits<_CharT>::char_type>(__c);
      }
      static inline typename ::__gnu_cxx::char_traits<_CharT>::int_type to_int_type(const typename ::__gnu_cxx::char_traits<_CharT>::char_type &__c)
      {
        return static_cast<typename ::__gnu_cxx::char_traits<_CharT>::int_type>(__c);
      }
      static inline bool eq_int_type(const typename ::__gnu_cxx::char_traits<_CharT>::int_type &__c1, const typename ::__gnu_cxx::char_traits<_CharT>::int_type &__c2)
      {
        return __c1 == __c2;
      }
      static inline typename ::__gnu_cxx::char_traits<_CharT>::int_type eof()
      {
        return static_cast<typename ::__gnu_cxx::char_traits<_CharT>::int_type>( -1);
      }
      static inline typename ::__gnu_cxx::char_traits<_CharT>::int_type not_eof(const typename ::__gnu_cxx::char_traits<_CharT>::int_type &__c)
      {
        return !eq_int_type(__c, eof()) ? __c : to_int_type(((typename ::__gnu_cxx::char_traits<_CharT>::char_type())));
      }
  };
  template < typename _CharT >
  int char_traits<_CharT>::compare(const typename ::__gnu_cxx::char_traits<_CharT>::char_type *__s1, const typename ::__gnu_cxx::char_traits<_CharT>::char_type *__s2, ::std::size_t __n)
  {
    for (::std::size_t __i(0); __i < __n;  ++__i)
      {
        if (lt(__s1[__i], __s2[__i]))
          {
            return  -1;
          }
        else
          {
            if (lt(__s2[__i], __s1[__i]))
              {
                return 1;
              }
          }
      }
    return 0;
  }
  template < typename _CharT >
  ::std::size_t char_traits<_CharT>::length(const typename ::__gnu_cxx::char_traits<_CharT>::char_type *__p)
  {
    ::std::size_t __i(0);
    while (!eq(__p[__i], ((typename ::__gnu_cxx::char_traits<_CharT>::char_type()))))
      {
         ++__i;
      }
    return __i;
  }
  template < typename _CharT >
  const typename ::__gnu_cxx::char_traits<_CharT>::char_type *char_traits<_CharT>::find(const typename ::__gnu_cxx::char_traits<_CharT>::char_type *__s, ::std::size_t __n, const typename ::__gnu_cxx::char_traits<_CharT>::char_type &__a)
  {
    for (::std::size_t __i(0); __i < __n;  ++__i)
      {
        if (eq(__s[__i], __a))
          {
            return __s + __i;
          }
      }
    return 0;
  }
  template < typename _CharT >
  typename ::__gnu_cxx::char_traits<_CharT>::char_type *char_traits<_CharT>::move(typename ::__gnu_cxx::char_traits<_CharT>::char_type *__s1, const typename ::__gnu_cxx::char_traits<_CharT>::char_type *__s2, ::std::size_t __n)
  {
    return static_cast<_CharT *>(__builtin_memmove(__s1, __s2, __n * sizeof(typename ::__gnu_cxx::char_traits<_CharT>::char_type)));
  }
  template < typename _CharT >
  typename ::__gnu_cxx::char_traits<_CharT>::char_type *char_traits<_CharT>::copy(typename ::__gnu_cxx::char_traits<_CharT>::char_type *__s1, const typename ::__gnu_cxx::char_traits<_CharT>::char_type *__s2, ::std::size_t __n)
  {
    std::copy(__s2, __s2 + __n, __s1);
    return __s1;
  }
  template < typename _CharT >
  typename ::__gnu_cxx::char_traits<_CharT>::char_type *char_traits<_CharT>::assign(typename ::__gnu_cxx::char_traits<_CharT>::char_type *__s, ::std::size_t __n, typename ::__gnu_cxx::char_traits<_CharT>::char_type __a)
  {
    std::fill_n(__s, __n, __a);
    return __s;
  }
}
namespace std __attribute__((__visibility__("default"))) {
  template < typename _CharT >
  struct  char_traits : ::__gnu_cxx::char_traits<_CharT>
  {
  };
  template <>
  struct  char_traits<char>
  {
      typedef char char_type;
      typedef int int_type;
      typedef ::std::streampos pos_type;
      typedef ::std::streamoff off_type;
      typedef ::mbstate_t state_type;
      static inline void assign(::std::char_traits<char>::char_type &__c1, const ::std::char_traits<char>::char_type &__c2)
      {
        __c1 = __c2;
      }
      static inline bool eq(const ::std::char_traits<char>::char_type &__c1, const ::std::char_traits<char>::char_type &__c2)
      {
        return __c1 == __c2;
      }
      static inline bool lt(const ::std::char_traits<char>::char_type &__c1, const ::std::char_traits<char>::char_type &__c2)
      {
        return static_cast<unsigned char>(__c1) < static_cast<unsigned char>(__c2);
      }
      static inline int compare(const ::std::char_traits<char>::char_type *__s1, const ::std::char_traits<char>::char_type *__s2, ::std::size_t __n)
      {
        if (__n == 0)
          {
            return 0;
          }
        return __builtin_memcmp(__s1, __s2, __n);
      }
      static inline ::std::size_t length(const ::std::char_traits<char>::char_type *__s)
      {
        return __builtin_strlen(__s);
      }
      static inline const ::std::char_traits<char>::char_type *find(const ::std::char_traits<char>::char_type *__s, ::std::size_t __n, const ::std::char_traits<char>::char_type &__a)
      {
        if (__n == 0)
          {
            return 0;
          }
        return static_cast<const ::std::char_traits<char>::char_type *>(__builtin_memchr(__s, __a, __n));
      }
      static inline ::std::char_traits<char>::char_type *move(::std::char_traits<char>::char_type *__s1, const ::std::char_traits<char>::char_type *__s2, ::std::size_t __n)
      {
        if (__n == 0)
          {
            return __s1;
          }
        return static_cast< ::std::char_traits<char>::char_type *>(__builtin_memmove(__s1, __s2, __n));
      }
      static inline ::std::char_traits<char>::char_type *copy(::std::char_traits<char>::char_type *__s1, const ::std::char_traits<char>::char_type *__s2, ::std::size_t __n)
      {
        if (__n == 0)
          {
            return __s1;
          }
        return static_cast< ::std::char_traits<char>::char_type *>(__builtin_memcpy(__s1, __s2, __n));
      }
      static inline ::std::char_traits<char>::char_type *assign(::std::char_traits<char>::char_type *__s, ::std::size_t __n, ::std::char_traits<char>::char_type __a)
      {
        if (__n == 0)
          {
            return __s;
          }
        return static_cast< ::std::char_traits<char>::char_type *>(__builtin_memset(__s, __a, __n));
      }
      static inline ::std::char_traits<char>::char_type to_char_type(const ::std::char_traits<char>::int_type &__c)
      {
        return static_cast< ::std::char_traits<char>::char_type>(__c);
      }
      static inline ::std::char_traits<char>::int_type to_int_type(const ::std::char_traits<char>::char_type &__c)
      {
        return static_cast< ::std::char_traits<char>::int_type>(static_cast<unsigned char>(__c));
      }
      static inline bool eq_int_type(const ::std::char_traits<char>::int_type &__c1, const ::std::char_traits<char>::int_type &__c2)
      {
        return __c1 == __c2;
      }
      static inline ::std::char_traits<char>::int_type eof()
      {
        return static_cast< ::std::char_traits<char>::int_type>( -1);
      }
      static inline ::std::char_traits<char>::int_type not_eof(const ::std::char_traits<char>::int_type &__c)
      {
        return __c == ::std::char_traits<char>::eof() ? 0 : __c;
      }
  };
  template <>
  struct  char_traits<wchar_t>
  {
      typedef wchar_t char_type;
      typedef ::wint_t int_type;
      typedef ::std::streamoff off_type;
      typedef ::std::wstreampos pos_type;
      typedef ::mbstate_t state_type;
      static inline void assign(::std::char_traits<wchar_t>::char_type &__c1, const ::std::char_traits<wchar_t>::char_type &__c2)
      {
        __c1 = __c2;
      }
      static inline bool eq(const ::std::char_traits<wchar_t>::char_type &__c1, const ::std::char_traits<wchar_t>::char_type &__c2)
      {
        return __c1 == __c2;
      }
      static inline bool lt(const ::std::char_traits<wchar_t>::char_type &__c1, const ::std::char_traits<wchar_t>::char_type &__c2)
      {
        return __c1 < __c2;
      }
      static inline int compare(const ::std::char_traits<wchar_t>::char_type *__s1, const ::std::char_traits<wchar_t>::char_type *__s2, ::std::size_t __n)
      {
        if (__n == 0)
          {
            return 0;
          }
        else
          {
            return ::std::wmemcmp(__s1, __s2, __n);
          }
      }
      static inline ::std::size_t length(const ::std::char_traits<wchar_t>::char_type *__s)
      {
        return ::std::wcslen(__s);
      }
      static inline const ::std::char_traits<wchar_t>::char_type *find(const ::std::char_traits<wchar_t>::char_type *__s, ::std::size_t __n, const ::std::char_traits<wchar_t>::char_type &__a)
      {
        if (__n == 0)
          {
            return 0;
          }
        else
          {
            return ::std::wmemchr(__s, __a, __n);
          }
      }
      static inline ::std::char_traits<wchar_t>::char_type *move(::std::char_traits<wchar_t>::char_type *__s1, const ::std::char_traits<wchar_t>::char_type *__s2, ::std::size_t __n)
      {
        if (__n == 0)
          {
            return __s1;
          }
        return ::std::wmemmove(__s1, __s2, __n);
      }
      static inline ::std::char_traits<wchar_t>::char_type *copy(::std::char_traits<wchar_t>::char_type *__s1, const ::std::char_traits<wchar_t>::char_type *__s2, ::std::size_t __n)
      {
        if (__n == 0)
          {
            return __s1;
          }
        return ::std::wmemcpy(__s1, __s2, __n);
      }
      static inline ::std::char_traits<wchar_t>::char_type *assign(::std::char_traits<wchar_t>::char_type *__s, ::std::size_t __n, ::std::char_traits<wchar_t>::char_type __a)
      {
        if (__n == 0)
          {
            return __s;
          }
        return ::std::wmemset(__s, __a, __n);
      }
      static inline ::std::char_traits<wchar_t>::char_type to_char_type(const ::std::char_traits<wchar_t>::int_type &__c)
      {
        return (::std::char_traits<wchar_t>::char_type)__c;
      }
      static inline ::std::char_traits<wchar_t>::int_type to_int_type(const ::std::char_traits<wchar_t>::char_type &__c)
      {
        return (::std::char_traits<wchar_t>::int_type)__c;
      }
      static inline bool eq_int_type(const ::std::char_traits<wchar_t>::int_type &__c1, const ::std::char_traits<wchar_t>::int_type &__c2)
      {
        return __c1 == __c2;
      }
      static inline ::std::char_traits<wchar_t>::int_type eof()
      {
        return static_cast< ::std::char_traits<wchar_t>::int_type>(4294967295U);
      }
      static inline ::std::char_traits<wchar_t>::int_type not_eof(const ::std::char_traits<wchar_t>::int_type &__c)
      {
        return ::std::char_traits<wchar_t>::eq_int_type(__c, ::std::char_traits<wchar_t>::eof()) ? 0 : __c;
      }
  };
}
namespace __gnu_cxx __attribute__((__visibility__("default"))) {
  using ::std::size_t;
  using ::std::ptrdiff_t;
  template < typename _Tp >
  class  new_allocator
  {
    public:
      typedef ::std::size_t size_type;
      typedef ::std::ptrdiff_t difference_type;
      typedef _Tp *pointer;
      typedef const _Tp *const_pointer;
      typedef _Tp &reference;
      typedef const _Tp &const_reference;
      typedef _Tp value_type;
      template < typename _Tp1 >
      struct  rebind
      {
          typedef ::__gnu_cxx::new_allocator<_Tp1> other;
      };
      inline new_allocator() throw()
      {
      }
      inline new_allocator(const ::__gnu_cxx::new_allocator<_Tp> &) throw()
      {
      }
      template < typename _Tp1 >
      inline new_allocator(const ::__gnu_cxx::new_allocator<_Tp1> &) throw()
      {
      }
      inline ~new_allocator() throw()
      {
      }
      inline typename ::__gnu_cxx::new_allocator<_Tp>::pointer address(typename ::__gnu_cxx::new_allocator<_Tp>::reference __x) const 
      {
        return std::__addressof(__x);
      }
      inline typename ::__gnu_cxx::new_allocator<_Tp>::const_pointer address(typename ::__gnu_cxx::new_allocator<_Tp>::const_reference __x) const 
      {
        return std::__addressof(__x);
      }
      inline typename ::__gnu_cxx::new_allocator<_Tp>::pointer allocate(typename ::__gnu_cxx::new_allocator<_Tp>::size_type __n, const void *  = (static_cast<const void *>(0)))
      {
        if (__n > this->max_size())
          {
            std::__throw_bad_alloc();
          }
        return static_cast<_Tp *>(::operator new(__n * sizeof(_Tp)));
      }
      inline void deallocate(typename ::__gnu_cxx::new_allocator<_Tp>::pointer __p, typename ::__gnu_cxx::new_allocator<_Tp>::size_type)
      {
        ::operator delete(__p);
      }
      inline typename ::__gnu_cxx::new_allocator<_Tp>::size_type max_size() const  throw()
      {
        return (::std::size_t) -1 / sizeof(_Tp);
      }
      inline void construct(typename ::__gnu_cxx::new_allocator<_Tp>::pointer __p, const _Tp &__val)
      {
        ::new ((void *)__p)_Tp(__val);
      }
      inline void destroy(typename ::__gnu_cxx::new_allocator<_Tp>::pointer __p)
      {
        __p->~_Tp();
      }
  };
  template < typename _Tp >
  inline bool operator ==(const ::__gnu_cxx::new_allocator<_Tp> &, const ::__gnu_cxx::new_allocator<_Tp> &);
  template < typename _Tp >
  inline bool operator ==(const ::__gnu_cxx::new_allocator<_Tp> &, const ::__gnu_cxx::new_allocator<_Tp> &)
  {
    return true;
  }
  template < typename _Tp >
  inline bool operator !=(const ::__gnu_cxx::new_allocator<_Tp> &, const ::__gnu_cxx::new_allocator<_Tp> &);
  template < typename _Tp >
  inline bool operator !=(const ::__gnu_cxx::new_allocator<_Tp> &, const ::__gnu_cxx::new_allocator<_Tp> &)
  {
    return false;
  }
}
namespace std __attribute__((__visibility__("default"))) {
  template <>
  class  allocator<void>
  {
    public:
      typedef ::std::size_t size_type;
      typedef ::std::ptrdiff_t difference_type;
      typedef void *pointer;
      typedef const void *const_pointer;
      typedef void value_type;
      template < typename _Tp1 >
      struct  rebind
      {
          typedef ::std::allocator<_Tp1> other;
      };
  };
  template < typename _Tp >
  class  allocator : public ::__gnu_cxx::new_allocator<_Tp>
  {
    public:
      typedef ::std::size_t size_type;
      typedef ::std::ptrdiff_t difference_type;
      typedef _Tp *pointer;
      typedef const _Tp *const_pointer;
      typedef _Tp &reference;
      typedef const _Tp &const_reference;
      typedef _Tp value_type;
      template < typename _Tp1 >
      struct  rebind
      {
          typedef ::std::allocator<_Tp1> other;
      };
      inline allocator() throw()
      {
      }
      inline allocator(const ::std::allocator<_Tp> &__a) throw()
        : __gnu_cxx::new_allocator<_Tp>(__a)
      {
      }
      template < typename _Tp1 >
      inline allocator(const ::std::allocator<_Tp1> &) throw()
      {
      }
      inline ~allocator() throw()
      {
      }
  };
  template < typename _T1, typename _T2 >
  inline bool operator ==(const ::std::allocator<_T1> &, const ::std::allocator<_T2> &) throw();
  template < typename _T1, typename _T2 >
  inline bool operator ==(const ::std::allocator<_T1> &, const ::std::allocator<_T2> &) throw()
  {
    return true;
  }
  template < typename _Tp >
  inline bool operator ==(const ::std::allocator<_Tp> &, const ::std::allocator<_Tp> &) throw();
  template < typename _Tp >
  inline bool operator ==(const ::std::allocator<_Tp> &, const ::std::allocator<_Tp> &) throw()
  {
    return true;
  }
  template < typename _T1, typename _T2 >
  inline bool operator !=(const ::std::allocator<_T1> &, const ::std::allocator<_T2> &) throw();
  template < typename _T1, typename _T2 >
  inline bool operator !=(const ::std::allocator<_T1> &, const ::std::allocator<_T2> &) throw()
  {
    return false;
  }
  template < typename _Tp >
  inline bool operator !=(const ::std::allocator<_Tp> &, const ::std::allocator<_Tp> &) throw();
  template < typename _Tp >
  inline bool operator !=(const ::std::allocator<_Tp> &, const ::std::allocator<_Tp> &) throw()
  {
    return false;
  }
  extern template class ::std::allocator<char>;
  extern template class ::std::allocator<wchar_t>;
  template < typename _Alloc, bool __nontype_tpl_param_1_1__ = __is_empty(_Alloc) >
  struct  __alloc_swap
  {
      static inline void _S_do_it(_Alloc &, _Alloc &)
      {
      }
  };
  template < typename _Alloc >
  struct  __alloc_swap<_Alloc, false>
  {
      static inline void _S_do_it(_Alloc &__one, _Alloc &__two)
      {
        if (__one != __two)
          {
            swap(__one, __two);
          }
      }
  };
  template < typename _Alloc, bool __nontype_tpl_param_1_1__ = __is_empty(_Alloc) >
  struct  __alloc_neq
  {
      static inline bool _S_do_it(const _Alloc &, const _Alloc &)
      {
        return false;
      }
  };
  template < typename _Alloc >
  struct  __alloc_neq<_Alloc, false>
  {
      static inline bool _S_do_it(const _Alloc &__one, const _Alloc &__two)
      {
        return __one != __two;
      }
  };
}
struct  lconv
{
    char *decimal_point;
    char *thousands_sep;
    char *grouping;
    char *int_curr_symbol;
    char *currency_symbol;
    char *mon_decimal_point;
    char *mon_thousands_sep;
    char *mon_grouping;
    char *positive_sign;
    char *negative_sign;
    char int_frac_digits;
    char frac_digits;
    char p_cs_precedes;
    char p_sep_by_space;
    char n_cs_precedes;
    char n_sep_by_space;
    char p_sign_posn;
    char n_sign_posn;
    char int_p_cs_precedes;
    char int_p_sep_by_space;
    char int_n_cs_precedes;
    char int_n_sep_by_space;
    char int_p_sign_posn;
    char int_n_sign_posn;
};
extern "C"
{
  extern char *setlocale(int __category, const char *__locale) throw();
}
extern "C"
{
  extern ::lconv *localeconv() throw();
}
extern "C"
{
  extern ::locale_t newlocale(int __category_mask, const char *__locale, ::locale_t __base) throw();
}
extern "C"
{
  extern ::locale_t duplocale(::locale_t __dataset) throw();
}
extern "C"
{
  extern void freelocale(::locale_t __dataset) throw();
}
extern "C"
{
  extern ::locale_t uselocale(::locale_t __dataset) throw();
}
namespace std __attribute__((__visibility__("default"))) {
  using ::lconv;
  using ::setlocale;
  using ::localeconv;
}
namespace __gnu_cxx __attribute__((__visibility__("default"))) {
extern "C"
  {
    ::locale_t __uselocale(::locale_t) throw();
  }
}
namespace std __attribute__((__visibility__("default"))) {
  typedef ::__locale_t __c_locale;
  inline int __convert_from_v(const ::std::__c_locale &__cloc __attribute__((__unused__)), char *__out, const int __size __attribute__((__unused__)), const char *__fmt, ...)
  {
    ::std::__c_locale __old(__gnu_cxx::__uselocale(__cloc));
    ::__builtin_va_list __args;
    __builtin_va_start(__args, __fmt);
    const int __ret(__builtin_vsnprintf(__out, __size, __fmt, __args));
    __builtin_va_end(__args);
    __gnu_cxx::__uselocale(__old);
    return __ret;
  }
  class ios_base;
  template < typename _CharT, typename _Traits = ::std::char_traits<_CharT> >
  class basic_ios;
  template < typename _CharT, typename _Traits = ::std::char_traits<_CharT> >
  class basic_streambuf;
  template < typename _CharT, typename _Traits = ::std::char_traits<_CharT> >
  class basic_istream;
  template < typename _CharT, typename _Traits = ::std::char_traits<_CharT> >
  class basic_ostream;
  template < typename _CharT, typename _Traits = ::std::char_traits<_CharT> >
  class basic_iostream;
  inline namespace __cxx11 __attribute__((__abi_tag__("cxx11"))) {
    template < typename _CharT, typename _Traits = ::std::char_traits<_CharT>, typename _Alloc = ::std::allocator<_CharT> >
    class basic_stringbuf;
    template < typename _CharT, typename _Traits = ::std::char_traits<_CharT>, typename _Alloc = ::std::allocator<_CharT> >
    class basic_istringstream;
    template < typename _CharT, typename _Traits = ::std::char_traits<_CharT>, typename _Alloc = ::std::allocator<_CharT> >
    class basic_ostringstream;
    template < typename _CharT, typename _Traits = ::std::char_traits<_CharT>, typename _Alloc = ::std::allocator<_CharT> >
    class basic_stringstream;
  }
  template < typename _CharT, typename _Traits = ::std::char_traits<_CharT> >
  class basic_filebuf;
  template < typename _CharT, typename _Traits = ::std::char_traits<_CharT> >
  class basic_ifstream;
  template < typename _CharT, typename _Traits = ::std::char_traits<_CharT> >
  class basic_ofstream;
  template < typename _CharT, typename _Traits = ::std::char_traits<_CharT> >
  class basic_fstream;
  template < typename _CharT, typename _Traits = ::std::char_traits<_CharT> >
  class istreambuf_iterator;
  template < typename _CharT, typename _Traits = ::std::char_traits<_CharT> >
  class ostreambuf_iterator;
  typedef ::std::basic_ios<char> ios;
  typedef ::std::basic_streambuf<char> streambuf;
  typedef ::std::basic_istream<char> istream;
  typedef ::std::basic_ostream<char> ostream;
  typedef ::std::basic_iostream<char> iostream;
  typedef ::std::__cxx11::basic_stringbuf<char> stringbuf;
  typedef ::std::__cxx11::basic_istringstream<char> istringstream;
  typedef ::std::__cxx11::basic_ostringstream<char> ostringstream;
  typedef ::std::__cxx11::basic_stringstream<char> stringstream;
  typedef ::std::basic_filebuf<char> filebuf;
  typedef ::std::basic_ifstream<char> ifstream;
  typedef ::std::basic_ofstream<char> ofstream;
  typedef ::std::basic_fstream<char> fstream;
  typedef ::std::basic_ios<wchar_t> wios;
  typedef ::std::basic_streambuf<wchar_t> wstreambuf;
  typedef ::std::basic_istream<wchar_t> wistream;
  typedef ::std::basic_ostream<wchar_t> wostream;
  typedef ::std::basic_iostream<wchar_t> wiostream;
  typedef ::std::__cxx11::basic_stringbuf<wchar_t> wstringbuf;
  typedef ::std::__cxx11::basic_istringstream<wchar_t> wistringstream;
  typedef ::std::__cxx11::basic_ostringstream<wchar_t> wostringstream;
  typedef ::std::__cxx11::basic_stringstream<wchar_t> wstringstream;
  typedef ::std::basic_filebuf<wchar_t> wfilebuf;
  typedef ::std::basic_ifstream<wchar_t> wifstream;
  typedef ::std::basic_ofstream<wchar_t> wofstream;
  typedef ::std::basic_fstream<wchar_t> wfstream;
}
extern "C"
{
  static inline unsigned int __bswap_32(unsigned int __bsx)
  {
    return __builtin_bswap32(__bsx);
  }
}
extern "C"
{
  static inline ::__uint64_t __bswap_64(::__uint64_t __bsx)
  {
    return __builtin_bswap64(__bsx);
  }
}
extern "C"
{
  static inline ::__uint16_t __uint16_identity(::__uint16_t __x)
  {
    return __x;
  }
}
extern "C"
{
  static inline ::__uint32_t __uint32_identity(::__uint32_t __x)
  {
    return __x;
  }
}
extern "C"
{
  static inline ::__uint64_t __uint64_identity(::__uint64_t __x)
  {
    return __x;
  }
}
enum mcc_enum_anon_41
{
  _ISupper = 0 < 8 ? 1 << 0 << 8 : 1 << 0 >> 8,
  _ISlower = 1 < 8 ? 1 << 1 << 8 : 1 << 1 >> 8,
  _ISalpha = 2 < 8 ? 1 << 2 << 8 : 1 << 2 >> 8,
  _ISdigit = 3 < 8 ? 1 << 3 << 8 : 1 << 3 >> 8,
  _ISxdigit = 4 < 8 ? 1 << 4 << 8 : 1 << 4 >> 8,
  _ISspace = 5 < 8 ? 1 << 5 << 8 : 1 << 5 >> 8,
  _ISprint = 6 < 8 ? 1 << 6 << 8 : 1 << 6 >> 8,
  _ISgraph = 7 < 8 ? 1 << 7 << 8 : 1 << 7 >> 8,
  _ISblank = 8 < 8 ? 1 << 8 << 8 : 1 << 8 >> 8,
  _IScntrl = 9 < 8 ? 1 << 9 << 8 : 1 << 9 >> 8,
  _ISpunct = 10 < 8 ? 1 << 10 << 8 : 1 << 10 >> 8,
  _ISalnum = 11 < 8 ? 1 << 11 << 8 : 1 << 11 >> 8
};
extern "C"
{
  extern const unsigned short int **__ctype_b_loc() throw() __attribute__((__const__));
}
extern "C"
{
  extern const ::__int32_t **__ctype_tolower_loc() throw() __attribute__((__const__));
}
extern "C"
{
  extern const ::__int32_t **__ctype_toupper_loc() throw() __attribute__((__const__));
}
extern "C"
{
  extern int isalnum(int) throw();
}
extern "C"
{
  extern int isalpha(int) throw();
}
extern "C"
{
  extern int iscntrl(int) throw();
}
extern "C"
{
  extern int isdigit(int) throw();
}
extern "C"
{
  extern int islower(int) throw();
}
extern "C"
{
  extern int isgraph(int) throw();
}
extern "C"
{
  extern int isprint(int) throw();
}
extern "C"
{
  extern int ispunct(int) throw();
}
extern "C"
{
  extern int isspace(int) throw();
}
extern "C"
{
  extern int isupper(int) throw();
}
extern "C"
{
  extern int isxdigit(int) throw();
}
extern "C"
{
  extern int tolower(int __c) throw();
}
extern "C"
{
  extern int toupper(int __c) throw();
}
extern "C"
{
  extern int isblank(int) throw();
}
extern "C"
{
  extern int isctype(int __c, int __mask) throw();
}
extern "C"
{
  extern int isascii(int __c) throw();
}
extern "C"
{
  extern int toascii(int __c) throw();
}
extern "C"
{
  extern int _toupper(int) throw();
}
extern "C"
{
  extern int _tolower(int) throw();
}
extern "C"
{
  extern int isalnum_l(int, ::locale_t) throw();
}
extern "C"
{
  extern int isalpha_l(int, ::locale_t) throw();
}
extern "C"
{
  extern int iscntrl_l(int, ::locale_t) throw();
}
extern "C"
{
  extern int isdigit_l(int, ::locale_t) throw();
}
extern "C"
{
  extern int islower_l(int, ::locale_t) throw();
}
extern "C"
{
  extern int isgraph_l(int, ::locale_t) throw();
}
extern "C"
{
  extern int isprint_l(int, ::locale_t) throw();
}
extern "C"
{
  extern int ispunct_l(int, ::locale_t) throw();
}
extern "C"
{
  extern int isspace_l(int, ::locale_t) throw();
}
extern "C"
{
  extern int isupper_l(int, ::locale_t) throw();
}
extern "C"
{
  extern int isxdigit_l(int, ::locale_t) throw();
}
extern "C"
{
  extern int isblank_l(int, ::locale_t) throw();
}
extern "C"
{
  extern int __tolower_l(int __c, ::locale_t __l) throw();
}
extern "C"
{
  extern int tolower_l(int __c, ::locale_t __l) throw();
}
extern "C"
{
  extern int __toupper_l(int __c, ::locale_t __l) throw();
}
extern "C"
{
  extern int toupper_l(int __c, ::locale_t __l) throw();
}
namespace std __attribute__((__visibility__("default"))) {
  using ::isalnum;
  using ::isalpha;
  using ::iscntrl;
  using ::isdigit;
  using ::isgraph;
  using ::islower;
  using ::isprint;
  using ::ispunct;
  using ::isspace;
  using ::isupper;
  using ::isxdigit;
  using ::tolower;
  using ::toupper;
  class locale;
  template < typename _Facet >
  bool has_facet(const ::std::locale &) throw();
  template < typename _Facet >
  const _Facet &use_facet(const ::std::locale &);
  template < typename _CharT >
  bool isspace(_CharT, const ::std::locale &);
  template < typename _CharT >
  bool isprint(_CharT, const ::std::locale &);
  template < typename _CharT >
  bool iscntrl(_CharT, const ::std::locale &);
  template < typename _CharT >
  bool isupper(_CharT, const ::std::locale &);
  template < typename _CharT >
  bool islower(_CharT, const ::std::locale &);
  template < typename _CharT >
  bool isalpha(_CharT, const ::std::locale &);
  template < typename _CharT >
  bool isdigit(_CharT, const ::std::locale &);
  template < typename _CharT >
  bool ispunct(_CharT, const ::std::locale &);
  template < typename _CharT >
  bool isxdigit(_CharT, const ::std::locale &);
  template < typename _CharT >
  bool isalnum(_CharT, const ::std::locale &);
  template < typename _CharT >
  bool isgraph(_CharT, const ::std::locale &);
  template < typename _CharT >
  _CharT toupper(_CharT, const ::std::locale &);
  template < typename _CharT >
  _CharT tolower(_CharT, const ::std::locale &);
  class ctype_base;
  template < typename _CharT >
  class ctype;
  template <>
  class ctype<char>;
  template <>
  class ctype<wchar_t>;
  template < typename _CharT >
  class ctype_byname;
  class codecvt_base;
  template < typename _InternT, typename _ExternT, typename _StateT >
  class codecvt;
  template <>
  class codecvt<char, char, ::__mbstate_t>;
  template <>
  class codecvt<wchar_t, char, ::__mbstate_t>;
  template < typename _InternT, typename _ExternT, typename _StateT >
  class codecvt_byname;
  template < typename _CharT, typename _InIter = ::std::istreambuf_iterator<_CharT> >
  class num_get;
  template < typename _CharT, typename _OutIter = ::std::ostreambuf_iterator<_CharT> >
  class num_put;
  inline namespace __cxx11 __attribute__((__abi_tag__("cxx11"))) {
    template < typename _CharT >
    class numpunct;
    template < typename _CharT >
    class numpunct_byname;
    template < typename _CharT >
    class collate;
    template < typename _CharT >
    class collate_byname;
  }
  class time_base;
  inline namespace __cxx11 __attribute__((__abi_tag__("cxx11"))) {
    template < typename _CharT, typename _InIter = ::std::istreambuf_iterator<_CharT> >
    class time_get;
    template < typename _CharT, typename _InIter = ::std::istreambuf_iterator<_CharT> >
    class time_get_byname;
  }
  template < typename _CharT, typename _OutIter = ::std::ostreambuf_iterator<_CharT> >
  class time_put;
  template < typename _CharT, typename _OutIter = ::std::ostreambuf_iterator<_CharT> >
  class time_put_byname;
  class money_base;
  inline namespace __cxx11 __attribute__((__abi_tag__("cxx11"))) {
    template < typename _CharT, typename _InIter = ::std::istreambuf_iterator<_CharT> >
    class money_get;
    template < typename _CharT, typename _OutIter = ::std::ostreambuf_iterator<_CharT> >
    class money_put;
    template < typename _CharT, bool _Intl = false >
    class moneypunct;
    template < typename _CharT, bool _Intl = false >
    class moneypunct_byname;
  }
  class messages_base;
  inline namespace __cxx11 __attribute__((__abi_tag__("cxx11"))) {
    template < typename _CharT >
    class messages;
    template < typename _CharT >
    class messages_byname;
  }
}
#pragma GCC visibility push(default)
namespace __cxxabiv1 {
  class  __forced_unwind
  {
      virtual ~__forced_unwind() throw();
      virtual void __pure_dummy() = 0 ;
    public:
  };
}
#pragma GCC visibility pop
namespace std __attribute__((__visibility__("default"))) {
  template < typename _CharT, typename _Traits >
  inline void __ostream_write(::std::basic_ostream<_CharT, _Traits> &__out, const _CharT *__s, ::std::streamsize __n);
  template < typename _CharT, typename _Traits >
  inline void __ostream_write(::std::basic_ostream<_CharT, _Traits> &__out, const _CharT *__s, ::std::streamsize __n)
  {
    typedef ::std::basic_ostream<_CharT, _Traits> __ostream_type;
    typedef typename ::std::basic_ostream<_CharT, _Traits>::ios_base __ios_base;
    const ::std::streamsize __put = __out.rdbuf()->sputn(__s, __n);
    if (__put != __n)
      {
        __out.setstate(__ios_base::badbit);
      }
  }
  template < typename _CharT, typename _Traits >
  inline void __ostream_fill(::std::basic_ostream<_CharT, _Traits> &__out, ::std::streamsize __n);
  template < typename _CharT, typename _Traits >
  inline void __ostream_fill(::std::basic_ostream<_CharT, _Traits> &__out, ::std::streamsize __n)
  {
    typedef ::std::basic_ostream<_CharT, _Traits> __ostream_type;
    typedef typename ::std::basic_ostream<_CharT, _Traits>::ios_base __ios_base;
    const _CharT __c = __out.fill();
    for (; __n > 0;  --__n)
      {
        const typename _Traits::int_type __put = __out.rdbuf()->sputc(__c);
        if (_Traits::eq_int_type(__put, _Traits::eof()))
          {
            __out.setstate(__ios_base::badbit);
            break;
          }
      }
  }
  template < typename _CharT, typename _Traits >
  ::std::basic_ostream<_CharT, _Traits> &__ostream_insert(::std::basic_ostream<_CharT, _Traits> &__out, const _CharT *__s, ::std::streamsize __n);
  template < typename _CharT, typename _Traits >
  ::std::basic_ostream<_CharT, _Traits> &__ostream_insert(::std::basic_ostream<_CharT, _Traits> &__out, const _CharT *__s, ::std::streamsize __n)
  {
    typedef ::std::basic_ostream<_CharT, _Traits> __ostream_type;
    typedef typename ::std::basic_ostream<_CharT, _Traits>::ios_base __ios_base;
    typename ::std::basic_ostream<_CharT, _Traits>::sentry __cerb(__out);
    if (__cerb)
      {
        try
        {
          const ::std::streamsize __w = __out.width();
          if (__w > __n)
            {
              const bool __left = (__out.flags() & __ios_base::adjustfield) == __ios_base::left;
              if (!__left)
                {
                  __ostream_fill(__out, __w - __n);
                }
              if (__out.good())
                {
                  __ostream_write(__out, __s, __n);
                }
              if (__left && __out.good())
                {
                  __ostream_fill(__out, __w - __n);
                }
            }
          else
            {
              __ostream_write(__out, __s, __n);
            }
          __out.width(0);
        }
        catch (::__cxxabiv1::__forced_unwind &)
        {
          __out._M_setstate(__ios_base::badbit);
          throw;
        }
        catch (...)
        {
          __out._M_setstate(__ios_base::badbit);
        }
      }
    return __out;
  }
  extern template ::std::basic_ostream<char> &__ostream_insert(::std::basic_ostream<char> &, const char *, long int);
  extern template ::std::basic_ostream<wchar_t> &__ostream_insert(::std::basic_ostream<wchar_t> &, const wchar_t *, long int);
  template < typename _Arg, typename _Result >
  struct  unary_function
  {
      typedef _Arg argument_type;
      typedef _Result result_type;
  };
  template < typename _Arg1, typename _Arg2, typename _Result >
  struct  binary_function
  {
      typedef _Arg1 first_argument_type;
      typedef _Arg2 second_argument_type;
      typedef _Result result_type;
  };
  template < typename _Tp >
  struct  plus : ::std::binary_function<_Tp, _Tp, _Tp>
  {
      inline _Tp operator ()(const _Tp &__x, const _Tp &__y) const 
      {
        return __x + __y;
      }
  };
  template < typename _Tp >
  struct  minus : ::std::binary_function<_Tp, _Tp, _Tp>
  {
      inline _Tp operator ()(const _Tp &__x, const _Tp &__y) const 
      {
        return __x - __y;
      }
  };
  template < typename _Tp >
  struct  multiplies : ::std::binary_function<_Tp, _Tp, _Tp>
  {
      inline _Tp operator ()(const _Tp &__x, const _Tp &__y) const 
      {
        return __x * __y;
      }
  };
  template < typename _Tp >
  struct  divides : ::std::binary_function<_Tp, _Tp, _Tp>
  {
      inline _Tp operator ()(const _Tp &__x, const _Tp &__y) const 
      {
        return __x / __y;
      }
  };
  template < typename _Tp >
  struct  modulus : ::std::binary_function<_Tp, _Tp, _Tp>
  {
      inline _Tp operator ()(const _Tp &__x, const _Tp &__y) const 
      {
        return __x % __y;
      }
  };
  template < typename _Tp >
  struct  negate : ::std::unary_function<_Tp, _Tp>
  {
      inline _Tp operator ()(const _Tp &__x) const 
      {
        return  -__x;
      }
  };
  template < typename _Tp >
  struct  equal_to : ::std::binary_function<_Tp, _Tp, bool>
  {
      inline bool operator ()(const _Tp &__x, const _Tp &__y) const 
      {
        return __x == __y;
      }
  };
  template < typename _Tp >
  struct  not_equal_to : ::std::binary_function<_Tp, _Tp, bool>
  {
      inline bool operator ()(const _Tp &__x, const _Tp &__y) const 
      {
        return __x != __y;
      }
  };
  template < typename _Tp >
  struct  greater : ::std::binary_function<_Tp, _Tp, bool>
  {
      inline bool operator ()(const _Tp &__x, const _Tp &__y) const 
      {
        return __x > __y;
      }
  };
  template < typename _Tp >
  struct  less : ::std::binary_function<_Tp, _Tp, bool>
  {
      inline bool operator ()(const _Tp &__x, const _Tp &__y) const 
      {
        return __x < __y;
      }
  };
  template < typename _Tp >
  struct  greater_equal : ::std::binary_function<_Tp, _Tp, bool>
  {
      inline bool operator ()(const _Tp &__x, const _Tp &__y) const 
      {
        return __x >= __y;
      }
  };
  template < typename _Tp >
  struct  less_equal : ::std::binary_function<_Tp, _Tp, bool>
  {
      inline bool operator ()(const _Tp &__x, const _Tp &__y) const 
      {
        return __x <= __y;
      }
  };
  template < typename _Tp >
  struct  logical_and : ::std::binary_function<_Tp, _Tp, bool>
  {
      inline bool operator ()(const _Tp &__x, const _Tp &__y) const 
      {
        return __x && __y;
      }
  };
  template < typename _Tp >
  struct  logical_or : ::std::binary_function<_Tp, _Tp, bool>
  {
      inline bool operator ()(const _Tp &__x, const _Tp &__y) const 
      {
        return __x || __y;
      }
  };
  template < typename _Tp >
  struct  logical_not : ::std::unary_function<_Tp, bool>
  {
      inline bool operator ()(const _Tp &__x) const 
      {
        return !__x;
      }
  };
  template < typename _Tp >
  struct  bit_and : ::std::binary_function<_Tp, _Tp, _Tp>
  {
      inline _Tp operator ()(const _Tp &__x, const _Tp &__y) const 
      {
        return __x & __y;
      }
  };
  template < typename _Tp >
  struct  bit_or : ::std::binary_function<_Tp, _Tp, _Tp>
  {
      inline _Tp operator ()(const _Tp &__x, const _Tp &__y) const 
      {
        return __x | __y;
      }
  };
  template < typename _Tp >
  struct  bit_xor : ::std::binary_function<_Tp, _Tp, _Tp>
  {
      inline _Tp operator ()(const _Tp &__x, const _Tp &__y) const 
      {
        return __x ^ __y;
      }
  };
  template < typename _Tp >
  struct  bit_not : ::std::unary_function<_Tp, _Tp>
  {
      inline _Tp operator ()(const _Tp &__x) const 
      {
        return ~__x;
      }
  };
  template < typename _Predicate >
  class  unary_negate : public ::std::unary_function<typename _Predicate::argument_type, bool>
  {
    protected:
      _Predicate _M_pred;
    public:
      inline explicit unary_negate(const _Predicate &__x)
        : _M_pred(__x)
      {
      }
      inline bool operator ()(const typename _Predicate::argument_type &__x) const 
      {
        return !::std::unary_negate<_Predicate>::_M_pred(__x);
      }
  };
  template < typename _Predicate >
  inline ::std::unary_negate<_Predicate> not1(const _Predicate &__pred);
  template < typename _Predicate >
  inline ::std::unary_negate<_Predicate> not1(const _Predicate &__pred)
  {
    return ::std::unary_negate<_Predicate>(__pred);
  }
  template < typename _Predicate >
  class  binary_negate : public ::std::binary_function<typename _Predicate::first_argument_type, typename _Predicate::second_argument_type, bool>
  {
    protected:
      _Predicate _M_pred;
    public:
      inline explicit binary_negate(const _Predicate &__x)
        : _M_pred(__x)
      {
      }
      inline bool operator ()(const typename _Predicate::first_argument_type &__x, const typename _Predicate::second_argument_type &__y) const 
      {
        return !::std::binary_negate<_Predicate>::_M_pred(__x, __y);
      }
  };
  template < typename _Predicate >
  inline ::std::binary_negate<_Predicate> not2(const _Predicate &__pred);
  template < typename _Predicate >
  inline ::std::binary_negate<_Predicate> not2(const _Predicate &__pred)
  {
    return ::std::binary_negate<_Predicate>(__pred);
  }
  template < typename _Arg, typename _Result >
  class  pointer_to_unary_function : public ::std::unary_function<_Arg, _Result>
  {
    protected:
      _Result (*_M_ptr)(_Arg);
    public:
      inline pointer_to_unary_function()
      {
      }
      inline explicit pointer_to_unary_function(_Result (*__x)(_Arg))
        : _M_ptr(__x)
      {
      }
      inline _Result operator ()(_Arg __x) const 
      {
        return ::std::pointer_to_unary_function<_Arg, _Result>::_M_ptr(__x);
      }
  };
  template < typename _Arg, typename _Result >
  inline ::std::pointer_to_unary_function<_Arg, _Result> ptr_fun(_Result (*__x)(_Arg));
  template < typename _Arg, typename _Result >
  inline ::std::pointer_to_unary_function<_Arg, _Result> ptr_fun(_Result (*__x)(_Arg))
  {
    return ::std::pointer_to_unary_function<_Arg, _Result>(__x);
  }
  template < typename _Arg1, typename _Arg2, typename _Result >
  class  pointer_to_binary_function : public ::std::binary_function<_Arg1, _Arg2, _Result>
  {
    protected:
      _Result (*_M_ptr)(_Arg1, _Arg2);
    public:
      inline pointer_to_binary_function()
      {
      }
      inline explicit pointer_to_binary_function(_Result (*__x)(_Arg1, _Arg2))
        : _M_ptr(__x)
      {
      }
      inline _Result operator ()(_Arg1 __x, _Arg2 __y) const 
      {
        return ::std::pointer_to_binary_function<_Arg1, _Arg2, _Result>::_M_ptr(__x, __y);
      }
  };
  template < typename _Arg1, typename _Arg2, typename _Result >
  inline ::std::pointer_to_binary_function<_Arg1, _Arg2, _Result> ptr_fun(_Result (*__x)(_Arg1, _Arg2));
  template < typename _Arg1, typename _Arg2, typename _Result >
  inline ::std::pointer_to_binary_function<_Arg1, _Arg2, _Result> ptr_fun(_Result (*__x)(_Arg1, _Arg2))
  {
    return ::std::pointer_to_binary_function<_Arg1, _Arg2, _Result>(__x);
  }
  template < typename _Tp >
  struct  _Identity : ::std::unary_function<_Tp, _Tp>
  {
      inline _Tp &operator ()(_Tp &__x) const 
      {
        return __x;
      }
      inline const _Tp &operator ()(const _Tp &__x) const 
      {
        return __x;
      }
  };
  template < typename _Pair >
  struct  _Select1st : ::std::unary_function<_Pair, typename _Pair::first_type>
  {
      inline typename _Pair::first_type &operator ()(_Pair &__x) const 
      {
        return __x.first;
      }
      inline const typename _Pair::first_type &operator ()(const _Pair &__x) const 
      {
        return __x.first;
      }
  };
  template < typename _Pair >
  struct  _Select2nd : ::std::unary_function<_Pair, typename _Pair::second_type>
  {
      inline typename _Pair::second_type &operator ()(_Pair &__x) const 
      {
        return __x.second;
      }
      inline const typename _Pair::second_type &operator ()(const _Pair &__x) const 
      {
        return __x.second;
      }
  };
  template < typename _Ret, typename _Tp >
  class  mem_fun_t : public ::std::unary_function<_Tp *, _Ret>
  {
    public:
      inline explicit mem_fun_t(_Ret (_Tp::*__pf)())
        : _M_f(__pf)
      {
      }
      inline _Ret operator ()(_Tp *__p) const 
      {
        return (__p->*::std::mem_fun_t<_Ret, _Tp>::_M_f)();
      }
    private:
      _Ret (_Tp::*_M_f)();
  };
  template < typename _Ret, typename _Tp >
  class  const_mem_fun_t : public ::std::unary_function<const _Tp *, _Ret>
  {
    public:
      inline explicit const_mem_fun_t(_Ret (_Tp::*__pf)() const )
        : _M_f(__pf)
      {
      }
      inline _Ret operator ()(const _Tp *__p) const 
      {
        return (__p->*::std::const_mem_fun_t<_Ret, _Tp>::_M_f)();
      }
    private:
      _Ret (_Tp::*_M_f)() const ;
  };
  template < typename _Ret, typename _Tp >
  class  mem_fun_ref_t : public ::std::unary_function<_Tp, _Ret>
  {
    public:
      inline explicit mem_fun_ref_t(_Ret (_Tp::*__pf)())
        : _M_f(__pf)
      {
      }
      inline _Ret operator ()(_Tp &__r) const 
      {
        return (__r.*::std::mem_fun_ref_t<_Ret, _Tp>::_M_f)();
      }
    private:
      _Ret (_Tp::*_M_f)();
  };
  template < typename _Ret, typename _Tp >
  class  const_mem_fun_ref_t : public ::std::unary_function<_Tp, _Ret>
  {
    public:
      inline explicit const_mem_fun_ref_t(_Ret (_Tp::*__pf)() const )
        : _M_f(__pf)
      {
      }
      inline _Ret operator ()(const _Tp &__r) const 
      {
        return (__r.*::std::const_mem_fun_ref_t<_Ret, _Tp>::_M_f)();
      }
    private:
      _Ret (_Tp::*_M_f)() const ;
  };
  template < typename _Ret, typename _Tp, typename _Arg >
  class  mem_fun1_t : public ::std::binary_function<_Tp *, _Arg, _Ret>
  {
    public:
      inline explicit mem_fun1_t(_Ret (_Tp::*__pf)(_Arg))
        : _M_f(__pf)
      {
      }
      inline _Ret operator ()(_Tp *__p, _Arg __x) const 
      {
        return (__p->*::std::mem_fun1_t<_Ret, _Tp, _Arg>::_M_f)(__x);
      }
    private:
      _Ret (_Tp::*_M_f)(_Arg);
  };
  template < typename _Ret, typename _Tp, typename _Arg >
  class  const_mem_fun1_t : public ::std::binary_function<const _Tp *, _Arg, _Ret>
  {
    public:
      inline explicit const_mem_fun1_t(_Ret (_Tp::*__pf)(_Arg) const )
        : _M_f(__pf)
      {
      }
      inline _Ret operator ()(const _Tp *__p, _Arg __x) const 
      {
        return (__p->*::std::const_mem_fun1_t<_Ret, _Tp, _Arg>::_M_f)(__x);
      }
    private:
      _Ret (_Tp::*_M_f)(_Arg) const ;
  };
  template < typename _Ret, typename _Tp, typename _Arg >
  class  mem_fun1_ref_t : public ::std::binary_function<_Tp, _Arg, _Ret>
  {
    public:
      inline explicit mem_fun1_ref_t(_Ret (_Tp::*__pf)(_Arg))
        : _M_f(__pf)
      {
      }
      inline _Ret operator ()(_Tp &__r, _Arg __x) const 
      {
        return (__r.*::std::mem_fun1_ref_t<_Ret, _Tp, _Arg>::_M_f)(__x);
      }
    private:
      _Ret (_Tp::*_M_f)(_Arg);
  };
  template < typename _Ret, typename _Tp, typename _Arg >
  class  const_mem_fun1_ref_t : public ::std::binary_function<_Tp, _Arg, _Ret>
  {
    public:
      inline explicit const_mem_fun1_ref_t(_Ret (_Tp::*__pf)(_Arg) const )
        : _M_f(__pf)
      {
      }
      inline _Ret operator ()(const _Tp &__r, _Arg __x) const 
      {
        return (__r.*::std::const_mem_fun1_ref_t<_Ret, _Tp, _Arg>::_M_f)(__x);
      }
    private:
      _Ret (_Tp::*_M_f)(_Arg) const ;
  };
  template < typename _Ret, typename _Tp >
  inline ::std::mem_fun_t<_Ret, _Tp> mem_fun(_Ret (_Tp::*__f)());
  template < typename _Ret, typename _Tp >
  inline ::std::mem_fun_t<_Ret, _Tp> mem_fun(_Ret (_Tp::*__f)())
  {
    return ::std::mem_fun_t<_Ret, _Tp>(__f);
  }
  template < typename _Ret, typename _Tp >
  inline ::std::const_mem_fun_t<_Ret, _Tp> mem_fun(_Ret (_Tp::*__f)() const );
  template < typename _Ret, typename _Tp >
  inline ::std::const_mem_fun_t<_Ret, _Tp> mem_fun(_Ret (_Tp::*__f)() const )
  {
    return ::std::const_mem_fun_t<_Ret, _Tp>(__f);
  }
  template < typename _Ret, typename _Tp >
  inline ::std::mem_fun_ref_t<_Ret, _Tp> mem_fun_ref(_Ret (_Tp::*__f)());
  template < typename _Ret, typename _Tp >
  inline ::std::mem_fun_ref_t<_Ret, _Tp> mem_fun_ref(_Ret (_Tp::*__f)())
  {
    return ::std::mem_fun_ref_t<_Ret, _Tp>(__f);
  }
  template < typename _Ret, typename _Tp >
  inline ::std::const_mem_fun_ref_t<_Ret, _Tp> mem_fun_ref(_Ret (_Tp::*__f)() const );
  template < typename _Ret, typename _Tp >
  inline ::std::const_mem_fun_ref_t<_Ret, _Tp> mem_fun_ref(_Ret (_Tp::*__f)() const )
  {
    return ::std::const_mem_fun_ref_t<_Ret, _Tp>(__f);
  }
  template < typename _Ret, typename _Tp, typename _Arg >
  inline ::std::mem_fun1_t<_Ret, _Tp, _Arg> mem_fun(_Ret (_Tp::*__f)(_Arg));
  template < typename _Ret, typename _Tp, typename _Arg >
  inline ::std::mem_fun1_t<_Ret, _Tp, _Arg> mem_fun(_Ret (_Tp::*__f)(_Arg))
  {
    return ::std::mem_fun1_t<_Ret, _Tp, _Arg>(__f);
  }
  template < typename _Ret, typename _Tp, typename _Arg >
  inline ::std::const_mem_fun1_t<_Ret, _Tp, _Arg> mem_fun(_Ret (_Tp::*__f)(_Arg) const );
  template < typename _Ret, typename _Tp, typename _Arg >
  inline ::std::const_mem_fun1_t<_Ret, _Tp, _Arg> mem_fun(_Ret (_Tp::*__f)(_Arg) const )
  {
    return ::std::const_mem_fun1_t<_Ret, _Tp, _Arg>(__f);
  }
  template < typename _Ret, typename _Tp, typename _Arg >
  inline ::std::mem_fun1_ref_t<_Ret, _Tp, _Arg> mem_fun_ref(_Ret (_Tp::*__f)(_Arg));
  template < typename _Ret, typename _Tp, typename _Arg >
  inline ::std::mem_fun1_ref_t<_Ret, _Tp, _Arg> mem_fun_ref(_Ret (_Tp::*__f)(_Arg))
  {
    return ::std::mem_fun1_ref_t<_Ret, _Tp, _Arg>(__f);
  }
  template < typename _Ret, typename _Tp, typename _Arg >
  inline ::std::const_mem_fun1_ref_t<_Ret, _Tp, _Arg> mem_fun_ref(_Ret (_Tp::*__f)(_Arg) const );
  template < typename _Ret, typename _Tp, typename _Arg >
  inline ::std::const_mem_fun1_ref_t<_Ret, _Tp, _Arg> mem_fun_ref(_Ret (_Tp::*__f)(_Arg) const )
  {
    return ::std::const_mem_fun1_ref_t<_Ret, _Tp, _Arg>(__f);
  }
}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
namespace std __attribute__((__visibility__("default"))) {
  template < typename _Operation >
  class  binder1st : public ::std::unary_function<typename _Operation::second_argument_type, typename _Operation::result_type>
  {
    protected:
      _Operation op;
      typename _Operation::first_argument_type value;
    public:
      inline binder1st(const _Operation &__x, const typename _Operation::first_argument_type &__y)
        : op(__x), value(__y)
      {
      }
      inline typename _Operation::result_type operator ()(const typename _Operation::second_argument_type &__x) const 
      {
        return ::std::binder1st<_Operation>::op(::std::binder1st<_Operation>::value, __x);
      }
      inline typename _Operation::result_type operator ()(typename _Operation::second_argument_type &__x) const 
      {
        return ::std::binder1st<_Operation>::op(::std::binder1st<_Operation>::value, __x);
      }
  };
  template < typename _Operation, typename _Tp >
  inline ::std::binder1st<_Operation> bind1st(const _Operation &__fn, const _Tp &__x);
  template < typename _Operation, typename _Tp >
  inline ::std::binder1st<_Operation> bind1st(const _Operation &__fn, const _Tp &__x)
  {
    typedef typename _Operation::first_argument_type _Arg1_type;
    return ::std::binder1st<_Operation>(__fn, _Arg1_type(__x));
  }
  template < typename _Operation >
  class  binder2nd : public ::std::unary_function<typename _Operation::first_argument_type, typename _Operation::result_type>
  {
    protected:
      _Operation op;
      typename _Operation::second_argument_type value;
    public:
      inline binder2nd(const _Operation &__x, const typename _Operation::second_argument_type &__y)
        : op(__x), value(__y)
      {
      }
      inline typename _Operation::result_type operator ()(const typename _Operation::first_argument_type &__x) const 
      {
        return ::std::binder2nd<_Operation>::op(__x, ::std::binder2nd<_Operation>::value);
      }
      inline typename _Operation::result_type operator ()(typename _Operation::first_argument_type &__x) const 
      {
        return ::std::binder2nd<_Operation>::op(__x, ::std::binder2nd<_Operation>::value);
      }
  };
  template < typename _Operation, typename _Tp >
  inline ::std::binder2nd<_Operation> bind2nd(const _Operation &__fn, const _Tp &__x);
  template < typename _Operation, typename _Tp >
  inline ::std::binder2nd<_Operation> bind2nd(const _Operation &__fn, const _Tp &__x)
  {
    typedef typename _Operation::second_argument_type _Arg2_type;
    return ::std::binder2nd<_Operation>(__fn, _Arg2_type(__x));
  }
}
#pragma GCC diagnostic pop
#pragma GCC visibility push(default)
typedef ::__time_t time_t;
struct  timespec
{
    ::__time_t tv_sec;
    ::__syscall_slong_t tv_nsec;
};
typedef ::__pid_t pid_t;
struct  sched_param
{
    int sched_priority;
};
extern "C"
{
  extern int clone(int (*__fn)(void *), void *__child_stack, int __flags, void *__arg, ...) throw();
}
extern "C"
{
  extern int unshare(int __flags) throw();
}
extern "C"
{
  extern int sched_getcpu() throw();
}
extern "C"
{
  extern int setns(int __fd, int __nstype) throw();
}
typedef unsigned long int __cpu_mask;
struct  cpu_set_t
{
    ::__cpu_mask __bits[16L];
};
extern "C"
{
  extern int __sched_cpucount(::size_t __setsize, const ::cpu_set_t *__setp) throw();
}
extern "C"
{
  extern ::cpu_set_t *__sched_cpualloc(::size_t __count) throw() __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern void __sched_cpufree(::cpu_set_t *__set) throw();
}
extern "C"
{
  extern int sched_setparam(::__pid_t __pid, const ::sched_param *__param) throw();
}
extern "C"
{
  extern int sched_getparam(::__pid_t __pid, ::sched_param *__param) throw();
}
extern "C"
{
  extern int sched_setscheduler(::__pid_t __pid, int __policy, const ::sched_param *__param) throw();
}
extern "C"
{
  extern int sched_getscheduler(::__pid_t __pid) throw();
}
extern "C"
{
  extern int sched_yield() throw();
}
extern "C"
{
  extern int sched_get_priority_max(int __algorithm) throw();
}
extern "C"
{
  extern int sched_get_priority_min(int __algorithm) throw();
}
extern "C"
{
  extern int sched_rr_get_interval(::__pid_t __pid, ::timespec *__t) throw();
}
extern "C"
{
  extern int sched_setaffinity(::__pid_t __pid, ::size_t __cpusetsize, const ::cpu_set_t *__cpuset) throw();
}
extern "C"
{
  extern int sched_getaffinity(::__pid_t __pid, ::size_t __cpusetsize, ::cpu_set_t *__cpuset) throw();
}
struct  timeval
{
    ::__time_t tv_sec;
    ::__suseconds_t tv_usec;
};
struct  timex
{
    unsigned int modes;
    ::__syscall_slong_t offset;
    ::__syscall_slong_t freq;
    ::__syscall_slong_t maxerror;
    ::__syscall_slong_t esterror;
    int status;
    ::__syscall_slong_t constant;
    ::__syscall_slong_t precision;
    ::__syscall_slong_t tolerance;
    ::timeval time;
    ::__syscall_slong_t tick;
    ::__syscall_slong_t ppsfreq;
    ::__syscall_slong_t jitter;
    int shift;
    ::__syscall_slong_t stabil;
    ::__syscall_slong_t jitcnt;
    ::__syscall_slong_t calcnt;
    ::__syscall_slong_t errcnt;
    ::__syscall_slong_t stbcnt;
    int tai;
    int:32;
    int:32;
    int:32;
    int:32;
    int:32;
    int:32;
    int:32;
    int:32;
    int:32;
    int:32;
    int:32;
};
extern "C"
{
  extern int clock_adjtime(::__clockid_t __clock_id, ::timex *__utx) throw();
}
typedef ::__clock_t clock_t;
struct  tm
{
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
    long int tm_gmtoff;
    const char *tm_zone;
};
typedef ::__clockid_t clockid_t;
typedef ::__timer_t timer_t;
struct  itimerspec
{
    ::timespec it_interval;
    ::timespec it_value;
};
struct sigevent;
extern "C"
{
  extern ::clock_t clock() throw();
}
extern "C"
{
  extern ::time_t time(::time_t *__timer) throw();
}
extern "C"
{
  extern double difftime(::time_t __time1, ::time_t __time0) throw() __attribute__((__const__));
}
extern "C"
{
  extern ::time_t mktime(::tm *__tp) throw();
}
extern "C"
{
  extern ::size_t strftime(char *__restrict __s, ::size_t __maxsize, const char *__restrict __format, const ::tm *__restrict __tp) throw();
}
extern "C"
{
  extern char *strptime(const char *__restrict __s, const char *__restrict __fmt, ::tm *__tp) throw();
}
extern "C"
{
  extern ::size_t strftime_l(char *__restrict __s, ::size_t __maxsize, const char *__restrict __format, const ::tm *__restrict __tp, ::locale_t __loc) throw();
}
extern "C"
{
  extern char *strptime_l(const char *__restrict __s, const char *__restrict __fmt, ::tm *__tp, ::locale_t __loc) throw();
}
extern "C"
{
  extern ::tm *gmtime(const ::time_t *__timer) throw();
}
extern "C"
{
  extern ::tm *localtime(const ::time_t *__timer) throw();
}
extern "C"
{
  extern ::tm *gmtime_r(const ::time_t *__restrict __timer, ::tm *__restrict __tp) throw();
}
extern "C"
{
  extern ::tm *localtime_r(const ::time_t *__restrict __timer, ::tm *__restrict __tp) throw();
}
extern "C"
{
  extern char *asctime(const ::tm *__tp) throw();
}
extern "C"
{
  extern char *ctime(const ::time_t *__timer) throw();
}
extern "C"
{
  extern char *asctime_r(const ::tm *__restrict __tp, char *__restrict __buf) throw();
}
extern "C"
{
  extern char *ctime_r(const ::time_t *__restrict __timer, char *__restrict __buf) throw();
}
extern "C"
{
  extern char *__tzname[2L];
}
extern "C"
{
  extern int __daylight;
}
extern "C"
{
  extern long int __timezone;
}
extern "C"
{
  extern char *tzname[2L];
}
extern "C"
{
  extern void tzset() throw();
}
extern "C"
{
  extern int daylight;
}
extern "C"
{
  extern long int timezone;
}
extern "C"
{
  extern int stime(const ::time_t *__when) throw();
}
extern "C"
{
  extern ::time_t timegm(::tm *__tp) throw();
}
extern "C"
{
  extern ::time_t timelocal(::tm *__tp) throw();
}
extern "C"
{
  extern int dysize(int __year) throw() __attribute__((__const__));
}
extern "C"
{
  extern int nanosleep(const ::timespec *__requested_time, ::timespec *__remaining);
}
extern "C"
{
  extern int clock_getres(::clockid_t __clock_id, ::timespec *__res) throw();
}
extern "C"
{
  extern int clock_gettime(::clockid_t __clock_id, ::timespec *__tp) throw();
}
extern "C"
{
  extern int clock_settime(::clockid_t __clock_id, const ::timespec *__tp) throw();
}
extern "C"
{
  extern int clock_nanosleep(::clockid_t __clock_id, int __flags, const ::timespec *__req, ::timespec *__rem);
}
extern "C"
{
  extern int clock_getcpuclockid(::pid_t __pid, ::clockid_t *__clock_id) throw();
}
extern "C"
{
  extern int timer_create(::clockid_t __clock_id, ::sigevent *__restrict __evp, ::timer_t *__restrict __timerid) throw();
}
extern "C"
{
  extern int timer_delete(::timer_t __timerid) throw();
}
extern "C"
{
  extern int timer_settime(::timer_t __timerid, int __flags, const ::itimerspec *__restrict __value, ::itimerspec *__restrict __ovalue) throw();
}
extern "C"
{
  extern int timer_gettime(::timer_t __timerid, ::itimerspec *__value) throw();
}
extern "C"
{
  extern int timer_getoverrun(::timer_t __timerid) throw();
}
extern "C"
{
  extern int timespec_get(::timespec *__ts, int __base) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int getdate_err;
}
extern "C"
{
  extern ::tm *getdate(const char *__string);
}
extern "C"
{
  extern int getdate_r(const char *__restrict __string, ::tm *__restrict __resbufp);
}
struct  __pthread_rwlock_arch_t
{
    unsigned int __readers;
    unsigned int __writers;
    unsigned int __wrphase_futex;
    unsigned int __writers_futex;
    unsigned int __pad3;
    unsigned int __pad4;
    int __cur_writer;
    int __shared;
    signed char __rwelision;
    unsigned char __pad1[7L];
    unsigned long int __pad2;
    unsigned int __flags;
};
struct __pthread_internal_list;
struct  __pthread_internal_list
{
    ::__pthread_internal_list *__prev;
    ::__pthread_internal_list *__next;
};
typedef ::__pthread_internal_list __pthread_list_t;
struct  __pthread_mutex_s
{
    int __lock;
    unsigned int __count;
    int __owner;
    unsigned int __nusers;
    int __kind;
    short int __spins;
    short int __elision;
    ::__pthread_list_t __list;
};
struct  __pthread_cond_s
{
    union 
    {
        __extension__ unsigned long long int __wseq;
        struct 
        {
            unsigned int __low;
            unsigned int __high;
        } __wseq32;
    };
    union 
    {
        __extension__ unsigned long long int __g1_start;
        struct 
        {
            unsigned int __low;
            unsigned int __high;
        } __g1_start32;
    };
    unsigned int __g_refs[2L];
    unsigned int __g_size[2L];
    unsigned int __g1_orig_size;
    unsigned int __wrefs;
    unsigned int __g_signals[2L];
};
typedef unsigned long int pthread_t;
union  pthread_mutexattr_t
{
    char __size[4L];
    int __align;
};
union  pthread_condattr_t
{
    char __size[4L];
    int __align;
};
typedef unsigned int pthread_key_t;
typedef int pthread_once_t;
union  pthread_attr_t
{
    char __size[56L];
    long int __align;
};
union  pthread_mutex_t
{
    ::__pthread_mutex_s __data;
    char __size[40L];
    long int __align;
};
union  pthread_cond_t
{
    ::__pthread_cond_s __data;
    char __size[48L];
    __extension__ long long int __align;
};
union  pthread_rwlock_t
{
    ::__pthread_rwlock_arch_t __data;
    char __size[56L];
    long int __align;
};
union  pthread_rwlockattr_t
{
    char __size[8L];
    long int __align;
};
typedef volatile int pthread_spinlock_t;
union  pthread_barrier_t
{
    char __size[32L];
    long int __align;
};
union  pthread_barrierattr_t
{
    char __size[4L];
    int __align;
};
typedef long int __jmp_buf[8L];
enum mcc_enum_anon_42
{
  PTHREAD_CREATE_JOINABLE = 0,
  PTHREAD_CREATE_DETACHED = 1
};
enum mcc_enum_anon_43
{
  PTHREAD_MUTEX_TIMED_NP = 0,
  PTHREAD_MUTEX_RECURSIVE_NP = 1,
  PTHREAD_MUTEX_ERRORCHECK_NP = 2,
  PTHREAD_MUTEX_ADAPTIVE_NP = 3,
  PTHREAD_MUTEX_NORMAL = ::PTHREAD_MUTEX_TIMED_NP,
  PTHREAD_MUTEX_RECURSIVE = ::PTHREAD_MUTEX_RECURSIVE_NP,
  PTHREAD_MUTEX_ERRORCHECK = ::PTHREAD_MUTEX_ERRORCHECK_NP,
  PTHREAD_MUTEX_DEFAULT = ::PTHREAD_MUTEX_NORMAL,
  PTHREAD_MUTEX_FAST_NP = ::PTHREAD_MUTEX_TIMED_NP
};
enum mcc_enum_anon_44
{
  PTHREAD_MUTEX_STALLED = 0,
  PTHREAD_MUTEX_STALLED_NP = ::PTHREAD_MUTEX_STALLED,
  PTHREAD_MUTEX_ROBUST = 1,
  PTHREAD_MUTEX_ROBUST_NP = ::PTHREAD_MUTEX_ROBUST
};
enum mcc_enum_anon_45
{
  PTHREAD_PRIO_NONE = 0,
  PTHREAD_PRIO_INHERIT = 1,
  PTHREAD_PRIO_PROTECT = 2
};
enum mcc_enum_anon_46
{
  PTHREAD_RWLOCK_PREFER_READER_NP = 0,
  PTHREAD_RWLOCK_PREFER_WRITER_NP = 1,
  PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP = 2,
  PTHREAD_RWLOCK_DEFAULT_NP = ::PTHREAD_RWLOCK_PREFER_READER_NP
};
enum mcc_enum_anon_47
{
  PTHREAD_INHERIT_SCHED = 0,
  PTHREAD_EXPLICIT_SCHED = 1
};
enum mcc_enum_anon_48
{
  PTHREAD_SCOPE_SYSTEM = 0,
  PTHREAD_SCOPE_PROCESS = 1
};
enum mcc_enum_anon_49
{
  PTHREAD_PROCESS_PRIVATE = 0,
  PTHREAD_PROCESS_SHARED = 1
};
struct _pthread_cleanup_buffer;
struct  _pthread_cleanup_buffer
{
    void (*__routine)(void *);
    void *__arg;
    int __canceltype;
    ::_pthread_cleanup_buffer *__prev;
};
enum mcc_enum_anon_50
{
  PTHREAD_CANCEL_ENABLE = 0,
  PTHREAD_CANCEL_DISABLE = 1
};
enum mcc_enum_anon_51
{
  PTHREAD_CANCEL_DEFERRED = 0,
  PTHREAD_CANCEL_ASYNCHRONOUS = 1
};
extern "C"
{
  extern int pthread_create(::pthread_t *__restrict __newthread, const ::pthread_attr_t *__restrict __attr, void *(*__start_routine)(void *), void *__restrict __arg) throw() __attribute__((__nonnull__(1, 3)));
}
extern "C"
{
  extern void pthread_exit(void *__retval) __attribute__((__noreturn__));
}
extern "C"
{
  extern int pthread_join(::pthread_t __th, void **__thread_return);
}
extern "C"
{
  extern int pthread_tryjoin_np(::pthread_t __th, void **__thread_return) throw();
}
extern "C"
{
  extern int pthread_timedjoin_np(::pthread_t __th, void **__thread_return, const ::timespec *__abstime);
}
extern "C"
{
  extern int pthread_detach(::pthread_t __th) throw();
}
extern "C"
{
  extern ::pthread_t pthread_self() throw() __attribute__((__const__));
}
extern "C"
{
  extern inline int pthread_equal(::pthread_t __thread1, ::pthread_t __thread2) throw() __attribute__((__const__)) __attribute__((__leaf__)) __attribute__((__gnu_inline__));
}
extern "C"
{
  extern int pthread_attr_init(::pthread_attr_t *__attr) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_attr_destroy(::pthread_attr_t *__attr) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_attr_getdetachstate(const ::pthread_attr_t *__attr, int *__detachstate) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int pthread_attr_setdetachstate(::pthread_attr_t *__attr, int __detachstate) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_attr_getguardsize(const ::pthread_attr_t *__attr, ::size_t *__guardsize) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int pthread_attr_setguardsize(::pthread_attr_t *__attr, ::size_t __guardsize) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_attr_getschedparam(const ::pthread_attr_t *__restrict __attr, ::sched_param *__restrict __param) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int pthread_attr_setschedparam(::pthread_attr_t *__restrict __attr, const ::sched_param *__restrict __param) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int pthread_attr_getschedpolicy(const ::pthread_attr_t *__restrict __attr, int *__restrict __policy) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int pthread_attr_setschedpolicy(::pthread_attr_t *__attr, int __policy) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_attr_getinheritsched(const ::pthread_attr_t *__restrict __attr, int *__restrict __inherit) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int pthread_attr_setinheritsched(::pthread_attr_t *__attr, int __inherit) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_attr_getscope(const ::pthread_attr_t *__restrict __attr, int *__restrict __scope) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int pthread_attr_setscope(::pthread_attr_t *__attr, int __scope) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_attr_getstackaddr(const ::pthread_attr_t *__restrict __attr, void **__restrict __stackaddr) throw() __attribute__((__nonnull__(1, 2))) __attribute__((__deprecated__));
}
extern "C"
{
  extern int pthread_attr_setstackaddr(::pthread_attr_t *__attr, void *__stackaddr) throw() __attribute__((__nonnull__(1))) __attribute__((__deprecated__));
}
extern "C"
{
  extern int pthread_attr_getstacksize(const ::pthread_attr_t *__restrict __attr, ::size_t *__restrict __stacksize) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int pthread_attr_setstacksize(::pthread_attr_t *__attr, ::size_t __stacksize) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_attr_getstack(const ::pthread_attr_t *__restrict __attr, void **__restrict __stackaddr, ::size_t *__restrict __stacksize) throw() __attribute__((__nonnull__(1, 2, 3)));
}
extern "C"
{
  extern int pthread_attr_setstack(::pthread_attr_t *__attr, void *__stackaddr, ::size_t __stacksize) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_attr_setaffinity_np(::pthread_attr_t *__attr, ::size_t __cpusetsize, const ::cpu_set_t *__cpuset) throw() __attribute__((__nonnull__(1, 3)));
}
extern "C"
{
  extern int pthread_attr_getaffinity_np(const ::pthread_attr_t *__attr, ::size_t __cpusetsize, ::cpu_set_t *__cpuset) throw() __attribute__((__nonnull__(1, 3)));
}
extern "C"
{
  extern int pthread_getattr_default_np(::pthread_attr_t *__attr) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_setattr_default_np(const ::pthread_attr_t *__attr) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_getattr_np(::pthread_t __th, ::pthread_attr_t *__attr) throw() __attribute__((__nonnull__(2)));
}
extern "C"
{
  extern int pthread_setschedparam(::pthread_t __target_thread, int __policy, const ::sched_param *__param) throw() __attribute__((__nonnull__(3)));
}
extern "C"
{
  extern int pthread_getschedparam(::pthread_t __target_thread, int *__restrict __policy, ::sched_param *__restrict __param) throw() __attribute__((__nonnull__(2, 3)));
}
extern "C"
{
  extern int pthread_setschedprio(::pthread_t __target_thread, int __prio) throw();
}
extern "C"
{
  extern int pthread_getname_np(::pthread_t __target_thread, char *__buf, ::size_t __buflen) throw() __attribute__((__nonnull__(2)));
}
extern "C"
{
  extern int pthread_setname_np(::pthread_t __target_thread, const char *__name) throw() __attribute__((__nonnull__(2)));
}
extern "C"
{
  extern int pthread_getconcurrency() throw();
}
extern "C"
{
  extern int pthread_setconcurrency(int __level) throw();
}
extern "C"
{
  extern int pthread_yield() throw();
}
extern "C"
{
  extern int pthread_setaffinity_np(::pthread_t __th, ::size_t __cpusetsize, const ::cpu_set_t *__cpuset) throw() __attribute__((__nonnull__(3)));
}
extern "C"
{
  extern int pthread_getaffinity_np(::pthread_t __th, ::size_t __cpusetsize, ::cpu_set_t *__cpuset) throw() __attribute__((__nonnull__(3)));
}
extern "C"
{
  extern int pthread_once(::pthread_once_t *__once_control, void (*__init_routine)()) __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int pthread_setcancelstate(int __state, int *__oldstate);
}
extern "C"
{
  extern int pthread_setcanceltype(int __type, int *__oldtype);
}
extern "C"
{
  extern int pthread_cancel(::pthread_t __th);
}
extern "C"
{
  extern void pthread_testcancel();
}
struct __attribute__((__aligned__))  __pthread_unwind_buf_t
{
    struct  mcc_struct_anon_44
    {
        ::__jmp_buf __cancel_jmp_buf;
        int __mask_was_saved;
    };
    ::__pthread_unwind_buf_t::mcc_struct_anon_44 __cancel_jmp_buf[1L];
    void *__pad[4L];
};
struct  __pthread_cleanup_frame
{
    void (*__cancel_routine)(void *);
    void *__cancel_arg;
    int __do_it;
    int __cancel_type;
};
class  __pthread_cleanup_class
{
    void (*__cancel_routine)(void *);
    void *__cancel_arg;
    int __do_it;
    int __cancel_type;
  public:
    inline __pthread_cleanup_class(void (*__fct)(void *), void *__arg)
      : __cancel_routine(__fct), __cancel_arg(__arg), __do_it(1)
    {
    }
    inline ~__pthread_cleanup_class()
    {
      if ((*this).__do_it)
        {
          (*this).__cancel_routine((*this).__cancel_arg);
        }
    }
    inline void __setdoit(int __newval)
    {
      (*this).__do_it = __newval;
    }
    inline void __defer()
    {
      ::pthread_setcanceltype(::PTHREAD_CANCEL_DEFERRED, &(*this).__cancel_type);
    }
    inline void __restore() const 
    {
      ::pthread_setcanceltype((*this).__cancel_type, 0);
    }
};
struct __jmp_buf_tag;
extern "C"
{
  extern int __sigsetjmp(::__jmp_buf_tag *__env, int __savemask) throw();
}
extern "C"
{
  extern int pthread_mutex_init(::pthread_mutex_t *__mutex, const ::pthread_mutexattr_t *__mutexattr) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_mutex_destroy(::pthread_mutex_t *__mutex) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_mutex_trylock(::pthread_mutex_t *__mutex) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_mutex_lock(::pthread_mutex_t *__mutex) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_mutex_timedlock(::pthread_mutex_t *__restrict __mutex, const ::timespec *__restrict __abstime) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int pthread_mutex_unlock(::pthread_mutex_t *__mutex) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_mutex_getprioceiling(const ::pthread_mutex_t *__restrict __mutex, int *__restrict __prioceiling) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int pthread_mutex_setprioceiling(::pthread_mutex_t *__restrict __mutex, int __prioceiling, int *__restrict __old_ceiling) throw() __attribute__((__nonnull__(1, 3)));
}
extern "C"
{
  extern int pthread_mutex_consistent(::pthread_mutex_t *__mutex) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_mutex_consistent_np(::pthread_mutex_t *__mutex) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_mutexattr_init(::pthread_mutexattr_t *__attr) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_mutexattr_destroy(::pthread_mutexattr_t *__attr) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_mutexattr_getpshared(const ::pthread_mutexattr_t *__restrict __attr, int *__restrict __pshared) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int pthread_mutexattr_setpshared(::pthread_mutexattr_t *__attr, int __pshared) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_mutexattr_gettype(const ::pthread_mutexattr_t *__restrict __attr, int *__restrict __kind) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int pthread_mutexattr_settype(::pthread_mutexattr_t *__attr, int __kind) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_mutexattr_getprotocol(const ::pthread_mutexattr_t *__restrict __attr, int *__restrict __protocol) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int pthread_mutexattr_setprotocol(::pthread_mutexattr_t *__attr, int __protocol) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_mutexattr_getprioceiling(const ::pthread_mutexattr_t *__restrict __attr, int *__restrict __prioceiling) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int pthread_mutexattr_setprioceiling(::pthread_mutexattr_t *__attr, int __prioceiling) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_mutexattr_getrobust(const ::pthread_mutexattr_t *__attr, int *__robustness) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int pthread_mutexattr_getrobust_np(const ::pthread_mutexattr_t *__attr, int *__robustness) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int pthread_mutexattr_setrobust(::pthread_mutexattr_t *__attr, int __robustness) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_mutexattr_setrobust_np(::pthread_mutexattr_t *__attr, int __robustness) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_rwlock_init(::pthread_rwlock_t *__restrict __rwlock, const ::pthread_rwlockattr_t *__restrict __attr) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_rwlock_destroy(::pthread_rwlock_t *__rwlock) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_rwlock_rdlock(::pthread_rwlock_t *__rwlock) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_rwlock_tryrdlock(::pthread_rwlock_t *__rwlock) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_rwlock_timedrdlock(::pthread_rwlock_t *__restrict __rwlock, const ::timespec *__restrict __abstime) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int pthread_rwlock_wrlock(::pthread_rwlock_t *__rwlock) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_rwlock_trywrlock(::pthread_rwlock_t *__rwlock) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_rwlock_timedwrlock(::pthread_rwlock_t *__restrict __rwlock, const ::timespec *__restrict __abstime) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int pthread_rwlock_unlock(::pthread_rwlock_t *__rwlock) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_rwlockattr_init(::pthread_rwlockattr_t *__attr) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_rwlockattr_destroy(::pthread_rwlockattr_t *__attr) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_rwlockattr_getpshared(const ::pthread_rwlockattr_t *__restrict __attr, int *__restrict __pshared) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int pthread_rwlockattr_setpshared(::pthread_rwlockattr_t *__attr, int __pshared) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_rwlockattr_getkind_np(const ::pthread_rwlockattr_t *__restrict __attr, int *__restrict __pref) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int pthread_rwlockattr_setkind_np(::pthread_rwlockattr_t *__attr, int __pref) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_cond_init(::pthread_cond_t *__restrict __cond, const ::pthread_condattr_t *__restrict __cond_attr) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_cond_destroy(::pthread_cond_t *__cond) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_cond_signal(::pthread_cond_t *__cond) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_cond_broadcast(::pthread_cond_t *__cond) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_cond_wait(::pthread_cond_t *__restrict __cond, ::pthread_mutex_t *__restrict __mutex) __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int pthread_cond_timedwait(::pthread_cond_t *__restrict __cond, ::pthread_mutex_t *__restrict __mutex, const ::timespec *__restrict __abstime) __attribute__((__nonnull__(1, 2, 3)));
}
extern "C"
{
  extern int pthread_condattr_init(::pthread_condattr_t *__attr) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_condattr_destroy(::pthread_condattr_t *__attr) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_condattr_getpshared(const ::pthread_condattr_t *__restrict __attr, int *__restrict __pshared) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int pthread_condattr_setpshared(::pthread_condattr_t *__attr, int __pshared) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_condattr_getclock(const ::pthread_condattr_t *__restrict __attr, ::__clockid_t *__restrict __clock_id) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int pthread_condattr_setclock(::pthread_condattr_t *__attr, ::__clockid_t __clock_id) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_spin_init(::pthread_spinlock_t *__lock, int __pshared) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_spin_destroy(::pthread_spinlock_t *__lock) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_spin_lock(::pthread_spinlock_t *__lock) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_spin_trylock(::pthread_spinlock_t *__lock) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_spin_unlock(::pthread_spinlock_t *__lock) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_barrier_init(::pthread_barrier_t *__restrict __barrier, const ::pthread_barrierattr_t *__restrict __attr, unsigned int __count) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_barrier_destroy(::pthread_barrier_t *__barrier) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_barrier_wait(::pthread_barrier_t *__barrier) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_barrierattr_init(::pthread_barrierattr_t *__attr) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_barrierattr_destroy(::pthread_barrierattr_t *__attr) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_barrierattr_getpshared(const ::pthread_barrierattr_t *__restrict __attr, int *__restrict __pshared) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int pthread_barrierattr_setpshared(::pthread_barrierattr_t *__attr, int __pshared) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_key_create(::pthread_key_t *__key, void (*__destr_function)(void *)) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int pthread_key_delete(::pthread_key_t __key) throw();
}
extern "C"
{
  extern void *pthread_getspecific(::pthread_key_t __key) throw();
}
extern "C"
{
  extern int pthread_setspecific(::pthread_key_t __key, const void *__pointer) throw();
}
extern "C"
{
  extern int pthread_getcpuclockid(::pthread_t __thread_id, ::__clockid_t *__clock_id) throw() __attribute__((__nonnull__(2)));
}
extern "C"
{
  extern int pthread_atfork(void (*__prepare)(), void (*__parent)(), void (*__child)()) throw();
}
extern "C"
{
  extern inline __attribute__((__const__)) __attribute__((__leaf__)) __attribute__((__gnu_inline__)) int pthread_equal(::pthread_t __thread1, ::pthread_t __thread2) throw()
  {
    return __thread1 == __thread2;
  }
}
typedef ::pthread_t __gthread_t;
typedef ::pthread_key_t __gthread_key_t;
typedef ::pthread_once_t __gthread_once_t;
typedef ::pthread_mutex_t __gthread_mutex_t;
typedef ::pthread_mutex_t __gthread_recursive_mutex_t;
typedef ::pthread_cond_t __gthread_cond_t;
typedef ::timespec __gthread_time_t;
static int __gthrw_pthread_once(::pthread_once_t *, void (*)()) throw() __attribute__((__weakref__("pthread_once")));
static void *__gthrw_pthread_getspecific(::pthread_key_t) throw() __attribute__((__weakref__("pthread_getspecific")));
static int __gthrw_pthread_setspecific(::pthread_key_t, const void *) throw() __attribute__((__weakref__("pthread_setspecific")));
static int __gthrw_pthread_create(::pthread_t *__restrict , const ::pthread_attr_t *__restrict , void *(*)(void *), void *__restrict ) throw() __attribute__((__weakref__("pthread_create")));
static int __gthrw_pthread_join(::pthread_t, void **) throw() __attribute__((__weakref__("pthread_join")));
static int __gthrw_pthread_equal(::pthread_t, ::pthread_t) throw() __attribute__((__weakref__("pthread_equal")));
static ::pthread_t __gthrw_pthread_self() throw() __attribute__((__weakref__("pthread_self")));
static int __gthrw_pthread_detach(::pthread_t) throw() __attribute__((__weakref__("pthread_detach")));
static int __gthrw_pthread_cancel(::pthread_t) throw() __attribute__((__weakref__("pthread_cancel")));
static int __gthrw_sched_yield() throw() __attribute__((__weakref__("sched_yield")));
static int __gthrw_pthread_mutex_lock(::pthread_mutex_t *) throw() __attribute__((__weakref__("pthread_mutex_lock")));
static int __gthrw_pthread_mutex_trylock(::pthread_mutex_t *) throw() __attribute__((__weakref__("pthread_mutex_trylock")));
static int __gthrw_pthread_mutex_timedlock(::pthread_mutex_t *__restrict , const ::timespec *__restrict ) throw() __attribute__((__weakref__("pthread_mutex_timedlock")));
static int __gthrw_pthread_mutex_unlock(::pthread_mutex_t *) throw() __attribute__((__weakref__("pthread_mutex_unlock")));
static int __gthrw_pthread_mutex_init(::pthread_mutex_t *, const ::pthread_mutexattr_t *) throw() __attribute__((__weakref__("pthread_mutex_init")));
static int __gthrw_pthread_mutex_destroy(::pthread_mutex_t *) throw() __attribute__((__weakref__("pthread_mutex_destroy")));
static int __gthrw_pthread_cond_init(::pthread_cond_t *__restrict , const ::pthread_condattr_t *__restrict ) throw() __attribute__((__weakref__("pthread_cond_init")));
static int __gthrw_pthread_cond_broadcast(::pthread_cond_t *) throw() __attribute__((__weakref__("pthread_cond_broadcast")));
static int __gthrw_pthread_cond_signal(::pthread_cond_t *) throw() __attribute__((__weakref__("pthread_cond_signal")));
static int __gthrw_pthread_cond_wait(::pthread_cond_t *__restrict , ::pthread_mutex_t *__restrict ) throw() __attribute__((__weakref__("pthread_cond_wait")));
static int __gthrw_pthread_cond_timedwait(::pthread_cond_t *__restrict , ::pthread_mutex_t *__restrict , const ::timespec *__restrict ) throw() __attribute__((__weakref__("pthread_cond_timedwait")));
static int __gthrw_pthread_cond_destroy(::pthread_cond_t *) throw() __attribute__((__weakref__("pthread_cond_destroy")));
static int __gthrw_pthread_key_create(::pthread_key_t *, void (*)(void *)) throw() __attribute__((__weakref__("pthread_key_create")));
static int __gthrw_pthread_key_delete(::pthread_key_t) throw() __attribute__((__weakref__("pthread_key_delete")));
static int __gthrw_pthread_mutexattr_init(::pthread_mutexattr_t *) throw() __attribute__((__weakref__("pthread_mutexattr_init")));
static int __gthrw_pthread_mutexattr_settype(::pthread_mutexattr_t *, int) throw() __attribute__((__weakref__("pthread_mutexattr_settype")));
static int __gthrw_pthread_mutexattr_destroy(::pthread_mutexattr_t *) throw() __attribute__((__weakref__("pthread_mutexattr_destroy")));
static int __gthrw___pthread_key_create(::pthread_key_t *, void (*)(void *)) throw() __attribute__((__weakref__("__pthread_key_create")));
static inline int __gthread_active_p()
{
  static void *const __gthread_active_ptr((void *)::__gthrw___pthread_key_create);
  return __gthread_active_ptr != 0;
}
static inline int __gthread_create(::__gthread_t *__threadid, void *(*__func)(void *), void *__args)
{
  return ::__gthrw_pthread_create(__threadid, 0L, __func, __args);
}
static inline int __gthread_join(::__gthread_t __threadid, void **__value_ptr)
{
  return ::__gthrw_pthread_join(__threadid, __value_ptr);
}
static inline int __gthread_detach(::__gthread_t __threadid)
{
  return ::__gthrw_pthread_detach(__threadid);
}
static inline int __gthread_equal(::__gthread_t __t1, ::__gthread_t __t2)
{
  return ::__gthrw_pthread_equal(__t1, __t2);
}
static inline ::__gthread_t __gthread_self()
{
  return ::__gthrw_pthread_self();
}
static inline int __gthread_yield()
{
  return ::__gthrw_sched_yield();
}
static inline int __gthread_once(::__gthread_once_t *__once, void (*__func)())
{
  if (::__gthread_active_p())
    {
      return ::__gthrw_pthread_once(__once, __func);
    }
  else
    {
      return  -1;
    }
}
static inline int __gthread_key_create(::__gthread_key_t *__key, void (*__dtor)(void *))
{
  return ::__gthrw_pthread_key_create(__key, __dtor);
}
static inline int __gthread_key_delete(::__gthread_key_t __key)
{
  return ::__gthrw_pthread_key_delete(__key);
}
static inline void *__gthread_getspecific(::__gthread_key_t __key)
{
  return ::__gthrw_pthread_getspecific(__key);
}
static inline int __gthread_setspecific(::__gthread_key_t __key, const void *__ptr)
{
  return ::__gthrw_pthread_setspecific(__key, __ptr);
}
static inline void __gthread_mutex_init_function(::__gthread_mutex_t *__mutex)
{
  if (::__gthread_active_p())
    {
      ::__gthrw_pthread_mutex_init(__mutex, 0L);
    }
}
static inline int __gthread_mutex_destroy(::__gthread_mutex_t *__mutex)
{
  if (::__gthread_active_p())
    {
      return ::__gthrw_pthread_mutex_destroy(__mutex);
    }
  else
    {
      return 0;
    }
}
static inline int __gthread_mutex_lock(::__gthread_mutex_t *__mutex)
{
  if (::__gthread_active_p())
    {
      return ::__gthrw_pthread_mutex_lock(__mutex);
    }
  else
    {
      return 0;
    }
}
static inline int __gthread_mutex_trylock(::__gthread_mutex_t *__mutex)
{
  if (::__gthread_active_p())
    {
      return ::__gthrw_pthread_mutex_trylock(__mutex);
    }
  else
    {
      return 0;
    }
}
static inline int __gthread_mutex_timedlock(::__gthread_mutex_t *__mutex, const ::__gthread_time_t *__abs_timeout)
{
  if (::__gthread_active_p())
    {
      return ::__gthrw_pthread_mutex_timedlock(__mutex, __abs_timeout);
    }
  else
    {
      return 0;
    }
}
static inline int __gthread_mutex_unlock(::__gthread_mutex_t *__mutex)
{
  if (::__gthread_active_p())
    {
      return ::__gthrw_pthread_mutex_unlock(__mutex);
    }
  else
    {
      return 0;
    }
}
static inline int __gthread_recursive_mutex_lock(::__gthread_recursive_mutex_t *__mutex)
{
  return ::__gthread_mutex_lock(__mutex);
}
static inline int __gthread_recursive_mutex_trylock(::__gthread_recursive_mutex_t *__mutex)
{
  return ::__gthread_mutex_trylock(__mutex);
}
static inline int __gthread_recursive_mutex_timedlock(::__gthread_recursive_mutex_t *__mutex, const ::__gthread_time_t *__abs_timeout)
{
  return ::__gthread_mutex_timedlock(__mutex, __abs_timeout);
}
static inline int __gthread_recursive_mutex_unlock(::__gthread_recursive_mutex_t *__mutex)
{
  return ::__gthread_mutex_unlock(__mutex);
}
static inline int __gthread_recursive_mutex_destroy(::__gthread_recursive_mutex_t *__mutex)
{
  return ::__gthread_mutex_destroy(__mutex);
}
static inline int __gthread_cond_broadcast(::__gthread_cond_t *__cond)
{
  return ::__gthrw_pthread_cond_broadcast(__cond);
}
static inline int __gthread_cond_signal(::__gthread_cond_t *__cond)
{
  return ::__gthrw_pthread_cond_signal(__cond);
}
static inline int __gthread_cond_wait(::__gthread_cond_t *__cond, ::__gthread_mutex_t *__mutex)
{
  return ::__gthrw_pthread_cond_wait(__cond, __mutex);
}
static inline int __gthread_cond_timedwait(::__gthread_cond_t *__cond, ::__gthread_mutex_t *__mutex, const ::__gthread_time_t *__abs_timeout)
{
  return ::__gthrw_pthread_cond_timedwait(__cond, __mutex, __abs_timeout);
}
static inline int __gthread_cond_wait_recursive(::__gthread_cond_t *__cond, ::__gthread_recursive_mutex_t *__mutex)
{
  return ::__gthread_cond_wait(__cond, __mutex);
}
static inline int __gthread_cond_destroy(::__gthread_cond_t *__cond)
{
  return ::__gthrw_pthread_cond_destroy(__cond);
}
#pragma GCC visibility pop
typedef int _Atomic_word;
namespace __gnu_cxx __attribute__((__visibility__("default"))) {
  static inline ::_Atomic_word __exchange_and_add(volatile ::_Atomic_word *__mem, int __val)
  {
    return __atomic_fetch_add(__mem, __val, 4);
  }
  static inline void __atomic_add(volatile ::_Atomic_word *__mem, int __val)
  {
    __atomic_fetch_add(__mem, __val, 4);
  }
  static inline ::_Atomic_word __exchange_and_add_single(::_Atomic_word *__mem, int __val)
  {
    ::_Atomic_word __result(*__mem);
    *__mem += __val;
    return __result;
  }
  static inline void __atomic_add_single(::_Atomic_word *__mem, int __val)
  {
    *__mem += __val;
  }
  static inline __attribute__((__unused__)) ::_Atomic_word __exchange_and_add_dispatch(::_Atomic_word *__mem, int __val)
  {
    if (::__gthread_active_p())
      {
        return ::__gnu_cxx::__exchange_and_add(__mem, __val);
      }
    else
      {
        return ::__gnu_cxx::__exchange_and_add_single(__mem, __val);
      }
  }
  static inline __attribute__((__unused__)) void __atomic_add_dispatch(::_Atomic_word *__mem, int __val)
  {
    if (::__gthread_active_p())
      {
        ::__gnu_cxx::__atomic_add(__mem, __val);
      }
    else
      {
        ::__gnu_cxx::__atomic_add_single(__mem, __val);
      }
  }
  template < typename _Alloc >
  struct  __alloc_traits
  {
      typedef _Alloc allocator_type;
      typedef typename _Alloc::pointer pointer;
      typedef typename _Alloc::const_pointer const_pointer;
      typedef typename _Alloc::value_type value_type;
      typedef typename _Alloc::reference reference;
      typedef typename _Alloc::const_reference const_reference;
      typedef typename _Alloc::size_type size_type;
      typedef typename _Alloc::difference_type difference_type;
      static inline typename ::__gnu_cxx::__alloc_traits<_Alloc>::pointer allocate(_Alloc &__a, typename ::__gnu_cxx::__alloc_traits<_Alloc>::size_type __n)
      {
        return __a.allocate(__n);
      }
      static inline void deallocate(_Alloc &__a, typename ::__gnu_cxx::__alloc_traits<_Alloc>::pointer __p, typename ::__gnu_cxx::__alloc_traits<_Alloc>::size_type __n)
      {
        __a.deallocate(__p, __n);
      }
      template < typename _Tp >
      static inline void construct(_Alloc &__a, typename ::__gnu_cxx::__alloc_traits<_Alloc>::pointer __p, const _Tp &__arg)
      {
        __a.construct(__p, __arg);
      }
      static inline void destroy(_Alloc &__a, typename ::__gnu_cxx::__alloc_traits<_Alloc>::pointer __p)
      {
        __a.destroy(__p);
      }
      static inline typename ::__gnu_cxx::__alloc_traits<_Alloc>::size_type max_size(const _Alloc &__a)
      {
        return __a.max_size();
      }
      static inline const _Alloc &_S_select_on_copy(const _Alloc &__a)
      {
        return __a;
      }
      static inline void _S_on_swap(_Alloc &__a, _Alloc &__b)
      {
        std::__alloc_swap<_Alloc>::_S_do_it(__a, __b);
      }
      template < typename _Tp >
      struct  rebind
      {
          typedef typename _Alloc::template rebind< _Tp>::other other;
      };
  };
 /* Instantiation of class template '::__gnu_cxx::__conditional_type<true, ::__gnu_cxx::__numeric_traits_integer<int>, ::__gnu_cxx::__numeric_traits_floating<int> >' */ 
 /* Instantiation of class template '::__gnu_cxx::__numeric_traits_integer<int>' */ 
 /* Instantiation of class template '::__gnu_cxx::__numeric_traits<int>' */ 
}
namespace std __attribute__((__visibility__("default"))) {
  inline namespace __cxx11 __attribute__((__abi_tag__("cxx11"))) {
    template < typename _CharT, typename _Traits, typename _Alloc >
    class  basic_string
    {
        typedef typename ::__gnu_cxx::__alloc_traits<_Alloc>::template rebind< _CharT>::other _Char_alloc_type;
        typedef ::__gnu_cxx::__alloc_traits<typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::_Char_alloc_type> _Alloc_traits;
      public:
        typedef _Traits traits_type;
        typedef typename _Traits::char_type value_type;
        typedef typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::_Char_alloc_type allocator_type;
        typedef typename ::__gnu_cxx::__alloc_traits<typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::_Char_alloc_type>::size_type size_type;
        typedef typename ::__gnu_cxx::__alloc_traits<typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::_Char_alloc_type>::difference_type difference_type;
        typedef typename ::__gnu_cxx::__alloc_traits<typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::_Char_alloc_type>::reference reference;
        typedef typename ::__gnu_cxx::__alloc_traits<typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::_Char_alloc_type>::const_reference const_reference;
        typedef typename ::__gnu_cxx::__alloc_traits<typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::_Char_alloc_type>::pointer pointer;
        typedef typename ::__gnu_cxx::__alloc_traits<typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::_Char_alloc_type>::const_pointer const_pointer;
        typedef ::__gnu_cxx::__normal_iterator<typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::pointer, ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> > iterator;
        typedef ::__gnu_cxx::__normal_iterator<typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::const_pointer, ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> > const_iterator;
        typedef ::std::reverse_iterator<typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::const_iterator> const_reverse_iterator;
        typedef ::std::reverse_iterator<typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::iterator> reverse_iterator;
        static const typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type npos = static_cast<typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type>( -1);
      private:
        typedef typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::iterator __const_iterator;
        struct  _Alloc_hider : ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::allocator_type
        {
            inline _Alloc_hider(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::pointer __dat, const _Alloc &__a  = (_Alloc()))
              : allocator_type(__a), _M_p(__dat)
            {
            }
            typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::pointer _M_p;
        };
        typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::_Alloc_hider _M_dataplus;
        typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type _M_string_length;
        enum mcc_enum_anon_52
        {
          _S_local_capacity = 15 / sizeof(_CharT)
        };
        union 
        {
            _CharT _M_local_buf[::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::_S_local_capacity + 1];
            typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type _M_allocated_capacity;
        };
        inline void _M_data(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::pointer __p)
        {
          ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::_M_dataplus._M_p = __p;
        }
        inline void _M_length(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __length)
        {
          ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::_M_string_length = __length;
        }
        inline typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::pointer _M_data() const 
        {
          return ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::_M_dataplus._M_p;
        }
        inline typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::pointer _M_local_data()
        {
          return ((typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::pointer(::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::_M_local_buf)));
        }
        inline typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::const_pointer _M_local_data() const 
        {
          return ((typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::const_pointer(::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::_M_local_buf)));
        }
        inline void _M_capacity(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __capacity)
        {
          ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::_M_allocated_capacity = __capacity;
        }
        inline void _M_set_length(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n)
        {
          (*this)._M_length(__n);
          traits_type::assign((*this)._M_data()[__n], _CharT());
        }
        inline bool _M_is_local() const 
        {
          return (*this)._M_data() == (*this)._M_local_data();
        }
        typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::pointer _M_create(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type &__capacity, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __old_capacity);
        inline void _M_dispose()
        {
          if (!(*this)._M_is_local())
            {
              (*this)._M_destroy(::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::_M_allocated_capacity);
            }
        }
        inline void _M_destroy(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __size) throw()
        {
          _Alloc_traits::deallocate((*this)._M_get_allocator(), (*this)._M_data(), __size + 1);
        }
        template < typename _InIterator >
        inline void _M_construct_aux(_InIterator __beg, _InIterator __end, ::std::__false_type)
        {
          typedef typename ::std::iterator_traits<_InIterator>::iterator_category _Tag;
          (*this)._M_construct(__beg, __end, _Tag());
        }
        template < typename _Integer >
        inline void _M_construct_aux(_Integer __beg, _Integer __end, ::std::__true_type)
        {
          (*this)._M_construct_aux_2(static_cast<typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type>(__beg), __end);
        }
        inline void _M_construct_aux_2(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __req, _CharT __c)
        {
          (*this)._M_construct(__req, __c);
        }
        template < typename _InIterator >
        inline void _M_construct(_InIterator __beg, _InIterator __end)
        {
          typedef typename ::std::__is_integer<_InIterator>::__type _Integral;
          (*this)._M_construct_aux(__beg, __end, _Integral());
        }
        template < typename _InIterator >
        void _M_construct(_InIterator __beg, _InIterator __end, ::std::input_iterator_tag);
        template < typename _FwdIterator >
        void _M_construct(_FwdIterator __beg, _FwdIterator __end, ::std::forward_iterator_tag);
        void _M_construct(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n, _CharT __c);
        inline typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::allocator_type &_M_get_allocator()
        {
          return ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::_M_dataplus;
        }
        inline const typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::allocator_type &_M_get_allocator() const 
        {
          return ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::_M_dataplus;
        }
        inline typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type _M_check(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos, const char *__s) const 
        {
          if (__pos > this->size())
            {
              __throw_out_of_range_fmt("%s: __pos (which is %zu) > this->size() (which is %zu)", __s, __pos, this->size());
            }
          return __pos;
        }
        inline void _M_check_length(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n1, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n2, const char *__s) const 
        {
          if (this->max_size() - (this->size() - __n1) < __n2)
            {
              ::std::__throw_length_error(__s);
            }
        }
        inline typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type _M_limit(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __off) const 
        {
          const bool __testoff = __off < this->size() - __pos;
          return __testoff ? __off : this->size() - __pos;
        }
        inline bool _M_disjunct(const _CharT *__s) const 
        {
          return ::std::less<const _CharT *>()(__s, (*this)._M_data()) || ::std::less<const _CharT *>()((*this)._M_data() + this->size(), __s);
        }
        static inline void _S_copy(_CharT *__d, const _CharT *__s, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n)
        {
          if (__n == 1)
            {
              traits_type::assign(*__d, *__s);
            }
          else
            {
              traits_type::copy(__d, __s, __n);
            }
        }
        static inline void _S_move(_CharT *__d, const _CharT *__s, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n)
        {
          if (__n == 1)
            {
              traits_type::assign(*__d, *__s);
            }
          else
            {
              traits_type::move(__d, __s, __n);
            }
        }
        static inline void _S_assign(_CharT *__d, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n, _CharT __c)
        {
          if (__n == 1)
            {
              traits_type::assign(*__d, __c);
            }
          else
            {
              traits_type::assign(__d, __n, __c);
            }
        }
        template < typename _Iterator >
        static inline void _S_copy_chars(_CharT *__p, _Iterator __k1, _Iterator __k2)
        {
          for (; __k1 != __k2; ( ++__k1, (void) ++__p))
            {
              traits_type::assign(*__p, *__k1);
            }
        }
        static inline void _S_copy_chars(_CharT *__p, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::iterator __k1, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::iterator __k2)
        {
          _S_copy_chars(__p, __k1.base(), __k2.base());
        }
        static inline void _S_copy_chars(_CharT *__p, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::const_iterator __k1, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::const_iterator __k2)
        {
          _S_copy_chars(__p, __k1.base(), __k2.base());
        }
        static inline void _S_copy_chars(_CharT *__p, _CharT *__k1, _CharT *__k2)
        {
          _S_copy(__p, __k1, __k2 - __k1);
        }
        static inline void _S_copy_chars(_CharT *__p, const _CharT *__k1, const _CharT *__k2)
        {
          _S_copy(__p, __k1, __k2 - __k1);
        }
        static inline int _S_compare(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n1, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n2)
        {
          const typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::difference_type __d = ((typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::difference_type(__n1 - __n2)));
          if (__d > ::__gnu_cxx::__numeric_traits_integer<int>::__max)
            {
              return ::__gnu_cxx::__numeric_traits_integer<int>::__max;
            }
          else
            {
              if (__d < ::__gnu_cxx::__numeric_traits_integer<int>::__min)
                {
                  return ::__gnu_cxx::__numeric_traits_integer<int>::__min;
                }
              else
                {
                  return int(__d);
                }
            }
        }
        void _M_assign(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__str);
        void _M_mutate(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __len1, const _CharT *__s, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __len2);
        void _M_erase(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n);
      public:
        inline basic_string()
          : _M_dataplus((*this)._M_local_data())
        {
          (*this)._M_set_length(0);
        }
        inline explicit basic_string(const _Alloc &__a)
          : _M_dataplus((*this)._M_local_data(), __a)
        {
          (*this)._M_set_length(0);
        }
        inline basic_string(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__str)
          : _M_dataplus((*this)._M_local_data(), _Alloc_traits::_S_select_on_copy(__str._M_get_allocator()))
        {
          (*this)._M_construct(__str._M_data(), __str._M_data() + __str.length());
        }
        inline basic_string(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__str, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos, const _Alloc &__a  = (_Alloc()))
          : _M_dataplus((*this)._M_local_data(), __a)
        {
          const _CharT *__start = __str._M_data() + __str._M_check(__pos, "basic_string::basic_string");
          (*this)._M_construct(__start, __start + __str._M_limit(__pos, ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::npos));
        }
        inline basic_string(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__str, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n)
          : _M_dataplus((*this)._M_local_data())
        {
          const _CharT *__start = __str._M_data() + __str._M_check(__pos, "basic_string::basic_string");
          (*this)._M_construct(__start, __start + __str._M_limit(__pos, __n));
        }
        inline basic_string(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__str, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n, const _Alloc &__a)
          : _M_dataplus((*this)._M_local_data(), __a)
        {
          const _CharT *__start = __str._M_data() + __str._M_check(__pos, "string::string");
          (*this)._M_construct(__start, __start + __str._M_limit(__pos, __n));
        }
        inline basic_string(const _CharT *__s, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n, const _Alloc &__a  = (_Alloc()))
          : _M_dataplus((*this)._M_local_data(), __a)
        {
          (*this)._M_construct(__s, __s + __n);
        }
        inline basic_string(const _CharT *__s, const _Alloc &__a  = (_Alloc()))
          : _M_dataplus((*this)._M_local_data(), __a)
        {
          (*this)._M_construct(__s, __s ? __s + traits_type::length(__s) : __s + ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::npos);
        }
        inline basic_string(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n, _CharT __c, const _Alloc &__a  = (_Alloc()))
          : _M_dataplus((*this)._M_local_data(), __a)
        {
          (*this)._M_construct(__n, __c);
        }
        template < typename _InputIterator >
        inline basic_string(_InputIterator __beg, _InputIterator __end, const _Alloc &__a  = (_Alloc()))
          : _M_dataplus((*this)._M_local_data(), __a)
        {
          (*this)._M_construct(__beg, __end);
        }
        inline ~basic_string()
        {
          (*this)._M_dispose();
        }
        inline ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &operator =(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__str)
        {
          return this->assign(__str);
        }
        inline ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &operator =(const _CharT *__s)
        {
          return this->assign(__s);
        }
        inline ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &operator =(_CharT __c)
        {
          this->assign(1, __c);
          return *this;
        }
        inline typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::iterator begin()
        {
          return ((typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::iterator((*this)._M_data())));
        }
        inline typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::const_iterator begin() const 
        {
          return ((typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::const_iterator((*this)._M_data())));
        }
        inline typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::iterator end()
        {
          return ((typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::iterator((*this)._M_data() + this->size())));
        }
        inline typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::const_iterator end() const 
        {
          return ((typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::const_iterator((*this)._M_data() + this->size())));
        }
        inline typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::reverse_iterator rbegin()
        {
          return ((typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::reverse_iterator(this->end())));
        }
        inline typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::const_reverse_iterator rbegin() const 
        {
          return ((typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::const_reverse_iterator(this->end())));
        }
        inline typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::reverse_iterator rend()
        {
          return ((typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::reverse_iterator(this->begin())));
        }
        inline typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::const_reverse_iterator rend() const 
        {
          return ((typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::const_reverse_iterator(this->begin())));
        }
        inline typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type size() const 
        {
          return ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::_M_string_length;
        }
        inline typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type length() const 
        {
          return ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::_M_string_length;
        }
        inline typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type max_size() const 
        {
          return (_Alloc_traits::max_size((*this)._M_get_allocator()) - 1) / 2;
        }
        void resize(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n, _CharT __c);
        inline void resize(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n)
        {
          this->resize(__n, _CharT());
        }
        inline typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type capacity() const 
        {
          return (*this)._M_is_local() ? ((typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type(::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::_S_local_capacity))) : ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::_M_allocated_capacity;
        }
        void reserve(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __res  = (0));
        inline void clear()
        {
          (*this)._M_set_length(0);
        }
        inline bool empty() const 
        {
          return this->size() == 0;
        }
        inline typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::const_reference operator [](typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos) const 
        {
          ;
          return (*this)._M_data()[__pos];
        }
        inline typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::reference operator [](typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos)
        {
          ;
          ;
          return (*this)._M_data()[__pos];
        }
        inline typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::const_reference at(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n) const 
        {
          if (__n >= this->size())
            {
              __throw_out_of_range_fmt("basic_string::at: __n (which is %zu) >= this->size() (which is %zu)", __n, this->size());
            }
          return (*this)._M_data()[__n];
        }
        inline typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::reference at(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n)
        {
          if (__n >= (*this).size())
            {
              __throw_out_of_range_fmt("basic_string::at: __n (which is %zu) >= this->size() (which is %zu)", __n, this->size());
            }
          return (*this)._M_data()[__n];
        }
        inline ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &operator +=(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__str)
        {
          return this->append(__str);
        }
        inline ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &operator +=(const _CharT *__s)
        {
          return this->append(__s);
        }
        inline ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &operator +=(_CharT __c)
        {
          this->push_back(__c);
          return *this;
        }
        inline ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &append(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__str)
        {
          return (*this)._M_append(__str._M_data(), __str.size());
        }
        inline ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &append(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__str, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n  = (::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::npos))
        {
          return (*this)._M_append(__str._M_data() + __str._M_check(__pos, "basic_string::append"), __str._M_limit(__pos, __n));
        }
        inline ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &append(const _CharT *__s, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n)
        {
          ;
          (*this)._M_check_length(((typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type(0))), __n, "basic_string::append");
          return (*this)._M_append(__s, __n);
        }
        inline ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &append(const _CharT *__s)
        {
          ;
          const typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n = traits_type::length(__s);
          (*this)._M_check_length(((typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type(0))), __n, "basic_string::append");
          return (*this)._M_append(__s, __n);
        }
        inline ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &append(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n, _CharT __c)
        {
          return (*this)._M_replace_aux(this->size(), ((typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type(0))), __n, __c);
        }
        template < typename _InputIterator >
        inline ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &append(_InputIterator __first, _InputIterator __last)
        {
          return this->replace((*this).end(), (*this).end(), __first, __last);
        }
        inline void push_back(_CharT __c)
        {
          const typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __size = this->size();
          if (__size + 1 > this->capacity())
            {
              this->_M_mutate(__size, ((typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type(0))), 0, ((typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type(1))));
            }
          traits_type::assign(this->_M_data()[__size], __c);
          this->_M_set_length(__size + 1);
        }
        inline ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &assign(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__str)
        {
          this->_M_assign(__str);
          return *this;
        }
        inline ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &assign(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__str, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n  = (::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::npos))
        {
          return (*this)._M_replace(((typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type(0))), this->size(), __str._M_data() + __str._M_check(__pos, "basic_string::assign"), __str._M_limit(__pos, __n));
        }
        inline ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &assign(const _CharT *__s, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n)
        {
          ;
          return (*this)._M_replace(((typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type(0))), this->size(), __s, __n);
        }
        inline ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &assign(const _CharT *__s)
        {
          ;
          return (*this)._M_replace(((typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type(0))), this->size(), __s, traits_type::length(__s));
        }
        inline ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &assign(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n, _CharT __c)
        {
          return (*this)._M_replace_aux(((typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type(0))), this->size(), __n, __c);
        }
        template < typename _InputIterator >
        inline ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &assign(_InputIterator __first, _InputIterator __last)
        {
          return this->replace((*this).begin(), (*this).end(), __first, __last);
        }
        inline void insert(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::iterator __p, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n, _CharT __c)
        {
          this->replace(__p, __p, __n, __c);
        }
        template < typename _InputIterator >
        inline void insert(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::iterator __p, _InputIterator __beg, _InputIterator __end)
        {
          this->replace(__p, __p, __beg, __end);
        }
        inline ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &insert(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos1, const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__str)
        {
          return this->replace(__pos1, ((typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type(0))), __str._M_data(), __str.size());
        }
        inline ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &insert(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos1, const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__str, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos2, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n  = (::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::npos))
        {
          return this->replace(__pos1, ((typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type(0))), __str._M_data() + __str._M_check(__pos2, "basic_string::insert"), __str._M_limit(__pos2, __n));
        }
        inline ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &insert(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos, const _CharT *__s, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n)
        {
          return this->replace(__pos, ((typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type(0))), __s, __n);
        }
        inline ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &insert(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos, const _CharT *__s)
        {
          ;
          return this->replace(__pos, ((typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type(0))), __s, traits_type::length(__s));
        }
        inline ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &insert(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n, _CharT __c)
        {
          return (*this)._M_replace_aux((*this)._M_check(__pos, "basic_string::insert"), ((typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type(0))), __n, __c);
        }
        inline typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::iterator insert(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::__const_iterator __p, _CharT __c)
        {
          ;
          const typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos = __p - (*this).begin();
          (*this)._M_replace_aux(__pos, ((typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type(0))), ((typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type(1))), __c);
          return ((typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::iterator((*this)._M_data() + __pos)));
        }
        inline ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &erase(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos  = (0), typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n  = (::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::npos))
        {
          (*this)._M_check(__pos, "basic_string::erase");
          if (__n == ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::npos)
            {
              this->_M_set_length(__pos);
            }
          else
            {
              if (__n != 0)
                {
                  this->_M_erase(__pos, (*this)._M_limit(__pos, __n));
                }
            }
          return *this;
        }
        inline typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::iterator erase(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::__const_iterator __position)
        {
          ;
          const typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos = __position - (*this).begin();
          this->_M_erase(__pos, ((typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type(1))));
          return ((typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::iterator((*this)._M_data() + __pos)));
        }
        inline typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::iterator erase(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::__const_iterator __first, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::__const_iterator __last)
        {
          ;
          const typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos = __first - (*this).begin();
          if (__last == (*this).end())
            {
              this->_M_set_length(__pos);
            }
          else
            {
              this->_M_erase(__pos, __last - __first);
            }
          return ((typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::iterator(this->_M_data() + __pos)));
        }
        inline ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &replace(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n, const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__str)
        {
          return this->replace(__pos, __n, __str._M_data(), __str.size());
        }
        inline ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &replace(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos1, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n1, const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__str, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos2, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n2  = (::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::npos))
        {
          return this->replace(__pos1, __n1, __str._M_data() + __str._M_check(__pos2, "basic_string::replace"), __str._M_limit(__pos2, __n2));
        }
        inline ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &replace(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n1, const _CharT *__s, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n2)
        {
          ;
          return (*this)._M_replace((*this)._M_check(__pos, "basic_string::replace"), (*this)._M_limit(__pos, __n1), __s, __n2);
        }
        inline ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &replace(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n1, const _CharT *__s)
        {
          ;
          return this->replace(__pos, __n1, __s, traits_type::length(__s));
        }
        inline ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &replace(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n1, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n2, _CharT __c)
        {
          return (*this)._M_replace_aux((*this)._M_check(__pos, "basic_string::replace"), (*this)._M_limit(__pos, __n1), __n2, __c);
        }
        inline ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &replace(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::__const_iterator __i1, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::__const_iterator __i2, const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__str)
        {
          return this->replace(__i1, __i2, __str._M_data(), __str.size());
        }
        inline ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &replace(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::__const_iterator __i1, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::__const_iterator __i2, const _CharT *__s, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n)
        {
          ;
          return this->replace(__i1 - (*this).begin(), __i2 - __i1, __s, __n);
        }
        inline ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &replace(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::__const_iterator __i1, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::__const_iterator __i2, const _CharT *__s)
        {
          ;
          return this->replace(__i1, __i2, __s, traits_type::length(__s));
        }
        inline ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &replace(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::__const_iterator __i1, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::__const_iterator __i2, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n, _CharT __c)
        {
          ;
          return (*this)._M_replace_aux(__i1 - (*this).begin(), __i2 - __i1, __n, __c);
        }
        template < typename _InputIterator >
        inline ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &replace(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::iterator __i1, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::iterator __i2, _InputIterator __k1, _InputIterator __k2)
        {
          ;
          ;
          typedef typename ::std::__is_integer<_InputIterator>::__type _Integral;
          return (*this)._M_replace_dispatch(__i1, __i2, __k1, __k2, _Integral());
        }
        inline ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &replace(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::__const_iterator __i1, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::__const_iterator __i2, _CharT *__k1, _CharT *__k2)
        {
          ;
          ;
          return this->replace(__i1 - (*this).begin(), __i2 - __i1, __k1, __k2 - __k1);
        }
        inline ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &replace(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::__const_iterator __i1, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::__const_iterator __i2, const _CharT *__k1, const _CharT *__k2)
        {
          ;
          ;
          return this->replace(__i1 - (*this).begin(), __i2 - __i1, __k1, __k2 - __k1);
        }
        inline ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &replace(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::__const_iterator __i1, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::__const_iterator __i2, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::iterator __k1, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::iterator __k2)
        {
          ;
          ;
          return this->replace(__i1 - (*this).begin(), __i2 - __i1, __k1.base(), __k2 - __k1);
        }
        inline ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &replace(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::__const_iterator __i1, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::__const_iterator __i2, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::const_iterator __k1, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::const_iterator __k2)
        {
          ;
          ;
          return this->replace(__i1 - (*this).begin(), __i2 - __i1, __k1.base(), __k2 - __k1);
        }
      private:
        template < typename _Integer >
        inline ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &_M_replace_dispatch(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::const_iterator __i1, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::const_iterator __i2, _Integer __n, _Integer __val, ::std::__true_type)
        {
          return (*this)._M_replace_aux(__i1 - (*this).begin(), __i2 - __i1, __n, __val);
        }
        template < typename _InputIterator >
        ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &_M_replace_dispatch(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::const_iterator __i1, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::const_iterator __i2, _InputIterator __k1, _InputIterator __k2, ::std::__false_type);
        ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &_M_replace_aux(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos1, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n1, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n2, _CharT __c);
        ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &_M_replace(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __len1, const _CharT *__s, const typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __len2);
        ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &_M_append(const _CharT *__s, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n);
      public:
        typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type copy(_CharT *__s, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos  = (0)) const ;
        void swap(::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__s);
        inline const _CharT *c_str() const 
        {
          return (*this)._M_data();
        }
        inline const _CharT *data() const 
        {
          return (*this)._M_data();
        }
        inline typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::allocator_type get_allocator() const 
        {
          return (*this)._M_get_allocator();
        }
        typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type find(const _CharT *__s, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n) const ;
        inline typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type find(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__str, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos  = (0)) const 
        {
          return this->find(__str.data(), __pos, __str.size());
        }
        inline typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type find(const _CharT *__s, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos  = (0)) const 
        {
          ;
          return this->find(__s, __pos, traits_type::length(__s));
        }
        typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type find(_CharT __c, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos  = (0)) const ;
        inline typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type rfind(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__str, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos  = (::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::npos)) const 
        {
          return this->rfind(__str.data(), __pos, __str.size());
        }
        typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type rfind(const _CharT *__s, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n) const ;
        inline typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type rfind(const _CharT *__s, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos  = (::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::npos)) const 
        {
          ;
          return this->rfind(__s, __pos, traits_type::length(__s));
        }
        typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type rfind(_CharT __c, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos  = (::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::npos)) const ;
        inline typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type find_first_of(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__str, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos  = (0)) const 
        {
          return this->find_first_of(__str.data(), __pos, __str.size());
        }
        typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type find_first_of(const _CharT *__s, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n) const ;
        inline typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type find_first_of(const _CharT *__s, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos  = (0)) const 
        {
          ;
          return this->find_first_of(__s, __pos, traits_type::length(__s));
        }
        inline typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type find_first_of(_CharT __c, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos  = (0)) const 
        {
          return this->find(__c, __pos);
        }
        inline typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type find_last_of(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__str, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos  = (::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::npos)) const 
        {
          return this->find_last_of(__str.data(), __pos, __str.size());
        }
        typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type find_last_of(const _CharT *__s, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n) const ;
        inline typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type find_last_of(const _CharT *__s, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos  = (::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::npos)) const 
        {
          ;
          return this->find_last_of(__s, __pos, traits_type::length(__s));
        }
        inline typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type find_last_of(_CharT __c, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos  = (::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::npos)) const 
        {
          return this->rfind(__c, __pos);
        }
        inline typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type find_first_not_of(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__str, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos  = (0)) const 
        {
          return this->find_first_not_of(__str.data(), __pos, __str.size());
        }
        typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type find_first_not_of(const _CharT *__s, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n) const ;
        inline typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type find_first_not_of(const _CharT *__s, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos  = (0)) const 
        {
          ;
          return this->find_first_not_of(__s, __pos, traits_type::length(__s));
        }
        typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type find_first_not_of(_CharT __c, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos  = (0)) const ;
        inline typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type find_last_not_of(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__str, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos  = (::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::npos)) const 
        {
          return this->find_last_not_of(__str.data(), __pos, __str.size());
        }
        typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type find_last_not_of(const _CharT *__s, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n) const ;
        inline typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type find_last_not_of(const _CharT *__s, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos  = (::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::npos)) const 
        {
          ;
          return this->find_last_not_of(__s, __pos, traits_type::length(__s));
        }
        typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type find_last_not_of(_CharT __c, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos  = (::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::npos)) const ;
        inline ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> substr(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos  = (0), typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n  = (::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::npos)) const 
        {
          return ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>(*this, (*this)._M_check(__pos, "basic_string::substr"), __n);
        }
        inline int compare(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__str) const 
        {
          const typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __size = this->size();
          const typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __osize = __str.size();
          const typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __len = std::min(__size, __osize);
          int __r = traits_type::compare((*this)._M_data(), __str.data(), __len);
          if (!__r)
            {
              __r = _S_compare(__size, __osize);
            }
          return __r;
        }
        int compare(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n, const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__str) const ;
        int compare(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos1, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n1, const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__str, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos2, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n2  = (::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::npos)) const ;
        int compare(const _CharT *__s) const ;
        int compare(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n1, const _CharT *__s) const ;
        int compare(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n1, const _CharT *__s, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n2) const ;
      template < typename __type_tpl__param_2_0__, typename __type_tpl__param_2_1__, typename __type_tpl__param_2_2__ >
      friend class basic_stringbuf;
    };
  }
  template < typename _CharT, typename _Traits, typename _Alloc >
  ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> operator +(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__lhs, const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__rhs);
  template < typename _CharT, typename _Traits, typename _Alloc >
  ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> operator +(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__lhs, const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__rhs)
  {
    ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> __str(__lhs);
    __str.append(__rhs);
    return __str;
  }
  template < typename _CharT, typename _Traits, typename _Alloc >
  ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> operator +(const _CharT *__lhs, const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__rhs);
  template < typename _CharT, typename _Traits, typename _Alloc >
  ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> operator +(_CharT __lhs, const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__rhs);
  template < typename _CharT, typename _Traits, typename _Alloc >
  inline ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> operator +(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__lhs, const _CharT *__rhs);
  template < typename _CharT, typename _Traits, typename _Alloc >
  inline ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> operator +(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__lhs, const _CharT *__rhs)
  {
    ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> __str(__lhs);
    __str.append(__rhs);
    return __str;
  }
  template < typename _CharT, typename _Traits, typename _Alloc >
  inline ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> operator +(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__lhs, _CharT __rhs);
  template < typename _CharT, typename _Traits, typename _Alloc >
  inline ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> operator +(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__lhs, _CharT __rhs)
  {
    typedef ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> __string_type;
    typedef typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __size_type;
    __string_type __str(__lhs);
    __str.append(__size_type(1), __rhs);
    return __str;
  }
  template < typename _CharT, typename _Traits, typename _Alloc >
  inline bool operator ==(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__lhs, const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__rhs);
  template < typename _CharT, typename _Traits, typename _Alloc >
  inline bool operator ==(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__lhs, const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__rhs)
  {
    return __lhs.compare(__rhs) == 0;
  }
  template < typename _CharT >
  inline typename ::__gnu_cxx::__enable_if<__is_char<_CharT>::__value, bool>::__type operator ==(const ::std::__cxx11::basic_string<_CharT> &__lhs, const ::std::__cxx11::basic_string<_CharT> &__rhs);
  template < typename _CharT >
  inline typename ::__gnu_cxx::__enable_if<__is_char<_CharT>::__value, bool>::__type operator ==(const ::std::__cxx11::basic_string<_CharT> &__lhs, const ::std::__cxx11::basic_string<_CharT> &__rhs)
  {
    return __lhs.size() == __rhs.size() && !std::char_traits<_CharT>::compare(__lhs.data(), __rhs.data(), __lhs.size());
  }
  template < typename _CharT, typename _Traits, typename _Alloc >
  inline bool operator ==(const _CharT *__lhs, const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__rhs);
  template < typename _CharT, typename _Traits, typename _Alloc >
  inline bool operator ==(const _CharT *__lhs, const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__rhs)
  {
    return __rhs.compare(__lhs) == 0;
  }
  template < typename _CharT, typename _Traits, typename _Alloc >
  inline bool operator ==(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__lhs, const _CharT *__rhs);
  template < typename _CharT, typename _Traits, typename _Alloc >
  inline bool operator ==(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__lhs, const _CharT *__rhs)
  {
    return __lhs.compare(__rhs) == 0;
  }
  template < typename _CharT, typename _Traits, typename _Alloc >
  inline bool operator !=(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__lhs, const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__rhs);
  template < typename _CharT, typename _Traits, typename _Alloc >
  inline bool operator !=(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__lhs, const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__rhs)
  {
    return !(__lhs == __rhs);
  }
  template < typename _CharT, typename _Traits, typename _Alloc >
  inline bool operator !=(const _CharT *__lhs, const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__rhs);
  template < typename _CharT, typename _Traits, typename _Alloc >
  inline bool operator !=(const _CharT *__lhs, const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__rhs)
  {
    return !(__lhs == __rhs);
  }
  template < typename _CharT, typename _Traits, typename _Alloc >
  inline bool operator !=(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__lhs, const _CharT *__rhs);
  template < typename _CharT, typename _Traits, typename _Alloc >
  inline bool operator !=(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__lhs, const _CharT *__rhs)
  {
    return !(__lhs == __rhs);
  }
  template < typename _CharT, typename _Traits, typename _Alloc >
  inline bool operator <(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__lhs, const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__rhs);
  template < typename _CharT, typename _Traits, typename _Alloc >
  inline bool operator <(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__lhs, const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__rhs)
  {
    return __lhs.compare(__rhs) < 0;
  }
  template < typename _CharT, typename _Traits, typename _Alloc >
  inline bool operator <(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__lhs, const _CharT *__rhs);
  template < typename _CharT, typename _Traits, typename _Alloc >
  inline bool operator <(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__lhs, const _CharT *__rhs)
  {
    return __lhs.compare(__rhs) < 0;
  }
  template < typename _CharT, typename _Traits, typename _Alloc >
  inline bool operator <(const _CharT *__lhs, const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__rhs);
  template < typename _CharT, typename _Traits, typename _Alloc >
  inline bool operator <(const _CharT *__lhs, const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__rhs)
  {
    return __rhs.compare(__lhs) > 0;
  }
  template < typename _CharT, typename _Traits, typename _Alloc >
  inline bool operator >(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__lhs, const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__rhs);
  template < typename _CharT, typename _Traits, typename _Alloc >
  inline bool operator >(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__lhs, const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__rhs)
  {
    return __lhs.compare(__rhs) > 0;
  }
  template < typename _CharT, typename _Traits, typename _Alloc >
  inline bool operator >(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__lhs, const _CharT *__rhs);
  template < typename _CharT, typename _Traits, typename _Alloc >
  inline bool operator >(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__lhs, const _CharT *__rhs)
  {
    return __lhs.compare(__rhs) > 0;
  }
  template < typename _CharT, typename _Traits, typename _Alloc >
  inline bool operator >(const _CharT *__lhs, const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__rhs);
  template < typename _CharT, typename _Traits, typename _Alloc >
  inline bool operator >(const _CharT *__lhs, const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__rhs)
  {
    return __rhs.compare(__lhs) < 0;
  }
  template < typename _CharT, typename _Traits, typename _Alloc >
  inline bool operator <=(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__lhs, const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__rhs);
  template < typename _CharT, typename _Traits, typename _Alloc >
  inline bool operator <=(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__lhs, const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__rhs)
  {
    return __lhs.compare(__rhs) <= 0;
  }
  template < typename _CharT, typename _Traits, typename _Alloc >
  inline bool operator <=(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__lhs, const _CharT *__rhs);
  template < typename _CharT, typename _Traits, typename _Alloc >
  inline bool operator <=(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__lhs, const _CharT *__rhs)
  {
    return __lhs.compare(__rhs) <= 0;
  }
  template < typename _CharT, typename _Traits, typename _Alloc >
  inline bool operator <=(const _CharT *__lhs, const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__rhs);
  template < typename _CharT, typename _Traits, typename _Alloc >
  inline bool operator <=(const _CharT *__lhs, const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__rhs)
  {
    return __rhs.compare(__lhs) >= 0;
  }
  template < typename _CharT, typename _Traits, typename _Alloc >
  inline bool operator >=(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__lhs, const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__rhs);
  template < typename _CharT, typename _Traits, typename _Alloc >
  inline bool operator >=(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__lhs, const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__rhs)
  {
    return __lhs.compare(__rhs) >= 0;
  }
  template < typename _CharT, typename _Traits, typename _Alloc >
  inline bool operator >=(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__lhs, const _CharT *__rhs);
  template < typename _CharT, typename _Traits, typename _Alloc >
  inline bool operator >=(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__lhs, const _CharT *__rhs)
  {
    return __lhs.compare(__rhs) >= 0;
  }
  template < typename _CharT, typename _Traits, typename _Alloc >
  inline bool operator >=(const _CharT *__lhs, const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__rhs);
  template < typename _CharT, typename _Traits, typename _Alloc >
  inline bool operator >=(const _CharT *__lhs, const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__rhs)
  {
    return __rhs.compare(__lhs) <= 0;
  }
  template < typename _CharT, typename _Traits, typename _Alloc >
  inline void swap(::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__lhs, ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__rhs);
  template < typename _CharT, typename _Traits, typename _Alloc >
  inline void swap(::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__lhs, ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__rhs)
  {
    __lhs.swap(__rhs);
  }
  template < typename _CharT, typename _Traits, typename _Alloc >
  ::std::basic_istream<_CharT, _Traits> &operator >>(::std::basic_istream<_CharT, _Traits> &__in, ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__str);
  template <>
  ::std::basic_istream<char> &operator >><char, ::std::char_traits<char>, ::std::allocator<char> >(::std::basic_istream<char> &__is, ::std::__cxx11::basic_string<char> &__str);
  template < typename _CharT, typename _Traits, typename _Alloc >
  inline ::std::basic_ostream<_CharT, _Traits> &operator <<(::std::basic_ostream<_CharT, _Traits> &__os, const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__str);
  template < typename _CharT, typename _Traits, typename _Alloc >
  inline ::std::basic_ostream<_CharT, _Traits> &operator <<(::std::basic_ostream<_CharT, _Traits> &__os, const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__str)
  {
    return __ostream_insert(__os, __str.data(), __str.size());
  }
  template < typename _CharT, typename _Traits, typename _Alloc >
  ::std::basic_istream<_CharT, _Traits> &getline(::std::basic_istream<_CharT, _Traits> &__in, ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__str, _CharT __delim);
  template < typename _CharT, typename _Traits, typename _Alloc >
  inline ::std::basic_istream<_CharT, _Traits> &getline(::std::basic_istream<_CharT, _Traits> &__is, ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__str);
  template < typename _CharT, typename _Traits, typename _Alloc >
  inline ::std::basic_istream<_CharT, _Traits> &getline(::std::basic_istream<_CharT, _Traits> &__is, ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__str)
  {
    return std::getline(__is, __str, __is.widen('\n'));
  }
  template <>
  ::std::basic_istream<char> &getline<char, ::std::char_traits<char>, ::std::allocator<char> >(::std::basic_istream<char> &__in, ::std::__cxx11::basic_string<char> &__str, char __delim);
  template <>
  ::std::basic_istream<wchar_t> &getline<wchar_t, ::std::char_traits<wchar_t>, ::std::allocator<wchar_t> >(::std::basic_istream<wchar_t> &__in, ::std::__cxx11::basic_string<wchar_t> &__str, wchar_t __delim);
  inline namespace __cxx11 __attribute__((__abi_tag__("cxx11"))) {
    template < typename _CharT, typename _Traits, typename _Alloc >
    const typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type basic_string<_CharT, _Traits, _Alloc>::npos;
    template < typename _CharT, typename _Traits, typename _Alloc >
    void basic_string<_CharT, _Traits, _Alloc>::swap(::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__s)
    {
      if (this == &__s)
        {
          return ;
        }
      _Alloc_traits::_S_on_swap((*this)._M_get_allocator(), __s._M_get_allocator());
      if ((*this)._M_is_local())
        {
          if (__s._M_is_local())
            {
              if ((*this).length() && __s.length())
                {
                  _CharT __tmp_data[::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::_S_local_capacity + 1];
                  traits_type::copy(__tmp_data, __s._M_local_buf, ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::_S_local_capacity + 1);
                  traits_type::copy(__s._M_local_buf, ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::_M_local_buf, ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::_S_local_capacity + 1);
                  traits_type::copy(::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::_M_local_buf, __tmp_data, ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::_S_local_capacity + 1);
                }
              else
                {
                  if (__s.length())
                    {
                      traits_type::copy(::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::_M_local_buf, __s._M_local_buf, ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::_S_local_capacity + 1);
                      (*this)._M_length(__s.length());
                      __s._M_set_length(0);
                      return ;
                    }
                  else
                    {
                      if ((*this).length())
                        {
                          traits_type::copy(__s._M_local_buf, ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::_M_local_buf, ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::_S_local_capacity + 1);
                          __s._M_length((*this).length());
                          (*this)._M_set_length(0);
                          return ;
                        }
                    }
                }
            }
          else
            {
              const typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __tmp_capacity = __s._M_allocated_capacity;
              traits_type::copy(__s._M_local_buf, ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::_M_local_buf, ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::_S_local_capacity + 1);
              (*this)._M_data(__s._M_data());
              __s._M_data(__s._M_local_buf);
              (*this)._M_capacity(__tmp_capacity);
            }
        }
      else
        {
          const typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __tmp_capacity = ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::_M_allocated_capacity;
          if (__s._M_is_local())
            {
              traits_type::copy(::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::_M_local_buf, __s._M_local_buf, ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::_S_local_capacity + 1);
              __s._M_data((*this)._M_data());
              (*this)._M_data(::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::_M_local_buf);
            }
          else
            {
              typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::pointer __tmp_ptr = (*this)._M_data();
              (*this)._M_data(__s._M_data());
              __s._M_data(__tmp_ptr);
              (*this)._M_capacity(__s._M_allocated_capacity);
            }
          __s._M_capacity(__tmp_capacity);
        }
      const typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __tmp_length = (*this).length();
      (*this)._M_length(__s.length());
      __s._M_length(__tmp_length);
    }
    template < typename _CharT, typename _Traits, typename _Alloc >
    typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::pointer basic_string<_CharT, _Traits, _Alloc>::_M_create(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type &__capacity, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __old_capacity)
    {
      if (__capacity > (*this).max_size())
        {
          std::__throw_length_error("basic_string::_M_create");
        }
      if (__capacity > __old_capacity && __capacity < 2 * __old_capacity)
        {
          __capacity = 2 * __old_capacity;
          if (__capacity > (*this).max_size())
            {
              __capacity = (*this).max_size();
            }
        }
      return _Alloc_traits::allocate((*this)._M_get_allocator(), __capacity + 1);
    }
    template < typename _CharT, typename _Traits, typename _Alloc >
    template < typename _InIterator >
    void basic_string<_CharT, _Traits, _Alloc>::_M_construct(_InIterator __beg, _InIterator __end, ::std::input_iterator_tag)
    {
      typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __len = 0;
      typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __capacity = ((typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type(::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::_S_local_capacity)));
      while (__beg != __end && __len < __capacity)
        {
          (*this)._M_data()[__len++] = *__beg;
           ++__beg;
        }
      try
      {
        while (__beg != __end)
          {
            if (__len == __capacity)
              {
                __capacity = __len + 1;
                typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::pointer __another = (*this)._M_create(__capacity, __len);
                this->_S_copy(__another, (*this)._M_data(), __len);
                (*this)._M_dispose();
                (*this)._M_data(__another);
                (*this)._M_capacity(__capacity);
              }
            (*this)._M_data()[__len++] = *__beg;
             ++__beg;
          }
      }
      catch (...)
      {
        (*this)._M_dispose();
        throw;
      }
      (*this)._M_set_length(__len);
    }
    template < typename _CharT, typename _Traits, typename _Alloc >
    template < typename _InIterator >
    void basic_string<_CharT, _Traits, _Alloc>::_M_construct(_InIterator __beg, _InIterator __end, ::std::forward_iterator_tag)
    {
      if (__gnu_cxx::__is_null_pointer(__beg) && __beg != __end)
        {
          std::__throw_logic_error("basic_string::_M_construct null not valid");
        }
      typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __dnew = static_cast<typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type>(std::distance(__beg, __end));
      if (__dnew > ((typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type(::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::_S_local_capacity))))
        {
          (*this)._M_data((*this)._M_create(__dnew, ((typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type(0)))));
          (*this)._M_capacity(__dnew);
        }
      try
      {
        this->_S_copy_chars((*this)._M_data(), __beg, __end);
      }
      catch (...)
      {
        (*this)._M_dispose();
        throw;
      }
      (*this)._M_set_length(__dnew);
    }
    template < typename _CharT, typename _Traits, typename _Alloc >
    void basic_string<_CharT, _Traits, _Alloc>::_M_construct(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n, _CharT __c)
    {
      if (__n > ((typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type(::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::_S_local_capacity))))
        {
          (*this)._M_data((*this)._M_create(__n, ((typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type(0)))));
          (*this)._M_capacity(__n);
        }
      if (__n)
        {
          this->_S_assign((*this)._M_data(), __n, __c);
        }
      (*this)._M_set_length(__n);
    }
    template < typename _CharT, typename _Traits, typename _Alloc >
    void basic_string<_CharT, _Traits, _Alloc>::_M_assign(const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__str)
    {
      if (this != &__str)
        {
          const typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __rsize = __str.length();
          const typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __capacity = (*this).capacity();
          if (__rsize > __capacity)
            {
              typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __new_capacity = __rsize;
              typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::pointer __tmp = (*this)._M_create(__new_capacity, __capacity);
              (*this)._M_dispose();
              (*this)._M_data(__tmp);
              (*this)._M_capacity(__new_capacity);
            }
          if (__rsize)
            {
              this->_S_copy((*this)._M_data(), __str._M_data(), __rsize);
            }
          (*this)._M_set_length(__rsize);
        }
    }
    template < typename _CharT, typename _Traits, typename _Alloc >
    void basic_string<_CharT, _Traits, _Alloc>::reserve(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __res)
    {
      if (__res < (*this).length())
        {
          __res = (*this).length();
        }
      const typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __capacity = (*this).capacity();
      if (__res != __capacity)
        {
          if (__res > __capacity || __res > ((typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type(::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::_S_local_capacity))))
            {
              typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::pointer __tmp = (*this)._M_create(__res, __capacity);
              this->_S_copy(__tmp, (*this)._M_data(), (*this).length() + 1);
              (*this)._M_dispose();
              (*this)._M_data(__tmp);
              (*this)._M_capacity(__res);
            }
          else
            {
              if (!(*this)._M_is_local())
                {
                  this->_S_copy((*this)._M_local_data(), (*this)._M_data(), (*this).length() + 1);
                  (*this)._M_destroy(__capacity);
                  (*this)._M_data((*this)._M_local_data());
                }
            }
        }
    }
    template < typename _CharT, typename _Traits, typename _Alloc >
    void basic_string<_CharT, _Traits, _Alloc>::_M_mutate(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __len1, const _CharT *__s, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __len2)
    {
      const typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __how_much = (*this).length() - __pos - __len1;
      typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __new_capacity = (*this).length() + __len2 - __len1;
      typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::pointer __r = (*this)._M_create(__new_capacity, (*this).capacity());
      if (__pos)
        {
          this->_S_copy(__r, (*this)._M_data(), __pos);
        }
      if (__s && __len2)
        {
          this->_S_copy(__r + __pos, __s, __len2);
        }
      if (__how_much)
        {
          this->_S_copy(__r + __pos + __len2, (*this)._M_data() + __pos + __len1, __how_much);
        }
      (*this)._M_dispose();
      (*this)._M_data(__r);
      (*this)._M_capacity(__new_capacity);
    }
    template < typename _CharT, typename _Traits, typename _Alloc >
    void basic_string<_CharT, _Traits, _Alloc>::_M_erase(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n)
    {
      const typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __how_much = (*this).length() - __pos - __n;
      if (__how_much && __n)
        {
          this->_S_move((*this)._M_data() + __pos, (*this)._M_data() + __pos + __n, __how_much);
        }
      (*this)._M_set_length((*this).length() - __n);
    }
    template < typename _CharT, typename _Traits, typename _Alloc >
    void basic_string<_CharT, _Traits, _Alloc>::resize(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n, _CharT __c)
    {
      const typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __size = this->size();
      if (__size < __n)
        {
          this->append(__n - __size, __c);
        }
      else
        {
          if (__n < __size)
            {
              this->_M_set_length(__n);
            }
        }
    }
    template < typename _CharT, typename _Traits, typename _Alloc >
    ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &basic_string<_CharT, _Traits, _Alloc>::_M_append(const _CharT *__s, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n)
    {
      const typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __len = __n + this->size();
      if (__len <= this->capacity())
        {
          if (__n)
            {
              this->_S_copy(this->_M_data() + this->size(), __s, __n);
            }
        }
      else
        {
          this->_M_mutate(this->size(), ((typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type(0))), __s, __n);
        }
      this->_M_set_length(__len);
      return *this;
    }
    template < typename _CharT, typename _Traits, typename _Alloc >
    template < typename _InputIterator >
    ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &basic_string<_CharT, _Traits, _Alloc>::_M_replace_dispatch(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::const_iterator __i1, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::const_iterator __i2, _InputIterator __k1, _InputIterator __k2, ::std::__false_type)
    {
      const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> __s(__k1, __k2);
      const typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n1 = __i2 - __i1;
      return (*this)._M_replace(__i1 - (*this).begin(), __n1, __s._M_data(), __s.size());
    }
    template < typename _CharT, typename _Traits, typename _Alloc >
    ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &basic_string<_CharT, _Traits, _Alloc>::_M_replace_aux(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos1, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n1, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n2, _CharT __c)
    {
      (*this)._M_check_length(__n1, __n2, "basic_string::_M_replace_aux");
      const typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __old_size = this->size();
      const typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __new_size = __old_size + __n2 - __n1;
      if (__new_size <= this->capacity())
        {
          typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::pointer __p = this->_M_data() + __pos1;
          const typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __how_much = __old_size - __pos1 - __n1;
          if (__how_much && __n1 != __n2)
            {
              this->_S_move(__p + __n2, __p + __n1, __how_much);
            }
        }
      else
        {
          this->_M_mutate(__pos1, __n1, 0, __n2);
        }
      if (__n2)
        {
          this->_S_assign(this->_M_data() + __pos1, __n2, __c);
        }
      this->_M_set_length(__new_size);
      return *this;
    }
    template < typename _CharT, typename _Traits, typename _Alloc >
    ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &basic_string<_CharT, _Traits, _Alloc>::_M_replace(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __len1, const _CharT *__s, const typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __len2)
    {
      (*this)._M_check_length(__len1, __len2, "basic_string::_M_replace");
      const typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __old_size = this->size();
      const typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __new_size = __old_size + __len2 - __len1;
      if (__new_size <= this->capacity())
        {
          typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::pointer __p = this->_M_data() + __pos;
          const typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __how_much = __old_size - __pos - __len1;
          if ((*this)._M_disjunct(__s))
            {
              if (__how_much && __len1 != __len2)
                {
                  this->_S_move(__p + __len2, __p + __len1, __how_much);
                }
              if (__len2)
                {
                  this->_S_copy(__p, __s, __len2);
                }
            }
          else
            {
              if (__len2 && __len2 <= __len1)
                {
                  this->_S_move(__p, __s, __len2);
                }
              if (__how_much && __len1 != __len2)
                {
                  this->_S_move(__p + __len2, __p + __len1, __how_much);
                }
              if (__len2 > __len1)
                {
                  if (__s + __len2 <= __p + __len1)
                    {
                      this->_S_move(__p, __s, __len2);
                    }
                  else
                    {
                      if (__s >= __p + __len1)
                        {
                          this->_S_copy(__p, __s + __len2 - __len1, __len2);
                        }
                      else
                        {
                          const typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __nleft = __p + __len1 - __s;
                          this->_S_move(__p, __s, __nleft);
                          this->_S_copy(__p + __nleft, __p + __len2, __len2 - __nleft);
                        }
                    }
                }
            }
        }
      else
        {
          this->_M_mutate(__pos, __len1, __s, __len2);
        }
      this->_M_set_length(__new_size);
      return *this;
    }
    template < typename _CharT, typename _Traits, typename _Alloc >
    typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type basic_string<_CharT, _Traits, _Alloc>::copy(_CharT *__s, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos) const 
    {
      (*this)._M_check(__pos, "basic_string::copy");
      __n = (*this)._M_limit(__pos, __n);
      ;
      if (__n)
        {
          _S_copy(__s, (*this)._M_data() + __pos, __n);
        }
      return __n;
    }
  }
  template < typename _CharT, typename _Traits, typename _Alloc >
  ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> operator +(const _CharT *__lhs, const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__rhs)
  {
    ;
    typedef ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> __string_type;
    typedef typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __size_type;
    const __size_type __len = _Traits::length(__lhs);
    __string_type __str;
    __str.reserve(__len + __rhs.size());
    __str.append(__lhs, __len);
    __str.append(__rhs);
    return __str;
  }
  template < typename _CharT, typename _Traits, typename _Alloc >
  ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> operator +(_CharT __lhs, const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__rhs)
  {
    typedef ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> __string_type;
    typedef typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __size_type;
    __string_type __str;
    const __size_type __len = __rhs.size();
    __str.reserve(__len + 1);
    __str.append(__size_type(1), __lhs);
    __str.append(__rhs);
    return __str;
  }
  inline namespace __cxx11 __attribute__((__abi_tag__("cxx11"))) {
    template < typename _CharT, typename _Traits, typename _Alloc >
    typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type basic_string<_CharT, _Traits, _Alloc>::find(const _CharT *__s, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n) const 
    {
      ;
      const typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __size = this->size();
      if (__n == 0)
        {
          return __pos <= __size ? __pos : ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::npos;
        }
      if (__pos >= __size)
        {
          return ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::npos;
        }
      const _CharT __elem0 = __s[0];
      const _CharT *const __data = (*this).data();
      const _CharT *__first = __data + __pos;
      const _CharT *const __last = __data + __size;
      typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __len = __size - __pos;
      while (__len >= __n)
        {
          __first = traits_type::find(__first, __len - __n + 1, __elem0);
          if (!__first)
            {
              return ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::npos;
            }
          if (traits_type::compare(__first, __s, __n) == 0)
            {
              return __first - __data;
            }
          __len = __last -  ++__first;
        }
      return ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::npos;
    }
    template < typename _CharT, typename _Traits, typename _Alloc >
    typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type basic_string<_CharT, _Traits, _Alloc>::find(_CharT __c, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos) const 
    {
      typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __ret = ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::npos;
      const typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __size = this->size();
      if (__pos < __size)
        {
          const _CharT *__data = (*this)._M_data();
          const typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n = __size - __pos;
          const _CharT *__p = traits_type::find(__data + __pos, __n, __c);
          if (__p)
            {
              __ret = __p - __data;
            }
        }
      return __ret;
    }
    template < typename _CharT, typename _Traits, typename _Alloc >
    typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type basic_string<_CharT, _Traits, _Alloc>::rfind(const _CharT *__s, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n) const 
    {
      ;
      const typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __size = this->size();
      if (__n <= __size)
        {
          __pos = std::min(((typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type(__size - __n))), __pos);
          const _CharT *__data = (*this)._M_data();
          do
            {
              if (traits_type::compare(__data + __pos, __s, __n) == 0)
                {
                  return __pos;
                }
            }
          while (__pos-- > 0);
        }
      return ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::npos;
    }
    template < typename _CharT, typename _Traits, typename _Alloc >
    typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type basic_string<_CharT, _Traits, _Alloc>::rfind(_CharT __c, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos) const 
    {
      typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __size = this->size();
      if (__size)
        {
          if ( --__size > __pos)
            {
              __size = __pos;
            }
          for ( ++__size; __size-- > 0; )
            {
              if (traits_type::eq((*this)._M_data()[__size], __c))
                {
                  return __size;
                }
            }
        }
      return ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::npos;
    }
    template < typename _CharT, typename _Traits, typename _Alloc >
    typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type basic_string<_CharT, _Traits, _Alloc>::find_first_of(const _CharT *__s, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n) const 
    {
      ;
      for (; __n && __pos < this->size();  ++__pos)
        {
          const _CharT *__p = traits_type::find(__s, __n, (*this)._M_data()[__pos]);
          if (__p)
            {
              return __pos;
            }
        }
      return ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::npos;
    }
    template < typename _CharT, typename _Traits, typename _Alloc >
    typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type basic_string<_CharT, _Traits, _Alloc>::find_last_of(const _CharT *__s, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n) const 
    {
      ;
      typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __size = this->size();
      if (__size && __n)
        {
          if ( --__size > __pos)
            {
              __size = __pos;
            }
          do
            {
              if (traits_type::find(__s, __n, (*this)._M_data()[__size]))
                {
                  return __size;
                }
            }
          while (__size-- != 0);
        }
      return ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::npos;
    }
    template < typename _CharT, typename _Traits, typename _Alloc >
    typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type basic_string<_CharT, _Traits, _Alloc>::find_first_not_of(const _CharT *__s, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n) const 
    {
      ;
      for (; __pos < this->size();  ++__pos)
        {
          if (!traits_type::find(__s, __n, (*this)._M_data()[__pos]))
            {
              return __pos;
            }
        }
      return ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::npos;
    }
    template < typename _CharT, typename _Traits, typename _Alloc >
    typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type basic_string<_CharT, _Traits, _Alloc>::find_first_not_of(_CharT __c, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos) const 
    {
      for (; __pos < this->size();  ++__pos)
        {
          if (!traits_type::eq((*this)._M_data()[__pos], __c))
            {
              return __pos;
            }
        }
      return ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::npos;
    }
    template < typename _CharT, typename _Traits, typename _Alloc >
    typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type basic_string<_CharT, _Traits, _Alloc>::find_last_not_of(const _CharT *__s, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n) const 
    {
      ;
      typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __size = this->size();
      if (__size)
        {
          if ( --__size > __pos)
            {
              __size = __pos;
            }
          do
            {
              if (!traits_type::find(__s, __n, (*this)._M_data()[__size]))
                {
                  return __size;
                }
            }
          while (__size--);
        }
      return ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::npos;
    }
    template < typename _CharT, typename _Traits, typename _Alloc >
    typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type basic_string<_CharT, _Traits, _Alloc>::find_last_not_of(_CharT __c, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos) const 
    {
      typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __size = this->size();
      if (__size)
        {
          if ( --__size > __pos)
            {
              __size = __pos;
            }
          do
            {
              if (!traits_type::eq((*this)._M_data()[__size], __c))
                {
                  return __size;
                }
            }
          while (__size--);
        }
      return ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::npos;
    }
    template < typename _CharT, typename _Traits, typename _Alloc >
    int basic_string<_CharT, _Traits, _Alloc>::compare(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n, const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__str) const 
    {
      (*this)._M_check(__pos, "basic_string::compare");
      __n = (*this)._M_limit(__pos, __n);
      const typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __osize = __str.size();
      const typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __len = std::min(__n, __osize);
      int __r = traits_type::compare((*this)._M_data() + __pos, __str.data(), __len);
      if (!__r)
        {
          __r = _S_compare(__n, __osize);
        }
      return __r;
    }
    template < typename _CharT, typename _Traits, typename _Alloc >
    int basic_string<_CharT, _Traits, _Alloc>::compare(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos1, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n1, const ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__str, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos2, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n2) const 
    {
      (*this)._M_check(__pos1, "basic_string::compare");
      __str._M_check(__pos2, "basic_string::compare");
      __n1 = (*this)._M_limit(__pos1, __n1);
      __n2 = __str._M_limit(__pos2, __n2);
      const typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __len = std::min(__n1, __n2);
      int __r = traits_type::compare((*this)._M_data() + __pos1, __str.data() + __pos2, __len);
      if (!__r)
        {
          __r = _S_compare(__n1, __n2);
        }
      return __r;
    }
    template < typename _CharT, typename _Traits, typename _Alloc >
    int basic_string<_CharT, _Traits, _Alloc>::compare(const _CharT *__s) const 
    {
      ;
      const typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __size = this->size();
      const typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __osize = traits_type::length(__s);
      const typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __len = std::min(__size, __osize);
      int __r = traits_type::compare((*this)._M_data(), __s, __len);
      if (!__r)
        {
          __r = _S_compare(__size, __osize);
        }
      return __r;
    }
    template < typename _CharT, typename _Traits, typename _Alloc >
    int basic_string<_CharT, _Traits, _Alloc>::compare(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n1, const _CharT *__s) const 
    {
      ;
      (*this)._M_check(__pos, "basic_string::compare");
      __n1 = (*this)._M_limit(__pos, __n1);
      const typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __osize = traits_type::length(__s);
      const typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __len = std::min(__n1, __osize);
      int __r = traits_type::compare((*this)._M_data() + __pos, __s, __len);
      if (!__r)
        {
          __r = _S_compare(__n1, __osize);
        }
      return __r;
    }
    template < typename _CharT, typename _Traits, typename _Alloc >
    int basic_string<_CharT, _Traits, _Alloc>::compare(typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __pos, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n1, const _CharT *__s, typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __n2) const 
    {
      ;
      (*this)._M_check(__pos, "basic_string::compare");
      __n1 = (*this)._M_limit(__pos, __n1);
      const typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __len = std::min(__n1, __n2);
      int __r = traits_type::compare((*this)._M_data() + __pos, __s, __len);
      if (!__r)
        {
          __r = _S_compare(__n1, __n2);
        }
      return __r;
    }
  }
  template < typename _CharT, typename _Traits, typename _Alloc >
  ::std::basic_istream<_CharT, _Traits> &operator >>(::std::basic_istream<_CharT, _Traits> &__in, ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__str)
  {
    typedef ::std::basic_istream<_CharT, _Traits> __istream_type;
    typedef ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> __string_type;
    typedef typename ::std::basic_istream<_CharT, _Traits>::ios_base __ios_base;
    typedef typename ::std::basic_istream<_CharT, _Traits>::int_type __int_type;
    typedef typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __size_type;
    typedef ::std::ctype<_CharT> __ctype_type;
    typedef typename ::std::ctype<_CharT>::ctype_base __ctype_base;
    __size_type __extracted = 0;
    typename ::std::basic_istream<_CharT, _Traits>::ios_base::iostate __err = __ios_base::goodbit;
    typename ::std::basic_istream<_CharT, _Traits>::sentry __cerb(__in, false);
    if (__cerb)
      {
        try
        {
          __str.erase();
          _CharT __buf[128L];
          __size_type __len = 0;
          const ::std::streamsize __w = __in.width();
          const __size_type __n = __w > 0 ? static_cast<__size_type>(__w) : __str.max_size();
          const __ctype_type &__ct = use_facet<__ctype_type>(__in.getloc());
          const __int_type __eof = _Traits::eof();
          __int_type __c = __in.rdbuf()->sgetc();
          while ((__extracted < __n && !_Traits::eq_int_type(__c, __eof)) && !__ct.is(__ctype_base::space, _Traits::to_char_type(__c)))
            {
              if (__len == sizeof(__buf) / sizeof(_CharT))
                {
                  __str.append(__buf, sizeof(__buf) / sizeof(_CharT));
                  __len = 0;
                }
              __buf[__len++] = _Traits::to_char_type(__c);
               ++__extracted;
              __c = __in.rdbuf()->snextc();
            }
          __str.append(__buf, __len);
          if (_Traits::eq_int_type(__c, __eof))
            {
              __err |= __ios_base::eofbit;
            }
          __in.width(0);
        }
        catch (::__cxxabiv1::__forced_unwind &)
        {
          __in._M_setstate(__ios_base::badbit);
          throw;
        }
        catch (...)
        {
          __in._M_setstate(__ios_base::badbit);
        }
      }
    if (!__extracted)
      {
        __err |= __ios_base::failbit;
      }
    if (__err)
      {
        __in.setstate(__err);
      }
    return __in;
  }
  template < typename _CharT, typename _Traits, typename _Alloc >
  ::std::basic_istream<_CharT, _Traits> &getline(::std::basic_istream<_CharT, _Traits> &__in, ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> &__str, _CharT __delim)
  {
    typedef ::std::basic_istream<_CharT, _Traits> __istream_type;
    typedef ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc> __string_type;
    typedef typename ::std::basic_istream<_CharT, _Traits>::ios_base __ios_base;
    typedef typename ::std::basic_istream<_CharT, _Traits>::int_type __int_type;
    typedef typename ::std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type __size_type;
    __size_type __extracted = 0;
    const __size_type __n = __str.max_size();
    typename ::std::basic_istream<_CharT, _Traits>::ios_base::iostate __err = __ios_base::goodbit;
    typename ::std::basic_istream<_CharT, _Traits>::sentry __cerb(__in, true);
    if (__cerb)
      {
        try
        {
          __str.erase();
          const __int_type __idelim = _Traits::to_int_type(__delim);
          const __int_type __eof = _Traits::eof();
          __int_type __c = __in.rdbuf()->sgetc();
          while ((__extracted < __n && !_Traits::eq_int_type(__c, __eof)) && !_Traits::eq_int_type(__c, __idelim))
            {
              __str += _Traits::to_char_type(__c);
               ++__extracted;
              __c = __in.rdbuf()->snextc();
            }
          if (_Traits::eq_int_type(__c, __eof))
            {
              __err |= __ios_base::eofbit;
            }
          else
            {
              if (_Traits::eq_int_type(__c, __idelim))
                {
                   ++__extracted;
                  __in.rdbuf()->sbumpc();
                }
              else
                {
                  __err |= __ios_base::failbit;
                }
            }
        }
        catch (::__cxxabiv1::__forced_unwind &)
        {
          __in._M_setstate(__ios_base::badbit);
          throw;
        }
        catch (...)
        {
          __in._M_setstate(__ios_base::badbit);
        }
      }
    if (!__extracted)
      {
        __err |= __ios_base::failbit;
      }
    if (__err)
      {
        __in.setstate(__err);
      }
    return __in;
  }
  inline namespace __cxx11 __attribute__((__abi_tag__("cxx11"))) {
    extern template class ::std::__cxx11::basic_string<char>;
  }
  extern template ::std::basic_istream<char> &operator >>(::std::basic_istream<char> &, ::std::__cxx11::basic_string<char> &);
  extern template ::std::basic_ostream<char> &operator <<(::std::basic_ostream<char> &, const ::std::__cxx11::basic_string<char> &);
  extern template ::std::basic_istream<char> &getline(::std::basic_istream<char> &, ::std::__cxx11::basic_string<char> &, char);
  extern template ::std::basic_istream<char> &getline(::std::basic_istream<char> &, ::std::__cxx11::basic_string<char> &);
  inline namespace __cxx11 __attribute__((__abi_tag__("cxx11"))) {
    extern template class ::std::__cxx11::basic_string<wchar_t>;
  }
  extern template ::std::basic_istream<wchar_t> &operator >>(::std::basic_istream<wchar_t> &, ::std::__cxx11::basic_string<wchar_t> &);
  extern template ::std::basic_ostream<wchar_t> &operator <<(::std::basic_ostream<wchar_t> &, const ::std::__cxx11::basic_string<wchar_t> &);
  extern template ::std::basic_istream<wchar_t> &getline(::std::basic_istream<wchar_t> &, ::std::__cxx11::basic_string<wchar_t> &, wchar_t);
  extern template ::std::basic_istream<wchar_t> &getline(::std::basic_istream<wchar_t> &, ::std::__cxx11::basic_string<wchar_t> &);
  enum _Rb_tree_color
  {
    _S_red = false,
    _S_black = true
  };
  struct  _Rb_tree_node_base
  {
      typedef ::std::_Rb_tree_node_base *_Base_ptr;
      typedef const ::std::_Rb_tree_node_base *_Const_Base_ptr;
      ::std::_Rb_tree_color _M_color;
      ::std::_Rb_tree_node_base::_Base_ptr _M_parent;
      ::std::_Rb_tree_node_base::_Base_ptr _M_left;
      ::std::_Rb_tree_node_base::_Base_ptr _M_right;
      static inline ::std::_Rb_tree_node_base::_Base_ptr _S_minimum(::std::_Rb_tree_node_base::_Base_ptr __x)
      {
        while ((*__x)._M_left != 0)
          {
            __x = (*__x)._M_left;
          }
        return __x;
      }
      static inline ::std::_Rb_tree_node_base::_Const_Base_ptr _S_minimum(::std::_Rb_tree_node_base::_Const_Base_ptr __x)
      {
        while ((*__x)._M_left != 0)
          {
            __x = (*__x)._M_left;
          }
        return __x;
      }
      static inline ::std::_Rb_tree_node_base::_Base_ptr _S_maximum(::std::_Rb_tree_node_base::_Base_ptr __x)
      {
        while ((*__x)._M_right != 0)
          {
            __x = (*__x)._M_right;
          }
        return __x;
      }
      static inline ::std::_Rb_tree_node_base::_Const_Base_ptr _S_maximum(::std::_Rb_tree_node_base::_Const_Base_ptr __x)
      {
        while ((*__x)._M_right != 0)
          {
            __x = (*__x)._M_right;
          }
        return __x;
      }
  };
  template < typename _Key_compare >
  struct  _Rb_tree_key_compare
  {
      _Key_compare _M_key_compare;
      inline _Rb_tree_key_compare()
        : _M_key_compare()
      {
      }
      inline _Rb_tree_key_compare(const _Key_compare &__comp)
        : _M_key_compare(__comp)
      {
      }
  };
  struct  _Rb_tree_header
  {
      ::std::_Rb_tree_node_base _M_header;
      ::std::size_t _M_node_count;
      inline _Rb_tree_header()
      {
        (*this)._M_header._M_color = ::std::_S_red;
        (*this).::std::_Rb_tree_header::_M_reset();
      }
      inline void _M_move_data(::std::_Rb_tree_header &__from)
      {
        (*this)._M_header._M_color = __from._M_header._M_color;
        (*this)._M_header._M_parent = __from._M_header._M_parent;
        (*this)._M_header._M_left = __from._M_header._M_left;
        (*this)._M_header._M_right = __from._M_header._M_right;
        (*(*this)._M_header._M_parent)._M_parent = &(*this)._M_header;
        (*this)._M_node_count = __from._M_node_count;
        __from.::std::_Rb_tree_header::_M_reset();
      }
      inline void _M_reset()
      {
        (*this)._M_header._M_parent = 0;
        (*this)._M_header._M_left = &(*this)._M_header;
        (*this)._M_header._M_right = &(*this)._M_header;
        (*this)._M_node_count = 0;
      }
  };
  template < typename _Val >
  struct  _Rb_tree_node : ::std::_Rb_tree_node_base
  {
      typedef ::std::_Rb_tree_node<_Val> *_Link_type;
      _Val _M_value_field;
      inline _Val *_M_valptr()
      {
        return std::__addressof(::std::_Rb_tree_node<_Val>::_M_value_field);
      }
      inline const _Val *_M_valptr() const 
      {
        return std::__addressof(::std::_Rb_tree_node<_Val>::_M_value_field);
      }
  };
  ::std::_Rb_tree_node_base *_Rb_tree_increment(::std::_Rb_tree_node_base *__x) throw() __attribute__((__pure__));
  const ::std::_Rb_tree_node_base *_Rb_tree_increment(const ::std::_Rb_tree_node_base *__x) throw() __attribute__((__pure__));
  ::std::_Rb_tree_node_base *_Rb_tree_decrement(::std::_Rb_tree_node_base *__x) throw() __attribute__((__pure__));
  const ::std::_Rb_tree_node_base *_Rb_tree_decrement(const ::std::_Rb_tree_node_base *__x) throw() __attribute__((__pure__));
  template < typename _Tp >
  struct  _Rb_tree_iterator
  {
      typedef _Tp value_type;
      typedef _Tp &reference;
      typedef _Tp *pointer;
      typedef ::std::bidirectional_iterator_tag iterator_category;
      typedef ::std::ptrdiff_t difference_type;
      typedef ::std::_Rb_tree_iterator<_Tp> _Self;
      typedef ::std::_Rb_tree_node_base::_Base_ptr _Base_ptr;
      typedef ::std::_Rb_tree_node<_Tp> *_Link_type;
      inline _Rb_tree_iterator()
        : _M_node()
      {
      }
      inline explicit _Rb_tree_iterator(typename ::std::_Rb_tree_iterator<_Tp>::_Base_ptr __x)
        : _M_node(__x)
      {
      }
      inline typename ::std::_Rb_tree_iterator<_Tp>::reference operator *() const 
      {
        return *static_cast<typename ::std::_Rb_tree_iterator<_Tp>::_Link_type>(::std::_Rb_tree_iterator<_Tp>::_M_node)->_M_valptr();
      }
      inline typename ::std::_Rb_tree_iterator<_Tp>::pointer operator ->() const 
      {
        return static_cast<typename ::std::_Rb_tree_iterator<_Tp>::_Link_type>(::std::_Rb_tree_iterator<_Tp>::_M_node)->_M_valptr();
      }
      inline typename ::std::_Rb_tree_iterator<_Tp>::_Self &operator ++()
      {
        ::std::_Rb_tree_iterator<_Tp>::_M_node = _Rb_tree_increment(::std::_Rb_tree_iterator<_Tp>::_M_node);
        return *this;
      }
      inline typename ::std::_Rb_tree_iterator<_Tp>::_Self operator ++(int)
      {
        typename ::std::_Rb_tree_iterator<_Tp>::_Self __tmp = *this;
        ::std::_Rb_tree_iterator<_Tp>::_M_node = _Rb_tree_increment(::std::_Rb_tree_iterator<_Tp>::_M_node);
        return __tmp;
      }
      inline typename ::std::_Rb_tree_iterator<_Tp>::_Self &operator --()
      {
        ::std::_Rb_tree_iterator<_Tp>::_M_node = _Rb_tree_decrement(::std::_Rb_tree_iterator<_Tp>::_M_node);
        return *this;
      }
      inline typename ::std::_Rb_tree_iterator<_Tp>::_Self operator --(int)
      {
        typename ::std::_Rb_tree_iterator<_Tp>::_Self __tmp = *this;
        ::std::_Rb_tree_iterator<_Tp>::_M_node = _Rb_tree_decrement(::std::_Rb_tree_iterator<_Tp>::_M_node);
        return __tmp;
      }
      inline bool operator ==(const typename ::std::_Rb_tree_iterator<_Tp>::_Self &__x) const 
      {
        return ::std::_Rb_tree_iterator<_Tp>::_M_node == __x._M_node;
      }
      inline bool operator !=(const typename ::std::_Rb_tree_iterator<_Tp>::_Self &__x) const 
      {
        return ::std::_Rb_tree_iterator<_Tp>::_M_node != __x._M_node;
      }
      typename ::std::_Rb_tree_iterator<_Tp>::_Base_ptr _M_node;
  };
  template < typename _Tp >
  struct  _Rb_tree_const_iterator
  {
      typedef _Tp value_type;
      typedef const _Tp &reference;
      typedef const _Tp *pointer;
      typedef ::std::_Rb_tree_iterator<_Tp> iterator;
      typedef ::std::bidirectional_iterator_tag iterator_category;
      typedef ::std::ptrdiff_t difference_type;
      typedef ::std::_Rb_tree_const_iterator<_Tp> _Self;
      typedef ::std::_Rb_tree_node_base::_Const_Base_ptr _Base_ptr;
      typedef const ::std::_Rb_tree_node<_Tp> *_Link_type;
      inline _Rb_tree_const_iterator()
        : _M_node()
      {
      }
      inline explicit _Rb_tree_const_iterator(typename ::std::_Rb_tree_const_iterator<_Tp>::_Base_ptr __x)
        : _M_node(__x)
      {
      }
      inline _Rb_tree_const_iterator(const typename ::std::_Rb_tree_const_iterator<_Tp>::iterator &__it)
        : _M_node(__it._M_node)
      {
      }
      inline typename ::std::_Rb_tree_const_iterator<_Tp>::iterator _M_const_cast() const 
      {
        return ((typename ::std::_Rb_tree_const_iterator<_Tp>::iterator(const_cast<typename ::std::_Rb_tree_iterator<_Tp>::_Base_ptr>(::std::_Rb_tree_const_iterator<_Tp>::_M_node))));
      }
      inline typename ::std::_Rb_tree_const_iterator<_Tp>::reference operator *() const 
      {
        return *static_cast<typename ::std::_Rb_tree_const_iterator<_Tp>::_Link_type>(::std::_Rb_tree_const_iterator<_Tp>::_M_node)->_M_valptr();
      }
      inline typename ::std::_Rb_tree_const_iterator<_Tp>::pointer operator ->() const 
      {
        return static_cast<typename ::std::_Rb_tree_const_iterator<_Tp>::_Link_type>(::std::_Rb_tree_const_iterator<_Tp>::_M_node)->_M_valptr();
      }
      inline typename ::std::_Rb_tree_const_iterator<_Tp>::_Self &operator ++()
      {
        ::std::_Rb_tree_const_iterator<_Tp>::_M_node = _Rb_tree_increment(::std::_Rb_tree_const_iterator<_Tp>::_M_node);
        return *this;
      }
      inline typename ::std::_Rb_tree_const_iterator<_Tp>::_Self operator ++(int)
      {
        typename ::std::_Rb_tree_const_iterator<_Tp>::_Self __tmp = *this;
        ::std::_Rb_tree_const_iterator<_Tp>::_M_node = _Rb_tree_increment(::std::_Rb_tree_const_iterator<_Tp>::_M_node);
        return __tmp;
      }
      inline typename ::std::_Rb_tree_const_iterator<_Tp>::_Self &operator --()
      {
        ::std::_Rb_tree_const_iterator<_Tp>::_M_node = _Rb_tree_decrement(::std::_Rb_tree_const_iterator<_Tp>::_M_node);
        return *this;
      }
      inline typename ::std::_Rb_tree_const_iterator<_Tp>::_Self operator --(int)
      {
        typename ::std::_Rb_tree_const_iterator<_Tp>::_Self __tmp = *this;
        ::std::_Rb_tree_const_iterator<_Tp>::_M_node = _Rb_tree_decrement(::std::_Rb_tree_const_iterator<_Tp>::_M_node);
        return __tmp;
      }
      inline bool operator ==(const typename ::std::_Rb_tree_const_iterator<_Tp>::_Self &__x) const 
      {
        return ::std::_Rb_tree_const_iterator<_Tp>::_M_node == __x._M_node;
      }
      inline bool operator !=(const typename ::std::_Rb_tree_const_iterator<_Tp>::_Self &__x) const 
      {
        return ::std::_Rb_tree_const_iterator<_Tp>::_M_node != __x._M_node;
      }
      typename ::std::_Rb_tree_const_iterator<_Tp>::_Base_ptr _M_node;
  };
  template < typename _Val >
  inline bool operator ==(const ::std::_Rb_tree_iterator<_Val> &__x, const ::std::_Rb_tree_const_iterator<_Val> &__y);
  template < typename _Val >
  inline bool operator ==(const ::std::_Rb_tree_iterator<_Val> &__x, const ::std::_Rb_tree_const_iterator<_Val> &__y)
  {
    return __x._M_node == __y._M_node;
  }
  template < typename _Val >
  inline bool operator !=(const ::std::_Rb_tree_iterator<_Val> &__x, const ::std::_Rb_tree_const_iterator<_Val> &__y);
  template < typename _Val >
  inline bool operator !=(const ::std::_Rb_tree_iterator<_Val> &__x, const ::std::_Rb_tree_const_iterator<_Val> &__y)
  {
    return __x._M_node != __y._M_node;
  }
  void _Rb_tree_insert_and_rebalance(const bool __insert_left, ::std::_Rb_tree_node_base *__x, ::std::_Rb_tree_node_base *__p, ::std::_Rb_tree_node_base &__header) throw();
  ::std::_Rb_tree_node_base *_Rb_tree_rebalance_for_erase(::std::_Rb_tree_node_base *const __z, ::std::_Rb_tree_node_base &__header) throw();
  template < typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc = ::std::allocator<_Val> >
  class  _Rb_tree
  {
      typedef typename ::__gnu_cxx::__alloc_traits<_Alloc>::template rebind< ::std::_Rb_tree_node<_Val> >::other _Node_allocator;
      typedef ::__gnu_cxx::__alloc_traits<typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Node_allocator> _Alloc_traits;
    protected:
      typedef ::std::_Rb_tree_node_base *_Base_ptr;
      typedef const ::std::_Rb_tree_node_base *_Const_Base_ptr;
      typedef ::std::_Rb_tree_node<_Val> *_Link_type;
      typedef const ::std::_Rb_tree_node<_Val> *_Const_Link_type;
    private:
      struct  _Reuse_or_alloc_node
      {
          inline _Reuse_or_alloc_node(::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &__t)
            : _M_root(__t._M_root()), _M_nodes(__t._M_rightmost()), _M_t(__t)
          {
            if (::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Reuse_or_alloc_node::_M_root)
              {
                ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Reuse_or_alloc_node::_M_root->_M_parent = 0;
                if (::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Reuse_or_alloc_node::_M_nodes->_M_left)
                  {
                    ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Reuse_or_alloc_node::_M_nodes = ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Reuse_or_alloc_node::_M_nodes->_M_left;
                  }
              }
            else
              {
                ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Reuse_or_alloc_node::_M_nodes = 0;
              }
          }
          inline ~_Reuse_or_alloc_node()
          {
            ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Reuse_or_alloc_node::_M_t._M_erase(static_cast<typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Link_type>(::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Reuse_or_alloc_node::_M_root));
          }
          template < typename _Arg >
          inline typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Link_type operator ()(const _Arg &__arg)
          {
            typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Link_type __node = static_cast<typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Link_type>((*this)._M_extract());
            if (__node)
              {
                ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Reuse_or_alloc_node::_M_t._M_destroy_node(__node);
                ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Reuse_or_alloc_node::_M_t._M_construct_node(__node, __arg);
                return __node;
              }
            return ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Reuse_or_alloc_node::_M_t._M_create_node(__arg);
          }
        private:
          inline typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Base_ptr _M_extract()
          {
            if (!::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Reuse_or_alloc_node::_M_nodes)
              {
                return ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Reuse_or_alloc_node::_M_nodes;
              }
            typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Base_ptr __node = ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Reuse_or_alloc_node::_M_nodes;
            ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Reuse_or_alloc_node::_M_nodes = ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Reuse_or_alloc_node::_M_nodes->_M_parent;
            if (::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Reuse_or_alloc_node::_M_nodes)
              {
                if (::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Reuse_or_alloc_node::_M_nodes->_M_right == __node)
                  {
                    ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Reuse_or_alloc_node::_M_nodes->_M_right = 0;
                    if (::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Reuse_or_alloc_node::_M_nodes->_M_left)
                      {
                        ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Reuse_or_alloc_node::_M_nodes = ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Reuse_or_alloc_node::_M_nodes->_M_left;
                        while (::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Reuse_or_alloc_node::_M_nodes->_M_right)
                          {
                            ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Reuse_or_alloc_node::_M_nodes = ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Reuse_or_alloc_node::_M_nodes->_M_right;
                          }
                        if (::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Reuse_or_alloc_node::_M_nodes->_M_left)
                          {
                            ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Reuse_or_alloc_node::_M_nodes = ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Reuse_or_alloc_node::_M_nodes->_M_left;
                          }
                      }
                  }
                else
                  {
                    ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Reuse_or_alloc_node::_M_nodes->_M_left = 0;
                  }
              }
            else
              {
                ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Reuse_or_alloc_node::_M_root = 0;
              }
            return __node;
          }
          typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Base_ptr _M_root;
          typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Base_ptr _M_nodes;
          ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &_M_t;
      };
      struct  _Alloc_node
      {
          inline _Alloc_node(::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &__t)
            : _M_t(__t)
          {
          }
          template < typename _Arg >
          inline typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Link_type operator ()(const _Arg &__arg) const 
          {
            return ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Alloc_node::_M_t._M_create_node(__arg);
          }
        private:
          ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &_M_t;
      };
    public:
      typedef _Key key_type;
      typedef _Val value_type;
      typedef typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::value_type *pointer;
      typedef const typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::value_type *const_pointer;
      typedef typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::value_type &reference;
      typedef const typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::value_type &const_reference;
      typedef ::std::size_t size_type;
      typedef ::std::ptrdiff_t difference_type;
      typedef _Alloc allocator_type;
      inline typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Node_allocator &_M_get_Node_allocator()
      {
        return *static_cast<typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Node_allocator *>(&this->_M_impl);
      }
      inline const typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Node_allocator &_M_get_Node_allocator() const 
      {
        return *static_cast<const typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Node_allocator *>(&this->_M_impl);
      }
      inline typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::allocator_type get_allocator() const 
      {
        return ((typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::allocator_type((*this)._M_get_Node_allocator())));
      }
    protected:
      inline typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Link_type _M_get_node()
      {
        return _Alloc_traits::allocate((*this)._M_get_Node_allocator(), 1);
      }
      inline void _M_put_node(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Link_type __p)
      {
        _Alloc_traits::deallocate((*this)._M_get_Node_allocator(), __p, 1);
      }
      inline void _M_construct_node(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Link_type __node, const typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::value_type &__x)
      {
        try
        {
          (*this).get_allocator().construct(__node->_M_valptr(), __x);
        }
        catch (...)
        {
          (*this)._M_put_node(__node);
          throw;
        }
      }
      inline typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Link_type _M_create_node(const typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::value_type &__x)
      {
        typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Link_type __tmp = (*this)._M_get_node();
        (*this)._M_construct_node(__tmp, __x);
        return __tmp;
      }
      inline void _M_destroy_node(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Link_type __p)
      {
        (*this).get_allocator().destroy(__p->_M_valptr());
      }
      inline void _M_drop_node(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Link_type __p)
      {
        (*this)._M_destroy_node(__p);
        (*this)._M_put_node(__p);
      }
      template < typename _NodeGen >
      inline typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Link_type _M_clone_node(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Const_Link_type __x, _NodeGen &__node_gen)
      {
        typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Link_type __tmp = __node_gen(*__x->_M_valptr());
        __tmp->_M_color = __x->_M_color;
        __tmp->_M_left = 0;
        __tmp->_M_right = 0;
        return __tmp;
      }
      template < typename _Key_compare, bool __nontype_tpl_param_2_1__ = __is_pod(_Key_compare) >
      struct  _Rb_tree_impl : ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Node_allocator, ::std::_Rb_tree_key_compare<_Key_compare>, ::std::_Rb_tree_header
      {
          typedef ::std::_Rb_tree_key_compare<_Key_compare> _Base_key_compare;
          inline _Rb_tree_impl()
          {
          }
          inline _Rb_tree_impl(const typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::template _Rb_tree_impl<_Key_compare, __nontype_tpl_param_2_1__> &__x)
            : _Node_allocator(_Alloc_traits::_S_select_on_copy(__x)), _Base_key_compare(__x._M_key_compare)
          {
          }
          inline _Rb_tree_impl(const _Key_compare &__comp, const typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Node_allocator &__a)
            : _Node_allocator(__a), _Base_key_compare(__comp)
          {
          }
      };
      typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::template _Rb_tree_impl<_Compare> _M_impl;
      inline typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Base_ptr &_M_root()
      {
        return this->_M_impl._M_header._M_parent;
      }
      inline typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Const_Base_ptr _M_root() const 
      {
        return this->_M_impl._M_header._M_parent;
      }
      inline typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Base_ptr &_M_leftmost()
      {
        return this->_M_impl._M_header._M_left;
      }
      inline typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Const_Base_ptr _M_leftmost() const 
      {
        return this->_M_impl._M_header._M_left;
      }
      inline typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Base_ptr &_M_rightmost()
      {
        return this->_M_impl._M_header._M_right;
      }
      inline typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Const_Base_ptr _M_rightmost() const 
      {
        return this->_M_impl._M_header._M_right;
      }
      inline typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Link_type _M_begin()
      {
        return static_cast<typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Link_type>(this->_M_impl._M_header._M_parent);
      }
      inline typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Const_Link_type _M_begin() const 
      {
        return static_cast<typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Const_Link_type>(this->_M_impl._M_header._M_parent);
      }
      inline typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Base_ptr _M_end()
      {
        return &this->_M_impl._M_header;
      }
      inline typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Const_Base_ptr _M_end() const 
      {
        return &this->_M_impl._M_header;
      }
      static inline typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_reference _S_value(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Const_Link_type __x)
      {
        return *__x->_M_valptr();
      }
      static inline const _Key &_S_key(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Const_Link_type __x)
      {
        return _KeyOfValue()(_S_value(__x));
      }
      static inline typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Link_type _S_left(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Base_ptr __x)
      {
        return static_cast<typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Link_type>((*__x)._M_left);
      }
      static inline typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Const_Link_type _S_left(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Const_Base_ptr __x)
      {
        return static_cast<typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Const_Link_type>((*__x)._M_left);
      }
      static inline typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Link_type _S_right(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Base_ptr __x)
      {
        return static_cast<typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Link_type>((*__x)._M_right);
      }
      static inline typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Const_Link_type _S_right(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Const_Base_ptr __x)
      {
        return static_cast<typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Const_Link_type>((*__x)._M_right);
      }
      static inline typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_reference _S_value(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Const_Base_ptr __x)
      {
        return *static_cast<typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Const_Link_type>(__x)->_M_valptr();
      }
      static inline const _Key &_S_key(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Const_Base_ptr __x)
      {
        return _KeyOfValue()(_S_value(__x));
      }
      static inline typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Base_ptr _S_minimum(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Base_ptr __x)
      {
        return _Rb_tree_node_base::_S_minimum(__x);
      }
      static inline typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Const_Base_ptr _S_minimum(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Const_Base_ptr __x)
      {
        return _Rb_tree_node_base::_S_minimum(__x);
      }
      static inline typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Base_ptr _S_maximum(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Base_ptr __x)
      {
        return _Rb_tree_node_base::_S_maximum(__x);
      }
      static inline typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Const_Base_ptr _S_maximum(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Const_Base_ptr __x)
      {
        return _Rb_tree_node_base::_S_maximum(__x);
      }
    public:
      typedef ::std::_Rb_tree_iterator<typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::value_type> iterator;
      typedef ::std::_Rb_tree_const_iterator<typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::value_type> const_iterator;
      typedef ::std::reverse_iterator<typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator> reverse_iterator;
      typedef ::std::reverse_iterator<typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator> const_reverse_iterator;
      ::std::pair< ::std::_Rb_tree_node_base *, ::std::_Rb_tree_node_base *> _M_get_insert_unique_pos(const typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::key_type &__k);
      ::std::pair< ::std::_Rb_tree_node_base *, ::std::_Rb_tree_node_base *> _M_get_insert_equal_pos(const typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::key_type &__k);
      ::std::pair< ::std::_Rb_tree_node_base *, ::std::_Rb_tree_node_base *> _M_get_insert_hint_unique_pos(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator __position, const typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::key_type &__k);
      ::std::pair< ::std::_Rb_tree_node_base *, ::std::_Rb_tree_node_base *> _M_get_insert_hint_equal_pos(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator __position, const typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::key_type &__k);
    private:
      template < typename _NodeGen >
      typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator _M_insert_(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Base_ptr __x, typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Base_ptr __p, const typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::value_type &__v, _NodeGen &__node_gen);
      typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator _M_insert_lower(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Base_ptr __p, const typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::value_type &__v);
      typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator _M_insert_equal_lower(const typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::value_type &__v);
      template < typename _NodeGen >
      typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Link_type _M_copy(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Const_Link_type __x, typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Base_ptr __p, _NodeGen &__node_gen);
      template < typename _NodeGen >
      inline typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Link_type _M_copy(const ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &__x, _NodeGen &__gen)
      {
        typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Link_type __root = (*this)._M_copy(__x._M_begin(), (*this)._M_end(), __gen);
        (*this)._M_leftmost() = _S_minimum(__root);
        (*this)._M_rightmost() = _S_maximum(__root);
        ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_impl._M_node_count = __x._M_impl._M_node_count;
        return __root;
      }
      inline typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Link_type _M_copy(const ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &__x)
      {
        typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Alloc_node __an(*this);
        return (*this)._M_copy(__x, __an);
      }
      void _M_erase(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Link_type __x);
      typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator _M_lower_bound(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Link_type __x, typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Base_ptr __y, const _Key &__k);
      typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator _M_lower_bound(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Const_Link_type __x, typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Const_Base_ptr __y, const _Key &__k) const ;
      typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator _M_upper_bound(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Link_type __x, typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Base_ptr __y, const _Key &__k);
      typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator _M_upper_bound(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Const_Link_type __x, typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Const_Base_ptr __y, const _Key &__k) const ;
    public:
      inline _Rb_tree()
      {
      }
      inline _Rb_tree(const _Compare &__comp, const typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::allocator_type &__a  = (((typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::allocator_type()))))
        : _M_impl(__comp, ((typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Node_allocator(__a))))
      {
      }
      inline _Rb_tree(const ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &__x)
        : _M_impl(__x._M_impl)
      {
        if (__x._M_root() != 0)
          {
            (*this)._M_root() = (*this)._M_copy(__x);
          }
      }
      inline ~_Rb_tree()
      {
        (*this)._M_erase((*this)._M_begin());
      }
      ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &operator =(const ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &__x);
      inline _Compare key_comp() const 
      {
        return ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_impl._M_key_compare;
      }
      inline typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator begin()
      {
        return ((typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator(this->_M_impl._M_header._M_left)));
      }
      inline typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator begin() const 
      {
        return ((typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator(this->_M_impl._M_header._M_left)));
      }
      inline typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator end()
      {
        return ((typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator(&this->_M_impl._M_header)));
      }
      inline typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator end() const 
      {
        return ((typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator(&this->_M_impl._M_header)));
      }
      inline typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::reverse_iterator rbegin()
      {
        return ((typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::reverse_iterator((*this).end())));
      }
      inline typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_reverse_iterator rbegin() const 
      {
        return ((typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_reverse_iterator((*this).end())));
      }
      inline typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::reverse_iterator rend()
      {
        return ((typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::reverse_iterator((*this).begin())));
      }
      inline typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_reverse_iterator rend() const 
      {
        return ((typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_reverse_iterator((*this).begin())));
      }
      inline bool empty() const 
      {
        return ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_impl._M_node_count == 0;
      }
      inline typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::size_type size() const 
      {
        return ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_impl._M_node_count;
      }
      inline typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::size_type max_size() const 
      {
        return _Alloc_traits::max_size((*this)._M_get_Node_allocator());
      }
      void swap(::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &__t);
      ::std::pair<typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator, bool> _M_insert_unique(const typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::value_type &__v);
      typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator _M_insert_equal(const typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::value_type &__v);
      template < typename _NodeGen >
      typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator _M_insert_unique_(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator __position, const typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::value_type &__v, _NodeGen &__node_gen);
      inline typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator _M_insert_unique_(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator __pos, const typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::value_type &__x)
      {
        typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Alloc_node __an(*this);
        return (*this)._M_insert_unique_(__pos, __x, __an);
      }
      template < typename _NodeGen >
      typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator _M_insert_equal_(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator __position, const typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::value_type &__v, _NodeGen &__node_gen);
      inline typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator _M_insert_equal_(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator __pos, const typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::value_type &__x)
      {
        typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Alloc_node __an(*this);
        return (*this)._M_insert_equal_(__pos, __x, __an);
      }
      template < typename _InputIterator >
      void _M_insert_unique(_InputIterator __first, _InputIterator __last);
      template < typename _InputIterator >
      void _M_insert_equal(_InputIterator __first, _InputIterator __last);
    private:
      void _M_erase_aux(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator __position);
      void _M_erase_aux(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator __first, typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator __last);
    public:
      inline void erase(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator __position)
      {
        ;
        (*this)._M_erase_aux(__position);
      }
      inline void erase(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator __position)
      {
        ;
        (*this)._M_erase_aux(__position);
      }
      typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::size_type erase(const typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::key_type &__x);
      inline void erase(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator __first, typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator __last)
      {
        (*this)._M_erase_aux(__first, __last);
      }
      inline void erase(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator __first, typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator __last)
      {
        (*this)._M_erase_aux(__first, __last);
      }
      void erase(const typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::key_type *__first, const typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::key_type *__last);
      inline void clear()
      {
        (*this)._M_erase((*this)._M_begin());
        ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_impl._M_reset();
      }
      typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator find(const typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::key_type &__k);
      typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator find(const typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::key_type &__k) const ;
      typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::size_type count(const typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::key_type &__k) const ;
      inline typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator lower_bound(const typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::key_type &__k)
      {
        return (*this)._M_lower_bound((*this)._M_begin(), (*this)._M_end(), __k);
      }
      inline typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator lower_bound(const typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::key_type &__k) const 
      {
        return (*this)._M_lower_bound((*this)._M_begin(), (*this)._M_end(), __k);
      }
      inline typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator upper_bound(const typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::key_type &__k)
      {
        return (*this)._M_upper_bound((*this)._M_begin(), (*this)._M_end(), __k);
      }
      inline typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator upper_bound(const typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::key_type &__k) const 
      {
        return (*this)._M_upper_bound((*this)._M_begin(), (*this)._M_end(), __k);
      }
      ::std::pair<typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator, typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator> equal_range(const typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::key_type &__k);
      ::std::pair<typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator, typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator> equal_range(const typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::key_type &__k) const ;
      bool __rb_verify() const ;
  };
  template < typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc >
  inline bool operator ==(const ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &__x, const ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &__y);
  template < typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc >
  inline bool operator ==(const ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &__x, const ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &__y)
  {
    return __x.size() == __y.size() && std::equal(__x.begin(), __x.end(), __y.begin());
  }
  template < typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc >
  inline bool operator <(const ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &__x, const ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &__y);
  template < typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc >
  inline bool operator <(const ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &__x, const ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &__y)
  {
    return std::lexicographical_compare(__x.begin(), __x.end(), __y.begin(), __y.end());
  }
  template < typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc >
  inline bool operator !=(const ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &__x, const ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &__y);
  template < typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc >
  inline bool operator !=(const ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &__x, const ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &__y)
  {
    return !(__x == __y);
  }
  template < typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc >
  inline bool operator >(const ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &__x, const ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &__y);
  template < typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc >
  inline bool operator >(const ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &__x, const ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &__y)
  {
    return __y < __x;
  }
  template < typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc >
  inline bool operator <=(const ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &__x, const ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &__y);
  template < typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc >
  inline bool operator <=(const ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &__x, const ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &__y)
  {
    return !(__y < __x);
  }
  template < typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc >
  inline bool operator >=(const ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &__x, const ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &__y);
  template < typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc >
  inline bool operator >=(const ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &__x, const ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &__y)
  {
    return !(__x < __y);
  }
  template < typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc >
  inline void swap(::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &__x, ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &__y);
  template < typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc >
  inline void swap(::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &__x, ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &__y)
  {
    __x.swap(__y);
  }
  template < typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc >
  ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::operator =(const ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &__x)
  {
    if (this != &__x)
      {
        typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Reuse_or_alloc_node __roan(*this);
        ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_impl._M_reset();
        ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_impl._M_key_compare = __x._M_impl._M_key_compare;
        if (__x._M_root() != 0)
          {
            (*this)._M_root() = (*this)._M_copy(__x, __roan);
          }
      }
    return *this;
  }
  template < typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc >
  template < typename _NodeGen >
  typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator _Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_insert_(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Base_ptr __x, typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Base_ptr __p, const _Val &__v, _NodeGen &__node_gen)
  {
    bool __insert_left = (__x != 0 || __p == (*this)._M_end()) || ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_impl._M_key_compare(_KeyOfValue()(__v), _S_key(__p));
    typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Link_type __z = __node_gen(__v);
    _Rb_tree_insert_and_rebalance(__insert_left, __z, __p, this->_M_impl._M_header);
     ++::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_impl._M_node_count;
    return ((typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator(__z)));
  }
  template < typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc >
  typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator _Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_insert_lower(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Base_ptr __p, const _Val &__v)
  {
    bool __insert_left = __p == (*this)._M_end() || !::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_impl._M_key_compare(_S_key(__p), _KeyOfValue()(__v));
    typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Link_type __z = (*this)._M_create_node(__v);
    _Rb_tree_insert_and_rebalance(__insert_left, __z, __p, this->_M_impl._M_header);
     ++::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_impl._M_node_count;
    return ((typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator(__z)));
  }
  template < typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc >
  typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator _Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_insert_equal_lower(const _Val &__v)
  {
    typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Link_type __x = (*this)._M_begin();
    typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Base_ptr __y = (*this)._M_end();
    while (__x != 0)
      {
        __y = __x;
        __x = !::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_impl._M_key_compare(_S_key(__x), _KeyOfValue()(__v)) ? _S_left(__x) : _S_right(__x);
      }
    return (*this)._M_insert_lower(__y, __v);
  }
  template < typename _Key, typename _Val, typename _KoV, typename _Compare, typename _Alloc >
  template < typename _NodeGen >
  typename ::std::_Rb_tree<_Key, _Val, _KoV, _Compare, _Alloc>::_Link_type _Rb_tree<_Key, _Val, _KoV, _Compare, _Alloc>::_M_copy(typename ::std::_Rb_tree<_Key, _Val, _KoV, _Compare, _Alloc>::_Const_Link_type __x, typename ::std::_Rb_tree<_Key, _Val, _KoV, _Compare, _Alloc>::_Base_ptr __p, _NodeGen &__node_gen)
  {
    typename ::std::_Rb_tree<_Key, _Val, _KoV, _Compare, _Alloc>::_Link_type __top = (*this)._M_clone_node(__x, __node_gen);
    __top->_M_parent = __p;
    try
    {
      if (__x->_M_right)
        {
          __top->_M_right = (*this)._M_copy(_S_right(__x), __top, __node_gen);
        }
      __p = __top;
      __x = _S_left(__x);
      while (__x != 0)
        {
          typename ::std::_Rb_tree<_Key, _Val, _KoV, _Compare, _Alloc>::_Link_type __y = (*this)._M_clone_node(__x, __node_gen);
          (*__p)._M_left = __y;
          __y->_M_parent = __p;
          if (__x->_M_right)
            {
              __y->_M_right = (*this)._M_copy(_S_right(__x), __y, __node_gen);
            }
          __p = __y;
          __x = _S_left(__x);
        }
    }
    catch (...)
    {
      (*this)._M_erase(__top);
      throw;
    }
    return __top;
  }
  template < typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc >
  void _Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_erase(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Link_type __x)
  {
    while (__x != 0)
      {
        (*this)._M_erase(_S_right(__x));
        typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Link_type __y = _S_left(__x);
        (*this)._M_drop_node(__x);
        __x = __y;
      }
  }
  template < typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc >
  typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator _Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_lower_bound(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Link_type __x, typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Base_ptr __y, const _Key &__k)
  {
    while (__x != 0)
      {
        if (!::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_impl._M_key_compare(_S_key(__x), __k))
          {
            (__y = __x, __x = _S_left(__x));
          }
        else
          {
            __x = _S_right(__x);
          }
      }
    return ((typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator(__y)));
  }
  template < typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc >
  typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator _Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_lower_bound(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Const_Link_type __x, typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Const_Base_ptr __y, const _Key &__k) const 
  {
    while (__x != 0)
      {
        if (!::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_impl._M_key_compare(_S_key(__x), __k))
          {
            (__y = __x, __x = _S_left(__x));
          }
        else
          {
            __x = _S_right(__x);
          }
      }
    return ((typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator(__y)));
  }
  template < typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc >
  typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator _Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_upper_bound(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Link_type __x, typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Base_ptr __y, const _Key &__k)
  {
    while (__x != 0)
      {
        if (::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_impl._M_key_compare(__k, _S_key(__x)))
          {
            (__y = __x, __x = _S_left(__x));
          }
        else
          {
            __x = _S_right(__x);
          }
      }
    return ((typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator(__y)));
  }
  template < typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc >
  typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator _Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_upper_bound(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Const_Link_type __x, typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Const_Base_ptr __y, const _Key &__k) const 
  {
    while (__x != 0)
      {
        if (::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_impl._M_key_compare(__k, _S_key(__x)))
          {
            (__y = __x, __x = _S_left(__x));
          }
        else
          {
            __x = _S_right(__x);
          }
      }
    return ((typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator(__y)));
  }
  template < typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc >
  ::std::pair<typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator, typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator> _Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::equal_range(const _Key &__k)
  {
    typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Link_type __x = (*this)._M_begin();
    typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Base_ptr __y = (*this)._M_end();
    while (__x != 0)
      {
        if (::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_impl._M_key_compare(_S_key(__x), __k))
          {
            __x = _S_right(__x);
          }
        else
          {
            if (::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_impl._M_key_compare(__k, _S_key(__x)))
              {
                (__y = __x, __x = _S_left(__x));
              }
            else
              {
                typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Link_type __xu(__x);
                typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Base_ptr __yu(__y);
                (__y = __x, __x = _S_left(__x));
                __xu = _S_right(__xu);
                return ::std::pair<typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator, typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator>((*this)._M_lower_bound(__x, __y, __k), (*this)._M_upper_bound(__xu, __yu, __k));
              }
          }
      }
    return ::std::pair<typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator, typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator>(((typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator(__y))), ((typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator(__y))));
  }
  template < typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc >
  ::std::pair<typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator, typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator> _Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::equal_range(const _Key &__k) const 
  {
    typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Const_Link_type __x = (*this)._M_begin();
    typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Const_Base_ptr __y = (*this)._M_end();
    while (__x != 0)
      {
        if (::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_impl._M_key_compare(_S_key(__x), __k))
          {
            __x = _S_right(__x);
          }
        else
          {
            if (::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_impl._M_key_compare(__k, _S_key(__x)))
              {
                (__y = __x, __x = _S_left(__x));
              }
            else
              {
                typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Const_Link_type __xu(__x);
                typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Const_Base_ptr __yu(__y);
                (__y = __x, __x = _S_left(__x));
                __xu = _S_right(__xu);
                return ::std::pair<typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator, typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator>((*this)._M_lower_bound(__x, __y, __k), (*this)._M_upper_bound(__xu, __yu, __k));
              }
          }
      }
    return ::std::pair<typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator, typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator>(((typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator(__y))), ((typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator(__y))));
  }
  template < typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc >
  void _Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::swap(::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &__t)
  {
    if ((*this)._M_root() == 0)
      {
        if (__t._M_root() != 0)
          {
            ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_impl._M_move_data(__t._M_impl);
          }
      }
    else
      {
        if (__t._M_root() == 0)
          {
            __t._M_impl._M_move_data(::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_impl);
          }
        else
          {
            std::swap((*this)._M_root(), __t._M_root());
            std::swap((*this)._M_leftmost(), __t._M_leftmost());
            std::swap((*this)._M_rightmost(), __t._M_rightmost());
            (*this)._M_root()->_M_parent = (*this)._M_end();
            __t._M_root()->_M_parent = __t._M_end();
            std::swap(this->_M_impl._M_node_count, __t._M_impl._M_node_count);
          }
      }
    std::swap(this->_M_impl._M_key_compare, __t._M_impl._M_key_compare);
    _Alloc_traits::_S_on_swap((*this)._M_get_Node_allocator(), __t._M_get_Node_allocator());
  }
 /* Instantiation of class template '::std::__pair_base< ::std::_Rb_tree_node_base *, ::std::_Rb_tree_node_base *>' */ 
 /* Instantiation of class template '::std::pair< ::std::_Rb_tree_node_base *, ::std::_Rb_tree_node_base *>' */ 
  template < typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc >
  ::std::pair< ::std::_Rb_tree_node_base *, ::std::_Rb_tree_node_base *> _Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_get_insert_unique_pos(const typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::key_type &__k)
  {
    typedef ::std::pair< ::std::_Rb_tree_node_base *, ::std::_Rb_tree_node_base *> _Res;
    typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Link_type __x = (*this)._M_begin();
    typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Base_ptr __y = (*this)._M_end();
    bool __comp(true);
    while (__x != 0)
      {
        __y = __x;
        __comp = ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_impl._M_key_compare(__k, _S_key(__x));
        __x = __comp ? _S_left(__x) : _S_right(__x);
      }
    typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator __j = ((typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator(__y)));
    if (__comp)
      {
        if (__j == (*this).begin())
          {
            return _Res(__x, __y);
          }
        else
          {
             --__j;
          }
      }
    if (::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_impl._M_key_compare(_S_key(__j._M_node), __k))
      {
        return _Res(__x, __y);
      }
    return _Res(__j._M_node, 0);
  }
  template < typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc >
  ::std::pair< ::std::_Rb_tree_node_base *, ::std::_Rb_tree_node_base *> _Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_get_insert_equal_pos(const typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::key_type &__k)
  {
    typedef ::std::pair< ::std::_Rb_tree_node_base *, ::std::_Rb_tree_node_base *> _Res;
    typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Link_type __x = (*this)._M_begin();
    typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Base_ptr __y = (*this)._M_end();
    while (__x != 0)
      {
        __y = __x;
        __x = ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_impl._M_key_compare(__k, _S_key(__x)) ? _S_left(__x) : _S_right(__x);
      }
    return _Res(__x, __y);
  }
  template < typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc >
  ::std::pair<typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator, bool> _Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_insert_unique(const _Val &__v)
  {
    typedef ::std::pair<typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator, bool> _Res;
    ::std::pair< ::std::_Rb_tree_node_base *, ::std::_Rb_tree_node_base *> __res = (*this)._M_get_insert_unique_pos(_KeyOfValue()(__v));
    if (__res.second)
      {
        typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Alloc_node __an(*this);
        return _Res((*this)._M_insert_(__res.first, __res.second, __v, __an), true);
      }
    return _Res(((typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator(__res.first))), false);
  }
  template < typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc >
  typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator _Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_insert_equal(const _Val &__v)
  {
    ::std::pair< ::std::_Rb_tree_node_base *, ::std::_Rb_tree_node_base *> __res = (*this)._M_get_insert_equal_pos(_KeyOfValue()(__v));
    typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Alloc_node __an(*this);
    return (*this)._M_insert_(__res.first, __res.second, __v, __an);
  }
  template < typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc >
  ::std::pair< ::std::_Rb_tree_node_base *, ::std::_Rb_tree_node_base *> _Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_get_insert_hint_unique_pos(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator __position, const typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::key_type &__k)
  {
    typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator __pos = __position._M_const_cast();
    typedef ::std::pair< ::std::_Rb_tree_node_base *, ::std::_Rb_tree_node_base *> _Res;
    if (__pos._M_node == (*this)._M_end())
      {
        if ((*this).size() > 0 && ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_impl._M_key_compare(_S_key((*this)._M_rightmost()), __k))
          {
            return _Res(0, (*this)._M_rightmost());
          }
        else
          {
            return (*this)._M_get_insert_unique_pos(__k);
          }
      }
    else
      {
        if (::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_impl._M_key_compare(__k, _S_key(__pos._M_node)))
          {
            typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator __before = __pos;
            if (__pos._M_node == (*this)._M_leftmost())
              {
                return _Res((*this)._M_leftmost(), (*this)._M_leftmost());
              }
            else
              {
                if (::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_impl._M_key_compare(_S_key(( --__before)._M_node), __k))
                  {
                    if (_S_right(__before._M_node) == 0)
                      {
                        return _Res(0, __before._M_node);
                      }
                    else
                      {
                        return _Res(__pos._M_node, __pos._M_node);
                      }
                  }
                else
                  {
                    return (*this)._M_get_insert_unique_pos(__k);
                  }
              }
          }
        else
          {
            if (::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_impl._M_key_compare(_S_key(__pos._M_node), __k))
              {
                typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator __after = __pos;
                if (__pos._M_node == (*this)._M_rightmost())
                  {
                    return _Res(0, (*this)._M_rightmost());
                  }
                else
                  {
                    if (::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_impl._M_key_compare(__k, _S_key(( ++__after)._M_node)))
                      {
                        if (_S_right(__pos._M_node) == 0)
                          {
                            return _Res(0, __pos._M_node);
                          }
                        else
                          {
                            return _Res(__after._M_node, __after._M_node);
                          }
                      }
                    else
                      {
                        return (*this)._M_get_insert_unique_pos(__k);
                      }
                  }
              }
            else
              {
                return _Res(__pos._M_node, 0);
              }
          }
      }
  }
  template < typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc >
  template < typename _NodeGen >
  typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator _Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_insert_unique_(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator __position, const _Val &__v, _NodeGen &__node_gen)
  {
    ::std::pair< ::std::_Rb_tree_node_base *, ::std::_Rb_tree_node_base *> __res = (*this)._M_get_insert_hint_unique_pos(__position, _KeyOfValue()(__v));
    if (__res.second)
      {
        return (*this)._M_insert_(__res.first, __res.second, __v, __node_gen);
      }
    return ((typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator(__res.first)));
  }
  template < typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc >
  ::std::pair< ::std::_Rb_tree_node_base *, ::std::_Rb_tree_node_base *> _Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_get_insert_hint_equal_pos(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator __position, const typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::key_type &__k)
  {
    typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator __pos = __position._M_const_cast();
    typedef ::std::pair< ::std::_Rb_tree_node_base *, ::std::_Rb_tree_node_base *> _Res;
    if (__pos._M_node == (*this)._M_end())
      {
        if ((*this).size() > 0 && !::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_impl._M_key_compare(__k, _S_key((*this)._M_rightmost())))
          {
            return _Res(0, (*this)._M_rightmost());
          }
        else
          {
            return (*this)._M_get_insert_equal_pos(__k);
          }
      }
    else
      {
        if (!::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_impl._M_key_compare(_S_key(__pos._M_node), __k))
          {
            typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator __before = __pos;
            if (__pos._M_node == (*this)._M_leftmost())
              {
                return _Res((*this)._M_leftmost(), (*this)._M_leftmost());
              }
            else
              {
                if (!::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_impl._M_key_compare(__k, _S_key(( --__before)._M_node)))
                  {
                    if (_S_right(__before._M_node) == 0)
                      {
                        return _Res(0, __before._M_node);
                      }
                    else
                      {
                        return _Res(__pos._M_node, __pos._M_node);
                      }
                  }
                else
                  {
                    return (*this)._M_get_insert_equal_pos(__k);
                  }
              }
          }
        else
          {
            typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator __after = __pos;
            if (__pos._M_node == (*this)._M_rightmost())
              {
                return _Res(0, (*this)._M_rightmost());
              }
            else
              {
                if (!::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_impl._M_key_compare(_S_key(( ++__after)._M_node), __k))
                  {
                    if (_S_right(__pos._M_node) == 0)
                      {
                        return _Res(0, __pos._M_node);
                      }
                    else
                      {
                        return _Res(__after._M_node, __after._M_node);
                      }
                  }
                else
                  {
                    return ::std::pair< ::std::_Rb_tree_node_base *, ::std::_Rb_tree_node_base *>(0, 0);
                  }
              }
          }
      }
  }
  template < typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc >
  template < typename _NodeGen >
  typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator _Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_insert_equal_(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator __position, const _Val &__v, _NodeGen &__node_gen)
  {
    ::std::pair< ::std::_Rb_tree_node_base *, ::std::_Rb_tree_node_base *> __res = (*this)._M_get_insert_hint_equal_pos(__position, _KeyOfValue()(__v));
    if (__res.second)
      {
        return (*this)._M_insert_(__res.first, __res.second, __v, __node_gen);
      }
    return (*this)._M_insert_equal_lower(__v);
  }
  template < typename _Key, typename _Val, typename _KoV, typename _Cmp, typename _Alloc >
  template < typename _II >
  void _Rb_tree<_Key, _Val, _KoV, _Cmp, _Alloc>::_M_insert_unique(_II __first, _II __last)
  {
    typename ::std::_Rb_tree<_Key, _Val, _KoV, _Cmp, _Alloc>::_Alloc_node __an(*this);
    for (; __first != __last;  ++__first)
      {
        (*this)._M_insert_unique_((*this).end(), *__first, __an);
      }
  }
  template < typename _Key, typename _Val, typename _KoV, typename _Cmp, typename _Alloc >
  template < typename _II >
  void _Rb_tree<_Key, _Val, _KoV, _Cmp, _Alloc>::_M_insert_equal(_II __first, _II __last)
  {
    typename ::std::_Rb_tree<_Key, _Val, _KoV, _Cmp, _Alloc>::_Alloc_node __an(*this);
    for (; __first != __last;  ++__first)
      {
        (*this)._M_insert_equal_((*this).end(), *__first, __an);
      }
  }
  template < typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc >
  void _Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_erase_aux(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator __position)
  {
    typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Link_type __y = static_cast<typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Link_type>(_Rb_tree_rebalance_for_erase(const_cast<typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Base_ptr>(__position._M_node), this->_M_impl._M_header));
    (*this)._M_drop_node(__y);
     --::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_impl._M_node_count;
  }
  template < typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc >
  void _Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_erase_aux(typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator __first, typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator __last)
  {
    if (__first == (*this).begin() && __last == (*this).end())
      {
        (*this).clear();
      }
    else
      {
        while (__first != __last)
          {
            (*this)._M_erase_aux(__first++);
          }
      }
  }
  template < typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc >
  typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::size_type _Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::erase(const _Key &__x)
  {
    ::std::pair<typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator, typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator> __p = (*this).equal_range(__x);
    const typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::size_type __old_size = (*this).size();
    (*this)._M_erase_aux(__p.first, __p.second);
    return __old_size - (*this).size();
  }
  template < typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc >
  void _Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::erase(const _Key *__first, const _Key *__last)
  {
    while (__first != __last)
      {
        (*this).erase(*__first++);
      }
  }
  template < typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc >
  typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator _Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::find(const _Key &__k)
  {
    typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator __j = (*this)._M_lower_bound((*this)._M_begin(), (*this)._M_end(), __k);
    return __j == (*this).end() || ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_impl._M_key_compare(__k, _S_key(__j._M_node)) ? (*this).end() : __j;
  }
  template < typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc >
  typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator _Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::find(const _Key &__k) const 
  {
    typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator __j = (*this)._M_lower_bound((*this)._M_begin(), (*this)._M_end(), __k);
    return __j == (*this).end() || ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_impl._M_key_compare(__k, _S_key(__j._M_node)) ? (*this).end() : __j;
  }
  template < typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc >
  typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::size_type _Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::count(const _Key &__k) const 
  {
    ::std::pair<typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator, typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator> __p = (*this).equal_range(__k);
    const typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::size_type __n = std::distance(__p.first, __p.second);
    return __n;
  }
  unsigned int _Rb_tree_black_count(const ::std::_Rb_tree_node_base *__node, const ::std::_Rb_tree_node_base *__root) throw() __attribute__((__pure__));
  template < typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc >
  bool _Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::__rb_verify() const 
  {
    if (::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_impl._M_node_count == 0 || (*this).begin() == (*this).end())
      {
        return ((::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_impl._M_node_count == 0 && (*this).begin() == (*this).end()) && this->_M_impl._M_header._M_left == (*this)._M_end()) && this->_M_impl._M_header._M_right == (*this)._M_end();
      }
    unsigned int __len = _Rb_tree_black_count((*this)._M_leftmost(), (*this)._M_root());
    for (typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::const_iterator __it = (*this).begin(); __it != (*this).end();  ++__it)
      {
        typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Const_Link_type __x = static_cast<typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Const_Link_type>(__it._M_node);
        typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Const_Link_type __L = _S_left(__x);
        typename ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_Const_Link_type __R = _S_right(__x);
        if (__x->_M_color == ::std::_S_red)
          {
            if ((__L && __L->_M_color == ::std::_S_red) || (__R && __R->_M_color == ::std::_S_red))
              {
                return false;
              }
          }
        if (__L && ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_impl._M_key_compare(_S_key(__x), _S_key(__L)))
          {
            return false;
          }
        if (__R && ::std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::_M_impl._M_key_compare(_S_key(__R), _S_key(__x)))
          {
            return false;
          }
        if ((!__L && !__R) && _Rb_tree_black_count(__x, (*this)._M_root()) != __len)
          {
            return false;
          }
      }
    if ((*this)._M_leftmost() != _Rb_tree_node_base::_S_minimum((*this)._M_root()))
      {
        return false;
      }
    if ((*this)._M_rightmost() != _Rb_tree_node_base::_S_maximum((*this)._M_root()))
      {
        return false;
      }
    return true;
  }
  template < typename _Key, typename _Tp, typename _Compare, typename _Alloc >
  class multimap;
  template < typename _Key, typename _Tp, typename _Compare = ::std::less<_Key>, typename _Alloc = ::std::allocator< ::std::pair<const _Key, _Tp> > >
  class  map
  {
    public:
      typedef _Key key_type;
      typedef _Tp mapped_type;
      typedef ::std::pair<const _Key, _Tp> value_type;
      typedef _Compare key_compare;
      typedef _Alloc allocator_type;
      class  value_compare : public ::std::binary_function<typename ::std::map<_Key, _Tp, _Compare, _Alloc>::value_type, typename ::std::map<_Key, _Tp, _Compare, _Alloc>::value_type, bool>
      {
        protected:
          _Compare comp;
          inline value_compare(_Compare __c)
            : comp(__c)
          {
          }
        public:
          inline bool operator ()(const typename ::std::map<_Key, _Tp, _Compare, _Alloc>::value_type &__x, const typename ::std::map<_Key, _Tp, _Compare, _Alloc>::value_type &__y) const 
          {
            return ::std::map<_Key, _Tp, _Compare, _Alloc>::value_compare::comp(__x.first, __y.first);
          }
        friend class ::std::map<_Key, _Tp, _Compare, _Alloc>;
      };
    private:
      typedef typename ::__gnu_cxx::__alloc_traits<_Alloc>::template rebind< typename ::std::map<_Key, _Tp, _Compare, _Alloc>::value_type>::other _Pair_alloc_type;
      typedef ::std::_Rb_tree<typename ::std::map<_Key, _Tp, _Compare, _Alloc>::key_type, typename ::std::map<_Key, _Tp, _Compare, _Alloc>::value_type, ::std::_Select1st<typename ::std::map<_Key, _Tp, _Compare, _Alloc>::value_type>, typename ::std::map<_Key, _Tp, _Compare, _Alloc>::key_compare, typename ::std::map<_Key, _Tp, _Compare, _Alloc>::_Pair_alloc_type> _Rep_type;
      typename ::std::map<_Key, _Tp, _Compare, _Alloc>::_Rep_type _M_t;
      typedef ::__gnu_cxx::__alloc_traits<typename ::std::map<_Key, _Tp, _Compare, _Alloc>::_Pair_alloc_type> _Alloc_traits;
    public:
      typedef typename ::__gnu_cxx::__alloc_traits<typename ::std::map<_Key, _Tp, _Compare, _Alloc>::_Pair_alloc_type>::pointer pointer;
      typedef typename ::__gnu_cxx::__alloc_traits<typename ::std::map<_Key, _Tp, _Compare, _Alloc>::_Pair_alloc_type>::const_pointer const_pointer;
      typedef typename ::__gnu_cxx::__alloc_traits<typename ::std::map<_Key, _Tp, _Compare, _Alloc>::_Pair_alloc_type>::reference reference;
      typedef typename ::__gnu_cxx::__alloc_traits<typename ::std::map<_Key, _Tp, _Compare, _Alloc>::_Pair_alloc_type>::const_reference const_reference;
      typedef typename ::std::_Rb_tree<typename ::std::map<_Key, _Tp, _Compare, _Alloc>::key_type, typename ::std::map<_Key, _Tp, _Compare, _Alloc>::value_type, ::std::_Select1st<typename ::std::map<_Key, _Tp, _Compare, _Alloc>::value_type>, typename ::std::map<_Key, _Tp, _Compare, _Alloc>::key_compare, typename ::std::map<_Key, _Tp, _Compare, _Alloc>::_Pair_alloc_type>::iterator iterator;
      typedef typename ::std::_Rb_tree<typename ::std::map<_Key, _Tp, _Compare, _Alloc>::key_type, typename ::std::map<_Key, _Tp, _Compare, _Alloc>::value_type, ::std::_Select1st<typename ::std::map<_Key, _Tp, _Compare, _Alloc>::value_type>, typename ::std::map<_Key, _Tp, _Compare, _Alloc>::key_compare, typename ::std::map<_Key, _Tp, _Compare, _Alloc>::_Pair_alloc_type>::const_iterator const_iterator;
      typedef typename ::std::_Rb_tree<typename ::std::map<_Key, _Tp, _Compare, _Alloc>::key_type, typename ::std::map<_Key, _Tp, _Compare, _Alloc>::value_type, ::std::_Select1st<typename ::std::map<_Key, _Tp, _Compare, _Alloc>::value_type>, typename ::std::map<_Key, _Tp, _Compare, _Alloc>::key_compare, typename ::std::map<_Key, _Tp, _Compare, _Alloc>::_Pair_alloc_type>::size_type size_type;
      typedef typename ::std::_Rb_tree<typename ::std::map<_Key, _Tp, _Compare, _Alloc>::key_type, typename ::std::map<_Key, _Tp, _Compare, _Alloc>::value_type, ::std::_Select1st<typename ::std::map<_Key, _Tp, _Compare, _Alloc>::value_type>, typename ::std::map<_Key, _Tp, _Compare, _Alloc>::key_compare, typename ::std::map<_Key, _Tp, _Compare, _Alloc>::_Pair_alloc_type>::difference_type difference_type;
      typedef typename ::std::_Rb_tree<typename ::std::map<_Key, _Tp, _Compare, _Alloc>::key_type, typename ::std::map<_Key, _Tp, _Compare, _Alloc>::value_type, ::std::_Select1st<typename ::std::map<_Key, _Tp, _Compare, _Alloc>::value_type>, typename ::std::map<_Key, _Tp, _Compare, _Alloc>::key_compare, typename ::std::map<_Key, _Tp, _Compare, _Alloc>::_Pair_alloc_type>::reverse_iterator reverse_iterator;
      typedef typename ::std::_Rb_tree<typename ::std::map<_Key, _Tp, _Compare, _Alloc>::key_type, typename ::std::map<_Key, _Tp, _Compare, _Alloc>::value_type, ::std::_Select1st<typename ::std::map<_Key, _Tp, _Compare, _Alloc>::value_type>, typename ::std::map<_Key, _Tp, _Compare, _Alloc>::key_compare, typename ::std::map<_Key, _Tp, _Compare, _Alloc>::_Pair_alloc_type>::const_reverse_iterator const_reverse_iterator;
      inline map()
        : _M_t()
      {
      }
      inline explicit map(const _Compare &__comp, const typename ::std::map<_Key, _Tp, _Compare, _Alloc>::allocator_type &__a  = (((typename ::std::map<_Key, _Tp, _Compare, _Alloc>::allocator_type()))))
        : _M_t(__comp, ((typename ::std::map<_Key, _Tp, _Compare, _Alloc>::_Pair_alloc_type(__a))))
      {
      }
      inline map(const ::std::map<_Key, _Tp, _Compare, _Alloc> &__x)
        : _M_t(__x._M_t)
      {
      }
      template < typename _InputIterator >
      inline map(_InputIterator __first, _InputIterator __last)
        : _M_t()
      {
        ::std::map<_Key, _Tp, _Compare, _Alloc>::_M_t._M_insert_unique(__first, __last);
      }
      template < typename _InputIterator >
      inline map(_InputIterator __first, _InputIterator __last, const _Compare &__comp, const typename ::std::map<_Key, _Tp, _Compare, _Alloc>::allocator_type &__a  = (((typename ::std::map<_Key, _Tp, _Compare, _Alloc>::allocator_type()))))
        : _M_t(__comp, ((typename ::std::map<_Key, _Tp, _Compare, _Alloc>::_Pair_alloc_type(__a))))
      {
        ::std::map<_Key, _Tp, _Compare, _Alloc>::_M_t._M_insert_unique(__first, __last);
      }
      inline ::std::map<_Key, _Tp, _Compare, _Alloc> &operator =(const ::std::map<_Key, _Tp, _Compare, _Alloc> &__x)
      {
        ::std::map<_Key, _Tp, _Compare, _Alloc>::_M_t = __x._M_t;
        return *this;
      }
      inline typename ::std::map<_Key, _Tp, _Compare, _Alloc>::allocator_type get_allocator() const 
      {
        return ((typename ::std::map<_Key, _Tp, _Compare, _Alloc>::allocator_type(::std::map<_Key, _Tp, _Compare, _Alloc>::_M_t.get_allocator())));
      }
      inline typename ::std::map<_Key, _Tp, _Compare, _Alloc>::iterator begin()
      {
        return ::std::map<_Key, _Tp, _Compare, _Alloc>::_M_t.begin();
      }
      inline typename ::std::map<_Key, _Tp, _Compare, _Alloc>::const_iterator begin() const 
      {
        return ::std::map<_Key, _Tp, _Compare, _Alloc>::_M_t.begin();
      }
      inline typename ::std::map<_Key, _Tp, _Compare, _Alloc>::iterator end()
      {
        return ::std::map<_Key, _Tp, _Compare, _Alloc>::_M_t.end();
      }
      inline typename ::std::map<_Key, _Tp, _Compare, _Alloc>::const_iterator end() const 
      {
        return ::std::map<_Key, _Tp, _Compare, _Alloc>::_M_t.end();
      }
      inline typename ::std::map<_Key, _Tp, _Compare, _Alloc>::reverse_iterator rbegin()
      {
        return ::std::map<_Key, _Tp, _Compare, _Alloc>::_M_t.rbegin();
      }
      inline typename ::std::map<_Key, _Tp, _Compare, _Alloc>::const_reverse_iterator rbegin() const 
      {
        return ::std::map<_Key, _Tp, _Compare, _Alloc>::_M_t.rbegin();
      }
      inline typename ::std::map<_Key, _Tp, _Compare, _Alloc>::reverse_iterator rend()
      {
        return ::std::map<_Key, _Tp, _Compare, _Alloc>::_M_t.rend();
      }
      inline typename ::std::map<_Key, _Tp, _Compare, _Alloc>::const_reverse_iterator rend() const 
      {
        return ::std::map<_Key, _Tp, _Compare, _Alloc>::_M_t.rend();
      }
      inline bool empty() const 
      {
        return ::std::map<_Key, _Tp, _Compare, _Alloc>::_M_t.empty();
      }
      inline typename ::std::map<_Key, _Tp, _Compare, _Alloc>::size_type size() const 
      {
        return ::std::map<_Key, _Tp, _Compare, _Alloc>::_M_t.size();
      }
      inline typename ::std::map<_Key, _Tp, _Compare, _Alloc>::size_type max_size() const 
      {
        return ::std::map<_Key, _Tp, _Compare, _Alloc>::_M_t.max_size();
      }
      inline typename ::std::map<_Key, _Tp, _Compare, _Alloc>::mapped_type &operator [](const typename ::std::map<_Key, _Tp, _Compare, _Alloc>::key_type &__k)
      {
        typename ::std::map<_Key, _Tp, _Compare, _Alloc>::iterator __i = (*this).lower_bound(__k);
        if (__i == (*this).end() || (*this).key_comp()(__k, (*__i).first))
          {
            __i = (*this).insert(__i, ((typename ::std::map<_Key, _Tp, _Compare, _Alloc>::value_type(__k, ((typename ::std::map<_Key, _Tp, _Compare, _Alloc>::mapped_type()))))));
          }
        return (*__i).second;
      }
      inline typename ::std::map<_Key, _Tp, _Compare, _Alloc>::mapped_type &at(const typename ::std::map<_Key, _Tp, _Compare, _Alloc>::key_type &__k)
      {
        typename ::std::map<_Key, _Tp, _Compare, _Alloc>::iterator __i = (*this).lower_bound(__k);
        if (__i == (*this).end() || (*this).key_comp()(__k, (*__i).first))
          {
            ::std::__throw_out_of_range("map::at");
          }
        return (*__i).second;
      }
      inline const typename ::std::map<_Key, _Tp, _Compare, _Alloc>::mapped_type &at(const typename ::std::map<_Key, _Tp, _Compare, _Alloc>::key_type &__k) const 
      {
        typename ::std::map<_Key, _Tp, _Compare, _Alloc>::const_iterator __i = (*this).lower_bound(__k);
        if (__i == (*this).end() || (*this).key_comp()(__k, (*__i).first))
          {
            ::std::__throw_out_of_range("map::at");
          }
        return (*__i).second;
      }
      inline ::std::pair<typename ::std::map<_Key, _Tp, _Compare, _Alloc>::iterator, bool> insert(const typename ::std::map<_Key, _Tp, _Compare, _Alloc>::value_type &__x)
      {
        return ::std::map<_Key, _Tp, _Compare, _Alloc>::_M_t._M_insert_unique(__x);
      }
      inline typename ::std::map<_Key, _Tp, _Compare, _Alloc>::iterator insert(typename ::std::map<_Key, _Tp, _Compare, _Alloc>::iterator __position, const typename ::std::map<_Key, _Tp, _Compare, _Alloc>::value_type &__x)
      {
        return ::std::map<_Key, _Tp, _Compare, _Alloc>::_M_t._M_insert_unique_(__position, __x);
      }
      template < typename _InputIterator >
      inline void insert(_InputIterator __first, _InputIterator __last)
      {
        ::std::map<_Key, _Tp, _Compare, _Alloc>::_M_t._M_insert_unique(__first, __last);
      }
      inline void erase(typename ::std::map<_Key, _Tp, _Compare, _Alloc>::iterator __position)
      {
        ::std::map<_Key, _Tp, _Compare, _Alloc>::_M_t.erase(__position);
      }
      inline typename ::std::map<_Key, _Tp, _Compare, _Alloc>::size_type erase(const typename ::std::map<_Key, _Tp, _Compare, _Alloc>::key_type &__x)
      {
        return ::std::map<_Key, _Tp, _Compare, _Alloc>::_M_t.erase(__x);
      }
      inline void erase(typename ::std::map<_Key, _Tp, _Compare, _Alloc>::iterator __first, typename ::std::map<_Key, _Tp, _Compare, _Alloc>::iterator __last)
      {
        ::std::map<_Key, _Tp, _Compare, _Alloc>::_M_t.erase(__first, __last);
      }
      inline void swap(::std::map<_Key, _Tp, _Compare, _Alloc> &__x)
      {
        ::std::map<_Key, _Tp, _Compare, _Alloc>::_M_t.swap(__x._M_t);
      }
      inline void clear()
      {
        ::std::map<_Key, _Tp, _Compare, _Alloc>::_M_t.clear();
      }
      inline typename ::std::map<_Key, _Tp, _Compare, _Alloc>::key_compare key_comp() const 
      {
        return ::std::map<_Key, _Tp, _Compare, _Alloc>::_M_t.key_comp();
      }
      inline typename ::std::map<_Key, _Tp, _Compare, _Alloc>::value_compare value_comp() const 
      {
        return ((typename ::std::map<_Key, _Tp, _Compare, _Alloc>::value_compare(::std::map<_Key, _Tp, _Compare, _Alloc>::_M_t.key_comp())));
      }
      inline typename ::std::map<_Key, _Tp, _Compare, _Alloc>::iterator find(const typename ::std::map<_Key, _Tp, _Compare, _Alloc>::key_type &__x)
      {
        return ::std::map<_Key, _Tp, _Compare, _Alloc>::_M_t.find(__x);
      }
      inline typename ::std::map<_Key, _Tp, _Compare, _Alloc>::const_iterator find(const typename ::std::map<_Key, _Tp, _Compare, _Alloc>::key_type &__x) const 
      {
        return ::std::map<_Key, _Tp, _Compare, _Alloc>::_M_t.find(__x);
      }
      inline typename ::std::map<_Key, _Tp, _Compare, _Alloc>::size_type count(const typename ::std::map<_Key, _Tp, _Compare, _Alloc>::key_type &__x) const 
      {
        return ::std::map<_Key, _Tp, _Compare, _Alloc>::_M_t.find(__x) == ::std::map<_Key, _Tp, _Compare, _Alloc>::_M_t.end() ? 0 : 1;
      }
      inline typename ::std::map<_Key, _Tp, _Compare, _Alloc>::iterator lower_bound(const typename ::std::map<_Key, _Tp, _Compare, _Alloc>::key_type &__x)
      {
        return ::std::map<_Key, _Tp, _Compare, _Alloc>::_M_t.lower_bound(__x);
      }
      inline typename ::std::map<_Key, _Tp, _Compare, _Alloc>::const_iterator lower_bound(const typename ::std::map<_Key, _Tp, _Compare, _Alloc>::key_type &__x) const 
      {
        return ::std::map<_Key, _Tp, _Compare, _Alloc>::_M_t.lower_bound(__x);
      }
      inline typename ::std::map<_Key, _Tp, _Compare, _Alloc>::iterator upper_bound(const typename ::std::map<_Key, _Tp, _Compare, _Alloc>::key_type &__x)
      {
        return ::std::map<_Key, _Tp, _Compare, _Alloc>::_M_t.upper_bound(__x);
      }
      inline typename ::std::map<_Key, _Tp, _Compare, _Alloc>::const_iterator upper_bound(const typename ::std::map<_Key, _Tp, _Compare, _Alloc>::key_type &__x) const 
      {
        return ::std::map<_Key, _Tp, _Compare, _Alloc>::_M_t.upper_bound(__x);
      }
      inline ::std::pair<typename ::std::map<_Key, _Tp, _Compare, _Alloc>::iterator, typename ::std::map<_Key, _Tp, _Compare, _Alloc>::iterator> equal_range(const typename ::std::map<_Key, _Tp, _Compare, _Alloc>::key_type &__x)
      {
        return ::std::map<_Key, _Tp, _Compare, _Alloc>::_M_t.equal_range(__x);
      }
      inline ::std::pair<typename ::std::map<_Key, _Tp, _Compare, _Alloc>::const_iterator, typename ::std::map<_Key, _Tp, _Compare, _Alloc>::const_iterator> equal_range(const typename ::std::map<_Key, _Tp, _Compare, _Alloc>::key_type &__x) const 
      {
        return ::std::map<_Key, _Tp, _Compare, _Alloc>::_M_t.equal_range(__x);
      }
    template < typename _K1, typename _T1, typename _C1, typename _A1 >
    friend bool operator ==(const ::std::map<_K1, _T1, _C1, _A1> &, const ::std::map<_K1, _T1, _C1, _A1> &);
    template < typename _K1, typename _T1, typename _C1, typename _A1 >
    friend bool operator <(const ::std::map<_K1, _T1, _C1, _A1> &, const ::std::map<_K1, _T1, _C1, _A1> &);
  };
  template < typename _Key, typename _Tp, typename _Compare, typename _Alloc >
  inline bool operator ==(const ::std::map<_Key, _Tp, _Compare, _Alloc> &__x, const ::std::map<_Key, _Tp, _Compare, _Alloc> &__y);
  template < typename _Key, typename _Tp, typename _Compare, typename _Alloc >
  inline bool operator ==(const ::std::map<_Key, _Tp, _Compare, _Alloc> &__x, const ::std::map<_Key, _Tp, _Compare, _Alloc> &__y)
  {
    return __x._M_t == __y._M_t;
  }
  template < typename _Key, typename _Tp, typename _Compare, typename _Alloc >
  inline bool operator <(const ::std::map<_Key, _Tp, _Compare, _Alloc> &__x, const ::std::map<_Key, _Tp, _Compare, _Alloc> &__y);
  template < typename _Key, typename _Tp, typename _Compare, typename _Alloc >
  inline bool operator <(const ::std::map<_Key, _Tp, _Compare, _Alloc> &__x, const ::std::map<_Key, _Tp, _Compare, _Alloc> &__y)
  {
    return __x._M_t < __y._M_t;
  }
  template < typename _Key, typename _Tp, typename _Compare, typename _Alloc >
  inline bool operator !=(const ::std::map<_Key, _Tp, _Compare, _Alloc> &__x, const ::std::map<_Key, _Tp, _Compare, _Alloc> &__y);
  template < typename _Key, typename _Tp, typename _Compare, typename _Alloc >
  inline bool operator !=(const ::std::map<_Key, _Tp, _Compare, _Alloc> &__x, const ::std::map<_Key, _Tp, _Compare, _Alloc> &__y)
  {
    return !(__x == __y);
  }
  template < typename _Key, typename _Tp, typename _Compare, typename _Alloc >
  inline bool operator >(const ::std::map<_Key, _Tp, _Compare, _Alloc> &__x, const ::std::map<_Key, _Tp, _Compare, _Alloc> &__y);
  template < typename _Key, typename _Tp, typename _Compare, typename _Alloc >
  inline bool operator >(const ::std::map<_Key, _Tp, _Compare, _Alloc> &__x, const ::std::map<_Key, _Tp, _Compare, _Alloc> &__y)
  {
    return __y < __x;
  }
  template < typename _Key, typename _Tp, typename _Compare, typename _Alloc >
  inline bool operator <=(const ::std::map<_Key, _Tp, _Compare, _Alloc> &__x, const ::std::map<_Key, _Tp, _Compare, _Alloc> &__y);
  template < typename _Key, typename _Tp, typename _Compare, typename _Alloc >
  inline bool operator <=(const ::std::map<_Key, _Tp, _Compare, _Alloc> &__x, const ::std::map<_Key, _Tp, _Compare, _Alloc> &__y)
  {
    return !(__y < __x);
  }
  template < typename _Key, typename _Tp, typename _Compare, typename _Alloc >
  inline bool operator >=(const ::std::map<_Key, _Tp, _Compare, _Alloc> &__x, const ::std::map<_Key, _Tp, _Compare, _Alloc> &__y);
  template < typename _Key, typename _Tp, typename _Compare, typename _Alloc >
  inline bool operator >=(const ::std::map<_Key, _Tp, _Compare, _Alloc> &__x, const ::std::map<_Key, _Tp, _Compare, _Alloc> &__y)
  {
    return !(__x < __y);
  }
  template < typename _Key, typename _Tp, typename _Compare, typename _Alloc >
  inline void swap(::std::map<_Key, _Tp, _Compare, _Alloc> &__x, ::std::map<_Key, _Tp, _Compare, _Alloc> &__y);
  template < typename _Key, typename _Tp, typename _Compare, typename _Alloc >
  inline void swap(::std::map<_Key, _Tp, _Compare, _Alloc> &__x, ::std::map<_Key, _Tp, _Compare, _Alloc> &__y)
  {
    __x.swap(__y);
  }
  template < typename _Key, typename _Tp, typename _Compare, typename _Alloc >
  class map;
  template < typename _Key, typename _Tp, typename _Compare = ::std::less<_Key>, typename _Alloc = ::std::allocator< ::std::pair<const _Key, _Tp> > >
  class  multimap
  {
    public:
      typedef _Key key_type;
      typedef _Tp mapped_type;
      typedef ::std::pair<const _Key, _Tp> value_type;
      typedef _Compare key_compare;
      typedef _Alloc allocator_type;
      class  value_compare : public ::std::binary_function<typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::value_type, typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::value_type, bool>
      {
        protected:
          _Compare comp;
          inline value_compare(_Compare __c)
            : comp(__c)
          {
          }
        public:
          inline bool operator ()(const typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::value_type &__x, const typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::value_type &__y) const 
          {
            return ::std::multimap<_Key, _Tp, _Compare, _Alloc>::value_compare::comp(__x.first, __y.first);
          }
        friend class ::std::multimap<_Key, _Tp, _Compare, _Alloc>;
      };
    private:
      typedef typename ::__gnu_cxx::__alloc_traits<_Alloc>::template rebind< typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::value_type>::other _Pair_alloc_type;
      typedef ::std::_Rb_tree<typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::key_type, typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::value_type, ::std::_Select1st<typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::value_type>, typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::key_compare, typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_Pair_alloc_type> _Rep_type;
      typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_Rep_type _M_t;
      typedef ::__gnu_cxx::__alloc_traits<typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_Pair_alloc_type> _Alloc_traits;
    public:
      typedef typename ::__gnu_cxx::__alloc_traits<typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_Pair_alloc_type>::pointer pointer;
      typedef typename ::__gnu_cxx::__alloc_traits<typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_Pair_alloc_type>::const_pointer const_pointer;
      typedef typename ::__gnu_cxx::__alloc_traits<typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_Pair_alloc_type>::reference reference;
      typedef typename ::__gnu_cxx::__alloc_traits<typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_Pair_alloc_type>::const_reference const_reference;
      typedef typename ::std::_Rb_tree<typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::key_type, typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::value_type, ::std::_Select1st<typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::value_type>, typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::key_compare, typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_Pair_alloc_type>::iterator iterator;
      typedef typename ::std::_Rb_tree<typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::key_type, typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::value_type, ::std::_Select1st<typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::value_type>, typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::key_compare, typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_Pair_alloc_type>::const_iterator const_iterator;
      typedef typename ::std::_Rb_tree<typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::key_type, typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::value_type, ::std::_Select1st<typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::value_type>, typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::key_compare, typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_Pair_alloc_type>::size_type size_type;
      typedef typename ::std::_Rb_tree<typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::key_type, typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::value_type, ::std::_Select1st<typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::value_type>, typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::key_compare, typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_Pair_alloc_type>::difference_type difference_type;
      typedef typename ::std::_Rb_tree<typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::key_type, typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::value_type, ::std::_Select1st<typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::value_type>, typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::key_compare, typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_Pair_alloc_type>::reverse_iterator reverse_iterator;
      typedef typename ::std::_Rb_tree<typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::key_type, typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::value_type, ::std::_Select1st<typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::value_type>, typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::key_compare, typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_Pair_alloc_type>::const_reverse_iterator const_reverse_iterator;
      inline multimap()
        : _M_t()
      {
      }
      inline explicit multimap(const _Compare &__comp, const typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::allocator_type &__a  = (((typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::allocator_type()))))
        : _M_t(__comp, ((typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_Pair_alloc_type(__a))))
      {
      }
      inline multimap(const ::std::multimap<_Key, _Tp, _Compare, _Alloc> &__x)
        : _M_t(__x._M_t)
      {
      }
      template < typename _InputIterator >
      inline multimap(_InputIterator __first, _InputIterator __last)
        : _M_t()
      {
        ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_M_t._M_insert_equal(__first, __last);
      }
      template < typename _InputIterator >
      inline multimap(_InputIterator __first, _InputIterator __last, const _Compare &__comp, const typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::allocator_type &__a  = (((typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::allocator_type()))))
        : _M_t(__comp, ((typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_Pair_alloc_type(__a))))
      {
        ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_M_t._M_insert_equal(__first, __last);
      }
      inline ::std::multimap<_Key, _Tp, _Compare, _Alloc> &operator =(const ::std::multimap<_Key, _Tp, _Compare, _Alloc> &__x)
      {
        ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_M_t = __x._M_t;
        return *this;
      }
      inline typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::allocator_type get_allocator() const 
      {
        return ((typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::allocator_type(::std::multimap<_Key, _Tp, _Compare, _Alloc>::_M_t.get_allocator())));
      }
      inline typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::iterator begin()
      {
        return ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_M_t.begin();
      }
      inline typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::const_iterator begin() const 
      {
        return ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_M_t.begin();
      }
      inline typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::iterator end()
      {
        return ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_M_t.end();
      }
      inline typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::const_iterator end() const 
      {
        return ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_M_t.end();
      }
      inline typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::reverse_iterator rbegin()
      {
        return ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_M_t.rbegin();
      }
      inline typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::const_reverse_iterator rbegin() const 
      {
        return ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_M_t.rbegin();
      }
      inline typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::reverse_iterator rend()
      {
        return ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_M_t.rend();
      }
      inline typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::const_reverse_iterator rend() const 
      {
        return ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_M_t.rend();
      }
      inline bool empty() const 
      {
        return ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_M_t.empty();
      }
      inline typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::size_type size() const 
      {
        return ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_M_t.size();
      }
      inline typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::size_type max_size() const 
      {
        return ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_M_t.max_size();
      }
      inline typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::iterator insert(const typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::value_type &__x)
      {
        return ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_M_t._M_insert_equal(__x);
      }
      inline typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::iterator insert(typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::iterator __position, const typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::value_type &__x)
      {
        return ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_M_t._M_insert_equal_(__position, __x);
      }
      template < typename _InputIterator >
      inline void insert(_InputIterator __first, _InputIterator __last)
      {
        ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_M_t._M_insert_equal(__first, __last);
      }
      inline void erase(typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::iterator __position)
      {
        ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_M_t.erase(__position);
      }
      inline typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::size_type erase(const typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::key_type &__x)
      {
        return ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_M_t.erase(__x);
      }
      inline void erase(typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::iterator __first, typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::iterator __last)
      {
        ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_M_t.erase(__first, __last);
      }
      inline void swap(::std::multimap<_Key, _Tp, _Compare, _Alloc> &__x)
      {
        ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_M_t.swap(__x._M_t);
      }
      inline void clear()
      {
        ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_M_t.clear();
      }
      inline typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::key_compare key_comp() const 
      {
        return ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_M_t.key_comp();
      }
      inline typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::value_compare value_comp() const 
      {
        return ((typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::value_compare(::std::multimap<_Key, _Tp, _Compare, _Alloc>::_M_t.key_comp())));
      }
      inline typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::iterator find(const typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::key_type &__x)
      {
        return ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_M_t.find(__x);
      }
      inline typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::const_iterator find(const typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::key_type &__x) const 
      {
        return ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_M_t.find(__x);
      }
      inline typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::size_type count(const typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::key_type &__x) const 
      {
        return ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_M_t.count(__x);
      }
      inline typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::iterator lower_bound(const typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::key_type &__x)
      {
        return ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_M_t.lower_bound(__x);
      }
      inline typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::const_iterator lower_bound(const typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::key_type &__x) const 
      {
        return ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_M_t.lower_bound(__x);
      }
      inline typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::iterator upper_bound(const typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::key_type &__x)
      {
        return ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_M_t.upper_bound(__x);
      }
      inline typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::const_iterator upper_bound(const typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::key_type &__x) const 
      {
        return ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_M_t.upper_bound(__x);
      }
      inline ::std::pair<typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::iterator, typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::iterator> equal_range(const typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::key_type &__x)
      {
        return ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_M_t.equal_range(__x);
      }
      inline ::std::pair<typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::const_iterator, typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::const_iterator> equal_range(const typename ::std::multimap<_Key, _Tp, _Compare, _Alloc>::key_type &__x) const 
      {
        return ::std::multimap<_Key, _Tp, _Compare, _Alloc>::_M_t.equal_range(__x);
      }
    template < typename _K1, typename _T1, typename _C1, typename _A1 >
    friend bool operator ==(const ::std::multimap<_K1, _T1, _C1, _A1> &, const ::std::multimap<_K1, _T1, _C1, _A1> &);
    template < typename _K1, typename _T1, typename _C1, typename _A1 >
    friend bool operator <(const ::std::multimap<_K1, _T1, _C1, _A1> &, const ::std::multimap<_K1, _T1, _C1, _A1> &);
  };
  template < typename _Key, typename _Tp, typename _Compare, typename _Alloc >
  inline bool operator ==(const ::std::multimap<_Key, _Tp, _Compare, _Alloc> &__x, const ::std::multimap<_Key, _Tp, _Compare, _Alloc> &__y);
  template < typename _Key, typename _Tp, typename _Compare, typename _Alloc >
  inline bool operator ==(const ::std::multimap<_Key, _Tp, _Compare, _Alloc> &__x, const ::std::multimap<_Key, _Tp, _Compare, _Alloc> &__y)
  {
    return __x._M_t == __y._M_t;
  }
  template < typename _Key, typename _Tp, typename _Compare, typename _Alloc >
  inline bool operator <(const ::std::multimap<_Key, _Tp, _Compare, _Alloc> &__x, const ::std::multimap<_Key, _Tp, _Compare, _Alloc> &__y);
  template < typename _Key, typename _Tp, typename _Compare, typename _Alloc >
  inline bool operator <(const ::std::multimap<_Key, _Tp, _Compare, _Alloc> &__x, const ::std::multimap<_Key, _Tp, _Compare, _Alloc> &__y)
  {
    return __x._M_t < __y._M_t;
  }
  template < typename _Key, typename _Tp, typename _Compare, typename _Alloc >
  inline bool operator !=(const ::std::multimap<_Key, _Tp, _Compare, _Alloc> &__x, const ::std::multimap<_Key, _Tp, _Compare, _Alloc> &__y);
  template < typename _Key, typename _Tp, typename _Compare, typename _Alloc >
  inline bool operator !=(const ::std::multimap<_Key, _Tp, _Compare, _Alloc> &__x, const ::std::multimap<_Key, _Tp, _Compare, _Alloc> &__y)
  {
    return !(__x == __y);
  }
  template < typename _Key, typename _Tp, typename _Compare, typename _Alloc >
  inline bool operator >(const ::std::multimap<_Key, _Tp, _Compare, _Alloc> &__x, const ::std::multimap<_Key, _Tp, _Compare, _Alloc> &__y);
  template < typename _Key, typename _Tp, typename _Compare, typename _Alloc >
  inline bool operator >(const ::std::multimap<_Key, _Tp, _Compare, _Alloc> &__x, const ::std::multimap<_Key, _Tp, _Compare, _Alloc> &__y)
  {
    return __y < __x;
  }
  template < typename _Key, typename _Tp, typename _Compare, typename _Alloc >
  inline bool operator <=(const ::std::multimap<_Key, _Tp, _Compare, _Alloc> &__x, const ::std::multimap<_Key, _Tp, _Compare, _Alloc> &__y);
  template < typename _Key, typename _Tp, typename _Compare, typename _Alloc >
  inline bool operator <=(const ::std::multimap<_Key, _Tp, _Compare, _Alloc> &__x, const ::std::multimap<_Key, _Tp, _Compare, _Alloc> &__y)
  {
    return !(__y < __x);
  }
  template < typename _Key, typename _Tp, typename _Compare, typename _Alloc >
  inline bool operator >=(const ::std::multimap<_Key, _Tp, _Compare, _Alloc> &__x, const ::std::multimap<_Key, _Tp, _Compare, _Alloc> &__y);
  template < typename _Key, typename _Tp, typename _Compare, typename _Alloc >
  inline bool operator >=(const ::std::multimap<_Key, _Tp, _Compare, _Alloc> &__x, const ::std::multimap<_Key, _Tp, _Compare, _Alloc> &__y)
  {
    return !(__x < __y);
  }
  template < typename _Key, typename _Tp, typename _Compare, typename _Alloc >
  inline void swap(::std::multimap<_Key, _Tp, _Compare, _Alloc> &__x, ::std::multimap<_Key, _Tp, _Compare, _Alloc> &__y);
  template < typename _Key, typename _Tp, typename _Compare, typename _Alloc >
  inline void swap(::std::multimap<_Key, _Tp, _Compare, _Alloc> &__x, ::std::multimap<_Key, _Tp, _Compare, _Alloc> &__y)
  {
    __x.swap(__y);
  }
}
using namespace ::std;
class  AbstractBlockPruning
{
  public:
    AbstractBlockPruning();
    virtual ~AbstractBlockPruning();
    void updateBestScore(int score);
    const ::Grid *getGrid() const ;
    void setGrid(const ::Grid *grid);
    void setSuperPartition(::Partition superPartition);
    void setScoreParams(const ::score_params_t *score_params);
    void setLocalAlignment();
    void setGlobalAlignment();
    int getRecurrenceType() const ;
    void setRecurrenceType(int recurrenceType);
  protected:
    bool isBlockPrunable(int bx, int by, int score);
  private:
    const ::score_params_t *score_params;
    int max_i;
    int max_j;
    int bestScore;
    int recurrenceType;
    const ::Grid *grid;
    virtual void initialize() = 0 ;
    virtual void finalize() = 0 ;
  public:
};
class  AbstractAligner : public ::IAligner
{
  public:
    AbstractAligner();
    virtual ~AbstractAligner();
    virtual void setManager(::IManager *manager);
    virtual const int *getForkWeights();
    virtual ::match_result_t matchLastColumn(const ::cell_t *buffer, const ::cell_t *base, int len, int goalScore);
  protected:
    void setForkCount(const int forkCount, const int *forkWeights  = (0L));
    ::Grid *createGrid(::Partition partition);
    virtual const ::Grid *getGrid() const ;
    void initializeBlockPruning(::AbstractBlockPruning *blockPruner);
    int getRecurrenceType() const ;
    int getSpecialRowInterval() const ;
    int getSpecialColumnInterval() const ;
    int getFirstColumnInitType();
    ::Partition getSuperPartition();
    int getFirstRowInitType();
    void receiveFirstRow(::cell_t *buffer, int len);
    void receiveFirstColumn(::cell_t *buffer, int len);
    void dispatchColumn(int j, const ::cell_t *buffer, int len);
    void dispatchRow(int i, const ::cell_t *buffer, int len);
    void dispatchScore(::score_t score, int bx  = ( -1), int by  = ( -1));
    bool mustContinue();
    bool mustDispatchLastCell();
    bool mustDispatchLastRow();
    bool mustDispatchLastColumn();
    bool mustDispatchSpecialRows();
    bool mustDispatchSpecialColumns();
    bool mustDispatchScores();
    bool mustPruneBlocks();
    ::cell_t getFirstColumnTail() const ;
    ::cell_t getFirstRowTail() const ;
  private:
    ::IManager *manager;
    int *forkWeights;
    int forkCount;
    ::Grid *grid;
    ::cell_t firstColumnTail;
    ::cell_t firstRowTail;
  public:
};
class  BlockAlignerParameters : public ::AbstractAlignerParameters
{
    int gridWidth;
    int gridHeight;
    int blockHeight;
    int blockWidth;
  public:
    BlockAlignerParameters();
    virtual ~BlockAlignerParameters();
    virtual int processArgument(int argc, char **argv);
    virtual void printUsage() const ;
    int getBlockHeight() const ;
    int getBlockWidth() const ;
    int getGridWidth() const ;
    int getGridHeight() const ;
};
class  AbstractBlockProcessor
{
  public:
    AbstractBlockProcessor();
    virtual ~AbstractBlockProcessor();
    virtual void setSequences(const char *seq0, const char *seq1, int seq0_len, int seq1_len) = 0 ;
    virtual void unsetSequences() = 0 ;
    virtual ::score_t processBlock(::cell_t *row, ::cell_t *col, const int i0, const int j0, const int i1, const int j1, const int recurrenceType) = 0 ;
};
class  BlockPruningGenericN2 : public ::AbstractBlockPruning
{
  public:
    BlockPruningGenericN2();
    virtual ~BlockPruningGenericN2();
    virtual void pruningUpdate(int bx, int by, int score);
    virtual bool isBlockPruned(int bx, int by);
  private:
    int **k;
    int gridHeight;
    int gridWidth;
    virtual void initialize();
    virtual void finalize();
  public:
};
class  AbstractBlockAligner : public ::AbstractAligner
{
  public:
    AbstractBlockAligner(::AbstractBlockProcessor *blockProcessor  = (0L), ::BlockAlignerParameters *params  = (0L));
    virtual ~AbstractBlockAligner();
    virtual void initialize();
    virtual void alignPartition(::Partition partition);
    virtual void finalize();
    virtual ::aligner_capabilities_t getCapabilities();
    virtual const ::score_params_t *getScoreParameters();
    virtual ::IAlignerParameters *getParameters();
    virtual void setSequences(const char *seq0, const char *seq1, int seq0_len, int seq1_len);
    virtual void unsetSequences();
    virtual void clearStatistics();
    virtual void printInitialStatistics(::FILE *file);
    virtual void printStageStatistics(::FILE *file);
    virtual void printFinalStatistics(::FILE *file);
    virtual void printStatistics(::FILE *file);
    virtual const char *getProgressString() const ;
    virtual long long int getProcessedCells();
  protected:
    ::cell_t **row;
    ::cell_t **col;
    virtual void scheduleBlocks(int grid_width, int grid_height) = 0 ;
    virtual void alignBlock(int bx, int by, int i0, int j0, int i1, int j1) = 0 ;
    void ignoreBlock(int bx, int by);
    bool isBlockPruned(int bx, int by) const ;
    virtual void increaseBlockStat(const bool pruned);
    void alignBlock(int bx, int by);
    bool processBlock(int bx, int by, int i0, int j0, int i1, int j1);
    bool isSpecialRow(int by);
    bool isSpecialColumn(int by);
    void setPreferredSizes(int preferredBlockSize, int preferredGridSize);
    virtual void allocateStructures();
    virtual void deallocateStructures();
  private:
    ::BlockAlignerParameters *params;
    ::score_t **grid_scores;
    ::AbstractBlockProcessor *blockProcessor;
    ::BlockPruningGenericN2 *blockPruner;
    int preferredBlockSize;
    int preferredGridSize;
    int statMinBlockWidth;
    int statMaxBlockWidth;
    int statMinBlockHeight;
    int statMaxBlockHeight;
    int statMinGridWidth;
    int statMaxGridWidth;
    int statMinGridHeight;
    int statMaxGridHeight;
    int statTotalBlocks;
    int statPrunedBlocks;
    ::score_params_t score_params;
    ::Grid *configureGrid(::Partition partition);
    void pruningUpdate(int bx, int by, int score);
  public:
};
class BlockPruningDiagonal;
class  BlockPruningDiagonal : public ::AbstractBlockPruning
{
  public:
    virtual ~BlockPruningDiagonal();
    BlockPruningDiagonal();
    virtual void initialize();
    virtual void finalize();
    void updatePruningWindow(int diagonal, const ::score_t *block_scores);
    void getNonPrunableWindow(int *start, int *end);
  private:
    int windowStart;
    int windowEnd;
  public:
};
class  AbstractDiagonalAligner : public ::AbstractAligner
{
  public:
    AbstractDiagonalAligner();
    virtual ~AbstractDiagonalAligner();
    virtual void alignPartition(::Partition partition);
    virtual void clearStatistics();
    virtual void printInitialStatistics(::FILE *file);
    virtual void printStageStatistics(::FILE *file);
    virtual void printFinalStatistics(::FILE *file);
    virtual void printStatistics(::FILE *file);
    virtual long long int getProcessedCells();
    virtual const char *getProgressString() const ;
  protected:
    virtual int getGridWidth(int width) = 0 ;
    virtual int getBlockHeight() = 0 ;
    virtual const ::cell_t *getSpecialRow(int j, int len) = 0 ;
    virtual const ::cell_t *getLastRow(int j, int len) = 0 ;
    virtual const ::cell_t *getLastColumn(int i, int len) = 0 ;
    virtual const ::score_t *getBlockScores() = 0 ;
    virtual void setFirstRow(const ::cell_t *cells, int j, int len) = 0 ;
    virtual void setFirstColumn(const ::cell_t *cells, int i, int len) = 0 ;
    virtual void clearPrunedBlocks(int b0, int b1) = 0 ;
    virtual void initializeDiagonals() = 0 ;
    virtual void processDiagonal(int diagonal, int windowLeft, int windowRight) = 0 ;
    virtual void finalizeDiagonals() = 0 ;
    ::Partition getPartition() const ;
  private:
    ::cell_t *h_loadColumn;
    int gridWidth;
    int gridHeight;
    int externalDiagonalCount;
    int currentExternalDiagonal;
    ::Partition partition;
    ::BlockPruningDiagonal *pruner;
    int windowStart;
    int windowEnd;
    int statTotalBlocks;
    int statPrunedBlocksLeft;
    int statPrunedBlocksRight;
    long long int statTotalCells;
    int statMinGridWidth;
    int statMaxGridWidth;
    ::Grid *configureGrid(::Partition partition);
    void prepareIterations();
    void processNextIteration();
    bool hasMoreIterations();
    void finalizeIterations();
    void flushSpecialRows();
    void flushLastRow();
    void flushLastColumn();
    void flushLastCell();
    void flushBlockScores();
    void loadFirstRow();
    void loadFirstColumn();
    bool isSpecialRow(int by);
    void pruneBlocks();
  public:
};
namespace std __attribute__((__visibility__("default"))) {
  template < typename _T1, typename _T2 >
  inline void _Construct(_T1 *__p, const _T2 &__value);
  template < typename _T1, typename _T2 >
  inline void _Construct(_T1 *__p, const _T2 &__value)
  {
    ::new (static_cast<void *>(__p))_T1(__value);
  }
  template < typename _T1 >
  inline void _Construct_novalue(_T1 *__p);
  template < typename _T1 >
  inline void _Construct_novalue(_T1 *__p)
  {
    ::new (static_cast<void *>(__p))_T1();
  }
  template < typename _Tp >
  inline void _Destroy(_Tp *__pointer);
  template < typename _Tp >
  inline void _Destroy(_Tp *__pointer)
  {
    __pointer->~_Tp();
  }
  template < bool __nontype_tpl_param_1_0__ >
  struct  _Destroy_aux
  {
      template < typename _ForwardIterator >
      static inline void __destroy(_ForwardIterator __first, _ForwardIterator __last)
      {
        for (; __first != __last;  ++__first)
          {
            std::_Destroy(std::__addressof(*__first));
          }
      }
  };
  template <>
  struct  _Destroy_aux<true>
  {
      template < typename _ForwardIterator >
      static inline void __destroy(_ForwardIterator, _ForwardIterator)
      {
      }
  };
  template < typename _ForwardIterator >
  inline void _Destroy(_ForwardIterator __first, _ForwardIterator __last);
  template < typename _ForwardIterator >
  inline void _Destroy(_ForwardIterator __first, _ForwardIterator __last)
  {
    typedef typename ::std::iterator_traits<_ForwardIterator>::value_type _Value_type;
    std::_Destroy_aux<__has_trivial_destructor(_Value_type)>::__destroy(__first, __last);
  }
  template < bool __nontype_tpl_param_1_0__ >
  struct  _Destroy_n_aux
  {
      template < typename _ForwardIterator, typename _Size >
      static inline _ForwardIterator __destroy_n(_ForwardIterator __first, _Size __count)
      {
        for (; __count > 0; ((void) ++__first,  --__count))
          {
            std::_Destroy(std::__addressof(*__first));
          }
        return __first;
      }
  };
  template <>
  struct  _Destroy_n_aux<true>
  {
      template < typename _ForwardIterator, typename _Size >
      static inline _ForwardIterator __destroy_n(_ForwardIterator __first, _Size __count)
      {
        std::advance(__first, __count);
        return __first;
      }
  };
  template < typename _ForwardIterator, typename _Size >
  inline _ForwardIterator _Destroy_n(_ForwardIterator __first, _Size __count);
  template < typename _ForwardIterator, typename _Size >
  inline _ForwardIterator _Destroy_n(_ForwardIterator __first, _Size __count)
  {
    typedef typename ::std::iterator_traits<_ForwardIterator>::value_type _Value_type;
    return std::_Destroy_n_aux<__has_trivial_destructor(_Value_type)>::__destroy_n(__first, __count);
  }
  template < typename _ForwardIterator, typename _Allocator >
  void _Destroy(_ForwardIterator __first, _ForwardIterator __last, _Allocator &__alloc);
  template < typename _ForwardIterator, typename _Allocator >
  void _Destroy(_ForwardIterator __first, _ForwardIterator __last, _Allocator &__alloc)
  {
    typedef ::__gnu_cxx::__alloc_traits<_Allocator> __traits;
    for (; __first != __last;  ++__first)
      {
        __traits::destroy(__alloc, std::__addressof(*__first));
      }
  }
  template < typename _ForwardIterator, typename _Tp >
  inline void _Destroy(_ForwardIterator __first, _ForwardIterator __last, ::std::allocator<_Tp> &);
  template < typename _ForwardIterator, typename _Tp >
  inline void _Destroy(_ForwardIterator __first, _ForwardIterator __last, ::std::allocator<_Tp> &)
  {
    _Destroy(__first, __last);
  }
  template < bool _TrivialValueTypes >
  struct  __uninitialized_copy
  {
      template < typename _InputIterator, typename _ForwardIterator >
      static inline _ForwardIterator __uninit_copy(_InputIterator __first, _InputIterator __last, _ForwardIterator __result)
      {
        _ForwardIterator __cur = __result;
        try
        {
          for (; __first != __last; ( ++__first, (void) ++__cur))
            {
              std::_Construct(std::__addressof(*__cur), *__first);
            }
          return __cur;
        }
        catch (...)
        {
          std::_Destroy(__result, __cur);
          throw;
        }
      }
  };
  template <>
  struct  __uninitialized_copy<true>
  {
      template < typename _InputIterator, typename _ForwardIterator >
      static inline _ForwardIterator __uninit_copy(_InputIterator __first, _InputIterator __last, _ForwardIterator __result)
      {
        return std::copy(__first, __last, __result);
      }
  };
  template < typename _InputIterator, typename _ForwardIterator >
  inline _ForwardIterator uninitialized_copy(_InputIterator __first, _InputIterator __last, _ForwardIterator __result);
  template < typename _InputIterator, typename _ForwardIterator >
  inline _ForwardIterator uninitialized_copy(_InputIterator __first, _InputIterator __last, _ForwardIterator __result)
  {
    typedef typename ::std::iterator_traits<_InputIterator>::value_type _ValueType1;
    typedef typename ::std::iterator_traits<_ForwardIterator>::value_type _ValueType2;
    const bool __assignable(true);
    return std::__uninitialized_copy<((__is_trivial(_ValueType1)) && (__is_trivial(_ValueType2))) && __assignable>::__uninit_copy(__first, __last, __result);
  }
  template < bool _TrivialValueType >
  struct  __uninitialized_fill
  {
      template < typename _ForwardIterator, typename _Tp >
      static inline void __uninit_fill(_ForwardIterator __first, _ForwardIterator __last, const _Tp &__x)
      {
        _ForwardIterator __cur = __first;
        try
        {
          for (; __cur != __last;  ++__cur)
            {
              std::_Construct(std::__addressof(*__cur), __x);
            }
        }
        catch (...)
        {
          std::_Destroy(__first, __cur);
          throw;
        }
      }
  };
  template <>
  struct  __uninitialized_fill<true>
  {
      template < typename _ForwardIterator, typename _Tp >
      static inline void __uninit_fill(_ForwardIterator __first, _ForwardIterator __last, const _Tp &__x)
      {
        std::fill(__first, __last, __x);
      }
  };
  template < typename _ForwardIterator, typename _Tp >
  inline void uninitialized_fill(_ForwardIterator __first, _ForwardIterator __last, const _Tp &__x);
  template < typename _ForwardIterator, typename _Tp >
  inline void uninitialized_fill(_ForwardIterator __first, _ForwardIterator __last, const _Tp &__x)
  {
    typedef typename ::std::iterator_traits<_ForwardIterator>::value_type _ValueType;
    const bool __assignable(true);
    std::__uninitialized_fill<(__is_trivial(_ValueType)) && __assignable>::__uninit_fill(__first, __last, __x);
  }
  template < bool _TrivialValueType >
  struct  __uninitialized_fill_n
  {
      template < typename _ForwardIterator, typename _Size, typename _Tp >
      static inline _ForwardIterator __uninit_fill_n(_ForwardIterator __first, _Size __n, const _Tp &__x)
      {
        _ForwardIterator __cur = __first;
        try
        {
          for (; __n > 0; ( --__n,  ++__cur))
            {
              std::_Construct(std::__addressof(*__cur), __x);
            }
          return __cur;
        }
        catch (...)
        {
          std::_Destroy(__first, __cur);
          throw;
        }
      }
  };
  template <>
  struct  __uninitialized_fill_n<true>
  {
      template < typename _ForwardIterator, typename _Size, typename _Tp >
      static inline _ForwardIterator __uninit_fill_n(_ForwardIterator __first, _Size __n, const _Tp &__x)
      {
        return std::fill_n(__first, __n, __x);
      }
  };
  template < typename _ForwardIterator, typename _Size, typename _Tp >
  inline _ForwardIterator uninitialized_fill_n(_ForwardIterator __first, _Size __n, const _Tp &__x);
  template < typename _ForwardIterator, typename _Size, typename _Tp >
  inline _ForwardIterator uninitialized_fill_n(_ForwardIterator __first, _Size __n, const _Tp &__x)
  {
    typedef typename ::std::iterator_traits<_ForwardIterator>::value_type _ValueType;
    const bool __assignable(true);
    return __uninitialized_fill_n<(__is_trivial(_ValueType)) && __assignable>::__uninit_fill_n(__first, __n, __x);
  }
  template < typename _InputIterator, typename _ForwardIterator, typename _Allocator >
  _ForwardIterator __uninitialized_copy_a(_InputIterator __first, _InputIterator __last, _ForwardIterator __result, _Allocator &__alloc);
  template < typename _InputIterator, typename _ForwardIterator, typename _Allocator >
  _ForwardIterator __uninitialized_copy_a(_InputIterator __first, _InputIterator __last, _ForwardIterator __result, _Allocator &__alloc)
  {
    _ForwardIterator __cur = __result;
    try
    {
      typedef ::__gnu_cxx::__alloc_traits<_Allocator> __traits;
      for (; __first != __last; ( ++__first, (void) ++__cur))
        {
          __traits::construct(__alloc, std::__addressof(*__cur), *__first);
        }
      return __cur;
    }
    catch (...)
    {
      std::_Destroy(__result, __cur, __alloc);
      throw;
    }
  }
  template < typename _InputIterator, typename _ForwardIterator, typename _Tp >
  inline _ForwardIterator __uninitialized_copy_a(_InputIterator __first, _InputIterator __last, _ForwardIterator __result, ::std::allocator<_Tp> &);
  template < typename _InputIterator, typename _ForwardIterator, typename _Tp >
  inline _ForwardIterator __uninitialized_copy_a(_InputIterator __first, _InputIterator __last, _ForwardIterator __result, ::std::allocator<_Tp> &)
  {
    return std::uninitialized_copy(__first, __last, __result);
  }
  template < typename _InputIterator, typename _ForwardIterator, typename _Allocator >
  inline _ForwardIterator __uninitialized_move_a(_InputIterator __first, _InputIterator __last, _ForwardIterator __result, _Allocator &__alloc);
  template < typename _InputIterator, typename _ForwardIterator, typename _Allocator >
  inline _ForwardIterator __uninitialized_move_a(_InputIterator __first, _InputIterator __last, _ForwardIterator __result, _Allocator &__alloc)
  {
    return std::__uninitialized_copy_a(__first, __last, __result, __alloc);
  }
  template < typename _InputIterator, typename _ForwardIterator, typename _Allocator >
  inline _ForwardIterator __uninitialized_move_if_noexcept_a(_InputIterator __first, _InputIterator __last, _ForwardIterator __result, _Allocator &__alloc);
  template < typename _InputIterator, typename _ForwardIterator, typename _Allocator >
  inline _ForwardIterator __uninitialized_move_if_noexcept_a(_InputIterator __first, _InputIterator __last, _ForwardIterator __result, _Allocator &__alloc)
  {
    return std::__uninitialized_copy_a(__first, __last, __result, __alloc);
  }
  template < typename _ForwardIterator, typename _Tp, typename _Allocator >
  void __uninitialized_fill_a(_ForwardIterator __first, _ForwardIterator __last, const _Tp &__x, _Allocator &__alloc);
  template < typename _ForwardIterator, typename _Tp, typename _Allocator >
  void __uninitialized_fill_a(_ForwardIterator __first, _ForwardIterator __last, const _Tp &__x, _Allocator &__alloc)
  {
    _ForwardIterator __cur = __first;
    try
    {
      typedef ::__gnu_cxx::__alloc_traits<_Allocator> __traits;
      for (; __cur != __last;  ++__cur)
        {
          __traits::construct(__alloc, std::__addressof(*__cur), __x);
        }
    }
    catch (...)
    {
      std::_Destroy(__first, __cur, __alloc);
      throw;
    }
  }
  template < typename _ForwardIterator, typename _Tp, typename _Tp2 >
  inline void __uninitialized_fill_a(_ForwardIterator __first, _ForwardIterator __last, const _Tp &__x, ::std::allocator<_Tp2> &);
  template < typename _ForwardIterator, typename _Tp, typename _Tp2 >
  inline void __uninitialized_fill_a(_ForwardIterator __first, _ForwardIterator __last, const _Tp &__x, ::std::allocator<_Tp2> &)
  {
    std::uninitialized_fill(__first, __last, __x);
  }
  template < typename _ForwardIterator, typename _Size, typename _Tp, typename _Allocator >
  _ForwardIterator __uninitialized_fill_n_a(_ForwardIterator __first, _Size __n, const _Tp &__x, _Allocator &__alloc);
  template < typename _ForwardIterator, typename _Size, typename _Tp, typename _Allocator >
  _ForwardIterator __uninitialized_fill_n_a(_ForwardIterator __first, _Size __n, const _Tp &__x, _Allocator &__alloc)
  {
    _ForwardIterator __cur = __first;
    try
    {
      typedef ::__gnu_cxx::__alloc_traits<_Allocator> __traits;
      for (; __n > 0; ( --__n,  ++__cur))
        {
          __traits::construct(__alloc, std::__addressof(*__cur), __x);
        }
      return __cur;
    }
    catch (...)
    {
      std::_Destroy(__first, __cur, __alloc);
      throw;
    }
  }
  template < typename _ForwardIterator, typename _Size, typename _Tp, typename _Tp2 >
  inline _ForwardIterator __uninitialized_fill_n_a(_ForwardIterator __first, _Size __n, const _Tp &__x, ::std::allocator<_Tp2> &);
  template < typename _ForwardIterator, typename _Size, typename _Tp, typename _Tp2 >
  inline _ForwardIterator __uninitialized_fill_n_a(_ForwardIterator __first, _Size __n, const _Tp &__x, ::std::allocator<_Tp2> &)
  {
    return std::uninitialized_fill_n(__first, __n, __x);
  }
  template < typename _InputIterator1, typename _InputIterator2, typename _ForwardIterator, typename _Allocator >
  inline _ForwardIterator __uninitialized_copy_move(_InputIterator1 __first1, _InputIterator1 __last1, _InputIterator2 __first2, _InputIterator2 __last2, _ForwardIterator __result, _Allocator &__alloc);
  template < typename _InputIterator1, typename _InputIterator2, typename _ForwardIterator, typename _Allocator >
  inline _ForwardIterator __uninitialized_copy_move(_InputIterator1 __first1, _InputIterator1 __last1, _InputIterator2 __first2, _InputIterator2 __last2, _ForwardIterator __result, _Allocator &__alloc)
  {
    _ForwardIterator __mid = std::__uninitialized_copy_a(__first1, __last1, __result, __alloc);
    try
    {
      return std::__uninitialized_move_a(__first2, __last2, __mid, __alloc);
    }
    catch (...)
    {
      std::_Destroy(__result, __mid, __alloc);
      throw;
    }
  }
  template < typename _InputIterator1, typename _InputIterator2, typename _ForwardIterator, typename _Allocator >
  inline _ForwardIterator __uninitialized_move_copy(_InputIterator1 __first1, _InputIterator1 __last1, _InputIterator2 __first2, _InputIterator2 __last2, _ForwardIterator __result, _Allocator &__alloc);
  template < typename _InputIterator1, typename _InputIterator2, typename _ForwardIterator, typename _Allocator >
  inline _ForwardIterator __uninitialized_move_copy(_InputIterator1 __first1, _InputIterator1 __last1, _InputIterator2 __first2, _InputIterator2 __last2, _ForwardIterator __result, _Allocator &__alloc)
  {
    _ForwardIterator __mid = std::__uninitialized_move_a(__first1, __last1, __result, __alloc);
    try
    {
      return std::__uninitialized_copy_a(__first2, __last2, __mid, __alloc);
    }
    catch (...)
    {
      std::_Destroy(__result, __mid, __alloc);
      throw;
    }
  }
  template < typename _ForwardIterator, typename _Tp, typename _InputIterator, typename _Allocator >
  inline _ForwardIterator __uninitialized_fill_move(_ForwardIterator __result, _ForwardIterator __mid, const _Tp &__x, _InputIterator __first, _InputIterator __last, _Allocator &__alloc);
  template < typename _ForwardIterator, typename _Tp, typename _InputIterator, typename _Allocator >
  inline _ForwardIterator __uninitialized_fill_move(_ForwardIterator __result, _ForwardIterator __mid, const _Tp &__x, _InputIterator __first, _InputIterator __last, _Allocator &__alloc)
  {
    std::__uninitialized_fill_a(__result, __mid, __x, __alloc);
    try
    {
      return std::__uninitialized_move_a(__first, __last, __mid, __alloc);
    }
    catch (...)
    {
      std::_Destroy(__result, __mid, __alloc);
      throw;
    }
  }
  template < typename _InputIterator, typename _ForwardIterator, typename _Tp, typename _Allocator >
  inline void __uninitialized_move_fill(_InputIterator __first1, _InputIterator __last1, _ForwardIterator __first2, _ForwardIterator __last2, const _Tp &__x, _Allocator &__alloc);
  template < typename _InputIterator, typename _ForwardIterator, typename _Tp, typename _Allocator >
  inline void __uninitialized_move_fill(_InputIterator __first1, _InputIterator __last1, _ForwardIterator __first2, _ForwardIterator __last2, const _Tp &__x, _Allocator &__alloc)
  {
    _ForwardIterator __mid2 = std::__uninitialized_move_a(__first1, __last1, __first2, __alloc);
    try
    {
      std::__uninitialized_fill_a(__mid2, __last2, __x, __alloc);
    }
    catch (...)
    {
      std::_Destroy(__first2, __mid2, __alloc);
      throw;
    }
  }
  inline ::std::size_t __deque_buf_size(::std::size_t __size)
  {
    return __size < 512 ? (::std::size_t)(512 / __size) : (::std::size_t)1;
  }
  template < typename _Tp, typename _Ref, typename _Ptr >
  struct  _Deque_iterator
  {
      typedef ::std::_Deque_iterator<_Tp, _Tp &, _Tp *> iterator;
      typedef ::std::_Deque_iterator<_Tp, const _Tp &, const _Tp *> const_iterator;
      typedef _Tp *_Elt_pointer;
      typedef _Tp **_Map_pointer;
      static inline ::std::size_t _S_buffer_size()
      {
        return ::std::__deque_buf_size(sizeof(_Tp));
      }
      typedef ::std::random_access_iterator_tag iterator_category;
      typedef _Tp value_type;
      typedef _Ptr pointer;
      typedef _Ref reference;
      typedef ::std::size_t size_type;
      typedef ::std::ptrdiff_t difference_type;
      typedef ::std::_Deque_iterator<_Tp, _Ref, _Ptr> _Self;
      typename ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::_Elt_pointer _M_cur;
      typename ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::_Elt_pointer _M_first;
      typename ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::_Elt_pointer _M_last;
      typename ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::_Map_pointer _M_node;
      inline _Deque_iterator(typename ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::_Elt_pointer __x, typename ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::_Map_pointer __y)
        : _M_cur(__x), _M_first(*__y), _M_last(*__y + _S_buffer_size()), _M_node(__y)
      {
      }
      inline _Deque_iterator()
        : _M_cur(), _M_first(), _M_last(), _M_node()
      {
      }
      inline _Deque_iterator(const typename ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::iterator &__x)
        : _M_cur(__x._M_cur), _M_first(__x._M_first), _M_last(__x._M_last), _M_node(__x._M_node)
      {
      }
      inline typename ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::iterator _M_const_cast() const 
      {
        return ((typename ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::iterator(::std::_Deque_iterator<_Tp, _Ref, _Ptr>::_M_cur, ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::_M_node)));
      }
      inline typename ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::reference operator *() const 
      {
        return *::std::_Deque_iterator<_Tp, _Ref, _Ptr>::_M_cur;
      }
      inline typename ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::pointer operator ->() const 
      {
        return ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::_M_cur;
      }
      inline typename ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::_Self &operator ++()
      {
         ++::std::_Deque_iterator<_Tp, _Ref, _Ptr>::_M_cur;
        if (::std::_Deque_iterator<_Tp, _Ref, _Ptr>::_M_cur == ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::_M_last)
          {
            (*this)._M_set_node(::std::_Deque_iterator<_Tp, _Ref, _Ptr>::_M_node + 1);
            ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::_M_cur = ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::_M_first;
          }
        return *this;
      }
      inline typename ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::_Self operator ++(int)
      {
        typename ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::_Self __tmp = *this;
         ++*this;
        return __tmp;
      }
      inline typename ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::_Self &operator --()
      {
        if (::std::_Deque_iterator<_Tp, _Ref, _Ptr>::_M_cur == ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::_M_first)
          {
            (*this)._M_set_node(::std::_Deque_iterator<_Tp, _Ref, _Ptr>::_M_node - 1);
            ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::_M_cur = ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::_M_last;
          }
         --::std::_Deque_iterator<_Tp, _Ref, _Ptr>::_M_cur;
        return *this;
      }
      inline typename ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::_Self operator --(int)
      {
        typename ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::_Self __tmp = *this;
         --*this;
        return __tmp;
      }
      inline typename ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::_Self &operator +=(typename ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::difference_type __n)
      {
        const typename ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::difference_type __offset = __n + (::std::_Deque_iterator<_Tp, _Ref, _Ptr>::_M_cur - ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::_M_first);
        if (__offset >= 0 && __offset < long(_S_buffer_size()))
          {
            ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::_M_cur += __n;
          }
        else
          {
            const typename ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::difference_type __node_offset = __offset > 0 ? __offset / long(_S_buffer_size()) :  -long(( -__offset - 1) / _S_buffer_size()) - 1;
            (*this)._M_set_node(::std::_Deque_iterator<_Tp, _Ref, _Ptr>::_M_node + __node_offset);
            ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::_M_cur = ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::_M_first + (__offset - __node_offset * long(_S_buffer_size()));
          }
        return *this;
      }
      inline typename ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::_Self operator +(typename ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::difference_type __n) const 
      {
        typename ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::_Self __tmp = *this;
        return __tmp += __n;
      }
      inline typename ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::_Self &operator -=(typename ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::difference_type __n)
      {
        return *this +=  -__n;
      }
      inline typename ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::_Self operator -(typename ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::difference_type __n) const 
      {
        typename ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::_Self __tmp = *this;
        return __tmp -= __n;
      }
      inline typename ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::reference operator [](typename ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::difference_type __n) const 
      {
        return *(*this + __n);
      }
      inline void _M_set_node(typename ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::_Map_pointer __new_node)
      {
        ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::_M_node = __new_node;
        ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::_M_first = *__new_node;
        ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::_M_last = ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::_M_first + long(_S_buffer_size());
      }
  };
  template < typename _Tp, typename _Ref, typename _Ptr >
  inline bool operator ==(const ::std::_Deque_iterator<_Tp, _Ref, _Ptr> &__x, const ::std::_Deque_iterator<_Tp, _Ref, _Ptr> &__y);
  template < typename _Tp, typename _Ref, typename _Ptr >
  inline bool operator ==(const ::std::_Deque_iterator<_Tp, _Ref, _Ptr> &__x, const ::std::_Deque_iterator<_Tp, _Ref, _Ptr> &__y)
  {
    return __x._M_cur == __y._M_cur;
  }
  template < typename _Tp, typename _RefL, typename _PtrL, typename _RefR, typename _PtrR >
  inline bool operator ==(const ::std::_Deque_iterator<_Tp, _RefL, _PtrL> &__x, const ::std::_Deque_iterator<_Tp, _RefR, _PtrR> &__y);
  template < typename _Tp, typename _RefL, typename _PtrL, typename _RefR, typename _PtrR >
  inline bool operator ==(const ::std::_Deque_iterator<_Tp, _RefL, _PtrL> &__x, const ::std::_Deque_iterator<_Tp, _RefR, _PtrR> &__y)
  {
    return __x._M_cur == __y._M_cur;
  }
  template < typename _Tp, typename _Ref, typename _Ptr >
  inline bool operator !=(const ::std::_Deque_iterator<_Tp, _Ref, _Ptr> &__x, const ::std::_Deque_iterator<_Tp, _Ref, _Ptr> &__y);
  template < typename _Tp, typename _Ref, typename _Ptr >
  inline bool operator !=(const ::std::_Deque_iterator<_Tp, _Ref, _Ptr> &__x, const ::std::_Deque_iterator<_Tp, _Ref, _Ptr> &__y)
  {
    return !(__x == __y);
  }
  template < typename _Tp, typename _RefL, typename _PtrL, typename _RefR, typename _PtrR >
  inline bool operator !=(const ::std::_Deque_iterator<_Tp, _RefL, _PtrL> &__x, const ::std::_Deque_iterator<_Tp, _RefR, _PtrR> &__y);
  template < typename _Tp, typename _RefL, typename _PtrL, typename _RefR, typename _PtrR >
  inline bool operator !=(const ::std::_Deque_iterator<_Tp, _RefL, _PtrL> &__x, const ::std::_Deque_iterator<_Tp, _RefR, _PtrR> &__y)
  {
    return !(__x == __y);
  }
  template < typename _Tp, typename _Ref, typename _Ptr >
  inline bool operator <(const ::std::_Deque_iterator<_Tp, _Ref, _Ptr> &__x, const ::std::_Deque_iterator<_Tp, _Ref, _Ptr> &__y);
  template < typename _Tp, typename _Ref, typename _Ptr >
  inline bool operator <(const ::std::_Deque_iterator<_Tp, _Ref, _Ptr> &__x, const ::std::_Deque_iterator<_Tp, _Ref, _Ptr> &__y)
  {
    return __x._M_node == __y._M_node ? __x._M_cur < __y._M_cur : __x._M_node < __y._M_node;
  }
  template < typename _Tp, typename _RefL, typename _PtrL, typename _RefR, typename _PtrR >
  inline bool operator <(const ::std::_Deque_iterator<_Tp, _RefL, _PtrL> &__x, const ::std::_Deque_iterator<_Tp, _RefR, _PtrR> &__y);
  template < typename _Tp, typename _RefL, typename _PtrL, typename _RefR, typename _PtrR >
  inline bool operator <(const ::std::_Deque_iterator<_Tp, _RefL, _PtrL> &__x, const ::std::_Deque_iterator<_Tp, _RefR, _PtrR> &__y)
  {
    return __x._M_node == __y._M_node ? __x._M_cur < __y._M_cur : __x._M_node < __y._M_node;
  }
  template < typename _Tp, typename _Ref, typename _Ptr >
  inline bool operator >(const ::std::_Deque_iterator<_Tp, _Ref, _Ptr> &__x, const ::std::_Deque_iterator<_Tp, _Ref, _Ptr> &__y);
  template < typename _Tp, typename _Ref, typename _Ptr >
  inline bool operator >(const ::std::_Deque_iterator<_Tp, _Ref, _Ptr> &__x, const ::std::_Deque_iterator<_Tp, _Ref, _Ptr> &__y)
  {
    return __y < __x;
  }
  template < typename _Tp, typename _RefL, typename _PtrL, typename _RefR, typename _PtrR >
  inline bool operator >(const ::std::_Deque_iterator<_Tp, _RefL, _PtrL> &__x, const ::std::_Deque_iterator<_Tp, _RefR, _PtrR> &__y);
  template < typename _Tp, typename _RefL, typename _PtrL, typename _RefR, typename _PtrR >
  inline bool operator >(const ::std::_Deque_iterator<_Tp, _RefL, _PtrL> &__x, const ::std::_Deque_iterator<_Tp, _RefR, _PtrR> &__y)
  {
    return __y < __x;
  }
  template < typename _Tp, typename _Ref, typename _Ptr >
  inline bool operator <=(const ::std::_Deque_iterator<_Tp, _Ref, _Ptr> &__x, const ::std::_Deque_iterator<_Tp, _Ref, _Ptr> &__y);
  template < typename _Tp, typename _Ref, typename _Ptr >
  inline bool operator <=(const ::std::_Deque_iterator<_Tp, _Ref, _Ptr> &__x, const ::std::_Deque_iterator<_Tp, _Ref, _Ptr> &__y)
  {
    return !(__y < __x);
  }
  template < typename _Tp, typename _RefL, typename _PtrL, typename _RefR, typename _PtrR >
  inline bool operator <=(const ::std::_Deque_iterator<_Tp, _RefL, _PtrL> &__x, const ::std::_Deque_iterator<_Tp, _RefR, _PtrR> &__y);
  template < typename _Tp, typename _RefL, typename _PtrL, typename _RefR, typename _PtrR >
  inline bool operator <=(const ::std::_Deque_iterator<_Tp, _RefL, _PtrL> &__x, const ::std::_Deque_iterator<_Tp, _RefR, _PtrR> &__y)
  {
    return !(__y < __x);
  }
  template < typename _Tp, typename _Ref, typename _Ptr >
  inline bool operator >=(const ::std::_Deque_iterator<_Tp, _Ref, _Ptr> &__x, const ::std::_Deque_iterator<_Tp, _Ref, _Ptr> &__y);
  template < typename _Tp, typename _Ref, typename _Ptr >
  inline bool operator >=(const ::std::_Deque_iterator<_Tp, _Ref, _Ptr> &__x, const ::std::_Deque_iterator<_Tp, _Ref, _Ptr> &__y)
  {
    return !(__x < __y);
  }
  template < typename _Tp, typename _RefL, typename _PtrL, typename _RefR, typename _PtrR >
  inline bool operator >=(const ::std::_Deque_iterator<_Tp, _RefL, _PtrL> &__x, const ::std::_Deque_iterator<_Tp, _RefR, _PtrR> &__y);
  template < typename _Tp, typename _RefL, typename _PtrL, typename _RefR, typename _PtrR >
  inline bool operator >=(const ::std::_Deque_iterator<_Tp, _RefL, _PtrL> &__x, const ::std::_Deque_iterator<_Tp, _RefR, _PtrR> &__y)
  {
    return !(__x < __y);
  }
  template < typename _Tp, typename _Ref, typename _Ptr >
  inline typename ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::difference_type operator -(const ::std::_Deque_iterator<_Tp, _Ref, _Ptr> &__x, const ::std::_Deque_iterator<_Tp, _Ref, _Ptr> &__y);
  template < typename _Tp, typename _Ref, typename _Ptr >
  inline typename ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::difference_type operator -(const ::std::_Deque_iterator<_Tp, _Ref, _Ptr> &__x, const ::std::_Deque_iterator<_Tp, _Ref, _Ptr> &__y)
  {
    return typename ::std::_Deque_iterator<_Tp, _Ref, _Ptr>::difference_type(_Deque_iterator<_Tp, _Ref, _Ptr>::_S_buffer_size()) * (__x._M_node - __y._M_node - 1) + (__x._M_cur - __x._M_first) + (__y._M_last - __y._M_cur);
  }
  template < typename _Tp, typename _RefL, typename _PtrL, typename _RefR, typename _PtrR >
  inline typename ::std::_Deque_iterator<_Tp, _RefL, _PtrL>::difference_type operator -(const ::std::_Deque_iterator<_Tp, _RefL, _PtrL> &__x, const ::std::_Deque_iterator<_Tp, _RefR, _PtrR> &__y);
  template < typename _Tp, typename _RefL, typename _PtrL, typename _RefR, typename _PtrR >
  inline typename ::std::_Deque_iterator<_Tp, _RefL, _PtrL>::difference_type operator -(const ::std::_Deque_iterator<_Tp, _RefL, _PtrL> &__x, const ::std::_Deque_iterator<_Tp, _RefR, _PtrR> &__y)
  {
    return typename ::std::_Deque_iterator<_Tp, _RefL, _PtrL>::difference_type(_Deque_iterator<_Tp, _RefL, _PtrL>::_S_buffer_size()) * (__x._M_node - __y._M_node - 1) + (__x._M_cur - __x._M_first) + (__y._M_last - __y._M_cur);
  }
  template < typename _Tp, typename _Ref, typename _Ptr >
  inline ::std::_Deque_iterator<_Tp, _Ref, _Ptr> operator +(::std::ptrdiff_t __n, const ::std::_Deque_iterator<_Tp, _Ref, _Ptr> &__x);
  template < typename _Tp, typename _Ref, typename _Ptr >
  inline ::std::_Deque_iterator<_Tp, _Ref, _Ptr> operator +(::std::ptrdiff_t __n, const ::std::_Deque_iterator<_Tp, _Ref, _Ptr> &__x)
  {
    return __x + __n;
  }
  template < typename _Tp >
  void fill(const ::std::_Deque_iterator<_Tp, _Tp &, _Tp *> &__first, const ::std::_Deque_iterator<_Tp, _Tp &, _Tp *> &__last, const _Tp &__value);
  template < typename _Tp >
  ::std::_Deque_iterator<_Tp, _Tp &, _Tp *> copy(::std::_Deque_iterator<_Tp, const _Tp &, const _Tp *> __first, ::std::_Deque_iterator<_Tp, const _Tp &, const _Tp *> __last, ::std::_Deque_iterator<_Tp, _Tp &, _Tp *> __result);
  template < typename _Tp >
  inline ::std::_Deque_iterator<_Tp, _Tp &, _Tp *> copy(::std::_Deque_iterator<_Tp, _Tp &, _Tp *> __first, ::std::_Deque_iterator<_Tp, _Tp &, _Tp *> __last, ::std::_Deque_iterator<_Tp, _Tp &, _Tp *> __result);
  template < typename _Tp >
  inline ::std::_Deque_iterator<_Tp, _Tp &, _Tp *> copy(::std::_Deque_iterator<_Tp, _Tp &, _Tp *> __first, ::std::_Deque_iterator<_Tp, _Tp &, _Tp *> __last, ::std::_Deque_iterator<_Tp, _Tp &, _Tp *> __result)
  {
    return std::copy(::std::_Deque_iterator<_Tp, const _Tp &, const _Tp *>(__first), ::std::_Deque_iterator<_Tp, const _Tp &, const _Tp *>(__last), __result);
  }
  template < typename _Tp >
  ::std::_Deque_iterator<_Tp, _Tp &, _Tp *> copy_backward(::std::_Deque_iterator<_Tp, const _Tp &, const _Tp *> __first, ::std::_Deque_iterator<_Tp, const _Tp &, const _Tp *> __last, ::std::_Deque_iterator<_Tp, _Tp &, _Tp *> __result);
  template < typename _Tp >
  inline ::std::_Deque_iterator<_Tp, _Tp &, _Tp *> copy_backward(::std::_Deque_iterator<_Tp, _Tp &, _Tp *> __first, ::std::_Deque_iterator<_Tp, _Tp &, _Tp *> __last, ::std::_Deque_iterator<_Tp, _Tp &, _Tp *> __result);
  template < typename _Tp >
  inline ::std::_Deque_iterator<_Tp, _Tp &, _Tp *> copy_backward(::std::_Deque_iterator<_Tp, _Tp &, _Tp *> __first, ::std::_Deque_iterator<_Tp, _Tp &, _Tp *> __last, ::std::_Deque_iterator<_Tp, _Tp &, _Tp *> __result)
  {
    return std::copy_backward(::std::_Deque_iterator<_Tp, const _Tp &, const _Tp *>(__first), ::std::_Deque_iterator<_Tp, const _Tp &, const _Tp *>(__last), __result);
  }
  template < typename _Tp, typename _Alloc >
  class  _Deque_base
  {
    protected:
      typedef typename ::__gnu_cxx::__alloc_traits<_Alloc>::template rebind< _Tp>::other _Tp_alloc_type;
      typedef ::__gnu_cxx::__alloc_traits<typename ::std::_Deque_base<_Tp, _Alloc>::_Tp_alloc_type> _Alloc_traits;
      typedef _Tp *_Ptr;
      typedef const _Tp *_Ptr_const;
      typedef typename ::__gnu_cxx::__alloc_traits<typename ::std::_Deque_base<_Tp, _Alloc>::_Tp_alloc_type>::template rebind< typename ::std::_Deque_base<_Tp, _Alloc>::_Ptr>::other _Map_alloc_type;
      typedef ::__gnu_cxx::__alloc_traits<typename ::std::_Deque_base<_Tp, _Alloc>::_Map_alloc_type> _Map_alloc_traits;
    public:
      typedef _Alloc allocator_type;
      typedef typename ::__gnu_cxx::__alloc_traits<typename ::std::_Deque_base<_Tp, _Alloc>::_Tp_alloc_type>::size_type size_type;
      inline typename ::std::_Deque_base<_Tp, _Alloc>::allocator_type get_allocator() const 
      {
        return ((typename ::std::_Deque_base<_Tp, _Alloc>::allocator_type((*this)._M_get_Tp_allocator())));
      }
      typedef ::std::_Deque_iterator<_Tp, _Tp &, typename ::std::_Deque_base<_Tp, _Alloc>::_Ptr> iterator;
      typedef ::std::_Deque_iterator<_Tp, const _Tp &, typename ::std::_Deque_base<_Tp, _Alloc>::_Ptr_const> const_iterator;
      inline _Deque_base()
        : _M_impl()
      {
        (*this)._M_initialize_map(0);
      }
      inline _Deque_base(::std::size_t __num_elements)
        : _M_impl()
      {
        (*this)._M_initialize_map(__num_elements);
      }
      inline _Deque_base(const typename ::std::_Deque_base<_Tp, _Alloc>::allocator_type &__a, ::std::size_t __num_elements)
        : _M_impl(__a)
      {
        (*this)._M_initialize_map(__num_elements);
      }
      inline _Deque_base(const typename ::std::_Deque_base<_Tp, _Alloc>::allocator_type &__a)
        : _M_impl(__a)
      {
      }
      ~_Deque_base();
    protected:
      typedef typename ::std::_Deque_iterator<_Tp, _Tp &, typename ::std::_Deque_base<_Tp, _Alloc>::_Ptr>::_Map_pointer _Map_pointer;
      struct  _Deque_impl : ::std::_Deque_base<_Tp, _Alloc>::_Tp_alloc_type
      {
          typename ::std::_Deque_base<_Tp, _Alloc>::_Map_pointer _M_map;
          ::std::size_t _M_map_size;
          typename ::std::_Deque_base<_Tp, _Alloc>::iterator _M_start;
          typename ::std::_Deque_base<_Tp, _Alloc>::iterator _M_finish;
          inline _Deque_impl()
            : _Tp_alloc_type(), _M_map(), _M_map_size(0), _M_start(), _M_finish()
          {
          }
          inline _Deque_impl(const typename ::std::_Deque_base<_Tp, _Alloc>::_Tp_alloc_type &__a)
            : _Tp_alloc_type(__a), _M_map(), _M_map_size(0), _M_start(), _M_finish()
          {
          }
          inline void _M_swap_data(typename ::std::_Deque_base<_Tp, _Alloc>::_Deque_impl &__x)
          {
            using ::std::swap;
            swap(this->_M_start, __x._M_start);
            swap(this->_M_finish, __x._M_finish);
            swap(this->_M_map, __x._M_map);
            swap(this->_M_map_size, __x._M_map_size);
          }
      };
      inline typename ::std::_Deque_base<_Tp, _Alloc>::_Tp_alloc_type &_M_get_Tp_allocator()
      {
        return *static_cast<typename ::std::_Deque_base<_Tp, _Alloc>::_Tp_alloc_type *>(&this->_M_impl);
      }
      inline const typename ::std::_Deque_base<_Tp, _Alloc>::_Tp_alloc_type &_M_get_Tp_allocator() const 
      {
        return *static_cast<const typename ::std::_Deque_base<_Tp, _Alloc>::_Tp_alloc_type *>(&this->_M_impl);
      }
      inline typename ::std::_Deque_base<_Tp, _Alloc>::_Map_alloc_type _M_get_map_allocator() const 
      {
        return ((typename ::std::_Deque_base<_Tp, _Alloc>::_Map_alloc_type((*this)._M_get_Tp_allocator())));
      }
      inline typename ::std::_Deque_base<_Tp, _Alloc>::_Ptr _M_allocate_node()
      {
        typedef ::__gnu_cxx::__alloc_traits<typename ::std::_Deque_base<_Tp, _Alloc>::_Tp_alloc_type> _Traits;
        return _Traits::allocate(::std::_Deque_base<_Tp, _Alloc>::_M_impl, ::std::__deque_buf_size(sizeof(_Tp)));
      }
      inline void _M_deallocate_node(typename ::std::_Deque_base<_Tp, _Alloc>::_Ptr __p)
      {
        typedef ::__gnu_cxx::__alloc_traits<typename ::std::_Deque_base<_Tp, _Alloc>::_Tp_alloc_type> _Traits;
        _Traits::deallocate(::std::_Deque_base<_Tp, _Alloc>::_M_impl, __p, ::std::__deque_buf_size(sizeof(_Tp)));
      }
      inline typename ::std::_Deque_base<_Tp, _Alloc>::_Map_pointer _M_allocate_map(::std::size_t __n)
      {
        typename ::std::_Deque_base<_Tp, _Alloc>::_Map_alloc_type __map_alloc = (*this)._M_get_map_allocator();
        return _Map_alloc_traits::allocate(__map_alloc, __n);
      }
      inline void _M_deallocate_map(typename ::std::_Deque_base<_Tp, _Alloc>::_Map_pointer __p, ::std::size_t __n)
      {
        typename ::std::_Deque_base<_Tp, _Alloc>::_Map_alloc_type __map_alloc = (*this)._M_get_map_allocator();
        _Map_alloc_traits::deallocate(__map_alloc, __p, __n);
      }
      void _M_initialize_map(::std::size_t __num_elements);
      void _M_create_nodes(typename ::std::_Deque_base<_Tp, _Alloc>::_Map_pointer __nstart, typename ::std::_Deque_base<_Tp, _Alloc>::_Map_pointer __nfinish);
      void _M_destroy_nodes(typename ::std::_Deque_base<_Tp, _Alloc>::_Map_pointer __nstart, typename ::std::_Deque_base<_Tp, _Alloc>::_Map_pointer __nfinish);
      enum mcc_enum_anon_53
      {
        _S_initial_map_size = 8
      };
      typename ::std::_Deque_base<_Tp, _Alloc>::_Deque_impl _M_impl;
  };
  template < typename _Tp, typename _Alloc >
  _Deque_base<_Tp, _Alloc>::~_Deque_base()
  {
    if (this->_M_impl._M_map)
      {
        (*this)._M_destroy_nodes(this->_M_impl._M_start._M_node, this->_M_impl._M_finish._M_node + 1);
        (*this)._M_deallocate_map(this->_M_impl._M_map, this->_M_impl._M_map_size);
      }
  }
  template < typename _Tp, typename _Alloc >
  void _Deque_base<_Tp, _Alloc>::_M_initialize_map(::std::size_t __num_elements)
  {
    const ::std::size_t __num_nodes = __num_elements / ::std::__deque_buf_size(sizeof(_Tp)) + 1;
    this->_M_impl._M_map_size = std::max((::std::size_t)::std::_Deque_base<_Tp, _Alloc>::_S_initial_map_size, (::std::size_t)(__num_nodes + 2));
    this->_M_impl._M_map = (*this)._M_allocate_map(this->_M_impl._M_map_size);
    typename ::std::_Deque_base<_Tp, _Alloc>::_Map_pointer __nstart = (this->_M_impl._M_map + (this->_M_impl._M_map_size - __num_nodes) / 2);
    typename ::std::_Deque_base<_Tp, _Alloc>::_Map_pointer __nfinish = __nstart + __num_nodes;
    try
    {
      (*this)._M_create_nodes(__nstart, __nfinish);
    }
    catch (...)
    {
      (*this)._M_deallocate_map(this->_M_impl._M_map, this->_M_impl._M_map_size);
      this->_M_impl._M_map = ((typename ::std::_Deque_base<_Tp, _Alloc>::_Map_pointer()));
      this->_M_impl._M_map_size = 0;
      throw;
    }
    this->_M_impl._M_start._M_set_node(__nstart);
    this->_M_impl._M_finish._M_set_node(__nfinish - 1);
    this->_M_impl._M_start._M_cur = ::std::_Deque_base<_Tp, _Alloc>::_M_impl._M_start._M_first;
    this->_M_impl._M_finish._M_cur = this->_M_impl._M_finish._M_first + __num_elements % ::std::__deque_buf_size(sizeof(_Tp));
  }
  template < typename _Tp, typename _Alloc >
  void _Deque_base<_Tp, _Alloc>::_M_create_nodes(typename ::std::_Deque_base<_Tp, _Alloc>::_Map_pointer __nstart, typename ::std::_Deque_base<_Tp, _Alloc>::_Map_pointer __nfinish)
  {
    typename ::std::_Deque_base<_Tp, _Alloc>::_Map_pointer __cur;
    try
    {
      for (__cur = __nstart; __cur < __nfinish;  ++__cur)
        {
          *__cur = this->_M_allocate_node();
        }
    }
    catch (...)
    {
      (*this)._M_destroy_nodes(__nstart, __cur);
      throw;
    }
  }
  template < typename _Tp, typename _Alloc >
  void _Deque_base<_Tp, _Alloc>::_M_destroy_nodes(typename ::std::_Deque_base<_Tp, _Alloc>::_Map_pointer __nstart, typename ::std::_Deque_base<_Tp, _Alloc>::_Map_pointer __nfinish)
  {
    for (typename ::std::_Deque_base<_Tp, _Alloc>::_Map_pointer __n = __nstart; __n < __nfinish;  ++__n)
      {
        (*this)._M_deallocate_node(*__n);
      }
  }
  template < typename _Tp, typename _Alloc = ::std::allocator<_Tp> >
  class  deque : protected ::std::_Deque_base<_Tp, _Alloc>
  {
      typedef ::std::_Deque_base<_Tp, _Alloc> _Base;
      typedef typename ::std::_Deque_base<_Tp, _Alloc>::_Tp_alloc_type _Tp_alloc_type;
      typedef typename ::std::_Deque_base<_Tp, _Alloc>::_Alloc_traits _Alloc_traits;
      typedef typename ::std::_Deque_base<_Tp, _Alloc>::_Map_pointer _Map_pointer;
    public:
      typedef _Tp value_type;
      typedef typename ::std::_Deque_base<_Tp, _Alloc>::_Alloc_traits::pointer pointer;
      typedef typename ::std::_Deque_base<_Tp, _Alloc>::_Alloc_traits::const_pointer const_pointer;
      typedef typename ::std::_Deque_base<_Tp, _Alloc>::_Alloc_traits::reference reference;
      typedef typename ::std::_Deque_base<_Tp, _Alloc>::_Alloc_traits::const_reference const_reference;
      typedef typename ::std::_Deque_base<_Tp, _Alloc>::iterator iterator;
      typedef typename ::std::_Deque_base<_Tp, _Alloc>::const_iterator const_iterator;
      typedef ::std::reverse_iterator<typename ::std::deque<_Tp, _Alloc>::const_iterator> const_reverse_iterator;
      typedef ::std::reverse_iterator<typename ::std::deque<_Tp, _Alloc>::iterator> reverse_iterator;
      typedef ::std::size_t size_type;
      typedef ::std::ptrdiff_t difference_type;
      typedef _Alloc allocator_type;
    protected:
      static inline ::std::size_t _S_buffer_size()
      {
        return ::std::__deque_buf_size(sizeof(_Tp));
      }
      using _Base::_M_initialize_map;
      using _Base::_M_create_nodes;
      using _Base::_M_destroy_nodes;
      using _Base::_M_allocate_node;
      using _Base::_M_deallocate_node;
      using _Base::_M_allocate_map;
      using _Base::_M_deallocate_map;
      using _Base::_M_get_Tp_allocator;
      using _Base::_M_impl;
    public:
      inline deque()
        : _Base()
      {
      }
      inline explicit deque(const typename ::std::deque<_Tp, _Alloc>::allocator_type &__a)
        : _Base(__a, 0)
      {
      }
      inline explicit deque(typename ::std::deque<_Tp, _Alloc>::size_type __n, const typename ::std::deque<_Tp, _Alloc>::value_type &__value  = (((typename ::std::deque<_Tp, _Alloc>::value_type()))), const typename ::std::deque<_Tp, _Alloc>::allocator_type &__a  = (((typename ::std::deque<_Tp, _Alloc>::allocator_type()))))
        : _Base(__a, __n)
      {
        (*this)._M_fill_initialize(__value);
      }
      inline deque(const ::std::deque<_Tp, _Alloc> &__x)
        : _Base(_Alloc_traits::_S_select_on_copy(__x._M_get_Tp_allocator()), __x.size())
      {
        std::__uninitialized_copy_a(__x.begin(), __x.end(), this->_M_impl._M_start, (_M_get_Tp_allocator)());
      }
      template < typename _InputIterator >
      inline deque(_InputIterator __first, _InputIterator __last, const typename ::std::deque<_Tp, _Alloc>::allocator_type &__a  = (((typename ::std::deque<_Tp, _Alloc>::allocator_type()))))
        : _Base(__a)
      {
        typedef typename ::std::__is_integer<_InputIterator>::__type _Integral;
        (*this)._M_initialize_dispatch(__first, __last, _Integral());
      }
      inline ~deque()
      {
        (*this)._M_destroy_data((*this).begin(), (*this).end(), (_M_get_Tp_allocator)());
      }
      ::std::deque<_Tp, _Alloc> &operator =(const ::std::deque<_Tp, _Alloc> &__x);
      inline void assign(typename ::std::deque<_Tp, _Alloc>::size_type __n, const typename ::std::deque<_Tp, _Alloc>::value_type &__val)
      {
        (*this)._M_fill_assign(__n, __val);
      }
      template < typename _InputIterator >
      inline void assign(_InputIterator __first, _InputIterator __last)
      {
        typedef typename ::std::__is_integer<_InputIterator>::__type _Integral;
        (*this)._M_assign_dispatch(__first, __last, _Integral());
      }
      inline typename ::std::deque<_Tp, _Alloc>::allocator_type get_allocator() const 
      {
        return _Base::get_allocator();
      }
      inline typename ::std::deque<_Tp, _Alloc>::iterator begin()
      {
        return this->_M_impl._M_start;
      }
      inline typename ::std::deque<_Tp, _Alloc>::const_iterator begin() const 
      {
        return this->_M_impl._M_start;
      }
      inline typename ::std::deque<_Tp, _Alloc>::iterator end()
      {
        return this->_M_impl._M_finish;
      }
      inline typename ::std::deque<_Tp, _Alloc>::const_iterator end() const 
      {
        return this->_M_impl._M_finish;
      }
      inline typename ::std::deque<_Tp, _Alloc>::reverse_iterator rbegin()
      {
        return ((typename ::std::deque<_Tp, _Alloc>::reverse_iterator(this->_M_impl._M_finish)));
      }
      inline typename ::std::deque<_Tp, _Alloc>::const_reverse_iterator rbegin() const 
      {
        return ((typename ::std::deque<_Tp, _Alloc>::const_reverse_iterator(this->_M_impl._M_finish)));
      }
      inline typename ::std::deque<_Tp, _Alloc>::reverse_iterator rend()
      {
        return ((typename ::std::deque<_Tp, _Alloc>::reverse_iterator(this->_M_impl._M_start)));
      }
      inline typename ::std::deque<_Tp, _Alloc>::const_reverse_iterator rend() const 
      {
        return ((typename ::std::deque<_Tp, _Alloc>::const_reverse_iterator(this->_M_impl._M_start)));
      }
      inline typename ::std::deque<_Tp, _Alloc>::size_type size() const 
      {
        return this->_M_impl._M_finish - this->_M_impl._M_start;
      }
      inline typename ::std::deque<_Tp, _Alloc>::size_type max_size() const 
      {
        return _Alloc_traits::max_size((_M_get_Tp_allocator)());
      }
      inline void resize(typename ::std::deque<_Tp, _Alloc>::size_type __new_size, typename ::std::deque<_Tp, _Alloc>::value_type __x  = (((typename ::std::deque<_Tp, _Alloc>::value_type()))))
      {
        const typename ::std::deque<_Tp, _Alloc>::size_type __len = (*this).size();
        if (__new_size > __len)
          {
            (*this)._M_fill_insert(this->_M_impl._M_finish, __new_size - __len, __x);
          }
        else
          {
            if (__new_size < __len)
              {
                (*this)._M_erase_at_end(this->_M_impl._M_start + (typename ::std::deque<_Tp, _Alloc>::difference_type)__new_size);
              }
          }
      }
      inline bool empty() const 
      {
        return this->_M_impl._M_finish == this->_M_impl._M_start;
      }
      inline typename ::std::deque<_Tp, _Alloc>::reference operator [](typename ::std::deque<_Tp, _Alloc>::size_type __n)
      {
        ;
        return this->_M_impl._M_start[(typename ::std::deque<_Tp, _Alloc>::difference_type)__n];
      }
      inline typename ::std::deque<_Tp, _Alloc>::const_reference operator [](typename ::std::deque<_Tp, _Alloc>::size_type __n) const 
      {
        ;
        return this->_M_impl._M_start[(typename ::std::deque<_Tp, _Alloc>::difference_type)__n];
      }
    protected:
      inline void _M_range_check(typename ::std::deque<_Tp, _Alloc>::size_type __n) const 
      {
        if (__n >= this->size())
          {
            __throw_out_of_range_fmt("deque::_M_range_check: __n (which is %zu)>= this->size() (which is %zu)", __n, this->size());
          }
      }
    public:
      inline typename ::std::deque<_Tp, _Alloc>::reference at(typename ::std::deque<_Tp, _Alloc>::size_type __n)
      {
        (*this)._M_range_check(__n);
        return (*this)[__n];
      }
      inline typename ::std::deque<_Tp, _Alloc>::const_reference at(typename ::std::deque<_Tp, _Alloc>::size_type __n) const 
      {
        (*this)._M_range_check(__n);
        return (*this)[__n];
      }
      inline typename ::std::deque<_Tp, _Alloc>::reference front()
      {
        ;
        return *(*this).begin();
      }
      inline typename ::std::deque<_Tp, _Alloc>::const_reference front() const 
      {
        ;
        return *(*this).begin();
      }
      inline typename ::std::deque<_Tp, _Alloc>::reference back()
      {
        ;
        typename ::std::deque<_Tp, _Alloc>::iterator __tmp = (*this).end();
         --__tmp;
        return *__tmp;
      }
      inline typename ::std::deque<_Tp, _Alloc>::const_reference back() const 
      {
        ;
        typename ::std::deque<_Tp, _Alloc>::const_iterator __tmp = (*this).end();
         --__tmp;
        return *__tmp;
      }
      inline void push_front(const typename ::std::deque<_Tp, _Alloc>::value_type &__x)
      {
        if (this->_M_impl._M_start._M_cur != this->_M_impl._M_start._M_first)
          {
            _Alloc_traits::construct(this->_M_impl, this->_M_impl._M_start._M_cur - 1, __x);
             --this->_M_impl._M_start._M_cur;
          }
        else
          {
            (*this)._M_push_front_aux(__x);
          }
      }
      inline void push_back(const typename ::std::deque<_Tp, _Alloc>::value_type &__x)
      {
        if (this->_M_impl._M_finish._M_cur != this->_M_impl._M_finish._M_last - 1)
          {
            _Alloc_traits::construct(this->_M_impl, this->_M_impl._M_finish._M_cur, __x);
             ++this->_M_impl._M_finish._M_cur;
          }
        else
          {
            (*this)._M_push_back_aux(__x);
          }
      }
      inline void pop_front()
      {
        ;
        if (this->_M_impl._M_start._M_cur != this->_M_impl._M_start._M_last - 1)
          {
            _Alloc_traits::destroy(this->_M_impl, this->_M_impl._M_start._M_cur);
             ++this->_M_impl._M_start._M_cur;
          }
        else
          {
            (*this)._M_pop_front_aux();
          }
      }
      inline void pop_back()
      {
        ;
        if (this->_M_impl._M_finish._M_cur != this->_M_impl._M_finish._M_first)
          {
             --this->_M_impl._M_finish._M_cur;
            _Alloc_traits::destroy(this->_M_impl, this->_M_impl._M_finish._M_cur);
          }
        else
          {
            (*this)._M_pop_back_aux();
          }
      }
      typename ::std::deque<_Tp, _Alloc>::iterator insert(typename ::std::deque<_Tp, _Alloc>::iterator __position, const typename ::std::deque<_Tp, _Alloc>::value_type &__x);
      inline void insert(typename ::std::deque<_Tp, _Alloc>::iterator __position, typename ::std::deque<_Tp, _Alloc>::size_type __n, const typename ::std::deque<_Tp, _Alloc>::value_type &__x)
      {
        (*this)._M_fill_insert(__position, __n, __x);
      }
      template < typename _InputIterator >
      inline void insert(typename ::std::deque<_Tp, _Alloc>::iterator __position, _InputIterator __first, _InputIterator __last)
      {
        typedef typename ::std::__is_integer<_InputIterator>::__type _Integral;
        (*this)._M_insert_dispatch(__position, __first, __last, _Integral());
      }
      inline typename ::std::deque<_Tp, _Alloc>::iterator erase(typename ::std::deque<_Tp, _Alloc>::iterator __position)
      {
        return (*this)._M_erase(__position._M_const_cast());
      }
      inline typename ::std::deque<_Tp, _Alloc>::iterator erase(typename ::std::deque<_Tp, _Alloc>::iterator __first, typename ::std::deque<_Tp, _Alloc>::iterator __last)
      {
        return (*this)._M_erase(__first._M_const_cast(), __last._M_const_cast());
      }
      inline void swap(::std::deque<_Tp, _Alloc> &__x)
      {
        _M_impl._M_swap_data(__x._M_impl);
        _Alloc_traits::_S_on_swap((_M_get_Tp_allocator)(), __x._M_get_Tp_allocator());
      }
      inline void clear()
      {
        (*this)._M_erase_at_end((*this).begin());
      }
    protected:
      template < typename _Integer >
      inline void _M_initialize_dispatch(_Integer __n, _Integer __x, ::std::__true_type)
      {
        (_M_initialize_map)(static_cast<typename ::std::deque<_Tp, _Alloc>::size_type>(__n));
        (*this)._M_fill_initialize(__x);
      }
      template < typename _InputIterator >
      inline void _M_initialize_dispatch(_InputIterator __first, _InputIterator __last, ::std::__false_type)
      {
        (*this)._M_range_initialize(__first, __last, std::__iterator_category(__first));
      }
      template < typename _InputIterator >
      void _M_range_initialize(_InputIterator __first, _InputIterator __last, ::std::input_iterator_tag);
      template < typename _ForwardIterator >
      void _M_range_initialize(_ForwardIterator __first, _ForwardIterator __last, ::std::forward_iterator_tag);
      void _M_fill_initialize(const typename ::std::deque<_Tp, _Alloc>::value_type &__value);
      template < typename _Integer >
      inline void _M_assign_dispatch(_Integer __n, _Integer __val, ::std::__true_type)
      {
        (*this)._M_fill_assign(__n, __val);
      }
      template < typename _InputIterator >
      inline void _M_assign_dispatch(_InputIterator __first, _InputIterator __last, ::std::__false_type)
      {
        (*this)._M_assign_aux(__first, __last, std::__iterator_category(__first));
      }
      template < typename _InputIterator >
      void _M_assign_aux(_InputIterator __first, _InputIterator __last, ::std::input_iterator_tag);
      template < typename _ForwardIterator >
      inline void _M_assign_aux(_ForwardIterator __first, _ForwardIterator __last, ::std::forward_iterator_tag)
      {
        const typename ::std::deque<_Tp, _Alloc>::size_type __len = std::distance(__first, __last);
        if (__len > (*this).size())
          {
            _ForwardIterator __mid = __first;
            std::advance(__mid, (*this).size());
            std::copy(__first, __mid, (*this).begin());
            (*this)._M_range_insert_aux((*this).end(), __mid, __last, std::__iterator_category(__first));
          }
        else
          {
            (*this)._M_erase_at_end(std::copy(__first, __last, (*this).begin()));
          }
      }
      inline void _M_fill_assign(typename ::std::deque<_Tp, _Alloc>::size_type __n, const typename ::std::deque<_Tp, _Alloc>::value_type &__val)
      {
        if (__n > (*this).size())
          {
            std::fill((*this).begin(), (*this).end(), __val);
            (*this)._M_fill_insert((*this).end(), __n - (*this).size(), __val);
          }
        else
          {
            (*this)._M_erase_at_end((*this).begin() + (typename ::std::deque<_Tp, _Alloc>::difference_type)__n);
            std::fill((*this).begin(), (*this).end(), __val);
          }
      }
      void _M_push_back_aux(const typename ::std::deque<_Tp, _Alloc>::value_type &__t);
      void _M_push_front_aux(const typename ::std::deque<_Tp, _Alloc>::value_type &__t);
      void _M_pop_back_aux();
      void _M_pop_front_aux();
      template < typename _Integer >
      inline void _M_insert_dispatch(typename ::std::deque<_Tp, _Alloc>::iterator __pos, _Integer __n, _Integer __x, ::std::__true_type)
      {
        (*this)._M_fill_insert(__pos, __n, __x);
      }
      template < typename _InputIterator >
      inline void _M_insert_dispatch(typename ::std::deque<_Tp, _Alloc>::iterator __pos, _InputIterator __first, _InputIterator __last, ::std::__false_type)
      {
        (*this)._M_range_insert_aux(__pos, __first, __last, std::__iterator_category(__first));
      }
      template < typename _InputIterator >
      void _M_range_insert_aux(typename ::std::deque<_Tp, _Alloc>::iterator __pos, _InputIterator __first, _InputIterator __last, ::std::input_iterator_tag);
      template < typename _ForwardIterator >
      void _M_range_insert_aux(typename ::std::deque<_Tp, _Alloc>::iterator __pos, _ForwardIterator __first, _ForwardIterator __last, ::std::forward_iterator_tag);
      void _M_fill_insert(typename ::std::deque<_Tp, _Alloc>::iterator __pos, typename ::std::deque<_Tp, _Alloc>::size_type __n, const typename ::std::deque<_Tp, _Alloc>::value_type &__x);
      typename ::std::deque<_Tp, _Alloc>::iterator _M_insert_aux(typename ::std::deque<_Tp, _Alloc>::iterator __pos, const typename ::std::deque<_Tp, _Alloc>::value_type &__x);
      void _M_insert_aux(typename ::std::deque<_Tp, _Alloc>::iterator __pos, typename ::std::deque<_Tp, _Alloc>::size_type __n, const typename ::std::deque<_Tp, _Alloc>::value_type &__x);
      template < typename _ForwardIterator >
      void _M_insert_aux(typename ::std::deque<_Tp, _Alloc>::iterator __pos, _ForwardIterator __first, _ForwardIterator __last, typename ::std::deque<_Tp, _Alloc>::size_type __n);
      void _M_destroy_data_aux(typename ::std::deque<_Tp, _Alloc>::iterator __first, typename ::std::deque<_Tp, _Alloc>::iterator __last);
      template < typename _Alloc1 >
      inline void _M_destroy_data(typename ::std::deque<_Tp, _Alloc>::iterator __first, typename ::std::deque<_Tp, _Alloc>::iterator __last, const _Alloc1 &)
      {
        (*this)._M_destroy_data_aux(__first, __last);
      }
      inline void _M_destroy_data(typename ::std::deque<_Tp, _Alloc>::iterator __first, typename ::std::deque<_Tp, _Alloc>::iterator __last, const ::std::allocator<_Tp> &)
      {
        if (!(__has_trivial_destructor(typename ::std::deque<_Tp, _Alloc>::value_type)))
          {
            (*this)._M_destroy_data_aux(__first, __last);
          }
      }
      inline void _M_erase_at_begin(typename ::std::deque<_Tp, _Alloc>::iterator __pos)
      {
        (*this)._M_destroy_data((*this).begin(), __pos, (_M_get_Tp_allocator)());
        _M_destroy_nodes(this->_M_impl._M_start._M_node, __pos._M_node);
        this->_M_impl._M_start = __pos;
      }
      inline void _M_erase_at_end(typename ::std::deque<_Tp, _Alloc>::iterator __pos)
      {
        (*this)._M_destroy_data(__pos, (*this).end(), (_M_get_Tp_allocator)());
        _M_destroy_nodes(__pos._M_node + 1, this->_M_impl._M_finish._M_node + 1);
        this->_M_impl._M_finish = __pos;
      }
      typename ::std::deque<_Tp, _Alloc>::iterator _M_erase(typename ::std::deque<_Tp, _Alloc>::iterator __position);
      typename ::std::deque<_Tp, _Alloc>::iterator _M_erase(typename ::std::deque<_Tp, _Alloc>::iterator __first, typename ::std::deque<_Tp, _Alloc>::iterator __last);
      inline typename ::std::deque<_Tp, _Alloc>::iterator _M_reserve_elements_at_front(typename ::std::deque<_Tp, _Alloc>::size_type __n)
      {
        const typename ::std::deque<_Tp, _Alloc>::size_type __vacancies = this->_M_impl._M_start._M_cur - this->_M_impl._M_start._M_first;
        if (__n > __vacancies)
          {
            (*this)._M_new_elements_at_front(__n - __vacancies);
          }
        return this->_M_impl._M_start - (typename ::std::deque<_Tp, _Alloc>::difference_type)__n;
      }
      inline typename ::std::deque<_Tp, _Alloc>::iterator _M_reserve_elements_at_back(typename ::std::deque<_Tp, _Alloc>::size_type __n)
      {
        const typename ::std::deque<_Tp, _Alloc>::size_type __vacancies = this->_M_impl._M_finish._M_last - this->_M_impl._M_finish._M_cur - 1;
        if (__n > __vacancies)
          {
            (*this)._M_new_elements_at_back(__n - __vacancies);
          }
        return this->_M_impl._M_finish + (typename ::std::deque<_Tp, _Alloc>::difference_type)__n;
      }
      void _M_new_elements_at_front(typename ::std::deque<_Tp, _Alloc>::size_type __new_elems);
      void _M_new_elements_at_back(typename ::std::deque<_Tp, _Alloc>::size_type __new_elems);
      inline void _M_reserve_map_at_back(typename ::std::deque<_Tp, _Alloc>::size_type __nodes_to_add  = (1))
      {
        if (__nodes_to_add + 1 > this->_M_impl._M_map_size - (this->_M_impl._M_finish._M_node - this->_M_impl._M_map))
          {
            (*this)._M_reallocate_map(__nodes_to_add, false);
          }
      }
      inline void _M_reserve_map_at_front(typename ::std::deque<_Tp, _Alloc>::size_type __nodes_to_add  = (1))
      {
        if (__nodes_to_add > ((typename ::std::deque<_Tp, _Alloc>::size_type(this->_M_impl._M_start._M_node - this->_M_impl._M_map))))
          {
            (*this)._M_reallocate_map(__nodes_to_add, true);
          }
      }
      void _M_reallocate_map(typename ::std::deque<_Tp, _Alloc>::size_type __nodes_to_add, bool __add_at_front);
  };
  template < typename _Tp, typename _Alloc >
  inline bool operator ==(const ::std::deque<_Tp, _Alloc> &__x, const ::std::deque<_Tp, _Alloc> &__y);
  template < typename _Tp, typename _Alloc >
  inline bool operator ==(const ::std::deque<_Tp, _Alloc> &__x, const ::std::deque<_Tp, _Alloc> &__y)
  {
    return __x.size() == __y.size() && std::equal(__x.begin(), __x.end(), __y.begin());
  }
  template < typename _Tp, typename _Alloc >
  inline bool operator <(const ::std::deque<_Tp, _Alloc> &__x, const ::std::deque<_Tp, _Alloc> &__y);
  template < typename _Tp, typename _Alloc >
  inline bool operator <(const ::std::deque<_Tp, _Alloc> &__x, const ::std::deque<_Tp, _Alloc> &__y)
  {
    return std::lexicographical_compare(__x.begin(), __x.end(), __y.begin(), __y.end());
  }
  template < typename _Tp, typename _Alloc >
  inline bool operator !=(const ::std::deque<_Tp, _Alloc> &__x, const ::std::deque<_Tp, _Alloc> &__y);
  template < typename _Tp, typename _Alloc >
  inline bool operator !=(const ::std::deque<_Tp, _Alloc> &__x, const ::std::deque<_Tp, _Alloc> &__y)
  {
    return !(__x == __y);
  }
  template < typename _Tp, typename _Alloc >
  inline bool operator >(const ::std::deque<_Tp, _Alloc> &__x, const ::std::deque<_Tp, _Alloc> &__y);
  template < typename _Tp, typename _Alloc >
  inline bool operator >(const ::std::deque<_Tp, _Alloc> &__x, const ::std::deque<_Tp, _Alloc> &__y)
  {
    return __y < __x;
  }
  template < typename _Tp, typename _Alloc >
  inline bool operator <=(const ::std::deque<_Tp, _Alloc> &__x, const ::std::deque<_Tp, _Alloc> &__y);
  template < typename _Tp, typename _Alloc >
  inline bool operator <=(const ::std::deque<_Tp, _Alloc> &__x, const ::std::deque<_Tp, _Alloc> &__y)
  {
    return !(__y < __x);
  }
  template < typename _Tp, typename _Alloc >
  inline bool operator >=(const ::std::deque<_Tp, _Alloc> &__x, const ::std::deque<_Tp, _Alloc> &__y);
  template < typename _Tp, typename _Alloc >
  inline bool operator >=(const ::std::deque<_Tp, _Alloc> &__x, const ::std::deque<_Tp, _Alloc> &__y)
  {
    return !(__x < __y);
  }
  template < typename _Tp, typename _Alloc >
  inline void swap(::std::deque<_Tp, _Alloc> &__x, ::std::deque<_Tp, _Alloc> &__y);
  template < typename _Tp, typename _Alloc >
  inline void swap(::std::deque<_Tp, _Alloc> &__x, ::std::deque<_Tp, _Alloc> &__y)
  {
    __x.swap(__y);
  }
  template < typename _Tp, typename _Alloc >
  ::std::deque<_Tp, _Alloc> &deque<_Tp, _Alloc>::operator =(const ::std::deque<_Tp, _Alloc> &__x)
  {
    if (&__x != this)
      {
        const typename ::std::deque<_Tp, _Alloc>::size_type __len = (*this).size();
        if (__len >= __x.size())
          {
            (*this)._M_erase_at_end(std::copy(__x.begin(), __x.end(), this->_M_impl._M_start));
          }
        else
          {
            typename ::std::deque<_Tp, _Alloc>::const_iterator __mid = __x.begin() + (typename ::std::deque<_Tp, _Alloc>::difference_type)__len;
            std::copy(__x.begin(), __mid, this->_M_impl._M_start);
            (*this)._M_range_insert_aux(this->_M_impl._M_finish, __mid, __x.end(), ::std::random_access_iterator_tag());
          }
      }
    return *this;
  }
  template < typename _Tp, typename _Alloc >
  typename ::std::deque<_Tp, _Alloc>::iterator deque<_Tp, _Alloc>::insert(typename ::std::deque<_Tp, _Alloc>::iterator __position, const typename ::std::deque<_Tp, _Alloc>::value_type &__x)
  {
    if (__position._M_cur == this->_M_impl._M_start._M_cur)
      {
        (*this).push_front(__x);
        return this->_M_impl._M_start;
      }
    else
      {
        if (__position._M_cur == this->_M_impl._M_finish._M_cur)
          {
            (*this).push_back(__x);
            typename ::std::deque<_Tp, _Alloc>::iterator __tmp = this->_M_impl._M_finish;
             --__tmp;
            return __tmp;
          }
        else
          {
            return (*this)._M_insert_aux(__position._M_const_cast(), __x);
          }
      }
  }
  template < typename _Tp, typename _Alloc >
  typename ::std::deque<_Tp, _Alloc>::iterator deque<_Tp, _Alloc>::_M_erase(typename ::std::deque<_Tp, _Alloc>::iterator __position)
  {
    typename ::std::deque<_Tp, _Alloc>::iterator __next = __position;
     ++__next;
    const typename ::std::deque<_Tp, _Alloc>::difference_type __index = __position - (*this).begin();
    if (static_cast<typename ::std::deque<_Tp, _Alloc>::size_type>(__index) < (*this).size() >> 1)
      {
        if (__position != (*this).begin())
          {
            std::copy_backward((*this).begin(), __position, __next);
          }
        (*this).pop_front();
      }
    else
      {
        if (__next != (*this).end())
          {
            std::copy(__next, (*this).end(), __position);
          }
        (*this).pop_back();
      }
    return (*this).begin() + __index;
  }
  template < typename _Tp, typename _Alloc >
  typename ::std::deque<_Tp, _Alloc>::iterator deque<_Tp, _Alloc>::_M_erase(typename ::std::deque<_Tp, _Alloc>::iterator __first, typename ::std::deque<_Tp, _Alloc>::iterator __last)
  {
    if (__first == __last)
      {
        return __first;
      }
    else
      {
        if (__first == (*this).begin() && __last == (*this).end())
          {
            (*this).clear();
            return (*this).end();
          }
        else
          {
            const typename ::std::deque<_Tp, _Alloc>::difference_type __n = __last - __first;
            const typename ::std::deque<_Tp, _Alloc>::difference_type __elems_before = __first - (*this).begin();
            if (static_cast<typename ::std::deque<_Tp, _Alloc>::size_type>(__elems_before) <= ((*this).size() - __n) / 2)
              {
                if (__first != (*this).begin())
                  {
                    std::copy_backward((*this).begin(), __first, __last);
                  }
                (*this)._M_erase_at_begin((*this).begin() + __n);
              }
            else
              {
                if (__last != (*this).end())
                  {
                    std::copy(__last, (*this).end(), __first);
                  }
                (*this)._M_erase_at_end((*this).end() - __n);
              }
            return (*this).begin() + __elems_before;
          }
      }
  }
  template < typename _Tp, typename _Alloc >
  template < typename _InputIterator >
  void deque<_Tp, _Alloc>::_M_assign_aux(_InputIterator __first, _InputIterator __last, ::std::input_iterator_tag)
  {
    typename ::std::deque<_Tp, _Alloc>::iterator __cur = (*this).begin();
    for (; __first != __last && __cur != (*this).end(); ( ++__cur,  ++__first))
      {
        *__cur = *__first;
      }
    if (__first == __last)
      {
        (*this)._M_erase_at_end(__cur);
      }
    else
      {
        (*this)._M_range_insert_aux((*this).end(), __first, __last, std::__iterator_category(__first));
      }
  }
  template < typename _Tp, typename _Alloc >
  void deque<_Tp, _Alloc>::_M_fill_insert(typename ::std::deque<_Tp, _Alloc>::iterator __pos, typename ::std::deque<_Tp, _Alloc>::size_type __n, const typename ::std::deque<_Tp, _Alloc>::value_type &__x)
  {
    if (__pos._M_cur == this->_M_impl._M_start._M_cur)
      {
        typename ::std::deque<_Tp, _Alloc>::iterator __new_start = (*this)._M_reserve_elements_at_front(__n);
        try
        {
          std::__uninitialized_fill_a(__new_start, this->_M_impl._M_start, __x, (_M_get_Tp_allocator)());
          this->_M_impl._M_start = __new_start;
        }
        catch (...)
        {
          _M_destroy_nodes(__new_start._M_node, this->_M_impl._M_start._M_node);
          throw;
        }
      }
    else
      {
        if (__pos._M_cur == this->_M_impl._M_finish._M_cur)
          {
            typename ::std::deque<_Tp, _Alloc>::iterator __new_finish = (*this)._M_reserve_elements_at_back(__n);
            try
            {
              std::__uninitialized_fill_a(this->_M_impl._M_finish, __new_finish, __x, (_M_get_Tp_allocator)());
              this->_M_impl._M_finish = __new_finish;
            }
            catch (...)
            {
              _M_destroy_nodes(this->_M_impl._M_finish._M_node + 1, __new_finish._M_node + 1);
              throw;
            }
          }
        else
          {
            (*this)._M_insert_aux(__pos, __n, __x);
          }
      }
  }
  template < typename _Tp, typename _Alloc >
  void deque<_Tp, _Alloc>::_M_fill_initialize(const typename ::std::deque<_Tp, _Alloc>::value_type &__value)
  {
    typename ::std::deque<_Tp, _Alloc>::_Map_pointer __cur;
    try
    {
      for (__cur = this->_M_impl._M_start._M_node; __cur < this->_M_impl._M_finish._M_node;  ++__cur)
        {
          std::__uninitialized_fill_a(*__cur, *__cur + _S_buffer_size(), __value, (_M_get_Tp_allocator)());
        }
      std::__uninitialized_fill_a(this->_M_impl._M_finish._M_first, this->_M_impl._M_finish._M_cur, __value, (_M_get_Tp_allocator)());
    }
    catch (...)
    {
      std::_Destroy(this->_M_impl._M_start, ((typename ::std::deque<_Tp, _Alloc>::iterator(*__cur, __cur))), (_M_get_Tp_allocator)());
      throw;
    }
  }
  template < typename _Tp, typename _Alloc >
  template < typename _InputIterator >
  void deque<_Tp, _Alloc>::_M_range_initialize(_InputIterator __first, _InputIterator __last, ::std::input_iterator_tag)
  {
    this->_M_initialize_map(0);
    try
    {
      for (; __first != __last;  ++__first)
        {
          (*this).push_back(*__first);
        }
    }
    catch (...)
    {
      (*this).clear();
      throw;
    }
  }
  template < typename _Tp, typename _Alloc >
  template < typename _ForwardIterator >
  void deque<_Tp, _Alloc>::_M_range_initialize(_ForwardIterator __first, _ForwardIterator __last, ::std::forward_iterator_tag)
  {
    const typename ::std::deque<_Tp, _Alloc>::size_type __n = std::distance(__first, __last);
    this->_M_initialize_map(__n);
    typename ::std::deque<_Tp, _Alloc>::_Map_pointer __cur_node;
    try
    {
      for (__cur_node = this->_M_impl._M_start._M_node; __cur_node < this->_M_impl._M_finish._M_node;  ++__cur_node)
        {
          _ForwardIterator __mid = __first;
          std::advance(__mid, _S_buffer_size());
          std::__uninitialized_copy_a(__first, __mid, *__cur_node, (_M_get_Tp_allocator)());
          __first = __mid;
        }
      std::__uninitialized_copy_a(__first, __last, this->_M_impl._M_finish._M_first, (_M_get_Tp_allocator)());
    }
    catch (...)
    {
      std::_Destroy(this->_M_impl._M_start, ((typename ::std::deque<_Tp, _Alloc>::iterator(*__cur_node, __cur_node))), (_M_get_Tp_allocator)());
      throw;
    }
  }
  template < typename _Tp, typename _Alloc >
  void deque<_Tp, _Alloc>::_M_push_back_aux(const typename ::std::deque<_Tp, _Alloc>::value_type &__t)
  {
    (*this)._M_reserve_map_at_back();
    *(this->_M_impl._M_finish._M_node + 1) = this->_M_allocate_node();
    try
    {
      this->_M_impl.construct(this->_M_impl._M_finish._M_cur, __t);
      this->_M_impl._M_finish._M_set_node(this->_M_impl._M_finish._M_node + 1);
      this->_M_impl._M_finish._M_cur = this->_M_impl._M_finish._M_first;
    }
    catch (...)
    {
      _M_deallocate_node(*(this->_M_impl._M_finish._M_node + 1));
      throw;
    }
  }
  template < typename _Tp, typename _Alloc >
  void deque<_Tp, _Alloc>::_M_push_front_aux(const typename ::std::deque<_Tp, _Alloc>::value_type &__t)
  {
    (*this)._M_reserve_map_at_front();
    *(this->_M_impl._M_start._M_node - 1) = this->_M_allocate_node();
    try
    {
      this->_M_impl._M_start._M_set_node(this->_M_impl._M_start._M_node - 1);
      this->_M_impl._M_start._M_cur = this->_M_impl._M_start._M_last - 1;
      this->_M_impl.construct(this->_M_impl._M_start._M_cur, __t);
    }
    catch (...)
    {
       ++this->_M_impl._M_start;
      _M_deallocate_node(*(this->_M_impl._M_start._M_node - 1));
      throw;
    }
  }
  template < typename _Tp, typename _Alloc >
  void deque<_Tp, _Alloc>::_M_pop_back_aux()
  {
    _M_deallocate_node(this->_M_impl._M_finish._M_first);
    this->_M_impl._M_finish._M_set_node(this->_M_impl._M_finish._M_node - 1);
    this->_M_impl._M_finish._M_cur = this->_M_impl._M_finish._M_last - 1;
    _Alloc_traits::destroy((_M_get_Tp_allocator)(), this->_M_impl._M_finish._M_cur);
  }
  template < typename _Tp, typename _Alloc >
  void deque<_Tp, _Alloc>::_M_pop_front_aux()
  {
    _Alloc_traits::destroy((_M_get_Tp_allocator)(), this->_M_impl._M_start._M_cur);
    _M_deallocate_node(this->_M_impl._M_start._M_first);
    this->_M_impl._M_start._M_set_node(this->_M_impl._M_start._M_node + 1);
    this->_M_impl._M_start._M_cur = this->_M_impl._M_start._M_first;
  }
  template < typename _Tp, typename _Alloc >
  template < typename _InputIterator >
  void deque<_Tp, _Alloc>::_M_range_insert_aux(typename ::std::deque<_Tp, _Alloc>::iterator __pos, _InputIterator __first, _InputIterator __last, ::std::input_iterator_tag)
  {
    std::copy(__first, __last, std::inserter(*this, __pos));
  }
  template < typename _Tp, typename _Alloc >
  template < typename _ForwardIterator >
  void deque<_Tp, _Alloc>::_M_range_insert_aux(typename ::std::deque<_Tp, _Alloc>::iterator __pos, _ForwardIterator __first, _ForwardIterator __last, ::std::forward_iterator_tag)
  {
    const typename ::std::deque<_Tp, _Alloc>::size_type __n = std::distance(__first, __last);
    if (__pos._M_cur == this->_M_impl._M_start._M_cur)
      {
        typename ::std::deque<_Tp, _Alloc>::iterator __new_start = (*this)._M_reserve_elements_at_front(__n);
        try
        {
          std::__uninitialized_copy_a(__first, __last, __new_start, (_M_get_Tp_allocator)());
          this->_M_impl._M_start = __new_start;
        }
        catch (...)
        {
          _M_destroy_nodes(__new_start._M_node, this->_M_impl._M_start._M_node);
          throw;
        }
      }
    else
      {
        if (__pos._M_cur == this->_M_impl._M_finish._M_cur)
          {
            typename ::std::deque<_Tp, _Alloc>::iterator __new_finish = (*this)._M_reserve_elements_at_back(__n);
            try
            {
              std::__uninitialized_copy_a(__first, __last, this->_M_impl._M_finish, (_M_get_Tp_allocator)());
              this->_M_impl._M_finish = __new_finish;
            }
            catch (...)
            {
              _M_destroy_nodes(this->_M_impl._M_finish._M_node + 1, __new_finish._M_node + 1);
              throw;
            }
          }
        else
          {
            (*this)._M_insert_aux(__pos, __first, __last, __n);
          }
      }
  }
  template < typename _Tp, typename _Alloc >
  typename ::std::deque<_Tp, _Alloc>::iterator deque<_Tp, _Alloc>::_M_insert_aux(typename ::std::deque<_Tp, _Alloc>::iterator __pos, const typename ::std::deque<_Tp, _Alloc>::value_type &__x)
  {
    typename ::std::deque<_Tp, _Alloc>::value_type __x_copy = __x;
    typename ::std::deque<_Tp, _Alloc>::difference_type __index = __pos - this->_M_impl._M_start;
    if (static_cast<typename ::std::deque<_Tp, _Alloc>::size_type>(__index) < (*this).size() / 2)
      {
        (*this).push_front((*this).front());
        typename ::std::deque<_Tp, _Alloc>::iterator __front1 = this->_M_impl._M_start;
         ++__front1;
        typename ::std::deque<_Tp, _Alloc>::iterator __front2 = __front1;
         ++__front2;
        __pos = this->_M_impl._M_start + __index;
        typename ::std::deque<_Tp, _Alloc>::iterator __pos1 = __pos;
         ++__pos1;
        std::copy(__front2, __pos1, __front1);
      }
    else
      {
        (*this).push_back((*this).back());
        typename ::std::deque<_Tp, _Alloc>::iterator __back1 = this->_M_impl._M_finish;
         --__back1;
        typename ::std::deque<_Tp, _Alloc>::iterator __back2 = __back1;
         --__back2;
        __pos = this->_M_impl._M_start + __index;
        std::copy_backward(__pos, __back2, __back1);
      }
    *__pos = __x_copy;
    return __pos;
  }
  template < typename _Tp, typename _Alloc >
  void deque<_Tp, _Alloc>::_M_insert_aux(typename ::std::deque<_Tp, _Alloc>::iterator __pos, typename ::std::deque<_Tp, _Alloc>::size_type __n, const typename ::std::deque<_Tp, _Alloc>::value_type &__x)
  {
    const typename ::std::deque<_Tp, _Alloc>::difference_type __elems_before = __pos - this->_M_impl._M_start;
    const typename ::std::deque<_Tp, _Alloc>::size_type __length = this->size();
    typename ::std::deque<_Tp, _Alloc>::value_type __x_copy = __x;
    if (__elems_before < (typename ::std::deque<_Tp, _Alloc>::difference_type)(__length / 2))
      {
        typename ::std::deque<_Tp, _Alloc>::iterator __new_start = (*this)._M_reserve_elements_at_front(__n);
        typename ::std::deque<_Tp, _Alloc>::iterator __old_start = this->_M_impl._M_start;
        __pos = this->_M_impl._M_start + __elems_before;
        try
        {
          if (__elems_before >= (typename ::std::deque<_Tp, _Alloc>::difference_type)__n)
            {
              typename ::std::deque<_Tp, _Alloc>::iterator __start_n = (this->_M_impl._M_start + (typename ::std::deque<_Tp, _Alloc>::difference_type)__n);
              std::__uninitialized_move_a(this->_M_impl._M_start, __start_n, __new_start, (_M_get_Tp_allocator)());
              this->_M_impl._M_start = __new_start;
              std::copy(__start_n, __pos, __old_start);
              std::fill(__pos - (typename ::std::deque<_Tp, _Alloc>::difference_type)__n, __pos, __x_copy);
            }
          else
            {
              std::__uninitialized_move_fill(this->_M_impl._M_start, __pos, __new_start, this->_M_impl._M_start, __x_copy, (_M_get_Tp_allocator)());
              this->_M_impl._M_start = __new_start;
              std::fill(__old_start, __pos, __x_copy);
            }
        }
        catch (...)
        {
          _M_destroy_nodes(__new_start._M_node, this->_M_impl._M_start._M_node);
          throw;
        }
      }
    else
      {
        typename ::std::deque<_Tp, _Alloc>::iterator __new_finish = (*this)._M_reserve_elements_at_back(__n);
        typename ::std::deque<_Tp, _Alloc>::iterator __old_finish = this->_M_impl._M_finish;
        const typename ::std::deque<_Tp, _Alloc>::difference_type __elems_after = (typename ::std::deque<_Tp, _Alloc>::difference_type)__length - __elems_before;
        __pos = this->_M_impl._M_finish - __elems_after;
        try
        {
          if (__elems_after > (typename ::std::deque<_Tp, _Alloc>::difference_type)__n)
            {
              typename ::std::deque<_Tp, _Alloc>::iterator __finish_n = (this->_M_impl._M_finish - (typename ::std::deque<_Tp, _Alloc>::difference_type)__n);
              std::__uninitialized_move_a(__finish_n, this->_M_impl._M_finish, this->_M_impl._M_finish, (_M_get_Tp_allocator)());
              this->_M_impl._M_finish = __new_finish;
              std::copy_backward(__pos, __finish_n, __old_finish);
              std::fill(__pos, __pos + (typename ::std::deque<_Tp, _Alloc>::difference_type)__n, __x_copy);
            }
          else
            {
              std::__uninitialized_fill_move(this->_M_impl._M_finish, __pos + (typename ::std::deque<_Tp, _Alloc>::difference_type)__n, __x_copy, __pos, this->_M_impl._M_finish, (_M_get_Tp_allocator)());
              this->_M_impl._M_finish = __new_finish;
              std::fill(__pos, __old_finish, __x_copy);
            }
        }
        catch (...)
        {
          _M_destroy_nodes(this->_M_impl._M_finish._M_node + 1, __new_finish._M_node + 1);
          throw;
        }
      }
  }
  template < typename _Tp, typename _Alloc >
  template < typename _ForwardIterator >
  void deque<_Tp, _Alloc>::_M_insert_aux(typename ::std::deque<_Tp, _Alloc>::iterator __pos, _ForwardIterator __first, _ForwardIterator __last, typename ::std::deque<_Tp, _Alloc>::size_type __n)
  {
    const typename ::std::deque<_Tp, _Alloc>::difference_type __elemsbefore = __pos - this->_M_impl._M_start;
    const typename ::std::deque<_Tp, _Alloc>::size_type __length = (*this).size();
    if (static_cast<typename ::std::deque<_Tp, _Alloc>::size_type>(__elemsbefore) < __length / 2)
      {
        typename ::std::deque<_Tp, _Alloc>::iterator __new_start = (*this)._M_reserve_elements_at_front(__n);
        typename ::std::deque<_Tp, _Alloc>::iterator __old_start = this->_M_impl._M_start;
        __pos = this->_M_impl._M_start + __elemsbefore;
        try
        {
          if (__elemsbefore >= (typename ::std::deque<_Tp, _Alloc>::difference_type)__n)
            {
              typename ::std::deque<_Tp, _Alloc>::iterator __start_n = (this->_M_impl._M_start + (typename ::std::deque<_Tp, _Alloc>::difference_type)__n);
              std::__uninitialized_move_a(this->_M_impl._M_start, __start_n, __new_start, (_M_get_Tp_allocator)());
              this->_M_impl._M_start = __new_start;
              std::copy(__start_n, __pos, __old_start);
              std::copy(__first, __last, __pos - (typename ::std::deque<_Tp, _Alloc>::difference_type)__n);
            }
          else
            {
              _ForwardIterator __mid = __first;
              std::advance(__mid, (typename ::std::deque<_Tp, _Alloc>::difference_type)__n - __elemsbefore);
              std::__uninitialized_move_copy(this->_M_impl._M_start, __pos, __first, __mid, __new_start, (_M_get_Tp_allocator)());
              this->_M_impl._M_start = __new_start;
              std::copy(__mid, __last, __old_start);
            }
        }
        catch (...)
        {
          _M_destroy_nodes(__new_start._M_node, this->_M_impl._M_start._M_node);
          throw;
        }
      }
    else
      {
        typename ::std::deque<_Tp, _Alloc>::iterator __new_finish = (*this)._M_reserve_elements_at_back(__n);
        typename ::std::deque<_Tp, _Alloc>::iterator __old_finish = this->_M_impl._M_finish;
        const typename ::std::deque<_Tp, _Alloc>::difference_type __elemsafter = (typename ::std::deque<_Tp, _Alloc>::difference_type)__length - __elemsbefore;
        __pos = this->_M_impl._M_finish - __elemsafter;
        try
        {
          if (__elemsafter > (typename ::std::deque<_Tp, _Alloc>::difference_type)__n)
            {
              typename ::std::deque<_Tp, _Alloc>::iterator __finish_n = (this->_M_impl._M_finish - (typename ::std::deque<_Tp, _Alloc>::difference_type)__n);
              std::__uninitialized_move_a(__finish_n, this->_M_impl._M_finish, this->_M_impl._M_finish, (_M_get_Tp_allocator)());
              this->_M_impl._M_finish = __new_finish;
              std::copy_backward(__pos, __finish_n, __old_finish);
              std::copy(__first, __last, __pos);
            }
          else
            {
              _ForwardIterator __mid = __first;
              std::advance(__mid, __elemsafter);
              std::__uninitialized_copy_move(__mid, __last, __pos, this->_M_impl._M_finish, this->_M_impl._M_finish, (_M_get_Tp_allocator)());
              this->_M_impl._M_finish = __new_finish;
              std::copy(__first, __mid, __pos);
            }
        }
        catch (...)
        {
          _M_destroy_nodes(this->_M_impl._M_finish._M_node + 1, __new_finish._M_node + 1);
          throw;
        }
      }
  }
  template < typename _Tp, typename _Alloc >
  void deque<_Tp, _Alloc>::_M_destroy_data_aux(typename ::std::deque<_Tp, _Alloc>::iterator __first, typename ::std::deque<_Tp, _Alloc>::iterator __last)
  {
    for (typename ::std::deque<_Tp, _Alloc>::_Map_pointer __node = __first._M_node + 1; __node < __last._M_node;  ++__node)
      {
        std::_Destroy(*__node, *__node + _S_buffer_size(), (_M_get_Tp_allocator)());
      }
    if (__first._M_node != __last._M_node)
      {
        std::_Destroy(__first._M_cur, __first._M_last, (_M_get_Tp_allocator)());
        std::_Destroy(__last._M_first, __last._M_cur, (_M_get_Tp_allocator)());
      }
    else
      {
        std::_Destroy(__first._M_cur, __last._M_cur, (_M_get_Tp_allocator)());
      }
  }
  template < typename _Tp, typename _Alloc >
  void deque<_Tp, _Alloc>::_M_new_elements_at_front(typename ::std::deque<_Tp, _Alloc>::size_type __new_elems)
  {
    if (this->max_size() - this->size() < __new_elems)
      {
        ::std::__throw_length_error("deque::_M_new_elements_at_front");
      }
    const typename ::std::deque<_Tp, _Alloc>::size_type __new_nodes = (__new_elems + _S_buffer_size() - 1) / _S_buffer_size();
    (*this)._M_reserve_map_at_front(__new_nodes);
    typename ::std::deque<_Tp, _Alloc>::size_type __i;
    try
    {
      for (__i = 1; __i <= __new_nodes;  ++__i)
        {
          *(this->_M_impl._M_start._M_node - __i) = this->_M_allocate_node();
        }
    }
    catch (...)
    {
      for (typename ::std::deque<_Tp, _Alloc>::size_type __j(1); __j < __i;  ++__j)
        {
          _M_deallocate_node(*(this->_M_impl._M_start._M_node - __j));
        }
      throw;
    }
  }
  template < typename _Tp, typename _Alloc >
  void deque<_Tp, _Alloc>::_M_new_elements_at_back(typename ::std::deque<_Tp, _Alloc>::size_type __new_elems)
  {
    if (this->max_size() - this->size() < __new_elems)
      {
        ::std::__throw_length_error("deque::_M_new_elements_at_back");
      }
    const typename ::std::deque<_Tp, _Alloc>::size_type __new_nodes = (__new_elems + _S_buffer_size() - 1) / _S_buffer_size();
    (*this)._M_reserve_map_at_back(__new_nodes);
    typename ::std::deque<_Tp, _Alloc>::size_type __i;
    try
    {
      for (__i = 1; __i <= __new_nodes;  ++__i)
        {
          *(this->_M_impl._M_finish._M_node + __i) = this->_M_allocate_node();
        }
    }
    catch (...)
    {
      for (typename ::std::deque<_Tp, _Alloc>::size_type __j(1); __j < __i;  ++__j)
        {
          _M_deallocate_node(*(this->_M_impl._M_finish._M_node + __j));
        }
      throw;
    }
  }
  template < typename _Tp, typename _Alloc >
  void deque<_Tp, _Alloc>::_M_reallocate_map(typename ::std::deque<_Tp, _Alloc>::size_type __nodes_to_add, bool __add_at_front)
  {
    const typename ::std::deque<_Tp, _Alloc>::size_type __old_num_nodes = this->_M_impl._M_finish._M_node - this->_M_impl._M_start._M_node + 1;
    const typename ::std::deque<_Tp, _Alloc>::size_type __new_num_nodes = __old_num_nodes + __nodes_to_add;
    typename ::std::deque<_Tp, _Alloc>::_Map_pointer __new_nstart;
    if (this->_M_impl._M_map_size > 2 * __new_num_nodes)
      {
        __new_nstart = this->_M_impl._M_map + (this->_M_impl._M_map_size - __new_num_nodes) / 2 + (__add_at_front ? __nodes_to_add : 0);
        if (__new_nstart < this->_M_impl._M_start._M_node)
          {
            std::copy(this->_M_impl._M_start._M_node, this->_M_impl._M_finish._M_node + 1, __new_nstart);
          }
        else
          {
            std::copy_backward(this->_M_impl._M_start._M_node, this->_M_impl._M_finish._M_node + 1, __new_nstart + __old_num_nodes);
          }
      }
    else
      {
        typename ::std::deque<_Tp, _Alloc>::size_type __new_map_size = this->_M_impl._M_map_size + std::max(this->_M_impl._M_map_size, __nodes_to_add) + 2;
        typename ::std::deque<_Tp, _Alloc>::_Map_pointer __new_map = this->_M_allocate_map(__new_map_size);
        __new_nstart = __new_map + (__new_map_size - __new_num_nodes) / 2 + (__add_at_front ? __nodes_to_add : 0);
        std::copy(this->_M_impl._M_start._M_node, this->_M_impl._M_finish._M_node + 1, __new_nstart);
        _M_deallocate_map(this->_M_impl._M_map, this->_M_impl._M_map_size);
        this->_M_impl._M_map = __new_map;
        this->_M_impl._M_map_size = __new_map_size;
      }
    this->_M_impl._M_start._M_set_node(__new_nstart);
    this->_M_impl._M_finish._M_set_node(__new_nstart + __old_num_nodes - 1);
  }
  template < typename _Tp >
  void fill(const ::std::_Deque_iterator<_Tp, _Tp &, _Tp *> &__first, const ::std::_Deque_iterator<_Tp, _Tp &, _Tp *> &__last, const _Tp &__value)
  {
    typedef typename ::std::_Deque_iterator<_Tp, _Tp &, _Tp *>::_Self _Self;
    for (typename ::std::_Deque_iterator<_Tp, _Tp &, _Tp *>::_Self::_Map_pointer __node = __first._M_node + 1; __node < __last._M_node;  ++__node)
      {
        std::fill(*__node, *__node + _Self::_S_buffer_size(), __value);
      }
    if (__first._M_node != __last._M_node)
      {
        std::fill(__first._M_cur, __first._M_last, __value);
        std::fill(__last._M_first, __last._M_cur, __value);
      }
    else
      {
        std::fill(__first._M_cur, __last._M_cur, __value);
      }
  }
  template < typename _Tp >
  ::std::_Deque_iterator<_Tp, _Tp &, _Tp *> copy(::std::_Deque_iterator<_Tp, const _Tp &, const _Tp *> __first, ::std::_Deque_iterator<_Tp, const _Tp &, const _Tp *> __last, ::std::_Deque_iterator<_Tp, _Tp &, _Tp *> __result)
  {
    typedef typename ::std::_Deque_iterator<_Tp, _Tp &, _Tp *>::_Self _Self;
    typedef typename ::std::_Deque_iterator<_Tp, _Tp &, _Tp *>::_Self::difference_type difference_type;
    difference_type __len = __last - __first;
    while (__len > 0)
      {
        const difference_type __clen = std::min(__len, std::min(__first._M_last - __first._M_cur, __result._M_last - __result._M_cur));
        std::copy(__first._M_cur, __first._M_cur + __clen, __result._M_cur);
        __first += __clen;
        __result += __clen;
        __len -= __clen;
      }
    return __result;
  }
  template < typename _Tp >
  ::std::_Deque_iterator<_Tp, _Tp &, _Tp *> copy_backward(::std::_Deque_iterator<_Tp, const _Tp &, const _Tp *> __first, ::std::_Deque_iterator<_Tp, const _Tp &, const _Tp *> __last, ::std::_Deque_iterator<_Tp, _Tp &, _Tp *> __result)
  {
    typedef typename ::std::_Deque_iterator<_Tp, _Tp &, _Tp *>::_Self _Self;
    typedef typename ::std::_Deque_iterator<_Tp, _Tp &, _Tp *>::_Self::difference_type difference_type;
    difference_type __len = __last - __first;
    while (__len > 0)
      {
        difference_type __llen = __last._M_cur - __last._M_first;
        _Tp *__lend = __last._M_cur;
        difference_type __rlen = __result._M_cur - __result._M_first;
        _Tp *__rend = __result._M_cur;
        if (!__llen)
          {
            __llen = _Self::_S_buffer_size();
            __lend = *(__last._M_node - 1) + __llen;
          }
        if (!__rlen)
          {
            __rlen = _Self::_S_buffer_size();
            __rend = *(__result._M_node - 1) + __rlen;
          }
        const difference_type __clen = std::min(__len, std::min(__llen, __rlen));
        std::copy_backward(__lend - __clen, __lend, __rend);
        __last -= __clen;
        __result -= __clen;
        __len -= __clen;
      }
    return __result;
  }
  template < typename _Tp, typename _Alloc >
  struct  _Vector_base
  {
      typedef typename ::__gnu_cxx::__alloc_traits<_Alloc>::template rebind< _Tp>::other _Tp_alloc_type;
      typedef typename ::__gnu_cxx::__alloc_traits<typename ::std::_Vector_base<_Tp, _Alloc>::_Tp_alloc_type>::pointer pointer;
      struct  _Vector_impl : ::std::_Vector_base<_Tp, _Alloc>::_Tp_alloc_type
      {
          typename ::std::_Vector_base<_Tp, _Alloc>::pointer _M_start;
          typename ::std::_Vector_base<_Tp, _Alloc>::pointer _M_finish;
          typename ::std::_Vector_base<_Tp, _Alloc>::pointer _M_end_of_storage;
          inline _Vector_impl()
            : _Tp_alloc_type(), _M_start(), _M_finish(), _M_end_of_storage()
          {
          }
          inline _Vector_impl(const typename ::std::_Vector_base<_Tp, _Alloc>::_Tp_alloc_type &__a)
            : _Tp_alloc_type(__a), _M_start(), _M_finish(), _M_end_of_storage()
          {
          }
          inline void _M_swap_data(typename ::std::_Vector_base<_Tp, _Alloc>::_Vector_impl &__x)
          {
            std::swap(::std::_Vector_base<_Tp, _Alloc>::_Vector_impl::_M_start, __x._M_start);
            std::swap(::std::_Vector_base<_Tp, _Alloc>::_Vector_impl::_M_finish, __x._M_finish);
            std::swap(::std::_Vector_base<_Tp, _Alloc>::_Vector_impl::_M_end_of_storage, __x._M_end_of_storage);
          }
      };
      typedef _Alloc allocator_type;
      inline typename ::std::_Vector_base<_Tp, _Alloc>::_Tp_alloc_type &_M_get_Tp_allocator()
      {
        return *static_cast<typename ::std::_Vector_base<_Tp, _Alloc>::_Tp_alloc_type *>(&this->_M_impl);
      }
      inline const typename ::std::_Vector_base<_Tp, _Alloc>::_Tp_alloc_type &_M_get_Tp_allocator() const 
      {
        return *static_cast<const typename ::std::_Vector_base<_Tp, _Alloc>::_Tp_alloc_type *>(&this->_M_impl);
      }
      inline typename ::std::_Vector_base<_Tp, _Alloc>::allocator_type get_allocator() const 
      {
        return ((typename ::std::_Vector_base<_Tp, _Alloc>::allocator_type((*this)._M_get_Tp_allocator())));
      }
      inline _Vector_base()
        : _M_impl()
      {
      }
      inline _Vector_base(const typename ::std::_Vector_base<_Tp, _Alloc>::allocator_type &__a)
        : _M_impl(__a)
      {
      }
      inline _Vector_base(::std::size_t __n)
        : _M_impl()
      {
        (*this)._M_create_storage(__n);
      }
      inline _Vector_base(::std::size_t __n, const typename ::std::_Vector_base<_Tp, _Alloc>::allocator_type &__a)
        : _M_impl(__a)
      {
        (*this)._M_create_storage(__n);
      }
      inline ~_Vector_base()
      {
        (*this)._M_deallocate(this->_M_impl._M_start, this->_M_impl._M_end_of_storage - this->_M_impl._M_start);
      }
      typename ::std::_Vector_base<_Tp, _Alloc>::_Vector_impl _M_impl;
      inline typename ::std::_Vector_base<_Tp, _Alloc>::pointer _M_allocate(::std::size_t __n)
      {
        typedef ::__gnu_cxx::__alloc_traits<typename ::std::_Vector_base<_Tp, _Alloc>::_Tp_alloc_type> _Tr;
        return __n != 0 ? _Tr::allocate(::std::_Vector_base<_Tp, _Alloc>::_M_impl, __n) : ((typename ::std::_Vector_base<_Tp, _Alloc>::pointer()));
      }
      inline void _M_deallocate(typename ::std::_Vector_base<_Tp, _Alloc>::pointer __p, ::std::size_t __n)
      {
        typedef ::__gnu_cxx::__alloc_traits<typename ::std::_Vector_base<_Tp, _Alloc>::_Tp_alloc_type> _Tr;
        if (__p)
          {
            _Tr::deallocate(::std::_Vector_base<_Tp, _Alloc>::_M_impl, __p, __n);
          }
      }
    private:
      inline void _M_create_storage(::std::size_t __n)
      {
        this->_M_impl._M_start = this->_M_allocate(__n);
        this->_M_impl._M_finish = this->_M_impl._M_start;
        this->_M_impl._M_end_of_storage = this->_M_impl._M_start + __n;
      }
  };
  template < typename _Tp, typename _Alloc = ::std::allocator<_Tp> >
  class  vector : protected ::std::_Vector_base<_Tp, _Alloc>
  {
      typedef ::std::_Vector_base<_Tp, _Alloc> _Base;
      typedef typename ::std::_Vector_base<_Tp, _Alloc>::_Tp_alloc_type _Tp_alloc_type;
      typedef ::__gnu_cxx::__alloc_traits<typename ::std::vector<_Tp, _Alloc>::_Tp_alloc_type> _Alloc_traits;
    public:
      typedef _Tp value_type;
      typedef typename ::std::_Vector_base<_Tp, _Alloc>::pointer pointer;
      typedef typename ::__gnu_cxx::__alloc_traits<typename ::std::vector<_Tp, _Alloc>::_Tp_alloc_type>::const_pointer const_pointer;
      typedef typename ::__gnu_cxx::__alloc_traits<typename ::std::vector<_Tp, _Alloc>::_Tp_alloc_type>::reference reference;
      typedef typename ::__gnu_cxx::__alloc_traits<typename ::std::vector<_Tp, _Alloc>::_Tp_alloc_type>::const_reference const_reference;
      typedef ::__gnu_cxx::__normal_iterator<typename ::std::vector<_Tp, _Alloc>::pointer, ::std::vector<_Tp, _Alloc> > iterator;
      typedef ::__gnu_cxx::__normal_iterator<typename ::std::vector<_Tp, _Alloc>::const_pointer, ::std::vector<_Tp, _Alloc> > const_iterator;
      typedef ::std::reverse_iterator<typename ::std::vector<_Tp, _Alloc>::const_iterator> const_reverse_iterator;
      typedef ::std::reverse_iterator<typename ::std::vector<_Tp, _Alloc>::iterator> reverse_iterator;
      typedef ::std::size_t size_type;
      typedef ::std::ptrdiff_t difference_type;
      typedef _Alloc allocator_type;
    protected:
      using _Base::_M_allocate;
      using _Base::_M_deallocate;
      using _Base::_M_impl;
      using _Base::_M_get_Tp_allocator;
    public:
      inline vector()
        : _Base()
      {
      }
      inline explicit vector(const typename ::std::vector<_Tp, _Alloc>::allocator_type &__a)
        : _Base(__a)
      {
      }
      inline explicit vector(typename ::std::vector<_Tp, _Alloc>::size_type __n, const typename ::std::vector<_Tp, _Alloc>::value_type &__value  = (((typename ::std::vector<_Tp, _Alloc>::value_type()))), const typename ::std::vector<_Tp, _Alloc>::allocator_type &__a  = (((typename ::std::vector<_Tp, _Alloc>::allocator_type()))))
        : _Base(__n, __a)
      {
        (*this)._M_fill_initialize(__n, __value);
      }
      inline vector(const ::std::vector<_Tp, _Alloc> &__x)
        : _Base(__x.size(), _Alloc_traits::_S_select_on_copy(__x._M_get_Tp_allocator()))
      {
        this->_M_impl._M_finish = std::__uninitialized_copy_a(__x.begin(), __x.end(), this->_M_impl._M_start, (_M_get_Tp_allocator)());
      }
      template < typename _InputIterator >
      inline vector(_InputIterator __first, _InputIterator __last, const typename ::std::vector<_Tp, _Alloc>::allocator_type &__a  = (((typename ::std::vector<_Tp, _Alloc>::allocator_type()))))
        : _Base(__a)
      {
        typedef typename ::std::__is_integer<_InputIterator>::__type _Integral;
        (*this)._M_initialize_dispatch(__first, __last, _Integral());
      }
      inline ~vector()
      {
        std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish, (_M_get_Tp_allocator)());
      }
      ::std::vector<_Tp, _Alloc> &operator =(const ::std::vector<_Tp, _Alloc> &__x);
      inline void assign(typename ::std::vector<_Tp, _Alloc>::size_type __n, const typename ::std::vector<_Tp, _Alloc>::value_type &__val)
      {
        (*this)._M_fill_assign(__n, __val);
      }
      template < typename _InputIterator >
      inline void assign(_InputIterator __first, _InputIterator __last)
      {
        typedef typename ::std::__is_integer<_InputIterator>::__type _Integral;
        (*this)._M_assign_dispatch(__first, __last, _Integral());
      }
      using _Base::get_allocator;
      inline typename ::std::vector<_Tp, _Alloc>::iterator begin()
      {
        return ((typename ::std::vector<_Tp, _Alloc>::iterator(this->_M_impl._M_start)));
      }
      inline typename ::std::vector<_Tp, _Alloc>::const_iterator begin() const 
      {
        return ((typename ::std::vector<_Tp, _Alloc>::const_iterator(this->_M_impl._M_start)));
      }
      inline typename ::std::vector<_Tp, _Alloc>::iterator end()
      {
        return ((typename ::std::vector<_Tp, _Alloc>::iterator(this->_M_impl._M_finish)));
      }
      inline typename ::std::vector<_Tp, _Alloc>::const_iterator end() const 
      {
        return ((typename ::std::vector<_Tp, _Alloc>::const_iterator(this->_M_impl._M_finish)));
      }
      inline typename ::std::vector<_Tp, _Alloc>::reverse_iterator rbegin()
      {
        return ((typename ::std::vector<_Tp, _Alloc>::reverse_iterator((*this).end())));
      }
      inline typename ::std::vector<_Tp, _Alloc>::const_reverse_iterator rbegin() const 
      {
        return ((typename ::std::vector<_Tp, _Alloc>::const_reverse_iterator((*this).end())));
      }
      inline typename ::std::vector<_Tp, _Alloc>::reverse_iterator rend()
      {
        return ((typename ::std::vector<_Tp, _Alloc>::reverse_iterator((*this).begin())));
      }
      inline typename ::std::vector<_Tp, _Alloc>::const_reverse_iterator rend() const 
      {
        return ((typename ::std::vector<_Tp, _Alloc>::const_reverse_iterator((*this).begin())));
      }
      inline typename ::std::vector<_Tp, _Alloc>::size_type size() const 
      {
        return ((typename ::std::vector<_Tp, _Alloc>::size_type(this->_M_impl._M_finish - this->_M_impl._M_start)));
      }
      inline typename ::std::vector<_Tp, _Alloc>::size_type max_size() const 
      {
        return _Alloc_traits::max_size((_M_get_Tp_allocator)());
      }
      inline void resize(typename ::std::vector<_Tp, _Alloc>::size_type __new_size, typename ::std::vector<_Tp, _Alloc>::value_type __x  = (((typename ::std::vector<_Tp, _Alloc>::value_type()))))
      {
        if (__new_size > (*this).size())
          {
            (*this)._M_fill_insert((*this).end(), __new_size - (*this).size(), __x);
          }
        else
          {
            if (__new_size < (*this).size())
              {
                (*this)._M_erase_at_end(this->_M_impl._M_start + __new_size);
              }
          }
      }
      inline typename ::std::vector<_Tp, _Alloc>::size_type capacity() const 
      {
        return ((typename ::std::vector<_Tp, _Alloc>::size_type(this->_M_impl._M_end_of_storage - this->_M_impl._M_start)));
      }
      inline bool empty() const 
      {
        return (*this).begin() == (*this).end();
      }
      void reserve(typename ::std::vector<_Tp, _Alloc>::size_type __n);
      inline typename ::std::vector<_Tp, _Alloc>::reference operator [](typename ::std::vector<_Tp, _Alloc>::size_type __n)
      {
        ;
        return *(this->_M_impl._M_start + __n);
      }
      inline typename ::std::vector<_Tp, _Alloc>::const_reference operator [](typename ::std::vector<_Tp, _Alloc>::size_type __n) const 
      {
        ;
        return *(this->_M_impl._M_start + __n);
      }
    protected:
      inline void _M_range_check(typename ::std::vector<_Tp, _Alloc>::size_type __n) const 
      {
        if (__n >= this->size())
          {
            __throw_out_of_range_fmt("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)", __n, this->size());
          }
      }
    public:
      inline typename ::std::vector<_Tp, _Alloc>::reference at(typename ::std::vector<_Tp, _Alloc>::size_type __n)
      {
        (*this)._M_range_check(__n);
        return (*this)[__n];
      }
      inline typename ::std::vector<_Tp, _Alloc>::const_reference at(typename ::std::vector<_Tp, _Alloc>::size_type __n) const 
      {
        (*this)._M_range_check(__n);
        return (*this)[__n];
      }
      inline typename ::std::vector<_Tp, _Alloc>::reference front()
      {
        ;
        return *(*this).begin();
      }
      inline typename ::std::vector<_Tp, _Alloc>::const_reference front() const 
      {
        ;
        return *(*this).begin();
      }
      inline typename ::std::vector<_Tp, _Alloc>::reference back()
      {
        ;
        return *((*this).end() - 1);
      }
      inline typename ::std::vector<_Tp, _Alloc>::const_reference back() const 
      {
        ;
        return *((*this).end() - 1);
      }
      inline _Tp *data()
      {
        return (*this)._M_data_ptr(this->_M_impl._M_start);
      }
      inline const _Tp *data() const 
      {
        return (*this)._M_data_ptr(this->_M_impl._M_start);
      }
      inline void push_back(const typename ::std::vector<_Tp, _Alloc>::value_type &__x)
      {
        if (this->_M_impl._M_finish != this->_M_impl._M_end_of_storage)
          {
            _Alloc_traits::construct(this->_M_impl, this->_M_impl._M_finish, __x);
             ++this->_M_impl._M_finish;
          }
        else
          {
            (*this)._M_realloc_insert((*this).end(), __x);
          }
      }
      inline void pop_back()
      {
        ;
         --this->_M_impl._M_finish;
        _Alloc_traits::destroy(this->_M_impl, this->_M_impl._M_finish);
      }
      typename ::std::vector<_Tp, _Alloc>::iterator insert(typename ::std::vector<_Tp, _Alloc>::iterator __position, const typename ::std::vector<_Tp, _Alloc>::value_type &__x);
      inline void insert(typename ::std::vector<_Tp, _Alloc>::iterator __position, typename ::std::vector<_Tp, _Alloc>::size_type __n, const typename ::std::vector<_Tp, _Alloc>::value_type &__x)
      {
        (*this)._M_fill_insert(__position, __n, __x);
      }
      template < typename _InputIterator >
      inline void insert(typename ::std::vector<_Tp, _Alloc>::iterator __position, _InputIterator __first, _InputIterator __last)
      {
        typedef typename ::std::__is_integer<_InputIterator>::__type _Integral;
        (*this)._M_insert_dispatch(__position, __first, __last, _Integral());
      }
      inline typename ::std::vector<_Tp, _Alloc>::iterator erase(typename ::std::vector<_Tp, _Alloc>::iterator __position)
      {
        return (*this)._M_erase(__position);
      }
      inline typename ::std::vector<_Tp, _Alloc>::iterator erase(typename ::std::vector<_Tp, _Alloc>::iterator __first, typename ::std::vector<_Tp, _Alloc>::iterator __last)
      {
        return (*this)._M_erase(__first, __last);
      }
      inline void swap(::std::vector<_Tp, _Alloc> &__x)
      {
        this->_M_impl._M_swap_data(__x._M_impl);
        _Alloc_traits::_S_on_swap((_M_get_Tp_allocator)(), __x._M_get_Tp_allocator());
      }
      inline void clear()
      {
        (*this)._M_erase_at_end(this->_M_impl._M_start);
      }
    protected:
      template < typename _ForwardIterator >
      inline typename ::std::vector<_Tp, _Alloc>::pointer _M_allocate_and_copy(typename ::std::vector<_Tp, _Alloc>::size_type __n, _ForwardIterator __first, _ForwardIterator __last)
      {
        typename ::std::vector<_Tp, _Alloc>::pointer __result = this->_M_allocate(__n);
        try
        {
          std::__uninitialized_copy_a(__first, __last, __result, (_M_get_Tp_allocator)());
          return __result;
        }
        catch (...)
        {
          _M_deallocate(__result, __n);
          throw;
        }
      }
      template < typename _Integer >
      inline void _M_initialize_dispatch(_Integer __n, _Integer __value, ::std::__true_type)
      {
        this->_M_impl._M_start = (_M_allocate)(static_cast<typename ::std::vector<_Tp, _Alloc>::size_type>(__n));
        this->_M_impl._M_end_of_storage = this->_M_impl._M_start + static_cast<typename ::std::vector<_Tp, _Alloc>::size_type>(__n);
        (*this)._M_fill_initialize(static_cast<typename ::std::vector<_Tp, _Alloc>::size_type>(__n), __value);
      }
      template < typename _InputIterator >
      inline void _M_initialize_dispatch(_InputIterator __first, _InputIterator __last, ::std::__false_type)
      {
        typedef typename ::std::iterator_traits<_InputIterator>::iterator_category _IterCategory;
        (*this)._M_range_initialize(__first, __last, _IterCategory());
      }
      template < typename _InputIterator >
      inline void _M_range_initialize(_InputIterator __first, _InputIterator __last, ::std::input_iterator_tag)
      {
        try
        {
          for (; __first != __last;  ++__first)
            {
              (*this).push_back(*__first);
            }
        }
        catch (...)
        {
          (*this).clear();
          throw;
        }
      }
      template < typename _ForwardIterator >
      inline void _M_range_initialize(_ForwardIterator __first, _ForwardIterator __last, ::std::forward_iterator_tag)
      {
        const typename ::std::vector<_Tp, _Alloc>::size_type __n = std::distance(__first, __last);
        this->_M_impl._M_start = this->_M_allocate(__n);
        this->_M_impl._M_end_of_storage = this->_M_impl._M_start + __n;
        this->_M_impl._M_finish = std::__uninitialized_copy_a(__first, __last, this->_M_impl._M_start, (_M_get_Tp_allocator)());
      }
      inline void _M_fill_initialize(typename ::std::vector<_Tp, _Alloc>::size_type __n, const typename ::std::vector<_Tp, _Alloc>::value_type &__value)
      {
        this->_M_impl._M_finish = std::__uninitialized_fill_n_a(this->_M_impl._M_start, __n, __value, (_M_get_Tp_allocator)());
      }
      template < typename _Integer >
      inline void _M_assign_dispatch(_Integer __n, _Integer __val, ::std::__true_type)
      {
        (*this)._M_fill_assign(__n, __val);
      }
      template < typename _InputIterator >
      inline void _M_assign_dispatch(_InputIterator __first, _InputIterator __last, ::std::__false_type)
      {
        (*this)._M_assign_aux(__first, __last, std::__iterator_category(__first));
      }
      template < typename _InputIterator >
      void _M_assign_aux(_InputIterator __first, _InputIterator __last, ::std::input_iterator_tag);
      template < typename _ForwardIterator >
      void _M_assign_aux(_ForwardIterator __first, _ForwardIterator __last, ::std::forward_iterator_tag);
      void _M_fill_assign(typename ::std::vector<_Tp, _Alloc>::size_type __n, const typename ::std::vector<_Tp, _Alloc>::value_type &__val);
      template < typename _Integer >
      inline void _M_insert_dispatch(typename ::std::vector<_Tp, _Alloc>::iterator __pos, _Integer __n, _Integer __val, ::std::__true_type)
      {
        (*this)._M_fill_insert(__pos, __n, __val);
      }
      template < typename _InputIterator >
      inline void _M_insert_dispatch(typename ::std::vector<_Tp, _Alloc>::iterator __pos, _InputIterator __first, _InputIterator __last, ::std::__false_type)
      {
        (*this)._M_range_insert(__pos, __first, __last, std::__iterator_category(__first));
      }
      template < typename _InputIterator >
      void _M_range_insert(typename ::std::vector<_Tp, _Alloc>::iterator __pos, _InputIterator __first, _InputIterator __last, ::std::input_iterator_tag);
      template < typename _ForwardIterator >
      void _M_range_insert(typename ::std::vector<_Tp, _Alloc>::iterator __position, _ForwardIterator __first, _ForwardIterator __last, ::std::forward_iterator_tag);
      void _M_fill_insert(typename ::std::vector<_Tp, _Alloc>::iterator __position, typename ::std::vector<_Tp, _Alloc>::size_type __n, const typename ::std::vector<_Tp, _Alloc>::value_type &__x);
      void _M_insert_aux(typename ::std::vector<_Tp, _Alloc>::iterator __position, const typename ::std::vector<_Tp, _Alloc>::value_type &__x);
      void _M_realloc_insert(typename ::std::vector<_Tp, _Alloc>::iterator __position, const typename ::std::vector<_Tp, _Alloc>::value_type &__x);
      inline typename ::std::vector<_Tp, _Alloc>::size_type _M_check_len(typename ::std::vector<_Tp, _Alloc>::size_type __n, const char *__s) const 
      {
        if ((*this).max_size() - (*this).size() < __n)
          {
            ::std::__throw_length_error(__s);
          }
        const typename ::std::vector<_Tp, _Alloc>::size_type __len = (*this).size() + std::max((*this).size(), __n);
        return __len < (*this).size() || __len > (*this).max_size() ? (*this).max_size() : __len;
      }
      inline void _M_erase_at_end(typename ::std::vector<_Tp, _Alloc>::pointer __pos)
      {
        std::_Destroy(__pos, this->_M_impl._M_finish, (_M_get_Tp_allocator)());
        this->_M_impl._M_finish = __pos;
      }
      typename ::std::vector<_Tp, _Alloc>::iterator _M_erase(typename ::std::vector<_Tp, _Alloc>::iterator __position);
      typename ::std::vector<_Tp, _Alloc>::iterator _M_erase(typename ::std::vector<_Tp, _Alloc>::iterator __first, typename ::std::vector<_Tp, _Alloc>::iterator __last);
      template < typename _Up >
      inline _Up *_M_data_ptr(_Up *__ptr) const 
      {
        return __ptr;
      }
      template < typename _Up >
      inline _Up *_M_data_ptr(_Up *__ptr)
      {
        return __ptr;
      }
      template < typename _Ptr >
      inline typename ::std::vector<_Tp, _Alloc>::value_type *_M_data_ptr(_Ptr __ptr)
      {
        return __ptr.operator ->();
      }
      template < typename _Ptr >
      inline const typename ::std::vector<_Tp, _Alloc>::value_type *_M_data_ptr(_Ptr __ptr) const 
      {
        return __ptr.operator ->();
      }
  };
  template < typename _Tp, typename _Alloc >
  inline bool operator ==(const ::std::vector<_Tp, _Alloc> &__x, const ::std::vector<_Tp, _Alloc> &__y);
  template < typename _Tp, typename _Alloc >
  inline bool operator ==(const ::std::vector<_Tp, _Alloc> &__x, const ::std::vector<_Tp, _Alloc> &__y)
  {
    return __x.size() == __y.size() && std::equal(__x.begin(), __x.end(), __y.begin());
  }
  template < typename _Tp, typename _Alloc >
  inline bool operator <(const ::std::vector<_Tp, _Alloc> &__x, const ::std::vector<_Tp, _Alloc> &__y);
  template < typename _Tp, typename _Alloc >
  inline bool operator <(const ::std::vector<_Tp, _Alloc> &__x, const ::std::vector<_Tp, _Alloc> &__y)
  {
    return std::lexicographical_compare(__x.begin(), __x.end(), __y.begin(), __y.end());
  }
  template < typename _Tp, typename _Alloc >
  inline bool operator !=(const ::std::vector<_Tp, _Alloc> &__x, const ::std::vector<_Tp, _Alloc> &__y);
  template < typename _Tp, typename _Alloc >
  inline bool operator !=(const ::std::vector<_Tp, _Alloc> &__x, const ::std::vector<_Tp, _Alloc> &__y)
  {
    return !(__x == __y);
  }
  template < typename _Tp, typename _Alloc >
  inline bool operator >(const ::std::vector<_Tp, _Alloc> &__x, const ::std::vector<_Tp, _Alloc> &__y);
  template < typename _Tp, typename _Alloc >
  inline bool operator >(const ::std::vector<_Tp, _Alloc> &__x, const ::std::vector<_Tp, _Alloc> &__y)
  {
    return __y < __x;
  }
  template < typename _Tp, typename _Alloc >
  inline bool operator <=(const ::std::vector<_Tp, _Alloc> &__x, const ::std::vector<_Tp, _Alloc> &__y);
  template < typename _Tp, typename _Alloc >
  inline bool operator <=(const ::std::vector<_Tp, _Alloc> &__x, const ::std::vector<_Tp, _Alloc> &__y)
  {
    return !(__y < __x);
  }
  template < typename _Tp, typename _Alloc >
  inline bool operator >=(const ::std::vector<_Tp, _Alloc> &__x, const ::std::vector<_Tp, _Alloc> &__y);
  template < typename _Tp, typename _Alloc >
  inline bool operator >=(const ::std::vector<_Tp, _Alloc> &__x, const ::std::vector<_Tp, _Alloc> &__y)
  {
    return !(__x < __y);
  }
  template < typename _Tp, typename _Alloc >
  inline void swap(::std::vector<_Tp, _Alloc> &__x, ::std::vector<_Tp, _Alloc> &__y);
  template < typename _Tp, typename _Alloc >
  inline void swap(::std::vector<_Tp, _Alloc> &__x, ::std::vector<_Tp, _Alloc> &__y)
  {
    __x.swap(__y);
  }
  typedef unsigned long int _Bit_type;
  enum mcc_enum_anon_54
  {
    _S_word_bit = (int)(8 * sizeof(::std::_Bit_type))
  };
  struct  _Bit_reference
  {
      ::std::_Bit_type *_M_p;
      ::std::_Bit_type _M_mask;
      inline _Bit_reference(::std::_Bit_type *__x, ::std::_Bit_type __y)
        : _M_p(__x), _M_mask(__y)
      {
      }
      inline _Bit_reference()
        : _M_p(0), _M_mask(0)
      {
      }
      inline operator bool() const 
      {
        return !!(*(*this)._M_p & (*this)._M_mask);
      }
      inline ::std::_Bit_reference &operator =(bool __x)
      {
        if (__x)
          {
            *(*this)._M_p |= (*this)._M_mask;
          }
        else
          {
            *(*this)._M_p &= ~(*this)._M_mask;
          }
        return *this;
      }
      inline ::std::_Bit_reference &operator =(const ::std::_Bit_reference &__x)
      {
        return *this = (bool)__x;
      }
      inline bool operator ==(const ::std::_Bit_reference &__x) const 
      {
        return (bool)*this == (bool)__x;
      }
      inline bool operator <(const ::std::_Bit_reference &__x) const 
      {
        return !((bool)*this) && (bool)__x;
      }
      inline void flip()
      {
        *(*this)._M_p ^= (*this)._M_mask;
      }
  };
 /* Instantiation of class template '::std::iterator< ::std::random_access_iterator_tag, bool>' */ 
  struct  _Bit_iterator_base : ::std::iterator< ::std::random_access_iterator_tag, bool>
  {
      ::std::_Bit_type *_M_p;
      unsigned int _M_offset;
      inline _Bit_iterator_base(::std::_Bit_type *__x, unsigned int __y)
        : _M_p(__x), _M_offset(__y)
      {
      }
      inline void _M_bump_up()
      {
        if ((*this)._M_offset++ == (int)::std::_S_word_bit - 1)
          {
            (*this)._M_offset = 0;
             ++(*this)._M_p;
          }
      }
      inline void _M_bump_down()
      {
        if ((*this)._M_offset-- == 0)
          {
            (*this)._M_offset = (int)::std::_S_word_bit - 1;
             --(*this)._M_p;
          }
      }
      inline void _M_incr(::std::ptrdiff_t __i)
      {
        ::std::iterator< ::std::random_access_iterator_tag, bool>::difference_type __n(__i + (*this)._M_offset);
        (*this)._M_p += __n / (int)::std::_S_word_bit;
        __n = __n % (int)::std::_S_word_bit;
        if (__n < 0)
          {
            __n += (int)::std::_S_word_bit;
             --(*this)._M_p;
          }
        (*this)._M_offset = static_cast<unsigned int>(__n);
      }
      inline bool operator ==(const ::std::_Bit_iterator_base &__i) const 
      {
        return (*this)._M_p == __i._M_p && (*this)._M_offset == __i._M_offset;
      }
      inline bool operator <(const ::std::_Bit_iterator_base &__i) const 
      {
        return (*this)._M_p < __i._M_p || ((*this)._M_p == __i._M_p && (*this)._M_offset < __i._M_offset);
      }
      inline bool operator !=(const ::std::_Bit_iterator_base &__i) const 
      {
        return !(*this == __i);
      }
      inline bool operator >(const ::std::_Bit_iterator_base &__i) const 
      {
        return __i < *this;
      }
      inline bool operator <=(const ::std::_Bit_iterator_base &__i) const 
      {
        return !(__i < *this);
      }
      inline bool operator >=(const ::std::_Bit_iterator_base &__i) const 
      {
        return !(*this < __i);
      }
  };
  inline ::std::ptrdiff_t operator -(const ::std::_Bit_iterator_base &__x, const ::std::_Bit_iterator_base &__y)
  {
    return (int)::std::_S_word_bit * (__x._M_p - __y._M_p) + __x._M_offset - __y._M_offset;
  }
  struct  _Bit_iterator : ::std::_Bit_iterator_base
  {
      typedef ::std::_Bit_reference reference;
      typedef ::std::_Bit_reference *pointer;
      typedef ::std::_Bit_iterator iterator;
      inline _Bit_iterator()
        : ::std::_Bit_iterator_base(0, 0)
      {
      }
      inline _Bit_iterator(::std::_Bit_type *__x, unsigned int __y)
        : ::std::_Bit_iterator_base(__x, __y)
      {
      }
      inline ::std::_Bit_iterator::iterator _M_const_cast() const 
      {
        return *this;
      }
      inline ::std::_Bit_iterator::reference operator *() const 
      {
        return ::std::_Bit_reference((*this)._M_p, 1LU << (*this)._M_offset);
      }
      inline ::std::_Bit_iterator::iterator &operator ++()
      {
        (*this).::std::_Bit_iterator_base::_M_bump_up();
        return *this;
      }
      inline ::std::_Bit_iterator::iterator operator ++(int)
      {
        ::std::_Bit_iterator::iterator __tmp((*this));
        (*this).::std::_Bit_iterator_base::_M_bump_up();
        return __tmp;
      }
      inline ::std::_Bit_iterator::iterator &operator --()
      {
        (*this).::std::_Bit_iterator_base::_M_bump_down();
        return *this;
      }
      inline ::std::_Bit_iterator::iterator operator --(int)
      {
        ::std::_Bit_iterator::iterator __tmp((*this));
        (*this).::std::_Bit_iterator_base::_M_bump_down();
        return __tmp;
      }
      inline ::std::_Bit_iterator::iterator &operator +=(::std::iterator< ::std::random_access_iterator_tag, bool>::difference_type __i)
      {
        (*this).::std::_Bit_iterator_base::_M_incr(__i);
        return *this;
      }
      inline ::std::_Bit_iterator::iterator &operator -=(::std::iterator< ::std::random_access_iterator_tag, bool>::difference_type __i)
      {
        *this +=  -__i;
        return *this;
      }
      inline ::std::_Bit_iterator::iterator operator +(::std::iterator< ::std::random_access_iterator_tag, bool>::difference_type __i) const 
      {
        ::std::_Bit_iterator::iterator __tmp((*this));
        return __tmp += __i;
      }
      inline ::std::_Bit_iterator::iterator operator -(::std::iterator< ::std::random_access_iterator_tag, bool>::difference_type __i) const 
      {
        ::std::_Bit_iterator::iterator __tmp((*this));
        return __tmp -= __i;
      }
      inline ::std::_Bit_iterator::reference operator [](::std::iterator< ::std::random_access_iterator_tag, bool>::difference_type __i) const 
      {
        return  *(*this + __i);
      }
  };
  inline ::std::_Bit_iterator operator +(::std::ptrdiff_t __n, const ::std::_Bit_iterator &__x)
  {
    return __x + __n;
  }
  struct  _Bit_const_iterator : ::std::_Bit_iterator_base
  {
      typedef bool reference;
      typedef bool const_reference;
      typedef const bool *pointer;
      typedef ::std::_Bit_const_iterator const_iterator;
      inline _Bit_const_iterator()
        : ::std::_Bit_iterator_base(0, 0)
      {
      }
      inline _Bit_const_iterator(::std::_Bit_type *__x, unsigned int __y)
        : ::std::_Bit_iterator_base(__x, __y)
      {
      }
      inline _Bit_const_iterator(const ::std::_Bit_iterator &__x)
        : ::std::_Bit_iterator_base(__x._M_p, __x._M_offset)
      {
      }
      inline ::std::_Bit_iterator _M_const_cast() const 
      {
        return ::std::_Bit_iterator((*this)._M_p, (*this)._M_offset);
      }
      inline ::std::_Bit_const_iterator::const_reference operator *() const 
      {
        return ::std::_Bit_reference((*this)._M_p, 1LU << (*this)._M_offset);
      }
      inline ::std::_Bit_const_iterator::const_iterator &operator ++()
      {
        (*this).::std::_Bit_iterator_base::_M_bump_up();
        return *this;
      }
      inline ::std::_Bit_const_iterator::const_iterator operator ++(int)
      {
        ::std::_Bit_const_iterator::const_iterator __tmp((*this));
        (*this).::std::_Bit_iterator_base::_M_bump_up();
        return __tmp;
      }
      inline ::std::_Bit_const_iterator::const_iterator &operator --()
      {
        (*this).::std::_Bit_iterator_base::_M_bump_down();
        return *this;
      }
      inline ::std::_Bit_const_iterator::const_iterator operator --(int)
      {
        ::std::_Bit_const_iterator::const_iterator __tmp((*this));
        (*this).::std::_Bit_iterator_base::_M_bump_down();
        return __tmp;
      }
      inline ::std::_Bit_const_iterator::const_iterator &operator +=(::std::iterator< ::std::random_access_iterator_tag, bool>::difference_type __i)
      {
        (*this).::std::_Bit_iterator_base::_M_incr(__i);
        return *this;
      }
      inline ::std::_Bit_const_iterator::const_iterator &operator -=(::std::iterator< ::std::random_access_iterator_tag, bool>::difference_type __i)
      {
        *this +=  -__i;
        return *this;
      }
      inline ::std::_Bit_const_iterator::const_iterator operator +(::std::iterator< ::std::random_access_iterator_tag, bool>::difference_type __i) const 
      {
        ::std::_Bit_const_iterator::const_iterator __tmp((*this));
        return __tmp += __i;
      }
      inline ::std::_Bit_const_iterator::const_iterator operator -(::std::iterator< ::std::random_access_iterator_tag, bool>::difference_type __i) const 
      {
        ::std::_Bit_const_iterator::const_iterator __tmp((*this));
        return __tmp -= __i;
      }
      inline ::std::_Bit_const_iterator::const_reference operator [](::std::iterator< ::std::random_access_iterator_tag, bool>::difference_type __i) const 
      {
        return  *(*this + __i);
      }
  };
  inline ::std::_Bit_const_iterator operator +(::std::ptrdiff_t __n, const ::std::_Bit_const_iterator &__x)
  {
    return __x + __n;
  }
  inline void __fill_bvector(::std::_Bit_iterator __first, ::std::_Bit_iterator __last, bool __x)
  {
    for (; __first != __last;  ++__first)
      {
         *__first = __x;
      }
  }
 /* Instantiation of template function 'void ::std::fill<unsigned long int *, int>(unsigned long int *, unsigned long int *, const int &)' */ 
  inline void fill(::std::_Bit_iterator __first, ::std::_Bit_iterator __last, const bool &__x)
  {
    if (__first._M_p != __last._M_p)
      {
        std::fill(__first._M_p + 1, __last._M_p, __x ? ~0 : 0);
        ::std::__fill_bvector(__first, ::std::_Bit_iterator(__first._M_p + 1, 0), __x);
        ::std::__fill_bvector(::std::_Bit_iterator(__last._M_p, 0), __last, __x);
      }
    else
      {
        ::std::__fill_bvector(__first, __last, __x);
      }
  }
  template < typename _Alloc >
  struct  _Bvector_base
  {
      typedef typename ::__gnu_cxx::__alloc_traits<_Alloc>::template rebind< ::std::_Bit_type>::other _Bit_alloc_type;
      typedef ::__gnu_cxx::__alloc_traits<typename ::std::_Bvector_base<_Alloc>::_Bit_alloc_type> _Bit_alloc_traits;
      typedef typename ::__gnu_cxx::__alloc_traits<typename ::std::_Bvector_base<_Alloc>::_Bit_alloc_type>::pointer _Bit_pointer;
      struct  _Bvector_impl : ::std::_Bvector_base<_Alloc>::_Bit_alloc_type
      {
          ::std::_Bit_iterator _M_start;
          ::std::_Bit_iterator _M_finish;
          typename ::std::_Bvector_base<_Alloc>::_Bit_pointer _M_end_of_storage;
          inline _Bvector_impl()
            : _Bit_alloc_type(), _M_start(), _M_finish(), _M_end_of_storage()
          {
          }
          inline _Bvector_impl(const typename ::std::_Bvector_base<_Alloc>::_Bit_alloc_type &__a)
            : _Bit_alloc_type(__a), _M_start(), _M_finish(), _M_end_of_storage()
          {
          }
          inline ::std::_Bit_type *_M_end_addr() const 
          {
            if (::std::_Bvector_base<_Alloc>::_Bvector_impl::_M_end_of_storage)
              {
                return std::__addressof(::std::_Bvector_base<_Alloc>::_Bvector_impl::_M_end_of_storage[ -1]) + 1;
              }
            return 0;
          }
      };
      typedef _Alloc allocator_type;
      inline typename ::std::_Bvector_base<_Alloc>::_Bit_alloc_type &_M_get_Bit_allocator()
      {
        return *static_cast<typename ::std::_Bvector_base<_Alloc>::_Bit_alloc_type *>(&this->_M_impl);
      }
      inline const typename ::std::_Bvector_base<_Alloc>::_Bit_alloc_type &_M_get_Bit_allocator() const 
      {
        return *static_cast<const typename ::std::_Bvector_base<_Alloc>::_Bit_alloc_type *>(&this->_M_impl);
      }
      inline typename ::std::_Bvector_base<_Alloc>::allocator_type get_allocator() const 
      {
        return ((typename ::std::_Bvector_base<_Alloc>::allocator_type((*this)._M_get_Bit_allocator())));
      }
      inline _Bvector_base()
        : _M_impl()
      {
      }
      inline _Bvector_base(const typename ::std::_Bvector_base<_Alloc>::allocator_type &__a)
        : _M_impl(__a)
      {
      }
      inline ~_Bvector_base()
      {
        this->_M_deallocate();
      }
    protected:
      typename ::std::_Bvector_base<_Alloc>::_Bvector_impl _M_impl;
      inline typename ::std::_Bvector_base<_Alloc>::_Bit_pointer _M_allocate(::std::size_t __n)
      {
        return _Bit_alloc_traits::allocate(::std::_Bvector_base<_Alloc>::_M_impl, _S_nword(__n));
      }
      inline void _M_deallocate()
      {
        if (::std::_Bvector_base<_Alloc>::_M_impl._M_start._M_p)
          {
            const ::std::size_t __n = ::std::_Bvector_base<_Alloc>::_M_impl._M_end_addr() - ::std::_Bvector_base<_Alloc>::_M_impl._M_start._M_p;
            _Bit_alloc_traits::deallocate(::std::_Bvector_base<_Alloc>::_M_impl, ::std::_Bvector_base<_Alloc>::_M_impl._M_end_of_storage - __n, __n);
            ::std::_Bvector_base<_Alloc>::_M_impl._M_start = ::std::_Bvector_base<_Alloc>::_M_impl._M_finish = ::std::_Bit_iterator();
            ::std::_Bvector_base<_Alloc>::_M_impl._M_end_of_storage = ((typename ::std::_Bvector_base<_Alloc>::_Bit_pointer()));
          }
      }
      static inline ::std::size_t _S_nword(::std::size_t __n)
      {
        return (__n + (int)::std::_S_word_bit - 1) / (int)::std::_S_word_bit;
      }
  };
 /* Instantiation of class template '::std::iterator_traits< ::std::_Bit_iterator>' */ 
 /* Instantiation of class template '::std::iterator< ::std::random_access_iterator_tag, bool, long int, ::std::_Bit_reference *, ::std::_Bit_reference>' */ 
 /* Instantiation of class template '::std::reverse_iterator< ::std::_Bit_iterator>' */ 
 /* Instantiation of class template '::std::iterator_traits< ::std::_Bit_const_iterator>' */ 
 /* Instantiation of class template '::std::iterator< ::std::random_access_iterator_tag, bool, long int, const bool *, bool>' */ 
 /* Instantiation of class template '::std::reverse_iterator< ::std::_Bit_const_iterator>' */ 
 /* Instantiation of class template '::__gnu_cxx::__conditional_type<true, ::__gnu_cxx::__numeric_traits_integer<long int>, ::__gnu_cxx::__numeric_traits_floating<long int> >' */ 
 /* Instantiation of class template '::__gnu_cxx::__numeric_traits_integer<long int>' */ 
 /* Instantiation of class template '::__gnu_cxx::__numeric_traits<long int>' */ 
  template < typename _Alloc >
  class  vector<bool, _Alloc> : protected ::std::_Bvector_base<_Alloc>
  {
      typedef ::std::_Bvector_base<_Alloc> _Base;
      typedef typename ::std::_Bvector_base<_Alloc>::_Bit_pointer _Bit_pointer;
      typedef typename ::std::_Bvector_base<_Alloc>::_Bit_alloc_traits _Bit_alloc_traits;
    public:
      typedef bool value_type;
      typedef ::std::size_t size_type;
      typedef ::std::ptrdiff_t difference_type;
      typedef ::std::_Bit_reference reference;
      typedef bool const_reference;
      typedef ::std::_Bit_reference *pointer;
      typedef const bool *const_pointer;
      typedef ::std::_Bit_iterator iterator;
      typedef ::std::_Bit_const_iterator const_iterator;
      typedef ::std::reverse_iterator< ::std::_Bit_const_iterator> const_reverse_iterator;
      typedef ::std::reverse_iterator< ::std::_Bit_iterator> reverse_iterator;
      typedef _Alloc allocator_type;
      inline typename ::std::vector<bool, _Alloc>::allocator_type get_allocator() const 
      {
        return _Base::get_allocator();
      }
    protected:
      using _Base::_M_allocate;
      using _Base::_M_deallocate;
      using _Base::_S_nword;
      using _Base::_M_get_Bit_allocator;
    public:
      inline vector()
        : _Base()
      {
      }
      inline explicit vector(const typename ::std::vector<bool, _Alloc>::allocator_type &__a)
        : _Base(__a)
      {
      }
      inline explicit vector(typename ::std::vector<bool, _Alloc>::size_type __n, const bool &__value  = (bool()), const typename ::std::vector<bool, _Alloc>::allocator_type &__a  = (((typename ::std::vector<bool, _Alloc>::allocator_type()))))
        : _Base(__a)
      {
        (*this)._M_initialize(__n);
        std::fill(this->_M_impl._M_start._M_p, this->_M_impl._M_end_addr(), __value ? ~0 : 0);
      }
      inline vector(const ::std::vector<bool, _Alloc> &__x)
        : _Base(_Bit_alloc_traits::_S_select_on_copy(__x._M_get_Bit_allocator()))
      {
        (*this)._M_initialize(__x.size());
        (*this)._M_copy_aligned(__x.begin(), __x.end(), this->_M_impl._M_start);
      }
      template < typename _InputIterator >
      inline vector(_InputIterator __first, _InputIterator __last, const typename ::std::vector<bool, _Alloc>::allocator_type &__a  = (((typename ::std::vector<bool, _Alloc>::allocator_type()))))
        : _Base(__a)
      {
        typedef typename ::std::__is_integer<_InputIterator>::__type _Integral;
        (*this)._M_initialize_dispatch(__first, __last, _Integral());
      }
      inline ~vector()
      {
      }
      inline ::std::vector<bool, _Alloc> &operator =(const ::std::vector<bool, _Alloc> &__x)
      {
        if (&__x == this)
          {
            return *this;
          }
        if (__x.size() > (*this).capacity())
          {
            this->_M_deallocate();
            (*this)._M_initialize(__x.size());
          }
        this->_M_impl._M_finish = (*this)._M_copy_aligned(__x.begin(), __x.end(), (*this).begin());
        return *this;
      }
      inline void assign(typename ::std::vector<bool, _Alloc>::size_type __n, const bool &__x)
      {
        (*this)._M_fill_assign(__n, __x);
      }
      template < typename _InputIterator >
      inline void assign(_InputIterator __first, _InputIterator __last)
      {
        typedef typename ::std::__is_integer<_InputIterator>::__type _Integral;
        (*this)._M_assign_dispatch(__first, __last, _Integral());
      }
      inline typename ::std::vector<bool, _Alloc>::iterator begin()
      {
        return this->_M_impl._M_start;
      }
      inline typename ::std::vector<bool, _Alloc>::const_iterator begin() const 
      {
        return this->_M_impl._M_start;
      }
      inline typename ::std::vector<bool, _Alloc>::iterator end()
      {
        return this->_M_impl._M_finish;
      }
      inline typename ::std::vector<bool, _Alloc>::const_iterator end() const 
      {
        return this->_M_impl._M_finish;
      }
      inline typename ::std::vector<bool, _Alloc>::reverse_iterator rbegin()
      {
        return ((typename ::std::vector<bool, _Alloc>::reverse_iterator((*this).end())));
      }
      inline typename ::std::vector<bool, _Alloc>::const_reverse_iterator rbegin() const 
      {
        return ((typename ::std::vector<bool, _Alloc>::const_reverse_iterator((*this).end())));
      }
      inline typename ::std::vector<bool, _Alloc>::reverse_iterator rend()
      {
        return ((typename ::std::vector<bool, _Alloc>::reverse_iterator((*this).begin())));
      }
      inline typename ::std::vector<bool, _Alloc>::const_reverse_iterator rend() const 
      {
        return ((typename ::std::vector<bool, _Alloc>::const_reverse_iterator((*this).begin())));
      }
      inline typename ::std::vector<bool, _Alloc>::size_type size() const 
      {
        return ((typename ::std::vector<bool, _Alloc>::size_type((*this).end() - (*this).begin())));
      }
      inline typename ::std::vector<bool, _Alloc>::size_type max_size() const 
      {
        const typename ::std::vector<bool, _Alloc>::size_type __isize(::__gnu_cxx::__numeric_traits_integer<long int>::__max - (int)::std::_S_word_bit + 1);
        const typename ::std::vector<bool, _Alloc>::size_type __asize = _Bit_alloc_traits::max_size((_M_get_Bit_allocator)());
        return __asize <= __isize / (int)::std::_S_word_bit ? __asize * (int)::std::_S_word_bit : __isize;
      }
      inline typename ::std::vector<bool, _Alloc>::size_type capacity() const 
      {
        return ((typename ::std::vector<bool, _Alloc>::size_type(((typename ::std::vector<bool, _Alloc>::const_iterator(this->_M_impl._M_end_addr(), 0))) - (*this).begin())));
      }
      inline bool empty() const 
      {
        return (*this).begin() == (*this).end();
      }
      inline typename ::std::vector<bool, _Alloc>::reference operator [](typename ::std::vector<bool, _Alloc>::size_type __n)
      {
        return  *((typename ::std::vector<bool, _Alloc>::iterator(this->_M_impl._M_start._M_p + __n / (int)::std::_S_word_bit, __n % (int)::std::_S_word_bit)));
      }
      inline typename ::std::vector<bool, _Alloc>::const_reference operator [](typename ::std::vector<bool, _Alloc>::size_type __n) const 
      {
        return  *((typename ::std::vector<bool, _Alloc>::const_iterator(this->_M_impl._M_start._M_p + __n / (int)::std::_S_word_bit, __n % (int)::std::_S_word_bit)));
      }
    protected:
      inline void _M_range_check(typename ::std::vector<bool, _Alloc>::size_type __n) const 
      {
        if (__n >= this->size())
          {
            __throw_out_of_range_fmt("vector<bool>::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)", __n, this->size());
          }
      }
    public:
      inline typename ::std::vector<bool, _Alloc>::reference at(typename ::std::vector<bool, _Alloc>::size_type __n)
      {
        (*this)._M_range_check(__n);
        return (*this)[__n];
      }
      inline typename ::std::vector<bool, _Alloc>::const_reference at(typename ::std::vector<bool, _Alloc>::size_type __n) const 
      {
        (*this)._M_range_check(__n);
        return (*this)[__n];
      }
      inline void reserve(typename ::std::vector<bool, _Alloc>::size_type __n)
      {
        if (__n > (*this).max_size())
          {
            ::std::__throw_length_error("vector::reserve");
          }
        if ((*this).capacity() < __n)
          {
            (*this)._M_reallocate(__n);
          }
      }
      inline typename ::std::vector<bool, _Alloc>::reference front()
      {
        return *(*this).begin();
      }
      inline typename ::std::vector<bool, _Alloc>::const_reference front() const 
      {
        return *(*this).begin();
      }
      inline typename ::std::vector<bool, _Alloc>::reference back()
      {
        return *((*this).end() - 1);
      }
      inline typename ::std::vector<bool, _Alloc>::const_reference back() const 
      {
        return *((*this).end() - 1);
      }
      inline void data()
      {
      }
      inline void push_back(bool __x)
      {
        if (this->_M_impl._M_finish._M_p != this->_M_impl._M_end_addr())
          {
            *this->_M_impl._M_finish++ = __x;
          }
        else
          {
            (*this)._M_insert_aux((*this).end(), __x);
          }
      }
      inline void swap(::std::vector<bool, _Alloc> &__x)
      {
        std::swap(this->_M_impl._M_start, __x._M_impl._M_start);
        std::swap(this->_M_impl._M_finish, __x._M_impl._M_finish);
        std::swap(this->_M_impl._M_end_of_storage, __x._M_impl._M_end_of_storage);
        _Bit_alloc_traits::_S_on_swap((_M_get_Bit_allocator)(), __x._M_get_Bit_allocator());
      }
      static inline void swap(typename ::std::vector<bool, _Alloc>::reference __x, typename ::std::vector<bool, _Alloc>::reference __y)
      {
        bool __tmp(__x);
        __x = __y;
        __y = __tmp;
      }
      inline typename ::std::vector<bool, _Alloc>::iterator insert(typename ::std::vector<bool, _Alloc>::iterator __position, const bool &__x  = (bool()))
      {
        const typename ::std::vector<bool, _Alloc>::difference_type __n = __position - (*this).begin();
        if (this->_M_impl._M_finish._M_p != this->_M_impl._M_end_addr() && __position == (*this).end())
          {
            *this->_M_impl._M_finish++ = __x;
          }
        else
          {
            (*this)._M_insert_aux(__position.::std::_Bit_iterator::_M_const_cast(), __x);
          }
        return (*this).begin() + __n;
      }
      template < typename _InputIterator >
      inline void insert(typename ::std::vector<bool, _Alloc>::iterator __position, _InputIterator __first, _InputIterator __last)
      {
        typedef typename ::std::__is_integer<_InputIterator>::__type _Integral;
        (*this)._M_insert_dispatch(__position, __first, __last, _Integral());
      }
      inline void insert(typename ::std::vector<bool, _Alloc>::iterator __position, typename ::std::vector<bool, _Alloc>::size_type __n, const bool &__x)
      {
        (*this)._M_fill_insert(__position, __n, __x);
      }
      inline void pop_back()
      {
         --this->_M_impl._M_finish;
      }
      inline typename ::std::vector<bool, _Alloc>::iterator erase(typename ::std::vector<bool, _Alloc>::iterator __position)
      {
        return (*this)._M_erase(__position.::std::_Bit_iterator::_M_const_cast());
      }
      inline typename ::std::vector<bool, _Alloc>::iterator erase(typename ::std::vector<bool, _Alloc>::iterator __first, typename ::std::vector<bool, _Alloc>::iterator __last)
      {
        return (*this)._M_erase(__first.::std::_Bit_iterator::_M_const_cast(), __last.::std::_Bit_iterator::_M_const_cast());
      }
      inline void resize(typename ::std::vector<bool, _Alloc>::size_type __new_size, bool __x  = (bool()))
      {
        if (__new_size < (*this).size())
          {
            (*this)._M_erase_at_end((*this).begin() + (typename ::std::vector<bool, _Alloc>::difference_type)__new_size);
          }
        else
          {
            (*this).insert((*this).end(), __new_size - (*this).size(), __x);
          }
      }
      inline void flip()
      {
        ::std::_Bit_type *const __end = this->_M_impl._M_end_addr();
        for (::std::_Bit_type *__p = this->_M_impl._M_start._M_p; __p != __end;  ++__p)
          {
            *__p = ~*__p;
          }
      }
      inline void clear()
      {
        (*this)._M_erase_at_end((*this).begin());
      }
    protected:
      inline typename ::std::vector<bool, _Alloc>::iterator _M_copy_aligned(typename ::std::vector<bool, _Alloc>::const_iterator __first, typename ::std::vector<bool, _Alloc>::const_iterator __last, typename ::std::vector<bool, _Alloc>::iterator __result)
      {
        ::std::_Bit_type *__q(std::copy(__first._M_p, __last._M_p, __result._M_p));
        return std::copy(::std::_Bit_const_iterator(__last._M_p, 0), __last, ::std::_Bit_iterator(__q, 0));
      }
      inline void _M_initialize(typename ::std::vector<bool, _Alloc>::size_type __n)
      {
        if (__n)
          {
            typename ::std::vector<bool, _Alloc>::_Bit_pointer __q = this->_M_allocate(__n);
            this->_M_impl._M_end_of_storage = __q + (_S_nword)(__n);
            this->_M_impl._M_start = ((typename ::std::vector<bool, _Alloc>::iterator(std::__addressof(*__q), 0)));
          }
        else
          {
            this->_M_impl._M_end_of_storage = ((typename ::std::vector<bool, _Alloc>::_Bit_pointer()));
            this->_M_impl._M_start = ::std::_Bit_iterator(0, 0);
          }
        this->_M_impl._M_finish = this->_M_impl._M_start + (typename ::std::vector<bool, _Alloc>::difference_type)__n;
      }
      void _M_reallocate(typename ::std::vector<bool, _Alloc>::size_type __n);
      template < typename _Integer >
      inline void _M_initialize_dispatch(_Integer __n, _Integer __x, ::std::__true_type)
      {
        (*this)._M_initialize(static_cast<typename ::std::vector<bool, _Alloc>::size_type>(__n));
        std::fill(this->_M_impl._M_start._M_p, this->_M_impl._M_end_addr(), __x ? ~0 : 0);
      }
      template < typename _InputIterator >
      inline void _M_initialize_dispatch(_InputIterator __first, _InputIterator __last, ::std::__false_type)
      {
        (*this)._M_initialize_range(__first, __last, std::__iterator_category(__first));
      }
      template < typename _InputIterator >
      inline void _M_initialize_range(_InputIterator __first, _InputIterator __last, ::std::input_iterator_tag)
      {
        for (; __first != __last;  ++__first)
          {
            (*this).push_back(*__first);
          }
      }
      template < typename _ForwardIterator >
      inline void _M_initialize_range(_ForwardIterator __first, _ForwardIterator __last, ::std::forward_iterator_tag)
      {
        const typename ::std::vector<bool, _Alloc>::size_type __n = std::distance(__first, __last);
        (*this)._M_initialize(__n);
        std::copy(__first, __last, this->_M_impl._M_start);
      }
      template < typename _Integer >
      inline void _M_assign_dispatch(_Integer __n, _Integer __val, ::std::__true_type)
      {
        (*this)._M_fill_assign(__n, __val);
      }
      template < typename _InputIterator >
      inline void _M_assign_dispatch(_InputIterator __first, _InputIterator __last, ::std::__false_type)
      {
        (*this)._M_assign_aux(__first, __last, std::__iterator_category(__first));
      }
      inline void _M_fill_assign(::std::size_t __n, bool __x)
      {
        if (__n > (*this).size())
          {
            std::fill(this->_M_impl._M_start._M_p, this->_M_impl._M_end_addr(), __x ? ~0 : 0);
            (*this).insert((*this).end(), __n - (*this).size(), __x);
          }
        else
          {
            (*this)._M_erase_at_end((*this).begin() + __n);
            std::fill(this->_M_impl._M_start._M_p, this->_M_impl._M_end_addr(), __x ? ~0 : 0);
          }
      }
      template < typename _InputIterator >
      inline void _M_assign_aux(_InputIterator __first, _InputIterator __last, ::std::input_iterator_tag)
      {
        typename ::std::vector<bool, _Alloc>::iterator __cur = (*this).begin();
        for (; __first != __last && __cur != (*this).end(); ( ++__cur,  ++__first))
          {
             *__cur = *__first;
          }
        if (__first == __last)
          {
            (*this)._M_erase_at_end(__cur);
          }
        else
          {
            (*this).insert((*this).end(), __first, __last);
          }
      }
      template < typename _ForwardIterator >
      inline void _M_assign_aux(_ForwardIterator __first, _ForwardIterator __last, ::std::forward_iterator_tag)
      {
        const typename ::std::vector<bool, _Alloc>::size_type __len = std::distance(__first, __last);
        if (__len < (*this).size())
          {
            (*this)._M_erase_at_end(std::copy(__first, __last, (*this).begin()));
          }
        else
          {
            _ForwardIterator __mid = __first;
            std::advance(__mid, (*this).size());
            std::copy(__first, __mid, (*this).begin());
            (*this).insert((*this).end(), __mid, __last);
          }
      }
      template < typename _Integer >
      inline void _M_insert_dispatch(typename ::std::vector<bool, _Alloc>::iterator __pos, _Integer __n, _Integer __x, ::std::__true_type)
      {
        (*this)._M_fill_insert(__pos, __n, __x);
      }
      template < typename _InputIterator >
      inline void _M_insert_dispatch(typename ::std::vector<bool, _Alloc>::iterator __pos, _InputIterator __first, _InputIterator __last, ::std::__false_type)
      {
        (*this)._M_insert_range(__pos, __first, __last, std::__iterator_category(__first));
      }
      void _M_fill_insert(typename ::std::vector<bool, _Alloc>::iterator __position, typename ::std::vector<bool, _Alloc>::size_type __n, bool __x);
      template < typename _InputIterator >
      inline void _M_insert_range(typename ::std::vector<bool, _Alloc>::iterator __pos, _InputIterator __first, _InputIterator __last, ::std::input_iterator_tag)
      {
        for (; __first != __last;  ++__first)
          {
            __pos = (*this).insert(__pos, *__first);
             ++__pos;
          }
      }
      template < typename _ForwardIterator >
      void _M_insert_range(typename ::std::vector<bool, _Alloc>::iterator __position, _ForwardIterator __first, _ForwardIterator __last, ::std::forward_iterator_tag);
      void _M_insert_aux(typename ::std::vector<bool, _Alloc>::iterator __position, bool __x);
      inline typename ::std::vector<bool, _Alloc>::size_type _M_check_len(typename ::std::vector<bool, _Alloc>::size_type __n, const char *__s) const 
      {
        if ((*this).max_size() - (*this).size() < __n)
          {
            ::std::__throw_length_error(__s);
          }
        const typename ::std::vector<bool, _Alloc>::size_type __len = (*this).size() + std::max((*this).size(), __n);
        return __len < (*this).size() || __len > (*this).max_size() ? (*this).max_size() : __len;
      }
      inline void _M_erase_at_end(typename ::std::vector<bool, _Alloc>::iterator __pos)
      {
        this->_M_impl._M_finish = __pos;
      }
      typename ::std::vector<bool, _Alloc>::iterator _M_erase(typename ::std::vector<bool, _Alloc>::iterator __position);
      typename ::std::vector<bool, _Alloc>::iterator _M_erase(typename ::std::vector<bool, _Alloc>::iterator __first, typename ::std::vector<bool, _Alloc>::iterator __last);
  };
  template < typename _Tp, typename _Alloc >
  void vector<_Tp, _Alloc>::reserve(typename ::std::vector<_Tp, _Alloc>::size_type __n)
  {
    if (__n > this->max_size())
      {
        ::std::__throw_length_error("vector::reserve");
      }
    if (this->capacity() < __n)
      {
        const typename ::std::vector<_Tp, _Alloc>::size_type __old_size = (*this).size();
        typename ::std::vector<_Tp, _Alloc>::pointer __tmp = (*this)._M_allocate_and_copy(__n, this->_M_impl._M_start, this->_M_impl._M_finish);
        std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish, (_M_get_Tp_allocator)());
        _M_deallocate(this->_M_impl._M_start, this->_M_impl._M_end_of_storage - this->_M_impl._M_start);
        this->_M_impl._M_start = __tmp;
        this->_M_impl._M_finish = __tmp + __old_size;
        this->_M_impl._M_end_of_storage = this->_M_impl._M_start + __n;
      }
  }
  template < typename _Tp, typename _Alloc >
  typename ::std::vector<_Tp, _Alloc>::iterator vector<_Tp, _Alloc>::insert(typename ::std::vector<_Tp, _Alloc>::iterator __position, const typename ::std::vector<_Tp, _Alloc>::value_type &__x)
  {
    const typename ::std::vector<_Tp, _Alloc>::size_type __n = __position - (*this).begin();
    if (this->_M_impl._M_finish != this->_M_impl._M_end_of_storage)
      {
        if (__position == (*this).end())
          {
            _Alloc_traits::construct(this->_M_impl, this->_M_impl._M_finish, __x);
             ++this->_M_impl._M_finish;
          }
        else
          {
            (*this)._M_insert_aux(__position, __x);
          }
      }
    else
      {
        (*this)._M_realloc_insert(__position, __x);
      }
    return ((typename ::std::vector<_Tp, _Alloc>::iterator(this->_M_impl._M_start + __n)));
  }
  template < typename _Tp, typename _Alloc >
  typename ::std::vector<_Tp, _Alloc>::iterator vector<_Tp, _Alloc>::_M_erase(typename ::std::vector<_Tp, _Alloc>::iterator __position)
  {
    if (__position + 1 != (*this).end())
      {
        std::copy(__position + 1, (*this).end(), __position);
      }
     --this->_M_impl._M_finish;
    _Alloc_traits::destroy(this->_M_impl, this->_M_impl._M_finish);
    return __position;
  }
  template < typename _Tp, typename _Alloc >
  typename ::std::vector<_Tp, _Alloc>::iterator vector<_Tp, _Alloc>::_M_erase(typename ::std::vector<_Tp, _Alloc>::iterator __first, typename ::std::vector<_Tp, _Alloc>::iterator __last)
  {
    if (__first != __last)
      {
        if (__last != (*this).end())
          {
            std::copy(__last, (*this).end(), __first);
          }
        (*this)._M_erase_at_end(__first.base() + ((*this).end() - __last));
      }
    return __first;
  }
  template < typename _Tp, typename _Alloc >
  ::std::vector<_Tp, _Alloc> &vector<_Tp, _Alloc>::operator =(const ::std::vector<_Tp, _Alloc> &__x)
  {
    if (&__x != this)
      {
        const typename ::std::vector<_Tp, _Alloc>::size_type __xlen = __x.size();
        if (__xlen > (*this).capacity())
          {
            typename ::std::vector<_Tp, _Alloc>::pointer __tmp = (*this)._M_allocate_and_copy(__xlen, __x.begin(), __x.end());
            std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish, (_M_get_Tp_allocator)());
            _M_deallocate(this->_M_impl._M_start, this->_M_impl._M_end_of_storage - this->_M_impl._M_start);
            this->_M_impl._M_start = __tmp;
            this->_M_impl._M_end_of_storage = this->_M_impl._M_start + __xlen;
          }
        else
          {
            if ((*this).size() >= __xlen)
              {
                std::_Destroy(std::copy(__x.begin(), __x.end(), (*this).begin()), (*this).end(), (_M_get_Tp_allocator)());
              }
            else
              {
                std::copy(__x._M_impl._M_start, __x._M_impl._M_start + (*this).size(), this->_M_impl._M_start);
                std::__uninitialized_copy_a(__x._M_impl._M_start + (*this).size(), __x._M_impl._M_finish, this->_M_impl._M_finish, (_M_get_Tp_allocator)());
              }
          }
        this->_M_impl._M_finish = this->_M_impl._M_start + __xlen;
      }
    return *this;
  }
  template < typename _Tp, typename _Alloc >
  void vector<_Tp, _Alloc>::_M_fill_assign(::std::size_t __n, const typename ::std::vector<_Tp, _Alloc>::value_type &__val)
  {
    if (__n > (*this).capacity())
      {
        ::std::vector<_Tp, _Alloc> __tmp(__n, __val, (_M_get_Tp_allocator)());
        __tmp._M_impl._M_swap_data(this->_M_impl);
      }
    else
      {
        if (__n > (*this).size())
          {
            std::fill((*this).begin(), (*this).end(), __val);
            this->_M_impl._M_finish = std::__uninitialized_fill_n_a(this->_M_impl._M_finish, __n - (*this).size(), __val, (_M_get_Tp_allocator)());
          }
        else
          {
            (*this)._M_erase_at_end(std::fill_n(this->_M_impl._M_start, __n, __val));
          }
      }
  }
  template < typename _Tp, typename _Alloc >
  template < typename _InputIterator >
  void vector<_Tp, _Alloc>::_M_assign_aux(_InputIterator __first, _InputIterator __last, ::std::input_iterator_tag)
  {
    typename ::std::vector<_Tp, _Alloc>::pointer __cur(this->_M_impl._M_start);
    for (; __first != __last && __cur != this->_M_impl._M_finish; ( ++__cur,  ++__first))
      {
        *__cur = *__first;
      }
    if (__first == __last)
      {
        (*this)._M_erase_at_end(__cur);
      }
    else
      {
        (*this)._M_range_insert((*this).end(), __first, __last, std::__iterator_category(__first));
      }
  }
  template < typename _Tp, typename _Alloc >
  template < typename _ForwardIterator >
  void vector<_Tp, _Alloc>::_M_assign_aux(_ForwardIterator __first, _ForwardIterator __last, ::std::forward_iterator_tag)
  {
    const typename ::std::vector<_Tp, _Alloc>::size_type __len = std::distance(__first, __last);
    if (__len > (*this).capacity())
      {
        typename ::std::vector<_Tp, _Alloc>::pointer __tmp((*this)._M_allocate_and_copy(__len, __first, __last));
        std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish, (_M_get_Tp_allocator)());
        _M_deallocate(this->_M_impl._M_start, this->_M_impl._M_end_of_storage - this->_M_impl._M_start);
        this->_M_impl._M_start = __tmp;
        this->_M_impl._M_finish = this->_M_impl._M_start + __len;
        this->_M_impl._M_end_of_storage = this->_M_impl._M_finish;
      }
    else
      {
        if ((*this).size() >= __len)
          {
            (*this)._M_erase_at_end(std::copy(__first, __last, this->_M_impl._M_start));
          }
        else
          {
            _ForwardIterator __mid = __first;
            std::advance(__mid, (*this).size());
            std::copy(__first, __mid, this->_M_impl._M_start);
            this->_M_impl._M_finish = std::__uninitialized_copy_a(__mid, __last, this->_M_impl._M_finish, (_M_get_Tp_allocator)());
          }
      }
  }
  template < typename _Tp, typename _Alloc >
  void vector<_Tp, _Alloc>::_M_insert_aux(typename ::std::vector<_Tp, _Alloc>::iterator __position, const _Tp &__x)
  {
    _Alloc_traits::construct(this->_M_impl, this->_M_impl._M_finish, *(this->_M_impl._M_finish - 1));
     ++this->_M_impl._M_finish;
    _Tp __x_copy = __x;
    std::copy_backward(__position.base(), this->_M_impl._M_finish - 2, this->_M_impl._M_finish - 1);
    *__position = __x_copy;
  }
  template < typename _Tp, typename _Alloc >
  void vector<_Tp, _Alloc>::_M_realloc_insert(typename ::std::vector<_Tp, _Alloc>::iterator __position, const _Tp &__x)
  {
    const typename ::std::vector<_Tp, _Alloc>::size_type __len = (*this)._M_check_len((typename ::std::vector<_Tp, _Alloc>::size_type)1, "vector::_M_realloc_insert");
    const typename ::std::vector<_Tp, _Alloc>::size_type __elems_before = __position - (*this).begin();
    typename ::std::vector<_Tp, _Alloc>::pointer __new_start(this->_M_allocate(__len));
    typename ::std::vector<_Tp, _Alloc>::pointer __new_finish(__new_start);
    try
    {
      _Alloc_traits::construct(this->_M_impl, __new_start + __elems_before, __x);
      __new_finish = ((typename ::std::vector<_Tp, _Alloc>::pointer()));
      __new_finish = std::__uninitialized_move_if_noexcept_a(this->_M_impl._M_start, __position.base(), __new_start, (_M_get_Tp_allocator)());
       ++__new_finish;
      __new_finish = std::__uninitialized_move_if_noexcept_a(__position.base(), this->_M_impl._M_finish, __new_finish, (_M_get_Tp_allocator)());
    }
    catch (...)
    {
      if (!__new_finish)
        {
          _Alloc_traits::destroy(this->_M_impl, __new_start + __elems_before);
        }
      else
        {
          std::_Destroy(__new_start, __new_finish, (_M_get_Tp_allocator)());
        }
      _M_deallocate(__new_start, __len);
      throw;
    }
    std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish, (_M_get_Tp_allocator)());
    _M_deallocate(this->_M_impl._M_start, this->_M_impl._M_end_of_storage - this->_M_impl._M_start);
    this->_M_impl._M_start = __new_start;
    this->_M_impl._M_finish = __new_finish;
    this->_M_impl._M_end_of_storage = __new_start + __len;
  }
  template < typename _Tp, typename _Alloc >
  void vector<_Tp, _Alloc>::_M_fill_insert(typename ::std::vector<_Tp, _Alloc>::iterator __position, typename ::std::vector<_Tp, _Alloc>::size_type __n, const typename ::std::vector<_Tp, _Alloc>::value_type &__x)
  {
    if (__n != 0)
      {
        if (((typename ::std::vector<_Tp, _Alloc>::size_type(this->_M_impl._M_end_of_storage - this->_M_impl._M_finish))) >= __n)
          {
            typename ::std::vector<_Tp, _Alloc>::value_type __x_copy = __x;
            const typename ::std::vector<_Tp, _Alloc>::size_type __elems_after = (*this).end() - __position;
            typename ::std::vector<_Tp, _Alloc>::pointer __old_finish(this->_M_impl._M_finish);
            if (__elems_after > __n)
              {
                std::__uninitialized_move_a(this->_M_impl._M_finish - __n, this->_M_impl._M_finish, this->_M_impl._M_finish, (_M_get_Tp_allocator)());
                this->_M_impl._M_finish += __n;
                std::copy_backward(__position.base(), __old_finish - __n, __old_finish);
                std::fill(__position.base(), __position.base() + __n, __x_copy);
              }
            else
              {
                this->_M_impl._M_finish = std::__uninitialized_fill_n_a(this->_M_impl._M_finish, __n - __elems_after, __x_copy, (_M_get_Tp_allocator)());
                std::__uninitialized_move_a(__position.base(), __old_finish, this->_M_impl._M_finish, (_M_get_Tp_allocator)());
                this->_M_impl._M_finish += __elems_after;
                std::fill(__position.base(), __old_finish, __x_copy);
              }
          }
        else
          {
            const typename ::std::vector<_Tp, _Alloc>::size_type __len = (*this)._M_check_len(__n, "vector::_M_fill_insert");
            const typename ::std::vector<_Tp, _Alloc>::size_type __elems_before = __position - (*this).begin();
            typename ::std::vector<_Tp, _Alloc>::pointer __new_start(this->_M_allocate(__len));
            typename ::std::vector<_Tp, _Alloc>::pointer __new_finish(__new_start);
            try
            {
              std::__uninitialized_fill_n_a(__new_start + __elems_before, __n, __x, (_M_get_Tp_allocator)());
              __new_finish = ((typename ::std::vector<_Tp, _Alloc>::pointer()));
              __new_finish = std::__uninitialized_move_if_noexcept_a(this->_M_impl._M_start, __position.base(), __new_start, (_M_get_Tp_allocator)());
              __new_finish += __n;
              __new_finish = std::__uninitialized_move_if_noexcept_a(__position.base(), this->_M_impl._M_finish, __new_finish, (_M_get_Tp_allocator)());
            }
            catch (...)
            {
              if (!__new_finish)
                {
                  std::_Destroy(__new_start + __elems_before, __new_start + __elems_before + __n, (_M_get_Tp_allocator)());
                }
              else
                {
                  std::_Destroy(__new_start, __new_finish, (_M_get_Tp_allocator)());
                }
              _M_deallocate(__new_start, __len);
              throw;
            }
            std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish, (_M_get_Tp_allocator)());
            _M_deallocate(this->_M_impl._M_start, this->_M_impl._M_end_of_storage - this->_M_impl._M_start);
            this->_M_impl._M_start = __new_start;
            this->_M_impl._M_finish = __new_finish;
            this->_M_impl._M_end_of_storage = __new_start + __len;
          }
      }
  }
  template < typename _Tp, typename _Alloc >
  template < typename _InputIterator >
  void vector<_Tp, _Alloc>::_M_range_insert(typename ::std::vector<_Tp, _Alloc>::iterator __pos, _InputIterator __first, _InputIterator __last, ::std::input_iterator_tag)
  {
    for (; __first != __last;  ++__first)
      {
        __pos = (*this).insert(__pos, *__first);
         ++__pos;
      }
  }
  template < typename _Tp, typename _Alloc >
  template < typename _ForwardIterator >
  void vector<_Tp, _Alloc>::_M_range_insert(typename ::std::vector<_Tp, _Alloc>::iterator __position, _ForwardIterator __first, _ForwardIterator __last, ::std::forward_iterator_tag)
  {
    if (__first != __last)
      {
        const typename ::std::vector<_Tp, _Alloc>::size_type __n = std::distance(__first, __last);
        if (((typename ::std::vector<_Tp, _Alloc>::size_type(this->_M_impl._M_end_of_storage - this->_M_impl._M_finish))) >= __n)
          {
            const typename ::std::vector<_Tp, _Alloc>::size_type __elems_after = (*this).end() - __position;
            typename ::std::vector<_Tp, _Alloc>::pointer __old_finish(this->_M_impl._M_finish);
            if (__elems_after > __n)
              {
                std::__uninitialized_move_a(this->_M_impl._M_finish - __n, this->_M_impl._M_finish, this->_M_impl._M_finish, (_M_get_Tp_allocator)());
                this->_M_impl._M_finish += __n;
                std::copy_backward(__position.base(), __old_finish - __n, __old_finish);
                std::copy(__first, __last, __position);
              }
            else
              {
                _ForwardIterator __mid = __first;
                std::advance(__mid, __elems_after);
                std::__uninitialized_copy_a(__mid, __last, this->_M_impl._M_finish, (_M_get_Tp_allocator)());
                this->_M_impl._M_finish += __n - __elems_after;
                std::__uninitialized_move_a(__position.base(), __old_finish, this->_M_impl._M_finish, (_M_get_Tp_allocator)());
                this->_M_impl._M_finish += __elems_after;
                std::copy(__first, __mid, __position);
              }
          }
        else
          {
            const typename ::std::vector<_Tp, _Alloc>::size_type __len = (*this)._M_check_len(__n, "vector::_M_range_insert");
            typename ::std::vector<_Tp, _Alloc>::pointer __new_start(this->_M_allocate(__len));
            typename ::std::vector<_Tp, _Alloc>::pointer __new_finish(__new_start);
            try
            {
              __new_finish = std::__uninitialized_move_if_noexcept_a(this->_M_impl._M_start, __position.base(), __new_start, (_M_get_Tp_allocator)());
              __new_finish = std::__uninitialized_copy_a(__first, __last, __new_finish, (_M_get_Tp_allocator)());
              __new_finish = std::__uninitialized_move_if_noexcept_a(__position.base(), this->_M_impl._M_finish, __new_finish, (_M_get_Tp_allocator)());
            }
            catch (...)
            {
              std::_Destroy(__new_start, __new_finish, (_M_get_Tp_allocator)());
              _M_deallocate(__new_start, __len);
              throw;
            }
            std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish, (_M_get_Tp_allocator)());
            _M_deallocate(this->_M_impl._M_start, this->_M_impl._M_end_of_storage - this->_M_impl._M_start);
            this->_M_impl._M_start = __new_start;
            this->_M_impl._M_finish = __new_finish;
            this->_M_impl._M_end_of_storage = __new_start + __len;
          }
      }
  }
  template < typename _Alloc >
  void vector<bool, _Alloc>::_M_reallocate(typename ::std::vector<bool, _Alloc>::size_type __n)
  {
    typename ::std::vector<bool, _Alloc>::_Bit_pointer __q = this->_M_allocate(__n);
    typename ::std::vector<bool, _Alloc>::iterator __start(std::__addressof(*__q), 0);
    typename ::std::vector<bool, _Alloc>::iterator __finish((*this)._M_copy_aligned((*this).begin(), (*this).end(), __start));
    this->_M_deallocate();
    this->_M_impl._M_start = __start;
    this->_M_impl._M_finish = __finish;
    this->_M_impl._M_end_of_storage = __q + (_S_nword)(__n);
  }
  template < typename _Alloc >
  void vector<bool, _Alloc>::_M_fill_insert(typename ::std::vector<bool, _Alloc>::iterator __position, typename ::std::vector<bool, _Alloc>::size_type __n, bool __x)
  {
    if (__n == 0)
      {
        return ;
      }
    if ((*this).capacity() - (*this).size() >= __n)
      {
        std::copy_backward(__position, (*this).end(), this->_M_impl._M_finish + (typename ::std::vector<bool, _Alloc>::difference_type)__n);
        std::fill(__position, __position + (typename ::std::vector<bool, _Alloc>::difference_type)__n, __x);
        this->_M_impl._M_finish += (typename ::std::vector<bool, _Alloc>::difference_type)__n;
      }
    else
      {
        const typename ::std::vector<bool, _Alloc>::size_type __len = (*this)._M_check_len(__n, "vector<bool>::_M_fill_insert");
        typename ::std::vector<bool, _Alloc>::_Bit_pointer __q = this->_M_allocate(__len);
        typename ::std::vector<bool, _Alloc>::iterator __start(std::__addressof(*__q), 0);
        typename ::std::vector<bool, _Alloc>::iterator __i = (*this)._M_copy_aligned((*this).begin(), __position, __start);
        std::fill(__i, __i + (typename ::std::vector<bool, _Alloc>::difference_type)__n, __x);
        typename ::std::vector<bool, _Alloc>::iterator __finish = std::copy(__position, (*this).end(), __i + (typename ::std::vector<bool, _Alloc>::difference_type)__n);
        this->_M_deallocate();
        this->_M_impl._M_end_of_storage = __q + (_S_nword)(__len);
        this->_M_impl._M_start = __start;
        this->_M_impl._M_finish = __finish;
      }
  }
  template < typename _Alloc >
  template < typename _ForwardIterator >
  void vector<bool, _Alloc>::_M_insert_range(typename ::std::vector<bool, _Alloc>::iterator __position, _ForwardIterator __first, _ForwardIterator __last, ::std::forward_iterator_tag)
  {
    if (__first != __last)
      {
        typename ::std::vector<bool, _Alloc>::size_type __n = std::distance(__first, __last);
        if ((*this).capacity() - (*this).size() >= __n)
          {
            std::copy_backward(__position, (*this).end(), this->_M_impl._M_finish + (typename ::std::vector<bool, _Alloc>::difference_type)__n);
            std::copy(__first, __last, __position);
            this->_M_impl._M_finish += (typename ::std::vector<bool, _Alloc>::difference_type)__n;
          }
        else
          {
            const typename ::std::vector<bool, _Alloc>::size_type __len = (*this)._M_check_len(__n, "vector<bool>::_M_insert_range");
            typename ::std::vector<bool, _Alloc>::_Bit_pointer __q = this->_M_allocate(__len);
            typename ::std::vector<bool, _Alloc>::iterator __start(std::__addressof(*__q), 0);
            typename ::std::vector<bool, _Alloc>::iterator __i = (*this)._M_copy_aligned((*this).begin(), __position, __start);
            __i = std::copy(__first, __last, __i);
            typename ::std::vector<bool, _Alloc>::iterator __finish = std::copy(__position, (*this).end(), __i);
            this->_M_deallocate();
            this->_M_impl._M_end_of_storage = __q + (_S_nword)(__len);
            this->_M_impl._M_start = __start;
            this->_M_impl._M_finish = __finish;
          }
      }
  }
  template < typename _Alloc >
  void vector<bool, _Alloc>::_M_insert_aux(typename ::std::vector<bool, _Alloc>::iterator __position, bool __x)
  {
    if (this->_M_impl._M_finish._M_p != this->_M_impl._M_end_addr())
      {
        std::copy_backward(__position, this->_M_impl._M_finish, this->_M_impl._M_finish + 1);
         *__position = __x;
         ++this->_M_impl._M_finish;
      }
    else
      {
        const typename ::std::vector<bool, _Alloc>::size_type __len = (*this)._M_check_len((typename ::std::vector<bool, _Alloc>::size_type)1, "vector<bool>::_M_insert_aux");
        typename ::std::vector<bool, _Alloc>::_Bit_pointer __q = this->_M_allocate(__len);
        typename ::std::vector<bool, _Alloc>::iterator __start(std::__addressof(*__q), 0);
        typename ::std::vector<bool, _Alloc>::iterator __i = (*this)._M_copy_aligned((*this).begin(), __position, __start);
         *__i++ = __x;
        typename ::std::vector<bool, _Alloc>::iterator __finish = std::copy(__position, (*this).end(), __i);
        this->_M_deallocate();
        this->_M_impl._M_end_of_storage = __q + (_S_nword)(__len);
        this->_M_impl._M_start = __start;
        this->_M_impl._M_finish = __finish;
      }
  }
  template < typename _Alloc >
  typename ::std::vector<bool, _Alloc>::iterator vector<bool, _Alloc>::_M_erase(typename ::std::vector<bool, _Alloc>::iterator __position)
  {
    if (__position + 1 != (*this).end())
      {
        std::copy(__position + 1, (*this).end(), __position);
      }
     --this->_M_impl._M_finish;
    return __position;
  }
  template < typename _Alloc >
  typename ::std::vector<bool, _Alloc>::iterator vector<bool, _Alloc>::_M_erase(typename ::std::vector<bool, _Alloc>::iterator __first, typename ::std::vector<bool, _Alloc>::iterator __last)
  {
    if (__first != __last)
      {
        (*this)._M_erase_at_end(std::copy(__last, (*this).end(), __first));
      }
    return __first;
  }
  template < typename _RandomAccessIterator, typename _Distance, typename _Compare >
  _Distance __is_heap_until(_RandomAccessIterator __first, _Distance __n, _Compare &__comp);
  template < typename _RandomAccessIterator, typename _Distance, typename _Compare >
  _Distance __is_heap_until(_RandomAccessIterator __first, _Distance __n, _Compare &__comp)
  {
    _Distance __parent = 0;
    for (_Distance __child = 1; __child < __n;  ++__child)
      {
        if (__comp(__first + __parent, __first + __child))
          {
            return __child;
          }
        if ((__child & 1) == 0)
          {
             ++__parent;
          }
      }
    return __n;
  }
  template < typename _RandomAccessIterator, typename _Distance >
  inline bool __is_heap(_RandomAccessIterator __first, _Distance __n);
  template < typename _RandomAccessIterator, typename _Distance >
  inline bool __is_heap(_RandomAccessIterator __first, _Distance __n)
  {
    ::__gnu_cxx::__ops::_Iter_less_iter __comp /* () */ ;
    return std::__is_heap_until(__first, __n, __comp) == __n;
  }
  template < typename _RandomAccessIterator, typename _Compare, typename _Distance >
  inline bool __is_heap(_RandomAccessIterator __first, _Compare __comp, _Distance __n);
  template < typename _RandomAccessIterator, typename _Compare, typename _Distance >
  inline bool __is_heap(_RandomAccessIterator __first, _Compare __comp, _Distance __n)
  {
    typedef __decltype(__comp) _Cmp;
    ::__gnu_cxx::__ops::_Iter_comp_iter<_Cmp> __cmp((__comp));
    return std::__is_heap_until(__first, __n, __cmp) == __n;
  }
  template < typename _RandomAccessIterator >
  inline bool __is_heap(_RandomAccessIterator __first, _RandomAccessIterator __last);
  template < typename _RandomAccessIterator >
  inline bool __is_heap(_RandomAccessIterator __first, _RandomAccessIterator __last)
  {
    return std::__is_heap(__first, std::distance(__first, __last));
  }
  template < typename _RandomAccessIterator, typename _Compare >
  inline bool __is_heap(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp);
  template < typename _RandomAccessIterator, typename _Compare >
  inline bool __is_heap(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp)
  {
    return std::__is_heap(__first, __comp, std::distance(__first, __last));
  }
  template < typename _RandomAccessIterator, typename _Distance, typename _Tp, typename _Compare >
  void __push_heap(_RandomAccessIterator __first, _Distance __holeIndex, _Distance __topIndex, _Tp __value, _Compare &__comp);
  template < typename _RandomAccessIterator, typename _Distance, typename _Tp, typename _Compare >
  void __push_heap(_RandomAccessIterator __first, _Distance __holeIndex, _Distance __topIndex, _Tp __value, _Compare &__comp)
  {
    _Distance __parent = (__holeIndex - 1) / 2;
    while (__holeIndex > __topIndex && __comp(__first + __parent, __value))
      {
        *(__first + __holeIndex) = *(__first + __parent);
        __holeIndex = __parent;
        __parent = (__holeIndex - 1) / 2;
      }
    *(__first + __holeIndex) = __value;
  }
  template < typename _RandomAccessIterator >
  inline void push_heap(_RandomAccessIterator __first, _RandomAccessIterator __last);
  template < typename _RandomAccessIterator >
  inline void push_heap(_RandomAccessIterator __first, _RandomAccessIterator __last)
  {
    typedef typename ::std::iterator_traits<_RandomAccessIterator>::value_type _ValueType;
    typedef typename ::std::iterator_traits<_RandomAccessIterator>::difference_type _DistanceType;
    ;
    ;
    ;
    ::__gnu_cxx::__ops::_Iter_less_val __comp /* () */ ;
    _ValueType __value = (*(__last - 1));
    std::__push_heap(__first, _DistanceType(__last - __first - 1), _DistanceType(0), __value, __comp);
  }
  template < typename _RandomAccessIterator, typename _Compare >
  inline void push_heap(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp);
  template < typename _RandomAccessIterator, typename _Compare >
  inline void push_heap(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp)
  {
    typedef typename ::std::iterator_traits<_RandomAccessIterator>::value_type _ValueType;
    typedef typename ::std::iterator_traits<_RandomAccessIterator>::difference_type _DistanceType;
    ;
    ;
    ;
    __decltype(__gnu_cxx::__ops::__iter_comp_val(__comp)) __cmp((__comp));
    _ValueType __value = (*(__last - 1));
    std::__push_heap(__first, _DistanceType(__last - __first - 1), _DistanceType(0), __value, __cmp);
  }
  template < typename _RandomAccessIterator, typename _Distance, typename _Tp, typename _Compare >
  void __adjust_heap(_RandomAccessIterator __first, _Distance __holeIndex, _Distance __len, _Tp __value, _Compare __comp);
  template < typename _RandomAccessIterator, typename _Distance, typename _Tp, typename _Compare >
  void __adjust_heap(_RandomAccessIterator __first, _Distance __holeIndex, _Distance __len, _Tp __value, _Compare __comp)
  {
    const _Distance __topIndex = __holeIndex;
    _Distance __secondChild = __holeIndex;
    while (__secondChild < (__len - 1) / 2)
      {
        __secondChild = 2 * (__secondChild + 1);
        if (__comp(__first + __secondChild, __first + (__secondChild - 1)))
          {
            __secondChild--;
          }
        *(__first + __holeIndex) = *(__first + __secondChild);
        __holeIndex = __secondChild;
      }
    if ((__len & 1) == 0 && __secondChild == (__len - 2) / 2)
      {
        __secondChild = 2 * (__secondChild + 1);
        *(__first + __holeIndex) = *(__first + (__secondChild - 1));
        __holeIndex = __secondChild - 1;
      }
    __decltype(__gnu_cxx::__ops::__iter_comp_val(__comp)) __cmp((__comp));
    std::__push_heap(__first, __holeIndex, __topIndex, __value, __cmp);
  }
  template < typename _RandomAccessIterator, typename _Compare >
  inline void __pop_heap(_RandomAccessIterator __first, _RandomAccessIterator __last, _RandomAccessIterator __result, _Compare &__comp);
  template < typename _RandomAccessIterator, typename _Compare >
  inline void __pop_heap(_RandomAccessIterator __first, _RandomAccessIterator __last, _RandomAccessIterator __result, _Compare &__comp)
  {
    typedef typename ::std::iterator_traits<_RandomAccessIterator>::value_type _ValueType;
    typedef typename ::std::iterator_traits<_RandomAccessIterator>::difference_type _DistanceType;
    _ValueType __value = (*__result);
    *__result = *__first;
    std::__adjust_heap(__first, _DistanceType(0), _DistanceType(__last - __first), __value, __comp);
  }
  template < typename _RandomAccessIterator >
  inline void pop_heap(_RandomAccessIterator __first, _RandomAccessIterator __last);
  template < typename _RandomAccessIterator >
  inline void pop_heap(_RandomAccessIterator __first, _RandomAccessIterator __last)
  {
    ;
    ;
    ;
    ;
    if (__last - __first > 1)
      {
         --__last;
        ::__gnu_cxx::__ops::_Iter_less_iter __comp /* () */ ;
        std::__pop_heap(__first, __last, __last, __comp);
      }
  }
  template < typename _RandomAccessIterator, typename _Compare >
  inline void pop_heap(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp);
  template < typename _RandomAccessIterator, typename _Compare >
  inline void pop_heap(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp)
  {
    ;
    ;
    ;
    ;
    if (__last - __first > 1)
      {
        typedef __decltype(__comp) _Cmp;
        ::__gnu_cxx::__ops::_Iter_comp_iter<_Cmp> __cmp((__comp));
         --__last;
        std::__pop_heap(__first, __last, __last, __cmp);
      }
  }
  template < typename _RandomAccessIterator, typename _Compare >
  void __make_heap(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare &__comp);
  template < typename _RandomAccessIterator, typename _Compare >
  void __make_heap(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare &__comp)
  {
    typedef typename ::std::iterator_traits<_RandomAccessIterator>::value_type _ValueType;
    typedef typename ::std::iterator_traits<_RandomAccessIterator>::difference_type _DistanceType;
    if (__last - __first < 2)
      {
        return ;
      }
    const _DistanceType __len = __last - __first;
    _DistanceType __parent = (__len - 2) / 2;
    while (true)
      {
        _ValueType __value = (*(__first + __parent));
        std::__adjust_heap(__first, __parent, __len, __value, __comp);
        if (__parent == 0)
          {
            return ;
          }
        __parent--;
      }
  }
  template < typename _RandomAccessIterator >
  inline void make_heap(_RandomAccessIterator __first, _RandomAccessIterator __last);
  template < typename _RandomAccessIterator >
  inline void make_heap(_RandomAccessIterator __first, _RandomAccessIterator __last)
  {
    ;
    ;
    ::__gnu_cxx::__ops::_Iter_less_iter __comp /* () */ ;
    std::__make_heap(__first, __last, __comp);
  }
  template < typename _RandomAccessIterator, typename _Compare >
  inline void make_heap(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp);
  template < typename _RandomAccessIterator, typename _Compare >
  inline void make_heap(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp)
  {
    ;
    ;
    typedef __decltype(__comp) _Cmp;
    ::__gnu_cxx::__ops::_Iter_comp_iter<_Cmp> __cmp((__comp));
    std::__make_heap(__first, __last, __cmp);
  }
  template < typename _RandomAccessIterator, typename _Compare >
  void __sort_heap(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare &__comp);
  template < typename _RandomAccessIterator, typename _Compare >
  void __sort_heap(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare &__comp)
  {
    while (__last - __first > 1)
      {
         --__last;
        std::__pop_heap(__first, __last, __last, __comp);
      }
  }
  template < typename _RandomAccessIterator >
  inline void sort_heap(_RandomAccessIterator __first, _RandomAccessIterator __last);
  template < typename _RandomAccessIterator >
  inline void sort_heap(_RandomAccessIterator __first, _RandomAccessIterator __last)
  {
    ;
    ;
    ;
    ::__gnu_cxx::__ops::_Iter_less_iter __comp /* () */ ;
    std::__sort_heap(__first, __last, __comp);
  }
  template < typename _RandomAccessIterator, typename _Compare >
  inline void sort_heap(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp);
  template < typename _RandomAccessIterator, typename _Compare >
  inline void sort_heap(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp)
  {
    ;
    ;
    ;
    typedef __decltype(__comp) _Cmp;
    ::__gnu_cxx::__ops::_Iter_comp_iter<_Cmp> __cmp((__comp));
    std::__sort_heap(__first, __last, __cmp);
  }
  template < typename _Tp, typename _Sequence = ::std::deque<_Tp> >
  class  queue
  {
    public:
      typedef typename _Sequence::value_type value_type;
      typedef typename _Sequence::reference reference;
      typedef typename _Sequence::const_reference const_reference;
      typedef typename _Sequence::size_type size_type;
      typedef _Sequence container_type;
    protected:
      _Sequence c;
    public:
      inline explicit queue(const _Sequence &__c  = (_Sequence()))
        : c(__c)
      {
      }
      inline bool empty() const 
      {
        return ::std::queue<_Tp, _Sequence>::c.empty();
      }
      inline typename ::std::queue<_Tp, _Sequence>::size_type size() const 
      {
        return ::std::queue<_Tp, _Sequence>::c.size();
      }
      inline typename ::std::queue<_Tp, _Sequence>::reference front()
      {
        ;
        return ::std::queue<_Tp, _Sequence>::c.front();
      }
      inline typename ::std::queue<_Tp, _Sequence>::const_reference front() const 
      {
        ;
        return ::std::queue<_Tp, _Sequence>::c.front();
      }
      inline typename ::std::queue<_Tp, _Sequence>::reference back()
      {
        ;
        return ::std::queue<_Tp, _Sequence>::c.back();
      }
      inline typename ::std::queue<_Tp, _Sequence>::const_reference back() const 
      {
        ;
        return ::std::queue<_Tp, _Sequence>::c.back();
      }
      inline void push(const typename ::std::queue<_Tp, _Sequence>::value_type &__x)
      {
        ::std::queue<_Tp, _Sequence>::c.push_back(__x);
      }
      inline void pop()
      {
        ;
        ::std::queue<_Tp, _Sequence>::c.pop_front();
      }
    template < typename _Tp1, typename _Seq1 >
    friend bool operator ==(const ::std::queue<_Tp1, _Seq1> &, const ::std::queue<_Tp1, _Seq1> &);
    template < typename _Tp1, typename _Seq1 >
    friend bool operator <(const ::std::queue<_Tp1, _Seq1> &, const ::std::queue<_Tp1, _Seq1> &);
  };
  template < typename _Tp, typename _Seq >
  inline bool operator ==(const ::std::queue<_Tp, _Seq> &__x, const ::std::queue<_Tp, _Seq> &__y);
  template < typename _Tp, typename _Seq >
  inline bool operator ==(const ::std::queue<_Tp, _Seq> &__x, const ::std::queue<_Tp, _Seq> &__y)
  {
    return __x.c == __y.c;
  }
  template < typename _Tp, typename _Seq >
  inline bool operator <(const ::std::queue<_Tp, _Seq> &__x, const ::std::queue<_Tp, _Seq> &__y);
  template < typename _Tp, typename _Seq >
  inline bool operator <(const ::std::queue<_Tp, _Seq> &__x, const ::std::queue<_Tp, _Seq> &__y)
  {
    return __x.c < __y.c;
  }
  template < typename _Tp, typename _Seq >
  inline bool operator !=(const ::std::queue<_Tp, _Seq> &__x, const ::std::queue<_Tp, _Seq> &__y);
  template < typename _Tp, typename _Seq >
  inline bool operator !=(const ::std::queue<_Tp, _Seq> &__x, const ::std::queue<_Tp, _Seq> &__y)
  {
    return !(__x == __y);
  }
  template < typename _Tp, typename _Seq >
  inline bool operator >(const ::std::queue<_Tp, _Seq> &__x, const ::std::queue<_Tp, _Seq> &__y);
  template < typename _Tp, typename _Seq >
  inline bool operator >(const ::std::queue<_Tp, _Seq> &__x, const ::std::queue<_Tp, _Seq> &__y)
  {
    return __y < __x;
  }
  template < typename _Tp, typename _Seq >
  inline bool operator <=(const ::std::queue<_Tp, _Seq> &__x, const ::std::queue<_Tp, _Seq> &__y);
  template < typename _Tp, typename _Seq >
  inline bool operator <=(const ::std::queue<_Tp, _Seq> &__x, const ::std::queue<_Tp, _Seq> &__y)
  {
    return !(__y < __x);
  }
  template < typename _Tp, typename _Seq >
  inline bool operator >=(const ::std::queue<_Tp, _Seq> &__x, const ::std::queue<_Tp, _Seq> &__y);
  template < typename _Tp, typename _Seq >
  inline bool operator >=(const ::std::queue<_Tp, _Seq> &__x, const ::std::queue<_Tp, _Seq> &__y)
  {
    return !(__x < __y);
  }
  template < typename _Tp, typename _Sequence = ::std::vector<_Tp>, typename _Compare = ::std::less<typename _Sequence::value_type> >
  class  priority_queue
  {
    public:
      typedef typename _Sequence::value_type value_type;
      typedef typename _Sequence::reference reference;
      typedef typename _Sequence::const_reference const_reference;
      typedef typename _Sequence::size_type size_type;
      typedef _Sequence container_type;
      typedef _Compare value_compare;
    protected:
      _Sequence c;
      _Compare comp;
    public:
      inline explicit priority_queue(const _Compare &__x  = (_Compare()), const _Sequence &__s  = (_Sequence()))
        : c(__s), comp(__x)
      {
        std::make_heap(::std::priority_queue<_Tp, _Sequence, _Compare>::c.begin(), ::std::priority_queue<_Tp, _Sequence, _Compare>::c.end(), ::std::priority_queue<_Tp, _Sequence, _Compare>::comp);
      }
      template < typename _InputIterator >
      inline priority_queue(_InputIterator __first, _InputIterator __last, const _Compare &__x  = (_Compare()), const _Sequence &__s  = (_Sequence()))
        : c(__s), comp(__x)
      {
        ;
        ::std::priority_queue<_Tp, _Sequence, _Compare>::c.insert(::std::priority_queue<_Tp, _Sequence, _Compare>::c.end(), __first, __last);
        std::make_heap(::std::priority_queue<_Tp, _Sequence, _Compare>::c.begin(), ::std::priority_queue<_Tp, _Sequence, _Compare>::c.end(), ::std::priority_queue<_Tp, _Sequence, _Compare>::comp);
      }
      inline bool empty() const 
      {
        return ::std::priority_queue<_Tp, _Sequence, _Compare>::c.empty();
      }
      inline typename ::std::priority_queue<_Tp, _Sequence, _Compare>::size_type size() const 
      {
        return ::std::priority_queue<_Tp, _Sequence, _Compare>::c.size();
      }
      inline typename ::std::priority_queue<_Tp, _Sequence, _Compare>::const_reference top() const 
      {
        ;
        return ::std::priority_queue<_Tp, _Sequence, _Compare>::c.front();
      }
      inline void push(const typename ::std::priority_queue<_Tp, _Sequence, _Compare>::value_type &__x)
      {
        ::std::priority_queue<_Tp, _Sequence, _Compare>::c.push_back(__x);
        std::push_heap(::std::priority_queue<_Tp, _Sequence, _Compare>::c.begin(), ::std::priority_queue<_Tp, _Sequence, _Compare>::c.end(), ::std::priority_queue<_Tp, _Sequence, _Compare>::comp);
      }
      inline void pop()
      {
        ;
        std::pop_heap(::std::priority_queue<_Tp, _Sequence, _Compare>::c.begin(), ::std::priority_queue<_Tp, _Sequence, _Compare>::c.end(), ::std::priority_queue<_Tp, _Sequence, _Compare>::comp);
        ::std::priority_queue<_Tp, _Sequence, _Compare>::c.pop_back();
      }
  };
}
using namespace ::std;
struct  dispatch_job_t
{
    enum dispatch_type_e
    {
      JOB_SCORE = 0
    };
    ::dispatch_job_t::dispatch_type_e type;
    union  dispatch_params_t
    {
        struct  params_score_t
        {
            ::score_t score;
            int bx;
            int by;
        };
        ::dispatch_job_t::dispatch_params_t::params_score_t params_score;
    };
    ::dispatch_job_t::dispatch_params_t dispatch_params;
};
 /* Instantiation of class template '::__gnu_cxx::new_allocator< ::dispatch_job_t>' */ 
 /* Instantiation of class template '::std::allocator< ::dispatch_job_t>' */ 
 /* Instantiation of class template '::__gnu_cxx::__alloc_traits< ::std::allocator< ::dispatch_job_t> >' */ 
 /* Instantiation of class template '::std::allocator< ::dispatch_job_t>::rebind< ::dispatch_job_t>' */ 
 /* Instantiation of class template '::__gnu_cxx::__alloc_traits< ::std::allocator< ::dispatch_job_t> >::rebind< ::dispatch_job_t>' */ 
 /* Instantiation of class template '::std::allocator< ::dispatch_job_t>::rebind< ::dispatch_job_t *>' */ 
 /* Instantiation of class template '::__gnu_cxx::__alloc_traits< ::std::allocator< ::dispatch_job_t> >::rebind< ::dispatch_job_t *>' */ 
 /* Instantiation of class template '::std::_Deque_iterator< ::dispatch_job_t, ::dispatch_job_t &, ::dispatch_job_t *>' */ 
 /* Instantiation of class template '::std::_Deque_base< ::dispatch_job_t, ::std::allocator< ::dispatch_job_t> >::_Deque_impl' */ 
 /* Instantiation of class template '::std::_Deque_base< ::dispatch_job_t, ::std::allocator< ::dispatch_job_t> >' */ 
 /* Instantiation of class template '::std::deque< ::dispatch_job_t, ::std::allocator< ::dispatch_job_t> >' */ 
 /* Instantiation of class template '::std::queue< ::dispatch_job_t>' */ 
class  AbstractAlignerSafe : public ::AbstractAligner
{
  public:
    AbstractAlignerSafe();
    virtual ~AbstractAlignerSafe();
    virtual void dispatchColumn(int j, const ::cell_t *buffer, int len);
    virtual void dispatchRow(int i, const ::cell_t *buffer, int len);
    virtual void dispatchScore(::score_t score, int bx  = ( -1), int by  = ( -1));
  protected:
    void createDispatcherQueue();
    void destroyDispatcherQueue();
  private:
    ::pthread_t thread;
    ::pthread_mutex_t mutex;
    ::pthread_cond_t condition;
    bool dispatcherQueueActive;
    ::std::queue< ::dispatch_job_t> dispatcherQueue;
    static void *staticFunctionThread(void *arg);
    void executeLoop();
  public:
};
class  CPUBlockProcessor : public ::AbstractBlockProcessor
{
  public:
    CPUBlockProcessor();
    virtual ~CPUBlockProcessor();
    virtual void setSequences(const char *seq0, const char *seq1, int seq0_len, int seq1_len);
    virtual void unsetSequences();
    virtual ::score_t processBlock(::cell_t *row, ::cell_t *col, const int i0, const int j0, const int i1, const int j1, const int recurrenceType);
  private:
    const char *seq0;
    const char *seq1;
  public:
};
class  AlignerUtils
{
  public:
    static void splitBlocksEvenly(int *pos, int j0, int j1, int count);
    static ::match_result_t matchColumn(const ::cell_t *buffer, const ::cell_t *base, int len, int goalScore, int gap_open_penalty);
};
int libmasa_entry_point(int argc, char **argv, ::IAligner *aligner, char *aligner_header  = (0L));
class  OmpSsAlignerParameters : public ::BlockAlignerParameters
{
  public:
    OmpSsAlignerParameters();
    virtual ~OmpSsAlignerParameters();
};
class  OmpSsAligner : public ::AbstractBlockAligner
{
  public:
    OmpSsAligner(::AbstractBlockProcessor *blockProcessor  = (0L));
    virtual ~OmpSsAligner();
    virtual void printInitialStatistics(::FILE *file);
  protected:
    virtual void scheduleBlocks(int grid_width, int grid_height);
  public:
    struct nanos_args_0_t;
    struct nanos_args_1_t;
    struct nanos_args_2_t;
  protected:
    virtual void alignBlock(int bx, int by, int i0, int j0, int i1, int j1);
    virtual void allocateStructures();
    virtual void deallocateStructures();
    virtual void increaseBlockStat(const bool pruned);
  private:
    ::cell_t **renamedRow;
    char *rowChain;
    char columnChain;
  public:
    void smp_ol_alignBlock_0_unpacked(int bx, int by, int j0, int j1, int i0, int i1, int dispatchThisSpecialRows) throw();
    static void smp_ol_alignBlock_0(::OmpSsAligner::nanos_args_0_t &args) throw();
    static void nanos_xlate_fun_OmpSsAlignercpp_0(::OmpSsAligner::nanos_args_0_t &arg, ::nanos_wd_t wd) throw();
    void smp_ol_alignBlock_1_unpacked(int j0, int j1, int i1, ::cell_t &first_cell, int bx, int by) throw();
    static void smp_ol_alignBlock_1(::OmpSsAligner::nanos_args_1_t &args) throw();
    static void nanos_xlate_fun_OmpSsAlignercpp_1(::OmpSsAligner::nanos_args_1_t &arg, ::nanos_wd_t wd) throw();
    void smp_ol_alignBlock_2_unpacked(int i0, int i1, int j1, int by) throw();
    static void smp_ol_alignBlock_2(::OmpSsAligner::nanos_args_2_t &args) throw();
    static void nanos_xlate_fun_OmpSsAlignercpp_2(::OmpSsAligner::nanos_args_2_t &arg, ::nanos_wd_t wd) throw();
};
enum idtype_t
{
  P_ALL = 0,
  P_PID = 1,
  P_PGID = 2
};
struct  div_t
{
    int quot;
    int rem;
};
struct  ldiv_t
{
    long int quot;
    long int rem;
};
__extension__ struct  lldiv_t
{
    __extension__ long long int quot;
    __extension__ long long int rem;
};
extern "C"
{
  extern ::size_t __ctype_get_mb_cur_max() throw() __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern inline double atof(const char *__nptr) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__)) __attribute__((__leaf__)) __attribute__((__gnu_inline__));
}
extern "C"
{
  extern inline int atoi(const char *__nptr) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__)) __attribute__((__leaf__)) __attribute__((__gnu_inline__));
}
extern "C"
{
  extern inline long int atol(const char *__nptr) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__)) __attribute__((__leaf__)) __attribute__((__gnu_inline__));
}
extern "C"
{
  extern inline long long int atoll(const char *__nptr) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__)) __attribute__((__leaf__)) __attribute__((__gnu_inline__));
}
extern "C"
{
  extern double strtod(const char *__restrict __nptr, char **__restrict __endptr) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern float strtof(const char *__restrict __nptr, char **__restrict __endptr) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern long double strtold(const char *__restrict __nptr, char **__restrict __endptr) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern ::_Float32 strtof32(const char *__restrict __nptr, char **__restrict __endptr) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern ::_Float64 strtof64(const char *__restrict __nptr, char **__restrict __endptr) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern ::_Float128 strtof128(const char *__restrict __nptr, char **__restrict __endptr) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern ::_Float32x strtof32x(const char *__restrict __nptr, char **__restrict __endptr) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern ::_Float64x strtof64x(const char *__restrict __nptr, char **__restrict __endptr) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern long int strtol(const char *__restrict __nptr, char **__restrict __endptr, int __base) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern unsigned long int strtoul(const char *__restrict __nptr, char **__restrict __endptr, int __base) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern long long int strtoq(const char *__restrict __nptr, char **__restrict __endptr, int __base) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern unsigned long long int strtouq(const char *__restrict __nptr, char **__restrict __endptr, int __base) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern long long int strtoll(const char *__restrict __nptr, char **__restrict __endptr, int __base) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern unsigned long long int strtoull(const char *__restrict __nptr, char **__restrict __endptr, int __base) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int strfromd(char *__dest, ::size_t __size, const char *__format, double __f) throw() __attribute__((__nonnull__(3)));
}
extern "C"
{
  extern int strfromf(char *__dest, ::size_t __size, const char *__format, float __f) throw() __attribute__((__nonnull__(3)));
}
extern "C"
{
  extern int strfroml(char *__dest, ::size_t __size, const char *__format, long double __f) throw() __attribute__((__nonnull__(3)));
}
extern "C"
{
  extern int strfromf32(char *__dest, ::size_t __size, const char *__format, ::_Float32 __f) throw() __attribute__((__nonnull__(3)));
}
extern "C"
{
  extern int strfromf64(char *__dest, ::size_t __size, const char *__format, ::_Float64 __f) throw() __attribute__((__nonnull__(3)));
}
extern "C"
{
  extern int strfromf128(char *__dest, ::size_t __size, const char *__format, ::_Float128 __f) throw() __attribute__((__nonnull__(3)));
}
extern "C"
{
  extern int strfromf32x(char *__dest, ::size_t __size, const char *__format, ::_Float32x __f) throw() __attribute__((__nonnull__(3)));
}
extern "C"
{
  extern int strfromf64x(char *__dest, ::size_t __size, const char *__format, ::_Float64x __f) throw() __attribute__((__nonnull__(3)));
}
extern "C"
{
  extern long int strtol_l(const char *__restrict __nptr, char **__restrict __endptr, int __base, ::locale_t __loc) throw() __attribute__((__nonnull__(1, 4)));
}
extern "C"
{
  extern unsigned long int strtoul_l(const char *__restrict __nptr, char **__restrict __endptr, int __base, ::locale_t __loc) throw() __attribute__((__nonnull__(1, 4)));
}
extern "C"
{
  extern long long int strtoll_l(const char *__restrict __nptr, char **__restrict __endptr, int __base, ::locale_t __loc) throw() __attribute__((__nonnull__(1, 4)));
}
extern "C"
{
  extern unsigned long long int strtoull_l(const char *__restrict __nptr, char **__restrict __endptr, int __base, ::locale_t __loc) throw() __attribute__((__nonnull__(1, 4)));
}
extern "C"
{
  extern double strtod_l(const char *__restrict __nptr, char **__restrict __endptr, ::locale_t __loc) throw() __attribute__((__nonnull__(1, 3)));
}
extern "C"
{
  extern float strtof_l(const char *__restrict __nptr, char **__restrict __endptr, ::locale_t __loc) throw() __attribute__((__nonnull__(1, 3)));
}
extern "C"
{
  extern long double strtold_l(const char *__restrict __nptr, char **__restrict __endptr, ::locale_t __loc) throw() __attribute__((__nonnull__(1, 3)));
}
extern "C"
{
  extern ::_Float32 strtof32_l(const char *__restrict __nptr, char **__restrict __endptr, ::locale_t __loc) throw() __attribute__((__nonnull__(1, 3)));
}
extern "C"
{
  extern ::_Float64 strtof64_l(const char *__restrict __nptr, char **__restrict __endptr, ::locale_t __loc) throw() __attribute__((__nonnull__(1, 3)));
}
extern "C"
{
  extern ::_Float128 strtof128_l(const char *__restrict __nptr, char **__restrict __endptr, ::locale_t __loc) throw() __attribute__((__nonnull__(1, 3)));
}
extern "C"
{
  extern ::_Float32x strtof32x_l(const char *__restrict __nptr, char **__restrict __endptr, ::locale_t __loc) throw() __attribute__((__nonnull__(1, 3)));
}
extern "C"
{
  extern ::_Float64x strtof64x_l(const char *__restrict __nptr, char **__restrict __endptr, ::locale_t __loc) throw() __attribute__((__nonnull__(1, 3)));
}
extern "C"
{
  extern inline __attribute__((__pure__)) __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__)) __attribute__((__leaf__)) __attribute__((__gnu_inline__)) int atoi(const char *__nptr) throw()
  {
    return (int)::strtol(__nptr, (char **)0L, 10);
  }
}
extern "C"
{
  extern inline __attribute__((__pure__)) __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__)) __attribute__((__leaf__)) __attribute__((__gnu_inline__)) long int atol(const char *__nptr) throw()
  {
    return ::strtol(__nptr, (char **)0L, 10);
  }
}
extern "C"
{
  __extension__ extern inline __attribute__((__pure__)) __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__)) __attribute__((__leaf__)) __attribute__((__gnu_inline__)) long long int atoll(const char *__nptr) throw()
  {
    return ::strtoll(__nptr, (char **)0L, 10);
  }
}
extern "C"
{
  extern char *l64a(long int __n) throw() __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern long int a64l(const char *__s) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__));
}
typedef ::__u_char u_char;
typedef ::__u_short u_short;
typedef ::__u_int u_int;
typedef ::__u_long u_long;
typedef ::__quad_t quad_t;
typedef ::__u_quad_t u_quad_t;
typedef ::__fsid_t fsid_t;
typedef ::__loff_t loff_t;
typedef ::__ino_t ino_t;
typedef ::__ino64_t ino64_t;
typedef ::__dev_t dev_t;
typedef ::__gid_t gid_t;
typedef ::__mode_t mode_t;
typedef ::__nlink_t nlink_t;
typedef ::__uid_t uid_t;
typedef ::__id_t id_t;
typedef ::__daddr_t daddr_t;
typedef ::__caddr_t caddr_t;
typedef ::__key_t key_t;
typedef ::__useconds_t useconds_t;
typedef ::__suseconds_t suseconds_t;
typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
typedef unsigned char u_int8_t;
typedef unsigned short int u_int16_t;
typedef unsigned int u_int32_t;
typedef unsigned long int u_int64_t;
typedef long int register_t;
struct  __sigset_t
{
    unsigned long int __val[16L];
};
typedef ::__sigset_t sigset_t;
typedef long int __fd_mask;
struct  fd_set
{
    ::__fd_mask fds_bits[16L];
};
typedef ::__fd_mask fd_mask;
extern "C"
{
  extern int select(int __nfds, ::fd_set *__restrict __readfds, ::fd_set *__restrict __writefds, ::fd_set *__restrict __exceptfds, ::timeval *__restrict __timeout);
}
extern "C"
{
  extern int pselect(int __nfds, ::fd_set *__restrict __readfds, ::fd_set *__restrict __writefds, ::fd_set *__restrict __exceptfds, const ::timespec *__restrict __timeout, const ::__sigset_t *__restrict __sigmask);
}
extern "C"
{
  extern long int __fdelt_chk(long int __d);
}
extern "C"
{
  extern long int __fdelt_warn(long int __d) __attribute__((__warning__("bit outside of fd_set selected")));
}
extern "C"
{
  extern inline unsigned int gnu_dev_major(::__dev_t __dev) throw() __attribute__((__const__)) __attribute__((__leaf__)) __attribute__((__gnu_inline__));
}
extern "C"
{
  extern inline unsigned int gnu_dev_minor(::__dev_t __dev) throw() __attribute__((__const__)) __attribute__((__leaf__)) __attribute__((__gnu_inline__));
}
extern "C"
{
  extern inline ::__dev_t gnu_dev_makedev(unsigned int __major, unsigned int __minor) throw() __attribute__((__const__)) __attribute__((__leaf__)) __attribute__((__gnu_inline__));
}
extern "C"
{
  __extension__ extern inline __attribute__((__const__)) __attribute__((__leaf__)) __attribute__((__gnu_inline__)) unsigned int gnu_dev_major(::__dev_t __dev) throw()
  {
    __extension__ unsigned int __major;
    __major = (__dev & (::__dev_t)1048320U) >> 8;
    __major |= (__dev & (::__dev_t)18446726481523507200LU) >> 32;
    return __major;
  }
}
extern "C"
{
  __extension__ extern inline __attribute__((__const__)) __attribute__((__leaf__)) __attribute__((__gnu_inline__)) unsigned int gnu_dev_minor(::__dev_t __dev) throw()
  {
    __extension__ unsigned int __minor;
    __minor = (__dev & (::__dev_t)255U) >> 0;
    __minor |= (__dev & (::__dev_t)17592184995840LU) >> 12;
    return __minor;
  }
}
extern "C"
{
  __extension__ extern inline __attribute__((__const__)) __attribute__((__leaf__)) __attribute__((__gnu_inline__)) ::__dev_t gnu_dev_makedev(unsigned int __major, unsigned int __minor) throw()
  {
    __extension__ ::__dev_t __dev;
    __dev = (::__dev_t)(__major & 4095U) << 8;
    __dev |= (::__dev_t)(__major & 4294963200U) << 32;
    __dev |= (::__dev_t)(__minor & 255U) << 0;
    __dev |= (::__dev_t)(__minor & 4294967040U) << 12;
    return __dev;
  }
}
typedef ::__blksize_t blksize_t;
typedef ::__blkcnt_t blkcnt_t;
typedef ::__fsblkcnt_t fsblkcnt_t;
typedef ::__fsfilcnt_t fsfilcnt_t;
typedef ::__blkcnt64_t blkcnt64_t;
typedef ::__fsblkcnt64_t fsblkcnt64_t;
typedef ::__fsfilcnt64_t fsfilcnt64_t;
extern "C"
{
  extern long int random() throw();
}
extern "C"
{
  extern void srandom(unsigned int __seed) throw();
}
extern "C"
{
  extern char *initstate(unsigned int __seed, char *__statebuf, ::size_t __statelen) throw() __attribute__((__nonnull__(2)));
}
extern "C"
{
  extern char *setstate(char *__statebuf) throw() __attribute__((__nonnull__(1)));
}
struct  random_data
{
    ::int32_t *fptr;
    ::int32_t *rptr;
    ::int32_t *state;
    int rand_type;
    int rand_deg;
    int rand_sep;
    ::int32_t *end_ptr;
};
extern "C"
{
  extern int random_r(::random_data *__restrict __buf, ::int32_t *__restrict __result) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int srandom_r(unsigned int __seed, ::random_data *__buf) throw() __attribute__((__nonnull__(2)));
}
extern "C"
{
  extern int initstate_r(unsigned int __seed, char *__restrict __statebuf, ::size_t __statelen, ::random_data *__restrict __buf) throw() __attribute__((__nonnull__(2, 4)));
}
extern "C"
{
  extern int setstate_r(char *__restrict __statebuf, ::random_data *__restrict __buf) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int rand() throw();
}
extern "C"
{
  extern void srand(unsigned int __seed) throw();
}
extern "C"
{
  extern int rand_r(unsigned int *__seed) throw();
}
extern "C"
{
  extern double drand48() throw();
}
extern "C"
{
  extern double erand48(unsigned short int __xsubi[3L]) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern long int lrand48() throw();
}
extern "C"
{
  extern long int nrand48(unsigned short int __xsubi[3L]) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern long int mrand48() throw();
}
extern "C"
{
  extern long int jrand48(unsigned short int __xsubi[3L]) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern void srand48(long int __seedval) throw();
}
extern "C"
{
  extern unsigned short int *seed48(unsigned short int __seed16v[3L]) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern void lcong48(unsigned short int __param[7L]) throw() __attribute__((__nonnull__(1)));
}
struct  drand48_data
{
    unsigned short int __x[3L];
    unsigned short int __old_x[3L];
    unsigned short int __c;
    unsigned short int __init;
    __extension__ unsigned long long int __a;
};
extern "C"
{
  extern int drand48_r(::drand48_data *__restrict __buffer, double *__restrict __result) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int erand48_r(unsigned short int __xsubi[3L], ::drand48_data *__restrict __buffer, double *__restrict __result) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int lrand48_r(::drand48_data *__restrict __buffer, long int *__restrict __result) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int nrand48_r(unsigned short int __xsubi[3L], ::drand48_data *__restrict __buffer, long int *__restrict __result) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int mrand48_r(::drand48_data *__restrict __buffer, long int *__restrict __result) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int jrand48_r(unsigned short int __xsubi[3L], ::drand48_data *__restrict __buffer, long int *__restrict __result) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int srand48_r(long int __seedval, ::drand48_data *__buffer) throw() __attribute__((__nonnull__(2)));
}
extern "C"
{
  extern int seed48_r(unsigned short int __seed16v[3L], ::drand48_data *__buffer) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int lcong48_r(unsigned short int __param[7L], ::drand48_data *__buffer) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern void *malloc(::size_t __size) throw() __attribute__((__malloc__)) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern void *calloc(::size_t __nmemb, ::size_t __size) throw() __attribute__((__malloc__)) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern void *realloc(void *__ptr, ::size_t __size) throw() __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern void *reallocarray(void *__ptr, ::size_t __nmemb, ::size_t __size) throw() __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern void free(void *__ptr) throw();
}
extern "C"
{
  extern void *alloca(::size_t __size) throw();
}
extern "C"
{
  extern void *valloc(::size_t __size) throw() __attribute__((__malloc__)) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int posix_memalign(void **__memptr, ::size_t __alignment, ::size_t __size) throw() __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern void *aligned_alloc(::size_t __alignment, ::size_t __size) throw() __attribute__((__malloc__)) __attribute__((__alloc_size__(2))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern void abort() throw() __attribute__((__noreturn__));
}
extern "C"
{
  extern int atexit(void (*__func)()) throw() __attribute__((__nonnull__(1)));
}
int at_quick_exit(void (*__func)()) throw() __asm("at_quick_exit") __attribute__((__nonnull__(1)));
extern "C"
{
  extern int on_exit(void (*__func)(int, void *), void *__arg) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern void exit(int __status) throw() __attribute__((__noreturn__));
}
extern "C"
{
  extern void quick_exit(int __status) throw() __attribute__((__noreturn__));
}
extern "C"
{
  extern void _Exit(int __status) throw() __attribute__((__noreturn__));
}
extern "C"
{
  extern char *getenv(const char *__name) throw() __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern char *secure_getenv(const char *__name) throw() __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int putenv(char *__string) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int setenv(const char *__name, const char *__value, int __replace) throw() __attribute__((__nonnull__(2)));
}
extern "C"
{
  extern int unsetenv(const char *__name) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int clearenv() throw();
}
extern "C"
{
  extern char *mktemp(char *__template) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int mkstemp(char *__template) __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int mkstemp64(char *__template) __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int mkstemps(char *__template, int __suffixlen) __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int mkstemps64(char *__template, int __suffixlen) __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern char *mkdtemp(char *__template) throw() __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int mkostemp(char *__template, int __flags) __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int mkostemp64(char *__template, int __flags) __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int mkostemps(char *__template, int __suffixlen, int __flags) __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int mkostemps64(char *__template, int __suffixlen, int __flags) __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int system(const char *__command) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern char *canonicalize_file_name(const char *__name) throw() __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern inline char *realpath(const char *__restrict __name, char *__restrict __resolved) throw() __attribute__((__warn_unused_result__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
typedef int (*__compar_fn_t)(const void *, const void *);
typedef ::__compar_fn_t comparison_fn_t;
typedef int (*__compar_d_fn_t)(const void *, const void *, void *);
extern "C"
{
  extern inline void *bsearch(const void *__key, const void *__base, ::size_t __nmemb, ::size_t __size, ::__compar_fn_t __compar) __attribute__((__nonnull__(1, 2, 5))) __attribute__((__warn_unused_result__)) __attribute__((__gnu_inline__));
}
extern "C"
{
  extern inline __attribute__((__nonnull__(1, 2, 5))) __attribute__((__warn_unused_result__)) __attribute__((__gnu_inline__)) void *bsearch(const void *__key, const void *__base, ::size_t __nmemb, ::size_t __size, ::__compar_fn_t __compar)
  {
    ::size_t __l;
    ::size_t __u;
    ::size_t __idx;
    const void *__p;
    int __comparison;
    __l = 0;
    __u = __nmemb;
    while (__l < __u)
      {
        __idx = (__l + __u) / 2;
        __p = (void *)((const char *)__base + __idx * __size);
        __comparison = (*__compar)(__key, __p);
        if (__comparison < 0)
          {
            __u = __idx;
          }
        else
          {
            if (__comparison > 0)
              {
                __l = __idx + 1;
              }
            else
              {
                return (void *)__p;
              }
          }
      }
    return 0L;
  }
}
extern "C"
{
  extern void qsort(void *__base, ::size_t __nmemb, ::size_t __size, ::__compar_fn_t __compar) __attribute__((__nonnull__(1, 4)));
}
extern "C"
{
  extern void qsort_r(void *__base, ::size_t __nmemb, ::size_t __size, ::__compar_d_fn_t __compar, void *__arg) __attribute__((__nonnull__(1, 4)));
}
extern "C"
{
  extern int abs(int __x) throw() __attribute__((__const__)) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern long int labs(long int __x) throw() __attribute__((__const__)) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern long long int llabs(long long int __x) throw() __attribute__((__const__)) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern ::div_t div(int __numer, int __denom) throw() __attribute__((__const__)) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern ::ldiv_t ldiv(long int __numer, long int __denom) throw() __attribute__((__const__)) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern ::lldiv_t lldiv(long long int __numer, long long int __denom) throw() __attribute__((__const__)) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern char *ecvt(double __value, int __ndigit, int *__restrict __decpt, int *__restrict __sign) throw() __attribute__((__nonnull__(3, 4))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern char *fcvt(double __value, int __ndigit, int *__restrict __decpt, int *__restrict __sign) throw() __attribute__((__nonnull__(3, 4))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern char *gcvt(double __value, int __ndigit, char *__buf) throw() __attribute__((__nonnull__(3))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern char *qecvt(long double __value, int __ndigit, int *__restrict __decpt, int *__restrict __sign) throw() __attribute__((__nonnull__(3, 4))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern char *qfcvt(long double __value, int __ndigit, int *__restrict __decpt, int *__restrict __sign) throw() __attribute__((__nonnull__(3, 4))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern char *qgcvt(long double __value, int __ndigit, char *__buf) throw() __attribute__((__nonnull__(3))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int ecvt_r(double __value, int __ndigit, int *__restrict __decpt, int *__restrict __sign, char *__restrict __buf, ::size_t __len) throw() __attribute__((__nonnull__(3, 4, 5)));
}
extern "C"
{
  extern int fcvt_r(double __value, int __ndigit, int *__restrict __decpt, int *__restrict __sign, char *__restrict __buf, ::size_t __len) throw() __attribute__((__nonnull__(3, 4, 5)));
}
extern "C"
{
  extern int qecvt_r(long double __value, int __ndigit, int *__restrict __decpt, int *__restrict __sign, char *__restrict __buf, ::size_t __len) throw() __attribute__((__nonnull__(3, 4, 5)));
}
extern "C"
{
  extern int qfcvt_r(long double __value, int __ndigit, int *__restrict __decpt, int *__restrict __sign, char *__restrict __buf, ::size_t __len) throw() __attribute__((__nonnull__(3, 4, 5)));
}
extern "C"
{
  extern int mblen(const char *__s, ::size_t __n) throw();
}
extern "C"
{
  extern int mbtowc(wchar_t *__restrict __pwc, const char *__restrict __s, ::size_t __n) throw();
}
extern "C"
{
  extern inline int wctomb(char *__s, wchar_t __wchar) throw() __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern inline ::size_t mbstowcs(wchar_t *__restrict __dst, const char *__restrict __src, ::size_t __len) throw() __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern inline ::size_t wcstombs(char *__restrict __dst, const wchar_t *__restrict __src, ::size_t __len) throw() __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern int rpmatch(const char *__response) throw() __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int getsubopt(char **__restrict __optionp, char *const *__restrict __tokens, char **__restrict __valuep) throw() __attribute__((__nonnull__(1, 2, 3))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern void setkey(const char *__key) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int posix_openpt(int __oflag) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int grantpt(int __fd) throw();
}
extern "C"
{
  extern int unlockpt(int __fd) throw();
}
extern "C"
{
  extern char *ptsname(int __fd) throw() __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern inline int ptsname_r(int __fd, char *__buf, ::size_t __buflen) throw() __attribute__((__nonnull__(2))) __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern int getpt();
}
extern "C"
{
  extern int getloadavg(double __loadavg[], int __nelem) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern inline __attribute__((__pure__)) __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__)) __attribute__((__leaf__)) __attribute__((__gnu_inline__)) double atof(const char *__nptr) throw()
  {
    return ::strtod(__nptr, (char **)0L);
  }
}
extern "C"
{
  extern char *__realpath_chk(const char *__restrict __name, char *__restrict __resolved, ::size_t __resolvedlen) throw() __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern char *__realpath_alias(const char *__restrict __name, char *__restrict __resolved) throw() __asm("""realpath") __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern char *__realpath_chk_warn(const char *__restrict __name, char *__restrict __resolved, ::size_t __resolvedlen) throw() __asm("""__realpath_chk") __attribute__((__warn_unused_result__)) __attribute__((__warning__("second argument of realpath must be either NULL or at ""least PATH_MAX bytes long buffer")));
}
extern "C"
{
  extern inline __attribute__((__warn_unused_result__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) char *realpath(const char *__restrict __name, char *__restrict __resolved) throw()
  {
    if (__builtin_object_size(__resolved, 2 > 1) != (::size_t) -1)
      {
        return ::__realpath_chk(__name, __resolved, __builtin_object_size(__resolved, 2 > 1));
      }
    return ::__realpath_alias(__name, __resolved);
  }
}
extern "C"
{
  extern int __ptsname_r_chk(int __fd, char *__buf, ::size_t __buflen, ::size_t __nreal) throw() __attribute__((__nonnull__(2)));
}
extern "C"
{
  extern int __ptsname_r_alias(int __fd, char *__buf, ::size_t __buflen) throw() __asm("""ptsname_r") __attribute__((__nonnull__(2)));
}
extern "C"
{
  extern int __ptsname_r_chk_warn(int __fd, char *__buf, ::size_t __buflen, ::size_t __nreal) throw() __asm("""__ptsname_r_chk") __attribute__((__nonnull__(2))) __attribute__((__warning__("ptsname_r called with buflen bigger than ""size of buf")));
}
extern "C"
{
  extern inline __attribute__((__nonnull__(2))) __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) int ptsname_r(int __fd, char *__buf, ::size_t __buflen) throw()
  {
    if (__builtin_object_size(__buf, 2 > 1) != (::size_t) -1)
      {
        if (!__builtin_constant_p(__buflen))
          {
            return ::__ptsname_r_chk(__fd, __buf, __buflen, __builtin_object_size(__buf, 2 > 1));
          }
        if (__buflen > __builtin_object_size(__buf, 2 > 1))
          {
            return ::__ptsname_r_chk_warn(__fd, __buf, __buflen, __builtin_object_size(__buf, 2 > 1));
          }
      }
    return ::__ptsname_r_alias(__fd, __buf, __buflen);
  }
}
extern "C"
{
  extern int __wctomb_chk(char *__s, wchar_t __wchar, ::size_t __buflen) throw() __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int __wctomb_alias(char *__s, wchar_t __wchar) throw() __asm("""wctomb") __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern inline __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) __attribute__((__warn_unused_result__)) int wctomb(char *__s, wchar_t __wchar) throw()
  {
    if (__builtin_object_size(__s, 2 > 1) != (::size_t) -1 && 16 > __builtin_object_size(__s, 2 > 1))
      {
        return ::__wctomb_chk(__s, __wchar, __builtin_object_size(__s, 2 > 1));
      }
    return ::__wctomb_alias(__s, __wchar);
  }
}
extern "C"
{
  extern ::size_t __mbstowcs_chk(wchar_t *__restrict __dst, const char *__restrict __src, ::size_t __len, ::size_t __dstlen) throw();
}
extern "C"
{
  extern ::size_t __mbstowcs_alias(wchar_t *__restrict __dst, const char *__restrict __src, ::size_t __len) throw() __asm("""mbstowcs");
}
extern "C"
{
  extern ::size_t __mbstowcs_chk_warn(wchar_t *__restrict __dst, const char *__restrict __src, ::size_t __len, ::size_t __dstlen) throw() __asm("""__mbstowcs_chk") __attribute__((__warning__("mbstowcs called with dst buffer smaller than len ""* sizeof (wchar_t)")));
}
extern "C"
{
  extern inline __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) ::size_t mbstowcs(wchar_t *__restrict __dst, const char *__restrict __src, ::size_t __len) throw()
  {
    if (__builtin_object_size(__dst, 2 > 1) != (::size_t) -1)
      {
        if (!__builtin_constant_p(__len))
          {
            return ::__mbstowcs_chk(__dst, __src, __len, __builtin_object_size(__dst, 2 > 1) / sizeof(wchar_t));
          }
        if (__len > __builtin_object_size(__dst, 2 > 1) / sizeof(wchar_t))
          {
            return ::__mbstowcs_chk_warn(__dst, __src, __len, __builtin_object_size(__dst, 2 > 1) / sizeof(wchar_t));
          }
      }
    return ::__mbstowcs_alias(__dst, __src, __len);
  }
}
extern "C"
{
  extern ::size_t __wcstombs_chk(char *__restrict __dst, const wchar_t *__restrict __src, ::size_t __len, ::size_t __dstlen) throw();
}
extern "C"
{
  extern ::size_t __wcstombs_alias(char *__restrict __dst, const wchar_t *__restrict __src, ::size_t __len) throw() __asm("""wcstombs");
}
extern "C"
{
  extern ::size_t __wcstombs_chk_warn(char *__restrict __dst, const wchar_t *__restrict __src, ::size_t __len, ::size_t __dstlen) throw() __asm("""__wcstombs_chk") __attribute__((__warning__("wcstombs called with dst buffer smaller than len")));
}
extern "C"
{
  extern inline __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) ::size_t wcstombs(char *__restrict __dst, const wchar_t *__restrict __src, ::size_t __len) throw()
  {
    if (__builtin_object_size(__dst, 2 > 1) != (::size_t) -1)
      {
        if (!__builtin_constant_p(__len))
          {
            return ::__wcstombs_chk(__dst, __src, __len, __builtin_object_size(__dst, 2 > 1));
          }
        if (__len > __builtin_object_size(__dst, 2 > 1))
          {
            return ::__wcstombs_chk_warn(__dst, __src, __len, __builtin_object_size(__dst, 2 > 1));
          }
      }
    return ::__wcstombs_alias(__dst, __src, __len);
  }
}
namespace std __attribute__((__visibility__("default"))) {
  using ::abs;
  inline long int abs(long int __i)
  {
    return __builtin_labs(__i);
  }
  inline long long int abs(long long int __x)
  {
    return __builtin_llabs(__x);
  }
  inline double abs(double __x)
  {
    return __builtin_fabs(__x);
  }
  inline float abs(float __x)
  {
    return __builtin_fabsf(__x);
  }
  inline long double abs(long double __x)
  {
    return __builtin_fabsl(__x);
  }
  inline __int128 abs(__int128 __x)
  {
    return __x >= 0 ? __x :  -__x;
  }
  inline __float128 abs(__float128 __x)
  {
    return __x < 0 ?  -__x : __x;
  }
  using ::div_t;
  using ::ldiv_t;
  using ::abort;
  using ::atexit;
  using ::atof;
  using ::atoi;
  using ::atol;
  using ::bsearch;
  using ::calloc;
  using ::div;
  using ::exit;
  using ::free;
  using ::getenv;
  using ::labs;
  using ::ldiv;
  using ::malloc;
  using ::mblen;
  using ::mbstowcs;
  using ::mbtowc;
  using ::qsort;
  using ::rand;
  using ::realloc;
  using ::srand;
  using ::strtod;
  using ::strtol;
  using ::strtoul;
  using ::system;
  using ::wcstombs;
  using ::wctomb;
  inline ::ldiv_t div(long int __i, long int __j)
  {
    return ::std::ldiv(__i, __j);
  }
}
namespace __gnu_cxx __attribute__((__visibility__("default"))) {
  using ::lldiv_t;
  using ::_Exit;
  using ::llabs;
  inline ::lldiv_t div(long long int __n, long long int __d)
  {
    ::lldiv_t __q /* () */ ;
    __q.quot = __n / __d;
    __q.rem = __n % __d;
    return __q;
  }
  using ::lldiv;
  using ::atoll;
  using ::strtoll;
  using ::strtoull;
  using ::strtof;
  using ::strtold;
}
namespace std __attribute__((__visibility__("default"))) {
  using ::__gnu_cxx::lldiv_t;
  using ::__gnu_cxx::_Exit;
  using ::__gnu_cxx::llabs;
  using ::__gnu_cxx::div;
  using ::__gnu_cxx::lldiv;
  using ::__gnu_cxx::atoll;
  using ::__gnu_cxx::strtof;
  using ::__gnu_cxx::strtoll;
  using ::__gnu_cxx::strtoull;
  using ::__gnu_cxx::strtold;
}
using ::std::abort;
using ::std::atexit;
using ::std::exit;
using ::std::div_t;
using ::std::ldiv_t;
using ::std::abs;
using ::std::atof;
using ::std::atoi;
using ::std::atol;
using ::std::bsearch;
using ::std::calloc;
using ::std::div;
using ::std::free;
using ::std::getenv;
using ::std::labs;
using ::std::ldiv;
using ::std::malloc;
using ::std::mblen;
using ::std::mbstowcs;
using ::std::mbtowc;
using ::std::qsort;
using ::std::rand;
using ::std::realloc;
using ::std::srand;
using ::std::strtod;
using ::std::strtol;
using ::std::strtoul;
using ::std::system;
using ::std::wcstombs;
using ::std::wctomb;
typedef ::__socklen_t socklen_t;
extern "C"
{
  extern int access(const char *__name, int __type) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int euidaccess(const char *__name, int __type) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int eaccess(const char *__name, int __type) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int faccessat(int __fd, const char *__file, int __type, int __flag) throw() __attribute__((__nonnull__(2))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern ::__off_t lseek(int __fd, ::__off_t __offset, int __whence) throw();
}
extern "C"
{
  extern ::__off64_t lseek64(int __fd, ::__off64_t __offset, int __whence) throw();
}
extern "C"
{
  extern int close(int __fd);
}
extern "C"
{
  extern inline ::ssize_t read(int __fd, void *__buf, ::size_t __nbytes) __attribute__((__warn_unused_result__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern ::ssize_t write(int __fd, const void *__buf, ::size_t __n) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern inline ::ssize_t pread(int __fd, void *__buf, ::size_t __nbytes, ::__off_t __offset) __attribute__((__warn_unused_result__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern ::ssize_t pwrite(int __fd, const void *__buf, ::size_t __n, ::__off_t __offset) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern inline ::ssize_t pread64(int __fd, void *__buf, ::size_t __nbytes, ::__off64_t __offset) __attribute__((__warn_unused_result__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern ::ssize_t pwrite64(int __fd, const void *__buf, ::size_t __n, ::__off64_t __offset) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int pipe(int __pipedes[2L]) throw() __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int pipe2(int __pipedes[2L], int __flags) throw() __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern unsigned int alarm(unsigned int __seconds) throw();
}
extern "C"
{
  extern unsigned int sleep(unsigned int __seconds);
}
extern "C"
{
  extern ::__useconds_t ualarm(::__useconds_t __value, ::__useconds_t __interval) throw();
}
extern "C"
{
  extern int usleep(::__useconds_t __useconds);
}
extern "C"
{
  extern int pause();
}
extern "C"
{
  extern int chown(const char *__file, ::__uid_t __owner, ::__gid_t __group) throw() __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int fchown(int __fd, ::__uid_t __owner, ::__gid_t __group) throw() __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int lchown(const char *__file, ::__uid_t __owner, ::__gid_t __group) throw() __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int fchownat(int __fd, const char *__file, ::__uid_t __owner, ::__gid_t __group, int __flag) throw() __attribute__((__nonnull__(2))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int chdir(const char *__path) throw() __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int fchdir(int __fd) throw() __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern inline char *getcwd(char *__buf, ::size_t __size) throw() __attribute__((__warn_unused_result__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern char *get_current_dir_name() throw();
}
extern "C"
{
  extern inline char *getwd(char *__buf) throw() __attribute__((__nonnull__(1))) __attribute__((__deprecated__)) __attribute__((__warn_unused_result__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern int dup(int __fd) throw() __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int dup2(int __fd, int __fd2) throw();
}
extern "C"
{
  extern int dup3(int __fd, int __fd2, int __flags) throw();
}
extern "C"
{
  extern char **__environ;
}
extern "C"
{
  extern char **environ;
}
extern "C"
{
  extern int execve(const char *__path, char *const __argv[], char *const __envp[]) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int fexecve(int __fd, char *const __argv[], char *const __envp[]) throw() __attribute__((__nonnull__(2)));
}
extern "C"
{
  extern int execv(const char *__path, char *const __argv[]) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int execle(const char *__path, const char *__arg, ...) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int execl(const char *__path, const char *__arg, ...) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int execvp(const char *__file, char *const __argv[]) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int execlp(const char *__file, const char *__arg, ...) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int execvpe(const char *__file, char *const __argv[], char *const __envp[]) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int nice(int __inc) throw() __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern void _exit(int __status) __attribute__((__noreturn__));
}
enum mcc_enum_anon_56
{
  _PC_LINK_MAX = 0,
  _PC_MAX_CANON = 1,
  _PC_MAX_INPUT = 2,
  _PC_NAME_MAX = 3,
  _PC_PATH_MAX = 4,
  _PC_PIPE_BUF = 5,
  _PC_CHOWN_RESTRICTED = 6,
  _PC_NO_TRUNC = 7,
  _PC_VDISABLE = 8,
  _PC_SYNC_IO = 9,
  _PC_ASYNC_IO = 10,
  _PC_PRIO_IO = 11,
  _PC_SOCK_MAXBUF = 12,
  _PC_FILESIZEBITS = 13,
  _PC_REC_INCR_XFER_SIZE = 14,
  _PC_REC_MAX_XFER_SIZE = 15,
  _PC_REC_MIN_XFER_SIZE = 16,
  _PC_REC_XFER_ALIGN = 17,
  _PC_ALLOC_SIZE_MIN = 18,
  _PC_SYMLINK_MAX = 19,
  _PC_2_SYMLINKS = 20
};
enum mcc_enum_anon_57
{
  _SC_ARG_MAX = 0,
  _SC_CHILD_MAX = 1,
  _SC_CLK_TCK = 2,
  _SC_NGROUPS_MAX = 3,
  _SC_OPEN_MAX = 4,
  _SC_STREAM_MAX = 5,
  _SC_TZNAME_MAX = 6,
  _SC_JOB_CONTROL = 7,
  _SC_SAVED_IDS = 8,
  _SC_REALTIME_SIGNALS = 9,
  _SC_PRIORITY_SCHEDULING = 10,
  _SC_TIMERS = 11,
  _SC_ASYNCHRONOUS_IO = 12,
  _SC_PRIORITIZED_IO = 13,
  _SC_SYNCHRONIZED_IO = 14,
  _SC_FSYNC = 15,
  _SC_MAPPED_FILES = 16,
  _SC_MEMLOCK = 17,
  _SC_MEMLOCK_RANGE = 18,
  _SC_MEMORY_PROTECTION = 19,
  _SC_MESSAGE_PASSING = 20,
  _SC_SEMAPHORES = 21,
  _SC_SHARED_MEMORY_OBJECTS = 22,
  _SC_AIO_LISTIO_MAX = 23,
  _SC_AIO_MAX = 24,
  _SC_AIO_PRIO_DELTA_MAX = 25,
  _SC_DELAYTIMER_MAX = 26,
  _SC_MQ_OPEN_MAX = 27,
  _SC_MQ_PRIO_MAX = 28,
  _SC_VERSION = 29,
  _SC_PAGESIZE = 30,
  _SC_RTSIG_MAX = 31,
  _SC_SEM_NSEMS_MAX = 32,
  _SC_SEM_VALUE_MAX = 33,
  _SC_SIGQUEUE_MAX = 34,
  _SC_TIMER_MAX = 35,
  _SC_BC_BASE_MAX = 36,
  _SC_BC_DIM_MAX = 37,
  _SC_BC_SCALE_MAX = 38,
  _SC_BC_STRING_MAX = 39,
  _SC_COLL_WEIGHTS_MAX = 40,
  _SC_EQUIV_CLASS_MAX = 41,
  _SC_EXPR_NEST_MAX = 42,
  _SC_LINE_MAX = 43,
  _SC_RE_DUP_MAX = 44,
  _SC_CHARCLASS_NAME_MAX = 45,
  _SC_2_VERSION = 46,
  _SC_2_C_BIND = 47,
  _SC_2_C_DEV = 48,
  _SC_2_FORT_DEV = 49,
  _SC_2_FORT_RUN = 50,
  _SC_2_SW_DEV = 51,
  _SC_2_LOCALEDEF = 52,
  _SC_PII = 53,
  _SC_PII_XTI = 54,
  _SC_PII_SOCKET = 55,
  _SC_PII_INTERNET = 56,
  _SC_PII_OSI = 57,
  _SC_POLL = 58,
  _SC_SELECT = 59,
  _SC_UIO_MAXIOV = 60,
  _SC_IOV_MAX = ::_SC_UIO_MAXIOV,
  _SC_PII_INTERNET_STREAM = 61,
  _SC_PII_INTERNET_DGRAM = 62,
  _SC_PII_OSI_COTS = 63,
  _SC_PII_OSI_CLTS = 64,
  _SC_PII_OSI_M = 65,
  _SC_T_IOV_MAX = 66,
  _SC_THREADS = 67,
  _SC_THREAD_SAFE_FUNCTIONS = 68,
  _SC_GETGR_R_SIZE_MAX = 69,
  _SC_GETPW_R_SIZE_MAX = 70,
  _SC_LOGIN_NAME_MAX = 71,
  _SC_TTY_NAME_MAX = 72,
  _SC_THREAD_DESTRUCTOR_ITERATIONS = 73,
  _SC_THREAD_KEYS_MAX = 74,
  _SC_THREAD_STACK_MIN = 75,
  _SC_THREAD_THREADS_MAX = 76,
  _SC_THREAD_ATTR_STACKADDR = 77,
  _SC_THREAD_ATTR_STACKSIZE = 78,
  _SC_THREAD_PRIORITY_SCHEDULING = 79,
  _SC_THREAD_PRIO_INHERIT = 80,
  _SC_THREAD_PRIO_PROTECT = 81,
  _SC_THREAD_PROCESS_SHARED = 82,
  _SC_NPROCESSORS_CONF = 83,
  _SC_NPROCESSORS_ONLN = 84,
  _SC_PHYS_PAGES = 85,
  _SC_AVPHYS_PAGES = 86,
  _SC_ATEXIT_MAX = 87,
  _SC_PASS_MAX = 88,
  _SC_XOPEN_VERSION = 89,
  _SC_XOPEN_XCU_VERSION = 90,
  _SC_XOPEN_UNIX = 91,
  _SC_XOPEN_CRYPT = 92,
  _SC_XOPEN_ENH_I18N = 93,
  _SC_XOPEN_SHM = 94,
  _SC_2_CHAR_TERM = 95,
  _SC_2_C_VERSION = 96,
  _SC_2_UPE = 97,
  _SC_XOPEN_XPG2 = 98,
  _SC_XOPEN_XPG3 = 99,
  _SC_XOPEN_XPG4 = 100,
  _SC_CHAR_BIT = 101,
  _SC_CHAR_MAX = 102,
  _SC_CHAR_MIN = 103,
  _SC_INT_MAX = 104,
  _SC_INT_MIN = 105,
  _SC_LONG_BIT = 106,
  _SC_WORD_BIT = 107,
  _SC_MB_LEN_MAX = 108,
  _SC_NZERO = 109,
  _SC_SSIZE_MAX = 110,
  _SC_SCHAR_MAX = 111,
  _SC_SCHAR_MIN = 112,
  _SC_SHRT_MAX = 113,
  _SC_SHRT_MIN = 114,
  _SC_UCHAR_MAX = 115,
  _SC_UINT_MAX = 116,
  _SC_ULONG_MAX = 117,
  _SC_USHRT_MAX = 118,
  _SC_NL_ARGMAX = 119,
  _SC_NL_LANGMAX = 120,
  _SC_NL_MSGMAX = 121,
  _SC_NL_NMAX = 122,
  _SC_NL_SETMAX = 123,
  _SC_NL_TEXTMAX = 124,
  _SC_XBS5_ILP32_OFF32 = 125,
  _SC_XBS5_ILP32_OFFBIG = 126,
  _SC_XBS5_LP64_OFF64 = 127,
  _SC_XBS5_LPBIG_OFFBIG = 128,
  _SC_XOPEN_LEGACY = 129,
  _SC_XOPEN_REALTIME = 130,
  _SC_XOPEN_REALTIME_THREADS = 131,
  _SC_ADVISORY_INFO = 132,
  _SC_BARRIERS = 133,
  _SC_BASE = 134,
  _SC_C_LANG_SUPPORT = 135,
  _SC_C_LANG_SUPPORT_R = 136,
  _SC_CLOCK_SELECTION = 137,
  _SC_CPUTIME = 138,
  _SC_THREAD_CPUTIME = 139,
  _SC_DEVICE_IO = 140,
  _SC_DEVICE_SPECIFIC = 141,
  _SC_DEVICE_SPECIFIC_R = 142,
  _SC_FD_MGMT = 143,
  _SC_FIFO = 144,
  _SC_PIPE = 145,
  _SC_FILE_ATTRIBUTES = 146,
  _SC_FILE_LOCKING = 147,
  _SC_FILE_SYSTEM = 148,
  _SC_MONOTONIC_CLOCK = 149,
  _SC_MULTI_PROCESS = 150,
  _SC_SINGLE_PROCESS = 151,
  _SC_NETWORKING = 152,
  _SC_READER_WRITER_LOCKS = 153,
  _SC_SPIN_LOCKS = 154,
  _SC_REGEXP = 155,
  _SC_REGEX_VERSION = 156,
  _SC_SHELL = 157,
  _SC_SIGNALS = 158,
  _SC_SPAWN = 159,
  _SC_SPORADIC_SERVER = 160,
  _SC_THREAD_SPORADIC_SERVER = 161,
  _SC_SYSTEM_DATABASE = 162,
  _SC_SYSTEM_DATABASE_R = 163,
  _SC_TIMEOUTS = 164,
  _SC_TYPED_MEMORY_OBJECTS = 165,
  _SC_USER_GROUPS = 166,
  _SC_USER_GROUPS_R = 167,
  _SC_2_PBS = 168,
  _SC_2_PBS_ACCOUNTING = 169,
  _SC_2_PBS_LOCATE = 170,
  _SC_2_PBS_MESSAGE = 171,
  _SC_2_PBS_TRACK = 172,
  _SC_SYMLOOP_MAX = 173,
  _SC_STREAMS = 174,
  _SC_2_PBS_CHECKPOINT = 175,
  _SC_V6_ILP32_OFF32 = 176,
  _SC_V6_ILP32_OFFBIG = 177,
  _SC_V6_LP64_OFF64 = 178,
  _SC_V6_LPBIG_OFFBIG = 179,
  _SC_HOST_NAME_MAX = 180,
  _SC_TRACE = 181,
  _SC_TRACE_EVENT_FILTER = 182,
  _SC_TRACE_INHERIT = 183,
  _SC_TRACE_LOG = 184,
  _SC_LEVEL1_ICACHE_SIZE = 185,
  _SC_LEVEL1_ICACHE_ASSOC = 186,
  _SC_LEVEL1_ICACHE_LINESIZE = 187,
  _SC_LEVEL1_DCACHE_SIZE = 188,
  _SC_LEVEL1_DCACHE_ASSOC = 189,
  _SC_LEVEL1_DCACHE_LINESIZE = 190,
  _SC_LEVEL2_CACHE_SIZE = 191,
  _SC_LEVEL2_CACHE_ASSOC = 192,
  _SC_LEVEL2_CACHE_LINESIZE = 193,
  _SC_LEVEL3_CACHE_SIZE = 194,
  _SC_LEVEL3_CACHE_ASSOC = 195,
  _SC_LEVEL3_CACHE_LINESIZE = 196,
  _SC_LEVEL4_CACHE_SIZE = 197,
  _SC_LEVEL4_CACHE_ASSOC = 198,
  _SC_LEVEL4_CACHE_LINESIZE = 199,
  _SC_IPV6 = ::_SC_LEVEL1_ICACHE_SIZE + 50,
  _SC_RAW_SOCKETS = 236,
  _SC_V7_ILP32_OFF32 = 237,
  _SC_V7_ILP32_OFFBIG = 238,
  _SC_V7_LP64_OFF64 = 239,
  _SC_V7_LPBIG_OFFBIG = 240,
  _SC_SS_REPL_MAX = 241,
  _SC_TRACE_EVENT_NAME_MAX = 242,
  _SC_TRACE_NAME_MAX = 243,
  _SC_TRACE_SYS_MAX = 244,
  _SC_TRACE_USER_EVENT_MAX = 245,
  _SC_XOPEN_STREAMS = 246,
  _SC_THREAD_ROBUST_PRIO_INHERIT = 247,
  _SC_THREAD_ROBUST_PRIO_PROTECT = 248
};
enum mcc_enum_anon_58
{
  _CS_PATH = 0,
  _CS_V6_WIDTH_RESTRICTED_ENVS = 1,
  _CS_GNU_LIBC_VERSION = 2,
  _CS_GNU_LIBPTHREAD_VERSION = 3,
  _CS_V5_WIDTH_RESTRICTED_ENVS = 4,
  _CS_V7_WIDTH_RESTRICTED_ENVS = 5,
  _CS_LFS_CFLAGS = 1000,
  _CS_LFS_LDFLAGS = 1001,
  _CS_LFS_LIBS = 1002,
  _CS_LFS_LINTFLAGS = 1003,
  _CS_LFS64_CFLAGS = 1004,
  _CS_LFS64_LDFLAGS = 1005,
  _CS_LFS64_LIBS = 1006,
  _CS_LFS64_LINTFLAGS = 1007,
  _CS_XBS5_ILP32_OFF32_CFLAGS = 1100,
  _CS_XBS5_ILP32_OFF32_LDFLAGS = 1101,
  _CS_XBS5_ILP32_OFF32_LIBS = 1102,
  _CS_XBS5_ILP32_OFF32_LINTFLAGS = 1103,
  _CS_XBS5_ILP32_OFFBIG_CFLAGS = 1104,
  _CS_XBS5_ILP32_OFFBIG_LDFLAGS = 1105,
  _CS_XBS5_ILP32_OFFBIG_LIBS = 1106,
  _CS_XBS5_ILP32_OFFBIG_LINTFLAGS = 1107,
  _CS_XBS5_LP64_OFF64_CFLAGS = 1108,
  _CS_XBS5_LP64_OFF64_LDFLAGS = 1109,
  _CS_XBS5_LP64_OFF64_LIBS = 1110,
  _CS_XBS5_LP64_OFF64_LINTFLAGS = 1111,
  _CS_XBS5_LPBIG_OFFBIG_CFLAGS = 1112,
  _CS_XBS5_LPBIG_OFFBIG_LDFLAGS = 1113,
  _CS_XBS5_LPBIG_OFFBIG_LIBS = 1114,
  _CS_XBS5_LPBIG_OFFBIG_LINTFLAGS = 1115,
  _CS_POSIX_V6_ILP32_OFF32_CFLAGS = 1116,
  _CS_POSIX_V6_ILP32_OFF32_LDFLAGS = 1117,
  _CS_POSIX_V6_ILP32_OFF32_LIBS = 1118,
  _CS_POSIX_V6_ILP32_OFF32_LINTFLAGS = 1119,
  _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS = 1120,
  _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS = 1121,
  _CS_POSIX_V6_ILP32_OFFBIG_LIBS = 1122,
  _CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS = 1123,
  _CS_POSIX_V6_LP64_OFF64_CFLAGS = 1124,
  _CS_POSIX_V6_LP64_OFF64_LDFLAGS = 1125,
  _CS_POSIX_V6_LP64_OFF64_LIBS = 1126,
  _CS_POSIX_V6_LP64_OFF64_LINTFLAGS = 1127,
  _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS = 1128,
  _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS = 1129,
  _CS_POSIX_V6_LPBIG_OFFBIG_LIBS = 1130,
  _CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS = 1131,
  _CS_POSIX_V7_ILP32_OFF32_CFLAGS = 1132,
  _CS_POSIX_V7_ILP32_OFF32_LDFLAGS = 1133,
  _CS_POSIX_V7_ILP32_OFF32_LIBS = 1134,
  _CS_POSIX_V7_ILP32_OFF32_LINTFLAGS = 1135,
  _CS_POSIX_V7_ILP32_OFFBIG_CFLAGS = 1136,
  _CS_POSIX_V7_ILP32_OFFBIG_LDFLAGS = 1137,
  _CS_POSIX_V7_ILP32_OFFBIG_LIBS = 1138,
  _CS_POSIX_V7_ILP32_OFFBIG_LINTFLAGS = 1139,
  _CS_POSIX_V7_LP64_OFF64_CFLAGS = 1140,
  _CS_POSIX_V7_LP64_OFF64_LDFLAGS = 1141,
  _CS_POSIX_V7_LP64_OFF64_LIBS = 1142,
  _CS_POSIX_V7_LP64_OFF64_LINTFLAGS = 1143,
  _CS_POSIX_V7_LPBIG_OFFBIG_CFLAGS = 1144,
  _CS_POSIX_V7_LPBIG_OFFBIG_LDFLAGS = 1145,
  _CS_POSIX_V7_LPBIG_OFFBIG_LIBS = 1146,
  _CS_POSIX_V7_LPBIG_OFFBIG_LINTFLAGS = 1147,
  _CS_V6_ENV = 1148,
  _CS_V7_ENV = 1149
};
extern "C"
{
  extern long int pathconf(const char *__path, int __name) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern long int fpathconf(int __fd, int __name) throw();
}
extern "C"
{
  extern long int sysconf(int __name) throw();
}
extern "C"
{
  extern inline ::size_t confstr(int __name, char *__buf, ::size_t __len) throw() __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern ::__pid_t getpid() throw();
}
extern "C"
{
  extern ::__pid_t getppid() throw();
}
extern "C"
{
  extern ::__pid_t getpgrp() throw();
}
extern "C"
{
  extern ::__pid_t __getpgid(::__pid_t __pid) throw();
}
extern "C"
{
  extern ::__pid_t getpgid(::__pid_t __pid) throw();
}
extern "C"
{
  extern int setpgid(::__pid_t __pid, ::__pid_t __pgid) throw();
}
extern "C"
{
  extern int setpgrp() throw();
}
extern "C"
{
  extern ::__pid_t setsid() throw();
}
extern "C"
{
  extern ::__pid_t getsid(::__pid_t __pid) throw();
}
extern "C"
{
  extern ::__uid_t getuid() throw();
}
extern "C"
{
  extern ::__uid_t geteuid() throw();
}
extern "C"
{
  extern ::__gid_t getgid() throw();
}
extern "C"
{
  extern ::__gid_t getegid() throw();
}
extern "C"
{
  extern inline int getgroups(int __size, ::__gid_t __list[]) throw() __attribute__((__warn_unused_result__)) __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern int group_member(::__gid_t __gid) throw();
}
extern "C"
{
  extern int setuid(::__uid_t __uid) throw() __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int setreuid(::__uid_t __ruid, ::__uid_t __euid) throw() __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int seteuid(::__uid_t __uid) throw() __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int setgid(::__gid_t __gid) throw() __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int setregid(::__gid_t __rgid, ::__gid_t __egid) throw() __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int setegid(::__gid_t __gid) throw() __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int getresuid(::__uid_t *__ruid, ::__uid_t *__euid, ::__uid_t *__suid) throw();
}
extern "C"
{
  extern int getresgid(::__gid_t *__rgid, ::__gid_t *__egid, ::__gid_t *__sgid) throw();
}
extern "C"
{
  extern int setresuid(::__uid_t __ruid, ::__uid_t __euid, ::__uid_t __suid) throw() __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int setresgid(::__gid_t __rgid, ::__gid_t __egid, ::__gid_t __sgid) throw() __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern ::__pid_t fork() throw();
}
extern "C"
{
  extern ::__pid_t vfork() throw();
}
extern "C"
{
  extern char *ttyname(int __fd) throw();
}
extern "C"
{
  extern inline int ttyname_r(int __fd, char *__buf, ::size_t __buflen) throw() __attribute__((__nonnull__(2))) __attribute__((__warn_unused_result__)) __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern int isatty(int __fd) throw();
}
extern "C"
{
  extern int ttyslot() throw();
}
extern "C"
{
  extern int link(const char *__from, const char *__to) throw() __attribute__((__nonnull__(1, 2))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int linkat(int __fromfd, const char *__from, int __tofd, const char *__to, int __flags) throw() __attribute__((__nonnull__(2, 4))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int symlink(const char *__from, const char *__to) throw() __attribute__((__nonnull__(1, 2))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern inline ::ssize_t readlink(const char *__restrict __path, char *__restrict __buf, ::size_t __len) throw() __attribute__((__nonnull__(1, 2))) __attribute__((__warn_unused_result__)) __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern int symlinkat(const char *__from, int __tofd, const char *__to) throw() __attribute__((__nonnull__(1, 3))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern inline ::ssize_t readlinkat(int __fd, const char *__restrict __path, char *__restrict __buf, ::size_t __len) throw() __attribute__((__nonnull__(2, 3))) __attribute__((__warn_unused_result__)) __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern int unlink(const char *__name) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int unlinkat(int __fd, const char *__name, int __flag) throw() __attribute__((__nonnull__(2)));
}
extern "C"
{
  extern int rmdir(const char *__path) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern ::__pid_t tcgetpgrp(int __fd) throw();
}
extern "C"
{
  extern int tcsetpgrp(int __fd, ::__pid_t __pgrp_id) throw();
}
extern "C"
{
  extern char *getlogin();
}
extern "C"
{
  extern inline int getlogin_r(char *__buf, ::size_t __buflen) __attribute__((__nonnull__(1))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern int setlogin(const char *__name) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern inline int gethostname(char *__buf, ::size_t __buflen) throw() __attribute__((__nonnull__(1))) __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern int sethostname(const char *__name, ::size_t __len) throw() __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int sethostid(long int __id) throw() __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern inline int getdomainname(char *__buf, ::size_t __buflen) throw() __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__)) __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__));
}
extern "C"
{
  extern int setdomainname(const char *__name, ::size_t __len) throw() __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int vhangup() throw();
}
extern "C"
{
  extern int revoke(const char *__file) throw() __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int profil(unsigned short int *__sample_buffer, ::size_t __size, ::size_t __offset, unsigned int __scale) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int acct(const char *__name) throw();
}
extern "C"
{
  extern char *getusershell() throw();
}
extern "C"
{
  extern void endusershell() throw();
}
extern "C"
{
  extern void setusershell() throw();
}
extern "C"
{
  extern int daemon(int __nochdir, int __noclose) throw() __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int chroot(const char *__path) throw() __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern char *getpass(const char *__prompt) __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int fsync(int __fd);
}
extern "C"
{
  extern int syncfs(int __fd) throw();
}
extern "C"
{
  extern long int gethostid();
}
extern "C"
{
  extern void sync() throw();
}
extern "C"
{
  extern int getpagesize() throw() __attribute__((__const__));
}
extern "C"
{
  extern int getdtablesize() throw();
}
extern "C"
{
  extern int truncate(const char *__file, ::__off_t __length) throw() __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int truncate64(const char *__file, ::__off64_t __length) throw() __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int ftruncate(int __fd, ::__off_t __length) throw() __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int ftruncate64(int __fd, ::__off64_t __length) throw() __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int brk(void *__addr) throw() __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern void *sbrk(::intptr_t __delta) throw();
}
extern "C"
{
  extern long int syscall(long int __sysno, ...) throw();
}
extern "C"
{
  extern int lockf(int __fd, int __cmd, ::__off_t __len) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int lockf64(int __fd, int __cmd, ::__off64_t __len) __attribute__((__warn_unused_result__));
}
extern "C"
{
  ::ssize_t copy_file_range(int __infd, ::__off64_t *__pinoff, int __outfd, ::__off64_t *__poutoff, ::size_t __length, unsigned int __flags);
}
extern "C"
{
  extern int fdatasync(int __fildes);
}
extern "C"
{
  extern char *crypt(const char *__key, const char *__salt) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern void encrypt(char *__glibc_block, int __edflag) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern void swab(const void *__restrict __from, void *__restrict __to, ::ssize_t __n) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  int getentropy(void *__buffer, ::size_t __length) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern ::ssize_t __read_chk(int __fd, void *__buf, ::size_t __nbytes, ::size_t __buflen) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern ::ssize_t __read_alias(int __fd, void *__buf, ::size_t __nbytes) __asm("""read") __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern ::ssize_t __read_chk_warn(int __fd, void *__buf, ::size_t __nbytes, ::size_t __buflen) __asm("""__read_chk") __attribute__((__warn_unused_result__)) __attribute__((__warning__("read called with bigger length than size of ""the destination buffer")));
}
extern "C"
{
  extern inline __attribute__((__warn_unused_result__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) ::ssize_t read(int __fd, void *__buf, ::size_t __nbytes)
  {
    if (__builtin_object_size(__buf, 0) != (::size_t) -1)
      {
        if (!__builtin_constant_p(__nbytes))
          {
            return ::__read_chk(__fd, __buf, __nbytes, __builtin_object_size(__buf, 0));
          }
        if (__nbytes > __builtin_object_size(__buf, 0))
          {
            return ::__read_chk_warn(__fd, __buf, __nbytes, __builtin_object_size(__buf, 0));
          }
      }
    return ::__read_alias(__fd, __buf, __nbytes);
  }
}
extern "C"
{
  extern ::ssize_t __pread_chk(int __fd, void *__buf, ::size_t __nbytes, ::__off_t __offset, ::size_t __bufsize) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern ::ssize_t __pread64_chk(int __fd, void *__buf, ::size_t __nbytes, ::__off64_t __offset, ::size_t __bufsize) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern ::ssize_t __pread_alias(int __fd, void *__buf, ::size_t __nbytes, ::__off_t __offset) __asm("""pread") __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern ::ssize_t __pread64_alias(int __fd, void *__buf, ::size_t __nbytes, ::__off64_t __offset) __asm("""pread64") __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern ::ssize_t __pread_chk_warn(int __fd, void *__buf, ::size_t __nbytes, ::__off_t __offset, ::size_t __bufsize) __asm("""__pread_chk") __attribute__((__warn_unused_result__)) __attribute__((__warning__("pread called with bigger length than size of ""the destination buffer")));
}
extern "C"
{
  extern ::ssize_t __pread64_chk_warn(int __fd, void *__buf, ::size_t __nbytes, ::__off64_t __offset, ::size_t __bufsize) __asm("""__pread64_chk") __attribute__((__warn_unused_result__)) __attribute__((__warning__("pread64 called with bigger length than size of ""the destination buffer")));
}
extern "C"
{
  extern inline __attribute__((__warn_unused_result__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) ::ssize_t pread(int __fd, void *__buf, ::size_t __nbytes, ::__off_t __offset)
  {
    if (__builtin_object_size(__buf, 0) != (::size_t) -1)
      {
        if (!__builtin_constant_p(__nbytes))
          {
            return ::__pread_chk(__fd, __buf, __nbytes, __offset, __builtin_object_size(__buf, 0));
          }
        if (__nbytes > __builtin_object_size(__buf, 0))
          {
            return ::__pread_chk_warn(__fd, __buf, __nbytes, __offset, __builtin_object_size(__buf, 0));
          }
      }
    return ::__pread_alias(__fd, __buf, __nbytes, __offset);
  }
}
extern "C"
{
  extern inline __attribute__((__warn_unused_result__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) ::ssize_t pread64(int __fd, void *__buf, ::size_t __nbytes, ::__off64_t __offset)
  {
    if (__builtin_object_size(__buf, 0) != (::size_t) -1)
      {
        if (!__builtin_constant_p(__nbytes))
          {
            return ::__pread64_chk(__fd, __buf, __nbytes, __offset, __builtin_object_size(__buf, 0));
          }
        if (__nbytes > __builtin_object_size(__buf, 0))
          {
            return ::__pread64_chk_warn(__fd, __buf, __nbytes, __offset, __builtin_object_size(__buf, 0));
          }
      }
    return ::__pread64_alias(__fd, __buf, __nbytes, __offset);
  }
}
extern "C"
{
  extern ::ssize_t __readlink_chk(const char *__restrict __path, char *__restrict __buf, ::size_t __len, ::size_t __buflen) throw() __attribute__((__nonnull__(1, 2))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern ::ssize_t __readlink_alias(const char *__restrict __path, char *__restrict __buf, ::size_t __len) throw() __asm("""readlink") __attribute__((__nonnull__(1, 2))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern ::ssize_t __readlink_chk_warn(const char *__restrict __path, char *__restrict __buf, ::size_t __len, ::size_t __buflen) throw() __asm("""__readlink_chk") __attribute__((__nonnull__(1, 2))) __attribute__((__warn_unused_result__)) __attribute__((__warning__("readlink called with bigger length ""than size of destination buffer")));
}
extern "C"
{
  extern inline __attribute__((__nonnull__(1, 2))) __attribute__((__warn_unused_result__)) __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) ::ssize_t readlink(const char *__restrict __path, char *__restrict __buf, ::size_t __len) throw()
  {
    if (__builtin_object_size(__buf, 2 > 1) != (::size_t) -1)
      {
        if (!__builtin_constant_p(__len))
          {
            return ::__readlink_chk(__path, __buf, __len, __builtin_object_size(__buf, 2 > 1));
          }
        if (__len > __builtin_object_size(__buf, 2 > 1))
          {
            return ::__readlink_chk_warn(__path, __buf, __len, __builtin_object_size(__buf, 2 > 1));
          }
      }
    return ::__readlink_alias(__path, __buf, __len);
  }
}
extern "C"
{
  extern ::ssize_t __readlinkat_chk(int __fd, const char *__restrict __path, char *__restrict __buf, ::size_t __len, ::size_t __buflen) throw() __attribute__((__nonnull__(2, 3))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern ::ssize_t __readlinkat_alias(int __fd, const char *__restrict __path, char *__restrict __buf, ::size_t __len) throw() __asm("""readlinkat") __attribute__((__nonnull__(2, 3))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern ::ssize_t __readlinkat_chk_warn(int __fd, const char *__restrict __path, char *__restrict __buf, ::size_t __len, ::size_t __buflen) throw() __asm("""__readlinkat_chk") __attribute__((__nonnull__(2, 3))) __attribute__((__warn_unused_result__)) __attribute__((__warning__("readlinkat called with bigger ""length than size of destination ""buffer")));
}
extern "C"
{
  extern inline __attribute__((__nonnull__(2, 3))) __attribute__((__warn_unused_result__)) __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) ::ssize_t readlinkat(int __fd, const char *__restrict __path, char *__restrict __buf, ::size_t __len) throw()
  {
    if (__builtin_object_size(__buf, 2 > 1) != (::size_t) -1)
      {
        if (!__builtin_constant_p(__len))
          {
            return ::__readlinkat_chk(__fd, __path, __buf, __len, __builtin_object_size(__buf, 2 > 1));
          }
        if (__len > __builtin_object_size(__buf, 2 > 1))
          {
            return ::__readlinkat_chk_warn(__fd, __path, __buf, __len, __builtin_object_size(__buf, 2 > 1));
          }
      }
    return ::__readlinkat_alias(__fd, __path, __buf, __len);
  }
}
extern "C"
{
  extern char *__getcwd_chk(char *__buf, ::size_t __size, ::size_t __buflen) throw() __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern char *__getcwd_alias(char *__buf, ::size_t __size) throw() __asm("""getcwd") __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern char *__getcwd_chk_warn(char *__buf, ::size_t __size, ::size_t __buflen) throw() __asm("""__getcwd_chk") __attribute__((__warn_unused_result__)) __attribute__((__warning__("getcwd caller with bigger length than size of ""destination buffer")));
}
extern "C"
{
  extern inline __attribute__((__warn_unused_result__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) char *getcwd(char *__buf, ::size_t __size) throw()
  {
    if (__builtin_object_size(__buf, 2 > 1) != (::size_t) -1)
      {
        if (!__builtin_constant_p(__size))
          {
            return ::__getcwd_chk(__buf, __size, __builtin_object_size(__buf, 2 > 1));
          }
        if (__size > __builtin_object_size(__buf, 2 > 1))
          {
            return ::__getcwd_chk_warn(__buf, __size, __builtin_object_size(__buf, 2 > 1));
          }
      }
    return ::__getcwd_alias(__buf, __size);
  }
}
extern "C"
{
  extern char *__getwd_chk(char *__buf, ::size_t buflen) throw() __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern char *__getwd_warn(char *__buf) throw() __asm("""getwd") __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__)) __attribute__((__warning__("please use getcwd instead, as getwd ""doesn't specify buffer size")));
}
extern "C"
{
  extern inline __attribute__((__nonnull__(1))) __attribute__((__deprecated__)) __attribute__((__warn_unused_result__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) char *getwd(char *__buf) throw()
  {
    if (__builtin_object_size(__buf, 2 > 1) != (::size_t) -1)
      {
        return ::__getwd_chk(__buf, __builtin_object_size(__buf, 2 > 1));
      }
    return ::__getwd_warn(__buf);
  }
}
extern "C"
{
  extern ::size_t __confstr_chk(int __name, char *__buf, ::size_t __len, ::size_t __buflen) throw();
}
extern "C"
{
  extern ::size_t __confstr_alias(int __name, char *__buf, ::size_t __len) throw() __asm("""confstr");
}
extern "C"
{
  extern ::size_t __confstr_chk_warn(int __name, char *__buf, ::size_t __len, ::size_t __buflen) throw() __asm("""__confstr_chk") __attribute__((__warning__("confstr called with bigger length than size of destination ""buffer")));
}
extern "C"
{
  extern inline __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) ::size_t confstr(int __name, char *__buf, ::size_t __len) throw()
  {
    if (__builtin_object_size(__buf, 2 > 1) != (::size_t) -1)
      {
        if (!__builtin_constant_p(__len))
          {
            return ::__confstr_chk(__name, __buf, __len, __builtin_object_size(__buf, 2 > 1));
          }
        if (__builtin_object_size(__buf, 2 > 1) < __len)
          {
            return ::__confstr_chk_warn(__name, __buf, __len, __builtin_object_size(__buf, 2 > 1));
          }
      }
    return ::__confstr_alias(__name, __buf, __len);
  }
}
extern "C"
{
  extern int __getgroups_chk(int __size, ::__gid_t __list[], ::size_t __listlen) throw() __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int __getgroups_alias(int __size, ::__gid_t __list[]) throw() __asm("""getgroups") __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int __getgroups_chk_warn(int __size, ::__gid_t __list[], ::size_t __listlen) throw() __asm("""__getgroups_chk") __attribute__((__warn_unused_result__)) __attribute__((__warning__("getgroups called with bigger group count than what ""can fit into destination buffer")));
}
extern "C"
{
  extern inline __attribute__((__warn_unused_result__)) __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) int getgroups(int __size, ::__gid_t *__list) throw()
  {
    if (__builtin_object_size(__list, 2 > 1) != (::size_t) -1)
      {
        if (!__builtin_constant_p(__size) || __size < 0)
          {
            return ::__getgroups_chk(__size, __list, __builtin_object_size(__list, 2 > 1));
          }
        if (__size * sizeof(::__gid_t) > __builtin_object_size(__list, 2 > 1))
          {
            return ::__getgroups_chk_warn(__size, __list, __builtin_object_size(__list, 2 > 1));
          }
      }
    return ::__getgroups_alias(__size, __list);
  }
}
extern "C"
{
  extern int __ttyname_r_chk(int __fd, char *__buf, ::size_t __buflen, ::size_t __nreal) throw() __attribute__((__nonnull__(2)));
}
extern "C"
{
  extern int __ttyname_r_alias(int __fd, char *__buf, ::size_t __buflen) throw() __asm("""ttyname_r") __attribute__((__nonnull__(2)));
}
extern "C"
{
  extern int __ttyname_r_chk_warn(int __fd, char *__buf, ::size_t __buflen, ::size_t __nreal) throw() __asm("""__ttyname_r_chk") __attribute__((__nonnull__(2))) __attribute__((__warning__("ttyname_r called with bigger buflen than ""size of destination buffer")));
}
extern "C"
{
  extern inline __attribute__((__nonnull__(2))) __attribute__((__warn_unused_result__)) __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) int ttyname_r(int __fd, char *__buf, ::size_t __buflen) throw()
  {
    if (__builtin_object_size(__buf, 2 > 1) != (::size_t) -1)
      {
        if (!__builtin_constant_p(__buflen))
          {
            return ::__ttyname_r_chk(__fd, __buf, __buflen, __builtin_object_size(__buf, 2 > 1));
          }
        if (__buflen > __builtin_object_size(__buf, 2 > 1))
          {
            return ::__ttyname_r_chk_warn(__fd, __buf, __buflen, __builtin_object_size(__buf, 2 > 1));
          }
      }
    return ::__ttyname_r_alias(__fd, __buf, __buflen);
  }
}
extern "C"
{
  extern int __getlogin_r_chk(char *__buf, ::size_t __buflen, ::size_t __nreal) __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int __getlogin_r_alias(char *__buf, ::size_t __buflen) __asm("""getlogin_r") __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int __getlogin_r_chk_warn(char *__buf, ::size_t __buflen, ::size_t __nreal) __asm("""__getlogin_r_chk") __attribute__((__nonnull__(1))) __attribute__((__warning__("getlogin_r called with bigger buflen than ""size of destination buffer")));
}
extern "C"
{
  extern inline __attribute__((__nonnull__(1))) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) int getlogin_r(char *__buf, ::size_t __buflen)
  {
    if (__builtin_object_size(__buf, 2 > 1) != (::size_t) -1)
      {
        if (!__builtin_constant_p(__buflen))
          {
            return ::__getlogin_r_chk(__buf, __buflen, __builtin_object_size(__buf, 2 > 1));
          }
        if (__buflen > __builtin_object_size(__buf, 2 > 1))
          {
            return ::__getlogin_r_chk_warn(__buf, __buflen, __builtin_object_size(__buf, 2 > 1));
          }
      }
    return ::__getlogin_r_alias(__buf, __buflen);
  }
}
extern "C"
{
  extern int __gethostname_chk(char *__buf, ::size_t __buflen, ::size_t __nreal) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int __gethostname_alias(char *__buf, ::size_t __buflen) throw() __asm("""gethostname") __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int __gethostname_chk_warn(char *__buf, ::size_t __buflen, ::size_t __nreal) throw() __asm("""__gethostname_chk") __attribute__((__nonnull__(1))) __attribute__((__warning__("gethostname called with bigger buflen than ""size of destination buffer")));
}
extern "C"
{
  extern inline __attribute__((__nonnull__(1))) __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) int gethostname(char *__buf, ::size_t __buflen) throw()
  {
    if (__builtin_object_size(__buf, 2 > 1) != (::size_t) -1)
      {
        if (!__builtin_constant_p(__buflen))
          {
            return ::__gethostname_chk(__buf, __buflen, __builtin_object_size(__buf, 2 > 1));
          }
        if (__buflen > __builtin_object_size(__buf, 2 > 1))
          {
            return ::__gethostname_chk_warn(__buf, __buflen, __builtin_object_size(__buf, 2 > 1));
          }
      }
    return ::__gethostname_alias(__buf, __buflen);
  }
}
extern "C"
{
  extern int __getdomainname_chk(char *__buf, ::size_t __buflen, ::size_t __nreal) throw() __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int __getdomainname_alias(char *__buf, ::size_t __buflen) throw() __asm("""getdomainname") __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern int __getdomainname_chk_warn(char *__buf, ::size_t __buflen, ::size_t __nreal) throw() __asm("""__getdomainname_chk") __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__)) __attribute__((__warning__("getdomainname called with bigger ""buflen than size of destination ""buffer")));
}
extern "C"
{
  extern inline __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__)) __attribute__((__leaf__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) __attribute__((__artificial__)) int getdomainname(char *__buf, ::size_t __buflen) throw()
  {
    if (__builtin_object_size(__buf, 2 > 1) != (::size_t) -1)
      {
        if (!__builtin_constant_p(__buflen))
          {
            return ::__getdomainname_chk(__buf, __buflen, __builtin_object_size(__buf, 2 > 1));
          }
        if (__buflen > __builtin_object_size(__buf, 2 > 1))
          {
            return ::__getdomainname_chk_warn(__buf, __buflen, __builtin_object_size(__buf, 2 > 1));
          }
      }
    return ::__getdomainname_alias(__buf, __buflen);
  }
}
typedef void *omp_lock_t;
typedef void *omp_nest_lock_t;
enum omp_sched_t
{
  omp_sched_static = ::nanos_omp_sched_static,
  omp_sched_dynamic = ::nanos_omp_sched_dynamic,
  omp_sched_guided = ::nanos_omp_sched_guided,
  omp_sched_auto = ::nanos_omp_sched_auto
};
extern "C"
{
  extern void omp_set_num_threads(int num_threads);
}
extern "C"
{
  extern int omp_get_num_threads();
}
extern "C"
{
  extern int omp_get_max_threads();
}
extern "C"
{
  extern int omp_get_thread_num();
}
extern "C"
{
  extern int omp_get_num_procs();
}
extern "C"
{
  extern int omp_in_parallel();
}
extern "C"
{
  extern void omp_set_dynamic(int dynamic_threads);
}
extern "C"
{
  extern int omp_get_dynamic();
}
extern "C"
{
  extern void omp_set_nested(int nested);
}
extern "C"
{
  extern int omp_get_nested();
}
extern "C"
{
  extern int omp_get_thread_limit();
}
extern "C"
{
  extern void omp_set_max_active_levels(int max_active_levels);
}
extern "C"
{
  extern int omp_get_max_active_levels();
}
extern "C"
{
  extern void omp_set_schedule(::omp_sched_t kind, int modifier);
}
extern "C"
{
  extern void omp_get_schedule(::omp_sched_t *kind, int *modifier);
}
extern "C"
{
  extern int omp_get_level();
}
extern "C"
{
  extern int omp_get_ancestor_thread_num(int level);
}
extern "C"
{
  extern int omp_get_team_size(int level);
}
extern "C"
{
  extern int omp_get_active_level();
}
extern "C"
{
  extern void omp_init_lock(::omp_lock_t *lock);
}
extern "C"
{
  extern void omp_destroy_lock(::omp_lock_t *lock);
}
extern "C"
{
  extern void omp_set_lock(::omp_lock_t *lock);
}
extern "C"
{
  extern void omp_unset_lock(::omp_lock_t *lock);
}
extern "C"
{
  extern int omp_test_lock(::omp_lock_t *lock);
}
extern "C"
{
  extern void omp_init_nest_lock(::omp_nest_lock_t *lock);
}
extern "C"
{
  extern void omp_destroy_nest_lock(::omp_nest_lock_t *lock);
}
extern "C"
{
  extern void omp_set_nest_lock(::omp_nest_lock_t *lock);
}
extern "C"
{
  extern void omp_unset_nest_lock(::omp_nest_lock_t *lock);
}
extern "C"
{
  extern int omp_test_nest_lock(::omp_nest_lock_t *lock);
}
extern "C"
{
  extern double omp_get_wtime();
}
extern "C"
{
  extern double omp_get_wtick();
}
extern "C"
{
  extern int omp_in_final();
}
OmpSsAligner::OmpSsAligner(::AbstractBlockProcessor *blockProcessor)
  : ::AbstractBlockAligner(blockProcessor, new (::OmpSsAlignerParameters)())
{
  (*this).::AbstractBlockAligner::setPreferredSizes(64, ::omp_get_max_threads() * 2);
}
OmpSsAligner::~OmpSsAligner()
{
}
void OmpSsAligner::scheduleBlocks(int grid_width, int grid_height)
{
  if ((*this).::AbstractAligner::mustDispatchLastColumn())
    {
      for (int d(0); d < grid_height + grid_width + 1 && (*this).::AbstractAligner::mustContinue(); d++)
        {
          for (int bx(0); (bx <= d && bx < grid_width) && (*this).::AbstractAligner::mustContinue(); bx++)
            {
              int by(d - bx);
              if (by >= grid_height)
                {
                  continue;
                }
              (*this).AbstractBlockAligner::alignBlock(bx, by);
            }
        }
    }
  else
    {
      int maxThreads(::omp_get_max_threads());
      for (int jj(0); jj < grid_height || jj < grid_width; jj += maxThreads)
        {
          for (int d(0); d < jj + (2 * maxThreads - 1); d++)
            {
              for (int k(0); k < maxThreads && k <= d; k++)
                {
                  int i(d - k);
                  int j(jj + k);
                  if ((i < grid_width && j < grid_height) && i <= j)
                    {
                      (*this).AbstractBlockAligner::alignBlock(i, j);
                    }
                  if ((j < grid_width && i < grid_height) && j > i)
                    {
                      (*this).AbstractBlockAligner::alignBlock(j, i);
                    }
                }
            }
        }
    }
  {
    ::nanos_wd_t nanos_wd_(::nanos_current_wd());
    ::nanos_err_t nanos_err;
    nanos_err = ::nanos_wg_wait_completion(nanos_wd_, 0);
    if (nanos_err != ::NANOS_OK)
      {
        ::nanos_handle_error(nanos_err);
      }
  }
}
 /* Instantiation of template function 'const int &::std::min<int>(const int &, const int &)' */ 
 /* Instantiation of template function '::cell_t *::std::copy< ::cell_t *, ::cell_t *>(::cell_t *, ::cell_t *, ::cell_t *)' */ 
struct  OmpSsAligner::nanos_args_0_t
{
    int bx;
    int by;
    int j0;
    int j1;
    int i0;
    int i1;
    int dispatchThisSpecialRows;
    ::OmpSsAligner *this_;
};
void OmpSsAligner::nanos_xlate_fun_OmpSsAlignercpp_0(::OmpSsAligner::nanos_args_0_t &arg, ::nanos_wd_t wd) throw()
{
  {
    void *device_base_address;
    ::nanos_err_t nanos_err;
    device_base_address = 0;
    nanos_err = ::nanos_get_addr(0, &device_base_address, wd);
    if (nanos_err != ::NANOS_OK)
      {
        ::nanos_handle_error(nanos_err);
      }
    arg.this_ = (::OmpSsAligner *)device_base_address;
  }
}
struct  OmpSsAligner::nanos_args_1_t
{
    int j0;
    int j1;
    int i1;
    ::cell_t first_cell;
    int bx;
    int by;
    ::OmpSsAligner *this_;
};
void OmpSsAligner::nanos_xlate_fun_OmpSsAlignercpp_1(::OmpSsAligner::nanos_args_1_t &arg, ::nanos_wd_t wd) throw()
{
  {
    void *device_base_address;
    ::nanos_err_t nanos_err;
    device_base_address = 0;
    nanos_err = ::nanos_get_addr(0, &device_base_address, wd);
    if (nanos_err != ::NANOS_OK)
      {
        ::nanos_handle_error(nanos_err);
      }
    arg.this_ = (::OmpSsAligner *)device_base_address;
  }
}
struct  OmpSsAligner::nanos_args_2_t
{
    int i0;
    int i1;
    int j1;
    int by;
    ::OmpSsAligner *this_;
};
void OmpSsAligner::nanos_xlate_fun_OmpSsAlignercpp_2(::OmpSsAligner::nanos_args_2_t &arg, ::nanos_wd_t wd) throw()
{
  {
    void *device_base_address;
    ::nanos_err_t nanos_err;
    device_base_address = 0;
    nanos_err = ::nanos_get_addr(0, &device_base_address, wd);
    if (nanos_err != ::NANOS_OK)
      {
        ::nanos_handle_error(nanos_err);
      }
    arg.this_ = (::OmpSsAligner *)device_base_address;
  }
}
void OmpSsAligner::alignBlock(int bx, int by, int i0, int j0, int i1, int j1)
{
  if (by == 0)
    {
      (*this).::AbstractAligner::receiveFirstRow((*this).row[bx], j1 - j0);
    }
  if (bx == 0)
    {
      (*this).col[by][0] = (*this).::AbstractAligner::getFirstColumnTail();
      (*this).::AbstractAligner::receiveFirstColumn((*this).col[by] + 1, i1 - i0);
    }
  if (!(*this).::AbstractAligner::mustContinue())
    {
      return ;
    }
  long long int priority(0);
  int grid_width((*(*this).getGrid()).::Grid::getGridWidth());
  int grid_height((*(*this).getGrid()).::Grid::getGridHeight());
  if ((*this).::AbstractAligner::mustDispatchLastColumn())
    {
      priority = grid_width - bx;
    }
  else
    {
      priority = std::min( -i0,  -j0);
    }
  int dispatchThisSpecialRows((*this).::AbstractBlockAligner::isSpecialRow(by));
  if (!(*this).::AbstractBlockAligner::isBlockPruned(bx, by))
    {
      {
        bool mcc_is_in_final;
        ::nanos_err_t mcc_err_in_final(::nanos_in_final(&mcc_is_in_final));
        if (mcc_err_in_final != ::NANOS_OK)
          {
            ::nanos_handle_error(mcc_err_in_final);
          }
        if (mcc_is_in_final)
          {
            {
              if (!(*this).::AbstractAligner::mustContinue())
                {
                  return ;
                }
              (*this).AbstractBlockAligner::processBlock(bx, by, i0, j0, i1, j1);
              if (dispatchThisSpecialRows)
                {
                  std::copy(&(*this).row[bx][0], &(*this).row[bx][j1 - j0], &(*this).renamedRow[bx][0]);
                }
            }
          }
        else
          {
            {
              static ::nanos_smp_args_t smp_ol_alignBlock_0_args = { /* .::nanos_smp_args_t::outline =  */ (void (*)(void *))(void (*)(::OmpSsAligner::nanos_args_0_t &))::OmpSsAligner::smp_ol_alignBlock_0};
              static ::nanos_const_wd_definition_1 nanos_wd_const_data = { /* .::nanos_const_wd_definition_1::base =  */ { /* .::nanos_const_wd_definition_tag::props =  */ { /* .::nanos_wd_props_t::mandatory_creation =  */ 0,  /* .::nanos_wd_props_t::tied =  */ 0,  /* .::nanos_wd_props_t::clear_chunk =  */ 0,  /* .::nanos_wd_props_t::reserved0 =  */ 0,  /* .::nanos_wd_props_t::reserved1 =  */ 0,  /* .::nanos_wd_props_t::reserved2 =  */ 0,  /* .::nanos_wd_props_t::reserved3 =  */ 0,  /* .::nanos_wd_props_t::reserved4 =  */ 0},  /* .::nanos_const_wd_definition_tag::data_alignment =  */ __alignof__(::OmpSsAligner::nanos_args_0_t),  /* .::nanos_const_wd_definition_tag::num_copies =  */ 3,  /* .::nanos_const_wd_definition_tag::num_devices =  */ 1,  /* .::nanos_const_wd_definition_tag::num_dimensions =  */ 3,  /* .::nanos_const_wd_definition_tag::description =  */ 0},  /* .::nanos_const_wd_definition_1::devices =  */ { /* [0] =  */ { /* .::nanos_device_t::factory =  */ ::nanos_smp_factory,  /* .::nanos_device_t::arg =  */ &smp_ol_alignBlock_0_args}}};
              ::nanos_wd_dyn_props_t nanos_wd_dyn_props /* () */ ;
              nanos_wd_dyn_props.tie_to = 0;
              nanos_wd_dyn_props.priority = priority;
              nanos_wd_dyn_props.flags.is_final = 0;
              nanos_wd_dyn_props.flags.is_implicit = 0;
              nanos_wd_dyn_props.flags.is_recover = 0;
              ::OmpSsAligner::nanos_args_0_t *ol_args;
              ol_args = (::OmpSsAligner::nanos_args_0_t *)0;
              ::OmpSsAligner::nanos_args_0_t imm_args /* () */ ;
              ::nanos_wd_t nanos_wd_((::nanos_wd_t)0);
              ::nanos_copy_data_t *ol_copy_data((::nanos_copy_data_t *)0);
              ::nanos_region_dimension_internal_t *ol_copy_dimensions((::nanos_region_dimension_internal_t *)0);
              ::nanos_err_t nanos_err;
              nanos_err = ::nanos_create_wd_compact(&nanos_wd_, &nanos_wd_const_data.base, &nanos_wd_dyn_props, sizeof(::OmpSsAligner::nanos_args_0_t &), (void **)&ol_args, ::nanos_current_wd(), &ol_copy_data, &ol_copy_dimensions);
              if (nanos_err != ::NANOS_OK)
                {
                  ::nanos_handle_error(nanos_err);
                }
              ::nanos_region_dimension_t dimensions_0[1L];
              ::nanos_region_dimension_t dimensions_1[1L];
              ::nanos_region_dimension_t dimensions_2[1L];
              ::nanos_data_access_t dependences[3L];
              dimensions_0[0].size = 1L * sizeof(::cell_t *);
              dimensions_0[0].lower_bound = (bx - 0L) * sizeof(::cell_t *);
              dimensions_0[0].accessed_length = (bx - 0L - (bx - 0L) + 1) * sizeof(::cell_t *);
              dependences[0].address = (void *)(*this).renamedRow;
              dependences[0].offset = 8L * (((bx) - (0L)));
              dependences[0].dimensions = dimensions_0;
              dependences[0].flags.input = 0;
              dependences[0].flags.output = 1;
              dependences[0].flags.can_rename = 0;
              dependences[0].flags.concurrent = 0;
              dependences[0].flags.commutative = 0;
              dependences[0].dimension_count = 1;
              dimensions_1[0].size = (((j1 - j0 - 1) - (0L) - 0L) + 1L) * sizeof(::cell_t);
              dimensions_1[0].lower_bound = (0L - 0L) * sizeof(::cell_t);
              dimensions_1[0].accessed_length = (j1 - j0 - 1 - 0L - (0L - 0L) + 1) * sizeof(::cell_t);
              dependences[1].address = (void *)(*this).row[bx];
              dependences[1].offset = 8L * (((0L) - (0L)));
              dependences[1].dimensions = dimensions_1;
              dependences[1].flags.input = 1;
              dependences[1].flags.output = 1;
              dependences[1].flags.can_rename = 0;
              dependences[1].flags.concurrent = 0;
              dependences[1].flags.commutative = 0;
              dependences[1].dimension_count = 1;
              dimensions_2[0].size = (((i1 - i0) - (0L) - 0L) + 1L) * sizeof(::cell_t);
              dimensions_2[0].lower_bound = (0L - 0L) * sizeof(::cell_t);
              dimensions_2[0].accessed_length = (i1 - i0 - 0L - (0L - 0L) + 1) * sizeof(::cell_t);
              dependences[2].address = (void *)(*this).col[by];
              dependences[2].offset = 8L * (((0L) - (0L)));
              dependences[2].dimensions = dimensions_2;
              dependences[2].flags.input = 1;
              dependences[2].flags.output = 1;
              dependences[2].flags.can_rename = 0;
              dependences[2].flags.concurrent = 0;
              dependences[2].flags.commutative = 0;
              dependences[2].dimension_count = 1;
              if (nanos_wd_ != (::nanos_wd_t)0)
                {
                  (*ol_args).bx = bx;
                  (*ol_args).by = by;
                  (*ol_args).j0 = j0;
                  (*ol_args).j1 = j1;
                  (*ol_args).i0 = i0;
                  (*ol_args).i1 = i1;
                  (*ol_args).dispatchThisSpecialRows = dispatchThisSpecialRows;
                  (*ol_args).this_ = this;
                  ol_copy_dimensions[0 + 0].size = 1L * sizeof(::cell_t *);
                  ol_copy_dimensions[0 + 0].lower_bound = (bx - 0L) * sizeof(::cell_t *);
                  ol_copy_dimensions[0 + 0].accessed_length = (bx - 0L - (bx - 0L) + 1) * sizeof(::cell_t *);
                  ol_copy_data[0].sharing = ::NANOS_SHARED;
                  ol_copy_data[0].address = (void *)this;
                  ol_copy_data[0].flags.input = 0;
                  ol_copy_data[0].flags.output = 1;
                  ol_copy_data[0].dimension_count = (short int)1;
                  ol_copy_data[0].dimensions = &ol_copy_dimensions[0];
                  ol_copy_data[0].offset = ((long int)&(*this).renamedRow - (long int)&*this) + (8L * (((bx) - (0L))));
                  ol_copy_dimensions[1 + 0].size = (((j1 - j0 - 1) - (0L) - 0L) + 1L) * sizeof(::cell_t);
                  ol_copy_dimensions[1 + 0].lower_bound = (0L - 0L) * sizeof(::cell_t);
                  ol_copy_dimensions[1 + 0].accessed_length = (j1 - j0 - 1 - 0L - (0L - 0L) + 1) * sizeof(::cell_t);
                  ol_copy_data[1].sharing = ::NANOS_SHARED;
                  ol_copy_data[1].address = (void *)this;
                  ol_copy_data[1].flags.input = 1;
                  ol_copy_data[1].flags.output = 1;
                  ol_copy_data[1].dimension_count = (short int)1;
                  ol_copy_data[1].dimensions = &ol_copy_dimensions[1];
                  ol_copy_data[1].offset = (((long int)&(*this).row - (long int)&*this) + (8L * (((bx) - (0L))))) + (8L * (((0L) - (0L))));
                  ol_copy_dimensions[2 + 0].size = (((i1 - i0) - (0L) - 0L) + 1L) * sizeof(::cell_t);
                  ol_copy_dimensions[2 + 0].lower_bound = (0L - 0L) * sizeof(::cell_t);
                  ol_copy_dimensions[2 + 0].accessed_length = (i1 - i0 - 0L - (0L - 0L) + 1) * sizeof(::cell_t);
                  ol_copy_data[2].sharing = ::NANOS_SHARED;
                  ol_copy_data[2].address = (void *)this;
                  ol_copy_data[2].flags.input = 1;
                  ol_copy_data[2].flags.output = 1;
                  ol_copy_data[2].dimension_count = (short int)1;
                  ol_copy_data[2].dimensions = &ol_copy_dimensions[2];
                  ol_copy_data[2].offset = (((long int)&(*this).col - (long int)&*this) + (8L * (((by) - (0L))))) + (8L * (((0L) - (0L))));
                  nanos_err = ::nanos_set_translate_function(nanos_wd_, (::nanos_translate_args_t)::OmpSsAligner::nanos_xlate_fun_OmpSsAlignercpp_0);
                  if (nanos_err != ::NANOS_OK)
                    {
                      ::nanos_handle_error(nanos_err);
                    }
                  nanos_err = ::nanos_submit(nanos_wd_, 3, &dependences[0], (::nanos_team_t)0);
                  if (nanos_err != ::NANOS_OK)
                    {
                      ::nanos_handle_error(nanos_err);
                    }
                }
              else
                {
                  imm_args.bx = bx;
                  imm_args.by = by;
                  imm_args.j0 = j0;
                  imm_args.j1 = j1;
                  imm_args.i0 = i0;
                  imm_args.i1 = i1;
                  imm_args.dispatchThisSpecialRows = dispatchThisSpecialRows;
                  imm_args.this_ = this;
                  ::nanos_copy_data_t imm_copy_data[3L];
                  ::nanos_region_dimension_internal_t imm_copy_dimensions[3L];
                  imm_copy_dimensions[0 + 0].size = 1L * sizeof(::cell_t *);
                  imm_copy_dimensions[0 + 0].lower_bound = (bx - 0L) * sizeof(::cell_t *);
                  imm_copy_dimensions[0 + 0].accessed_length = (bx - 0L - (bx - 0L) + 1) * sizeof(::cell_t *);
                  imm_copy_data[0].sharing = ::NANOS_SHARED;
                  imm_copy_data[0].address = (void *)this;
                  imm_copy_data[0].flags.input = 0;
                  imm_copy_data[0].flags.output = 1;
                  imm_copy_data[0].dimension_count = (short int)1;
                  imm_copy_data[0].dimensions = &imm_copy_dimensions[0];
                  imm_copy_data[0].offset = ((long int)&(*this).renamedRow - (long int)&*this) + (8L * (((bx) - (0L))));
                  imm_copy_dimensions[1 + 0].size = (((j1 - j0 - 1) - (0L) - 0L) + 1L) * sizeof(::cell_t);
                  imm_copy_dimensions[1 + 0].lower_bound = (0L - 0L) * sizeof(::cell_t);
                  imm_copy_dimensions[1 + 0].accessed_length = (j1 - j0 - 1 - 0L - (0L - 0L) + 1) * sizeof(::cell_t);
                  imm_copy_data[1].sharing = ::NANOS_SHARED;
                  imm_copy_data[1].address = (void *)this;
                  imm_copy_data[1].flags.input = 1;
                  imm_copy_data[1].flags.output = 1;
                  imm_copy_data[1].dimension_count = (short int)1;
                  imm_copy_data[1].dimensions = &imm_copy_dimensions[1];
                  imm_copy_data[1].offset = (((long int)&(*this).row - (long int)&*this) + (8L * (((bx) - (0L))))) + (8L * (((0L) - (0L))));
                  imm_copy_dimensions[2 + 0].size = (((i1 - i0) - (0L) - 0L) + 1L) * sizeof(::cell_t);
                  imm_copy_dimensions[2 + 0].lower_bound = (0L - 0L) * sizeof(::cell_t);
                  imm_copy_dimensions[2 + 0].accessed_length = (i1 - i0 - 0L - (0L - 0L) + 1) * sizeof(::cell_t);
                  imm_copy_data[2].sharing = ::NANOS_SHARED;
                  imm_copy_data[2].address = (void *)this;
                  imm_copy_data[2].flags.input = 1;
                  imm_copy_data[2].flags.output = 1;
                  imm_copy_data[2].dimension_count = (short int)1;
                  imm_copy_data[2].dimensions = &imm_copy_dimensions[2];
                  imm_copy_data[2].offset = (((long int)&(*this).col - (long int)&*this) + (8L * (((by) - (0L))))) + (8L * (((0L) - (0L))));
                  nanos_err = ::nanos_create_wd_and_run_compact(&nanos_wd_const_data.base, &nanos_wd_dyn_props, sizeof(::OmpSsAligner::nanos_args_0_t &), &imm_args, 3, &dependences[0], imm_copy_data, imm_copy_dimensions, (::nanos_translate_args_t)::OmpSsAligner::nanos_xlate_fun_OmpSsAlignercpp_0);
                  if (nanos_err != ::NANOS_OK)
                    {
                      ::nanos_handle_error(nanos_err);
                    }
                }
            }
          }
      }
    }
  else
    {
      (*this).AbstractBlockAligner::ignoreBlock(bx, by);
    }
  if (dispatchThisSpecialRows)
    {
      ::cell_t first_cell(((*this).::AbstractAligner::getFirstColumnTail()));
      first_cell.f =  -999999999;
      {
        bool mcc_is_in_final;
        ::nanos_err_t mcc_err_in_final(::nanos_in_final(&mcc_is_in_final));
        if (mcc_err_in_final != ::NANOS_OK)
          {
            ::nanos_handle_error(mcc_err_in_final);
          }
        if (mcc_is_in_final)
          {
            {
              if (!(*this).::AbstractAligner::mustContinue())
                {
                  return ;
                }
              if (bx == 0)
                {
                  (*this).::AbstractAligner::dispatchRow(i1, &first_cell, 1);
                }
              (*this).::AbstractAligner::dispatchRow(i1, (*this).row[bx], j1 - j0);
            }
          }
        else
          {
            {
              static ::nanos_smp_args_t smp_ol_alignBlock_1_args = { /* .::nanos_smp_args_t::outline =  */ (void (*)(void *))(void (*)(::OmpSsAligner::nanos_args_1_t &))::OmpSsAligner::smp_ol_alignBlock_1};
              static ::nanos_const_wd_definition_1 nanos_wd_const_data = { /* .::nanos_const_wd_definition_1::base =  */ { /* .::nanos_const_wd_definition_tag::props =  */ { /* .::nanos_wd_props_t::mandatory_creation =  */ 0,  /* .::nanos_wd_props_t::tied =  */ 0,  /* .::nanos_wd_props_t::clear_chunk =  */ 0,  /* .::nanos_wd_props_t::reserved0 =  */ 0,  /* .::nanos_wd_props_t::reserved1 =  */ 0,  /* .::nanos_wd_props_t::reserved2 =  */ 0,  /* .::nanos_wd_props_t::reserved3 =  */ 0,  /* .::nanos_wd_props_t::reserved4 =  */ 0},  /* .::nanos_const_wd_definition_tag::data_alignment =  */ __alignof__(::OmpSsAligner::nanos_args_1_t),  /* .::nanos_const_wd_definition_tag::num_copies =  */ 3,  /* .::nanos_const_wd_definition_tag::num_devices =  */ 1,  /* .::nanos_const_wd_definition_tag::num_dimensions =  */ 3,  /* .::nanos_const_wd_definition_tag::description =  */ 0},  /* .::nanos_const_wd_definition_1::devices =  */ { /* [0] =  */ { /* .::nanos_device_t::factory =  */ ::nanos_smp_factory,  /* .::nanos_device_t::arg =  */ &smp_ol_alignBlock_1_args}}};
              ::nanos_wd_dyn_props_t nanos_wd_dyn_props /* () */ ;
              nanos_wd_dyn_props.tie_to = 0;
              nanos_wd_dyn_props.priority = 0;
              nanos_wd_dyn_props.flags.is_final = 0;
              nanos_wd_dyn_props.flags.is_implicit = 0;
              nanos_wd_dyn_props.flags.is_recover = 0;
              ::OmpSsAligner::nanos_args_1_t *ol_args;
              ol_args = (::OmpSsAligner::nanos_args_1_t *)0;
              ::OmpSsAligner::nanos_args_1_t imm_args /* () */ ;
              ::nanos_wd_t nanos_wd_((::nanos_wd_t)0);
              ::nanos_copy_data_t *ol_copy_data((::nanos_copy_data_t *)0);
              ::nanos_region_dimension_internal_t *ol_copy_dimensions((::nanos_region_dimension_internal_t *)0);
              ::nanos_err_t nanos_err;
              nanos_err = ::nanos_create_wd_compact(&nanos_wd_, &nanos_wd_const_data.base, &nanos_wd_dyn_props, sizeof(::OmpSsAligner::nanos_args_1_t &), (void **)&ol_args, ::nanos_current_wd(), &ol_copy_data, &ol_copy_dimensions);
              if (nanos_err != ::NANOS_OK)
                {
                  ::nanos_handle_error(nanos_err);
                }
              ::nanos_region_dimension_t dimensions_3[1L];
              ::nanos_region_dimension_t dimensions_4[1L];
              ::nanos_region_dimension_t dimensions_5[1L];
              ::nanos_data_access_t dependences[3L];
              dimensions_3[0].size = 1L * sizeof(::cell_t *);
              dimensions_3[0].lower_bound = (bx - 0L) * sizeof(::cell_t *);
              dimensions_3[0].accessed_length = (bx - 0L - (bx - 0L) + 1) * sizeof(::cell_t *);
              dependences[0].address = (void *)(*this).renamedRow;
              dependences[0].offset = 8L * (((bx) - (0L)));
              dependences[0].dimensions = dimensions_3;
              dependences[0].flags.input = 1;
              dependences[0].flags.output = 0;
              dependences[0].flags.can_rename = 0;
              dependences[0].flags.concurrent = 0;
              dependences[0].flags.commutative = 0;
              dependences[0].dimension_count = 1;
              dimensions_4[0].size = 1L * sizeof(char);
              dimensions_4[0].lower_bound = (by - 0L) * sizeof(char);
              dimensions_4[0].accessed_length = (by - 0L - (by - 0L) + 1) * sizeof(char);
              dependences[1].address = (void *)(*this).rowChain;
              dependences[1].offset = 1L * (((by) - (0L)));
              dependences[1].dimensions = dimensions_4;
              dependences[1].flags.input = 1;
              dependences[1].flags.output = 1;
              dependences[1].flags.can_rename = 0;
              dependences[1].flags.concurrent = 0;
              dependences[1].flags.commutative = 0;
              dependences[1].dimension_count = 1;
              dimensions_5[0].size = 1 * sizeof(char);
              dimensions_5[0].lower_bound = 0 * sizeof(char);
              dimensions_5[0].accessed_length = (0 - 0 + 1) * sizeof(char);
              dependences[2].address = (void *)(*this).rowChain;
              dependences[2].offset = 0L;
              dependences[2].dimensions = dimensions_5;
              dependences[2].flags.input = 1;
              dependences[2].flags.output = 1;
              dependences[2].flags.can_rename = 0;
              dependences[2].flags.concurrent = 0;
              dependences[2].flags.commutative = 1;
              dependences[2].dimension_count = 1;
              if (nanos_wd_ != (::nanos_wd_t)0)
                {
                  (*ol_args).j0 = j0;
                  (*ol_args).j1 = j1;
                  (*ol_args).i1 = i1;
                  (*ol_args).first_cell = first_cell;
                  (*ol_args).bx = bx;
                  (*ol_args).by = by;
                  (*ol_args).this_ = this;
                  ol_copy_dimensions[0 + 0].size = 1L * sizeof(::cell_t *);
                  ol_copy_dimensions[0 + 0].lower_bound = (bx - 0L) * sizeof(::cell_t *);
                  ol_copy_dimensions[0 + 0].accessed_length = (bx - 0L - (bx - 0L) + 1) * sizeof(::cell_t *);
                  ol_copy_data[0].sharing = ::NANOS_SHARED;
                  ol_copy_data[0].address = (void *)this;
                  ol_copy_data[0].flags.input = 1;
                  ol_copy_data[0].flags.output = 0;
                  ol_copy_data[0].dimension_count = (short int)1;
                  ol_copy_data[0].dimensions = &ol_copy_dimensions[0];
                  ol_copy_data[0].offset = ((long int)&(*this).renamedRow - (long int)&*this) + (8L * (((bx) - (0L))));
                  ol_copy_dimensions[1 + 0].size = 1L * sizeof(char);
                  ol_copy_dimensions[1 + 0].lower_bound = (by - 0L) * sizeof(char);
                  ol_copy_dimensions[1 + 0].accessed_length = (by - 0L - (by - 0L) + 1) * sizeof(char);
                  ol_copy_data[1].sharing = ::NANOS_SHARED;
                  ol_copy_data[1].address = (void *)this;
                  ol_copy_data[1].flags.input = 1;
                  ol_copy_data[1].flags.output = 1;
                  ol_copy_data[1].dimension_count = (short int)1;
                  ol_copy_data[1].dimensions = &ol_copy_dimensions[1];
                  ol_copy_data[1].offset = ((long int)&(*this).rowChain - (long int)&*this) + (1L * (((by) - (0L))));
                  ol_copy_dimensions[2 + 0].size = 1 * sizeof(char);
                  ol_copy_dimensions[2 + 0].lower_bound = 0 * sizeof(char);
                  ol_copy_dimensions[2 + 0].accessed_length = (0 - 0 + 1) * sizeof(char);
                  ol_copy_data[2].sharing = ::NANOS_SHARED;
                  ol_copy_data[2].address = (void *)this;
                  ol_copy_data[2].flags.input = 1;
                  ol_copy_data[2].flags.output = 1;
                  ol_copy_data[2].dimension_count = (short int)1;
                  ol_copy_data[2].dimensions = &ol_copy_dimensions[2];
                  ol_copy_data[2].offset = 0L;
                  nanos_err = ::nanos_set_translate_function(nanos_wd_, (::nanos_translate_args_t)::OmpSsAligner::nanos_xlate_fun_OmpSsAlignercpp_1);
                  if (nanos_err != ::NANOS_OK)
                    {
                      ::nanos_handle_error(nanos_err);
                    }
                  nanos_err = ::nanos_submit(nanos_wd_, 3, &dependences[0], (::nanos_team_t)0);
                  if (nanos_err != ::NANOS_OK)
                    {
                      ::nanos_handle_error(nanos_err);
                    }
                }
              else
                {
                  imm_args.j0 = j0;
                  imm_args.j1 = j1;
                  imm_args.i1 = i1;
                  imm_args.first_cell = first_cell;
                  imm_args.bx = bx;
                  imm_args.by = by;
                  imm_args.this_ = this;
                  ::nanos_copy_data_t imm_copy_data[3L];
                  ::nanos_region_dimension_internal_t imm_copy_dimensions[3L];
                  imm_copy_dimensions[0 + 0].size = 1L * sizeof(::cell_t *);
                  imm_copy_dimensions[0 + 0].lower_bound = (bx - 0L) * sizeof(::cell_t *);
                  imm_copy_dimensions[0 + 0].accessed_length = (bx - 0L - (bx - 0L) + 1) * sizeof(::cell_t *);
                  imm_copy_data[0].sharing = ::NANOS_SHARED;
                  imm_copy_data[0].address = (void *)this;
                  imm_copy_data[0].flags.input = 1;
                  imm_copy_data[0].flags.output = 0;
                  imm_copy_data[0].dimension_count = (short int)1;
                  imm_copy_data[0].dimensions = &imm_copy_dimensions[0];
                  imm_copy_data[0].offset = ((long int)&(*this).renamedRow - (long int)&*this) + (8L * (((bx) - (0L))));
                  imm_copy_dimensions[1 + 0].size = 1L * sizeof(char);
                  imm_copy_dimensions[1 + 0].lower_bound = (by - 0L) * sizeof(char);
                  imm_copy_dimensions[1 + 0].accessed_length = (by - 0L - (by - 0L) + 1) * sizeof(char);
                  imm_copy_data[1].sharing = ::NANOS_SHARED;
                  imm_copy_data[1].address = (void *)this;
                  imm_copy_data[1].flags.input = 1;
                  imm_copy_data[1].flags.output = 1;
                  imm_copy_data[1].dimension_count = (short int)1;
                  imm_copy_data[1].dimensions = &imm_copy_dimensions[1];
                  imm_copy_data[1].offset = ((long int)&(*this).rowChain - (long int)&*this) + (1L * (((by) - (0L))));
                  imm_copy_dimensions[2 + 0].size = 1 * sizeof(char);
                  imm_copy_dimensions[2 + 0].lower_bound = 0 * sizeof(char);
                  imm_copy_dimensions[2 + 0].accessed_length = (0 - 0 + 1) * sizeof(char);
                  imm_copy_data[2].sharing = ::NANOS_SHARED;
                  imm_copy_data[2].address = (void *)this;
                  imm_copy_data[2].flags.input = 1;
                  imm_copy_data[2].flags.output = 1;
                  imm_copy_data[2].dimension_count = (short int)1;
                  imm_copy_data[2].dimensions = &imm_copy_dimensions[2];
                  imm_copy_data[2].offset = 0L;
                  nanos_err = ::nanos_create_wd_and_run_compact(&nanos_wd_const_data.base, &nanos_wd_dyn_props, sizeof(::OmpSsAligner::nanos_args_1_t &), &imm_args, 3, &dependences[0], imm_copy_data, imm_copy_dimensions, (::nanos_translate_args_t)::OmpSsAligner::nanos_xlate_fun_OmpSsAlignercpp_1);
                  if (nanos_err != ::NANOS_OK)
                    {
                      ::nanos_handle_error(nanos_err);
                    }
                }
            }
          }
      }
    }
  if ((*this).::AbstractBlockAligner::isSpecialColumn(bx))
    {
      if (by == 0)
        {
          ::cell_t first_cell(((*this).::AbstractAligner::getFirstRowTail()));
          first_cell.f =  -999999999;
          (*this).::AbstractAligner::dispatchColumn(j1, &first_cell, 1);
        }
      {
        bool mcc_is_in_final;
        ::nanos_err_t mcc_err_in_final(::nanos_in_final(&mcc_is_in_final));
        if (mcc_err_in_final != ::NANOS_OK)
          {
            ::nanos_handle_error(mcc_err_in_final);
          }
        if (mcc_is_in_final)
          {
            {
              (*this).::AbstractAligner::dispatchColumn(j1, (*this).col[by] + 1, i1 - i0);
            }
          }
        else
          {
            {
              static ::nanos_smp_args_t smp_ol_alignBlock_2_args = { /* .::nanos_smp_args_t::outline =  */ (void (*)(void *))(void (*)(::OmpSsAligner::nanos_args_2_t &))::OmpSsAligner::smp_ol_alignBlock_2};
              static ::nanos_const_wd_definition_1 nanos_wd_const_data = { /* .::nanos_const_wd_definition_1::base =  */ { /* .::nanos_const_wd_definition_tag::props =  */ { /* .::nanos_wd_props_t::mandatory_creation =  */ 0,  /* .::nanos_wd_props_t::tied =  */ 0,  /* .::nanos_wd_props_t::clear_chunk =  */ 0,  /* .::nanos_wd_props_t::reserved0 =  */ 0,  /* .::nanos_wd_props_t::reserved1 =  */ 0,  /* .::nanos_wd_props_t::reserved2 =  */ 0,  /* .::nanos_wd_props_t::reserved3 =  */ 0,  /* .::nanos_wd_props_t::reserved4 =  */ 0},  /* .::nanos_const_wd_definition_tag::data_alignment =  */ __alignof__(::OmpSsAligner::nanos_args_2_t),  /* .::nanos_const_wd_definition_tag::num_copies =  */ 2,  /* .::nanos_const_wd_definition_tag::num_devices =  */ 1,  /* .::nanos_const_wd_definition_tag::num_dimensions =  */ 2,  /* .::nanos_const_wd_definition_tag::description =  */ 0},  /* .::nanos_const_wd_definition_1::devices =  */ { /* [0] =  */ { /* .::nanos_device_t::factory =  */ ::nanos_smp_factory,  /* .::nanos_device_t::arg =  */ &smp_ol_alignBlock_2_args}}};
              ::nanos_wd_dyn_props_t nanos_wd_dyn_props /* () */ ;
              nanos_wd_dyn_props.tie_to = 0;
              nanos_wd_dyn_props.priority = 0;
              nanos_wd_dyn_props.flags.is_final = 0;
              nanos_wd_dyn_props.flags.is_implicit = 0;
              nanos_wd_dyn_props.flags.is_recover = 0;
              ::OmpSsAligner::nanos_args_2_t *ol_args;
              ol_args = (::OmpSsAligner::nanos_args_2_t *)0;
              ::OmpSsAligner::nanos_args_2_t imm_args /* () */ ;
              ::nanos_wd_t nanos_wd_((::nanos_wd_t)0);
              ::nanos_copy_data_t *ol_copy_data((::nanos_copy_data_t *)0);
              ::nanos_region_dimension_internal_t *ol_copy_dimensions((::nanos_region_dimension_internal_t *)0);
              ::nanos_err_t nanos_err;
              nanos_err = ::nanos_create_wd_compact(&nanos_wd_, &nanos_wd_const_data.base, &nanos_wd_dyn_props, sizeof(::OmpSsAligner::nanos_args_2_t &), (void **)&ol_args, ::nanos_current_wd(), &ol_copy_data, &ol_copy_dimensions);
              if (nanos_err != ::NANOS_OK)
                {
                  ::nanos_handle_error(nanos_err);
                }
              ::nanos_region_dimension_t dimensions_6[1L];
              ::nanos_region_dimension_t dimensions_7[1L];
              ::nanos_data_access_t dependences[2L];
              dimensions_6[0].size = (((i1 - i0) - (0L) - 0L) + 1L) * sizeof(::cell_t);
              dimensions_6[0].lower_bound = (0L - 0L) * sizeof(::cell_t);
              dimensions_6[0].accessed_length = (i1 - i0 - 0L - (0L - 0L) + 1) * sizeof(::cell_t);
              dependences[0].address = (void *)(*this).col[by];
              dependences[0].offset = 8L * (((0L) - (0L)));
              dependences[0].dimensions = dimensions_6;
              dependences[0].flags.input = 1;
              dependences[0].flags.output = 0;
              dependences[0].flags.can_rename = 0;
              dependences[0].flags.concurrent = 0;
              dependences[0].flags.commutative = 0;
              dependences[0].dimension_count = 1;
              dimensions_7[0].size = 1 * sizeof(char);
              dimensions_7[0].lower_bound = 0 * sizeof(char);
              dimensions_7[0].accessed_length = (0 - 0 + 1) * sizeof(char);
              dependences[1].address = (void *)&(*this).columnChain;
              dependences[1].offset = 0L;
              dependences[1].dimensions = dimensions_7;
              dependences[1].flags.input = 1;
              dependences[1].flags.output = 1;
              dependences[1].flags.can_rename = 0;
              dependences[1].flags.concurrent = 0;
              dependences[1].flags.commutative = 0;
              dependences[1].dimension_count = 1;
              if (nanos_wd_ != (::nanos_wd_t)0)
                {
                  (*ol_args).i0 = i0;
                  (*ol_args).i1 = i1;
                  (*ol_args).j1 = j1;
                  (*ol_args).by = by;
                  (*ol_args).this_ = this;
                  ol_copy_dimensions[0 + 0].size = (((i1 - i0) - (0L) - 0L) + 1L) * sizeof(::cell_t);
                  ol_copy_dimensions[0 + 0].lower_bound = (0L - 0L) * sizeof(::cell_t);
                  ol_copy_dimensions[0 + 0].accessed_length = (i1 - i0 - 0L - (0L - 0L) + 1) * sizeof(::cell_t);
                  ol_copy_data[0].sharing = ::NANOS_SHARED;
                  ol_copy_data[0].address = (void *)this;
                  ol_copy_data[0].flags.input = 1;
                  ol_copy_data[0].flags.output = 0;
                  ol_copy_data[0].dimension_count = (short int)1;
                  ol_copy_data[0].dimensions = &ol_copy_dimensions[0];
                  ol_copy_data[0].offset = (((long int)&(*this).col - (long int)&*this) + (8L * (((by) - (0L))))) + (8L * (((0L) - (0L))));
                  ol_copy_dimensions[1 + 0].size = 1 * sizeof(char);
                  ol_copy_dimensions[1 + 0].lower_bound = 0 * sizeof(char);
                  ol_copy_dimensions[1 + 0].accessed_length = (0 - 0 + 1) * sizeof(char);
                  ol_copy_data[1].sharing = ::NANOS_SHARED;
                  ol_copy_data[1].address = (void *)this;
                  ol_copy_data[1].flags.input = 1;
                  ol_copy_data[1].flags.output = 1;
                  ol_copy_data[1].dimension_count = (short int)1;
                  ol_copy_data[1].dimensions = &ol_copy_dimensions[1];
                  ol_copy_data[1].offset = (long int)&(*this).columnChain - (long int)&*this;
                  nanos_err = ::nanos_set_translate_function(nanos_wd_, (::nanos_translate_args_t)::OmpSsAligner::nanos_xlate_fun_OmpSsAlignercpp_2);
                  if (nanos_err != ::NANOS_OK)
                    {
                      ::nanos_handle_error(nanos_err);
                    }
                  nanos_err = ::nanos_submit(nanos_wd_, 2, &dependences[0], (::nanos_team_t)0);
                  if (nanos_err != ::NANOS_OK)
                    {
                      ::nanos_handle_error(nanos_err);
                    }
                }
              else
                {
                  imm_args.i0 = i0;
                  imm_args.i1 = i1;
                  imm_args.j1 = j1;
                  imm_args.by = by;
                  imm_args.this_ = this;
                  ::nanos_copy_data_t imm_copy_data[2L];
                  ::nanos_region_dimension_internal_t imm_copy_dimensions[2L];
                  imm_copy_dimensions[0 + 0].size = (((i1 - i0) - (0L) - 0L) + 1L) * sizeof(::cell_t);
                  imm_copy_dimensions[0 + 0].lower_bound = (0L - 0L) * sizeof(::cell_t);
                  imm_copy_dimensions[0 + 0].accessed_length = (i1 - i0 - 0L - (0L - 0L) + 1) * sizeof(::cell_t);
                  imm_copy_data[0].sharing = ::NANOS_SHARED;
                  imm_copy_data[0].address = (void *)this;
                  imm_copy_data[0].flags.input = 1;
                  imm_copy_data[0].flags.output = 0;
                  imm_copy_data[0].dimension_count = (short int)1;
                  imm_copy_data[0].dimensions = &imm_copy_dimensions[0];
                  imm_copy_data[0].offset = (((long int)&(*this).col - (long int)&*this) + (8L * (((by) - (0L))))) + (8L * (((0L) - (0L))));
                  imm_copy_dimensions[1 + 0].size = 1 * sizeof(char);
                  imm_copy_dimensions[1 + 0].lower_bound = 0 * sizeof(char);
                  imm_copy_dimensions[1 + 0].accessed_length = (0 - 0 + 1) * sizeof(char);
                  imm_copy_data[1].sharing = ::NANOS_SHARED;
                  imm_copy_data[1].address = (void *)this;
                  imm_copy_data[1].flags.input = 1;
                  imm_copy_data[1].flags.output = 1;
                  imm_copy_data[1].dimension_count = (short int)1;
                  imm_copy_data[1].dimensions = &imm_copy_dimensions[1];
                  imm_copy_data[1].offset = (long int)&(*this).columnChain - (long int)&*this;
                  nanos_err = ::nanos_create_wd_and_run_compact(&nanos_wd_const_data.base, &nanos_wd_dyn_props, sizeof(::OmpSsAligner::nanos_args_2_t &), &imm_args, 2, &dependences[0], imm_copy_data, imm_copy_dimensions, (::nanos_translate_args_t)::OmpSsAligner::nanos_xlate_fun_OmpSsAlignercpp_2);
                  if (nanos_err != ::NANOS_OK)
                    {
                      ::nanos_handle_error(nanos_err);
                    }
                }
            }
          }
      }
    }
}
__attribute__((common)) ::nanos_lock_t nanos_default_critical_lock /* ((::NANOS_LOCK_FREE)) */ ;
void OmpSsAligner::increaseBlockStat(const bool pruned)
{
  {
    ::nanos_err_t nanos_err;
    nanos_err = ::nanos_set_lock(&::nanos_default_critical_lock);
    if (nanos_err != ::NANOS_OK)
      {
        ::nanos_handle_error(nanos_err);
      }
    {
      (*this).AbstractBlockAligner::increaseBlockStat(pruned);
    }
    nanos_err = ::nanos_unset_lock(&::nanos_default_critical_lock);
    if (nanos_err != ::NANOS_OK)
      {
        ::nanos_handle_error(nanos_err);
      }
  }
}
void OmpSsAligner::printInitialStatistics(::FILE *file)
{
  (*this).AbstractBlockAligner::printInitialStatistics(file);
  ::fprintf(file, "Threads: %d\n", ::omp_get_max_threads());
}
void OmpSsAligner::allocateStructures()
{
  (*this).AbstractBlockAligner::allocateStructures();
  int grid_width((*(*this).getGrid()).::Grid::getGridWidth());
  int grid_height((*(*this).getGrid()).::Grid::getGridHeight());
  (*this).rowChain = new char [grid_height];
  (*this).renamedRow = new ::cell_t *[grid_width];
  for (int j(0); j < grid_width; j++)
    {
      int block_width((*(*this).getGrid()).::Grid::getBlockWidth(j, 0));
      (*this).renamedRow[j] = new ::cell_t [block_width];
    }
}
void OmpSsAligner::deallocateStructures()
{
  (*this).AbstractBlockAligner::deallocateStructures();
  int grid_width((*(*this).getGrid()).::Grid::getGridWidth());
  if ((*this).renamedRow != 0L)
    {
      for (int j(0); j < grid_width;  ++j)
        {
          delete[] (*this).renamedRow[j];
        }
      delete[] (*this).renamedRow;
      (*this).renamedRow = 0L;
    }
  if ((*this).rowChain != 0L)
    {
      delete[] (*this).rowChain;
      (*this).rowChain = 0L;
    }
}
void OmpSsAligner::smp_ol_alignBlock_0_unpacked(int bx, int by, int j0, int j1, int i0, int i1, int dispatchThisSpecialRows) throw()
{
  {
    {
      if (!(*this).::AbstractAligner::mustContinue())
        {
          return ;
        }
      (*this).AbstractBlockAligner::processBlock(bx, by, i0, j0, i1, j1);
      if (dispatchThisSpecialRows)
        {
          std::copy(&(*this).row[bx][0], &(*this).row[bx][j1 - j0], &(*this).renamedRow[bx][0]);
        }
    }
  }
}
void OmpSsAligner::smp_ol_alignBlock_0(::OmpSsAligner::nanos_args_0_t &args) throw()
{
  {
    (*args.this_).::OmpSsAligner::smp_ol_alignBlock_0_unpacked(args.bx, args.by, args.j0, args.j1, args.i0, args.i1, args.dispatchThisSpecialRows);
  }
}
void OmpSsAligner::smp_ol_alignBlock_1_unpacked(int j0, int j1, int i1, ::cell_t &first_cell, int bx, int by) throw()
{
  {
    {
      if (!(*this).::AbstractAligner::mustContinue())
        {
          return ;
        }
      if (bx == 0)
        {
          (*this).::AbstractAligner::dispatchRow(i1, &first_cell, 1);
        }
      (*this).::AbstractAligner::dispatchRow(i1, (*this).row[bx], j1 - j0);
    }
  }
}
void OmpSsAligner::smp_ol_alignBlock_1(::OmpSsAligner::nanos_args_1_t &args) throw()
{
  {
    (*args.this_).::OmpSsAligner::smp_ol_alignBlock_1_unpacked(args.j0, args.j1, args.i1, args.first_cell, args.bx, args.by);
  }
}
void OmpSsAligner::smp_ol_alignBlock_2_unpacked(int i0, int i1, int j1, int by) throw()
{
  {
    {
      (*this).::AbstractAligner::dispatchColumn(j1, (*this).col[by] + 1, i1 - i0);
    }
  }
}
void OmpSsAligner::smp_ol_alignBlock_2(::OmpSsAligner::nanos_args_2_t &args) throw()
{
  {
    (*args.this_).::OmpSsAligner::smp_ol_alignBlock_2_unpacked(args.i0, args.i1, args.j1, args.by);
  }
}
extern "C"
{
  __attribute__((weak)) void nanos_needs_priorities_fun()
  {
  }
}
