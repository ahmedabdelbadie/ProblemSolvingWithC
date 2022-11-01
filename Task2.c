#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>


//function for Circle Inside Square

double pi_dart_CIS(long long n){                   //n indicates the number of throws
    double x, y,z, pi,cpu_sec,cpu_millisec;
    long long i, h = 0;                            //h indicates the number of hits
    clock_t start = clock();
    for(i = 0; i < n; i++){

    //generating random numbers x and y

    x = (double)rand() / RAND_MAX;
            y = (double)rand() / RAND_MAX;

            z = x * x + y * y;

            if(z <= 1){
                h++;
            }
    }
    pi = (long double)4 * h / n;
    clock_t end = clock();
    cpu_sec=(double)(end - start) / CLOCKS_PER_SEC;     //calculating cpu time
    cpu_millisec=cpu_sec*1000;
    printf("CPU Time for CIS is : %f milliseconds\n",cpu_millisec);
    return pi;
}

//function for Square Inside Circle

double pi_dart_SIC(long long n){                     //n indicates the number of throws
    double x, y, z, pi,cpu_sec,cpu_millisec;
    long long i, h = 0,t=0;                         //h indicates the number of hits
                                                    //t indicates the number of throws landing inside circle
    clock_t start = clock();
    while(t<=n)
    {

        //generating random numbers x and y

        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;
        z = x * x + y * y;

        if(z <= 1){
            t++;
        }
        if(x<=1/sqrt(2) && y<=1/sqrt(2))
        {
            h++;
        }
    }
    pi = (long double)2 * (long double)n / (long double)h;
    clock_t end = clock();
    cpu_sec=(double)(end - start) / CLOCKS_PER_SEC;                    //calculating cpu time
    cpu_millisec=cpu_sec*1000;
    printf("CPU Time for SIC is : %f milliseconds\n",cpu_millisec);
    return pi;
}

//function for Integral

double pi_dart_integral(long long n){                              //n is the number of sub-intervals
    double sum=0;
    double x, y,cpu_sec,cpu_millisec,y1, z=1/(double) n, a,pi;
    long long i;
    clock_t start = clock();

    for(i = 0; i <=n-1; i++){
        x=(i-0.5)*z;
        a=1/(1+x*x);
        sum=sum+a;

    }
    pi = (long double)4*(long double)sum* (long double)z;
    clock_t end = clock();
    cpu_sec=(double)(end - start) / CLOCKS_PER_SEC;                      //calculating cpu time
    cpu_millisec=cpu_sec*1000;
    printf("CPU Time for Integral is : %f milliseconds\n",cpu_millisec);

    return pi;
}

int main(int argc, char** argv) {
    omp_set_dynamic(0);     // Explicitly disable dynamic teams
    omp_set_num_threads(12); // Use 4 threads for all consecutive parallel regions
    long N;
    double pi_CIS,pi_SIC,pi_integral;
    int i;
    scanf("%ld", &N);
    srand(time(NULL));
    int thread_id;

    int threadCount = 4;
    //sequential Pi CIS
    printf("sequential Pi CIS\n");
    pi_CIS = pi_dart_CIS(N);
    printf("The pi value for CIS for run %d is : %.10f\n", i,pi_CIS);
    threadCount = 12;
    //parallel Pi CIS (Vary number of threads = 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12)
     printf("parallel Pi CIS (Vary number of threads = 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12)\n");
    #pragma omp parallel num_threads(threadCount) shared(N) private(thread_id)
    {
        #pragma omp barrier
        thread_id = omp_get_thread_num();
        printf("Hello from process: %d\n", thread_id);
        {
            pi_CIS = pi_dart_CIS(N);
            printf("The pi value for CIS for run %d is : %.10f\n", i,pi_CIS);
        }
    }
    //sequential Pi SIC
    printf("sequential Pi SIC\n");
    pi_SIC = pi_dart_SIC(N);
    printf("The pi value for SIC for run %d is : %.10f\n", i,pi_SIC);
    threadCount = 12;
    //parallel Pi SIC (Vary number of threads = 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12)
     printf("parallel Pi SIC (Vary number of threads = 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12)\n");
    #pragma omp parallel num_threads(threadCount) shared(N) private(thread_id)
    {
        #pragma omp barrier
        thread_id = omp_get_thread_num();
        printf("Hello from process: %d\n", thread_id);
        {
            pi_SIC = pi_dart_SIC(N);
            printf("The pi value for SIC for run %d is : %.10f\n", i,pi_SIC);
        }
    }
    //sequential Pi Integral
    printf("sequential Pi Integral\n");
    pi_integral = pi_dart_integral(N);
    printf("The pi value for Integral for run %d is : %.10f\n",i,pi_integral);
    threadCount = 12;
    //parallel Pi Integral (Vary number of threads = 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12)
     printf("parallel Pi Integral (Vary number of threads = 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12)\n");
    #pragma omp parallel num_threads(threadCount) shared(N) private(thread_id)
    {
        #pragma omp barrier
        thread_id = omp_get_thread_num();
        printf("Hello from process: %d\n", thread_id);
         {
            pi_integral = pi_dart_integral(N);
            printf("The pi value for Integral for run %d is : %.10f\n",i,pi_integral);
         }
    }
    return 0;
}
