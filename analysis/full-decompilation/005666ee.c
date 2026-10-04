
void __thiscall FUN_005666ee(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (*(int *)(param_1 + 0x424) == 2) {
    FUN_005e46f0(0);
    iVar1 = 9;
    do {
      FUN_0054f3dc(0);
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    FUN_0057a7f7(s_UI_Nhood_bdoze_cancel_006cda44,0xfffffffc);
  }
  else if (*(int *)(param_1 + 0x424) == 3) {
    *(undefined1 *)(param_1 + 0x11c) = 0;
    *(undefined4 *)(param_1 + 0x118) = 0;
    FUN_00567a12();
  }
  *(int *)(param_1 + 0x424) = param_2;
  if (param_2 == 0) {
    if (*(char *)(param_1 + 0x3b4) != '\0') {
      piVar2 = *(int **)(param_1 + 0x3fc);
      if ((char)piVar2[0x5a] != '\x01') {
        *(undefined1 *)(piVar2 + 0x5a) = 1;
        (**(code **)(*piVar2 + 0x168))();
      }
      piVar2 = *(int **)(param_1 + 0x400);
      if ((char)piVar2[0x5a] != '\x01') {
        *(undefined1 *)(piVar2 + 0x5a) = 1;
        (**(code **)(*piVar2 + 0x168))();
      }
      piVar2 = *(int **)(param_1 + 0x404);
      if ((char)piVar2[0x5a] != '\x01') {
        *(undefined1 *)(piVar2 + 0x5a) = 1;
        (**(code **)(*piVar2 + 0x168))();
      }
      FUN_00566d9f();
    }
    *(undefined1 **)(param_1 + 0x41c) = &LAB_00565af9;
    *(code **)(param_1 + 0x420) = FUN_00565c9a;
    if (*(char *)(param_1 + 0x3b4) != '\0') {
      iVar1 = FUN_005e749a(4);
      goto LAB_00566945;
    }
    if (*(char *)(param_1 + 0xe0) == '\0') {
      uVar4 = 0x2d;
    }
    else {
      uVar4 = 0x2c;
    }
  }
  else {
    if (param_2 == 2) {
      if (*(char *)(param_1 + 0x3b4) != '\0') {
        piVar2 = *(int **)(param_1 + 0x3fc);
        if ((char)piVar2[0x5a] != '\0') {
          *(undefined1 *)(piVar2 + 0x5a) = 0;
          (**(code **)(*piVar2 + 0x168))();
        }
        piVar2 = *(int **)(param_1 + 0x400);
        if ((char)piVar2[0x5a] != '\0') {
          *(undefined1 *)(piVar2 + 0x5a) = 0;
          (**(code **)(*piVar2 + 0x168))();
        }
        piVar2 = *(int **)(param_1 + 0x404);
        if ((char)piVar2[0x5a] != '\0') {
          *(undefined1 *)(piVar2 + 0x5a) = 0;
          (**(code **)(*piVar2 + 0x168))();
        }
        piVar2 = *(int **)(param_1 + 0x408);
        if ((char)piVar2[0x5a] != '\0') {
          *(undefined1 *)(piVar2 + 0x5a) = 0;
          (**(code **)(*piVar2 + 0x168))();
        }
      }
      *(code **)(param_1 + 0x41c) = FUN_00565b68;
      *(undefined1 **)(param_1 + 0x420) = &LAB_00566696;
      iVar1 = FUN_005e74ca(0x22);
      FUN_005e46f0(1);
      iVar3 = 9;
      do {
        FUN_0054f3dc(1);
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      FUN_0057a7f7(s_UI_Nhood_bdoze_006cda34,0xfffffffc);
      goto LAB_00566945;
    }
    if (param_2 != 3) {
      return;
    }
    *(undefined1 *)(param_1 + 0x11c) = 1;
    *(undefined1 **)(param_1 + 0x41c) = &LAB_005679fc;
    uVar4 = 0x28;
  }
  iVar1 = FUN_005e74ca(uVar4);
LAB_00566945:
  if (iVar1 != 0) {
    FUN_005dde6d(iVar1);
    piVar2 = (int *)(param_1 + 0x3d8);
    iVar3 = 9;
    do {
      if (*piVar2 != 0) {
        FUN_005dde6d(iVar1);
      }
      piVar2 = piVar2 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return;
}

