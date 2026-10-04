
void FUN_004b75f8(undefined4 param_1,int param_2,undefined4 *param_3,int param_4,int *param_5,
                 undefined4 param_6,int *param_7,int *param_8,int *param_9,int param_10,int param_11
                 ,int param_12,int param_13,uint *param_14,int param_15,undefined4 param_16)

{
  uint *puVar1;
  undefined1 uVar2;
  char cVar3;
  undefined2 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  ushort *puVar8;
  int iVar9;
  uint uVar10;
  undefined4 *puVar11;
  undefined1 local_1c [4];
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  int local_8;
  
  puVar1 = param_14;
  uVar10 = param_14[1];
  if (0 < (int)uVar10) {
    (**(code **)(*param_7 + 0xc))(uVar10);
    (**(code **)(*param_5 + 0xc))(puVar1[1]);
    (**(code **)(*param_8 + 0xc))(puVar1[1]);
    (**(code **)(*param_9 + 0xc))(puVar1[1]);
    uVar10 = puVar1[1];
    param_10 = param_10 + uVar10 * param_11 * 2;
    param_12 = param_12 + uVar10 * param_13 * 2;
  }
  iVar7 = (int)param_3 - puVar1[2];
  iVar9 = param_4 - puVar1[3];
  param_4 = uVar10 + param_2;
  local_8 = iVar7;
  local_c = FUN_004cebb0();
  FUN_004b46a4();
  uVar2 = __ftol();
  param_14 = (uint *)CONCAT13(uVar2,param_14._0_3_);
  if ((int)puVar1[1] < iVar9) {
    param_2 = iVar9 - puVar1[1];
    do {
      cVar3 = (**(code **)(*param_7 + 8))(&DAT_006c7444,&param_3);
      if (cVar3 == '\x01') {
        (**(code **)(*param_5 + 8))(&DAT_006f02c4,local_1c);
        (**(code **)(*param_8 + 8))(&DAT_006f023c,&local_18);
        (**(code **)(*param_9 + 8))(&DAT_006f01b4,&local_14);
        local_10 = FUN_0049a73d(param_16,param_4);
        uVar10 = *puVar1;
        if ((int)uVar10 < iVar7) {
          iVar5 = param_15 - param_12;
          puVar8 = (ushort *)(param_12 + uVar10 * 2);
          iVar9 = param_10 - param_12;
          do {
            if (*(char *)((int)param_3 + uVar10) != -1) {
              *(char *)((int)param_3 + uVar10) = -1;
              iVar7 = (uint)*(ushort *)(iVar5 + (int)puVar8) + local_10;
              if (iVar7 <= (int)(*puVar8 + 1)) {
                *puVar8 = (ushort)iVar7;
                uVar4 = FUN_00438f12();
                *(undefined2 *)(iVar9 + (int)puVar8) = uVar4;
              }
            }
            uVar10 = uVar10 + 1;
            puVar8 = puVar8 + 1;
            iVar7 = local_8;
          } while ((int)uVar10 < local_8);
        }
        uVar10 = *puVar1;
        if (uVar10 != 0) {
          puVar11 = param_3;
          for (uVar6 = uVar10 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
            *puVar11 = 0xffffffff;
            puVar11 = puVar11 + 1;
          }
          for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
            *(undefined1 *)puVar11 = 0xff;
            puVar11 = (undefined4 *)((int)puVar11 + 1);
          }
        }
        uVar10 = puVar1[2];
        if (uVar10 != 0) {
          puVar11 = (undefined4 *)((int)param_3 + iVar7);
          for (uVar6 = uVar10 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
            *puVar11 = 0xffffffff;
            puVar11 = puVar11 + 1;
          }
          for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
            *(undefined1 *)puVar11 = 0xff;
            puVar11 = (undefined4 *)((int)puVar11 + 1);
          }
        }
      }
      else {
        (**(code **)(*param_5 + 0xc))(1);
        (**(code **)(*param_8 + 0xc))(1);
        (**(code **)(*param_9 + 0xc))(1);
      }
      param_4 = param_4 + 1;
      param_2 = param_2 + -1;
      param_10 = param_10 + param_11 * 2;
      param_12 = param_12 + param_13 * 2;
    } while (param_2 != 0);
  }
  return;
}

