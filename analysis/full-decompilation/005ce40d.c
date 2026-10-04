
void FUN_005ce40d(void)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 *extraout_ECX;
  int *piVar3;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x1c) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_006734a0;
  *(undefined4 *)(unaff_EBP + -4) = 0xb;
  while (1 < (uint)((int)(extraout_ECX[0x70] - extraout_ECX[0x6f]) / 0x44)) {
    FUN_005cea2a();
  }
  if ((int *)extraout_ECX[0x25] != (int *)0x0) {
    (**(code **)(*(int *)extraout_ECX[0x25] + 8))();
    extraout_ECX[0x25] = 0;
  }
  piVar1 = (int *)extraout_ECX[0x22];
  piVar3 = (int *)extraout_ECX[0x21];
  *(int **)(unaff_EBP + -0x10) = piVar1;
  *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX + 0x21;
  if (piVar3 != piVar1) {
    do {
      if ((int *)*piVar3 != (int *)0x0) {
        (**(code **)(*(int *)*piVar3 + 8))();
      }
      piVar3 = piVar3 + 1;
    } while (piVar3 != *(int **)(unaff_EBP + -0x10));
  }
  piVar1 = (int *)extraout_ECX[0x1f];
  piVar3 = (int *)extraout_ECX[0x1e];
  *(int **)(unaff_EBP + -0x10) = piVar1;
  *(undefined4 **)(unaff_EBP + -0x18) = extraout_ECX + 0x1e;
  if (piVar3 != piVar1) {
    do {
      if ((int *)*piVar3 != (int *)0x0) {
        (**(code **)(*(int *)*piVar3 + 4))();
      }
      piVar3 = piVar3 + 1;
    } while (piVar3 != *(int **)(unaff_EBP + -0x10));
  }
  piVar1 = (int *)extraout_ECX[0x35];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    extraout_ECX[0x35] = 0;
  }
  piVar1 = (int *)extraout_ECX[0x36];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    extraout_ECX[0x36] = 0;
  }
  piVar1 = (int *)extraout_ECX[0x6d];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    extraout_ECX[0x6d] = 0;
  }
  piVar1 = (int *)extraout_ECX[0x6e];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    extraout_ECX[0x6e] = 0;
  }
  piVar1 = (int *)extraout_ECX[0x8b];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    extraout_ECX[0x8b] = 0;
  }
  FUN_006321f0(extraout_ECX[0x100]);
  FUN_006321f0(extraout_ECX[0x101]);
  *(undefined1 *)(unaff_EBP + -4) = 10;
  FUN_005cb62e();
  *(undefined1 *)(unaff_EBP + -4) = 9;
  FUN_005cb62e();
  uVar2 = extraout_ECX[0x81];
  *(undefined1 *)(unaff_EBP + -4) = 8;
  *(undefined4 *)(unaff_EBP + -0x10) = uVar2;
  FUN_005db425();
  uVar2 = extraout_ECX[0x7b];
  *(undefined1 *)(unaff_EBP + -4) = 7;
  *(undefined4 *)(unaff_EBP + -0x10) = uVar2;
  FUN_005db425();
  uVar2 = extraout_ECX[0x75];
  *(undefined1 *)(unaff_EBP + -4) = 6;
  *(undefined4 *)(unaff_EBP + -0x10) = uVar2;
  FUN_005db425();
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_005cf224();
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_005c4890();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005c4890();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005c4890();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = **(undefined4 **)(unaff_EBP + -0x14);
  FUN_0048c4c9();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -0x1c) = **(undefined4 **)(unaff_EBP + -0x18);
  FUN_0048c4c9();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

