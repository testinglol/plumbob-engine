
undefined4 FUN_0041b869(int param_1,int param_2)

{
  int local_14 [2];
  int local_c [2];
  
  if (-1 < param_2) {
    FUN_00580a92(local_c);
    while (local_c[0] != 0) {
      FUN_00580a92(local_14);
      while (local_14[0] != 0) {
        if (*(int *)(local_14[0] + 0x13) == param_1) {
          *(int *)(local_14[0] + 0x13) = *(int *)(local_14[0] + 0x13) - param_2;
          return 1;
        }
        FUN_0041ddb4();
      }
      FUN_00576e56();
    }
  }
  return 0;
}

