typedef struct plthook plthook_t;

int plthook_open(plthook_t **plthook_out, const char *filename);
int plthook_open_by_handle(plthook_t **plthook_out, void *handle);
int plthook_open_by_address(plthook_t **plthook_out, void *address);
int plthook_enum(plthook_t *plthook, unsigned int *pos, const char **name_out, void ***addr_out);
int plthook_replace(plthook_t *plthook, const char *funcname, void *funcaddr, void **oldfunc);
void plthook_close(plthook_t *plthook);
const char *plthook_error(void);
