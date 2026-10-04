
void __thiscall FUN_0046f847(undefined4 *param_1,char *param_2,uint param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  
  if (param_2 != (char *)0x0) {
    if ((int)param_3 < 0) {
      uVar3 = 0xffffffff;
      pcVar4 = param_2;
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      param_3 = ~uVar3 - 1;
    }
    else {
      uVar3 = 0;
      if (0 < (int)param_3) {
        do {
          if (param_2[uVar3] == '\0') break;
          uVar3 = uVar3 + 1;
        } while ((int)uVar3 < (int)param_3);
        if ((int)uVar3 < (int)param_3) {
          param_3 = uVar3;
        }
      }
    }
    iVar2 = (**(code **)*param_1)();
    if ((int)(uint)*(ushort *)((int)param_1 + 10) <= (int)(param_3 + iVar2)) {
      param_3 = ((uint)*(ushort *)((int)param_1 + 10) - iVar2) - 1;
    }
    pcVar4 = (char *)(param_1[1] + iVar2);
    for (uVar3 = param_3 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)pcVar4 = *(undefined4 *)param_2;
      param_2 = param_2 + 4;
      pcVar4 = pcVar4 + 4;
    }
    for (uVar3 = param_3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar4 = *param_2;
      param_2 = param_2 + 1;
      pcVar4 = pcVar4 + 1;
    }
    *(undefined1 *)(param_1[1] + iVar2 + param_3) = 0;
    *(short *)(param_1 + 2) = *(short *)(param_1 + 2) + (short)param_3;
  }
  return;
}

