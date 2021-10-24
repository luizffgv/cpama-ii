# Chapter 11 Exercises

1. (a) and (g)

2. (e), (f) and (i)

3. ```c
   void avg_sum(double a[], int n, double *avg, double *sum)
   {
       int i;

       *sum = 0.0;
       for (i = 0; i < n; i++)
           *sum += a[i];
       *avg = *sum / n;

   }
   ```

4. ```c
   void swap(int *p, int *q)
   {
       int temp = *p;
       *p = *q;
       *q = temp;
   }
   ```

5. ```c
   void split_time(long total_sec, int *hr, int *min, int *sec)
   {
       *hr = total_sec / 3600;
       total_sec %= 3600;
       *min = total_sec / 60;
       *sec = total_sec % 60;
   }
   ```

6. ```c
   void find_two_largest(int a[], int n, int *largest, int *second_largest)
   {
       *largest = *second_largest = a[0];
       for (int i = 1; i < n; i++)
           if (a[i] > *largest)
           {
               *second_largest = *largest;
               *largest = a[i];
           }
   }
   ```

7. ```c
   void split_date(int day_of_year, int year, int *month, int *day)
   {
       int days_of_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
       
       if (!(year % 4) && (year % 100 || !(year % 400))) ++days_of_month[1];

       for (*month = 0; day_of_year > 0; (*month)++)
           day_of_year -= days_of_month[*month];
       *day = day_of_year + days_of_month[*month - 1];
   }
   ```

8. ```c
   int *find_largest(int a[], int n)
   {
       int *largest = &a[0];
   
       for (int i = 1; i < n;  i++)
           if (a[i] > *largest)
               largest = &a[i];
       
       return largest;
   }
   ```
