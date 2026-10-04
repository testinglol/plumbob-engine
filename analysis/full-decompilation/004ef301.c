
undefined4 FUN_004ef301(void)

{
  char cVar1;
  undefined1 uVar2;
  HWND pHVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  char *pcVar8;
  char cVar9;
  HWND unaff_EBX;
  int unaff_EBP;
  int *unaff_ESI;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  cVar1 = FUN_005d6516(s_debug_objects_006ca810,unaff_EBX,1);
  if (cVar1 != '\0') {
    DAT_006c2973 = 1;
  }
  cVar1 = FUN_005d6516(s_rebuild_catalog_006ca800,unaff_EBX,1);
  cVar9 = (char)unaff_EBX;
  if (cVar1 != '\0') {
    DAT_006f29ec = 1;
    DAT_006c9f58 = cVar9;
  }
  cVar1 = FUN_005d6516(s_non_us_locale_006ca7f0,unaff_EBX,1);
  if (cVar1 == '\0') {
    pHVar3 = (HWND)FUN_00637627();
    if (pHVar3 == unaff_EBX) {
      MessageBoxA(unaff_EBX,s_Set_locale_returned_NULL_006ca7bc,s_Locale_Error_006ca7d8,
                  (UINT)unaff_EBX);
    }
  }
  cVar1 = FUN_005d6516(s_show_init_progress_006ca7a8,unaff_EBX,1);
  if (cVar1 == '\0') {
    pHVar3 = operator_new(0x6c);
    *(HWND *)(unaff_EBP + -0x18) = pHVar3;
    *(undefined4 *)(unaff_EBP + -4) = 2;
    if (pHVar3 == unaff_EBX) {
      pHVar3 = (HWND)0x0;
    }
    else {
      FUN_0046fca5();
      pHVar3->unused = (int)&PTR_FUN_0066643c;
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    unaff_ESI[0x45] = (int)pHVar3;
    uVar4 = FUN_0041532c(9,pHVar3);
    FUN_004fff98(0x9b,uVar4);
  }
  FUN_004ff6fa(0x73746170,s_Starting_App_init_006ca794);
  cVar1 = FUN_005d6516(s_soundguys_006ca788,unaff_EBX,1);
  if (cVar1 != '\0') {
    DAT_006e50e4 = 1;
  }
  cVar1 = FUN_005d6516(s_dumpassets_006ca77c,unaff_EBX,1);
  if (cVar1 != '\0') {
    DAT_006f29f4 = 1;
  }
  cVar1 = FUN_005d6516(s_reportassets_006ca76c,unaff_EBX,1);
  if (cVar1 != '\0') {
    DAT_006f29f5 = 1;
  }
  if (DAT_006fe8cc != unaff_EBX) {
    FUN_0047d9ea(DAT_006fe8cc);
  }
  piVar5 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
  iVar6 = (**(code **)(*piVar5 + 8))();
  unaff_ESI[0x20] = iVar6;
  piVar5 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
  iVar6 = (**(code **)(*piVar5 + 0x24))();
  if (*(char *)(iVar6 + 0x75) != cVar9) {
    (**(code **)(*(int *)unaff_ESI[0x20] + 0x174))(1);
  }
  (**(code **)(*(int *)unaff_ESI[0x20] + 0x9c))(&DAT_006f2930);
  pHVar3 = operator_new(0x14);
  *(HWND *)(unaff_EBP + -0x18) = pHVar3;
  *(undefined4 *)(unaff_EBP + -4) = 3;
  if (pHVar3 == unaff_EBX) {
    pHVar3 = (HWND)0x0;
  }
  else {
    pHVar3 = (HWND)FUN_005a3d9e();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  unaff_ESI[0x23] = (int)pHVar3;
  if (pHVar3 == unaff_EBX) {
    uVar4 = 0;
  }
  else {
    FUN_004ff6fa(0x72656772,s_Registering_resources_006ca754);
    FUN_004f2c6e();
    pHVar3 = operator_new(0x450);
    *(HWND *)(unaff_EBP + -0x18) = pHVar3;
    *(undefined4 *)(unaff_EBP + -4) = 4;
    if (pHVar3 == unaff_EBX) {
      iVar6 = 0;
    }
    else {
      iVar6 = FUN_004ce248(unaff_ESI);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    unaff_ESI[0x2c] = iVar6;
    FUN_004ff6fa(0x6374726c,s_Setting_up_controls_006ca740);
    FUN_0046f824(unaff_EBP + -0x19c,unaff_EBX,0x104);
    *(undefined ***)(unaff_EBP + -0x1a8) = &PTR_FUN_006664e8;
    uVar4 = FUN_0041532c(0x11);
    FUN_004ee9ce(uVar4);
    uVar4 = FUN_005d4956(*(undefined4 *)(unaff_EBP + -0x1a4));
    piVar5 = DAT_006fe8bc;
    *(undefined4 *)(unaff_EBP + -4) = 5;
    piVar5 = (int *)(**(code **)(*piVar5 + 0x10))();
    (**(code **)(*piVar5 + 0x20))(uVar4);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
    puVar7 = (undefined4 *)FUN_005e7743();
    (**(code **)*puVar7)();
    FUN_004ff397();
    (**(code **)(*unaff_ESI + 0x34))();
    (**(code **)(*DAT_006fe8bc + 0x18))();
    pHVar3 = (HWND)FUN_005dad1c();
    if (pHVar3 != unaff_EBX) {
      (**(code **)(pHVar3->unused + 8))();
    }
    if ((DAT_006e486c != unaff_EBX) && ((HWND)DAT_006e486c[0xb].unused != unaff_EBX)) {
      ((HWND)DAT_006e486c[0xb].unused)[0x18].unused = 100;
    }
    FUN_004fb5e5();
    (**(code **)(*(int *)unaff_ESI[0x20] + 0x94))();
    pHVar3 = operator_new(0x1d8);
    *(HWND *)(unaff_EBP + -0x18) = pHVar3;
    *(undefined4 *)(unaff_EBP + -4) = 6;
    if (pHVar3 == unaff_EBX) {
      pHVar3 = (HWND)0x0;
    }
    else {
      pHVar3 = (HWND)FUN_005edbcb();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    unaff_ESI[0x44] = (int)pHVar3;
    if (pHVar3 != unaff_EBX) {
      FUN_0046fca5();
      *(undefined ***)(unaff_EBP + -0x98) = &PTR_FUN_0066643c;
      *(undefined4 *)(unaff_EBP + -4) = 7;
      uVar4 = FUN_0041532c(9,unaff_EBP + -0x98);
      uVar2 = FUN_004fff98(0x9a,uVar4);
      *(undefined1 *)(unaff_EBP + -0x11) = uVar2;
      iVar6 = unaff_ESI[0x20];
      (**(code **)(*(int *)unaff_ESI[0x44] + 0x60))
                (*(undefined4 *)(iVar6 + 0x7c),*(undefined4 *)(iVar6 + 0x80),
                 *(undefined4 *)(iVar6 + 0x84),*(undefined4 *)(iVar6 + 0x88));
      FUN_005a5631(0x232b,unaff_EBP + -0x1c,4);
      if (*(char *)(unaff_EBP + -0x11) == cVar9) {
        pcVar8 = s_The_Sims_is__c__1999_by_Maxis_El_006ca6f8;
      }
      else {
        pcVar8 = (char *)FUN_004705f2(6,0xffffffff);
      }
      FUN_005ee87a(1,*(undefined4 *)(unaff_EBP + -0x1c),unaff_EBX,pcVar8);
      FUN_005ee8d4(DAT_006f2abc);
      FUN_005ddfdc(1);
      (**(code **)(*(int *)unaff_ESI[0x44] + 0x94))();
      (**(code **)(*(int *)unaff_ESI[0x20] + 0x94))();
      (**(code **)(*(int *)unaff_ESI[0x20] + 0x20))(unaff_ESI[0x44]);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_00470467();
    }
    if (DAT_006f29f7 == cVar9) {
      *(undefined1 *)(unaff_ESI[0x44] + 0x1b0) = 1;
    }
    else {
      FUN_004fb0d6();
      FUN_004fb49a();
    }
    uVar4 = 1;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

