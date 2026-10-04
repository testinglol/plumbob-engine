
undefined4 __thiscall
FUN_0042ccd8(int param_1,uint param_2,uint param_3,undefined4 param_4,undefined4 param_5)

{
  short sVar1;
  undefined4 *puVar2;
  undefined2 uVar3;
  DWORD DVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint in_stack_00000024;
  undefined2 in_stack_00000028;
  char in_stack_0000002c;
  undefined **local_444 [3];
  undefined1 local_438 [256];
  undefined **local_338;
  undefined4 local_334;
  undefined1 local_32c [256];
  undefined **local_22c [3];
  undefined1 local_220 [256];
  undefined **local_120 [3];
  undefined1 local_114 [260];
  undefined4 local_10;
  undefined4 *local_c;
  undefined4 *local_8;
  
  DVar4 = timeGetTime();
  FUN_005bc6cb(DVar4);
  local_8 = *(undefined4 **)(DAT_006e486c + 0x28);
  local_c = (undefined4 *)FUN_0043acf5(param_2);
  if (local_c == (undefined4 *)0x0) {
    return 0;
  }
  local_10 = *local_c;
  param_2 = -0x2b;
  FUN_0046f824(local_114,0,0x104);
  local_120[0] = &PTR_FUN_006664e8;
  if (*(int *)(param_1 + 0x160) < 32000) {
    do {
      if (param_2 != -0x2b) break;
      FUN_0046fb9b(local_32c,0x100);
      local_338 = &PTR_LAB_0066655c;
      FUN_00635858(local_334,s_User_05d_006c2650,*(undefined4 *)(param_1 + 0x160));
      FUN_0046f824(local_220,0,0x100);
      local_22c[0] = &PTR_FUN_00666524;
      FUN_0046f8e4(&local_338);
      FUN_0046f847(&DAT_006c2648,0xffffffff);
      FUN_00412122(param_1,local_120);
      FUN_0046f847(s_Characters__006c1d48,0xffffffff);
      FUN_0046f917(local_22c,0xffffffff);
      FUN_0046f824(local_438,0,0x100);
      local_444[0] = &PTR_FUN_00666524;
      FUN_0046f8e4(&local_338);
      FUN_0046fa24(0x20);
      FUN_0047234b();
      FUN_0047239b(local_444);
      param_2 = FUN_004723b0(local_10,local_120);
      *(int *)(param_1 + 0x160) = *(int *)(param_1 + 0x160) + 1;
    } while (*(int *)(param_1 + 0x160) < 32000);
    if (*(int *)(param_1 + 0x160) < 32000) goto LAB_0042cea6;
  }
  *(undefined4 *)(param_1 + 0x160) = 0;
LAB_0042cea6:
  iVar10 = 0;
  if (param_2 != 0) {
    return 0;
  }
  FUN_0043c422(local_120);
  param_2 = 0;
  iVar5 = FUN_0043ad1f(0);
  if (iVar5 != 0) {
    do {
      sVar1 = *(short *)(*(int *)(iVar5 + 0x60) + 0x12);
      if ((((sVar1 == 0x200) || (sVar1 == 0x800)) || (sVar1 == 0x1000)) &&
         ((iVar6 = FUN_004257ba(iVar5), iVar6 == 0 && (iVar10 == 0)))) {
        iVar10 = FUN_004257ef(iVar5,0xffffffff);
      }
      param_2 = param_2 + 1;
      iVar5 = FUN_0043ad1f(param_2);
    } while (iVar5 != 0);
    if (iVar10 != 0) {
      puVar2 = *(undefined4 **)(iVar10 + 8);
      if (puVar2 == (undefined4 *)0x0) {
        return 0;
      }
      local_8 = puVar2;
      (**(code **)(*(int *)*puVar2 + 0x10))();
      (**(code **)(*(int *)*puVar2 + 0x14))();
      *(undefined2 *)(puVar2[0x18] + 0x12) = 2;
      FUN_004574bb();
      FUN_004e8b76();
      sVar1 = *(short *)(local_c[0x18] + 0x12);
      if (((sVar1 == 0x200) || (sVar1 == 0x800)) || (sVar1 == 0x1000)) {
        uVar7 = FUN_0045741b();
        uVar7 = FUN_004e988f(uVar7);
        FUN_004ea53c(uVar7,1);
        FUN_004eaa9b(uVar7,param_3);
        FUN_004eabf6(uVar7,param_4);
        FUN_0040f4b7(&stack0x00000014);
        FUN_004eac8c(uVar7,&PTR_FUN_00666634);
        iVar10 = FUN_004ea79e(uVar7);
        uVar3 = (undefined2)in_stack_00000024;
        *(undefined2 *)(iVar10 + 0xa2) = uVar3;
        iVar10 = FUN_004ea79e(uVar7);
        *(undefined2 *)(iVar10 + 0xa4) = uVar3;
        iVar10 = FUN_004ea79e(uVar7);
        param_2 = 0;
        param_3 = 0;
        *(undefined2 *)(iVar10 + 0xa0) = in_stack_00000028;
        if (*(short *)(local_c[0x18] + 0x12) == 0x1000) {
          uVar8 = FUN_004ead10();
          in_stack_00000024 = FUN_004ead68(uVar7);
          if (0 < (int)uVar8) {
            if ((int)uVar8 < 1000) {
              iVar10 = 1000;
            }
            else {
              iVar10 = uVar8 * 2;
            }
            param_2 = FUN_005bc722(iVar10);
            param_2 = param_2 % uVar8;
          }
          if (0 < (int)in_stack_00000024) {
            if ((int)in_stack_00000024 < 1000) {
              iVar10 = 1000;
            }
            else {
              iVar10 = in_stack_00000024 * 2;
            }
            param_3 = FUN_005bc722(iVar10);
            param_3 = param_3 % in_stack_00000024;
          }
          FUN_004ead2c(uVar7,param_2);
          FUN_004eada1(uVar7,param_3);
        }
        else {
          uVar8 = FUN_004eacb7(uVar7);
          uVar9 = FUN_004ead68(uVar7);
          if (0 < (int)uVar8) {
            iVar10 = 1000;
            if (999 < (int)uVar8) {
              iVar10 = uVar8 * 2;
            }
            param_2 = FUN_005bc722(iVar10);
            param_2 = param_2 % uVar8;
          }
          if (0 < (int)uVar9) {
            if ((int)uVar9 < 1000) {
              iVar10 = 1000;
            }
            else {
              iVar10 = uVar9 * 2;
            }
            param_3 = FUN_005bc722(iVar10);
            param_3 = param_3 % uVar9;
          }
          FUN_004eacf0(uVar7,param_2);
          FUN_004eada1(uVar7,param_3);
        }
        FUN_004eadc1(uVar7);
        if (in_stack_0000002c != '\0') {
          uVar3 = FUN_005bc722(1000);
          iVar10 = FUN_004ea79e(uVar7);
          *(undefined2 *)(iVar10 + 0x14) = uVar3;
          uVar3 = FUN_005bc722(1000);
          iVar10 = FUN_004ea79e(uVar7);
          *(undefined2 *)(iVar10 + 0x16) = uVar3;
          uVar3 = FUN_005bc722(1000);
          iVar10 = FUN_004ea79e(uVar7);
          *(undefined2 *)(iVar10 + 0x18) = uVar3;
          uVar3 = FUN_005bc722(1000);
          iVar10 = FUN_004ea79e(uVar7);
          *(undefined2 *)(iVar10 + 0x1e) = uVar3;
          uVar3 = FUN_005bc722(1000);
          iVar10 = FUN_004ea79e(uVar7);
          *(undefined2 *)(iVar10 + 0x22) = uVar3;
          uVar3 = FUN_005bc722(1000);
          iVar10 = FUN_004ea79e(uVar7);
          *(undefined2 *)(iVar10 + 0x24) = uVar3;
          if (((param_2 & 1) != 0) && (FUN_004ead4c(uVar7), (param_3 & 1) != 0)) {
            FUN_004ead4c(uVar7);
          }
        }
        FUN_004e9a99(uVar7,param_5);
        FUN_004ea674(uVar7,1,1,0);
      }
      uVar7 = FUN_0045741b();
      return uVar7;
    }
  }
  return 0xffffffff;
}

