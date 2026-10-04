
undefined4 __thiscall FUN_00444c08(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 *local_8;
  
  if ((*(int *)(param_1 + 0xa8) == 0) || (param_2 == 0)) {
    if (*(int *)(param_1 + 0xa8) == param_2) {
      uVar1 = 1;
    }
    else {
      if (*(int *)(param_1 + 0xa8) != 0) {
        for (local_8 = *(undefined4 **)(param_1 + 100); local_8 != *(undefined4 **)(param_1 + 0x68);
            local_8 = local_8 + 1) {
          if (*(int *)*local_8 == *(int *)(param_1 + 0xa8)) {
            FUN_004370fd();
          }
        }
      }
      *(int *)(param_1 + 0xa8) = param_2;
      FUN_0040766a(0x107,0);
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

