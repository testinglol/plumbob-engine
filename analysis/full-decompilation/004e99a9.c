
undefined4 FUN_004e99a9(void)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(*DAT_006e486c + 0x14) != 0) {
    iVar1 = FUN_00445724();
    if (iVar1 != 0) {
      uVar2 = FUN_0045741b();
      uVar2 = FUN_004e988f(uVar2);
      return uVar2;
    }
  }
  return 0xffffffff;
}

