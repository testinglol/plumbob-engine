
undefined1 FUN_00603918(void)

{
  int iVar1;
  int extraout_ECX;
  undefined1 uVar2;
  int unaff_EBP;
  int iStack_20;
  
  FUN_00634c24();
  *(undefined ***)(unaff_EBP + -0x1c) = &PTR_LAB_00669c88;
  iVar1 = *(int *)(extraout_ECX + 0xac);
  *(int **)(unaff_EBP + -0x18) = (int *)(extraout_ECX + 0xac);
  iStack_20 = 0x603945;
  (**(code **)(iVar1 + 4))();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = *(int *)(extraout_ECX + 0x78);
  iStack_20 = *(int *)(iVar1 + 8);
  *(int *)(unaff_EBP + -0x10) = iStack_20;
  do {
    if (iStack_20 == iVar1) {
      uVar2 = 0;
LAB_006039a1:
      iVar1 = *(int *)(extraout_ECX + 0xac);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      iStack_20 = 0x6039ac;
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
        iStack_20 = 0x60399b;
        (**(code **)(**(int **)(unaff_EBP + 8) + 4))();
      }
      uVar2 = 1;
      goto LAB_006039a1;
    }
    iStack_20 = 0x603969;
    FUN_0041674f();
    iVar1 = *(int *)(extraout_ECX + 0x78);
    iStack_20 = *(int *)(unaff_EBP + -0x10);
  } while( true );
}

