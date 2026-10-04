
void FUN_004bfe8b(undefined4 *param_1,int *param_2,undefined2 *param_3,int param_4,int param_5,
                 int param_6)

{
  ushort uVar1;
  undefined2 uVar2;
  uint uVar3;
  ushort *puVar4;
  uint uVar5;
  int iVar6;
  undefined2 *puVar7;
  ushort *puVar8;
  uint local_14;
  int local_10;
  undefined2 *local_c;
  int local_8;
  
  puVar8 = param_3 + 8;
  local_c = (undefined2 *)*param_1;
  local_10 = *param_2;
  do {
    while( true ) {
      while( true ) {
        uVar1 = *puVar8;
        uVar3 = uVar1 & 0x1fff;
        uVar5 = uVar1 & 0xe000;
        puVar8 = puVar8 + 1;
        if ((uVar1 & 0xe000) != 0) break;
        param_3 = local_c;
        local_8 = local_10;
        local_c = local_c + param_1[1];
        local_10 = local_10 + param_2[1] * 2;
      }
      local_14 = uVar3;
      if (uVar5 == 0x2000) break;
      if (uVar5 == 0x4000) {
        if ((uVar1 & 0x1fff) != 0) {
          puVar7 = param_3;
          do {
            uVar1 = *(ushort *)((local_8 - (int)param_3) + (int)puVar7);
            if (*(short *)(param_6 + (uint)(byte)*puVar8 * 2) + param_5 <= (int)(uint)uVar1) {
              uVar2 = FUN_0049a775(CONCAT11((char)(uVar1 >> 8),(byte)puVar8[1]));
              *puVar7 = uVar2;
            }
            puVar8 = (ushort *)((int)puVar8 + 3);
            puVar7 = puVar7 + 1;
            local_14 = local_14 - 1;
          } while (local_14 != 0);
        }
        param_3 = param_3 + uVar3;
        local_8 = local_8 + uVar3 * 2;
        puVar8 = (ushort *)((int)puVar8 + ((uint)puVar8 & 1));
      }
      else {
        if (uVar5 == 0x6000) goto LAB_004bffda;
        if (uVar5 == 0x8000) {
          if ((uVar1 & 0x1fff) != 0) {
            do {
              param_3 = local_c;
              local_c = local_c + param_1[1];
              local_8 = local_10;
              local_10 = local_10 + param_2[1] * 2;
              uVar3 = uVar3 - 1;
            } while (uVar3 != 0);
          }
        }
        else if (uVar5 == 0xa000) {
          return;
        }
      }
    }
    if ((uVar1 & 0x1fff) != 0) {
      puVar4 = puVar8;
      do {
        iVar6 = *(short *)(param_6 + (uint)(byte)*puVar4 * 2) + param_5;
        if (iVar6 <= (int)(uint)*(ushort *)((local_8 - (int)puVar8) + (int)puVar4)) {
          *(short *)((local_8 - (int)puVar8) + (int)puVar4) = (short)iVar6;
          *(undefined2 *)(((int)param_3 - (int)puVar8) + (int)puVar4) =
               *(undefined2 *)(param_4 + (uint)*(byte *)((int)puVar4 + 1) * 2);
        }
        puVar4 = puVar4 + 1;
        local_14 = local_14 - 1;
      } while (local_14 != 0);
    }
    puVar8 = puVar8 + uVar3;
LAB_004bffda:
    param_3 = param_3 + uVar3;
    local_8 = local_8 + uVar3 * 2;
  } while( true );
}

