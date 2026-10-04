
void __thiscall
FUN_005f3eb5(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
            int *param_8)

{
  int *piVar1;
  char *pcVar2;
  char cVar3;
  int iVar4;
  size_t sVar5;
  int iVar6;
  
  *param_1 = param_3;
  piVar1 = param_1 + 5;
  param_1[3] = 5;
  param_1[4] = param_2 * param_5;
  *(undefined1 *)((int)param_1 + 0x21) = 0;
  param_1[2] = param_5;
  *(bool *)(param_1 + 8) = param_6 != 0;
  if ((param_1[6] - *piVar1 >> 2 != 0) && (param_4 <= param_1[6] - *piVar1 >> 2)) {
    FUN_004071be(*piVar1 + param_4 * 4,param_1[6]);
  }
  if (param_6 != 0) {
    do {
      iVar6 = (param_1[6] - *piVar1 >> 2) + 1;
      pcVar2 = (char *)(*param_1 + iVar6 + -1 + param_6);
      cVar3 = *pcVar2;
      iVar4 = (**(code **)(*param_8 + 0x44))(pcVar2,0xffffffff);
      if (cVar3 == '\0') {
        *(undefined1 *)(param_1 + 8) = 0;
        goto LAB_005f3ff6;
      }
      if (cVar3 == '\n') {
        *(undefined1 *)(param_1 + 8) = 0;
        *(undefined1 *)((int)param_1 + 0x21) = 1;
        if ((param_1[6] - *piVar1 & 0xfffffffcU) == 0) {
          param_5 = 0;
        }
        else {
          param_5 = *(undefined4 *)(param_1[6] + -4);
        }
        FUN_0042eab4(&param_5);
        goto LAB_005f3ff6;
      }
      param_5 = (**(code **)(*param_8 + 0x68))(*param_1 + param_6,iVar4 + -1 + iVar6);
      if (0 < iVar4) {
        do {
          FUN_0042eab4(&param_5);
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
    } while (param_5 <= param_1[3] + -3 + param_7);
    iVar6 = *param_8;
    iVar4 = param_1[3] + -3 + param_7;
    sVar5 = _strlen((char *)(*param_1 + param_6));
    iVar4 = (**(code **)(iVar6 + 0x60))(*param_1 + param_6,sVar5,iVar4);
    FUN_004071be(*piVar1 + iVar4 * 4,param_1[6]);
  }
LAB_005f3ff6:
  param_1[1] = param_1[6] - *piVar1 >> 2;
  return;
}

