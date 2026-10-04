
int * FUN_005a1f21(void)

{
  undefined4 uVar1;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(int **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005b8680();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b8680();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b8680();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005d499c(*(undefined4 *)(unaff_EBP + 8));
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  extraout_ECX[0xc] = 0;
  extraout_ECX[10] = 0;
  *(undefined1 *)(extraout_ECX + 0xb) = 0;
  *extraout_ECX = extraout_ECX[2] - extraout_ECX[1];
  *unaff_FS_OFFSET = uVar1;
  return extraout_ECX;
}

