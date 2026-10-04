
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_0056558c(int *param_1)

{
  uint *puVar1;
  int *piVar2;
  char cVar3;
  undefined4 uVar4;
  int *piVar5;
  DWORD DVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  undefined1 local_a0 [16];
  undefined1 local_90 [16];
  undefined1 local_80 [16];
  undefined1 local_70 [16];
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  uint local_10;
  uint uStack_c;
  uint *local_8;
  
  local_8 = *(uint **)(param_1[0xee] + 0x1c);
  uStack_c = *(uint *)(param_1[0xee] + 0x20);
  local_50 = 400;
  local_4c = 0x15e;
  local_48 = 800;
  local_44 = 600;
  local_60 = 400;
  local_5c = 0x15e;
  local_58 = 800;
  local_54 = 600;
  if (local_8 < (uint *)(param_1[0x21] - param_1[0x1f])) {
    uVar7 = (uint)((param_1[0x21] - param_1[0x1f]) - (int)local_8) >> 1;
  }
  else {
    uVar7 = 0;
  }
  puVar1 = (uint *)(param_1 + 0xf4);
  *puVar1 = uVar7;
  if (uStack_c < (uint)(param_1[0x22] - param_1[0x20])) {
    uVar7 = (param_1[0x22] - param_1[0x20]) - uStack_c >> 1;
  }
  else {
    uVar7 = 0;
  }
  param_1[0xf5] = uVar7;
  uVar4 = (**(code **)(*DAT_006fe8bc + 0x1c))
                    (0,&cITSGraphicSystem::RTTI_Type_Descriptor,
                     &cTSGraphicSystemW95::RTTI_Type_Descriptor,0);
  FUN_006359f2(uVar4);
  if (param_1[0x114] < 0) {
    uVar4 = FUN_004b469d();
    FUN_005caf21(uVar4);
    FUN_005cddcf(uVar4);
  }
  piVar5 = (int *)FUN_005caf21();
  if ((piVar5[1] - *piVar5 & 0xfffffff0U) != 0) {
    local_8 = (uint *)FUN_005caf21();
    for (uVar7 = *local_8; uStack_c = uVar7, uVar7 != local_8[1]; uVar7 = uVar7 + 0x10) {
      FUN_005de822(uVar7);
      local_40 = local_30;
      local_3c = local_2c;
      local_38 = local_28;
      local_34 = local_24;
      FUN_004df599(local_70,puVar1);
      FUN_005de841(&local_40,local_70);
      cVar3 = (**(code **)(*(int *)param_1[0x17] + 0x20))(0x10);
      if (cVar3 != '\0') {
        if ((local_40 < local_38) && (local_3c < local_34)) {
          uVar10 = 0;
          iVar8 = *(int *)param_1[0x17];
          piVar5 = &local_40;
          uVar4 = FUN_0053a19c(local_80,puVar1);
          (**(code **)(iVar8 + 0x9c))(param_1[0xee],uVar4,piVar5,uVar10);
          uVar7 = uStack_c;
        }
        (**(code **)(*(int *)param_1[0x17] + 0x24))(0x10);
      }
      piVar5 = (int *)FUN_004b46a0();
      (**(code **)(*piVar5 + 0x170))(&local_30);
      local_20 = local_30;
      local_1c = local_2c;
      local_18 = local_28;
      local_14 = local_24;
      uVar4 = FUN_004df599(local_90,puVar1);
      FUN_005de841(&local_20,uVar4);
      if ((local_18 <= local_20) || (local_14 <= local_1c)) {
        local_20 = local_30;
        local_1c = local_2c;
        local_18 = local_28;
        local_14 = local_24;
        uVar4 = FUN_004df599(local_a0,puVar1);
        FUN_005de841(&local_20,uVar4);
      }
    }
  }
  DVar6 = timeGetTime();
  uStack_c = 0;
  local_10 = DVar6 - param_1[0x116];
  *(undefined1 *)(param_1 + 0xda) = 0;
  if (_DAT_006687a0 / (float)local_10 <= (float)param_1[0x115]) {
    param_1[0x114] = param_1[0x114] + 1;
    piVar5 = param_1 + 0x5e;
    iVar8 = 6;
    do {
      iVar9 = 0;
      if (0 < *piVar5) {
        do {
          piVar2 = (int *)(piVar5[-0xd] + iVar9 * 4);
          *piVar2 = *piVar2 + 1;
          iVar9 = iVar9 + 1;
        } while (iVar9 < *piVar5);
      }
      piVar5 = piVar5 + 0x18;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    param_1[0x116] = param_1[0x116] + local_10;
    *(undefined1 *)(param_1 + 0xda) = 1;
  }
  if (param_1[0x114] == 10) {
    param_1[0x114] = 0;
  }
  (**(code **)(*param_1 + 0x168))();
  return 1;
}

