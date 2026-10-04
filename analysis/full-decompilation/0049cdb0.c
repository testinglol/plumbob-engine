
uint FUN_0049cdb0(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = __ftol();
  uVar2 = __ftol();
  uVar3 = __ftol();
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  if (0xff < iVar1) {
    iVar1 = 0xff;
  }
  if ((int)uVar2 < 0) {
    uVar2 = 0;
  }
  if (0xff < (int)uVar2) {
    uVar2 = 0xff;
  }
  if ((int)uVar3 < 0) {
    uVar3 = 0;
  }
  if (0xff < (int)uVar3) {
    uVar3 = 0xff;
  }
  return (iVar1 << 8 | uVar2) << 8 | uVar3;
}

