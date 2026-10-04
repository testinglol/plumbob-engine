
void FUN_005a047e(uint param_1)

{
  int local_c [2];
  
  if (DAT_006f75e0 + DAT_006f75dc < param_1) {
    DAT_006f75dc = param_1;
    FUN_00580a92(local_c);
    while (local_c[0] != 0) {
      if (*(int *)(local_c[0] + 0x2c) != 0) {
        FUN_005a3805(param_1);
      }
      FUN_0040fe8a();
    }
  }
  return;
}

