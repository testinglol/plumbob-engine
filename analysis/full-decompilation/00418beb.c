
uint __thiscall FUN_00418beb(undefined4 *param_1,int param_2,int param_3)

{
  int *in_EAX;
  undefined4 *puVar1;
  
  if (-1 < param_3) {
    for (puVar1 = (undefined4 *)*param_1; puVar1 != (undefined4 *)param_1[1]; puVar1 = puVar1 + 5) {
      for (in_EAX = (int *)*puVar1; in_EAX != (int *)puVar1[1]; in_EAX = in_EAX + 0x17) {
        if (*in_EAX == param_2) {
          *in_EAX = *in_EAX - param_3;
          return CONCAT31((int3)((uint)in_EAX >> 8),1);
        }
      }
    }
  }
  return (uint)in_EAX & 0xffffff00;
}

