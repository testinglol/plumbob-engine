
undefined4 __thiscall FUN_0043ac74(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined **local_110 [3];
  undefined1 local_104 [256];
  
  uVar3 = 0;
  FUN_0046f824(local_104,0,0x100);
  local_110[0] = &PTR_FUN_00666524;
  FUN_0046f847(param_2,0xffffffff);
  if (*(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x20) >> 2 != 0) {
    do {
      uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x20) + uVar3 * 4);
      iVar2 = FUN_0046f973(local_110);
      if (iVar2 == 0) {
        return uVar1;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < (uint)(*(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x20) >> 2));
  }
  return 0;
}

