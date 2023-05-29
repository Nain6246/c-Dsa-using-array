#include <iostream>
using namespace std;
int N, n = 0;

int *size_double(int *&arr)
{
   int temp = N * 2;
   int *new_arr = new int[temp];
   for (int i = 0; i < N; i++)
   {
      new_arr[i] = arr[i];
   }
   delete[] arr;
   arr = new_arr;
   return new_arr;
}
void insert_at_start(int *&arr, int value)
{
   if (n == N)
   {
      size_double(*&arr);
   }
   for (int i = n; i >= 1; i--)
   {
      arr[i] = arr[i - 1];
   }
   arr[0] = value;
   n++;
}
void insert_at_middle(int *&arr, int position, int value)
{
   if (n == N)
   {
      size_double(*&arr);
   }
   for (int i = n; i > position; i--)
   {
      arr[i] = arr[i - 1];
   }
   arr[position] = value;
   n++;
}
void insert_at_end(int *&arr, int value)
{
   if (n == N)
   {
      size_double(*&arr);
   }
   arr[n] = value;
   n++;
}
void delete_at_start(int *&arr)
{
   if (n == 0)
   {
      cout << "Array is empty, cannot delete element at the beginning" << endl;
   }
   else
   {
      for (int i = 0; i < n - 1; i++)
      {
         arr[i] = arr[i + 1];
      }
      n--;
   }
}
void delete_at_middle(int *&arr, int position)
{
   if (n == 0)
   {
      cout << "Array is empty, cannot delete element at the middle" << endl;
   }
   else
   {
      for (int i = position; i < n - 1; i++)
      {
         arr[i] = arr[i + 1];
      }

      n--;
   }
}
void delete_at_end(int *&arr)
{
   if (n == 0)
   {
      cout << "Array is empty, cannot delete element at the end" << endl;
      return;
   }
   arr[n] = 0;
   n--;
}
int search(int *&arr, int value)
{
   for (int i = 0; i < n; i++)
   {
      if (arr[i] == value)
      {
         cout << "value at index no :" << i << endl;
         return i;
      }
   }
   cout << "Value are not found in the array :" << endl;
}
void display(int *&arr)
{
   cout << " data is :";
   for (int i = 0; i < n; i++)
   {
      cout << arr[i] << "  ";
   }
}

int main()
{

   int N = 3;
   int *arr = new int[N];
   fill_n(arr, N, 0);
   insert_at_end(arr, 6);
   insert_at_start(arr, 5);
   insert_at_start(arr, 4);
   insert_at_end(arr, 9);
   insert_at_middle(arr, 2, 7);
   delete_at_middle(arr, 2);
   display(arr);
   search(arr, 5);
}
