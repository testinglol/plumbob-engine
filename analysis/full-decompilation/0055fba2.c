
undefined4 __thiscall FUN_0055fba2(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  
  if (*(char *)(param_1 + 0x164) == '\0') {
    if (param_2 == 1) {
      if (*(char *)(param_1 + 0x1ac) == '\0') {
        iVar3 = 0;
        piVar2 = (int *)(param_1 + 0xf4);
        do {
          if (param_3 == *piVar2) {
            if (iVar3 + 1 != -1) {
              *(undefined1 *)(param_1 + 0x1ac) = 1;
              (**(code **)(param_1 + 0x158))(iVar3 + 1);
              goto LAB_0055fc38;
            }
            break;
          }
          iVar3 = iVar3 + 1;
          piVar2 = piVar2 + 1;
        } while (iVar3 < 10);
        iVar3 = 0;
        piVar2 = (int *)(param_1 + 0x11c);
LAB_0055fc11:
        if (param_3 != *piVar2) goto code_r0x0055fc15;
        if (iVar3 != -1) {
          *(undefined1 *)(param_1 + 0x1ac) = 1;
          (**(code **)(param_1 + 0x15c))(iVar3);
LAB_0055fc38:
          *(undefined1 *)(param_1 + 0x1ac) = 0;
          goto LAB_0055fbd3;
        }
        goto LAB_0055fbbc;
      }
    }
    else {
      if (param_2 != 0x20) goto LAB_0055fbbc;
      FUN_00561954(1);
      *(int *)(param_1 + 0x160) = param_3;
    }
LAB_0055fbd3:
    FUN_005dadbc(0,1);
    uVar1 = 1;
  }
  else {
LAB_0055fbbc:
    uVar1 = 0;
  }
  return uVar1;
code_r0x0055fc15:
  iVar3 = iVar3 + 1;
  piVar2 = piVar2 + 1;
  if (0xd < iVar3) goto LAB_0055fbbc;
  goto LAB_0055fc11;
}

