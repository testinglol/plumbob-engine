
uint FUN_004eabb1(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  
  if (DAT_006f2630 != 0) {
    cVar1 = FUN_004eab60(param_1);
    if (cVar1 != '\0') {
      uVar2 = FUN_0040cd0e();
      return uVar2;
    }
  }
  iVar3 = FUN_004ea79e(param_1);
  if ((*(byte *)(iVar3 + 0x82) & 1) == 0) {
    return 0;
  }
  return (uint)((*(byte *)(iVar3 + 0x82) & 1) == 1);
}

