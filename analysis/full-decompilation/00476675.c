
/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00476675(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int unaff_EBP;
  int iVar6;
  bool bVar7;
  
  FUN_00634c24();
  iVar2 = FUN_00444bf6();
  iVar3 = DAT_006fe954;
  uVar5 = 0;
  *(int *)(unaff_EBP + -0x14) = iVar2;
  if ((iVar3 != 0) && (iVar3 = *(int *)(iVar3 + 0xd8), iVar3 != 0)) {
    uVar5 = *(undefined4 *)(iVar3 + 0x30);
  }
  FUN_0046dae0(0xc,uVar5);
  iVar3 = _DAT_006c4da8;
  if (iVar2 == 0) goto LAB_004769c8;
  cVar1 = FUN_00452c2d(*(undefined4 *)(*(int *)(iVar2 + 0x11c) + 0xc),0,s_query_wait_event_006c4df0,
                       0);
  iVar4 = DAT_006fe954;
  if (cVar1 == '\0') goto LAB_004769c1;
  iVar6 = (int)*(short *)(iVar2 + 0x3a);
  iVar2 = (int)*(short *)(iVar2 + 0x3c);
  bVar7 = false;
  iVar3 = _DAT_006c4da8;
  switch(iVar6) {
  case 1:
    if (*(int *)(DAT_006f2a08 + 0xb0) == 0) goto LAB_004769c8;
    iVar3 = FUN_004cfe0d();
    break;
  case 2:
  case 9:
  case 0xb:
  case 0xd:
  case 0xf:
    if (((DAT_006f3adc == 0) || (iVar3 = *(int *)(DAT_006f3adc + 0x158), iVar3 == 0)) ||
       (*(char *)(iVar3 + 0xe0) == '\0')) {
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
    }
    else {
      *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(iVar3 + 0x10c);
    }
    iVar3 = _DAT_006c4da8;
    if (*(int *)(unaff_EBP + -0x10) == 0) goto LAB_004769c8;
    FUN_0046f824(unaff_EBP + -0x1c,0,8);
    *(undefined ***)(unaff_EBP + -0x28) = &PTR_FUN_00666644;
    if (iVar6 == 2) {
      FUN_0046f824(unaff_EBP + -0x80,0,8);
      *(undefined ***)(unaff_EBP + -0x8c) = &PTR_FUN_00666644;
      FUN_0046f847(s_motives_006c4dd8,0xffffffff);
      iVar3 = unaff_EBP + -0x8c;
code_r0x00476868:
      FUN_0046f8e4(iVar3);
    }
    else {
      if (iVar6 == 9) {
        FUN_0046f824(unaff_EBP + -0x6c,0,8);
        *(undefined ***)(unaff_EBP + -0x78) = &PTR_FUN_00666644;
        FUN_0046f847(&PTR_s_ndex_006c6568_0xa_006c2994,0xffffffff);
        iVar3 = unaff_EBP + -0x78;
        goto code_r0x00476868;
      }
      if (iVar6 == 0xb) {
        FUN_0046f824(unaff_EBP + -0x58,0,8);
        *(undefined ***)(unaff_EBP + -100) = &PTR_FUN_00666644;
        FUN_0046f847(&PTR_LAB_006c2990,0xffffffff);
        iVar3 = unaff_EBP + -100;
        goto code_r0x00476868;
      }
      if (iVar6 == 0xd) {
        FUN_0046f824(unaff_EBP + -0x44,0,8);
        *(undefined ***)(unaff_EBP + -0x50) = &PTR_FUN_00666644;
        FUN_0046f847(s_skill_006c4de0,0xffffffff);
        iVar3 = unaff_EBP + -0x50;
        goto code_r0x00476868;
      }
      if (iVar6 == 0xf) {
        FUN_0046f824(unaff_EBP + -0x30,0,8);
        *(undefined ***)(unaff_EBP + -0x3c) = &PTR_FUN_00666644;
        FUN_0046f847(s_per_ity_006c4de8,0xffffffff);
        iVar3 = unaff_EBP + -0x3c;
        goto code_r0x00476868;
      }
    }
    iVar3 = FUN_0046f93d(unaff_EBP + -0x28);
    break;
  default:
    goto LAB_004769c8;
  case 4:
    if ((DAT_006fe954 == 0) || (*(int *)(DAT_006fe954 + 0xd8) == 0)) goto LAB_004769c8;
    bVar7 = *(int *)(*(int *)(DAT_006fe954 + 0xd8) + 0x30) == iVar2;
    goto code_r0x004768d1;
  case 5:
    if ((DAT_006fe954 == 0) || (iVar2 = FUN_0042573e(iVar2), iVar3 = _DAT_006c4da8, iVar2 == 0))
    goto LAB_004769c8;
    uVar5 = FUN_00401f73();
    uVar5 = FUN_004e988f(uVar5);
    FUN_005c1719();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    cVar1 = FUN_004e93e4(uVar5,unaff_EBP + -0x10);
    if ((cVar1 != '\0') && (iVar3 = *(int *)(iVar4 + 0xd8), iVar2 = FUN_004096c2(), iVar2 == iVar3))
    {
      bVar7 = true;
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005a5e09();
    goto code_r0x004769a3;
  case 6:
    iVar3 = *(int *)(DAT_006e54d8 + 0x84);
    goto code_r0x00476961;
  case 7:
    iVar3 = _DAT_006e54a8;
code_r0x00476961:
    if (_DAT_006c4da8 == -1) goto LAB_004769c8;
    bVar7 = _DAT_006c4da8 == iVar3;
    goto code_r0x004769a5;
  case 8:
    uVar5 = FUN_00476603(iVar2);
    iVar4 = FUN_00476615(uVar5);
    iVar3 = _DAT_006c4da8;
    if (((iVar4 == 0) || (*(int *)(iVar4 + 0xd8) == 0)) ||
       ((*(int *)(*(int *)(iVar4 + 0xd8) + 0x30) != iVar2 || (*(int *)(iVar4 + 0xe0) == 0))))
    goto LAB_004769c8;
    bVar7 = true;
code_r0x004769a3:
    bVar7 = !bVar7;
code_r0x004769a5:
    iVar3 = _DAT_006c4da8;
    if (bVar7) goto LAB_004769c8;
    goto code_r0x004769a7;
  case 0xe:
    if (((DAT_006f3adc == 0) || (iVar3 = *(int *)(DAT_006f3adc + 0x158), iVar3 == 0)) ||
       (*(char *)(iVar3 + 0xe0) == '\0')) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(iVar3 + 0x10c);
    }
  }
  bVar7 = iVar3 == 0;
code_r0x004768d1:
  iVar3 = _DAT_006c4da8;
  if (bVar7) {
code_r0x004769a7:
    FUN_00452c2d(*(undefined4 *)(*(int *)(*(int *)(unaff_EBP + -0x14) + 0x11c) + 0xc),0,
                 s_got_wait_event_006c4dc8,0);
LAB_004769c1:
    _DAT_006c4da8 = -1;
    iVar3 = _DAT_006c4da8;
  }
LAB_004769c8:
  _DAT_006c4da8 = iVar3;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

