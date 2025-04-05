#include <pthread.h>

// TODO: flesh out this function a little more
void *thread_function(void *arg);

/**
 * thread_ids: Array of pthread_t ids to be populated by the function.
 */
void create_threads(pthread_t *thread_ids);

/**
 * thread_ids: Array of pthread_t ids to be joined by the function.
 */
void join_threads(pthread_t *thread_ids);
