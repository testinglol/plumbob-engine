
void FUN_00625370(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 local_c;
  
  local_c = *(int *)(*param_1 + 0x24);
  iVar1 = *param_1 + 0x28;
  if (0 < local_c) {
    do {
      FUN_006252f0(iVar1,param_2,param_3,param_4,param_5,param_6,param_7);
      iVar1 = iVar1 + 4;
      local_c = local_c + -1;
    } while (local_c != 0);
  }
  return;
}

