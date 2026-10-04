
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0049e134(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  int local_4c;
  int local_48;
  int local_44;
  uint local_40;
  float local_3c;
  undefined4 local_38;
  undefined4 local_24;
  undefined4 local_20;
  float local_1c;
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  if (param_2 != *(int *)(param_1 + 0xd8)) {
    *(int *)(param_1 + 0xd8) = param_2;
    local_24 = FUN_0046f546();
    if (*(int *)(param_1 + 0x88) == 0) {
      uVar2 = FUN_0046f546();
      *(undefined4 *)(param_1 + 0x88) = uVar2;
    }
    FUN_0046f54c(*(undefined4 *)(param_1 + 0x88));
    puVar8 = (undefined4 *)(param_1 + 0xe0);
    local_c = 0x20;
    do {
      FUN_0049e67e(*puVar8,puVar8[1]);
      puVar8 = puVar8 + 5;
      local_c = local_c + -1;
    } while (local_c != 0);
    local_14 = (8 << ((byte)param_2 & 0x1f)) / 4;
    local_10 = ((local_14 + -1) * local_14 * 0x10) / 2 + local_14 * 8;
    iVar3 = *(int *)(param_1 + 0xd4) * 4;
    *(int *)(param_1 + 0xdc) = iVar3;
    if (iVar3 < 500) {
      *(undefined4 *)(param_1 + 0xdc) = 500;
    }
    local_c = 0;
    if (0 < *(int *)(param_1 + 0xdc)) {
      do {
        iVar1 = local_10;
        iVar3 = local_14;
        uVar4 = FUN_0046f556();
        uVar4 = uVar4 % (uint)(iVar1 * 2);
        iVar7 = (int)uVar4 % iVar1;
        iVar9 = 0;
        if (0 < iVar7) {
          iVar5 = 8;
          do {
            if (iVar7 < iVar5) break;
            iVar7 = iVar7 - iVar5;
            iVar9 = iVar9 + 1;
            iVar5 = iVar5 + 0x10;
          } while (0 < iVar7);
        }
        if (iVar1 <= (int)uVar4) {
          iVar9 = (iVar3 * 2 - iVar9) + -1;
        }
        uVar4 = FUN_0046f556();
        local_8 = FUN_0046f556();
        local_8 = local_8 % 0xfa1;
        local_1c = (float)local_8 * (float)_DAT_00668428;
        local_20 = FUN_0049e2f6();
        local_8 = 0;
        if (*(char *)(param_1 + 0x82) != '\0') {
          local_8 = *(uint *)(s_Lights_006c6278 + param_2 * 4 + 4);
        }
        uVar6 = local_8;
        if (1 < (int)local_8) {
          local_18 = FUN_0046f556();
          uVar6 = local_8 - local_18 % (uint)((int)local_8 / 2);
        }
        local_3c = local_1c;
        local_48 = local_c;
        local_38 = local_20;
        local_4c = iVar9;
        local_44 = uVar6;
        local_40 = uVar4 & 3;
        FUN_0049e64e(&local_4c);
        local_c = local_c + 1;
      } while (local_c < *(int *)(param_1 + 0xdc));
    }
    FUN_0046f54c(local_24);
  }
  return;
}

