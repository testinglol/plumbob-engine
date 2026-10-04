
int * FUN_00607dbc(void)

{
  undefined4 *puVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  size_t sVar6;
  void *pvVar7;
  int extraout_ECX;
  int unaff_EBP;
  char *pcVar8;
  int *piVar9;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x18) = extraout_ECX;
  if ((*(int *)(unaff_EBP + 0x14) == 0) &&
     (piVar5 = (int *)**(int **)(extraout_ECX + 0xc), piVar5 != *(int **)(extraout_ECX + 0xc))) {
    do {
      piVar9 = (int *)piVar5[2];
      iVar4 = (**(code **)(*piVar9 + 0x14))();
      if (iVar4 == *(int *)(unaff_EBP + 8)) {
        iVar4 = (**(code **)(*piVar9 + 0x18))();
        if (iVar4 == *(int *)(unaff_EBP + 0xc)) {
          iVar4 = (**(code **)(*piVar9 + 0x24))();
          if (iVar4 == *(int *)(unaff_EBP + 0x10)) {
            (**(code **)*piVar9)();
            goto LAB_006080e4;
          }
        }
      }
      piVar5 = (int *)*piVar5;
    } while (piVar5 != (int *)*(int *)(*(int *)(unaff_EBP + -0x18) + 0xc));
  }
  puVar1 = (undefined4 *)(*(int *)(unaff_EBP + -0x18) + 0x20);
  FUN_005b86bd(puVar1);
  iVar4 = *(int *)(unaff_EBP + 0x14);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (iVar4 == 0) {
    piVar5 = (int *)(**(code **)(*DAT_006fe8bc + 4))();
    iVar4 = (**(code **)(*piVar5 + 0x1c))();
  }
  if ((((iVar4 == 0xf) || (iVar4 == 0x11)) || (iVar4 == 0x12)) ||
     ((iVar4 == 0x14 || (iVar4 == 0x13)))) {
    if (iVar4 != 0xf) {
      if (iVar4 == 0x11) {
        pcVar8 = s_font16gb_fon_006d9568;
        goto LAB_00608023;
      }
      if (iVar4 == 0x12) {
        pcVar8 = s_font16b5_fon_006d9578;
        goto LAB_00608023;
      }
      if (iVar4 == 0x13) {
        sVar6 = _strlen(s_font20th_fon_006d9588);
        FUN_00412d8a(s_font20th_fon_006d9588,s_font20th_fon_006d9588 + sVar6);
        iVar4 = *(int *)(unaff_EBP + -0x18);
        if (*(char *)(iVar4 + 0x2c) == '\0') {
          FUN_00608e7b(*puVar1,0x13);
          *(undefined1 *)(iVar4 + 0x2c) = 1;
        }
        pvVar7 = operator_new(0x28);
        *(void **)(unaff_EBP + 0xc) = pvVar7;
        *(undefined1 *)(unaff_EBP + -4) = 1;
        if (pvVar7 != (void *)0x0) {
          piVar5 = (int *)FUN_0060a5a2(unaff_EBP + -0x28);
          goto LAB_00608072;
        }
        goto LAB_00608070;
      }
      if (iVar4 == 0x14) {
        if (*(uint *)(unaff_EBP + 0xc) < 0x10) {
          pcVar8 = s_FONT12K_FON_006d95a4;
        }
        else {
          pcVar8 = s_FONT16K_FON_006d9598;
        }
        goto LAB_00608023;
      }
      goto LAB_00607f58;
    }
    pcVar8 = s_FONT12J_FON_006d955c;
    if (0xf < *(uint *)(unaff_EBP + 0xc)) {
      pcVar8 = s_FONT16J_FON_006d9550;
    }
LAB_00608023:
    sVar6 = _strlen(pcVar8);
    FUN_00412d8a(pcVar8,pcVar8 + sVar6);
    iVar2 = *(int *)(unaff_EBP + -0x18);
    if (*(char *)(iVar2 + 0x2d) == '\0') {
      FUN_0060858c(*puVar1,iVar4);
      *(undefined1 *)(iVar2 + 0x2d) = 1;
    }
    pvVar7 = operator_new(0x28);
    *(void **)(unaff_EBP + 0xc) = pvVar7;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    if (pvVar7 != (void *)0x0) {
      piVar5 = (int *)FUN_006098ed(unaff_EBP + -0x28,1);
      goto LAB_00608072;
    }
  }
  else {
    if (iVar4 == 0xd) {
      pcVar8 = s_Russian__006d95d8;
LAB_00607e8b:
      sVar6 = _strlen(pcVar8);
      FUN_00412d8a(pcVar8,pcVar8 + sVar6);
    }
    else if (iVar4 == 0x10) {
      pcVar8 = s_Polish__006d95d0;
      goto LAB_00607e8b;
    }
    sVar6 = _strlen(s_VariableSans__006d95c0);
    FUN_00412d8a(s_VariableSans__006d95c0,s_VariableSans__006d95c0 + sVar6);
    wsprintfA((LPSTR)(unaff_EBP + -0x10),&DAT_006d95b8,*(undefined4 *)(unaff_EBP + 0xc));
    sVar6 = _strlen((char *)(unaff_EBP + -0x10));
    FUN_00412d8a(unaff_EBP + -0x10,unaff_EBP + -0x10 + sVar6);
    *(undefined1 *)(unaff_EBP + -0x10) = 0;
    if ((*(byte *)(unaff_EBP + 0x10) & 1) != 0) {
      FUN_006358c0(unaff_EBP + -0x10,&DAT_006c0fac);
    }
    sVar6 = _strlen((char *)(unaff_EBP + -0x10));
    if (sVar6 != 0) {
      sVar6 = _strlen(&DAT_006c111c);
      FUN_00412d8a(&DAT_006c111c,&DAT_006c111c + sVar6);
      sVar6 = _strlen((char *)(unaff_EBP + -0x10));
      FUN_00412d8a(unaff_EBP + -0x10,unaff_EBP + -0x10 + sVar6);
    }
    sVar6 = _strlen(&DAT_006d95b0);
    FUN_00412d8a(&DAT_006d95b0,&DAT_006d95b0 + sVar6);
LAB_00607f58:
    pvVar7 = operator_new(0x44);
    *(void **)(unaff_EBP + -0x1c) = pvVar7;
    *(undefined1 *)(unaff_EBP + -4) = 3;
    if (pvVar7 != (void *)0x0) {
      piVar5 = (int *)FUN_0060afe9(unaff_EBP + -0x28,*(undefined4 *)(unaff_EBP + 8),
                                   *(undefined4 *)(unaff_EBP + 0xc),
                                   *(undefined4 *)(unaff_EBP + 0x10));
      goto LAB_00608072;
    }
  }
LAB_00608070:
  piVar5 = (int *)0x0;
LAB_00608072:
  *(undefined1 *)(unaff_EBP + -4) = 0;
  piVar9 = (int *)0x0;
  *(int **)(unaff_EBP + -0x14) = piVar5;
  if (piVar5 != (int *)0x0) {
    (**(code **)(*piVar5 + 0x20))(0xffff);
  }
  cVar3 = (**(code **)(**(int **)(unaff_EBP + -0x14) + 0xc))();
  if (cVar3 == '\0') {
    if (*(int **)(unaff_EBP + -0x14) != (int *)0x0) {
      (**(code **)(**(int **)(unaff_EBP + -0x14) + 8))(1);
    }
  }
  else {
    if (*(int *)(unaff_EBP + 0x14) == 0) {
      FUN_00580875(unaff_EBP + -0x14);
    }
    (**(code **)**(undefined4 **)(unaff_EBP + -0x14))();
    if ((*(byte *)(unaff_EBP + 0x10) & 0x10) != 0) {
      (**(code **)(**(int **)(unaff_EBP + -0x14) + 0x2c))(0x10,1);
    }
    piVar9 = *(int **)(unaff_EBP + -0x14);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
LAB_006080e4:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return piVar9;
}

