
int FUN_0048e661(void)

{
  int iVar1;
  undefined4 uVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar1 = *(int *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005b86bd(iVar1);
  uVar2 = *(undefined4 *)(iVar1 + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(extraout_ECX + 0xc) = uVar2;
  *(undefined4 *)(extraout_ECX + 0x10) = *(undefined4 *)(iVar1 + 0x10);
  *(undefined1 *)(extraout_ECX + 0x14) = *(undefined1 *)(iVar1 + 0x14);
  FUN_0048e6ef(iVar1 + 0x18);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined4 *)(extraout_ECX + 0x24) = *(undefined4 *)(iVar1 + 0x24);
  return extraout_ECX;
}

