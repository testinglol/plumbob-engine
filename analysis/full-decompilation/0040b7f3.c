
int FUN_0040b7f3(void)

{
  int iVar1;
  undefined4 uVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar1 = *(int *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_0040f567(iVar1);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b86bd(iVar1 + 0xc);
  *(undefined4 *)(extraout_ECX + 0x18) = *(undefined4 *)(iVar1 + 0x18);
  uVar2 = *(undefined4 *)(iVar1 + 0x1c);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  *(undefined4 *)(extraout_ECX + 0x1c) = uVar2;
  FUN_0040f5c8(iVar1 + 0x20);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

