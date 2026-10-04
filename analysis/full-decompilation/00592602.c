
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall FUN_00592602(int param_1,float param_2)

{
  int iStack_8;
  
  if (_DAT_0066657c <= param_2) {
    if (_DAT_0066743c <= param_2) {
      if (_DAT_0066740c <= param_2) {
        if (_DAT_00672050 <= param_2) {
          if (_DAT_00668318 <= param_2) {
            return -1;
          }
          iStack_8 = 7;
        }
        else {
          iStack_8 = 5;
        }
      }
      else {
        iStack_8 = 3;
      }
    }
    else {
      iStack_8 = 1;
    }
  }
  else {
    iStack_8 = 9;
  }
  if (*(short *)(*(int *)(param_1 + 0x138) + 0x58c) == 1) {
    iStack_8 = iStack_8 + 1;
  }
  return iStack_8;
}

