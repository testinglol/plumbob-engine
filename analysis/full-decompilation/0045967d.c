
void FUN_0045967d(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00667378;
  iVar1 = extraout_ECX[699];
  *(undefined4 *)(unaff_EBP + -4) = 8;
  if (iVar1 != 0) {
    FUN_00635f6d(iVar1 + 8,0x14,9,&LAB_0042147c);
    FUN_006321f0(iVar1);
  }
  iVar1 = extraout_ECX[0x2b7];
  if (iVar1 != 0) {
    FUN_005880b4();
    FUN_006321f0(iVar1);
  }
  uVar2 = extraout_ECX[0x2c0];
  *(undefined1 *)(unaff_EBP + -4) = 7;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
  FUN_004d6053();
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_0045f9bf();
  uVar2 = extraout_ECX[0x2b8];
  *(undefined1 *)(unaff_EBP + -4) = 5;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
  FUN_00542b02();
  uVar2 = extraout_ECX[0x2b4];
  *(undefined1 *)(unaff_EBP + -4) = 4;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
  FUN_004d6053();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_00635f6d(extraout_ECX + 0x208,0x44,8,FUN_004434c5);
  uVar2 = extraout_ECX[0x205];
  *(undefined1 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
  FUN_005db425();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004323e0();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

