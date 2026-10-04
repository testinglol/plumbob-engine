
void FUN_0049a7e6(undefined4 param_1,undefined4 param_2,int param_3,void *param_4,int *param_5,
                 undefined4 param_6,int *param_7,int *param_8,int param_9,int param_10,int param_11,
                 int param_12,size_t *param_13,int param_14)

{
  byte bVar1;
  short sVar2;
  size_t *psVar3;
  char cVar4;
  undefined2 uVar5;
  undefined2 *puVar6;
  size_t sVar7;
  int iVar8;
  int iVar9;
  undefined1 local_18 [4];
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  psVar3 = param_13;
  if (0 < (int)param_13[1]) {
    (**(code **)(*param_7 + 0xc))(param_13[1]);
    (**(code **)(*param_5 + 0xc))(psVar3[1]);
    (**(code **)(*param_8 + 0xc))(psVar3[1]);
    param_9 = param_9 + psVar3[1] * param_10 * 2;
    param_11 = param_11 + psVar3[1] * param_12 * 2;
  }
  iVar9 = param_14;
  param_3 = param_3 - psVar3[2];
  iVar8 = (int)param_4 - psVar3[3];
  FUN_004cebb0();
  local_c = FUN_0049a73d(iVar9,*(undefined4 *)(iVar9 + 0x24));
  local_8 = FUN_004ca70b();
  if ((int)psVar3[1] < iVar8) {
    param_14 = iVar8 - psVar3[1];
    do {
      cVar4 = (**(code **)(*param_7 + 8))(&DAT_006c61d0,&param_4);
      if (cVar4 == '\x01') {
        (**(code **)(*param_5 + 8))(&DAT_006e5dd4,local_18);
        (**(code **)(*param_8 + 8))(&DAT_006e5d4c,&local_14);
        sVar7 = *psVar3;
        if ((int)sVar7 < param_3) {
          local_10 = param_9 - param_11;
          param_13 = (size_t *)(param_11 + sVar7 * 2);
          do {
            bVar1 = *(byte *)((int)param_4 + sVar7);
            if (bVar1 != 0xff) {
              sVar2 = *(short *)(local_8 + (uint)bVar1 * 2);
              *(byte *)((int)param_4 + sVar7) = 0xff;
              iVar9 = sVar2 + local_c;
              if (iVar9 <= (int)(uint)(ushort)*param_13) {
                puVar6 = (undefined2 *)(local_10 + (int)param_13);
                uVar5 = FUN_0049a996(*(undefined1 *)(sVar7 + local_14));
                *puVar6 = uVar5;
                *(ushort *)param_13 = (ushort)iVar9;
              }
            }
            sVar7 = sVar7 + 1;
            param_13 = (size_t *)((int)param_13 + 2);
          } while ((int)sVar7 < param_3);
        }
        if (*psVar3 != 0) {
          _memset(param_4,0xff,*psVar3);
        }
        if (psVar3[2] != 0) {
          _memset((void *)((int)param_4 + param_3),0xff,psVar3[2]);
        }
      }
      else {
        (**(code **)(*param_5 + 0xc))(1);
        (**(code **)(*param_8 + 0xc))(1);
      }
      param_14 = param_14 + -1;
      param_9 = param_9 + param_10 * 2;
      param_11 = param_11 + param_12 * 2;
    } while (param_14 != 0);
  }
  return;
}

