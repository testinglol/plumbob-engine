
uint FUN_0057a965(void)

{
  int iVar1;
  uint unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  
  iVar1 = *(int *)(unaff_ESI + 0xc);
  *(uint *)(unaff_EBP + -4) = unaff_EBX;
  (**(code **)(**(int **)(iVar1 + 0x10) + 8))();
  if (*(char *)(unaff_EBP + 0xb) == (char)unaff_EBX) {
    InterlockedDecrement(&DAT_006f29fc);
  }
  else {
    unaff_EBX = 1;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return unaff_EBX & 0xff;
}

