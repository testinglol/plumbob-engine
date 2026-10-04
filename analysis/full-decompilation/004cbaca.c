
uint __thiscall FUN_004cbaca(int param_1,uint param_2,uint param_3)

{
  short sVar1;
  uint in_EAX;
  
  if ((*(int *)(param_1 + 0x24) == 1) &&
     (in_EAX = *(uint *)(*(int *)(param_1 + 0x28) + 0x60),
     (param_2 & (int)*(short *)(in_EAX + 0x50)) != 0)) {
    sVar1 = *(short *)(in_EAX + 0xbc);
    in_EAX = CONCAT22((short)(in_EAX >> 0x10),sVar1);
    if (((param_3 & (int)sVar1) != 0) || ((param_3 == 0xff && (sVar1 == 0)))) {
      return CONCAT31((int3)(in_EAX >> 8),1);
    }
  }
  return in_EAX & 0xffffff00;
}

