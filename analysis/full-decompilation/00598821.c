
int * FUN_00598821(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  piVar1 = *(int **)(unaff_EBP + 8);
  do {
    FUN_00594033(unaff_EBP + -0x41c,0x400,10);
    if (piVar1 == (int *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(*piVar1 + 4) + (int)piVar1;
    }
    if (((*(byte *)(iVar2 + 8) & 6) != 0) || (iVar2 == 0)) goto LAB_00598942;
  } while (*(char *)(unaff_EBP + -0x41c) == '\0');
  FUN_005b870f(unaff_EBP + -0x41c);
  iVar2 = *(int *)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d499c(unaff_EBP + -0x1c);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  FUN_006326ae(unaff_EBP + -0x10);
  if (piVar1 == (int *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(*piVar1 + 4) + (int)piVar1;
  }
  if (((*(byte *)(iVar3 + 8) & 6) == 0) && (iVar3 != 0)) {
    *(undefined4 *)(unaff_EBP + 8) = 0;
    if (0 < *(int *)(unaff_EBP + -0x10)) {
      do {
        pvVar4 = operator_new(0x16c);
        *(void **)(unaff_EBP + 0xc) = pvVar4;
        *(undefined4 *)(unaff_EBP + -4) = 1;
        if (pvVar4 == (void *)0x0) {
          uVar5 = 0;
        }
        else {
          uVar5 = FUN_00598953();
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_00595790(piVar1,uVar5);
        if (piVar1 == (int *)0x0) {
          iVar3 = 0;
        }
        else {
          iVar3 = *(int *)(*piVar1 + 4) + (int)piVar1;
        }
        if (((*(byte *)(iVar3 + 8) & 6) != 0) || (iVar3 == 0)) goto LAB_00598942;
        FUN_0059903f(uVar5);
        *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
      } while (*(int *)(unaff_EBP + 8) < *(int *)(unaff_EBP + -0x10));
    }
    *(int *)(iVar2 + 0xa4) = *(int *)(iVar2 + 0xa4) + 1;
    *(int *)(iVar2 + 0xac) = *(int *)(iVar2 + 0xac) + 1;
    *(int *)(iVar2 + 0xb4) = *(int *)(iVar2 + 0xb4) + 1;
  }
LAB_00598942:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return piVar1;
}

