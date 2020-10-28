#include "deps.h"

struct timeval start_time, end_time;
int number_of_threads, number_range;
int prime_count = 0;


int main(int argc, char *argv[]) {
  printf("Peter Krause's \033[1;31mOpenMP PrimeFinder\033[0m V1\n");

  if (argc > 2) {
    number_range = atoi(argv[1]);
    number_of_threads = atoi(argv[2]);
  } else {
    number_range = 1000000;
    number_of_threads = 5;
  }
  printf("\nSearching numbers from 0 to \033[1;36m%d\033[0m using \033[1;32m%d\033[0m threads\n", number_range, number_of_threads);
  int chunk_size = number_range / number_of_threads;

  gettimeofday(&start_time, NULL);
  #pragma omp parallel for
  for (int thread_number=0; thread_number<number_of_threads; thread_number++) {

    int chunk_offset = thread_number * chunk_size;
    int start_limit = 1 + chunk_offset;
    int end_limit = chunk_size + chunk_offset;

    if (thread_number == 0) {
      start_limit -= 1;
    }

    for (int i=start_limit; i<end_limit; i++) {
      int prime_if_zero = 0;

      for (int k = 2; k <= i / 2; ++k) {
          if (i % k == 0) {
              prime_if_zero = 1;
              break;
          }
      }
      if (prime_if_zero == 0) {
        prime_count += 1;
      }

    }
    printf(
      "Thread nº\033[1;32m%d\033[0m finished search between \033[1;36m[\033[0m%d\033[1;36m,\033[0m %d\033[1;36m]\033[0m\n",
      omp_get_thread_num(),
      start_limit,
      end_limit
    );
  }

  gettimeofday(&end_time, NULL);
  double seconds_spent = end_time.tv_sec - start_time.tv_sec;
  double milliseconds_spent =  (end_time.tv_usec - start_time.tv_usec)/1000000.0;
  double time_spent = seconds_spent + milliseconds_spent;
  printf("Time spent searching for primes: %f\n", time_spent);
  return 0;
}
