
uint __thiscall FUN_004ed225(int param_1,uint param_2)

{
  uint *in_EAX;
  uint uVar1;
  
  uVar1 = 0;
  if (*(uint *)(param_1 + 4) != 0) {
    in_EAX = (uint *)(param_1 + 0x40c);
    do {
      if ((in_EAX[-1] <= param_2) && (param_2 <= *in_EAX)) {
        return CONCAT31((int3)((uint)in_EAX >> 8),1);
      }
      uVar1 = uVar1 + 1;
      in_EAX = in_EAX + 2;
    } while (uVar1 < *(uint *)(param_1 + 4));
  }
  return (uint)in_EAX & 0xffffff00;
}

