
undefined4 FUN_00607401(void)

{
  int *piVar1;
  int iVar2;
  int extraout_ECX;
  int unaff_EBP;
  int *piVar3;
  
  FUN_00634c24();
  piVar1 = (int *)(extraout_ECX + 0x28);
  (**(code **)(*(int *)(extraout_ECX + 0x28) + 0x38))(unaff_EBP + -0x10);
  iVar2 = *(int *)(extraout_ECX + 0x40);
  *(int *)(unaff_EBP + -0x34) = iVar2;
  *(int *)(extraout_ECX + 0x40) = iVar2 + 1;
  *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -0x30) = *(undefined4 *)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + 0x10);
  *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + 0x14);
  *(undefined1 *)(unaff_EBP + -0x24) = *(undefined1 *)(unaff_EBP + 0x18);
  *(undefined1 *)(unaff_EBP + -0x18) = *(undefined1 *)(unaff_EBP + 0x1c);
  if ((int *)**(int **)(extraout_ECX + 4) == *(int **)(extraout_ECX + 4)) {
    FUN_005772e2();
    iVar2 = FUN_005fd8ea();
    piVar3 = (int *)(extraout_ECX + 0x44);
    *(int **)(unaff_EBP + -0x10) = piVar3;
    *(int *)(unaff_EBP + -0x1c) = iVar2 + *(int *)(unaff_EBP + -0x20);
    iVar2 = *piVar3;
    *(undefined ***)(unaff_EBP + -0x14) = &PTR_LAB_00669c88;
    (**(code **)(iVar2 + 4))();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_0060784f(unaff_EBP + -0x34);
    if (*(char *)(extraout_ECX + 0x8d) == '\0') {
      *(undefined1 *)(extraout_ECX + 0x8d) = 1;
      (**(code **)(*piVar1 + 4))(extraout_ECX);
    }
    (**(code **)(*piVar1 + 0x14))();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    iVar2 = *piVar3;
  }
  else {
    iVar2 = FUN_005fd8ea();
    piVar3 = (int *)(extraout_ECX + 0x44);
    *(int **)(unaff_EBP + -0x10) = piVar3;
    *(int *)(unaff_EBP + -0x1c) = iVar2 + *(int *)(unaff_EBP + -0x20);
    iVar2 = *piVar3;
    *(undefined ***)(unaff_EBP + -0x14) = &PTR_LAB_00669c88;
    (**(code **)(iVar2 + 4))();
    *(undefined4 *)(unaff_EBP + -4) = 1;
    FUN_0060784f(unaff_EBP + -0x34);
    (**(code **)(*piVar1 + 0x1c))();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    iVar2 = *piVar3;
  }
  (**(code **)(iVar2 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x34);
}

