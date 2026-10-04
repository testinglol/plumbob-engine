
void FUN_00473729(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  uVar1 = *(undefined4 *)(extraout_ECX + 0xc);
  uVar2 = *(undefined4 *)(extraout_ECX + 8);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_00473a46(uVar2,uVar1);
  FUN_0052ea87(*(undefined4 *)(extraout_ECX + 0x14),*(undefined4 *)(extraout_ECX + 0x18));
  uVar1 = *(undefined4 *)(extraout_ECX + 0x14);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  FUN_0048c4c9();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004739fe();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

