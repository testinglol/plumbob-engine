
void __thiscall FUN_0055b4e6(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar4 = *(int *)(param_1 + 0xd4);
  if (iVar4 == 1) {
    FUN_005e46f0(0);
  }
  else {
    if (iVar4 == 2) {
      FUN_005e46f0(0);
      iVar4 = *(int *)(param_1 + 0x148);
      iVar2 = *(int *)(iVar4 + 8);
      while (iVar2 != iVar4) {
        FUN_0054f3dc(0);
        FUN_0041674f();
        iVar4 = *(int *)(param_1 + 0x148);
      }
    }
    else {
      if (iVar4 != 3) {
        if (iVar4 == 5) {
          *(undefined1 *)(param_1 + 0x120) = 0;
          *(undefined4 *)(param_1 + 0x11c) = 0;
          FUN_0055d55e();
        }
        goto LAB_0055b5bb;
      }
      FUN_005e46f0(0);
      iVar4 = *(int *)(param_1 + 0x148);
      iVar2 = *(int *)(iVar4 + 8);
      while (iVar2 != iVar4) {
        FUN_0054f3dc(0);
        FUN_0041674f();
        iVar4 = *(int *)(param_1 + 0x148);
      }
    }
    FUN_0057a7f7(s_UI_Nhood_bdoze_cancel_006cda44,0xfffffffc);
  }
LAB_0055b5bb:
  *(int *)(param_1 + 0xd4) = param_2;
  if (param_2 == 0) {
    if (*(char *)(param_1 + 0x121) != '\0') {
      piVar1 = *(int **)(param_1 + 0x164);
      if ((char)piVar1[0x5a] != '\x01') {
        *(undefined1 *)(piVar1 + 0x5a) = 1;
        (**(code **)(*piVar1 + 0x168))();
      }
      piVar1 = *(int **)(param_1 + 0x178);
      if ((char)piVar1[0x5a] != '\x01') {
        *(undefined1 *)(piVar1 + 0x5a) = 1;
        (**(code **)(*piVar1 + 0x168))();
      }
      piVar1 = *(int **)(param_1 + 0x154);
      if ((char)piVar1[0x5a] != '\x01') {
        *(undefined1 *)(piVar1 + 0x5a) = 1;
        (**(code **)(*piVar1 + 0x168))();
      }
      piVar1 = *(int **)(param_1 + 0x15c);
      if ((char)piVar1[0x5a] != '\x01') {
        *(undefined1 *)(piVar1 + 0x5a) = 1;
        (**(code **)(*piVar1 + 0x168))();
      }
      piVar1 = *(int **)(param_1 + 0x160);
      if ((char)piVar1[0x5a] != '\x01') {
        *(undefined1 *)(piVar1 + 0x5a) = 1;
        (**(code **)(*piVar1 + 0x168))();
      }
      piVar1 = *(int **)(param_1 + 0x168);
      if ((char)piVar1[0x5a] != '\x01') {
        *(undefined1 *)(piVar1 + 0x5a) = 1;
        (**(code **)(*piVar1 + 0x168))();
      }
      piVar1 = *(int **)(param_1 + 0x16c);
      if ((char)piVar1[0x5a] != '\x01') {
        *(undefined1 *)(piVar1 + 0x5a) = 1;
        (**(code **)(*piVar1 + 0x168))();
      }
      piVar1 = *(int **)(param_1 + 0x158);
      if ((char)piVar1[0x5a] != '\x01') {
        *(undefined1 *)(piVar1 + 0x5a) = 1;
        (**(code **)(*piVar1 + 0x168))();
      }
      piVar1 = *(int **)(param_1 + 0x180);
      if ((char)piVar1[0x5a] != '\x01') {
        *(undefined1 *)(piVar1 + 0x5a) = 1;
        (**(code **)(*piVar1 + 0x168))();
      }
      if ((*(byte *)(DAT_006e486c + 0x66) & 4) != 0) {
        piVar1 = *(int **)(param_1 + 0x174);
        if ((char)piVar1[0x5a] != '\x01') {
          *(undefined1 *)(piVar1 + 0x5a) = 1;
          (**(code **)(*piVar1 + 0x168))();
        }
      }
      if ((*(byte *)(DAT_006e486c + 0x66) & 8) != 0) {
        piVar1 = *(int **)(param_1 + 0x17c);
        if ((char)piVar1[0x5a] != '\x01') {
          *(undefined1 *)(piVar1 + 0x5a) = 1;
          (**(code **)(*piVar1 + 0x168))();
        }
      }
      if ((*(byte *)(DAT_006e486c + 0x66) & 0x40) != 0) {
        piVar1 = *(int **)(param_1 + 0x184);
        if ((char)piVar1[0x5a] != '\x01') {
          *(undefined1 *)(piVar1 + 0x5a) = 1;
          (**(code **)(*piVar1 + 0x168))();
        }
      }
      if ((*(byte *)(DAT_006e486c + 0x66) & 0x80) != 0) {
        piVar1 = *(int **)(param_1 + 0x188);
        if ((char)piVar1[0x5a] != '\x01') {
          *(undefined1 *)(piVar1 + 0x5a) = 1;
          (**(code **)(*piVar1 + 0x168))();
        }
      }
      FUN_0055c517();
    }
    *(code **)(param_1 + 0x1a4) = FUN_00558723;
    *(code **)(param_1 + 0x1a8) = FUN_005591ff;
    if (*(char *)(param_1 + 0x121) == '\0') {
      uVar5 = 0x29;
LAB_0055bc98:
      iVar4 = FUN_005e74ca(uVar5);
    }
    else {
      iVar4 = FUN_005e749a(4);
    }
  }
  else if (param_2 == 1) {
    *(code **)(param_1 + 0x1a4) = FUN_00558829;
    *(code **)(param_1 + 0x1a8) = FUN_005591ff;
    iVar4 = FUN_005e74ca(0x21);
    FUN_005e46f0(1);
  }
  else if (param_2 == 2) {
    if (*(char *)(param_1 + 0x121) != '\0') {
      piVar1 = *(int **)(param_1 + 0x164);
      if ((char)piVar1[0x5a] != '\0') {
        *(undefined1 *)(piVar1 + 0x5a) = 0;
        (**(code **)(*piVar1 + 0x168))();
      }
      piVar1 = *(int **)(param_1 + 0x178);
      if ((char)piVar1[0x5a] != '\0') {
        *(undefined1 *)(piVar1 + 0x5a) = 0;
        (**(code **)(*piVar1 + 0x168))();
      }
      piVar1 = *(int **)(param_1 + 0x154);
      if ((char)piVar1[0x5a] != '\0') {
        *(undefined1 *)(piVar1 + 0x5a) = 0;
        (**(code **)(*piVar1 + 0x168))();
      }
      piVar1 = *(int **)(param_1 + 0x15c);
      if ((char)piVar1[0x5a] != '\0') {
        *(undefined1 *)(piVar1 + 0x5a) = 0;
        (**(code **)(*piVar1 + 0x168))();
      }
      piVar1 = *(int **)(param_1 + 0x160);
      if ((char)piVar1[0x5a] != '\0') {
        *(undefined1 *)(piVar1 + 0x5a) = 0;
        (**(code **)(*piVar1 + 0x168))();
      }
      piVar1 = *(int **)(param_1 + 0x168);
      if ((char)piVar1[0x5a] != '\0') {
        *(undefined1 *)(piVar1 + 0x5a) = 0;
        (**(code **)(*piVar1 + 0x168))();
      }
      piVar1 = *(int **)(param_1 + 0x16c);
      if ((char)piVar1[0x5a] != '\0') {
        *(undefined1 *)(piVar1 + 0x5a) = 0;
        (**(code **)(*piVar1 + 0x168))();
      }
      piVar1 = *(int **)(param_1 + 0x174);
      if ((char)piVar1[0x5a] != '\0') {
        *(undefined1 *)(piVar1 + 0x5a) = 0;
        (**(code **)(*piVar1 + 0x168))();
      }
      piVar1 = *(int **)(param_1 + 0x17c);
      if ((char)piVar1[0x5a] != '\0') {
        *(undefined1 *)(piVar1 + 0x5a) = 0;
        (**(code **)(*piVar1 + 0x168))();
      }
      piVar1 = *(int **)(param_1 + 0x184);
      if ((char)piVar1[0x5a] != '\0') {
        *(undefined1 *)(piVar1 + 0x5a) = 0;
        (**(code **)(*piVar1 + 0x168))();
      }
      piVar1 = *(int **)(param_1 + 0x188);
      if ((char)piVar1[0x5a] != '\0') {
        *(undefined1 *)(piVar1 + 0x5a) = 0;
        (**(code **)(*piVar1 + 0x168))();
      }
      piVar1 = *(int **)(param_1 + 0x180);
      if ((char)piVar1[0x5a] != '\0') {
        *(undefined1 *)(piVar1 + 0x5a) = 0;
        (**(code **)(*piVar1 + 0x168))();
      }
    }
    *(code **)(param_1 + 0x1a4) = FUN_00558a29;
    *(undefined1 **)(param_1 + 0x1a8) = &LAB_0055b44c;
    iVar4 = FUN_005e74ca(0x22);
    FUN_005e46f0(1);
    iVar2 = *(int *)(param_1 + 0x148);
    iVar3 = *(int *)(iVar2 + 8);
    while (iVar3 != iVar2) {
      FUN_0054f3dc(1);
      FUN_0041674f();
      iVar2 = *(int *)(param_1 + 0x148);
    }
    FUN_0057a7f7(s_UI_Nhood_bdoze_006cda34,0xfffffffc);
  }
  else if (param_2 == 3) {
    piVar1 = *(int **)(param_1 + 0x164);
    if ((char)piVar1[0x5a] != '\0') {
      *(undefined1 *)(piVar1 + 0x5a) = 0;
      (**(code **)(*piVar1 + 0x168))();
    }
    piVar1 = *(int **)(param_1 + 0x178);
    if ((char)piVar1[0x5a] != '\0') {
      *(undefined1 *)(piVar1 + 0x5a) = 0;
      (**(code **)(*piVar1 + 0x168))();
    }
    piVar1 = *(int **)(param_1 + 0x154);
    if ((char)piVar1[0x5a] != '\0') {
      *(undefined1 *)(piVar1 + 0x5a) = 0;
      (**(code **)(*piVar1 + 0x168))();
    }
    piVar1 = *(int **)(param_1 + 0x15c);
    if ((char)piVar1[0x5a] != '\0') {
      *(undefined1 *)(piVar1 + 0x5a) = 0;
      (**(code **)(*piVar1 + 0x168))();
    }
    piVar1 = *(int **)(param_1 + 0x160);
    if ((char)piVar1[0x5a] != '\0') {
      *(undefined1 *)(piVar1 + 0x5a) = 0;
      (**(code **)(*piVar1 + 0x168))();
    }
    piVar1 = *(int **)(param_1 + 0x168);
    if ((char)piVar1[0x5a] != '\0') {
      *(undefined1 *)(piVar1 + 0x5a) = 0;
      (**(code **)(*piVar1 + 0x168))();
    }
    piVar1 = *(int **)(param_1 + 0x16c);
    if ((char)piVar1[0x5a] != '\0') {
      *(undefined1 *)(piVar1 + 0x5a) = 0;
      (**(code **)(*piVar1 + 0x168))();
    }
    piVar1 = *(int **)(param_1 + 0x174);
    if ((char)piVar1[0x5a] != '\0') {
      *(undefined1 *)(piVar1 + 0x5a) = 0;
      (**(code **)(*piVar1 + 0x168))();
    }
    piVar1 = *(int **)(param_1 + 0x17c);
    if ((char)piVar1[0x5a] != '\0') {
      *(undefined1 *)(piVar1 + 0x5a) = 0;
      (**(code **)(*piVar1 + 0x168))();
    }
    piVar1 = *(int **)(param_1 + 0x184);
    if ((char)piVar1[0x5a] != '\0') {
      *(undefined1 *)(piVar1 + 0x5a) = 0;
      (**(code **)(*piVar1 + 0x168))();
    }
    piVar1 = *(int **)(param_1 + 0x188);
    if ((char)piVar1[0x5a] != '\0') {
      *(undefined1 *)(piVar1 + 0x5a) = 0;
      (**(code **)(*piVar1 + 0x168))();
    }
    piVar1 = *(int **)(param_1 + 0x158);
    if ((char)piVar1[0x5a] != '\0') {
      *(undefined1 *)(piVar1 + 0x5a) = 0;
      (**(code **)(*piVar1 + 0x168))();
    }
    *(code **)(param_1 + 0x1a4) = FUN_00558d57;
    *(undefined1 **)(param_1 + 0x1a8) = &LAB_0055b49a;
    iVar4 = FUN_005e74ca(0x28);
    FUN_005e46f0(1);
    iVar2 = *(int *)(param_1 + 0x148);
    iVar3 = *(int *)(iVar2 + 8);
    while (iVar3 != iVar2) {
      FUN_0054f3dc(1);
      FUN_0041674f();
      iVar2 = *(int *)(param_1 + 0x148);
    }
  }
  else {
    if (param_2 != 4) {
      if (param_2 != 5) goto LAB_0055bcd7;
      *(undefined1 *)(param_1 + 0x120) = 1;
      *(undefined1 **)(param_1 + 0x1a4) = &LAB_0055d543;
      uVar5 = 0x28;
      goto LAB_0055bc98;
    }
    *(code **)(param_1 + 0x1a4) = FUN_005591a7;
    *(code **)(param_1 + 0x1a8) = FUN_004ac500;
    iVar4 = FUN_005e74ca(0x29);
    iVar2 = *(int *)(param_1 + 0x148);
    iVar3 = *(int *)(iVar2 + 8);
    while (iVar3 != iVar2) {
      FUN_0054f3dc(2);
      FUN_0041674f();
      iVar2 = *(int *)(param_1 + 0x148);
    }
  }
  if (iVar4 != 0) {
    FUN_005dde6d(iVar4);
    iVar2 = *(int *)(param_1 + 0x148);
    iVar3 = *(int *)(iVar2 + 8);
    while (iVar3 != iVar2) {
      FUN_005dde6d(iVar4);
      FUN_0041674f();
      iVar2 = *(int *)(param_1 + 0x148);
    }
  }
LAB_0055bcd7:
  FUN_0055d388();
  return;
}

