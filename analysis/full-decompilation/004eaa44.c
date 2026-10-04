
uint FUN_004eaa44(int param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  
  if ((-1 < param_1) && (param_1 < (DAT_006f264c - DAT_006f2648) / 0x44)) {
    if (DAT_006f2630 != 0) {
      cVar1 = FUN_005a5e72();
      if (cVar1 != '\0') {
        uVar2 = FUN_0040cc3f();
        return uVar2;
      }
    }
    iVar3 = FUN_004ea79e(param_1);
    return (uint)(*(short *)(iVar3 + 0x74) < 0x12);
  }
  return 0;
}

