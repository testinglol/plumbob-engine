
void __thiscall FUN_004128dd(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined **local_114 [2];
  ushort local_10c;
  undefined1 local_108 [260];
  
  FUN_0046f824(local_108,0,0x104);
  local_114[0] = &PTR_FUN_006664e8;
  FUN_0041218d(param_2,local_114);
  iVar1 = (*(code *)**(undefined4 **)(param_1 + 8))();
  if ((iVar1 != 0) && (iVar1 = FUN_0046fb18(*(undefined4 *)(param_1 + 0xc),0), iVar1 != 0)) {
    return;
  }
  iVar1 = (*(code *)**(undefined4 **)(param_1 + 0x34))();
  iVar2 = (uint)local_10c - iVar1;
  if (-1 < iVar2) {
    if ((iVar1 != 0) &&
       (iVar1 = FUN_0046fb18(*(undefined4 *)(param_1 + 0x38),iVar2), iVar1 != iVar2)) {
      return;
    }
    FUN_004129d9(param_2);
  }
  return;
}

