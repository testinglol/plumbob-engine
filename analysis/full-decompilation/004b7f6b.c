
int FUN_004b7f6b(int param_1,int param_2,int param_3,int param_4,undefined4 param_5,char param_6)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  ushort uVar5;
  ushort *puVar6;
  ushort *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined4 local_44;
  int local_40;
  int local_3c;
  undefined2 local_38;
  undefined2 local_36;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined2 local_1c;
  undefined4 local_1a;
  undefined2 local_16;
  undefined2 local_14;
  undefined4 local_12;
  int local_c;
  int local_8;
  
  local_40 = param_3;
  uVar1 = param_3 * 3 + 3U & 0xfffffffc;
  local_1c = 0x4d42;
  local_1a = 0;
  local_16 = 0;
  local_14 = 0;
  local_12 = 0x36;
  local_44 = 0x28;
  local_3c = param_4;
  local_38 = 1;
  local_36 = 0x18;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_c = FUN_0041ffd9(uVar1 * param_4 + 0x36);
  if (local_c == 0) {
    local_c = 0;
  }
  else {
    iVar2 = FUN_00420048(local_c);
    FUN_00636510(iVar2,&local_1c,0xe);
    FUN_00636510(iVar2 + 0xe,&local_44,0x28);
    puVar7 = (ushort *)(param_1 + (param_4 + -1) * param_2 * 2);
    if (*(int *)(DAT_006e486c + 0x34) == 1) {
      if (0 < param_4) {
        puVar4 = (undefined1 *)(iVar2 + 0x37);
        local_8 = param_4;
        do {
          if (0 < param_3) {
            _param_6 = param_3;
            puVar6 = puVar7;
            puVar8 = puVar4;
            do {
              uVar3 = FUN_00438f76(*puVar6);
              puVar8[1] = (char)((uint)uVar3 >> 0x10);
              *puVar8 = (char)((uint)uVar3 >> 8);
              puVar8[-1] = (char)uVar3;
              puVar6 = puVar6 + 1;
              puVar8 = puVar8 + 3;
              _param_6 = _param_6 + -1;
            } while (_param_6 != 0);
          }
          puVar4 = puVar4 + uVar1;
          local_8 = local_8 + -1;
          puVar7 = puVar7 + -param_2;
        } while (local_8 != 0);
        local_8 = 0;
      }
    }
    else if (param_6 == '\0') {
      if (0 < param_4) {
        puVar4 = (undefined1 *)(iVar2 + 0x37);
        local_8 = param_4;
        do {
          if (0 < param_3) {
            _param_6 = param_3;
            puVar6 = puVar7;
            puVar8 = puVar4;
            do {
              uVar3 = FUN_00438f9b(*puVar6);
              puVar8[1] = (char)((uint)uVar3 >> 0x10);
              *puVar8 = (char)((uint)uVar3 >> 8);
              puVar8[-1] = (char)uVar3;
              puVar6 = puVar6 + 1;
              puVar8 = puVar8 + 3;
              _param_6 = _param_6 + -1;
            } while (_param_6 != 0);
          }
          puVar4 = puVar4 + uVar1;
          local_8 = local_8 + -1;
          puVar7 = puVar7 + -param_2;
        } while (local_8 != 0);
      }
    }
    else if (0 < param_4) {
      puVar4 = (undefined1 *)(iVar2 + 0x37);
      local_8 = param_4;
      do {
        if (0 < param_3) {
          _param_6 = param_3;
          puVar8 = puVar4;
          puVar6 = puVar7;
          puVar9 = puVar4;
          do {
            uVar5 = (ushort)((uint)puVar8 >> 0x10);
            puVar8 = (undefined1 *)
                     FUN_00438f76(CONCAT22(uVar5 >> 1,(short)(CONCAT22(uVar5,*puVar6) >> 1)) &
                                  0xffff7fe0 | *puVar6 & 0x1f);
            puVar9[1] = (char)((uint)puVar8 >> 0x10);
            *puVar9 = (char)((uint)puVar8 >> 8);
            puVar9[-1] = (char)puVar8;
            puVar6 = puVar6 + 1;
            puVar9 = puVar9 + 3;
            _param_6 = _param_6 + -1;
          } while (_param_6 != 0);
        }
        puVar4 = puVar4 + uVar1;
        local_8 = local_8 + -1;
        puVar7 = puVar7 + -param_2;
      } while (local_8 != 0);
      local_8 = 0;
    }
    FUN_0042004f(local_c);
  }
  return local_c;
}

