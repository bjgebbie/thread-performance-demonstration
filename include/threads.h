#include <pthread.h>

/**
 * thread_ids: Array of pthread_t ids to be populated by the function.
 */
void create_threads(pthread_t *thread_ids, void *thread_function,
					void *thread_function_arg);

/**
 * thread_ids: Array of pthread_t ids to be joined by the function.
 */
void join_threads(pthread_t *thread_ids, void **ret_vals);
