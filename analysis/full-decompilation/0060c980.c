
int FUN_0060c980(void)

{
  undefined **ppuVar1;
  int iVar2;
  undefined **ppuVar3;
  
  iVar2 = 0;
  if (PTR_LAB_006d9e10 != (undefined *)0x0) {
    ppuVar3 = &PTR_LAB_006d9e10;
    do {
      ppuVar1 = ppuVar3 + 5;
      ppuVar3 = ppuVar3 + 5;
      iVar2 = iVar2 + 1;
    } while (*ppuVar1 != (undefined *)0x0);
  }
  return iVar2;
}

