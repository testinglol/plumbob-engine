
void FUN_004c0b84(int *param_1,int *param_2,ushort *param_3,int param_4,int param_5,int param_6)

{
  ushort uVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  ushort *puVar6;
  undefined2 *puVar7;
  ushort *puVar8;
  ushort *puVar9;
  uint local_14;
  ushort *local_10;
  undefined2 *local_c;
  undefined2 *local_8;
  
  puVar9 = param_3 + 8;
  local_c = (undefined2 *)(*param_1 + -2 + (uint)*param_3 * 2);
  local_10 = (ushort *)(*param_2 + -2 + (uint)*param_3 * 2);
  do {
    while( true ) {
      while( true ) {
        uVar1 = *puVar9;
        uVar3 = uVar1 & 0x1fff;
        uVar5 = uVar1 & 0xe000;
        puVar9 = puVar9 + 1;
        if ((uVar1 & 0xe000) != 0) break;
        local_8 = local_c;
        param_3 = local_10;
        local_c = local_c + param_1[1];
        local_10 = local_10 + param_2[1];
      }
      local_14 = uVar3;
      if (uVar5 == 0x2000) break;
      if (uVar5 == 0x4000) {
        if ((uVar1 & 0x1fff) != 0) {
          puVar7 = local_8;
          do {
            uVar1 = *(ushort *)(((int)param_3 - (int)local_8) + (int)puVar7);
            if (*(short *)(param_6 + (uint)(byte)*puVar9 * 2) + param_5 <= (int)(uint)uVar1) {
              uVar2 = FUN_0049a996(CONCAT11((char)(uVar1 >> 8),(byte)puVar9[1]));
              *puVar7 = uVar2;
            }
            puVar9 = (ushort *)((int)puVar9 + 3);
            puVar7 = puVar7 + -1;
            local_14 = local_14 - 1;
          } while (local_14 != 0);
        }
        local_8 = local_8 + -uVar3;
        param_3 = param_3 + -uVar3;
        puVar9 = (ushort *)((int)puVar9 + ((uint)puVar9 & 1));
      }
      else {
        if (uVar5 == 0x6000) goto LAB_004c0cde;
        if (uVar5 == 0x8000) {
          if ((uVar1 & 0x1fff) != 0) {
            do {
              local_8 = local_c;
              local_c = local_c + param_1[1];
              param_3 = local_10;
              local_10 = local_10 + param_2[1];
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
      puVar6 = param_3;
      puVar8 = puVar9;
      do {
        iVar4 = *(short *)(param_6 + (uint)(byte)*puVar8 * 2) + param_5;
        if (iVar4 <= (int)(uint)*puVar6) {
          *puVar6 = (ushort)iVar4;
          *(undefined2 *)(((int)local_8 - (int)param_3) + (int)puVar6) =
               *(undefined2 *)(param_4 + (uint)*(byte *)((int)puVar8 + 1) * 2);
        }
        puVar8 = puVar8 + 1;
        puVar6 = puVar6 + -1;
        local_14 = local_14 - 1;
      } while (local_14 != 0);
    }
    puVar9 = puVar9 + uVar3;
LAB_004c0cde:
    local_8 = local_8 + -uVar3;
    param_3 = param_3 + -uVar3;
  } while( true );
}

