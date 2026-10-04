
void __thiscall FUN_0056b2f2(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (*(int *)(param_1 + 0x1a4) == 2) {
    FUN_005e46f0(0);
    iVar1 = 9;
    do {
      FUN_0054f3dc(0);
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    FUN_0057a7f7(s_UI_Nhood_bdoze_cancel_006cda44,0xfffffffc);
  }
  else if (*(int *)(param_1 + 0x1a4) == 3) {
    *(undefined1 *)(param_1 + 0x110) = 0;
    *(undefined4 *)(param_1 + 0x10c) = 0;
    FUN_0056c78c();
  }
  *(int *)(param_1 + 0x1a4) = param_2;
  if (param_2 == 0) {
    if (*(char *)(param_1 + 0x128) != '\0') {
      piVar2 = *(int **)(param_1 + 0x17c);
      if ((char)piVar2[0x5a] != '\x01') {
        *(undefined1 *)(piVar2 + 0x5a) = 1;
        (**(code **)(*piVar2 + 0x168))();
      }
      piVar2 = *(int **)(param_1 + 0x180);
      if ((char)piVar2[0x5a] != '\x01') {
        *(undefined1 *)(piVar2 + 0x5a) = 1;
        (**(code **)(*piVar2 + 0x168))();
      }
      piVar2 = *(int **)(param_1 + 0x184);
      if ((char)piVar2[0x5a] != '\x01') {
        *(undefined1 *)(piVar2 + 0x5a) = 1;
        (**(code **)(*piVar2 + 0x168))();
      }
      FUN_0056b9c4();
    }
    *(undefined1 **)(param_1 + 0x19c) = &LAB_0056a169;
    *(code **)(param_1 + 0x1a0) = FUN_0056a5f4;
    if (*(char *)(param_1 + 0x128) != '\0') {
      iVar1 = FUN_005e749a(4);
      goto LAB_0056b531;
    }
    uVar4 = 0x27;
  }
  else {
    if (param_2 == 2) {
      if (*(char *)(param_1 + 0x128) != '\0') {
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
        piVar2 = *(int **)(param_1 + 0x184);
        if ((char)piVar2[0x5a] != '\0') {
          *(undefined1 *)(piVar2 + 0x5a) = 0;
          (**(code **)(*piVar2 + 0x168))();
        }
        piVar2 = *(int **)(param_1 + 0x188);
        if ((char)piVar2[0x5a] != '\0') {
          *(undefined1 *)(piVar2 + 0x5a) = 0;
          (**(code **)(*piVar2 + 0x168))();
        }
      }
      *(undefined1 **)(param_1 + 0x19c) = &LAB_0056a2d6;
      *(undefined1 **)(param_1 + 0x1a0) = &LAB_0056b29a;
      iVar1 = FUN_005e74ca(0x22);
      FUN_005e46f0(1);
      iVar3 = 9;
      do {
        FUN_0054f3dc(1);
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      FUN_0057a7f7(s_UI_Nhood_bdoze_006cda34,0xfffffffc);
      goto LAB_0056b531;
    }
    if (param_2 != 3) {
      return;
    }
    *(undefined1 *)(param_1 + 0x110) = 1;
    *(undefined1 **)(param_1 + 0x19c) = &LAB_0056c776;
    uVar4 = 0x28;
  }
  iVar1 = FUN_005e74ca(uVar4);
LAB_0056b531:
  if (iVar1 != 0) {
    FUN_005dde6d(iVar1);
    piVar2 = (int *)(param_1 + 0x154);
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

