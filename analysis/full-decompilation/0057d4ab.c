
bool FUN_0057d4ab(undefined4 param_1,undefined4 *param_2)

{
  int local_c [2];
  
  FUN_005a509f(local_c,param_1);
  if (local_c[0] == 0) {
    *param_2 = 0;
  }
  else {
    *param_2 = *(undefined4 *)(local_c[0] + 0x10);
  }
  return local_c[0] != 0;
}

