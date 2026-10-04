
void __thiscall FUN_005547b8(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  
  iVar2 = *(int *)(param_1 + 0xd4);
  if (iVar2 == 1) {
    FUN_005e46f0(0);
  }
  else if (iVar2 == 2) {
    FUN_005e46f0(0);
    iVar2 = 9;
    do {
      FUN_0054f3dc(0);
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    FUN_0057a7f7(s_UI_Nhood_bdoze_cancel_006cda44,0xfffffffc);
  }
  else if (iVar2 == 5) {
    *(undefined1 *)(param_1 + 0x128) = 0;
    *(undefined4 *)(param_1 + 0x124) = 0;
    FUN_00555b68();
  }
  iVar2 = 0;
  *(int *)(param_1 + 0xd4) = param_2;
  if (param_2 == 0) {
    if (*(char *)(param_1 + 0x12a) != '\0') {
      piVar3 = *(int **)(param_1 + 0x170);
      if ((char)piVar3[0x5a] != '\x01') {
        *(undefined1 *)(piVar3 + 0x5a) = 1;
        (**(code **)(*piVar3 + 0x168))();
      }
      piVar3 = *(int **)(param_1 + 0x174);
      if ((char)piVar3[0x5a] != '\x01') {
        *(undefined1 *)(piVar3 + 0x5a) = 1;
        (**(code **)(*piVar3 + 0x168))();
      }
      piVar3 = *(int **)(param_1 + 0x178);
      if ((char)piVar3[0x5a] != '\x01') {
        *(undefined1 *)(piVar3 + 0x5a) = 1;
        (**(code **)(*piVar3 + 0x168))();
      }
      piVar3 = *(int **)(param_1 + 0x184);
      if ((char)piVar3[0x5a] != '\x01') {
        *(undefined1 *)(piVar3 + 0x5a) = 1;
        (**(code **)(*piVar3 + 0x168))();
      }
      FUN_00554f58();
    }
    *(code **)(param_1 + 0x194) = FUN_00552a75;
    *(code **)(param_1 + 0x198) = FUN_00552fa9;
    if (*(char *)(param_1 + 0x12a) != '\0') {
      iVar1 = FUN_005e749a(4);
      goto LAB_00554afa;
    }
    uVar4 = 0x2f;
  }
  else {
    if (param_2 == 1) {
      *(code **)(param_1 + 0x194) = FUN_00556352;
      *(code **)(param_1 + 0x198) = FUN_00552fa9;
      iVar1 = FUN_005e74ca(0x21);
      FUN_005e46f0(1);
      goto LAB_00554afa;
    }
    if (param_2 == 2) {
      if (*(char *)(param_1 + 0x12a) != '\0') {
        piVar3 = *(int **)(param_1 + 0x170);
        if ((char)piVar3[0x5a] != '\0') {
          *(undefined1 *)(piVar3 + 0x5a) = 0;
          (**(code **)(*piVar3 + 0x168))();
        }
        piVar3 = *(int **)(param_1 + 0x174);
        if ((char)piVar3[0x5a] != '\0') {
          *(undefined1 *)(piVar3 + 0x5a) = 0;
          (**(code **)(*piVar3 + 0x168))();
        }
        piVar3 = *(int **)(param_1 + 0x178);
        if ((char)piVar3[0x5a] != '\0') {
          *(undefined1 *)(piVar3 + 0x5a) = 0;
          (**(code **)(*piVar3 + 0x168))();
        }
        piVar3 = *(int **)(param_1 + 0x184);
        if ((char)piVar3[0x5a] != '\0') {
          *(undefined1 *)(piVar3 + 0x5a) = 0;
          (**(code **)(*piVar3 + 0x168))();
        }
        piVar3 = *(int **)(param_1 + 0x17c);
        if ((char)piVar3[0x5a] != '\0') {
          *(undefined1 *)(piVar3 + 0x5a) = 0;
          (**(code **)(*piVar3 + 0x168))();
        }
      }
      *(code **)(param_1 + 0x194) = FUN_00552c63;
      *(undefined1 **)(param_1 + 0x198) = &LAB_0055474e;
      iVar1 = FUN_005e74ca(0x22);
      FUN_005e46f0(1);
      iVar2 = 9;
      do {
        FUN_0054f3dc(1);
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      FUN_0057a7f7(s_UI_Nhood_bdoze_006cda34,0xfffffffc);
      goto LAB_00554afa;
    }
    if (param_2 == 4) {
      *(undefined1 **)(param_1 + 0x194) = &LAB_00556593;
      *(code **)(param_1 + 0x198) = FUN_004ac500;
      iVar1 = FUN_005e74ca((*(char *)(param_1 + 0xec) != '\0') + '.');
      do {
        FUN_0054f3dc(2);
        if (2 < iVar2) {
          FUN_0054f7ae(1);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < 9);
      goto LAB_00554afa;
    }
    if (param_2 != 5) {
      return;
    }
    *(undefined1 *)(param_1 + 0x128) = 1;
    *(undefined1 **)(param_1 + 0x194) = &LAB_00555b52;
    uVar4 = 0x28;
  }
  iVar1 = FUN_005e74ca(uVar4);
LAB_00554afa:
  if (iVar1 != 0) {
    FUN_005dde6d(iVar1);
    piVar3 = (int *)(param_1 + 0x14c);
    iVar2 = 9;
    do {
      if (*piVar3 != 0) {
        FUN_005dde6d(iVar1);
      }
      piVar3 = piVar3 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}

