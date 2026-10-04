
void __thiscall FUN_0054c4af(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (*(int *)(param_1 + 0x19c) == 2) {
    FUN_005e46f0(0);
    iVar1 = 10;
    do {
      FUN_0054f3dc(0);
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    FUN_0057a7f7(s_UI_Nhood_bdoze_cancel_006cda44,0xfffffffc);
  }
  else if (*(int *)(param_1 + 0x19c) == 3) {
    *(undefined1 *)(param_1 + 0x110) = 0;
    *(undefined4 *)(param_1 + 0x10c) = 0;
    FUN_0054d8dc();
  }
  *(int *)(param_1 + 0x19c) = param_2;
  if (param_2 == 0) {
    if (*(char *)(param_1 + 0x128) != '\0') {
      piVar2 = *(int **)(param_1 + 0x174);
      if ((char)piVar2[0x5a] != '\x01') {
        *(undefined1 *)(piVar2 + 0x5a) = 1;
        (**(code **)(*piVar2 + 0x168))();
      }
      piVar2 = *(int **)(param_1 + 0x178);
      if ((char)piVar2[0x5a] != '\x01') {
        *(undefined1 *)(piVar2 + 0x5a) = 1;
        (**(code **)(*piVar2 + 0x168))();
      }
      piVar2 = *(int **)(param_1 + 0x17c);
      if ((char)piVar2[0x5a] != '\x01') {
        *(undefined1 *)(piVar2 + 0x5a) = 1;
        (**(code **)(*piVar2 + 0x168))();
      }
      FUN_0054cb4f();
    }
    *(undefined1 **)(param_1 + 0x194) = &LAB_0054b896;
    *(code **)(param_1 + 0x198) = FUN_0054b9fa;
    if (*(char *)(param_1 + 0x128) != '\0') {
      iVar1 = FUN_005e749a(4);
      goto LAB_0054c6ee;
    }
    uVar4 = 0x25;
  }
  else {
    if (param_2 == 2) {
      if (*(char *)(param_1 + 0x128) != '\0') {
        piVar2 = *(int **)(param_1 + 0x174);
        if ((char)piVar2[0x5a] != '\0') {
          *(undefined1 *)(piVar2 + 0x5a) = 0;
          (**(code **)(*piVar2 + 0x168))();
        }
        piVar2 = *(int **)(param_1 + 0x178);
        if ((char)piVar2[0x5a] != '\0') {
          *(undefined1 *)(piVar2 + 0x5a) = 0;
          (**(code **)(*piVar2 + 0x168))();
        }
        piVar2 = *(int **)(param_1 + 0x17c);
        if ((char)piVar2[0x5a] != '\0') {
          *(undefined1 *)(piVar2 + 0x5a) = 0;
          (**(code **)(*piVar2 + 0x168))();
        }
        piVar2 = *(int **)(param_1 + 0x180);
        if ((char)piVar2[0x5a] != '\0') {
          *(undefined1 *)(piVar2 + 0x5a) = 0;
          (**(code **)(*piVar2 + 0x168))();
        }
      }
      *(code **)(param_1 + 0x194) = FUN_0054b8d3;
      *(undefined1 **)(param_1 + 0x198) = &LAB_0054c457;
      iVar1 = FUN_005e74ca(0x22);
      FUN_005e46f0(1);
      iVar3 = 10;
      do {
        FUN_0054f3dc(1);
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      FUN_0057a7f7(s_UI_Nhood_bdoze_006cda34,0xfffffffc);
      goto LAB_0054c6ee;
    }
    if (param_2 != 3) {
      return;
    }
    *(undefined1 *)(param_1 + 0x110) = 1;
    *(undefined1 **)(param_1 + 0x194) = &LAB_0054d8c6;
    uVar4 = 0x28;
  }
  iVar1 = FUN_005e74ca(uVar4);
LAB_0054c6ee:
  if (iVar1 != 0) {
    FUN_005dde6d(iVar1);
    piVar2 = (int *)(param_1 + 0x14c);
    iVar3 = 10;
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

