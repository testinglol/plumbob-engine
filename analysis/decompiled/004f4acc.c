
undefined4 FUN_004f4acc(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  void *pvVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_004ff6fa(0x6d61696e,s_Adding_main_window_006cb064);
  if (*(int *)(extraout_ECX + 0x84) == 0) {
    pvVar4 = operator_new(0x11d8);
    *(void **)(unaff_EBP + -0x14) = pvVar4;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar4 == (void *)0x0) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = (int *)FUN_004d0023(extraout_ECX,*(undefined4 *)(extraout_ECX + 0xb0));
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(int **)(extraout_ECX + 0x84) = piVar5;
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 0x90))(0x20000,1);
      iVar6 = *(int *)(extraout_ECX + 0x80);
      (**(code **)(**(int **)(extraout_ECX + 0x84) + 0x60))
                (*(undefined4 *)(iVar6 + 0x7c),*(undefined4 *)(iVar6 + 0x80),
                 *(undefined4 *)(iVar6 + 0x84),*(undefined4 *)(iVar6 + 0x88));
      (**(code **)(**(int **)(extraout_ECX + 0x84) + 0x98))();
      (**(code **)(**(int **)(extraout_ECX + 0x80) + 0x20))(*(undefined4 *)(extraout_ECX + 0x84));
      *(undefined4 *)(DAT_006e486c + 0x40) = *(undefined4 *)(extraout_ECX + 0x84);
    }
  }
  FUN_004ff6fa(0x63706e6c,s_Adding_control_panel_006cb04c);
  uVar3 = DAT_006d7440;
  if (*(int *)(extraout_ECX + 0x88) == 0) {
    *(uint *)(unaff_EBP + -0x10) = DAT_006d7440;
    DAT_006d7440 = DAT_006d7440 | 0x20000;
    pvVar4 = operator_new(0x110);
    *(void **)(unaff_EBP + -0x14) = pvVar4;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    if (pvVar4 == (void *)0x0) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = (int *)FUN_00509a74(*(undefined4 *)(extraout_ECX + 0xb0));
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(int **)(extraout_ECX + 0x88) = piVar5;
    if (piVar5 != (int *)0x0) {
      iVar6 = *(int *)(extraout_ECX + 0x84);
      uVar7 = *(undefined4 *)(iVar6 + 0x7c);
      uVar1 = *(undefined4 *)(iVar6 + 0x84);
      iVar6 = *(int *)(iVar6 + 0x88);
      *(int *)(unaff_EBP + -0x2c) = iVar6 + -0x96;
      (**(code **)(*piVar5 + 0x60))(uVar7,*(undefined4 *)(unaff_EBP + -0x2c),uVar1,iVar6);
      (**(code **)(**(int **)(extraout_ECX + 0x84) + 0x20))(*(undefined4 *)(extraout_ECX + 0x88));
      FUN_0050a2a2();
      uVar3 = *(uint *)(unaff_EBP + -0x10);
    }
  }
  DAT_006d7440 = uVar3;
  if (*(int *)(extraout_ECX + 0xb0) != 0) {
    FUN_004cfe14(1,1);
  }
  iVar6 = *(int *)(extraout_ECX + 0x84);
  if (*(int *)(iVar6 + 0x11ac) != 0) {
    iVar2 = *(int *)(iVar6 + 0x84);
    *(int *)(unaff_EBP + -0x1c) = *(int *)(iVar6 + 0x80) + 1;
    *(int *)(unaff_EBP + -0x20) = iVar2 + -1;
    FUN_004ffa2d(unaff_EBP + -0x20);
  }
  piVar5 = (int *)(**(code **)(*DAT_006fe8bc + 4))();
  iVar6 = (**(code **)(*piVar5 + 0x1c))();
  *(int *)(unaff_EBP + -0x10) = iVar6;
  if ((((iVar6 == 0xf) || (iVar6 == 0x11)) || (iVar6 == 0x12)) || (iVar6 == 0x14)) {
    piVar5 = (int *)FUN_005e7743();
    piVar5 = (int *)(**(code **)(*piVar5 + 8))(0);
    iVar6 = (**(code **)(*piVar5 + 0x58))();
    *(int *)(unaff_EBP + -0x14) = iVar6;
    piVar5 = operator_new(0x1914);
    *(int **)(unaff_EBP + -0x18) = piVar5;
    *(undefined4 *)(unaff_EBP + -4) = 2;
    if (piVar5 == (int *)0x0) {
      piVar5 = (int *)0x0;
    }
    else {
      FUN_005e9913();
      piVar5[0x644] = 0;
      *piVar5 = (int)&PTR_FUN_00669910;
      piVar5[0x35] = (int)&PTR_FUN_006698e8;
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    DAT_006feca8 = piVar5;
    piVar5 = (int *)FUN_005e7743();
    iVar2 = DAT_006feca8[0x35];
    uVar7 = (**(code **)(*piVar5 + 8))(0);
    (**(code **)(iVar2 + 0x18))(uVar7);
    (**(code **)(*DAT_006feca8 + 0x60))(0x14,0x14,0x1a4,iVar6 + 0x1a);
    (**(code **)(DAT_006feca8[0x35] + 0x20))(4,4);
    FUN_005ddfdc(1);
    (**(code **)(*DAT_006feca8 + 0x98))();
    (**(code **)(**(int **)(extraout_ECX + 0x80) + 0x20))(DAT_006feca8);
    (**(code **)(*DAT_006feca8 + 0x44))();
    pvVar4 = operator_new(0x118);
    *(void **)(unaff_EBP + -0x18) = pvVar4;
    *(undefined4 *)(unaff_EBP + -4) = 3;
    if (pvVar4 == (void *)0x0) {
      DAT_006fecac = (int *)0x0;
    }
    else {
      DAT_006fecac = (int *)FUN_004f4e92();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    piVar5 = (int *)FUN_005e7743();
    iVar2 = DAT_006fecac[0x35];
    uVar7 = (**(code **)(*piVar5 + 8))(0);
    (**(code **)(iVar2 + 0x18))(uVar7);
    (**(code **)(*DAT_006fecac + 0x60))
              (0x14,iVar6 + 0x1e,0xdc,iVar6 + 0x36 + *(int *)(unaff_EBP + -0x14) * 10);
    (**(code **)(DAT_006fecac[0x35] + 0x20))(4,4);
    FUN_005ddfdc(1);
    (**(code **)(*DAT_006fecac + 0x98))();
    if ((0x10 < *(int *)(unaff_EBP + -0x10)) && (*(int *)(unaff_EBP + -0x10) < 0x13)) {
      *(undefined1 *)(DAT_006fecac + 0x45) = 1;
    }
    (**(code **)(**(int **)(extraout_ECX + 0x80) + 0x20))(DAT_006fecac);
    (**(code **)(*DAT_006fecac + 0x44))();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

