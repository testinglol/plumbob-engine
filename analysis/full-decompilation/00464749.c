
undefined4 __thiscall FUN_00464749(int param_1,uint param_2)

{
  uint uVar1;
  undefined4 uStack_8;
  
  uVar1 = *(uint *)(param_1 + 4) & param_2;
  if ((uVar1 == *(uint *)(param_1 + 4)) || (uVar1 == 0)) {
    uStack_8 = 0;
  }
  else {
    uVar1 = *(uint *)(param_1 + 0xc) & param_2;
    if ((uVar1 == *(uint *)(param_1 + 0xc)) || (uVar1 == 0)) {
      uStack_8 = 1;
    }
    else {
      uVar1 = *(uint *)(param_1 + 0x14) & param_2;
      if ((uVar1 == *(uint *)(param_1 + 0x14)) || (uVar1 == 0)) {
        uStack_8 = 2;
      }
      else {
        param_2 = *(uint *)(param_1 + 0x1c) & param_2;
        if ((param_2 == *(uint *)(param_1 + 0x1c)) || (param_2 == 0)) {
          uStack_8 = 3;
        }
        else {
          uStack_8 = 4;
        }
      }
    }
  }
  return uStack_8;
}

