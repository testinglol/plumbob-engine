
void __fastcall FUN_0054d5e9(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  if (*(int *)(param_1 + 0x11c) < 0) {
    *(undefined4 *)(param_1 + 0x11c) = 0;
    if (*(undefined4 **)(param_1 + 0x120) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x120))(1);
      *(undefined4 *)(param_1 + 0x120) = 0;
    }
    FUN_005a5631(0x13ba,(undefined4 *)(param_1 + 0x120),4);
    *(undefined4 *)(param_1 + 0x124) = *(undefined4 *)(param_1 + 0x1c8);
    FUN_0054d786();
  }
  if (*(int *)(param_1 + 0x124) == *(int *)(param_1 + 0x1c8)) goto LAB_0054d75b;
  *(int *)(param_1 + 0x124) = *(int *)(param_1 + 0x1c8);
  iVar1 = *(int *)(param_1 + 0x11c);
  if (iVar1 == 0) {
    FUN_0057a14d(s_nessie_sfx_006cdb18);
    puVar2 = *(undefined4 **)(param_1 + 0x120);
    *(undefined4 *)(param_1 + 0x11c) = 1;
    if (puVar2 != (undefined4 *)0x0) {
      (**(code **)*puVar2)(1);
      *(int *)(param_1 + 0x120) = 0;
    }
LAB_0054d684:
    uVar3 = 0x13bb;
  }
  else if (iVar1 == 1) {
    *(undefined4 *)(param_1 + 0x11c) = 2;
    if (*(undefined4 **)(param_1 + 0x120) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x120))(1);
      *(undefined4 *)(param_1 + 0x120) = 0;
    }
    uVar3 = 0x13bc;
  }
  else {
    if (iVar1 == 2) {
      *(int *)(param_1 + 0x114) = *(int *)(param_1 + 0x114) + -2;
      *(int *)(param_1 + 0x118) = *(int *)(param_1 + 0x118) + 1;
      FUN_0054d786();
      if (0x159 < *(int *)(param_1 + 0x114)) {
        return;
      }
      *(undefined4 *)(param_1 + 0x11c) = 3;
      return;
    }
    if (iVar1 == 3) {
      *(undefined4 *)(param_1 + 0x11c) = 4;
      if (*(undefined4 **)(param_1 + 0x120) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(param_1 + 0x120))(1);
        *(undefined4 *)(param_1 + 0x120) = 0;
      }
      goto LAB_0054d684;
    }
    if (iVar1 != 4) {
      *(undefined1 *)(param_1 + 0x111) = 0;
      if (*(undefined4 **)(param_1 + 0x120) == (undefined4 *)0x0) {
        return;
      }
      (**(code **)**(undefined4 **)(param_1 + 0x120))(1);
      *(undefined4 *)(param_1 + 0x120) = 0;
      return;
    }
    *(undefined4 *)(param_1 + 0x11c) = 5;
    if (*(undefined4 **)(param_1 + 0x120) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x120))(1);
      *(undefined4 *)(param_1 + 0x120) = 0;
    }
    uVar3 = 0x13ba;
  }
  FUN_005a5631(uVar3,param_1 + 0x120,4);
LAB_0054d75b:
  FUN_0054d786();
  return;
}

