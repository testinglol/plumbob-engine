
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_0055f7ea(int *param_1)

{
  uint *puVar1;
  uint uVar2;
  float fVar3;
  char cVar4;
  uint uVar5;
  undefined4 uVar6;
  int *piVar7;
  DWORD DVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int *piVar12;
  undefined1 local_a8 [16];
  undefined1 local_98 [16];
  undefined1 local_88 [16];
  undefined1 local_78 [16];
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  uint local_30;
  int *piStack_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  char local_5;
  
  local_5 = '\0';
  uVar5 = *(uint *)(param_1[0x36] + 0x1c);
  uVar2 = *(uint *)(param_1[0x36] + 0x20);
  local_64 = 0;
  local_68 = 0x177;
  local_60 = 800;
  local_5c = 400;
  local_58 = 0x235;
  local_54 = 400;
  local_50 = 800;
  local_4c = 600;
  if (uVar5 < (uint)(param_1[0x21] - param_1[0x1f])) {
    uVar5 = (param_1[0x21] - param_1[0x1f]) - uVar5 >> 1;
  }
  else {
    uVar5 = 0;
  }
  puVar1 = (uint *)(param_1 + 0x3b);
  *puVar1 = uVar5;
  if (uVar2 < (uint)(param_1[0x22] - param_1[0x20])) {
    uVar5 = (param_1[0x22] - param_1[0x20]) - uVar2 >> 1;
  }
  else {
    uVar5 = 0;
  }
  param_1[0x3c] = uVar5;
  uVar6 = (**(code **)(*DAT_006fe8bc + 0x1c))
                    (0,&cITSGraphicSystem::RTTI_Type_Descriptor,
                     &cTSGraphicSystemW95::RTTI_Type_Descriptor,0);
  local_48 = FUN_006359f2(uVar6);
  if (param_1[99] < 0) {
    uVar6 = FUN_004b469d();
    FUN_005caf21(uVar6);
    FUN_005cddcf(uVar6);
  }
  piVar7 = (int *)FUN_005caf21();
  if ((piVar7[1] - *piVar7 & 0xfffffff0U) != 0) {
    piStack_2c = (int *)FUN_005caf21();
    for (iVar9 = *piStack_2c; local_44 = iVar9, iVar9 != piStack_2c[1]; iVar9 = iVar9 + 0x10) {
      FUN_005de822(iVar9);
      local_40 = local_28;
      local_3c = local_24;
      local_38 = local_20;
      local_34 = local_1c;
      FUN_004df599(local_88,puVar1);
      FUN_005de841(&local_40,local_88);
      cVar4 = (**(code **)(*(int *)param_1[0x17] + 0x20))(0x10);
      if (cVar4 != '\0') {
        if (800 < param_1[0x21] - param_1[0x1f]) {
          (**(code **)(*(int *)param_1[0x17] + 0x9c))(param_1[0x37],&local_28,&local_28,0);
        }
        if ((local_40 < local_38) && (local_3c < local_34)) {
          uVar10 = 0;
          iVar9 = *(int *)param_1[0x17];
          piVar7 = &local_40;
          uVar6 = FUN_0053a19c(local_98,puVar1);
          (**(code **)(iVar9 + 0x9c))(param_1[0x36],uVar6,piVar7,uVar10);
          iVar9 = local_44;
        }
      }
      piVar7 = (int *)FUN_004b46a0();
      (**(code **)(*piVar7 + 0x170))(&local_28);
      local_18 = local_28;
      local_14 = local_24;
      local_10 = local_20;
      local_c = local_1c;
      uVar6 = FUN_004df599(local_a8,puVar1);
      FUN_005de841(&local_18,uVar6);
      if ((local_18 < local_10) && (local_14 < local_c)) {
LAB_0055fa5d:
        local_5 = '\x01';
      }
      else {
        local_18 = local_28;
        local_14 = local_24;
        local_10 = local_20;
        local_c = local_1c;
        uVar6 = FUN_004df599(local_78,puVar1);
        FUN_005de841(&local_18,uVar6);
        if ((local_18 < local_10) && (local_14 < local_c)) goto LAB_0055fa5d;
      }
    }
  }
  iVar9 = param_1[0x68];
  DVar8 = timeGetTime();
  local_30 = DVar8 - iVar9;
  piStack_2c = (int *)0x0;
  fVar3 = _DAT_006687a0 / (float)local_30;
  if (fVar3 <= (float)param_1[0x67]) {
    param_1[99] = param_1[99] + 1;
    param_1[0x68] = iVar9 + local_30;
  }
  if (param_1[99] == 4) {
    param_1[99] = 0;
  }
  if ((((fVar3 <= (float)param_1[0x67]) || (local_5 != '\0')) && (0 < param_1[99])) &&
     (param_1[param_1[99] + 99] != 0)) {
    uVar6 = 0x10;
    cVar4 = (**(code **)(*(int *)param_1[0x17] + 0x20))(0x10);
    if (cVar4 != '\0') {
      uVar11 = 0;
      iVar9 = param_1[param_1[99] + 99];
      piStack_2c = *(int **)param_1[0x17];
      uVar10 = FUN_004e84f4(local_78,param_1[0x36] + 0x14);
      (**(code **)((int)piStack_2c + 0x9c))(param_1[param_1[99] + 99],iVar9 + 0x14,uVar10,uVar11);
      (**(code **)(*(int *)param_1[0x17] + 0x24))(0x10);
    }
    piVar7 = (int *)(local_48 + 0x48);
    piVar12 = param_1;
    uVar10 = FUN_004df599(local_78,param_1 + 0x3b);
    (**(code **)(*piVar7 + 0x24))(uVar10,piVar12);
    FUN_005ecd7f(uVar10,piVar12);
    piVar12 = param_1;
    uVar10 = FUN_004df599(local_78,param_1 + 0x3b);
    (**(code **)(*piVar7 + 0x24))(uVar10,piVar12);
    FUN_005ecd7f(piVar12,uVar6);
  }
  (**(code **)(*param_1 + 0x168))();
  return 1;
}

