
void FUN_004bf8da(int *param_1,undefined4 *param_2,ushort *param_3,undefined4 param_4,int param_5,
                 int param_6)

{
  ushort uVar1;
  ushort *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  ushort *puVar7;
  byte bVar8;
  ushort *puVar9;
  uint local_1c;
  int local_18;
  int local_c;
  int local_8;
  
  puVar7 = param_3 + 8;
  local_c = 2;
  local_18 = *param_1;
  puVar2 = (ushort *)*param_2;
  do {
    while( true ) {
      while( true ) {
        while( true ) {
          while( true ) {
            while( true ) {
              uVar1 = *puVar7;
              uVar3 = uVar1 & 0x1fff;
              uVar5 = uVar1 & 0xe000;
              puVar7 = puVar7 + 1;
              if ((uVar1 & 0xe000) != 0) break;
              param_3 = puVar2;
              local_8 = local_18;
              local_18 = local_18 + param_1[1] * 2;
              puVar2 = puVar2 + param_2[1];
            }
            local_1c = uVar3;
            if (uVar5 != 0x2000) break;
            if ((uVar1 & 0x1fff) != 0) {
              puVar9 = param_3;
              do {
                iVar4 = *(short *)(param_6 + (uint)(byte)*puVar7 * 2) + param_5;
                if (iVar4 <= (int)(uint)*puVar9) {
                  *puVar9 = (ushort)iVar4;
                  *(undefined2 *)((int)puVar9 + (local_8 - (int)param_3)) = 0xffff;
                }
                puVar7 = (ushort *)((int)puVar7 + local_c);
                puVar9 = puVar9 + 1;
                local_1c = local_1c - 1;
              } while (local_1c != 0);
            }
            local_c = 2;
            local_8 = local_8 + uVar3 * 2;
            puVar7 = (ushort *)((int)puVar7 + ((uint)puVar7 & 1));
            param_3 = param_3 + uVar3;
          }
          if (uVar5 != 0x4000) break;
          if ((uVar1 & 0x1fff) != 0) {
            puVar9 = param_3;
            do {
              iVar4 = *(short *)(param_6 + (uint)(byte)*puVar7 * 2) + param_5;
              if (iVar4 <= (int)(uint)*puVar9) {
                *puVar9 = (ushort)iVar4;
                bVar8 = (byte)puVar7[1] >> 3;
                *(ushort *)((local_8 - (int)param_3) + (int)puVar9) =
                     ((ushort)(byte)((byte)puVar7[1] >> 2) | (ushort)bVar8 << 6) << 5 |
                     (ushort)bVar8;
              }
              puVar7 = (ushort *)((int)puVar7 + local_c);
              puVar9 = puVar9 + 1;
              local_1c = local_1c - 1;
            } while (local_1c != 0);
          }
          local_c = 3;
          local_8 = local_8 + uVar3 * 2;
          puVar7 = (ushort *)((int)puVar7 + ((uint)puVar7 & 1));
          param_3 = param_3 + uVar3;
        }
        if (uVar5 != 0x6000) break;
        local_8 = local_8 + uVar3 * 2;
        param_3 = param_3 + uVar3;
      }
      if (uVar5 != 0x8000) break;
      iVar6 = param_2[1] * (uVar3 - 1);
      iVar4 = param_1[1] * (uVar3 - 1);
      local_8 = local_8 + iVar4 * 2;
      param_3 = param_3 + iVar6;
      local_18 = local_18 + (param_1[1] + iVar4) * 2;
      puVar2 = puVar2 + param_2[1] + iVar6;
    }
  } while (uVar5 != 0xa000);
  return;
}

