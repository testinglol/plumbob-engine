
void __thiscall FUN_0056c048(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  *(undefined4 *)(param_1 + 0x100) = param_2;
  if (*(undefined4 **)(param_1 + 0xfc) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0xfc))(1);
    *(undefined4 *)(param_1 + 0xfc) = 0;
  }
  iVar1 = *(int *)(param_1 + 0x100);
  if (iVar1 == 1) {
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
  else if (iVar1 == 0x10) {
    uVar2 = 0x1346;
  }
  else if (iVar1 == 0x20) {
    uVar2 = 0x1347;
  }
  else {
    if (iVar1 != 0x40) {
      return;
    }
    uVar2 = 0x1348;
  }
  FUN_005a5631(uVar2,(undefined4 *)(param_1 + 0xfc),4);
  return;
}

