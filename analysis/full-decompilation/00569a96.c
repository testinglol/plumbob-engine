
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00569a96(int *param_1)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  int *piVar5;
  DWORD DVar6;
  int iVar7;
  undefined1 *puVar8;
  uint *puVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int *piVar12;
  undefined1 local_a4 [16];
  undefined1 local_94 [16];
  undefined1 local_84 [16];
  undefined1 local_74 [16];
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  int local_44;
  int local_40;
  int local_3c;
  uint local_38;
  int local_34;
  int local_30;
  int local_2c;
  uint local_28;
  int local_24;
  int local_20;
  int local_1c;
  uint local_18;
  int iStack_14;
  uint local_10;
  int *local_c;
  undefined1 local_6;
  char local_5;
  
  local_5 = '\0';
  local_c = *(int **)(param_1[0x4b] + 0x1c);
  local_10 = *(uint *)(param_1[0x4b] + 0x20);
  local_64 = 400;
  local_60 = 0x15e;
  local_5c = 800;
  local_58 = 600;
  local_54 = 400;
  local_50 = 0x15e;
  local_4c = 800;
  local_48 = 600;
  if (local_c < (int *)(param_1[0x21] - param_1[0x1f])) {
    uVar3 = (uint)((param_1[0x21] - param_1[0x1f]) - (int)local_c) >> 1;
  }
  else {
    uVar3 = 0;
  }
  param_1[0x53] = uVar3;
  if (local_10 < (uint)(param_1[0x22] - param_1[0x20])) {
    uVar3 = (param_1[0x22] - param_1[0x20]) - local_10 >> 1;
  }
  else {
    uVar3 = 0;
  }
  param_1[0x54] = uVar3;
  uVar4 = (**(code **)(*DAT_006fe8bc + 0x1c))
                    (0,&cITSGraphicSystem::RTTI_Type_Descriptor,
                     &cTSGraphicSystemW95::RTTI_Type_Descriptor,0);
  local_44 = FUN_006359f2(uVar4);
  if (param_1[0x74] < 0) {
    uVar4 = FUN_004b469d();
    FUN_005caf21(uVar4);
    FUN_005cddcf(uVar4);
  }
  piVar5 = (int *)FUN_005caf21();
  if ((piVar5[1] - *piVar5 & 0xfffffff0U) != 0) {
    local_c = (int *)FUN_005caf21();
    for (iVar7 = *local_c; iVar7 != local_c[1]; iVar7 = iVar7 + 0x10) {
      FUN_005de822(iVar7);
      local_40 = local_30;
      local_3c = local_2c;
      local_38 = local_28;
      local_34 = local_24;
      FUN_004df599(local_94,param_1 + 0x53);
      FUN_005de841(&local_40,local_94);
      cVar2 = (**(code **)(*(int *)param_1[0x17] + 0x20))(0x10);
      if (cVar2 != '\0') {
        if (800 < param_1[0x21] - param_1[0x1f]) {
          (**(code **)(*(int *)param_1[0x17] + 0x9c))(param_1[0x4c],&local_30,&local_30,0);
        }
        if ((local_40 < (int)local_38) && (local_3c < local_34)) {
          uVar10 = 0;
          local_10 = *(uint *)param_1[0x17];
          piVar5 = &local_40;
          uVar4 = FUN_0053a19c(local_a4,param_1 + 0x53);
          (**(code **)(local_10 + 0x9c))(param_1[0x4b],uVar4,piVar5,uVar10);
        }
        (**(code **)(*(int *)param_1[0x17] + 0x24))(0x10);
      }
      piVar5 = (int *)FUN_004b46a0();
      (**(code **)(*piVar5 + 0x170))(&local_30);
      local_20 = local_30;
      local_1c = local_2c;
      local_18 = local_28;
      iStack_14 = local_24;
      uVar4 = FUN_004df599(local_84,param_1 + 0x53);
      FUN_005de841(&local_20,uVar4);
      if ((local_20 < (int)local_18) && (local_1c < iStack_14)) {
LAB_00569d1c:
        local_5 = '\x01';
      }
      else {
        local_20 = local_30;
        local_1c = local_2c;
        local_18 = local_28;
        iStack_14 = local_24;
        uVar4 = FUN_004df599(local_74,param_1 + 0x53);
        FUN_005de841(&local_20,uVar4);
        if ((local_20 < (int)local_18) && (local_1c < iStack_14)) goto LAB_00569d1c;
      }
    }
  }
  piVar5 = param_1 + 0x53;
  iVar7 = param_1[0x7c];
  DVar6 = timeGetTime();
  local_18 = DVar6 - iVar7;
  iStack_14 = 0;
  local_6 = _DAT_006687a0 / (float)local_18 <= (float)param_1[0x7b];
  if ((bool)local_6) {
    param_1[0x74] = param_1[0x74] + 1;
    param_1[0x7c] = iVar7 + local_18;
  }
  if (param_1[0x74] == 10) {
    param_1[0x74] = 0;
  }
  iVar7 = param_1[0x74];
  if (4 < iVar7) {
    iVar7 = 9 - iVar7;
  }
  if ((((bool)local_6) || (local_5 != '\0')) &&
     (piVar1 = param_1 + iVar7 + 0x75, param_1[iVar7 + 0x75] != 0)) {
    local_18 = 0;
    iStack_14 = 0;
    uVar4 = 0x10;
    cVar2 = (**(code **)(*(int *)param_1[0x17] + 0x20))(0x10);
    if (cVar2 != '\0') {
      uVar11 = 0;
      local_10 = *piVar1 + 0x14;
      local_c = *(int **)param_1[0x17];
      puVar8 = local_74;
      FUN_004df599(local_84,&local_18);
      uVar10 = FUN_004df599(puVar8,piVar5);
      (*(code *)local_c[0x27])(*piVar1,local_10,uVar10,uVar11);
      (**(code **)(*(int *)param_1[0x17] + 0x24))(0x10);
    }
    piVar5 = (int *)(local_44 + 0x48);
    puVar9 = &local_18;
    puVar8 = local_74;
    piVar12 = param_1;
    FUN_004e84f4(local_84,*piVar1 + 0x14);
    uVar10 = FUN_004df599(puVar8,puVar9);
    (**(code **)(*piVar5 + 0x24))(uVar10,piVar12);
    FUN_005ecd7f(piVar12,uVar4);
  }
  (**(code **)(*param_1 + 0x168))();
  return 1;
}

