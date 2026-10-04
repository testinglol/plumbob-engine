
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_005d52b1(int *param_1)

{
  uint uVar1;
  undefined8 uVar2;
  int iVar3;
  uint *puVar4;
  uint local_44;
  uint uStack_40;
  float fStack_3c;
  uint uStack_38;
  uint local_34;
  uint local_30;
  char *local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  char *local_1c;
  uint uStack_18;
  uint *local_14;
  int local_10;
  uint uStack_c;
  uint local_8;
  
  if (DAT_006fe8b0 != '\0') {
    uVar2 = rdtsc();
    local_20 = (uint)((ulonglong)uVar2 >> 0x20);
    local_24 = (uint)uVar2;
    uStack_18 = 0;
    local_1c = s_TP__PerTickProcessing_006d6e0c;
    uStack_c = local_24;
    local_8 = local_20;
    FUN_004b406a(&local_24);
    FUN_005d5544(param_1[9],param_1[10]);
    local_34 = param_1[0xc];
    local_30 = param_1[0xd];
    local_14 = (uint *)(param_1 + 0xc);
    uVar1 = *(uint *)*param_1;
    local_10 = uVar1 - local_34;
    uStack_c = (((uint *)*param_1)[1] - local_30) - (uint)(uVar1 < local_34);
    local_28 = param_1[0xe];
    local_2c = (char *)(float)(((float10)CONCAT44(uStack_c,local_10) / (float10)_DAT_006fe8a8) *
                              (float10)_DAT_00667890);
    local_24 = local_34;
    local_20 = local_30;
    local_1c = local_2c;
    uStack_18 = local_28;
    FUN_005d5519(&local_34);
    iVar3 = *param_1;
    uStack_c = 1;
    if (1 < (uint)(param_1[1] - iVar3 >> 4)) {
      local_8 = 0x10;
      do {
        puVar4 = (uint *)(iVar3 + local_8);
        local_44 = puVar4[-4];
        uStack_40 = puVar4[-3];
        local_1c = (char *)(*puVar4 - local_44);
        uStack_18 = (puVar4[1] - uStack_40) - (uint)(*puVar4 < local_44);
        uStack_38 = puVar4[-2];
        fStack_3c = (float)(((float10)CONCAT44(uStack_18,local_1c) / (float10)_DAT_006fe8a8) *
                           (float10)_DAT_00667890);
        local_34 = local_44;
        local_30 = uStack_40;
        local_2c = (char *)fStack_3c;
        local_28 = uStack_38;
        FUN_005d5519(&local_44);
        iVar3 = *param_1;
        uStack_c = uStack_c + 1;
        local_8 = local_8 + 0x10;
      } while (uStack_c < (uint)(param_1[1] - iVar3 >> 4));
    }
    FUN_005d5544(*param_1,param_1[1]);
    FUN_005bfaad(param_1 + 3);
    FUN_005d5544(param_1[3],param_1[4]);
    uVar2 = rdtsc();
    local_30 = (uint)((ulonglong)uVar2 >> 0x20);
    local_34 = (uint)uVar2;
    local_28 = 0;
    local_2c = s_TP__Done_006d6e00;
    *local_14 = local_34;
    local_14[1] = local_30;
    local_14[2] = (uint)s_TP__Done_006d6e00;
    local_14[3] = 0;
    uVar2 = rdtsc();
    local_20 = (uint)((ulonglong)uVar2 >> 0x20);
    local_24 = (uint)uVar2;
    uStack_18 = 0;
    local_1c = s_TP__SystemOverhead_006d6dec;
    local_14 = (uint *)local_24;
    uStack_c = local_20;
    local_8 = local_30;
    FUN_004b406a(&local_24);
  }
  return;
}

