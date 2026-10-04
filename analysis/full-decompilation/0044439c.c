
undefined4 __thiscall FUN_0044439c(int param_1,int param_2)

{
  undefined4 *local_8;
  
  local_8 = *(undefined4 **)(param_1 + 100);
  while( true ) {
    if (local_8 == *(undefined4 **)(param_1 + 0x68)) {
      return 0;
    }
    if (*(int *)*local_8 == param_2) break;
    local_8 = local_8 + 1;
  }
  return *local_8;
}

