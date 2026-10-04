
void __thiscall FUN_004ff8c3(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  if (*(undefined4 **)(param_1 + 0xd4) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0xd4))(1);
  }
  FUN_005a55f6(param_2,param_3,(int *)(param_1 + 0xd4),4);
  iVar2 = *(int *)(param_1 + 0xd4);
  if (iVar2 == 0) {
    iVar2 = 0x2d;
    *(undefined4 *)(param_1 + 0xf8) = 0x2d;
    *(undefined4 *)(param_1 + 0xfc) = 0x2d;
    iVar1 = 0x2d;
  }
  else {
    iVar1 = *(int *)(iVar2 + 0x1c);
    iVar2 = *(int *)(iVar2 + 0x20);
    *(undefined4 *)(param_1 + 0xf0) = 0;
    *(undefined4 *)(param_1 + 0xf4) = 0;
    if (iVar1 == 0x2d) {
      *(undefined4 *)(param_1 + 0xec) = 1;
    }
    if (iVar2 == 0x2d) {
      *(undefined4 *)(param_1 + 0xe8) = 1;
    }
    iVar1 = iVar1 / *(int *)(param_1 + 0xec);
    iVar2 = iVar2 / *(int *)(param_1 + 0xe8);
    *(int *)(param_1 + 0xf8) = iVar1;
    *(int *)(param_1 + 0xfc) = iVar2;
  }
  FUN_004cb1a2(iVar1,iVar2);
  return;
}

