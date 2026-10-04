
void __thiscall FUN_004ba71b(int param_1,uint param_2)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  
  if ((param_2 != 0) && (*(char *)(param_1 + 0x14) != '\x01')) {
    iVar2 = *(int *)(param_1 + 0xc);
    if (iVar2 < (int)param_2) {
      if (iVar2 != 0) {
        *(undefined4 *)(param_1 + 0xc) = 0;
        param_2 = param_2 - iVar2;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 2;
      }
      for (; 0 < (int)param_2; param_2 = param_2 - 1) {
        pcVar3 = *(char **)(param_1 + 8);
        cVar1 = *pcVar3;
        uVar4 = (uint)(byte)pcVar3[1];
        *(char **)(param_1 + 8) = pcVar3 + 2;
        if (cVar1 == '\x04') {
          if (((uVar4 == 2) && (pcVar3[2] == '\x05')) && (pcVar3[3] == -1)) {
            uVar4 = (uint)CONCAT11(pcVar3[4],pcVar3[5]);
          }
          *(char **)(param_1 + 8) = pcVar3 + uVar4;
        }
        else {
          if (cVar1 == '\x05') {
            *(undefined1 *)(param_1 + 0x14) = 1;
            return;
          }
          if (cVar1 == '\t') {
            if (uVar4 == 0) {
              param_2 = param_2 - 1;
            }
            else if (param_2 < uVar4) {
              *(char **)(param_1 + 8) = pcVar3;
              *(uint *)(param_1 + 0xc) = uVar4 - param_2;
              param_2 = 1;
            }
            else {
              param_2 = param_2 + (1 - uVar4);
            }
          }
        }
      }
    }
    else {
      *(uint *)(param_1 + 0xc) = iVar2 - param_2;
      if (iVar2 - param_2 == 0) {
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 2;
      }
    }
  }
  return;
}

