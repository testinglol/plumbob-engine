
undefined4 FUN_004e6141(void)

{
  int iVar1;
  undefined4 uStack_4;
  
  if (*(int *)(DAT_006e486c + 0x20) != 0) {
    iVar1 = FUN_004c4472();
    if (iVar1 != 0) {
      if (iVar1 == 1) {
        uStack_4 = 1;
      }
      else {
        uStack_4 = 2;
      }
      return uStack_4;
    }
  }
  return 0;
}

