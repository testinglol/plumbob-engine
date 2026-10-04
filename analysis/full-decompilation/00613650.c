
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00613650(undefined4 param_1,int *param_2,double param_3,undefined1 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  double dVar1;
  double dVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  uint uVar11;
  int iVar12;
  undefined4 *local_ec;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 uStack_c4;
  byte local_c0;
  undefined1 uStack_bf;
  byte bStack_be;
  byte bStack_bd;
  double local_b8;
  int local_ac;
  double local_a8;
  double local_a0;
  double local_98;
  undefined1 local_8c;
  undefined1 uStack_8b;
  byte bStack_8a;
  undefined1 uStack_89;
  int local_84;
  int local_80;
  int local_7c;
  double local_78;
  undefined1 local_70;
  undefined1 uStack_6f;
  byte bStack_6e;
  byte bStack_6d;
  double local_68;
  undefined1 local_60;
  undefined1 uStack_5f;
  byte bStack_5e;
  undefined1 uStack_5d;
  double local_58;
  double local_50;
  int local_44;
  double local_40;
  double local_38;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  undefined8 local_18;
  undefined8 local_10;
  
  local_ac = *param_2;
  local_7c = 0;
  if (0 < *(int *)(local_ac + 0x14)) {
    do {
      local_ec = (undefined4 *)(param_2[2] * local_7c + param_2[1]);
      local_80 = 0;
      if (0 < *(int *)(local_ac + 0x10)) {
        local_18 = (double)local_7c;
        local_10 = -param_3;
        do {
          local_a0 = (double)local_80;
          local_44 = 1;
          local_84 = 1;
          local_c8 = (undefined4)local_18;
          uStack_c4 = local_18._4_4_;
          FUN_00613fe0(&local_a0,&local_c8,-DAT_006ff43c,-DAT_006ff440);
          FUN_00613520(&local_a0,&local_c8,(undefined4)local_10,local_10._4_4_);
          iVar7 = __ftol();
          iVar8 = __ftol();
          iVar12 = iVar7 + 1;
          if (local_a0 < _DAT_006669e8) {
            iVar12 = iVar7 + -1;
          }
          iVar9 = iVar8 + 1;
          if ((double)CONCAT44(uStack_c4,local_c8) < _DAT_006669e8) {
            iVar9 = iVar8 + -1;
          }
          local_98 = (double)CONCAT44(local_98._4_4_,iVar9);
          local_24 = iVar12;
          uVar10 = FUN_00614000(param_1,iVar7,iVar8,&local_20,param_6);
          local_8c = (undefined1)uVar10;
          uStack_8b = (undefined1)((uint)uVar10 >> 8);
          bStack_8a = (byte)((uint)uVar10 >> 0x10);
          uStack_89 = (undefined1)((uint)uVar10 >> 0x18);
          uVar10 = FUN_00614000(param_1,local_24,iVar8,&local_28,param_6);
          local_60 = (undefined1)uVar10;
          uStack_5f = (undefined1)((uint)uVar10 >> 8);
          bStack_5e = (byte)((uint)uVar10 >> 0x10);
          uStack_5d = (undefined1)((uint)uVar10 >> 0x18);
          uVar11 = FUN_00614000(param_1,iVar7,local_98._0_4_,&local_1c,param_6);
          local_70 = (undefined1)uVar11;
          uStack_6f = (undefined1)(uVar11 >> 8);
          bStack_6e = (byte)(uVar11 >> 0x10);
          bStack_6d = (byte)(uVar11 >> 0x18);
          uVar10 = FUN_00614000(param_1,iVar12,iVar9,&local_2c,param_6);
          local_c0 = (byte)uVar10;
          uStack_bf = (undefined1)((uint)uVar10 >> 8);
          bStack_be = (byte)((uint)uVar10 >> 0x10);
          bStack_bd = (byte)((uint)uVar10 >> 0x18);
          if (local_a0 < _DAT_006669e8) {
            iVar12 = __ftol();
            dVar1 = _DAT_00667280 - (local_a0 - (double)iVar12);
          }
          else {
            iVar12 = __ftol();
            dVar1 = local_a0 - (double)iVar12;
          }
          if ((double)CONCAT44(uStack_c4,local_c8) < _DAT_006669e8) {
            iVar12 = __ftol();
            local_98 = _DAT_00667280 - ((double)CONCAT44(uStack_c4,local_c8) - (double)iVar12);
          }
          else {
            iVar12 = __ftol();
            local_98 = (double)CONCAT44(uStack_c4,local_c8) - (double)iVar12;
          }
          iVar12 = local_44;
          if (local_20 == 0) {
            if (local_28 == 0) {
              local_78 = 0.0;
              local_68 = 0.0;
              iVar12 = 0;
            }
            else {
              local_78 = (double)bStack_5e;
              local_68 = (double)(CONCAT11(bStack_5e,uStack_5f) & 0xff);
            }
          }
          else if (local_28 == 0) {
            local_78 = (double)bStack_8a;
            local_68 = (double)(CONCAT11(bStack_8a,uStack_8b) & 0xff);
          }
          else {
            local_78 = (double)bStack_8a * (_DAT_00667280 - dVar1) + (double)bStack_5e * dVar1;
            local_68 = (double)(CONCAT11(bStack_8a,uStack_8b) & 0xff) * (_DAT_00667280 - dVar1) +
                       (double)(CONCAT11(bStack_5e,uStack_5f) & 0xff) * dVar1;
          }
          iVar7 = local_84;
          if (local_1c == 0) {
            if (local_2c == 0) {
              local_38 = 0.0;
              local_50 = 0.0;
              local_40 = 0.0;
              local_58 = 0.0;
              iVar7 = 0;
            }
            else {
              local_38 = (double)bStack_bd;
              local_50 = (double)bStack_be;
              local_40 = (double)(CONCAT11(bStack_be,uStack_bf) & 0xff);
              local_58 = (double)local_c0;
            }
          }
          else if (local_2c == 0) {
            local_38 = (double)bStack_6d;
            local_50 = (double)bStack_6e;
            local_40 = (double)(CONCAT11(bStack_6e,uStack_6f) & 0xff);
            local_58 = (double)(uVar11 & 0xff);
          }
          else {
            dVar2 = _DAT_00667280 - dVar1;
            local_38 = (double)bStack_6d * dVar2 + (double)bStack_bd * dVar1;
            local_50 = (double)bStack_6e * dVar2 + (double)bStack_be * dVar1;
            local_40 = (double)(CONCAT11(bStack_6e,uStack_6f) & 0xff) * dVar2 +
                       (double)(CONCAT11(bStack_be,uStack_bf) & 0xff) * dVar1;
            local_58 = (double)(uVar11 & 0xff) * dVar2 + (double)local_c0 * dVar1;
          }
          if (iVar12 == 0) {
            if (iVar7 == 0) {
              local_b8 = 0.0;
              local_a8 = 0.0;
            }
            else {
              local_b8 = local_50;
              local_a8 = local_40;
            }
          }
          else if (iVar7 == 0) {
            local_b8 = local_78;
            local_a8 = local_68;
          }
          else {
            local_b8 = local_50 * local_98 + (_DAT_00667280 - local_98) * local_78;
            local_a8 = local_40 * local_98 + (_DAT_00667280 - local_98) * local_68;
          }
          uVar3 = __ftol();
          uVar4 = __ftol();
          uVar5 = __ftol();
          uVar6 = __ftol();
          local_cc = CONCAT31(CONCAT21(CONCAT11(uVar3,uVar4),uVar5),uVar6);
          if (*(int *)(local_ac + 0x18) < 9) {
            if ((iVar12 == 0) && (iVar7 == 0)) {
              *(undefined1 *)local_ec = param_4;
            }
            else {
              uVar3 = FUN_006140a0(param_2,local_cc);
              *(undefined1 *)local_ec = uVar3;
            }
            local_ec = (undefined4 *)((int)local_ec + 1);
          }
          else if ((iVar12 == 0) && (iVar7 == 0)) {
            *local_ec = param_5;
            local_ec = local_ec + 1;
          }
          else {
            *local_ec = local_cc;
            local_ec = local_ec + 1;
          }
          local_ac = *param_2;
          local_80 = local_80 + 1;
        } while (local_80 < *(int *)(local_ac + 0x10));
      }
      local_ac = *param_2;
      local_7c = local_7c + 1;
    } while (local_7c < *(int *)(local_ac + 0x14));
  }
  return;
}

