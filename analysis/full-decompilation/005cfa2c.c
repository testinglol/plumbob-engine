
void FUN_005cfa2c(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_006734d8;
  iVar1 = extraout_ECX[3];
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (iVar1 != 0) {
    FUN_005d4045();
    FUN_006321f0(iVar1);
  }
  iVar1 = extraout_ECX[4];
  if (iVar1 != 0) {
    FUN_005d2789();
    FUN_006321f0(iVar1);
  }
  FUN_005cfc13();
  uVar2 = extraout_ECX[10];
  *(undefined1 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
  FUN_0048c4c9();
  uVar2 = extraout_ECX[7];
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
  FUN_0048c4c9();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

