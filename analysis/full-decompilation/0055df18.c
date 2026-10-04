
void __fastcall FUN_0055df18(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  if (*(int *)(param_1 + 0x10c) < 0) {
    *(undefined4 *)(param_1 + 0x10c) = 0;
    if (*(undefined4 **)(param_1 + 0x110) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x110))(1);
      *(undefined4 *)(param_1 + 0x110) = 0;
    }
    FUN_005a5631(0x13ba,(undefined4 *)(param_1 + 0x110),4);
    *(undefined4 *)(param_1 + 0x114) = *(undefined4 *)(param_1 + 0x1d8);
    FUN_0055e0b2();
  }
  if (*(int *)(param_1 + 0x114) == *(int *)(param_1 + 0x1d8)) goto LAB_0055e087;
  *(int *)(param_1 + 0x114) = *(int *)(param_1 + 0x1d8);
  iVar1 = *(int *)(param_1 + 0x10c);
  if (iVar1 == 0) {
    FUN_0057a14d(s_nessie_sfx_006cdb18);
    puVar2 = *(undefined4 **)(param_1 + 0x110);
    *(undefined4 *)(param_1 + 0x10c) = 1;
    if (puVar2 != (undefined4 *)0x0) {
      (**(code **)*puVar2)(1);
      *(int *)(param_1 + 0x110) = 0;
    }
LAB_0055dfb3:
    uVar3 = 0x13bb;
  }
  else if (iVar1 == 1) {
    *(undefined4 *)(param_1 + 0x10c) = 2;
    if (*(undefined4 **)(param_1 + 0x110) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x110))(1);
      *(undefined4 *)(param_1 + 0x110) = 0;
    }
    uVar3 = 0x13bc;
  }
  else {
    if (iVar1 == 2) {
      *(int *)(param_1 + 0x104) = *(int *)(param_1 + 0x104) + -2;
      *(int *)(param_1 + 0x108) = *(int *)(param_1 + 0x108) + 1;
      FUN_0055e0b2();
      if (0x3c < *(int *)(param_1 + 0x104)) {
        return;
      }
      *(undefined4 *)(param_1 + 0x10c) = 3;
      return;
    }
    if (iVar1 == 3) {
      *(undefined4 *)(param_1 + 0x10c) = 4;
      if (*(undefined4 **)(param_1 + 0x110) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(param_1 + 0x110))(1);
        *(undefined4 *)(param_1 + 0x110) = 0;
      }
      goto LAB_0055dfb3;
    }
    if (iVar1 != 4) {
      *(undefined1 *)(param_1 + 0x100) = 0;
      if (*(undefined4 **)(param_1 + 0x110) == (undefined4 *)0x0) {
        return;
      }
      (**(code **)**(undefined4 **)(param_1 + 0x110))(1);
      *(undefined4 *)(param_1 + 0x110) = 0;
      return;
    }
    *(undefined4 *)(param_1 + 0x10c) = 5;
    if (*(undefined4 **)(param_1 + 0x110) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x110))(1);
      *(undefined4 *)(param_1 + 0x110) = 0;
    }
    uVar3 = 0x13ba;
  }
  FUN_005a5631(uVar3,param_1 + 0x110,4);
LAB_0055e087:
  FUN_0055e0b2();
  return;
}

