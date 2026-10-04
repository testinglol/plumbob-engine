
undefined4 FUN_006023ed(void)

{
  undefined4 uVar1;
  int iVar2;
  int extraout_ECX;
  int unaff_EBP;
  uint uVar3;
  int *piVar4;
  int iStack_24;
  
  FUN_00634c24();
  *(undefined ***)(unaff_EBP + -0x20) = &PTR_LAB_00669c88;
  uVar3 = -(uint)(extraout_ECX != 0x48) & extraout_ECX - 0x38U;
  iVar2 = *(int *)(uVar3 + 4);
  piVar4 = (int *)(uVar3 + 4);
  *(int **)(unaff_EBP + -0x1c) = piVar4;
  iStack_24 = 0x602420;
  (**(code **)(iVar2 + 4))();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar2 = *(int *)(extraout_ECX + 8);
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
      iStack_24 = 0x602464;
      (**(code **)**(undefined4 **)(unaff_EBP + -0x18))();
    }
    iVar2 = *(int *)(extraout_ECX + 8);
    iStack_24 = *(int *)(unaff_EBP + -0x10);
  }
  iVar2 = *piVar4;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iStack_24 = 0x602476;
  (**(code **)(iVar2 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

