
void FUN_004ca8f1(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int *param_5,
                 int param_6,int *param_7,int param_8,int param_9,int param_10,int param_11,
                 size_t *param_12,int param_13)

{
  short sVar1;
  size_t sVar2;
  size_t *psVar3;
  char cVar4;
  int iVar5;
  ushort *puVar6;
  int local_10;
  int local_c;
  int local_8;
  
  psVar3 = param_12;
  if (0 < (int)param_12[1]) {
    (**(code **)(*param_7 + 0xc))(param_12[1]);
    (**(code **)(*param_5 + 0xc))(psVar3[1]);
    param_8 = param_8 + psVar3[1] * param_9 * 2;
    param_10 = param_10 + psVar3[1] * param_11 * 2;
  }
  iVar5 = param_13;
  local_8 = param_3 - psVar3[2];
  sVar2 = psVar3[3];
  FUN_004cebb0();
  local_c = FUN_0049a73d(iVar5,*(undefined4 *)(iVar5 + 0x24));
  if ((int)psVar3[1] < (int)(param_4 - sVar2)) {
    param_13 = (param_4 - sVar2) - psVar3[1];
    do {
      cVar4 = (**(code **)(*param_7 + 8))(&DAT_006c779c,&param_12);
      if (cVar4 == '\x01') {
        (**(code **)(*param_5 + 8))(&DAT_006f0bd8,&local_10);
        sVar2 = *psVar3;
        if ((int)sVar2 < local_8) {
          puVar6 = (ushort *)(param_10 + sVar2 * 2);
          iVar5 = param_3 - sVar2;
          param_4 = local_8 - sVar2;
          do {
            iVar5 = iVar5 + -1;
            if (*(byte *)(iVar5 + (int)param_12) != 0xff) {
              sVar1 = (&DAT_006f0c60)[*(byte *)(iVar5 + (int)param_12)];
              *(undefined1 *)(iVar5 + (int)param_12) = 0xff;
              if (sVar1 + local_c <= (int)(uint)*puVar6) {
                *(undefined2 *)((param_8 - param_10) + (int)puVar6) =
                     *(undefined2 *)(param_6 + (uint)*(byte *)(iVar5 + local_10) * 2);
                *puVar6 = (ushort)(sVar1 + local_c);
              }
            }
            puVar6 = puVar6 + 1;
            param_4 = param_4 + -1;
          } while (param_4 != 0);
        }
        if (psVar3[2] != 0) {
          _memset(param_12,0xff,psVar3[2]);
        }
        sVar2 = *psVar3;
        if (sVar2 != 0) {
          _memset((void *)((int)param_12 + (param_3 - sVar2)),0xff,sVar2);
        }
      }
      else {
        (**(code **)(*param_5 + 0xc))(1);
      }
      param_13 = param_13 + -1;
      param_8 = param_8 + param_9 * 2;
      param_10 = param_10 + param_11 * 2;
    } while (param_13 != 0);
  }
  return;
}

