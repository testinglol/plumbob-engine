
void FUN_004bfd10(int *param_1,int *param_2,ushort *param_3,int param_4,int param_5,int param_6)

{
  ushort uVar1;
  ushort *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  ushort *puVar6;
  uint uVar7;
  ushort *puVar8;
  uint local_14;
  ushort *local_10;
  int local_c;
  ushort *local_8;
  
  puVar8 = param_3 + 8;
  local_10 = (ushort *)(*param_2 + -2 + (uint)*param_3 * 2);
  puVar2 = (ushort *)(*param_1 + -2 + (uint)*param_3 * 2);
  do {
    while( true ) {
      while( true ) {
        puVar6 = puVar2;
        local_c = 2;
        uVar1 = *puVar8;
        uVar7 = uVar1 & 0x1fff;
        uVar3 = uVar1 & 0xe000;
        puVar8 = puVar8 + 1;
        if ((uVar1 & 0xe000) != 0) break;
        local_8 = local_10;
        local_10 = local_10 + param_2[1];
        puVar2 = puVar6 + param_1[1];
        param_3 = puVar6;
      }
      puVar2 = puVar6;
      if (uVar3 != 0x2000) break;
LAB_004bfddb:
      if (uVar7 < 0x10) {
        if ((uVar1 & 0x1fff) != 0) {
          puVar6 = local_8;
          local_14 = uVar7;
          do {
            iVar4 = *(short *)(param_6 + (uint)(byte)*puVar8 * 2) + param_5;
            if (iVar4 <= (int)(uint)*puVar6) {
              *puVar6 = (ushort)iVar4;
              *(undefined2 *)(((int)param_3 - (int)local_8) + (int)puVar6) =
                   *(undefined2 *)(param_4 + (uint)*(byte *)((int)puVar8 + 1) * 2);
            }
            puVar8 = (ushort *)((int)puVar8 + local_c);
            puVar6 = puVar6 + -1;
            local_14 = local_14 - 1;
          } while (local_14 != 0);
        }
      }
      else {
        FUN_004bcef1(uVar7,puVar8,param_3,local_8,param_4,param_5,param_6,local_c);
        puVar8 = (ushort *)((int)puVar8 + uVar7 * local_c);
      }
      local_8 = local_8 + -uVar7;
      puVar8 = (ushort *)((int)puVar8 + ((uint)puVar8 & 1));
      param_3 = param_3 + -uVar7;
    }
    if (uVar3 == 0x4000) {
      local_c = 3;
      goto LAB_004bfddb;
    }
    if (uVar3 == 0x6000) {
      local_8 = local_8 + -uVar7;
      param_3 = param_3 + -uVar7;
    }
    else if (uVar3 == 0x8000) {
      iVar4 = param_1[1] * (uVar7 - 1);
      iVar5 = param_2[1] * (uVar7 - 1);
      local_10 = local_10 + param_2[1] + iVar5;
      local_8 = local_8 + iVar5;
      puVar2 = puVar6 + param_1[1] + iVar4;
      param_3 = param_3 + iVar4;
    }
    else if (uVar3 == 0xa000) {
      return;
    }
  } while( true );
}

