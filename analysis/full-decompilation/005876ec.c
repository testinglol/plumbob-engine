
void __thiscall FUN_005876ec(undefined4 param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined ***pppuVar3;
  undefined **local_500 [3];
  undefined1 local_4f4 [256];
  undefined **local_3f4;
  undefined4 local_3f0;
  undefined1 local_3e8 [256];
  undefined **local_2e8 [3];
  undefined1 local_2dc [256];
  undefined **local_1dc [3];
  undefined1 local_1d0 [64];
  undefined **local_190 [3];
  undefined1 local_184 [64];
  undefined **local_144 [3];
  undefined1 local_138 [64];
  undefined **local_f8 [3];
  undefined1 local_ec [64];
  undefined **local_ac [3];
  undefined1 local_a0 [64];
  undefined **local_60;
  int local_5c;
  undefined1 local_54 [64];
  undefined4 local_14;
  int *local_10;
  int *local_c;
  undefined4 *local_8;
  
  if (DAT_006d0688 != -1) {
    local_c = &DAT_006d0688;
    local_14 = param_1;
    do {
      local_10 = local_c;
      local_8 = (undefined4 *)FUN_004705f2(*local_c,0xffffffff);
      FUN_0046f824(local_4f4,0,0x100);
      local_500[0] = &PTR_FUN_00666524;
      FUN_0046f847(local_8,0xffffffff);
      local_c = (int *)FUN_004705f2(*local_c,0xffffffff);
      FUN_0046f824(local_2dc,0,0x100);
      local_2e8[0] = &PTR_FUN_00666524;
      FUN_0046f847(local_c,0xffffffff);
      iVar1 = FUN_0046f973(local_2e8);
      if (iVar1 != 0) {
        FUN_0046f824(local_3e8,0,0x100);
        local_3f4 = &PTR_FUN_00666524;
        uVar2 = FUN_0046fab1(&DAT_006c145c,0);
        FUN_0046f917(local_2e8,uVar2);
        FUN_0046f847(&DAT_006c145c,0xffffffff);
        FUN_0046f917(local_500,0xffffffff);
        FUN_0046f824(local_1d0,0,0x40);
        local_1dc[0] = &PTR_FUN_0066651c;
        FUN_0046f824(local_54,0,0x40);
        local_60 = &PTR_FUN_0066651c;
        FUN_00455edc(*local_10,local_1dc,&local_60,0);
        FUN_0046f824(local_184,0,0x40);
        local_190[0] = &PTR_FUN_0066651c;
        FUN_0046f824(local_ec,0,0x40);
        local_f8[0] = &PTR_FUN_0066651c;
        FUN_00455edc(*local_10,local_190,local_f8,0);
        iVar1 = FUN_0046f973(local_f8);
        if (iVar1 != 0) {
          FUN_0046f824(local_a0,0,0x40);
          local_ac[0] = &PTR_FUN_0066651c;
          local_c = (int *)0x0;
          local_8 = &DAT_006f6b8c;
          do {
            iVar1 = FUN_0046fab1(*local_8,0);
            if (iVar1 == 0) {
              local_c = (int *)((uint)*(ushort *)(&DAT_006f6b90 + (int)local_c * 0x4c) + local_5c);
              FUN_0046f824(local_138,0,0x40);
              local_144[0] = &PTR_FUN_0066651c;
              FUN_0046f847(local_c,0xffffffff);
              pppuVar3 = local_144;
              goto LAB_0058791d;
            }
            local_8 = local_8 + 0x13;
            local_c = (int *)((int)local_c + 1);
          } while ((int)local_8 < 0x6f6c70);
          pppuVar3 = &local_60;
LAB_0058791d:
          FUN_0046f8e4(pppuVar3);
          local_8 = (undefined4 *)*param_3;
          if (local_8 != (undefined4 *)param_3[1]) {
            do {
              iVar1 = FUN_0046f973(local_ac);
              if (iVar1 == 0) break;
              local_8 = (undefined4 *)((int)local_8 + 0x4c);
            } while (local_8 != (undefined4 *)param_3[1]);
            if (local_8 != (undefined4 *)param_3[1]) goto LAB_005879b9;
          }
          FUN_0040f4f6(local_ac);
        }
LAB_005879b9:
        FUN_004704a5(*local_10,local_3f0,0xffffffff);
      }
      local_c = local_10 + 1;
    } while (*local_c != -1);
  }
  return;
}

