
undefined1 __thiscall FUN_00599c53(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  
  uVar3 = FUN_0059a1ce(param_1,param_2);
  iVar1 = *(int *)(param_1 + 8);
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(iVar1 + 0x94);
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar1 + 0x98);
  *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(iVar1 + 0x9c);
  *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(iVar1 + 0xa0);
  uVar2 = *(undefined4 *)(iVar1 + 0xa8);
  *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(iVar1 + 0xa4);
  *(undefined4 *)(param_1 + 0x30) = uVar2;
  FUN_00463049((undefined4 *)(param_1 + 0x1c));
  return uVar3;
}

