
undefined4 FUN_005a4bf1(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int local_c [2];
  
  FUN_005a509f(local_c,param_1);
  if (local_c[0] == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(local_c[0] + 0x10);
    *param_2 = uVar1;
    uVar1 = CONCAT31((int3)((uint)uVar1 >> 8),1);
  }
  return uVar1;
}

