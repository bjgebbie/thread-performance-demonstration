#include <pthread.h>

void *thread_function(void *arg);
pthread_t *create_threads(pthread_t *thread_ids);
void join_threads(pthread_t *thread_ids);
