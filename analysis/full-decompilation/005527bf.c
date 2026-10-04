
undefined4 __thiscall FUN_005527bf(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  
  if ((*(char *)(param_1 + 0x19c) == '\0') && (DAT_006f2a04 == '\0')) {
    if (param_2 == 1) {
      if (*(char *)(param_1 + 0x1d8) == '\0') {
        iVar3 = 0;
        piVar2 = (int *)(param_1 + 0x14c);
        do {
          if (param_3 == *piVar2) {
            if (iVar3 + 0x5a != -1) {
              *(undefined1 *)(param_1 + 0x1d8) = 1;
              (**(code **)(param_1 + 0x194))(iVar3 + 0x5a);
              goto LAB_0055285d;
            }
            break;
          }
          iVar3 = iVar3 + 1;
          piVar2 = piVar2 + 1;
        } while (iVar3 < 9);
        iVar3 = 0;
        piVar2 = (int *)(param_1 + 0x170);
        do {
          if (param_3 == *piVar2) {
            if (iVar3 != -1) {
              *(undefined1 *)(param_1 + 0x1d8) = 1;
              (**(code **)(param_1 + 0x198))(iVar3);
              goto LAB_0055285d;
            }
            break;
          }
          iVar3 = iVar3 + 1;
          piVar2 = piVar2 + 1;
        } while (iVar3 < 6);
        iVar3 = 0;
        piVar2 = (int *)(param_1 + 0xf8);
LAB_00552884:
        if (param_3 != *piVar2) goto code_r0x00552888;
        if (iVar3 != -1) {
          *(undefined1 *)(param_1 + 0x1d8) = 1;
          FUN_00555950(iVar3);
LAB_0055285d:
          *(undefined1 *)(param_1 + 0x1d8) = 0;
          goto LAB_005527f8;
        }
        goto LAB_005527e1;
      }
    }
    else {
      if (param_2 != 0x20) goto LAB_005527e1;
      FUN_005547b8(1);
      *(int *)(param_1 + 0xe4) = param_3;
    }
LAB_005527f8:
    FUN_005dadbc(0,1);
    uVar1 = 1;
  }
  else {
LAB_005527e1:
    uVar1 = 0;
  }
  return uVar1;
code_r0x00552888:
  iVar3 = iVar3 + 1;
  piVar2 = piVar2 + 1;
  if (6 < iVar3) goto LAB_005527e1;
  goto LAB_00552884;
}

