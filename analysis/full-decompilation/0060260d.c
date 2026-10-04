
undefined4 FUN_0060260d(void)

{
  int *piVar1;
  int iVar2;
  int extraout_ECX;
  undefined1 *extraout_ECX_00;
  int unaff_EBP;
  undefined1 *puStack_34;
  int iStack_30;
  
  FUN_00634c24();
  *(undefined ***)(unaff_EBP + -0x28) = &PTR_LAB_00669c88;
  iVar2 = *(int *)(extraout_ECX + 4);
  *(int **)(unaff_EBP + -0x24) = (int *)(extraout_ECX + 4);
  (**(code **)(iVar2 + 4))();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iStack_30 = unaff_EBP + -0x10;
  puStack_34 = (undefined1 *)0x60264d;
  FUN_005e76d4();
  iStack_30 = *(int *)(unaff_EBP + -0x10);
  if (iStack_30 == *(int *)(extraout_ECX + 0x90)) {
    iStack_30 = 0x60265d;
    piVar1 = operator_new(4);
    *(int **)(unaff_EBP + -0x14) = piVar1;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    if (piVar1 == (int *)0x0) {
      piVar1 = (int *)0x0;
    }
    else {
      iStack_30 = 0x602672;
      iVar2 = FUN_00401742();
      *piVar1 = iVar2;
      *(int *)iVar2 = iVar2;
      *(int *)(*piVar1 + 4) = *piVar1;
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + 0xc);
    iStack_30 = unaff_EBP + -0x18;
    *(int **)(unaff_EBP + -0x1c) = piVar1;
    puStack_34 = (undefined1 *)0x60269c;
    FUN_00602b14();
  }
  else {
    puStack_34 = (undefined1 *)&iStack_30;
    iVar2 = **(int **)(iStack_30 + 0x14);
    *(int **)(unaff_EBP + -0x14) = &iStack_30;
    FUN_00575825();
    *(undefined1 ***)(unaff_EBP + -0x14) = &puStack_34;
    puStack_34 = extraout_ECX_00;
    FUN_00602902(&puStack_34);
    piVar1 = (int *)FUN_00602c63(unaff_EBP + -0x1c);
    if (*piVar1 != iVar2) goto LAB_006026e4;
  }
  iStack_30 = 0x6026e4;
  FUN_00601324();
LAB_006026e4:
  iVar2 = *(int *)(extraout_ECX + 4);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  (**(code **)(iVar2 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

