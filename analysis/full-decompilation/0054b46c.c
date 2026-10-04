
undefined4 __thiscall FUN_0054b46c(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  
  if (((*(char *)(param_1 + 0x1a0) == '\0') && (DAT_006f2a04 == '\0')) && (param_2 == 1)) {
    if (*(char *)(param_1 + 500) != '\0') {
LAB_0054b4e9:
      FUN_005dadbc(0,1);
      return 1;
    }
    iVar2 = 0;
    piVar1 = (int *)(param_1 + 0x14c);
    do {
      if (param_3 == *piVar1) {
        iVar2 = FUN_0054ccae(iVar2);
        if (iVar2 != -1) {
          *(undefined1 *)(param_1 + 500) = 1;
          (**(code **)(param_1 + 0x194))(iVar2);
          goto LAB_0054b4e3;
        }
        break;
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 1;
    } while (iVar2 < 10);
    iVar2 = 0;
    piVar1 = (int *)(param_1 + 0x174);
    do {
      if (param_3 == *piVar1) {
        if (iVar2 != -1) {
          *(undefined1 *)(param_1 + 500) = 1;
          (**(code **)(param_1 + 0x198))(iVar2);
          goto LAB_0054b4e3;
        }
        break;
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 1;
    } while (iVar2 < 5);
    iVar2 = 0;
    piVar1 = (int *)(param_1 + 0xe0);
    do {
      if (param_3 == *piVar1) {
        if (iVar2 == -1) {
          return 0;
        }
        *(undefined1 *)(param_1 + 500) = 1;
        FUN_0054d4a3(iVar2);
LAB_0054b4e3:
        *(undefined1 *)(param_1 + 500) = 0;
        goto LAB_0054b4e9;
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 1;
    } while (iVar2 < 7);
  }
  return 0;
}

