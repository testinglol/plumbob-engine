
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004864ed(void)

{
  int *piVar1;
  int iVar2;
  int unaff_EBP;
  bool bVar3;
  int iVar4;
  
  FUN_00634c24();
  piVar1 = DAT_006fe8bc;
  if (*(int *)(unaff_EBP + 8) == 0) {
    FUN_004d2900(0);
    DAT_006c5e40 = 0xffffffff;
  }
  else {
    iVar2 = unaff_EBP + -0x10;
    iVar4 = unaff_EBP + -0x14;
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    (**(code **)(*piVar1 + 0x18))(iVar4,iVar2);
    FUN_005d9928(iVar4,iVar2);
    DAT_006c5e40 = *(undefined4 *)(unaff_EBP + -0x14);
    *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 0x11;
    _DAT_006c5e44 = *(undefined4 *)(unaff_EBP + -0x10);
    *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + -5;
    FUN_005d4956(s_Can_t_place_here__006c5ea4);
    bVar3 = DAT_006e576c == 0;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (bVar3) {
      FUN_00486fb2();
    }
    if (*(int *)(unaff_EBP + 8) == 0x1a) {
      piVar1 = (int *)(**(code **)(*DAT_006fe8bc + 4))();
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x7c))
                  (*(int *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + 0xc) >> 0x1f,unaff_EBP + -0x20);
      }
    }
    else if (DAT_006e576c != 0) {
      iVar2 = FUN_004705f2(*(undefined4 *)(unaff_EBP + 8),0xffffffff);
      if (iVar2 != 0) {
        FUN_005d4bbf(iVar2);
      }
    }
    FUN_004d28b2(*(undefined4 *)(unaff_EBP + -0x14),*(undefined4 *)(unaff_EBP + -0x10),
                 unaff_EBP + -0x20);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

