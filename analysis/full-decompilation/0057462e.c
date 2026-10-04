
void FUN_0057462e(int param_1)

{
  undefined4 uVar1;
  int local_1c [2];
  int local_14 [2];
  int local_c [2];
  
  FUN_00580a92(local_c);
  while (local_c[0] != 0) {
    if (*(int *)(local_c[0] + 8) == param_1) {
      uVar1 = *(undefined4 *)(local_c[0] + 4);
      FUN_0057644e(local_14);
      FUN_005747dc(uVar1);
      FUN_00580a92(local_1c);
      local_c[0] = local_1c[0];
    }
    else {
      FUN_00576e56();
    }
  }
  return;
}

