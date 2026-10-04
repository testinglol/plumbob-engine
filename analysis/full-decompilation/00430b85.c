
void FUN_00430b85(void)

{
  int *piVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  int unaff_EBP;
  int *piVar5;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  piVar1 = *(int **)(unaff_EBP + 8);
  iVar4 = piVar1[1];
  iVar2 = *piVar1;
  *(int *)(unaff_EBP + 8) = iVar4 - iVar2 >> 2;
  FUN_00464a5e(unaff_EBP + 8,1);
  if ((uint)(iVar4 - iVar2 >> 2) < *(uint *)(unaff_EBP + 8)) {
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    FUN_00430db9(iVar4,*(uint *)(unaff_EBP + 8) - (iVar4 - iVar2 >> 2),unaff_EBP + -0x14);
  }
  while (iVar4 = piVar1[1], *(uint *)(unaff_EBP + 8) < (uint)(iVar4 - *piVar1 >> 2)) {
    iVar2 = *(int *)(iVar4 + -4);
    if (iVar2 != 0) {
      FUN_00423852();
      FUN_006321f0(iVar2);
    }
    FUN_0042ed71(iVar4 + -4,iVar4);
  }
  piVar5 = (int *)*piVar1;
  piVar1 = (int *)piVar1[1];
  do {
    if (piVar5 == piVar1) {
      *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
      return;
    }
    iVar4 = *piVar5;
    *(uint *)(unaff_EBP + -0x10) = (uint)(iVar4 != 0);
    FUN_00464a4e(unaff_EBP + -0x10,1);
    if (*(int *)(unaff_EBP + -0x10) == 0) {
      if (iVar4 != 0) {
        FUN_00423852();
        FUN_006321f0(iVar4);
        *piVar5 = 0;
        goto LAB_00430c7d;
      }
    }
    else {
      if (iVar4 == 0) {
        pvVar3 = operator_new(0x274);
        *(void **)(unaff_EBP + -0x14) = pvVar3;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        if (pvVar3 == (void *)0x0) {
          iVar4 = 0;
        }
        else {
          iVar4 = FUN_00423769();
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        *piVar5 = iVar4;
LAB_00430c7d:
        if (*(int *)(unaff_EBP + -0x10) == 0) goto LAB_00430c90;
      }
      FUN_00423e3b(*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x10));
    }
LAB_00430c90:
    piVar5 = piVar5 + 1;
  } while( true );
}

