
void FUN_00455bb9(void)

{
  int *piVar1;
  int iVar2;
  void *pvVar3;
  int *extraout_ECX;
  undefined2 extraout_var;
  int unaff_EBP;
  
  FUN_00634c24();
  piVar1 = extraout_ECX + 3;
  FUN_0043bfaf(piVar1,0,*(undefined4 *)(unaff_EBP + 8),0,*(undefined4 *)(unaff_EBP + 0xc));
  if ((0x26 < *(int *)(unaff_EBP + 0xc)) && (*(int *)(unaff_EBP + 0xc) < 0x2f)) {
    FUN_0046f824(unaff_EBP + -0x110,0,0x100);
    *(undefined ***)(unaff_EBP + -0x11c) = &PTR_FUN_00666524;
    FUN_00464d2c(unaff_EBP + -0x11c);
  }
  *(undefined1 *)(extraout_ECX + 4) = 0;
  if (*piVar1 == 0) {
    iVar2 = FUN_0043acf5(0x3c08965f);
    *piVar1 = iVar2;
    extraout_ECX[1] = 0x584f424a;
    *(undefined1 *)(extraout_ECX + 4) = 1;
    if (iVar2 == 0) goto LAB_00455d2b;
  }
  iVar2 = extraout_ECX[1];
  if (iVar2 == 0x444f4f52) {
    pvVar3 = operator_new(0x1b8);
    *(void **)(unaff_EBP + -0x10) = pvVar3;
    *(undefined4 *)(unaff_EBP + -4) = 3;
    if (pvVar3 == (void *)0x0) {
LAB_00455d18:
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004631a6(*piVar1,0,extraout_ECX[2]);
    }
LAB_00455d1a:
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *extraout_ECX = iVar2;
  }
  else {
    if (iVar2 == 0x50455253) {
      pvVar3 = operator_new(0xc14);
      *(void **)(unaff_EBP + -0x10) = pvVar3;
      *(undefined4 *)(unaff_EBP + -4) = 1;
      if (pvVar3 == (void *)0x0) goto LAB_00455d18;
      iVar2 = FUN_00459493(*piVar1,extraout_ECX[2]);
      goto LAB_00455d1a;
    }
    if (iVar2 == 0x584d544f) {
      pvVar3 = operator_new(0x1ac);
      *(void **)(unaff_EBP + -0x10) = pvVar3;
      *(undefined4 *)(unaff_EBP + -4) = 2;
      if (pvVar3 == (void *)0x0) goto LAB_00455d18;
      iVar2 = FUN_004227e6(*piVar1,0,extraout_ECX[2]);
      goto LAB_00455d1a;
    }
    if (iVar2 == 0x584f424a) {
      pvVar3 = operator_new(0x18c);
      *(void **)(unaff_EBP + -0x10) = pvVar3;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if (pvVar3 == (void *)0x0) goto LAB_00455d18;
      iVar2 = FUN_0043194c(*piVar1,extraout_ECX[2]);
      goto LAB_00455d1a;
    }
  }
  if ((int *)*extraout_ECX != (int *)0x0) {
    (**(code **)(*(int *)*extraout_ECX + 0x3c))();
  }
LAB_00455d2b:
  if (*extraout_ECX != 0) {
    FUN_0043426c(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc));
    FUN_0044350d(*extraout_ECX,CONCAT22(extraout_var,*(undefined2 *)(*extraout_ECX + 0xf0)),0);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

