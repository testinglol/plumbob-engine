
undefined4 __thiscall FUN_0056585d(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  
  if (((*(char *)(param_1 + 0x428) == '\0') && (DAT_006f2a04 == '\0')) && (param_2 == 1)) {
    if (*(char *)(param_1 + 0x464) != '\0') {
LAB_005658d4:
      FUN_005dadbc(0,1);
      return 1;
    }
    iVar2 = 0;
    piVar1 = (int *)(param_1 + 0x3d8);
    do {
      if (param_3 == *piVar1) {
        if (iVar2 + 0x51 != -1) {
          *(undefined1 *)(param_1 + 0x464) = 1;
          (**(code **)(param_1 + 0x41c))(iVar2 + 0x51);
          goto LAB_005658ce;
        }
        break;
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 1;
    } while (iVar2 < 9);
    iVar2 = 0;
    piVar1 = (int *)(param_1 + 0x3fc);
    do {
      if (param_3 == *piVar1) {
        if (iVar2 != -1) {
          *(undefined1 *)(param_1 + 0x464) = 1;
          (**(code **)(param_1 + 0x420))(iVar2);
          goto LAB_005658ce;
        }
        break;
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 1;
    } while (iVar2 < 5);
    iVar2 = 0;
    piVar1 = (int *)(param_1 + 0xe4);
    do {
      if (param_3 == *piVar1) {
        if (iVar2 == -1) {
          return 0;
        }
        *(undefined1 *)(param_1 + 0x464) = 1;
        FUN_0056778c(iVar2);
LAB_005658ce:
        *(undefined1 *)(param_1 + 0x464) = 0;
        goto LAB_005658d4;
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 1;
    } while (iVar2 < 9);
  }
  return 0;
}

