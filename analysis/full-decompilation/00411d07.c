
undefined4 FUN_00411d07(undefined4 param_1)

{
  int *piVar1;
  undefined **local_40 [3];
  undefined1 local_34 [32];
  int *local_14;
  undefined4 local_10;
  int *local_c;
  undefined4 local_8;
  
  FUN_0046f824(local_34,0,0x20);
  local_40[0] = &PTR_FUN_006666dc;
  FUN_00411bde(param_1,local_40);
  FUN_00411d77(&local_c,local_40);
  if (local_c != (int *)0x0) {
    piVar1 = local_c + 0xc;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      local_14 = local_c;
      local_10 = local_8;
      FUN_00411e6e(&local_14);
      return 1;
    }
  }
  return 0;
}

