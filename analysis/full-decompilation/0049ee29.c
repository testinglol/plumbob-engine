
void FUN_0049ee29(undefined4 param_1,int param_2,int param_3,int param_4,int *param_5,int param_6,
                 int *param_7,int param_8,int param_9,int param_10,int param_11,size_t *param_12,
                 int param_13,undefined4 param_14)

{
  byte bVar1;
  size_t *psVar2;
  char cVar3;
  int iVar4;
  size_t sVar5;
  int iVar6;
  ushort *puVar7;
  int local_4c [4];
  undefined *local_3c;
  undefined *local_38;
  undefined *local_34;
  undefined *local_30;
  int local_2c [5];
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  psVar2 = param_12;
  if (0 < (int)param_12[1]) {
    (**(code **)(*param_7 + 0xc))(param_12[1]);
    (**(code **)(*param_5 + 0xc))(psVar2[1]);
    param_8 = param_8 + psVar2[1] * param_9 * 2;
    param_10 = param_10 + psVar2[1] * param_11 * 2;
  }
  iVar6 = param_3 - psVar2[2];
  local_8 = FUN_004cebb0();
  param_12 = (size_t *)FUN_00492d2c();
  iVar4 = 8 << ((byte)param_12 & 0x1f);
  local_2c[2] = 0;
  local_2c[3] = 0;
  local_4c[2] = param_13;
  local_4c[0] = param_13 + iVar4 * -2;
  local_4c[3] = param_13;
  local_2c[0] = *(int *)(local_8 + (0x12 - (int)param_12) * 4);
  local_4c[1] = param_13 - (iVar4 * 2 + 2);
  local_2c[4] = local_2c[0] / 2;
  local_3c = &DAT_00668540;
  local_38 = &DAT_00668540;
  local_34 = &DAT_00668540;
  local_30 = &DAT_00668540;
  sVar5 = psVar2[1];
  param_3 = param_2 + sVar5;
  if ((int)sVar5 < (int)(param_4 - psVar2[3])) {
    param_13 = (param_4 - psVar2[3]) - sVar5;
    local_2c[1] = local_2c[0];
    local_18 = local_2c[0];
    local_14 = local_2c[4];
    local_10 = local_2c[0];
    do {
      cVar3 = (**(code **)(*param_7 + 8))(&DAT_006c6664,&param_12);
      if (cVar3 == '\x01') {
        (**(code **)(*param_5 + 8))(&DAT_006ede70,&param_2);
        param_4 = FUN_0049a73d(param_14,param_3);
        sVar5 = *psVar2;
        if ((int)sVar5 < iVar6) {
          puVar7 = (ushort *)(param_10 + sVar5 * 2);
          local_c = param_8 - param_10;
          do {
            bVar1 = *(byte *)((int)param_12 + sVar5);
            if (bVar1 != 0xff) {
              bVar1 = (&DAT_00668440)[bVar1];
              *(byte *)((int)param_12 + sVar5) = 0xff;
              iVar4 = (uint)*(ushort *)(local_4c[bVar1] + sVar5 * 2) + local_2c[bVar1] + param_4;
              if (iVar4 <= (int)(*puVar7 + 1)) {
                *puVar7 = (ushort)iVar4;
                *(undefined2 *)((param_8 - param_10) + (int)puVar7) =
                     *(undefined2 *)(param_6 + (uint)*(byte *)(sVar5 + param_2) * 2);
              }
            }
            sVar5 = sVar5 + 1;
            puVar7 = puVar7 + 1;
          } while ((int)sVar5 < iVar6);
        }
        if (*psVar2 != 0) {
          _memset(param_12,0xff,*psVar2);
        }
        if (psVar2[2] != 0) {
          _memset((void *)((int)param_12 + iVar6),0xff,psVar2[2]);
        }
      }
      else {
        (**(code **)(*param_5 + 0xc))(1);
      }
      param_3 = param_3 + 1;
      param_13 = param_13 + -1;
      param_8 = param_8 + param_9 * 2;
      param_10 = param_10 + param_11 * 2;
    } while (param_13 != 0);
  }
  return;
}

