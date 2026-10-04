
void FUN_004a708e(void)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  int *piVar3;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x18) = extraout_ECX;
  *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX + -2;
  extraout_ECX[-2] = &PTR_FUN_00668744;
  *extraout_ECX = &PTR_FUN_00668738;
  *(undefined4 *)(unaff_EBP + -4) = 0x11;
  piVar3 = extraout_ECX + 0x1a;
  *(undefined4 *)(unaff_EBP + -0x10) = 2;
  do {
    if (*piVar3 != 0) {
      FUN_005e3581();
      *piVar3 = 0;
    }
    piVar3 = piVar3 + 1;
    piVar1 = (int *)(unaff_EBP + -0x10);
    *piVar1 = *piVar1 + -1;
  } while (*piVar1 != 0);
  if (extraout_ECX[0x6f] != 0) {
    FUN_004b4b68();
  }
  FUN_006321f0(extraout_ECX[0x79]);
  FUN_006321f0(extraout_ECX[0x7a]);
  if ((undefined4 *)extraout_ECX[0x13] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)extraout_ECX[0x13])(1);
  }
  if (extraout_ECX[300] != 0) {
    FUN_0046176c();
    extraout_ECX[300] = 0;
  }
  if (extraout_ECX[0x12d] != 0) {
    FUN_0046176c();
    extraout_ECX[0x12d] = 0;
  }
  if ((undefined4 *)extraout_ECX[0x7d] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)extraout_ECX[0x7d])(1);
  }
  FUN_004b8176();
  uVar2 = extraout_ECX[0x13e];
  *(undefined1 *)(unaff_EBP + -4) = 0x10;
  *(undefined4 *)(unaff_EBP + -0x10) = uVar2;
  FUN_005db425();
  *(undefined1 *)(unaff_EBP + -4) = 0xf;
  FUN_005b8770();
  uVar2 = extraout_ECX[0x117];
  *(undefined1 *)(unaff_EBP + -4) = 0xd;
  *(undefined4 *)(unaff_EBP + -0x10) = uVar2;
  FUN_005db425();
  uVar2 = extraout_ECX[0x111];
  *(undefined1 *)(unaff_EBP + -4) = 0xc;
  *(undefined4 *)(unaff_EBP + -0x10) = uVar2;
  FUN_005db425();
  uVar2 = extraout_ECX[0x10b];
  *(undefined1 *)(unaff_EBP + -4) = 0xb;
  *(undefined4 *)(unaff_EBP + -0x10) = uVar2;
  FUN_005db425();
  uVar2 = extraout_ECX[0x105];
  *(undefined1 *)(unaff_EBP + -4) = 10;
  *(undefined4 *)(unaff_EBP + -0x10) = uVar2;
  FUN_005db425();
  uVar2 = extraout_ECX[0x102];
  *(undefined1 *)(unaff_EBP + -4) = 9;
  *(undefined4 *)(unaff_EBP + -0x10) = uVar2;
  FUN_0048c4c9();
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_00635f6d(extraout_ECX + 0x80,8,0x40,FUN_00416e17);
  uVar2 = extraout_ECX[0x76];
  *(undefined1 *)(unaff_EBP + -4) = 7;
  *(undefined4 *)(unaff_EBP + -0x10) = uVar2;
  FUN_00448934();
  uVar2 = extraout_ECX[0x73];
  *(undefined1 *)(unaff_EBP + -4) = 6;
  *(undefined4 *)(unaff_EBP + -0x10) = uVar2;
  FUN_00448934();
  uVar2 = extraout_ECX[0x70];
  *(undefined1 *)(unaff_EBP + -4) = 5;
  *(undefined4 *)(unaff_EBP + -0x10) = uVar2;
  FUN_00448934();
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_0042004f();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_004c9db5();
  uVar2 = extraout_ECX[0x26];
  *(undefined1 *)(unaff_EBP + -4) = 2;
  *(undefined4 *)(unaff_EBP + -0x10) = uVar2;
  FUN_005db425();
  uVar2 = extraout_ECX[0x20];
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *(undefined4 *)(unaff_EBP + -0x10) = uVar2;
  FUN_005db425();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0040763c();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00476c1e();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

