
undefined1 FUN_006022b0(void)

{
  undefined4 *puVar1;
  int iVar2;
  int extraout_ECX;
  undefined1 uVar3;
  int unaff_EBP;
  uint uVar4;
  int *piVar5;
  int iStack_1c;
  
  FUN_00634c24();
  *(undefined ***)(unaff_EBP + -0x18) = &PTR_LAB_00669c88;
  uVar4 = -(uint)(extraout_ECX != 0x48) & extraout_ECX - 0x38U;
  iVar2 = *(int *)(uVar4 + 4);
  piVar5 = (int *)(uVar4 + 4);
  *(int **)(unaff_EBP + -0x14) = piVar5;
  iStack_1c = 0x6022e3;
  (**(code **)(iVar2 + 4))();
  iStack_1c = unaff_EBP + 8;
  uVar3 = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005e76d4(unaff_EBP + -0x10);
  iStack_1c = *(int *)(unaff_EBP + -0x10);
  if (iStack_1c != *(int *)(extraout_ECX + 8)) {
    if (*(char *)(unaff_EBP + 0xc) != '\0') {
      puVar1 = (undefined4 *)(iStack_1c + 0x14);
      iStack_1c = 0x60230f;
      (*(code *)**(undefined4 **)*puVar1)();
      iStack_1c = *(int *)(unaff_EBP + -0x10);
    }
    *(int **)(unaff_EBP + 0xc) = &iStack_1c;
    FUN_006043cb();
    uVar3 = 1;
  }
  iVar2 = *piVar5;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iStack_1c = 0x60232e;
  (**(code **)(iVar2 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

