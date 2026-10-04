
void FUN_004c0fed(int *param_1,undefined4 *param_2,int param_3,int param_4,int param_5,int param_6)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  ushort *puVar5;
  ushort *puVar6;
  int iVar7;
  uint local_14;
  int local_10;
  ushort *local_c;
  ushort *local_8;
  
  puVar6 = (ushort *)(param_3 + 0x10);
  local_c = (ushort *)*param_2;
  iVar2 = *param_1;
  do {
    while( true ) {
      while( true ) {
        iVar7 = iVar2;
        local_10 = 2;
        uVar1 = *puVar6;
        uVar3 = uVar1 & 0x1fff;
        uVar4 = uVar1 & 0xe000;
        puVar6 = puVar6 + 1;
        if ((uVar1 & 0xe000) != 0) break;
        local_8 = local_c;
        local_c = local_c + param_2[1];
        iVar2 = iVar7 + param_1[1] * 2;
        param_3 = iVar7;
      }
      iVar2 = iVar7;
      local_14 = uVar3;
      if (uVar4 != 0x2000) break;
LAB_004c1092:
      if ((uVar1 & 0x1fff) != 0) {
        puVar5 = local_8;
        do {
          iVar7 = *(short *)(param_6 + (uint)(byte)*puVar6 * 2) + param_5;
          if (iVar7 <= (int)(uint)*puVar5) {
            *puVar5 = (ushort)iVar7;
            *(undefined2 *)((param_3 - (int)local_8) + (int)puVar5) =
                 *(undefined2 *)(param_4 + (uint)*(byte *)((int)puVar6 + 1) * 2);
          }
          puVar6 = (ushort *)((int)puVar6 + local_10);
          puVar5 = puVar5 + 1;
          local_14 = local_14 - 1;
        } while (local_14 != 0);
      }
      local_8 = local_8 + uVar3;
      puVar6 = (ushort *)((int)puVar6 + ((uint)puVar6 & 1));
      param_3 = param_3 + uVar3 * 2;
    }
    if (uVar4 == 0x4000) {
      local_10 = 3;
      goto LAB_004c1092;
    }
    if (uVar4 == 0x6000) {
      local_8 = local_8 + uVar3;
      param_3 = param_3 + uVar3 * 2;
    }
    else if (uVar4 == 0x8000) {
      if ((uVar1 & 0x1fff) != 0) {
        do {
          param_3 = iVar7;
          local_8 = local_c;
          local_c = local_c + param_2[1];
          iVar7 = param_3 + param_1[1] * 2;
          local_14 = local_14 - 1;
          iVar2 = iVar7;
        } while (local_14 != 0);
      }
    }
    else if (uVar4 == 0xa000) {
      return;
    }
  } while( true );
}

