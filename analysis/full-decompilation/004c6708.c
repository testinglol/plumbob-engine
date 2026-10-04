
void FUN_004c6708(undefined4 *param_1,int *param_2,undefined2 *param_3,int param_4,int param_5,
                 int *param_6)

{
  int *piVar1;
  ushort uVar2;
  byte bVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined2 uVar6;
  ushort *puVar7;
  uint uVar8;
  undefined2 *puVar9;
  int *piVar10;
  undefined2 *puVar11;
  uint local_10;
  undefined2 *local_8;
  
  puVar7 = param_3 + 8;
  puVar4 = (undefined2 *)*param_2;
  piVar10 = param_6;
  puVar5 = (undefined2 *)*param_1;
  do {
    while( true ) {
      while( true ) {
        while( true ) {
          while( true ) {
            puVar11 = puVar5;
            puVar9 = puVar4;
            uVar2 = *puVar7;
            local_10 = uVar2 & 0x1fff;
            uVar8 = uVar2 & 0xe000;
            puVar7 = puVar7 + 1;
            if ((uVar2 & 0xe000) != 0) break;
            piVar10 = (int *)(*param_6 + param_5);
            puVar4 = puVar9 + param_2[1];
            puVar5 = puVar11 + param_1[1];
            param_3 = puVar11;
            param_6 = param_6 + 1;
            local_8 = puVar9;
          }
          puVar4 = puVar9;
          puVar5 = puVar11;
          if (uVar8 != 0x2000) break;
          if ((uVar2 & 0x1fff) != 0) {
            do {
              bVar3 = (byte)*puVar7 >> 3;
              if (bVar3 != 0) {
                *local_8 = (short)piVar10;
                if (bVar3 < 0x1f) {
                  uVar6 = FUN_0049a775(bVar3);
                  *param_3 = uVar6;
                }
                else {
                  *param_3 = *(undefined2 *)(param_4 + (uint)*(byte *)((int)puVar7 + 1) * 2);
                }
              }
              param_3 = param_3 + 1;
              local_8 = local_8 + 1;
              puVar7 = puVar7 + 1;
              local_10 = local_10 - 1;
            } while (local_10 != 0);
          }
        }
        if (uVar8 != 0x6000) break;
        param_3 = param_3 + local_10;
        local_8 = local_8 + local_10;
      }
      if (uVar8 != 0x8000) break;
      if ((uVar2 & 0x1fff) != 0) {
        do {
          param_3 = puVar11;
          local_8 = puVar9;
          piVar1 = param_6 + 1;
          piVar10 = (int *)(*param_6 + param_5);
          local_10 = local_10 - 1;
          puVar9 = local_8 + param_2[1];
          puVar4 = local_8 + param_2[1];
          puVar11 = param_3 + param_1[1];
          puVar5 = param_3 + param_1[1];
          param_6 = piVar1;
        } while (local_10 != 0);
      }
    }
  } while (uVar8 != 0xa000);
  return;
}

