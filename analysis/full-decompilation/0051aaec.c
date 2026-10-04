
void FUN_0051aaec(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  void *pvVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  FUN_005a5631(0x1010,unaff_EBP + -0x10,4);
  pvVar5 = operator_new(0x194);
  *(void **)(unaff_EBP + -0x14) = pvVar5;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar5 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_005e372a();
  }
  piVar1 = *(int **)(unaff_EBP + -0x10);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(extraout_ECX + 0x1b0) = uVar6;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x68))(DAT_006f2a64);
  }
  (**(code **)(**(int **)(extraout_ECX + 0x1b0) + 0x19c))(*(undefined4 *)(unaff_EBP + -0x10),4,1);
  *(undefined1 *)(*(int *)(extraout_ECX + 0x1b0) + 0x16b) = 1;
  *(undefined4 *)(*(int *)(extraout_ECX + 0x1b0) + 0xf8) = 1;
  *(undefined4 *)(*(int *)(extraout_ECX + 0x1b0) + 0xf4) = 1;
  (**(code **)(**(int **)(extraout_ECX + 0x1b0) + 0x94))();
  (**(code **)(**(int **)(extraout_ECX + 0x410) + 0x20))(*(undefined4 *)(extraout_ECX + 0x1b0));
  FUN_005e46f0(1);
  FUN_005a5631(0x1011,unaff_EBP + -0x10,4);
  pvVar5 = operator_new(0x194);
  *(void **)(unaff_EBP + -0x14) = pvVar5;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (pvVar5 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_005e372a();
  }
  piVar1 = *(int **)(unaff_EBP + -0x10);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(extraout_ECX + 0x1ac) = uVar6;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x68))(DAT_006f2a64);
  }
  (**(code **)(**(int **)(extraout_ECX + 0x1ac) + 0x19c))(*(undefined4 *)(unaff_EBP + -0x10),4,1);
  *(undefined1 *)(*(int *)(extraout_ECX + 0x1ac) + 0x16b) = 1;
  *(undefined4 *)(*(int *)(extraout_ECX + 0x1ac) + 0xf8) = 1;
  *(undefined4 *)(*(int *)(extraout_ECX + 0x1ac) + 0xf4) = 1;
  (**(code **)(**(int **)(extraout_ECX + 0x1ac) + 0x94))();
  (**(code **)(**(int **)(extraout_ECX + 0x410) + 0x20))(*(undefined4 *)(extraout_ECX + 0x1ac));
  FUN_005e46f0(0);
  FUN_005a5631(0x1012,unaff_EBP + -0x10,4);
  pvVar5 = operator_new(0x194);
  *(void **)(unaff_EBP + -0x14) = pvVar5;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  if (pvVar5 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_005e372a();
  }
  piVar1 = *(int **)(unaff_EBP + -0x10);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(extraout_ECX + 0x1b4) = uVar6;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x68))(DAT_006f2a64);
  }
  (**(code **)(**(int **)(extraout_ECX + 0x1b4) + 0x19c))(*(undefined4 *)(unaff_EBP + -0x10),4,1);
  *(undefined1 *)(*(int *)(extraout_ECX + 0x1b4) + 0x16b) = 1;
  *(undefined4 *)(*(int *)(extraout_ECX + 0x1b4) + 0xf8) = 1;
  *(undefined4 *)(*(int *)(extraout_ECX + 0x1b4) + 0xf4) = 1;
  (**(code **)(**(int **)(extraout_ECX + 0x1b4) + 0x94))();
  (**(code **)(**(int **)(extraout_ECX + 0x410) + 0x20))(*(undefined4 *)(extraout_ECX + 0x1b4));
  FUN_005e46f0(0);
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0x98) = &PTR_FUN_0066643c;
  *(undefined4 *)(unaff_EBP + -4) = 3;
  uVar6 = FUN_0041532c(9,unaff_EBP + -0x98,0);
  cVar4 = FUN_004fff98(0xf1,uVar6);
  if (cVar4 != '\0') {
    FUN_00471655(unaff_EBP + -0x18);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_0046fc87(unaff_EBP + -0x20,0);
    *(undefined1 *)(unaff_EBP + -4) = 5;
    uVar6 = FUN_0046fc7a();
    FUN_005d4956(uVar6);
    *(undefined1 *)(unaff_EBP + -4) = 6;
    FUN_005dd9c8(unaff_EBP + -0x2c);
    *(undefined1 *)(unaff_EBP + -4) = 5;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_0042004f();
    FUN_0046fc87(unaff_EBP + -0x20,0);
    *(undefined1 *)(unaff_EBP + -4) = 7;
    uVar6 = FUN_0046fc7a();
    FUN_005d4956(uVar6);
    *(undefined1 *)(unaff_EBP + -4) = 8;
    FUN_005dd9c8(unaff_EBP + -0x2c);
    *(undefined1 *)(unaff_EBP + -4) = 7;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_0042004f();
    FUN_0046fc87(unaff_EBP + -0x20,0);
    *(undefined1 *)(unaff_EBP + -4) = 9;
    uVar6 = FUN_0046fc7a();
    FUN_005d4956(uVar6);
    *(undefined1 *)(unaff_EBP + -4) = 10;
    FUN_005dd9c8(unaff_EBP + -0x2c);
    *(undefined1 *)(unaff_EBP + -4) = 9;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_0042004f();
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_0042004f();
  }
  cVar4 = FUN_004cff80();
  if (cVar4 == '\0') {
    iVar7 = (**(code **)(*DAT_006f2a8c + 0x58))();
    FUN_004cb21d(2,iVar7 + 0x14);
    iVar7 = *(int *)(*(int *)(extraout_ECX + 0x1b0) + 0x88);
    iVar2 = *(int *)(*(int *)(extraout_ECX + 0x1b0) + 0x80);
    iVar8 = (**(code **)(*DAT_006f2a8c + 0x58))();
    FUN_004cb21d(2,iVar8 + 0x15 + (iVar7 - iVar2));
    iVar7 = *(int *)(extraout_ECX + 0x1ac);
    iVar2 = *(int *)(iVar7 + 0x88);
    iVar8 = *(int *)(iVar7 + 0x88);
    iVar3 = *(int *)(iVar7 + 0x80);
    iVar7 = *(int *)(iVar7 + 0x80);
    iVar9 = (**(code **)(*DAT_006f2a8c + 0x58))();
    iVar7 = iVar9 + (iVar8 - iVar7) + 0x16 + (iVar2 - iVar3);
  }
  else {
    iVar7 = (**(code **)(*DAT_006f2a8c + 0x58))();
    FUN_004cb21d(2,iVar7 + 0x28);
    iVar7 = *(int *)(*(int *)(extraout_ECX + 0x1b0) + 0x88);
    iVar2 = *(int *)(*(int *)(extraout_ECX + 0x1b0) + 0x80);
    iVar8 = (**(code **)(*DAT_006f2a8c + 0x58))();
    FUN_004cb21d(2,iVar8 + 0x29 + (iVar7 - iVar2));
    iVar7 = *(int *)(*(int *)(extraout_ECX + 0x1b0) + 0x88);
    iVar2 = *(int *)(*(int *)(extraout_ECX + 0x1b0) + 0x80);
    iVar8 = *(int *)(*(int *)(extraout_ECX + 0x1ac) + 0x88);
    iVar3 = *(int *)(*(int *)(extraout_ECX + 0x1ac) + 0x80);
    iVar9 = (**(code **)(*DAT_006f2a8c + 0x58))();
    iVar7 = iVar9 + (iVar8 - iVar3) + 0x2a + (iVar7 - iVar2);
  }
  FUN_004cb21d(2,iVar7);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00470467();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

