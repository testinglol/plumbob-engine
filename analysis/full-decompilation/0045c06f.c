
uint FUN_0045c06f(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (*(int *)(param_1 + 8) != 0) {
    uVar1 = FUN_0045741b();
    if (uVar1 == 0x7c4) {
      return CONCAT31(7,*(int *)(param_1 + 0x10) == 3);
    }
  }
  return uVar1 & 0xffffff00;
}

