
uint __thiscall FUN_004561a0(uint *param_1,uint param_2)

{
  uint in_EAX;
  uint uVar1;
  
  if (((int)param_2 < 0) || (in_EAX = *param_1, (uint)((int)(param_1[1] - in_EAX) >> 2) <= param_2))
  {
    uVar1 = in_EAX & 0xffff0000;
  }
  else {
    uVar1 = CONCAT22((short)(in_EAX >> 0x10),*(undefined2 *)(in_EAX + param_2 * 4));
  }
  return uVar1;
}

