
void __thiscall FUN_0054d4a3(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x100);
  if ((((iVar1 == 1) || (iVar1 == 2)) || (iVar1 == 4)) ||
     (((iVar1 == 8 || (iVar1 == 0x10)) || ((iVar1 == 0x20 || (iVar1 == 0x40)))))) {
    FUN_005e46f0(0);
  }
  if (param_2 == 0) {
    FUN_0056c048(0x10);
  }
  else if (param_2 == 1) {
    FUN_0056c048(0x20);
  }
  else if (param_2 == 2) {
    FUN_0056c048(8);
  }
  else if (param_2 == 3) {
    FUN_0056c048(4);
  }
  else if (param_2 == 4) {
    FUN_0056c048(2);
  }
  else if (param_2 == 5) {
    FUN_0056c048(0x40);
  }
  else {
    if (param_2 != 6) {
      return;
    }
    FUN_0056c048(1);
  }
  FUN_005e46f0(1);
  return;
}

