bool next_array(vector<int> &A, int limit) {
  A.back()++;
  for (int i = size(A)-1; i >= 0; i--) {
    if (A[i] > limit) {
      A[i] = 0;
      if (i-1 >= 0) A[i-1]++;
      else {
        return false;
      }
    }
  }
  return true;
}
