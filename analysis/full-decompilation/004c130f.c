
void FUN_004c130f(int *param_1,int *param_2,ushort *param_3,int param_4,int param_5,int param_6)

{
  ushort uVar1;
  ushort *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  ushort *puVar6;
  ushort *puVar7;
  uint local_14;
  int local_10;
  ushort *local_c;
  ushort *local_8;
  
  puVar7 = param_3 + 8;
  local_c = (ushort *)(*param_2 + -2 + (uint)*param_3 * 2);
  puVar2 = (ushort *)(*param_1 + -2 + (uint)*param_3 * 2);
  do {
    while( true ) {
      while( true ) {
        puVar6 = puVar2;
        local_10 = 2;
        uVar1 = *puVar7;
        uVar3 = uVar1 & 0x1fff;
        uVar4 = uVar1 & 0xe000;
        puVar7 = puVar7 + 1;
        if ((uVar1 & 0xe000) != 0) break;
        local_8 = local_c;
        local_c = local_c + param_2[1];
        puVar2 = puVar6 + param_1[1];
        param_3 = puVar6;
      }
      puVar2 = puVar6;
      local_14 = uVar3;
      if (uVar4 != 0x2000) break;
LAB_004c13c1:
      if ((uVar1 & 0x1fff) != 0) {
        puVar6 = local_8;
        do {
          iVar5 = *(short *)(param_6 + (uint)(byte)*puVar7 * 2) + param_5;
          if (iVar5 <= (int)(uint)*puVar6) {
            *puVar6 = (ushort)iVar5;
            *(undefined2 *)(((int)param_3 - (int)local_8) + (int)puVar6) =
                 *(undefined2 *)(param_4 + (uint)*(byte *)((int)puVar7 + 1) * 2);
          }
          puVar7 = (ushort *)((int)puVar7 + local_10);
          puVar6 = puVar6 + -1;
          local_14 = local_14 - 1;
        } while (local_14 != 0);
      }
      local_8 = local_8 + -uVar3;
      puVar7 = (ushort *)((int)puVar7 + ((uint)puVar7 & 1));
      param_3 = param_3 + -uVar3;
    }
    if (uVar4 == 0x4000) {
      local_10 = 3;
      goto LAB_004c13c1;
    }
    if (uVar4 == 0x6000) {
      local_8 = local_8 + -uVar3;
      param_3 = param_3 + -uVar3;
    }
    else if (uVar4 == 0x8000) {
      if ((uVar1 & 0x1fff) != 0) {
        do {
          param_3 = puVar6;
          local_8 = local_c;
          local_c = local_c + param_2[1];
          local_14 = local_14 - 1;
          puVar6 = param_3 + param_1[1];
          puVar2 = param_3 + param_1[1];
        } while (local_14 != 0);
      }
    }
    else if (uVar4 == 0xa000) {
      return;
    }
  } while( true );
}

