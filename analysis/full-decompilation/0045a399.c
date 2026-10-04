
undefined4 __thiscall FUN_0045a399(int param_1,int param_2,int param_3,int param_4,short param_5)

{
  char cVar1;
  short sVar2;
  undefined2 *puVar3;
  undefined4 uVar4;
  int iVar5;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined2 extraout_var_02;
  undefined2 extraout_var_03;
  undefined2 extraout_var_04;
  undefined2 extraout_var_05;
  undefined2 extraout_var_06;
  undefined4 *puVar6;
  undefined2 extraout_var_07;
  undefined2 extraout_var_08;
  undefined2 extraout_var_09;
  undefined2 extraout_var_10;
  undefined2 extraout_var_11;
  undefined2 extraout_var_12;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 local_24;
  undefined4 local_20;
  undefined2 local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  puVar3 = (undefined2 *)FUN_00425769(*(undefined4 *)(*(int *)(param_1 + 0x118) + 0x1c));
  iVar8 = 0;
  if (puVar3 == (undefined2 *)0x0) {
    return 1;
  }
  local_c = FUN_0042a8e3(*puVar3);
  if (local_c == 0) {
    return 1;
  }
  sVar2 = (short)param_2;
  local_8 = 0;
  local_10 = 0;
  if (sVar2 == -1) {
    local_18 = *DAT_006e486c;
    uVar4 = FUN_00425db3(0);
    *(undefined4 *)(local_18 + 0x10) = uVar4;
    iVar5 = FUN_00425db3((int)*(short *)(param_1 + 0x606));
    local_18 = *(undefined4 *)(iVar5 + 0x110);
    if (param_5 != 0) goto LAB_0045a540;
    local_14 = -1;
    FUN_0041f69e(3,&local_14,0);
    if ((short)local_14 != -1) {
      local_24 = 0;
      local_20 = 0;
      local_1c = 1;
      FUN_0041f6fd(local_14,&local_24);
      uVar4 = FUN_004e988f(local_20);
      iVar8 = FUN_004e9744(uVar4);
      if (iVar8 == 0) goto LAB_0045a673;
      local_8 = DAT_006e486c[9];
      uVar4 = FUN_0045741b();
LAB_0045a524:
      puVar3 = (undefined2 *)FUN_00425769(uVar4);
      local_8 = FUN_0042a8e3(*puVar3);
      goto LAB_0045a563;
    }
  }
  else {
    local_18 = param_2;
    if (param_5 == 0) {
      local_14 = -1;
      FUN_0041f69e(1,&local_14,0);
      if ((short)local_14 != -1) {
        local_24 = 0;
        local_20 = 0;
        local_1c = 1;
        FUN_0041f6fd(local_14,&local_24);
        uVar4 = FUN_004e988f(local_20);
        iVar8 = FUN_004e9744(uVar4);
        if (iVar8 != 0) {
          local_8 = DAT_006e486c[9];
          uVar4 = FUN_0045741b();
          goto LAB_0045a524;
        }
      }
      goto LAB_0045a673;
    }
LAB_0045a540:
    if (param_5 == 1) {
      local_10 = FUN_00425db3((int)*(short *)(param_1 + 0x606));
LAB_0045a563:
      if ((iVar8 != 0) && (local_8 != 0)) {
        FUN_0041f4e7(2);
        uVar4 = __ftol();
        FUN_0041f38f(2,0,uVar4);
        uVar4 = __ftol();
        FUN_0041f38f(2,1,uVar4);
        uVar4 = __ftol();
        FUN_0041f38f(2,2,uVar4);
        uVar4 = __ftol();
        FUN_0041f38f(2,3,uVar4);
        uVar4 = __ftol();
        FUN_0041f38f(2,4,uVar4);
        uVar4 = __ftol();
        FUN_0041f38f(2,5,uVar4);
        uVar4 = __ftol();
        FUN_0041f38f(2,6,uVar4);
        FUN_0041f38f(2,9,CONCAT22(extraout_var,*(undefined2 *)(iVar8 + 0x59c)));
        FUN_0041f38f(2,10,CONCAT22(extraout_var_00,*(undefined2 *)(iVar8 + 0x62c)));
        FUN_0041f38f(2,0xb,CONCAT22(extraout_var_01,*(undefined2 *)(iVar8 + 0x630)));
        FUN_0041f38f(2,0xc,CONCAT22(extraout_var_02,*(undefined2 *)(iVar8 + 0x62e)));
      }
      if (local_10 != 0) {
        local_14 = 0;
        iVar5 = FUN_004102e1();
        iVar8 = local_c;
        if (0 < iVar5) {
          do {
            puVar6 = (undefined4 *)FUN_004102ab(local_14);
            iVar8 = FUN_0044097d(*puVar6);
            if (iVar8 != 0) {
              FUN_00425ab3(iVar8);
              puVar6 = (undefined4 *)FUN_004102ab(local_14);
              puVar3 = (undefined2 *)FUN_00425769(*puVar6);
              local_8 = FUN_0042a8e3(*puVar3);
              if (local_14 == 0) {
                local_c = local_8;
              }
              FUN_0041f4e7(2);
              uVar4 = __ftol();
              FUN_0041f38f(2,0,uVar4);
              uVar4 = __ftol();
              FUN_0041f38f(2,1,uVar4);
              uVar4 = __ftol();
              FUN_0041f38f(2,2,uVar4);
              uVar4 = __ftol();
              FUN_0041f38f(2,3,uVar4);
              uVar4 = __ftol();
              FUN_0041f38f(2,4,uVar4);
              uVar4 = __ftol();
              FUN_0041f38f(2,5,uVar4);
              uVar4 = __ftol();
              FUN_0041f38f(2,6,uVar4);
              FUN_0041f38f(2,9,CONCAT22(extraout_var_07,*(undefined2 *)(iVar8 + 0x59c)));
              FUN_0041f38f(2,10,CONCAT22(extraout_var_08,*(undefined2 *)(iVar8 + 0x62c)));
              FUN_0041f38f(2,0xb,CONCAT22(extraout_var_09,*(undefined2 *)(iVar8 + 0x630)));
              FUN_0041f38f(2,0xc,CONCAT22(extraout_var_10,*(undefined2 *)(iVar8 + 0x62e)));
            }
            local_14 = local_14 + 1;
            iVar5 = FUN_004102e1();
            iVar8 = local_c;
          } while (local_14 < iVar5);
        }
        goto LAB_0045a8f1;
      }
    }
  }
LAB_0045a673:
  FUN_0041f4e7(2);
  uVar4 = __ftol();
  iVar8 = local_c;
  FUN_0041f38f(2,0,uVar4);
  uVar4 = __ftol();
  FUN_0041f38f(2,1,uVar4);
  uVar4 = __ftol();
  FUN_0041f38f(2,2,uVar4);
  uVar4 = __ftol();
  FUN_0041f38f(2,3,uVar4);
  uVar4 = __ftol();
  FUN_0041f38f(2,4,uVar4);
  uVar4 = __ftol();
  FUN_0041f38f(2,5,uVar4);
  uVar4 = __ftol();
  FUN_0041f38f(2,6,uVar4);
  FUN_0041f38f(2,9,CONCAT22(extraout_var_03,*(undefined2 *)(param_1 + 0x59c)));
  FUN_0041f38f(2,10,CONCAT22(extraout_var_04,*(undefined2 *)(param_1 + 0x62c)));
  FUN_0041f38f(2,0xb,CONCAT22(extraout_var_05,*(undefined2 *)(param_1 + 0x630)));
  FUN_0041f38f(2,0xc,CONCAT22(extraout_var_06,*(undefined2 *)(param_1 + 0x62e)));
LAB_0045a8f1:
  cVar1 = FUN_004074bc();
  if (((cVar1 == '\0') || (sVar2 < 0x28)) || (0x31 < sVar2)) {
    iVar5 = DAT_006e486c[7];
    iVar7 = CONCAT22(extraout_var_12,*(undefined2 *)(iVar5 + 0x10));
    param_4._0_2_ = *(short *)(iVar5 + 0x1a) + (short)param_4;
    param_2 = CONCAT22((short)((uint)iVar5 >> 0x10),(short)param_4);
    if (0x3b < (short)param_4) {
      iVar7 = iVar7 + 1;
      param_2 = (int)(short)param_4 % 0x3c;
    }
    param_3 = iVar7 + param_3;
    if (0x17 < (short)param_3) {
      param_3 = (int)(short)param_3 % 0x18;
    }
  }
  else {
    param_2 = param_4;
  }
  if (iVar8 != 0) {
    FUN_0041f38f(2,7,param_3);
    FUN_0041f38f(2,8,param_2);
  }
  FUN_00425316(DAT_006e486c[0x11]);
  if (param_5 == 0) {
    uVar9 = 0;
    uVar4 = *(undefined4 *)(*(int *)(param_1 + 0x118) + 0x1c);
  }
  else {
    if (param_5 != 1) {
      return 1;
    }
    uVar9 = CONCAT22(extraout_var_11,*(undefined2 *)(param_1 + 0x606));
    uVar4 = 0;
  }
  FUN_004fc7b2(local_18,uVar4,uVar9);
  return 1;
}

