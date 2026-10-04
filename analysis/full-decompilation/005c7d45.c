
void FUN_005c7d45(void)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00673458;
  *(undefined4 *)(unaff_EBP + -4) = 0x16;
  FUN_005caacc();
  if (*(char *)(extraout_ECX + 2) != '\0') {
    uVar2 = (**(code **)(*(int *)extraout_ECX[0x1d] + 0x4c))((int *)extraout_ECX[0x1d]);
    extraout_ECX[1] = uVar2;
  }
  piVar1 = (int *)extraout_ECX[0x29];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    extraout_ECX[0x29] = 0;
  }
  piVar1 = (int *)extraout_ECX[0x28];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    extraout_ECX[0x28] = 0;
  }
  piVar1 = (int *)extraout_ECX[0x1d];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    extraout_ECX[0x1d] = 0;
  }
  piVar1 = (int *)extraout_ECX[0x1c];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    extraout_ECX[0x1c] = 0;
  }
  piVar1 = (int *)extraout_ECX[0x1b];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    extraout_ECX[0x1b] = 0;
  }
  if ((HMODULE)extraout_ECX[0x14d] != (HMODULE)0x0) {
    FreeLibrary((HMODULE)extraout_ECX[0x14d]);
  }
  uVar2 = extraout_ECX[0x266];
  *(undefined1 *)(unaff_EBP + -4) = 0x15;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
  FUN_005cb56f();
  *(undefined1 *)(unaff_EBP + -4) = 0x14;
  FUN_005cb4e1();
  uVar2 = extraout_ECX[0x260];
  *(undefined1 *)(unaff_EBP + -4) = 0x13;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
  FUN_004d6053();
  *(undefined1 *)(unaff_EBP + -4) = 0x12;
  FUN_005c7c9d();
  *(undefined1 *)(unaff_EBP + -4) = 0x11;
  FUN_005c7c9d();
  uVar2 = extraout_ECX[0x132];
  *(undefined1 *)(unaff_EBP + -4) = 0x10;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
  FUN_005db425();
  uVar2 = extraout_ECX[300];
  *(undefined1 *)(unaff_EBP + -4) = 0xf;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
  FUN_005db425();
  uVar2 = extraout_ECX[0x126];
  *(undefined1 *)(unaff_EBP + -4) = 0xe;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
  FUN_005db425();
  uVar2 = extraout_ECX[0x120];
  *(undefined1 *)(unaff_EBP + -4) = 0xd;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
  FUN_005db425();
  uVar2 = extraout_ECX[0x11a];
  *(undefined1 *)(unaff_EBP + -4) = 0xc;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
  FUN_005db425();
  uVar2 = extraout_ECX[0x114];
  *(undefined1 *)(unaff_EBP + -4) = 0xb;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
  FUN_005db425();
  *(undefined1 *)(unaff_EBP + -4) = 10;
  FUN_005c2ee6();
  *(undefined1 *)(unaff_EBP + -4) = 9;
  FUN_005c2ee6();
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_005c2ee6();
  *(undefined1 *)(unaff_EBP + -4) = 7;
  FUN_005c7c9d();
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_005c7c9d();
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_005c7c9d();
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_005c7c9d();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005c7c9d();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005cb62e();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005cb62e();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005cb62e();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005cb62e();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

