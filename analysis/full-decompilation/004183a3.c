
undefined4 FUN_004183a3(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 local_18 [4];
  int local_14;
  byte local_e;
  void *local_8;
  
  local_8 = operator_new(0xc800);
  if (local_8 == (void *)0x0) {
    uVar1 = 0xffffff38;
  }
  else {
    iVar3 = 0;
    iVar4 = 0x40;
    while( true ) {
      iVar2 = FUN_004181b3(local_18,iVar4);
      if (iVar2 != 0) break;
      if ((local_e & 4) == 0) {
        FUN_0041a615(iVar4,iVar3,local_14,local_8);
      }
      else {
        iVar3 = iVar3 + local_14;
      }
      iVar4 = iVar4 + local_14;
    }
    FUN_006321f0(local_8);
    FUN_00412fe1(iVar4 - iVar3);
    uVar1 = 0;
  }
  return uVar1;
}

