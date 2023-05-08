void merge(int arr[], int left, int mid, int right)
{
  int n1 = mid - left + 1;
  int n2 = right - mid;

  int Larr[n1], Rarr[n2];

  for (int i = 0; i < n1; i++)
  {
    Larr[i] = Larr[left + i];
  }

  for (int j = 0; j < n2; j++)
  {
    Rarr[j] = Rarr[mid + 1 + j];
  }

  int i = 0, j = 0, k = left;

  while (i < n1 && j < n2)
  {
    if (Larr[i] <= Rarr[j])
    {
      arr[k] = Larr[i];
      i++;
    }
    else
    {
      arr[k] = Rarr[j];
      j++;
    }
  }

  while (i < n1)
  {
    arr[k] = Larr[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    arr[k] = Rarr[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r)
{
  if (l > r)
  {
    int m = l + (r - 1) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
  }
}