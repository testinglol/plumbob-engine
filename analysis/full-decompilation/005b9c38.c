
undefined4 FUN_005b9c38(undefined4 param_1,undefined4 param_2,int *param_3)

{
  int local_14 [2];
  int local_c [2];
  
  FUN_005a509f(local_c,param_1);
  if ((local_c[0] != 0) && (FUN_005a509f(local_14,param_2), local_14[0] != 0)) {
    if (param_3 != (int *)0x0) {
      *param_3 = local_14[0] + 0x10;
    }
    return 1;
  }
  return 0;
}

