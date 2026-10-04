
void FUN_005d1468(void)

{
  int iVar1;
  int iVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar2 = *(int *)(extraout_ECX + 0xd4);
  iVar1 = *(int *)(extraout_ECX + 0xd8);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffec;
  if (iVar2 == iVar1) {
    FUN_005d157f(*(int *)(extraout_ECX + 0xf0) - *(int *)(extraout_ECX + 0xec) >> 2);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  FUN_005bd780(*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x14);
  FUN_005d14d2();
  return;
}

