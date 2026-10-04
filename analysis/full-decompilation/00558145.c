
undefined4 __thiscall FUN_00558145(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  
  if (*(char *)(param_1 + 0x1b0) == '\0') {
    if (param_2 == 1) {
      if (*(char *)(param_1 + 0x208) == '\0') {
        iVar4 = *(int *)(param_1 + 0x148);
        iVar1 = *(int *)(iVar4 + 8);
        while (iVar1 != iVar4) {
          if (param_3 == *(int *)(iVar1 + 0x14)) {
            iVar4 = *(int *)(*(int *)(iVar1 + 0x14) + 0x1d8);
            if (iVar4 != -1) {
              *(undefined1 *)(param_1 + 0x208) = 1;
              (**(code **)(param_1 + 0x1a4))(iVar4);
              goto LAB_005581f7;
            }
            break;
          }
          FUN_0041674f();
          iVar4 = *(int *)(param_1 + 0x148);
        }
        iVar4 = 0;
        piVar3 = (int *)(param_1 + 0x154);
        do {
          if (param_3 == *piVar3) {
            if (iVar4 != -1) {
              *(undefined1 *)(param_1 + 0x208) = 1;
              (**(code **)(param_1 + 0x1a8))(iVar4);
              goto LAB_005581f7;
            }
            break;
          }
          iVar4 = iVar4 + 1;
          piVar3 = piVar3 + 1;
        } while (iVar4 < 0xe);
        iVar4 = 0;
        piVar3 = (int *)(param_1 + 0xe4);
LAB_00558221:
        if (param_3 != *piVar3) goto code_r0x00558225;
        if (iVar4 != -1) {
          *(undefined1 *)(param_1 + 0x208) = 1;
          FUN_0055dd99(iVar4);
LAB_005581f7:
          *(undefined1 *)(param_1 + 0x208) = 0;
          goto LAB_00558178;
        }
        goto LAB_00558162;
      }
    }
    else {
      if (param_2 != 0x20) goto LAB_00558162;
      FUN_0055b4e6(1);
      *(int *)(param_1 + 0x1ac) = param_3;
    }
LAB_00558178:
    FUN_005dadbc(0,1);
    uVar2 = 1;
  }
  else {
LAB_00558162:
    uVar2 = 0;
  }
  return uVar2;
code_r0x00558225:
  iVar4 = iVar4 + 1;
  piVar3 = piVar3 + 1;
  if (6 < iVar4) goto LAB_00558162;
  goto LAB_00558221;
}

