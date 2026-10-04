
void FUN_0048b35a(void)

{
  int iVar1;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined1 *puVar7;
  int extraout_ECX;
  undefined1 extraout_var;
  undefined1 extraout_var_00;
  undefined1 extraout_var_01;
  char cVar8;
  int unaff_EBP;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 local_1c;
  
  FUN_00634c24();
  if (*(char *)(extraout_ECX + 0x70) != '\0') goto LAB_0048b637;
  local_1c = unaff_EBP + 8;
  cVar2 = FUN_00484ba0();
  if (cVar2 == '\0') {
    local_1c = 0x48b392;
    uVar3 = FUN_00492b26();
    *(undefined4 **)(unaff_EBP + -0x18) = &local_1c;
    local_1c._0_2_ =
         CONCAT11((char)(*(int *)(unaff_EBP + 8) >> 4),(char)(*(int *)(unaff_EBP + 0xc) >> 4));
    local_1c._0_3_ = CONCAT12(uVar3,(undefined2)local_1c);
    local_1c = CONCAT13(extraout_var,(undefined3)local_1c);
    iVar4 = FUN_00488924();
    if (iVar4 == 0) goto LAB_0048b621;
    local_1c = 0x48b3c6;
    iVar4 = FUN_0048b777();
    if (iVar4 == *(int *)(extraout_ECX + 0x6c)) {
      if ((*(int *)(unaff_EBP + 0xc) == *(int *)(extraout_ECX + 0x3c)) &&
         (*(int *)(unaff_EBP + 8) == *(int *)(extraout_ECX + 0x38))) goto LAB_0048b637;
    }
    else {
      iVar5 = *(int *)(extraout_ECX + 0x5c);
      *(int *)(extraout_ECX + 0x6c) = iVar4;
      if (iVar5 != 0) {
        *(undefined1 *)(unaff_EBP + -0x14) = *(undefined1 *)(iVar5 + 0xe02c);
        *(undefined1 *)(unaff_EBP + -0x13) = *(undefined1 *)(iVar5 + 0xe02d);
        *(undefined1 *)(unaff_EBP + -0x12) = *(undefined1 *)(iVar5 + 0xe02e);
        *(undefined4 *)(unaff_EBP + -4) = 0;
        local_1c = 0x48b3fb;
        FUN_00495076();
        *(undefined4 *)(*(int *)(extraout_ECX + 0x5c) + 0xe040) =
             *(undefined4 *)(extraout_ECX + 0x6c);
        local_1c = unaff_EBP + -0x14;
        FUN_00496868();
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      }
      local_1c = *(undefined4 *)(extraout_ECX + 0x6c);
      FUN_0048b9f3();
    }
    puVar9 = *(undefined4 **)(unaff_EBP + 0x14);
    *(undefined4 *)(extraout_ECX + 0x38) = *(undefined4 *)(unaff_EBP + 8);
    *(undefined4 *)(extraout_ECX + 0x3c) = *(undefined4 *)(unaff_EBP + 0xc);
    puVar10 = (undefined4 *)(extraout_ECX + 0x40);
    for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar10 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar10 = puVar10 + 1;
    }
    local_1c = 0x48b453;
    iVar4 = FUN_004a6988();
    local_1c = 0x48b45a;
    iVar5 = FUN_004a697c();
    *(int *)(unaff_EBP + -0x14) = iVar5 * iVar5;
    *(int *)(unaff_EBP + -0x14) = iVar4 * iVar4;
    local_1c = 0x48b47b;
    uVar6 = __ftol();
    *(undefined4 *)(unaff_EBP + -0x14) = uVar6;
    uVar6 = *(undefined4 *)(*(int *)(unaff_EBP + 0x14) + 0xc);
    *(undefined4 *)(unaff_EBP + 0x14) = uVar6;
    iVar5 = (int)*(short *)(unaff_EBP + 0x16) - *(int *)(extraout_ECX + 0x54);
    iVar4 = (int)(short)uVar6 - *(int *)(extraout_ECX + 0x58);
    *(int *)(unaff_EBP + -0x18) = iVar4;
    iVar4 = iVar4 * iVar4 + iVar5 * iVar5;
    if ((iVar4 < 0x7fffffff) && (*(int *)(extraout_ECX + 0x5c) != 0)) {
      local_1c = 0x48b4b5;
      FUN_00495076();
    }
    local_1c = unaff_EBP + 8;
    FUN_0048b857();
    local_1c = 0x48b4c5;
    uVar6 = FUN_00492b26();
    *(undefined4 *)(unaff_EBP + 0x14) = uVar6;
    cVar8 = (char)(*(int *)(unaff_EBP + 0xc) >> 4);
    *(char *)(unaff_EBP + -0x10) = cVar8;
    cVar2 = (char)(*(int *)(unaff_EBP + 8) >> 4);
    *(char *)(unaff_EBP + -0xf) = cVar2;
    *(char *)(unaff_EBP + -0xe) = (char)uVar6;
    iVar1 = *(int *)(extraout_ECX + 0x5c);
    *(undefined4 *)(unaff_EBP + -4) = 1;
    if (iVar1 != 0) {
      if ((((*(char *)(extraout_ECX + 0x30) == cVar8) && (*(char *)(extraout_ECX + 0x31) == cVar2))
          && (*(char *)(extraout_ECX + 0x32) == *(char *)(unaff_EBP + 0x14))) &&
         (*(int *)(unaff_EBP + -0x14) < iVar4)) {
        local_1c = *(undefined4 *)(unaff_EBP + -0x18);
        puVar7 = (undefined1 *)FUN_00496cbf(unaff_EBP + 0x14,extraout_ECX + 0x30,iVar5);
        *(undefined1 *)(unaff_EBP + -0x10) = *puVar7;
        *(undefined1 *)(unaff_EBP + -0xf) = puVar7[1];
        *(undefined1 *)(unaff_EBP + -0xe) = puVar7[2];
      }
      local_1c = 0;
      cVar2 = FUN_00496e92(unaff_EBP + -0x10);
      if (cVar2 == '\0') {
        *(undefined1 *)(unaff_EBP + -0x10) = *(undefined1 *)(extraout_ECX + 0x33);
        *(undefined1 *)(unaff_EBP + -0xf) = *(undefined1 *)(extraout_ECX + 0x34);
        *(undefined1 *)(unaff_EBP + -0xe) = *(undefined1 *)(extraout_ECX + 0x35);
      }
      iVar4 = *(int *)(extraout_ECX + 0x5c);
      *(undefined1 *)(unaff_EBP + 0x14) = *(undefined1 *)(iVar4 + 0xe030);
      uVar3 = *(undefined1 *)(iVar4 + 0xe032);
      *(undefined1 *)(unaff_EBP + 0x15) = *(undefined1 *)(iVar4 + 0xe031);
      *(undefined1 *)(unaff_EBP + 0x16) = uVar3;
      *(undefined1 *)(unaff_EBP + -4) = 2;
      *(undefined4 **)(unaff_EBP + -0x18) = &local_1c;
      local_1c._0_2_ =
           CONCAT11(*(undefined1 *)(unaff_EBP + -0xf),*(undefined1 *)(unaff_EBP + -0x10));
      local_1c._0_3_ = CONCAT12(*(undefined1 *)(unaff_EBP + -0xe),(undefined2)local_1c);
      local_1c = CONCAT13(extraout_var_00,(undefined3)local_1c);
      FUN_004968fb();
      local_1c = *(int *)(extraout_ECX + 0x5c) + 0xe030;
      cVar2 = FUN_0048b8b2();
      if (cVar2 == '\0') {
        *(undefined4 **)(unaff_EBP + -0x18) = &local_1c;
        local_1c._0_2_ =
             CONCAT11(*(undefined1 *)(unaff_EBP + 0x15),*(undefined1 *)(unaff_EBP + 0x14));
        local_1c._0_3_ = CONCAT12(*(undefined1 *)(unaff_EBP + 0x16),(undefined2)local_1c);
        local_1c = CONCAT13(extraout_var_01,(undefined3)local_1c);
        FUN_004968fb();
        local_1c = *(int *)(extraout_ECX + 0x5c) + 0xe030;
        FUN_0048b8b2();
      }
      else {
        local_1c = 0x48b5d0;
        local_1c = FUN_00492b26();
        FUN_00540a5b();
        FUN_00540eb1();
      }
      *(undefined1 *)(unaff_EBP + -4) = 1;
    }
    local_1c = 0;
    FUN_0040766a(0x101);
    if (*(int *)(extraout_ECX + 0x5c) == 0) goto LAB_0048b637;
    iVar4 = *(int *)(*(int *)(extraout_ECX + 0x5c) + 0xe064);
    if (iVar4 != 0) goto LAB_0048b62d;
    local_1c = 0x48b605;
    cVar2 = FUN_004972cb();
    if (cVar2 == '\0') {
      local_1c = *(int *)(*(int *)(extraout_ECX + 0x5c) + 0xe028);
      if (local_1c == 0) goto LAB_0048b637;
      iVar4 = 0x1a;
    }
    else {
      local_1c = -1;
      iVar4 = 0x19;
    }
  }
  else {
LAB_0048b621:
    iVar4 = 1;
    *(undefined4 *)(*(int *)(extraout_ECX + 0x5c) + 0xe064) = 1;
LAB_0048b62d:
    local_1c = -1;
  }
  FUN_004864ed(iVar4);
LAB_0048b637:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

