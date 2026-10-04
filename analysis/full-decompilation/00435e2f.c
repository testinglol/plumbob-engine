
int * FUN_00435e2f(void)

{
  int iVar1;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar1 = *(int *)(unaff_EBP + 8);
  *(int **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = iVar1;
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(iVar1 + 0x11c);
  }
  extraout_ECX[1] = iVar1;
  FUN_005b8680();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b8680();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b8680();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005b8680();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005b8680();
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_005b8680();
  *(undefined1 *)(unaff_EBP + -4) = 5;
  extraout_ECX[0x14] = 0;
  FUN_005a5dea(0);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined1 *)(extraout_ECX + 0x1a) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x69) = 1;
  *(undefined2 *)((int)extraout_ECX + 0x6a) = 0;
  *(undefined1 *)(extraout_ECX + 0x1b) = 0;
  extraout_ECX[0x1c] = 0;
  extraout_ECX[0x1d] = 0;
  return extraout_ECX;
}

