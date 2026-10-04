
void FUN_004c6d8c(undefined4 *param_1,undefined4 *param_2,undefined2 *param_3,int param_4,
                 int param_5,int *param_6)

{
  int *piVar1;
  ushort uVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  int *piVar5;
  uint uVar6;
  undefined2 *puVar7;
  ushort *puVar8;
  undefined2 *puVar9;
  uint local_c;
  undefined2 *local_8;
  
  puVar8 = param_3 + 8;
  piVar5 = param_6;
  puVar3 = (undefined2 *)*param_2;
  puVar4 = (undefined2 *)*param_1;
  do {
    while( true ) {
      while( true ) {
        while( true ) {
          while( true ) {
            puVar9 = puVar4;
            puVar7 = puVar3;
            uVar2 = *puVar8;
            local_c = uVar2 & 0x1fff;
            uVar6 = uVar2 & 0xe000;
            puVar8 = puVar8 + 1;
            if ((uVar2 & 0xe000) != 0) break;
            piVar5 = (int *)(*param_6 + param_5);
            puVar3 = puVar7 + param_2[1];
            puVar4 = puVar9 + param_1[1];
            param_3 = puVar9;
            param_6 = param_6 + 1;
            local_8 = puVar7;
          }
          puVar3 = puVar7;
          puVar4 = puVar9;
          if (uVar6 != 0x2000) break;
          if ((uVar2 & 0x1fff) != 0) {
            do {
              if ((*puVar8 & 0xf8) != 0) {
                *local_8 = (short)piVar5;
                *param_3 = *(undefined2 *)(param_4 + (uint)*(byte *)((int)puVar8 + 1) * 2);
              }
              param_3 = param_3 + 1;
              local_8 = local_8 + 1;
              puVar8 = puVar8 + 1;
              local_c = local_c - 1;
            } while (local_c != 0);
          }
        }
        if (uVar6 != 0x6000) break;
        param_3 = param_3 + local_c;
        local_8 = local_8 + local_c;
      }
      if (uVar6 != 0x8000) break;
      if ((uVar2 & 0x1fff) != 0) {
        do {
          param_3 = puVar9;
          local_8 = puVar7;
          piVar1 = param_6 + 1;
          piVar5 = (int *)(*param_6 + param_5);
          local_c = local_c - 1;
          puVar7 = local_8 + param_2[1];
          puVar3 = local_8 + param_2[1];
          puVar9 = param_3 + param_1[1];
          puVar4 = param_3 + param_1[1];
          param_6 = piVar1;
        } while (local_c != 0);
      }
    }
  } while (uVar6 != 0xa000);
  return;
}

