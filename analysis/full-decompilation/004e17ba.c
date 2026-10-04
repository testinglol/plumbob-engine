
int FUN_004e17ba(void)

{
  int iVar1;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar1 = *(int *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005b86bd(iVar1);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b86bd(iVar1 + 0xc);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined4 *)(extraout_ECX + 0x18) = *(undefined4 *)(iVar1 + 0x18);
  *(undefined4 *)(extraout_ECX + 0x1c) = *(undefined4 *)(iVar1 + 0x1c);
  return extraout_ECX;
}

