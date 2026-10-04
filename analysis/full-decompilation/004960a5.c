
/* WARNING (jumptable): Unable to track spacebase fully for stack */

void FUN_004960a5(void)

{
  undefined1 uVar1;
  short sVar2;
  undefined3 *puVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int extraout_ECX;
  undefined1 extraout_var;
  uint extraout_ECX_00;
  uint uVar8;
  uint extraout_ECX_01;
  int iVar9;
  int iVar10;
  int unaff_EBP;
  undefined4 *puVar11;
  int iStack_100;
  undefined4 auStack_fc [7];
  undefined4 uStack_e0;
  undefined3 *puStack_dc;
  uint uStack_d8;
  undefined4 local_d4;
  
  FUN_00634c24();
  *(undefined1 *)(unaff_EBP + -0x16) = 0;
  *(undefined1 *)(unaff_EBP + -0x11) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if ((*(int *)(unaff_EBP + 0xc) < 0) || (1 < *(int *)(unaff_EBP + 0xc))) goto LAB_004964ee;
  puVar3 = *(undefined3 **)(unaff_EBP + 8);
  *(undefined4 **)(unaff_EBP + -0x20) = &local_d4;
  local_d4._3_1_ = (undefined1)((uint)extraout_ECX >> 0x18);
  local_d4 = CONCAT13(local_d4._3_1_,*puVar3);
  uStack_d8 = unaff_EBP - 0x4c;
  puStack_dc = (undefined3 *)0x496102;
  FUN_00467768();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  switch(*(undefined4 *)(unaff_EBP + 0x10)) {
  case 0:
  case 1:
    *(undefined4 *)(unaff_EBP + -0x10) = 1;
    break;
  case 2:
  case 3:
    *(undefined4 *)(unaff_EBP + -0x10) = 2;
    break;
  case 4:
  case 5:
    *(undefined4 *)(unaff_EBP + -0x10) = 0x20;
    break;
  case 6:
  case 7:
    *(undefined4 *)(unaff_EBP + -0x10) = 0x10;
    break;
  default:
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
  }
  uStack_d8 = *(uint *)(unaff_EBP + -0x10);
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  *(bool *)(unaff_EBP + -0x12) = (uStack_d8 & *(uint *)(unaff_EBP + -0x4c)) == uStack_d8;
  *(undefined1 *)(unaff_EBP + 0x13) = 0;
  if (*(int *)(unaff_EBP + 0xc) == 0) {
    if (*(char *)(unaff_EBP + -0x12) == '\0') {
      uVar8 = *(uint *)(extraout_ECX + 0xe038);
      *(uint *)(unaff_EBP + -0x4c) = *(uint *)(unaff_EBP + -0x4c) | uStack_d8;
      *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(&DAT_006e57e8 + uVar8 * 4);
      if ((uStack_d8 == 0x10) || (uStack_d8 == 0x20)) {
        *(undefined2 *)(unaff_EBP + -0x44) = 0;
        *(undefined2 *)(unaff_EBP + -0x38) = 0;
      }
      *(uint *)(unaff_EBP + -0x24) = *(uint *)(unaff_EBP + -0x24) | 0x10;
      puStack_dc = (undefined3 *)0x496196;
      local_d4 = uStack_d8;
      uStack_d8 = uVar8;
      FUN_004633e3();
      local_d4 = 0;
      uStack_d8 = *(uint *)(unaff_EBP + -0x10);
      puStack_dc = *(undefined3 **)(extraout_ECX + 0xe03c);
      uStack_e0 = 0x4961a8;
      FUN_00493b0f();
      if (*(int *)(extraout_ECX + 0xe038) == 0xff) {
        uVar1 = *(undefined1 *)puVar3;
        *(undefined1 *)(unaff_EBP + -0x11) = 1;
        *(undefined1 *)(unaff_EBP + -0x18) = uVar1;
        *(undefined1 *)(unaff_EBP + -0x17) = *(undefined1 *)((int)puVar3 + 1);
        *(undefined1 *)(unaff_EBP + -0x16) = *(undefined1 *)((int)puVar3 + 2);
      }
    }
    else {
      local_d4 = 0;
      puStack_dc = (undefined3 *)0x4961d9;
      iVar9 = FUN_00435221();
      sVar2 = *(short *)(unaff_EBP + -0x44 + iVar9 * 2);
      if ((((sVar2 != 3) && (sVar2 != 5)) && (sVar2 != 6)) &&
         (((sVar2 != 0xf && (sVar2 != 0x17)) && (sVar2 != 0x16)))) goto LAB_004964ee;
      local_d4 = unaff_EBP + -0x20;
      uStack_d8 = *(uint *)(unaff_EBP + -0x10);
      uStack_e0 = 0x496211;
      puStack_dc = puVar3;
      cVar4 = FUN_00497140();
      if (cVar4 == '\0') goto LAB_004964ee;
      uVar1 = *(undefined1 *)puVar3;
      *(undefined4 **)(unaff_EBP + 0xc) = &local_d4;
      *(int *)(unaff_EBP + -0x1c) = -*(int *)(unaff_EBP + -0x20);
      local_d4._0_2_ = CONCAT11(*(undefined1 *)((int)puVar3 + 1),uVar1);
      local_d4._0_3_ = CONCAT12(*(undefined1 *)((int)puVar3 + 2),(undefined2)local_d4);
      local_d4 = CONCAT13(extraout_var,(undefined3)local_d4);
      uStack_d8 = unaff_EBP - 0xa4;
      puStack_dc = (undefined3 *)0x496249;
      puVar7 = (undefined4 *)FUN_00467768();
      local_d4 = 0xb;
      puVar11 = (undefined4 *)(unaff_EBP + -0x4c);
      for (iVar9 = 0xb; iVar9 != 0; iVar9 = iVar9 + -1) {
        *puVar11 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar11 = puVar11 + 1;
      }
      *(int *)(extraout_ECX + 0xe050) = *(int *)(extraout_ECX + 0xe050) + 1;
    }
  }
  else {
    local_d4 = 0;
    puStack_dc = (undefined3 *)0x496265;
    iVar9 = FUN_00435221();
    sVar2 = *(short *)(unaff_EBP + -0x44 + iVar9 * 2);
    if (((((sVar2 == 3) || (sVar2 == 5)) || (sVar2 == 6)) || ((sVar2 == 0xf || (sVar2 == 0x17)))) ||
       (uVar8 = local_d4, sVar2 == 0x16)) {
      local_d4 = unaff_EBP - 0x20;
      uStack_d8 = *(uint *)(unaff_EBP + -0x10);
      uStack_e0 = 0x49629d;
      puStack_dc = puVar3;
      cVar4 = FUN_00497140();
      uVar8 = extraout_ECX_00;
      if (cVar4 != '\0') {
        *(int *)(unaff_EBP + -0x1c) = -*(int *)(unaff_EBP + -0x20);
        *(undefined1 *)(unaff_EBP + 0xc) = *(undefined1 *)puVar3;
        *(undefined1 *)(unaff_EBP + 0xd) = *(undefined1 *)((int)puVar3 + 1);
        *(undefined1 *)(unaff_EBP + 0xe) = *(undefined1 *)((int)puVar3 + 2);
        local_d4 = -*(int *)(DAT_006e54d8 + 0x84) & 3;
        uStack_d8 = 0x4962d7;
        FUN_00434ffd();
        iVar5 = (int)*(char *)(unaff_EBP + 0xc);
        iVar10 = (int)*(char *)(unaff_EBP + 0xd);
        iVar9 = *(int *)(&DAT_006f4620 +
                        ((-*(int *)(DAT_006e54d8 + 0x84) & 3U) * 0x40 + *(int *)(unaff_EBP + -0x10))
                        * 4);
        if (iVar9 == 1) {
          *(undefined2 *)((iVar5 * 0x40 + iVar10) * 0xe + 0x26 + extraout_ECX) = 1;
          uVar8 = 0;
        }
        else if (iVar9 == 2) {
          *(undefined2 *)((iVar5 * 0x40 + iVar10) * 0xe + 0x28 + extraout_ECX) = 1;
          uVar8 = 0;
        }
        else if (iVar9 == 4) {
          *(undefined2 *)((iVar5 * 0x40 + iVar10) * 0xe + 0x3a6 + extraout_ECX) = 1;
          uVar8 = 0;
        }
        else {
          uVar8 = iVar9 - 8;
          if (uVar8 == 0) {
            *(undefined2 *)((iVar5 * 0x40 + iVar10) * 0xe + 0x36 + extraout_ECX) = 1;
          }
        }
        *(undefined1 *)(unaff_EBP + 0x13) = 1;
      }
    }
    if (*(char *)(unaff_EBP + -0x12) != '\0') {
      if ((*(int *)(unaff_EBP + -0x10) == 0x10) || (*(int *)(unaff_EBP + -0x10) == 0x20)) {
        uVar1 = *(undefined1 *)puVar3;
        *(undefined4 **)(unaff_EBP + 0xc) = &local_d4;
        local_d4._0_2_ = CONCAT11(*(undefined1 *)((int)puVar3 + 1),uVar1);
        local_d4._3_1_ = (undefined1)(uVar8 >> 0x18);
        local_d4._0_3_ = CONCAT12(*(undefined1 *)((int)puVar3 + 2),(undefined2)local_d4);
        uStack_d8 = 0x49638c;
        iVar9 = FUN_00486420();
        if (iVar9 == 0xff) {
          local_d4 = (uint)*(ushort *)(unaff_EBP + -0x38);
          *(uint **)(unaff_EBP + 0xc) = &uStack_d8;
          uStack_e0 = 0x4963a4;
          puStack_dc = puVar3;
          uStack_d8 = extraout_ECX_01;
          FUN_00461b74();
          puStack_dc = (undefined3 *)0x4963af;
          FUN_00487992();
        }
      }
      local_d4 = 0x4963c6;
      uVar6 = __ftol();
      *(uint *)(unaff_EBP + -0x24) = *(uint *)(unaff_EBP + -0x24) | 0x10;
      *(undefined4 *)(unaff_EBP + -0x1c) = uVar6;
      *(undefined1 *)(unaff_EBP + 0x13) = 1;
      *(uint *)(unaff_EBP + -0x4c) = *(uint *)(unaff_EBP + -0x4c) & ~*(uint *)(unaff_EBP + -0x10);
      *(int *)(extraout_ECX + 0xe050) = *(int *)(extraout_ECX + 0xe050) + 1;
    }
    if (*(char *)(unaff_EBP + 0x13) == '\0') goto LAB_004964ee;
  }
  *(int *)(extraout_ECX + 0xe028) = *(int *)(extraout_ECX + 0xe028) + *(int *)(unaff_EBP + -0x1c);
  *(undefined4 **)(unaff_EBP + 0xc) = auStack_fc;
  *(undefined1 *)(extraout_ECX + 0xe024) = 1;
  puVar7 = (undefined4 *)(unaff_EBP + -0x4c);
  puVar11 = auStack_fc;
  for (iStack_100 = 0xb; iStack_100 != 0; iStack_100 = iStack_100 + -1) {
    *puVar11 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar11 = puVar11 + 1;
  }
  *(undefined1 *)(unaff_EBP + -4) = 2;
  *(int **)(unaff_EBP + 0x10) = &iStack_100;
  FUN_00461b74(*(undefined4 *)(unaff_EBP + 8));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_00489224();
  if (*(char *)(unaff_EBP + -0x11) != '\0') {
    local_d4 = unaff_EBP + -0x18;
    uStack_d8 = *(uint *)(unaff_EBP + -0x10);
    puStack_dc = (undefined3 *)0x496440;
    FUN_0053c0e0();
    puStack_dc = *(undefined3 **)(unaff_EBP + -0x10);
    uStack_e0 = 0x496448;
    uVar6 = FUN_0053c135();
    iVar5 = local_d4;
    uStack_e0 = 0xb;
    *(undefined4 *)(unaff_EBP + 0xc) = uVar6;
    puVar7 = (undefined4 *)(unaff_EBP + -0x78);
    for (iVar9 = 0xb; iVar9 != 0; iVar9 = iVar9 + -1) {
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
    }
    *(undefined4 **)(unaff_EBP + 0x10) = &local_d4;
    *(undefined1 *)(unaff_EBP + -4) = 3;
    local_d4._0_2_ = CONCAT11(*(undefined1 *)(unaff_EBP + -0x17),*(undefined1 *)(unaff_EBP + -0x18))
    ;
    local_d4._3_1_ = SUB41(iVar5,3);
    local_d4._0_3_ = CONCAT12(*(undefined1 *)(unaff_EBP + -0x16),(undefined2)local_d4);
    uStack_d8 = unaff_EBP - 0xd0;
    puStack_dc = (undefined3 *)0x496484;
    puVar7 = (undefined4 *)FUN_00467768();
    local_d4 = 0;
    uStack_d8 = *(uint *)(unaff_EBP + 0xc);
    puVar11 = (undefined4 *)(unaff_EBP + -0x78);
    for (iVar9 = 0xb; iVar9 != 0; iVar9 = iVar9 + -1) {
      *puVar11 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar11 = puVar11 + 1;
    }
    puStack_dc = *(undefined3 **)(extraout_ECX + 0xe03c);
    uStack_e0 = 0x4964a1;
    FUN_00493b0f();
    *(undefined4 **)(unaff_EBP + 0xc) = auStack_fc;
    puVar7 = (undefined4 *)(unaff_EBP + -0x78);
    puVar11 = auStack_fc;
    for (iStack_100 = 0xb; iStack_100 != 0; iStack_100 = iStack_100 + -1) {
      *puVar11 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar11 = puVar11 + 1;
    }
    *(int **)(unaff_EBP + 0x10) = &iStack_100;
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_00461b74(unaff_EBP + -0x18);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_00489224();
    *(undefined1 *)(unaff_EBP + -4) = 1;
  }
  local_d4 = *(undefined4 *)(unaff_EBP + 8);
  uStack_d8 = 0x4964df;
  FUN_00492be0();
  local_d4 = *(undefined4 *)(unaff_EBP + -0x1c);
  uStack_d8 = 0x4964ee;
  FUN_00492bb0();
LAB_004964ee:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

