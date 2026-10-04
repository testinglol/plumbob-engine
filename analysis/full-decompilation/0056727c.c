
void __thiscall FUN_0056727c(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  *(undefined4 *)(param_1 + 0x10c) = param_2;
  if (*(undefined4 **)(param_1 + 0x108) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x108))(1);
    *(undefined4 *)(param_1 + 0x108) = 0;
  }
  iVar1 = *(int *)(param_1 + 0x10c);
  if (iVar1 < 0x21) {
    if (iVar1 == 0x20) {
      uVar2 = 0x1347;
    }
    else if (iVar1 == 1) {
      uVar2 = 0x1342;
    }
    else if (iVar1 == 2) {
      uVar2 = 0x1343;
    }
    else if (iVar1 == 4) {
      uVar2 = 0x1344;
    }
    else if (iVar1 == 8) {
      uVar2 = 0x1345;
    }
    else {
      if (iVar1 != 0x10) {
        return;
      }
      uVar2 = 0x1346;
    }
  }
  else if (iVar1 == 0x40) {
    uVar2 = 0x1348;
  }
  else if (iVar1 == 0x80) {
    uVar2 = 0x1349;
  }
  else if (iVar1 == 0x100) {
    uVar2 = 0x134b;
  }
  else if (iVar1 == 0x200) {
    uVar2 = 0x134c;
  }
  else {
    if (iVar1 != 0x400) {
      return;
    }
    uVar2 = 0x134a;
  }
  FUN_005a5631(uVar2,(undefined4 *)(param_1 + 0x108),4);
  return;
}

