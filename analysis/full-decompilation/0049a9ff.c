
void FUN_0049a9ff(undefined4 param_1,undefined4 param_2,int param_3,void *param_4,int *param_5,
                 undefined4 param_6,int *param_7,int *param_8,int param_9,int param_10,int param_11,
                 int param_12,size_t *param_13,int param_14)

{
  byte bVar1;
  short sVar2;
  size_t sVar3;
  size_t *psVar4;
  char cVar5;
  undefined2 uVar6;
  undefined2 *puVar7;
  int iVar8;
  int iVar9;
  undefined1 local_20 [4];
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  psVar4 = param_13;
  if (0 < (int)param_13[1]) {
    (**(code **)(*param_7 + 0xc))(param_13[1]);
    (**(code **)(*param_5 + 0xc))(psVar4[1]);
    (**(code **)(*param_8 + 0xc))(psVar4[1]);
    param_9 = param_9 + psVar4[1] * param_10 * 2;
    param_11 = param_11 + psVar4[1] * param_12 * 2;
  }
  iVar9 = param_14;
  local_8 = param_3 - psVar4[2];
  iVar8 = (int)param_4 - psVar4[3];
  param_13 = (size_t *)FUN_004cebb0();
  local_10 = FUN_004ca70b();
  local_14 = FUN_0049a73d(iVar9,*(undefined4 *)(iVar9 + 0x24));
  if ((int)psVar4[1] < iVar8) {
    local_c = iVar8 - psVar4[1];
    do {
      cVar5 = (**(code **)(*param_7 + 8))(&DAT_006c61d0,&param_4);
      if (cVar5 == '\x01') {
        (**(code **)(*param_5 + 8))(&DAT_006e5dd4,local_20);
        (**(code **)(*param_8 + 8))(&DAT_006e5d4c,&local_1c);
        sVar3 = *psVar4;
        if ((int)sVar3 < local_8) {
          local_18 = param_9 - param_11;
          iVar9 = param_3 - sVar3;
          param_13 = (size_t *)(param_11 + sVar3 * 2);
          param_14 = local_8 - sVar3;
          do {
            iVar9 = iVar9 + -1;
            bVar1 = *(byte *)((int)param_4 + iVar9);
            if (bVar1 != 0xff) {
              sVar2 = *(short *)(local_10 + (uint)bVar1 * 2);
              *(byte *)((int)param_4 + iVar9) = 0xff;
              iVar8 = sVar2 + local_14;
              if (iVar8 <= (int)(uint)*(ushort *)param_13) {
                puVar7 = (undefined2 *)((int)param_13 + local_18);
                uVar6 = FUN_0049a775(*(undefined1 *)(iVar9 + local_1c));
                *puVar7 = uVar6;
                *(ushort *)param_13 = (ushort)iVar8;
              }
            }
            param_13 = (size_t *)((int)param_13 + 2);
            param_14 = param_14 + -1;
          } while (param_14 != 0);
        }
        if (psVar4[2] != 0) {
          _memset(param_4,0xff,psVar4[2]);
        }
        sVar3 = *psVar4;
        if (sVar3 != 0) {
          _memset((void *)((int)param_4 + (param_3 - sVar3)),0xff,sVar3);
        }
      }
      else {
        (**(code **)(*param_5 + 0xc))(1);
        (**(code **)(*param_8 + 0xc))(1);
      }
      local_c = local_c + -1;
      param_9 = param_9 + param_10 * 2;
      param_11 = param_11 + param_12 * 2;
    } while (local_c != 0);
  }
  return;
}

