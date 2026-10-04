
void FUN_0060d540(undefined4 *param_1,undefined4 param_2,int param_3,uint param_4,int param_5,
                 undefined4 param_6)

{
  uint uVar1;
  
  uVar1 = 0;
  if (0 < param_3) {
    do {
      if (((uVar1 ^ param_4) & 1) != 0) {
        if (param_5 < 9) {
          *(char *)param_1 = (char)param_6;
        }
        else {
          *param_1 = param_6;
        }
      }
      if (param_5 < 9) {
        param_1 = (undefined4 *)((int)param_1 + 1);
      }
      else {
        param_1 = param_1 + 1;
      }
      uVar1 = uVar1 + 1;
    } while ((int)uVar1 < param_3);
  }
  return;
}

