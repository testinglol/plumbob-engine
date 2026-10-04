
int FUN_004181b3(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_8;
  
  local_8 = 0x10;
  iVar1 = FUN_004131a0(param_2);
  if (iVar1 == 0) {
    iVar1 = FUN_00413178(param_1,&local_8);
    if (iVar1 == 0) {
      FUN_004181f1();
      iVar1 = 0;
    }
  }
  return iVar1;
}

