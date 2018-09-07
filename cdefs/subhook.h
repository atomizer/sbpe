// for cffi
struct subhook_struct;
typedef struct subhook_struct *subhook_t;

subhook_t subhook_new(void *src, void *dst, int options);
void subhook_free(subhook_t hook);

void *subhook_get_trampoline(subhook_t hook);

int subhook_install(subhook_t hook);
int subhook_is_installed(subhook_t hook);
int subhook_remove(subhook_t hook);
