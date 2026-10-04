
undefined4 * FUN_005eea7d(void)

{
  int iVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_00607956();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined1 *)(extraout_ECX + 0x1f) = 0;
  FUN_005d909f();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  iVar1 = FUN_00401742(0x40);
  extraout_ECX[0x30] = iVar1;
  *(int *)iVar1 = iVar1;
  iVar1 = extraout_ECX[0x30];
  *(int *)(iVar1 + 4) = iVar1;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005eec0c();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005ebf65();
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_005d6960();
  *extraout_ECX = &PTR_LAB_0067547c;
  extraout_ECX[1] = &PTR_LAB_00675470;
  extraout_ECX[2] = &PTR_FUN_00675458;
  extraout_ECX[4] = &PTR_LAB_00675450;
  extraout_ECX[0x12] = &PTR_FUN_00675400;
  *(undefined1 *)(extraout_ECX + 0x1d) = 0;
  extraout_ECX[0x1e] = 0;
  _memset(&DAT_006feb20,0,0x17c);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined1 *)(extraout_ECX + 0x1f) = 1;
  extraout_ECX[0xb2] = 0;
  extraout_ECX[0xb3] = 0;
  extraout_ECX[0xbc] = 0;
  extraout_ECX[0xbd] = 0;
  extraout_ECX[0x1c] = 0;
  *(undefined1 *)(extraout_ECX + 0xb1) = 0;
  *(undefined1 *)(extraout_ECX + 0x26) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x99) = 0;
  DAT_006fefd8 = extraout_ECX;
  return extraout_ECX;
}

