
void __thiscall FUN_00561954(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0xd4) == 1) {
    FUN_005e46f0(0);
  }
  else if (*(int *)(param_1 + 0xd4) == 2) {
    FUN_005e46f0(0);
    iVar1 = 10;
    do {
      FUN_0054f3dc(0);
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    FUN_0057a7f7(s_UI_Nhood_bdoze_cancel_006cda44,0xfffffffc);
  }
  *(int *)(param_1 + 0xd4) = param_2;
  if (param_2 == 0) {
    piVar2 = *(int **)(param_1 + 300);
    if ((char)piVar2[0x5a] != '\x01') {
      *(undefined1 *)(piVar2 + 0x5a) = 1;
      (**(code **)(*piVar2 + 0x168))();
    }
    piVar2 = *(int **)(param_1 + 0x140);
    if ((char)piVar2[0x5a] != '\x01') {
      *(undefined1 *)(piVar2 + 0x5a) = 1;
      (**(code **)(*piVar2 + 0x168))();
    }
    piVar2 = *(int **)(param_1 + 0x11c);
    if ((char)piVar2[0x5a] != '\x01') {
      *(undefined1 *)(piVar2 + 0x5a) = 1;
      (**(code **)(*piVar2 + 0x168))();
    }
    piVar2 = *(int **)(param_1 + 0x124);
    if ((char)piVar2[0x5a] != '\x01') {
      *(undefined1 *)(piVar2 + 0x5a) = 1;
      (**(code **)(*piVar2 + 0x168))();
    }
    piVar2 = *(int **)(param_1 + 0x128);
    if ((char)piVar2[0x5a] != '\x01') {
      *(undefined1 *)(piVar2 + 0x5a) = 1;
      (**(code **)(*piVar2 + 0x168))();
    }
    piVar2 = *(int **)(param_1 + 0x130);
    if ((char)piVar2[0x5a] != '\x01') {
      *(undefined1 *)(piVar2 + 0x5a) = 1;
      (**(code **)(*piVar2 + 0x168))();
    }
    piVar2 = *(int **)(param_1 + 0x134);
    if ((char)piVar2[0x5a] != '\x01') {
      *(undefined1 *)(piVar2 + 0x5a) = 1;
      (**(code **)(*piVar2 + 0x168))();
    }
    if ((*(byte *)(DAT_006e486c + 0x66) & 4) != 0) {
      piVar2 = *(int **)(param_1 + 0x13c);
      if ((char)piVar2[0x5a] != '\x01') {
        *(undefined1 *)(piVar2 + 0x5a) = 1;
        (**(code **)(*piVar2 + 0x168))();
      }
    }
    if ((*(byte *)(DAT_006e486c + 0x66) & 8) != 0) {
      piVar2 = *(int **)(param_1 + 0x144);
      if ((char)piVar2[0x5a] != '\x01') {
        *(undefined1 *)(piVar2 + 0x5a) = 1;
        (**(code **)(*piVar2 + 0x168))();
      }
    }
    if ((*(byte *)(DAT_006e486c + 0x66) & 0x40) != 0) {
      piVar2 = *(int **)(param_1 + 0x14c);
      if ((char)piVar2[0x5a] != '\x01') {
        *(undefined1 *)(piVar2 + 0x5a) = 1;
        (**(code **)(*piVar2 + 0x168))();
      }
    }
    if ((*(byte *)(DAT_006e486c + 0x66) & 0x80) != 0) {
      piVar2 = *(int **)(param_1 + 0x150);
      if ((char)piVar2[0x5a] != '\x01') {
        *(undefined1 *)(piVar2 + 0x5a) = 1;
        (**(code **)(*piVar2 + 0x168))();
      }
    }
    *(code **)(param_1 + 0x158) = FUN_0056007a;
    *(code **)(param_1 + 0x15c) = FUN_005607f3;
    iVar1 = FUN_005e749a(4);
  }
  else if (param_2 == 1) {
    *(code **)(param_1 + 0x158) = FUN_0056026e;
    *(code **)(param_1 + 0x15c) = FUN_005607f3;
    iVar1 = FUN_005e74ca(0x21);
    FUN_005e46f0(1);
  }
  else {
    if (param_2 != 2) {
      return;
    }
    piVar2 = *(int **)(param_1 + 300);
    if ((char)piVar2[0x5a] != '\0') {
      *(undefined1 *)(piVar2 + 0x5a) = 0;
      (**(code **)(*piVar2 + 0x168))();
    }
    piVar2 = *(int **)(param_1 + 0x140);
    if ((char)piVar2[0x5a] != '\0') {
      *(undefined1 *)(piVar2 + 0x5a) = 0;
      (**(code **)(*piVar2 + 0x168))();
    }
    piVar2 = *(int **)(param_1 + 0x11c);
    if ((char)piVar2[0x5a] != '\0') {
      *(undefined1 *)(piVar2 + 0x5a) = 0;
      (**(code **)(*piVar2 + 0x168))();
    }
    piVar2 = *(int **)(param_1 + 0x124);
    if ((char)piVar2[0x5a] != '\0') {
      *(undefined1 *)(piVar2 + 0x5a) = 0;
      (**(code **)(*piVar2 + 0x168))();
    }
    piVar2 = *(int **)(param_1 + 0x128);
    if ((char)piVar2[0x5a] != '\0') {
      *(undefined1 *)(piVar2 + 0x5a) = 0;
      (**(code **)(*piVar2 + 0x168))();
    }
    piVar2 = *(int **)(param_1 + 0x130);
    if ((char)piVar2[0x5a] != '\0') {
      *(undefined1 *)(piVar2 + 0x5a) = 0;
      (**(code **)(*piVar2 + 0x168))();
    }
    piVar2 = *(int **)(param_1 + 0x134);
    if ((char)piVar2[0x5a] != '\0') {
      *(undefined1 *)(piVar2 + 0x5a) = 0;
      (**(code **)(*piVar2 + 0x168))();
    }
    piVar2 = *(int **)(param_1 + 0x13c);
    if ((char)piVar2[0x5a] != '\0') {
      *(undefined1 *)(piVar2 + 0x5a) = 0;
      (**(code **)(*piVar2 + 0x168))();
    }
    piVar2 = *(int **)(param_1 + 0x144);
    if ((char)piVar2[0x5a] != '\0') {
      *(undefined1 *)(piVar2 + 0x5a) = 0;
      (**(code **)(*piVar2 + 0x168))();
    }
    piVar2 = *(int **)(param_1 + 0x14c);
    if ((char)piVar2[0x5a] != '\0') {
      *(undefined1 *)(piVar2 + 0x5a) = 0;
      (**(code **)(*piVar2 + 0x168))();
    }
    piVar2 = *(int **)(param_1 + 0x150);
    if ((char)piVar2[0x5a] != '\0') {
      *(undefined1 *)(piVar2 + 0x5a) = 0;
      (**(code **)(*piVar2 + 0x168))();
    }
    *(code **)(param_1 + 0x158) = FUN_0056044b;
    *(undefined1 **)(param_1 + 0x15c) = &LAB_00561906;
    iVar1 = FUN_005e74ca(0x22);
    FUN_005e46f0(1);
    param_2 = 10;
    do {
      FUN_0054f3dc(1);
      param_2 = param_2 + -1;
    } while (param_2 != 0);
    FUN_0057a7f7(s_UI_Nhood_bdoze_006cda34,0xfffffffc);
  }
  if (iVar1 != 0) {
    FUN_005dde6d(iVar1);
    piVar2 = (int *)(param_1 + 0xf4);
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

