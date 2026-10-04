
undefined4 __thiscall FUN_004f666b(int param_1,short param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_2 < 0xe5) {
    if (param_2 != 0xe4) {
      if (param_2 < 0xdc) {
        if (param_2 != 0xdb) {
          if (param_2 == 0x87) {
            iVar1 = FUN_00407498(param_3);
            if ((iVar1 != 0) && (*(short *)(*(int *)(iVar1 + 0x118) + 0x12) == 2)) {
              FUN_004cfc01(iVar1);
            }
            piVar2 = (int *)FUN_004cebb4();
            if (piVar2 != (int *)0x0) {
              (**(code **)(*piVar2 + 0x6c))(param_3);
            }
            if (*(int *)(param_1 + 0x1c) == 0) {
              return 1;
            }
            FUN_004d2f53(iVar1);
            return 1;
          }
          if (param_2 != 0x88) {
            if (param_2 == 0x91) {
              if (*(int *)(param_1 + 0x48) == 0) {
                return 1;
              }
              iVar1 = FUN_00401f6f();
              if (iVar1 != 0) {
                return 1;
              }
              uVar4 = 0x100;
              goto LAB_004f6799;
            }
            if (param_2 != 0xda) {
              return 0;
            }
            if (*(char *)(param_1 + 0x8c) != '\0') {
              return 1;
            }
            if (*(char *)(param_1 + 0x8d) != '\0') {
              return 1;
            }
            *(undefined1 *)(param_1 + 0x8f) = 1;
            uVar4 = 0x4000;
            goto LAB_004f695e;
          }
LAB_004f67ba:
          if (*(char *)(param_1 + 0x8d) != '\0') {
            return 1;
          }
          *(undefined1 *)(param_1 + 0x8f) = 1;
          return 1;
        }
        if (*(short *)(*(int *)(DAT_006e486c + 0x1c) + 0x1a) == 0) {
          FUN_0057ad70();
        }
      }
      else if (param_2 != 0xdc) {
        if (param_2 == 0xe0) {
          FUN_004e8b76();
          return 1;
        }
        if (param_2 != 0xe2) {
          return 0;
        }
        goto LAB_004f67ba;
      }
    }
  }
  else {
    if (0x107 < param_2) {
      if (param_2 == 0x108) {
        if (*(char *)(param_1 + 0x90) != '\0') {
          return 1;
        }
        uVar4 = 0x1000000;
      }
      else {
        if (param_2 == 0x109) {
          *(bool *)(*(int *)(*(int *)(param_1 + 0x20) + 0xdc) + 0x1ec) = param_3 != 0;
          FUN_0053b6eb(2);
          return 1;
        }
        if (param_2 != 0x10c) {
          return 0;
        }
        iVar1 = FUN_004425e2();
        iVar3 = FUN_0046d8a7();
        if (iVar3 == iVar1) {
          return 1;
        }
        FUN_0046d7b3(iVar1);
        uVar4 = 0x40;
      }
      goto LAB_004f695e;
    }
    if (param_2 == 0x107) {
      if (*(int *)(*(int *)(param_1 + 0x1c) + 0x11ac) == 0) {
        return 1;
      }
      FUN_004ffd9a();
      return 1;
    }
    if (param_2 == 0xe8) {
      uVar4 = 0xffffffff;
      goto LAB_004f6799;
    }
    if (param_2 != 0xee) {
      if (param_2 != 0xf6) {
        if (param_2 == 0xfa) {
          FUN_0057a706();
          FUN_004f277c();
          FUN_004f5aa0(0);
          return 1;
        }
        return 0;
      }
      if (*(int *)(param_1 + 0x48) != 0) {
        FUN_004cee86(0x80000);
      }
      if (*(int *)(*(int *)(param_1 + 0x1c) + 0x11ac) != 0) {
        FUN_004ffd9a();
      }
      if (*(int **)(DAT_006fe8f4 + 500) != (int *)0x0) {
        (**(code **)(**(int **)(DAT_006fe8f4 + 500) + 0x98))();
      }
      if (*(short *)(*(int *)(DAT_006e486c + 0x1c) + 0x44) == 0) {
        return 1;
      }
      (**(code **)(**(int **)(*(int *)(param_1 + 0x20) + 0xec) + 0x94))();
      (**(code **)(**(int **)(*(int *)(param_1 + 0x20) + 0xec) + 0x98))();
      return 1;
    }
  }
  if (*(char *)(param_1 + 0x8c) != '\0') {
    return 1;
  }
  *(undefined1 *)(param_1 + 0x8f) = 1;
  if (param_2 == 0xee) {
    uVar4 = 4;
LAB_004f6799:
    FUN_004cee86(uVar4);
    return 1;
  }
  if (param_2 == 0xe4) {
    uVar4 = 8;
  }
  else {
    if (param_2 != 0xdb) {
      return 1;
    }
    uVar4 = 0x2000;
  }
LAB_004f695e:
  FUN_004cee86(uVar4);
  FUN_004ce5aa();
  return 1;
}

