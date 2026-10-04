
undefined4 __thiscall
FUN_005dfeb6(int param_1,undefined4 param_2,undefined1 *param_3,undefined1 *param_4,
            undefined1 *param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 == 5) {
    uVar2 = FUN_00438f76(param_2);
  }
  else if (iVar1 == 6) {
    uVar2 = FUN_004a45b9(param_2);
  }
  else if (iVar1 == 8) {
    uVar2 = FUN_004a45de(param_2);
  }
  else {
    uVar2 = FUN_00438f9b();
  }
  *param_3 = (char)((uint)uVar2 >> 0x10);
  *param_4 = (char)((uint)uVar2 >> 8);
  *param_5 = (char)uVar2;
  return 1;
}

