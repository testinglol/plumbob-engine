
int FUN_0043fc42(undefined4 param_1)

{
  int extraout_var;
  int iVar1;
  undefined4 uVar2;
  int local_c;
  int local_8;
  
  uVar2 = *(undefined4 *)(DAT_006e486c + 0x28);
  FUN_0043de5b(param_1);
  *(undefined1 *)(extraout_var + 0x11) = 0;
  iVar1 = extraout_var;
  FUN_00445fc4(extraout_var,uVar2);
  FUN_004427da();
  local_8 = FUN_00449c9e(iVar1,param_1,0x4f626a4d,1,&local_c);
  if (local_c < 0x2f) {
    local_8 = FUN_00442a34(param_1);
  }
  if (local_8 == 0) {
    FUN_00442bdf();
    FUN_00443cf3();
  }
  *(undefined1 *)(iVar1 + 0x12) = 1;
  return local_8;
}

