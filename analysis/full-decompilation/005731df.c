
uint FUN_005731df(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0x20000;
  do {
    iVar1 = FUN_0057d4e4(uVar2);
    if (iVar1 == 0) {
      return uVar2;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x2fffff);
  return 0;
}

