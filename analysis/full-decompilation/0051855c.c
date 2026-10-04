
void FUN_0051855c(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_0066c618;
  *(undefined4 *)(unaff_EBP + -4) = 0xf;
  FUN_0051af7b();
  if (DAT_006f3adc == extraout_ECX) {
    DAT_006f3adc = (undefined4 *)0x0;
  }
  *(undefined1 *)(unaff_EBP + -4) = 0xe;
  FUN_005b8770();
  uVar1 = extraout_ECX[0x110];
  *(undefined1 *)(unaff_EBP + -4) = 0xd;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  FUN_0048c4c9();
  uVar1 = extraout_ECX[0x10d];
  *(undefined1 *)(unaff_EBP + -4) = 0xc;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  FUN_0048c4c9();
  *(undefined1 *)(unaff_EBP + -4) = 0xb;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 10;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 9;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 7;
  FUN_00635f6d(extraout_ECX + 0x97,0xc,0xc,FUN_005b8770);
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_00635f6d(extraout_ECX + 0x73,0xc,0xc,FUN_005b8770);
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_0048c4c9();
  uVar1 = extraout_ECX[0x53];
  *(undefined1 *)(unaff_EBP + -4) = 4;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  FUN_0048c4c9();
  uVar1 = extraout_ECX[0x50];
  *(undefined1 *)(unaff_EBP + -4) = 3;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  FUN_0048c4c9();
  uVar1 = extraout_ECX[0x4d];
  *(undefined1 *)(unaff_EBP + -4) = 2;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  FUN_0048c4c9();
  uVar1 = extraout_ECX[0x4a];
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  FUN_0048c4c9();
  uVar1 = extraout_ECX[0x3c];
  *(undefined1 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  FUN_0048c4c9();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005dbeb0();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

