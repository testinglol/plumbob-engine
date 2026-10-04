
void FUN_004bf501(ushort *param_1,undefined4 *param_2,int param_3,int param_4,int param_5,
                 int param_6)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  ushort *puVar5;
  ushort *puVar6;
  uint uVar7;
  ushort *puVar8;
  uint local_14;
  ushort *local_10;
  int local_c;
  int local_8;
  
  puVar6 = (ushort *)(param_3 + 0x10);
  local_c = *(int *)param_1;
  puVar8 = param_1;
  local_10 = (ushort *)*param_2;
  do {
    while( true ) {
      while( true ) {
        local_8 = 2;
        uVar1 = *puVar6;
        uVar7 = uVar1 & 0x1fff;
        uVar2 = uVar1 & 0xe000;
        puVar6 = puVar6 + 1;
        if ((uVar1 & 0xe000) != 0) break;
        param_3 = local_c;
        local_c = local_c + *(int *)(param_1 + 2) * 2;
        puVar8 = local_10;
        local_10 = local_10 + param_2[1];
      }
      if (uVar2 != 0x2000) break;
LAB_004bf5c6:
      if (uVar7 < 0x10) {
        if ((uVar1 & 0x1fff) != 0) {
          puVar5 = puVar8;
          local_14 = uVar7;
          do {
            iVar3 = *(short *)(param_6 + (uint)(byte)*puVar6 * 2) + param_5;
            if (iVar3 <= (int)(uint)*puVar5) {
              *puVar5 = (ushort)iVar3;
              *(undefined2 *)((param_3 - (int)puVar8) + (int)puVar5) =
                   *(undefined2 *)(param_4 + (uint)*(byte *)((int)puVar6 + 1) * 2);
            }
            puVar6 = (ushort *)((int)puVar6 + local_8);
            puVar5 = puVar5 + 1;
            local_14 = local_14 - 1;
          } while (local_14 != 0);
        }
      }
      else {
        FUN_004bbf78(uVar7,puVar6,param_3,puVar8,param_4,param_5,param_6,local_8);
        puVar6 = (ushort *)((int)puVar6 + uVar7 * local_8);
      }
      param_3 = param_3 + uVar7 * 2;
      puVar8 = puVar8 + uVar7;
      puVar6 = (ushort *)((int)puVar6 + ((uint)puVar6 & 1));
    }
    if (uVar2 == 0x4000) {
      local_8 = 3;
      goto LAB_004bf5c6;
    }
    if (uVar2 == 0x6000) {
      param_3 = param_3 + uVar7 * 2;
      puVar8 = puVar8 + uVar7;
    }
    else if (uVar2 == 0x8000) {
      iVar3 = *(int *)(param_1 + 2) * (uVar7 - 1);
      iVar4 = param_2[1] * (uVar7 - 1);
      puVar8 = puVar8 + iVar4;
      param_3 = param_3 + iVar3 * 2;
      local_c = local_c + (*(int *)(param_1 + 2) + iVar3) * 2;
      local_10 = local_10 + param_2[1] + iVar4;
    }
    else if (uVar2 == 0xa000) {
      return;
    }
  } while( true );
}

