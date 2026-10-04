
void FUN_004ca790(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int *param_5,
                 int param_6,int *param_7,int param_8,int param_9,int param_10,int param_11,
                 size_t *param_12,void *param_13)

{
  short sVar1;
  size_t *psVar2;
  char cVar3;
  int iVar4;
  ushort *puVar5;
  size_t sVar6;
  int iVar7;
  
  psVar2 = param_12;
  if (0 < (int)param_12[1]) {
    (**(code **)(*param_7 + 0xc))(param_12[1]);
    (**(code **)(*param_5 + 0xc))(psVar2[1]);
    param_8 = param_8 + psVar2[1] * param_9 * 2;
    param_10 = param_10 + psVar2[1] * param_11 * 2;
  }
  param_3 = param_3 - psVar2[2];
  iVar7 = param_4 - psVar2[3];
  FUN_004cebb0();
  iVar4 = FUN_0049a73d(param_13,*(undefined4 *)((int)param_13 + 0x24));
  if ((int)psVar2[1] < iVar7) {
    param_12 = (size_t *)(iVar7 - psVar2[1]);
    do {
      cVar3 = (**(code **)(*param_7 + 8))(&DAT_006c779c,&param_13);
      if (cVar3 == '\x01') {
        (**(code **)(*param_5 + 8))(&DAT_006f0bd8,&param_4);
        sVar6 = *psVar2;
        if ((int)sVar6 < param_3) {
          puVar5 = (ushort *)(param_10 + sVar6 * 2);
          do {
            if (*(byte *)(sVar6 + (int)param_13) != 0xff) {
              sVar1 = (&DAT_006f0c60)[*(byte *)(sVar6 + (int)param_13)];
              *(undefined1 *)(sVar6 + (int)param_13) = 0xff;
              if (sVar1 + iVar4 <= (int)(uint)*puVar5) {
                *(undefined2 *)((param_8 - param_10) + (int)puVar5) =
                     *(undefined2 *)(param_6 + (uint)*(byte *)(sVar6 + param_4) * 2);
                *puVar5 = (ushort)(sVar1 + iVar4);
              }
            }
            sVar6 = sVar6 + 1;
            puVar5 = puVar5 + 1;
          } while ((int)sVar6 < param_3);
        }
        if (*psVar2 != 0) {
          _memset(param_13,0xff,*psVar2);
        }
        if (psVar2[2] != 0) {
          _memset((void *)((int)param_13 + param_3),0xff,psVar2[2]);
        }
      }
      else {
        (**(code **)(*param_5 + 0xc))(1);
      }
      param_12 = (size_t *)((int)param_12 + -1);
      param_8 = param_8 + param_9 * 2;
      param_10 = param_10 + param_11 * 2;
    } while (param_12 != (size_t *)0x0);
  }
  return;
}

