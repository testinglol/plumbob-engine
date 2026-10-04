
void FUN_004c4ebf(void)

{
  int iVar1;
  undefined4 uVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  iVar1 = *(int *)(extraout_ECX + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 6;
  if (iVar1 != 0) {
    FUN_006029b3();
    FUN_006321f0(iVar1);
  }
  FUN_004c5c4a();
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_004054b4();
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_004054b4();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_00470467();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_00470467();
  uVar2 = *(undefined4 *)(extraout_ECX + 0x24);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
  FUN_00542b02();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_004a169d();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004c659b();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

