
undefined4 FUN_006039bf(void)

{
  undefined4 uVar1;
  int iVar2;
  int extraout_ECX;
  int unaff_EBP;
  int iStack_24;
  
  FUN_00634c24();
  *(undefined ***)(unaff_EBP + -0x20) = &PTR_LAB_00669c88;
  iVar2 = *(int *)(extraout_ECX + 0xac);
  *(int **)(unaff_EBP + -0x1c) = (int *)(extraout_ECX + 0xac);
  iStack_24 = 0x6039ec;
  (**(code **)(iVar2 + 4))();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar2 = *(int *)(extraout_ECX + 0x78);
  iStack_24 = *(int *)(iVar2 + 8);
  *(int *)(unaff_EBP + -0x10) = iStack_24;
  while (iStack_24 != iVar2) {
    uVar1 = *(undefined4 *)(iStack_24 + 0x14);
    *(int **)(unaff_EBP + -0x14) = &iStack_24;
    *(int *)(unaff_EBP + -0x14) = iStack_24;
    *(undefined4 *)(unaff_EBP + -0x18) = uVar1;
    FUN_0041674f();
    iStack_24 = *(int *)(unaff_EBP + -0x14);
    FUN_006043cb();
    if (*(char *)(unaff_EBP + 8) != '\0') {
      iStack_24 = 0x603a31;
      (**(code **)(**(int **)(unaff_EBP + -0x18) + 4))();
    }
    iVar2 = *(int *)(extraout_ECX + 0x78);
    iStack_24 = *(int *)(unaff_EBP + -0x10);
  }
  iVar2 = *(int *)(extraout_ECX + 0xac);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iStack_24 = 0x603a43;
  (**(code **)(iVar2 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

