
int FUN_0046d888(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = __ftol();
  iVar2 = iVar1;
  if (iVar1 >= 0x5b) {
    iVar2 = 0x5a;
  }
  if (SBORROW4(iVar2,0x5a) != (iVar1 < 0x5b && iVar1 + -0x5a < 0)) {
    iVar2 = 0x5a;
  }
  return iVar2;
}

