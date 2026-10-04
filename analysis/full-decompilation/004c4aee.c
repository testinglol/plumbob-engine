
void FUN_004c4aee(undefined4 param_1,int param_2,int param_3,int param_4,int *param_5,int *param_6,
                 int param_7,int param_8,int param_9,int param_10,uint *param_11,int param_12,
                 undefined4 param_13,int param_14)

{
  uint *puVar1;
  char cVar2;
  ushort *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  undefined4 *puVar9;
  int local_10;
  int local_c;
  int local_8;
  
  puVar1 = param_11;
  uVar5 = param_11[1];
  if (0 < (int)uVar5) {
    (**(code **)(*param_6 + 0xc))(uVar5);
    (**(code **)(*param_5 + 0xc))(puVar1[1]);
    uVar5 = puVar1[1];
    param_7 = param_7 + uVar5 * param_8 * 2;
    param_9 = param_9 + uVar5 * param_10 * 2;
  }
  iVar6 = param_3 - puVar1[2];
  uVar4 = puVar1[3];
  param_3 = uVar5 + param_2;
  FUN_004cebb0();
  if ((int)puVar1[1] < (int)(param_4 - uVar4)) {
    param_4 = (param_4 - uVar4) - puVar1[1];
    do {
      cVar2 = (**(code **)(*param_6 + 8))(&DAT_006c76a8,&param_11);
      if (cVar2 == '\x01') {
        (**(code **)(*param_5 + 4))(&DAT_006f0a98,&local_10);
        local_c = FUN_0049a73d(param_13,param_3);
        local_c = local_c + param_14;
        uVar5 = *puVar1;
        if ((int)uVar5 < iVar6) {
          local_8 = param_12 - param_9;
          puVar3 = (ushort *)(param_9 + uVar5 * 2);
          do {
            if (*(char *)((int)param_11 + uVar5) != -1) {
              *(char *)((int)param_11 + uVar5) = -1;
              iVar7 = (uint)*(ushort *)(local_8 + (int)puVar3) + local_c;
              if (iVar7 <= (int)(*puVar3 + 1)) {
                *puVar3 = (ushort)iVar7;
                *(undefined2 *)((param_7 - param_9) + (int)puVar3) =
                     *(undefined2 *)(local_10 + uVar5 * 2);
              }
            }
            uVar5 = uVar5 + 1;
            puVar3 = puVar3 + 1;
          } while ((int)uVar5 < iVar6);
        }
        uVar5 = *puVar1;
        if (uVar5 != 0) {
          puVar8 = param_11;
          for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar8 = 0xffffffff;
            puVar8 = puVar8 + 1;
          }
          for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *(undefined1 *)puVar8 = 0xff;
            puVar8 = (uint *)((int)puVar8 + 1);
          }
        }
        uVar5 = puVar1[2];
        if (uVar5 != 0) {
          puVar9 = (undefined4 *)((int)param_11 + iVar6);
          for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar9 = 0xffffffff;
            puVar9 = puVar9 + 1;
          }
          for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *(undefined1 *)puVar9 = 0xff;
            puVar9 = (undefined4 *)((int)puVar9 + 1);
          }
        }
      }
      else {
        (**(code **)(*param_5 + 0xc))(1);
      }
      param_3 = param_3 + 1;
      param_4 = param_4 + -1;
      param_7 = param_7 + param_8 * 2;
      param_9 = param_9 + param_10 * 2;
    } while (param_4 != 0);
  }
  return;
}

