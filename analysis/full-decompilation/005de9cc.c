
void __thiscall FUN_005de9cc(undefined4 *param_1,int param_2)

{
  int iVar1;
  
  *param_1 = 0;
  param_1[1] = 0;
  if ((*(byte *)(param_2 + 0x6a) & 2) == 0) {
    if (*(int *)(param_2 + 0x54) == 0x10) {
      iVar1 = *(int *)(param_2 + 0x58);
      if (((iVar1 == 0x7c00) && (*(int *)(param_2 + 0x5c) == 0x3e0)) &&
         (*(int *)(param_2 + 0x60) == 0x1f)) {
        *param_1 = 5;
      }
      else if (((iVar1 == 0xf800) && (*(int *)(param_2 + 0x5c) == 0x7e0)) &&
              (*(int *)(param_2 + 0x60) == 0x1f)) {
        *param_1 = 7;
      }
      else if (((iVar1 == 0xfc00) && (*(int *)(param_2 + 0x5c) == 0x3e0)) &&
              (*(int *)(param_2 + 0x60) == 0x1f)) {
        *param_1 = 6;
      }
      else {
        if (iVar1 != 0xf800) {
          return;
        }
        if (*(int *)(param_2 + 0x5c) != 0x7c0) {
          return;
        }
        if (*(int *)(param_2 + 0x60) != 0x3f) {
          return;
        }
        *param_1 = 8;
      }
      param_1[1] = 0x10;
    }
  }
  else {
    *param_1 = 10;
    param_1[1] = *(undefined4 *)(param_2 + 0x54);
  }
  return;
}

