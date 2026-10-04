
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00579a41(void)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar4 = extraout_ECX[2];
  if (iVar4 != 1) {
    if (iVar4 == 2) {
      iVar4 = *(int *)(unaff_EBP + 0xc);
      if (((iVar4 == *(int *)(*(int *)(*extraout_ECX + 0x34) + 0x30)) &&
          (*(char *)(extraout_ECX[3] + 0xc) != '\0')) && ((char)extraout_ECX[5] == '\0')) {
        FUN_00577422();
        *(undefined1 *)(extraout_ECX + 5) = 1;
      }
      if ((iVar4 != 1) ||
         ((iVar4 = extraout_ECX[3], *(char *)(iVar4 + 0xc) != '\0' &&
          (*(char *)(unaff_EBP + 8) != '\0')))) goto LAB_00579d97;
      extraout_ECX[2] = 4;
      if (((*(int *)(iVar4 + 0x40) != 0) || (*(int *)(iVar4 + 0x44) != 0)) &&
         (*(int *)(iVar4 + 0x40) <= *(int *)(iVar4 + 0x44))) {
        _rand();
        *(undefined4 *)(unaff_EBP + 8) = *(undefined4 *)(extraout_ECX[3] + 0x40);
        uVar3 = (**(code **)(*(int *)extraout_ECX[1] + 0x88))();
        *(undefined4 *)(unaff_EBP + 8) = uVar3;
        iVar4 = *(int *)extraout_ECX[1];
        uVar3 = __ftol();
        (**(code **)(iVar4 + 0x8c))(uVar3);
      }
      iVar4 = (*(int *)(extraout_ECX[3] + 0x10) * *(int *)(*extraout_ECX + 0x28)) / 0x400;
      cVar2 = *(char *)(extraout_ECX[3] + 0x1c);
      *(int *)(unaff_EBP + 8) = iVar4;
      if ((cVar2 != '\0') && (3 < iVar4)) {
        iVar4 = _rand();
        *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) - iVar4 % (*(int *)(unaff_EBP + 8) / 3);
      }
      if (*(int *)(extraout_ECX[3] + 0x20) == 0) {
        FUN_00579f5b(*(undefined4 *)(extraout_ECX[3] + 0x10));
      }
      else {
        (**(code **)(*(int *)extraout_ECX[1] + 0x78))(0);
      }
      iVar4 = *(int *)extraout_ECX[1];
      uVar3 = (**(code **)(iVar4 + 0x74))
                        (CONCAT31((int3)((uint)extraout_ECX[3] >> 8),
                                  *(undefined1 *)(extraout_ECX[3] + 0x3c)),1);
      (**(code **)(iVar4 + 0x20))(uVar3);
      if (*(int *)(*extraout_ECX + 0x2c) != 0) {
        (**(code **)(*(int *)extraout_ECX[1] + 0x9c))(*(int *)(*extraout_ECX + 0x2c));
      }
      FUN_00579f97();
      if (*(int *)(extraout_ECX[3] + 0x20) != 0) {
        (**(code **)(*(int *)extraout_ECX[1] + 0x7c))(*(undefined4 *)(unaff_EBP + 8),0,2000,1,0);
      }
    }
    else {
      if (iVar4 == 3) {
        extraout_ECX[2] = 2;
        goto LAB_00579d97;
      }
      if (iVar4 != 4) {
        if ((iVar4 == 5) && (cVar2 = (**(code **)(*(int *)extraout_ECX[1] + 0x24))(), cVar2 == '\0')
           ) {
          FUN_00579ea3();
          extraout_ECX[2] = 0;
        }
        goto LAB_00579d97;
      }
      iVar4 = extraout_ECX[3];
      if (*(char *)(iVar4 + 0x3c) == '\0') {
        cVar2 = (**(code **)(*(int *)extraout_ECX[1] + 0x24))();
        if (cVar2 == '\0') {
          FUN_00579e40();
          extraout_ECX[2] = 0;
        }
        goto LAB_00579d97;
      }
      extraout_ECX[4] = extraout_ECX[4] + -1;
      iVar1 = extraout_ECX[4];
      if (*(char *)((int)extraout_ECX + 0x15) != '\0') {
        if (iVar1 == 0) goto LAB_00579d97;
        if ((*(char *)(iVar4 + 0xc) == '\0') || (*(char *)(unaff_EBP + 8) == '\0')) {
          FUN_00579ea3();
          goto LAB_00579d97;
        }
      }
      if (iVar1 == 1) {
        if ((*(char *)(iVar4 + 0xc) != '\0') && ((char)extraout_ECX[5] == '\0')) {
          FUN_00577422();
          *(undefined1 *)(extraout_ECX + 5) = 1;
        }
        goto LAB_00579d97;
      }
      if ((iVar1 != 0) ||
         (cVar2 = *(char *)(unaff_EBP + 8), extraout_ECX[4] = *(int *)(iVar4 + 0x34), cVar2 != '\0')
         ) goto LAB_00579d97;
    }
    if ((char)extraout_ECX[5] != '\0') {
      FUN_00577447();
      *(undefined1 *)(extraout_ECX + 5) = 0;
    }
    goto LAB_00579d97;
  }
  uVar3 = FUN_00412ab1(unaff_EBP + -0x24,*extraout_ECX + 0x4094,extraout_ECX[3]);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b86bd(uVar3);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_00401729();
  piVar5 = *(int **)(*extraout_ECX + 0x38);
  if (piVar5 == (int *)0x0) {
LAB_00579d2b:
    piVar5 = (int *)(**(code **)(*DAT_006fecc4 + 0x70))(unaff_EBP + -0x18,0,1);
    extraout_ECX[1] = (int)piVar5;
    cVar2 = (**(code **)(*piVar5 + 0x60))();
    if (cVar2 == '\0') {
      FUN_00579ea3();
    }
    else {
      (**(code **)(*(int *)extraout_ECX[1] + 0xec))(_DAT_0066674c);
      (**(code **)(*(int *)extraout_ECX[1] + 0xf4))(_DAT_00671738);
      _DAT_006f6428 = _DAT_006f6428 + 1;
      extraout_ECX[2] = 2;
    }
  }
  else {
    cVar2 = (**(code **)(*piVar5 + 0x28))(unaff_EBP + -0x18);
    if (cVar2 != '\0') {
      uVar3 = (**(code **)(*piVar5 + 0x20))(unaff_EBP + -0x30,unaff_EBP + -0x18);
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_005d499c(uVar3);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_005b8770();
      goto LAB_00579d2b;
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
LAB_00579d97:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

