
int * FUN_005a234f(void)

{
  undefined4 uVar1;
  int iVar2;
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
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  extraout_ECX[0xc] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005d499c(uVar1);
  uVar1 = *(undefined4 *)(unaff_EBP + 0xc);
  *extraout_ECX = extraout_ECX[2] - extraout_ECX[1];
  FUN_005d499c(uVar1);
  FUN_005d499c(*(undefined4 *)(unaff_EBP + 0x10));
  iVar2 = *(int *)(unaff_EBP + 0x14);
  *(undefined1 *)(extraout_ECX + 0xb) = 0;
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  extraout_ECX[10] = iVar2;
  *unaff_FS_OFFSET = uVar1;
  return extraout_ECX;
}

