
int FUN_00425316(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int extraout_ECX;
  int unaff_EBP;
  int *piVar5;
  undefined4 uVar6;
  
  FUN_00634c24();
  FUN_0046f824(unaff_EBP + -0x124,0,0x104);
  *(undefined ***)(unaff_EBP + -0x130) = &PTR_FUN_006664e8;
  FUN_00412122(extraout_ECX,unaff_EBP + -0x130);
  FUN_0046f847(s_NTemp_iff_006c25f8,0xffffffff);
  iVar4 = *(int *)(*DAT_006e486c + 0x20);
  FUN_0046f5cd();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar2 = FUN_00465a37(unaff_EBP + -0x130,1);
  if (iVar2 == 0) {
    if (*(short *)(iVar4 + 0x44) != 0) {
      *(undefined2 *)(extraout_ECX + 300) = *(undefined2 *)(extraout_ECX + 0x164);
    }
    FUN_00430291(extraout_ECX,0x4e474248);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    iVar2 = FUN_00464eab(unaff_EBP + -0x20,*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x374,1);
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_00465055();
    *(int *)(unaff_EBP + -0x10) = iVar2;
    if (iVar2 == 0) {
      *(int *)(unaff_EBP + -0x1c) = extraout_ECX + 0x148;
      *(undefined4 *)(unaff_EBP + -0x18) = 0x4e425253;
      uVar3 = FUN_0043079c(unaff_EBP + -0x1c,unaff_EBP + -0x374,0x4e425253,1,
                           *(undefined4 *)(unaff_EBP + 8));
      *(undefined4 *)(unaff_EBP + -0x10) = uVar3;
    }
    for (piVar5 = *(int **)(extraout_ECX + 0x154); piVar5 != *(int **)(extraout_ECX + 0x158);
        piVar5 = piVar5 + 1) {
      if ((*(int *)(*piVar5 + 0x110) != 0) &&
         (*(int *)(*piVar5 + 0x110) == *(int *)(extraout_ECX + 0x164))) {
        *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(iVar4 + 0xa4);
        iVar2 = __ftol();
        *(int *)(*piVar5 + 0x11c) = iVar2 + *(int *)(iVar4 + 0x9c) + *(int *)(iVar4 + 0xa0);
      }
      if (*(char *)(*piVar5 + 0x124) != '\0') {
        FUN_00427c21(*piVar5);
      }
      FUN_00410729(unaff_EBP + -0x374,*(undefined4 *)(unaff_EBP + 8));
    }
    FUN_0043e1a3(unaff_EBP + -0x374);
    FUN_0046b7ee();
    if (*(int *)(unaff_EBP + -0x10) == 0) {
      iVar4 = FUN_0046b546(extraout_ECX);
      *(int *)(unaff_EBP + -0x10) = iVar4;
      if ((iVar4 == 0) || (iVar4 == -0x28)) {
        uVar3 = *(undefined4 *)(extraout_ECX + 4);
        uVar6 = *(undefined4 *)(unaff_EBP + -300);
        FUN_005b8e25(uVar6,uVar3);
        cVar1 = FUN_005b9849(uVar6,uVar3);
        if (cVar1 == '\0') {
          iVar2 = -1;
          goto LAB_0042550f;
        }
      }
    }
    else {
      FUN_0046b546(unaff_EBP + -0x130);
    }
    iVar2 = *(int *)(unaff_EBP + -0x10);
  }
LAB_0042550f:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0046b2e6();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar2;
}

