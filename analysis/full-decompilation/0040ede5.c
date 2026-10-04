
void FUN_0040ede5(void)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  pcVar1 = (char *)FUN_004705f2(2,0xffffffff);
  if ((pcVar1 == (char *)0x0) || (*pcVar1 == '\0')) goto LAB_0040eff0;
  FUN_005879ea();
  FUN_00587670();
  uVar3 = *(undefined4 *)(extraout_ECX + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00470636(uVar3);
  iVar2 = FUN_0040cd0e();
  if (iVar2 < 0) {
LAB_0040ee73:
    if (*(int *)(unaff_EBP + -0x14) != -1) goto LAB_0040ee78;
LAB_0040ee81:
    FUN_00470636(extraout_ECX + 0xc);
    iVar2 = FUN_0040cd0e();
    if (-1 < iVar2) {
      if (iVar2 < 2) {
        uVar3 = FUN_0040d106();
        *(undefined4 *)(unaff_EBP + -0x20) = uVar3;
        uVar3 = FUN_0040d46a();
        *(undefined4 *)(unaff_EBP + -0x18) = uVar3;
      }
      else if (iVar2 < 6) {
        uVar3 = FUN_0040d106();
        *(undefined4 *)(unaff_EBP + -0x20) = uVar3;
        *(undefined4 *)(unaff_EBP + -0x18) = 0;
      }
    }
    iVar2 = FUN_0040cc3f();
    if (iVar2 == 0) {
      uVar3 = FUN_0040d591();
      *(undefined4 *)(unaff_EBP + -0x1c) = uVar3;
    }
    else {
      *(undefined4 *)(unaff_EBP + -0x1c) = 0;
    }
    iVar2 = FUN_0040dbc1();
    uVar3 = FUN_0040d8a9();
    *(undefined4 *)(unaff_EBP + -0x24) = uVar3;
    uVar3 = FUN_0040ded9();
    *(undefined4 *)(unaff_EBP + -0x14) = uVar3;
    iVar4 = FUN_0040cc3f();
    if (iVar4 == 0) {
      uVar3 = FUN_0040e1f1();
      *(undefined4 *)(unaff_EBP + -0x10) = uVar3;
    }
    else {
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
    }
    if (*(int *)(unaff_EBP + -0x20) == -1) {
      FUN_0040ecea();
      iVar4 = FUN_0040cc3f();
      if (iVar4 == 0) {
        FUN_0040b84f();
        iVar4 = FUN_0040cf46();
        if (iVar4 == 0) {
          FUN_0040c04d();
        }
      }
      else {
        FUN_0040c3d8();
      }
      iVar4 = FUN_0040cf46();
      if (iVar4 == 0) {
        FUN_0040c8b7();
      }
    }
    if (*(int *)(unaff_EBP + -0x18) == -1) {
      FUN_0040ecc7();
    }
    if (*(int *)(unaff_EBP + -0x1c) == -1) {
      FUN_0040ed27();
    }
    if (iVar2 == -1) {
      FUN_0040ed73();
    }
    if (*(int *)(unaff_EBP + -0x24) == -1) {
      FUN_0040ed4d();
    }
    if (*(int *)(unaff_EBP + -0x14) == -1) {
      FUN_0040ed99();
    }
    if (*(int *)(unaff_EBP + -0x10) == -1) {
      FUN_0040edbf();
    }
    if ((((*(int *)(unaff_EBP + -0x18) == -1) || (*(int *)(unaff_EBP + -0x20) == -1)) ||
        (*(int *)(unaff_EBP + -0x1c) == -1)) ||
       (((iVar2 == -1 || (*(int *)(unaff_EBP + -0x24) == -1)) ||
        ((*(int *)(unaff_EBP + -0x14) == -1 || (*(int *)(unaff_EBP + -0x10) == -1)))))) {
      FUN_0040a5ea();
    }
    FUN_005876ec(unaff_EBP + -0x90,*(undefined4 *)(unaff_EBP + 8));
  }
  else {
    if (iVar2 < 2) {
      uVar3 = FUN_0040d106();
      *(undefined4 *)(unaff_EBP + -0x10) = uVar3;
      uVar3 = FUN_0040d46a();
      *(undefined4 *)(unaff_EBP + -0x14) = uVar3;
      goto LAB_0040ee73;
    }
    if (5 < iVar2) goto LAB_0040ee73;
    uVar3 = FUN_0040d106();
    *(undefined4 *)(unaff_EBP + -0x10) = uVar3;
LAB_0040ee78:
    if (*(int *)(unaff_EBP + -0x10) == -1) goto LAB_0040ee81;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00470467();
LAB_0040eff0:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

