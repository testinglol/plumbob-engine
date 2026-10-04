
undefined1 FUN_00602341(void)

{
  int iVar1;
  int extraout_ECX;
  undefined1 uVar2;
  int unaff_EBP;
  uint uVar3;
  int *piVar4;
  int iStack_20;
  
  FUN_00634c24();
  *(undefined ***)(unaff_EBP + -0x1c) = &PTR_LAB_00669c88;
  uVar3 = -(uint)(extraout_ECX != 0x48) & extraout_ECX - 0x38U;
  iVar1 = *(int *)(uVar3 + 4);
  piVar4 = (int *)(uVar3 + 4);
  *(int **)(unaff_EBP + -0x18) = piVar4;
  iStack_20 = 0x602374;
  (**(code **)(iVar1 + 4))();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = *(int *)(extraout_ECX + 8);
  iStack_20 = *(int *)(iVar1 + 8);
  *(int *)(unaff_EBP + -0x10) = iStack_20;
  do {
    if (iStack_20 == iVar1) {
      uVar2 = 0;
LAB_006023cf:
      iVar1 = *piVar4;
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      iStack_20 = 0x6023da;
      (**(code **)(iVar1 + 8))();
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return uVar2;
    }
    if (*(int *)(iStack_20 + 0x14) == *(int *)(unaff_EBP + 8)) {
      *(int **)(unaff_EBP + -0x14) = &iStack_20;
      *(int *)(unaff_EBP + -0x14) = iStack_20;
      FUN_0041674f();
      iStack_20 = *(int *)(unaff_EBP + -0x14);
      FUN_006043cb();
      if (*(char *)(unaff_EBP + 0xc) != '\0') {
        iStack_20 = 0x6023c9;
        (**(code **)**(undefined4 **)(unaff_EBP + 8))();
      }
      uVar2 = 1;
      goto LAB_006023cf;
    }
    iStack_20 = 0x602398;
    FUN_0041674f();
    iVar1 = *(int *)(extraout_ECX + 8);
    iStack_20 = *(int *)(unaff_EBP + -0x10);
  } while( true );
}

