
undefined4 FUN_0041bd6b(undefined4 param_1)

{
  undefined4 uVar1;
  int local_c [2];
  
  uVar1 = 0;
  FUN_00575b11(local_c,&param_1);
  if (local_c[0] != 0) {
    uVar1 = *(undefined4 *)(local_c[0] + 0x18);
  }
  return uVar1;
}

