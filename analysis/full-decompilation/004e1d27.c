
bool FUN_004e1d27(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined **local_110 [3];
  undefined1 local_104 [256];
  
  iVar2 = FUN_00425db3(param_1);
  if (iVar2 != 0) {
    uVar1 = *param_2;
    FUN_0046f824(local_104,0,0x100);
    local_110[0] = &PTR_FUN_00666524;
    FUN_0046f847(uVar1,0xffffffff);
    FUN_004108c4(local_110);
  }
  return iVar2 != 0;
}

