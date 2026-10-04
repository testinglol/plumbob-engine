
int FUN_0041baf1(uint param_1,undefined2 param_2)

{
  int iVar1;
  int local_18 [2];
  int local_10 [2];
  undefined4 local_8;
  
  local_8 = param_1;
  iVar1 = 0;
  FUN_00575b11(local_10,&local_8);
  if (local_10[0] != 0) {
    param_1 = CONCAT22((short)(param_1 >> 0x10),param_2) & 0xff00ffff;
    FUN_0041d8f0(local_18,&param_1);
    if (local_18[0] != 0) {
      iVar1 = local_18[0] + 7;
    }
  }
  return iVar1;
}

