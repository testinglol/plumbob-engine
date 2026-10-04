
uint FUN_0049bee2(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = __ftol();
  if ((int)uVar1 < 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = 0xff;
    if ((int)uVar1 < 0x100) {
      uVar3 = uVar1;
    }
  }
  iVar2 = uVar3 + 0x30;
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  else if (0xff < iVar2) {
    iVar2 = 0xff;
  }
  return (iVar2 << 8 | uVar3) << 8 | uVar3;
}

