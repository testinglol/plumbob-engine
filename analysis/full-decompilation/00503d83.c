
undefined4 FUN_00503d83(void)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  void *pvVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if (*(int *)(unaff_EBP + 8) != 1) {
    if (*(int *)(unaff_EBP + 8) != 0x13) {
      uVar3 = FUN_005dd97f(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc));
      goto LAB_00504064;
    }
    if ((*(int *)(extraout_ECX + 0xfc) != 0) && (*(int *)(extraout_ECX + 0x100) != 0)) {
      for (piVar6 = (int *)(extraout_ECX + 0xdc);
          (piVar6 != (int *)(extraout_ECX + 0xfc) && (*piVar6 != *(int *)(unaff_EBP + 0xc)));
          piVar6 = piVar6 + 1) {
      }
      FUN_00504075((int)piVar6 + (-0xdc - extraout_ECX) >> 2);
    }
    goto LAB_0050405e;
  }
  piVar6 = (int *)(extraout_ECX + 0xdc);
  for (piVar7 = piVar6;
      (piVar7 != (int *)(extraout_ECX + 0xfc) && (*piVar7 != *(int *)(unaff_EBP + 0xc)));
      piVar7 = piVar7 + 1) {
  }
  iVar4 = (int)piVar7 + (-0xdc - extraout_ECX) >> 2;
  if ((iVar4 < 0) || (7 < iVar4)) {
    uVar3 = 0;
    goto LAB_00504064;
  }
  if (*(char *)(*(int *)(extraout_ECX + 0xfc) + 0xe0) != '\0') {
    FUN_00504075(iVar4);
  }
  if (iVar4 == 0) {
    if (*(int *)(extraout_ECX + 0xe0) != 0) {
      FUN_005e46f0(0);
    }
    if (*(int *)(extraout_ECX + 0xe4) != 0) {
      FUN_005e46f0(0);
    }
    uVar3 = 0;
LAB_00504053:
    FUN_004cfca7(uVar3);
  }
  else {
    if (iVar4 == 1) {
      if (*piVar6 != 0) {
        FUN_005e46f0(0);
      }
      if (*(int *)(extraout_ECX + 0xe4) != 0) {
        FUN_005e46f0(0);
      }
      uVar3 = 1;
      goto LAB_00504053;
    }
    if (iVar4 == 2) {
      if (*piVar6 != 0) {
        FUN_005e46f0(0);
      }
      if (*(int *)(extraout_ECX + 0xe0) != 0) {
        FUN_005e46f0(0);
      }
      uVar3 = 2;
      goto LAB_00504053;
    }
    if (iVar4 == 4) {
      if (DAT_006f2c14 == '\0') {
        DAT_006f2c14 = 1;
        pvVar5 = operator_new(300);
        *(void **)(unaff_EBP + 0xc) = pvVar5;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        if (pvVar5 == (void *)0x0) {
          piVar6 = (int *)0x0;
        }
        else {
          piVar6 = (int *)FUN_0052a597();
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        if (piVar6 != (int *)0x0) {
          cVar2 = (**(code **)(*piVar6 + 0xc))();
          if (cVar2 != '\0') {
            piVar7 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
            iVar8 = (**(code **)(*piVar7 + 8))();
            iVar4 = *(int *)(iVar8 + 0x7c);
            iVar9 = *(int *)(iVar8 + 0x80);
            iVar1 = *(int *)(iVar8 + 0x84);
            *(int *)(unaff_EBP + -0x18) = iVar9;
            *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(iVar8 + 0x88);
            iVar9 = -iVar9;
            *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + iVar9;
            *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + iVar9;
            iVar9 = piVar6[0x20];
            iVar8 = piVar6[0x22];
            *(int *)(unaff_EBP + -0x14) = iVar1 - iVar4;
            FUN_004cb21d(((piVar6[0x1f] - piVar6[0x21]) + *(int *)(unaff_EBP + -0x14)) / 2,
                         (((iVar9 - iVar8) - *(int *)(unaff_EBP + -0x18)) +
                         *(int *)(unaff_EBP + -0x10)) / 2);
            piVar6[0x12] = extraout_ECX;
            uVar3 = 0;
            piVar7 = piVar6;
            (**(code **)(*DAT_006fe8bc + 0x18))(0,piVar6);
            FUN_005daa44(uVar3,piVar7);
            FUN_005da4c7(piVar6);
            FUN_005db1e2();
          }
        }
        DAT_006f2c14 = '\0';
      }
    }
    else {
      if (iVar4 == 5) {
        if (*(int *)(extraout_ECX + 0xf4) != 0) {
          FUN_005e46f0(0);
        }
        if (*(int *)(extraout_ECX + 0xf8) != 0) {
          FUN_005e46f0(0);
        }
        uVar3 = 0;
      }
      else if (iVar4 == 6) {
        if (*(int *)(extraout_ECX + 0xf0) != 0) {
          FUN_005e46f0(0);
        }
        if (*(int *)(extraout_ECX + 0xf8) != 0) {
          FUN_005e46f0(0);
        }
        uVar3 = 1;
      }
      else {
        if (iVar4 != 7) goto LAB_0050405e;
        if (*(int *)(extraout_ECX + 0xf0) != 0) {
          FUN_005e46f0(0);
        }
        if (*(int *)(extraout_ECX + 0xf4) != 0) {
          FUN_005e46f0(0);
        }
        uVar3 = 2;
      }
      FUN_004cfdc9(uVar3);
    }
  }
LAB_0050405e:
  uVar3 = 1;
LAB_00504064:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

