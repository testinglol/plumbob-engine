
int FUN_004b9c72(void)

{
  int iVar1;
  uint3 uVar2;
  
  iVar1 = *(int *)(DAT_006e486c + 0x34);
  uVar2 = (uint3)((uint)iVar1 >> 8);
  if (iVar1 == 1) {
    DAT_006f0674 = FUN_004b9ca0;
  }
  else {
    if (iVar1 != 2) {
      return (uint)uVar2 << 8;
    }
    DAT_006f0674 = FUN_004b9f3e;
  }
  return CONCAT31(uVar2,1);
}

