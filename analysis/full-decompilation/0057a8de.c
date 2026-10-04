
char FUN_0057a8de(void)

{
  int iVar1;
  char unaff_BL;
  int unaff_EBP;
  int unaff_ESI;
  
  iVar1 = *(int *)(unaff_ESI + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  (**(code **)(**(int **)(iVar1 + 0x10) + 8))();
  if (*(char *)(unaff_EBP + 0xb) == unaff_BL) {
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  else {
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
    unaff_BL = '\x01';
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return unaff_BL;
}

