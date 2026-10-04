
void FUN_004f613c(void)

{
  int iVar1;
  int iVar2;
  char cVar3;
  void *pvVar4;
  int *piVar5;
  int *piVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined4 uVar9;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  do {
    if (*(int *)(extraout_ECX + 0xb0) != 0) {
      FUN_004ceb56();
    }
    FUN_0042888d();
    *(undefined1 *)(extraout_ECX + 0xf7) = 0;
    pvVar4 = operator_new(0x478);
    *(void **)(unaff_EBP + -0x10) = pvVar4;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar4 == (void *)0x0) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = (int *)FUN_00564664(1);
    }
    iVar1 = *(int *)(extraout_ECX + 0x80);
    *(int **)(extraout_ECX + 0x9c) = piVar5;
    iVar2 = *piVar5;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    (**(code **)(iVar2 + 0x60))
              (*(undefined4 *)(iVar1 + 0x7c),*(undefined4 *)(iVar1 + 0x80),
               *(undefined4 *)(iVar1 + 0x84),*(undefined4 *)(iVar1 + 0x88));
    (**(code **)(**(int **)(extraout_ECX + 0x84) + 0x98))();
    *(undefined1 *)(extraout_ECX + 0xf5) = 0;
    piVar6 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
    piVar5 = DAT_006fe8bc;
    uVar9 = *(undefined4 *)(extraout_ECX + 0x9c);
    uVar7 = (**(code **)(*piVar6 + 8))(uVar9);
    (**(code **)(*piVar5 + 0x18))(uVar7);
    uVar8 = FUN_005daa44(uVar7,uVar9);
    if (999 < uVar8) {
      uVar8 = 1000 - uVar8;
    }
    if ((0 < (int)uVar8) && (*(char *)(extraout_ECX + 0xf8) == '\0')) {
      (**(code **)(**(int **)(extraout_ECX + 0x84) + 0x94))();
    }
    if (*(int *)(extraout_ECX + 0xb0) != 0) {
      FUN_004cfe14(1,0);
    }
    FUN_004ce51f(0);
    FUN_005da4c7(*(undefined4 *)(extraout_ECX + 0x9c));
    *(undefined4 *)(extraout_ECX + 0x9c) = 0;
    if (*(short *)(*(int *)(DAT_006e486c + 0x1c) + 0x50) == 0) {
      FUN_004cebf8(2,0);
      uVar9 = FUN_0046d982();
      FUN_004cefe5(uVar9);
    }
    FUN_004ce51f(1);
    (**(code **)(**(int **)(extraout_ECX + 0x84) + 0xac))();
  } while (uVar8 == 0xfffffffe);
  if (uVar8 == 0xffffffec) {
    FUN_004f5aa0(0);
  }
  if (*(char *)(extraout_ECX + 0x118) != '\0') {
    FUN_004e609e();
    cVar3 = FUN_004e63de();
    if (cVar3 != '\0') {
      *(char *)(extraout_ECX + 0x118) = '\0';
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

