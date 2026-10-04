
uint FUN_004eac16(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  
  if (DAT_006f2630 != 0) {
    cVar1 = FUN_004eab60(param_1);
    if (cVar1 != '\0') {
      uVar2 = FUN_0040cf46();
      return uVar2;
    }
  }
  iVar3 = FUN_004ea79e(param_1);
  if ((*(ushort *)(iVar3 + 0x82) & 2) != 0) {
    return 1;
  }
  return ((int)(char)*(ushort *)(iVar3 + 0x82) & 4U) >> 1;
}

