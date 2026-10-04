
undefined4 * FUN_004b388e(void)

{
  int iVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = 0;
  extraout_ECX[1] = 0;
  extraout_ECX[2] = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004b3f82(0x400);
  iVar1 = *(int *)(unaff_EBP + 8);
  FUN_004b4251(iVar1);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined1 *)(extraout_ECX + 3) = *(undefined1 *)(iVar1 + 0xc);
  extraout_ECX[4] = *(undefined4 *)(iVar1 + 0x10);
  *(undefined1 *)(extraout_ECX + 5) = 0;
  return extraout_ECX;
}

