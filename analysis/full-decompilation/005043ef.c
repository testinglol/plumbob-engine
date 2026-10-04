
void __thiscall FUN_005043ef(int param_1,char param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  *(char *)(param_1 + 0x11c) = param_2;
  iVar4 = 0;
  piVar3 = (int *)(param_1 + 0xdc);
  do {
    iVar2 = DAT_006d74f0;
    if (iVar4 != 4) {
      iVar1 = *piVar3;
      if (param_2 == '\0') {
        if (DAT_006d74f0 == 0) goto LAB_0050443e;
        *(undefined4 *)(iVar1 + 0x154) = 6;
LAB_00504436:
        *(int *)(iVar1 + 0x158) = iVar2;
      }
      else {
        if (DAT_006d74f0 != 0) {
          *(undefined4 *)(iVar1 + 0x154) = 1;
          goto LAB_00504436;
        }
LAB_0050443e:
        *(undefined4 *)(iVar1 + 0x154) = 0;
      }
      *(undefined1 *)(iVar1 + 0x16c) = 0;
    }
    iVar4 = iVar4 + 1;
    piVar3 = piVar3 + 1;
    if (7 < iVar4) {
      return;
    }
  } while( true );
}

